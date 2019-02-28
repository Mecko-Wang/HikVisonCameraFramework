/************************************************************************/
/* 以C++接口为基础，对常用函数进行二次封装，方便用户使用                */
/************************************************************************/

#ifndef _MY_CAMERA_H_
#define _MY_CAMERA_H_

#include "MvCameraControl.h"
#include "qhalconwindow.h"
#include <QDebug>
#include <QException>
#include <QString>
#include <QThread>
#include <QDir>
#include <QDateTime>
#include "cplc.h"
#include "param.h"
#include "Operator/HOperator.h"
#define GLOG_NO_ABBREVIATED_SEVERITIES
#include "glog/logging.h"

using namespace HalconCpp;

//摄像机状态
enum _CAMERA_STATE_
{
    CAMERA_STATE_DISCONNECT = 0,                        //未连接
    CAMERA_STATE_CONNECT = 1,                           //已连接但未开启预览
    CAMERA_STATE_SHOT = 2,                              //触发采集
    CAMERA_STATE_CONTINUOUS = 3,                        //连续采集
    CAMERA_STATE_PAUSE,                                 //暂停---暂时不使用
};

//PLC状态
enum _PLC_STATE_
{
    PLC_DISCONNECT = 0,                                 //PLC未连接
    PLC_CONNECT = 1,                                    //PLC已连接
};

//PLC IP地址
const QString PLC_IP1 = "192.168.1.101";
const QString PLC_IP2 = "192.168.1.101";
const QString PLC_IP3 = "192.168.1.103";
const QString PLC_IP4 = "192.168.1.103";
const QString PLC_IP5 = "192.168.1.105";

//PLC端口号
const unsigned int PLC_PORT1 = 5500;
const unsigned int PLC_PORT2 = 5501;
const unsigned int PLC_PORT3 = 5502;
const unsigned int PLC_PORT4 = 5503;
const unsigned int PLC_PORT5 = 5504;

//向PLC中发送图像处理结果的寄存器地址
const int Cam1_state = 0000;
const int Cam1_angle = 0000;
const int Cam2_state = 0000;
const int Cam2_angle = 0000;
const int Cam3_state = 0000;
const int Cam3_angle = 0000;
const int Cam4_state = 0000;
const int Cam4_angle = 0000;
const int Cam5_state = 0000;
const int Cam5_angle = 0000;

//向PLC中发送图像处理结果
const int PLC_SIGNAL_OK = 10;
const int PLC_SIGNAL_NG = 12;

class CMyCamera: public QObject, public CHOperator
{
    Q_OBJECT

signals:
    void frameReceivedSignal1(bool state, unsigned char* data);              //Cam1帧数据收到信号
    void frameReceivedSignal2(bool state, unsigned char* data);              //Cam2帧数据收到信号
    void frameReceivedSignal3(bool state, unsigned char* data);              //Cam3帧数据收到信号
    void frameReceivedSignal4(bool state, unsigned char* data);              //Cam4帧数据收到信号
    void frameReceivedSignal5(bool state, unsigned char* data);              //Cam5帧数据收到信号

    void sendMess(QString excelevel, QString excedata);                     //发送信息信号
    void flushWindow();                                                     //更新HalconWindow窗口信号
    void plcState(bool state);                                              //发送PLC状态信号
    void sendDateToPlc(bool* state, const int startNum, const int len, const int data);  //发送数据至PLC
public:
    CMyCamera(MV_CC_DEVICE_INFO*  device, QHalconWindow* win);
    ~CMyCamera();

    _CAMERA_STATE_ CAMERA_STATE = CAMERA_STATE_DISCONNECT;                        //相机状态结构体
    _PLC_STATE_ PLC_STATE = PLC_DISCONNECT;                                       //PLC状态结构体

    //Cam1发送帧数据收到信号
    void sendFrameReceivedSignal1(bool state, unsigned char* data);
    //Cam1接收图像数据回调函数
    static void __stdcall ImageCallBackEx1(unsigned char * pData, MV_FRAME_OUT_INFO_EX* pFrameInfo, void* pUser);

    //Cam2发送帧数据收到信号
    void sendFrameReceivedSignal2(bool state, unsigned char* data);
    //Cam2接收图像数据回调函数
    static void __stdcall ImageCallBackEx2(unsigned char * pData, MV_FRAME_OUT_INFO_EX* pFrameInfo, void* pUser);

    //Cam3发送帧数据收到信号
    void sendFrameReceivedSignal3(bool state, unsigned char* data);
    //Cam3接收图像数据回调函数
    static void __stdcall ImageCallBackEx3(unsigned char * pData, MV_FRAME_OUT_INFO_EX* pFrameInfo, void* pUser);

    //Cam4发送帧数据收到信号
    void sendFrameReceivedSignal4(bool state, unsigned char* data);
    //Cam4接收图像数据回调函数
    static void __stdcall ImageCallBackEx4(unsigned char * pData, MV_FRAME_OUT_INFO_EX* pFrameInfo, void* pUser);

    //Cam5发送帧数据收到信号
    void sendFrameReceivedSignal5(bool state, unsigned char* data);
    //Cam2接收图像数据回调函数
    static void __stdcall ImageCallBackEx5(unsigned char * pData, MV_FRAME_OUT_INFO_EX* pFrameInfo, void* pUser);

