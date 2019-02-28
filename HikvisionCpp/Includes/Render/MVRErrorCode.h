/** @file    MVRErrorCode.h
 *  @note    Hikvision Digital Technology Co., Ltd. All Rights Reserved.
 *  @brief   
 *
 *  @author  
 *  @date    2016/06/29
 *  @note    V1.0.0
 *
 *  @warning 
 */

#ifndef __MV_RENDER_ERROR_CODE_H__
#define __MV_RENDER_ERROR_CODE_H__

#define MVR_RETURN_OK				1 // 返回成功
#define MVR_RETURN_FAIL				0 // 返回失败

#define MVR_ERR_INPUT_PARAM        0x80000001 // 无效的入参
#define MVR_ERR_RESOURECE          0x80000002 // 资源申请失败
#define MVR_ERR_INVALID_SUB_PORT   0x80000003 // 非法的端口号
#define MVR_ERR_PORT_USING         0x80000004 // 端口号已被占用
#define MVR_ERR_INVALID_HWND       0x80000005 // 无效的显示句柄
#define MVR_ERR_INVALID_RECT       0x80000006 // 无效的矩形区域
#define MVR_ERR_INVALID_FLOAT      0x80000007 // 无效的归一化浮点值
#define MVR_ERR_INVALID_COLOR      0x80000008 // 无效的颜色
#define MVR_ERR_INVALID_HANDLE     0x80000009 // 无效的句柄
#define MVR_ERR_INVALID_POINT      0x8000000A // 无效的点


#endif  /*__MV_RENDER_ERROR_CODE_H__*/