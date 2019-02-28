
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

const QString IP_Cam1 = "192.168.11.201";
const QString IP_Cam2 = "192.168.11.202";
const QString IP_Cam3 = "192.168.11.203";
const QString IP_Cam4 = "192.168.11.204";
const QString IP_Cam5 = "192.168.11.205";

const double ExposureTime = 10000;

const int ImageWidth = 2448;
const int ImageHeight = 2048;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 设置为主窗口关闭时其余窗口关闭
    this->setAttribute(Qt::WA_QuitOnClose,true);
    setWindowState(Qt::WindowMaximized);

    HalW1 = NULL;
    HalW2 = NULL;
    HalW3 = NULL;
    HalW4 = NULL;
    HalW5 = NULL;

    m_pCamera1 = NULL;
    m_pCamera2 = NULL;
    m_pCamera3 = NULL;
    m_pCamera4 = NULL;
    m_pCamera5 = NULL;

    m_thread1 = NULL;
    m_thread2 = NULL;
    m_thread3 = NULL;
    m_thread4 = NULL;
    m_thread5 = NULL;

    //初始化Glog
    initGlog();

    //显示图像窗口
    HalW1 = new QHalconWindow(ui->widget1, ui->widget1->width(), ui->widget1->height(), ImageHeight-1, ImageWidth-1);
    HalW1->GetHalconBuffer()->SetWindowParam("background_color", "black");
    HalW1->GetHalconBuffer()->SetColor("blue");
    HalW1->GetHalconBuffer()->SetDraw("margin");
    HalW1->GetHalconBuffer()->SetFont("Consolas-Normal-30");

    HalW2 = new QHalconWindow(ui->widget2, ui->widget2->width(), ui->widget2->height(), ImageHeight-1, ImageWidth-1);
    HalW2->GetHalconBuffer()->SetWindowParam("background_color", "black");
    HalW2->GetHalconBuffer()->SetColor("blue");
    HalW2->GetHalconBuffer()->SetDraw("margin");
    HalW2->GetHalconBuffer()->SetFont("Consolas-Normal-30");

    HalW3 = new QHalconWindow(ui->widget3, ui->widget3->width(), ui->widget3->height(), ImageHeight-1, ImageWidth-1);
    HalW3->GetHalconBuffer()->SetWindowParam("background_color", "black");
    HalW3->GetHalconBuffer()->SetColor("blue");
    HalW3->GetHalconBuffer()->SetDraw("margin");
    HalW3->GetHalconBuffer()->SetFont("Consolas-Normal-30");

    HalW4 = new QHalconWindow(ui->widget4, ui->widget4->width(), ui->widget4->height(), ImageHeight-1, ImageWidth-1);
    HalW4->GetHalconBuffer()->SetWindowParam("background_color", "black");
    HalW4->GetHalconBuffer()->SetColor("blue");
    HalW4->GetHalconBuffer()->SetDraw("margin");
    HalW4->GetHalconBuffer()->SetFont("Consolas-Normal-30");

    HalW5 = new QHalconWindow(ui->widget5, ui->widget5->width(), ui->widget5->height(), ImageHeight-1, ImageWidth-1);
    HalW5->GetHalconBuffer()->SetWindowParam("background_color", "black");
    HalW5->GetHalconBuffer()->SetColor("blue");
    HalW5->GetHalconBuffer()->SetDraw("margin");
    HalW5->GetHalconBuffer()->SetFont("Consolas-Normal-30");

    connect(this, SIGNAL(sendMess(QString, QString)), this, SLOT(on_showMessage(QString, QString)));
    connect(this, SIGNAL(dispParamUI()), &paramSetDialog, SLOT(dispParam()));

    connect(&paramSetDialog, SIGNAL(clearHistoryPicture()), this ,SLOT(clearHistoryPicture()));

    m_thread1 = new QThread;
    m_thread2 = new QThread;
    m_thread3 = new QThread;
    m_thread4 = new QThread;
    m_thread5 = new QThread;

    QFile paramsFile("./params.ini");
    if(!paramsFile.exists())
    {
        QSettings *pIni = new QSettings("./params.ini", QSettings::IniFormat);
        pIni->setValue("/Params","init");
        delete pIni;
    }

    emit sendMess("INFO", "Open program.");
    LOG(INFO)<<"Open program.";
}

MainWindow::~MainWindow()
{
    if(m_pCamera1 != NULL)
        m_pCamera1->Close();

    if(m_pCamera2 != NULL)
        m_pCamera2->Close();

    if(m_pCamera3 != NULL)
        m_pCamera3->Close();

    if(m_pCamera4 != NULL)
        m_pCamera4->Close();

    if(m_pCamera5 != NULL)
        m_pCamera5->Close();

    m_thread1->quit();
    m_thread1->wait(2000);
    delete m_thread1;

    m_thread2->quit();
    m_thread2->wait(2000);
    delete m_thread2;

    m_thread3->quit();
    m_thread3->wait(2000);
    delete m_thread3;

    m_thread4->quit();
    m_thread4->wait(2000);
    delete m_thread4;

    m_thread5->quit();
    m_thread5->wait(2000);
    delete m_thread5;

    google::ShutdownGoogleLogging();

    delete ui;
}

void MainWindow::initWork()
{
    //枚举设备，通过IP选择设备，并创建相机设备信息变量
    memset(&m_stDevList, 0, sizeof(MV_CC_DEVICE_INFO_LIST));
    int nRet = -1;
    nRet = CMyCamera::EnumDevices(&m_stDevList);
    if (MV_OK != nRet)
    {
        emit sendMess("WARNING","No device found!");
        LOG(WARNING)<<"No device found!";
    }
    QString strDeviceIP;
    int nIp1 = 0;
    int nIp2 = 0;
    int nIp3 = 0;
    int nIp4 = 0;
    int deviceNum = m_stDevList.nDeviceNum;
    if(deviceNum <= 0)
    {
        ui->label_cam1->setStyleSheet("background:red");
        ui->checkBox_Continuous1->setEnabled(false);
        ui->pb_connectCamera1->setEnabled(true);

        ui->label_cam2->setStyleSheet("background:red");
        ui->checkBox_Continuous2->setEnabled(false);
        ui->pb_connectCamera2->setEnabled(true);

        ui->label_cam3->setStyleSheet("background:red");
        ui->checkBox_Continuous3->setEnabled(false);
        ui->pb_connectCamera3->setEnabled(true);

        ui->label_cam4->setStyleSheet("background:red");
        ui->checkBox_Continuous4->setEnabled(false);
        ui->pb_connectCamera4->setEnabled(true);

        ui->label_cam5->setStyleSheet("background:red");
        ui->checkBox_Continuous5->setEnabled(false);
        ui->pb_connectCamera5->setEnabled(true);

        emit sendMess("WARNING", "No device found!");
        LOG(WARNING)<<"No device found!";
    }
    for ( int i = 0; i < deviceNum; i++)
    {
        MV_CC_DEVICE_INFO* pDeviceInfo = m_stDevList.pDeviceInfo[i];
        if (NULL == pDeviceInfo)
        {
            continue;
        }
        if (pDeviceInfo->nTLayerType == MV_GIGE_DEVICE)
        {
            nIp1 = ((pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0xff000000) >> 24);
            nIp2 = ((pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x00ff0000) >> 16);
            nIp3 = ((pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x0000ff00) >> 8);
            nIp4 = (pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x000000ff);

            strDeviceIP = QString("%1.%2.%3.%4").arg(nIp1).arg(nIp2).arg(nIp3).arg(nIp4);

            //通过IP选择相机设备, 实例化QCcamera对象,打开相机
            //相机1
            if(strDeviceIP == IP_Cam1)
            {
                m_deviceInfo1 = pDeviceInfo;
                m_pCamera1 = new QCamera1(m_deviceInfo1, HalW1);
                nRet = m_pCamera1->Open();
                if(MV_OK == nRet)
                {
                    m_pCamera1->SetEnumValue("ExposureMode", MV_EXPOSURE_MODE_TIMED);//曝光时间设置为定时曝光
                    m_pCamera1->SetEnumValue("ExposureAuto", MV_EXPOSURE_AUTO_MODE_OFF);//自动曝光关闭
                    m_pCamera1->SetFloatValue("ExposureTime", ExposureTime);//曝光时间
                    m_pCamera1->SetFloatValue("AcquisitionFrameRate", 10.0);//帧率设置为10.0
                    m_pCamera1->SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);//打开触发模式
                    m_pCamera1->SetEnumValue("TriggerSource", 0);//设置触发源

                    m_pCamera1->CAMERA_STATE = CAMERA_STATE_CONNECT;//设置相机状态

                    ui->label_cam1->setStyleSheet("background:green");
                    ui->checkBox_Continuous1->setEnabled(true);
                    ui->pb_connectCamera1->setEnabled(false);

                    QString msg = QString("%1%2").arg(tr("Camera opened:")).arg(IP_Cam1);
                    emit sendMess("INFO", msg);

                    QByteArray ba = msg.toLocal8Bit();
                    char* message = ba.data();
                    LOG(INFO)<<message;
                }
                else
                {
                    ui->label_cam1->setStyleSheet("background:red");
                    ui->checkBox_Continuous1->setEnabled(false);
                    ui->pb_connectCamera1->setEnabled(true);

                    m_pCamera1->CAMERA_STATE = CAMERA_STATE_DISCONNECT;
                    QString msg = QString("%1%2").arg(tr("Camera open failed:")).arg(IP_Cam1);
                    emit sendMess("WARNING", msg);

                    QByteArray ba = msg.toLocal8Bit();
                    char* message = ba.data();
                    LOG(WARNING)<<message;
                }
                m_pCamera1->moveToThread(m_thread1);
                connect(m_pCamera1, SIGNAL(frameReceivedSignal1(bool,unsigned char*)), m_pCamera1, SLOT(imageProcess(bool,unsigned char*)),Qt::BlockingQueuedConnection);
                connect(m_pCamera1, SIGNAL(flushWindow()), this, SLOT(on_flushWin1()));
                connect(m_pCamera1, SIGNAL(sendMess(QString, QString)), this, SLOT(on_showMessage(QString, QString)));
                connect(m_pCamera1, SIGNAL(plcState(bool)), this, SLOT(on_plcStateChanged1(bool)));
                connect(m_thread1, SIGNAL(started()), m_pCamera1, SLOT(initWork()));//线程开始时，初始化相机对象
                connect(m_thread1, SIGNAL(finished()), m_pCamera1, SLOT(deleteLater()));//线程结束时，销毁相机对象
                connect(&paramSetDialog, SIGNAL(updateParam()), m_pCamera1, SLOT(readParam()));
                m_thread1->start();
            }

            //相机2
            if(strDeviceIP == IP_Cam2)
            {
                m_deviceInfo2 = pDeviceInfo;
                m_pCamera2 = new QCamera2(m_deviceInfo2, HalW2);
                nRet = m_pCamera2->Open();
                if(MV_OK == nRet)
                {
                    m_pCamera2->SetEnumValue("ExposureMode", MV_EXPOSURE_MODE_TIMED);//曝光时间设置为定时曝光
                    m_pCamera2->SetEnumValue("ExposureAuto", MV_EXPOSURE_AUTO_MODE_OFF);//自动曝光关闭
                    m_pCamera2->SetFloatValue("ExposureTime", ExposureTime);//曝光时间
                    m_pCamera2->SetFloatValue("AcquisitionFrameRate", 10.0);//帧率设置为10.0
                    m_pCamera2->SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);//打开触发模式
                    m_pCamera2->SetEnumValue("TriggerSource", 0);//设置触发源

                    m_pCamera2->CAMERA_STATE = CAMERA_STATE_CONNECT;//设置相机状态

                    ui->label_cam2->setStyleSheet("background:green");
                    ui->checkBox_Continuous2->setEnabled(true);
                    ui->pb_connectCamera2->setEnabled(false);

                    QString msg = QString("%1%2").arg(tr("Camera opened:")).arg(IP_Cam2);
                    emit sendMess("INFO", msg);

                    QByteArray ba = msg.toLocal8Bit();
                    char* message = ba.data();
                    LOG(INFO)<<message;
                }
                else
                {
                    ui->label_cam2->setStyleSheet("background:red");
                    ui->checkBox_Continuous2->setEnabled(false);
                    ui->pb_connectCamera2->setEnabled(true);

                    m_pCamera2->CAMERA_STATE = CAMERA_STATE_DISCONNECT;
                    QString msg = QString("%1%2").arg(tr("Camera open failed:")).arg(IP_Cam2);
                    emit sendMess("WARNING", msg);

                    QByteArray ba = msg.toLocal8Bit();
                    char* message = ba.data();
                    LOG(WARNING)<<message;
                }
                m_pCamera2->moveToThread(m_thread2);
                connect(m_pCamera2, SIGNAL(frameReceivedSignal2(bool,unsigned char*)), m_pCamera2, SLOT(imageProcess(bool,unsigned char*)),Qt::BlockingQueuedConnection);
                connect(m_pCamera2, SIGNAL(flushWindow()), this, SLOT(on_flushWin2()));
                connect(m_pCamera2, SIGNAL(sendMess(QString, QString)), this, SLOT(on_showMessage(QString, QString)));
                connect(m_pCamera2, SIGNAL(plcState(bool)), this, SLOT(on_plcStateChanged2(bool)));
                connect(m_thread2, SIGNAL(started()), m_pCamera2, SLOT(initWork()));
                connect(m_thread2, SIGNAL(finished()), m_pCamera2, SLOT(deleteLater()));
                connect(&paramSetDialog, SIGNAL(updateParam()), m_pCamera2, SLOT(readParam()));
                m_thread2->start();
            }
            
            //相机3
            if(strDeviceIP == IP_Cam3)
            {
                m_deviceInfo3 = pDeviceInfo;
                m_pCamera3 = new QCamera3(m_deviceInfo3, HalW3);
                nRet = m_pCamera3->Open();
                if(MV_OK == nRet)
                {
                    m_pCamera3->SetEnumValue("ExposureMode", MV_EXPOSURE_MODE_TIMED);//曝光时间设置为定时曝光
                    m_pCamera3->SetEnumValue("ExposureAuto", MV_EXPOSURE_AUTO_MODE_OFF);//自动曝光关闭
                    m_pCamera3->SetFloatValue("ExposureTime", ExposureTime);//曝光时间
                    m_pCamera3->SetFloatValue("AcquisitionFrameRate", 10.0);//帧率设置为10.0
                    m_pCamera3->SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);//打开触发模式
                    m_pCamera3->SetEnumValue("TriggerSource", 0);//设置触发源

                    m_pCamera3->CAMERA_STATE = CAMERA_STATE_CONNECT;//设置相机状态

                    ui->label_cam3->setStyleSheet("background:green");
                    ui->checkBox_Continuous3->setEnabled(true);
                    ui->pb_connectCamera3->setEnabled(false);

                    QString msg = QString("%1%2").arg(tr("Camera opened:")).arg(IP_Cam3);
                    emit sendMess("INFO", msg);

                    QByteArray ba = msg.toLocal8Bit();
                    char* message = ba.data();
                    LOG(INFO)<<message;
                }
                else
                {
                    ui->label_cam3->setStyleSheet("background:red");
                    ui->checkBox_Continuous3->setEnabled(false);
                    ui->pb_connectCamera3->setEnabled(true);

                    m_pCamera3->CAMERA_STATE = CAMERA_STATE_DISCONNECT;
                    QString msg = QString("%1%2").arg(tr("Camera open failed:")).arg(IP_Cam3);
                    emit sendMess("WARNING", msg);

                    QByteArray ba = msg.toLocal8Bit();
                    char* message = ba.data();
                    LOG(WARNING)<<message;
                }
                m_pCamera3->moveToThread(m_thread3);
                connect(m_pCamera3, SIGNAL(frameReceivedSignal3(bool,unsigned char*)), m_pCamera3, SLOT(imageProcess(bool,unsigned char*)),Qt::BlockingQueuedConnection);
                connect(m_pCamera3, SIGNAL(flushWindow()), this, SLOT(on_flushWin3()));
                connect(m_pCamera3, SIGNAL(sendMess(QString, QString)), this, SLOT(on_showMessage(QString, QString)));
                connect(m_pCamera3, SIGNAL(plcState(bool)), this, SLOT(on_plcStateChanged3(bool)));
                connect(m_thread3, SIGNAL(started()), m_pCamera3, SLOT(initWork()));
                connect(m_thread3, SIGNAL(finished()), m_pCamera3, SLOT(deleteLater()));
                connect(&paramSetDialog, SIGNAL(updateParam()), m_pCamera3, SLOT(readParam()));
                m_thread3->start();
            }
            
            //相机4
            if(strDeviceIP == IP_Cam4)
            {
                m_deviceInfo4 = pDeviceInfo;
                m_pCamera4 = new QCamera4(m_deviceInfo4, HalW4);
                nRet = m_pCamera4->Open();
                if(MV_OK == nRet)
                {
                    m_pCamera4->SetEnumValue("ExposureMode", MV_EXPOSURE_MODE_TIMED);//曝光时间设置为定时曝光
                    m_pCamera4->SetEnumValue("ExposureAuto", MV_EXPOSURE_AUTO_MODE_OFF);//自动曝光关闭
                    m_pCamera4->SetFloatValue("ExposureTime", ExposureTime);//曝光时间
                    m_pCamera4->SetFloatValue("AcquisitionFrameRate", 10.0);//帧率设置为10.0
                    m_pCamera4->SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);//打开触发模式
                    m_pCamera4->SetEnumValue("TriggerSource", 0);//设置触发源

                    m_pCamera4->CAMERA_STATE = CAMERA_STATE_CONNECT;//设置相机状态

                    ui->label_cam4->setStyleSheet("background:green");
                    ui->checkBox_Continuous4->setEnabled(true);
                    ui->pb_connectCamera4->setEnabled(false);

                    QString msg = QString("%1%2").arg(tr("Camera opened:")).arg(IP_Cam4);
                    emit sendMess("INFO", msg);

                    QByteArray ba = msg.toLocal8Bit();
                    char* message = ba.data();
                    LOG(INFO)<<message;
                }
                else
                {
                    ui->label_cam4->setStyleSheet("background:red");
                    ui->checkBox_Continuous4->setEnabled(false);
                    ui->pb_connectCamera4->setEnabled(true);

                    m_pCamera4->CAMERA_STATE = CAMERA_STATE_DISCONNECT;
                    QString msg = QString("%1%2").arg(tr("Camera open failed:")).arg(IP_Cam4);
                    emit sendMess("WARNING", msg);

                    QByteArray ba = msg.toLocal8Bit();
                    char* message = ba.data();
                    LOG(WARNING)<<message;
                }
                m_pCamera4->moveToThread(m_thread4);
                connect(m_pCamera4, SIGNAL(frameReceivedSignal4(bool,unsigned char*)), m_pCamera4, SLOT(imageProcess(bool,unsigned char*)),Qt::BlockingQueuedConnection);
                connect(m_pCamera4, SIGNAL(flushWindow()), this, SLOT(on_flushWin4()));
                connect(m_pCamera4, SIGNAL(sendMess(QString, QString)), this, SLOT(on_showMessage(QString, QString)));
                connect(m_pCamera4, SIGNAL(plcState(bool)), this, SLOT(on_plcStateChanged4(bool)));
                connect(m_thread4, SIGNAL(started()), m_pCamera4, SLOT(initWork()));
                connect(m_thread4, SIGNAL(finished()), m_pCamera4, SLOT(deleteLater()));
                connect(&paramSetDialog, SIGNAL(updateParam()), m_pCamera4, SLOT(readParam()));
                m_thread4->start();
            }
            
            //相机5
            if(strDeviceIP == IP_Cam5)
            {
                m_deviceInfo5 = pDeviceInfo;
                m_pCamera5 = new QCamera5(m_deviceInfo5, HalW5);
                nRet = m_pCamera5->Open();
                if(MV_OK == nRet)
                {
                    m_pCamera5->SetEnumValue("ExposureMode", MV_EXPOSURE_MODE_TIMED);//曝光时间设置为定时曝光
                    m_pCamera5->SetEnumValue("ExposureAuto", MV_EXPOSURE_AUTO_MODE_OFF);//自动曝光关闭
                    m_pCamera5->SetFloatValue("ExposureTime", ExposureTime);//曝光时间
                    m_pCamera5->SetFloatValue("AcquisitionFrameRate", 10.0);//帧率设置为10.0
                    m_pCamera5->SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);//打开触发模式
                    m_pCamera5->SetEnumValue("TriggerSource", 0);//设置触发源

                    m_pCamera5->CAMERA_STATE = CAMERA_STATE_CONNECT;//设置相机状态

                    ui->label_cam5->setStyleSheet("background:green");
                    ui->checkBox_Continuous5->setEnabled(true);
                    ui->pb_connectCamera5->setEnabled(false);

                    QString msg = QString("%1%2").arg(tr("Camera opened:")).arg(IP_Cam5);
                    emit sendMess("INFO", msg);

                    QByteArray ba = msg.toLocal8Bit();
                    char* message = ba.data();
                    LOG(INFO)<<message;
                }
                else
                {
                    ui->label_cam5->setStyleSheet("background:red");
                    ui->checkBox_Continuous5->setEnabled(false);
                    ui->pb_connectCamera5->setEnabled(true);

                    m_pCamera5->CAMERA_STATE = CAMERA_STATE_DISCONNECT;
                    QString msg = QString("%1%2").arg(tr("Camera open failed:")).arg(IP_Cam5);
                    emit sendMess("WARNING", msg);

                    QByteArray ba = msg.toLocal8Bit();
                    char* message = ba.data();
                    LOG(WARNING)<<message;
                }
                m_pCamera5->moveToThread(m_thread5);
                connect(m_pCamera5, SIGNAL(frameReceivedSignal5(bool,unsigned char*)), m_pCamera5, SLOT(imageProcess(bool,unsigned char*)),Qt::BlockingQueuedConnection);
                connect(m_pCamera5, SIGNAL(flushWindow()), this, SLOT(on_flushWin5()));
                connect(m_pCamera5, SIGNAL(sendMess(QString, QString)), this, SLOT(on_showMessage(QString, QString)));
                connect(m_pCamera5, SIGNAL(plcState(bool)), this, SLOT(on_plcStateChanged5(bool)));
                connect(m_thread5, SIGNAL(started()), m_pCamera5, SLOT(initWork()));
                connect(m_thread5, SIGNAL(finished()), m_pCamera5, SLOT(deleteLater()));
                connect(&paramSetDialog, SIGNAL(updateParam()), m_pCamera5, SLOT(readParam()));
                m_thread2->start();
            }
        }
        //一切准备成功，则使"开始"按钮可用
        if(checkEverythingReady())
        {
            ui->pb_Start->setEnabled(true);
        }
    }
}

