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

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud 
{
	/** \addtogroup util_group
	*  @{
	*/

	class CMemoryHeap;
	class CriticalSection;

	/** 
	\~korean
	Fast Heap�� �����ϴ� ����Դϴ�.

	\~english
	This is how to access Fast Heap.

	\~chinese
	����Fast Heap��۰�ҡ�

	\~japanese
	Fast Heap�򫢫���������۰�ҪǪ���
	\~
	*/
	enum FastHeapAccessMode
	{
		/** 
		\~korean
		�� �Ѱ��� �����常�� Fast Heap�� ���������� Fast Heap ���ΰ� Thread safe���� �ʽ��ϴ�.
		�� ������ �� �Ѱ��� �����常�� Fast Heap�� �����Ѵٴ� ���� ����� ���� ����Ͻʽÿ�!

		\~english
		Only 1 tread accesses to Fast Heap but the inside of Fast Heap is not Thread safe.
		This setting must be used when there is a guarantee that onl 1 thread accessed to Fast Heap.!

		\~chinese
		?��������??������Fast Heap��ӣFast Heap?ݻ��Thread safe��
		?����������??������Fast Heap?�����?�ǣ�

		\~japanese
		���ê���ĪΫ���ëɪΪߪ�Fast Heap�򫢫��������ު�����Fast Heap?ݻ��Thread safe�ǪϪ���ު���
		�������ҪϪ��ê���ĪΫ���ëɪΪߪ�Fast Heap�򫢫���������Ȫ������Ȫ����������Ϊ��Ūêƪ���������
		\~
		*/
		FastHeapAccessMode_UnsafeSingleThread,
		
		/** 
		\~korean
		���� �����忡�� Fast Heap�� �����ص� �����ϰ� �۵��մϴ�. �׸��� ��� CPU �ھ Ȱ���ϴ� �۵����� �����մϴ�.

		\~english
		This operates safely even if multiple threads accee to Fast Heap. And has a way to utilize all of CPU cores.

		\~chinese
		?η��??������Fast Heap������������??������?�����CPU������??۰����

		\~japanese
		��?�Ϋ���ëɪ�Fast Heap�򫢫��������ƪ���������Ѫ��ު��������ơ����٪ƪ�CPU���������Ī�����������?�Ū��ު���
		\~
		*/
		FastHeapAccessMode_MultiThreaded,
	};

	/** 
	\~korean
	Fast Heap�� Lookaside Allocator�� ȯ�漳���� ��� �ֽ��ϴ�.

	\~english
	Settings environment for Fast Heap and Lookaside Allocator

	\~chinese
	�����Fast Heap��Lookaside Allocator��?��?�ǡ�

	\~japanese
	Fast Heap��Lookaside Allocator���������Ҫ�?��ƪ��ު���
	\~
	*/
	class CFastHeapSettings
	{
	public:
		/** 
		\~korean
		���� �޸� �����ڰ� ProudNet���� �̸� ������ ���� Heap�� �ƴ� �ٸ� Heap�� ����ϰ� ������� �Ѵٸ� ���⿡ CMemoryHeap ��ü�� �����͸�
		������ �˴ϴ�. 
		- �� ������ ���õ� �޸� �Ŵ����� �ı��� ���⼭ ������ CMemoryHeap �� �ı������� �ʽ��ϴ�.
		- NULL�� ������ ProudNet���� �̸� ������ ���� Heap�� ����մϴ�.

		\~english
		If memory manager intends to let other Heap to be used rather than previously created custom Heap from ProudNet then this is where pointer of CMemoryHeap object to be entered.
		- When the memory manager related to this setting is destructed, CMemoryHeap designated in here is not to be destructed.
		- When NULL entered, the Heap previously created by ProudNet is used.
		
		\~chinese
		����?����η��?���������ProudNet���������?��Heap���������Heap��?���?��?�� CMemoryHeap%?�����?��
		- ?�?����?��?����η��?����??��?��?��?�?������� CMemoryHeap%��
		- ۯ��NULL��?�����ProudNet���������?��Heap��

		\~japanese
		�⪷������?η����ProudNet��?����������?��Heap�ǪϪʪ����Heap���Ū��誦�˪���������ϡ�������CMemoryHeap���֫������ȪΫݫ���?������ƪ���������
		- �������Ҫ�?֧��������?�ޫ�?����?����?���˪�������Ҫ���CMemoryHeap����?���몳�ȪϪ���ު���
		- NULL��������ProudNet��?����������?��Heap���Ū��ު���
		\~
		*/
		CMemoryHeap* m_pHeap;

		/** 
		\~korean
		������ ����Դϴ�.

		\~english
		Threading mode 

		\~chinese
		Threading ټ�ҡ�

		\~japanese
		����ëǫ��󫰫�?�ɪǪ���
		\~
		*/
		FastHeapAccessMode m_accessMode;

		/** 
		\~korean
		�� �Ѱ��� �����忡���� �� fast heap�� ����ϴ��� �˻��ϴ� Critical section ��ü�Դϴ�.
		- fast heap�� FastHeapAccessMode_UnsafeSingleThread �� ��쿡�� ��ȿ�մϴ�.
		- fast heap�� FastHeapAccessMode_UnsafeSingleThread �� ���, �� ����� ����ڰ� ������ �־�� �մϴ�.
		- �� ����� debug mode������ �۵��մϴ�.

		\~english
		This is Critical section object that checks if only 1 thread uses this fast heap.
		- Only valid if the fast heap is FastHeapAccessMode_UnsafeSingleThread
		- If the fast heap is FastHeapAccessMode_UnsafeSingleThread, then this member must be set by user.
		- This function only operates in debug mode. 

		\~chinese
		??���������??�������fast heap��Critical section?�ڡ�
		- ���fast heap��FastHeapAccessMode_UnsafeSingleThread����?��������
		- fast heap ��FastHeapAccessMode_UnsafeSingleThread����??����?�?�����?��
		- ��������debug mode??��

		\~japanese
		���ê���ĪΫ���ëɪǪΪߪ���Fast Heap���Ū��Ϊ���?�۪���Critical section���֫������ȪǪ���
		- fast heap�� FastHeapAccessMode_UnsafeSingleThread�Ǫ��������Ϊ���?�Ǫ���
		- fast heap�� FastHeapAccessMode_UnsafeSingleThread�Ǫ������ꡢ���Ϋ���?���?��?�����Ҫ�����驪�����ު���
		- ����Ѧ����debug mode�ǪΪ����Ѫ��ު���
		\~
		*/
		CriticalSection* m_debugSafetyCheckCritSec;

		CFastHeapSettings();
	};

	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
