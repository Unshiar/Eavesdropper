#ifndef MYINPUTDEVICES_H
#define MYINPUTDEVICES_H

#include <QObject>

class QAudioDeviceInfo;

class InputDevices
{
public:
    InputDevices();
    QStringList getInputDeviceNames();//получить список имен входных аудиоустройств (микрофонов)
    QAudioDeviceInfo &getCurrentInputDevice();//получить текущее аудиоустройство
    QAudioDeviceInfo &getInputDevice(int idx);//получить аудиоустройство из списка по индексу

    int deviceIdx() const;

public slots:
    void setDeviceIdx(int deviceIdx);

private:
    QList<QAudioDeviceInfo> getInputDevices();//получить список входных аудиоустройств (микрофонов)

    QList<QAudioDeviceInfo> m_deviceList;
    int m_deviceIdx;//индекс выбранного аудиоустройства
};

#endif // MYINPUTDEVICES_H
