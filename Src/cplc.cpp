#include "cplc.h"

CPlc::CPlc(QString IP, unsigned int PORT, QObject *parent) : PLC_IP(IP), PLC_PORT(PORT), QObject(parent)
{

}

CPlc::~CPlc()
{

}

//写入plc制定寄存器
void CPlc::writePlc(bool* state, const int startNum, const int len, const int data, const QByteArray registerName)
{
    if(!plc_port)
        *state = false;
    int dat[] = {data};
    QByteArray command;
    QByteArray tmpsend = SanLing_PLC::MC_Bin3E_write_message_bit32(registerName, startNum, len, dat, &command);
    qDebug()<<tmpsend.toHex().toUpper();
    //写入
    plc_port->write(tmpsend);
    //等待写入完成
    plc_port->waitForBytesWritten(100);
    //等待读取
    plc_port->waitForReadyRead(1000);
    //读取
    QByteArray tmp_result = plc_port->readAll().toHex().toUpper();
    //qDebug()<<tmp_result;
    //验证数据的正确性，这里可能会溢出，此时为写入失败
    if(tmp_result.length()==0 || tmp_result.mid(18,2) == "C0")
    {
        if(tmp_result.mid(18,2) == "C0")
            *state = false;
    }

    //emit sendMess("cplc","create a connection success.");
    *state = true;
}

bool CPlc::isPlcConnect()
{
    if(plc_port->state() == QAbstractSocket::ConnectedState)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void CPlc::initFunc()
{
    // 链接plc
    plc_port = new QTcpSocket;

    connect(plc_port, SIGNAL(connected()), this, SLOT(plcConnect()));
    connect(plc_port, SIGNAL(disconnected()), this, SLOT(plcDisconnect()));

    plc_port->connectToHost(PLC_IP, PLC_PORT);
    if(!plc_port->waitForConnected(5000))
    {
        emit sendMess("ERROR", "Connect plc failed!");
        LOG(ERROR)<<"Connect plc failed!";
    }
    else
    {
        emit sendMess("INFO", "Connect plc success!");
        LOG(INFO)<<"Connect plc success!";
    }
    // 链接plc end
}

void CPlc::deleteLater()
{
    if(plc_port!=nullptr)
    {
        if(plc_port->isOpen())
        {
            plc_port->close();
            delete plc_port;
            plc_port = nullptr;
        }
    }
}

void CPlc::plcConnect()
{
    emit plcStates(true);
}

void CPlc::plcDisconnect()
{
    emit plcStates(false);
}

