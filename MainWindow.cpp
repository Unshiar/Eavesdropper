#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QAudioDeviceInfo>
#include <QMessageBox>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      m_curDeviceIdx(-1)
{
    ui->setupUi(this);

    connect(ui->cb_inDeviceList, SIGNAL(currentIndexChanged(int)), this, SLOT(setCurInputDevice(int)));
    connect(ui->cb_sampleRates, SIGNAL(currentIndexChanged(int)), this, SLOT(setSampleRate(int)));

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
}

//задаем SampleRate для текущего аудиоустройства
void MainWindow::setSampleRate(int sampleRateIdx)
{
    m_inputDevices[m_curDeviceIdx].audioFormat().setSampleRate(ui->cb_sampleRates->itemText(sampleRateIdx).toInt());
}

//обновляем список входных аудиоустройств
void MainWindow::refreshInputDevices()
{
    m_inputDevices.clear();

    for(auto device : QAudioDeviceInfo::availableDevices(QAudio::AudioInput))
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

    for(auto sampleRate : m_inputDevices.at(m_curDeviceIdx).supportedSampleRates())
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



