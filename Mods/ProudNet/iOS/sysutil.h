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
#include "PNString.h"
#include "Singleton.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif

#ifdef _WIN32
#pragma comment(lib, "Shlwapi.lib") // PathCombine() ���� ���Ƿ�.
#endif

namespace Proud
{
	const int MaxCpuCoreCount = 4096; // 2050���� �Ѿ�� �� ���� ���ľ� ������ �𸥴�.
	   
	/** \addtogroup util_group
	*  @{
	*/

	/**
	\~korean
	Microsecond Sleep Function.

	\~englich TODO:suspend execution for microsecond intervals.

	\~chinese
	?��?��?����??��

	\~japanese
	\~
	*/
	PROUD_API void USleep(long uSec);

	/**
	\~korean
	CPU������ ���Ѵ�.

	\~englich 
	Get the number of CPUs. 

	\~chinese
	ϴCPU??��

	\~japanese
	CPU?��ϴ��ު���
	\~
	*/
	PROUD_API uint32_t GetNoofProcessors();

	/**
	\~korean
	���μ����� �̸��� ���´�.

	\~english 
	Get the name of the process. 

	\~chinese
	?��?�٣��

	\~japanese
	�׫뫻��٣������?�ߪު���
	\~
	*/
	PROUD_API String GetProcessName();

	/** Returns current thread ID.
	- win32 kinds: same to ::GetCurrentThreadId().
	- unix kinds: same to pthread_self(). */
	uint64_t GetCurrentThreadID();

	/**
	 \~korean
	 ProudNet ����ڰ� �Ǽ��� ��쿡�� �����ִ� ������.
	 - CNetConfig::UserMisuseErrorReaction �� type�� ���� MessageBoxȤ�� ����׺�� Ȯ�� �� �� �ִ� ������ ������ش�.
	 \param text Error Comment

	 \~english 
	This is an error shown only when a ProudNet user makes a mistake. 
	- Depending on the type of CNetConfig::UserMisuseErrorReaction, it outputs the error that can be confirmed with either MessageBox or debugview. 
	\param text Error Comment


	 \~chinese
	 ProudNet��?��?��?��?����??��
	 - ���� CNetConfig::UserMisuseErrorReaction%��type��������MessageBox���??viewʦ�??��??��
	 \param text Error Comment

	 \~japanese
	ProudNet��?��?�����ުê�����Ϊ����ƪ��뫨��?�Ǫ���
	- CNetConfig::UserMisuseErrorReaction��type�˪�ê�MessageBox�ު��ϫǫЫë��ӫ�?������Ǫ��뫨��?���������ު���
	\param text Error Comment

	 \~
	 */
	PROUD_API void ShowUserMisuseError(const PNTCHAR* text);


	/**
	\~korean
	debug output or console�� ������ ������ ����մϴ�. newline�� �߰����� �ʽ��ϴ�.

	\~english
	Prints text for debugging to debugger output window or console, without newline.

	\~chinese
	�debug output or console��?��??��?ϣ����?��ʥnewline��

	\~japanese
	debug output or console�˫ǫЫë�������ϣ���������ު���Newline����ʥ����ު���
	\~
	*/
	void TraceA(const char * format, ...);


#ifdef _WIN32
	/**
	\~korean
	������ �޸� �������� ���Ѵ�.

	\~english 
	Calculate the physical memory occupancy rate

	\~chinese
	ϴڪ��?������㡣

	\~japanese
	ڪ���ܫ���?������ϴ��ު���
	\~
	*/
	PROUD_API size_t GetOccupiedPhysicalMemory();

	/**
	\~korean
	�� �޸𸮸� ���Ѵ�.

	\~english 
	Calculate the total memory

	\~chinese
	ϴ??��

	\~japanese
	?����?��ϴ��ު���
	\~
	*/
	PROUD_API size_t GetTotalPhysicalMemory();

	/**
	\~korean
	��ǻ�� �̸��� ���Ѵ�.

	\~english 
	Get the computer name. 

	\~chinese
	ϴ??٣?��

	\~japanese
	����ԫ�?��?٣��ϴ��ު���
	\~
	*/
	PROUD_API String GetComputerName();

