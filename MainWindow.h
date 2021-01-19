#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "InputDevice.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void setCurInputDevice(int deviceIdx);
    void setSampleRate(int sampleRateIdx);
    void setChannelCount(int channelIdx);
    void setSampleSize(int sampleSizeIdx);
    void setSampleType(int sampleTypeIdx);
    void setByteOrder(int byteOrderIdx);

private:
    void refreshInputDevices();
    void fillDeviceSampleRates();
    void selectDeviceSampleRate();
    void fillDeviceChannels();
    void selectDeviceChannels();
    void fillDeviceSampleSize();
    void selectDeviceSampleSize();
    void fillDeviceSampleType();
    void selectDeviceSampleType();
    void fillDeviceByteOrder();
    void selectDeviceByteOrder();

    Ui::MainWindow *ui;
    QList<InputDevice> m_inputDevices;//список входных аудиоустройств
    int m_curDeviceIdx;//индекс выбранного входного аудиоустройства
};
#endif // MAINWINDOW_H
