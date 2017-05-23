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

#include "BasicTypes.h"
#include "FakeClr.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	class CThreadPool;

	/** \addtogroup net_group
	*  @{
	*/

	/**
	\~korean
	¼­¹ö¿¡ ¿¬°áÇÏ±â À§ÇÑ Á¤º¸ ±¸Á¶Ã¼

	\~english
	Informtion structure of making server connection

	\~chinese
	?Öõ?ïÈÜ×?ĞïîÜãáãÓ?ğã?¡£

	\~japanese
	«µ?«Ğ?ªËïÈ?ª¹ªëª¿ªáªÎï×ÜÃÏ°ğã?
	\~
	 */
	class CNetConnectionParam
	{
	public:
		/**
		\~korean
		¿¬°áÇÒ ¼­¹öÀÇ ÁÖ¼Ò
		- ¿¹: 111.222.111.222(IP ÁÖ¼Ò½Ä) È¤Àº game.mydomain.net(È£½ºÆ® ÀÌ¸§½Ä)
		- ½ºÆ®·¹½º Å×½ºÆ®¸¦ ÇÏ´Â °æ¿ì¿¡ ÇÑ²¨¹ø¿¡ ¸¹Àº Å¬¶óÀÌ¾ğÆ®°¡ ¼­¹ö¿¡ Á¢¼ÓÇØ¾ß ÇÕ´Ï´Ù. ÀÌ·¯ÇÑ °æ¿ì
		¼­¹ö ÁÖ¼Ò°¡ È£½ºÆ® ÀÌ¸§½ÄÀÎ °æ¿ì Á¢¼Ó ¼Óµµ°¡ ¸Å¿ì ´À¸± ¼ö ÀÖ½À´Ï´Ù. µû¶ó¼­ ½ºÆ®·¹½º Å×½ºÆ®¸¦ ÇÒ °æ¿ì
		¼­¹ö ÁÖ¼Ò·Î IP ÁÖ¼Ò½ÄÀ» ¾²´Â °ÍÀ» ±ÇÀåÇÕ´Ï´Ù.

		\~english
		Address of server to coneec to
		- ex: 111.222.111.222(IP address) or game.mydomain.net(host name)
		- During a stress test, lots of clients need to be connected to the server at the same time.
		If the server address is a type of a host name, it can be seriously laggy.
		It is strongly recommended to use IP address format for server address.

		\~chinese
		é©?ïÈîÜÜ×?Ğïò¢ò£¡£
		- ÖÇ£º111.222.111.222£¨IP ò¢ò£ãÒ£©ûä game.mydomain.net£¨ñ«ÏõÙ£ãÒ£©¡£
		- ñ®?Õô??îÜï×?ìéó­é©?ïÈÒı?ËÔ?Ó®¡£??ï×?Ü×?Ğïò¢ò£ãÀñ«ÏõÙ£ãÒîÜ?£¬?ïÈáÜÓøÊ¦Òö??Ø·¡£ì×ó®ñ®?Õô??îÜ?ı¦Ëï?÷êIPò¢ò£ãÒéÄ?Ü×?Ğïò¢ò£¡£

		\~japanese
		ïÈ?ª¹ªë«µ?«Ğ?ªÎ«¢«É«ì«¹
		- ÖÇ: 111.222.111.222(IP«¢«É«ì«¹û¡ãÒ)ªŞª¿ªÏ game.mydomain.net(«Û«¹«ÈÙ£û¡ãÒ)
		- «¹«È«ì«¹«Æ«¹«Èªòª¹ªëíŞùêªËìéÓøªËÒıª¤«¯«é«¤«¢«ó«Èª¬«µ?«Ğ?ªËïÈ?ª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£ª³ªÎªèª¦ªÊíŞùê
		«µ?«Ğ?«¢«É«ì«¹ª¬«Û«¹«ÈÙ£û¡ãÒªÇª¢ªëíŞùê¡¢ïÈ?áÜÓøª¬ŞªßÈªË?ª¤íŞùêª¬ª¢ªêªŞª¹¡£ªèªÃªÆ¡¢«¹«È«ì«¹«Æ«¹«Èªòª¹ªëíŞùê¡¢«µ?«Ğ?«¢«É«ì«¹ªÈª·ªÆIP«¢«É«ì«¹û¡ãÒªòŞÅª¦ª³ªÈªòªª?ªáª·ªŞª¹¡£
		\~
		 */
		String m_serverIP;

		/**
		\~korean
		¿¬°áÇÒ ¼­¹öÀÇ TCP Æ÷Æ®ÀÔ´Ï´Ù.

		\~english
		The TCP port of the server to be connected.

		\~chinese
		é©?ïÈîÜÜ×?ĞïTCPÓ®Ï¢¡£

		\~japanese
		ïÈ?ª¹ªë«µ?«Ğ?ªÎTCP«İ?«ÈªÇª¹¡£
		\~
		 */
		uint16_t m_serverPort;

		/**
		\~korean
		IPv4 literal ¹®ÀÚ¿­·Î ¼­¹ö¿¡ Á¢¼ÓÇÏ´õ¶óµµ IPv6 ³×Æ®¿öÅ© Å¬¶óÀÌ¾ğÆ®¿¡¼­ÀÇ Á¢¼ÓÀÌ °¡´ÉÇÏ°Ô ÇØÁÖ´Â º¯¼öÀÔ´Ï´Ù.
		ÀÚ¼¼ÇÑ °ÍÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#apple_ipv6_workaround" >AppleÀÇ IPv6 Á¤Ã¥ ¿ìÈ¸Ã¥</a> ¸¦ Âü°íÇÏ½Ê½Ã¿À.

		\~english
		It is the variable that enables connection from IPv6 network client even if connects to server by IPv4 literal string.
		For more details, please refer to tips for resolving <a target="_blank" href="http://guide.nettention.com/cpp_en#apple_ipv6_workaround" >Apple's IPv6 enforcement.</a>

		\~chinese
		It is the variable that enables connection from IPv6 network client even if connects to server by IPv4 literal string.
		For more details, please refer to tips for resolving <a target="_blank" href="http://guide.nettention.com/cpp_zh#apple_ipv6_workaround" >Apple's IPv6 enforcement.</a>

		\~japanese
		It is the variable that enables connection from IPv6 network client even if connects to server by IPv4 literal string.
		For more details, please refer to tips for resolving <a target="_blank" href="http://guide.nettention.com/cpp_jp#apple_ipv6_workaround" >Apple's IPv6 enforcement.</a>
		*/
		String m_publicDomainName1;

		/** \copydoc m_publicDomainName1 */
		String m_publicDomainName2;

 		/**
		\~korean
		Å¬¶óÀÌ¾ğÆ®¿¡¼­ »ı¼ºÇÏ´Â UDP socketÀÌ »ç¿ëÇÒ local port ¹øÈ£µéÀÔ´Ï´Ù.

		ÀÌ ¸ğµâÀº ¼­¹ö³ª peer¿ÍÀÇ ¿¬°á °¢°¢À» À§ÇØ 1°³ÀÇ UDP port¸¦ »ç¿ëÇÕ´Ï´Ù. ÀÌ¶§ m_localUdpPortPool ¿¡¼­ ÁöÁ¤ÇÑ
		Æ÷Æ® ¹øÈ£µéÀ» local port·Î »ï´Â UDP socketµéÀ» »ı¼ºÇÏ°Ô µË´Ï´Ù. ¸¸¾à m_localUdpPortPool¿¡¼­ ½ÃÁ¤ÇÑ
		Æ÷Æ® ¹øÈ£°¡ ¾ø°Å³ª m_localUdpPortPool¿¡¼­ ÁöÁ¤ÇÑ Æ÷Æ® ¹øÈ£µéÀÌ ¸ğµÎ ´Ù¸¥µ¥¼­ »ç¿ëÁßÀÎ °æ¿ì ÀÓÀÇÀÇ
		Æ÷Æ® ¹øÈ£°¡ ÁöÁ¤µÇ¾î UDP socketÀÌ »ı¼ºµË´Ï´Ù.

		ÀÏ¹İÀûÀ¸·Î´Â m_localUdpPortPool °ªÀº ±×³É µÎ½Ã´Â °ÍÀÌ ÁÁ½À´Ï´Ù. ÇÏÁö¸¸ ÀÇµµÀûÀ¸·Î local UDP socketÀÇ
		port ¹øÈ£¸¦ °­Á¦·Î ÁöÁ¤ÇÏ°íÀÚ ÇÒ ¶§ m_localUdpPortPool ¾È¿¡ ¿øÇÏ½Ã´Â °ªµéÀ» ³ÖÀ¸½Ê½Ã¿À.

		\~english
		Numbers of UDP ports for newly created UDP sockets.

		This host module uses an UDP port for each server or peer connection. Values in m_localUdpPortPool are
		used for binding local UDP port to every UDP socket created by this module. Arbitrary UDP port number
		will be taken if m_localUdpPortPool is empty or no available UDP port corresponding to m_localUdpPortPool
		exists.

		In ordinary case, m_localUdpPortPool should be left unchanged. You should add values into m_localUdpPortPool
		if you want to bind some local UDP ports to UDP sockets created by this module.

		\~chinese
		î¤ËÔ?Ó®ßæà÷îÜUDP socketé©ŞÅéÄîÜlocal port??¡£
		ó®Ù¼??Öõ?Ü×?ĞïûäíºpeerîÜ?ïÈ£¬ÊÀŞÅéÄìé?UDP port¡£???ßæà÷î¤m_localUdpPortPoolò¦ïÒîÜÓ®Ï¢???local portîÜUDP socket¡£
		åıÍı?êóî¤m_localUdpPortPoolò¦ïÒîÜÓ®Ï¢??£¬ûäíºî¤m_localUdpPortPoolò¦ïÒîÜÓ®Ï¢??Ô´î¤?îÜò¢Û°ŞÅéÄñéîÜ?ı¦£¬ìòëòÓ®Ï¢???ù¬ò¦ïÒ?ßæà÷UDP socket¡£
		ìéÚõîÜï×?ù»£¬õÌû¿Üôé©?m_localUdpPortPool?¡£Ó£ãÀßÌË­ğ¤ò¦ïÒlocal UDP socketîÜportîÜ?ı¦£¬èÙm_localUdpPortPool×ìÛ¯á¶âÍîÜ?¡£

		\~japanese
		«¯«é«¤«¢«ó«ÈªÇßæà÷ª¹ªëUDP socketª¬ŞÅéÄª¹ªëLocal portÛã?ªÇª¹¡£
		ª³ªÎ«â«¸«å?«ëªÏ«µ?«Ğ?ªÈª«peerªÈªÎÖ§Ì¿ªÎª¿ªáªËª½ªìª¾ªì1ËÁªÎUDP portªòŞÅéÄª·ªŞª¹¡£ª³ªÎãÁ¡¢m_localUdpPortPoolªÇò¦ïÒª·ª¿«İ?«ÈÛã?ªòLocal portªÈª¹ªëUDP socketªòßæà÷ª¹ªëªèª¦ªËªÊªêªŞª¹¡£ªâª·¡¢m_localUdpPortPoolªÇãÀïáª·ª¿«İ?«ÈÛã?ª¬ªÊª¤ªÈª«¡¢m_localUdpPortPoolªÇò¦ïÒª·ª¿«İ?«ÈÛã?ª¬îïªÆêŞª¦á¶ªÇŞÅéÄñéªÎíŞùê¡¢ìòëòªÎ«İ?«ÈÛã?ª¬ò¦ïÒªµªìUDP socketª¬ßæà÷ªµªìªŞª¹¡£
		ìéÚõîÜªËm_localUdpPortPoolö·ªÏª½ªÎªŞªŞöÇª¤ª¿Û°ª¬ÕŞª¤ªÇª¹¡£ª·ª«ª·¡¢ëò?îÜªËlocal UDP socketªÎportÛã?ªò?ğ¤ªËò¦ïÒª·ª¿ª¤íŞùê¡¢m_localUdpPortPool?ªËıñØĞª¹ªëö·ªòìıªìªÆª¯ªÀªµª¤¡£
		\~
		 */
		CFastArray<int> m_localUdpPortPool;

		/**
		\~korean
		¼­¹ö¿¡ ¿¬°áÇÏ±â Àü¿¡, ¼­¹ö¿ÍÀÇ ÇÁ·ÎÅäÄİ ¸ÅÄªÀ» À§ÇÑ °ªÀÔ´Ï´Ù.
		- CNetServer.Start¿¡¼­ ÀÔ·ÂÇß´ø protocol version°ú ¼­¹ö¿ÍÀÇ ¿¬°áÀÌ ¼º°øÇÕ´Ï´Ù. ±×·¸Áö ¾ÊÀ» °æ¿ì
		ErrorType_ProtocolVersionMismatch°¡ ¼­¹ö ¿¬°á ÈÄ ÀÀ´äÀ¸·Î ¿É´Ï´Ù.

		\~english
		This is the value to match the protocol with servers before connecting to the severs.
		- The connection to the server with the protocol version that was input at CNetServer.Start.
		If not, ErrorType_ProtocolVerionMismatch is to be returned after connected to the server.

		\~chinese
		?ïÈÜ×?Ğïñıîñ£¬?Öõ?Ü×?Ğïprotocolù¯ÛÕîÜ?¡£
		- î¤ CNetServer.Start%?ìıîÜprotocol versionûúÜ×?Ğï?ïÈà÷ÍíÖõ¡£Üú??ïÈÜ×?Ğïñıı¨?ÔğÓğErrorType_ProtocolVersionMismatch¡£

		\~japanese
		«µ?«Ğ?ªËïÈ?ª¹ªëîñªË¡¢«µ?«Ğ?ªÈªÎ«×«í«È«³«ë«Ş«Ã«Á«ó«°ªÎª¿ªáªÎö·ªÇª¹¡£
		- CNetServer.StartªÇìıÕôª·ª¿protocol versionªÈ«µ?«Ğ?ªÈªÎïÈ?ª¬à÷Ííª·ªŞª¹¡£ª½ª¦ªÇªÏªÊª¤íŞùê¡¢ErrorType_ProtocolVersionMismatchª¬«µ?«Ğ?ïÈ?ı­ªË?ÓÍªÈª·ªÆ?ªŞª¹¡£
		\~
		 */
		Guid m_protocolVersion;
		/**
		\~korean
		¼­¹ö¿¡ º¸³»´Â Ãß°¡ ¿¬°á Á¤º¸ÀÔ´Ï´Ù. INetServerEvent.OnConnectionRequest()¿¡¼­ ÀÌ µ¥ÀÌÅÍ°¡ ¹Ş¾ÆÁı´Ï´Ù.

		\~english
		This is an additional connection info to be sent to the server.
 		This data is received at INetServerEvent.OnConnectRequest().

		\~chinese
		î¤Ü×?Ğï?áê?èâİ¾Ê¥?ïÈãáãÓ¡£
		î¤ INetServerEvent.OnConnectionRequest()ïÈâ¥?Ëß¡£

		\~japanese
		«µ?«Ğ?ªËáêªëõÚÊ¥ïÈ?ï×ÜÃªÇª¹¡£INetServerEvent.OnConnectionRequest()ªÇª³ªÎ«Ç?«¿ª¬áôª±ö¢ªéªìªŞª¹¡£
		\~
		 */
		ByteArray m_userData;

		/**
		\~korean
		±âº»°ªÀº false ÀÔ´Ï´Ù.
		true ·Î ¼³Á¤ÇÒ °æ¿ì Reliable P2P ÀÇ Àü¼Û¼Óµµ´Â 1MB/sec¸¦ °¨´çÇÒ ¼ö ¾ø½À´Ï´Ù.
		±×·¯³ª Ã³¸® ¼º´ÉÀÌ °¡º­¿öÁı´Ï´Ù. ´õ¹Ì Å¬¶óÀÌ¾ğÆ® Å×½ºÆ®¸¦ ÇÒ ¶§¿¡¸¸ true ·Î ¼³Á¤ÇÏ½Ê½Ã¿À.

		\~english
		Default is false.
		If setting it as true, Reliable P2P transmission speed cannot support 1MB/sec.
		But performance will be improved, so set it as true only for dummy client test.

		\~chinese
		ĞñÜâ??false¡£
		åıÍı?ó®?öÇ?true£¬Reliable P2PîÜ?áêáÜÓø?ÙéÛöã¯?1MB/sec¡£
		Ó£?ğ«ÍÔ?×âàõÒö£¬?ñşî¤?ú¼????ó®??öÇ?true¡£

		\~japanese
		«Ç«Õ«©«ë«Èö·ªÏ falseªÇª¹¡£
		true ªËàâïÒª¹ªëíŞùêReliable P2PªÎ?áêáÜÓøªÏ 1MB/secªòÒ±ª¨ªëª³ªÈªÏªÇª­ªŞª»ªó¡£
		ª·ª«ª·?×âàõÒöª¬ªèª¯ªÊªêªŞª¹¡£«À«ß?«¯«é«¤«¢«ó«È«Æ«¹«Èªòª¹ªëãÁªÀª± true ªËàâïÒª·ªÆª¯ªÀªµª¤¡£

		\~
		*/
		bool m_slowReliableP2P;

		// coalesce interval. Å×½ºÆ®¿ëÀÌ¹Ç·Î Æò¼Ò¿¡´Â ¼Õ´ëÁö ¸» °Í. 0ÀÌ¸é ±âº»°ª ÀÎÅÍ¹ú °ªÀ¸·Î ´ëÃ¼µÊÀ» ÀÇ¹ÌÇÏ¸ç, ÀÌ °ª ÀÚÃ¼ÀÇ ±âº»°ªÀº 0ÀÌ´Ù.
		int m_tunedNetworkerSendIntervalMs_TEST;

		/**
		\~korean
		\brief Simple network protocol mode.

		±âº»°ªÀº false ÀÔ´Ï´Ù.
		ÆĞÅ¶ Ä¸ÃÄ ¹× º¹Á¦ ¹æ½ÄÀ¸·Î ´õ¹Ì Å¬¶óÀÌ¾ğÆ® Å×½ºÆ®¸¦ °¡´ÉÇÏ°Ô ÇÏ±â À§ÇØ¼­ ÀÌ °ªÀ» true·Î ¼³Á¤ÇÏ½Ê½Ã¿À.
		´Ü, ¼­ºñ½º°¡ ÇØÄ¿ÀÇ °ø°İ¿¡ Ãë¾àÇØ Áö¸ç UDP networking°ú direct P2P Åë½ÅÀ» »ç¿ëÇÒ ¼ö ¾ø½À´Ï´Ù. (´ë½Å relay ·Î Àü¼ÛÇÕ´Ï´Ù.)
		¶óÀÌºê ¼­ºñ½º¸¦ À§ÇØ¼­´Â false·Î ¼³Á¤ÇÏ½Ê½Ã¿À.

		ÆĞÅ¶ Ä¸ÃÄ¿Í ¸®ÇÃ·¹ÀÌ Å×½ºÆ®°ü·Ã ³»¿ë:
		°¢°¢ÀÇ ´õ¹Ì Å¬¶óÀÌ¾ğÆ®´Â ÀÚ½ÅÀÇ HostID¸¦ È®ÀÎÇÒ ¼ö ¾ø½À´Ï´Ù.
		CreateP2PGroup() °ú °°ÀÌ P2P ±×·ì °ü·Ã ÇÔ¼ö¸¦ È£ÃâÇÒ °æ¿ì ¿¹»óÄ¡ ¸øÇÑ »óÈ²ÀÌ ¹ß»ıÇÒ ¼ö ÀÖ½À´Ï´Ù.

		\~english
		\brief Simple network protocol mode.

		Default is false.
		Setting this to true allows dummy client test via packet capture and replication method.
		However, it will make service vulnerable to hackers, and does not allow UDP networking
		and direct P2P communication (will be relayed instead.)
		You should set this to false for live service.

		Notice for packet capture and replay test:
		- Each dummy client cannot identify self HostID.
		Unexpected behavior may occur if you call P2P group functions such as CreateP2PGroup().

		\~chinese
		\brief Simple network protocol mode.

		ĞñÜâ??false¡£
		ãÀ?ËßøĞï¸ö¢Ğà?ğ¤îÜÛ°ãÒ£¬?Òö??ú¼ËÔ?Ó®????ó®??öÇ?true¡£
		Ó£??Ê¦Òö?é»æ¶áôÓğıÙËÔÍô?ó¦ÙéÛöŞÅéÄUDP networkingûúDirect P2P÷×ãá¡££¨Ó£???éÄrelay?áê£©¡£
		?Òö?ğ«Íê??Ü×???ó®??öÇ?false¡£

		?ËßøĞï¸ö¢?Replay??îÜßÓ??é»£º
		ÊÀ??ËÔ?Ó®ÙéÛö??í»ĞùîÜHostID¡£
		åıCreateP2PGroup()£¬û¼Ğ£P2P?ßÓ?ùŞ??Ê¦Òö??ßæ?êó??ÓğîÜ??¡£

		\~japanese
		\brief Simple network protocol mode.

		«Ç«Õ«©«ë«Èö·ªÏ false ªÇª¹¡£
		Packet captureĞàªÓÜÜğ²Û°ãÒªÇdummy client «Æ«¹«ÈªòÊ¦ÒöªËª¹ªëª¿ªáªËª³ªÎö·ªò trueªËàâïÒª·ªÆª¯ªÀªµª¤¡£
		ª¿ªÀª·¡¢«µ?«Ó«¹ª¬HackerªÎÍô?ªËöªå°ªËªÊªê¡¢ UDP networkingªÈ direct P2P÷×ãáªòŞÅª¦ª³ªÈª¬ªÇª­ªŞª»ªó¡£ (ÓÛªïªêªË relayªÇ?áêª·ªŞª¹¡£)
		Live«µ?«Ó«¹ªÎª¿ªáªËªÏ falseªËàâïÒª·ªÆª¯ªÀªµª¤¡£

		Packet captureªÈ«ê«×«ì?«Æ«¹«È?Ö§?é»
		ÊÀ?ªÎ dummy client ªÏí»İÂªÎ HostIDªÎü¬ìãª¬ªÇª­ªŞª»ªó¡£
		CreateP2PGroup() ªÎªèª¦ªË P2P«°«ë?«×?Ö§??ªòû¼ªÓõóª¹íŞùê¡¢åøßÌèâªÎ?üÏª¬?ßæª¹ªëÍğªìª¬ª¢ªêªŞª¹¡£

		\~
		*/
		bool m_simplePacketMode;

		/**
		\~korean
		- OnException Äİ¹é ±â´ÉÀ» »ç¿ëÇÒ Áö ¿©ºÎ¸¦ ¼±ÅÃÇÕ´Ï´Ù.
		- ±âº»°ªÀº trueÀÔ´Ï´Ù.
		- ¸¸¾à false¸¦ ÁöÁ¤ÇÏ¸é À¯Àú Äİ¹é¿¡¼­ ¿¹»óÄ¡ ¸øÇÑ Exception ¹ß»ı ½Ã OnExceptionÀÌ È£ÃâµÇÁö ¾Ê°í Å©·¡½Ã°¡ ¹ß»ıÇÕ´Ï´Ù.

		\~english
		- Decide whether it uses OnException callback function or not.
		- Default value is true.
		- If setting it as false, when exception occurs during  user callback, crash will occur as OnException is not called.

		\~chinese
		- ??ãÀÜúŞÅéÄ OnException CallbackÍíÒö¡£
		- ĞñÜâ?? true¡£
		- åıÍıò¦ïÒfalse£¬éÄ?î¤Callback?ïïñé?ßæëòßÌÜôÓğîÜ Exception ?£¬OnException?Üôù¬û¼õó£¬ó¦?ßæCrash¡£

		\~japanese
		- OnException CallbackÑ¦ÒöªòŞÅéÄª¹ªëª«ªÉª¦ª«ªòàÔ?ª·ªŞª¹¡£
		- «Ç«Õ«©«ë«Èö·ªÏtrueªÇª¹¡£
		- ªâª·falseªòò¦ïÒª¹ªëªÈ«æ?«¶?Callbackª«ªéåøßÌªÇª­ªÊª¤Exceptionª¬?ßæª·ª¿ãÁ¡¢OnExceptionª¬û¼ªÓõóªµªìªºªË«¯«é«Ã«·«åª¬?ßæª·ªŞª¹¡£
		\~
		*/
		bool m_allowOnExceptionCallback;

		/**
		\~korean
		¼­¹ö¿Í Å¬¶óÀÌ¾ğÆ®°¡ NAT ¶ó¿ìÅÍ µÚ¿¡ ÀÖ´Â »óÅÂ¿¡¼­ ´Ù¸¥ Å¬¶óÀÌ¾ğÆ®¿Í P2P Åë½ÅÀ» ÇØ¾ß ÇÒ °æ¿ì ÇÊ¿äÇÒ ¼ö ÀÖ½À´Ï´Ù.
		°¡·É Å¬¶óÀÌ¾ğÆ®°¡ °ÔÀÓ ÇÃ·¹ÀÌ¸¦ Ã³¸®ÇÏ´Â super peer°¡ µÇ¾î¾ß ÇÏ´Â °æ¿ì,
		±×¸®°í super peer¿Í ¼­¹ö°¡ °°Àº hostÀÎ °æ¿ì,
		super peer ¾È¿¡¼­´Â ¿©±â¿¡ super peerÀÇ public ÁÖ¼Ò¸¦ ³ÖÀ¸½Ã±â ¹Ù¶ø´Ï´Ù.

		\~english
		It is variable used when trying to set the clients' external address by force.
		It might be necesaary to make a P2P communication with other clients when a server and client is behind the NAT router.
		For example, if it should be the super peer that the client deal with game play and if it is the host that has a same server with the super peer, put the public address of the super peer here in the super peer.

		\~chinese
		ãÀ?ÖõË­ğ¤?öÇËÔ?Ó®îÜèâİ»ò¢ò£îÜ?ı¦ŞÅéÄîÜ?Õá¡£
		Ü×?ĞïûúËÔ?Ó®î¤NATÖØë¦Ğïı¨ØüîÜ??ù»?ĞìöâËÔ?Ó®P2P÷×ãáîÜ?ı¦Ê¦ÒöâÍé©¡£
		?ŞÅËÔ?Ó®£¨client£©âÍé©?×âêı?îÜsuper peer, ì»ó¦super peer ûúÜ×?Ğïìé?ãÀhostîÜï×?ù»£¬super peeré©ÛÕöÇsuper peerîÜpublicò¢ò£¡£
		øÁ?Üôé©?öÇËÀÌ«¡£

		\~japanese
		«¯«é«¤«¢«ó«ÈªÎèâİ»«¢«É«ì«¹ªò?ğ¤îÜªËàâïÒª·ªèª¦ªÈª¹ªëğ·ªËŞÅéÄªµªìªë??ªÇª¹¡£
		«µ?«Ğ?ªÈ«¯«é«¤«¢«ó«Èª¬NAT«ë?«¿?ªÎı­ªíªËª¢ªë?÷¾ªÇ¡¢öâªÎ«¯«é«¤«¢«ó«ÈªÈP2P÷×ãáªòª·ªÊª±ªìªĞªÊªéªÊª¤íŞùê¡¢ù±é©ªËªÊªëª«ªâª·ªìªŞª»ªó¡£
		?ªË«¯«é«¤«¢«ó«Èª¬«²?«à«×«ì«¤ªò?×âª¹ªësuper peerªËªÊªéªÊª±ªìªĞªÊªéªÊª¤íŞùê¡¢
		ª½ª·ªÆsuper peerªÈ«µ?«Ğ?ª¬ÔÒª¸hostªÎíŞùê¡¢
		super peee?ªÇªÏ¡¢ª³ª³ªËsuper peerªÎpublic«¢«É«ì«¹ªòìıÕôª·ªÆª¯ªÀªµª¤¡£
		ÜÅÓ«ªÏö·ªòàâïÒª·ªÊª¤ªÇª¯ªÀªµª¤¡£

		\~
		*/
		String m_clientAddrAtServer;

		/** <a target="_blank" href="http://guide.nettention.com/cpp_ko#acr" >¿¬°á À¯Áö ±â´É »ç¿ëÇÏ±â</a> ¸¦ ÄÑ°Å³ª ²ü´Ï´Ù. ±âº»ÀûÀ¸·Î ²¨Á® ÀÖ½À´Ï´Ù. */
		bool m_enableAutoConnectionRecovery;

		/**
		\ref
		RMI, ÀÌº¥Æ® ¸¦ Äİ¹é ¹ŞÀ» ¾²·¹µå ¸ğµ¨À» ÁöÁ¤ÇÕ´Ï´Ù.

		- SingleThreaded ÁöÁ¤½Ã »ç¿ëÀÚ´Â NetClient.FrameMove ÇÔ¼ö¸¦ È£Ãâ ÇÒ ¶§ RMI, ÀÌº¥Æ®°¡ Äİ¹é µË´Ï´Ù.
		- MultiThreaded ÁöÁ¤½Ã RMI, ÀÌº¥Æ® Äİ¹éÀÌ ¸ÖÆ¼ ¾²·¹µå·Î Äİ¹é µË´Ï´Ù.
		- UseExternalThreadPool ÁöÁ¤½Ã m_externalUserWorkerThreadPool ¿¡ ÁöÁ¤ µÈ »ç¿ëÀÚ Á¤ÀÇ ¾²·¹µå Ç®·Î ÀÛµ¿ µË´Ï´Ù.
		±âº» ¿É¼ÇÀº SingleThreaded ÀÔ´Ï´Ù.

		(ÁÖÀÇ! SingleThreaded ¿É¼Ç »ç¿ë½Ã »ç¿ëÀÚ´Â NetClient.FrameMove ÇÔ¼ö¸¦ ¹İµå½Ã È£Ãâ ÇØ¾ß ÇÕ´Ï´Ù.)
		*/
		ThreadModel m_userWorkerThreadModel;

		/**
		\ref
		³×Æ®¿öÅ© I/O Ã³¸® ÀÛ¾÷¿¡ ´ëÇÑ ¾²·¹µå ¸ğµ¨À» ÁöÁ¤ÇÕ´Ï´Ù.

		- SingleThreaded ÁöÁ¤½Ã »ç¿ëÀÚ´Â NetClient.FrameMove ÇÔ¼ö¸¦ È£Ãâ ÇÒ ¶§ I/O Ã³¸®¸¦ ÇÕ´Ï´Ù.
		- MultiThreaded ÁöÁ¤½Ã Àü¿ª °øÀ¯ ¾²·¹µåÇ®¿¡¼­ ¸ÖÆ¼ ¾²·¹µå·Î Ã³¸®°¡ µË´Ï´Ù.
		- UseExternalThreadPool ÁöÁ¤½Ã m_externalNetWorkerThreadPool ¿¡ ÁöÁ¤ µÈ »ç¿ëÀÚ Á¤ÀÇ ¾²·¹µå Ç®·Î ÀÛµ¿ µË´Ï´Ù.
		 (Àü¿ª °øÀ¯ ¾²·¹µåÇ®ÀÌ¶õ, NetClient °´Ã¼°¡ ¿©·¯°³°¡ µÇ´õ¶óµµ ¿£Áø ³»ºÎÀÇ ÇÏ³ªÀÇ ¾²·¹µåÇ®¿¡¼­ Ã³¸®°¡ µË´Ï´Ù.)

		±âº» ¿É¼ÇÀº MultiThreaded ÀÔ´Ï´Ù.

		(ÁÖÀÇ! SingleThreaded ¿É¼Ç »ç¿ë½Ã »ç¿ëÀÚ´Â NetClient.FrameMove ÇÔ¼ö¸¦ ¹İµå½Ã È£Ãâ ÇØ¾ß ÇÕ´Ï´Ù.)
		*/
		ThreadModel m_netWorkerThreadModel;

		/**
		\ref
		RMI, ÀÌº¥Æ® Äİ¹é µî ´Ù¾çÇÑ ÀÛ¾÷À» »ç¿ëÀÚÀÇ ¾²·¹µå Ç®¿¡¼­ ÀÛµ¿ ÇÏµµ·Ï ÇÕ´Ï´Ù.
		m_userWorkerThreadModel ¿¡¼­ ThreadModel_UseExternalThreadPool ÁöÁ¤ ½Ã ¹İµå½Ã ÀÌ °ªÀ» ¼¼ÆÃ ÇØ¾ß ÇÕ´Ï´Ù.
		*/
		CThreadPool* m_externalUserWorkerThreadPool;

		/**
		\ref
		³×Æ®¿öÅ© I/O Ã³¸®¸¦ »ç¿ëÀÚÀÇ ¾²·¹µå Ç®¿¡¼­ ÀÛµ¿ ÇÏµµ·Ï ÇÕ´Ï´Ù.
		m_netWorkerThreadModel ¿¡¼­ ThreadModel_UseExternalThreadPool ÁöÁ¤ ½Ã ¹İµå½Ã ÀÌ °ªÀ» ¼¼ÆÃ ÇØ¾ß ÇÕ´Ï´Ù.
		*/
		CThreadPool* m_externalNetWorkerThreadPool;

		/**
		\~korean
		Timer callback ÁÖ±â ÀÔ´Ï´Ù. <a target="_blank" href="http://guide.nettention.com/cpp_ko#server_timer_callback" >¼­¹ö¿¡¼­ Å¸ÀÌ¸Ó ·çÇÁ RMI ÀÌº¥Æ® Ã³¸®ÇÏ±â</a>  ±â´ÉÀÔ´Ï´Ù.
		ÀÌ°ÍÀ» ¼¼ÆÃÇÏ¸é milisec´ÜÀ§·Î ÇÑ¹ø¾¿ INetServerEvent.OnTick °¡ È£ÃâµË´Ï´Ù.
		- 0ÀÌ¸é Äİ¹éÇÏÁö ¾Ê½À´Ï´Ù.
		- ±âº»°ªÀº 0ÀÔ´Ï´Ù.

		\~english
		This sets the period of timer callback. A function described in <a target="_blank" href="http://guide.nettention.com/cpp_en#server_timer_callback" >Managing Timer loop RMI Event from server</a>.
		When this is activated, INetServerEvent.OnTimerCallback will be called at every period set by millisecond unit.
		- Ther is no callback when this is set as 0.
		- The default value is 0

		\~chinese
		Timer callbackñ²Ñ¢¡£<a target="_blank" href="http://guide.nettention.com/cpp_zh#server_timer_callback" >î¤Ü×?Ğï?×âTimer Loop£¬RMI£¬Event</a> ÍíÒö¡£
		?öÇ??îÜ?£¬ INetServerEvent.OnTick%?ì¤milisec?êÈû¼Ğ£ìéó­¡£
		- 0îÜîÜ?Üô?üŞ?¡£
		- Ùù??ãÀ0¡£

		\~japanese
		Timer callback ñ²Ñ¢ªÇª¹¡£\ref server_timer_callback  Ñ¦ÒöªÇª¹¡£
		ª³ªìªòàâïÒª¹ªëªÈ¡¢«ß«êõ©?êÈªÇìéÓøªºªÄINetServerEvent.OnTickª¬û¼ªÓõóªµªìªŞª¹¡£
		- 0ªÇª¢ªìªĞ«³?«ë«Ğ«Ã«¯ª·ªŞª»ªó¡£
		- ĞñÜâö·ªÏ0ªÇª¹¡£
		\~
		*/
		uint32_t m_timerCallbackIntervalMs;

		/**
		\~korean
		Timer callbackÀÌ µ¿½Ã ¸î °³ÀÇ user worker thread¿¡¼­ È£ÃâµÉ ¼ö ÀÖ´ÂÁö¸¦ Á¤ÇÕ´Ï´Ù.
		±âº»°ªÀº 1ÀÔ´Ï´Ù. ¸ğµç user worker thread¸¦ »ç¿ëÇÏ°í ½Í´Ù¸é INT_MAX¸¦ ÀÔ·ÂÇØµµ µË´Ï´Ù.

		\~english TODO:translate needed.

		\~chinese
		?ïÒTimer callbackÔÒ?Òöî¤??user worker threadù¬û¼Ğ£¡£
		Ùù??ãÀ1¡£ßÌŞÅéÄá¶êóuser worker threadîÜ?å¥Ê¦ì¤?ìıINT_MAX¡£

		\~japanese
		Timer callbackª¬ÔÒãÁªËª¤ª¯ªÄªÎuser worker threadªÇû¼ªÓõóªµªìªëª³ªÈª¬ªÇª­ªëªÎª«ªòÌ½ªáªŞª¹¡£
		ĞñÜâö·ªÏ1ªÇª¹¡£îïªÆªÎuser worker threadªòŞÅéÄª·ª¿ª¤íŞùêªÏ¡¢INT_MAXªòìıÕôª·ªÆªâÕŞª¤ªÇª¹¡£
		\~
		*/
		int32_t m_timerCallbackParallelMaxCount;

		/**
		\~korean
		¼­¹ö¿¡¼­ ÀÏÁ¤ÁÖ±â¿¡ ÇÑ¹ø¾¿ Äİ¹éÀ» ÇÒ½Ã¿¡ ÀÎÀÚ·Î »ç¿ëµÇ´Â À¯Àú µ¥ÀÌÅÍÀÔ´Ï´Ù.
		Proud.INetServerEvent.OnTick °¡ È£ÃâµÉ½Ã¿¡ ÀÎÀÚ°ªÀ¸·Î µé¾î°©´Ï´Ù. <a target="_blank" href="http://guide.nettention.com/cpp_ko#server_timer_callback" >¼­¹ö¿¡¼­ Å¸ÀÌ¸Ó ·çÇÁ RMI ÀÌº¥Æ® Ã³¸®ÇÏ±â</a> ±â´ÉÀÔ´Ï´Ù.
		- ±âº»°ªÀº NULLÀÔ´Ï´Ù.

		\~english
		This is a user data used as an index when the server calls back each time in every period.
		This value is to be input as an index when Proud.INetServerEvent.OnTimerCallback is called. A function described in <a target="_blank" href="http://guide.nettention.com/cpp_en#server_timer_callback" >Managing Timer loop RMI Event from server</a>.
		- The default value is NULL.

		\~chinese
		î¤Ü×?ĞïØßìéïÒñ²Ñ¢üŞ?ìéó­îÜ?ı¦éÄéÍì×áÈîÜéÄ??Ëß¡£
		Proud.INetServerEvent.OnTick%ù¬û¼Ğ£îÜ?ı¦?ìıà÷ì×áÈ?¡£ãÀ<a target="_blank" href="http://guide.nettention.com/cpp_zh#server_timer_callback" >î¤Ü×?Ğï?×âTimer Loop£¬RMI£¬Event</a>%ÍíÒö¡£
		- Ùù??ãÀNULL¡£

		\~japanese
		«µ?«Ğ?ªÇá¶ïÒñ²Ñ¢ªËìéÓøªºªÄ«³?«ë«Ğ«Ã«¯ªòª¹ªëãÁªËì×í­ªÈª·ªÆŞÅªïªìªë«æ?«¶?«Ç?«¿ªÇª¹¡£
		Proud.INetServerEvent.OnTickª¬û¼ªÓõóªµªìªëãÁªËì×í­ö·ªÈª·ªÆìıªêªŞª¹¡£\ref server_timer_callback Ñ¦ÒöªÇª¹¡£
		- ĞñÜâö·ªÏNULLªÇª¹¡£
		\~
		*/
		void* m_timerCallbackContext;

		PROUD_API CNetConnectionParam();
	};

	/**  @} */
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
