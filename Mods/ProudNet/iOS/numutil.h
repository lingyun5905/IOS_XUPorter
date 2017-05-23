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
#include "quicksort.h"
#include "pnstdint.h" 

#if defined(_WIN32)
    #include <algorithm>
#endif

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup util_group
	*  @{
	*/

	/** 
	\~korean
	µÎ °ª v1,v2ÀÇ v1->v2·ÎÀÇ ³»ºĞ°ª ratioÀ» ±¸ÇÑ´Ù.
	ratio°¡ 0¿¡ °¡±î¿ï¼ö·Ï v1¿¡ °¡±õ´Ù. 

	\~english
	Obtains a interior division ratio of two values of v1,v2, v1->v2.
	As ratio gets closer to 0, it gets closer to v1.

	\~chinese
	Ï´èÙ???v1¡¢v2îÜv1->v2îÜ??ratio¡£
	Ration êÆïÈĞÎ0ö¦?êÆïÈĞÎv1.

	\~japanese
	?ö·v1¡¢v2ªÎv1->v2ªØªÎ?İÂö·ratioªòÏ´ªáªŞª¹¡£
	ratioª¬0ªËĞÎªÅª¯ªÛªÉv1ªËĞÎª¤ªÇª¹¡£
	\~
	*/
	template<typename T>
	inline T Lerp(T v1, T v2, T ratio)
	{
		return v1 + (v2 - v1)*ratio;
	}


	/**
	\~korean
 	LerpÀÇ Á¤¼öÇü ¹öÀü. ratioÀÇ ºĞÀÚ´Â ratio1,ºĞ¸ğ´Â ratio2

	\~english TODO:translate needed.
	Integer version of Lerp. Numerator of the ratio is ratio 1. Denominator is ratio 2. 

	\~chinese
	Lerp îÜïÚ?úş÷úÜâ¡£Ratio îÜİÂí­ãÀratio1£¬İÂÙ½ãÀratio2.

	\~japanese
	LerpªÎïÚ?úş«Ğ?«¸«ç«ó¡£RatioªÎİÂí­ªÏratio1¡¢İÂÙ½ªÏratio2
	\~
	*/
	template<typename T>
	inline T LerpInt(T v1, T v2,T ratio1, T ratio2)
	{
		return (v1 + ((v2 - v1)*ratio1)/ratio2);
	}

	/** 
	\~korean
	Round robin ½½·Ô ¼ıÀÚ »ı¼ºÀÚ.

	\~english
	Round robin slot number generator 

	\~chinese
	Round robin ?ğË£¨slot£©?í®ßæà÷íº¡£

	\~japanese
	Round robin «¹«í«Ã«È?í®ßæà÷í­
	\~
	*/
	class CRoundRobinNumberGenerator
	{
		int m_number;
	public:
		PROUD_API CRoundRobinNumberGenerator();

		PROUD_API int Next(int maxNumber);
	};
	/**  @} */

	// ÃâÃ³: http://www.java2s.com/Tutorial/Cpp/0260__template/Genericquicksort.htm

// 	template<typename T>
// 	inline void swap(T& v1,T& v2)
// 	{
// 		T temp=v2;
// 		v2=v1;
// 		v1=temp;
// 	}

}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
