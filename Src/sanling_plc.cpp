#include "sanling_plc.h"

#include <QDebug>


QByteArray SanLing_PLC::MC_Bin3E_read_message(const QByteArray registerName, const uint startNum, const int len, QByteArray * commandLog)
{
    QByteArray temp= "";
    temp.append("5000");  //副头部
    temp.append("00");    //Q头部-网络编号
    temp.append("FF");    //Q头部-可编程控制器编号
    temp.append("FF03");  //Q头部-请求目标模块I/O编号
    temp.append("00");    //Q头部-请求目标模块站号

    temp.append("0C00");  //Q头部-请求数据长度，需根据实际填写
    temp.append("1000");  //Q头部-CPU监视定时器
    temp.append("0104");  //指令
    temp.append("0000");  //子指令

    QByteArray Hex = QByteArray::number(startNum,16).toUpper();
    while(6-Hex.length()) {
        Hex.insert(0,"0");
    }
    temp.append(Hex.right(2)); //数字位16进制高低交换
    Hex.remove(Hex.length()-2,2);
    temp.append(Hex.right(2)); //数字位16进制高低交换
    Hex.remove(Hex.length()-2,2);
    temp.append(Hex.right(2)); //数字位16进制高低交换

    if(registerName == "M"){
        temp.append("90"); //M寄存器
    }
    else if(registerName == "D"){
        temp.append("A8"); //D寄存器
    }

    Hex = QByteArray::number(len,16).toUpper();
    while(4-Hex.length()) {
        Hex.insert(0,"0");
    }
    temp.append(Hex.right(2)); //数字位16进制高低交换
    temp.append(Hex.left(2));  //数字位16进制高低交换

    *commandLog = temp;

    QByteArray dHex;
    int length = temp.length()/2;
    for(int i=0;i<length;i++)
    {
        dHex[i] = temp.left(2).toInt(Q_NULLPTR, 16);
        temp.remove(0,2);
    }

    return dHex;
}

QByteArray SanLing_PLC::MC_Bin3E_write_message(const QByteArray registerName, const uint startNum, const int len, const qint32 data[], QByteArray * commandLog)
{
    QByteArray temp= "";
    temp.append("5000"); //副头部
    temp.append("00");   //Q头部-网络编号
    temp.append("FF");   //Q头部-可编程控制器编号
    temp.append("FF03"); //Q头部-请求目标模块I/O编号
    temp.append("00");   //Q头部-请求目标模块站号

    int datalen = 12+2*len;
    QByteArray Hex = QByteArray::number(datalen,16).toUpper();
    while(4-Hex.length()) {
        Hex.insert(0,"0");
    }
    temp.append(Hex.right(2)); //Q头部-请求数据长度
    temp.append(Hex.left(2));  //Q头部-请求数据长度
    temp.append("1000");       //Q头部-CPU监视定时器
    temp.append("0114");       //指令
    temp.append("0000");       //子指令

    //起始寄存器
    Hex = QByteArray::number(startNum,16).toUpper();
    while(6-Hex.length()) {
        Hex.insert(0,"0");
    }
    temp.append(Hex.right(2)); //数字位16进制高低交换
    Hex.remove(Hex.length()-2,2);
    temp.append(Hex.right(2)); //数字位16进制高低交换
    Hex.remove(Hex.length()-2,2);
    temp.append(Hex.right(2)); //数字位16进制高低交换

    if(registerName == "M"){
        temp.append("90"); //M寄存器
    }
    else if(registerName == "D"){
        temp.append("A8"); //D寄存器
    }

    //数据长度
    Hex = QByteArray::number(len,16).toUpper();
    while(4-Hex.length()) {
        Hex.insert(0,"0");
    }
    temp.append(Hex.right(2)); //数字位16进制高低交换
    temp.append(Hex.left(2));  //数字位16进制高低交换

    //加入数据
    for(int i=0; i<len; i++)
    {
        Hex = QByteArray::number(data[i],16).toUpper();        
        if(Hex.length()==8)
        {
            Hex = Hex.right(4);
        }
        while(4-Hex.length()) {
            Hex.insert(0,"0");
        }
        temp.append(Hex.right(2)); //数字位16进制高低交换
        temp.append(Hex.left(2));  //数字位16进制高低交换
    }
    //qDebug()<<"temp"<<temp;

    *commandLog = temp;

    QByteArray dHex;
    int length = temp.length()/2;
    for(int i=0;i<length;i++)
    {
        dHex[i] = temp.left(2).toInt(Q_NULLPTR, 16);
        temp.remove(0,2);
    }

    return dHex;
}

QByteArray SanLing_PLC::MC_Bin3E_write_message_bit32(const QByteArray registerName, const uint startNum, const int len, const qint32 data[], QByteArray * commandLog)
{
    QByteArray temp= "";
    temp.append("5000"); //副头部
    temp.append("00");   //Q头部-网络编号
    temp.append("FF");   //Q头部-可编程控制器编号
    temp.append("FF03"); //Q头部-请求目标模块I/O编号
    temp.append("00");   //Q头部-请求目标模块站号

    int datalen = 12+4*len;
    QByteArray Hex = QByteArray::number(datalen,16).toUpper();
    while(4-Hex.length()) {
        Hex.insert(0,"0");
    }
    temp.append(Hex.right(2)); //Q头部-请求数据长度
    temp.append(Hex.left(2));  //Q头部-请求数据长度
    temp.append("1000");       //Q头部-CPU监视定时器
    temp.append("0114");       //指令
    temp.append("0000");       //子指令

    //起始寄存器
    Hex = QByteArray::number(startNum,16).toUpper();
    while(6-Hex.length()) {
        Hex.insert(0,"0");
    }
    temp.append(Hex.right(2)); //数字位16进制高低交换
    Hex.remove(Hex.length()-2,2);
    temp.append(Hex.right(2)); //数字位16进制高低交换
    Hex.remove(Hex.length()-2,2);
    temp.append(Hex.right(2)); //数字位16进制高低交换

    if(registerName == "M"){
        temp.append("90"); //M寄存器
    }
    else if(registerName == "D"){
        temp.append("A8"); //D寄存器
    }

    //数据长度
    Hex = QByteArray::number(len*2,16).toUpper();
    while(4-Hex.length()) {
        Hex.insert(0,"0");
    }
    temp.append(Hex.right(2)); //数字位16进制高低交换
    temp.append(Hex.left(2));  //数字位16进制高低交换

    //加入数据
    for(int i=0; i<len; i++)
    {
        Hex = QByteArray::number(data[i],16).toUpper();

        while(8-Hex.length()) {
            Hex.insert(0,"0");
        }
        //temp.append(Hex.mid(2,2));  //数字位字节2
        //temp.append(Hex.mid(0,2));  //数字位字节1
        //temp.append(Hex.mid(6,2));  //数字位字节4
        //temp.append(Hex.mid(4,2));  //数字位字节3
        temp.append(Hex.mid(6,2));  //数字位字节4
        temp.append(Hex.mid(4,2));  //数字位字节3
        temp.append(Hex.mid(2,2));  //数字位字节2
        temp.append(Hex.mid(0,2));  //数字位字节1

    }
    //qDebug()<<"temp"<<temp;
    *commandLog = temp;

    QByteArray dHex;
    int length = temp.length()/2;
    for(int i=0;i<length;i++)
    {
        dHex[i] = temp.left(2).toInt(Q_NULLPTR, 16);
        temp.remove(0,2);
    }

    return dHex;
}
