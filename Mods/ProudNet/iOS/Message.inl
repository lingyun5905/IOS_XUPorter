/*
ProudNet 1.7.34387-dev003-10


이 프로그램의 저작권은 넷텐션에게 있습니다.
이 프로그램의 수정, 사용, 배포에 관련된 사항은 본 프로그램의 소유권자와의 계약을 따르며,
계약을 준수하지 않는 경우 원칙적으로 무단 사용을 금지합니다.
무단 사용에 의한 책임은 본 프로그램의 소유권자와의 계약서에 명시되어 있습니다.

** 주의 : 저작물에 관한 위의 명시를 제거하지 마십시오.


This program is soley copyrighted by Nettention.
Any use, correction, and distribution of this program are subject to the terms and conditions of the License Agreement.
Any violated use of this program is prohibited and will be cause of immediate termination according to the License Agreement.

** WARNING : PLEASE DO NOT REMOVE THE LEGAL NOTICE ABOVE.


此程序的版??Nettention公司所有。
?此程序的修改、使用、?布相?的事?要遵守此程序的所有?者的??。
不遵守???要原?性的禁止擅自使用。
擅自使用的?任明示在?此程序所有?者的合同?里。

** 注意：不要移除?于制作物的上述明示。


このプログラムの著作?はNettentionにあります。
このプログラムの修正、使用、配布に?する事項は本プログラムの所有?者との契約に?い、
契約を遵守しない場合、原則的に無?使用を禁じます。
無?使用による責任は本プログラムの所有?者との契約書に明示されています。

** 注意：著作物に?する上記の明示を除去しないでください。

*/
#pragma once

#include "CompactScalarValue.h"

namespace Proud
{
	//////////////////////////////////////////////////////////////////////////
	// 성능을 많이 먹는 것들을 일로 옮겼음.

	const int StringSerializeMaxLength = 1024 * 1024;
	extern const char* ReadOffsetAlignErrorText;
	extern const char* NullAccessErrorText;
	extern const char* WriteBitsOfOneByteText;


	inline void AdjustReadOffsetByteAlign(CMessage& msg)
	{
		// 비트 단위 읽기를 하던 중이라 읽기 포인트가 byte align이 아니면 조정한다.
		int octetOffset = msg.m_readBitOffset & 7; // mod 8

		msg.m_readBitOffset &= 0xfffffff8; // mod 8만큼을 빼 버림

		if (octetOffset != 0)
			msg.m_readBitOffset += 8;
	}

	inline void AssureReadOffsetByteAlign(CMessage& msg)
	{
		if ((msg.m_readBitOffset & 7) != 0)
		{
			CMessage::ThrowOnWrongLength(ReadOffsetAlignErrorText, (int)strlen(ReadOffsetAlignErrorText), StringSerializeMaxLength);
		}
	}

	inline bool CMessage::Read(uint8_t* data, int count)
	{
		// 아예 읽을게 없으면 splitter test 자체도 제낀다.
		if (count == 0)
			return true;

		AdjustReadOffsetByteAlign(*this);

		if (!Read_NoTestSplitter(data, count))
			return false;

#ifdef _DEBUG
		ReadAndCheckTestSplitterOnCase();
#endif

		return true;
	}

	template<typename POD>
	inline bool CMessage::Read_POD(POD* data)
	{
		AdjustReadOffsetByteAlign(*this);

		if (!Read_NoTestSplitter_POD<POD>(data))
			return false;

#ifdef _DEBUG
		ReadAndCheckTestSplitterOnCase();
#endif
		return true;
	}


	inline void CMessage::Write(const Guid &b)
	{
		const PNGUID* p = &b;
		Write((const uint8_t*)p, sizeof(*p));
	}

	inline bool CMessage::Read(Guid &b)
	{
		PNGUID* p = &b;
		return Read((uint8_t*)p, sizeof(*p));
	}

	inline bool CMessage::CanRead(int count)
	{
		// 아예 읽을게 없으면 splitter test 자체도 제낀다.
		if (count == 0)
			return true;

		int oldReadBitOffset = m_readBitOffset;

		AdjustReadOffsetByteAlign(*this);

		if (!CanRead_NoTestSplitter(count))
		{
			m_readBitOffset = oldReadBitOffset;
			return false;
		}
#ifdef _DEBUG
		ReadAndCheckTestSplitterOnCase();
#endif

		m_readBitOffset = oldReadBitOffset;

		return true;
	}