//初始化Glog日志类
void MainWindow::initGlog()
{
    QDir dir;
    if(!dir.exists("./logfiles/INFO"))
        dir.mkpath("./logfiles/INFO");
    if(!dir.exists("./logfiles/WARNING"))
        dir.mkpath("./logfiles/WARNING");
    if(!dir.exists("./logfiles/ERROR"))
        dir.mkpath("./logfiles/ERROR");

    google::InitGoogleLogging("");

    //google::SetStderrLogging(google::GLOG_INFO); //设置级别高于 google::INFO 的日志同时输出到屏幕
    google::SetLogDestination(google::GLOG_INFO,"./logfiles/INFO/INFO_"); //设置 google::INFO 级别的日志存储路径和文件名前缀
    google::SetLogDestination(google::GLOG_WARNING,"./logfiles/WARNING/WARNING_");   //设置 google::WARNING 级别的日志存储路径和文件名前缀
    google::SetLogDestination(google::GLOG_ERROR,"./logfiles/ERROR/ERROR_");   //设置 google::ERROR 级别的日志存储路径和文件名前缀
    google::SetLogFilenameExtension("Qt_");     //设置文件名扩展

    FLAGS_colorlogtostderr = true;    //设置输出到屏幕的日志显示相应颜色
    FLAGS_logbufsecs = 0;        //缓冲日志输出，默认为30秒，此处改为立即输出
    FLAGS_max_log_size = 100;    //最大日志大小为 100MB
    FLAGS_stop_logging_if_full_disk = true;     //当磁盘被写满时，停止日志输出
}

bool MainWindow::checkEverythingReady()
{
    if(
            //所有相机打开成功
            (NULL != m_pCamera1) && (NULL != m_pCamera2) && (NULL != m_pCamera3) && (NULL != m_pCamera4) && (NULL != m_pCamera5)
            //所有相机处于触发拍照模式
            && m_pCamera1->CAMERA_STATE == CAMERA_STATE_SHOT && m_pCamera2->CAMERA_STATE == CAMERA_STATE_SHOT
            && m_pCamera3->CAMERA_STATE == CAMERA_STATE_SHOT && m_pCamera4->CAMERA_STATE == CAMERA_STATE_SHOT
            && m_pCamera5->CAMERA_STATE == CAMERA_STATE_SHOT
            //所有PLC连接成功
            && m_pCamera1->PLC_STATE == PLC_CONNECT && m_pCamera2->PLC_STATE == PLC_CONNECT
            && m_pCamera3->PLC_STATE == PLC_CONNECT && m_pCamera4->PLC_STATE == PLC_CONNECT
            && m_pCamera5->PLC_STATE == PLC_CONNECT)
    {
        return true;
    }
    else
        return false;
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    bool ok;
    QString str = QInputDialog::getText(this,tr("密码核对"),tr("请输入密码："),QLineEdit::Password,"",&ok);
    if(ok)
    {
        if(str == QString("aac"))
        {
            emit sendMess("INFO", "Exit program.");
            LOG(INFO)<<"Exit program.";
            e->accept();
        }
        else
        {
            //QMessageBox提示密码错误
            e->ignore();
            QMessageBox errorBox;
            errorBox.setText("code error!!!");
            errorBox.exec();
        }
    }
    else
    {
        e->ignore();
    }
}

void MainWindow::on_pb_Start_clicked()
{
    if(checkEverythingReady())
    {
        ui->pb_Start->setEnabled(false);
        ui->pb_Stop->setEnabled(true);
        globle_param::m_run_mode  = true;

        ui->checkBox_Continuous1->setEnabled(false);
        ui->checkBox_Continuous2->setEnabled(false);
        ui->checkBox_Continuous3->setEnabled(false);
        ui->checkBox_Continuous4->setEnabled(false);
        ui->checkBox_Continuous5->setEnabled(false);
    }
}

void MainWindow::on_pb_Stop_clicked()
{
    ui->pb_Stop->setEnabled(false);
    globle_param::m_run_mode  = false;

    if(m_pCamera1->CAMERA_STATE == CAMERA_STATE_SHOT)
        ui->checkBox_Continuous1->setEnabled(true);
    if(m_pCamera2->CAMERA_STATE == CAMERA_STATE_SHOT)
        ui->checkBox_Continuous2->setEnabled(true);
    if(m_pCamera3->CAMERA_STATE == CAMERA_STATE_SHOT)
        ui->checkBox_Continuous3->setEnabled(true);
    if(m_pCamera4->CAMERA_STATE == CAMERA_STATE_SHOT)
        ui->checkBox_Continuous4->setEnabled(true);
    if(m_pCamera5->CAMERA_STATE == CAMERA_STATE_SHOT)
        ui->checkBox_Continuous5->setEnabled(true);

    if(checkEverythingReady())
        ui->pb_Start->setEnabled(true);
}

void MainWindow::on_showMessage(QString excelevel, QString excedata)
{
    QTime m_currentTime = QTime::currentTime();
    QString dispmsg = QString("[%1][%2] %3").arg(m_currentTime.toString("hh:mm:ss")).arg(excelevel).arg(excedata);
    qDebug()<<dispmsg;

    ui->edit_message->append(dispmsg);
    QTextCursor cursor = ui->edit_message->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->edit_message->setTextCursor(cursor);
}

void MainWindow::on_flushWin1()
{
    HalW1->GetHalconBuffer()->FlushBuffer();
}

void MainWindow::on_flushWin2()
{
    HalW2->GetHalconBuffer()->FlushBuffer();
}

void MainWindow::on_flushWin3()
{
    HalW3->GetHalconBuffer()->FlushBuffer();
}

void MainWindow::on_flushWin4()
{
    HalW4->GetHalconBuffer()->FlushBuffer();
}

void MainWindow::on_flushWin5()
{
    HalW5->GetHalconBuffer()->FlushBuffer();
}

void MainWindow::clearPic(QString dirc)
{
    if(QFile::exists(dirc))
    {
        QDir pic(dirc);
        QStringList nameFilters;
        nameFilters<<"*.bmp";
        QStringList files = pic.entryList(nameFilters, QDir::Files|QDir::Readable, QDir::Name);

        for(int i=0; i<files.length(); i++)
        {
            pic.remove(files[i]);
        }
    }
}

//清理所有历史图像
void MainWindow::clearHistoryPicture()
{
    clearPic("./BMP/CAM1/TEST/");
    clearPic("./BMP/CAM1/OK/");
    clearPic("./BMP/CAM1/NG/");

    clearPic("./BMP/CAM2/TEST/");
    clearPic("./BMP/CAM2/OK/");
    clearPic("./BMP/CAM2/NG/");

    clearPic("./BMP/CAM3/TEST/");
    clearPic("./BMP/CAM3/OK/");
    clearPic("./BMP/CAM3/NG/");

    clearPic("./BMP/CAM3/TEST/");
    clearPic("./BMP/CAM3/OK/");
    clearPic("./BMP/CAM3/NG/");

    clearPic("./BMP/CAM4/TEST/");
    clearPic("./BMP/CAM4/OK/");
    clearPic("./BMP/CAM4/NG/");

    clearPic("./BMP/CAM5/TEST/");
    clearPic("./BMP/CAM5/OK/");
    clearPic("./BMP/CAM5/NG/");


    QMessageBox clearDoneBox;
    clearDoneBox.setText("CLEAR DONE");
    clearDoneBox.exec();
}

void MainWindow::on_plcStateChanged1(bool state)
{
    if(state)
    {
        ui->lb_PlcState1->setStyleSheet("background:green");
        m_pCamera1->PLC_STATE = PLC_CONNECT;
    }
    else
    {
        ui->lb_PlcState1->setStyleSheet("background:red");
        m_pCamera1->PLC_STATE = PLC_DISCONNECT;
    }
    //相机打开成功，PLC连接成功，则使"开始"按钮可用
    if(checkEverythingReady())
    {
        ui->pb_Start->setEnabled(true);
    }
    else
    {
        on_pb_Stop_clicked();
    }
}

void MainWindow::on_plcStateChanged2(bool state)
{
    if(state)
    {
        ui->lb_PlcState2->setStyleSheet("background:green");
        m_pCamera2->PLC_STATE = PLC_CONNECT;
    }
    else
    {
        ui->lb_PlcState2->setStyleSheet("background:red");
        m_pCamera2->PLC_STATE = PLC_DISCONNECT;
    }
    //相机打开成功，PLC连接成功，则使"开始"按钮可用
    if(checkEverythingReady())
    {
        ui->pb_Start->setEnabled(true);
    }
    else
    {
        on_pb_Stop_clicked();
    }
}

void MainWindow::on_plcStateChanged3(bool state)
{
    if(state)
    {
        ui->lb_PlcState3->setStyleSheet("background:green");
        m_pCamera3->PLC_STATE = PLC_CONNECT;
    }
    else
    {
        ui->lb_PlcState3->setStyleSheet("background:red");
        m_pCamera3->PLC_STATE = PLC_DISCONNECT;
    }
    //相机打开成功，PLC连接成功，则使"开始"按钮可用
    if(checkEverythingReady())
    {
        ui->pb_Start->setEnabled(true);
    }
    else
    {
        on_pb_Stop_clicked();
    }
}

void MainWindow::on_plcStateChanged4(bool state)
{
    if(state)
    {
        ui->lb_PlcState4->setStyleSheet("background:green");
        m_pCamera4->PLC_STATE = PLC_CONNECT;
    }
    else
    {
        ui->lb_PlcState4->setStyleSheet("background:red");
        m_pCamera4->PLC_STATE = PLC_DISCONNECT;
    }
    //相机打开成功，PLC连接成功，则使"开始"按钮可用
    if(checkEverythingReady())
    {
        ui->pb_Start->setEnabled(true);
    }
    else
    {
        on_pb_Stop_clicked();
    }
}

void MainWindow::on_plcStateChanged5(bool state)
{
    if(state)
    {
        ui->lb_PlcState5->setStyleSheet("background:green");
        m_pCamera5->PLC_STATE = PLC_CONNECT;
    }
    else
    {
        ui->lb_PlcState5->setStyleSheet("background:red");
        m_pCamera5->PLC_STATE = PLC_DISCONNECT;
    }
    //相机打开成功，PLC连接成功，则使"开始"按钮可用
    if(checkEverythingReady())
    {
        ui->pb_Start->setEnabled(true);
    }
    else
    {
        on_pb_Stop_clicked();
    }
}

