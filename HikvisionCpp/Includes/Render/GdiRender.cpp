/** @file    GDIRender.cpp
 *  @note    Hikvision Digital Technology Co., Ltd. All Rights Reserved.
 *  @brief
 *
 *  @author
 *  @date    2016/09/08
 *  @note    V1.0.0
 *
 *  @warning
 */

#include "MvrUtil.h"
#include "GdiRender.h"

//#define USE_DOUBLE_BUFFER

/** @func name   CGdiRender
 *  @func brief

 *  @return
**/
CGdiRender::CGdiRender()
{
    m_hBitmap       = NULL;
    m_pstBitmapInfo = NULL;
    m_pvBits        = NULL;
    m_pvBitsDisplay = NULL;

    m_nImageWidth   = 0;
    m_nImageHeight  = 0;

    m_nWndWidth     = 0;
    m_nWndHeight    = 0;

    m_nPixelType     = MVR_PF_NULL;

    m_pRgbCvtBuf     = NULL;
    m_nRgbCvtBufSize = 0;

    m_bUseGdiplus    = false;
    m_lGdiplusToken  = 0;

    memset(&m_stPortInfo, 0, MVR_MAX_PORT * sizeof(PORTINFO));
    for (int nPortIndex = 0; nPortIndex < MVR_MAX_PORT; nPortIndex++)
    {
        m_stPortInfo[nPortIndex].stDisplaySrc.fLeft   = 0.0;
        m_stPortInfo[nPortIndex].stDisplaySrc.fRight  = 1.0;
        m_stPortInfo[nPortIndex].stDisplaySrc.fTop    = 0.0;
        m_stPortInfo[nPortIndex].stDisplaySrc.fBottom = 1.0;

        m_stPortInfo[nPortIndex].stDisplayDst.fLeft   = 0.0;
        m_stPortInfo[nPortIndex].stDisplayDst.fRight  = 1.0;
        m_stPortInfo[nPortIndex].stDisplayDst.fTop    = 0.0;
        m_stPortInfo[nPortIndex].stDisplayDst.fBottom = 1.0;
    }
}

/** @func name   ~CGdiRender
 *  @func brief

 *  @return
**/
CGdiRender::~CGdiRender()
{
    DeInitImage();

    if (m_pRgbCvtBuf)
    {
        free(m_pRgbCvtBuf);
        m_pRgbCvtBuf = NULL;
    }
          

}

unsigned int CGdiRender::Init(MVRPixelFormat nPixelFormat, unsigned int nThreadSafe)
{
    m_nPixelType = nPixelFormat;

    

    return MVR_RETURN_OK;
}

unsigned int CGdiRender::UpdateFrameData(unsigned char* pImageData, unsigned int nWidth, unsigned int nHeight)
{

    //CSRLock lock(&m_stPortMutex);

    if (nWidth  != m_nImageWidth ||
        nHeight != m_nImageHeight)
    {
        m_nImageWidth  = nWidth;
        m_nImageHeight = nHeight;
        DeInitImage();
        InitImage();
    }

//     int nPixelSize = 1;
//     switch (m_nPixelType)
//     {
//     case MVR_PF_MONO8:
//         {
//             nPixelSize = 1;
//         }
//         break;
//     case MVR_PF_RGB24:    
//         {
//             nPixelSize = 3;
//         }
//         break;    
//     case MVR_PF_RGBA32:
//         {
//             nPixelSize = 4;
//         }
//         break;
//     default:
//         break;
//     }

    unsigned char* pSrcData = pImageData;


    if (m_nPixelType == MVR_PF_RGB24)
    {

        /*RGB转换成BGR,Bitmap为BGR顺序*/
        if (NULL == m_pRgbCvtBuf)
        {
            m_pRgbCvtBuf = (unsigned char*)malloc(nWidth * nHeight * 3);
            if (NULL == m_pRgbCvtBuf)
            {
                return MVR_ERR_RESOURECE;
            }
            m_nRgbCvtBufSize = nWidth * nHeight * 3;
        }

        if (nWidth * nHeight * 3 > m_nRgbCvtBufSize)
        {
            free(m_pRgbCvtBuf);
            m_pRgbCvtBuf = NULL;
            m_pRgbCvtBuf = (unsigned char*)malloc(nWidth * nHeight * 3);
            if (NULL == m_pRgbCvtBuf)            {
                return MVR_ERR_RESOURECE;
            }
            m_nRgbCvtBufSize = nWidth * nHeight * 3;
        }

        /*把图像数据拷贝到转换内存中,不去修改原数据*/
        memcpy_s(m_pRgbCvtBuf, m_nRgbCvtBufSize,
                 pImageData,   nWidth * nHeight * 3);

        unsigned char* pRgbData = NULL;
        pRgbData = m_pRgbCvtBuf;

        for (unsigned int j = 0; j < nHeight; j++)
        {
            for (unsigned int i = 0; i < nWidth; i++)
            {
                unsigned char red = pRgbData[j * (nWidth * 3) + i * 3];
                pRgbData[j * (nWidth * 3) + i * 3]     = pRgbData[j * (nWidth * 3) + i * 3 + 2];
                pRgbData[j * (nWidth * 3) + i * 3 + 2] = red;

            }
            
        }

        pSrcData = m_pRgbCvtBuf;

    }

    if (m_hBitmap &&
        m_pvBits)
    {
        
//         if (MVR_PF_MONO8 == m_nPixelType ||
//             MVR_PF_RGB24 == m_nPixelType)
//         {
        /*减少内存拷贝,除了RGB24,都直接用此接口传入的图像内存地址进行渲染,应用层调用Display时需加锁保护该内存地址*/
        m_pvBitsDisplay = pSrcData;
//         }
//         else
//         {
//             memcpy(m_pvBits, pSrcData, nWidth * nHeight * nPixelSize);
//             m_pvBitsDisplay = m_pvBits;
//         }   
        
    }

    return MVR_RETURN_OK;
}

