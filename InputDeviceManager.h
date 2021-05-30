#ifndef INPUTDEVICEMANAGER_H
#define INPUTDEVICEMANAGER_H

#include "InputDeviceInfo.h"

#include <QtGlobal>
#include <QList>
#include <QString>

class InputDeviceManager
{
public:
    InputDeviceManager();

    uint16_t deviceIdx() const;
    void setDeviceIdx(const uint16_t &deviceIdx);

    QString deviceName() const;
    int sampleRate();
    void setSampleRate(int sampleRate);
    int channelCount();
    void setChannelCount(int channelCount);
    int sampleSize();
    void setSampleSize(int sampleSize);

private:
    uint16_t m_deviceIdx;
    QList<InputDeviceInfo> m_inputDevices;
};

#endif // INPUTDEVICEMANAGER_H
