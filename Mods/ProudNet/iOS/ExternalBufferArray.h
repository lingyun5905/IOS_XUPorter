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
#include "Exception.h"
#include "UnsafeMem.h"
#include "sysutil.h"
#include "FastArray.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup util_group
	*  @{
	*/

	PROUD_API extern const char* ExternalBufferArrayIsUninitializedError;
	PROUD_API extern const char* ExternalBufferArrayIsInitializedError;

	/** 
	\~korean
	�ܺ� ���۸� ����ϴ� �迭 Ŭ�����Դϴ�.

	����: �ܺ� ���۾ȿ� �̹� �Ҵ�� ��ü���� �������� �ʾƾ� �մϴ�. �� �ܼ��� �ʱ�ȭ�� �޸� �����̾�� �մϴ�. �ֳ��ϸ�
	CArrayWithExternalBuffer �� �ʱ�ȭ�� ���̱� �����Դϴ�. 

	\param TYPE �迭�� ���� Ÿ���Դϴ�.
	\param RAWTYPE �迭 ���Ұ� raw memory copy�� �ص� ������ Ÿ�������� ���� �����Դϴ�. int�� ���������� std.string�� �������� �ʽ��ϴ�.
	�迭�� �׸� Ÿ���� ������, �ı���, ���� ���� �����ڰ� ������ �ʾƵ� �Ǵ� Ÿ���� ��� true�� ������ �� �ֽ��ϴ�.
	�̸� true�� �����ϸ� �迭�� ����, ����, ũ�� ���� ���� �� �� ���������� �߻��ϴ� �迭 �׸��� ����, �ı�, ���� ������ ����
	������, �ı���, ���� ���� �����ڸ� ȣ������ �ʽ��ϴ�. ���� ó�� �ӵ��� ���˴ϴ�. �⺻���� false�Դϴ�.
	\param INDEXTYPE �迭 �ִ� ũ�� �� index�� type. int32,int64,intPtr �� �ϳ��� ���� ���� �����մϴ�. 32-64bit int�� casting ���ϵ� ���� ���ϹǷ� ������ ���� �� ���� ���մϴ�.
	���� ��� ��Ŷ ũ���� ��� �����ϸ� 2GB�� �Ѵ� ���� �� �ٷ�Ƿ� int32�� �����մϴ�. ���� ���μ��������� �ٷ�� ���̸� intPtr�� ���մϴ�. ��Ʈ��ũ ��� �� 32bit�δ� ������� ���� �ٷ��
	int64�� ���մϴ�.

	\~english
	Allocation class that uses external buffer

	Note: There must be NO previously allocated object within external buffer. In other words,it must be an initialized memory area since CArrayWithExternalBuffer will be initialized.

	\param TYPE Allocation type
	\param RAWTYPE To check if the type is safe even if array element is processed as ��raw memory copy��. int is safe but std.string is not safe.
	In case element type of array is not related to constructor, destructor and copy assignment operator, you can set it as ��true��. 
	If setting it as ��true��, constructor, destructor and copy assignment will not be called for progression of construction, destruction and copy of array element that internally occurs when inserting & deleting & changing size.
	Therefore, processing speed will be improved. 
	Default is ��false��.
	\param INDEXTYP It is strongly recommended to use the maximum size of array and one of index types like int32,int64 and intPtr.
	Casting load between int32 and int64 should be considered, so using the appropriate one is recommended. 
	For example, packet size should be int32 because it does not exceed 2GB and if it is only for local process, intPtr is recommended. 
	int64 is appropriate when int32 cannot deal with accurate value like network statistics.  

	\~chinese
	������ݻ?��?����֪?��
	�����ݻ?��?��?����?������?�ڡ�???��??�������?��?洡���? CArrayWithExternalBuffer%??�����?��

	\param TYPE ��֪�����?����
	\param RAWTYPE ???��?��raw memory copy������������?����Int ?�����ӣ std.string%�����
	������֪��?��?��ʦ�������Constructor��Destructor��?�???ߩݬ��Copy Assignment Operator����?ʦ����?true��
	����?�����?true���?��֪?��?����?𶡢?�����������?��?��?���?ݻ?������֪?������������?��?�?�����УConstructor��Destructor��?�???ߩݬ��
	??���?�������������??false��
	\param INDEXTYP ��?�??���������index��type. int32,int64,intPtr ����������?��32-64bit int ��?��casting?���������?������?������?��۰����
	����?�����������Դ��������?2GB�ܣ�����?����int32���������������?��?intPtr������????��?������32bit���������?����?��int64��

	\~japanese
	��ݻ�Ыëի�?���Ū���֪���髹�Ǫ���

	�������ݻ�Ыëի�??��?���ܪ�?�ƪ�쪿���֫������Ȫ�����ƪϪ����ު���?����?�����Ѣ�����쪿����?��洪ǪϪʪ���Ъʪ�ު��󡣪ʪ��ʪ顢CArrayWithExternalBuffer����Ѣ������몫��Ǫ���
	\param TYPE ��֪����ȫ����תǪ���
	\param RAWTYPE ��֪��Ȫ�raw memory copy�򪷪ƪ�����ʫ����תʪΪ���?����ʦ���Ǫ���Int������Ǫ�����std.string������ǪϪ���ު���
	��֪�����ͫ����ת���������?������?������ߩ���Ū��ʪ��ƪ��ު������תǪ������ꡢtrue����Ҫ��몳�Ȫ��Ǫ��ު���
	�����ture����Ҫ������֪��?������𶡢������?�ڪʪɪ򪹪�����?ݻ�ܪ�?�檹����֪���ͪ���������?������?Φ��Ϊ���ˡ���������?������?������ߩ�������󪷪ު��󡣪�êơ�?����������߾����ު�����������false�Ǫ���
	\param INDEXTYPE��֪���ޫ����������index��type. int32��int64��intPtr�Ϊ�����Ī��Ū����Ȫ�?�᪷�ު���32-64bit int���castingݶ�ê����ʪǪ��ު���Ϊ���﷪ʪ�Ϊ��Ū����Ȫ�?�᪷�ު���
	�Ǫ��С��ѫ��ëȪΫ����������ꡢ�Ǫ����2GB����Φ���ʪ���Ϊ����ʪ��Ϊ�int32��?�᪷�ު�����?����׫����ǪΪ��⪤��Ϊʪ�intPtr��?�᪷�ު����ͫëȫ�?����ͪ�ʪ�32bit�Ǫ�����ª������⪨��int64��?�᪷�ު���

	\~
	*/
	template < typename TYPE, bool TYPE_IN_REF = true, bool RAWTYPE = false, typename INDEXTYPE = intptr_t>
	class CArrayWithExternalBuffer :public CFastArray < TYPE, TYPE_IN_REF, RAWTYPE, INDEXTYPE >
	{
		/****************************
		����!!! ���� ũ�� �迭�� ����� ������ ���� ������ �̰Ͱ��� PS4���� ���δ�!! 
		*/

	public:
		inline CArrayWithExternalBuffer(void *buffer, INDEXTYPE capacity)
		{
			// CFastArray���� �����Ǿ��� ���¸� �����Ѵ�.
			this->m_Capacity = capacity;
			this->m_Data = (TYPE*)buffer;
		}

		

		/**
		\~korean
		NULL�̸� ���ܸ� ����

		\~english TODO:translate needed.
		Generate an exception if null. 

		\~chinese
		NULL ��??���⡣

		\~japanese
		NULL�Ǫ��������˪ʪ�ު���
		\~
		*/
		inline void MustNotNull() const
		{
			if (this->m_Data == NULL)
				ThrowException(ExternalBufferArrayIsUninitializedError);
		}
		
		/**
		\~korean
		NULL�� �ƴϸ� ���ܸ� ����

		\~english TODO:translate needed.
		Generate an exception if not null.

		\~chinese
		����NULL��?���⡣

		\~japanese
		NULL�ǪϪʪ��������˪ʪ�ު���
		\~
		*/
		inline void MustNull() const
		{
			if (this->m_Data != NULL)
				ThrowException(ExternalBufferArrayIsInitializedError);
		}

		/**
		\~korean
		���� NULL�̴�

		\~english TODO:translate needed.
		It��s null now

		\~chinese
		?���NULL��

		\~japanese
		���NULL�Ǫ���
		\~
		*/
		inline bool IsNull() const
		{
			return this->m_Data == NULL;
		}

		/** 
		\~korean 
		�����Ѵ�.
		\param buffer buffer������ 
		\param capacity ������ ũ�� 

		\~english TODO:translate needed.
		Set it up. 
		\param buffer buffer pointer
		\param capacity buffer size

		\~chinese
		?�ǡ�
		\param buffer buffer�?��
		\param capacity buffer����᳡�		

		\~japanese
		���Ҫ��ު���
		\param buffer buffer�ݫ���?
		\param capacity �Ыëի�?�Ϋ�����
		\~
		*/
		inline void Init(void* buffer, INDEXTYPE capacity)
		{
			MustNull();

			if(buffer == 0 || capacity == 0)
				return;   // �Ϻη� �̷��� �����ϴ� ��쵵 ���� �� �ִ�. �̷��� ��� �ƹ� �͵� ó������ ���� �����ؾ� �Ѵ�. �̰��� ���ϴ� ��ü�� �־���.

			// ���¸� �����Ѵ�.
			this->m_Capacity = capacity;
			this->m_Length = 0;
			this->m_Data = (TYPE*)buffer;
		}

		/**
		\~korean
		��� ��� ������ �ʱ�ȭ �Ѵ�.

		\~english TODO:translate needed.
		Initialize all member parameters. 

		\~chinese
		����������???��

		\~japanese
		��ƪΫ���?��??����Ѣ�����ު���
		\~
		*/
		inline void Uninit()
		{
			this->SetCount(0); // �̰� ���־ ���� �ʱ�ȭ���� �� ������!
			this->m_Capacity = 0;
			this->m_Length = 0;
			this->m_Data = NULL;
		}

		inline CArrayWithExternalBuffer()
		{
			this->m_Capacity = 0;
			this->m_Length = 0;
			this->m_Data = NULL;
		}

		inline ~CArrayWithExternalBuffer()
		{
			// �̰� ����� ���� Ŭ������ �ı��ڿ��� DataBlock_Free�� ȣ�� ���Ѵ�.
			// �� �Լ��� ������ ������ ��ǻ� ���� û�ҵ� �����̾�� �Ѵ�.
			if (IsNull() == false)
			{
				this->SetCount(0);
				this->m_Data = NULL; 
			}
		}

		/**
		\~korean 
		dest�� ���۸� �����Ѵ�. 

		\~english Shares data with dest.

		\~chinese
		dest ?dest����?��?��

		\~japanese
		Dest�ȫЫëի�?�����媷�ު���
		\~
		*/
		inline void ShareTo(CArrayWithExternalBuffer& dest) const
		{
			dest.m_Capacity = this->m_Capacity;
			dest.m_Data = this->m_Data;
			dest.m_Length = this->m_Length;
		}
	private:



		/* 
		\~korean
		���� ��ü�� �����ȴ�. CopyTo �Ǵ� ShareTo�� ��� �Ѵ�.
		�̷��� �Ǿ� �ִ� ������, CArrayWithExternalBuffer �� = �����ڸ� �� ��� �̰���
		������ ��������, ���빰 ���������� ��ȣ�ϱ� �����̴�.

		\~english
		Duplication itself is prohibited. Must use CopyTo or ShareTo.
		The reason why is that it is unclear whether CArrayWithExternalBuffer is a pointer share or copying contents 
		when CArrayWithExternalBuffer uses '=' opeartor.

		\~chinese
		?�������������ܡ������CopyTo���ShareTo��
		��?������ CArrayWithExternalBuffer%?ߩ���?��???�������?����?��?�?𤡣

		\~japanese
		����?�?�����Ǫ���CopyTo�ު���ShareTo���Ūêƪ���������
		���Ϊ誦�˪ʪ���릪ϡ�CArrayWithExternalBuffer��=��ߩ���Ū����ꡢ���쪬�ݫ���?����ʪΪ���?�ڪ����?�ʪΪ������ܪ�����Ǫ���
		\~
		*/
		CArrayWithExternalBuffer& operator=(const CArrayWithExternalBuffer&);
		CArrayWithExternalBuffer(const CArrayWithExternalBuffer&);

		virtual INDEXTYPE GetRecommendedCapacity(INDEXTYPE actualCount)
		{
			// �׻� �̹� �����ִ� ���� �޸��� ũ�⸦ ���.
			if (actualCount > this->m_Capacity)
				ThrowArrayOutOfBoundException();
			return this->m_Capacity;
		}

		virtual void DataBlock_Free(void* /*data*/)
		{
			// �ϴ� ���� ����. 
			// ����: CFastArray�� m_Data=null �ϴ� ���� ������ �����ؾ� �Ѵ�!
		}

		virtual void* DataBlock_Alloc(size_t length)
		{
			if (length > 0)
			{
				MustNotNull();
			}
			return this->m_Data;
		}

		virtual void* DataBlock_Realloc(void* /*oldPtr*/, size_t newLength)
		{
			if (newLength > 0)
			{
				MustNotNull();
			}
			return this->m_Data;
		}
	};

	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
