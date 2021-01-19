#ifndef MYINPUTDEVICES_H
#define MYINPUTDEVICES_H

#include <QAudioDeviceInfo>
#include <QMap>

class InputDevice : public QAudioDeviceInfo
{
public:
    InputDevice();
    InputDevice(const QAudioDeviceInfo &other);

    QAudioFormat &audioFormat();
    const QMap<int, QString> &getSampleTypeMap() const;
    const QMap<int, QString> &getByteOrderMap()const;

private:
    void fillSampleTypeMap();
    void fillByteOrderMap();
    QAudioFormat m_audioFormat;
    QMap<int, QString> m_sampleType;
    QMap<int, QString> m_byteOrder;
};

#endif // MYINPUTDEVICES_H