/** @func name   AddSubPort
 *  @func brief
 *  @param       unsigned int nPort

 *  @return      unsigned int
**/
unsigned int CGdiRender::AddSubPort(unsigned int nPort)
{
    //CSRLock lock(&m_stPortMutex);

    if (nPort >= MVR_MAX_PORT)
    {
        return MVR_ERR_INVALID_SUB_PORT;
    }

    if (m_stPortInfo[nPort].nState)
    {
        return MVR_ERR_PORT_USING;
    }

    m_stPortInfo[nPort].nState = 1;

    return MVR_RETURN_OK;
}

/** @func name   DelSubPort
 *  @func brief
 *  @param       unsigned int nPort

 *  @return      unsigned int
**/
unsigned int CGdiRender::DelSubPort(unsigned int nPort)
{
    //CSRLock lock(&m_stPortMutex);

    if (nPort >= MVR_MAX_PORT)
    {
        return MVR_ERR_INVALID_SUB_PORT;
    }

    if (m_stPortInfo[nPort].nState)
    {
        if (m_stPortInfo[nPort].hMemDc)
        {
            DeleteObject(m_stPortInfo[nPort].hMemDc);
        }
        if (m_stPortInfo[nPort].hBitmap)
        {
            DeleteObject(m_stPortInfo[nPort].hBitmap);
        }
        if (m_stPortInfo[nPort].hWnd &&
            m_stPortInfo[nPort].hDC)
        {
            ::ReleaseDC(m_stPortInfo[nPort].hWnd, m_stPortInfo[nPort].hDC);
        }

        memset(&m_stPortInfo[nPort], 0, sizeof(PORTINFO));

        m_stPortInfo[nPort].stDisplaySrc.fLeft   = 0.0;
        m_stPortInfo[nPort].stDisplaySrc.fRight  = 1.0;
        m_stPortInfo[nPort].stDisplaySrc.fTop    = 0.0;
        m_stPortInfo[nPort].stDisplaySrc.fBottom = 1.0;

        m_stPortInfo[nPort].stDisplayDst.fLeft   = 0.0;
        m_stPortInfo[nPort].stDisplayDst.fRight  = 1.0;
        m_stPortInfo[nPort].stDisplayDst.fTop    = 0.0;
        m_stPortInfo[nPort].stDisplayDst.fBottom = 1.0;
    }

    return MVR_RETURN_OK;
}

/** @func name   Display
 *  @func brief
 *  @param       unsigned int nPort
 *  @param       void * hWnd

 *  @return      unsigned int
**/
unsigned int CGdiRender::Display(unsigned int nPort, void* hWnd)
{


    //CSRLock lock(&m_stPortMutex);

    if (m_nImageWidth  == 0 ||
        m_nImageHeight == 0)
    {
        return MVR_RETURN_FAIL;
    }

    if (nPort >= MVR_MAX_PORT)
    {
        return MVR_ERR_INVALID_SUB_PORT;
    }

    if (NULL == hWnd)
    {
        return MVR_ERR_INPUT_PARAM;
    }

    if (!m_stPortInfo[nPort].nState)
    {
        return MVR_ERR_INVALID_SUB_PORT;
    }

#ifdef USE_DOUBLE_BUFFER

    if (NULL == m_stPortInfo[nPort].hWnd)
    {
        if (!::IsWindow((HWND)hWnd))
        {
            return MVR_ERR_INVALID_HWND;
        }

        m_stPortInfo[nPort].hWnd = (HWND)hWnd;
        m_stPortInfo[nPort].hDC  = ::GetDC(m_stPortInfo[nPort].hWnd);

        if (m_stPortInfo[nPort].hMemDc == NULL)
        {
            m_stPortInfo[nPort].hMemDc = CreateCompatibleDC(m_stPortInfo[nPort].hDC);
            SetStretchBltMode(m_stPortInfo[nPort].hMemDc, COLORONCOLOR);
        }
    }
    else
    {
        if (hWnd != m_stPortInfo[nPort].hWnd)
        {
            ::ReleaseDC(m_stPortInfo[nPort].hWnd, m_stPortInfo[nPort].hDC);
            m_stPortInfo[nPort].hWnd = (HWND)hWnd;
            m_stPortInfo[nPort].hDC  = ::GetDC(m_stPortInfo[nPort].hWnd);

            if (m_stPortInfo[nPort].hMemDc)
            {
                DeleteObject(m_stPortInfo[nPort].hMemDc);
            }            
            m_stPortInfo[nPort].hMemDc = CreateCompatibleDC(m_stPortInfo[nPort].hDC);
            SetStretchBltMode(m_stPortInfo[nPort].hMemDc, COLORONCOLOR);

            if (m_stPortInfo[nPort].hBitmap)
            {
                DeleteObject(m_stPortInfo[nPort].hBitmap);
                m_stPortInfo[nPort].hBitmap = NULL;
                m_nWndWidth  = 0;
                m_nWndHeight = 0;
            }                        
        }
    }


    RECT wndRect;
    ::GetClientRect(m_stPortInfo[nPort].hWnd, &wndRect);

    if (wndRect.right  != m_nWndWidth ||
        wndRect.bottom != m_nImageHeight)
    {
        m_nWndWidth  = wndRect.right;
        m_nWndHeight = wndRect.bottom;

        if (m_stPortInfo[nPort].hBitmap)
        {
            DeleteObject(m_stPortInfo[nPort].hBitmap);
            m_stPortInfo[nPort].hBitmap = NULL;
            m_nWndWidth  = 0;
            m_nWndHeight = 0;
        }

        if (m_stPortInfo[nPort].hBitmap == NULL)
        {
            m_stPortInfo[nPort].hBitmap = CreateCompatibleBitmap(m_stPortInfo[nPort].hDC, wndRect.right, wndRect.bottom);
        }
    }

    int nWndRectWidth  = wndRect.right  - wndRect.left;
    int nWndRectHeight = wndRect.bottom - wndRect.top;

    int nDstX      = wndRect.left + (int)(m_stPortInfo[nPort].stDisplayDst.fLeft * nWndRectWidth);
    int nDstY      = wndRect.top  + (int)(m_stPortInfo[nPort].stDisplayDst.fTop  * nWndRectHeight);
    int nDstWidth  = (int)((m_stPortInfo[nPort].stDisplayDst.fRight - m_stPortInfo[nPort].stDisplayDst.fLeft) * nWndRectWidth);
    int nDstHeight = (int)((m_stPortInfo[nPort].stDisplayDst.fBottom - m_stPortInfo[nPort].stDisplayDst.fTop) * nWndRectHeight);

    int nSrcX      = (int)(m_stPortInfo[nPort].stDisplaySrc.fLeft * m_nImageWidth);
    int nSrcY      = (int)(m_stPortInfo[nPort].stDisplaySrc.fTop * m_nImageHeight);
    int nSrcWidth  = (int)((m_stPortInfo[nPort].stDisplaySrc.fRight  - m_stPortInfo[nPort].stDisplaySrc.fLeft) * m_nImageWidth);
    int nSrcHeight = (int)((m_stPortInfo[nPort].stDisplaySrc.fBottom - m_stPortInfo[nPort].stDisplaySrc.fTop) * m_nImageHeight);



    HBITMAP hOldBmp = (HBITMAP)SelectObject(m_stPortInfo[nPort].hMemDc, m_stPortInfo[nPort].hBitmap);

    StretchDIBits(m_stPortInfo[nPort].hMemDc,
        nDstX, nDstY, nDstWidth, nDstHeight,
        nSrcX, nSrcY, nSrcWidth, nSrcHeight, m_pvBits, m_pstBitmapInfo, DIB_RGB_COLORS, SRCCOPY);


    if (m_stPortInfo[nPort].cbFunc)
    {
        m_stPortInfo[nPort].cbFunc(m_stPortInfo[nPort].pUser, nPort, m_stPortInfo[nPort].nCBType, NULL, m_nImageWidth, m_nImageHeight);
    }

    BitBlt(m_stPortInfo[nPort].hDC, 0, 0, wndRect.right, wndRect.bottom, m_stPortInfo[nPort].hMemDc, 0, 0, SRCCOPY);

    SelectObject(m_stPortInfo[nPort].hMemDc, hOldBmp); 

#else

    if (NULL == m_stPortInfo[nPort].hWnd)
    {
        if (!::IsWindow((HWND)hWnd))
        {
            return MVR_ERR_INVALID_HWND;
        }

        m_stPortInfo[nPort].hWnd = (HWND)hWnd;
        m_stPortInfo[nPort].hDC  = ::GetDC(m_stPortInfo[nPort].hWnd);
        SetStretchBltMode(m_stPortInfo[nPort].hDC, COLORONCOLOR);

    }
    else
    {
        if (hWnd != m_stPortInfo[nPort].hWnd)
        {
            ::ReleaseDC(m_stPortInfo[nPort].hWnd, m_stPortInfo[nPort].hDC);
            m_stPortInfo[nPort].hWnd = (HWND)hWnd;
            m_stPortInfo[nPort].hDC  = ::GetDC(m_stPortInfo[nPort].hWnd);

            SetStretchBltMode(m_stPortInfo[nPort].hDC, COLORONCOLOR); 
                       
        }
    }


    RECT wndRect;
    ::GetClientRect(m_stPortInfo[nPort].hWnd, &wndRect);

    if (wndRect.right  != m_nWndWidth ||
        wndRect.bottom != m_nImageHeight)
    {
        m_nWndWidth  = wndRect.right;
        m_nWndHeight = wndRect.bottom;
    }

    int nWndRectWidth  = wndRect.right  - wndRect.left;
    int nWndRectHeight = wndRect.bottom - wndRect.top;

    int nDstX      = wndRect.left + (int)(m_stPortInfo[nPort].stDisplayDst.fLeft * nWndRectWidth);
    int nDstY      = wndRect.top  + (int)(m_stPortInfo[nPort].stDisplayDst.fTop  * nWndRectHeight);
    int nDstWidth  = (int)((m_stPortInfo[nPort].stDisplayDst.fRight - m_stPortInfo[nPort].stDisplayDst.fLeft) * nWndRectWidth);
    int nDstHeight = (int)((m_stPortInfo[nPort].stDisplayDst.fBottom - m_stPortInfo[nPort].stDisplayDst.fTop) * nWndRectHeight);

    int nSrcX      = (int)(m_stPortInfo[nPort].stDisplaySrc.fLeft * m_nImageWidth);
    /*Bitmap默认图像上下颠倒,设置显示区域时m_stPortInfo[nPort].stDisplaySrc.fTop调整为1.0 - m_stPortInfo[nPort].stDisplaySrc.fBottom*/
    int nSrcY      = (int)((1.0 - m_stPortInfo[nPort].stDisplaySrc.fBottom) * m_nImageHeight);
    int nSrcWidth  = (int)((m_stPortInfo[nPort].stDisplaySrc.fRight  - m_stPortInfo[nPort].stDisplaySrc.fLeft) * m_nImageWidth);
    int nSrcHeight = (int)((m_stPortInfo[nPort].stDisplaySrc.fBottom - m_stPortInfo[nPort].stDisplaySrc.fTop) * m_nImageHeight);

   
    StretchDIBits(m_stPortInfo[nPort].hDC,
                  nDstX, nDstY, nDstWidth, nDstHeight,
                  nSrcX, nSrcY, nSrcWidth, nSrcHeight, m_pvBitsDisplay, m_pstBitmapInfo, DIB_RGB_COLORS, SRCCOPY);

    if (m_stPortInfo[nPort].cbFunc)
    {
        m_stPortInfo[nPort].cbFunc(m_stPortInfo[nPort].pUser, nPort, m_stPortInfo[nPort].nCBType, NULL, m_nImageWidth, m_nImageHeight);
    }


    

#endif

  

    return MVR_RETURN_OK;
}

/** @func name   SetDisplayRect
 *  @func brief
 *  @param       unsigned int nPort
 *  @param       MVRRECTF * pstDisplayRectSrc
 *  @param       MVRRECTF * pstDisplayRectDst

 *  @return      unsigned int
**/
unsigned int CGdiRender::SetDisplayRect(unsigned int nPort, MVRRECTF* pstDisplayRectSrc, MVRRECTF* pstDisplayRectDst)
{
    //CSRLock lock(&m_stPortMutex);

    if (nPort >= MVR_MAX_PORT)
    {
        return MVR_ERR_INVALID_SUB_PORT;
    }

    if ((NULL == pstDisplayRectSrc) ||
        (NULL == pstDisplayRectDst))
    {
        return MVR_ERR_INPUT_PARAM;
    }

    if (!m_stPortInfo[nPort].nState)
    {
        return MVR_ERR_INVALID_SUB_PORT;
    }

    if ((MVR_CheckRectF(pstDisplayRectSrc) != MVR_RETURN_OK) ||
        (MVR_CheckRectF(pstDisplayRectDst) != MVR_RETURN_OK))
    {
        return MVR_ERR_INVALID_RECT;
    }

    memcpy(&(m_stPortInfo[nPort].stDisplaySrc), pstDisplayRectSrc, sizeof(MVRRECTF));
    memcpy(&(m_stPortInfo[nPort].stDisplayDst), pstDisplayRectDst, sizeof(MVRRECTF));

    return MVR_RETURN_OK;
}

