/** @file    MvrUtil.cpp
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
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void MVR_PrintInfo(char * szFormat, ...)
{
    char szInfo[512];
    va_list ArgumentList;
    va_start(ArgumentList, szFormat);
    vsprintf_s(szInfo, 512, szFormat, ArgumentList);
    va_end(ArgumentList);

    OutputDebugStringA(szInfo);         


    return ;
}


unsigned int MVR_CheckFloatValue(float fValue)
{
    if ((fValue > 1.0f)||
        (fValue < 0.0f))
    {
        return MVR_ERR_INVALID_FLOAT;
    }

    return MVR_RETURN_OK;
}

unsigned int MVR_CheckRectF(MVRRECTF* pstRect)
{
    if (NULL == pstRect)
    {
        return MVR_ERR_INPUT_PARAM;
    }

    if ((pstRect->fLeft >= pstRect->fRight) ||
        (pstRect->fTop  >= pstRect->fBottom))
    {
        return MVR_ERR_INVALID_RECT;
    }

    if ((MVR_CheckFloatValue(pstRect->fLeft)   != MVR_RETURN_OK) ||
        (MVR_CheckFloatValue(pstRect->fRight)  != MVR_RETURN_OK) ||
        (MVR_CheckFloatValue(pstRect->fTop)    != MVR_RETURN_OK) ||
        (MVR_CheckFloatValue(pstRect->fBottom) != MVR_RETURN_OK))
    {
        return MVR_ERR_INVALID_RECT;
    }

    return MVR_RETURN_OK;    
}

unsigned int MVR_CheckColorF(MVRCOLORF* pstColor)
{
    if (NULL == pstColor)
    {
        return MVR_ERR_INPUT_PARAM;
    }

    if ((MVR_CheckFloatValue(pstColor->fR)     != MVR_RETURN_OK) ||
        (MVR_CheckFloatValue(pstColor->fG)     != MVR_RETURN_OK) ||
        (MVR_CheckFloatValue(pstColor->fB)     != MVR_RETURN_OK) ||
        (MVR_CheckFloatValue(pstColor->fAlpha) != MVR_RETURN_OK))
    {
        return MVR_ERR_INVALID_COLOR;
    }

    return MVR_RETURN_OK;
}

unsigned int MVR_CheckPointF(MVRPOINTF* pstPoint)
{
    if (NULL == pstPoint)
    {
        return MVR_ERR_INPUT_PARAM;
    }

    if ((MVR_CheckFloatValue(pstPoint->fX) != MVR_RETURN_OK) ||
        (MVR_CheckFloatValue(pstPoint->fY) != MVR_RETURN_OK))
    {
        return MVR_ERR_INVALID_POINT;
    }

    return MVR_RETURN_OK;
}

