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

#include <new>
#include "BasicTypes.h"
#include "FastHeapSettings.h"
#include "Exception.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup util_group
	*  @{
	*/

	/**
	\~korean
	���� �ӵ��� heap alloc�� ������ ���� ������ �ִ� �Ҵ��� Ŭ����.

	����
	- <a target="_blank" href="http://guide.nettention.com/cpp_ko#fast_heap" >Fast heap</a>  ����

	����
	- �Ҵ� �ӵ��� ������

	����
	- �� �Ҵ��ڷ� �Ҵ��� �ν��Ͻ��� main() ���� ���� �ı��Ǿ�� �Ѵ�. �� ���� ������ �� �� �����ؾ� �Ѵ�.
	- Ư�� �̻� ũ��� ������ ���� ���Ѵ�.
	- �޸� Ǯ ����̹Ƿ� ��ð� ���� �׿� �޸𸮰� ���´�. ���� ���� �Ҵ�/�ı��� �ϴ� ��쿡�� ������ ����.

	\~english
	Though this allocation class allocates heap alloc with high speed but there are some restrictions.

	Usage
	- Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#fast_heap" >Fast heap</a>

	Strength
	- High allocation speed

	Weakness
	- The instance allocated by this allocator must be destructed before main() terminates. In other words, must be carefu when set this as global variable.
	- A certain size or bigger cannot be accelerated.
	- This leaves some unused memory when used for a long time since this is memory pool way. Therefore, this can be used only when there are needs to perform frequent allocation/destruction.

	\~chinese
	?��������heap alloc����?�����������������?��

	����۰��
	- ??��<a target="_blank" href="http://guide.nettention.com/cpp_zh#fast_heap" >Fast heap</a>%��

	?��
	- ���������ᡣ

	����
	- ��������������?����main()?�������?��?����������?����?�������
	- �����߾�����������ʥ�ܡ�
	- ��??����pool۰�ң�???����??��?����?����ᡣ��?���?��?������/��?��??���ġ�?������?��

	\~japanese
	�ܪ�������heap alloc�򪷪ު�������������Ϊ�����?���髹�Ǫ���

	����۰��
	- \ref fast_heap  ?��

	���
	- ��?�������ܪ��Ǫ���

	ӭ�
	- ������?���ܪ�?�ƪ����󫹫��󫹪�main()�����������?���ʪ���Ъʪ�ު���?�������??���Ǫ�������򪷪ʪ���Ъʪ�ު���
	- �����߾�Ϋ�������ʥ�ܪ��������ު���
	- ����?��?��۰�ҪʪΪǡ��������������˪�?������?��?��ު�����êơ��誯��?/��?�򪹪�����Ϊ��Ū��誦�˪��ު��窦��
	\~
	*/
	class CFastHeap
	{
	protected:
		CFastHeap(); // ���� ���� ����
	public:
		enum { DefaultAccelBlockSizeLimit = 2048 };

		PROUD_API virtual ~CFastHeap();

		/**
		\~korean
		�޸𸮸� �Ҵ��Ѵ�. �Ҵ��� �޸𸮴� Realloc�̳� Free�� ������ �� �ִ�.
		\param size �Ҵ���� �޸� ũ��

		\~english 
		Allocate the memory. The allocated memory may be adjusted by Realloc or Free. 
		\param size Size of the memory to be allocated. 


		\~chinese
		����?��������?��ʦ���Realloc���Free?�ڡ�
		\param size ʦ�������?����᳡�

		\~japanese
		����?���ܪ�?�ƪު����ܪ�?�ƪ�����?��Realloc�Ȫ�Free�����ڪ���몳�Ȫ��Ǫ��ު���
		\param size �ܪ�?�ƪ������?������
		\~
		*/
		virtual void* Alloc(size_t size) = 0;

		/**
		\~korean
		�޸𸮸� ���Ҵ��Ѵ�. ���Ҵ��� �޸𸮴� ��ġ�� �ٲ� �� �ֱ� ������ ���ϵǴ� ������ ���� �ݵ�� ������ ��.
		\param ptr ���Ҵ��� �޸� ������
		\param size ���Ҵ��� �޸� ������

		\~english 
		Reallocate the memory. As reallocated memory may have its position switched, you must refer the returned pointer value. 
		\param ptr Memory pointer to be reallocated.
		\param size Memory size to be reallocated. 


		\~chinese
		��������?������������?��������ʦ��?��?����??���������??��
		\param ptr �����������?���?��
		\param size �����������?����᳡�

		\~japanese
		����?����ܪ�?�ƪ��ު�����ܪ�?�ƪ�������?�����Ǫ�?��몳�Ȫ�����ު��Ϊǡ��꫿?�󪵪�ʪ��ݫ���?��������?�Ϊ��ƪ���������
		\param ptr ��ܪ�?�ƪ������?�ݫ���? 
		\param size ��ܪ�?�ƪ������?������
		\~
		*/
		virtual void* Realloc(void* ptr, size_t size) = 0;

		/**
		\~korean
		�Ҵ��ߴ� �޸𸮸� �����Ѵ�.
		\param ptr �Ҵ� �޾Ҵ� �޸��� ������

		\~english 
		Clear the memory that was allocated. 
		\param ptr Pointer of the memory that was allocated. 

		\~chinese
		�������?��?��
		\param ptr ��������?���?��

		\~japanese
		�ܪ�?�ƪ�����?����𶪷�ު���
		\param ptr �ܪ�?�ƪ�����?�Ϋݫ���?
		\~
		*/
		virtual void Free(void* ptr) = 0;

		/**
		\~korean
		CFastHeap ��ü�� �����Ѵ�.
		\param AccelBlockSizeLimit �� ������ ū ũ���� �޸� ���� �Ҵ��� ������ lookaside allocator �����
		���� �ʴ� ������� �޸� ���� �Ҵ��Ѵ�. �� ���� Ŭ ���� �� ���� �޸𸮸� �Ҹ������� ���� �ӵ��� heap
		�Ҵ� Ȯ���� Ŀ����. (�׷��ٰ� ����ġ�� ũ�� page fault ������� ���� ���� ���ϰ� �Ƿ� �߻��Ѵ�.)
		\param pHeap ���� �� Fast Heap�� ProudNet���� �̸� ������ ���� Heap�� �ƴ� �ٸ� Heap�� ����ϰ� ������� �Ѵٸ� ���⿡ CMemoryHeap ��ü�� �����͸�
		�־�� �Ѵ�. ��, �� Ŭ������ CMemoryHeap �� �ڵ� ���������� �ʴ´�.
		NULL�� ������ ProudNet���� �̸� ������ ���� Heap�� ����Ѵ�.
		\param safeMode CLookasideAllocator.New() ����
		\param debugSafetyCheckCritSec ����׿��̴�. safeMode�� false�� ��쿡�� ��ȿ�ϴ�.
		�� fast heap�� ������ ������ debugSafetyCheckCritSec �� ����Ű�� critical section�� ���� �����忡 ���� ��� �������� üũ�ϰ�,
		��� ���°� �ƴϸ� ������ �߻���Ű�� �˶��� �Ѵ�.

		\~english
		Creates CFastHeap object
		\param AccelBlockSizeLimit Whenever allocating memory block bigger than this value, this allocates a usual memory block that does not follow lookaside allocator.
		Bigger this value becomes, occupies more memory but also increased chance of high speed heap allocation probability. (But if it is too bug then it lowers performance due to page fault cost.)
		\param pHeap In order to let this Fast Heap use other Heap that is not previously created by ProudNet, CMemoryHeap object pointer must be entered in here.
		But, this class does not automatically remove CMemoryHeap.
		If NULL is entered in here then uses previously created Heap by ProudNet.
		\param safeMode Please refer CLookasideAllocator.New()
		\param debugSafetyCheckCritSec for debugging use. Only valid when safeMode=false
		Whenever access to this fast heap, must check if critical section pointed by debugSafetyCheckCritSec is in its locked status by current thread, if not locked then this alarms that error occurs.

		\~chinese
		���� CFastHeap%?�ڡ�
		\param AccelBlockSizeLimit ��?�������?����?��BLOCK��?������������lookaside allocator۰��������?��block��???������?���������?��ӣ����������heap?��?��ʥ����?η��󮣬?����?�??����page fault?���������������
		\param pHeap ����??Fast Heap��?�������ProudNet���������?��Heap������heap���������������heap��?��?�����ʥ CMemoryHeap%?�����?��ӣ�����?��?�??� CMemoryHeap%��
		?��NULL?�����ProudNet����������?��Heap��
		\param safeMode ??�� CLookasideAllocator.New()��
		\param debugSafetyCheckCritSec ��??�ġ����safeMode��false?������
		��?????fast heap��?�����??debugSafetyCheckCritSe������critical section��������?�?��?����??������������?����???��

		\~japanese
		CFastHeap���֫������Ȫ��������ު���
		\param AccelBlockSizeLimit ����������ު����������Ϋ���?�֫�ë����ܪ�?�ƪ������Ȫ�lookaside allocator۰�Ҫ��Ū�ʪ����ȪΫ���?�֫�ë����ܪ�?�ƪު������������ު����۪ɪ�ê���������?����Ī��ު������ܪ�������heap��?���㪬�ު����ʪ�ު���(�����������ު�˪��ު�Φ������page fault�����Ȫ˪����������Ϊ���潪����������?�檷�ު���) 
		\param pHeap �⪷������Fast Heap��ProudNet�����ê���������?�Ī�Heap�ǪϪʪ����Heap�����Ī���誦�˪���������ϡ�������CMemoryHeap���֫������ȪΫݫ���?������ʪ���Ъʪ�ު���ӣ�������Ϋ��髹��CMemoryHeap�������۪��몳�ȪϪ���ު���
		NULL��������ProudNet�����ê���������?�Ī�Heap�����Ī��ު���
		\param safeMode CLookasideAllocator.New() ?��	
		\param debugSafetyCheckCritSec �ǫЫë��ĪǪ���safeMode��false�Ǫ�������Ϊ���?�Ǫ��� 
		����fast heap�򫢫��������������Ȫ�debugSafetyCheckCritSec��򦪹critical section����Ϋ���ëɪ˪�êƫ�ë�?���ʪΪ�������ë����ơ���ë�?���ǪϪʪ���Ы���?��?�檵���뫢��?��򪷪ު��� 
		
		\~
		*/
		PROUD_API static CFastHeap* New( size_t AccelBlockSizeLimit = DefaultAccelBlockSizeLimit , const CFastHeapSettings& settings = CFastHeapSettings());

		/**
		\~korean
		block�� fast heap�� ���� ������� ���� �ƴϸ� ����â�� ���ų� ũ���ð� �߻��Ѵ�.

		\~english
		If block is not created by fast heap then it will either produce an error window or cause a crash.

		\~chinese
		����block������fast heap?����?��?��????���?����?��

		\~japanese
		�֫�ë���fast heap�˪�ê��ª�쪿�ΪǪϪʪ���Ы���??�������ƪ��몫����ë��媬?�檷�ު���
		\~
		*/
		PROUD_API static void AssureValidBlock(void* block);

		virtual int DebugCheckConsistency() = 0;
	};

	template<typename T>
	inline T* FastHeap_NewInstance(CFastHeap* heap)
	{
		T* ret = (T*)heap->Alloc(sizeof(T));

		if (ret == NULL)
			ThrowBadAllocException();

		CallConstructor<T>(ret);

		return ret;
	}

	template<typename T>
	inline void FastHeap_DeleteInstance(CFastHeap* heap, T* obj)
	{
		CallDestructor<T>(obj);
		heap->Free(obj);
	}

	/**  @} */

}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