    static int EnumDevices(MV_CC_DEVICE_INFO_LIST* pstDevList);

    // ch:打开设备 | en:Open Device
    int     Open();

    // ch:关闭设备 | en:Close Device
    int     Close();

    // ch:开启抓图 | en:Start Grabbing
    int     StartGrabbing();

    // ch:停止抓图 | en:Stop Grabbing
    int     StopGrabbing();

    // ch:主动获取一帧图像数据 | en:Get one frame initiatively
    int     GetOneFrameTimeout(unsigned char* pData, unsigned int* pnDataLen, unsigned int nDataSize, MV_FRAME_OUT_INFO_EX* pFrameInfo, int nMsec);

    // ch:设置显示窗口句柄 | en:Set Display Window Handle
    int     Display(void* hWnd);

    // ch:保存图片 | en:save image
    int     SaveImage(MV_SAVE_IMAGE_PARAM_EX* pstParam);

    // ch:注册图像数据回调 | en:Register Image Data CallBack
    int     RegisterImageCallBack(void(__stdcall* cbOutput)(unsigned char * pData, MV_FRAME_OUT_INFO_EX* pFrameInfo, void* pUser),
                                    void* pUser);

    // ch:注册消息异常回调 | en:Register Message Exception CallBack
    int     RegisterExceptionCallBack(void(__stdcall* cbException)(unsigned int nMsgType, void* pUser),
                                        void* pUser);

    // ch:获取Int型参数，如 Width和Height，详细内容参考SDK安装目录下的 MvCameraNode.xlsx 文件
    // en:Get Int type parameters, such as Width and Height, for details please refer to MvCameraNode.xlsx file under SDK installation directory
    int     GetIntValue(IN const char* strKey, OUT unsigned int *pnValue);
    int     SetIntValue(IN const char* strKey, IN unsigned int nValue);

    // ch:获取Float型参数，如 ExposureTime和Gain，详细内容参考SDK安装目录下的 MvCameraNode.xlsx 文件
    // en:Get Float type parameters, such as ExposureTime and Gain, for details please refer to MvCameraNode.xlsx file under SDK installation directory
    int     GetFloatValue(IN const char* strKey, OUT float *pfValue);
    int     SetFloatValue(IN const char* strKey, IN float fValue);

    // ch:获取Enum型参数，如 PixelFormat，详细内容参考SDK安装目录下的 MvCameraNode.xlsx 文件
    // en:Get Enum type parameters, such as PixelFormat, for details please refer to MvCameraNode.xlsx file under SDK installation directory
    int     GetEnumValue(IN const char* strKey, OUT unsigned int *pnValue);
    int     SetEnumValue(IN const char* strKey, IN unsigned int nValue);

    // ch:获取Bool型参数，如 ReverseX，详细内容参考SDK安装目录下的 MvCameraNode.xlsx 文件
    // en:Get Bool type parameters, such as ReverseX, for details please refer to MvCameraNode.xlsx file under SDK installation directory
    int     GetBoolValue(IN const char* strKey, OUT bool *pbValue);
    int     SetBoolValue(IN const char* strKey, IN bool bValue);

    // ch:获取String型参数，如 DeviceUserID，详细内容参考SDK安装目录下的 MvCameraNode.xlsx 文件UserSetSave
    // en:Get String type parameters, such as DeviceUserID, for details please refer to MvCameraNode.xlsx file under SDK installation directory
    int     GetStringValue(IN const char* strKey, IN OUT char* strValue, IN unsigned int nSize);
    int     SetStringValue(IN const char* strKey, IN const char * strValue);

    // ch:执行一次Command型命令，如 UserSetSave，详细内容参考SDK安装目录下的 MvCameraNode.xlsx 文件
    // en:Execute Command once, such as UserSetSave, for details please refer to MvCameraNode.xlsx file under SDK installation directory
    int     CommandExecute(IN const char* strKey);

    // ch:探测网络最佳包大小(只对GigE相机有效) | en:Detection network optimal package size(It only works for the GigE camera)
    int     GetOptimalPacketSize();

    // 获取统计参数
    int     GetAllMatchInfo(OUT unsigned int *nLostFrame, OUT unsigned int *nFrameCount);

private:
    void*               m_hDevHandle;

public:
    unsigned char*  m_pBufForSaveImage;         // 用于保存图像的缓存
    unsigned int    m_nBufSizeForSaveImage;

    unsigned char*  m_pBufForDriver;            // 用于从驱动获取图像的缓存
    unsigned int    m_nBufSizeForDriver;

    QHalconWindow*          hwin;
    MV_CC_DEVICE_INFO*      m_device;        //设备信息

    CPlc*               m_plc;               //套接字，用于建立与PLC的TCP/IP连接
    QThread*            m_plcThread;         //套接字线程

    RoiParam            Roi;                            //ROI参数
    MatieralParam       Matieral;                       //物料参数
    ModelParam          ModelCircle, ModelFeature;      //模板匹配参数

    HTuple              Model_Circle, Model_Material;                //用于模板匹配的模板ID句柄
};

#endif
