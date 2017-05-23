/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 177 92 124 113 87 79 17 155 171 239 138 133 88 235 28 112 146 102 93 52 214 131 240 31 138 179 248 115 127 118 107 31 112 91 111 14 243 1 121 131 22 69 144 19 214 101 65 133 253 32 122 175 12 198 63 134 23 240 109 90 59 142 194 194 160 148 139 101 68 220 217 181 32 240 36 47 59 74 18 182 145 116 17 29 255 115 236 11 29 111 122  */
/*
ProudNet 1.7.34387-dev003-10


ÀÌ ÇÁ·Î±×·¥ÀÇ ÀúÀÛ±ÇÀº ³İÅÙ¼Ç¿¡°Ô ÀÖ½À´Ï´Ù.
ÀÌ ÇÁ·Î±×·¥ÀÇ ¼öÁ¤, »ç¿ë, ¹èÆ÷¿¡ °ü·ÃµÈ »çÇ×Àº º» ÇÁ·Î±×·¥ÀÇ ¼ÒÀ¯±ÇÀÚ¿ÍÀÇ °è¾àÀ» µû¸£¸ç,
°è¾àÀ» ÁØ¼öÇÏÁö ¾Ê´Â °æ¿ì ¿øÄ¢ÀûÀ¸·Î ¹«´Ü »ç¿ëÀ» ±İÁöÇÕ´Ï´Ù.
¹«´Ü »ç¿ë¿¡ ÀÇÇÑ Ã¥ÀÓÀº º» ÇÁ·Î±×·¥ÀÇ ¼ÒÀ¯±ÇÀÚ¿ÍÀÇ °è¾à¼­¿¡ ¸í½ÃµÇ¾î ÀÖ½À´Ï´Ù.

** ÁÖÀÇ : ÀúÀÛ¹°¿¡ °üÇÑ À§ÀÇ ¸í½Ã¸¦ Á¦°ÅÇÏÁö ¸¶½Ê½Ã¿À.


This program is soley copyrighted by Nettention.
Any use, correction, and distribution of this program are subject to the terms and conditions of the License Agreement.
Any violated use of this program is prohibited and will be cause of immediate termination according to the License Agreement.

** WARNING : PLEASE DO NOT REMOVE THE LEGAL NOTICE ABOVE.


ó®ïïßíîÜ÷ú??NettentionÍëŞÉá¶êó¡£
?ó®ïïßíîÜáóËÇ¡¢ŞÅéÄ¡¢?øÖßÓ?îÜŞÀ?é©ñåáúó®ïïßíîÜá¶êó?íºîÜ??¡£
Üôñåáú???é©ê«?àõîÜĞ×ò­ôºí»ŞÅéÄ¡£
ôºí»ŞÅéÄîÜ?ìòÙ¥ãÆî¤?ó®ïïßíá¶êó?íºîÜùêÔÒ?×ì¡£

** ñ¼ëò£ºÜôé©ì¹ğ¶?éÍğ¤íÂÚªîÜß¾âûÙ¥ãÆ¡£


ª³ªÎ«×«í«°«é«àªÎîÊíÂ?ªÏNettentionªËª¢ªêªŞª¹¡£
ª³ªÎ«×«í«°«é«àªÎáóïá¡¢ŞÅéÄ¡¢ÛÕøÖªË?ª¹ªëŞÀú£ªÏÜâ«×«í«°«é«àªÎá¶êó?íºªÈªÎÌøå³ªË?ª¤¡¢
Ìøå³ªòñåáúª·ªÊª¤íŞùê¡¢ê«öÎîÜªËÙí?ŞÅéÄªòĞ×ª¸ªŞª¹¡£
Ùí?ŞÅéÄªËªèªëô¡ìòªÏÜâ«×«í«°«é«àªÎá¶êó?íºªÈªÎÌøå³ßöªËÙ¥ãÆªµªìªÆª¤ªŞª¹¡£

** ñ¼ëò£ºîÊíÂÚªªË?ª¹ªëß¾ÑÀªÎÙ¥ãÆªòğ¶ËÛª·ªÊª¤ªÇª¯ªÀªµª¤¡£

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
	// ¾Æ·¡ enumµéÀ» CMessage.Read or Write()¿¡¼­ »ç¿ëÇÒ ¼ö ¾ø°Ô ÇÏ±â À§ÇØ, ´ÙÀ½°ú °°ÀÌ ÇÏ°í ÀÖ´Ù.
	// 1. Àü¹æ ¼±¾ğ
	// 2. Write(),Read()¸¦ privateÀ¸·Î ¼±¾ğÇÏ¿©, »ç¿ëÇÒ ¼ö ¾ø°Ô ÇÏ±â.
	// ´Ü, Àü¹æ ¼±¾ğÀº VC++ ¿ÜÀÇ C++11¿¡¼­ ¸ø ¾²¹Ç·Î, VC++ Àü¿ëÀ¸·Î¸¸ È°¼ºÈ­ÇÑ´Ù.
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
	¸Ş½ÃÁö Å¬·¡½º. ÀÚ¼¼ÇÑ ³»¿ëÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#message_class" >¸Ş½ÃÁö °´Ã¼(Proud.CMessage)</a>¸¦ Âü°í.

	\~english 
	Message class. For detailed information, refer to \ref message_class

	\~chinese
	ãáãÓ?¡£????ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#message_class" >ãáãÓËÔ?(Proud.CMessage)</a>%¡£

	\~japanese
	«á«Ã«»?«¸«¯«é«¹¡£ßÙª·ª¯ªÏ¡¢\ref message_classªòª´?ğÎª¯ªÀªµª¤¡£
	\~
	*/
	class CMessage
	{
		// ÇöÀç ÀĞ±â Ä¿¼­ À§Ä¡. ¹ÙÀÌÆ®°¡ ¾Æ´Ï¶ó ºñÆ®´Ù!
		int m_readBitOffset;
		// ±â·ÏµÇ¾î ÀÖ´Â ÃÑ µ¥ÀÌÅÍ Å©±â Áß, ¸Ç ¸¶Áö¸· ¹ÙÀÌÆ® Áß ¸î¹øÂ° ºñÆ®±îÁö ±â·ÏµÇ¾îÀÖ´ÂÁö¸¦ °¡¸®Å²´Ù. 
		// ºñÆ®´ÜÀ§ write¸¦ ÇÒ ¶§ Áõ°¡ÇÑ´Ù.
		int m_bitLengthInOneByte; 

		// ÀÌ °ªÀÌ trueÀÌ¸é read/write scalar°¡ ºñÈ°¼ºµÇ¾î ¹«Á¶°Ç int64·Î ±âÀçµÇ´Â µî,
		// ÆĞÅ¶ ±¸Á¶´Â »ç¿ëÀÚ°¡ ¾Ë ¼ö ÀÖµµ·Ï ´Ü¼øÈ­µÇµÇ ÇÊ¿äÇÑ È¿À²ÀûÀÎ ±â´ÉµéÀÌ »ç¶óÁø´Ù.
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
			
			// count°¡ ÇØÅ·µÇ¾î ¸»µµ ¾ÈµÇ´Â °ªÀÌ¸é ½ÇÆĞ Ã³¸®ÇÏ±â
			// ¹°·Ğ ¸ğµç °æ¿ì¸¦ ÀâÁö´Â ¸øÇÏÁö¸¸ (sizeof elem ¹«¿ëÁö¹°) ±×·¡µµ ÃÖ¼Ò 1¹ÙÀÌÆ®´Â ¾µÅ×´Ï.
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
		¸Ş½ÃÁö·ÎºÎÅÍ µ¥ÀÌÅÍ¸¦ ÀĞ´Â´Ù.
		\param data ÀĞÀº µ¥ÀÌÅÍ°¡ ÀúÀåµÉ °÷
		\param count dataÀÇ ¹ÙÀÌÆ® ´ÜÀ§ Å©±â 
		\return count¸¸Å­ ¼º°øÀûÀ¸·Î ÀĞ¾úÀ¸¸é true.

		\~english 
		Read data from the message. 
		\param data Where the read data will be stored. 
		\param count Byte unit size of the data
		\return True if successfully read as the count


		\~chinese
		?ãáãÓ?ö¢?Ëß¡£
		\param data á¶?ö¢îÜ?Ëß?ğíîÜêÈöÇ¡£
		\param count dataîÜbyte?êÈÓŞá³¡£ 
		\return ?ÓğõÌı¨îÜ?true¡£

		\~japanese
		«á«Ã«»?«¸ª«ªé«Ç?«¿ªò?ªßö¢ªêªŞª¹¡£
		\param data?ªßö¢ªÃª¿«Ç?«¿ª¬ÜÁğíªµªìªëá¶ªÇª¹¡£
		\param count dataªÎ«Ğ«¤«È?êÈªÎ«µ«¤«º
		\return countªÀª±?ªßö¢ªëª³ªÈªËà÷Ííª·ª¿ªétrueªÇª¹¡£
		\~
		*/
		inline  bool Read( uint8_t* data, int count );

		template<typename POD>
		inline  bool Read_POD(POD* data);

		inline  bool CanRead( int count );
		
		/** 
		\~korean
		¸Ş½ÃÁö¿¡ µ¥ÀÌÅÍ¸¦ ±â·ÏÇÑ´Ù.

		\~english 
		Record data in the message
		

		\~chinese
		??ãáãÓ?Ëß¡£

		\~japanese
		«á«Ã«»?«¸ªË«Ç?«¿ªòÑÀ?ª·ªŞª¹¡£
		\~
		*/
		inline void Write(const uint8_t* data, int count)
		{
			// ¾Æ¿¹ ¾µ°Ô ¾øÀ¸¸é splitter test ÀÚÃ¼µµ Á¦³¤´Ù.
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
		ÀĞ±â ÁöÁ¡À» °­Á¦ Á¶Á¤ÇÑ´Ù. ¹ÙÀÌÆ® ´ÜÀ§ÀÌ´Ù.

		\~english 
		Read point is forcibly adjusted. It is in bytes. 

		\~chinese
		Ë­ğ¤?ïÚ?ö¢ò¢ïÃ¡£Byte ?êÈ¡£

		\~japanese
		?ªßö¢ªêò¢ïÃªò?ğ¤ªËğàïÚª·ªŞª¹¡£«Ğ«¤«È?êÈªÇª¹¡£
		\~
		*/
		inline  void SetReadOffset(int offset);

		// »ç¿ëÀÚ´Â ÀÌ ÇÔ¼ö¸¦ È£ÃâÇÏÁö ¸» °Í
		inline  void SetSimplePacketMode(bool isSimplePacketMode);

		/** 
		\~korean
		¸Ş½ÃÁöÀÇ ÇöÀç Å©±â¸¦ ¼³Á¤ÇÑ´Ù.

		\~english 
		Set the current size of the message. 

		\~chinese
		?öÇãáãÓ?î¤îÜÓŞá³¡£

		\~japanese
		«á«Ã«»?«¸ªÎúŞî¤«µ«¤«ºªòàâïÒª·ªŞª¹¡£
		\~
		*/
		inline  void SetLength(int count);
		inline   int GetWriteOffset();

		//////////////////////////////////////////////////////////////////////////
		// Test splitter ±â´É
		// ¼º´É¿¡ ¹Î°¨ÇÏ¹Ç·Î, release build¿¡¼­´Â Á¦°ÅµÇ¾î ÀÖÀ½.
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
			m_msgBuffer.AddCount(sizeof(POD)); // Å©±â¸¦ ´Ã¸®°í
#if defined(__MARMALADE__) || defined(__ANDROID__) || defined(__arm__) // RVCT¸¦ ¾²´Â °æ¿ì __packed keyword¸¦ ¾²¸é µÇÁö¸¸ gcc¸¦ ¾²¹Ç·Î 
			// ARM¿¡¼­´Â 4byte alignÀÌ ¾Æ´Ñ µ¥ÀÌÅÍ¿¡ ¹Ù·Î = ¸¦ ¾²¸é Å©·¡½Ã°¡ ³­´Ù. 
			// µû¶ó¼­ memcpy¸¦ ½áÁÖ¾î¾ß ÇÑ´Ù. ³»ºÎÀûÀ¸·Î non-4byte alignÀ» Ã³¸®ÇÏ±â ¶§¹®ÀÌ´Ù.
			// ¹°·Ğ ´À¸®´Ù. ÇÏÁö¸¸ ¸ğ¹ÙÀÏ Å¬¶óÀÌ¾ğÆ®°¡ ÀÌ°É·Î ¹®Á¦µÇÁö´Â ¾Ê´Â´Ù.
			memcpy(m_msgBuffer.GetData() + oldLength, data, sizeof(POD));
#else
			// x86 °è¿­¿¡¼­´Â ÇÏ±â ¸í·É¾î°¡ non 4byte alignÀÌ¶óµµ Àß ÀÛµ¿ÇÑ´Ù. ´À·Á¼­ ±×·¸Áö.
			*((POD*)(m_msgBuffer.GetData() + oldLength)) = *data; // º¹»ç
#endif
		}

		inline void AdjustWriteOffsetByteAlign()
		{
			// ºñÆ® ´ÜÀ§ ±â·ÏÀ» ÇÏ´ø ÁßÀÌ¶ó ¾²±â Æ÷ÀÎÆ®°¡ byte alignÀÌ ¾Æ´Ï¸é, Á¶Á¤ÇÑ´Ù.
			// ´Ü, ÀÌ°ÍÀ» È£Ãâ ÈÄ¿¡´Â ¹İµå½Ã ÃÖ¼Ò 1 ¹ÙÀÌÆ®¸¦ ±â·ÏÇØ¾ß ÇÑ´Ù. ¾È±×·¯¸é ±â·ÏÇÏ´ø ºñÆ®µéÀº À¯½ÇµÈ´Ù.
			m_bitLengthInOneByte = 0;
		}

	public:
		/** 
		\~korean
		ÀÌ °´Ã¼ÀÇ ¸Ş¸ğ¸® ¹öÆÛ¸¦ outputÀÌ length Å©±â¸¸Å­ ÀĞ¾î°¡´Â ¾ç»óÀ¸·Î ¸¸µéµÇ,
		outputÀº ¿ÜºÎ·Î¼­ ÀÌ °´Ã¼ÀÇ ¹öÆÛ¸¦ ÂüÁ¶ÇÏµµ·Ï ¸¸µç´Ù. 
		¼º´ÉÀ» À§ÇØ »ç¿ëµÇ´Â ÇÔ¼ö´Ù.

		\~english 
		Make the memory buffer of this object as if the output reads as much as the size of the length, the output should be made to refer the buffer of this object. 
		This is the function used for performance.

		\~chinese
		÷êó®?ßÚîÜ?ğíbufferğ¤ğãà÷output?ö¢ßÓ?éÍlengthÓŞá³îÜÏÑØü£¬Ó£ãÀoutputíÂ?èâİ»ğ¤ğãà÷?ÍÅó®?ßÚîÜbuffer¡£
		?ÖõàõÒöŞÅéÄîÜùŞ?¡£

		\~japanese
		ª³ªÎ«ª«Ö«¸«§«¯«ÈªÎ«á«â«ê?«Ğ«Ã«Õ«¡?ªòoutputª¬length«µ«¤«ºªÀª±?ªßö¢ªëªèª¦ªËíÂªëª¬¡¢outputªÏèâİ»ªÈª·ªÆª³ªÎ«ª«Ö«¸«§«¯«ÈªÎ«Ğ«Ã«Õ«¡?ªò?ğÎª¹ªëªèª¦ªËíÂªêªŞª¹¡£
		àõÒöªÎª¿ªáªËŞÅªïªìªë??ªÇª¹¡£
		\~
		*/
		inline  bool ReadWithShareBuffer(CMessage& output, int length);

		/** 
		\~korean
		¸Ş½ÃÁö °´Ã¼¿¡ µ¥ÀÌÅÍ¸¦ Ãß°¡ ±â·ÏÇÑ´Ù.
		bool Å¸ÀÔ »Ó¸¸ ¾Æ´Ï¶ó ´Ù¾çÇÑ Å¸ÀÔÀ» Áö¿øÇÑ´Ù.

		\~english 
		Additionally record the data in the message object. 
		It supports not only Boolean type but also various types. 

		\~chinese
		èÙãáãÓ?ßÚôÕÊ¥???Ëß¡£
		ÜôñşãÀbool?úş£¬?ò¨ò¥ÊÀ??úş¡£

		\~japanese
		«á«Ã«»?«¸«ª«Ö«¸«§«¯«ÈªË«Ç?«¿ªòõÚÊ¥ÑÀ?ª·ªŞª¹¡£
		Bool«¿«¤«×ªÀª±ªÇªÏªÊª¯¡¢Òı?ªÊ«¿«¤«×ªò«µ«İ?«Èª·ªŞª¹¡£
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
		/* Q: ¿Ö long type¿¡ ´ëÇØ¼­´Â Write & Read°¡ ¾ø³ª¿ä?
		A: long, unsigned longÀº ¸î¸î ÄÄÆÄÀÏ·¯¿¡¼­ Å©±â°¡ ¼­·Î ´Ù¸¨´Ï´Ù. 
		VC++ x64¿¡¼­´Â 32bitÀÌÁö¸¸, ´Ù¸¥ ÄÄÆÄÀÏ·¯ Áß ÇÏ³ª´Â x64¿¡¼­ 64bit·Î Ã³¸®µË´Ï´Ù.
		ÀÌ·¯¸é ³×Æ®¿öÅ©·Î ÁÖ°í¹Ş´Â µ¥ÀÌÅÍ Å¸ÀÔÀ¸·Î ºÎÀûÀıÀÔ´Ï´Ù.
		´ë½Å int64_t, uint64_t¸¦ ¾²½Ã±â ¹Ù¶ø´Ï´Ù. ¾Æ´Ï¸é (unsigned)int or (u)int32_t¸¦ ¾²½Ã´øÁö.
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
			// b´Â buffer usage¸¦ ¹Ì¸® ÁöÁ¤Çß¾î¾ß ÇÔ
			WriteArrayT<uint8_t,true,ByteArrayPtr>(*this,b);
		}

		bool Read(ByteArrayPtr &b)
		{
			// b´Â buffer usage¸¦ ¹Ì¸® ÁöÁ¤Çß¾î¾ß ÇÔ
			return ReadArrayT<uint8_t, true, ByteArrayPtr>(*this,b);
		}


		/** 
		\~korean
		scalar compression ±â¹ıÀ¸·Î °ªÀ» ÀĞ´Â´Ù.

		\~english
		Reads with scalar compression technique

		\~chinese
		éÄscalar compressionĞü??ìı?¡£

		\~japanese
		scalar compression ĞüÛöªÇö·ªò?ªßö¢ªêªŞª¹¡£
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
		scalar compression ±â¹ıÀ¸·Î °ªÀ» ±â·ÏÇÑ´Ù. 

		\~english
		Writes with scalar compression technique

		\~chinese
		éÄscalar compressionĞü????¡£

		\~japanese
		scalar compression ĞüÛöªÇö·ªòÑÀ?ª·ªŞª¹¡£ 
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
		¸Ş½ÃÁö °´Ã¼¿¡ µ¥ÀÌÅÍ¸¦ Ãß°¡ ±â·ÏÇÑ´Ù.
		bool Å¸ÀÔ »Ó¸¸ ¾Æ´Ï¶ó ´Ù¾çÇÑ Å¸ÀÔÀ» Áö¿øÇÑ´Ù. 
		\return ¿ÏÀüÈ÷ ÀĞ´Âµ¥ ¼º°øÇÏ¸é true 

		\~english
		Additionally writes data to message object
		Suuports various types including bool type 
		\return True if successful in thorough reading

		\~chinese
		èÙãáãÓ?ßÚôÕÊ¥???Ëß¡£
		Üô?ãÀbool?úş£¬ò¨ò¥ÊÀ??úş¡£
		\return èÇîïîÜ?ìıà÷ÍíîÜ?true

		\~japanese
		«á«Ã«»?«¸«ª«Ö«¸«§«¯«ÈªË«Ç?«¿ªòõÚÊ¥ÑÀ?ª·ªŞª¹¡£
		bool«¿«¤«×ªÀª±ªÇªÏªÊª¯¡¢Òı?ªÊ«¿«¤«×ªò«µ«İ?«Èª·ªŞª¹¡£
		\return èÇîïªË?ªßö¢ªëª³ªÈªËà÷Ííª·ª¿ªétrueªÇª¹¡£
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
		¸Ş½ÃÁöÀÇ ±æÀÌ¸¦ ¾ò´Â´Ù. 

		\~english
		Gets the length of message

		\~chinese
		?ö¢ãáãÓîÜ?Óø¡£

		\~japanese
		«á«Ã«»?«¸ªÎíşªµªòÔğªŞª¹¡£
		\~
		*/
		inline int GetLength() const
		{
			return (int)m_msgBuffer.GetCount();
		}

		/** 
		\~korean
		¸Ş½ÃÁöÀÇ ÇöÀç ÀĞ±â ÁöÁ¡À» ±¸ÇÑ´Ù. ¸®ÅÏ°ªÀº ¹ÙÀÌÆ® ´ÜÀ§´Ù.

		\~english
		Calculates current read point of message. The return value is in byte. 

		\~chinese
		Ï´ãáãÓîÜ?î¤?ö¢ò¢ïÃ¡£Ú÷üŞ?ãÀbyte?êÈ¡£

		\~japanese
		«á«Ã«»?«¸ªÎúŞî¤ªÎ?ªßö¢ªêò¢ïÃªòÏ´ªáªŞª¹¡£«ê«¿?«óö·ªÏ«Ğ«¤«È?êÈªÇª¹¡£
		\~
		 */
		inline int GetReadOffset() const
		{
			return m_readBitOffset >> 3; // ³ª´©±â 8. signedµµ >>¿¬»êÀÚ°¡ Àß ÀÛµ¿ÇÏ´Â±¸¸¶ÀÌ!
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
		¿ÜºÎ ¹öÆÛ¸¦ »ç¿ëÇÏµµ·Ï ¼±¾ğÇÑ´Ù.
		\param buf ¿ÜºÎ ¹öÆÛ Æ÷ÀÎÅÍ
		\param capacity ¿ÜºÎ ¹öÆÛÀÇ Å©±â

		\~english 
		Declare to use an external buffer
		\param buf External buffer pointer
		\param capacity Size of an external buffer

		\~chinese
		à¾åëŞÅéÄèâİ»buffer¡£
		\param buf èâİ»bufferò¦?¡£
		\param capacity èâİ»bufferÓŞá³¡£

		\~japanese
		èâİ»«Ğ«Ã«Õ«¡?ªòŞÅª¦ªèª¦ªËà¾åëª·ªŞª¹¡£
		\param buf èâİ»«Ğ«Ã«Õ«¡?«İ«¤«ó«¿?
		param capacity èâİ»«Ğ«Ã«Õ«¡?«µ«¤«º
		\~
		 */
		inline  void UseExternalBuffer(uint8_t* buf, int capacity);
		
		/** 
		\~korean
		³»ºÎ ¹öÆÛ¸¦ »ç¿ëÇÏµµ·Ï ¼±¾ğÇÑ´Ù.

		\~english
		Declares to use internal buffer

		\~chinese
		à¾åëŞÅéÄ?İ»buffer¡£

		\~japanese
		?İ»«Ğ«Ã«Õ«¡?ªòŞÅª¦ªèª¦ªËà¾åëª·ªŞª¹¡£
		\~
		 */
		inline  void UseInternalBuffer();

		/** 
		\~korean
		»ç¿ëÇÏ´ø ¹öÆÛ¸¦ ¿ÏÀüÈ÷ ¸®¼ÂÇÏ°í, »õ·Î ¿ÜºÎ ¶Ç´Â ³»ºÎ ¹öÆÛ¸¦ »ç¿ëÇÏµµ·Ï ¼±¾ğÇÑ´Ù.
		- UseExternalBuffer, UseInternalBuffer¸¦ Àç»ç¿ëÇÏ·Á¸é ¹İµå½Ã ÀÌ°ÍÀ» È£ÃâÇØ¾ß ÇÑ´Ù.
		ÀÌ·¯ÇÑ ¸Ş¼­µå°¡ µû·Î ÀÖ´Â ÀÌÀ¯´Â »ç¿ëÀÚ°¡ ½Ç¼öÇÏ´Â °ÍÀ» ¹æÁöÇÏ±â À§ÇØ¼­´Ù. 
		- ÀÌ ¸Ş¼­µå È£Ãâ ÈÄ¿¡´Â read offset°ú ¸Ş½ÃÁö Å©±â°¡ ÃÊ±âÈ­µÈ´Ù.

		\~english
		Completely resets the PROUD_API void UseExternalBuffer(BYTE* buf, int capacity)r
		- This must be called in order to re-use UseExternalBuffer and UseInternalBuffer.
		  The reasone why this kind of method exists is to prevent for user to make mistakes.
		- After this method is called, the size of read offset and message will be initialized.

		\~chinese
		èÇîï?êÈŞÅéÄîÜbuffer£¬à¾åëñìãæŞÅéÄèâİ»ûäíº?İ»buffer¡£
		- ßÌî¢ŞÅéÄUseExternalBuffer, UseInternalBufferîÜ?ù±?û¼Ğ£??¡£
		?êó??Û°ÛöîÜ×âë¦ãÀ?ÖõÛÁò­éÄ?ã÷?¡£
		- û¼Ğ£ó®Û°Ûöû¼Ğ£ì¤ı¨?ôøã·ûùread offsetûúãáãÓÓŞá³¡£

		\~japanese
		ŞÅªÃªÆª¤ª¿«Ğ«Ã«Õ«¡?ªòèÇîïªË«ê«»«Ã«Èª·ªÆ¡¢ãæª¿ªËèâİ»ªŞª¿ªÏ?İ»«Ğ«Ã«Õ«¡?ªòŞÅª¦ªèª¦ªËà¾åëª·ªŞª¹¡£
		- UseExternalBuffer, UseInternalBufferªòî¢ŞÅéÄª¹ªëª¿ªáªËªÏ¡¢ù±ªºª³ªìªòû¼ªÓõóª·ªÆª¯ªÀªµª¤¡£
		ª³ªÎªèª¦ªÊ«á«½«Ã«Éª¬Ü¬ªËª¢ªë×âë¦ªÏ¡¢«æ?«¶?ªÎÊàêŞª¤ªòÛÁò­ª¹ªëª¿ªáªÇª¹¡£
		- ª³ªÎ«á«½«Ã«Éªòû¼ªÓõóª·ª¿ı­ªËªÏ¡¢read offsetªÈ«á«Ã«»?«¸«µ«¤«ºª¬ôøÑ¢ûùªµªìªŞª¹¡£

		 */
		inline  void UninitBuffer();

		/**
		\~korean
		ÇöÀç ÀĞÀº µ¥ÀÌÅÍ Å©±â¿¡ count¸¦ ´õÇÑ´Ù.

		\~english 
		Add count to the data size read currently. 

		\~chinese
		èÙ?î¤á¶??ËßÓŞá³ß¾ôÕÊ¥count¡£

		\~japanese
		úŞî¤?ªßö¢ªÃª¿«Ç?«¿«µ«¤«ºªËcountªòÊ¥ª¨ªŞª¹¡£
		\~
		*/
		inline  bool SkipRead(int count);

		/**
		\~korean
		¹®ÀÚ¿­ ³Ö±â

		\~english
		Write string

		\~chinese
		?ìıí®İ¬Íú¡£

		\~japanese
		Ùşí®Öªªòìıªìªë
		\~
		*/
		inline  void WriteString(const char* str);

		/**
		\~korean
		¹®ÀÚ¿­ ³Ö±â

		\~english
		Write string

		\~chinese
		?ìıí®İ¬Íú¡£

		\~japanese
		Ùşí®Öªªòìıªìªë
		\~
		*/
		inline  void WriteString(const wchar_t* str);

		/**
		\~korean
		¹®ÀÚ¿­ ³Ö±â

		\~english
		Write string

		\~chinese
		?ìıí®İ¬Íú¡£

		\~japanese
		Ùşí®Öªªòìıªìªë
		\~
		*/
		inline  void WriteString(const Proud::StringA &str);

		/**
		\~korean
		¹®ÀÚ¿­ ³Ö±â

		\~english
		Write string

		\~chinese
		?ìıí®İ¬Íú¡£

		\~japanese
		Ùşí®Öªªòìıªìªë
		\~
		*/
		inline  void WriteString(const Proud::StringW &str);
		
		/**
		\~korean
		¹®ÀÚ¿­ ³Ö±â

		\~english
		Write string

		\~chinese
		?ìıí®İ¬Íú¡£

		\~japanese
		\~
		*/
		inline  void WriteString(const std::string &str)
		{
			WriteString(str.c_str());
		}

		/**
		\~korean
		¹®ÀÚ¿­ ³Ö±â

		\~english
		Write string

		\~chinese
		?ìıí®İ¬Íú¡£

		\~japanese
		Ùşí®Öªªòìıªìªë
		\~
		*/
		inline  void WriteString(const std::wstring &str)
		{	
			WriteString(str.c_str());
		}

		/**
		\~korean
		¹®ÀÚ¿­ ²¨³»±â

		\~english
		Read string

		\~chinese
		?õóí®İ¬Íú¡£

		\~japanese
		Ùşí®Öªªòìıªìªë
		\~
		*/
		inline  bool ReadString(Proud::StringA &str);

		/**
		\~korean
		¹®ÀÚ¿­ ²¨³»±â

		\~english
		Read string

		\~chinese
		?õóí®İ¬Íú¡£

		\~japanese
		Ùşí®Öªªòìıªìªë
		\~
		*/
		inline  bool ReadString(Proud::StringW &str);
		
		/**
		\~korean
		¹®ÀÚ¿­ ²¨³»±â

		\~english
		Read string

		\~chinese
		?õóí®İ¬Íú¡£

		\~japanese
		Ùşí®Öªªòìıªìªë
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
		¹®ÀÚ¿­ ²¨³»±â

		\~english
		Read string 

		\~chinese
		?õóí®İ¬Íú¡£

		\~japanese
		Ùşí®Öªªòìıªìªë
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
		bitCount ¸¸Å­ÀÇ ºñÆ® µ¥ÀÌÅÍ¸¦ ±â·ÏÇÑ´Ù.
		- ¸¸¾à ¾Õ¼­ bit¸¦ ±â·ÏÇÏ´ø ÁßÀÌ¶ó bit offset > 0ÀÎ °æ¿ì »ç¿ë °¡´ÉÇÑ ÀÜ¿© ºñÆ®¿¡ ÀÌ¾î¼­ ±â·ÏµÈ´Ù.
		- ¸¸¾à bit offset > 0ÀÎ »óÅÂ¿¡¼­ Write()·Î ÀÎÇØ byte ´ÜÀ§ ¾²±â¸¦ ÇÒ °æ¿ì ÀÜ¿© ºñÆ®´Â ¹«½ÃµÇ°í
		»õ ¹ÙÀÌÆ®¿¡¼­ ¾²±â°¡ Àç°³µÈ´Ù. Áï byte assignÀ¸·Î Á¶Á¤µÈ´Ù. 
		µû¶ó¼­ È¿°úÀûÀÎ ºñÆ® »ç¿ëÀ» À§ÇØ¼­ ºñÆ® ÇÊµå°ú ºñÆ®°¡ ¾Æ´Ñ ÇÊµå¸¦ ³¢¸®³¢¸® ¸ğ¾Æ¼­ ÀĞ±â/¾²±â¸¦ ÇØ¾ß ÇÑ´Ù.

		\~english
		Writes bit data as muuch of bitCount
		- If bit offset > 0 due to prior bit writing then writes continuous to usable remaining bits.
		- When writing byte unit due to Write() when bit offset > 0 then remaining bits will be ignored and the writing will be continued at a new byte. In other words, it will be modified to byte assign. 
		Therefore, to use bits effectively, it must collectively read/write those fields, not fields and bits.

		\~chinese
		??ßÓ?éÍbitCountîÜbit?Ëß¡£
		- åıÍıñıîñãÀ??bitñıñéì»bit offset > 0îÜï×?îÜ?£¬?ïÈó·î¤Ê¦ì¤ŞÅéÄîÜ?×ºbitß¾?ú¼??¡£
		- åıÍı?bit offset > 0îÜï×?£¬ì×?Write()£¬é©?à÷byte?êÈîÜ?£¬?×ºbit?ù¬ûì?£¬?ãæîÜbit?ã·?ìı¡£??ïÚ?byte assign¡£
		?Öõêóüùò¢ŞÅéÄbit£¬ö©ó¢ãÀbit?æ´ûúÜôãÀbitîÜ?æ´ñıı¨?ú¼?/?¡£

		\~japanese
		bitCount ªÀª±ªÎ«Ó«Ã«È«Ç?«¿ªòÑÀ?ª·ªŞª¹¡£
		- ªâª·¡¢à»ªË«Ó«Ã«ÈªòÑÀ?ª·ªÆª¤ª¿ªÎªÇ¡¢bit offset > 0ªÇª¢ªëíŞùê¡¢ŞÅéÄÊ¦ÒöªÊ?åù«Ó«Ã«ÈªË?ª±ªÆÑÀ?ªµªìªŞª¹¡£
		- ªâª·¡¢bit offset > 0ªÇª¢ªë?÷¾ªÇ¡¢Write()ªËªèªÃªÆ¡¢byte?êÈªÎßöª­?ªßªòª¹ªëíŞùê¡¢?åù«Ó«Ã«ÈªÏÙíãÊªµªìªÆãæª·ª¤«Ğ«¤«ÈªÇßöª­?ªßª¬î¢ËÒªµªìªŞª¹¡£?ªÁ¡¢byte assignªËğàïÚªµªìªŞª¹¡£ªèªÃªÆ¡¢?ÍıîÜªÊ«Ó«Ã«ÈŞÅéÄªÎª¿ªáªËªÏ«Ó«Ã«È«Õ«£?«ë«ÉªÈ«Ó«Ã«ÈªÇªÏªÊª¤«Õ«£?«ë«ÉÔÒŞÍªòó¢ªáªÆ?ªßö¢ªê/ßöª­?ªßªòª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£
		
		\~
		 */
		inline  void WriteBits(uint8_t* src,int srcBitLength);

		/** 
		\~korean
		bitCount¸¸Å­ÀÇ ºñÆ® µ¥ÀÌÅÍ¸¦ ÀĞ¾îµéÀÎ´Ù.
		\return ÀĞ´Âµ¥ ¼º°øÇÏ¸é true¸¦ ¸®ÅÏÇÑ´Ù. ÀĞÀ» bit°¡ ¸ğÀÚ¶ó¸é false¸¦ ¸®ÅÏ.
		- ¸¸¾à ¾Õ¼­ bit¸¦ ÀĞ´ø ÁßÀÌ¶ó bit offset > 0ÀÎ °æ¿ì »ç¿ë °¡´ÉÇÑ ÀÜ¿© ºñÆ®¿¡ ÀÌ¾î¼­ ÀĞ´Â´Ù.
		- ¸¸¾à bit offset>0ÀÎ »óÅÂ¿¡¼­ Read()·Î ÀÎÇØ byte ´ÜÀ§ ÀĞ±â¸¦ ÇÒ °æ¿ì ÀÜ¿© ºñÆ®´Â ¹«½ÃµÇ°í
		»õ ¹ÙÀÌÆ®¿¡¼­ ÀĞ±â°¡ Àç°³µÈ´Ù. Áï byte assignÀ¸·Î Á¶Á¤µÈ´Ù. 
		µû¶ó¼­ È¿°úÀûÀÎ ºñÆ® »ç¿ëÀ» À§ÇØ¼­ ºñÆ® ÇÊµå°ú ºñÆ®°¡ ¾Æ´Ñ ÇÊµå¸¦ ³¢¸®³¢¸® ¸ğ¾Æ¼­ ÀĞ±â/¾²±â¸¦ ÇØ¾ß ÇÑ´Ù. 

		\~english
		Reads bit data as much of bitCount
		\return Returns true if reading is successful. Returns false when there are not enough bits to read.
		- If bit offset > 0 due to prior bit reading then reads continuous to usable remaining bits.
		- When reading byte unit due to Read() when bit offset > 0 then remaining bits will be ignored and the reading will be continued at a new byte. In other words, it will be modified to byte assign. 
		Therefore, to use bits effectively, it must collectively read/write those fields, not fields and bits.

		\~chinese
		?ìıßÓ?éÍbitCountîÜbit?Ëß¡£
		\return ?ìıà÷ÍíîÜ?Ú÷üŞture¡£ÌÀá´é©?îÜbitîÜ?Ú÷üŞfalse¡£
		- åıÍıñıîñãÀ??bitñıñéì»bit offset > 0îÜï×?îÜ?£¬ïÈó·?Ê¦ì¤ŞÅéÄîÜ?×ºbitñé?ö¢¡£		-åıÍıãÀbit offset > 0îÜï×?£¬ì×?Read()£¬é©?à÷byte?êÈîÜ?£¬?×ºbit?ù¬ûì?£¬?ãæbitß¾?ã·?ö¢¡£??ïÚ?byte assign¡£
		?Öõêóüùò¢ŞÅéÄbit£¬ö©ó¢ãÀbit?æ´ûúÜôãÀbitîÜ?æ´ñıı¨?ú¼?/?¡£

		\~japanese
		bitCountªÀª±ªÎ«Ó«Ã«È«Ç?«¿ªò?ªßö¢ªêªŞª¹¡£
		ReturnªÎ?ªßö¢ªêªËà÷Ííª·ª¿ªétrueªò«ê«¿?«óª·ªŞª¹¡£?ªßö¢ªëbitª¬ğëªêªÊª±ªìªĞfalseªò«ê«¿?«óª·ªŞª¹¡£
		- ªâª·¡¢à»ªË«Ó«Ã«Èªò?ªóªÇª¤ª¿ªÎªÇ¡¢bit offset > 0ªÇª¢ªëíŞùê¡¢ŞÅéÄÊ¦ÒöªÊ?åù«Ó«Ã«ÈªË?ª±ªÆ?ªßö¢ªêªŞª¹¡£
		- ªâª·¡¢bit offset > 0ªÇª¢ªë?÷¾ªÇ¡¢Read()ªËªèªÃªÆ¡¢byte?êÈªÎ?ªßö¢ªêªòª¹ªëíŞùê¡¢?åù«Ó«Ã«ÈªÏÙíãÊªµªìªÆãæª·ª¤«Ğ«¤«ÈªÇ?ªßö¢ªêª¬î¢ËÒªµªìªŞª¹¡£?ªÁ¡¢byte assignªËğàïÚªµªìªŞª¹¡£ªèªÃªÆ¡¢?ÍıîÜªÊ«Ó«Ã«ÈŞÅéÄªÎª¿ªáªËªÏ«Ó«Ã«È«Õ«£?«ë«ÉªÈ«Ó«Ã«ÈªÇªÏªÊª¤«Õ«£?«ë«ÉÔÒŞÍªòó¢ªáªÆ?ªßö¢ªê/ßöª­?ªßªòª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£

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

#ifdef _MSC_VER // ¸Ç À§ÀÇ ÁÖ¼® Âü°í
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

	//// ·ÎÄÃ º¯¼ö·Î Àá±ñ ¾µ °æ¿ì À¯¿ë=>´õ ÀÌ»ó ¾È¾¸. UseInternalBufferÀÚÃ¼°¡ obj-pool±â´ÉÀ¸·Î ÀÎÇØ rellocÈ½¼ö°¡ Á¡Â÷ ÁÙ¾îµå´Ï±î.
	//class CSendingMessage: public CMessage
	//{
	//public:
	//	CSendingMessage()
	//	{
	//		UseInternalBuffer();
	//		// ¹Ì¸® °ø°£À» È® È®º¸ÇÑ ÈÄ ´Ù½Ã ÇØÁ¦ÇØ¹ö¸°´Ù. ÀÌ·¸°Ô ÇØ¼­ ÀçÇÒ´ç È½¼ö¸¦ 0À¸·Î ¸¸µç´Ù.
	//		// ¿¹Àü¿¡´Â Proud::CNetConfig::MessageMaxLength¸¦ ³Ö¾úÀ¸³ª, ÀÌ°ÍÀ» ³ÖÀ¸¸é CRT heapÀ» Á÷Á¢ Á¢±ÙÇØ¹ö¸®¹Ç·Î Ä³»ğÁúÀÌ µÈ´Ù.
	//		// µû¶ó¼­ °í¼Ó ÇÒ´çÀ» ÇÏ´Â CFastHeap::DefaultAccelBlockSizeLimit¸¦ ½á¾ß ÇÑ´Ù.
	//		SetLength(CFastHeap::DefaultAccelBlockSizeLimit);
	//		SetLength(0);
	//	}
	//};

	// ------- ÀÌ°Ç ´õ ÀÌ»ó ¾È¾´´Ù. ProudNetConfig::MessageMaxLength¸¦ ·±Å¸ÀÓ¿¡¼­ ¼öÁ¤ÇÒ ¼ö ÀÖ¾î¾ß ÇÏ´Ï±î.
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

	// ·ÎÄÃ º¯¼ö·Î Àá±ñ ¾µ °æ¿ì À¯¿ë
	// ÁÖÀÇ: ¹öÆÛ Å©±â°¡ ¸Å¿ì ÀÛÀ¸¹Ç·Î Á¶½ÉÇØ¼­ ¾µ °Í! °¡º¯ Å©±â µ¥ÀÌÅÍ¸¦ ³Ö°Å³ª ÇØ¼­´Â °ï¶õ!
	// ** PS4&UE4 Æ÷ÆÃÇÏ´ø »óÈ²¿¡¼­, ÀÌ°ÍÀÌ °íÁ¤ Å©±â ¹è¿­À» ³»ÀåÇß´õ´Ï, ¿À·ù°¡ ¹ß»ıÇß¾ú´Ù. ±×¸®°í ÀÌ Å¬·¡½º´Â
	// obj-pool ±â´ÉÀÌ ¾ø´ø ½ÃÀı¿¡ µé¾î°¬´ø ±â´ÉÀÌ´Ù. µû¶ó¼­ Áö±İÀº ÀÌ Å¬·¡½º¸¦ ¾ø¾Öµµ µÈ´Ù.
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
	ÀÓ½ÃÀûÀ¸·Î splitter test¸¦ ²ô°íÀÚ ÇÒ ¶§ ÀÌ °´Ã¼¸¦ ·ÎÄÃ º¯¼ö·Î µÖ¼­ ¾²µµ·Ï ÇÑ´Ù.
	- ÁÖ·Î serialize ÇÔ¼ö ³»ºÎ¿¡¼­ ¾´´Ù.
	- CSendFragRefs¿¡¼­ ÇÊ¿äÇØ¼­ ³ÖÀº Å¬·¡½º 

	\~english
	To temporarily turn off splitter test, this object can be as a local variable.
	- Mainly use in inside of serialize function
	- Class added since required by CSendFragRefs

	\~chinese
	ßÌ????splitter testîÜ?ı¦£¬é©÷êó®?ßÚ×º?Üâò¢??ì»ŞÅéÄ¡£
	- ñ«é©î¤serializeùŞ??İ»ŞÅéÄ¡£
	- î¤ CSendFragRefs%×ìâÍé©ì»?ìıîÜ?¡£

	\~japanese
	×üãÁîÜªËsplitter testªò«ª«Õª·ª¿ª¤íŞùê¡¢ª³ªÎ«ª«Ö«¸«§«¯«Èªò«í?«««ë??ªËöÇª¤ªÆŞÅª¦ªèª¦ªËª·ªŞª¹¡£
	- ñ«ªË serialize??ªÎ?İ»ªÇŞÅª¤ªŞª¹¡£
	- CSendFragRefsªÇù±é©ªÊªÎªÇìıªìª¿«¯«é«¹ 
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