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
#include "UnsafeMem.h"
#include "Exception.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup util_group
	*  @{
	*/


	extern const char* CannotUseFastHeapForFilledCollectionErrorText;

	PROUD_API void ShowLibSignatureMismatchError();
	extern int LibSignature;

	/**
	\~korean
	�� ��ü�� �迭 ũ�Ⱑ ������ �� ����ġ Ÿ��

	\~english
	The weight type when the size of the array of this object.

	\~chinese
	�?����??�����ʥ��?��ʥ��??����

	\~japanese
	���Ϋ��֫������Ȫ���֪��������?ʥ��������ʥ����������
	\~
	 */
	enum GrowPolicy
	{
		/**
		\~korean
		����

		\~english
		Balance

		\~chinese
		г��

		\~japanese
		�Ы��
		\~
		*/
		GrowPolicy_Normal,
		/**
		\~korean
		����. ��� �޸� ��뷮�� ����

		\~english
		High performance but use more memory

		\~chinese
		����������??������������

		\~japanese
		���������۪��˫���?�����᪬�����Ǫ���
		\~
		*/
		GrowPolicy_HighSpeed,
		/**
		\~korean
		�޸� ����. ��� �迭 ũ�Ⱑ ������ ���� ���Ϸ� ���� ������.

		\~english
		Save memory but when array size is increased, it shows low performance because of overload of copying

		\~chinese
		?��?��ӣ��??��??�����ʥ??�?���������������

		\~japanese
		����?������۪�����֪��������?ʥ���˫���?ݶ�ê˪�ê�������ժ���ު���
		\~
		*/
		GrowPolicy_LowMemory,
	};

	// byval���� byref������ ���� ���õǾ� ���Ǵ�, Ư��ȭ ���ø� Ŭ����

	template<typename T, bool T_IN_REF>
	struct FastArray_Traits;

	template<typename T>
	struct FastArray_Traits< T, true >
	{
		typedef const T& type;
	};

	template<typename T>
	struct FastArray_Traits< T, false >
	{
		typedef T type;
	};

	/**
	\~korean
	�迭 Ŭ����

	Pritimitive type�� ���� ���� ��� ���
	- RAWTYPE=true�� �����ϸ�, �迭 ��Ҵ� int ���� primitive Ÿ������ ���ֵǾ� �迭 �ٷ�� ������ ���˴ϴ�. (���� �ش�ȭ�� ���� ���������� memcpy ���� ���˴ϴ�.)
	- ��, int, bool, byte �� primitive type�� ��� �����մϴ�. ������, �ı���, ���� ���� �����ڸ� ���� ������ �ִ� Ÿ���� �迭 �׸����� ���̴� ��� �����մϴ�.

	�ֿ� Ư¡
	- heap ������ �ּ�ȭ�ϱ� ���� auto memory shrink�� ���� �ʽ��ϴ�.
	�� capacity�� ���� ���� �ʽ��ϴ�. ���� �޸� ���� ����� �������� ����ؾ� �Ѵٸ� �� ��ü�� ����� ���ϴ� ���� �����ϴ�.
	- ���������� <a target="_blank" href="http://guide.nettention.com/cpp_ko#fast_heap" >Fast heap</a> �� �Ἥ heap �������� ���� ���ϸ� ������ �� �ֽ��ϴ�.
	�⺻������ �� ����� �����ֽ��ϴ�. �׷���, UseFastHeap���� ���� �����մϴ�.
	- .Net framework�� List<>, STL.vector, CAtlArray�� �޼��� �̸��� ��� �� �� �ֽ��ϴ�. �׸��� STL.vector.iterator�� ���� ������
	iterator class�� �����ϰ� �ֽ��ϴ�.

	\param T �迭�� �׸� Ÿ���Դϴ�.
	\param T_IN_REF true�̸�, by reference�� �Է°��� ���޵˴ϴ�. false�̸� by value�� ���޵˴ϴ�. int ó�� ũ�Ⱑ 8 byte ������ ���� false�� ���� ���� ����˴ϴ�.
	\param RAWTYPE �迭 �׸��� raw memory copy�� �ص� ������ Ÿ�������� ���� �����Դϴ�. int�� ���������� std.string�� �������� �ʽ��ϴ�.
	�迭�� �׸� Ÿ���� ������, �ı���, ���� ���� �����ڰ� ������ �ʾƵ� �Ǵ� Ÿ���� ��� true�� ������ �� �ֽ��ϴ�.
	�̸� true�� �����ϸ� �迭�� ����, ����, ũ�� ���� ���� �� �� ���������� �߻��ϴ� �迭 �׸��� ����, �ı�, ���� ������ ����
	������, �ı���, ���� ���� �����ڸ� ȣ������ �ʽ��ϴ�. ���� ó�� �ӵ��� ���˴ϴ�. �⺻���� false �Դϴ�.
	\param INDEXTYPE �迭 �ִ� ũ�� �� index�� type. int32,int64,intPtr �� �ϳ��� ���� ���� �����մϴ�. 32-64bit int�� casting ���ϵ� ���� ���ϹǷ� ������ ���� �� ���� ���մϴ�.
	���� ��� ��Ŷ ũ���� ��� �����ϸ� 2GB�� �Ѵ� ���� �� �ٷ�Ƿ� int32�� �����մϴ�. ���� ���μ��������� �ٷ�� ���̸� intPtr�� ���մϴ�. ��Ʈ��ũ ��� �� 32bit�δ� ������� ���� �ٷ��
	int64�� ���մϴ�.

	\~english
	Array class

	Performance increase function for primitive type
	- The performance that manages array increases when RAWTYPE=true due to array factors are regarded as primitive type such as int. (In order to maximize the performance, sometimes memcpy can be used internally.)
	- However, only specific primitive types such as int, bool and byte can be used. It can be dangerous that the type with separate constructor, destructor and duplicator is used as array clause.

	Major characteristics
	- Does not perform auto memory shrink in order to minimize heap access
	  In other words, capacity never decreases. Therefore, if the circumstances must consider the side-effects of using too much memory then this object must not be used.
	- Internally, by using <a target="_blank" href="http://guide.nettention.com/cpp_en#fast_heap" >Fast heap</a>, it is possible to decrease the load cuased by heap access.
	  By default, this feature is off. But it can be changed by UseFastHeap.
	- Can use the metohd names of List<> of .Net framework, STL.vector and CAtlArray. And provides interator class that acts as STL.vector.iterator

	\param T Clause type of array
	\param T_IN_REF Set to true if you want the value to be passed by reference, or false for by value. Type of 8 or less of bytes such as int is passed faster if by value is selected.
	\param RAWTYPE To check if the type is safe even if array element is processed as ��raw memory copy��. int is safe but std.string is not safe.
	In case element type of array is not related to constructor, destructor and copy assignment operator, you can set it as ��true��.
	If setting it as ��true��, constructor, destructor and copy assignment will not be called for progression of construction, destruction and copy of array element that internally occurs when inserting & deleting & changing size.
	Therefore, processing speed will be improved.
	Default is ��false��.
	\param INDEXTYPE It is strongly recommended to use the maximum size of array and one of index types like int32,int64 and intPtr.
	Casting load between int32 and int64 should be considered, so using the appropriate one is recommended.
	For example, packet size should be int32 because it does not exceed 2GB and if it is only for local process, intPtr is recommended.
	int64 is appropriate when int32 cannot deal with accurate value like network statistics.

	\~chinese
	???

	?��Pritimitive type���������������
	- ?����RAWTYPE=true ��???����?����int��primitive?����?������??��������ԣ�?��������?������?ݻ����memcpy������
	- -ӣ��������int, bool, byte��Primitive type������??��Constructor��Destructor��?�???ߩݬ��?������?��֪?��?ʦ��?�����?��

	������
	- ?�������heap??�����auto memory shrink��
	?capacity??��??ᴡ�������??������?��??��?�����������?�������ġ�
	- ?ݻʦ�����<a target="_blank" href="http://guide.nettention.com/cpp_zh#fast_heap" >Fast heap</a>%�??heap??������?�á�
	���������?????��ӣ��ʦ���UseFastHeap?�����ǡ�
	- ʦ�����.Net framework ��List<>, STL.vector, CAtlArray%�����۰��٣?��?�����STL.vector.iterator%��iterator class��

	\param T ??��?��?����
	\param T_IN Type name for input parameter.
	Use T/const T& for passing values by value/reference.
	byval is preferred if data type is same or little than 8 bytes.
	\param RAWTYPE ???��?��raw memory copy������������?����Int ?�����ӣ std.string%�����
	������֪��?��?��ʦ�������Constructor��Destructor��?�???ߩݬ��Copy Assignment Operator����?ʦ����?true��
	����?�����?true���?��֪?��?����?𶡢?�����������?��?��?���?ݻ?������֪?������������?��?�?�����УConstructor��Destructor��?�???ߩݬ��
	??���?�������������??false��
	\param INDEXTYPE ��?�??���������index��type. int32,int64,intPtr ����������?��32-64bit int ��?��casting?���������?������?������?��۰����
	����?�����������Դ��������?2GB�ܣ�����?����int32���������������?��?intPtr������????��?������32bit���������?����?��int64��

	\~japanese
	��֪���髹
	Pritimitive type�Ϊ����������߾Ѧ��
	- RAWTYPE=true�����Ҫ���ȡ���֪��Ȫ�int�ʪɪ�primitive�����ת�̸�ʪ������֪��������߾����ު���(����п�����Ϊ����?ݻ�ܪ�memcpy�ʪɪ��Ū��ު�)
	- ӣ����int, bool, byte�ʪ�primitive type�Ϊ�����ʦ���Ǫ�����������?������?������ߩ��ܬ���êƪ��뫿���ת���֪���ͪ��Ū���������?�Ǫ���

	����?
	- heap ������������������몿��� auto memory shrink�򪷪ު���
	?����capacity���?���骷�ު��󡣪�êơ�����?Φ�����Ī�����ê����窹��С����Ϋ��֫������Ȫ����Ī�������۰���ު��Ǫ���
	- ?ݻ�ܪ�\ref fast_heap���Ūê�heap���������˪��ݶ�ê��峪��몳�Ȫ��Ǫ��ު��� 
	�����ܪ˪���Ѧ���ϫ��ժǪ�����������UseFastHeap��?��ʦ���Ǫ���
	- .Net framework��List<>��STL.vector��CAtlArray�Ϋ᫽�ë�٣������Ū����Ȫ��Ǫ��ު��������ơ�STL.vector.iterator�Ϊ誦����ܪ�iterator class����ꪷ�ƪ��ު���
	\param T ��֪�����ͫ����תǪ���
	\param T_IN_REF true�Ǫ���С�by reference����������?ӹ����ު���False�Ǫ����by value��?ӹ����ު���Int�Ϊ誦�˫�������8 byte����Ϊ�Ϊ�false���Ū����Ȫ�?�᪷�ު���
	\param RAWTYPE ��֪���ͪ� raw memory copy�򪷪ƪ�����ʫ����תʪΪ��ɪ����Ǫ���Int������Ǫ�����std.string������ǪϪ���ު���
	��֪�����ͫ����ת���������?������?������ߩ���Ū��ʪ��ƪ��ު������תǪ��������true����Ҫ��몳�Ȫ��Ǫ��ު���
	�����ture����Ҫ������֪��?������𶡢������?�ڪʪɪ򪹪�����?ݻ�ܪ�?�檹����֪���ͪ���������?������?Φ��Ϊ���ˡ���������?������?������ߩ�������󪷪ު��󡣪�êơ�?����������߾����ު�����������false�Ǫ���
	\param INDEXTYPE ��֪���ޫ����������index��type��int32,int64,intPtr�������Ī��Ū����Ȫ�?�᪷�ު���32-64bit int���castingݶ�ê����ʪǪ��ު���Ϊǡ���﷪ʪ�Ϊ��Ū����Ȫ�?�᪷�ު���
	�Ǫ��С��ѫ��ëȫ����������ꡢ�Ǫ����2GB���������Ϊ����ʪ��Ϊ�int32��?�᪷�ު�����?����׫����ǪΪ��⪦�ʪ�intPtr��?�᪷�ު����ͫëȫ�?����ͪ�ʪ�32bit�Ǫ�����ª������⪨��int64��?�᪷�ު���

	\~
	 */
	template<typename T, bool T_IN_REF = true, bool RAWTYPE = false, typename INDEXTYPE = intptr_t>
	class CFastArray
	{
		typedef typename FastArray_Traits<T, T_IN_REF>::type T_IN;

	protected:
		/* �� ������ ��ӵ� Ŭ�������� ���� ������ �� �ִ�.
		Q: ��ġ��ũ �ƴѰ���?
		A: ���� ���� �־�� �ϰ� ���� ���� ����� �Ѵٴ� ���� ��å�� ���������,
		min capacity�� capacity ���� ���⼭ ���� �׼����Ǳ� ������ �̵� ���� ������ ���� �ִ� ���� ���� �������Դϴ�.
		*/

		// �迭 ������
		T* m_Data;
		// �迭�� ���� ũ��
		INDEXTYPE m_Length;
		// �迭 ������ ���� ���� �Ҵ�� ũ��
		INDEXTYPE m_Capacity;
		// �迭 ������ ���� �ּ� ũ��. �� 1���� �迭 �׸��� ��Ƶ� �̰� �̻��� ������ �Ǿ� �ִ�.
		INDEXTYPE m_minCapacity;

		// if true, capacity never shrinks.
		// for example, this is flagged if this object is being object-pooled.
		bool m_suspendShrink;

		// �޸� �켱? CPU �켱?
		GrowPolicy m_growPolicy;

		inline void InitVars()
		{
			m_Data = NULL;
			m_Length = 0;
			m_Capacity = 0;
			m_minCapacity = 0;
		}

		// gets recommended capacity for required length actualCount.
		virtual INDEXTYPE GetRecommendedCapacity(INDEXTYPE actualCount)
		{
			INDEXTYPE nGrowBy = INDEXTYPE(); // prevent compile LV4 warning
			switch (m_growPolicy)
			{
			case GrowPolicy_LowMemory:
				// ����ڰ� �ø����� ũ�� �״�θ� �ø���.
				return PNMAX(m_minCapacity, actualCount);
			default:
				nGrowBy = m_Length / 8;
				nGrowBy = PNMIN(nGrowBy, 1024); // �ִ� ������
				nGrowBy = PNMAX(nGrowBy, 4); // �ּ� ������
				break;
			case GrowPolicy_HighSpeed:
				// ���� ������ �� 12% ������ �߰��� �ø���.
				nGrowBy = m_Length / 8;
				nGrowBy = PNMAX(nGrowBy, 16); // �ּ� ������
				nGrowBy = PNMAX(nGrowBy, (INDEXTYPE)(64 / sizeof(T))); // for ByteArray and CMessage.
				nGrowBy = PNMIN(nGrowBy, 1024); // �ִ� ������
				break;
			}

			// change capacity only if there is much gap between current capacity and new capacity.
			INDEXTYPE v1 = m_Capacity;
			INDEXTYPE v2 = actualCount + nGrowBy;
			INDEXTYPE diff;
			if (v1 > v2) // INDEXTYPE might be unsigned.
				diff = v1 - v2;
			else
				diff = v2 - v1;

			// never return 0 which clears all capacity.
			if(!m_suspendShrink)
			{
				// shrink�� ����ϴ� ��Ȳ.
				if (diff > nGrowBy)
				{
					return PNMAX(m_minCapacity, v2);
				}
				else
					return PNMAX(m_minCapacity, v1);
			}
			else
			{
				// shrink�� ���� ���� �ʴ� ��Ȳ.
				if (diff > nGrowBy)
				{
					return PNMAX(m_Capacity, v2);
				}
				else
					return PNMAX(m_Capacity, v1);
			}
		}

		inline void BoundCheck(INDEXTYPE index) const
		{
			if (index < 0 || index >= m_Length)
				ThrowArrayOutOfBoundException();
		}
	public:

		/**
		\~korean
		�⺻ ������

		\~english
		Default constructor

		\~chinese
		��?�����

		\~japanese
		���������
		\~
		*/
		inline CFastArray()
		{
			m_growPolicy = GrowPolicy_Normal;
			m_suspendShrink = false;

			InitVars();
		}

		/**
		\~korean
		�ܺ� �����͸� �����ؿ��� ������
		\param data ������ �迭�� ������ �Դϴ�.
		\param count �迭�� Data�� �Դϴ�.

		\~english 
		Constructor that copies external data
		\param src This is the pointer of the data array
		\param count This is the number of data in the array		



		\~chinese
		?���ݻ?����������
		\param data ?��??���?��
		\param count ��??��Data?��

		\~japanese
		��ݻ��?���򫳫�?���ƪ��������
		\param data ��?����֪�Ϋݫ���?�Ǫ���
		\param count ��֪�Ϋ�?��?�Ǫ���

		\~
		*/
		inline CFastArray(const T* data, INDEXTYPE count)
		{
			m_growPolicy = GrowPolicy_Normal;
			m_suspendShrink = false;

			InitVars();
			InsertRange(0, data, count);
		}

		/**
		\~korean
		�ܺ� �����͸� �����ؿ��� ������
		\param src ������ CFastArray

		\~english 
		Constructor that copies external data
		\param src CFastArray to be copied
		

		\~chinese
		?���ݻ?����������
		\param src �?��� CFastArray%��

		\~japanese
		��ݻ��?���򫳫�?���ƪ��������
		\param src ����?���� CFastArray 

		\~
		*/
		inline CFastArray(const CFastArray &src)
		{
			if(PROUDNET_H_LIB_SIGNATURE != LibSignature)
			{
				ShowLibSignatureMismatchError();
			}

			m_suspendShrink = src.m_suspendShrink;
			m_growPolicy = src.m_growPolicy;
			InitVars();
			src.CopyTo(*this);
		}

		virtual ~CFastArray()
		{
			// SetCount(0); // �̷��� �ϸ� �ȵ�! SetCount->GetRecommendedCapacity->invalid enum value����->kaboom!
			if(!RAWTYPE)
			{
				if(m_Length > 0)
					CallDestructors(m_Data, m_Length);
			}

			if (m_Data != NULL)
			{
				DataBlock_Free(m_Data);
			}
		}

		/**
		\~korean
		�� ��ü�� �迭 ũ�Ⱑ ������ �� ����ġ Ÿ���� ����. �ڼ��� ������ GrowPolicy�� ����
		\param val �迭�� ���� ����ġ�� ���� type

		\~english 
		Set the weighted value type when the array size of this object increases. For details, refer to GrowPolicy.
		\param val The type to the weighted value of the array


		\~chinese
		?�?����??�����ʥ��?��?��ʥ��??����???�??��GrowPolicy��
		\param val ???��ʥʥ��?��type��

		\~japanese
		���Ϋ��֫������Ȫ���֪��������?ʥ��������ʥ���������ת����ҡ��٪����ϡ�GrowPolicy��?��
		\param val ��֪��?ʥʥ������?����type

		\~
		 */
		inline void SetGrowPolicy(GrowPolicy val)
		{
			m_growPolicy = val;
		}

		/**
		\~korean
		���� grow policy(�� ��ü�� �迭 ũ�Ⱑ ������ �� ����ġ Ÿ��) ���

		\~english
		Getting existing grow policy

		\~chinese
		?������grow policy���?����??�����ʥ?��ʥ��??������

		\~japanese
		?���grow policy(���Ϋ��֫������Ȫ���֪��������?ʥ��������ʥ����������)����ު���
		\~
		 */
		inline GrowPolicy GetGrowPolicy()
		{
			return m_growPolicy;
		}

		/**
		\~korean
		�ּ� ���� ũ�⸦ �����Ѵ�. ����(capacity)ũ�Ⱑ ������ �� �ּ��� �� ������� ũ�� �����Ѵ�.
		\param newCapacity �ּ� Capacity size

		\~english 
		Set the minimum buffer size. When the buffer (capacity) size increases, set it at least bigger than this size.
		\param newCapacity Minimum capacity size



		\~chinese
		?�����buffer��᳡�Buffer��capacity�������ʥ?��?��?������?����??��
		\param newCapacity ���Capacity size��

		\~japanese
		��ᳫЫëի�?�����������Ҫ��ު����Ыëի�?(capacity)��������?ʥ������������ڪ��Ϋ���������ު������Ҫ��ު���
		\param newCapacity ��� Capacity size 

		\~
		*/
		inline void SetMinCapacity(INDEXTYPE newCapacity)
		{
			m_minCapacity = PNMAX(newCapacity, m_minCapacity);
			//SetCapacity(m_minCapacity); �̷��� ���ø� �ߴµ��� ���� �Ҵ���! ��!
		}

		/**
		\~korean
		�迭�� ���� �ִ� ����(ĳ�ۼ�Ƽ)�� �����Ѵ�.
		- ĳ�ۼ�Ƽ�� ������ �� ��, �پ������ �ʴ´�.

		\~english
		Balances the buffer(capacity) possessed by array
		- Capacity is only increased, not decreased.

		\~chinese
		?��???����buffer��capacity����
		- capacity��?��ʥ����??ᴡ�

		\~japanese
		��֪���êƪ���Ыëի�?(����ѫ��ƫ�?)����ｪ��ު���
		- ����ѫ��ƫ�?��?ʥ������������몳�ȪϪ���ު���

		\~
		 */
		inline void SetCapacity(INDEXTYPE newCapacity)
		{
			assert(m_Capacity >= m_Length);

			newCapacity = PNMAX(m_minCapacity, PNMAX(newCapacity, m_Capacity) );

			// �ø� �ʿ䰡 �������� �ø���.
			if(newCapacity > m_Capacity)
			{
				if (m_Capacity == 0) // ĳ�۰� �ִ��� �����ٸ�
				{
					assert(!m_Data);

					// 0->N
					m_Data = (T*)DataBlock_Alloc(newCapacity * sizeof(T));

					// capacity�� ������ ���̹Ƿ� ctor,dtor ȣ�� NO!
				}
				else
				{
					// �ִ� ĳ���� ����
					if(RAWTYPE)
					{
						T* oldData = m_Data;
						T* newData;

						newData = (T*)DataBlock_Realloc(oldData, newCapacity * sizeof(T));

						m_Data = newData;

						// realloc�� �� �������� ���絵 ���ϴϱ� ���⼭ �� ���� ���ʿ�
					}
					else	// raw type�� �ƴ� ���
					{
						T* oldData = m_Data;
						T* newData;

						// copy operator�� �ִ� ��ü Ÿ���� ��� realloc�� �ϸ� �� ������ ���� �ҽ��ϰ� �ȴ�.
						// ���� realloc�� �ƴ� alloc new => do assign oper => delete old�� �ؾ� �Ѵ�.
						newData = (T*)DataBlock_Alloc(newCapacity * sizeof(T));

						// ���� �Ҵ�� ���ۿ� �� ���ۿ� �ִ� ��ü���� ���� �����ڸ� �����Ѵ�.
						CallCopyConstructors<T>(newData, oldData, m_Length);

						// �� ������ ���� �ֵ� ��ü���� �����ؾ�. ������ ���簡 �Ǿ����Ƿ�. �̰� ������ ������ �̾���!
						CallDestructors<T>(oldData,m_Length);
						DataBlock_Free(oldData);

						m_Data = newData;
					}
				}
				// ���ο� �뷮���� �����Ѵ�.
				m_Capacity = newCapacity;
			}
		}

		// Capacity never shrinks after this is called.
		// called by object pool classes.
		inline void SuspendShrink()
		{
			m_suspendShrink = true;
		}

		// called by object pool classes.
		inline void OnRecycle()
		{
		}

		// called by object pool classes.
		inline void OnDrop()
		{
			// �迭 ��ü�� ���� �����Ǵ� ���, ���� �ִ� ������� ��� û���ϴ� ���� ����.
			// �࿩�� shared_ptr�� ������ �ִ� item type�̸�, �̰� ������ ������ �̾��� �� �����ϱ�.
			ClearAndKeepCapacity();
		}

		/**
		\~korean
		�迭 ũ�⸦ �����Ѵ�
		- �迭 ũ�� ������ capacity�� ����� �����Ѵ�.
		\param newVal ���ο� �迭�� ũ��

		\~english 
		Adjust the array size
		- When adjusting the array size, the capacity increases sufficiently. 
		\param newVal Size of the new array


		\~chinese
		?��??��᳡�
		- ?��??���?capacity?������ʥ��
		\param newVal ����??��᳡�

		\~japanese
		��֪����������ｪ��ު���
		- ��֪���������������capacity�����?ʥ���ު���
		\param newVal �檷����֪�Ϋ�����

		\~
		 */
		inline void SetCount(INDEXTYPE newVal) // ������ �߿��ϹǷ� ��ƾ�� Ŀ�� inline
		{
			/*
			\~korean
			ũ�� ������ �߻��ϴ� ����
			- 0->N: ���� ����
			- N->0: capacity�� �״�� ����
			- M->N (M>N): capacity�� �״�� ����
			- M->N(M<N): granularity ������ ũ�� ����. ũ�� ������ realloc��.

			\~english
			Details occur when modifying size
			- 0->N: creates buffer
			- N->0: capacity is still kept
			- M->N (M>N): capacity is still kept
			- M->N(M<N): size increases in granularity unit. to be 'relloc'ed when size increased.

			\~chinese
			?�����??������?��
			- 0->N: ����buffer
			- N->0: capacity��׺�?
			- M->N (M>N): capacity��׺�?
			- M->N(M<N): �granularity?����ʥ��᳡������ʥ??realloc��

			\~japanese
			�������������?�檹������
			- 0->N: �Ыի�?����
			- N->0: capacity�Ϫ��Ϊު�����
			- M->N (M>N): capacity�Ϫ��Ϊު�����
			- M->N(M<N): granularity ?�Ȫǫ�����?ʥ��������?ʥ����realloc����ު���

			\~
			 */

			if (newVal < 0)
			{
				ThrowInvalidArgumentException();
			}

			if (newVal > m_Length)
			{
				// �ø���
				AddCount(newVal - m_Length);
			}
			else if (newVal < m_Length) // ���̱�
			{
				// �ʿ�� ĳ�۸� ������. �޸𸮸� �Ƴ��� �Ʋ�����.
				// ����ڴ�, ������ �ʿ��ϸ� SuspendShrink�� �ᵵ �ǰ�.
				INDEXTYPE newCapacity = GetRecommendedCapacity(newVal);
				SetCapacity(newCapacity);

				if (!RAWTYPE)
				{
					// ũ�Ⱑ �ٰ� ������ �ı��� ȣ��
					CallDestructors<T>(m_Data + newVal, m_Length - newVal);
				}
				else
				{
					// �ƹ��͵� ���Ѵ�.
					// ������� �Ǵ� ������ zero memory�ϴ� �͵� ���ɿ� �ǿ���. ���� ��.
				}

				// �� ������ ����
				m_Length = newVal;
			}
		}

		// SetCount���� ó�� �ӵ��� �� ������.
		// CMessage.Write���� ���� ȣ���ϹǷ� ���� ����ȭ�� ����.
		inline void AddCount(INDEXTYPE addLength)
		{
			if (addLength < 0)
			{
				ThrowInvalidArgumentException(); // ũ�⸦ ���̷��� �� �Լ� ���� �ٸ� �Լ��� �� ��.
			}
			else if (addLength > 0)
			{
				// �Ʒ� �� ������ ���� �ð��� �Դ´�. ���� ���ǹ����� �̸� �ǳʶڴ�.
				if (m_Length + addLength > m_Capacity) // capacity�� �� �÷��� �Ѵٸ�
				{
					// ���� ũ�� ���Ҵ�, �ʿ�� ��ü ���� ó��
					INDEXTYPE newCapacity = GetRecommendedCapacity(m_Length + addLength);
					SetCapacity(newCapacity);
				}

				if(!RAWTYPE)
				{
					// �þ ũ�⸸ŭ ������ ȣ��
					CallConstructors<T>(m_Data + m_Length, addLength);
				}

				// �� ũ�� ����
				m_Length += addLength;
			}
		}

		/// for STL compatibility
		inline void resize(INDEXTYPE sz)
		{
			SetCount(sz);
		}

		/**
		\~korean
		capacity�� ũ�⸦ ��´�

		\~english 
		Get the size of the capacity

		\~chinese
		?��capacity����᳡�

		\~japanese
		capacity�Ϋ���������ު���
		\~
		*/
		inline INDEXTYPE GetCapacity() const { return m_Capacity; }

		/**
		\~korean
		�迭 ũ��

		\~english
		Array size

		\~chinese
		??���

		\~japanese
		��֪������
		\~
		*/
		inline INDEXTYPE GetCount() const
		{
			return m_Length;
		}

		/// for STL compatibility
		inline INDEXTYPE size() const
		{
			return GetCount();
		}

		inline bool IsEmpty() const
		{
			return m_Length == 0;
		}

		/**
		\~korean
		�迭 û��. ClearAndKeepCapacity�� ����

		\~english
		Clean up array. Same as ClearAndKeepCapacity

		\~chinese
		????��?ClearAndKeepCapacity��?��

		\~japanese
		��֪�𶡣. ClearAndKeepCapacity���Ҫ��Ǫ���
		\~
		*/
		inline void Clear()
		{
			SetCount(0);    // �޸� �� �ı��� ���� ����
		}

		/**
		\~korean
		�迭 û��. Clear�� ����

		\~english
		Clean up array. Same as Clear

		\~chinese
		????��?clear��?��

		\~japanese
		��֪�𶡣Clear���Ҫ��Ǫ���
		\~
		*/
		inline void ClearAndKeepCapacity()
		{
#ifdef _DEBUG
			INDEXTYPE oldCount = m_Length;
#endif
			Clear();
#ifdef _DEBUG
			// �ִ� �迭�� ���Ŷ�� ���۰� �����־�� �Ѵ�.
			if (oldCount > 0)
			{
				assert(m_Data != NULL);
			}
#endif
		}

#if defined(_MSC_VER)
		/**
		\~korean
		�迭 ũ��

		\~english
		Array size

		\~chinese
		??��᳡�

		\~japanese
		��֪������
		\~
		*/
		__declspec(property(get = GetCount)) INDEXTYPE Count;
#endif

		/**
		\~korean
		index�� ����Ű�� �迭 �׸�

		\~english
		Array item that pointed by index

		\~chinese
		Index����???�͡�

		\~japanese
		index��򦪹��֪����
		\~
		*/
		inline T_IN ElementAt(INDEXTYPE index) const
		{
			BoundCheck(index);
			return m_Data[index];
		}

		/**
		\~korean
		index�� ����Ű�� �迭 �׸�

		\~english
		Array item that pointed by index

		\~chinese
		Index����???�͡�

		\~japanese
		index��򦪹��֪����
		\~
		*/
		inline T& ElementAt(INDEXTYPE index)
		{
			BoundCheck(index);
			return m_Data[index];
		}

		/**
		\~korean
		index�� ����Ű�� �迭 �׸�

		\~english
		Array item that pointed by index

		\~chinese
		Index����???�͡�

		\~japanese
		index��򦪹��֪����
		\~
		*/
		inline T_IN operator[] (INDEXTYPE index) const
		{
			return ElementAt(index);
		}

		/**
		\~korean
		index�� ����Ű�� �迭 �׸�

		\~english
		Array item that pointed by index

		\~chinese
		Index����???�͡�

		\~japanese
		index��򦪹��֪����
		\~
		*/
		inline T& operator[](INDEXTYPE index)
		{
			return ElementAt(index);
		}

		/**
		\~korean
		�迭 ���� �����͸� ��´�.

		\~english
		Gets array buffer pointer

		\~chinese
		?��??buffer�?��

		\~japanese
		��֪�Ыëի�?�ݫ���?����ު���
		\~
		*/
		inline T* GetData()
		{
			if (m_Length == 0)
				return NULL;
			return m_Data;
		}

		/**
		\~korean
		�迭 ���� �����͸� ��´�.

		\~english
		Gets array buffer pointer

		\~chinese
		?��??buffer�?��

		\~japanese
		��֪�Ыëի�?�ݫ���?����ު���
		\~
		*/
		inline const T* GetData() const
		{
			if (m_Length == 0)
				return NULL;
			return m_Data;
		}

		/**
		\~korean
		�ǵڿ� �߰�

		\~english
		Add at the end

		\~chinese
		��ʥ��������

		\~japanese
		��������ʥ
		\~
		*/
		inline void Add(T_IN value)
		{
			INDEXTYPE length = m_Length;

			// code profile ��� �ſ� ���� ȣ��Ǵ� �Լ��̴�. �̷��� ���� �������� ó���ϸ� ��κ��� ��� ������.
			if (length < m_Capacity)
			{
				if (!RAWTYPE)
				{
					CallConstructor(&m_Data[length], value);
				}
				else
				{
					m_Data[length] = value;
				}
				length++;
				m_Length = length;
			}
			else
			{
				// �� ���� �߰��Ѵ�.
				Insert(m_Length, value);
			}
		}

		/**
		\~korean
		indexAt�� ����Ű�� �׸��� ��� ��ĭ�� �ڷ� �а� value �� indexAt �� ����Ű�� ���� �߰��Ѵ�.

		\~english
		Move back item that pointed by indexAt then add value to place that pointed by indexAt

		\~chinese
		��indexAt����?����������̫�����value��ʥ��indexAt�������ǡ�

		\~japanese
		indexAt��򦪹���ͪ����1����������˪��骷�ơ�value��indexAt��򦪹�Ȫ������ʥ���ު���
		\~
		*/
		inline void Insert(INDEXTYPE indexAt, T_IN value)
		{
			InsertRange(indexAt, &value, 1);
		}

		/**
		\~korean
		�迭 �ڿ� ���ο� �迭 �߰�
		\param data ���� �߰��� �迭�� ������
		\param count �߰��� �迭�� ũ��

		\~english 
		Add a new array behind an array
		\param data Pointer of the array to be newly added. 
		\param count Size of the array to be added


		\~chinese
		??����ʥ����??��
		\param data �����ʥ���?��
		\param count ���ʥ��??��᳡�

		\~japanese
		��֪��������檷����֪����ʥ
		\param data �檿����ʥ������֪�Ϋݫ���? 
		\param count ��ʥ������֪�Ϋ�����

		\~
		*/
		inline void AddRange(const T* data, INDEXTYPE count)
		{
			//InsertRange(m_Length, data, count);�̰� �� ����

			if (count < 0)
				ThrowInvalidArgumentException();

			if (count == 0)
				return;

			INDEXTYPE oldCount = m_Length;

			// ���� Ȯ��
			AddCount(count);
			INDEXTYPE indexAt = oldCount;

			T* src = GetData();
			if (!RAWTYPE)
			{
				// �� ä���

				for (INDEXTYPE i = 0; i < count; i++)
				{
					// ������ ���� GetData() ���
					src[i + indexAt] = data[i];
				}
			}
			else
			{
				UnsafeFastMemcpy(src + indexAt, data, sizeof(T)*count);
			}
		}

		/**
		\~korean
		�迭 �߰��� �迭 �߰�. indexAt�� ����Ű�� �κ��� �ڷ� �о���� ƴ���� �߰��Ѵ�.
		\param indexAt �� index ��ȣ�� �������� �߰� �˴ϴ�.
		\param data data ������ �迭�� ������ �Դϴ�.
		\param count ������ �迭�� ũ��

		\~english 
		Add an array in the middle of an array. Push the area pointed at by indexAt behind and add it in the gap. 
		\param indexAt It is added after this index number. 
		\param data data It is a pointer of the array to be inserted. 
		\param count Size of the array to be added. 




		\~chinese
		�??��?��ʥ??��?indexAt����ݻ�����ϣ�������ʥ��?���졣
		\param indexAt ?index??����?���ʥ��
		\param data data�?����??�?��
		\param count ?����??��᳡�

		\~japanese
		��֪�������֪��ʥ��indexAt��򦪹ݻ�ª�����ت��骷���Ǫ����������ʥ���ު���
		\param indexAt ����index��?��󭪫����ʥ����ު���
		\param data data ?��������֪�Ϋݫ���?�Ǫ���
		\param count ?��������֪�Ϋ�����

		\~
		*/
		inline void InsertRange(INDEXTYPE indexAt, const T* data, INDEXTYPE count)
		{
			if (count < 0 || indexAt < 0 || indexAt > m_Length)
				ThrowInvalidArgumentException();

			INDEXTYPE oldCount =  m_Length;

			// ���� Ȯ��
			AddCount(count);

			// �̸� �о�ְ�
			INDEXTYPE moveAmount = oldCount - indexAt;
			T* src = GetData(); // getdata�ȿ� if������.

			if (moveAmount > 0)
			{
				if(!RAWTYPE)
				{
					for (INDEXTYPE i = moveAmount - 1;i >= 0;i--)
					{
						// ������ ���� GetData() ���
						src[i+indexAt+count] = src[i+indexAt];
					}
				}
				else
				{
					UnsafeFastMemmove(src+indexAt+count,src+indexAt,sizeof(T)*moveAmount);
					assert(indexAt+count+moveAmount<=m_Length);
				}
			}

			if(!RAWTYPE)
			{
				// �� ä���
				for (INDEXTYPE i = 0;i < count;i++)
				{
					// ������ ���� GetData() ���
					src[i+indexAt] = data[i];
				}
			}
			else
			{
				UnsafeFastMemcpy(src+indexAt,data,sizeof(T)*count);
			}
		}

		/**
		\~korean
		dest�� ũ�⸦ count�� ���� �� src�� �Ϻγ� ��ü�� dest�� �����Ѵ�.
		\param dest �迭�� dest�� �����մϴ�.
		\param srcOffset �迭 �� srcOffset ���� Data���� dest�� ���� �Ѵ�.
		\param count count���� ��ŭ�� �迭�� ���� �Ѵ�.

		\~english 
		After adjusting the size of dest with count, part of all of src is copied to dest. 
		\param dest Array is copied to dest. 
		\param srcOffset Copy the data after srcOffset within the array to dest.  
		\param count count Copy arrays as the same number of count. 




		\~chinese
		��dest�����?��?count����?src��ݻ������ݻ?���dest��
		\param dest ��???�?dest��
		\param srcOffset ????srcOffset���Data?�?���dest��
		\param count  ?�����?��count??��??��

		\~japanese
		Dest�Ϋ�������count����������src����ݻ�ު�����?��dest�ث���?���ު��� 
		\param dest ��֪��dest�ث���?���ު���
		\param srcOffset ��֪?��srcOffset�˽�Ϋ�?������dest�ث���?���ު���
		\param count count?��������֪�򫳫�?���ު���

		\~
		*/
		inline void CopyRangeTo(CFastArray &dest, INDEXTYPE srcOffset, INDEXTYPE count) const
		{
			if (srcOffset + count > m_Length || srcOffset < 0 || count < 0)
				ThrowInvalidArgumentException();

			dest.SetCount(count);

			if(!RAWTYPE)
			{
				T* pDest = dest.GetData();
				const T* pSrc = GetData();
				for (INDEXTYPE i = 0;i < count;i++)
				{
					// ������ ���� GetData() ���
					pDest[i] = pSrc[i+srcOffset];
				}
			}
			else
			{
				UnsafeFastMemcpy(dest.GetData(),GetData()+srcOffset,sizeof(T)*count);
			}
		}

		/**
		\~korean
		\param dest �迭�� dest�� �����Ѵ�.

		\~english
		\param dest copy array to dest.

		\~chinese
		\param dest ��???���dest��

		\~japanese
		\param dest ��֪��dest�ث���?���ު��� 
		\~
		*/
		inline void CopyTo(CFastArray &dest) const
		{
			CopyRangeTo(dest, 0, m_Length);
		}

		inline void CopyFrom(const CFastArray &src)
		{
			src.CopyTo(*this);
		}

		inline void CopyFrom(const T* from, INDEXTYPE fromCount)
		{
			if (fromCount < 0)
				ThrowInvalidArgumentException();
			SetCount(fromCount);
			for (INDEXTYPE i = 0;i < fromCount;i++)
			{
				(*this)[i] = from[i];
			}
		}

		/**
		\~korean
		index��° �׸���� count��ŭ �����Ѵ�.
		\param index ������ �迭�� index
		\param count index�κ��� count�� ��ŭ �����Ѵ�.

		\~english 
		Remove as many as the count from the (index)th item. 
		\param index Index of the array to be removed. 
		\param count Remove as many as the number of count from the index.


		\~chinese
		?�index??��?���?��count���ᡣ
		\param index �?���??index��
		\param count ?index?�?���?��count���ᡣ

		\~japanese
		index���ͪ����ͪ���count������۪��ު��� 
		\param index ��۪�����֪�� index
		\param count index����count?������۪��ު���

		\~
		*/
		inline void RemoveRange(INDEXTYPE index, INDEXTYPE count)
		{
			if (index < 0 || count < 0)
				ThrowInvalidArgumentException();
			count = PNMIN(count, m_Length - index);

			//������ �����
			INDEXTYPE amount = m_Length - (index + count);

			T* src = GetData();
			if (amount > 0)
			{
				if(!RAWTYPE)
				{
					for (INDEXTYPE i = 0;i < amount;i++)
					{
						// ������ ���� GetData() ���
						src[i+index] = src[i+index+count];
					}
				}
				else
				{
					UnsafeFastMemmove(src+index,src+index+count,amount*sizeof(T));
					assert(index+count+amount<=m_Length);
				}
			}

			SetCount(m_Length - count);
		}

		/**
		\~korean
		\param index index�� �ش��ϴ� data�� �����Ѵ�.

		\~english
		\param index Remove index th item

		\~chinese
		\param index ?�����index��data��

		\~japanese
		\param index index����?�����?������۪��ު��� 
		\~
		*/
		inline void RemoveAt(INDEXTYPE index)
		{
			RemoveRange(index, 1);
		}

		/**
		\~korean
		\param value value�� ���� ���� ������ �迭 �տ������� ã�Ƽ� ã���� �����Ѵ�.

		\~english
		\param value Seek same value as value from the first then remove it

		\~chinese
		\param value ?��?�???value����?��??��?����?𶡣

		\~japanese
		\param value value�Ϊ誦����������֪���񪫪������ơ�̸�Ī��ê�����۪��ު���
		\~
		*/
		inline bool RemoveOneByValue(T_IN value)
		{
			T* src = GetData();
			for (INDEXTYPE i = 0;i < m_Length;i++)
			{
				// ������ ���� GetData() ���
				if (src[i] == value)
				{
					RemoveAt(i);
					return true;
				}
			}

			return false;
		}

		/**
		\~korean
		���� ���� ������

		\~english
		Copy assignment operator

		\~chinese
		?�???ߩݬ��

		\~japanese
		����?������ߩ�
		\~
		*/
		inline CFastArray& operator=(const CFastArray &src)
		{
			src.CopyTo(*this);
			return *this;
		}

		/**
		\~korean
		\param value value�� ���� ���� ������ �迭 �׸��� �ִ��� Ȯ���Ѵ�.
		\return value�� ���� ���� ������ �迭 �׸��� ������ �� �ε����� �����Ѵ�. ã�� ���ϸ� -1�� �����Ѵ�.

		\~english
		\param value check if there is an array that has the same value as ��value��.
		\return If there is the array that has the same value as ��value��, the index is returned. If not found, -1 will be returned.

		\~chinese
		\param value ??������?value��??��???�͡�
		\return ������?value��??��???����?������?index��?��?������-1��

		\~japanese
		\param value value�Ϊ誦����������֪���ͪ����몫�����㪷�ު���
		\return value�Ϊ誦����������֪���ͪ�����С����Ϋ���ǫë�����꫿?�󪷪ު���̸�Ī���ʪ��ê���?1��꫿?�󪷪ު���

		\~
		 */
		inline INDEXTYPE FindByValue(T_IN value)
		{
			T* src = GetData();

			for (INDEXTYPE i = 0;i <  m_Length;i++)
			{
				if (value == src[i])
					return i;
			}
			return -1;
		}

		/** Returns true if value exists in the array. */
		inline bool Contains(T_IN value)
		{
			return FindByValue(value) >= 0;
		}

		/**
		\~korean
		- ����: �ܼ� �޸� �񱳴�. �� ���� ������ ��.
		\param rhs rhs�� ������ �������� üũ�Ѵ�.

		\~english
		- Note: This is a simple memory comparison. This is crucial.
		\param rhs Checks if this contains same as rhs

		\~chinese
		- �����??��?����?�����?���á�
		\param rhs ??����?rhs?����ҡ�

		\~japanese
		- �����?�����?����Ǫ�������˪���򪹪몳�ȡ�
		\param rhs rhs��?黪��Ҫ����ɪ���������ë����ު���

		\~
		 */
		inline bool Equals(const CFastArray &rhs) const
		{
			if(rhs.m_Length!=m_Length)
				return false;

			// �ܼ� �޸� �񱳴�.
			const T* p_rhs = rhs.GetData();
			const T* p_lhs = GetData();

			if(RAWTYPE)
			{
				return memcmp(p_rhs,p_lhs,rhs.m_Length * sizeof(T)) == 0;
			}
			else
			{

				for (INDEXTYPE i=0;i<m_Length;i++)
				{
					if(p_rhs[i] != p_lhs[i])
						return false;
				}
				return true;
			}

		}

		/// for STL compatibility
		inline void clear()
		{
			Clear();
		}

		class iterator;

		friend class iterator;

#ifndef PROUDNET_NO_CONST_ITERATOR
		class const_iterator;
		friend class const_iterator;

		/**
		\~korean
		STL�� const_iterator�� ���� ������ �Ѵ�.

		\~english
		Acts like const_iterator of STL

		\~chinese
		���?STL��const_iterator��?�����ġ�

		\~japanese
		STL��const_iterator�Ϊ誦����ܪ򪷪ު���
		\~
		 */
		class const_iterator
		{
			friend class CFastArray;
		public:
			const CFastArray* m_owner;
			INDEXTYPE m_pos;

			inline const_iterator() {}
			inline const_iterator(const iterator& src) { m_owner=src.m_owner; m_pos=src.m_pos; }

			inline const_iterator& operator++()
			{
				// preincrement
				if(m_pos<m_owner->m_Length)
					m_pos++;
				else
					ThrowArrayOutOfBoundException();

				return (*this);
			}

			inline const_iterator operator++(int)
			{
				// postincrement
				const_iterator _Tmp = *this;
				++*this;
				return (_Tmp);
			}

			inline bool operator==(const const_iterator& a) const
			{
				return m_pos==a.m_pos && m_owner==a.m_owner;
			}

			inline bool operator!=(const const_iterator& a) const
			{
				return !(m_pos==a.m_pos && m_owner==a.m_owner);
			}

			inline T_IN operator*() const
			{
				return m_owner->ElementAt(m_pos);
			}

		};
#endif
		/**
		\~korean
		STL�� iterator�� ���� ������ �Ѵ�.

		\~english
		Acts similar as iterator of STL

		\~chinese
		���?STL��iterator��?�����ġ�

		\~japanese
		STL��iterator�Ϊ誦����ܪ򪷪ު���
		\~
		 */
		class iterator
		{
			friend class CFastArray;
		public:
			CFastArray* m_owner;
			INDEXTYPE m_pos;

			inline iterator() {}
			inline iterator(const const_iterator& src) { m_owner=src.m_owner; m_pos=src.m_pos; }

			inline iterator& operator++()
			{
				// preincrement
				if(m_pos<m_owner->m_Length)
					m_pos++;
				else
					ThrowArrayOutOfBoundException();

				return (*this);
			}

			inline iterator operator++(int)
			{
				// postincrement
				iterator _Tmp = *this;
				++*this;
				return (_Tmp);
			}

			inline T_IN operator*() const
			{
				return m_owner->ElementAt(m_pos);
			}

			inline T& operator*()  // �� �޼��尡 ������ �� ������?
			{
				return m_owner->ElementAt(m_pos);
			}

			inline bool operator==(const iterator& a) const
			{
				return m_pos==a.m_pos && m_owner==a.m_owner;
			}

			inline bool operator!=(const iterator& a) const
			{
				return !(m_pos==a.m_pos && m_owner==a.m_owner);
			}
		};

		/**
		\~korean
		STL�� ���� �޼���� ���� ������ �Ѵ�.

		\~english
		Acts similar as same name method of STL

		\~chinese
		���?STL����٣۰����?�����ġ�

		\~japanese
		STL����٣�᫽�ëɪΪ誦����ܪ򪷪ު���
		\~
		 */
		inline iterator begin()
		{
			iterator ret;
			ret.m_pos = 0;
			ret.m_owner=this;

			return ret;
		}

		/**
		\~korean
		STL�� ���� �޼���� ���� ������ �Ѵ�.

		\~english
		Acts similar as same name method of STL

		\~chinese
		���?STL����٣۰����?�����ġ�

		\~japanese
		STL����٣�᫽�ëɪΪ誦����ܪ򪷪ު���
		\~
		 */
		inline iterator end()
		{
			iterator ret;
			ret.m_pos=m_Length;
			ret.m_owner=this;

			return ret;
		}

#ifndef PROUDNET_NO_CONST_ITERATOR
			/**
			\~korean
			STL�� ���� �޼���� ���� ������ �Ѵ�.

			\~english
			Acts similar as same name method of STL

			\~chinese
			���?STL����٣۰����?�����ġ�

			\~japanese
			STL����٣�᫽�ëɪΪ誦����ܪ򪷪ު���
			\~
			 */
		inline const_iterator begin() const
		{
			const_iterator ret;
			ret.m_pos = 0;
			ret.m_owner = this;

			return ret;
		}

		/**
		\~korean
		STL�� ���� �޼���� ���� ������ �Ѵ�.

		\~english
		Acts similar as same name method of STL

		\~chinese
		���?STL����٣۰����?�����ġ�

		\~japanese
		STL����٣�᫽�ëɪΪ誦����ܪ򪷪ު���
		\~
		 */
		inline const_iterator end() const
		{
			const_iterator ret;
			ret.m_pos=m_Length;
			ret.m_owner=this;

			return ret;
		}
#endif
		/**
		\~korean
		STL�� ���� �޼���� ���� ������ �Ѵ�.
		\param iter iter�� ����Ű�� �����͸� �����Ѵ�.

		\~english 
		Acts similar as same name method of STL


		\~chinese
		���?STL����٣۰����?�����ġ�
		\param iter ?�iter����?�ߡ�

		\~japanese
		STL����٣�᫽�ëɪΪ誦����ܪ򪷪ު���
		\param iter iter��򦪹��?������۪��ު���

		\~
		 */
		iterator erase(iterator iter)
		{
			if(iter.m_owner!=this)
			{
				ThrowInvalidArgumentException();
			}
			iterator ret = iter;
			//ret++; �̰� ����� �Ѵ�. �迭 �׸��� �����ϸ鼭 �ڿ��ִ°� ������ �ַ�� �з����� �׷��鼭 iter�� �ڵ����� ������ ����Ű�ϱ�.
			RemoveAt(iter.m_pos);

			return ret;
		}

		/**
		\~korean
		�迭�� ������ ������ �迭������ �����ϰ� �������ش�.

		\~english 
		Remove the last information of the array within the array and return it. 

		\~chinese
		?????�??����������?���ޡ�

		\~japanese
		��֪�����������ê���֪?������۪��ƫ꫿?�󪷪ު���
		\~
		*/
		inline T PopBack()
		{
			INDEXTYPE cnt = m_Length;

			if(cnt == 0)
				ThrowInvalidArgumentException();

			T ret = GetData()[cnt - 1];
			SetCount(cnt - 1);

			return ret;
		}

		/**
		\~korean
		�� ������ �׸��� index�� ����Ű�� ������ �ű� �� �� ������ �׸��� �����Ѵ�.
		������ ������� �ݷ��ǿ��� �㸮 �׸��� ������ �� Remove ��� ���� ȿ�����̴�.
		\param index ������ index

		\~english 
		After moving the last item to the place where index is pointing at and remove the last item. 
		It is effective to use instead of Remove when you move the waist item from a collection where sequence is irrelevant. 
		\param index Index to be removed. 

		\~chinese
		������?��?��index������۰���?�����?��
		�??����?��collection��?�mid-part?����?������Remove��??��������
		\param index �?���index��

		\~japanese
		���������ͪ�index��򦪹ᶪ�칪����������������ͪ���۪��ު���
		�����?���ʪ����쫯����������ͪ���۪�������Remove��������Ū���?���ܪǪ���
		\param index ��۪��� index

		\~
		 */
		inline void RemoveAndPullLast(intptr_t index)
		{
			intptr_t cnt = m_Length;
			if(index<0 || index>=cnt)
				ThrowInvalidArgumentException();

			// �� �� �׸��� index�� ����Ű�� ������ �̵�
			if(index < cnt - 1)
			{
				GetData()[index] = GetData()[cnt - 1];
			}

			// ������ 1 ����
			SetCount(cnt-1);
		}


		virtual void DataBlock_Free(void* data)
		{
			CProcHeap::Free(data);
		}

		virtual void* DataBlock_Alloc(size_t length)
		{
			void* ret = CProcHeap::Alloc(length);

			if (ret == NULL)
				ThrowBadAllocException();

			return ret;
		}

		virtual void* DataBlock_Realloc(void* oldPtr, size_t newLength)
		{
			void* newData = (T*)CProcHeap::Realloc(oldPtr, newLength);

			if (newData == NULL)
				ThrowBadAllocException();

			return newData;
		}
	};



	/**  @} */

	PROUD_API void ShowLibSignatureMismatchError();

	extern int LibSignature;
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
