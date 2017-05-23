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

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup util_group
	*  @{
	*/

	class CMemoryHeap;

	/**
	\~korean
	ProudNet ��ü���� �����ϴ� �޸� Heap. Process Heap�� �ƴϴ�!
	- �� Ŭ������ ProudNet ���ο��� ����. ���ſ��� CFastArray �� ���� ������ malloc,free�� ������
	�̰��� debug CRT���� redefine�Ǳ� ������ debug ���忡�� �ٸ��� �۵��Ѵ�. Ư��
	ProudNet�� DLL ������ ��� malloc,free�� msvcr90d.dll!_free_dbg ��� ��Ÿ�� ������ ���� ������
	�� Ŭ������ ����� �Ұ����ϴ�.
	- �׷��� CSingleton �� ���������� ����ϰ� �ִ�. CSingleton �� CFirstHeap �� �ƴ� CProcHeap �� �����Ѵ�.

	\~english
	This is a memory heap that is owned by ProudNet. This is not 'Process Heap' at all!
	- This class is used inside of ProudNet. In the past, malloc and free used by many such as CFastArray but since this is re-defined at debug CRT and works differently in debug build.
	Especially when ProudNet is DLL version, malloc and free cause runtime error at msvcr90d.dll!_free_dbg therefore it is necessary to use this class.
	- However, this uses CSingleton internally. CSingleton is depended on CProcHeap, not CFirstHeap.

	\~chinese
	�ProudNet������׺��?����Heap.����Process Heap��
	- �?�ProudNet?ݻ���ġ�?��� CFastArray%��?���۰����malloc,free��ӣ��??�debug CRT��redefine�����debug build����??���ҡ���?��ProudNet��DLL����?��malloc,free �msvcr90d.dll!_free_dbg ��?��?������??���?����������ʦ�����ܡ�
	- ӣ���?ݻ���� CSingleton%�� CSingleton ��? CProcHeap%����� CFirstHeap%��

	\~japanese
	ProudNet ���?�����󪹪����?Heap. Process Heap�ǪϪ���ު���
	- ���Ϋ��髹��ProudNet��?ݻ���Ū��ު���Φ�۪˪�CFastArray�ʪ�??��ᶪ� malloc��free���Ūêƪ��ު����������쪬debug CRT��redefine�˪ʪ몿�ᡢdebug�ӫ�ɪ��ު����Ѫ򪷪ު�����ˡ�ProudNet��DLL��?�����Ǫ������ꡢmalloc��free��msvcr90d.dll!_free_dbg�ʪɪǫ�󫿫��૨��?���󪷪ު��Ϊǡ����Ϋ��髹�����Ī���۰����ު���
	- ��������CSingleton��?ݻ�ܪ��Ūêƪ��ު���CSingleton��CFirstHeap�ǪϪʪ�CProcHeap�������ު���
	\~
	*/
	class CFirstHeap
	{
	public:
		PROUD_API static void* Alloc(size_t size);
		PROUD_API static void* Realloc(void* ptr, size_t size);
		PROUD_API static void Free(void* ptr);

		PROUD_API static CMemoryHeap* GetHeap();
	};

	/**
	\~korean
	CFirstHeap �� �޸� �̰��� Process Heap�� ���� �ٷ��.
	- �̰��� CSingleton �� �����ϴ� Heap Ŭ�����̴�.

	\~english
	Not as CFirstHeap, this directly manages Process Heap.
	- This is Heap class that CSingleton is depended on.

	\~chinese
	? CFirstHeap%���ң�??����?��Process Heap��
	- ?�� CSingleton%��?��Heap?��

	\~japanese
	CFirstHeap���ުêƪ���� Process Heap�����������⪤�ު���
	- �����CSingleton��������Heap���髹�Ǫ���
	\~
	*/
	class CProcHeap
	{
	public:
		PROUD_API static void* Alloc(size_t size);
		PROUD_API static void* Realloc(void* ptr, size_t size);
		PROUD_API static void Free(void* ptr);
	};

	class CMemoryHeap
	{
	public:
#if !defined(_WIN32)
		PROUD_API static CMemoryHeap* NewFromHeapHandle();
		PROUD_API static CMemoryHeap* NewHeap();
#else
		PROUD_API static CMemoryHeap* NewFromHeapHandle(HANDLE hHeap, bool autoDestroy);
		PROUD_API static CMemoryHeap* NewHeap(bool autoDestroy);
#endif

		virtual void* Alloc(size_t size) = 0;
		virtual void* Realloc(void* ptr, size_t size) = 0;
		virtual void Free(void* ptr) = 0;
		virtual int DebugCheckConsistency() = 0;

		virtual ~CMemoryHeap() {}
	};

	/**  @} */

}

#define DECLARE_NEW_AND_DELETE // ��ǻ� CProcHeap::Alloc() = malloc()�̱� ������, �׳� ���ƹ��ȴ�.
// #define DECLARE_NEW_AND_DELETE					\
// 	void* operator new(size_t size)					\
// 		{															\
// 		void *ret = CProcHeap::Alloc(size);						\
// 		if (ret == NULL)										\
// 			ThrowBadAllocException();							\
// 		return ret;												\
// 		}															\
// 	void operator delete(void* ptr, size_t)			\
// 		{															\
// 		return CProcHeap::Free(ptr);							\
// 		}
// 

/* UE4 ���� operator new, delete�� override�ϴµ�, �̹� ��ü������ obj-pool ���� ���� ��� ���� �� �ִ�.
�� ������ obj-pool�� �ٷ����� �͵��� �Ʒ� ��ũ�θ� �ȿ��� ������ ����.
UE4�� throw keyword�� �� ���Ƿ� ThrowBadAllocException�� ����.
*/
#define DECLARE_NEW_AND_DELETE_THROWABLE \
 	void* operator new(size_t size)					\
 		{															\
 		void *ret = CProcHeap::Alloc(size);						\
 		if (ret == NULL)										\
 			ThrowBadAllocException();							\
 		return ret;												\
 		}															\
 	void operator delete(void* ptr, size_t)			\
 		{															\
 		return CProcHeap::Free(ptr);							\
 		}
 
#ifdef _MSC_VER
#pragma pack(pop)
#endif