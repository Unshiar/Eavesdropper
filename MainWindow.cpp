#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      m_curDeviceIdx(-1)
{
    ui->setupUi(this);

    connect(ui->cb_inDeviceList, SIGNAL(currentIndexChanged(int)), this, SLOT(setCurInputDevice(int)));
    connect(ui->cb_sampleRates, SIGNAL(currentIndexChanged(int)), this, SLOT(setSampleRate(int)));
    connect(ui->cb_channelCount, SIGNAL(currentIndexChanged(int)), this, SLOT(setChannelCount(int)));
    connect(ui->cb_sampleSizes, SIGNAL(currentIndexChanged(int)), this, SLOT(setSampleSize(int)));
    connect(ui->cb_sampleType, SIGNAL(currentIndexChanged(int)), this, SLOT(setSampleType(int)));

    refreshInputDevices();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//задаем текущее аудиоустройство из списка
void MainWindow::setCurInputDevice(int deviceIdx)
{
    m_curDeviceIdx = deviceIdx;

    fillDeviceSampleRates();
    selectDeviceSampleRate();

    fillDeviceChannels();
    selectDeviceChannels();

    fillDeviceSampleSize();
    selectDeviceSampleSize();

    fillDeviceSampleType();
    selectDeviceSampleType();
}

//задаем SampleRate для текущего аудиоустройства
void MainWindow::setSampleRate(int sampleRateIdx)
{
    m_inputDevices[m_curDeviceIdx].audioFormat().setSampleRate(ui->cb_sampleRates->itemText(sampleRateIdx).toInt());
}

void MainWindow::setChannelCount(int channelIdx)
{
    m_inputDevices[m_curDeviceIdx].audioFormat().setChannelCount(ui->cb_channelCount->itemText(channelIdx).toInt());
}

//задаем SampleSize для текущего аудиоустройства
void MainWindow::setSampleSize(int sampleSizeIdx)
{
    m_inputDevices[m_curDeviceIdx].audioFormat().setSampleSize(ui->cb_sampleSizes->itemText(sampleSizeIdx).toInt());
}

//задаем SampleType для текущего аудиоустройства
void MainWindow::setSampleType(int sampleTypeIdx)
{
    QAudioFormat::SampleType sampleType = static_cast<QAudioFormat::SampleType>(m_inputDevices.at(m_curDeviceIdx).getSampleTypeMap().key(ui->cb_sampleType->itemText(sampleTypeIdx)));
    m_inputDevices[m_curDeviceIdx].audioFormat().setSampleType(sampleType);
}

//обновляем список входных аудиоустройств
void MainWindow::refreshInputDevices()
{
    m_inputDevices.clear();

    for(auto &device : InputDevice::availableDevices(QAudio::AudioInput))
        m_inputDevices.append(device);

    if(m_inputDevices.isEmpty())
        return;

    for(auto &device: m_inputDevices)
        ui->cb_inDeviceList->addItem(device.deviceName());
}

//заполняем список поддерживаемых SampleRates для текущего аудиоустройства
void MainWindow::fillDeviceSampleRates()
{
    disconnect(ui->cb_sampleRates, SIGNAL(currentIndexChanged(int)), this, SLOT(setSampleRate(int)));

    ui->cb_sampleRates->clear();

    const QList<int> supportedSampleRates = m_inputDevices.at(m_curDeviceIdx).supportedSampleRates();
    for(auto sampleRate : supportedSampleRates)
        ui->cb_sampleRates->addItem(QString::number(sampleRate));

    connect(ui->cb_sampleRates, SIGNAL(currentIndexChanged(int)), this, SLOT(setSampleRate(int)));
}

//показываем выбранное SampleRate для текущего аудиоустройства
void MainWindow::selectDeviceSampleRate()
{
    disconnect(ui->cb_sampleRates, SIGNAL(currentIndexChanged(int)), this, SLOT(setSampleRate(int)));

    int sampleRate = m_inputDevices[m_curDeviceIdx].audioFormat().sampleRate();

    for(int idx = 0; idx < ui->cb_sampleRates->count(); ++idx)
        if(sampleRate == ui->cb_sampleRates->itemText(idx).toInt())
        {
            ui->cb_sampleRates->setCurrentIndex(idx);
            break;
        }

    connect(ui->cb_sampleRates, SIGNAL(currentIndexChanged(int)), this, SLOT(setSampleRate(int)));
}

//заполняем список поддерживаемых ChannelCount для текущего аудиоустройства
void MainWindow::fillDeviceChannels()
{
    disconnect(ui->cb_channelCount, SIGNAL(currentIndexChanged(int)), this, SLOT(setChannelCount(int)));

    ui->cb_channelCount->clear();

    const QList<int> supportedChannelCounts = m_inputDevices.at(m_curDeviceIdx).supportedChannelCounts();
    for(auto channelCount : supportedChannelCounts)
        ui->cb_channelCount->addItem(QString::number(channelCount));

    connect(ui->cb_channelCount, SIGNAL(currentIndexChanged(int)), this, SLOT(setChannelCount(int)));
}

//показываем выбранное ChannelCount для текущего аудиоустройства
void MainWindow::selectDeviceChannels()
{
    disconnect(ui->cb_channelCount, SIGNAL(currentIndexChanged(int)), this, SLOT(setChannelCount(int)));

    int channelCount = m_inputDevices[m_curDeviceIdx].audioFormat().channelCount();

    for(int idx = 0; idx < ui->cb_channelCount->count(); ++idx)
        if(channelCount == ui->cb_channelCount->itemText(idx).toInt())
        {
            ui->cb_channelCount->setCurrentIndex(idx);
            break;
        }

    connect(ui->cb_channelCount, SIGNAL(currentIndexChanged(int)), this, SLOT(setChannelCount(int)));
}

//заполняем список поддерживаемых SampleSize для текущего аудиоустройства
void MainWindow::fillDeviceSampleSize()
{
    disconnect(ui->cb_sampleSizes, SIGNAL(currentIndexChanged(int)), this, SLOT(setSampleSize(int)));

    ui->cb_sampleSizes->clear();

    const QList<int> supportedSampleSizes = m_inputDevices.at(m_curDeviceIdx).supportedSampleSizes();
    for(auto sampleSize : supportedSampleSizes)
        ui->cb_sampleSizes->addItem(QString::number(sampleSize));

    connect(ui->cb_sampleSizes, SIGNAL(currentIndexChanged(int)), this, SLOT(setSampleSize(int)));
}

//показываем выбранное SampleSize для текущего аудиоустройства
void MainWindow::selectDeviceSampleSize()
{
    disconnect(ui->cb_sampleSizes, SIGNAL(currentIndexChanged(int)), this, SLOT(setSampleSize(int)));

    int sampleSize = m_inputDevices[m_curDeviceIdx].audioFormat().sampleSize();

    for(int idx = 0; idx < ui->cb_channelCount->count(); ++idx)
        if(sampleSize == ui->cb_sampleSizes->itemText(idx).toInt())
        {
            ui->cb_sampleSizes->setCurrentIndex(idx);
            break;
        }

    connect(ui->cb_sampleSizes, SIGNAL(currentIndexChanged(int)), this, SLOT(setSampleSize(int)));
}

//заполняем список поддерживаемых SampleType для текущего аудиоустройства
void MainWindow::fillDeviceSampleType()
{
    disconnect(ui->cb_sampleType, SIGNAL(currentIndexChanged(int)), this, SLOT(setSampleType(int)));

    ui->cb_sampleType->clear();

    const QList<QAudioFormat::SampleType> supportedSampleTypes = m_inputDevices.at(m_curDeviceIdx).supportedSampleTypes();
    for(auto sampleType : supportedSampleTypes)
        ui->cb_sampleType->addItem(m_inputDevices.at(m_curDeviceIdx).getSampleTypeMap().value(sampleType));

    connect(ui->cb_sampleType, SIGNAL(currentIndexChanged(int)), this, SLOT(setSampleType(int)));
}

//показываем выбранное SampleType для текущего аудиоустройства
void MainWindow::selectDeviceSampleType()
{
    disconnect(ui->cb_sampleType, SIGNAL(currentIndexChanged(int)), this, SLOT(setSampleType(int)));

    int sampleType = m_inputDevices[m_curDeviceIdx].audioFormat().sampleType();

    for(int idx = 0; idx < ui->cb_sampleType->count(); ++idx)
        if(sampleType == m_inputDevices.at(m_curDeviceIdx).getSampleTypeMap().key(ui->cb_sampleType->itemText(idx)))
        {
            ui->cb_sampleType->setCurrentIndex(idx);
            break;
        }

    connect(ui->cb_sampleType, SIGNAL(currentIndexChanged(int)), this, SLOT(setSampleType(int)));
}