	inline void CMessage::Write(const AddrPort &b)
	{
		Write((uint8_t*)&b.m_addr, sizeof(b.m_addr));
		Write(b.m_port);
	}



	inline void CMessage::CopyFromArrayAndResetReadOffset(const uint8_t* src, int srcLength)
	{
		m_msgBuffer.Clear();
		m_msgBuffer.AddRange(src, srcLength);
		m_readBitOffset = 0;
	}

	inline CMessage::CMessage()
	{
		Clear();
	}

	// 복사 생성자
	inline CMessage::CMessage(const CMessage &src)
	{
		m_readBitOffset = src.m_readBitOffset;
#ifdef _DEBUG
		m_enableTestSplitter = src.m_enableTestSplitter;
#endif
		m_bitLengthInOneByte = src.m_bitLengthInOneByte;
		m_isSimplePacketMode = src.m_isSimplePacketMode;

		m_msgBuffer = src.m_msgBuffer;
	}

	/*void CMessage::ResetWritePointer()
	{
	m_msgBuffer.Clear();
	}*/

	inline int CMessage::GetWriteOffset()
	{
		return (int)m_msgBuffer.GetCount();
	}

	inline void CMessage::Clear()
	{
		m_readBitOffset = 0;
#ifdef _DEBUG
		m_enableTestSplitter = CNetConfig::EnableTestSplitter;
#endif
		m_bitLengthInOneByte = 0;
		m_isSimplePacketMode = false;

		m_msgBuffer.Clear(); // keeps buffer, however.
	}

	inline bool CMessage::Read(AddrPort &b)
	{
		b = AddrPort::Unassigned;
		return (Read((uint8_t*)&b.m_addr, sizeof(b.m_addr)) == true &&
			Read(b.m_port) == true);
	}


	inline bool CMessage::Read(HostID &b)
	{
		b = HostID_None;
		int x;
		bool r;
		r = Read(x);
		if (r == true)
			b = (HostID)x;
		return r;
	}



	inline void CMessage::Write(NamedAddrPort n)
	{
		WriteString(n.m_addr);
		Write(n.m_port);
	}

	inline bool CMessage::Read(NamedAddrPort &n)
	{
		return ReadString(n.m_addr) && Read(n.m_port);
	}



	inline void CMessage::SetReadOffset(int offset)
	{
		if (offset > (int)m_msgBuffer.GetCount())
		{
			ThrowReadOffsetOutOfRangeException(offset);
		}
		m_readBitOffset = offset * 8;
	}


	inline void CMessage::UseInternalBuffer()
	{
		/* Q: CMessage ctor를 냅두고 이 함수가 따로 있나요?
		A: global object pool에서 가져오는 과정이 무조건 수행되면 느리잖아요.t
		Q: 그러면, 최초의 write 가 발생하면 JIT로 하면 되잖아요?
		A: Aㅏ..... TODO로 남깁시다 ㅋㅋㅋ */
		m_msgBuffer.UseInternalBuffer();
		m_msgBuffer.SetGrowPolicy(GrowPolicy_HighSpeed);
		m_msgBuffer.SetMinCapacity(CNetConfig::MessageMinLength);
	}

	inline void CMessage::WriteString(const char* str)
	{
		WriteStringA(str);
	}

	inline void CMessage::WriteString(const wchar_t* str)
	{
		WriteStringW(str);
	}

	inline void CMessage::WriteString(const StringA &str)
	{
		WriteStringA(str);
	}

	inline void CMessage::WriteString(const StringW &str)
	{
		WriteStringW(str);
	}

	inline bool CMessage::ReadString(StringA &str)
	{
		return ReadStringA(str);
	}

	inline bool CMessage::ReadString(StringW &str)
	{
		return ReadStringW(str);
	}


	inline void CMessage::SetLength(int count)
	{
		if (m_readBitOffset > count * 8)
		{
			m_readBitOffset = count * 8; // 어쨌거나 크기 조절하기를 시행.
		}

		m_msgBuffer.SetCount(count);
	}



	/// 읽은 것처럼 구라친다.
	inline bool CMessage::SkipRead(int count)
	{
#ifdef _DEBUG
		ReadAndCheckTestSplitterOnCase();
#endif

		if (m_msgBuffer.IsNull())
		{
			ThrowOnWrongLength(NullAccessErrorText, (int)strlen(NullAccessErrorText), StringSerializeMaxLength);
		}

		if (GetReadOffset() + count > (int)m_msgBuffer.GetCount())
			return false;
		// memcpy(data,m_msgBuffer.GetData()+m_readOffset,count); 이것만 commented out.
		m_readBitOffset += count * 8;

		return true;

	}




	inline bool CMessage::Read_NoTestSplitter(uint8_t* data, int count)
	{
		if (m_msgBuffer.IsNull())
		{
			ThrowOnWrongLength(NullAccessErrorText, (int)strlen(NullAccessErrorText), StringSerializeMaxLength);
		}

		AssureReadOffsetByteAlign(*this);

		if (GetReadOffset() + count > (int)m_msgBuffer.GetCount())
			return false;
		UnsafeFastMemcpy(data, m_msgBuffer.GetData() + GetReadOffset(), count);
		m_readBitOffset += count * 8;

		return true;
	}

	template<typename POD>
	inline bool CMessage::Read_NoTestSplitter_POD(POD* data)
	{
		const int length = sizeof(POD); // 상수. 성능 위해.
		const int bitLength = sizeof(POD) * 8; // 상수. 성능 위해.

		if (m_msgBuffer.IsNull())
		{
			ThrowOnWrongLength(NullAccessErrorText, (int)strlen(NullAccessErrorText), StringSerializeMaxLength);
		}

		AssureReadOffsetByteAlign(*this);

		// cache it
		int readOffset = GetReadOffset();

		if (readOffset + length > (int)m_msgBuffer.GetCount())
			return false;

		// 하기 if에 대해서는 Write_NoTestSplitter_POD에 설명이 있다.
#if defined(__MARMALADE__) || defined(__ANDROID__) || defined(__arm__) // RVCT를 쓰는 경우 __packed keyword를 쓰면 되지만 gcc를 쓰므로 
		memcpy(data, m_msgBuffer.GetData() + readOffset, length);
#else
		*data = *((POD*)(m_msgBuffer.GetData() + readOffset));
#endif
		m_readBitOffset += bitLength;

		return true;
	}


	inline bool CMessage::CanRead_NoTestSplitter(int count)
	{
		if (m_msgBuffer.IsNull())
		{
			ThrowOnWrongLength(NullAccessErrorText, (int)strlen(NullAccessErrorText), StringSerializeMaxLength);
		}

		int oldReadBitOffset = m_readBitOffset;

		AssureReadOffsetByteAlign(*this);

		if (GetReadOffset() + count > (int)m_msgBuffer.GetCount())
		{
			m_readBitOffset = oldReadBitOffset;
			return false;
		}

		m_readBitOffset = oldReadBitOffset;

		return true;
	}

#ifdef _DEBUG
	inline void CMessage::ReadAndCheckTestSplitterOnCase()
	{
		if (m_enableTestSplitter)
		{
			uint8_t s;
			if (!Read_NoTestSplitter(&s, sizeof(s)) || s != Splitter)
			{
				ThrowWrongSpliiterException();
			}
		}
	}

	inline void CMessage::EnableTestSplitter(bool enable)
	{
		m_enableTestSplitter = enable;
	}
#endif

	inline bool CMessage::ReadWithShareBuffer(CMessage& output, int length)
	{
		if (GetLength() < GetReadOffset() + length)
			return false;

		uint8_t* contentPtr = GetData() + GetReadOffset();
		output.UseExternalBuffer(contentPtr, length);
		output.SetLength(length); // 이게 있어야 함!
		SkipRead(length);

		return true;
	}


	inline void CMessage::AppendByteArray(const uint8_t* fragment, int fragmentLength)
	{
		m_msgBuffer.AddRange(fragment, fragmentLength);
	}

