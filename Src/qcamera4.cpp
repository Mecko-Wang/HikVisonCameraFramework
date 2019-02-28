#include "qcamera4.h"

QCamera4::QCamera4(MV_CC_DEVICE_INFO *device, QHalconWindow *win):CMyCamera(device, win)
{
    m_plcThread = NULL;
    m_plc = NULL;
}
QCamera4::~QCamera4()
{
    m_plcThread->quit();
    m_plcThread->wait(2000);
    delete m_plcThread;

    delete m_plc;
}

//手动连接至PLC
void QCamera4::connectPLC()
{
    if(NULL != m_plcThread)
    {
        m_plcThread->quit();
        m_plcThread->wait(2000);
        delete m_plcThread;
        m_plcThread = NULL;
    }
    if(NULL != m_plcThread)
    {
        delete m_plc;
        m_plc = NULL;
    }

    try
    {
        m_plc = new CPlc(PLC_IP4, PLC_PORT4);
        m_plcThread = new QThread;

        connect(m_plcThread,SIGNAL(finished()),m_plc,SLOT(deleteLater()));
        connect(m_plcThread,SIGNAL(started()),m_plc,SLOT(initFunc()));

        connect(this, SIGNAL(sendDateToPlc(bool*,int,int,int)), m_plc, SLOT(writePlc(bool*, int, int, int)), Qt::BlockingQueuedConnection);
        connect(m_plc, &CPlc::plcStates, this, [&](bool state)
        {
            emit plcState(state);
        });
        connect(m_plc, &CPlc::sendMess, this, [&](QString excelevel, QString excedata)
        {
            emit sendMess(excelevel, excedata);
        });

        m_plc->moveToThread(m_plcThread);
        m_plcThread->start();
    }
    catch(QException& e)
    {
        emit sendMess("ERROR", "Cam1 Connect PLC QException");
        LOG(ERROR)<<"Cam1 Connect PLC QException";
    }
}

void QCamera4::readParam()
{
    //创建配置文件
    QSettings *pIni = new QSettings("./params.ini", QSettings::IniFormat);

    //圆形ROI
    Roi.Row = pIni->value("/Cam4/circle_roi_row").toDouble();
    Roi.Col = pIni->value("/Cam4/circle_roi_col").toDouble();
    Roi.Radius = pIni->value("/Cam4/circle_roi_radius").toDouble();
    //物料参数
    Matieral.Radius = pIni->value("/Cam4/material_radius").toDouble();
    Matieral.OffsetLow = pIni->value("/Cam4/material_offsetlow").toDouble();
    Matieral.OffsetHigh = pIni->value("/Cam4/material_offsethigh").toDouble();
    //找圆心模板匹配参数
    ModelCircle.ScaleMin = pIni->value("/Cam4/circle_model_scalemin").toDouble();
    ModelCircle.ScaleMax = pIni->value("/Cam4/circle_model_scalemax").toDouble();
    ModelCircle.MinScore = pIni->value("/Cam4/circle_model_minscore").toDouble();
    //找特征模板匹配参数
    ModelFeature.ScaleMin = pIni->value("/Cam4/feature_model_scalemin").toDouble();
    ModelFeature.ScaleMax = pIni->value("/Cam4/feature_model_scalemax").toDouble();
    ModelFeature.MinScore = pIni->value("/Cam4/feature_model_minscore").toDouble();
}

void QCamera4::initWork()
{
    try
    {
        m_plc = new CPlc(PLC_IP4, PLC_PORT4);
        m_plcThread = new QThread;

        connect(m_plcThread,SIGNAL(finished()),m_plc,SLOT(deleteLater()));
        connect(m_plcThread,SIGNAL(started()),m_plc,SLOT(initFunc()));

        connect(m_plc,&CPlc::plcStates, [&](bool state){

            emit plcState(state);
        });
        connect(this, SIGNAL(sendDateToPlc(bool*,int,int,int)), m_plc, SLOT(writePlc(bool*, int, int, int)), Qt::BlockingQueuedConnection);
        connect(m_plc, &CPlc::sendMess, this, [&](QString excelevel, QString excedata)
        {
            emit sendMess(excelevel, excedata);
        });

        m_plc->moveToThread(m_plcThread);
        m_plcThread->start();
    }
    catch(QException& e)
    {
        emit sendMess("ERROR", "Cam1 Connect PLC QException");
        LOG(ERROR)<<"Cam1 Connect PLC QException";
    }

    int nRet = RegisterImageCallBack(ImageCallBackEx4, this);
    if (MV_OK != nRet)
    {
        QString error = QString("Cam1 Register Image CallBack Failed!");
        emit sendMess("ERROR", error);
        return;
    }
    else
    {
        nRet = StartGrabbing();
        if(MV_OK == nRet)
            CAMERA_STATE = CAMERA_STATE_SHOT;
    }
}

void QCamera4::imageProcess(bool state, unsigned char *data)
{

}
