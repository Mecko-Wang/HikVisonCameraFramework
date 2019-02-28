/** @file    SRMutex.cpp
 *  @note    HangZhou Hikvision Software Co., Ltd. All Right Reserved.
 *  @brief   跨平台渲染库互斥锁相关定义的实现文件
 *
 *  @author  播放应用软件组 -- 王川艳
 *  @date    2013/03/01
 *  @note    V1.0.0
 *
 *  @warning 版权所有
 */
#include "SRMutex.h"

/*************************** 线程锁定义 ************************************/

/**	@fn	     CSRMutex
 *	@brief	 构造函数
 *	@return	
	见返回值类型说明
 */
CSRMutex::CSRMutex()
{
	

	InitializeCriticalSection(&m_pMutex);	

};

/**	@fn	     ~CSRMutex
 *	@brief	 析构函数
 *	@return	
	见返回值类型说明
 */
CSRMutex::~CSRMutex()
{
    DeleteCriticalSection(&m_pMutex);

};

/**	@fn	     Lock
 *	@brief	 进入锁状态
 *	@return	
	见返回值类型说明
 */
void CSRMutex::Lock()
{

    EnterCriticalSection(&m_pMutex);

};

/**	@fn	     UnLock
 *	@brief	 解锁
 *	@return	
	见返回值类型说明
 */
void CSRMutex::UnLock()
{

    LeaveCriticalSection(&m_pMutex);

};