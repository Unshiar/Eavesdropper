#include "InputDeviceManager.h"

InputDeviceManager::InputDeviceManager()
{

}

uint16_t InputDeviceManager::deviceIdx() const
{
    return m_deviceIdx;
}

void InputDeviceManager::setDeviceIdx(const uint16_t &deviceIdx)
{
    m_deviceIdx = deviceIdx;
}

QString InputDeviceManager::deviceName() const
{
    return m_inputDevices.at(m_deviceIdx).deviceName();
}

int InputDeviceManager::sampleRate()
{
    return m_inputDevices[m_deviceIdx].audioFormat().sampleRate();
}

void InputDeviceManager::setSampleRate(int sampleRate)
{
    m_inputDevices[m_deviceIdx].audioFormat().setSampleRate(sampleRate);
}

int InputDeviceManager::channelCount()
{
    return m_inputDevices[m_deviceIdx].audioFormat().channelCount();
}

void InputDeviceManager::setChannelCount(int channelCount)
{
    m_inputDevices[m_deviceIdx].audioFormat().setChannelCount(channelCount);
}

int InputDeviceManager::sampleSize()
{
    return m_inputDevices[m_deviceIdx].audioFormat().sampleSize();
}

void InputDeviceManager::setSampleSize(int sampleSize)
{
    m_inputDevices[m_deviceIdx].audioFormat().setSampleSize(sampleSize);
}



