#include "InputDevice.h"

InputDevice::InputDevice() :
    QAudioDeviceInfo()
{
    m_audioFormat = preferredFormat();
}

InputDevice::InputDevice(const QAudioDeviceInfo &other) :
    QAudioDeviceInfo(other)
{
    m_audioFormat = preferredFormat();
}

//доступ к аудиоформату устройства
QAudioFormat &InputDevice::audioFormat()
{
    return m_audioFormat;
}

