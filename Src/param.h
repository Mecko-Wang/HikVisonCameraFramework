#ifndef PARAM
#define PARAM


#include <QMutex>
#include <QList>
#include <QStringList>
#include <QDebug>

#include <HalconCpp.h>
#include <HOperatorSetLegacy.h>
using namespace HalconCpp;


struct Time
{
    static HTuple  t1;
    static HTuple  t2;
};

struct globle_param
{
    static bool   m_save_NG_image;
    static bool   m_save_OK_image;
    static bool   m_test_model;
    static bool   m_run_mode;
};

struct RoiParam
{
    HTuple Row;            //ROI圆心位置坐标
    HTuple Col;            //ROI圆心位置坐标
    HTuple Radius;         //ROI半径
};

struct MatieralParam
{
    HTuple Radius;            //物料半径
    HTuple OffsetLow;         //物料误差低值
    HTuple OffsetHigh;        //物料误差高值
};

struct ModelParam
{
    HTuple ScaleMin;            //最小缩放倍数
    HTuple ScaleMax;            //最大缩放倍数
    HTuple MinScore;            //最小匹配分数
};
#endif // PARAM



