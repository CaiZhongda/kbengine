#ifndef __KBENGINE_DLL__
#define __KBENGINE_DLL__

#include "stdio.h"
#include "stdlib.h"
#include "cstdkbe/cstdkbe.hpp"
#include "python.h"

#ifdef KBE_DLL_API
#else
#define KBE_DLL_API  extern "C" _declspec(dllimport)
#endif

namespace KBEngine{
	class EventHandle;
}

/**
	��ʼ������������ģ��
*/
KBE_DLL_API bool kbe_init();
KBE_DLL_API bool kbe_destroy();

/**
	����һ��uint64λ��Ψһֵ(ע�⣺����ǰapp�в�����Ψһ��)
*/
KBE_DLL_API KBEngine::uint64 kbe_genUUID64(); 

/**
	����
*/
KBE_DLL_API void kbe_sleep(KBEngine::uint32 ms); 

/**
	��õ�ǰϵͳʱ�䣬 ����
*/
KBE_DLL_API KBEngine::uint32 kbe_getSystemTime();

/**
	��¼������
*/
KBE_DLL_API bool kbe_login(const char* accountName, const char* passwd, 
						   const char* ip = NULL, KBEngine::uint32 port = 0);

/**
	��������״̬
*/
KBE_DLL_API void kbe_update();

/**
	�������� ��ֹ���߳��·��ʽű��ȳ�����
	��Ҫ���python
*/
KBE_DLL_API void kbe_lock();
KBE_DLL_API void kbe_unlock();

/**
	��ȡ���һ��ʹ�õ��˺�
*/
KBE_DLL_API const char* kbe_getLastAccountName();

/**
	�õ�player�ĵ�ǰID
*/
KBE_DLL_API KBEngine::ENTITY_ID kbe_playerID();

/**
	�õ�player�ĵ�ǰdbid
*/
KBE_DLL_API KBEngine::DBID kbe_playerDBID();

/**
	ע��һ���¼�handle����������������¼�
	Ȼ������¼���������Ӧ�ı���
*/
KBE_DLL_API bool kbe_registerEventHandle(KBEngine::EventHandle* pHandle);
KBE_DLL_API bool kbe_deregisterEventHandle(KBEngine::EventHandle* pHandle);

/**
	���ýű�entity�ķ��� 
*/
KBE_DLL_API PyObject* kbe_callEntityMethod(KBEngine::ENTITY_ID entityID, const char *method, 
										   PyObject *args, PyObject *kw = NULL); 




#endif // __KBENGINE_DLL__