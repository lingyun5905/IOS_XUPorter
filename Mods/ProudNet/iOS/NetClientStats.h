/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 177 92 124 113 87 79 17 155 171 239 138 133 88 235 28 112 146 102 93 52 214 131 240 31 138 179 248 115 127 118 107 31 112 91 111 14 243 1 121 131 22 69 144 19 214 101 65 133 253 32 122 175 12 198 63 134 23 240 109 90 59 142 194 194 160 148 139 101 68 220 217 181 32 240 36 47 59 74 18 182 145 116 17 29 255 115 236 11 29 111 122  */
#pragma once

#include "NetCoreStats.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/**
	\~korean
	Å¬¶óÀÌ¾ğÆ®ÀÇ »óÈ² Åë°è Á¤º¸ÀÔ´Ï´Ù.
	¼º´É ÃøÁ¤ µî¿¡¼­ »ç¿ëµË´Ï´Ù.
	
	\~english
	Client status information.
	Used for performance check.
	
	\~chinese
	ËÔ?Ó®????ãáãÓ¡£
	éÄéÍàõÒö??¡£
	
	\~japanese
	«¯«é«¤«¢«ó«ÈªÎ?üÏªÎ÷ÖÍªï×ÜÃªÇª¹¡£
	«Ñ«Õ«©?«Ş«ó«¹ªÎö´ïÒÔõªÇŞÅªïªìªÆª¤ªŞª¹¡£
	*/
	class CNetClientStats :public CNetCoreStats
	{
	public:

		/**
		\~korean
		ÇöÀç ¿¬°áµÇ¾îÀÖ´Â remote peerÀÇ °¹¼ö

		\~english
		Number of remote peer that in currently connected

		\~chinese
		?î¤ì«?ïÈîÜremote peerîÜ??¡£

		\~japanese
		úŞî¤ªÄªÊª¬ªÃªÆª¤ªëremote peerªÎ?
		\~
		*/
		uint32_t m_remotePeerCount;

		/**
		\~korean
		trueÀÌ¸é ¼­¹ö¿ÍÀÇ UDP Åë½ÅÀÌ Á¤»óÀÓÀ» ÀÇ¹ÌÇÑ´Ù.
		falseÀÌ¸é UDP¸¦ ¾²Áö ¸øÇÏ¸ç, ¼­¹ö¿ÍÀÇ unreliable ¸Ş½ÃÂ¡µµ TCP·Î ÁÖ°í¹Ş¾ÆÁö°í ÀÖÀ½À» ÀÇ¹ÌÇÑ´Ù.

		\~english
		true means the UDP communication with server is ok
		Cannot use UDP when false and also means the unreliable messaging with server is done via TCP.

		\~chinese
		TrueîÜ?ëòÚ«ó·?Ü×?ĞïîÜUDP÷×ãáïáßÈ¡£
		FalseîÜ?ÜôÒöŞÅéÄUDP£¬ëòÚ«ó·?unreliable messagingå¥ÜôÒöéÄTCP?ïÈ¡£

		\~japanese
		TrueªÇª¢ªìªĞ«µ?«Ğ?ªÈªÎUDP÷×ãáª¬ïáßÈªÇª¢ªëª³ªÈªòëòÚ«ª·ªŞª¹¡£
		FalseªÇª¢ªìªĞUDPªòŞÅª¨ªº¡¢«µ?«Ğ?ªÈªÎunreliable«á«Ã«»?«¸«ó«°ªâTCPªÇªäªêö¢ªêª¹ªëª³ªÈªòëòÚ«ª·ªŞª¹¡£
		\~
		*/
		bool m_serverUdpEnabled;

		/**
		\~korean
		Direct P2P°¡ µÇ¾îÀÖ´Â remote peerÀÇ °¹¼ö

		\~english
		Number of remote peer that consisted Direct P2P

		\~chinese
		Direct P2PîÜremote peer??¡£

		\~japanese
		Direct P2PªËªÊªÃªÆª¤ªëremote peerªÎ?
		\~
		*/
		uint32_t m_directP2PEnabledPeerCount;


		/**
		\~korean
		TCP, UDP Send Queue¿¡ ³²¾ÆÀÖ´Â ÃÑ Å©±â, Send Queue ÃÑ Å©±â

		\~english
		Total size left in TCP and UDP Send Queue. Total size of the Send Queue


		\~chinese
		TCP, UDP Send Queueñéí¥åùîÜ?îÜÓŞá³, Send QueueîÜ?ÓŞá³

		\~japanese
		TCP, UDP Send QueueªË?ªÃªÆª¤ªë«µ«¤«ºùêÍª¡¢Send QueueªÎ«µ«¤«ºùêÍª
		\~
		*/
		uint32_t m_sendQueueTotalBytes;
		uint32_t m_sendQueueTcpTotalBytes;
		uint32_t m_sendQueueUdpTotalBytes;


		CNetClientStats();

		virtual String ToString() const;
	};
}
#ifdef _MSC_VER
#pragma pack(pop)
#endif