	inline void CMessage::WriteBits(uint8_t* src, int srcBitLength)
	{
		if (srcBitLength < 0)
			ThrowInvalidArgumentException();

		int srcBitOffset = 0;
		while (srcBitOffset < srcBitLength)
		{
			int done = WriteBitsOfOneByte(src, srcBitLength, srcBitOffset);
			if (done <= 0)
			{
				ThrowBitOperationError(__FUNCTION__);
			}
			srcBitOffset += done;
		}

	}

	inline int CMessage::WriteBitsOfOneByte(const uint8_t* src, int srcBitLength, int srcBitOffset)
	{
		// 기록할 수 있는 비트 수를 구한다.
		int bitLengthToWrite = PNMIN(8 - srcBitOffset % 8, 8 - m_bitLengthInOneByte);
		bitLengthToWrite = PNMIN(bitLengthToWrite, srcBitLength - srcBitOffset);
		bitLengthToWrite = PNMAX(0, bitLengthToWrite);

		// 기록할 것이 없으면 종료 처리한다.
		if (bitLengthToWrite == 0)
			return 0;

		// 기록 대상의 bit offset이 0이면 새 바이트를 추가한다.
		if (m_bitLengthInOneByte == 0)
			m_msgBuffer.Add(0);

		// 기록 대상의 원래 값을 미리 얻어둔다.
		int result = m_msgBuffer[m_msgBuffer.GetCount() - 1];

		// 기록할 비트를 추출한다. 총 비트에서 기록 대상 외 비트를 제거한 후 왼쪽으로 옮긴다.
		int bits = src[srcBitOffset / 8];

		int bitMask = (1 << bitLengthToWrite) - 1;
		bits = (bits >> (srcBitOffset % 8)) & bitMask;
		bits <<= m_bitLengthInOneByte % 8;

		// 결과물을 기록한다.
		result |= bits;
		m_msgBuffer[m_msgBuffer.GetCount() - 1] = (uint8_t)result;
		m_bitLengthInOneByte += bitLengthToWrite;

		if (m_bitLengthInOneByte > 8)
		{
			ThrowBitOperationError(WriteBitsOfOneByteText);
		}

		if (m_bitLengthInOneByte == 8)
		{
			m_bitLengthInOneByte = 0;
		}
		return bitLengthToWrite;
	}

	inline bool CMessage::ReadBits(uint8_t* output, int outputBitLength)
	{
		if (outputBitLength < 0)
			ThrowInvalidArgumentException();

		int outputBitOffset = 0;
		while (outputBitOffset < outputBitLength)
		{
			int done = ReadBitsOfOneByte(output, outputBitLength, outputBitOffset);
			if (done == 0)
				return false;   // 만약 더 읽을 것이 없으면 false를 그냥 리턴.
			outputBitOffset += done;
		}

		return true;
	}

	inline int CMessage::ReadBitsOfOneByte(uint8_t* output, int outputBitLength, int outputBitOffset)
	{
		// 읽을 수 있는 비트 수를 구한다.
		int outputBitOffsetInOneByte = outputBitOffset % 8;
		int bitLengthToRead = PNMIN(8 - outputBitOffsetInOneByte, 8 - m_readBitOffset % 8);
		bitLengthToRead = PNMIN(bitLengthToRead, outputBitLength - outputBitOffset);
		bitLengthToRead = PNMAX(0, bitLengthToRead);

		// 읽을 것이 없으면 종료 처리한다.
		if (bitLengthToRead == 0)
			return 0;

		// 읽기 소스가 있으면 새 바이트를 추가한다.
		if (outputBitOffsetInOneByte == 0)
			output[outputBitOffset / 8] = 0;

		int outputOldValue = output[outputBitOffset / 8];

		// 읽기 소스의 바이트 값을 읽는다.
		int bits = m_msgBuffer[m_readBitOffset / 8];

		// 읽기 소스에서 읽을 만큼의 비트를 걸러내기 위해 비트를 우측으로 옮긴다.
		bits >>= m_readBitOffset % 8;
		int bitMask = (1 << bitLengthToRead) - 1;
		int readResult = bits & bitMask;
		readResult <<= outputBitOffsetInOneByte;

		// 읽은 결과물을 기록할 결과물에 병합한다.
		readResult |= outputOldValue;
		output[outputBitOffset / 8] = (int8_t)readResult;

		m_readBitOffset += bitLengthToRead;

		return bitLengthToRead;
	}

	template<typename Type>
	inline bool Message_ReadScalar(CMessage& msg, Type &a)
	{
		if (msg.IsSimplePacketMode())
		{
			int64_t a0; // VLQ에 대해서는, 사용자가 어떤 타입을 넣을지 무시하고 쓰므로
			bool ok = msg.Read(a0); 
			if (ok)
			{
				a = (Type)a0; // 크기가 작더라도 무시하자.
			}
			return ok;
		}
		else
		{
			CCompactScalarValue<Type> val;
			int readOffset = msg.GetReadOffset();
			if (!val.ExtractValue(msg.GetData() + readOffset, msg.GetLength() - readOffset))
				return false;

			a = val.m_extractedValue;
			msg.SkipRead(val.m_extracteeLength);

			return true;
		}
	}

	inline bool CMessage::ReadScalar(int64_t &a)
	{
		return Message_ReadScalar<int64_t>(*this, a);
	}

	inline bool CMessage::ReadScalar(int32_t &a)
	{
		return Message_ReadScalar<int32_t>(*this, a);
	}

	inline bool CMessage::ReadScalar(int16_t &a)
	{
		return Message_ReadScalar<int16_t>(*this, a);
	}

	inline bool CMessage::ReadScalar(int8_t &a)
	{
		return Message_ReadScalar<int8_t>(*this, a);
	}

	template <typename Type>
	inline void Message_WriteScalar(CMessage& msg, Type a)
	{
		if (msg.IsSimplePacketMode())
		{
			msg.Write((int64_t)a); // VLQ에 대해서는, 사용자가 어떤 타입을 넣을지 무시하고 쓰므로
		}
		else
		{
			// 변환된 메모리 블럭 생성
			CCompactScalarValue<Type> comp;
			comp.MakeBlock(a);

			// 이를 메시지 객체에 넣기
			msg.Write(comp.m_filledBlock, comp.m_filledBlockLength);
		}
	}

	inline void CMessage::WriteScalar(int64_t a)
	{
		Message_WriteScalar<int64_t>(*this, a);
	}

	inline void CMessage::WriteScalar(int32_t a)
	{
		Message_WriteScalar<int32_t>(*this, a);
	}

	inline void CMessage::WriteScalar(int16_t a)
	{
		Message_WriteScalar<int16_t>(*this, a);
	}

	inline void CMessage::WriteScalar(int8_t a)
	{
		Message_WriteScalar<int8_t>(*this, a);
	}

	inline void CMessage::UninitBuffer()
	{
		m_readBitOffset = 0;
		m_bitLengthInOneByte = 0;
		m_msgBuffer.UninitBuffer();
	}

#ifdef _DEBUG
	inline CMessageTestSplitterTemporaryDisabler::CMessageTestSplitterTemporaryDisabler(CMessage& msg)
	{
		m_msg = &msg;
		m_oldVal = m_msg->IsTestSplitterEnabled();
		m_msg->EnableTestSplitter(false);
	}

	inline CMessageTestSplitterTemporaryDisabler::~CMessageTestSplitterTemporaryDisabler()
	{
		m_msg->EnableTestSplitter(m_oldVal);
	}
#endif

	// 이 함수를 호출하면 simple packet mode가 켜지거나 꺼진다.
	// read/write scalar 등을 비활성화하는데 사용된다.
	inline void CMessage::SetSimplePacketMode(bool isSimplePacketMode)
	{
		m_isSimplePacketMode = isSimplePacketMode;
	}

	// 다른 버퍼 객체와 포인터를 공유하기 시작하면서 읽기 위치를 리셋한다.
	inline void CMessage::ShareFromAndResetReadOffset(ByteArrayPtr data)
	{
		m_msgBuffer = data;
		m_readBitOffset = 0;
	}

	inline void CMessage::UseExternalBuffer(uint8_t* buf, int capacity)
	{
		// 		if (capacity > CNetConfig::MessageMaxLength)
		// 			throw Exception("UseExternalBuffer failed due to too large capacity");

		m_msgBuffer.UseExternalBuffer(buf, capacity);
	}





}