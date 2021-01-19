#include "InputDevice.h"

InputDevice::InputDevice() :
    QAudioDeviceInfo()
{
    m_audioFormat = preferredFormat();
    fillSampleTypeMap();
    fillByteOrderMap();
}

InputDevice::InputDevice(const QAudioDeviceInfo &other) :
    QAudioDeviceInfo(other)
{
    m_audioFormat = preferredFormat();
    fillSampleTypeMap();
    fillByteOrderMap();
}

QAudioFormat &InputDevice::audioFormat()
{
    return m_audioFormat;
}

const QMap<int, QString> &InputDevice::getSampleTypeMap() const
{
    return m_sampleType;
}

const QMap<int, QString> &InputDevice::getByteOrderMap() const
{
    return m_byteOrder;
}

void InputDevice::fillSampleTypeMap()
{
    for(auto &sampleType : supportedSampleTypes())
    {
        switch (sampleType) {
        case 0: m_sampleType[sampleType] = "Unknown";
            break;

        case 1: m_sampleType[sampleType] = "SignedInt";
            break;

        case 2: m_sampleType[sampleType] = "UnSignedInt";
            break;

        case 3: m_sampleType[sampleType] = "Float";
            break;

        default: m_sampleType[sampleType] = "Undefined";
            break;
        }
    }
}

void InputDevice::fillByteOrderMap()
{
    for(auto &byteOrder : supportedByteOrders())
    {
        switch (static_cast<QSysInfo::Endian>(byteOrder)) {
        case QSysInfo::BigEndian: m_byteOrder[byteOrder] = "BigEndian";
            break;

        case QSysInfo::LittleEndian: m_byteOrder[byteOrder] = "LittleEndian";
            break;

        default:
            break;
        }
    }
}
