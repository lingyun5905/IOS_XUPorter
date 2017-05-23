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

#include "FastArrayPtr.h"
#include "ByteArray.h"
#include "BiasManagedPointer.h"

#if defined(_MSC_VER)
#pragma warning(disable:4290) // �� ���� VC++������ �߻��ϴ� ����
#endif

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
	ByteArray �� smart pointer ����� �߰��� ����. ��Ʈ��ũ ��Ŷ ���·� ���̹Ƿ� 32-64 ��ȯ���� �ΰ�. ���� intPtr�� �ƴ� int32 Ÿ���̴�.
	ByteArray �� typedef�� �ƴ� ��� Ŭ�����̱� ������ �ʿ��� �޼��带 �� ��ü�� �������̵��ؾ�
	���� ������ ���Ѵ�.

	\~english
	It is the form that smart pointer function has been added to ByteArray. It is very sensitive to conversion from 32 to 64 because of being used as the form of network packet, so its form is int32 (not intPtr).
	To avoid build error, this object has to override require method because ByreArray is inherit class instead of typedef.

	\~chinese
	� ByteArray%��ʥ��smartpointer��������?�����������???��������?��?32-64????������������inPtr���int32?����
	��? ByteArray%����typedef�����??�����?�����۰���������?�����?Build??��

	\~japanese
	ByteArray��smart pointerѦ������ʥ���쪿�������ͫëȫ�?���ѫ��ë��������Ū��ު��Ϊǡ�32-64?���˪�����Ǫ�����êơ�intPtr�ǪϪʪ�int32�����תǪ���
	ByteArray��typedef�ǪϪʪ���?���髹�Ǫ��몿�ᡢ��驪ʫ᫽�ëɪ򪳪Ϋ��֫������Ȫ⫪?��?�髤�ɪ��ƫӫ�ɫ���?�������ު���
	\~
	 */
	class ByteArrayPtr:public BiasManagedPointer<ByteArray, true>
	{
	private:
		// base class�� ��ü�� buffer��, �� external buffer �߿����� �ϳ��� ��ȿ�ϰ�, �������� �� ���°� �ȴ�.
		CArrayWithExternalBuffer<uint8_t, false, true, int> m_externalBuffer;

	public:

		inline ByteArrayPtr() {}

		inline ByteArrayPtr(const ByteArrayPtr& src)
			: BiasManagedPointer<ByteArray, true>(src)
		{
			src.m_externalBuffer.ShareTo(m_externalBuffer);
		}

#ifdef SUPPORTS_CPP11
		// �̵� ������
 		inline ByteArrayPtr(ByteArrayPtr&& src)
 			: BiasManagedPointer<ByteArray, true>(src)
 		{
 			src.m_externalBuffer.ShareTo(m_externalBuffer);
 			src.m_externalBuffer.Uninit();
 		}
#endif
		inline ByteArrayPtr& operator=(const ByteArrayPtr& src)
		{
			// base class
			BiasManagedPointer<ByteArray, true>::operator=(src);

			src.m_externalBuffer.ShareTo(m_externalBuffer);

			return *this;
		}

#ifdef SUPPORTS_CPP11
		// �̵� ������
 		inline ByteArrayPtr& operator=(ByteArrayPtr&& src)
 		{
 			// base class
 			BiasManagedPointer<ByteArray, true>::operator=(src);

 			if (&src != this) // �̵� �����ڴ� �̰� �� üũ�ؾ�.
 			{
 				src.m_externalBuffer.ShareTo(m_externalBuffer);
 				src.m_externalBuffer.Uninit();
 			}

 			return *this;
 		}
#endif

	public:

		inline int GetCapacity() const
		{
			if (GetTombstone())
			{
				return GetTombstone()->m_substance.GetCapacity();
			}
			else if (m_externalBuffer.IsNull())
			{
				ThrowArrayIsNullError();
			}

			return m_externalBuffer.GetCapacity();
		}

		inline int GetCount() const
		{
			if (GetTombstone())
			{
				return GetTombstone()->m_substance.GetCount();
			}
			else if (m_externalBuffer.IsNull())
			{
				ThrowArrayIsNullError();
			}

			return m_externalBuffer.GetCount();
		}

#if defined(_MSC_VER)
		__declspec(property(get = GetCount)) int Count;
#endif

		inline void MustNotNull() const
		{
			if (IsNull())
			{
				ThrowArrayIsNullError();
			}
		}

		inline void MustNull() const throw(Exception)
		{
			if (!IsNull())
				ThrowException(ArrayPtrIsNotNullError);
		}

		/**
		\~korean
		\param length ������ Capacity ������

		\~english TODO:translate needed.
		\param length Capacity size to change the length

		\~chinese
		\param length �??��Capacity��᳡�

		\~japanese
		\param length ?�ڪ���Capacity������ 
		\~
		*/
		inline void SetCapacity(int length)
		{
			if(length < 0)
				ThrowInvalidArgumentException();

			if (!m_externalBuffer.IsNull())
			{
				// �ƹ��͵� ����
			}
			else
			{
				if (GetTombstone() != NULL)
					GetTombstone()->m_substance.SetCapacity(length);
			}
		}

		/**
		\~korean
		�迭�� ����� setting �Ѵ�.
		\param length ������ �迭�� ������

		\~english TODO:translate needed.
		Set the size of the array
		\param length Size of the array to change the length

		\~chinese
		Setting ��֪����᳡�
		\param length �??����֪����᳡�

		\~japanese
		��֪�Ϋ����������Ҫ��롣
		\param length ?�ڪ�����֪�Ϋ�����
		\~
		*/
		inline void SetCount(int length)
		{
			if(length < 0)
				ThrowInvalidArgumentException();

			if (!m_externalBuffer.IsNull())
			{
				m_externalBuffer.SetCount(length);
			}
			else
			{
				if(length > 0)
				{
					if(GetTombstone())
						GetTombstone()->m_substance.SetCount(length);
					else
					{
						ThrowArrayIsNullError();
					}
				}
				else
				{
					if(GetTombstone())
						GetTombstone()->m_substance.SetCount(0);
				}
			}
		}


		inline void AddCount(int length)
		{
			// CMessage.Write�� ���� ȣ��󵵰� ���Ƽ�, ���� ����ȭ�� �Ǿ� �ִ�.
			if (!m_externalBuffer.IsNull())
			{
				m_externalBuffer.AddCount(length);
			}
			else
			{
				if (length > 0) // ũ�� �ø��� ������ �׳� �����ϰ� �Ѿ��.
				{
					if (GetTombstone())
						GetTombstone()->m_substance.AddCount(length);
					else
					{
						ThrowArrayIsNullError();
					}
				}
			}

		}

		/**
		\~korean
		1 BYTE ������ Data�� �߰��մϴ�.
		\param data �߰��� BYTE

		\~english TODO:translate needed.
		Add data in 1 byte unit
		\param data Byte to add data

		\~chinese
		��ʥ1BYTE?����Data��
		\param data ���ʥ��BYTE��

		\~japanese
		1�Ы���?�ȪΫ�?������ʥ���ު���
		\param data ��ʥ����Ы��� 
		\~
		*/
		inline void Add(uint8_t data)
		{
			AddRange(&data, 1);
		}

		/**
		\~korean
		������ �迭�� BYTE�迭 data�� �߰� �մϴ�.
		\param data �߰��� BYTE�迭 ������
		\param count �迭�� ũ��

		\~english TODO:translate needed.
		Add byte array data to the current array
		\param data Byte array pointer to add data
		\param count Size of the count array

		\~chinese
		�?������֪߾��ʥBYTE��֪data��
		\param data ���ʥ��BYTE��֪�?��
		\param count ��֪����᳡�

		\~japanese
		�����֪�˫Ы�����֪��?������ʥ���ު���
		\param data ��ʥ����BYTE��֪�ݫ���?
		\param count ��֪�Ϋ�����
		\~
		*/
		inline void AddRange(const uint8_t* data, int count)
		{
			// InsertRange���� AddRange�ٷ� ���� �� ����
			if (m_externalBuffer.IsNull() == false)
			{
				m_externalBuffer.AddRange(data, count);
			}
			else
			{
				if(GetTombstone())
				{
					GetTombstone()->m_substance.AddRange(data, count);
				}
				else
				{
					ThrowArrayIsNullError();
				}
			}
		}

		/*
		\~korean
		������ �迭�� BYTE�迭 data�� �߰� �մϴ�.
		\param indexAt �迭������ indexAt��°�ڿ� �����մϴ�. ������ indexAt���� �����ʹ� ���Ե� ������ �ڷ� �и��ϴ�.
		\param data �߰��� BYTE�迭 ������
		\param count �迭�� ũ��

		\~english TODO:translate needed.
		Add byte array data to the current array
		\Insert after (indexAt) th within the indexAt array. The data after the original indexAt is moved back to the inserted data.
		\param data Byte array pointer to add data
		\param count Size of the count array

		\~chinese
		�?������֪߾��ʥBYTE��֪data��
		\param indexAt ���֪����indexAt��?���������indexAt����?��??����?����?��������
		\param data ���ʥ��BYTE��֪�?��
		\param count ��֪����᳡�

		\~japanese
		�����֪�˫Ы�����֪��?������ʥ���ު���
		\param indexAt ��֪?��indexAt���ͪ�����?�����ު�����?��indexAt�����Ϋ�?����?�����쪿��?�������˪��骵��ު���
		\param data ��ʥ����Ы�����֪�ݫ���? 
		\param count ��֪�Ϋ����� 
		\~
		*/
		inline void InsertRange(int indexAt, const uint8_t* data, int count)
		{
			if (m_externalBuffer.IsNull() == false)
			{
				m_externalBuffer.InsertRange(indexAt, data, count);
			}
			else
			{
				if(GetTombstone())
					GetTombstone()->m_substance.InsertRange(indexAt, data, count);
				else
				{
					ThrowArrayIsNullError();
				}
			}
		}

		/**
		\~korean
		�����͵��� ���� �մϴ�.
		\param indexAt ������ data�� index�Դϴ�.
		\param count ������ �迭�� �� �Դϴ�.

		\~english TODO:translate needed.
		Remove data
		\param indexAt Index of the removed data
		\param count Number of the array to be removed


		\~chinese
		?�Data��
		\param indexAt ��?���Data index��
		\param count  �?�����֪?��

		\~japanese
		��?������۪��ު���
		\param indexAt ��۪�����?����index�Ǫ���
		\param count ��۪�����֪��?�Ǫ���
		\~
		*/
		inline void RemoveRange(int indexAt, int count)
		{
			if (m_externalBuffer.IsNull() == false)
			{
				m_externalBuffer.RemoveRange(indexAt, count);
			}
			else
			{
				if(GetTombstone())
					GetTombstone()->m_substance.RemoveRange(indexAt, count);
				else
				{
					ThrowArrayIsNullError();
				}
			}
		}

		/**
		\~korean
		�迭���� �ϳ��� �����͸� �����մϴ�.
		\param index ������ �迭�� index��

		\~english TODO:translate needed.
		Remove one datum within the array
		\param index Index value of the array to be removed


		\~chinese
		?���֪������?Data��
		\param index �?�����֪��index?��

		\~japanese
		��֪?����ĪΫ�?������۪��ު���
		\param index ��۪�����֪��index��
		\~
		*/
		inline void RemoveAt(int index)
		{
			RemoveRange(index, 1);
		}

		/**
		\~korean
		�迭�� ���ϴ�. capacity�� ��ȭ���� �ʽ��ϴ�.

		\~english 
		Empty the array. The capacity does not change

		\~chinese
		?����֪��Capacity ��??��

		\~japanese
		��֪�����˪��ު���Capacity��?�����ު���
		\~
		*/
		inline void Clear()
		{
			SetCount(0);
			// capacity�� �״�� �ξ�� ��. �ȱ׷��� ������ �������� ũ�� ���ϵȴ�!
		}

		/**
		\~korean
		\return Data�迭�� �����͸� �����մϴ�.

		\~english 
		\return the pointer of the data array.

		\~chinese
		\return return Data��֪���?��

		\~japanese
		\return Data��֪�Ϋݫ���?��꫿?�󪷪ު���
		\~
		*/
		inline uint8_t* GetData()
		{
			if (!m_externalBuffer.IsNull())
			{
				return m_externalBuffer.GetData();
			}
			else if (GetTombstone() == NULL)
			{
				ThrowArrayIsNullError();
			}

			return GetTombstone()->m_substance.GetData();
		}

		/**
		\~korean
		\return Data�迭�� const �����͸� �����մϴ�.

		\~english TODO:translate needed.
		\return the const pointer of the data array. 

		\~chinese
		\return return Data��֪��const�?��

		\~japanese
		\return Data��֪��const�ݫ���?��꫿?�󪷪ު���
		\~
		*/
		inline const uint8_t* GetData() const
		{
			if (m_externalBuffer.IsNull() == false)
				return m_externalBuffer.GetData();
			else if (GetTombstone() == NULL)
			{
				ThrowArrayIsNullError();
			}

			return GetTombstone()->m_substance.GetData();
		}

		/**
		\~korean
		\return �迭�� ���纻�� �����մϴ�.

		\~english TODO:translate needed.
		\return the copy of the array

		\~chinese
		\return  return��֪��?�⡣

		\~japanese
		\return ��֪�Ϋ���?��꫿?�󪷪ު���
		\~
		*/
		inline ByteArrayPtr Clone()
		{
			if(!m_externalBuffer.IsNull())
				ThrowException(MustNotExternalBufferError);

			ByteArrayPtr ret;

			if(GetTombstone())
			{
				ret.UseInternalBuffer();
				ret.SetCount(GetCount());
			}
			CopyRangeTo(ret, 0, GetCount());

			return ret;
		}

		/**
		\~korean
		�����͵��� dest�� ������
		\param dest ������� ��ü
		\param srcOffset ���縦 ������ ���� �迭�� ��ġ
		\param count ���� ���� �迭�� ũ��

		\~english TODO:translate needed.
		copy data to dest
		\param dest object to be copied 
		\param srcOffset Location of the original array to start copying
		\param count Size of the array to be copied 

		\~chinese
		??��?���dest��
		\param dest  ����?�����?��
		\param srcOffset  �?�?����������֪���ǡ�
		\param count ����?�����֪����᳡�

		\~japanese
		��?����dest�ث���?���ު���
		\param dest ����?���ƪ�骦���֫�������
		\param srcOffset ����?����㷪��������֪������
		\param count ����?���ƪ�骦��֪�Ϋ�����
		\~
		*/
		template<typename BYTEARRAYT>
		inline void CopyRangeToT(BYTEARRAYT &dest, int srcOffset, int count) const
		{
			if (count <= 0)
				return;

			if (dest.GetCount() < srcOffset + count)
				ThrowArrayOutOfBoundException();

			if (!GetData() || !dest.GetData())
				ThrowInvalidArgumentException();

			UnsafeFastMemmove(dest.GetData(), GetData() + srcOffset, count * sizeof(uint8_t));
		}

		/**
		\~korean
		�����͵��� dest�� ������
		\param dest ������� ByteArrayPtr
		\param srcOffset ���縦 ������ ���� �迭�� ��ġ
		\param count ���� ���� �迭�� ũ��

		\~english TODO:translate needed.
		copy data to dest
		\param dest ByteArrayPtr to be copied
		\param srcOffset Location of the original array to start copying
		\param count Size of the array to be copied

		\~chinese
		??��?���dest��
		\param dest ����?��� ByteArrayPtr
		\param srcOffset �?�?��������֪�����ǡ�
		\param count ����?�����֪����᳡�

		\~japanese
		��?����dest�ث���?���ު���
		\param dest ����?���ƪ�骦ByteArrayPtr
		\param srcOffset ����?����㷪��������֪������
		\param count ����?���ƪ�骦��֪�Ϋ�����
		\~
		*/
		void CopyRangeTo(ByteArrayPtr &dest, int srcOffset, int count) const
		{
			CopyRangeToT<ByteArrayPtr>(dest,srcOffset,count);
		}

		/**
		\~korean
		�����͵��� dest�� ������
		\param dest ������� ByteArray
		\param srcOffset ���縦 ������ ���� �迭�� ��ġ
		\param count ���� ���� �迭�� ũ��

		\~english TODO:translate needed.
		copy data to dest
		\param dest ByteArray to be copied
		\param srcOffset Location of the original array to start copying
		\param count Size of the array to be copied


		\~chinese
		??��?���dest��
		\param dest �����?��� ByteArray
		\param srcOffset �?�?����������֪���ǡ�
		\param count �����?�����֪����᳡�

		\~japanese
		��?����dest�ث���?���ު���
		\param dest ����?���ƪ�骦ByteArray
		\param srcOffset ����?����㷪��������֪������
		\param count ����?���ƪ�骦��֪�Ϋ�����
		\~
		*/
		void CopyRangeTo(ByteArray& dest, int srcOffset, int count) const
		{
			CopyRangeToT<ByteArray>(dest,srcOffset,count);
		}

		inline uint8_t& operator[](int index)
		{
			if (m_externalBuffer.IsNull()==false)
				return m_externalBuffer[index];
			else
			{
				if(GetTombstone())
					return GetTombstone()->m_substance.operator[](index);
				else
				{
					// UE4������ throw Ű���带 �� ����. ���� �̷��� �Լ��� �����Ͽ� throw Ű���带 ������Ų��.
					ThrowArrayIsNullError();
					return m_externalBuffer[0]; // unreachable code. just preventing 'Control may reach end of non-void function' warning
				}
			}
		}

		inline const uint8_t operator[](int index) const
		{
			if (m_externalBuffer.IsNull() == false)
				return m_externalBuffer[index];
			else
			{
				if (GetTombstone())
					return GetTombstone()->m_substance.operator[](index);
				else
				{
					// UE4������ throw Ű���带 �� ����. ���� �̷��� �Լ��� �����Ͽ� throw Ű���带 ������Ų��.
					ThrowArrayIsNullError();
					return m_externalBuffer[0]; // unreachable code. just preventing 'Control may reach end of non-void function' warning
				}
			}
		}


		/**
		\~korean
		\return �� ��ü�� �迭 ũ�Ⱑ ������ �� ����ġ Ÿ��

		\~english 
		\return Weighted value when the array size of this object increases. 

		\~chinese
		\return ?���?����֪�����ʥ?��ʥ��??����

		\~japanese
		\return ���Ϋ��֫������Ȫ���֪��������?ʥ��������ʥ����������
		\~
		*/
		inline GrowPolicy GetGrowPolicy() const
		{
			if (GetTombstone() != NULL)
				GetTombstone()->m_substance.GetGrowPolicy();

			return GrowPolicy_Normal;
		}

		/**
		\~korean
		�� ��ü�� �迭 ũ�Ⱑ ������ �� ����ġ Ÿ���� �����Ѵ�.
		�ڼ��� ������ GrowPolicy �� ����
		\param val ������ ���� ����ġ Ÿ��

		\~english TODO:translate needed.
		The weighted value type is set when the array size of this object increases. 
		For more details, refer to GrowPolicy
		\param val The weighted value type when increasing

		\~chinese
		?�����?����֪�����ʥ?��ʥ��?��
		???�?��GrowPolicy��
		\param val ��ʥ?��ʥ��?��?����

		\~japanese
		���Ϋ��֫������Ȫ���֪��������?ʥ��������ʥ���������ת����Ҫ��ު���
		�٪����ϡ�GrowPolicy ��?�Ϊ���������
		\param val ?ʥ��������ʥ���������� 
		\~
		*/
		void SetGrowPolicy(GrowPolicy val)
		{
			if (GetTombstone() != NULL)
				GetTombstone()->m_substance.SetGrowPolicy(val);
			else
			{
				// none
			}
		}

		/**
		\~korean
		�ּ� ���� ũ�⸦ �����Ѵ�. ����(capacity)ũ�Ⱑ ������ �� �ּ��� �� ������� ũ�� �����Ѵ�.
		\param val �ּ� Capacity size

		\~english TODO:translate needed.
		Set the minimum buffer size. When the buffer (capacity) size increases, set it at least bigger than this size. 
		\param val Minimum capacity size

		\~chinese
		?�����buffer����᳡�?Buffer��Capacity�������ʥ?���?��������������?��
		\param val ���Capacity size

		\~japanese
		��ᳫЫëի�?�����������Ҫ��ު����Ыëի�?(capacity)��������?ʥ��������ᴪʪ��Ȫ⪳�Ϋ���������ު������Ҫ��ު��� 
		\param val ��� Capacity size 
		\~
		*/
		void SetMinCapacity(int val)
		{
			if(GetTombstone())
				GetTombstone()->m_substance.SetMinCapacity(val);
			else
			{
				// none
			}
		}

		/**
		\~korean
		�̰��� �ʱ⿡ ȣ���ϸ� ���� ���۸� �����Ͽ� ����Ѵ�.

		\~english TODO:translate needed.
		If you call this at the initial stage, generate and use an internal buffer

		\~chinese
		���Ѣ����??��?����?����?ݻBuffer��

		\~japanese
		�������Ѣ�������󪹪�?ݻ�Ыëի�?�����������Ū��ު���
		\~
		*/
		inline void UseInternalBuffer()
		{
			if(!m_externalBuffer.IsNull())
				ThrowException(AlreadyHasExternalBufferError);

			InitTombstoneIfEmpty();

		}

		/**
		\~korean
		�̰� �ʱ⿡ ȣ���ϸ� �� ��ü�� �ܺ� ���۸� ����Ѵ�.

		\~english
		If you call this at the beginning, this object use external buffer

		\~chinese
		���Ѣ����??�����??������ݻBuffer��

		\~japanese
		�������Ѣ�������󪹪�?ݻ�Ыëի�?�����������Ū��ު���
		\~
		*/
		inline void UseExternalBuffer(uint8_t* buf, int capacity)
		{
			if (GetTombstone() != NULL)
				ThrowException(AlreadyHasInternalBufferError);
			else if (m_externalBuffer.IsNull() == false)
				ThrowException(AlreadyHasExternalBufferError);

			m_externalBuffer.Init(buf, capacity);
		}

		/**
		\~korean
		UseInternalBuffer, UseExternalBuffer �� �����Ϸ��� �� �޼��带 ȣ���� ��.

		\~english
		Call this method if you want to reuse UseInternalBuffer,UseExternalBuffer

		\~chinese
		������������UseInternalBuffer , UseExternalBuffer �� �����۰����

		\~japanese
		UseInternalBuffer, UseExternalBuffer������Ī��몿��˪Ϫ��Ϋ᫽�ëɪ������󪹪��ȡ�
		\~
		*/
		void UninitBuffer()
		{
			UninitTombstone();
			m_externalBuffer.Uninit();
		}

		/**
		\~korean
		\return NULL�̸� true, NULL�� �ƴϸ� false�� �����Ѵ�.

		\~english TODO:translate needed.
		\return true if null, otherwise return false.

		\~chinese
		\return  NULL��?true,����NULL��?return false��

		\~japanese
		\return NULL�Ǫ����true��NULL�ǪϪʪ����false��꫿?�󪷪ު��� 
		\~
		*/
		inline bool IsNull() const
		{
			return (GetTombstone() == NULL && m_externalBuffer.IsNull());
		}

// 		inline ByteArray& GetInternalBufferRef()
// 		{
// 			MustInternalBuffer();
// 			return *m_tombstone;
// 		}

		/**
		\~korean
		���� ���۸� ����ϰ� �ִ� ���� �ƴϸ� ���ܸ� �߻���Ų��.

		\~english TODO:translate needed.
		Generate an exception if an internal buffer is not being used.

		\~chinese
		������������?ݻBuffer�������������⡣

		\~japanese
		?ݻ�Ыëի�?���Ūêƪ���ΪǪϪʪ���������?�檵���ު���
		\~
		*/
		inline void MustInternalBuffer()
		{
			if (GetTombstone() == NULL)
			{
				ThrowException(MustInternalBufferError);
			}
		}

		/**
		\~korean
		rhs�� ������ �������� üũ�Ѵ�.
		- ����: �ܼ� �޸� �񱳴�. �� ���� ������ ��.
		\param rhs ���� ByteArrayPtr
		\return ������ true �ٸ��� false�� �����Ѵ�.

		\~english TODO:translate needed.
		 Check to see if the content is the same as rhs
		- Caution: this is a simple comparison of memory. Use caution.
		\param rhs ByteArrayPtr to be compared
		\return true if the same, otherwise return false

		\~chinese
		??����?rhs��?����ȡ�
		- �������??��?����?������?���á�
		\param rhs ���?�� ByteArrayPtr
		\return ������?��?true����?return false��

		\~japanese
		Rhs��?黪��Ҫ��ʪΪ�������ë����ު���
		- �����?�����?����Ǫ�������˪���򪯪�������
		\param rhs ���򪹪� ByteArrayPtr
		\return �Ҫ��Ǫ����true��춪ʪ��false��꫿?�󪷪ު���
		\~
		*/
		inline bool Equals(const ByteArrayPtr &rhs) const
		{
			if (rhs.GetCount() != GetCount())
				return false;

			// �ܼ� �޸� �񱳴�.
			const uint8_t* p_rhs = (uint8_t*)rhs.GetData();
			const uint8_t* p_lhs = (uint8_t*)GetData();
			return memcmp(p_rhs, p_lhs, rhs.GetCount() * sizeof(uint8_t)) == 0;
		}


	};

	//////////////////////////////////////////////////////////////////////////
	// UE4 x86 or x64���� link error�� ����. ���� �Ұ����ϰ� �̷��� �� ���ø� ������ �Լ��� ȣ���ϵ��� ������.
	// #UE4_PATCH
	// TODO: ���׷��̵� ������ �ϴٰ�, ������ �Ʒ� �ڵ尡 �ݺ��� �� ������ ��ũ��ȭ�Ͽ� ��ȸ�ϵ��� ����.

	void* ByteArrayPtr_AllocTombstone();
	void ByteArrayPtr_FreeTombstone(void* tombstone);

	template<>
	inline BiasManagedPointer<ByteArray, true>::Tombstone* BiasManagedPointer<ByteArray, true>::AllocTombstone()
	{
		return (BiasManagedPointer<ByteArray, true>::Tombstone*)ByteArrayPtr_AllocTombstone();
	}

	template<>
	inline void BiasManagedPointer<ByteArray, true>::FreeTombstone(BiasManagedPointer<ByteArray, true>::Tombstone* tombstone)
	{
		return ByteArrayPtr_FreeTombstone((void*)tombstone);
	}


	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif