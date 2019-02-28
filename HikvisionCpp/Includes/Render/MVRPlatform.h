/** @file    MVRPlatform.h
 *  @note    Hikvision Digital Technology Co., Ltd. All Rights Reserved.
 *  @brief   
 *
 *  @author  
 *  @date    2016/06/29
 *  @note    V1.0.0
 *
 *  @warning 
 */

#ifndef __MV_RENDER_PLATFORM_H__
#define __MV_RENDER_PLATFORM_H__

#ifdef WIN32
    #ifndef MVR_WIN32
    #define MVR_WIN32 WIN32
    #endif

    #if defined(MVRENDER_EXPORTS)
    #define MVR_API  extern "C" __declspec(dllexport) 
    #else 
    #define MVR_API  extern "C" __declspec(dllimport) 
    #endif

#endif



#endif  /*__MV_RENDER_PLATFORM_H__*/