void MainWindow::on_pb_connectCamera1_clicked()
{
    int nRet = -1;
    nRet = CMyCamera::EnumDevices(&m_stDevList);
    if (MV_OK != nRet)
    {
        emit sendMess("WARNING", "No device found!");
        LOG(WARNING)<<"No device found!";
    }
    QString strDeviceIP;
    int nIp1 = 0;
    int nIp2 = 0;
    int nIp3 = 0;
    int nIp4 = 0;
    int deviceNum = m_stDevList.nDeviceNum;
    if(deviceNum <= 0)
    {
        ui->label_cam1->setStyleSheet("background:red");
        ui->checkBox_Continuous1->setEnabled(false);
        ui->pb_connectCamera1->setEnabled(true);

        ui->label_cam2->setStyleSheet("background:red");
        ui->checkBox_Continuous2->setEnabled(false);
        ui->pb_connectCamera2->setEnabled(true);

        ui->label_cam3->setStyleSheet("background:red");
        ui->checkBox_Continuous3->setEnabled(false);
        ui->pb_connectCamera3->setEnabled(true);

        ui->label_cam4->setStyleSheet("background:red");
        ui->checkBox_Continuous4->setEnabled(false);
        ui->pb_connectCamera4->setEnabled(true);

        ui->label_cam5->setStyleSheet("background:red");
        ui->checkBox_Continuous5->setEnabled(false);
        ui->pb_connectCamera5->setEnabled(true);

        emit sendMess("WARNING", "No device!");
        LOG(WARNING)<<"No device!";
    }
    for(int i = 0; i < deviceNum; i++)
    {
        MV_CC_DEVICE_INFO* pDeviceInfo = m_stDevList.pDeviceInfo[i];
        if (NULL == pDeviceInfo)
        {
            continue;
        }
        if (pDeviceInfo->nTLayerType == MV_GIGE_DEVICE)
        {
            nIp1 = ((pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0xff000000) >> 24);
            nIp2 = ((pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x00ff0000) >> 16);
            nIp3 = ((pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x0000ff00) >> 8);
            nIp4 = (pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x000000ff);

            strDeviceIP = QString("%1.%2.%3.%4").arg(nIp1).arg(nIp2).arg(nIp3).arg(nIp4);

            //通过IP选择相机设备, 实例化QCcamera对象,打开相机
            //相机1
            if(strDeviceIP == IP_Cam1)
            {
                m_deviceInfo1 = pDeviceInfo;
                m_pCamera1 = new QCamera1(m_deviceInfo1, HalW1);
                nRet = m_pCamera1->Open();
                if(MV_OK == nRet)
                {
                    m_pCamera1->SetEnumValue("ExposureMode", MV_EXPOSURE_MODE_TIMED);//曝光时间设置为定时曝光
                    m_pCamera1->SetEnumValue("ExposureAuto", MV_EXPOSURE_AUTO_MODE_OFF);//自动曝光关闭
                    m_pCamera1->SetFloatValue("ExposureTime", ExposureTime);//曝光时间
                    m_pCamera1->SetFloatValue("AcquisitionFrameRate", 10.0);//帧率设置为10.0
                    m_pCamera1->SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);//打开触发模式
                    m_pCamera1->SetEnumValue("TriggerSource", 0);//设置触发源

                    m_pCamera1->CAMERA_STATE = CAMERA_STATE_CONNECT;//设置相机状态

                    ui->label_cam1->setStyleSheet("background:green");
                    ui->checkBox_Continuous1->setEnabled(true);
                    ui->pb_connectCamera1->setEnabled(false);

                    QString msg = QString("%1%2").arg(tr("Camera opened:")).arg(IP_Cam1);
                    emit sendMess("INFO", msg);

                    QByteArray ba = msg.toLocal8Bit();
                    char* message = ba.data();
                    LOG(INFO)<<message;
                }
                else
                {
                    ui->label_cam1->setStyleSheet("background:red");
                    ui->checkBox_Continuous1->setEnabled(false);
                    ui->pb_connectCamera1->setEnabled(true);

                    m_pCamera1->CAMERA_STATE = CAMERA_STATE_DISCONNECT;
                    QString msg = QString("%1%2").arg(tr("Camera open failed:")).arg(IP_Cam1);
                    emit sendMess("WARNING", msg);

                    QByteArray ba = msg.toLocal8Bit();
                    char* message = ba.data();
                    LOG(WARNING)<<message;
                }
                m_pCamera1->moveToThread(m_thread1);
                connect(m_pCamera1, SIGNAL(frameReceivedSignal1(bool, unsigned char*)), m_pCamera1, SLOT(imageProcess(bool,unsigned char*)),Qt::BlockingQueuedConnection);
                connect(m_pCamera1, SIGNAL(flushWindow()), this, SLOT(on_flushWin1()));
                connect(m_pCamera1, SIGNAL(sendMess(QString, QString)), this, SLOT(on_showMessage(QString, QString)));
                connect(m_pCamera1, SIGNAL(plcState(bool)), this, SLOT(on_plcStateChanged1(bool)));
                connect(m_thread1, SIGNAL(started()), m_pCamera1, SLOT(initWork()));
                connect(m_thread1, SIGNAL(finished()), m_pCamera1, SLOT(deleteLater()));
                connect(&paramSetDialog, SIGNAL(updateParam()), m_pCamera1, SLOT(readParam()));
                m_thread1->start();
            }
        }
    }
    //相机打开成功，PLC连接成功，则使"开始"按钮可用
    if(checkEverythingReady())
    {
        ui->pb_Start->setEnabled(true);
    }
}

