/** @file    MVRStruct.h
 *  @note    Hikvision Digital Technology Co., Ltd. All Rights Reserved.
 *  @brief   
 *
 *  @author  
 *  @date    2016/06/29
 *  @note    V1.0.0
 *
 *  @warning 
 */

#ifndef __MV_RENDER_STRUCT_H__
#define __MV_RENDER_STRUCT_H__


// 定义最大的支持的显示端口数量
#define MVR_MAX_PORT 4

typedef void (__stdcall * MVR_CallBack)(void* pUser, unsigned int nPort, unsigned int nCBType, void* hDC, unsigned int nWidth, unsigned int nHeight); 

typedef enum tagMVRPixelFormat
{
    MVR_PF_NULL   = 0x0,
    MVR_PF_RGB24  = 0x1,
    MVR_PF_RGBA32 = 0x2,
    MVR_PF_MONO8  = 0x3,    
}MVRPixelFormat;

typedef enum tagMVREngine
{
    MVR_ENGINE_DEFAULT = 0x0,
    MVR_ENGINE_GDI     = 0x1,
}MVREngine;

typedef struct tagMVRRectF
{
    float fTop;		// [0.0 , 1.0]
    float fBottom;	// [0.0 , 1.0]
    float fLeft;	// [0.0 , 1.0]
    float fRight;	// [0.0 , 1.0]
}MVRRECTF;

typedef struct tagMVRColorF
{
    float fR;		// [0.0 , 1.0]
    float fG;		// [0.0 , 1.0]
    float fB;		// [0.0 , 1.0]
    float fAlpha;	// [0.0 , 1.0]
}MVRCOLORF;

typedef struct tagMVRPointF
{
    float fX;
    float fY;
}MVRPOINTF;

#endif  /*__MV_RENDER_STRUCT_H__*/