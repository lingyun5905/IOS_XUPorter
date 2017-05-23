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

#include "ProcHeap.h"
#include "Exception.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif

	/** \addtogroup util_group
	*  @{
	*/

	/** 
	\~korean
	<a target="_blank" href="http://guide.nettention.com/cpp_ko#quantizer" >µ¥ÀÌÅÍ ¾çÀÚÈ­</a> ±â´ÉÀ» ´ã´çÇÏ´Â Å¬·¡½ºÀÔ´Ï´Ù.

	\~english
	Class manages <a target="_blank" href="http://guide.nettention.com/cpp_en#quantizer" >Data Quantization</a> function

	\~chinese
	?ìò<a target="_blank" href="http://guide.nettention.com/cpp_zh#quantizer" >?ËßÕáí­ûù</a>%ÍíÒöîÜ? ¡£

	\~japanese
	\ref quantizer  Ñ¦Òöªò??ª¹ªë«¯«é«¹ªÇª¹¡£
	\~
	*/
	class CQuantizer
	{
		double m_min,m_max;
		uint32_t m_granulation;
	public:
		/** 
		\~korean
		»ı¼ºÀÚ
		\param min ¾çÀÚÈ­µÇ´Â °ªÀº ÀÌ °ª ÀÌÇÏ·Î´Â µé¾î°¡Áö ¾Ê½À´Ï´Ù.
		\param max ¾çÀÚÈ­µÇ´Â °ªÀº ÀÌ °ª ÀÌ»óÀ¸·Î´Â µé¾î°¡Áö ¾Ê½À´Ï´Ù.
		\param granulation ¾çÀÚÈ­µÇ´Â °ªÀº Á¤¼ö Å¸ÀÔÀÔ´Ï´Ù. º» °ªÀº ¾çÀÚÈ­µÇ´Â °ªÀÌ 0ºÎÅÍ ¾ó¸¶±îÁöÀÇ Á¤¼öÇüÀ¸·Î º¯È¯µÇ´À³Ä¸¦ ÁöÄªÇÕ´Ï´Ù.
		°ªÀÌ Å¬¼ö·Ï ¾çÀÚÈ­µÈ °ªÀÇ Á¤¹Ğµµ°¡ ³ôÁö¸¸ ¾çÀÚÈ­µÈ µ¥ÀÌÅÍ°¡ ÇÊ¿ä·Î ÇÏ´Â ºñÆ®¼ö°¡ Áõ°¡ÇÏ°Ô µË´Ï´Ù. 

		\~english
		Constructor
		\param min the quantized value will not be entered and no less than this value.
		\param max the quantized value will not be entered and no more than this value.
		\param granulation the quantized value has integer type. This value points that the quantized value is to be converted from 0 to which integer.
		Larger value provides more pricise quantized value but the number of bits required by quantized data.

		\~chinese
		ßæà÷í­
		\param min ?ìıÕáí­ûùîÜ?ÜôÒöî¸éÍó®?¡£
		\param ma ?ìıÕáí­ûùîÜ?ÜôÒöÍÔéÍó®?¡£
		\param granulation Õáí­ûùîÜ?ãÀïá??¡£ó®?ãÀò¦?Õáí­ûùîÜ?????0ÓğÒıá´îÜïá??¡£
		?êÆÓŞ£¬Õáí­ûùîÜ?ïñÓøêÆÓŞ£¬Ó£ãÀÕáí­ûùîÜ?ËßâÍé©îÜbit??ñòÊ¥¡£

		\~japanese
		ßæà÷í­
		\param min Õáí­ûùªµªìªëö·ªÏª³ªÎö·ì¤ù»ªËªÏìıªêªŞª»ªó¡£
		\param min Õáí­ûùªµªìªëö·ªÏª³ªÎö·ì¤ù»ªËªÏìıªêªŞª»ªó¡£
		\param max ¾çÀÚÈ­µÇ´Â °ªÀº ÀÌ °ª ÀÌÇÏ·Î´Â µé¾î°¡Áö ¾Ê½À´Ï´Ù.
		\param granulation Õáí­ûùªµªìªëö·ªÏïÚ?«¿«¤«×ªÇª¹¡£ª³ªÎö·ªÏÕáí­ûùªµªìªëö·ª¬0ª«ªéª¤ª¯ªéªŞªÇªÎïÚ?úşªË?üµªµªìªëª«ªòò¦ª·ªŞª¹¡£
		ö·ª¬ÓŞª­ª¤ªÛªÉÕáí­ûùªµªìª¿ö·ªÎïñÚËÓøª¬ÍÔª¤ªÇª¹ª¬¡¢Õáí­ûùªµªìª¿«Ç?«¿ª¬ù±é©ªÈª¹ªë«Ó«Ã«É?ª¬?Ê¥ª·ªŞª¹¡£
		\~
		*/
		CQuantizer( double min, double max, uint32_t granulation )
		{
			m_min = min;
			m_max = max;
			m_granulation = granulation;
		}

		/** 
		\~korean
		¾çÀÚÈ­¸¦ ÇÕ´Ï´Ù. 

		\~english
		Quantizing

		\~chinese
		?ú¼Õáí­ûù¡£

		\~japanese
		Õáí­ûùªòª·ªŞª¹¡£
		\~
		*/
		uint32_t Quantize(double value)
		{
			value = PNMIN(m_max, value);
			value = PNMAX(m_min, value);
			double range = m_max - m_min;
			double offset = value - m_min;
			double offset2 = offset / range * (double)m_granulation;
			return (uint32_t)offset2;
		}

		/** 
		\~korean
		¾çÀÚÈ­µÈ °ªÀ» º¹¿øÇÕ´Ï´Ù. 

		\~english
		Recover quantized value

		\~chinese
		üá?Õáí­ûùîÜ?¡£

		\~japanese
		Õáí­ûùªµªìª¿ö·ªòÜÖêªª·ªŞª¹¡£
		\~
		*/
		double Dequantize(uint32_t value)
		{
			double offset = (double)value;
			double range = m_max - m_min;
			double offset2 = offset / (double)m_granulation * range;
			return offset2 + m_min;
		}

#ifdef _WIN32
#pragma push_macro("new")
#undef new
		// ÀÌ Å¬·¡½º´Â ProudNet DLL °æ¿ì¸¦ À§ÇØ Ä¿½ºÅÒ ÇÒ´çÀÚ¸¦ ¾²µÇ fast heapÀ» ¾²Áö ¾Ê´Â´Ù.
		DECLARE_NEW_AND_DELETE
#pragma pop_macro("new")
#endif
	};


	/**  @} */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif