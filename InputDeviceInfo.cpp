#include "InputDeviceInfo.h"

InputDeviceInfo::InputDeviceInfo(const QAudioDeviceInfo &other) :
    QAudioDeviceInfo(other)
{
    m_audioFormat = preferredFormat();
}

QAudioFormat &InputDeviceInfo::audioFormat()
{
    return m_audioFormat;
}
