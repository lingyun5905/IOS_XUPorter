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

#include "FastArray.h"
#include "PNString.h"

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
	����Ʈ �迭. ProudNet�� �뵵�� �°� ����ȭ�Ǿ� �ִ�.
	- ��Ʈ��ũ ��Ŷ�� �ְ� �޴� �����̹Ƿ� int32�θ� ����� �����Ѵ�.
	- ByteArray�� operator new,delete�� �������̵�Ǿ fast heap�� �����ϰ� �ִ�. ����	���� Proud.CFastHeap�� ���ǻ��� �Ծ��� �ؼ��ؾ� �Ѵ�.

	\~english TODO:translate needed.
	Byte array. It is optimized for the use of ProudNet
	- Since the purpose is to give and receive network packets, use is mandatory only in int32
	- The ByteArray is overridden in the operator new and delete, so it approaches fast heap. When using, the caution rules of Proud.CFastHeap must be complied with


	\~chinese
	Byte ��֪���?��������ProudNet��Բ��
	- ����������????������?����?�����˭�����int32��
	- BytesArray��?��operator new,delete,�������fast heap���������?����� Proud.CFastHeap%�������??��

	\japanese
	�Ы�����֪��ProudNet����Բ����請������������ƪ��ު���
	- �ͫëȫ�?���ѫ��ëȪ������ꪹ�����ܪǪ��Ϊǡ�int32�ǪΪ����Ī�?𤪷�ު���
	- ByteArray��operator new��delete�⫪?��?�髤�ɪ���ơ�fast heap�˫��׫�?�����ƪ��ު�����êơ���������Proud.CFastHeap�Ϊ����������Ю峪��������ʪ���Ъʪ�ު���
	\~
	\todo translate it.
	 */
	class ByteArray :public CFastArray < uint8_t, false, true, int >
	{
	public:
		typedef CFastArray<uint8_t, false, true, int> Base;
// 		PROUD_API static void* LookasideAllocator_Alloc(size_t length);
// 		PROUD_API static void LookasideAllocator_Free(void* ptr);
        
	public:
//#ifndef __MARMALADE__
//#pragma push_macro("new")
//#undef new
		//DECLARE_NEW_AND_DELETE
//		void* operator new(size_t size)
//		{
//			return LookasideAllocator_Alloc(size);
//		}
//		void operator delete(void* ptr, size_t /*size */)
//		{
//			LookasideAllocator_Free(ptr);
//		}
//#pragma pop_macro("new")
//#endif // __MARMALADE__

		/** 
		\~korean
		�⺻ ������

		\~english
		Defalut constructor

		\~chinese
		����������

		\~japanese
		���������
		\~
		 */
		inline ByteArray()
		{
		}

		/** 
		\~korean
		�ܺ� �����͸� �����ؿ��� ������
		\param data �����ؿ� BYTE�迭�� ������
		\param count count ��ŭ�� �����Ѵ�.

		\~english TODO:translate needed.
		Constructor copies external data 
		\param data
		\param count

		\~chinese
		?���ݻ?����������
		\param date �?���BYTE��֪���?��
		\param count ?���?��count���ᡣ 

		\~japanese
		��ݻ��?���򫳫�?���ƪ��������
		\param data ����?���ƪ���BYTE��֪�Ϋݫ���?
		\param count count �����򫳫�?���ު���
		\~
		 */
		inline ByteArray(const uint8_t* data, int count):Base(data,count)
		{
		}

		/** 
		\~korean
		�ܺ� �����͸� �����ؿ��� ������
		\param src ������ ByteArray ����

		\~english TODO:translate needed.
		Constructor copies external data
		\param src

		\~chinese
		?���ݻ?����������
		\param src �?���BytesArray��졣

		\~japanese
		��ݻ��?���򫳫�?���ƪ��������
		\param src ����?����ByteArray���
		\~
		 */
		inline ByteArray(const ByteArray &src):Base(src)
		{
		}

		virtual ~ByteArray();

// 		BUG PRONE! ���� ���ƹ��ȴ�.
		/*
						\~korean
						������. ��, �迭 ũ�⸦ �̸� �����Ѵ�.
						\~english
						Constructor. But it must have previously set array size.
						\~
						 */
// 		inline ByteArray(int count):CFastArray<BYTE,true>(count)
// 		{
// 		}

		/** 
		\~korean
		�迭�� 16������ String���� ��ȯ�Ͽ� return���ش�.
		\return String���� ��ȯ�� 16���� �迭 (�� L"FFAB123")

		\~english TODO:translate needed.
		The array is returned by being transformed in a hexadecimal string
		\return Hexadecimal array converted with String (ex: L��FFAB123��)

		\~chinese
		?��֪??��16??��
		??��
		\return String��16??��֪�����ǣ�L��FFAB123����

		\~japanese
		��֪��16��?��String��?������return���ƪ���ު���
		\return String��?�����쪿16��?����֪���ǣ�L"FFAB123")
		\~
		*/
		String ToHexString();

		/**
		\~korean
		16���� �迭 String�� 16������ �ٲپ��ش�.
		\param 16���� �迭 String (�� text = L"FFFFEAB12")
		\return ��ȯ�� �����ϸ� true, �����ϸ� false

		\~english TODO:translate needed.
		A hexadecimal array string is converted into a hexadecimal number
		\param hexadecimal array String (ex. Text = L"FFFFEAB12")
		\return conversion is successful, it is true. If failed, it is false. 	

		\~chinese
		?16??��֪String?��16??��
		\param 16??��֪String ���ǣ�text=L��FFFFEAB12����
		\return ??����?true����??false��

		\~japanese
		16��?����֪String��16��?��?���ƪ���ު���
		\param 16��?����֪String (�ǣ�text = L"FFFFEAB12")
		\return ?�����������true�����������false
		\~
		*/
		bool FromHexString(String text);
	};
	
	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif

