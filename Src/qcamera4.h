#ifndef QCAMERA4_H
#define QCAMERA4_H

#include "Camera.h"
#include "qhalconwindow.h"
#include <QDebug>
#include <QThread>
#include <QSettings>

class QCamera4:public CMyCamera
{
    Q_OBJECT

public:
    QCamera4(MV_CC_DEVICE_INFO*  device, QHalconWindow* win);
    virtual~QCamera4();
    void connectPLC();

signals:

private:
    void readModels();

private slots:
    void readParam();
    void initWork();
    void imageProcess(bool state, unsigned char* data);
};

#endif // QCAMERA1_H
