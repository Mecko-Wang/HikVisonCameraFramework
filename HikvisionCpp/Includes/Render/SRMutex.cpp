/** @file    SRMutex.cpp
 *  @note    HangZhou Hikvision Software Co., Ltd. All Right Reserved.
 *  @brief   ��ƽ̨��Ⱦ�⻥������ض����ʵ���ļ�
 *
 *  @author  ����Ӧ������� -- ������
 *  @date    2013/03/01
 *  @note    V1.0.0
 *
 *  @warning ��Ȩ����
 */
#include "SRMutex.h"

/*************************** �߳������� ************************************/

/**	@fn	     CSRMutex
 *	@brief	 ���캯��
 *	@return	
	������ֵ����˵��
 */
CSRMutex::CSRMutex()
{
	

	InitializeCriticalSection(&m_pMutex);	

};

/**	@fn	     ~CSRMutex
 *	@brief	 ��������
 *	@return	
	������ֵ����˵��
 */
CSRMutex::~CSRMutex()
{
    DeleteCriticalSection(&m_pMutex);

};

/**	@fn	     Lock
 *	@brief	 ������״̬
 *	@return	
	������ֵ����˵��
 */
void CSRMutex::Lock()
{

    EnterCriticalSection(&m_pMutex);

};

/**	@fn	     UnLock
 *	@brief	 ����
 *	@return	
	������ֵ����˵��
 */
void CSRMutex::UnLock()
{

    LeaveCriticalSection(&m_pMutex);

};