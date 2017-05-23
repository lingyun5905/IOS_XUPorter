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

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	class CSocket;

#ifdef _WIN32

	/** \addtogroup net_group
	*  @{
	*/

	/** 
	\~korean
	SocketSelectContext class
	- »ç¿ë¹ı ¿¹Á¦´Â SampleÁß SimpleHttpConnect¸¦ Âü°íÇÏ½Ã¸é µË´Ï´Ù.
	- socketÀÇ select() non-block model À» À§ÇÑ ¿ëµµ
	- ÁÖÀÇ: Wait È£Ãâ ÈÄ¿¡´Â FD_SETÀÇ ³»¿ëÀÌ ¹Ù²ï´Ù. µû¶ó¼­ ÀÌ °´Ã¼´Â 1È¸¼ºÀ¸·Î ¾²¿©¾ß ÇÑ´Ù. 
	- Win32¿¡¼­¸¸ Áö¿øÇÏ´Â ±â´ÉÀÔ´Ï´Ù. iOS, linux¿¡¼­´Â ÀÌ°Í ´ë½Å ::poll()À» »ç¿ëÇÏ½Ê½Ã¿À.

	\~english TODO:translate needed.
	SocketSelectContext class
-
	- This it for select() non-block model of socket
	- Note: After Wait calling, informationf of FD_SET will be changed. So this object has to use for once.
	- This class can work only in Win32 platform. Use ::poll() in iOS or Linux.

	\~chinese
	SocketSelectContext class
	- ŞÅéÄÛ°ÛöÖÇí­?ÍÅsampleñéSimpleHttpConnect?Ê¦¡£
	- ?ÖõsocketîÜselect() non-block modelîÜéÄÔ²¡£
	- ñ¼ëò£ºWaitû¼Ğ£ì¤ı¨?ËÇ?FD_SETîÜ?é»¡£á¶ì¤ó®?ßÚé©éÄéÍìéó­àõ¡£
	- ñşî¤Win32Ê¦ì¤ò¨ò¥¡£î¤iOS, linuxŞÅéÄ::poll()?ÓÛôğ??¡£

	\~japanese
	\~
	*/
	class SocketSelectContext
	{
	public:
		SocketSelectContext() {}

		virtual void AddWriteWaiter(CSocket& socket) = 0;
		virtual void AddExceptionWaiter( CSocket& socket ) = 0;
		virtual void Wait(uint32_t miliSec) = 0;
		virtual bool GetConnectResult(CSocket& socket, SocketErrorCode& outCode) = 0;

		PROUD_API static SocketSelectContext *New();
	};
#endif // _WIN32

	/** 
	\~korean
	Socket Delegate Interface 
	- Socket¿¡ °ü·ÃµÈ ¿¡·¯¸¦ OnSocketWarning ÇÔ¼ö¿¡¼­ ¹ŞÀ»¼ö ÀÖ´Ù. 

	\~english
	Socket Delegate Interface 
	- You can receive Socket related error from OnSocketWarning function.

	\~chinese
	Socket Delegate Interface 
	- SocketßÓ?îÜ??Ê¦ì¤î¤OnSocketWarningùŞ?×ìïÈâ¥¡£

	\~japanese
	\~
	*/
	class ISocketDelegate
	{
	public:
		virtual ~ISocketDelegate() {}
		virtual void OnSocketWarning(CSocket* soket, String msg) = 0;
	};

	/** 
	\~korean
	CSocket class 
	- ProudÀÇ NetClient ¸¦ ¾²Áö ¾Ê°í ¿ÜºÎÀÇ Server³ª http¿¡ Á¢±ÙÇÒ¶§ ¾²¸é À¯¿ëÇÏ´Ù.
	- ³»ºÎÀûÀ¸·Î Proud::FastSocket À» »ç¿ëÇÑ´Ù. 

	\~english
	CSocket class 
	- It is useful when you access external Server or http without NetClient of ProudNet.
	- Use Proud::FastSocket internally

	\~chinese
	CSocket class
	- ÜôŞÅéÄProudîÜNetClient£¬??èâİ»îÜServerûäíºhttpîÜ?ı¦ŞÅéÄîÜ?êóéÄ¡£
	- ŞÅéÄ?İ» Proud::FastSocket%¡£

	\~japanese
	\~
	*/
	class CSocket
	{
	public:
		virtual ~CSocket(){}

	public:
		virtual bool Bind() = 0;
		virtual bool Bind(int port) = 0;
		virtual bool Bind( const PNTCHAR* addr, int port ) = 0;

		/** 
		\~kore?an
		Connect ÇÑ´Ù. 
		\param hostAddr host ÀÇ ÁÖ¼Ò 
		\param hostPort host ÀÇ port 
		
		\~english TODO:translate needed.
		
		\~chinese
		?ú¼connect¡£
		\param hostAddr hostîÜò¢ò£¡£
		\param hostPort hostîÜport¡£

		\~japanese
		\~
		*/
		virtual SocketErrorCode Connect(String hostAddr, int hostPort) = 0;

#if !defined(_WIN32)
// 		virtual SocketErrorCode NonBlockedRecvFrom(int length) = 0;
// 		virtual SocketErrorCode NonBlockedSendTo( BYTE* data, int count, AddrPort sendTo ) = 0;
// 		virtual SocketErrorCode NonBlockedRecv(int length) = 0;
// 		virtual SocketErrorCode NonBlockSend( BYTE* data, int count) = 0;
#else
		/**
		\~korean 
		UDP socket
		- Recv¸¦ IssueÇÑ´Ù.
		\param length ¹öÆÛÀÇ Å©±â
		\return ¼ÒÄÏ Error¸¦ ¸®ÅÏÇØÁİ´Ï´Ù. SocketErrorCode_Ok ÀÌ¸é Á¤»ó

		\~english TODO:translate needed.

		\~chinese
		UDP socket
		- ÷êRecv?ú¼issue¡£
		\param length bufferîÜÓŞá³¡£
		\return Ú÷üŞsocketîÜError¡£SocketErrorCode_Ok îÜ?ïáßÈ¡£

		\~japanese
		\~
		*/
		virtual SocketErrorCode IssueRecvFrom(int length) = 0;
		
		/**
		\~korean 
		UDP socket
		- Send¸¦ IssueÇÑ´Ù.
		\param data º¸³¾ dataÀÇ ¹è¿­
		\param count ¹è¿­ÀÇ Å©±â
		\param sendTo º¸³¾ ÁÖ¼Ò
		\return ¼ÒÄÏ Error¸¦ ¸®ÅÏÇØÁİ´Ï´Ù. SocketErrorCode_Ok ÀÌ¸é Á¤»ó

		\~english TODO:translate needed.

		\~chinese
		UDP socket
		- ÷êSend?ú¼Issue¡£
		\param data é©?áêîÜdataîÜ??¡£
		\param count ??îÜÓŞá³¡£
		\param sendTo é©?áêîÜò¢ò£¡£
		\return Ú÷üŞsocketîÜError¡£SocketErrorCode_Ok îÜ?ïáßÈ¡£

		\~japanese
		\~
		*/
		virtual SocketErrorCode IssueSendTo( uint8_t* data, int count, AddrPort sendTo ) = 0;
		
		/**
		\~korean 
		TCP socket
		- Recv¸¦ IssueÇÑ´Ù.
		\param length ¹öÆÛÀÇ Å©±â
		\return ¼ÒÄÏ Error¸¦ ¸®ÅÏÇØÁİ´Ï´Ù. SocketErrorCode_Ok ÀÌ¸é Á¤»ó

		\~english TODO:translate needed.

		\~chinese
		UDP socket
		- ÷êRecv?ú¼issue¡£
		\param length bufferîÜÓŞá³¡£
		\return Ú÷üŞsocketîÜError¡£SocketErrorCode_Ok îÜ?ïáßÈ¡£

		\~japanese
		\~
		*/	
		virtual SocketErrorCode IssueRecv(int length) = 0;

		/**
		\~korean 
		TCP socket
		- Send ¸¦ Issue ÇÑ´Ù.
		\param data º¸³¾ data ÀÇ ¹è¿­
		\param count ¹è¿­ÀÇ Å©±â
		\return ¼ÒÄÏ Error ¸¦ ¸®ÅÏÇØÁİ´Ï´Ù. SocketErrorCode_OkÀÌ¸é Á¤»ó

		\~english TODO:translate needed.

		\~chinese
		UDP socket
		- ÷êSend?ú¼Issue¡£
		\param data é©?áêîÜdataîÜ??¡£
		\param count ??îÜÓŞá³¡£
		\return Ú÷üŞsocketîÜError¡£SocketErrorCode_Ok îÜ?ïáßÈ¡£

		\~japanese
		\~
		*/
		virtual SocketErrorCode IssueSend( uint8_t* data, int count) = 0;

		/**
		\~korean
		async issueÀÇ °á°ú¸¦ ±â´Ù¸°´Ù.
		- ¾ÆÁ÷ ¾Æ¹«°Íµµ ¿Ï·áµÇÁö ¾Ê¾ÒÀ¸¸é nullÀ» ¸®ÅÏÇÑ´Ù.
		- ¸¸¾à ¿Ï·á ¼º°ø ¶Ç´Â ¼ÒÄÏ ¿¡·¯ µîÀÇ ½ÇÆĞ°¡ »ı±â¸é °´Ã¼¸¦ ¸®ÅÏÇÏµÇ m_errorCode°¡ Ã¤¿öÁ® ÀÖ´Ù.
		\param waitUntilComplete ¿Ï·áµÉ¶§±îÁö ±â´Ù¸± °ÍÀÎÁö °áÁ¤ÇÑ´Ù.
		\param ret °á°ú \ref OverlappedResult ÂüÁ¶
		\return ¼º°øÀÌ¸é true, ½ÇÆĞÀÌ¸é false¸®ÅÏ

		\~english TODO:translate needed.

		\~chinese
		ÔõÓâasync issueîÜ?Íı¡£
		- ä§?Ô´?êó?áÖîÜ?Ú÷üŞnull¡£
		- åıÍıà÷Íí?áÖûäíº?ßæsocket??îÜã÷?îÜîÜ?£¬Ú÷üŞ?ßÚÓ£ãÀ??õöm_errorCode¡£
		\param waitUntilComplete ?ïÒãÀÜúé©ÔõÓğ?áÖ¡£
		\param ret ?ğÎ?Íı\ref OverlappedResult%¡£
		\return à÷ÍíîÜ?true£¬ã÷?îÜ?Ú÷üŞfalse¡£

		\~japanese
		\~
		*/
		virtual bool GetRecvOverlappedResult(bool waitUntilComplete, OverlappedResult &ret) = 0;
		
		/**
		\~korean
		async issueÀÇ °á°ú¸¦ ±â´Ù¸°´Ù.
		- ¾ÆÁ÷ ¾Æ¹«°Íµµ ¿Ï·áµÇÁö ¾Ê¾ÒÀ¸¸é nullÀ» ¸®ÅÏÇÑ´Ù.
		- ¸¸¾à ¿Ï·á ¼º°ø ¶Ç´Â ¼ÒÄÏ ¿¡·¯ µîÀÇ ½ÇÆĞ°¡ »ı±â¸é °´Ã¼¸¦ ¸®ÅÏÇÏµÇ m_errorCode°¡ Ã¤¿öÁ® ÀÖ´Ù.
		\param waitUntilComplete ¿Ï·áµÉ¶§±îÁö ±â´Ù¸± °ÍÀÎÁö °áÁ¤ÇÑ´Ù.
		\param ret °á°ú \ref OverlappedResult ÂüÁ¶
		\return ¼º°øÀÌ¸é true, ½ÇÆĞÀÌ¸é false¸®ÅÏ

		\~english TODO:translate needed.

		\~chinese
		Ôõasync issueîÜ?Íı¡£
		- ä§?Ô´?êó?áÖîÜ?Ú÷üŞnull¡£
		- åıÍıà÷Íí?áÖûäíº?ßæsocket??îÜã÷?îÜîÜ?£¬Ú÷üŞ?ßÚÓ£ãÀ??õöm_errorCode¡£
		\param waitUntilComplete ?ïÒãÀÜúé©ÔõÓğ?áÖ¡£
		\param ret ?ğÎ?Íı\ref OverlappedResult%¡£
		\return à÷ÍíîÜ?true£¬ã÷?îÜ?Ú÷üŞfalse¡£

		\~japanese
		\~
		*/
		virtual bool GetSendOverlappedResult(bool waitUntilComplete, OverlappedResult &ret) = 0;

		
#endif
        
		/** 
		\~korean 
		¼ÒÄÏÀÇ ÁÖ¼Ò¸¦ °¡Á®¿Â´Ù. 
		
		\~english TODO:translate needed.

		\~chinese
		ÑÚ?socketîÜò¢ò£¡£

		\~japanese
		\~
		*/
		virtual AddrPort GetSockName() = 0;

		/** 
		\~korean 
		peer ¿¡ ´ëÇÑ ¼ÒÄÏÀÇ ÁÖ¼Ò¸¦ °¡Á®¿Â´Ù. 
		
		\~english TODO:translate needed.

		\~chinese
		ÑÚ??peerîÜsocketò¢ò£¡£

		\~japanese
		\~
		*/
		virtual AddrPort GetPeerName() = 0;

		/** 
		\~korean 
		Åë½Å¿¡ ´ëÇÏ¿© ºí·°Å· ¸ğµå¸¦ »ç¿ëÇÒ °ÍÀÎÁö ¼±ÅÃÇÑ´Ù. 
		
		\~english TODO:translate needed.

		\~chinese
		???÷×ãáãÀÜúŞÅéÄblockingÙ¼ãÒ¡£

		\~japanese
		\~
		*/
		virtual void SetBlockingMode(bool isBlockingMode) = 0;

		/** 
		\~korean 
		recv ¹öÆÛÀÇ Æ÷ÀÎÅÍ¸¦ ¾ò¾î¿Â´Ù. 
		
		\~english TODO:translate needed.

		\~chinese
		?ö¢recv bufferîÜò¦?¡£

		\~japanese
		\~
		*/
		virtual uint8_t* GetRecvBufferPtr() = 0;
		
		/** 
		\~korean 
		recv hostÀÇ ip Address¸¦ ¾ò¾î¿Â´Ù. 
		
		\~english TODO:translate needed.

		\~chinese
		?ö¢recv hostîÜip Address¡£

		\~japanese
		\~
		*/
		PROUD_API static String GetIPAddress(String hostName);

		/** 
		\~korean 
		CSocket °´Ã¼¸¦ »ı¼ºÇÑ´Ù. 
		\param auxSocket socket°´Ã¼
		\param dg ¼ÒÄÏÀÇ ÀÌº¥Æ®¸¦ ¹ŞÀ» °´Ã¼. \ref ISocketDelegate ¸¦ ÂüÁ¶

		\~english TODO:translate needed.

		\~chinese
		ßæà÷ CSocket%?ßÚ¡£
		\param auxSocket socket?ßÚ¡£
		\param dg ïÈâ¥socketîÜeventîÜ?ßÚ¡£?ğÎ\ref ISocketDelegate%¡£

		\~japanese
		\~
		*/
	//	PROUD_API static CSocket *New(SOCKET auxSocket,ISocketDelegate* dg);

		/** 
		\~korean 
		CSocket °´Ã¼¸¦ »ı¼ºÇÑ´Ù. 
		\param type ¼ÒÄÏÀÇ TypeÀ» Á¤ÇÑ´Ù.  
		\param dg ¼ÒÄÏÀÇ ÀÌº¥Æ®¸¦ ¹ŞÀ» °´Ã¼. \ref ISocketDelegate ¸¦ ÂüÁ¶

		\~english TODO:translate needed.

		\~chinese
		ßæà÷ CSocket%?ßÚ¡£
		\param type ò¦ïÒsocketîÜType¡£
		\param dg ïÈâ¥socketîÜeventîÜ?ßÚ¡£?ğÎ\ref ISocketDelegate%¡£

		\~japanese
		\~
		*/
		PROUD_API static CSocket *New(SocketType type, ISocketDelegate *dg);
	};

	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