/** @func name   SetCallBack
 *  @func brief
 *  @param       unsigned int nPort
 *  @param       unsigned int nCBType
 *  @param       MVR_CallBack cbFunc
 *  @param       void * pUser

 *  @return      unsigned int
**/
unsigned int CGdiRender::SetCallBack(unsigned int nPort, unsigned int nCBType, MVR_CallBack cbFunc, void* pUser)
{
    //CSRLock lock(&m_stPortMutex);

    if (nPort >= MVR_MAX_PORT)
    {
        return MVR_ERR_INVALID_SUB_PORT;
    }

    if ((NULL == cbFunc) ||
        (NULL == pUser))
    {
        return MVR_ERR_INPUT_PARAM;
    }

    if (!m_stPortInfo[nPort].nState)
    {
        return MVR_ERR_INVALID_SUB_PORT;
    }

    m_stPortInfo[nPort].nCBType = nCBType;
    m_stPortInfo[nPort].cbFunc  = cbFunc;
    m_stPortInfo[nPort].pUser   = pUser;

    return MVR_RETURN_OK;
}



unsigned int CGdiRender::InitImage()
{
    if (NULL == m_hBitmap)
    {

        if (NULL == m_pstBitmapInfo)
        {
            m_pstBitmapInfo = (PBITMAPINFO)malloc(sizeof(BITMAPINFO) + 256 * sizeof(RGBQUAD));
        }
        memset(m_pstBitmapInfo, 0, sizeof(BITMAPINFO) + 256 * sizeof(RGBQUAD));
        m_pstBitmapInfo->bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
        m_pstBitmapInfo->bmiHeader.biWidth       = m_nImageWidth;
        m_pstBitmapInfo->bmiHeader.biHeight      = -m_nImageHeight;
        m_pstBitmapInfo->bmiHeader.biPlanes      = 1;
        m_pstBitmapInfo->bmiHeader.biCompression = BI_RGB;

        switch (m_nPixelType)
        {
        case MVR_PF_MONO8:
            {
                m_pstBitmapInfo->bmiHeader.biBitCount = 8;

                for (int i = 0; i < 256; i++)
                {
                    m_pstBitmapInfo->bmiColors[i].rgbRed      = i;
                    m_pstBitmapInfo->bmiColors[i].rgbGreen    = i;
                    m_pstBitmapInfo->bmiColors[i].rgbBlue     = i;
                    m_pstBitmapInfo->bmiColors[i].rgbReserved = 0;
                }
            }
            break;
        case MVR_PF_RGB24:        
            {
                m_pstBitmapInfo->bmiHeader.biBitCount = 24;
               
            }
            break;
        case MVR_PF_RGBA32:
            {
                m_pstBitmapInfo->bmiHeader.biBitCount = 32;
            }
            break;
        default:
            break;
        }

        m_hBitmap = CreateDIBSection(NULL, m_pstBitmapInfo, DIB_RGB_COLORS, &m_pvBits, NULL, 0);

    }

    return 1;
}

unsigned int CGdiRender::DeInitImage()
{
    if (NULL != m_hBitmap)
    {
        DeleteObject(m_hBitmap);
        m_hBitmap = NULL;
    }

    if (NULL != m_pstBitmapInfo)
    {
        free(m_pstBitmapInfo);
        m_pstBitmapInfo = NULL;
    }

    return MVR_RETURN_OK;
}