void MainWindow::on_pb_connectCamera2_clicked()
{
    int nRet = -1;
    nRet = CMyCamera::EnumDevices(&m_stDevList);
    if (MV_OK != nRet)
    {
        emit sendMess("WARNING", "No device found!");
        LOG(WARNING)<<"No device found!";
    }
    QString strDeviceIP;
    int nIp1 = 0;
    int nIp2 = 0;
    int nIp3 = 0;
    int nIp4 = 0;
    int deviceNum = m_stDevList.nDeviceNum;
    if(deviceNum <= 0)
    {
        ui->label_cam1->setStyleSheet("background:red");
        ui->checkBox_Continuous1->setEnabled(false);
        ui->pb_connectCamera1->setEnabled(true);

        ui->label_cam2->setStyleSheet("background:red");
        ui->checkBox_Continuous2->setEnabled(false);
        ui->pb_connectCamera2->setEnabled(true);

        ui->label_cam3->setStyleSheet("background:red");
        ui->checkBox_Continuous3->setEnabled(false);
        ui->pb_connectCamera3->setEnabled(true);

        ui->label_cam4->setStyleSheet("background:red");
        ui->checkBox_Continuous4->setEnabled(false);
        ui->pb_connectCamera4->setEnabled(true);

        ui->label_cam5->setStyleSheet("background:red");
        ui->checkBox_Continuous5->setEnabled(false);
        ui->pb_connectCamera5->setEnabled(true);

        emit sendMess("WARNING", "No device!");
        LOG(WARNING)<<"No device!";
    }
    for(int i = 0; i < deviceNum; i++)
    {
        MV_CC_DEVICE_INFO* pDeviceInfo = m_stDevList.pDeviceInfo[i];
        if (NULL == pDeviceInfo)
        {
            continue;
        }
        if (pDeviceInfo->nTLayerType == MV_GIGE_DEVICE)
        {
            nIp1 = ((pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0xff000000) >> 24);
            nIp2 = ((pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x00ff0000) >> 16);
            nIp3 = ((pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x0000ff00) >> 8);
            nIp4 = (pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x000000ff);

            strDeviceIP = QString("%1.%2.%3.%4").arg(nIp1).arg(nIp2).arg(nIp3).arg(nIp4);

            //通过IP选择相机设备, 实例化QCcamera对象,打开相机
            //相机2
            if(strDeviceIP == IP_Cam2)
            {
                m_deviceInfo2 = pDeviceInfo;
                m_pCamera2 = new QCamera2(m_deviceInfo2, HalW2);
                nRet = m_pCamera2->Open();
                if(MV_OK == nRet)
                {
                    m_pCamera2->SetEnumValue("ExposureMode", MV_EXPOSURE_MODE_TIMED);//曝光时间设置为定时曝光
                    m_pCamera2->SetEnumValue("ExposureAuto", MV_EXPOSURE_AUTO_MODE_OFF);//自动曝光关闭
                    m_pCamera2->SetFloatValue("ExposureTime", ExposureTime);//曝光时间
                    m_pCamera2->SetFloatValue("AcquisitionFrameRate", 10.0);//帧率设置为10.0
                    m_pCamera2->SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);//打开触发模式
                    m_pCamera2->SetEnumValue("TriggerSource", 0);//设置触发源

                    m_pCamera2->CAMERA_STATE = CAMERA_STATE_CONNECT;//设置相机状态

                    ui->label_cam2->setStyleSheet("background:green");
                    ui->checkBox_Continuous2->setEnabled(true);
                    ui->pb_connectCamera2->setEnabled(false);

                    QString msg = QString("%1%2").arg(tr("Camera opened:")).arg(IP_Cam2);
                    emit sendMess("INFO", msg);

                    QByteArray ba = msg.toLocal8Bit();
                    char* message = ba.data();
                    LOG(INFO)<<message;
                }
                else
                {
                    ui->label_cam2->setStyleSheet("background:red");
                    ui->checkBox_Continuous2->setEnabled(false);
                    ui->pb_connectCamera2->setEnabled(true);

                    m_pCamera2->CAMERA_STATE = CAMERA_STATE_DISCONNECT;
                    QString msg = QString("%1%2").arg(tr("Camera open failed:")).arg(IP_Cam2);
                    emit sendMess("WARNING", msg);

                    QByteArray ba = msg.toLocal8Bit();
                    char* message = ba.data();
                    LOG(WARNING)<<message;
                }
                m_pCamera2->moveToThread(m_thread2);
                connect(m_pCamera2, SIGNAL(frameReceivedSignal2(bool,unsigned char*)), m_pCamera2, SLOT(imageProcess(bool,unsigned char*)),Qt::BlockingQueuedConnection);
                connect(m_pCamera2, SIGNAL(flushWindow()), this, SLOT(on_flushWin2()));
                connect(m_pCamera2, SIGNAL(sendMess(QString, QString)), this, SLOT(on_showMessage(QString, QString)));
                connect(m_pCamera2, SIGNAL(plcState(bool)), this, SLOT(on_plcStateChanged2(bool)));
                connect(m_thread2, SIGNAL(started()), m_pCamera2, SLOT(initWork()));
                connect(m_thread2, SIGNAL(finished()), m_pCamera2, SLOT(deleteLater()));
                connect(&paramSetDialog, SIGNAL(updateParam()), m_pCamera2, SLOT(readParam()));
                m_thread2->start();
            }
        }
    }
    //相机打开成功，PLC连接成功，则使"开始"按钮可用
    if(checkEverythingReady())
    {
        ui->pb_Start->setEnabled(true);
    }
}

void MainWindow::on_pb_connectCamera3_clicked()
{
    int nRet = -1;
    nRet = CMyCamera::EnumDevices(&m_stDevList);
    if (MV_OK != nRet)
    {
        emit sendMess("WARNING", "No device found!");
        LOG(WARNING)<<"No device found!";
    }
    QString strDeviceIP;
    int nIp1 = 0;
    int nIp2 = 0;
    int nIp3 = 0;
    int nIp4 = 0;
    int deviceNum = m_stDevList.nDeviceNum;
    if(deviceNum <= 0)
    {
        ui->label_cam1->setStyleSheet("background:red");
        ui->checkBox_Continuous1->setEnabled(false);
        ui->pb_connectCamera1->setEnabled(true);

        ui->label_cam2->setStyleSheet("background:red");
        ui->checkBox_Continuous2->setEnabled(false);
        ui->pb_connectCamera2->setEnabled(true);

        ui->label_cam3->setStyleSheet("background:red");
        ui->checkBox_Continuous3->setEnabled(false);
        ui->pb_connectCamera3->setEnabled(true);

        ui->label_cam4->setStyleSheet("background:red");
        ui->checkBox_Continuous4->setEnabled(false);
        ui->pb_connectCamera4->setEnabled(true);

        ui->label_cam5->setStyleSheet("background:red");
        ui->checkBox_Continuous5->setEnabled(false);
        ui->pb_connectCamera5->setEnabled(true);

        emit sendMess("WARNING", "No device!");
        LOG(WARNING)<<"No device!";
    }
    for(int i = 0; i < deviceNum; i++)
    {
        MV_CC_DEVICE_INFO* pDeviceInfo = m_stDevList.pDeviceInfo[i];
        if (NULL == pDeviceInfo)
        {
            continue;
        }
        if (pDeviceInfo->nTLayerType == MV_GIGE_DEVICE)
        {
            nIp1 = ((pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0xff000000) >> 24);
            nIp2 = ((pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x00ff0000) >> 16);
            nIp3 = ((pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x0000ff00) >> 8);
            nIp4 = (pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x000000ff);

            strDeviceIP = QString("%1.%2.%3.%4").arg(nIp1).arg(nIp2).arg(nIp3).arg(nIp4);

            //通过IP选择相机设备, 实例化QCcamera对象,打开相机
            //相机3
            if(strDeviceIP == IP_Cam3)
            {
                m_deviceInfo3 = pDeviceInfo;
                m_pCamera3 = new QCamera3(m_deviceInfo3, HalW3);
                nRet = m_pCamera3->Open();
                if(MV_OK == nRet)
                {
                    m_pCamera3->SetEnumValue("ExposureMode", MV_EXPOSURE_MODE_TIMED);//曝光时间设置为定时曝光
                    m_pCamera3->SetEnumValue("ExposureAuto", MV_EXPOSURE_AUTO_MODE_OFF);//自动曝光关闭
                    m_pCamera3->SetFloatValue("ExposureTime", ExposureTime);//曝光时间
                    m_pCamera3->SetFloatValue("AcquisitionFrameRate", 10.0);//帧率设置为10.0
                    m_pCamera3->SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);//打开触发模式
                    m_pCamera3->SetEnumValue("TriggerSource", 0);//设置触发源

                    m_pCamera3->CAMERA_STATE = CAMERA_STATE_CONNECT;//设置相机状态

                    ui->label_cam3->setStyleSheet("background:green");
                    ui->checkBox_Continuous3->setEnabled(true);
                    ui->pb_connectCamera3->setEnabled(false);

                    QString msg = QString("%1%2").arg(tr("Camera opened:")).arg(IP_Cam3);
                    emit sendMess("INFO", msg);

                    QByteArray ba = msg.toLocal8Bit();
                    char* message = ba.data();
                    LOG(INFO)<<message;
                }
                else
                {
                    ui->label_cam3->setStyleSheet("background:red");
                    ui->checkBox_Continuous3->setEnabled(false);
                    ui->pb_connectCamera3->setEnabled(true);

                    m_pCamera3->CAMERA_STATE = CAMERA_STATE_DISCONNECT;
                    QString msg = QString("%1%2").arg(tr("Camera open failed:")).arg(IP_Cam3);
                    emit sendMess("WARNING", msg);

                    QByteArray ba = msg.toLocal8Bit();
                    char* message = ba.data();
                    LOG(WARNING)<<message;
                }
                m_pCamera3->moveToThread(m_thread3);
                connect(m_pCamera3, SIGNAL(frameReceivedSignal3(bool,unsigned char*)), m_pCamera3, SLOT(imageProcess(bool,unsigned char*)),Qt::BlockingQueuedConnection);
                connect(m_pCamera3, SIGNAL(flushWindow()), this, SLOT(on_flushWin3()));
                connect(m_pCamera3, SIGNAL(sendMess(QString, QString)), this, SLOT(on_showMessage(QString, QString)));
                connect(m_pCamera3, SIGNAL(plcState(bool)), this, SLOT(on_plcStateChanged3(bool)));
                connect(m_thread3, SIGNAL(started()), m_pCamera3, SLOT(initWork()));
                connect(m_thread3, SIGNAL(finished()), m_pCamera3, SLOT(deleteLater()));
                connect(&paramSetDialog, SIGNAL(updateParam()), m_pCamera3, SLOT(readParam()));
                m_thread3->start();
            }
        }
    }
    //相机打开成功，PLC连接成功，则使"开始"按钮可用
    if(checkEverythingReady())
    {
        ui->pb_Start->setEnabled(true);
    }
}

