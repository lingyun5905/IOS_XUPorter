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

#include "EncryptEnum.h"
#include "CompressEnum.h"
#include "Enums.h"
#include "PNString.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	class CMessage;

	/** \addtogroup net_group
	*  @{
	*/

	/** 
	\~korean
	Àü¼ÛµÇ´Â ¸Ş½ÃÁöÀÇ ¿ä¾à Á¤º¸ÀÔ´Ï´Ù. ¿¹¸¦ µé¾î RMI ·Î±×¸¦ ÃßÀûÇÒ ¶§, º¸³½ ¸Ş½ÃÁö°¡ ¾î¶² Çü½ÄÀÎÁö µîÀ» ¿ä¾àÇÏ¿© »ç¿ëÀÚ¿¡°Ô Á¦°øÇÕ´Ï´Ù. 

	\~english
	This is a quick summary of messages being sent. For instance, when tracking RMI log, this shows a summary of the sent messages to user such as which type they are in.

	\~chinese
	??áêîÜãáãÓî×é©¡£ÖÇåıéÄRMIõÚñ¡logîÜ?ı¦£¬?âû?áêîÜãáãÓãÀä§?û¡ãÒÔõğ«Íê?éÄ?¡£

	\~japanese
	?áêªµªìªë«á«Ã«»?«¸ªÎé©å³ï×ÜÃªÇª¹¡£ÖÇª¨ªĞ¡¢RMI«í«°ªòõÚîæª¹ªëãÁ¡¢áêªÃª¿«á«Ã«»?«¸ª¬ªÉªÎªèª¦ªÊû¡ãÒªÊªÎª«ªÊªÉªòé©å³ª·ªÆ«æ?«¶?ªËğ«Íêª·ªŞª¹¡£
	\~
	*/
	class MessageSummary
	{
	public:
		/** 
		\~korean
		¸Ş½ÃÁöÀÇ Å©±âÀÔ´Ï´Ù. ProudNetÀÇ ¸Ş½ÃÁö °èÃş ÀÌÇÏÀÇ °èÃşÀº Æ÷ÇÔÇÏÁö ¾Ê½À´Ï´Ù. 

		\~english
		Size of message. This doesn't include other classes than the ProudNet message class.

		\~chinese
		ãáãÓîÜÓŞá³¡£ÜôøĞùßProudNetîÜãáãÓ??ì¤ù»îÜ??¡£

		\~japanese
		«á«Ã«»?«¸ªÎ«µ«¤«ºªÇª¹¡£ProudNetªÎ«á«Ã«»?«¸Í­öµì¤ù»ªÎÍ­öµªÏùßªáªŞª»ªó¡£
		\~
		*/
		int m_payloadLength;

		/** 
		\~korean
		¾ĞÃàµÈ ¸Ş½ÃÁöÀÇ Å©±âÀÔ´Ï´Ù.¾ĞÃàÀÌ µÇÁö ¾Ê¾ÒÀ¸¸é,0ÀÌ µé¾î°©´Ï´Ù. ProudNetÀÇ ¸Ş½ÃÁö °èÃş ÀÌÇÏÀÇ °èÃşÀº Æ÷ÇÔÇÏÁö ¾Ê½À´Ï´Ù. 

		\~english
		Size of compressed message. This doesn't include other classes than the ProudNet message class.

		\~chinese
		??îÜãáãÓÓŞá³¡£åıÍı?êó??îÜ?ãÀ0¡£ÜôøĞÎÀProudNetîÜãáãÓ??ì¤ù»îÜ??¡£

		\~japanese
		?õêªµªìª¿«á«Ã«»?«¸ªÎ«µ«¤«ºªÇª¹¡£?õêª¬ªµªìªÊª±ªìªĞ0ª¬ìıªêªŞª¹¡£ProudNetªÎ«á«Ã«»?«¸Í­öµì¤ù»ªÎÍ­öµªÏùßªáªŞª»ªó¡£
		\~
		*/
		int m_compressedPayloadLength;

		/** 
		\~korean
		ÀÌ ¸Ş½ÃÁö°¡ RMI ¸Ş½ÃÁöÀÎ °æ¿ì RMIÀÇ ID°ªÀÔ´Ï´Ù. 

		\~english
		RMI ID if a message is RMI.

		\~chinese
		åıÍıó®ãáãÓãÀRMIãáãÓîÜ?ãÀRMIîÜID?¡£

		\~japanese
		ª³ªÎ«á«Ã«»?«¸ª¬RMI«á«Ã«»?«¸ªÇª¢ªëíŞùê¡¢RMIªÎIDö·ªÇª¹¡£
		\~
		*/
		RmiID m_rmiID;
		/** 
		\~korean
		ÀÌ ¸Ş½ÃÁö°¡ RMI ¸Ş½ÃÁöÀÎ °æ¿ì RMIÀÇ ÇÔ¼ö¸íÀÔ´Ï´Ù. 

		\~english
		RMI function name if a message is RMI.

		\~chinese
		åıÍıó®ãáãÓãÀRMIãáãÓîÜ?ãÀRMIîÜùŞ?Ù£¡£

		\~japanese
		ª³ªÎ«á«Ã«»?«¸ª¬RMI«á«Ã«»?«¸ªÇª¢ªëíŞùê¡¢RMIªÎ??Ù£ªÇª¹¡£
		\~
		*/
		const PNTCHAR* m_rmiName;
		/** 
		\~korean
		ÀÌ ¸Ş½ÃÁö¿¡ µ¿¿øµÈ ¾ÏÈ£È­ ±â¹ıÀÔ´Ï´Ù. 

		\~english
		The encrypted method of a message.

		\~chinese
		ù¬??ãáãÓ??îÜÊ¥ÚËĞü?¡£

		\~japanese
		ª³ªÎ«á«Ã«»?«¸ªËÔÑê¬ªµªìª¿äŞ?ûùĞüÛöªÇª¹¡£
		\~
		*/
		EncryptMode m_encryptMode;
		/** 
		\~korean
		ÀÌ ¸Ş½ÃÁö¿¡ µ¿¿øµÈ ¾ĞÃà¹æ½ÄÀÔ´Ï´Ù.

		\~english
		The compressed method of a message.

		\~chinese
		ù¬??ãáãÓ??îÜ??Û°ãÒ¡£

		\~japanese
		ª³ªÎ«á«Ã«»?«¸ªËÔÑê¬ªµªìª¿?õêÛ°ãÒªÇª¹¡£
		\~
		*/
		CompressMode m_compressMode;
	};

	/**  @} */

	/** 
	\~korean
	IRmiStub::BeforeRmiInvocation ¿¡¼­ ¼ö½Å ¸Ş½ÃÁöÀÇ ¿ä¾à Á¤º¸ÀÔ´Ï´Ù. ¿¹¸¦ µé¾î RMI ·Î±×¸¦ ÃßÀûÇÒ ¶§, º¸³½ ¸Ş½ÃÁö°¡ ¾î¶² Çü½ÄÀÎÁö µîÀ» ¿ä¾àÇÏ¿© »ç¿ëÀÚ¿¡°Ô Á¦°øÇÕ´Ï´Ù. 

	\~english
	Summary of received message at IRmiStub::BeforeRmiInvocation. For exmaple, it provide summary to user such as type of message when you tracking RMI log.

	\~chinese
	î¤IRmiStub::BeforeRmiInvocation â¥ãáãáãÓîÜî×é©¡£ÖÇåıéÄRMIõÚñ¡logîÜ?ı¦£¬?âû?áêîÜãáãÓãÀì¤ä§?û¡ãÒÔõğ«Íê?éÄ?¡£

	\~japanese
	IRmiStub::BeforeRmiInvocation ªÇáôãá«á«Ã«»?«¸ªÎé©å³ï×ÜÃªÇª¹¡£ÖÇª¨ªĞ¡¢RMI«í«°ªòõÚîæª¹ªëãÁ¡¢áêªÃª¿«á«Ã«»?«¸ª¬ªÉªóªÊû¡ãÒªÊªÎª«ªÊªÉªòé©å³ª·ªÆ«æ?«¶?ªËğ«Íêª·ªŞª¹¡£
	\~
	*/
	class BeforeRmiSummary
	{
	public:
		/** 
		\~korean
		ÀÌ ¸Ş½ÃÁö°¡ RMI ¸Ş½ÃÁöÀÎ °æ¿ì RMIÀÇ ID°ªÀÔ´Ï´Ù. 

		\~english
		RMI ID if a message is RMI.

		\~chinese
		åıÍıó®ãáãÓãÀRMIãáãÓîÜ?ãÀRMIîÜID?¡£

		\~japanese
		ª³ªÎ«á«Ã«»?«¸ª¬RMI«á«Ã«»?«¸ªÇª¢ªëíŞùê¡¢RMIªÎIDö·ªÇª¹¡£
		\~
		*/
		RmiID m_rmiID;
		/** 
		\~korean
		ÀÌ ¸Ş½ÃÁö°¡ RMI ¸Ş½ÃÁöÀÎ °æ¿ì RMIÀÇ ÇÔ¼ö¸íÀÔ´Ï´Ù. 

		\~english
		RMI function name if a message is RMI.

		\~chinese
		åıÍıó®ãáãÓãÀRMIãáãÓîÜ?ãÀRMIîÜùŞ?Ù£¡£

		\~japanese
		ª³ªÎ«á«Ã«»?«¸ª¬RMI«á«Ã«»?«¸ªÇª¢ªëíŞùê¡¢RMIªÎ??Ù£ªÇª¹¡£
		\~
		*/
		const PNTCHAR* m_rmiName;
		/** 
		\~korean
		º¸³½ HostÀÇ HostID ÀÔ´Ï´Ù. 

		\~english
		HostID of Host who sent

		\~chinese
		?áêîÜHostîÜHost ID¡£

		\~japanese
		áêªÃª¿HostªÎHostIDªÇª¹¡£
		\~
		*/
		HostID m_hostID;
		/** 
		\~korean
		»ç¿ëÀÚ°¡ ÁöÁ¤ÇÑ hostTagÀÇ Æ÷ÀÎÅÍÀÔ´Ï´Ù. 

		\~english
		Pointer of user defined hostTag.

		\~chinese
		éÄ?ò¦ïÒîÜhostTagîÜò¦?¡£

		\~japanese
		«æ?«¶?ª¬ò¦ïÒª·ª¿hostTagªÎ«İ«¤«ó«¿?ªÇª¹¡£
		\~
		*/
		void* m_hostTag;
	};

	/**  @} */

	/** \addtogroup net_group
	*  @{
	*/

	/** 
	\~korean
	IRmiStub::AfterRmiInvocation ¿¡¼­ ¼ö½Å ¸Ş½ÃÁöÀÇ ¿ä¾à Á¤º¸ÀÔ´Ï´Ù. ¿¹¸¦ µé¾î RMI ·Î±×¸¦ ÃßÀûÇÒ ¶§, º¸³½ ¸Ş½ÃÁö°¡ ¾î¶² Çü½ÄÀÎÁö µîÀ» ¿ä¾àÇÏ¿© »ç¿ëÀÚ¿¡°Ô Á¦°øÇÕ´Ï´Ù. 

	\~english
	Summary of received message at IRmiStub::AfterRmiInvocation. For exmaple, it provide summary to user such as type of message when you tracking RMI log.

	\~chinese
	î¤IRmiStub::AfterRmiInvocation â¥ãáãáãÓîÜî×é©¡£ÖÇåıéÄRMIõÚñ¡logîÜ?ı¦£¬?âû?áêîÜãáãÓãÀì¤ä§?û¡ãÒÔõğ«Íê?éÄ?¡£

	\~japanese
	IRmiStub::AfterRmiInvocation ªÇáôãá«á«Ã«»?«¸ªÎé©å³ï×ÜÃªÇª¹¡£ÖÇª¨ªĞ¡¢RMI«í«°ªòõÚîæª¹ªëãÁ¡¢áêªÃª¿«á«Ã«»?«¸ª¬ªÉªóªÊû¡ãÒªÊªÎª«ªÊªÉªòé©å³ª·ªÆ«æ?«¶?ªËğ«Íêª·ªŞª¹¡£
	\~
	*/
	class AfterRmiSummary
	{
	public:
		/** 
		\~korean
		ÀÌ ¸Ş½ÃÁö°¡ RMI ¸Ş½ÃÁöÀÎ °æ¿ì RMIÀÇ ID°ªÀÔ´Ï´Ù. 

		\~english
		RMI ID if a message is RMI.

		\~chinese
		åıÍıó®ãáãÓãÀRMIîÜãáãÓîÜ?ãÀRMIîÜID?¡£

		\~japanese
		ª³ªÎ«á«Ã«»?«¸ª¬RMI«á«Ã«»?«¸ªÇª¢ªëíŞùê¡¢RMIªÎIDö·ªÇª¹¡£
		\~
		*/
		RmiID m_rmiID;
		/** 
		\~korean
		ÀÌ ¸Ş½ÃÁö°¡ RMI ¸Ş½ÃÁöÀÎ °æ¿ì RMIÀÇ ÇÔ¼ö¸íÀÔ´Ï´Ù.

		\~english
		RMI function name if a message is RMI.

		\~chinese
		åıÍıó®ãáãÓãÀRMIîÜãáãÓîÜ?ãÀRMIîÜùŞ?Ù£¡£

		\~japanese
		ª³ªÎ«á«Ã«»?«¸ª¬RMI«á«Ã«»?«¸ªÇª¢ªëíŞùê¡¢RMIªÎ??Ù£ªÇª¹¡£
		\~
		*/
		const PNTCHAR* m_rmiName;
		/** 
		\~korean
		º¸³½ HostÀÇ HostID ÀÔ´Ï´Ù. 

		\~english
		HostID of Host who sent

		\~chinese
		?áêîÜHostîÜHost ID¡£

		\~japanese
		áêªÃª¿HostªÎHostIDªÇª¹¡£
		\~
		*/
		HostID m_hostID;
		/** 
		\~korean
		»ç¿ëÀÚ°¡ ÁöÁ¤ÇÑ hostTagÀÇ Æ÷ÀÎÅÍÀÔ´Ï´Ù. 

		\~english
		Pointer of user defined hostTag.

		\~chinese
		éÄ?ò¦ïÒîÜhostTagîÜò¦?¡£

		\~japanese
		«æ?«¶?ª¬ò¦ïÒª·ª¿hostTagªÎ«İ«¤«ó«¿?ªÇª¹¡£
		\~
		*/
		void* m_hostTag;
		/** 
		\~korean
		¼ö½Å RMIÇÔ¼ö°¡ Ã³¸®µÇ´Âµ¥ °É¸®´Â ½Ã°£ 

		\~english
		Time to process received RMI function.

		\~chinese
		â¥ãáRMIùŞ?ù¬?×â?á¶âÍé©îÜ??¡£

		\~japanese
		áôãáRMI??ª¬?×âªµªìªëªËª«ª«ªëãÁÊà
		\~
		*/
		uint32_t m_elapsedTime;
	};

	/**  @} */
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif