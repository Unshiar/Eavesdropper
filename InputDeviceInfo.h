#ifndef INPUTDEVICEINFO_H
#define INPUTDEVICEINFO_H

#include <QAudioDeviceInfo>
#include <QAudioFormat>

class InputDeviceInfo : public QAudioDeviceInfo
{
public:
    InputDeviceInfo(const QAudioDeviceInfo &other);

    QAudioFormat &audioFormat();

private:
    QAudioFormat m_audioFormat;

};

#endif // INPUTDEVICEINFO_H
