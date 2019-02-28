/** @file    SRMutex.h
 *  @note    HangZhou Hikvision Software Co., Ltd. All Right Reserved.
 *  @brief   ��ƽ̨��Ⱦ�⻥������ض����ͷ�ļ�
 *
 *  @author  ����Ӧ������� -- ������
 *  @date    2013/03/01
 *  @note    V1.0.0
 *
 *  @warning ��Ȩ����
 */
#ifndef __SR_MUTEX_H__
#define __SR_MUTEX_H__




	#include "windows.h"
	#include "process.h"
	#define SR_Mutex  CRITICAL_SECTION


/*************************** �߳������� ************************************/

// ���·�װ�Ļ�������
class CSRMutex
{
public:
	// ���캯��
	CSRMutex();
	// ��������
	~CSRMutex();
	// ���뻥����
	void Lock();
	// ����
	void UnLock();
private:
	// win32�������ٽ��� ��linux��apple�����ǻ�����
	SR_Mutex  m_pMutex;
};

// ���������ĵ��÷�װ��һ������
class CSRLock
{
public:
	// win32 ��������ٽ��� �� linux��apple������뻥����״̬
	CSRLock(CSRMutex * pMutex)
	{
		m_pMutex = pMutex;
		if (NULL != pMutex)
		{
			pMutex->Lock();
		}
	};

	// win32 ������ٽ��� �� linux��apple�����������
	~CSRLock()
	{
		if (NULL != m_pMutex)
		{
			m_pMutex->UnLock();
		}
		m_pMutex = NULL;
	};
private:
	// �ٽ���/��������صĳ�Ա����
	CSRMutex * m_pMutex;
};

/***************************************************************/

#endif