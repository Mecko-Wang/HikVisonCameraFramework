#ifndef QCAMERA2_H
#define QCAMERA2_H

#include "Camera.h"
#include "qhalconwindow.h"
#include <QDebug>
#include <QThread>
#include <QSettings>

class QCamera2:public CMyCamera
{
    Q_OBJECT

public:
    QCamera2(MV_CC_DEVICE_INFO*  device, QHalconWindow* win);
    virtual~QCamera2();
    void connectPLC();

signals:

private:
    void readModels();

private slots:
    void readParam();
    void initWork();
    void imageProcess(bool state, unsigned char* data);
};

#endif // QCAMERA2_H
