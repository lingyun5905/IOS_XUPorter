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

#if defined _WIN32 || defined _WIN64
#include <winbase.h>
#endif
#include "ProcHeap.h"
#include "Singleton.h"
#include "Event.h"
#include "PnThread.h"
#include "sysutil.h"
#include "BasicTypes.h"
#include "SysTime.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/*	�� �Լ����� Windows Vista ���Ŀ��� �� �� ����. ���� ����.

	// ���� �ϳ� ���� critical section���� ��ȣ�Ǵ� read/write�� �����׼�.
	// 32bit OS���� 64bit ���� volatile keyword���� �����ؼ� i/o�ϴ� ���� non-atomic. �� tearing�� ������ ����.
	// �̸� �����ϰ��� �� �Լ����� ����
	// ���� ����, align(8)�� �Ǿ� �־�� ��
	inline double InterlockedRead(volatile double* src)
	{
	LONGLONG *src2 = (LONGLONG*)src;
	LONGLONG ret0 = InterlockedOr64(&src2, 0);
	double* pRet = (double*)&ret0; // raw data cast
	return *pRet;
	}

	inline void InterlockedWrite(volatile double* dest, double newValue)
	{
	LONGLONG* dest2 = (LONGLONG*)dest;
	LONGLONG* pNewValue2 = (LONGLONG*)&newValue; // raw cast
	InterlockedExchange64(&dest2, *pNewValue);
	}*/

	/** \addtogroup util_group
	*  @{
	*/

	/**
	\~korean
	CTimerQueue::NewTimer �� ���� �Ѱ��ִ� �Ķ���� �Դϴ�.

	\~english
	Parameter that pass CTimerQueue::NewTimer when it needs

	\~chinese
	���� CTimerQueue::NewTimer%??����??��

	\~japanese
	CTimerQueue::NewTimer �����������ڪ�Ԥ���ѫ��?��?�Ǫ���
	\~
	*/
#if defined(_WIN32)
	struct NewTimerParam {
		/**
		\~korean
		�� �ð����� �ݹ� �Ǿ��� �Լ��� �����մϴ�.

		\~english
		Set function that will callback every hours

		\~chinese
		?����ӫ??����?����?��

		\~japanese
		?���઴�Ȫ˫�?��Ыë������??�����Ҫ��ު���
		\~
		*/
		WaitOrTimerCallbackProc m_callback;

		/**
		\~korean
		Callback �Ǿ����� �����Ͱ��� �����մϴ�.

		\~english
		Designate pointer value that can callback

		\~chinese
		���callback���??��

		\~japanese
		��?��Ыë������ݫ���?������Ҫ��ު���
		\~
		*/
		void *m_pCtx;

		/**
		\~korean
		�Ź� Callback �Ǿ����� �ð��� �Է��մϴ�.

		\~english
		Enter the time to callback

		\~chinese
		?�����callback��??��

		\~japanese
		?�ޫ�?��Ыë������������������ު���
		\~
		*/
		uint32_t m_period;

		/**
		\~korean
		DueTime ���� ������ �ð� ���� ���� Callback �� ���۵˴ϴ�.

		\~english
		Callback will start time which is set by Duetime

		\~chinese
		?���?DueTime??���?�?��callback��

		\~japanese
		DueTime����Ҫ��쪿�����˽����Callback����㷪���ު���
		\~
		*/
		uint32_t m_DueTime;

		NewTimerParam() : m_callback(0), m_pCtx(0), m_period(0), m_DueTime(0) {}
		NewTimerParam(WaitOrTimerCallbackProc callback, void *pCtx, uint32_t period, uint32_t DueTime);
	};

	class CTimerQueueTimer;

	/**
	\~korean
	�����忡 �̸��� �����Ѵ�. �̷��� �ϸ� ����� ������ �信�� �� �����忡 �̸��� ǥ�õȴ�.
	- ������� ������ ���̴�.
	- ���� �ڼ��� ������
	ms-help://MS.VSCC.2003/MS.MSDNQTR.2003APR.1033/vsdebug/html/vxtskSettingThreadName.htm ����

	\~english
	Designates a name to thread. By doing so, each thread will have their names shown at debugger thread view.
	- Debugging will be easier.
	- Please refer
	ms-help://MS.VSCC.2003/MS.MSDNQTR.2003APR.1033/vsdebug/html/vxtskSettingThreadName.htm

	\~chinese
	??�����٣��??��?�???��view��??����??����٣��
	- ???��ʥ۰����
	- ???�??��
	ms-help://MS.VSCC.2003/MS.MSDNQTR.2003APR.1033/vsdebug/html/vxtskSettingThreadName.htm ��

	\~japanese
	����ëɪ�٣�����Ҫ��ު������Ϊ誦�˪���ȡ��ǫЫë�?����ëɫӫ�?��������ëɪ�٣�����ƪ���ު���
	- �ǫЫë��󫰪��涪��ʪ�ު���
	- ����٪����ϡ�
	ms-help://MS.VSCC.2003/MS.MSDNQTR.2003APR.1033/vsdebug/html/vxtskSettingThreadName.htm ��?�Ϊ���������

	\~
	*/
	PROUD_API void SetThreadName(uint32_t dwThreadID, const char* szThreadName);

	/**
	\~korean
	�� �������� ���� �ڵ��� ���Ѵ�.

	\~english
	Gets the real handle of this thread

	\~chinese
	ϴ�?����??handle��

	\~japanese
	���Ϋ���ëɪ�?�ϫ�ɪ�ϴ��ު���
	\~
	*/
	PROUD_API HANDLE GetCurrentRealThread();

	/**
	\~korean
	�ü������ �����ϴ� Thread Pool���� ���� �ð������� tick event�� ������ �� �ְ� �ϴ�
	�̱��� Ŭ�����̴�.
	- CTimerQueueTimer �� ȥ��ȴ�.
	- �ڼ��� ���� <a target="_blank" href="http://guide.nettention.com/cpp_ko#timer_queue" >Timer Queue (Thread pool���� tick event�� �����ϴ� ���)</a> �� ����ٶ�
	- Windows 98 ���� ���������� �� �� ����.

	\~english
	Singleton class that can execute periodic tick event at thread pool provided by OS
	- Regarded as CTimerQueueTimer
	- Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#timer_queue" >Timer Queue (A module that operates tick event from thread pool)</a>
	- Cannot be used Windows 98 or older version

	\~chinese
	??��?ͧ�����Thread Pool��������??��?��tick event��singleton?��
	- ? CTimerQueueTimer%���ġ�
	- ??��??��<a target="_blank" href="http://guide.nettention.com/cpp_zh#timer_queue" >Timer Queue (�Thread pool��?��tick event��ټ?)</a>%��
	- �Windows 98��������������ġ�

	\~japanese
	OS����ꪹ��ThreadPool��������઴�Ȫ�tick event��?���Ǫ���誦�˪��뫷�󫰫�ȫ󫯫髹�Ǫ���
	- CTimerQueueTimer �����Ī���ު���
	- �٪����ϡ�\ref timer_queue��?�Ϊ���������
	- Windows 98 ����Ϋ�?�����Ǫ��Ū��ު���
	\~
	*/
	class CTimerQueue : public CSingleton<CTimerQueue>
	{
		friend CTimerQueueTimer;
		HANDLE m_timerQueue;
		Event m_endEvent;

	public:
		CTimerQueue();
		~CTimerQueue();

		/**
		\~korean
		���� �ð����� ���� �Լ��� ȣ���� ����Ѵ�.
		- ���� �Լ� ȣ���� ����ϸ� CTimerQueueTimer ��ü�� ���ϵȴ�.
		- ���� �Լ� ȣ���� CTimerQueue �̱��濡 ������ �ߺ��ؼ� ����ص� �ȴ�.

		\param callback ���� �ð����� ȣ��� ���� �Լ�
		\param ctx callback�� ���޵� ���� �Ķ����
		\param period ���� �Լ��� ȣ��� �ֱ�(�и���)

		\~english
		Periodically registeres user function calling
		- Once registered then CTimerQueueTimer object is returned.
		- Calling user function can be repeatedly registered at CTimerQueue singleton.

		\param callback User function to be called periodically
		\param ctx user parameter to be delivered to callback
		\param period the period that user function to be called in millisecond

		\~chinese
		������??��?��?��?����У��
		- ��?��?��?��У��?���� CTimerQueueTimer%?�ڡ�
		- ��?��?����Уʦ�� CTimerQueue singleton��???����?��

		\param callback ������??���У����?��?��
		\param ctx ???callback����???��
		\param period ���У��?��?���Ѣ����������

		\~japanese
		������઴�ȪΫ�?��???�������󪷪���?���ު���
		- ��?��???�������󪷪���?����� CTimerQueueTimer ���֫������Ȫ��꫿?�󪵪�ު���
		- ��?��???�������󪷪�CTimerQueue ���󫰫�ȫ����?�����ܪ�����?���ƪ��ު��Ǫ���

		\param callback ������઴�Ȫ������󪵪���?��???
		\param ctx callback��?�����?��?�ѫ��?��?
		\param period ��?��???�������󪵪���Ѣ���߫�����
		\~
		*/
		PROUD_API CTimerQueueTimer* NewTimer(NewTimerParam& Param);
	};

	/**
	\~korean
	���� �ð����� ������ Ǯ���� �־��� �Լ��� ȣ���ϴ� Ÿ�̸� ��ü
	- �ڼ��� ���� <a target="_blank" href="http://guide.nettention.com/cpp_ko#timer_queue" >Timer Queue (Thread pool���� tick event�� �����ϴ� ���)</a> �� ����ٶ�
	- CTimerQueue.NewTimer �� ���ؼ� ���ϵǴ� ��ü�� Ÿ���̴�. �� ��ü�� �ı��ϱ� ������ CTimerQueue.NewTimer �� ����
	��ϵ� �Լ��� ���� �ð����� ������ Ǯ���� ����ȴ�.
	- ���� �뵵�� ���� ���� �����Ѵ�. Windows 98 ���� ���������� �� �� ����.

	\~english
	Timer object that periodicaly calls the functions provided by thread pool
	- Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#timer_queue" >Timer Queue (A module that operates tick event from thread pool)</a>.
	- Type of object that is returned by CTimerQueue.NewTimer. Until this object is destructed, the function registered by CTimerQueue.NewTimer is executed periodically in thread pool.
	- Recommended to use for server. Cannot be used for Windows 98 or older version.

	\~chinese
	������??��??��?��У������?��timer?�ڡ�
	- ????��<a target="_blank" href="http://guide.nettention.com/cpp_zh#timer_queue" >Timer Queue (�Thread pool��?��tick event��ټ?)</a>%��
	- �� CTimerQueue.NewTimer%������?��?��������?�?��?򭣬�� CTimerQueue.NewTimer%��?����?������??�?����?����
	- ��?������?����Բ���Windows 98��������������ġ�

	\~japanese
	������઴�Ȫ˫���ëɫ�?����?����쪿??�������󪹫�����?���֫�������
	- �٪�����\ref timer_queue��?�Ϊ���������
	- CTimerQueue.NewTimer �˪�êƫ꫿?�󪵪�뫪�֫������ȪΫ����תǪ������Ϋ��֫������Ȫ���?������ު�CTimerQueue.NewTimer�˪�ê���?���쪿??���������઴�Ȫ˫���ëɫ�?���?������ު���
	- ��?��?��Բ���Ū����Ȫ�?�᪷�ު��� Windows 98����Ϋ�?�����Ǫ��Ū��ު���
	\~
	*/
	class CTimerQueueTimer
	{
		friend CTimerQueue;

		CTimerQueue *m_manager;
		HANDLE m_timer;
		Event m_endEvent;

		CTimerQueueTimer() {} // ����� ���� ����
	public:

		PROUD_API ~CTimerQueueTimer();

#ifdef _WIN32
#pragma push_macro("new")
#undef new
		// �� Ŭ������ ProudNet DLL ��츦 ���� Ŀ���� �Ҵ��ڸ� ���� fast heap�� ���� �ʴ´�.
		DECLARE_NEW_AND_DELETE
#pragma pop_macro("new")
#endif
	};

#endif // _WIN32
	/**  @} */

	// win32 or not�� ����
	inline void* TlsGetValue(uint32_t tlsIndex)
	{
#ifdef _WIN32
		return ::TlsGetValue(tlsIndex);
#else
		return pthread_getspecific(tlsIndex);
#endif
	}

	// win32 or not�� ����
	inline bool TlsSetValue(uint32_t tlsIndex, void* tlsValue)
	{
#ifdef _WIN32
		return ::TlsSetValue(tlsIndex, tlsValue) != 0;
#else
		return pthread_setspecific(tlsIndex, (const void*)tlsValue) == 0;
#endif
	}

	uint32_t TlsAlloc();
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
