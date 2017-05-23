/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 177 92 124 113 87 79 17 155 171 239 138 133 88 235 28 112 146 102 93 52 214 131 240 31 138 179 248 115 127 118 107 31 112 91 111 14 243 1 121 131 22 69 144 19 214 101 65 133 253 32 122 175 12 198 63 134 23 240 109 90 59 142 194 194 160 148 139 101 68 220 217 181 32 240 36 47 59 74 18 182 145 116 17 29 255 115 236 11 29 111 122  */
#pragma once

#include "PNString.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \~korean »óÈ² Åë°è Á¤º¸ÀÔ´Ï´Ù. 
	\~english Status information.
	\~chinese ????ãáãÓ¡£
	\~japanese ?üÏªÎ÷ÖÍªï×ÜÃªÇª¹¡£
	\~
	*/
	class CNetCoreStats
	{
	public:
		uint64_t m_totalTcpReceiveCount;

		/**
		\~korean
		ÃÑ ¼ö½ÅµÈ TCP ¸Ş½ÃÁöÀÇ ¾ç(byte). RMI »Ó¸¸ ¾Æ´Ï¶ó ProudNet ³»ºÎÀÇ ¸ğµç ÆĞÅ¶ÀÇ Çì´õ±îÁö Æ÷ÇÔÇÑ´Ù.

		\~english
		Amount(byte) of all TCP messages received. This includes RMI and the headers of all packets in ProudNet.

		\~chinese
		?â¥ãáîÜTCPãáãÓÕá£¨byte£©¡£ğ¶ÖõRMI£¬å¥øĞÎÀProudNet?İ»îÜá¶êó?ËßøĞheader¡£

		\~japanese
		áôãáªµªìª¿TCP«á«Ã«»?«¸ªÎ?Õá(byte)¡£RMIªÀª±ªÇªÏªÊª¯¡¢ProudNet?İ»ªÎîïªÆªÎ«Ñ«±«Ã«ÈªÎ«Ø«Ã«À?ªŞªÇùßªáªŞª¹¡£
		\~
		*/
		uint64_t m_totalTcpReceiveBytes;

		uint64_t m_totalTcpSendCount;

		/**
		\~korean
		ÃÑ ¼Û½ÅµÈ TCP ¸Ş½ÃÁöÀÇ ¾ç(byte). RMI »Ó¸¸ ¾Æ´Ï¶ó ProudNet ³»ºÎÀÇ ¸ğµç ÆĞÅ¶ÀÇ Çì´õ±îÁö Æ÷ÇÔÇÑ´Ù.

		\~english
		Amount(byte) of all TCP messages sent. This includes RMI and the headers of all packets in ProudNet.

		\~chinese
		??áêîÜTCPãáãÓÕá£¨byte£©¡£ğ¶ÖõRMI£¬å¥øĞÎÀProudNet?İ»îÜá¶êó?ËßøĞheader¡£

		\~japanese
		áêãáªµªìª¿TCP«á«Ã«»?«¸ªÎ?Õá(byte)¡£RMIªÀª±ªÇªÏªÊª¯¡¢ProudNet?İ»ªÎîïªÆªÎ«Ñ«±«Ã«ÈªÎ«Ø«Ã«À?ªŞªÇùßªáªŞª¹¡£
		\~
		*/
		uint64_t m_totalTcpSendBytes;
		
		/**
		\~korean
		ÃÑ ¼ö½ÅµÈ UDP ¸Ş½ÃÁöÀÇ °¹¼ö. RMI »Ó¸¸ ¾Æ´Ï¶ó ProudNet ³»ºÎÀÇ ¸ğµç ÆĞÅ¶ÀÇ Çì´õ±îÁö Æ÷ÇÔÇÑ´Ù.

		\~english
		Number of all UDP messages received. This includes RMI and the headers of all packets in ProudNet.

		\~chinese
		?â¥ãáîÜUDPãáãÓ??¡£ğ¶ÖõRMI£¬å¥øĞÎÀProudNet?İ»îÜá¶êó?ËßøĞheader¡£

		\~japanese
		áôãáªµªìª¿UDP«á«Ã«»?«¸ªÎ??¡£RMIªÀª±ªÇªÏªÊª¯¡¢ProudNet?İ»ªÎîïªÆªÎ«Ñ«±«Ã«ÈªÎ«Ø«Ã«À?ªŞªÇùßªáªŞª¹¡£
		\~
		*/
		uint64_t m_totalUdpReceiveCount;
		/**
		\~korean
		ÃÑ ¼ö½ÅµÈ UDP ¸Ş½ÃÁöÀÇ ¾ç(byte). RMI »Ó¸¸ ¾Æ´Ï¶ó ProudNet ³»ºÎÀÇ ¸ğµç ÆĞÅ¶ÀÇ Çì´õ±îÁö Æ÷ÇÔÇÑ´Ù.

		\~english
		Amount(byte) of all UDP messages received. This includes RMI and the headers of all packets in ProudNet

		\~chinese
		?â¥ãáîÜUDPãáãÓÕá£¨byte£©¡£ğ¶ÖõRMI£¬å¥øĞÎÀProudNet?İ»îÜá¶êó?ËßøĞheader¡£

		\~japanese
		áôãáªµªìª¿UDP«á«Ã«»?«¸ªÎ?Õá£¨byte£©¡£RMIªÀª±ªÇªÏªÊª¯¡¢ProudNet?İ»ªÎîïªÆªÎ«Ñ«±«Ã«ÈªÎ«Ø«Ã«À?ªŞªÇùßªáªŞª¹¡£
		\~
		*/
		uint64_t m_totalUdpReceiveBytes;

		/**
		\~korean
		ÃÑ ¼Û½ÅµÈ UDP ¸Ş½ÃÁöÀÇ ¾ç(byte). RMI »Ó¸¸ ¾Æ´Ï¶ó ProudNet ³»ºÎÀÇ ¸ğµç ÆĞÅ¶ÀÇ Çì´õ±îÁö Æ÷ÇÔÇÑ´Ù.

		\~english
		Amount(byte) of all UDP messages sent. This includes RMI and the headers of all packets in ProudNet.

		\~chinese
		??áêîÜUDPãáãÓÕá£¨byte£©¡£ğ¶ÖõRMI£¬å¥øĞÎÀProudNet?İ»îÜá¶êó?ËßøĞheader¡£

		\~japanese
		áêãáªµªìª¿UDP«á«Ã«»?«¸ªÎ?Õá£¨byte£©¡£RMIªÀª±ªÇªÏªÊª¯¡¢ProudNet?İ»ªÎîïªÆªÎ«Ñ«±«Ã«ÈªÎ«Ø«Ã«À?ªŞªÇùßªáªŞª¹¡£
		\~
		*/
		uint64_t m_totalUdpSendBytes;

		/**
		\~korean
		ÃÑ ¼Û½ÅµÈ UDP ¸Ş½ÃÁöÀÇ °¹¼ö. RMI »Ó¸¸ ¾Æ´Ï¶ó ProudNet ³»ºÎÀÇ ¸ğµç ÆĞÅ¶ÀÇ Çì´õ±îÁö Æ÷ÇÔÇÑ´Ù.

		\~english
		Number of all UDP messages sent. This includes RMI and the headers of all packets in ProudNet.

		\~chinese
		??áêîÜUDPãáãÓ??¡£ğ¶ÖõRMI£¬å¥øĞÎÀProudNet?İ»îÜá¶êó?ËßøĞheader¡£

		\~japanese
		áêãáªµªìª¿UDP«á«Ã«»?«¸ªÎ??¡£RMIªÀª±ªÇªÏªÊª¯¡¢ProudNet?İ»ªÎîïªÆªÎ«Ñ«±«Ã«ÈªÎ«Ø«Ã«À?ªŞªÇùßªáªŞª¹¡£
		\~
		*/
		uint64_t m_totalUdpSendCount;

		inline uint64_t GetTotalReceiveBytes()
		{
			return m_totalTcpReceiveBytes + m_totalUdpReceiveBytes;
		}

		/**
		\~korean
		ÃÑ ¼ö½ÅµÈ ¸Ş½ÃÁöÀÇ ¾ç(byte). RMI »Ó¸¸ ¾Æ´Ï¶ó ProudNet ³»ºÎÀÇ ¸ğµç ÆĞÅ¶ÀÇ Çì´õ±îÁö Æ÷ÇÔÇÑ´Ù.

		\~english
		Amount(byte) of all messages sent. This includes RMI and the headers of all packets in ProudNet.

		\~chinese
		?â¥ãáîÜãáãÓÕá£¨byte£©¡£ğ¶ÖõRMI£¬å¥øĞÎÀProudNet?İ»îÜá¶êó?ËßøĞheader¡£

		\~japanese
		áôãáªµªìª¿«á«Ã«»?«¸ªÎ?Õá£¨byte£©¡£RMIªÀª±ªÇªÏªÊª¯¡¢ProudNet?İ»ªÎîïªÆªÎ«Ñ«±«Ã«ÈªÎ«Ø«Ã«À?ªŞªÇùßªáªŞª¹¡£
		\~
		*/
#if defined(_MSC_VER)
		__declspec(property(get = GetTotalReceiveBytes)) uint64_t m_totalReceiveBytes;
#endif


		inline uint64_t GetTotalSendCount()
		{
			return m_totalTcpSendCount + m_totalUdpSendCount;
		}
		inline uint64_t GetTotalReceiveCount()
		{
			return m_totalTcpReceiveCount + m_totalUdpReceiveCount;
		}
		inline uint64_t GetTotalSendBytes()
		{
			return m_totalTcpSendBytes + m_totalUdpSendBytes;
		}
		/**
		\~korean
		ÃÑ ¼Û½ÅµÈ ¸Ş½ÃÁöÀÇ °¹¼ö. RMI »Ó¸¸ ¾Æ´Ï¶ó ProudNet ³»ºÎÀÇ ¸ğµç ÆĞÅ¶ÀÇ Çì´õ±îÁö Æ÷ÇÔÇÑ´Ù.

		\~english
		Number of all messages sent. This includes RMI and the headers of all packets in ProudNet.

		\~chinese
		?â¥ãáîÜãáãÓ??¡£ğ¶ÖõRMI£¬å¥øĞÎÀProudNet?İ»îÜá¶êó?ËßøĞheader¡£

		\~japanese
		áêãáªµªìª¿«á«Ã«»?«¸ªÎ??¡£RMIªÀª±ªÇªÏªÊª¯¡¢ProudNet?İ»ªÎîïªÆªÎ«Ñ«±«Ã«ÈªÎ«Ø«Ã«À?ªŞªÇùßªáªŞª¹¡£
		\~
		*/
#if defined (_MSC_VER)
		__declspec(property(get = GetTotalSendCount)) uint64_t m_totalSendCount;

		/**
		\~korean
		ÃÑ ¼ö½ÅµÈ ¸Ş½ÃÁöÀÇ °¹¼ö. RMI »Ó¸¸ ¾Æ´Ï¶ó ProudNet ³»ºÎÀÇ ¸ğµç ÆĞÅ¶ÀÇ Çì´õ±îÁö Æ÷ÇÔÇÑ´Ù.

		\~english
		Number of all received messages. This includes RMI and the headers of all packets in ProudNet.

		\~chinese
		?â¥ãáîÜãáãÓ??¡£ğ¶ÖõRMI£¬å¥øĞÎÀProudNet?İ»îÜá¶êó?ËßøĞheader¡£

		\~japanese
		áôãáªµªìª¿«á«Ã«»?«¸ªÎ??¡£RMIªÀª±ªÇªÏªÊª¯¡¢ProudNet?İ»ªÎîïªÆªÎ«Ñ«±«Ã«ÈªÎ«Ø«Ã«À?ªŞªÇùßªáªŞª¹¡£
		\~
		*/
		__declspec(property(get = GetTotalReceiveCount)) uint64_t m_totalReceiveCount;

		/**
		\~korean
		ÃÑ ¼Û½ÅµÈ ¸Ş½ÃÁöÀÇ ¾ç(byte). RMI »Ó¸¸ ¾Æ´Ï¶ó ProudNet ³»ºÎÀÇ ¸ğµç ÆĞÅ¶ÀÇ Çì´õ±îÁö Æ÷ÇÔÇÑ´Ù.

		\~english
		Amount(byte) of all sent messages. This includes RMI and the headers of all packets in ProudNet.

		\~chinese
		?â¥ãáîÜãáãÓîÜÕá£¨byte£©¡£ğ¶ÖõRMI£¬å¥øĞÎÀProudNet?İ»îÜá¶êó?ËßøĞheader¡£

		\~japanese
		áêãáªµªìª¿«á«Ã«»?«¸ªÎ?Õá£¨byte£©¡£RMIªÀª±ªÇªÏªÊª¯¡¢ProudNet?İ»ªÎîïªÆªÎ«Ñ«±«Ã«ÈªÎ«Ø«Ã«À?ªŞªÇùßªáªŞª¹¡£
		\~
		*/
		__declspec(property(get = GetTotalSendBytes)) uint64_t m_totalSendBytes;
		
#endif

		CNetCoreStats();

		/**
		\~korean
		ÀÌ °´Ã¼ÀÇ ³»¿ë¹°À» Ç¥ÇöÇÏ´Â ¹®ÀÚ¿­À» ¸®ÅÏÇÕ´Ï´Ù.

		\~english
		Returns a string that represents this object.

		\~chinese
		Ú÷üŞøúãÆ??ßÚîÜí®İ¬Íú¡£

		\~japanese
		ª³ªÎ«ª«Ö«¸«§«¯«ÈªÎ?é»ªòøúª¹«¹«È«ê«ó«°ªò«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		virtual String ToString() const = 0;
	};
}
#ifdef _MSC_VER
#pragma pack(pop)
#endif