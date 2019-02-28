#ifndef QCAMERA1_H
#define QCAMERA1_H

#include "Camera.h"
#include "qhalconwindow.h"
#include <QDebug>
#include <QThread>
#include <QSettings>

class QCamera1:public CMyCamera
{
    Q_OBJECT

public:
    QCamera1(MV_CC_DEVICE_INFO*  device, QHalconWindow* win);
    virtual~QCamera1();
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
