/** @file    SRMutex.h
 *  @note    HangZhou Hikvision Software Co., Ltd. All Right Reserved.
 *  @brief   跨平台渲染库互斥锁相关定义的头文件
 *
 *  @author  播放应用软件组 -- 王川艳
 *  @date    2013/03/01
 *  @note    V1.0.0
 *
 *  @warning 版权所有
 */
#ifndef __SR_MUTEX_H__
#define __SR_MUTEX_H__




	#include "windows.h"
	#include "process.h"
	#define SR_Mutex  CRITICAL_SECTION


/*************************** 线程锁定义 ************************************/

// 重新封装的互斥锁类
class CSRMutex
{
public:
	// 构造函数
	CSRMutex();
	// 析构函数
	~CSRMutex();
	// 进入互斥锁
	void Lock();
	// 解锁
	void UnLock();
private:
	// win32下面是临界区 ，linux和apple下面是互斥锁
	SR_Mutex  m_pMutex;
};

// 将互斥锁的调用封装到一个类中
class CSRLock
{
public:
	// win32 下面进入临界区 ， linux和apple下面进入互斥锁状态
	CSRLock(CSRMutex * pMutex)
	{
		m_pMutex = pMutex;
		if (NULL != pMutex)
		{
			pMutex->Lock();
		}
	};

	// win32 下面出临界区 ， linux和apple下面出互斥锁
	~CSRLock()
	{
		if (NULL != m_pMutex)
		{
			m_pMutex->UnLock();
		}
		m_pMutex = NULL;
	};
private:
	// 临界区/互斥锁相关的成员变量
	CSRMutex * m_pMutex;
};

/***************************************************************/

#endif