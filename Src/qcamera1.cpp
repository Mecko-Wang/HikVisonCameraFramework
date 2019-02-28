#include "qcamera1.h"

QCamera1::QCamera1(MV_CC_DEVICE_INFO *device, QHalconWindow *win):CMyCamera(device, win)
{
    m_plcThread = NULL;
    m_plc = NULL;
}
QCamera1::~QCamera1()
{
    m_plcThread->quit();
    m_plcThread->wait(2000);
    delete m_plcThread;

    delete m_plc;
}

//手动连接至PLC
void QCamera1::connectPLC()
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
        m_plc = new CPlc(PLC_IP1, PLC_PORT1);
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

void QCamera1::readModels()
{
    try
    {
        ReadShapeModel("./Model/Cam1_Circle.shm", &Model_Circle);
        ReadShapeModel("./Model/Cam1_Material.shm", &Model_Material);
    }
    catch(HException &he)
    {
        HTuple  Exception;
        he.ToHTuple(&Exception);
        QString error = QString("Cam1 HException:")+QString(Exception.ToString().Text());
        emit sendMess("ERROR", error);

        QByteArray ba = error.toLocal8Bit();
        char* message = ba.data();
        LOG(ERROR)<<message;
    }
}

void QCamera1::readParam()
{
    //创建配置文件
    QSettings *pIni = new QSettings("./params.ini", QSettings::IniFormat);

    //圆形ROI
    Roi.Row = pIni->value("/Cam1/circle_roi_row").toDouble();
    Roi.Col = pIni->value("/Cam1/circle_roi_col").toDouble();
    Roi.Radius = pIni->value("/Cam1/circle_roi_radius").toDouble();
    //物料参数
    Matieral.Radius = pIni->value("/Cam1/material_radius").toDouble();
    Matieral.OffsetLow = pIni->value("/Cam1/material_offsetlow").toDouble();
    Matieral.OffsetHigh = pIni->value("/Cam1/material_offsethigh").toDouble();
    //找圆心模板匹配参数
    ModelCircle.ScaleMin = pIni->value("/Cam1/circle_model_scalemin").toDouble();
    ModelCircle.ScaleMax = pIni->value("/Cam1/circle_model_scalemax").toDouble();
    ModelCircle.MinScore = pIni->value("/Cam1/circle_model_minscore").toDouble();
    //找特征模板匹配参数
    ModelFeature.ScaleMin = pIni->value("/Cam1/feature_model_scalemin").toDouble();
    ModelFeature.ScaleMax = pIni->value("/Cam1/feature_model_scalemax").toDouble();
    ModelFeature.MinScore = pIni->value("/Cam1/feature_model_minscore").toDouble();
}

void QCamera1::initWork()
{
    try
    {
        m_plc = new CPlc(PLC_IP1, PLC_PORT1);
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

    int nRet = RegisterImageCallBack(ImageCallBackEx1, this);
    if (MV_OK != nRet)
    {
        QString error = QString("Cam1 Register Image CallBack Failed!");
        emit sendMess("ERROR", error);

        QByteArray ba = error.toLocal8Bit();
        char* message = ba.data();
        LOG(ERROR)<<message;
        return;
    }
    else
    {
        nRet = StartGrabbing();
        if(MV_OK == nRet)
            CAMERA_STATE = CAMERA_STATE_SHOT;
    }
}

void QCamera1::imageProcess(bool state, unsigned char *data)
{

}
