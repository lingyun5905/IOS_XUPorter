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
	/** \addtogroup util_group
	*  @{
	*/

	class CPnIconv;
	class CStringEncoderImpl;

	/** 
	\~korean
	iconv ·¡ÆÛ Å¬·¡½ºÀÔ´Ï´Ù.
	- Create·Î »ı¼º ÈÄ ÇÊ¿äÇÒ ¶§¸¶´Ù ·ÎÄÃ º¯¼ö·Î¼­ GetIconv-ReleaseIconv¸¦ ¾²½Ã¸é µË´Ï´Ù.
	- ¿©·¯ ½º·¹µå¿¡¼­ÀÇ µ¿½Ã Á¢±ÙÀ» À§ÇÑ ¿ÀºêÁ§Æ® Ç®¸µÀÇ ÇüÅÂ·Î iconv °´Ã¼¸¦ Á¦°øÇÕ´Ï´Ù. 
	µû¶ó¼­ ¼Óµµ°¡ ºü¸¨´Ï´Ù. 

	ProudNetÀº ¹®ÀÚ¿­ Ã³¸®¸¦ À§ÇØ À©µµ¿¡¼­µµ ÀÌ°ÍÀ» »ç¿ëÇØ¼­ ÀÛµ¿ÇÕ´Ï´Ù. 
	°ú°Å¿¡´Â win32 ±â´ÉÀ» »ç¿ëÇßÁö¸¸ ¸ÖÆ¼ÇÃ·§Æû ´ÜÀÏÈ­¸¦ À§ÇØ¼­ÀÔ´Ï´Ù.

	\~english
	It is a wrapper class. 
	- After creating by ¡°create¡±, you can use GetIconv-ReleaseIconv as the local variable whenever needed. 
	- iconv objective is provided as the form of object pooling for concurrent access to many threads. 
	As a result of this, it is fast. 

	ProudNet used win32 function in the past but for unifying multi-platform, it uses this in Windows for string processing.

	\~chinese
	iconv ãÀøĞ??¡£
	- éÄCreateßæà÷ı¨£¬î¤ù±é©?ì¤Üâò¢?ÕáŞÅéÄGetIconv-ReleaseIconv?Ê¦¡£
	- ãÀî¤Òı??ïïñé??ú¼ÔÒ?ïÈĞÎîÜ?ßÚò®û¡ãÒ£¬ğ«Íêiconv?ßÚ¡£ì×ó®áÜÓø?öá¡£ 

	??×âí®İ¬Íú£¬ProudNetî¤Windowsñéå¥ŞÅéÄó®iconv?ú¼¡£
	?ËÛŞÅéÄÖõwin32ÍíÒö£¬Ó£?î¤ŞÅéÄiconvãÀ?ÖõÒıøÁ÷»îÜ?ìéûù¡£

	\~japanese
	iconv¡¡wrapper«¯«é«¹ªÇª¹¡£.
	- CreateªÇßæà÷ª·ªÆª«ªéù±é©ªÊãÁªË«í?«««ë??ªÈª·ªÆ GetIconv-ReleaseIconvªòŞÅªÃªÆª¯ªÀªµª¤¡£
	- ßä?ªÊ«¹«ì«Ã«ÉªÇªÎÔÒãÁïÈĞÎªÎª¿ªáªÎ«ª«Ö«¸«§«¯«×?«ê«ó«°ªÎû¡÷¾ªÇ iconv «ª«Ö«¸«§«¯«Èªòğ«Íêª·ªŞª¹¡£ 
	¡¡ª·ª¿ª¬ªÃªÆáÜÓøª¬áÜª¤ªÇª¹¡£

	 ProudNetªÏÙşí®Öª?×âªÎª¿ªáªËWindowsªÇªâª³ªìªòŞÅªÃªÆíÂÔÑª·ªŞª¹¡£ 
	 Î¦ËÛªËªÏ win32Ñ¦ÒöªòŞÅéÄª·ªŞª·ª¿ª¬¡¢úŞî¤ªÏ«Ş«ë«Á«×«é«Ã«È«Õ«©?«à?ìéûùªÎª¿ªáªËó­ªÎªèª¦ªË?ÌÚªµªìªŞª·ª¿¡£

	\~

	Example code:
	\code
	StringA2W(a, b); // use platform-specific default encoder

	// use the encoder you select
	shared_ptr<CStringEncoder> e(CStringEncoder::Create("UTF-8", "UTF-16LE"));
	StringA2W(a, b, e);
	\endcode

	*/
	class CStringEncoder
	{
	private:
		CStringEncoder(const char* srcCodepage, const char* destCodepage);
	public:
		static CStringEncoder* Create(const char* srcCodepage, const char* destCodepage);
		virtual ~CStringEncoder();
		CPnIconv* GetIconv();
		void ReleaseIconv(CPnIconv *obj);
	private:
		CStringEncoderImpl* m_pimpl;
	};

	PROUD_API void iconv_string_convert(CStringEncoder* encoder, const char* input, size_t* inbytesleft, char* out, size_t* outbytesleft);

/**  @} */
}
#ifdef _MSC_VER
#pragma pack(pop)
#endif