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

//доступ к аудиоформату устройства
QAudioFormat &InputDevice::audioFormat()
{
    return m_audioFormat;
}

//получить enum QAudioFormat::SampleType в виде контейнера map
const QMap<int, QString> &InputDevice::getSampleTypeMap() const
{
    return m_sampleType;
}

//получить enum QAudioFormat::Endian в виде контейнера map
const QMap<int, QString> &InputDevice::getByteOrderMap() const
{
    return m_byteOrder;
}

//заполняем контейнер для QAudioFormat::SampleType
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

//заполняем контейнер для QAudioFormat::Endian
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

