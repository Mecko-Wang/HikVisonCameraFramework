#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcamera1.h"
#include "qcamera2.h"
#include "qcamera3.h"
#include "qcamera4.h"
#include "qcamera5.h"
#include <QThread>
#include <QTime>
#include "cplc.h"
#include <QInputDialog>
#include <QCloseEvent>
#include <QDir>
#include "paramSetDialog.h"
#include "param.h"
#define GLOG_NO_ABBREVIATED_SEVERITIES
#include "glog/logging.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initWork();
    void closeEvent(QCloseEvent *e);
    void initGlog();
    bool checkEverythingReady();
    void clearPic(QString dirc);      //删除图片

signals:
    void sendMess(QString excelevel, QString excedata);
    void dispParamUI();

private slots:
    void on_pb_Start_clicked();
    void on_pb_Stop_clicked();
    void on_showMessage(QString excelevel, QString excedata);
    void on_flushWin1();
    void on_flushWin2();
    void on_flushWin3();
    void on_flushWin4();
    void on_flushWin5();
    void clearHistoryPicture();

    void on_plcStateChanged1(bool state);
    void on_plcStateChanged2(bool state);
    void on_plcStateChanged3(bool state);
    void on_plcStateChanged4(bool state);
    void on_plcStateChanged5(bool state);

    void on_action_set_param_triggered();

    void on_pb_connectCamera1_clicked();

    void on_pb_connectCamera2_clicked();

    void on_checkBox_Continuous1_stateChanged(int arg1);

    void on_checkBox_Continuous2_stateChanged(int arg1);

    void on_checkBox_Continuous3_stateChanged(int arg1);

    void on_checkBox_Continuous4_stateChanged(int arg1);

    void on_checkBox_Continuous5_stateChanged(int arg1);

    void on_pb_connectCamera3_clicked();

    void on_pb_connectCamera4_clicked();

    void on_pb_connectCamera5_clicked();

    void on_action_connect_PLC_triggered();

private:
    Ui::MainWindow *ui;
    MV_CC_DEVICE_INFO_LIST  m_stDevList;         //设备信息列表结构体变量，用来存储设备列表

    QHalconWindow*          HalW1;
    QHalconWindow*          HalW2;
    QHalconWindow*          HalW3;
    QHalconWindow*          HalW4;
    QHalconWindow*          HalW5;

    MV_CC_DEVICE_INFO*      m_deviceInfo1;        //设备信息
    MV_CC_DEVICE_INFO*      m_deviceInfo2;
    MV_CC_DEVICE_INFO*      m_deviceInfo3;
    MV_CC_DEVICE_INFO*      m_deviceInfo4;
    MV_CC_DEVICE_INFO*      m_deviceInfo5;

    QCamera1*               m_pCamera1;
    QCamera2*               m_pCamera2;
    QCamera3*               m_pCamera3;
    QCamera4*               m_pCamera4;
    QCamera5*               m_pCamera5;

    QThread*                m_thread1;
    QThread*                m_thread2;
    QThread*                m_thread3;
    QThread*                m_thread4;
    QThread*                m_thread5;

    QThread*                m_logthread;

    Dialog                  paramSetDialog;             //参数设置界面
};

#endif // MAINWINDOW_H