void MainWindow::on_pb_connectCamera4_clicked()
{
    int nRet = -1;
    nRet = CMyCamera::EnumDevices(&m_stDevList);
    if (MV_OK != nRet)
    {
        emit sendMess("WARNING", "No device found!");
        LOG(WARNING)<<"No device found!";
    }
    QString strDeviceIP;
    int nIp1 = 0;
    int nIp2 = 0;
    int nIp3 = 0;
    int nIp4 = 0;
    int deviceNum = m_stDevList.nDeviceNum;
    if(deviceNum <= 0)
    {
        ui->label_cam1->setStyleSheet("background:red");
        ui->checkBox_Continuous1->setEnabled(false);
        ui->pb_connectCamera1->setEnabled(true);

        ui->label_cam2->setStyleSheet("background:red");
        ui->checkBox_Continuous2->setEnabled(false);
        ui->pb_connectCamera2->setEnabled(true);

        ui->label_cam3->setStyleSheet("background:red");
        ui->checkBox_Continuous3->setEnabled(false);
        ui->pb_connectCamera3->setEnabled(true);

        ui->label_cam4->setStyleSheet("background:red");
        ui->checkBox_Continuous4->setEnabled(false);
        ui->pb_connectCamera4->setEnabled(true);

        ui->label_cam5->setStyleSheet("background:red");
        ui->checkBox_Continuous5->setEnabled(false);
        ui->pb_connectCamera5->setEnabled(true);

        emit sendMess("WARNING", "No device!");
        LOG(WARNING)<<"No device!";
    }
    for(int i = 0; i < deviceNum; i++)
    {
        MV_CC_DEVICE_INFO* pDeviceInfo = m_stDevList.pDeviceInfo[i];
        if (NULL == pDeviceInfo)
        {
            continue;
        }
        if (pDeviceInfo->nTLayerType == MV_GIGE_DEVICE)
        {
            nIp1 = ((pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0xff000000) >> 24);
            nIp2 = ((pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x00ff0000) >> 16);
            nIp3 = ((pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x0000ff00) >> 8);
            nIp4 = (pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x000000ff);

            strDeviceIP = QString("%1.%2.%3.%4").arg(nIp1).arg(nIp2).arg(nIp3).arg(nIp4);

            //通过IP选择相机设备, 实例化QCcamera对象,打开相机
            //相机2
            if(strDeviceIP == IP_Cam4)
            {
                m_deviceInfo4 = pDeviceInfo;
                m_pCamera4 = new QCamera4(m_deviceInfo4, HalW4);
                nRet = m_pCamera4->Open();
                if(MV_OK == nRet)
                {
                    m_pCamera4->SetEnumValue("ExposureMode", MV_EXPOSURE_MODE_TIMED);//曝光时间设置为定时曝光
                    m_pCamera4->SetEnumValue("ExposureAuto", MV_EXPOSURE_AUTO_MODE_OFF);//自动曝光关闭
                    m_pCamera4->SetFloatValue("ExposureTime", ExposureTime);//曝光时间
                    m_pCamera4->SetFloatValue("AcquisitionFrameRate", 10.0);//帧率设置为10.0
                    m_pCamera4->SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);//打开触发模式
                    m_pCamera4->SetEnumValue("TriggerSource", 0);//设置触发源

                    m_pCamera4->CAMERA_STATE = CAMERA_STATE_CONNECT;//设置相机状态

                    ui->label_cam4->setStyleSheet("background:green");
                    ui->checkBox_Continuous4->setEnabled(true);
                    ui->pb_connectCamera4->setEnabled(false);

                    QString msg = QString("%1%2").arg(tr("Camera opened:")).arg(IP_Cam4);
                    emit sendMess("INFO", msg);

                    QByteArray ba = msg.toLocal8Bit();
                    char* message = ba.data();
                    LOG(INFO)<<message;
                }
                else
                {
                    ui->label_cam4->setStyleSheet("background:red");
                    ui->checkBox_Continuous4->setEnabled(false);
                    ui->pb_connectCamera4->setEnabled(true);

                    m_pCamera4->CAMERA_STATE = CAMERA_STATE_DISCONNECT;
                    QString msg = QString("%1%2").arg(tr("Camera open failed:")).arg(IP_Cam4);
                    emit sendMess("WARNING", msg);

                    QByteArray ba = msg.toLocal8Bit();
                    char* message = ba.data();
                    LOG(WARNING)<<message;
                }
                m_pCamera4->moveToThread(m_thread4);
                connect(m_pCamera4, SIGNAL(frameReceivedSignal4(bool,unsigned char*)), m_pCamera4, SLOT(imageProcess(bool,unsigned char*)),Qt::BlockingQueuedConnection);
                connect(m_pCamera4, SIGNAL(flushWindow()), this, SLOT(on_flushWin4()));
                connect(m_pCamera4, SIGNAL(sendMess(QString, QString)), this, SLOT(on_showMessage(QString, QString)));
                connect(m_pCamera4, SIGNAL(plcState(bool)), this, SLOT(on_plcStateChanged4(bool)));
                connect(m_thread4, SIGNAL(started()), m_pCamera4, SLOT(initWork()));
                connect(m_thread4, SIGNAL(finished()), m_pCamera4, SLOT(deleteLater()));
                connect(&paramSetDialog, SIGNAL(updateParam()), m_pCamera4, SLOT(readParam()));
                m_thread4->start();
            }
        }
    }
    //相机打开成功，PLC连接成功，则使"开始"按钮可用
    if(checkEverythingReady())
    {
        ui->pb_Start->setEnabled(true);
    }
}