	/**
	\~korean
	Windows XP, 2003������ �����ϴ� ������� low-fragmentation heap�� ����.
	- �̰� ���� SMP ȯ�濡�� heap ���� �ӵ��� ���� ���ȴ�. ���� low-fragmentation�� ���͵� ��´�.
	���� �����ϸ� �̰��� ���� ���� ���� ����ȴ�.
	- �� �޼���� Windows 98 ����� �������� �ʴµ�, �̷� ��� �� �޼���� �ƹ� �͵� ���� �ʴ´�.
	������ Windows 98���� �ʿ� Win32 API�� �� ã�� ������ �߻������� �ʴ´�.

	\~english 
	As the feature supported only in Window XP and 2003, it uses low-fragmentation heap. 
	- When you use this, the heap access speed increases dramatically in SMP environment. Of course, you also get the benefits of low-fragmentation. 
	Therefore, we strongly recommend you to use this if possible. 
	- This method is not supported in Windows 98, etc. and in this case, this method does not do anything. 
	However, errors do not occur when an essential Win32 API is not searched in Window 98. 

	\~chinese
	�����Windows XP, 2003��������������low-fragmentation heap��
	- ����??��?�SMP?��������heap����?��������ԡ�?���?����low-fragmentation ���̡���ʦ���?˭����?����??��
	- �۰���Windows 98���򥣬??���۰����?��������ס�ӣ����?��Windows 98?��?�����Win32 API�?��??��

	\~japanese
	Windows XP, 2003�ǪΪ߫���?�Ȫ���Ѧ����low-fragmentation heap���Ū��ު���
	- ������Ū���SMP���Ѫ�heap�Ϋ�������������������߾����ު���ڨ�塢low-fragmentation�����̪���ު���
	��êơ��Ǫ���Ъ�����Ū����Ȫ�?����?�᪷�ު���
	- ���Ϋ᫽�ëɪ�Windows 98�ʪɪǪϫ���?�Ȫ��ު��󪬡����Ϊ誦�����ꡢ���Ϋ᫽�ëɪ����⪷�ު���
	��������Windows 98����驪�Wind 32 API��̸�Ī��骺����?��?�檹�몳�ȪϪ���ު���
	\~
	*/
	PROUD_API bool EnableLowFragmentationHeap();

	String GetCurrentProgramDirectory();

	/**
	\~korean
	�� ���α׷��� ����ǰ� �ִ� ������ ã�Ƽ� current directory�� �����Ѵ�.
	- �̷��� �ϴ� ��� �ٸ� ���丮���� �� ���α׷��� ������ѵ� media file�� ����� ã�´�.

	\~english 
	Look for the folder where this program is being run and set as the current directory. 
	- In this case, the media file is searched properly even this program is run in other directories. 

	\~chinese
	?����������?����������?��?current directory��
	- ??��?�������directory?��������?��??��media file��

	\~japanese
	���Ϋ׫���બ?������ƪ���ի����?��̸�Ī���current directory�����Ҫ��ު���
	- ���Ϊ誦�˪������ꡢ��Ϋǫ��쫯�ȫ�?�Ǫ��Ϋ׫�����?�������ƪ�media file���᪷��̸�Ī��ު���
	\~
	*/
	PROUD_API void SetCurrentDirectoryWhereProgramExists();

	/**
	\~korean
	���� Process�� Service Mode�� ���������� ���θ� �˻��մϴ�.
	\return ���񽺸��� 1 �ƴϸ� 0

	\~english 
	Check whether the current process is being executed in service mode. 
	\return  1 if service mode, otherwise 0. 

	\~chinese
	???���Process�����Service Mode?����
	\return ����?ټ����?��1������?0��

	\~japanese
	���Process��Service Mode��?����ʪΪ��ɪ�����?�۪��ު���
	\return ��?�ӫ���?�ɪǪ����1������Ȫ�0
	\~
	*/
	PROUD_API bool IsServiceMode();

	/**
	\~korean
	GetQueuedCompletionStatusEx ��� ���� ���θ� �˻��Ѵ�. Server2008�̻� ����Ҽ� �ִٰ� �˷��� �ִ�.
	\return ��밡���ϸ� 1 �ƴϸ� 0

	\~english 
	Check whether it can be used. It is known that it can only be used in Server2008 or higher. 
	\return 1 if usable, otherwise 0. 

	\~chinese
	??GetQueuedCompletionStatusEx����ʦ����ġ���?���Server2008�߾ʦ����ġ�
	\return ʦ�������?1��������?0��

	\~japanese
	GetQueuedCompletionStatusEx ����ʦ��ʦ����?�۪��ު���Server2008�߾�Ϊ��Ū����Ȫ��Ǫ�������ƪ��ު���
	\return ����ʦ���Ǫ����1������Ȫ�0
	\~
	*/
	PROUD_API bool IsGqcsExSupported();

	/**
	\~korean
	HyperThreading�� �����ϴ����� �˻��Ѵ�.

	\~english 
	Check whether it supports HyperThreading. 

	\~chinese
	??������HyperThreading��

	\~japanese
	HyperThreading�򫵫�?�Ȫ��몫�ɪ�����?�۪��ު���
	\~
	*/
	PROUD_API bool IsHyperThreading();

	/**
	\~korean
	��Ʈ�� 1�� ���� üũ�մϴ�.
	\param bitMask ��Ʈ�� �˻��� ����
	\return ��Ʈ�� 1�� ��

	\~english 
	Check the number with the bit as 1. 
	\param bitMask Parameter to check the bit. 
	\return Number with the bit as 1. 


	\~chinese
	����bit?1��?��
	\param bitmask ??bit��??��
	\return bit?1��?��

	\~japanese
	�ӫëȪ�1�Ǫ���?������ë����ު���
	\param bitMask �ӫëȪ�?�۪���??
	\return �ӫëȪ�1�Ǫ���?
	\~
	*/
	PROUD_API uint32_t CountSetBits(uintptr_t bitMask);

	typedef WINBASEAPI
		/*__out_opt*/
		HANDLE
		(WINAPI* CreateIoCompletionPortProc)(
		/*__in*/     HANDLE FileHandle,
		/*__in_opt*/ HANDLE ExistingCompletionPort,
		/*__in*/     ULONG_PTR CompletionKey,
		/*__in*/     uint32_t NumberOfConcurrentThreads
		);

	typedef WINBASEAPI
		BOOL
		(WINAPI* HeapSetInformationProc) (
		/*__in_opt*/ HANDLE HeapHandle,
		/*__in*/ HEAP_INFORMATION_CLASS HeapInformationClass,
		/*__in_bcount_opt HeapInformationLength*/ PVOID HeapInformation,
		/*__in*/ size_t HeapInformationLength
		);

	typedef WINBASEAPI
		BOOL
		(WINAPI* QueueUserWorkItemProc) (
		/*__in*/     LPTHREAD_START_ROUTINE Function,
		/*__in_opt*/ PVOID Context,
		/*__in*/     uint32_t Flags
		);

	typedef WINBASEAPI
		BOOL
		(WINAPI* GetQueuedCompletionStatusProc) (
		/*__in*/  HANDLE CompletionPort,
		/*__out*/ LPDWORD lpNumberOfBytesTransferred,
		/*__out*/ PULONG_PTR lpCompletionKey,
		/*__out*/ LPOVERLAPPED *lpOverlapped,
		/*__in*/  uint32_t dwMilliseconds
		);

	// win32 api���� �����ؿ� ����
	struct PN_OVERLAPPED_ENTRY {
		ULONG_PTR lpCompletionKey;
		LPOVERLAPPED lpOverlapped;
		ULONG_PTR Internal;
		DWORD dwNumberOfBytesTransferred;
	};

	typedef WINBASEAPI
		BOOL
		(WINAPI* GetQueuedCompletionStatusExProc) (
		/*__in  */HANDLE CompletionPort,
		/*__out_ecount_part(ulCount, *ulNumEntriesRemoved)*/ PN_OVERLAPPED_ENTRY* lpCompletionPortEntries,
		/*__in  */uint32_t ulCount,
		/*__out */PULONG ulNumEntriesRemoved,
		/*__in  */uint32_t dwMilliseconds,
		/*__in  */BOOL fAlertable
		);

	typedef WINBASEAPI
		PVOID
		(WINAPI* AddVectoredExceptionHandlerProc) (
		/*__in*/          uint32_t FirstHandler,
		/*__in*/          PVECTORED_EXCEPTION_HANDLER VectoredHandler
		);

	typedef WINBASEAPI
		BOOL
		(WINAPI* GetLogicalProcessorInformation)(
		/*__out */	PSYSTEM_LOGICAL_PROCESSOR_INFORMATION Buffer,
		/*))inout */ PDWORD ReturnLength
		);

	/**
	\~korean
	������ ���� ��� �̸��� ���Ѵ�. �̹� ���� ��� �̸��̸� �״�� �����Ѵ�.

	\~english 
	Get the absolute pathname of the file. If it is already the absolute pathname, return as it is. 

	\~chinese
	ϴ������??��?٣?���?��??��?٣?��?�?���ޡ�

	\~japanese
	�ի�������??��٣��ϴ��ު���?���??��٣�Ǫ���Ъ��Ϊުޫ꫿?�󪷪ު���
	\~
	*/
	PROUD_API String GetFullPath(const PNTCHAR* fileName);

	/**
	\~korean
	���丮�� �����ϰ� Ǯ�н��� ���Ѵ�.

	\~english 
	Generate a directory and get the full path. 

	\~chinese
	����directory��ϴfullpath��

	\~japanese
	�ǫ��쫯�ȫ�?���������ƫի�ѫ���ϴ��ު���
	\~
	*/
	PROUD_API bool CreateFullDirectory(const PNTCHAR* lpPathName, String& outCreatedDirectory);

	/**
	\~korean
	���� ���丮�� ���Ѵ�.

	\~english 
	Get the current directory. 

	\~chinese
	ϴ?�directory��

	\~japanese
	��ǫ��쫯�ȫ�?��ϴ��ު���
	\~
	*/
	PROUD_API String GetCurrentDirectory();

	/**
	\~korean
	Ÿ�̸� ���� �ݹ� �Լ�
	- Ÿ�̸� �ݹ� �Ǵ� ��ϵ� ��� �ݹ��� ���� ���� �ּҸ� �����ϴ� ���ø����̼� ���� �Լ� �̴�.
	�� �ּҴ� CreateTimerQueueTimer�� RegisterWaitForSingleObject �Լ��� ���� �Ѵ�.

	WaitOrTimerCallbackProc Ÿ���� �ݹ� �Լ����� �����͸� �����Ѵ�. WaitOrTimerCallbackProc�� ���ø����̼� ���� �Լ� �̸��� ���� �÷��̽�Ȧ�� �̴�.

	\param [in] lpParameter ������ �����ʹ� CreateTimerQueueTimer �� RegisterWaitForSingleObject �Լ��� �Ķ���͸� ����ϴ� �Լ��� ��������.
	\param TimerOrWaitFired ���� �� �Ķ���Ͱ� TRUE ��� ���ð��� ������. ���� �� �Ķ���Ͱ� FALSE ��� ��� �̺�Ʈ�� ��ȣ�� �߻���Ų��. (�� �Ķ���ʹ� Ÿ�̸� �ݹ��� ���� �׻� TRUE �̴�.)

	\~english
	Timer user callback function
	- An application-defined function that serves as the starting address for a timer callback or a registered wait callback.
	Specify this address when calling the CreateTimerQueueTimer, RegisterWaitForSingleObject function.

	The WaitOrTimerCallbackProc type defines a pointer to this callback function. WaitOrTimerCallback is a placeholder for the application-defined function name.

	\param [in] lpParameter The thread data passed to the function using a parameter of the CreateTimerQueueTimer or RegisterWaitForSingleObject function.
	\param TimerOrWaitFired If this parameter is TRUE, the wait timed out. If this parameter is FALSE, the wait event has been signaled. (This parameter is always TRUE for timer callbacks.)

	\~chinese
	Timer ��?��?��?
	- ?��timer��?���������?��������?��?�����?����?��?��
	������CreateTimerQueueTimer��RegisterWaitForSingleObject��?��ҡ�

	WaitOrTimerCallbackProc ?����?���?��?���?�� WaitOrTimerCallbackProc ��?��?����?��?٣?�����ݬ��

	\param [in] lpParameter ?��?��?������CreateTimerQueueTimer��RegisterWaitForSingleObject��???����?��
	\param TimerOrWaitFired �����??��TRUE��?����?����?�֡������??��FALSE��?������event??����?�����???��timer��?������TRUE����

	\~japanese
	������?��?��?��?��Ыë�??
	- ������?��?��Ыë��ު�����?���쪿��Ѧ��?��Ыë��Ϊ������㷫��ɫ쫹����ꪹ�뫢�׫꫱?���������??�Ǫ���
	���Ϋ��ɫ쫹��CreateTimerQueueTimer��RegisterWaitForSingleObject��??����Ҫ��ު���
	WaitOrTimerCallbackProc�����תϫ�?��Ыë�??�تΫݫ���?���������ު���WaitOrTimerCallbackProc�ϫ��׫꫱?���������??٣�Ϊ���Ϋ׫쫤���۫��?�Ǫ���
	\param [in] lpParameter ����ëɫ�?���ϡ�CreateTimerQueueTimer���RegisterWaitForSingleObject??�Ϋѫ��?��?���Ū�??������ު���
	\param TimerOrWaitFired �⪷�����Ϋѫ��?��?��TRUE�Ǫ������Ѧ������?�������ު����⪷�����Ϋѫ��?��?��FALSE�Ǫ������Ѧ���٫�Ȫ���?��?�檷�ު���(���Ϋѫ��?��?�ϫ�����?��?��Ыë��Ϊ���˪��Ī�TRUE�Ǫ���)

	\~
	*/
	typedef VOID (NTAPI * WaitOrTimerCallbackProc) (PVOID lpParameter , BOOLEAN TimerOrWaitFired );

	typedef WINBASEAPI
		HANDLE
		(WINAPI* CreateTimerQueueProc) (
		VOID
		);

	typedef WINBASEAPI
		BOOL
		(WINAPI* CreateTimerQueueTimerProc ) (
		/*__deref_out*/ PHANDLE phNewTimer,
		/*__in_opt   */ HANDLE TimerQueue,
		/*__in       */ WaitOrTimerCallbackProc Callback,
		/*__in_opt   */ PVOID Parameter,
		/*__in       */ uint32_t DueTime,
		/*__in       */ uint32_t Period,
		/*__in       */ uint32_t Flags
		) ;


	typedef WINBASEAPI
		BOOL
		(WINAPI* DeleteTimerQueueTimerProc) (
		/*__in_opt*/ HANDLE TimerQueue,
		/*__in    */ HANDLE Timer,
		/*__in_opt*/ HANDLE CompletionEvent
		);

	typedef WINBASEAPI
		BOOL
		(WINAPI* DeleteTimerQueueExProc) (
		/*__in    */ HANDLE TimerQueue,
		/*__in_opt*/ HANDLE CompletionEvent
		);

	typedef WINBASEAPI
		BOOL
		(WINAPI* InitializeCriticalSectionExProc) (
		/*__out*/ LPCRITICAL_SECTION lpCriticalSection,
		/*__in*/  uint32_t dwSpinCount,
		/*__in  */uint32_t Flags
		);

#if defined(_WIN32)
	bool GetWindowsVersion(DWORD& major, DWORD& minor, DWORD& servicePack);
#endif

	/**
	\~korean
	Windows NT ���� API�� �������� ������ Ŭ����
	- Windows 98������ ��� ȣ���� �������� �ƿ� �ش� API�� ��� exe ���� ������ ���ϴ� ������ �ذ��� �ʿ䰡
	������ �� Ŭ������ �����ϴ�.
	- ��ҿ��� �� �ʿ䰡 ����. �ٸ�, Windows 98������ �۵��ؾ� �ϴ� ����� ����ٸ� �����ϴ�.

	\~english
	Class that gets Windows NT custom API as dynamic
	- Though it cannot be called by Windows 98 but this can be very useful sovling troubles that even exe cannot be run.
	- Does not need to be used normally. But useful when creating a module that is to run on Windows 98.

	\~chinese
	��Windows NT?��API�???����?��
	- ?���Windows 98������У��ӣ�����?��?��??��API���������?��exe��???���??��������
	- ��??��������ġ�ӣ������Windows 98���??��ټ???���ġ�

	\~japanese
	Windows NT?�Ī�API������ʫ߫ë������?�뫯�髹
	- Windows 98�Ǫϡ����Ȫ������󪷪ϪǪ��ު��󪬡�?����?API���ʪ���exe?�������Ǫ��ʪ�������̽������驪��������˪��Ϋ��髹�����ĪǪ���
	- ���Ȫ˪��Ū���驪�����ު���ӣ����Windows 98�Ǫ����Ѫ��ʪ���Ъʪ�ʪ��⫸��?����ª�ʪ����ĪǪ���
	
	\~
	*/
	class CKernel32Api/*:protected CSingleton<CKernel32Api> �̱��� ��. ������ �ı��� ���� �����Ƿ�. �Դٰ� CSingleton�� �̷� ������Ʈ�� ���� ������ �� �����Ƿ�. */
	{
		//modify by rekfkno1 - �̷��� ��������� �δ°��� ������ ȣ���� �ʴ°�찡 �ִ���.
		//�׷��� static �Լ����� static ���ú����� �̱����� �ϴ°��� ���� ���ϴ�.
		//static CKernel32Api g_instance;
	public:
		CKernel32Api();

		PROUD_API static CKernel32Api& Instance();

		// �Լ� ������ ��� ������
		HeapSetInformationProc HeapSetInformation;
		GetQueuedCompletionStatusExProc GetQueuedCompletionStatusEx;  // windows 2008 server ���ĺ��� ���� ���

		InitializeCriticalSectionExProc InitializeCriticalSectionEx;
		GetLogicalProcessorInformation GetLogicalProcessInformation;

		HINSTANCE m_dllHandle;               // Handle to DLL
	};

	class CLocale:protected CSingleton<CLocale>
	{
	public:
		int m_languageID;

		CLocale();

		PROUD_API static CLocale& GetUnsafeRef();
	};

	class CSystemInfo:protected CSingleton<CSystemInfo>
	{
	public:
		SYSTEM_INFO m_info;

		CSystemInfo();
		inline uint32_t GetMemoryPageSize() { return m_info.dwPageSize; }

		PROUD_API static CSystemInfo& GetUnsafeRef();
	};

	/**
	\~korean
	���� ���μ������� ���ǰ� �ִ� �� �������� ���� ���´�.

	\~english
	Gain the number of whole threads which is used in process now.

	\~chinese
	?��?���������??��?��

	\~japanese
	��׫������Ū��ƪ���?����ëɪ�?����ު���
	\~
	*/
	PROUD_API int GetTotalThreadCount();

	/**
	\~korean
	���� �������� ���¸� ���´�.

	\~english
	Gain the condition of that thead currently.

	\~chinese
	Gain the condition of that thead currently.

	\~japanese
	�����ëɪ�?������ު���
	\~
	*/
	PROUD_API DWORD GetThreadStatus(HANDLE const handle);

#endif //#ifdef _WIN32

	/**  @} */

#ifdef _MSC_VER
	#if !defined(_NO_NTTNTRACE) && (defined(_DEBUG)||defined(IW_DEBUG))
		#define NTTNTRACE Proud::TraceA
	#else
		#define NTTNTRACE __noop // �� VC++������ �̰��� ��� ���ϹǷ� �Ʒ� ���� ����
	#endif
#else
	#if !defined(_NO_NTTNTRACE) && (defined(_DEBUG)||defined(IW_DEBUG))
		#define NTTNTRACE(...) Proud::TraceA(__VA_ARGS__)
	#else
		#define NTTNTRACE(...) //VC++������ C4390 ��� ����. �׷��� ���� ���� ����.
	#endif
#endif

	// _MAX_PATH�� 260�ۿ� �ȵȴ�. ���� ���뿡�� �̰��� �ʹ� �۴�. �̰��� ����.
	const int LongMaxPath = 4000;

	// non-win32�� ���� �͵��� ���� ���·� Ÿ �÷����� ���� ����
	// �Ϻη� namespace Proud �ȿ� �ξ���. ���� ���� global namespace�� �����ϴ� ��� Ÿ�簡 ������ �Ͱ� �浹�� �� ������.
	// �Դٰ� �� Ŭ������ ����� �� ����: �ȱ׷����� ATL�� �߰��ϴ� ��� IsDebuggerPresent �Լ��� ���� ������ ������ ������ �߻��ؼ�.
	class CFakeWin32
	{
	public:
		PROUD_API static unsigned int GetTickCount();
		PROUD_API static bool IsDebuggerPresent();
		PROUD_API static void OutputDebugStringA(const char *text);
		PROUD_API static void OutputDebugStringW(const wchar_t *text);
	};

#ifdef _PNUNICODE
#define OutputDebugStringT OutputDebugStringW
#else
#define OutputDebugStringT OutputDebugStringA
#endif


#ifdef _WIN32
	String GetMessageTextFromWin32Error(uint32_t errorCode);
#endif // _WIN32

#ifndef _WIN32
	bool fd_is_valid(int fd);
#endif


}

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

