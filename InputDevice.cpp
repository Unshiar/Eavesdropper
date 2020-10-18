#include "InputDevice.h"

InputDevice::InputDevice()
{
    m_audioFormat = preferredFormat();
}

//доступ к аудиоформату устройства
QAudioFormat &InputDevice::audioFormat()
{
    return m_audioFormat;
}

