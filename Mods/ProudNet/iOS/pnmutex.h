/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 177 92 124 113 87 79 17 155 171 239 138 133 88 235 28 112 146 102 93 52 214 131 240 31 138 179 248 115 127 118 107 31 112 91 111 14 243 1 121 131 22 69 144 19 214 101 65 133 253 32 122 175 12 198 63 134 23 240 109 90 59 142 194 194 160 148 139 101 68 220 217 181 32 240 36 47 59 74 18 182 145 116 17 29 255 115 236 11 29 111 122  */
/*
ProudNet 1.7.34387-dev003-10


�� ���α׷��� ���۱��� ���ټǿ��� �ֽ��ϴ�.
�� ���α׷��� ����, ���, ������ ���õ� ������ �� ���α׷��� �������ڿ��� ����� ������,
����� �ؼ����� �ʴ� ��� ��Ģ������ ���� ����� �����մϴ�.
���� ��뿡 ���� å���� �� ���α׷��� �������ڿ��� ��༭�� ��õǾ� �ֽ��ϴ�.

** ���� : ���۹��� ���� ���� ��ø� �������� ���ʽÿ�.


This program is soley copyrighted by Nettention.
Any use, correction, and distribution of this program are subject to the terms and conditions of the License Agreement.
Any violated use of this program is prohibited and will be cause of immediate termination according to the License Agreement.

** WARNING : PLEASE DO NOT REMOVE THE LEGAL NOTICE ABOVE.


���������??Nettention�������
?����������ǡ����ġ�?����?����?���������������?���??��
������???��?�������������ġ�
���������?��٥���?��������?�������?�졣

** ��������?�����ڪ��߾��٥�ơ�


���Ϋ׫���������?��Nettention�˪���ު���
���Ϋ׫��������ᡢ���ġ����֪�?������������׫��������?�Ȫ���峪�?����
��峪��������ʪ����ꡢ����ܪ���?���Ī��ת��ު���
��?���Ī˪���������׫��������?�Ȫ��������٥�ƪ���ƪ��ު���

** �������ڪ��?����߾����٥�ƪ���۪��ʪ��Ǫ���������

*/

#pragma once

#include "BasicTypes.h"
#include <errno.h>

#if defined(__ANDROID__)
#include <sys/syscall.h>
#elif defined(__linux__)
#include <sys/unistd.h>
#endif

#if !defined(_WIN32)
#include <pthread.h>
#endif

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	enum LockResult
	{
		LockResult_Success, // lock ����
		LockResult_Timeout, // timeout���� ���� ����
		LockResult_Error, // ��Ÿ ������ ����(���� �̹� ����� mutex)
	};

	class Mutex
	{
	public:
#if defined (_WIN32)
		HANDLE m_mutexHandle;
#else
		pthread_mutex_t m_mutexHandle;
#endif
		Mutex();
		~Mutex();

		inline LockResult TryLock()
		{
			return Lock(0);
		}

		// 0�̸� try-lock
		// PN_INFINITE�̸� ������ ����ϴ� ��� �õ�
		// �ƴϸ� �и���
		LockResult Lock(int timeout = PN_INFINITE);
		LockResult Unlock();
	};
}
#ifdef _MSC_VER
#pragma pack(pop)
#endif