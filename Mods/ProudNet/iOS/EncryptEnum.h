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
	/** \addtogroup net_group
	*  @{
	*/

	// ÁÖÀÇ: ÀÌ°Íµµ ¹Ù²Ù¸é ProudClr namespaceÀÇ µ¿¸í ½Éº¼µµ ¼öÁ¤ÇØ¾ß ÇÑ´Ù.

	/** 
	\~korean
	¾ÏÈ£È­ ¹× º¹È£È­ ¼³Á¤°ªÀÔ´Ï´Ù.

	\~english
	Setup value of encryption and decryption

	\~chinese
	Ê¥ÚËì¤Ğàú°ÚË?ïÒ?¡£

	\~japanese
	äŞ?ûùĞàªÓÜÖ?ûùªÎàâïÒö·ªÇª¹¡£
	\~
	*/
	enum EncryptMode
	{
		/** 
		\~korean
		¾ÏÈ£È­¸¦ ¾ÈÇÕ´Ï´Ù.

		\~english
		Do not encrypt

		\~chinese
		ÜôÊ¥ÚË¡£

		\~japanese
		äŞ?ûùªòª·ªŞª»ªó¡£
		\~
		*/
		EM_None,		
		/** 
		\~korean
		RSA¿Í AES¸¦ È¥¿ëÇÑ ¾ÏÈ£È­¸¦ ¼öÇàÇÕ´Ï´Ù. ·Î±×¿Â µî º¸¾È¼ºÀÌ ³ôÀº ¸Ş½ÃÁö¿¡ ¾²½Ê½Ã¿À.

		\~english
		Do encryption that mixture with RSA and AES. Do not use with secure message such as logon

		\~chinese
		?ú¼ûèéÄRSAûúAESîÜÊ¥ÚË¡£éÄî¤ßÀÔô?ÔõäÌîïàõÍÔîÜãáãÓß¾¡£

		\~japanese
		RSAªÈAESªòûèéÄª·ª¿äŞ?ûùªòâÄú¼ª·ªŞª¹¡£«í«°«ª«óªÊªÉ«»«­«å«ê«Æ«£àõªÎÍÔª¤«á«Ã«»?«¸ªËŞÅªÃªÆª¯ªÀªµª¤¡£
		\~
		*/
		EM_Secure,		
		/** 
		\~korean
		RSA¿Í Fast¸¦ È¥¿ëÇÑ ¾ÏÈ£È­¸¦ ¼öÇàÇÕ´Ï´Ù. Ä³¸¯ÅÍ ÀÌµ¿ µî ¾à°£ÀÇ ¾ÏÈ£È­´Â ÇÊ¿äÇÏÁö¸¸ ¼º´É ¶ÇÇÑ °í·ÁÇØ¾ß ÇÏ´Â »óÈ²¿¡¼­ ¾²½Ê½Ã¿À.

		\~english
		Do encryption that mixture with RSA and Fast. Encryption is required like moving character but please consider about performance.

		\~chinese
		?ú¼ûèéÄRSAûúFastîÜÊ¥ÚË¡£åıÊÇßäì¹?Ôõ?Ê¥ÚËïïÓøÜôÍÔ£¬Ó£âÍÍÅ?àõÒöîÜ??ù»?ŞÅéÄó®Û°Ûö¡£ 

		\~japanese
		RSAªÈFastªòûèéÄª·ª¿äŞ?ûùªòâÄú¼ª·ªŞª¹¡£«­«ã«é«¯«¿?ì¹ÔÑªÊªÉá´ª·ªÎäŞ?ûùªÏù±é©ªÇª¹ª¬¡¢àõÒöªâÍÅÕçª¹ªÙª­?üÏªÇŞÅªÃªÆª¯ªÀªµª¤¡£
		\~
		*/
		EM_Fast,			
		EM_LAST,
	};

	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
