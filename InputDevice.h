#ifndef MYINPUTDEVICES_H
#define MYINPUTDEVICES_H

#include <QAudioDeviceInfo>
#include <QMap>

class InputDevice : public QAudioDeviceInfo
{
public:
    InputDevice();
    InputDevice(const QAudioDeviceInfo &other);

    QAudioFormat &audioFormat();//доступ к аудиоформату устройства
    const QMap<int, QString> &getSampleTypeMap() const;//получить enum QAudioFormat::SampleType в виде контейнера map
    const QMap<int, QString> &getByteOrderMap()const; //получить enum QAudioFormat::Endian в виде контейнера map

private:
    void fillSampleTypeMap();//заполняем контейнер для QAudioFormat::SampleType
    void fillByteOrderMap();//заполняем контейнер для QAudioFormat::Endian
    QAudioFormat m_audioFormat;
    QMap<int, QString> m_sampleType;
    QMap<int, QString> m_byteOrder;
};

#endif // MYINPUTDEVICES_H
