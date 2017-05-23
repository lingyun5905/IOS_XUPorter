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

//#include <string> ����ڿ��� ����Ǵ� ��� ������ STL�� ����� �� �����Ƿ�
#include "BasicTypes.h"
#include "atomic.h"
#include "PNString.h"
#include "pnmutex.h"
#include "ClassBehavior.h"

#if !defined(_WIN32)
    #include <pthread.h>
    #include <time.h>
#endif

#if defined(_MSC_VER) && defined(_WIN32)
#pragma comment(lib,"dbghelp.lib") // Lock_Interval���� MiniDumpWriteDump�� ���� ������.
#endif

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif
	class CriticalSection_BottleneckDetector;
	class CriticalSection_Standard;

	uint32_t GetAppropriateSpinCount();

	/** parameters for critical section initialization.
	*/
	class CriticalSectionSettings
	{
	public:
		/// spin count. will be set to appropriate value by default.
		/// This value will be set to 0 if only one CPU core is being used.
		uint32_t m_spinCount;
#ifdef _WIN32
		/// true if you want to perform faster for Windows 6 or later.
		bool m_fasterForWindows6;
#endif
		/**
		\~korean
		���� �߻��� ���� ������ ������ �̸��� �����մϴ�.
		(ex. L"example_dump_file_name/")
		\~english
		Select the name to save the dump file when bottleneck occurs. 
		(ex. L"example_dump_file_name/")

		\~chinese

		\~japanese
		�ܫëȫ�ͫë���?����������׫ի������������٣������Ҫ��ު���
		(ex. L"example_dump_file_name/")

		\~
		*/
		String m_bottleneckWarningDumpFileName;

		/**
		\~korean
		���� �߻��� ���� ������ ������ ��θ� �����մϴ�.
		(ex. L"C:/")
		\~english
		Set the path to save the dump file when bottleneck occurs. 
		(ex. L"C:/")

		\~chinese

		\~japanese
		�ܫëȫ�ͫë���?����������׫ի������������?�ت����Ҫ��ު���
		(ex. L"C:/")


		\~
		*/
		String m_bottleneckWarningDumpFilePath;

		/**
		\~korean
		��� �߻��Ҷ��� �ִ� �ð����� �����մϴ�.
		�ش簪�� 0 �̿��� ������ ���õǸ� NetServer ���ο��� �ش� �� ��ŭ ���� �߻��� ���� ���� ������ ����ϴ�.
		\~english
		Set the maximum time value when a warning occurs. 
		When the value is set for a value other than 0, it leaves a warning and a dump file when bottleneck occurs equal to the value inside NetServer.  

		\~chinese

		\~japanese
		��ͱ��?�檹���������������������Ҫ��ު���
		��?����0�����������Ҫ����С�NetServer?ݻ����?�������ܫëȫ�ͫë���?��������ͱ�ȫ���׫ի������?���ު���

		\~
		*/
		uint32_t m_bottleneckWarningThresholdMs;

		/** If you this value to true,
		Proud.CriticalSection.GetLastLockedThreadID() is valid. */
		bool m_updateLastLockedThreadID;

		CriticalSectionSettings();
	};


	class CriticalSection_BottleneckDetector;
	// _BottleneckDetectorAwareLock ��ȯ��
	class LockBottleneckDetectorResult
	{
	public:
		LockResult m_lockResult;
		uint64_t m_owningThread; // lock�� ������Ų �������� ID. pthread_t or win32 thread ID��.
	};



	/** \addtogroup util_group
	*  @{
	*/
	/**
	\~korean
	Critical section Ŭ����
	- MFC�� CCriticalSection���� ����� �� �����Ǿ� �ִ�.
	- Ư�� (SMP ȯ�濡��) thread sleep state�� �ִ��� ���̱� ���� �⺻������ spin lock�� �����Ǿ� �ִ�.
	�Ϲ��� �뵵
	- CriticalSection ��ü�� ���� ���� ��, CriticalSectionLock ��ü�� ���� critical section lock & unlock�� �� �� �ִ�.

	\~english
	Critical section (class)
	- More fortified features than CCriticalSection of MFC environment
	- A spin lock is set as default in order to minimize thread sleep state under SMP environment.
	General usage
	- It is possible to perform critical section lock/unlock through CriticalSectionLock object after creating it.

	\~chinese
	Critical section?
	- ��MFC�� CCriticalSection%����ʥ˭����
	- ��?����SMP?������?����thread sleep state��������?ᴣ�����Դ?����spin lock��
	������Բ
	���CriticalSection?��?��������?CriticalSectionLock?��ʦ�critical section lock & unlock��

	\~japanese
	Critical section ���髹
	- MFC��CCriticalSection���Ѧ������ê���?����ƪ��ު���
	- ���(SMP���Ѫ�)��thread sleep state�������ڪ����骹����������ܪ�spin lock�����Ҫ���ƪ��ު���
	�����ܪ���Բ
	- CriticalSection ���֫������Ȫ�໪��ªê�����CriticalSectionLock ���֫������Ȫ��ת�critical section lock & unlock���������Ȫ��Ǫ��ު���

	\~
	 */
	class CriticalSection
	{
        //String m_name;
		uint32_t m_validKey;

		CriticalSectionSettings m_settings;

		CriticalSection_Standard* m_standard;

		// 0: ���� �� ����� ��, 1: ���� ����� �ִ� ��
		CriticalSection_BottleneckDetector* m_bottleneckDetector;
	public:
		/** Initializes a critical section object. */
        PROUD_API CriticalSection();

		/** Initializes a critical section object. */
		PROUD_API CriticalSection(CriticalSectionSettings &settings);

	private:
		void _Initialize(CriticalSectionSettings &settings);
		void _Uninitialize();

		void _BottleneckDetectorAwareLock(int32_t timeout, LockBottleneckDetectorResult& result);

		void Lock_internal();
		inline bool IsBottleneckWarningEnabled()
		{
			return (bool)(m_settings.m_bottleneckWarningThresholdMs > 0);
		}

		bool IsOwningThreadAlive() const;

	public:
		/**
		\~korean
		�ı���
		- �ı��ϱ� ����, �� critical section�� �����ϰ� �ִ� �����尡 ����� �Ѵ�!
		\~english
		Destroyer
		- There must be no thread occupying the critical section before the desruction.
		\~chinese
		��?�
		- ��?��������������critical section��?�
		\~japanese
		��?�
		- ��?������ˡ�����critical section����󪷪ƪ��뫹��ëɪ����êƪϪ����ު���!
		\~
		  */
		PROUD_API ~CriticalSection(void);

		/**
		\~korean
		critical section�� �� �޼��带 ȣ���ϴ� �����尡 �����Ѵ�.
		�߸��� ȣ���� �Ͼ�� �� MessageBox�� ����ݴϴ�.
		\~english
		The critical section is to be occupied by the thread calling this method.
		\~chinese
		��У�۰����?�����critical section��
		?��??��У?��?MessageBox��
		\~japanese
		\~
		 */
		PROUD_API void Lock();

		/**
		\~korean
		critical section�� �� �޼��带 ȣ���ϴ� �����尡 �����Ѵ�.
		�߸��� ȣ���� �Ͼ�� �� �ƹ� ó������ �ʰ� �Ѿ�ϴ�.
		\~english TODO:translate needed.
		The critical section is to be occupied by the thread calling this method.
		\~chinese
		��У�۰����?�����critical section��
		?��??����?�������?�⡣
		\~japanese
		critical section�򪳪Ϋ᫽�ëɪ������󪹫���ëɪ���󪷪ު���
		���ުê������󪷪�?�檷������MessageBox�����ƪ��ު���
		\~
		 */
		PROUD_API void UnsafeLock();

		/**
		\~korean
		critical section�� �� �޼��带 ȣ���ϴ� �����尡 ���� �����Ѵ�.
		\~english
		The critical section is to be relieved by the thread calling this method.
		\~chinese
		��У�۰����?��������critical section��
		\~japanese
		critical section�򪳪Ϋ᫽�ëɪ������󪹫���ëɪ������𶪷�ު���
		\~
		 */
		PROUD_API void Unlock();

		/**
		\~korean
		EnterCriticalSection ��� TryEnterCriticalSection�� ����Ѵ�.
		\return ���������� ��� ������ true.
		\~english
		Use TryEnterCriticalSection rather than EnterCriticalSection.
		\return If it locked successfully, it is true.
		\~chinese
		TryEnterCriticalSection����EnterCriticalSection���ġ�
		\return ?��������?true��
		\~japanese
		EnterCriticalSection���۪���TryEnterCriticalSection�����Ī��ު���
		\return ��ë�����������true��
		\~
		 */
		PROUD_API bool TryLock();
		PROUD_API bool IsValid();

#ifndef _WIN32
		/** Returns pthread_mutex_t object. */
		pthread_mutex_t* GetMutexObject() const;
#endif

#ifdef PN_LOCK_OWNER_SHOWN
		/** Returns true if this is locked by current thread. */
		bool IsLockedByCurrentThread() const;

		/** Returns true if this is locked by any thread. */
		bool IsLocked() const;
#endif

		// �� ���� true�̸� �ı��ڿ��� ���� ��ü�� �ı� ����.
		// �� �� �ٷ�Ⱑ �ʿ��� ���: �� Ÿ���� ���� ��ü�̰�, ���μ��� �����, ��ü �ı� ������ �����ϰ� �ٷ���� �� ��, ������ �����ϴ���.
		bool m_neverCallDtor;

		// Critical Section �� Setting ���� �ٲٰ� ������
		void Reset(CriticalSectionSettings& settings);

		void ShowErrorOnInvalidState();

		//////////////////////////////////////////////////////////////////////////
		// lock�� �� �� context switch�� �߻��ߴ����� �� �� �ִ�.
		// ���� ��: object pool�� ���� ���� ���Ǵ� ��� ���� 700:1 ������ contention�� ����Ų��.

		// try-lock ���� ȸ��
		int m_tryLockSuccessCount;

		// try-lock ���� Ƚ��. �� �Ϲ� lock Ƚ��.
		int m_tryLockFailCount;

		NO_COPYABLE(CriticalSection)


	public:
		/** returns ID of the thread where the last acquire (lock) is done.

		This value does not set to zero if last unacquire (unlock) is done.
		You must set Proud.CriticalSectionSettings.m_updateLastLockedThreadID to true before using this function.

		NOTE: on unix, this is pthread_t value. This may differ from thread ID shown in debugger.
		*/
		uint64_t GetLastLockedThreadID();

	private:
		uint64_t m_lastLockedThreadID;
	};

	//typedef RefCount<CriticalSection,false> CriticalSectionPtr;

	/**
	\~korean
	\brief CriticalSection ��ü�� lock access�ϴ� ��ü�Դϴ�.
	- �Ϲ������� ���� �����μ� ���˴ϴ�. 
	- �� ��ü�� �ı��� �� �ڵ����� lock�ϰ� �ִ� critical section�� unlock�մϴ�.
	\~english
	 \brief The object that 'lock accesses' CriticalSection object.
	- Usually created and used as a local variable.
	- When this object is destroyed, it automatically unlocks the critical section that was locked by this.
	\~chinese
	\brief CriticalSection ��?��lock access��?�ڡ�
	- ���������??�����ġ�
	- �?������?��?���?unlock��lock��critical section��
	\~japanese
	\brief CriticalSection ���֫������Ȫ�lock access���뫪�֫�������
	- ������?����??������������ĪΫ���ë�?�ǪΪ��Ū��ު���
	- ���Ϋ��֫������Ȫ���?�����������ѫ�ë����ƪ���critical section��unlock���ު���
	\~

	\code
	// Example
	void foo()
	{
		CriticalSectionLock lock(critSec, true);
		... 
		
		// automatically unlocked here.
	}
	\endcode
	*/
	class CriticalSectionLock
	{
		CriticalSection* m_cs;

		// �� ���� Lock�� ȣ���ߴ°�?
		// ����: m_cs�� ���� lock Ƚ���� �ٸ� �� �ִ�.
		// �� ���� �� CriticalSectionLock�� ���ؼ� Lock�� �͵鸸 ī�����Ѵ�.
		int m_recursionCount;

	public:
		/**
		\~korean
		critical section ��ü�� �����ڿ��� �ٷ� lock�� �� �ִ�.
		\param cs ����� critical section ��ü
		\param initialLock true�̸� �����ڿ��� �ٷ� lock�Ѵ�.
		\~english
		It is possible to directly lock the critical section object at constructor.
		\param cs The critical section object to use
		\param initialLock If it is true then the constructor immediately locks it.
		\~chinese
		������ʦ�ء?lock critical section?�ڡ�
		\param cs �������critical section?��
		\param initialLock true��?������ء?lock��
		\~japanese
		critical section ���֫������Ȫ������Ǫ�����ë��Ǫ��ު���
		\param cs ���Ī��� critical section ���֫�������
		\param initialLock true�Ǫ���������Ǫ�����ë����ު���
		\~
		 */
		inline CriticalSectionLock(CriticalSection& cs, bool initialLock)
		{
			SetCriticalSection(cs, initialLock);
		}

		/**
		\~korean
		critical section�� ���߿� �����Ҷ��� ����� �������Դϴ�.
		\~english
		This is constructor that using set critical section later.
		\~chinese
		���?��critical section��?���������������
		\~japanese
		critical section���������Ҫ��������Ū������Ǫ���
		\~
		*/
		inline CriticalSectionLock()
		{
			m_cs = NULL;
			m_recursionCount = 0;
		}
		inline void SetCriticalSection(CriticalSection &cs,bool initialLock)
		{
			m_cs = &cs;
			m_recursionCount = 0;
			if (initialLock)
			{
				Lock();
			}
		}
		// ���� ���� ���� ��������, ���� �����尡 �� critsec�� ��װ� �ִ� �������� �˻縦 �ؾ� �� ���� �־
		// �� �Լ��� ������.
		inline CriticalSection* GetCriticalSection() const
		{
			return m_cs;
		}

		/**
		\~korean
		����� �Ǿ��ֳ�?
		\~english
		Is it locked?
		\~chinese
		?����?��
		\~japanese
		��ë�����ƪ��ު�����
		\~
		 */
		bool IsLocked() const
		{
			assert(m_recursionCount >= 0);
			return m_recursionCount > 0;
		}

		/**
		\~korean
		�ı���
		- �̹� �� ��ü�� �����ϰ� �ִ� CriticalSection�� ���� ��� ���� ������ �ڵ����� �Ѵ�.
		\~english
		Destructor
		- If there is a Critical Section occupied by this object then it automatically relieves.
		\~chinese
		��?�
		- �?���?���CriticalSection��?���?��𶡣
		\~japanese
		��?�
		- ?�˪��Ϋ��֫������Ȫ���󪷪ƪ���CriticalSection���������ꡢ���������Ѫ������ު���
		\~
		 */
		inline ~CriticalSectionLock()
		{
			assert(m_recursionCount >= 0);
			for ( ; m_recursionCount > 0; --m_recursionCount )
			{
				m_cs->Unlock();
			}
		}

		/**
		\~korean
		critical section�� �����Ѵ�.
		\~english
		This occupies the critical section.
		\~chinese
		���critical section��
		\~japanese
		critical section����󪷪ު���
		\~
		 */
		inline void Lock()
		{
			m_cs->Lock();
			++m_recursionCount;
		}

		/**
		\~korean
		Try Lock�� �����Ѵ�.
		\return CriticalSection.TryLock()�� ���� ��
		\~english
		Perform Try Lock.
		\return Same value as CriticalSection.TryLock()
		\~chinese
		?��Try Lock��
		\return ?CriticalSection.TryLock()��?��?��
		\~japanese
		Try Lock���������ު���
		\return CriticalSection.TryLock()���Ҫ���
		\~
		 */
		inline bool TryLock()
		{
			bool r = m_cs->TryLock();
			if ( r )
			{
				++m_recursionCount;
			}
			return r;
		}

		// ������ �뵵�θ�
		inline void UnsafeLock()
		{
			m_cs->UnsafeLock();
			++m_recursionCount;
		}

		/**
		\~korean
		critical section�� ���� �����Ѵ�.
		\~english
		This relieves occupied critical section.
		\~chinese
		������critical section��
		\~japanese
		critical section�������𶪷�ު���
		\~
		 */
		inline void Unlock()
		{
			if ( IsLocked() )
			{
				--m_recursionCount;
				m_cs->Unlock();
			}
		}

		/**
		\~korean
		���� ��ø�� Ƚ���� ��ȸ�Ѵ�.

		\~english
		Inquire the time that the lock is over

		\~chinese

		\~japanese
		��ë�����ʪê���?����?���ު���
		\~
		*/
		inline int GetRecursionCount()
		{
			assert(m_recursionCount >= 0);
			return m_recursionCount;
		}

		NO_COPYABLE(CriticalSectionLock)
	};

	/**  @} */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
};

#ifdef _MSC_VER
#pragma pack(pop)
#endif
