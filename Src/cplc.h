#ifndef CPLC_H
#define CPLC_H

#include <QObject>
#include <QTcpSocket>
//#include <Windows.h>

#include "sanling_plc.h"
#define GLOG_NO_ABBREVIATED_SEVERITIES
#include "glog/logging.h"

class CPlc : public QObject
{
    Q_OBJECT
public:
    explicit CPlc(QString IP, unsigned int PORT, QObject *parent = 0);
    ~CPlc();
    // 写plc制定寄存器数据
    bool isPlcConnect();
private:
    QTcpSocket *plc_port = nullptr;// 与plc通信的端口
    QString PLC_IP;
    unsigned int PLC_PORT;

signals:
    void sendMess(QString excelevel, QString excedata);
    void plcStates(bool state);

private slots:
    void initFunc();
    void deleteLater();
    void plcConnect();
    void plcDisconnect();
    void writePlc(bool* state, const int startNum, const int len, const int data, const QByteArray registerName = "D");
};

#endif // CPLC_H
