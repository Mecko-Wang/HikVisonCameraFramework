#ifndef QCAMERA3_H
#define QCAMERA3_H

#include "Camera.h"
#include "qhalconwindow.h"
#include <QDebug>
#include <QThread>
#include <QSettings>

class QCamera3:public CMyCamera
{
    Q_OBJECT

public:
    QCamera3(MV_CC_DEVICE_INFO*  device, QHalconWindow* win);
    virtual~QCamera3();
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
