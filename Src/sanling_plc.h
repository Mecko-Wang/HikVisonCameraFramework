#ifndef SANLING_PLC_H
#define SANLING_PLC_H

#include <QObject>

class SanLing_PLC
{
public:

    /**********************************   暂只能用于数据寄存器(D)的读写  *********************************************/
    //
    /// \brief   生成MC协议读取二进制报文
    /// \param registerName - [in] 寄存器名字，'M'为M寄存器，'D'为数据寄存器
    /// \param startNum     - [in] 寄存器开始序列号，如100
    /// \param len          - [in] 寄存器连续个数。
    /// \return             - 生成的二进制报文
    ///
    static QByteArray MC_Bin3E_read_message(const QByteArray registerName, const uint startNum, const int len, QByteArray* commandLog);

    ///
    /// \brief   生成MC协议写入16位数据二进制报文
    /// \param registerName - [in] 寄存器名字，'M'为M寄存器，'D'为数据寄存器
    /// \param startNum     - [in] 寄存器开始序列号，如100
    /// \param len          - [in] 寄存器连续个数。
    /// \param data[]       - [in] 输入的数据，以单个'M'或'D'输入。
    /// \return             - 生成的二进制报文
    ///
    static QByteArray MC_Bin3E_write_message(const QByteArray registerName, const uint startNum, const int len, const qint32 data[], QByteArray* commandLog);

    ///
    /// \brief   生成MC协议写入32位数据二进制报文
    /// \param registerName - [in] 寄存器名字，'M'为M寄存器，'D'为数据寄存器
    /// \param startNum     - [in] 寄存器开始序列号，如100
    /// \param len          - [in] 寄存器连续个数。
    /// \param data[]       - [in] 输入的数据，以双个'D'输入。
    /// \return             - 生成的二进制报文
    ///
    static QByteArray MC_Bin3E_write_message_bit32(const QByteArray registerName, const uint startNum, const int len, const qint32 data[], QByteArray* commandLog);

};

#endif // SANLING_PLC_H
