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
    void setCurInputDevice(int deviceIdx);//задаем текущее аудиоустройство из списка
    void setSampleRate(int sampleRateIdx);//задаем SampleRate для текущего аудиоустройства

private:
    void refreshInputDevices();//обновляем список входных аудиоустройств
    void fillDeviceSampleRates();//заполняем список поддерживаемых SampleRates для текущего аудиоустройства
    void selectDeviceSampleRate();//показываем выбранное SampleRate для текущего аудиоустройства

    Ui::MainWindow *ui;
    QList<InputDevice> m_inputDevices;//список входных аудиоустройств
    int m_curDeviceIdx;//индекс выбранного входного аудиоустройства
};
#endif // MAINWINDOW_H
