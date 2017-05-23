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

#if defined(_WIN32)
//#include <string>
#endif
#include <string>
#include "FastArray.h"
#include "FastArrayPtr.h"
#include "AddrPort.h"
#include "EncryptEnum.h"
#include "FakeClr.h"
#include "HostIDArray.h"
#include "NetConfig.h"
#include "Enums.h"
#include "BasicTypes.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif
	/** \addtogroup net_group
	*  @{
	*/
	class CMessage;
	struct AddrPort;

#ifdef _MSC_VER
	//////////////////////////////////////////////////////////////////////////
	// �Ʒ� enum���� CMessage.Read or Write()���� ����� �� ���� �ϱ� ����, ������ ���� �ϰ� �ִ�.
	// 1. ���� ����
	// 2. Write(),Read()�� private���� �����Ͽ�, ����� �� ���� �ϱ�.
	// ��, ���� ������ VC++ ���� C++11���� �� ���Ƿ�, VC++ �������θ� Ȱ��ȭ�Ѵ�.
	enum MessageType;
	enum MessagePriority;
	enum DirectP2PStartCondition;
	enum FallbackMethod;
	enum EncryptMode;
	enum ReliableUdpFrameType;
	enum _LocalEventType;
	enum _RmiID;

#define DECLARE_READ_AND_WRITE(TYPE) void Write(TYPE); bool Read(TYPE&);
#endif


	/** 
	\~korean
	�޽��� Ŭ����. �ڼ��� ������ <a target="_blank" href="http://guide.nettention.com/cpp_ko#message_class" >�޽��� ��ü(Proud.CMessage)</a>�� ����.

	\~english 
	Message class. For detailed information, refer to \ref message_class

	\~chinese
	����?��????��<a target="_blank" href="http://guide.nettention.com/cpp_zh#message_class" >������?(Proud.CMessage)</a>%��

	\~japanese
	��ë�?�����髹���٪����ϡ�\ref message_class��?�Ϊ���������
	\~
	*/
	class CMessage
	{
		// ���� �б� Ŀ�� ��ġ. ����Ʈ�� �ƴ϶� ��Ʈ��!
		int m_readBitOffset;
		// ��ϵǾ� �ִ� �� ������ ũ�� ��, �� ������ ����Ʈ �� ���° ��Ʈ���� ��ϵǾ��ִ����� ����Ų��. 
		// ��Ʈ���� write�� �� �� �����Ѵ�.
		int m_bitLengthInOneByte; 

		// �� ���� true�̸� read/write scalar�� ��Ȱ���Ǿ� ������ int64�� ����Ǵ� ��,
		// ��Ŷ ������ ����ڰ� �� �� �ֵ��� �ܼ�ȭ�ǵ� �ʿ��� ȿ������ ��ɵ��� �������.
		bool m_isSimplePacketMode;
	public:
		inline bool IsSimplePacketMode() const { return m_isSimplePacketMode; }
	private:
		friend void AdjustReadOffsetByteAlign(CMessage& msg);
		friend void AssureReadOffsetByteAlign(CMessage& msg);

		static void ThrowOnWrongLength(const char* where, int length, int maxLength);
	public:
		

		template<typename T, bool RAWTYPE, typename COLLT>
		static inline bool ReadArrayT(CMessage &a, COLLT &b)
		{
			int length;
			if (a.ReadScalar(length) == false)
				return false;
			
			// count�� ��ŷ�Ǿ� ���� �ȵǴ� ���̸� ���� ó���ϱ�
			// ���� ��� ��츦 ������ �������� (sizeof elem ��������) �׷��� �ּ� 1����Ʈ�� ���״�.
			if (length < 0 || length > a.GetLength() - a.GetReadOffset())
				return false;

			b.SetCount(length);

			if(RAWTYPE)
			{
				return a.Read((uint8_t*)b.GetData(), sizeof(T) * length);
			}
			else 
			{
				for (int i = 0; i < length; i++)
				{
					if (a.Read(b[i]) == false)
						return false;
				}
				return true;
			}
		}

		template<typename T, bool RAWTYPE, typename COLLT>
		static inline void WriteArrayT(CMessage &a, const COLLT &b)
		{
			int length = (int)b.GetCount();
			a.WriteScalar(length);

			if(RAWTYPE)
				a.Write((uint8_t*)b.GetData(), sizeof(T) * length);
			else
			{
				for (int i = 0; i < length; i++)
					a.Write(b[i]);
			}
		}

	public:
		ByteArrayPtr m_msgBuffer;

		inline CMessage();
		inline CMessage(const CMessage &src);

		inline bool DataEquals(const CMessage& rhs)
		{
			return m_msgBuffer.Equals(rhs.m_msgBuffer);
		}
		/** 
		\~korean
		�޽����κ��� �����͸� �д´�.
		\param data ���� �����Ͱ� ����� ��
		\param count data�� ����Ʈ ���� ũ�� 
		\return count��ŭ ���������� �о����� true.

		\~english 
		Read data from the message. 
		\param data Where the read data will be stored. 
		\param count Byte unit size of the data
		\return True if successfully read as the count


		\~chinese
		?����?��?�ߡ�
		\param data �?����?��?�������ǡ�
		\param count data��byte?����᳡� 
		\return ?��������?true��

		\~japanese
		��ë�?�������?����?������ު���
		\param data?�����ê���?�����������ᶪǪ���
		\param count data�ΫЫ���?�ȪΫ�����
		\return count����?�����몳�Ȫ���������true�Ǫ���
		\~
		*/
		inline  bool Read( uint8_t* data, int count );

		template<typename POD>
		inline  bool Read_POD(POD* data);

		inline  bool CanRead( int count );
		
		/** 
		\~korean
		�޽����� �����͸� ����Ѵ�.

		\~english 
		Record data in the message
		

		\~chinese
		??����?�ߡ�

		\~japanese
		��ë�?���˫�?������?���ު���
		\~
		*/
		inline void Write(const uint8_t* data, int count)
		{
			// �ƿ� ���� ������ splitter test ��ü�� ������.
			if (count == 0)
				return;

			AdjustWriteOffsetByteAlign();

			Write_NoTestSplitter(data, count);

#ifdef _DEBUG
			WriteTestSplitterOnCase();
#endif
		}

		template<typename POD>
		inline void Write_POD(const POD* data)
		{
			AdjustWriteOffsetByteAlign();

			Write_NoTestSplitter_POD<POD>(data);
#ifdef _DEBUG
			WriteTestSplitterOnCase();
#endif
		}

		inline  void CopyFromArrayAndResetReadOffset(const uint8_t* src, int srcLength);
		//PROUD_API void ResetWritePointer();

		/** 
		\~korean
		�б� ������ ���� �����Ѵ�. ����Ʈ �����̴�.

		\~english 
		Read point is forcibly adjusted. It is in bytes. 

		\~chinese
		˭�?��?����á�Byte ?�ȡ�

		\~japanese
		?��������ê�?�����ڪ��ު����Ы���?�ȪǪ���
		\~
		*/
		inline  void SetReadOffset(int offset);

		// ����ڴ� �� �Լ��� ȣ������ �� ��
		inline  void SetSimplePacketMode(bool isSimplePacketMode);

		/** 
		\~korean
		�޽����� ���� ũ�⸦ �����Ѵ�.

		\~english 
		Set the current size of the message. 

		\~chinese
		?������?�����᳡�

		\~japanese
		��ë�?����������������Ҫ��ު���
		\~
		*/
		inline  void SetLength(int count);
		inline   int GetWriteOffset();

		//////////////////////////////////////////////////////////////////////////
		// Test splitter ���
		// ���ɿ� �ΰ��ϹǷ�, release build������ ���ŵǾ� ����.
#ifdef _DEBUG
		inline  void EnableTestSplitter(bool enable);
		inline  bool IsTestSplitterEnabled() {
			return m_enableTestSplitter;
		}
	private:
		bool m_enableTestSplitter;
		enum { Splitter = 254 };

		inline void ReadAndCheckTestSplitterOnCase();
		inline void WriteTestSplitterOnCase()
		{
			if (m_enableTestSplitter)
			{
				uint8_t s = Splitter;
				Write_NoTestSplitter(&s, sizeof(s));
			}
		}
#endif

		//////////////////////////////////////////////////////////////////////////

		inline  bool Read_NoTestSplitter(uint8_t* data, int count);

		template<typename POD>
		inline  bool Read_NoTestSplitter_POD(POD* data);

		inline  bool CanRead_NoTestSplitter(int count);
		inline void Write_NoTestSplitter( const uint8_t* data, int count )
		{
			m_msgBuffer.MustNotNull();

			m_msgBuffer.AddRange(data, count);
		}

		template<typename POD>
		inline void Write_NoTestSplitter_POD(const POD* data)
		{
			int oldLength = m_msgBuffer.GetCount();
			m_msgBuffer.AddCount(sizeof(POD)); // ũ�⸦ �ø���
#if defined(__MARMALADE__) || defined(__ANDROID__) || defined(__arm__) // RVCT�� ���� ��� __packed keyword�� ���� ������ gcc�� ���Ƿ� 
			// ARM������ 4byte align�� �ƴ� �����Ϳ� �ٷ� = �� ���� ũ���ð� ����. 
			// ���� memcpy�� ���־�� �Ѵ�. ���������� non-4byte align�� ó���ϱ� �����̴�.
			// ���� ������. ������ ����� Ŭ���̾�Ʈ�� �̰ɷ� ���������� �ʴ´�.
			memcpy(m_msgBuffer.GetData() + oldLength, data, sizeof(POD));
#else
			// x86 �迭������ �ϱ� ��ɾ non 4byte align�̶� �� �۵��Ѵ�. ������ �׷���.
			*((POD*)(m_msgBuffer.GetData() + oldLength)) = *data; // ����
#endif
		}

		inline void AdjustWriteOffsetByteAlign()
		{
			// ��Ʈ ���� ����� �ϴ� ���̶� ���� ����Ʈ�� byte align�� �ƴϸ�, �����Ѵ�.
			// ��, �̰��� ȣ�� �Ŀ��� �ݵ�� �ּ� 1 ����Ʈ�� ����ؾ� �Ѵ�. �ȱ׷��� ����ϴ� ��Ʈ���� ���ǵȴ�.
			m_bitLengthInOneByte = 0;
		}

	public:
		/** 
		\~korean
		�� ��ü�� �޸� ���۸� output�� length ũ�⸸ŭ �о�� ������� �����,
		output�� �ܺημ� �� ��ü�� ���۸� �����ϵ��� �����. 
		������ ���� ���Ǵ� �Լ���.

		\~english 
		Make the memory buffer of this object as if the output reads as much as the size of the length, the output should be made to refer the buffer of this object. 
		This is the function used for performance.

		\~chinese
		���?����?��buffer�����output?����?��length�����������ӣ��output��?��ݻ�����?���?����buffer��
		?��������������?��

		\~japanese
		���Ϋ��֫������ȪΫ���?�Ыëի�?��output��length����������?������誦���ª몬��output����ݻ�Ȫ��ƪ��Ϋ��֫������ȪΫЫëի�?��?�Ϊ���誦���ª�ު���
		�����Ϊ�����Ū���??�Ǫ���
		\~
		*/
		inline  bool ReadWithShareBuffer(CMessage& output, int length);

		/** 
		\~korean
		�޽��� ��ü�� �����͸� �߰� ����Ѵ�.
		bool Ÿ�� �Ӹ� �ƴ϶� �پ��� Ÿ���� �����Ѵ�.

		\~english 
		Additionally record the data in the message object. 
		It supports not only Boolean type but also various types. 

		\~chinese
		������?����ʥ???�ߡ�
		������bool?����?����??����

		\~japanese
		��ë�?�����֫������Ȫ˫�?������ʥ��?���ު���
		Bool�����ת����ǪϪʪ�����?�ʫ����ת򫵫�?�Ȫ��ު���
		\~
		*/
		inline void Write(bool b) {
			Write_POD<bool>(&b);
		}
		inline void Write(int8_t b) {
			Write_POD<int8_t>(&b);
		}
		inline void Write(uint8_t b) {
			Write_POD<uint8_t>(&b);
		}
		inline void Write(int16_t b) {
			Write_POD<int16_t>(&b);
		}
		inline void Write(uint16_t b) {
			Write_POD<uint16_t>(&b);
		}
		inline void Write(int32_t b) {
			Write_POD<int32_t>(&b);
		}
		inline void Write(uint32_t b) {
			Write_POD<uint32_t>(&b);
		}
		/* Q: �� long type�� ���ؼ��� Write & Read�� ������?
		A: long, unsigned long�� ��� �����Ϸ����� ũ�Ⱑ ���� �ٸ��ϴ�. 
		VC++ x64������ 32bit������, �ٸ� �����Ϸ� �� �ϳ��� x64���� 64bit�� ó���˴ϴ�.
		�̷��� ��Ʈ��ũ�� �ְ�޴� ������ Ÿ������ �������Դϴ�.
		��� int64_t, uint64_t�� ���ñ� �ٶ��ϴ�. �ƴϸ� (unsigned)int or (u)int32_t�� ���ô���.
		*/
		inline void Write(int64_t b) {
			Write_POD<int64_t>(&b);
		}
		inline void Write(uint64_t b) {
			Write_POD<uint64_t>(&b);
		}
		inline void Write(float b) {
			Write_POD<float>(&b);
		}
		inline void Write(double b) {
			Write_POD<double>(&b);
		}
		inline void Write(HostID b) {
			Write_POD<HostID>(&b);
		}

		inline  void Write(const AddrPort &b);
		inline  bool Read(AddrPort &b);
		
		bool Read(ByteArray &b)
		{
			return ReadArrayT<uint8_t, true, ByteArray>(*this,b);
		}
		void Write(const ByteArray &b)
		{
			WriteArrayT<uint8_t,true,ByteArray>(*this,b);
		}

		void Write(ByteArrayPtr b)
		{
			// b�� buffer usage�� �̸� �����߾�� ��
			WriteArrayT<uint8_t,true,ByteArrayPtr>(*this,b);
		}

		bool Read(ByteArrayPtr &b)
		{
			// b�� buffer usage�� �̸� �����߾�� ��
			return ReadArrayT<uint8_t, true, ByteArrayPtr>(*this,b);
		}


		/** 
		\~korean
		scalar compression ������� ���� �д´�.

		\~english
		Reads with scalar compression technique

		\~chinese
		��scalar compression��??��?��

		\~japanese
		scalar compression ����������?������ު���
		\~
		 */
		inline  bool ReadScalar(int64_t &a);
		inline  bool ReadScalar(int32_t &a);
		inline  bool ReadScalar(int16_t &a);
		inline  bool ReadScalar(int8_t &a);
		inline  bool ReadScalar(uint64_t &a) { return ReadScalar((int64_t&)a); }
		inline  bool ReadScalar(uint32_t &a) { return ReadScalar((int32_t&)a); }
		inline  bool ReadScalar(uint16_t &a) { return ReadScalar((int16_t&)a); }
		inline  bool ReadScalar(uint8_t &a) { return ReadScalar((int8_t&)a); }

		/** 
		\~korean
		scalar compression ������� ���� ����Ѵ�. 

		\~english
		Writes with scalar compression technique

		\~chinese
		��scalar compression��????��

		\~japanese
		scalar compression ������������?���ު��� 
		\~
		*/
		inline  void WriteScalar(int64_t a);
		inline  void WriteScalar(int32_t a);
		inline  void WriteScalar(int16_t a);
		inline  void WriteScalar(int8_t a);
		inline  void WriteScalar(uint64_t a) { WriteScalar((int64_t)a); }
		inline  void WriteScalar(uint32_t a) { WriteScalar((int32_t)a); }
		inline  void WriteScalar(uint16_t a) { WriteScalar((int16_t)a); }
		inline  void WriteScalar(uint8_t a) { WriteScalar((int8_t)a); }

		//bool Read(out CFastArray<BYTE> b)
		//{
		//	b = new CFastArray<BYTE>();
		//	int length;
		//	if (Read(out length) == false)
		//		return false;

		//	for (int i = 0; i < length; i++)
		//	{
		//		BYTE p = 0;
		//		if (Read(out p) == false)
		//			return false;
		//		b.Add(p);
		//	}

		//	return true;
		//}

		//void Write(CFastArray<BYTE> b)
		//{
		//	int length = b.GetCount();
		//	Write(length);
		//	for (int i = 0; i < length; i++)
		//	{
		//		Write(b[i]);
		//	}
		//}

		//PROUD_API bool ReadFrameNumberArray(CFastArrayPtr<int,true> &b);
		//PROUD_API void WriteFrameNumberArray(const int* arr, int count);

		/** 
		\~korean
		�޽��� ��ü�� �����͸� �߰� ����Ѵ�.
		bool Ÿ�� �Ӹ� �ƴ϶� �پ��� Ÿ���� �����Ѵ�. 
		\return ������ �дµ� �����ϸ� true 

		\~english
		Additionally writes data to message object
		Suuports various types including bool type 
		\return True if successful in thorough reading

		\~chinese
		������?����ʥ???�ߡ�
		��?��bool?��������??����
		\return ������?��������?true

		\~japanese
		��ë�?�����֫������Ȫ˫�?������ʥ��?���ު���
		bool�����ת����ǪϪʪ�����?�ʫ����ת򫵫�?�Ȫ��ު���
		\return �����?�����몳�Ȫ���������true�Ǫ���
		\~
		*/
		inline bool Read(bool &b) {
			return Read_POD<bool>(&b);
		}
		inline bool Read(int8_t &b) {
			return Read_POD(&b);
		}
		inline bool Read(uint8_t &b) {
			return Read_POD(&b);
		}
		inline bool Read(int16_t &b) {
			return Read_POD(&b);
		}
		inline bool Read(uint16_t &b) {
			return Read_POD(&b);
		}
		inline bool Read(int32_t &b) {
			return Read_POD(&b);
		}
		inline bool Read(uint32_t &b) {
			return Read_POD(&b);
		}
		//bool Read(unsigned &b) { return CMessage_RawRead(*this,b); }
		inline bool Read(int64_t &b) {
			return Read_POD(&b);
		}
		inline bool Read(uint64_t &b) {
			return Read_POD(&b);
		}
		inline bool Read(float &b) {
			return Read_POD(&b);
		}
		inline bool Read(double &b) {
			return Read_POD(&b);
		}

		inline void Write(const Guid &b);
		inline bool Read(Guid &b);

		inline  bool Read(HostID &b);

		//void ClonedTo(CMessage_RawRead()
		//{
		//	BYTE[] o = new BYTE[m_buffer.GetCount()];
		//	m_buffer.CopyTo(o);
		//	return o;
		//}

		inline  void Write(NamedAddrPort n);
		inline  bool Read(NamedAddrPort &n);

// 		PROUD_API void WriteMessageContent(const CMessage &msg);
// 		PROUD_API bool ReadMessageContent(CMessage &msg);

		/** 
		\~korean
		�޽����� ���̸� ��´�. 

		\~english
		Gets the length of message

		\~chinese
		?��������?����

		\~japanese
		��ë�?������������ު���
		\~
		*/
		inline int GetLength() const
		{
			return (int)m_msgBuffer.GetCount();
		}

		/** 
		\~korean
		�޽����� ���� �б� ������ ���Ѵ�. ���ϰ��� ����Ʈ ������.

		\~english
		Calculates current read point of message. The return value is in byte. 

		\~chinese
		ϴ������?�?����á�����?��byte?�ȡ�

		\~japanese
		��ë�?�������?��������ê�ϴ��ު����꫿?�����ϫЫ���?�ȪǪ���
		\~
		 */
		inline int GetReadOffset() const
		{
			return m_readBitOffset >> 3; // ������ 8. signed�� >>�����ڰ� �� �۵��ϴ±�����!
		}

		inline void AppendByteArray(const uint8_t* fragment, int fragmentLength);

		inline uint8_t* GetData()
		{
			return m_msgBuffer.GetData();
		}

		inline const uint8_t* GetData() const
		{
			return m_msgBuffer.GetData();
		}

		template<typename BYTEARRAY>
		inline void CopyToT(BYTEARRAY& dest)
		{
			dest.SetCount(GetLength());
			UnsafeFastMemcpy(dest.GetData(), GetData(), GetLength());
		}

		inline void CopyTo(ByteArray& dest)
		{
			CopyToT<ByteArray>(dest);
		}
		inline void CopyTo(ByteArrayPtr& dest)
		{
			CopyToT<ByteArrayPtr>(dest);
		}
		inline void CopyTo(CMessage& dest)
		{
			CopyToT<ByteArrayPtr>(dest.m_msgBuffer);
			dest.m_readBitOffset = m_readBitOffset;
			dest.m_isSimplePacketMode = m_isSimplePacketMode;
		}

		/*		PROUD_API void CloneTo(CMessage& dest);
		PROUD_API ByteArrayPtr ToByteArray();
		PROUD_API void ToByteArray(ByteArray &ret);
		PROUD_API void CopyTo(ByteArray& dest); */

		// called by BiasManagedPointer.
		void Clear();

		inline  void ShareFromAndResetReadOffset(ByteArrayPtr data);

		/** 
		\~korean
		�ܺ� ���۸� ����ϵ��� �����Ѵ�.
		\param buf �ܺ� ���� ������
		\param capacity �ܺ� ������ ũ��

		\~english 
		Declare to use an external buffer
		\param buf External buffer pointer
		\param capacity Size of an external buffer

		\~chinese
		���������ݻbuffer��
		\param buf ��ݻbuffer�?��
		\param capacity ��ݻbuffer��᳡�

		\~japanese
		��ݻ�Ыëի�?���Ū��誦����몷�ު���
		\param buf ��ݻ�Ыëի�?�ݫ���?
		param capacity ��ݻ�Ыëի�?������
		\~
		 */
		inline  void UseExternalBuffer(uint8_t* buf, int capacity);
		
		/** 
		\~korean
		���� ���۸� ����ϵ��� �����Ѵ�.

		\~english
		Declares to use internal buffer

		\~chinese
		�������?ݻbuffer��

		\~japanese
		?ݻ�Ыëի�?���Ū��誦����몷�ު���
		\~
		 */
		inline  void UseInternalBuffer();

		/** 
		\~korean
		����ϴ� ���۸� ������ �����ϰ�, ���� �ܺ� �Ǵ� ���� ���۸� ����ϵ��� �����Ѵ�.
		- UseExternalBuffer, UseInternalBuffer�� �����Ϸ��� �ݵ�� �̰��� ȣ���ؾ� �Ѵ�.
		�̷��� �޼��尡 ���� �ִ� ������ ����ڰ� �Ǽ��ϴ� ���� �����ϱ� ���ؼ���. 
		- �� �޼��� ȣ�� �Ŀ��� read offset�� �޽��� ũ�Ⱑ �ʱ�ȭ�ȴ�.

		\~english
		Completely resets the PROUD_API void UseExternalBuffer(BYTE* buf, int capacity)r
		- This must be called in order to re-use UseExternalBuffer and UseInternalBuffer.
		  The reasone why this kind of method exists is to prevent for user to make mistakes.
		- After this method is called, the size of read offset and message will be initialized.

		\~chinese
		����?��������buffer���������������ݻ���?ݻbuffer��
		- �������UseExternalBuffer, UseInternalBuffer��?��?��У??��
		?��??۰���������?�������?��?��
		- ��У�۰����У���?�����read offset��������᳡�

		\~japanese
		�Ūêƪ����Ыëի�?������˫꫻�ëȪ��ơ��檿����ݻ�ު���?ݻ�Ыëի�?���Ū��誦����몷�ު���
		- UseExternalBuffer, UseInternalBuffer������Ī��몿��˪ϡ���������������󪷪ƪ���������
		���Ϊ誦�ʫ᫽�ëɪ�ܬ�˪�����릪ϡ���?��?�����ު�����򭪹�몿��Ǫ���
		- ���Ϋ᫽�ëɪ������󪷪����˪ϡ�read offset�ȫ�ë�?������������Ѣ������ު���

		 */
		inline  void UninitBuffer();

		/**
		\~korean
		���� ���� ������ ũ�⿡ count�� ���Ѵ�.

		\~english 
		Add count to the data size read currently. 

		\~chinese
		��?��??�����߾��ʥcount��

		\~japanese
		���?�����ê���?����������count��ʥ���ު���
		\~
		*/
		inline  bool SkipRead(int count);

		/**
		\~korean
		���ڿ� �ֱ�

		\~english
		Write string

		\~chinese
		?���ݬ����

		\~japanese
		���֪�������
		\~
		*/
		inline  void WriteString(const char* str);

		/**
		\~korean
		���ڿ� �ֱ�

		\~english
		Write string

		\~chinese
		?���ݬ����

		\~japanese
		���֪�������
		\~
		*/
		inline  void WriteString(const wchar_t* str);

		/**
		\~korean
		���ڿ� �ֱ�

		\~english
		Write string

		\~chinese
		?���ݬ����

		\~japanese
		���֪�������
		\~
		*/
		inline  void WriteString(const Proud::StringA &str);

		/**
		\~korean
		���ڿ� �ֱ�

		\~english
		Write string

		\~chinese
		?���ݬ����

		\~japanese
		���֪�������
		\~
		*/
		inline  void WriteString(const Proud::StringW &str);
		
		/**
		\~korean
		���ڿ� �ֱ�

		\~english
		Write string

		\~chinese
		?���ݬ����

		\~japanese
		\~
		*/
		inline  void WriteString(const std::string &str)
		{
			WriteString(str.c_str());
		}

		/**
		\~korean
		���ڿ� �ֱ�

		\~english
		Write string

		\~chinese
		?���ݬ����

		\~japanese
		���֪�������
		\~
		*/
		inline  void WriteString(const std::wstring &str)
		{	
			WriteString(str.c_str());
		}

		/**
		\~korean
		���ڿ� ������

		\~english
		Read string

		\~chinese
		?���ݬ����

		\~japanese
		���֪�������
		\~
		*/
		inline  bool ReadString(Proud::StringA &str);

		/**
		\~korean
		���ڿ� ������

		\~english
		Read string

		\~chinese
		?���ݬ����

		\~japanese
		���֪�������
		\~
		*/
		inline  bool ReadString(Proud::StringW &str);
		
		/**
		\~korean
		���ڿ� ������

		\~english
		Read string

		\~chinese
		?���ݬ����

		\~japanese
		���֪�������
		\~
		*/
		inline  bool ReadString(std::string &str)
		{
			StringA str2;
			bool ret = ReadString(str2);
			if(ret)
			{
				str = str2;
			}
			return ret;
		}

		/**
		\~korean
		���ڿ� ������

		\~english
		Read string 

		\~chinese
		?���ݬ����

		\~japanese
		���֪�������
		\~
		*/
		inline  bool ReadString(std::wstring &str)
		{
			StringW str2;
			bool ret = ReadString(str2);
			if(ret)
			{
				str = str2;
			}
			return ret;
		}

		bool ReadStringA(Proud::StringA &str);
		bool ReadStringW(Proud::StringW &str);
		void WriteStringA(const char* str);
		void WriteStringW(const wchar_t* str);

		/** 
		\~korean
		bitCount ��ŭ�� ��Ʈ �����͸� ����Ѵ�.
		- ���� �ռ� bit�� ����ϴ� ���̶� bit offset > 0�� ��� ��� ������ �ܿ� ��Ʈ�� �̾ ��ϵȴ�.
		- ���� bit offset > 0�� ���¿��� Write()�� ���� byte ���� ���⸦ �� ��� �ܿ� ��Ʈ�� ���õǰ�
		�� ����Ʈ���� ���Ⱑ �簳�ȴ�. �� byte assign���� �����ȴ�. 
		���� ȿ������ ��Ʈ ����� ���ؼ� ��Ʈ �ʵ�� ��Ʈ�� �ƴ� �ʵ带 �������� ��Ƽ� �б�/���⸦ �ؾ� �Ѵ�.

		\~english
		Writes bit data as muuch of bitCount
		- If bit offset > 0 due to prior bit writing then writes continuous to usable remaining bits.
		- When writing byte unit due to Write() when bit offset > 0 then remaining bits will be ignored and the writing will be continued at a new byte. In other words, it will be modified to byte assign. 
		Therefore, to use bits effectively, it must collectively read/write those fields, not fields and bits.

		\~chinese
		??��?��bitCount��bit?�ߡ�
		- ����������??bit�����bit offset > 0����?��?��?����ʦ�������?׺bit߾?��??��
		- ����?bit offset > 0����?����?Write()���?��byte?����?��?׺bit?����?��?����bit?�?����??��?byte assign��
		?�����������bit�������bit?�������bit��?�����?��?/?��

		\~japanese
		bitCount �����Ϋӫëȫ�?������?���ު���
		- �⪷��໪˫ӫëȪ���?���ƪ����Ϊǡ�bit offset > 0�Ǫ������ꡢ����ʦ����?���ӫëȪ�?������?����ު���
		- �⪷��bit offset > 0�Ǫ���?���ǡ�Write()�˪�êơ�byte?�Ȫ�����?�ߪ򪹪����ꡢ?���ӫëȪ����ʪ�����檷���Ы��Ȫ�����?�ߪ���Ҫ���ު���?����byte assign�����ڪ���ު�����êơ�?���ܪʫӫë����ĪΪ���˪ϫӫëȫի�?��ɪȫӫëȪǪϪʪ��ի�?������ͪ����?������/����?�ߪ򪷪ʪ���Ъʪ�ު���
		
		\~
		 */
		inline  void WriteBits(uint8_t* src,int srcBitLength);

		/** 
		\~korean
		bitCount��ŭ�� ��Ʈ �����͸� �о���δ�.
		\return �дµ� �����ϸ� true�� �����Ѵ�. ���� bit�� ���ڶ�� false�� ����.
		- ���� �ռ� bit�� �д� ���̶� bit offset > 0�� ��� ��� ������ �ܿ� ��Ʈ�� �̾ �д´�.
		- ���� bit offset>0�� ���¿��� Read()�� ���� byte ���� �б⸦ �� ��� �ܿ� ��Ʈ�� ���õǰ�
		�� ����Ʈ���� �бⰡ �簳�ȴ�. �� byte assign���� �����ȴ�. 
		���� ȿ������ ��Ʈ ����� ���ؼ� ��Ʈ �ʵ�� ��Ʈ�� �ƴ� �ʵ带 �������� ��Ƽ� �б�/���⸦ �ؾ� �Ѵ�. 

		\~english
		Reads bit data as much of bitCount
		\return Returns true if reading is successful. Returns false when there are not enough bits to read.
		- If bit offset > 0 due to prior bit reading then reads continuous to usable remaining bits.
		- When reading byte unit due to Read() when bit offset > 0 then remaining bits will be ignored and the reading will be continued at a new byte. In other words, it will be modified to byte assign. 
		Therefore, to use bits effectively, it must collectively read/write those fields, not fields and bits.

		\~chinese
		?����?��bitCount��bit?�ߡ�
		\return ?��������?����ture������?��bit��?����false��
		- ����������??bit�����bit offset > 0����?��?�����?ʦ�������?׺bit��?����		-������bit offset > 0����?����?Read()���?��byte?����?��?׺bit?����?��?��bit߾?�?����??��?byte assign��
		?�����������bit�������bit?�������bit��?�����?��?/?��

		\~japanese
		bitCount�����Ϋӫëȫ�?����?������ު���
		Return��?���������������true��꫿?�󪷪ު���?������bit�����ʪ����false��꫿?�󪷪ު���
		- �⪷��໪˫ӫëȪ�?��Ǫ����Ϊǡ�bit offset > 0�Ǫ������ꡢ����ʦ����?���ӫëȪ�?����?������ު���
		- �⪷��bit offset > 0�Ǫ���?���ǡ�Read()�˪�êơ�byte?�Ȫ�?������򪹪����ꡢ?���ӫëȪ����ʪ�����檷���Ы��Ȫ�?�����ꪬ��Ҫ���ު���?����byte assign�����ڪ���ު�����êơ�?���ܪʫӫë����ĪΪ���˪ϫӫëȫի�?��ɪȫӫëȪǪϪʪ��ի�?������ͪ����?������/����?�ߪ򪷪ʪ���Ъʪ�ު���

		\~
		*/
		inline  bool ReadBits(uint8_t* output,int outputBitLength);

		inline bool ReadBits(bool &output, int outputBitLength) { return ReadBits((uint8_t*)&output, outputBitLength); }
		inline void WriteBits(bool src, int srcBitLength) { WriteBits((uint8_t*)&src, srcBitLength); }

		inline bool ReadBits(int8_t &output, int outputBitLength) { return ReadBits((uint8_t*)&output, outputBitLength); }
		inline void WriteBits(int8_t src, int srcBitLength) { WriteBits((uint8_t*)&src, srcBitLength); }

		inline bool ReadBits(uint8_t &output, int outputBitLength) { return ReadBits((uint8_t*)&output, outputBitLength); }
		inline void WriteBits(uint8_t src, int srcBitLength) { WriteBits((uint8_t*)&src, srcBitLength); }

		inline bool ReadBits(int16_t &output, int outputBitLength) { return ReadBits((uint8_t*)&output, outputBitLength); }
		inline void WriteBits(int16_t src, int srcBitLength) { WriteBits((uint8_t*)&src, srcBitLength); }

		inline bool ReadBits(uint16_t &output, int outputBitLength) { return ReadBits((uint8_t*)&output, outputBitLength); }
		inline void WriteBits(uint16_t src, int srcBitLength) { WriteBits((uint8_t*)&src, srcBitLength); }

		inline bool ReadBits(int32_t &output, int outputBitLength) { return ReadBits((uint8_t*)&output, outputBitLength); }
		inline void WriteBits(int32_t src, int srcBitLength) { WriteBits((uint8_t*)&src, srcBitLength); }

		inline bool ReadBits(uint32_t &output, int outputBitLength) { return ReadBits((uint8_t*)&output, outputBitLength); }
		inline void WriteBits(uint32_t src, int srcBitLength) { WriteBits((uint8_t*)&src, srcBitLength); }

		inline bool ReadBits(float &output,int outputBitLength) {return ReadBits((uint8_t*)&output,outputBitLength);}
		inline void WriteBits(float src,int srcBitLength) { WriteBits((uint8_t*)&src,srcBitLength);}

		inline bool ReadBits(double &output,int outputBitLength) {return ReadBits((uint8_t*)&output,outputBitLength);}
		inline void WriteBits(double src,int srcBitLength) { WriteBits((uint8_t*)&src,srcBitLength);}



	private:

#ifdef _MSC_VER // �� ���� �ּ� ����
		DECLARE_READ_AND_WRITE(MessageType)
		DECLARE_READ_AND_WRITE(MessagePriority)
		DECLARE_READ_AND_WRITE(DirectP2PStartCondition)
		DECLARE_READ_AND_WRITE(FallbackMethod)
		DECLARE_READ_AND_WRITE(EncryptMode)
		DECLARE_READ_AND_WRITE(ReliableUdpFrameType)
		DECLARE_READ_AND_WRITE(_LocalEventType)
		DECLARE_READ_AND_WRITE(_RmiID)
		DECLARE_READ_AND_WRITE(ErrorType)
#endif

		inline int WriteBitsOfOneByte(const uint8_t* src, int srcBitLength, int srcBitOffset);
		inline int ReadBitsOfOneByte(uint8_t* output, int outputBitLength, int outputBitOffset);
		void ThrowBitOperationError(const char* where);
		void ThrowReadOffsetOutOfRangeException(int offset);
		void ThrowWrongSpliiterException();

	};

	//// ���� ������ ��� �� ��� ����=>�� �̻� �Ⱦ�. UseInternalBuffer��ü�� obj-pool������� ���� rellocȽ���� ���� �پ��ϱ�.
	//class CSendingMessage: public CMessage
	//{
	//public:
	//	CSendingMessage()
	//	{
	//		UseInternalBuffer();
	//		// �̸� ������ Ȯ Ȯ���� �� �ٽ� �����ع�����. �̷��� �ؼ� ���Ҵ� Ƚ���� 0���� �����.
	//		// �������� Proud::CNetConfig::MessageMaxLength�� �־�����, �̰��� ������ CRT heap�� ���� �����ع����Ƿ� ĳ������ �ȴ�.
	//		// ���� ��� �Ҵ��� �ϴ� CFastHeap::DefaultAccelBlockSizeLimit�� ��� �Ѵ�.
	//		SetLength(CFastHeap::DefaultAccelBlockSizeLimit);
	//		SetLength(0);
	//	}
	//};

	// ------- �̰� �� �̻� �Ⱦ���. ProudNetConfig::MessageMaxLength�� ��Ÿ�ӿ��� ������ �� �־�� �ϴϱ�.
	// class CSendingMessage: public CMessage 
	// {
	// 	BYTE m_stackBuffer[CNetConfig::MessageMaxLength];
	// 
	// public:
	// 	CSendingMessage()
	// 	{
	// 		UseExternalBuffer(m_stackBuffer, sizeof(m_stackBuffer));
	// 	}
	// };

	// ���� ������ ��� �� ��� ����
	// ����: ���� ũ�Ⱑ �ſ� �����Ƿ� �����ؼ� �� ��! ���� ũ�� �����͸� �ְų� �ؼ��� ���!
	// ** PS4&UE4 �����ϴ� ��Ȳ����, �̰��� ���� ũ�� �迭�� �����ߴ���, ������ �߻��߾���. �׸��� �� Ŭ������
	// obj-pool ����� ���� ������ ���� ����̴�. ���� ������ �� Ŭ������ ���ֵ� �ȴ�.
	class CSmallStackAllocMessage: public CMessage
	{
	public:
		inline CSmallStackAllocMessage()
		{
			UseInternalBuffer();
		}
	};

