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
#include "Ptr.h"
#include "Event.h"
#include "CallbackContext.h"
#include "LambdaWrap.h"

#ifdef SUPPORTS_LAMBDA_EXPRESSION
#include <functional>
#endif
#include <memory>

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif

namespace Proud 
{
	class ThreadProcContext;

	/** \addtogroup util_group
	*  @{
	*/

	/** 
	\~korean
	�ܼ� ������ Wrapper Ŭ�����Դϴ�.
	- �� �ν��Ͻ��� ������ �� Start�� ȣ���ϸ� �����尡 �����˴ϴ�. �׸��� �� �ν��Ͻ��� �ı��Ǹ� �����Ǿ��� �����尡 ������ ������ ��ŷ�˴ϴ�.
	- �� Ŭ������ .net framework�� System.Threading.Thread Ŭ������ ���� �۵� ����� �����ϴ�.

	�Ϲ��� ����
	- Thread ��ü�� �����ϵ�, �Ķ���ͷ� ������ �Լ��� �����մϴ�. ������ �Լ��� �����ڿ��� �����մϴ�.
	- Thread ��ü�� �����Ѵٰ� �ؼ� �ٷ� �����尡 �۵������� �ʽ��ϴ�. Start�� �����ؾ߸� �մϴ�.
	- Join�� ȣ���ϰų� Thread ��ü�� �ı��� �� �������� �����尡 ������ ������ ��ٸ��ϴ�.

	\~english
	Simple thread wrapper class
	- After creating this instance, a thread will be created by calling Start. And if this instance is destructed then it will be blocked until created thread is terminated.
	- This class has the same operating process as System.Threading.Thread class of .NET framework. 

	General usage
	- Creates a thread object and designates thread function as a parameter. The thread function is designated by constructor.
	- Creating a thread object does not mean immediate thread execution. Start must be run. 
	- Either when calls Join or destructing the thread object, this waits until the running thread ends.

	\~chinese
	??��Wrapper?
	- �����?��������Start?ʦ����?��?������?������������?��?�?�?��Blocking��
	- �?? .net framework�� System.Threading.Thread ?����������?��۰�ҡ�

	��������۰��
	- ����Thread?��?��??���?����?��?����?����������ҡ�
	- ?��������Thread?�����?ء??��?����?��Start��
	- ����Join��Thread?������??��������?������?��?�?򭡣
	\~japanese
	����׫뫹��ë�Wrapper���髹
	- ���Ϋ��󫹫��󫹪���������Start�������󪹪ȫ���ëɪ���������ު��������ƪ��Ϋ��󫹫��󫹪���?��������������ƪ�����ëɪ����������ުǫ֫�ë�����ު���
	-���Ϋ��髹��.net framework��System.Threading.Thread���髹���Ҫ��誦������۰�Ҫ����ު���

	�����ܪ��Ū�۰
	-Thread���֫������Ȫ��������ު������ѫ��?��?�ǫ���ëɪ�??����Ҫ��ު�������ë�??��ϰ������Ҫ��ު���
	-Thread���֫������Ȫ��������ƪ⡢�����˫���ëɪ����Ѫ���缾�ǪϪ���ު���Start��?�����ʪ���Ъʪ�ު���
	-Join�������󪷪���Thread���֫������Ȫ���?�����𷡢?����Ϋ���ëɪ����������ު�����ު���
	\~

	\~korean �������� �����尡 ������ ��ƾ�� �Ʒ�ó�� ���ٽ�(lambda expression)���� ����ŵ� �˴ϴ�.
	\~english You may create a routine that a thread will execute as Lambda Expression below.
	\~chinese ?��?��??����Routine?ʦ������Lambda����?�
	\~japanese ����ëɪ�?�������?����������Ϊ誦�˫�����(lambda expression)���ªêƪ���𹪢��ު���

	\~
	\code
	CriticalSection critSec;
	int totalWorkCount = 0;
	volatile bool stopThread = false;
	ThreadPtr th = ThreadPtr(new Thread([&]()
	{
		// note that thread function is defined exactly here 
		// and even the variables out of the scope are
		// used here, thankfully by lambda capture above.
		while (!stopThread)
		{
			CriticalSectionLock lock(critSec, true);
			do_something();
			totalWorkCount++;
		}
	});
	th->Start();
	do_something_or_wait();
	stopThread = true;
	th->Join();
	print(totalWorkCount);
	\endcode
	*/
	class Thread
	{
		friend class ThreadProcContext;

#if defined(_WIN32)
		//static void __cdecl InternalThreadProc(void* ctx);
		static DWORD __stdcall InternalThreadProc(void* ctx);
#else
		static void* InternalThreadProc(void* ctx);
#endif

#if defined(_WIN32)
		HANDLE m_handle;
#else
		pthread_t m_thread;
#endif
		// Thread ID.
		// win32: same to GetCurrentThreadID() value.
		// unix: same to pthread_t value.
		uint64_t m_ID;

		bool m_neededJoin;
	public:
		static bool m_dllProcessDetached_INTERNAL;

		/** 
		\~korean
		������
		\param threadProc �� �ν��Ͻ��� ��� ���� �������� ���� �Լ�
		\param ctx threadProc�� �Ѱ��� �Ķ����
		\param neededJoin Join �Լ��� ��� ����
		�⺻���� true�Դϴ�. ���� �� �����尡 ���� �����庸�� ���� ������� ����Ǹ�, Join ����� ������� �����÷��� false�� �������ֽø� �˴ϴ�.

		\~english TODO:translate needed.
		Constructer
		\param threadProc The main function of the thread which would be held by this instance. 
		\param ctx The parameter to be sent to threadProc
		\param neededJoin Join Whether to use the Join function
		The default value is true. If this thread is to be guaranteed to end earlier than the main thread and you don��t want to use the Join feature, you can set it as false. 

		\~chinese TODO:translate needed.
		?����?
		\paramthreadProc �instance?����?�������?
		\paramctxthreadProc ??��??
		\paramneededJoin Join��?������?��
		��???true�� ������?����?�����?������?�֣���?������Join����?ʦ���??��?false��

		\~japanese TODO:translate needed.
		�����
		\param threadProc ���Ϋ��󫹫��󫹪��êƪ��뫹��ëɪΫ᫤��??
		\param ctx threadProc���ڪ�Ԥ���ѫ��?��?
		\param neededJoin Join ??������ʦ��
		��������true�Ǫ����⪷�����Ϋ���ëɪ��᫤�󫹫�ëɪ��໪���������몳�Ȫ������ơ�JoinѦ�������Ī��ʪ����false����Ҫ��ƪ���������

		\~
		*/
	private:
		void Init_INTERNAL();
	public:
		// ������ ���(C function with context ptr)
		typedef void(*ThreadProc)(void* ctx);
		PROUD_API Thread(ThreadProc threadProc, void *ctx, bool neededJoin = true);

	public:
		/** 
		\~korean
		�ı���
		- �����尡 �̽������̸� ��� �����ϳ�, �����尡 �̹� �������̸� �����尡 ������ ������ ��ٸ���.

		\~english
		Destructor
		- Immediately returns if thread is not running but waits until the thread terminates if the thread is already running.

		\~chinese
		��?��
		- ����?��?ڱ?��???ء??��Return������?���??��?����?��?�?򭡣

		\~japanese
		��?�
		- ����ëɪ�ڱ?����Ǫ���������˫꫿?�󪷪ު���������ëɪ�?��?����Ǫ���Ы���ëɪ������������ު�����ު���

		\~
		*/
		PROUD_API ~Thread();

		/** 
		\~korean
		�����带 �����Ѵ�.
		- �̹� ������ ���¸� ���ܰ� �߻��Ѵ�.

		\~english
		Creates thread
		- An exeption will ocur if already created.

		\~chinese
		����?�
		- �����?������?��??�����⡣

		\~japanese
		����ëɪ��������ު���
		- ?����������?���Ǫ�������⪬?�檷�ު���

		\~
		*/
		PROUD_API void Start();

		/** 
		\~korean
		�����尡 ������ ������ ��ٸ���.

		\~english
		Waits until the thread terminates

		\~chinese
		����?��?򭡣

		\~japanese
		����ëɪ������������ު�����ު���

		\~
		*/
		PROUD_API void Join();

		/** 
		\~korean
		������ �ڵ�

		\~english
		Thread handle

		\~chinese
		?��Handle��

		\~japanese
		����ëɫϫ�ɫ�

		\~
		*/
#if defined(_WIN32)
		__declspec(property(get = GetHandle)) HANDLE Handle;
#endif
		/** 
		\~korean
		������ �ڵ��� ��´�.

		\~english
		Gets thread handle

		\~chinese
		?��?��Handle��

		\~japanese
		����ëɫϫ�ɫ����ު���

		\~
		*/
#if defined(_WIN32)
		inline HANDLE GetHandle()
		{
			return m_handle;
		}
#else
		inline pthread_t GetHandle()
		{
			return m_thread;
		}
#endif

		/** 
		\~korean
		������ ���̵�

		\~english
		Thread ID 

		\~chinese
		?��?��ID��

		\~japanese
		����ë�ID

		\~
		*/
#if defined(_WIN32)
		__declspec(property(get = GetID)) uint64_t ID;
#endif

		/** 
		\~korean
		������ ���̵� ����ϴ�.
		�� ���� Proud.GetCurrentThreadID()�� ���� ȣȯ�˴ϴ�.

		\~english
		Gets thread ID.
		This value is compatible to Proud.GetCurrentThreadID() value.

		\~chinese
		?��?��ID��
		This value is compatible to Proud.GetCurrentThreadID() value.

		\~japanese
		����ëɪ�ID�����𪷪ު���
		This value is compatible to Proud.GetCurrentThreadID() value.
		\~
		*/
		inline uint64_t GetID()
		{
			return m_ID;
		}

#if defined(_WIN32)
		bool IsAlive() const;
#endif

		/** 
		\~korean
		Static library�μ��� ProudNet�� DLL���� ���Ǵ� ��� 
		DllMain�� Process detach case���� �� �޼��带 �� ȣ���ؾ� �Ѵ�.

		\~english
		When ProudNet is used at DLL as a ststic library, this method must be called at Process detach case of DllMain.

		\~chinese
		��?Static library�DLL������ProudNet����?��
		������DllMain��Process detach case�������۰����

		\~japanese
		Static library�Ȫ��ƪ�ProudNet��DLL���Ū������� 
		DllMain��Process detach case�Ǫ��Ϋ᫽�ëɪ����������󪵪ʪ���Ъʪ�ު���

		\~
		*/
		PROUD_API static void NotifyDllProcessDetached();
	private:
		// ����ڰ� �Է��� �Լ��� ������ (����)
		ThreadProc m_threadProc;
		void* m_ctx;

		//////////////////////////////////////////////////////////////////////////
		// C++11 ���(lambda expression)

	private:
		// ����ڰ� �Է��� �Լ� ��ü(���ٽ�)
		// ����: shared_ptr�� �ٲ��� �� ��. ����ڰ� boost, tr1, stdlibc++ ������ �� shared_ptr�� ���� ������ �޶��� ��� ������.
		// ����: ��ü ����̹Ƿ� SUPPORTS_LAMBDA_EXPRESSION ���� �ȿ� ���� �� ��. ������ ã�� ���� ���׷� �̾�����.
		RefCount<LambdaBase_Param0<void> > m_lambdaProc;
		
#ifdef SUPPORTS_LAMBDA_EXPRESSION
	public:
		/** Constructor. Does not create a thread until Start() is called.
		\param function Your function or lambda expression. 
		\param needJoin True if you want this to wait for thread exit. No wait if set to false. */
		Thread(const std::function<void()> &function, bool needJoin = true)
#ifdef _WIN32
			:m_threadStopped(true, true)
#endif // _WIN32
		{
			m_threadProc = NULL;
			m_ctx = NULL;
			m_lambdaProc = RefCount<LambdaBase_Param0<void>>(new Lambda_Param0<void>(function));
			m_neededJoin = needJoin;
			Init_INTERNAL();
		}
#endif // SUPPORTS_LAMBDA_EXPRESSION

		//////////////////////////////////////////////////////////////////////////

	private:
#if defined(_WIN32)
		// non-win32������ pthread_join�� ���̹Ƿ� ������ ��
		Event m_threadStopped;

	public:
		// true�̸� CoInitialize�� ������ ���۽� ȣ��ȴ�.
		bool m_useComModel;
#endif
	};

	/** Smart pointer of thread object. */
	typedef RefCount<Thread> ThreadPtr;

	/**  @} */
}

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif
