/** @file    BaseRender.h
 *  @note    Hikvision Digital Technology Co., Ltd. All Rights Reserved.
 *  @brief   
 *
 *  @author  luyao
 *  @date    2016/07/14
 *  @note    V1.0.0
 *
 *  @warning 
 */

#ifndef __BASE_RENDER_H__
#define __BASE_RENDER_H__

#include "MvRenderDefine.h"

class CBaseRender
{
public:
    virtual ~CBaseRender() {};

    virtual unsigned int Init(MVRPixelFormat nPixelFormat, unsigned int nThreadSafe) = 0;

    virtual unsigned int UpdateFrameData(unsigned char* pImageData, unsigned int nWidth, unsigned int nHeight) = 0;

    virtual unsigned int AddSubPort(unsigned int nPort) = 0;

    virtual unsigned int DelSubPort(unsigned int nPort) = 0;

    virtual unsigned int Display(unsigned int nPort, void* hWnd) = 0;    

    virtual unsigned int SetDisplayRect(unsigned int nPort, MVRRECTF* pstDisplayRectSrc, MVRRECTF* pstDisplayRectDst) = 0;

    virtual unsigned int SetCallBack(unsigned int nPort, unsigned int nCBType, MVR_CallBack cbFunc, void* pUser) = 0;

    

};

#endif  /*__BASE_RENDER_H__*/