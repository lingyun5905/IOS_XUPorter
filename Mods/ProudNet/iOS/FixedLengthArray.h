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
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif

	/** \addtogroup util_group
	*  @{
	*/

	/** 
	\~korean
	���� ũ���� �迭 Ŭ����. 
	- T data[] ������ ���� ũ�� �ܼ� �迭�� bounds checking�� �Ϸ��� �� Ŭ������ ��ü�ؼ� �������� ������ �� �ִ�.

	�Ϲ��� �뵵
	- CAtlArray �� ī���ش� ��������Ƿ� CAtlArray �� ������ ���� �����ϴ�. ��, static�̴� �翬������, ����/����/û�� ���� ����� �����ִ�. 

	���ǻ���
	- ���� ���� �迭�� CFixedLengthArray �� �ٲ� ��� _countof()�� sizeof()�� ���� ��찡 ���� ���ε�, �̷��� �κ��� ã�Ƽ� �����ؾ� �Ѵ�.
	������ _countof()�� �׻� 1�� ������ ���̱� �����̴�.

	\~english
	Array class with fixed size 
	- To 'bounds check' a simple, fixed size array of T data[] format, it is possible to replace with this class to draw stability.

	General usage
	- Has similar usage of CAtlArray since this is copied and made from it, but it does not have insertion/removal/cleanup functions since it is static. (of course...) 

	Note
	- If replacing the existing static array with CFixedLengthArray then there can be cases that either _countof() or sizeof() is used. << must modify them correctly.
	This is because of the fact that _countof() will always return 1.

	\~chinese
	ͳ�������???��
	- ��bounds checking T data[]������ͳ�����????�����?������ʦ?��������?������

	������Բ
	- ��?��?� CAtlArray%����ܣ���? CAtlArray%������۰���������ġ���?��static������?���ģ�ӣ����ʿ?��?��/?�/?���������

	�������
	- ��������????��?? CFixedLengthArray%��?��ʦ��?����_countof()���sizeof()���?��?��?????�����ǡ�
	��������?_countof()����?����1��

	\~japanese
	ͳ�ҫ���������֪���髹
	- T data[] ���Ҫ�ͳ�ҫ�������?����֪��bounds checking���몿��˪ϡ����Ϋ��髹�����ê���������?�몳�Ȫ��Ǫ��ު���

	�����ܪ���Բ
	- CAtlArray�򫳫�?�����Ūê����ᡢCAtlArray������۰�����۪�׾�Ī��ƪ��ު���ӣ����static�ʪΪ�?�ԪǪ�����?��/���/��ʪɪ�Ѧ����?���ƪ��ު��� 

	���������
	- ?��Ϋ����ƫ��ë���֪��CFixedLengthArray��?�������ꡢ_countof()��sizeof()���Ū����ꪬ����ު��������Ϊ誦��ݻ�ª����������᪷�ʪ���Ъʪ�ު���
	�Ǫ��С�_countof()�Ϫ��Ī�1��꫿?�󪹪�Ϫ�������Ǫ���
	\~
	*/
	template<int size,typename TYPE, typename ARG_TYPE = const TYPE&>
	class CFixedLengthArray 
	{
	public:

		// ����� �� �ε��� ��ȣ�� �ƴϸ� ���� �߻��Ѵ�.
		inline void CheckValidIndex(int nIndex) const
		{
			if(!(0<=nIndex && nIndex<size) )
				ThrowArrayOutOfBoundException();
		}

		/**
		\~korean
		�迭 ���̸� ���Ѵ�.

		\~english
		Gets length of array

		\~chinese
		ϴ???����

		\~japanese
		��֪��������ϴ��ު���
		\~
		*/
		inline int GetSize() const { return size; }

		/**
		\~korean
		�迭 ���̸� ���Ѵ�.

		\~english
		Gets length of array

		\~chinese
		ϴ???����

		\~japanese
		��֪��������ϴ��ު���
		\~
		*/
		inline int GetCount() const { return size; }

		/**
		\~korean
		�迭�� ����°�?

		\~english
		Is array empty?

		\~chinese
		??����?��

		\~japanese
		��֪�������ƪ��ު�����
		\~
		*/
		inline bool IsEmpty() const { return size==0; }

		/**
		\~korean
		�迭 �׸� ������ 

		\~english
		Array item accessor

		\~chinese
		???��??��

		\~japanese
		��֪���ͪ������
		\~
		*/
		inline const TYPE& GetAt(int nIndex) const { CheckValidIndex(nIndex); return m_data[nIndex]; }

		/**
		\~korean
		�迭 �׸� ������

		\~english
		Array item accessor 

		\~chinese
		???��??��

		\~japanese
		��֪���ͪ������
		\~
		*/
		inline TYPE& GetAt(int nIndex) { CheckValidIndex(nIndex); return m_data[nIndex]; }	

		/**
		\~korean
		�迭 �׸� ������

		\~english
		Array item accessor 

		\~chinese
		???��??��

		\~japanese
		��֪���ͪ������
		\~
		*/
		inline void SetAt(int nIndex, ARG_TYPE newElement) { CheckValidIndex(nIndex); m_data[nIndex]=newElement; }

		/**
		\~korean
		�迭 �׸� ������

		\~english
		Array item accessor

		\~chinese
		???��??��

		\~japanese
		��֪���ͪ������
		\~
		*/
		inline const TYPE& ElementAt(int nIndex) const {CheckValidIndex(nIndex); return m_data[nIndex]; }

		/**
		\~korean
		�迭 �׸� ������

		\~english
		Array item accessor

		\~chinese
		???��??��

		\~japanese
		��֪���ͪ������
		\~
		*/
		inline TYPE& ElementAt(int nIndex){CheckValidIndex(nIndex); return m_data[nIndex];}

		/**
		\~korean
		�迭 ���� ��ü�� �����͸� ��´�.

		\~english
		Gets pointer of array buffer object

		\~chinese
		?��???��??�����?��

		\~japanese
		��֪�Ыëի�?���֫������ȪΫݫ���?����ު���
		\~
		*/
		inline const TYPE* GetData() const {return m_data;}

		/**
		\~korean
		�迭 ���� ��ü�� �����͸� ��´�.

		\~english
		Gets pointer of array buffer object

		\~chinese
		?��???��??�����?��

		\~japanese
		��֪�Ыëի�?���֫������ȪΫݫ���?����ު���
		\~
		*/
		inline TYPE* GetData(){return m_data;}

		/**
		\~korean
		�迭 �׸� ������

		\~english
		Array item accessor

		\~chinese
		???��??��

		\~japanese
		��֪���ͪ������
		\~
		*/
		inline const TYPE& operator[](int nIndex) const{CheckValidIndex(nIndex); return m_data[nIndex];}	
		
		/**
		\~korean
		�迭 �׸� ������

		\~english
		Array item accessor

		\~chinese
		???��??��

		\~japanese
		��֪���ͪ������
		\~
		*/
		inline TYPE& operator[](int nIndex){CheckValidIndex(nIndex); return m_data[nIndex];}

	private:
		TYPE m_data[size];   // the actual array of data
	};

	/**  @} */

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