#ifdef _DEBUG
	/* 
	\~korean
	�ӽ������� splitter test�� ������ �� �� �� ��ü�� ���� ������ �ּ� ������ �Ѵ�.
	- �ַ� serialize �Լ� ���ο��� ����.
	- CSendFragRefs���� �ʿ��ؼ� ���� Ŭ���� 

	\~english
	To temporarily turn off splitter test, this object can be as a local variable.
	- Mainly use in inside of serialize function
	- Class added since required by CSendFragRefs

	\~chinese
	��????splitter test��?��������?��׺?���??����ġ�
	- ���serialize��??ݻ���ġ�
	- � CSendFragRefs%������?����?��

	\~japanese
	�����ܪ�splitter test�򫪫ժ��������ꡢ���Ϋ��֫������Ȫ��?����??���Ǫ����Ū��誦�˪��ު���
	- �� serialize??��?ݻ���Ū��ު���
	- CSendFragRefs����驪ʪΪ����쪿���髹 
	\~
	*/
	class CMessageTestSplitterTemporaryDisabler
	{
		CMessage* m_msg;
		bool m_oldVal;
	public:
		CMessageTestSplitterTemporaryDisabler(CMessage& msg);
		~CMessageTestSplitterTemporaryDisabler();
	};

#endif


	/**  @} */
	

	
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif

#include "Message.inl"