#ifndef MYINPUTDEVICES_H
#define MYINPUTDEVICES_H

#include <QAudioDeviceInfo>
#include <QAudioFormat>
#include <QObject>

class InputDevice : public QAudioDeviceInfo
{
public:
    InputDevice();
    InputDevice(const QAudioDeviceInfo &other);

    QAudioFormat &audioFormat();//доступ к аудиоформату устройства

private:
    QAudioFormat m_audioFormat;
};

#endif // MYINPUTDEVICES_H
