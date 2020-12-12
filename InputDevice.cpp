#include "InputDevice.h"

InputDevice::InputDevice() :
    QAudioDeviceInfo()
{
    m_audioFormat = preferredFormat();
    fillSampleTypeMap();
}

InputDevice::InputDevice(const QAudioDeviceInfo &other) :
    QAudioDeviceInfo(other)
{
    m_audioFormat = preferredFormat();
    fillSampleTypeMap();
}

//доступ к аудиоформату устройства
QAudioFormat &InputDevice::audioFormat()
{
    return m_audioFormat;
}

//получить QAudioFormat::SampleType в виде коньейнера map
const QMap<int, QString> &InputDevice::getSampleTypeMap() const
{
    return m_sampleType;
}

//заполняем контейнер для QAudioFormat::SampleType
void InputDevice::fillSampleTypeMap()
{
    QString sampleTypeName("Undefined");
    for(auto sampleType : supportedSampleTypes())
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

