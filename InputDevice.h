#ifndef MYINPUTDEVICES_H
#define MYINPUTDEVICES_H

#include <QAudioDeviceInfo>
#include <QAudioFormat>
#include <QMap>
#include <QObject>

class InputDevice : public QAudioDeviceInfo
{
public:
    InputDevice();
    InputDevice(const QAudioDeviceInfo &other);

    QAudioFormat &audioFormat();//доступ к аудиоформату устройства
    const QMap<int, QString> &getSampleTypeMap() const;//получить QAudioFormat::SampleType в виде коньейнера map

private:
    void fillSampleTypeMap();//заполняем контейнер для QAudioFormat::SampleType
    QAudioFormat m_audioFormat;
    QMap<int, QString> m_sampleType;
};

#endif // MYINPUTDEVICES_H
