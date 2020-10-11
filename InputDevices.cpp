#include "InputDevices.h"

#include <QAudioDeviceInfo>

InputDevices::InputDevices() :
    m_deviceIdx(-1)
{
    getInputDevices();

    if(!m_deviceList.isEmpty())
        setDeviceIdx(0);
}

//получить список имен входных аудиоустройств (микрофонов)
QStringList InputDevices::getInputDeviceNames()
{
   QStringList result;

   for(auto &device : m_deviceList)
       result.append(device.deviceName());

   return result;
}

//получить текущее аудиоустройство
QAudioDeviceInfo &InputDevices::getCurrentInputDevice()
{
    return m_deviceList[m_deviceIdx];
}

//получить аудиоустройство из списка по идексу
QAudioDeviceInfo &InputDevices::getInputDevice(int idx)
{
    return m_deviceList[idx];
}

int InputDevices::deviceIdx() const
{
    return m_deviceIdx;
}

void InputDevices::setDeviceIdx(int deviceIdx)
{
    m_deviceIdx = deviceIdx;
}

//получить список входных аудиоустройств (микрофонов)
QList<QAudioDeviceInfo> InputDevices::getInputDevices()
{
    m_deviceList.clear();

    for(auto &inputDevice : QAudioDeviceInfo::availableDevices(QAudio::AudioInput))
        m_deviceList.append(inputDevice);

    return m_deviceList;
}

