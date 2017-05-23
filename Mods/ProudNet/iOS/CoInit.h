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

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup db_group
	*  @{
	*/

	/** 
	\~korean
	CoInitialize, CoUninitialize È£Ãâ ½ÖÀ» ¸ÂÃá´Ù.
	- ÀÏ¹İÀûÀ¸·Î CoInitialize¿Í CoUninitialize´Â È£Ãâ È½¼ö°¡ ±ÕÇüÀ» ¸ÂÃç¾ß ÇÏ¸ç, °¢ ½º·¹µå º°·Î È£ÃâÇØ¾ß ÇÏ´Â ¸Ş¼­µåÀÌ´Ù.
	ÀÚ¼¼ÇÑ °ÍÀº °¢ APIÀÇ ¹®¼­¸¦ Âü°íÇÒ °Í.
	- Á÷Á¢ CoInitialize(), CoUninitialize()¸¦ È£ÃâÇÏ´Â °Íº¸´Ù ÀÌ Å¬·¡½º¸¦ ·ÎÄÃ º¯¼ö·Î ¼±¾ğÇÏ´Â °ÍÀÌ ´õ ¾ÈÁ¤ÀûÀÌ´Ù.
	ÀÌ Å¬·¡½º´Â ÀÚµ¿À¸·Î CoUninitialize()¸¦ ÇÊ¿äÇÒ ¶§ È£ÃâÇÏ±â ¶§¹®ÀÌ´Ù.
	
	\~english
	This method works in a set of CoInitialize and CoUninitialize call.
	- It needs to be called per each threads and normally the number of calls for CoInitialize and CoUninitialize should be balanced.
	Refer to API document for more detailed information.
	- It's safer to declare this class as a local variable rather than directly calling for CoInitialize() and CoUninitialize(),
	since it automatically calls for CoUninitialize() when needed.
	
	\~chinese
	CoInitialize, CoUninitializeû¼Ğ£??¡£
	- ìéÚõ??CoInitializeûúCoUninitializeîÜû¼Ğ£ó­?é©?ñ×øÁû¬£¬ì¤Øß?ïïû¼Ğ£îÜÛ°ãÒ¡£
	??îÜ??ÍÅÊÀAPIÙşËì¡£
	- İïÑÃòÁïÈû¼Ğ£CoInitialize()£¬CoUninitialize()Û°Ûö£¬÷êó®?à¾Í±?Üâò¢??ÌÚ?ïÒ¡£
	ì×?ó®?âÍé©CoUninitialize()îÜ?ı¦?í»?û¼Ğ£¡£
	
	\~japanese
	CoInitialize, CoUninitialize û¼ªÓõóª·«Ú«¢ªòùêªïª»ªŞª¹¡£
	- ìéÚõîÜªË¡¢CoInitializeªÈCoUninitializeªÏû¼ªÓõóª·üŞ?ªË«Ğ«é«ó«¹ªòö¢ªëù±é©ª¬ª¢ªÃªÆ¡¢ÊÀ«¹«ì«Ã«ÉÜ¬ªËû¼ªÓõóªµªÊª±ªìªĞªÊªéªÊª¤«á«½«Ã«ÉªÇª¹¡£
	ßÙª·ª¯ªÏÊÀAPIªÎÙşßöªòª´?ğÎª¯ªÀªµª¤¡£
	- òÁïÈCoInitialize(), CoUninitialize()ªòû¼ªÓõóª¹ª³ªÈªèªêªÏ¡¢ª³ªÎ«¯«é«¹ªò«í?«««ë??ªÇà¾åëª·ª¿Û°ª¬ªâªÃªÈäÌïÒîÜªÇª¹¡£
	ª³ªÎ«¯«é«¹ªÏí»ÔÑªËCoUninitialize()ªòù±é©ªÈª¹ªëãÁªËû¼ªÓõóª¹ª¿ªáªÇª¹¡£
	\~
	*/
	class CCoInitializer
	{
		bool m_success;
	public:
		PROUD_API CCoInitializer();
		PROUD_API ~CCoInitializer();
	};

	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif