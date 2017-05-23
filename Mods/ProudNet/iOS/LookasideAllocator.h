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
#include "FastHeapSettings.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif
	/** \addtogroup util_group
	*  @{
	*/
	class CLookasideAllocatorInternal;

	/** 
	\~korean
	�ſ� ���� �޸� �Ҵ�,������ ������ �� ���� ������ �ִ�.
	- �׻� ���� ũ���� �޸𸮸� �Ҵ��� �� �ִ�.
	- �̰ɷ� �Ҵ��� ��ü�� ���� �����̾�� �ȵȴ�. �� �Ҵ��� ��ü�� ��� �ð����� �� allocator�� ��� �ð����� ���̾�� �Ѵ�.

	Ư¡
	- ���������� memory page ������ �޸� ���� �̸� �Ҵ��ϰ� ����Ѵ�. ���� �ʹ� ���� ������ CLookasideAllocator �ν��Ͻ��� ����� ���� �������� �ʴ´�.
	- memory page�� VirtualAlloc���� �Ҵ�ȴ�. ���� internal fragmentation�� ������ �����Ƿ� win32 working set�� ũ�⵵ �����ϴ�
	ȿ���� �ش�. 

	\~english
	Performs very high speed memory allocation/disengagement but there are some restrictions.
	- Memory of same size can only be allocated at all time.
	- The object allocated by this cannot be global variable. In other words, the destruction time of this allocator must come prior to the desruction time of allocated object.

	Characteristics
	- Allocate memory block of memory page unit in advance and then use it, so it is recommended not to make too many CLookasideAllocator instances. 
	- Memory page is allocated to VirtualAlloc. Since it will not create internal fragmentation, it brings an effect of reducing the size of win32 working set.

	\~chinese
	ު������?�����գ�ӣ��??�?��
	- ����������?�����?��
	- �����������?���������??��?��������?????��llocator������

	����
	- �?ݻ??�����memory page?����?��Block�����ģ��������??��?���� CLookasideAllocator%?�ǡ�
	- memory page ������VirtualAlloc����?��?��internal fragmentation�����????�win32 working set�������������

	\~japanese
	�Ȫƪ��ܪ�����?��?�����򪷪ު����������Ī����峪�����ު���
	- ���Ī��Ҫ��������Ϋ���?�Ϊߪ��ܪ�?�ƪ몳�Ȫ��Ǫ��ު���
	- ������ܪ�?�ƪ����֫������Ȫ����??�ǪϪʪ���Ъʪ�ު���?�����ܪ�?�ƪ����֫������Ȫ�?ѥ�����ꪳ��Allocator��?ѥ������໪ǪϪʪ���Ъʪ�ު���

	��?
	- ?ݻ�ܪ�memory page?�ȪΫ���?�֫�ë������ê��ܪ�?�ƪ����Ī��ު�����êơ��Ȫƪ�������?��CLookasideAllocator���󫹫��󫹪��ª몳�ȪϪ�?�᪷�ު���
	- memory page��VirtualAlloc���ܪ�?�ƪު�����êơ�internal fragmentation���ª�ʪ��Ϊǡ�win32 working set�Ϋ��������������?����?���ު��� 
	\~
	*/
	class CLookasideAllocator
	{
	protected:
		CLookasideAllocator(); // �����ڸ� ���ƹ���. �Ļ� Ŭ���������� �����.
	public:
		virtual ~CLookasideAllocator();

		/** 
		\~korean
		�޸𸮸� �Ҵ��մϴ�. 

		\~english
		Allocate memory.

		\~chinese
		����?��

		\~japanese
		����?���ܪ�?�ƪު���
		\~
		*/
		virtual void* Alloc(size_t size) = 0;
		/** 
		\~korean
		�Ҵ��ߴ� �޸𸮸� �����մϴ�.

		\~english
		Disengage the allocated memory.

		\~chinese
		���������?��

		\~japanese
		�ܪ�?�ƪ�����?����𶪷�ު���
		\~
		*/
		virtual void Free(void* ptr) = 0;
		/** 
		\~korean
		�⺻������ thread safe�Դϴ�. ������ thread unsafe�� �ؼ� ���� ����ȭ�� �Ϸ��� thread unsafe�ϰ� �ɼ��� �ٲ� �� �ֽ��ϴ�.
		- �����ؼ� ����ϼž� �մϴ�. 

		\~english
		This is thread safe by default. the option can change to thread unsafe in order to accelerate.
		- Must be careful when use this.

		\~chinese
		������thread safe��ӣ����thread unsafe?��?��ʥ��?ʦ�?????��thread unsafe��
		- �������ġ�

		\~japanese
		�����ܪ�thread safe�Ǫ�����������thread unsafe�˪�ê�?��ʥ�����򪹪몿��˪ϡ�thread unsafe�˫��׫�����?���몳�Ȫ��Ǫ��ު���
		- ��򪷪��Ūêƪ���������
		
		\~
		*/
		virtual int DebugCheckConsistency() = 0;

		/** 
		\~korean
		�� Lookaside allocator�� �����մϴ�.
		\param settings �ʱ� �Ӽ��� ������ �� �ֽ��ϴ�. ���� ������ �Ķ�����Դϴ�.  

		\~english
		Creates a new Lookaside allocator
		\param settings Can set the initial attributes. This is a neglectable parameter.

		\~chinese
		��������Lookaside allocator��
		\param settings ʦ�?����Ѣ?������ʦ�������??��

		\~japanese
		�檷��Lookaside allocator���������ު���
		\param settings ��Ѣ?�������Ҫ��몳�Ȫ��Ǫ��ު�������ʦ���ʫѫ��?��?�Ǫ���  
		\~
		*/
		PROUD_API static CLookasideAllocator* New(const CFastHeapSettings& settings = CFastHeapSettings());
	};
	typedef RefCount<CLookasideAllocator> CLookasideAllocatorPtr;

	/**  @} */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif