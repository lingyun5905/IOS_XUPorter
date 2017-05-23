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
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif

	/** \addtogroup util_group
	*  @{
	*/

	/** 
	\~korean
	°íÁ¤ Å©±âÀÇ ¹è¿­ Å¬·¡½º. 
	- T data[] Çü½ÄÀÇ °íÁ¤ Å©±â ´Ü¼ø ¹è¿­À» bounds checkingÀ» ÇÏ·Á¸é ÀÌ Å¬·¡½º·Î ´ëÃ¼ÇØ¼­ ¾ÈÁ¤¼ºÀ» µµ¸ğÇÒ ¼ö ÀÖ´Ù.

	ÀÏ¹İÀû ¿ëµµ
	- CAtlArray ¸¦ Ä«ÇÇÇØ´Ù ¸¸µé¾úÀ¸¹Ç·Î CAtlArray ¿Í »ç¿ë¹ıÀÌ °ÅÀÇ À¯»çÇÏ´Ù. ´Ü, staticÀÌ´Ï ´ç¿¬ÇÏÁö¸¸, »ğÀÔ/Á¦°Å/Ã»¼Ò µîÀÇ ±â´ÉÀÌ ºüÁ®ÀÖ´Ù. 

	ÁÖÀÇ»çÇ×
	- ±âÁ¸ Á¤Àû ¹è¿­À» CFixedLengthArray ·Î ¹Ù²Ü °æ¿ì _countof()³ª sizeof()¸¦ ¾²´Â °æ¿ì°¡ ÀÖÀ» ÅÍÀÎµ¥, ÀÌ·¯ÇÑ ºÎºĞÀ» Ã£¾Æ¼­ ¼öÁ¤ÇØ¾ß ÇÑ´Ù.
	¿¹ÄÁ´ë _countof()´Â Ç×»ó 1À» ¸®ÅÏÇÒ °ÍÀÌ±â ¶§¹®ÀÌ´Ù.

	\~english
	Array class with fixed size 
	- To 'bounds check' a simple, fixed size array of T data[] format, it is possible to replace with this class to draw stability.

	General usage
	- Has similar usage of CAtlArray since this is copied and made from it, but it does not have insertion/removal/cleanup functions since it is static. (of course...) 

	Note
	- If replacing the existing static array with CFixedLengthArray then there can be cases that either _countof() or sizeof() is used. << must modify them correctly.
	This is because of the fact that _countof() will always return 1.

	\~chinese
	Í³ïÒÓŞá³îÜ???¡£
	- ßÌbounds checking T data[]û¡ãÒîÜÍ³ïÒÓŞá³????£¬éÄó®?ÓÛôğı¨Ê¦?ÔğÌÚû¿îÜ?ïÒàõ¡£

	ìéÚõéÄÔ²
	- ì×?ãÀ?ğ¤ CAtlArray%ğ¤íÂîÜ£¬á¶ì¤? CAtlArray%îÜŞÅéÄÛ°ÛöĞñÜâßÓŞÄ¡£ì×?ãÀstaticá¶ì¤ù±ïÒ?ßÓŞÄ£¬Ó£×ìØüÊ¿?êó?ìı/?ğ¶/?ğ¶ÔõÍíÒö¡£

	ñ¼ëòŞÀßÚ
	- ßÌ÷êñıîñ????ôğ?? CFixedLengthArray%îÜ?£¬Ê¦Òö?êóéÄ_countof()ûäíºsizeof()£¬é©?Óğ?ŞÁ?????ú¼áóËÇ¡£
	ÖÇåı£¬ì×?_countof()ìéòÁ?Ú÷üŞ1¡£

	\~japanese
	Í³ïÒ«µ«¤«ºªÎÛÕÖª«¯«é«¹
	- T data[] û¡ãÒªÎÍ³ïÒ«µ«¤«ºªÎ?âíÛÕÖªªòbounds checkingª¹ªëª¿ªáªËªÏ¡¢ª³ªÎ«¯«é«¹ªËôğªïªÃªÆäÌïÒàõªò?ªëª³ªÈª¬ªÇª­ªŞª¹¡£

	ìéÚõîÜªÊéÄÔ²
	- CAtlArrayªò«³«Ô?ª·ªÆŞÅªÃª¿ª¿ªá¡¢CAtlArrayªÈŞÅéÄÛ°Ûöª¬ªÛªÜ×¾ŞÄª·ªÆª¤ªŞª¹¡£Ó£ª·¡¢staticªÊªÎªÇ?æÔªÇª¹ª¬¡¢?ìı/ğ¶ËÛ/á·ğ¶ªÊªÉªÎÑ¦Òöª¬?ª±ªÆª¤ªŞª¹¡£ 

	ª´ñ¼ëòŞÀú£
	- ?ğíªÎ«¹«¿«Æ«£«Ã«¯ÛÕÖªªòCFixedLengthArrayªË?ª¨ªëíŞùê¡¢_countof()ª«sizeof()ªòŞÅª¦íŞùêª¬ª¢ªêªŞª¹ª¬¡¢ª³ªÎªèª¦ªÊİ»İÂªò÷®ª·ªÆáóïáª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£
	ÖÇª¨ªĞ¡¢_countof()ªÏª¤ªÄªâ1ªò«ê«¿?«óª¹ªëªÏªºªÀª«ªéªÇª¹¡£
	\~
	*/
	template<int size,typename TYPE, typename ARG_TYPE = const TYPE&>
	class CFixedLengthArray 
	{
	public:

		// Á¦´ë·Î µÈ ÀÎµ¦½º ¹øÈ£°¡ ¾Æ´Ï¸é ¿¡·¯ ¹ß»ıÇÑ´Ù.
		inline void CheckValidIndex(int nIndex) const
		{
			if(!(0<=nIndex && nIndex<size) )
				ThrowArrayOutOfBoundException();
		}

		/**
		\~korean
		¹è¿­ ±æÀÌ¸¦ ±¸ÇÑ´Ù.

		\~english
		Gets length of array

		\~chinese
		Ï´???Óø¡£

		\~japanese
		ÛÕÖªªÎíşªµªòÏ´ªáªŞª¹¡£
		\~
		*/
		inline int GetSize() const { return size; }

		/**
		\~korean
		¹è¿­ ±æÀÌ¸¦ ±¸ÇÑ´Ù.

		\~english
		Gets length of array

		\~chinese
		Ï´???Óø¡£

		\~japanese
		ÛÕÖªªÎíşªµªòÏ´ªáªŞª¹¡£
		\~
		*/
		inline int GetCount() const { return size; }

		/**
		\~korean
		¹è¿­ÀÌ ºñ¾ú´Â°¡?

		\~english
		Is array empty?

		\~chinese
		??ÍöÖõ?£¿

		\~japanese
		ÛÕÖªª¬Íöª¤ªÆª¤ªŞª¹ª«£¿
		\~
		*/
		inline bool IsEmpty() const { return size==0; }

		/**
		\~korean
		¹è¿­ Ç×¸ñ Á¢±ÙÀÚ 

		\~english
		Array item accessor

		\~chinese
		???ÙÍ??íº¡£

		\~japanese
		ÛÕÖªú£ÙÍªÎïÈĞÎíº
		\~
		*/
		inline const TYPE& GetAt(int nIndex) const { CheckValidIndex(nIndex); return m_data[nIndex]; }

		/**
		\~korean
		¹è¿­ Ç×¸ñ Á¢±ÙÀÚ

		\~english
		Array item accessor 

		\~chinese
		???ÙÍ??íº¡£

		\~japanese
		ÛÕÖªú£ÙÍªÎïÈĞÎíº
		\~
		*/
		inline TYPE& GetAt(int nIndex) { CheckValidIndex(nIndex); return m_data[nIndex]; }	

		/**
		\~korean
		¹è¿­ Ç×¸ñ Á¢±ÙÀÚ

		\~english
		Array item accessor 

		\~chinese
		???ÙÍ??íº¡£

		\~japanese
		ÛÕÖªú£ÙÍªÎïÈĞÎíº
		\~
		*/
		inline void SetAt(int nIndex, ARG_TYPE newElement) { CheckValidIndex(nIndex); m_data[nIndex]=newElement; }

		/**
		\~korean
		¹è¿­ Ç×¸ñ Á¢±ÙÀÚ

		\~english
		Array item accessor

		\~chinese
		???ÙÍ??íº¡£

		\~japanese
		ÛÕÖªú£ÙÍªÎïÈĞÎíº
		\~
		*/
		inline const TYPE& ElementAt(int nIndex) const {CheckValidIndex(nIndex); return m_data[nIndex]; }

		/**
		\~korean
		¹è¿­ Ç×¸ñ Á¢±ÙÀÚ

		\~english
		Array item accessor

		\~chinese
		???ÙÍ??íº¡£

		\~japanese
		ÛÕÖªú£ÙÍªÎïÈĞÎíº
		\~
		*/
		inline TYPE& ElementAt(int nIndex){CheckValidIndex(nIndex); return m_data[nIndex];}

		/**
		\~korean
		¹è¿­ ¹öÆÛ °´Ã¼ÀÇ Æ÷ÀÎÅÍ¸¦ ¾ò´Â´Ù.

		\~english
		Gets pointer of array buffer object

		\~chinese
		?ö¢???ğí??ßÚîÜò¦?¡£

		\~japanese
		ÛÕÖª«Ğ«Ã«Õ«¡?«ª«Ö«¸«§«¯«ÈªÎ«İ«¤«ó«¿?ªòÔğªŞª¹¡£
		\~
		*/
		inline const TYPE* GetData() const {return m_data;}

		/**
		\~korean
		¹è¿­ ¹öÆÛ °´Ã¼ÀÇ Æ÷ÀÎÅÍ¸¦ ¾ò´Â´Ù.

		\~english
		Gets pointer of array buffer object

		\~chinese
		?ö¢???ğí??ßÚîÜò¦?¡£

		\~japanese
		ÛÕÖª«Ğ«Ã«Õ«¡?«ª«Ö«¸«§«¯«ÈªÎ«İ«¤«ó«¿?ªòÔğªŞª¹¡£
		\~
		*/
		inline TYPE* GetData(){return m_data;}

		/**
		\~korean
		¹è¿­ Ç×¸ñ Á¢±ÙÀÚ

		\~english
		Array item accessor

		\~chinese
		???ÙÍ??íº¡£

		\~japanese
		ÛÕÖªú£ÙÍªÎïÈĞÎíº
		\~
		*/
		inline const TYPE& operator[](int nIndex) const{CheckValidIndex(nIndex); return m_data[nIndex];}	
		
		/**
		\~korean
		¹è¿­ Ç×¸ñ Á¢±ÙÀÚ

		\~english
		Array item accessor

		\~chinese
		???ÙÍ??íº¡£

		\~japanese
		ÛÕÖªú£ÙÍªÎïÈĞÎíº
		\~
		*/
		inline TYPE& operator[](int nIndex){CheckValidIndex(nIndex); return m_data[nIndex];}

	private:
		TYPE m_data[size];   // the actual array of data
	};

	/**  @} */

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
