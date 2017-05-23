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

#ifdef USE_HLA
#include "HlaEntity_S.h"
#include "HlaDelagate_Common.h"

namespace Proud 
{
	class CHlaEntityManagerBase_S;
	class CriticalSection;
	class CHlaSpace_S;
	class IHlaDelegate_S;

	/**
	\~korean
	HLA ¼¼¼Ç ¼­¹ö ¸Ş¼­µå ÀÎÅÍÆäÀÌ½ºÀÔ´Ï´Ù.

	\~english TODO:translate needed.
	This is a HLA session server method interface. 

	\~chinese
	ãÀHLA sessionÜ×?ĞïÛ°ÛöÍ£Øü¡£

	\~japanese
	HLA«»«Ã«·«ç«ó«µ?«Ğ?«á«½«Ã«É«¤«ó«¿?«Õ«§?«¹ªÇª¹¡£
	\~
	*/
	class IHlaHost_S
	{
	public:
		virtual ~IHlaHost_S() {};

		/** 
		\~korean
		HLA entity class¸¦ µî·ÏÇÕ´Ï´Ù. 
		HLA entity class´Â HLA compiler outputÀÌ¾î¾ß ÇÕ´Ï´Ù. 

		\~english TODO:translate needed.
		An HLA entity class is registered. 
		An HLA entity class must be HLA complier output. 
	
		\~chinese
		Ôô?HLA entity class¡£
		HLA entity classÔğãÀHLA compiler output¡£

		\~japanese
		HLA entity classªòÔô?ª·ªŞª¹¡£
		HLA entity classªÏHLA compiler outputªÇªÏªÊª±ªìªĞªÊªêªŞª»ªó¡£

		*/
		virtual void HlaAttachEntityTypes(CHlaEntityManagerBase_S* entityManager) = 0;

		/** 
		\~korean
		ÀÌ ¸ğµâ¿¡ ÀÇÇØ Äİ¹éµÇ´Â ¸Ş¼­µåµéÀ» ±¸ÇöÇÑ °´Ã¼¸¦ ¹Ş¾ÆµéÀÔ´Ï´Ù. 

		\~english TODO:translate needed.
		This receives the objects that implements the methods called back by this module. 
	
		\~chinese
		î¤ïÈâ¥??ù¬ó®Ù¼?îÜüŞ?Û°ÛöîÜ?ßÚ¡£

		\~japanese
		ª³ªÎ«â«¸«å?«ëªËªèªÃªÆ«³?«ë«Ğ«Ã«¯ªµªìªë«á«½«Ã«Éªò?úŞª·ª¿«ª«Ö«¸«§«¯«Èªòáôª±ìıªìªŞª¹¡£

		*/
		virtual void HlaSetDelegate(IHlaDelegate_S* dg) = 0;

		/** 
		\~korean
		»ç¿ëÀÚ´Â ÀÌ ÇÔ¼ö¸¦ ÀÏÁ¤ ½Ã°£¸¶´Ù Äİ ÇØ¾ß ÇÕ´Ï´Ù. 

		\~english TODO:translate needed.
		Users must call this function at a certain interval. 
	
		\~chinese
		éÄ?é©î¤ØßÌ°ìéÓ«???ó®ùŞ?¡£

		\~japanese
		«æ?«¶?ªÏª³ªÎ??ªòá¶ïÒãÁÊàª´ªÈªËû¼ªÓõóªµªÊª±ªìªĞªÊªêªŞª»ªó¡£

		*/
		virtual void HlaFrameMove() = 0;
		
		virtual CHlaSpace_S* HlaCreateSpace() = 0;
		virtual void HlaDestroySpace(CHlaSpace_S* space) = 0;

		virtual CHlaEntity_S* HlaCreateEntity(HlaClassID classID) = 0;
		virtual void HlaDestroyEntity(CHlaEntity_S* Entity) = 0;

		virtual void HlaViewSpace(HostID viewerID, CHlaSpace_S* space, double levelOfDetail = 1) = 0;
		virtual void HlaUnviewSpace(HostID viewerID, CHlaSpace_S* space) = 0;
	};

	/** 
	\~korean
	HLA ¼¼¼Ç ¼­¹ö¿¡ ÀÇÇØ Äİ¹éµÇ´Â ÀÎÅÍÆäÀÌ½ºÀÔ´Ï´Ù. 
	
	Âü°í
	- C++ ÀÌ¿Ü ¹öÀü¿¡¼­´Â º» ¸Ş¼­µå´Â delegate callback ÇüÅÂÀÏ ¼ö ÀÖ½À´Ï´Ù. 

	\~english
	This is an interface called back by the HLA session server.

	Note
	- In versions other than C++, this method may be in the form of delegate callback. 
	
	\~chinese
	ù¬HLA??Ü×?ĞïüŞ?îÜïÈÏ¢¡£ 
	?ğÎ
	- î¤C++ ñıèâîÜ÷úÜâñéÜâÛ°ÛöÊ¦ì¤ãÀdelegate callbackû¡ãÒ¡£ 

	\~japanese
	HLA«»«Ã«·«ç«ó«µ?«Ğ?ªËªèªÃªÆ«³?«ë«Ğ«Ã«¯ªµªìªë«¤«ó«¿?«Õ«§?«¹ªÇª¹¡£
	
	?ÍÅ
	- C++ ì¤èâªÎ«Ğ?«¸«ç«óªÇªÏ¡¢Üâ«á«½«Ã«ÉªÏdelegate callbackû¡÷¾ªÇª¢ªëíŞùêª¬ª¢ªêªŞª¹¡£

	*/
	class IHlaDelegate_S:public IHlaDelegate_Common
	{
	public:
		virtual ~IHlaDelegate_S() {}

	};
}
#endif
#ifdef _MSC_VER
#pragma pack(pop)
#endif