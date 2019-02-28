/** @file    MvrUtil.h
 *  @note    Hikvision Digital Technology Co., Ltd. All Rights Reserved.
 *  @brief   
 *
 *  @author  luyao
 *  @date    2016/09/08
 *  @note    V1.0.0
 *
 *  @warning 
 */

#ifndef __MVR_UTIL_H__
#define __MVR_UTIL_H__

#include "MvRenderDefine.h"

void MVR_PrintInfo(char * szFormat, ...);

unsigned int MVR_CheckFloatValue(float fValue);

unsigned int MVR_CheckRectF(MVRRECTF* pstRect);

unsigned int MVR_CheckColorF(MVRCOLORF* pstColor);

unsigned int MVR_CheckPointF(MVRPOINTF* pstPoint);




#endif  /*__UTIL_H__*/