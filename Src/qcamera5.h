#ifndef QCAMERA5_H
#define QCAMERA5_H

#include "Camera.h"
#include "qhalconwindow.h"
#include <QDebug>
#include <QThread>
#include <QSettings>

class QCamera5:public CMyCamera
{
    Q_OBJECT

public:
    QCamera5(MV_CC_DEVICE_INFO*  device, QHalconWindow* win);
    virtual~QCamera5();
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