void MainWindow::on_pb_connectCamera5_clicked()
{
    int nRet = -1;
    nRet = CMyCamera::EnumDevices(&m_stDevList);
    if (MV_OK != nRet)
    {
        emit sendMess("WARNING", "No device found!");
        LOG(WARNING)<<"No device found!";
    }
    QString strDeviceIP;
    int nIp1 = 0;
    int nIp2 = 0;
    int nIp3 = 0;
    int nIp4 = 0;
    int deviceNum = m_stDevList.nDeviceNum;
    if(deviceNum <= 0)
    {
        ui->label_cam1->setStyleSheet("background:red");
        ui->checkBox_Continuous1->setEnabled(false);
        ui->pb_connectCamera1->setEnabled(true);

        ui->label_cam2->setStyleSheet("background:red");
        ui->checkBox_Continuous2->setEnabled(false);
        ui->pb_connectCamera2->setEnabled(true);

        ui->label_cam3->setStyleSheet("background:red");
        ui->checkBox_Continuous3->setEnabled(false);
        ui->pb_connectCamera3->setEnabled(true);

        ui->label_cam4->setStyleSheet("background:red");
        ui->checkBox_Continuous4->setEnabled(false);
        ui->pb_connectCamera4->setEnabled(true);

        ui->label_cam5->setStyleSheet("background:red");
        ui->checkBox_Continuous5->setEnabled(false);
        ui->pb_connectCamera5->setEnabled(true);

        emit sendMess("WARNING", "No device!");
        LOG(WARNING)<<"No device!";
    }
    for(int i = 0; i < deviceNum; i++)
    {
        MV_CC_DEVICE_INFO* pDeviceInfo = m_stDevList.pDeviceInfo[i];
        if (NULL == pDeviceInfo)
        {
            continue;
        }
        if (pDeviceInfo->nTLayerType == MV_GIGE_DEVICE)
        {
            nIp1 = ((pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0xff000000) >> 24);
            nIp2 = ((pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x00ff0000) >> 16);
            nIp3 = ((pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x0000ff00) >> 8);
            nIp4 = (pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x000000ff);

            strDeviceIP = QString("%1.%2.%3.%4").arg(nIp1).arg(nIp2).arg(nIp3).arg(nIp4);

            //通过IP选择相机设备, 实例化QCcamera对象,打开相机
            //相机2
            if(strDeviceIP == IP_Cam5)
            {
                m_deviceInfo5 = pDeviceInfo;
                m_pCamera5 = new QCamera5(m_deviceInfo5, HalW5);
                nRet = m_pCamera5->Open();
                if(MV_OK == nRet)
                {
                    m_pCamera5->SetEnumValue("ExposureMode", MV_EXPOSURE_MODE_TIMED);//曝光时间设置为定时曝光
                    m_pCamera5->SetEnumValue("ExposureAuto", MV_EXPOSURE_AUTO_MODE_OFF);//自动曝光关闭
                    m_pCamera5->SetFloatValue("ExposureTime", ExposureTime);//曝光时间
                    m_pCamera5->SetFloatValue("AcquisitionFrameRate", 10.0);//帧率设置为10.0
                    m_pCamera5->SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);//打开触发模式
                    m_pCamera5->SetEnumValue("TriggerSource", 0);//设置触发源

                    m_pCamera5->CAMERA_STATE = CAMERA_STATE_CONNECT;//设置相机状态

                    ui->label_cam5->setStyleSheet("background:green");
                    ui->checkBox_Continuous5->setEnabled(true);
                    ui->pb_connectCamera5->setEnabled(false);

                    QString msg = QString("%1%2").arg(tr("Camera opened:")).arg(IP_Cam5);
                    emit sendMess("INFO", msg);

                    QByteArray ba = msg.toLocal8Bit();
                    char* message = ba.data();
                    LOG(INFO)<<message;
                }
                else
                {
                    ui->label_cam5->setStyleSheet("background:red");
                    ui->checkBox_Continuous5->setEnabled(false);
                    ui->pb_connectCamera5->setEnabled(true);

                    m_pCamera5->CAMERA_STATE = CAMERA_STATE_DISCONNECT;
                    QString msg = QString("%1%2").arg(tr("Camera open failed:")).arg(IP_Cam5);
                    emit sendMess("WARNING", msg);

                    QByteArray ba = msg.toLocal8Bit();
                    char* message = ba.data();
                    LOG(WARNING)<<message;
                }
                m_pCamera5->moveToThread(m_thread5);
                connect(m_pCamera5, SIGNAL(frameReceivedSignal5(bool,unsigned char*)), m_pCamera5, SLOT(imageProcess(bool,unsigned char*)),Qt::BlockingQueuedConnection);
                connect(m_pCamera5, SIGNAL(flushWindow()), this, SLOT(on_flushWin5()));
                connect(m_pCamera5, SIGNAL(sendMess(QString, QString)), this, SLOT(on_showMessage(QString, QString)));
                connect(m_pCamera5, SIGNAL(plcState(bool)), this, SLOT(on_plcStateChanged5(bool)));
                connect(m_thread5, SIGNAL(started()), m_pCamera5, SLOT(initWork()));
                connect(m_thread5, SIGNAL(finished()), m_pCamera5, SLOT(deleteLater()));
                connect(&paramSetDialog, SIGNAL(updateParam()), m_pCamera5, SLOT(readParam()));
                m_thread5->start();
            }
        }
    }
    //相机打开成功，PLC连接成功，则使"开始"按钮可用
    if(checkEverythingReady())
    {
        ui->pb_Start->setEnabled(true);
    }
}

void MainWindow::on_checkBox_Continuous1_stateChanged(int arg1)
{
    if(arg1 == 2)
    {
        m_pCamera1->StopGrabbing();
        m_pCamera1->SetEnumValue("TriggerMode", MV_TRIGGER_MODE_OFF);//关闭触发模式
        m_pCamera1->StartGrabbing();
        m_pCamera1->CAMERA_STATE = CAMERA_STATE_CONTINUOUS;

        ui->pb_Start->setEnabled(false);
    }
    else if(arg1 == 0)
    {
        m_pCamera1->StopGrabbing();
        m_pCamera1->SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);//关闭触发模式
        m_pCamera1->StartGrabbing();
        m_pCamera1->CAMERA_STATE = CAMERA_STATE_SHOT;

        if(checkEverythingReady())
        {
            ui->pb_Start->setEnabled(true);
        }
    }
}

void MainWindow::on_checkBox_Continuous2_stateChanged(int arg1)
{
    if(arg1 == 2)
    {
        m_pCamera2->StopGrabbing();
        m_pCamera2->SetEnumValue("TriggerMode", MV_TRIGGER_MODE_OFF);//关闭触发模式
        m_pCamera2->StartGrabbing();
        m_pCamera2->CAMERA_STATE = CAMERA_STATE_CONTINUOUS;

        ui->pb_Start->setEnabled(false);
    }
    else if(arg1 == 0)
    {
        m_pCamera2->StopGrabbing();
        m_pCamera2->SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);//关闭触发模式
        m_pCamera2->StartGrabbing();
        m_pCamera2->CAMERA_STATE = CAMERA_STATE_SHOT;

        if(checkEverythingReady())
        {
            ui->pb_Start->setEnabled(true);
        }
    }
}

void MainWindow::on_checkBox_Continuous3_stateChanged(int arg1)
{
    if(arg1 == 2)
    {
        m_pCamera3->StopGrabbing();
        m_pCamera3->SetEnumValue("TriggerMode", MV_TRIGGER_MODE_OFF);//关闭触发模式
        m_pCamera3->StartGrabbing();
        m_pCamera3->CAMERA_STATE = CAMERA_STATE_CONTINUOUS;

        ui->pb_Start->setEnabled(false);
    }
    else if(arg1 == 0)
    {
        m_pCamera3->StopGrabbing();
        m_pCamera3->SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);//关闭触发模式
        m_pCamera3->StartGrabbing();
        m_pCamera3->CAMERA_STATE = CAMERA_STATE_SHOT;

        if(checkEverythingReady())
        {
            ui->pb_Start->setEnabled(true);
        }
    }
}

void MainWindow::on_checkBox_Continuous4_stateChanged(int arg1)
{
    if(arg1 == 2)
    {
        m_pCamera4->StopGrabbing();
        m_pCamera4->SetEnumValue("TriggerMode", MV_TRIGGER_MODE_OFF);//关闭触发模式
        m_pCamera4->StartGrabbing();
        m_pCamera4->CAMERA_STATE = CAMERA_STATE_CONTINUOUS;

        ui->pb_Start->setEnabled(false);
    }
    else if(arg1 == 0)
    {
        m_pCamera4->StopGrabbing();
        m_pCamera4->SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);//关闭触发模式
        m_pCamera4->StartGrabbing();
        m_pCamera4->CAMERA_STATE = CAMERA_STATE_SHOT;

        if(checkEverythingReady())
        {
            ui->pb_Start->setEnabled(true);
        }
    }
}

void MainWindow::on_checkBox_Continuous5_stateChanged(int arg1)
{
    if(arg1 == 2)
    {
        m_pCamera5->StopGrabbing();
        m_pCamera5->SetEnumValue("TriggerMode", MV_TRIGGER_MODE_OFF);//关闭触发模式
        m_pCamera5->StartGrabbing();
        m_pCamera5->CAMERA_STATE = CAMERA_STATE_CONTINUOUS;

        ui->pb_Start->setEnabled(false);
    }
    else if(arg1 == 0)
    {
        m_pCamera5->StopGrabbing();
        m_pCamera5->SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);//关闭触发模式
        m_pCamera5->StartGrabbing();
        m_pCamera5->CAMERA_STATE = CAMERA_STATE_SHOT;

        if(checkEverythingReady())
        {
            ui->pb_Start->setEnabled(true);
        }
    }
}

void MainWindow::on_action_set_param_triggered()
{
    paramSetDialog.show();
    emit dispParamUI();
}


void MainWindow::on_action_connect_PLC_triggered()
{
    this->setCursor(Qt::WaitCursor);
    QCoreApplication::processEvents();
    if(NULL != m_pCamera1 &&m_pCamera1->PLC_STATE == PLC_DISCONNECT)
    {
        m_pCamera1->connectPLC();
    }
    if(NULL != m_pCamera2 &&m_pCamera2->PLC_STATE == PLC_DISCONNECT)
    {

    }
    if(NULL != m_pCamera3 &&m_pCamera3->PLC_STATE == PLC_DISCONNECT)
    {

    }
    if(NULL != m_pCamera4 &&m_pCamera4->PLC_STATE == PLC_DISCONNECT)
    {

    }
    if(NULL != m_pCamera5 &&m_pCamera5->PLC_STATE == PLC_DISCONNECT)
    {

    }
    //相机打开成功，PLC连接成功，则使"开始"按钮可用
    if(checkEverythingReady())
    {
        ui->pb_Start->setEnabled(true);
    }
    this->setCursor(Qt::ArrowCursor);
}
