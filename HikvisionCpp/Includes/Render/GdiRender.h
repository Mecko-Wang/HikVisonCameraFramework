/** @file    GDIRender.h
 *  @note    Hikvision Digital Technology Co., Ltd. All Rights Reserved.
 *  @brief
 *
 *  @author
 *  @date    2016/09/08
 *  @note    V1.0.0
 *
 *  @warning
 */

#ifndef __GDI_RENDER_H__
#define __GDI_RENDER_H__


#include "SRMutex.h"
#include <WinGDI.h>
#include "BaseRender.h"

#pragma comment(lib,"User32.lib")
#pragma comment(lib,"gdi32.lib")
#pragma comment(lib,"kernel32.lib")


typedef struct tagPortInfo
{
    unsigned int nPort;  /*端口号*/
    unsigned int nState; /*端口是否启用*/
    HWND         hWnd;
    HDC          hDC;
    HDC          hMemDc;
    HBITMAP      hBitmap;
    MVRRECTF     stDisplaySrc;
    MVRRECTF     stDisplayDst;
    unsigned int nCBType;
    MVR_CallBack cbFunc;
    void*        pUser;
} PORTINFO;

const unsigned int MAX_COLOR_VALUE = 255;

class CGdiRender: public CBaseRender
{
public:

    CGdiRender();

    ~CGdiRender();

    unsigned int Init(MVRPixelFormat nPixelFormat, unsigned int nThreadSafe);

    unsigned int UpdateFrameData(unsigned char* pImageData, unsigned int nWidth, unsigned int nHeight);

    unsigned int AddSubPort(unsigned int nPort);

    unsigned int DelSubPort(unsigned int nPort);

    unsigned int Display(unsigned int nPort, void* hWnd);   

    unsigned int SetDisplayRect(unsigned int nPort, MVRRECTF* pstDisplayRectSrc, MVRRECTF* pstDisplayRectDst);

    unsigned int SetCallBack(unsigned int nPort, unsigned int nCBType, MVR_CallBack cbFunc, void* pUser);

    

private:

    unsigned int InitImage();

    unsigned int DeInitImage();

private:

    HBITMAP        m_hBitmap;
    PBITMAPINFO    m_pstBitmapInfo;
    void*          m_pvBits;
    void*          m_pvBitsDisplay;

    unsigned int   m_nImageWidth;
    unsigned int   m_nImageHeight;

    unsigned int   m_nWndWidth;
    unsigned int   m_nWndHeight;

    unsigned int   m_nPixelType;

    unsigned char* m_pRgbCvtBuf;/*BGR->RGB转换内存*/
    unsigned int   m_nRgbCvtBufSize;

    bool           m_bUseGdiplus;
    ULONG_PTR      m_lGdiplusToken;

    PORTINFO       m_stPortInfo[MVR_MAX_PORT];
    CSRMutex       m_stPortMutex;

    
};
#endif
