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
	/** \addtogroup util_group
	*  @{
	*/

	class CMemoryHeap;
	class CriticalSection;

	/** 
	\~korean
	Fast HeapÀ» Á¢±ÙÇÏ´Â ¹æ½ÄÀÔ´Ï´Ù.

	\~english
	This is how to access Fast Heap.

	\~chinese
	ïÈĞÎFast HeapîÜÛ°ãÒ¡£

	\~japanese
	Fast Heapªò«¢«¯«»«¹ª¹ªëÛ°ãÒªÇª¹¡£
	\~
	*/
	enum FastHeapAccessMode
	{
		/** 
		\~korean
		´Ü ÇÑ°³ÀÇ ½º·¹µå¸¸ÀÌ Fast HeapÀ» Á¢±ÙÇÏÁö¸¸ Fast Heap ³»ºÎ°¡ Thread safeÇÏÁö ¾Ê½À´Ï´Ù.
		ÀÌ ¼³Á¤Àº ´Ü ÇÑ°³ÀÇ ½º·¹µå¸¸ÀÌ Fast HeapÀ» Á¢±ÙÇÑ´Ù´Â °ÍÀÌ º¸ÀåµÉ ¶§¸¸ »ç¿ëÇÏ½Ê½Ã¿À!

		\~english
		Only 1 tread accesses to Fast Heap but the inside of Fast Heap is not Thread safe.
		This setting must be used when there is a guarantee that onl 1 thread accessed to Fast Heap.!

		\~chinese
		?æÔñşêóìé??ïïïÈĞÎFast Heap£¬Ó£Fast Heap?İ»ÜôThread safe¡£
		?î¤ÜÁî¡ñşêóìé??ïïïÈĞÎFast Heap?ŞÅéÄó®?öÇ£¡

		\~japanese
		ª¿ªÃª¿ìéªÄªÎ«¹«ì«Ã«ÉªÎªßª¬Fast Heapªò«¢«¯«»«¹ª·ªŞª¹ª¬¡¢Fast Heap?İ»ª¬Thread safeªÇªÏª¢ªêªŞª»ªó¡£
		ª³ªÎàâïÒªÏª¿ªÃª¿ìéªÄªÎ«¹«ì«Ã«ÉªÎªßª¬Fast Heapªò«¢«¯«»«¹ª¹ªëªÈª¤ª¦ª³ªÈª¬ÜÁî¡ªµªìªëãÁªÎªßŞÅªÃªÆª¯ªÀªµª¤£¡
		\~
		*/
		FastHeapAccessMode_UnsafeSingleThread,
		
		/** 
		\~korean
		¿©·¯ ½º·¹µå¿¡¼­ Fast HeapÀ» Á¢±ÙÇØµµ ¾ÈÀüÇÏ°Ô ÀÛµ¿ÇÕ´Ï´Ù. ±×¸®°í ¸ğµç CPU ÄÚ¾î¸¦ È°¿ëÇÏ´Â ÀÛµ¿¹ıÀ» ±¸»çÇÕ´Ï´Ù.

		\~english
		This operates safely even if multiple threads accee to Fast Heap. And has a way to utilize all of CPU cores.

		\~chinese
		?Î·Òı??ïïïÈĞÎFast Heap£¬Ğìå¥ÒöäÌîïò¢??¡£æÔı¨?éÄá¶êóCPUú·ãıîÜ??Û°Ûö¡£

		\~japanese
		ÜÜ?ªÎ«¹«ì«Ã«ÉªÇFast Heapªò«¢«¯«»«¹ª·ªÆªâäÌîïªËíÂÔÑª·ªŞª¹¡£ª½ª·ªÆ¡¢ª¹ªÙªÆªÎCPU«³«¢ªòüÀéÄª¹ªëíÂÔÑÛöªò?ŞÅª·ªŞª¹¡£
		\~
		*/
		FastHeapAccessMode_MultiThreaded,
	};

	/** 
	\~korean
	Fast Heap°ú Lookaside AllocatorÀÇ È¯°æ¼³Á¤À» ´ã°í ÀÖ½À´Ï´Ù.

	\~english
	Settings environment for Fast Heap and Lookaside Allocator

	\~chinese
	øĞùßó·Fast HeapûúLookaside AllocatorîÜ?ÌÑ?öÇ¡£

	\~japanese
	Fast HeapªÈLookaside AllocatorªÎü»ÌÑàâïÒªò?ªáªÆª¤ªŞª¹¡£
	\~
	*/
	class CFastHeapSettings
	{
	public:
		/** 
		\~korean
		¸¸¾à ¸Ş¸ğ¸® °ü¸®ÀÚ°¡ ProudNet¿¡¼­ ¹Ì¸® »ı¼ºÇÑ Àü¿ë HeapÀÌ ¾Æ´Ñ ´Ù¸¥ HeapÀ» »ç¿ëÇÏ°Ô ¸¸µé°íÀÚ ÇÑ´Ù¸é ¿©±â¿¡ CMemoryHeap °´Ã¼ÀÇ Æ÷ÀÎÅÍ¸¦
		³ÖÀ¸¸é µË´Ï´Ù. 
		- ÀÌ ¼³Á¤°ú °ü·ÃµÈ ¸Ş¸ğ¸® ¸Å´ÏÀú°¡ ÆÄ±«½Ã ¿©±â¼­ ÁöÁ¤ÇÑ CMemoryHeap À» ÆÄ±«ÇÏÁö´Â ¾Ê½À´Ï´Ù.
		- NULLÀ» ³ÖÀ¸¸é ProudNet¿¡¼­ ¹Ì¸® »ı¼ºÇÑ Àü¿ë HeapÀ» »ç¿ëÇÕ´Ï´Ù.

		\~english
		If memory manager intends to let other Heap to be used rather than previously created custom Heap from ProudNet then this is where pointer of CMemoryHeap object to be entered.
		- When the memory manager related to this setting is destructed, CMemoryHeap designated in here is not to be destructed.
		- When NULL entered, the Heap previously created by ProudNet is used.
		
		\~chinese
		åıÍı?ğíĞïÎ·×â?ßÌğ¤íÂÜôãÀProudNetŞÀà»ßæà÷îÜ?éÄHeap£¬ì»ãÀĞìöâHeapîÜ?£¬î¤?×ì?ìı CMemoryHeap%?ßÚîÜò¦?¡£
		- ?ó®?öÇßÓ?îÜ?ğíĞïÎ·×â?ù¬÷ò??£¬?Üô?÷ò?î¤?×ìò¦ïÒîÜ CMemoryHeap%¡£
		- Û¯ìıNULLîÜ?ŞÅéÄî¤ProudNetŞÀà»ßæà÷îÜ?éÄHeap¡£

		\~japanese
		ªâª·¡¢«á«â«ê?Î·×âíºª¬ProudNetªÇ?ªËßæà÷ª·ª¿?éÄHeapªÇªÏªÊª¤öâªÎHeapªòŞÅª¦ªèª¦ªËª·ª¿ª¤íŞùêªÏ¡¢ª³ª³ªËCMemoryHeap«ª«Ö«¸«§«¯«ÈªÎ«İ«¤«ó«¿?ªòìıªìªÆª¯ªÀªµª¤¡£
		- ª³ªÎàâïÒªË?Ö§ª·ª¿«á«â«ê?«Ş«Í?«¸«ã?ª¬÷ò?ãÁªËª³ª³ªÇò¦ïÒª·ª¿CMemoryHeapªò÷ò?ª¹ªëª³ªÈªÏª¢ªêªŞª»ªó¡£
		- NULLªòìıªìªìªĞProudNetªÇ?ªËßæà÷ª·ª¿?éÄHeapªòŞÅª¤ªŞª¹¡£
		\~
		*/
		CMemoryHeap* m_pHeap;

		/** 
		\~korean
		½º·¹µù ¸ğµåÀÔ´Ï´Ù.

		\~english
		Threading mode 

		\~chinese
		Threading Ù¼ãÒ¡£

		\~japanese
		«¹«ì«Ã«Ç«£«ó«°«â?«ÉªÇª¹¡£
		\~
		*/
		FastHeapAccessMode m_accessMode;

		/** 
		\~korean
		´Ü ÇÑ°³ÀÇ ½º·¹µå¿¡¼­¸¸ ÀÌ fast heapÀ» »ç¿ëÇÏ´ÂÁö °Ë»çÇÏ´Â Critical section °´Ã¼ÀÔ´Ï´Ù.
		- fast heapÀÌ FastHeapAccessMode_UnsafeSingleThread ÀÎ °æ¿ì¿¡¸¸ À¯È¿ÇÕ´Ï´Ù.
		- fast heapÀÌ FastHeapAccessMode_UnsafeSingleThread ÀÎ °æ¿ì, ÀÌ ¸â¹ö¸¦ »ç¿ëÀÚ°¡ ¼³Á¤ÇØ ÁÖ¾î¾ß ÇÕ´Ï´Ù.
		- ÀÌ ±â´ÉÀº debug mode¿¡¼­¸¸ ÀÛµ¿ÇÕ´Ï´Ù.

		\~english
		This is Critical section object that checks if only 1 thread uses this fast heap.
		- Only valid if the fast heap is FastHeapAccessMode_UnsafeSingleThread
		- If the fast heap is FastHeapAccessMode_UnsafeSingleThread, then this member must be set by user.
		- This function only operates in debug mode. 

		\~chinese
		??ãÀÜúñşî¤ìé??ïïŞÅéÄó®fast heapîÜCritical section?ßÚ¡£
		- ñşî¤fast heapãÀFastHeapAccessMode_UnsafeSingleThreadîÜï×?ù»êóüù¡£
		- fast heap ãÀFastHeapAccessMode_UnsafeSingleThreadîÜï×??£¬éÄ?é©?öÇó®à÷?¡£
		- ó®ÍíÒöñşî¤debug mode??¡£

		\~japanese
		ª¿ªÃª¿ìéªÄªÎ«¹«ì«Ã«ÉªÇªÎªßª³ªÎFast HeapªòŞÅª¦ªÎª«ªò?ŞÛª¹ªëCritical section«ª«Ö«¸«§«¯«ÈªÇª¹¡£
		- fast heapÀÌ FastHeapAccessMode_UnsafeSingleThreadªÇª¢£ò£ùíŞùêªÎªßêó?ªÇª¹¡£
		- fast heapÀÌ FastHeapAccessMode_UnsafeSingleThreadªÇª¢ªëíŞùê¡¢ª³ªÎ«á«ó«Ğ?ªò«æ?«¶?ª¬àâïÒª¹ªëù±é©ª¬ª¢ªêªŞª¹¡£
		- ª³ªÎÑ¦ÒöªÏdebug modeªÇªÎªßíÂÔÑª·ªŞª¹¡£
		\~
		*/
		CriticalSection* m_debugSafetyCheckCritSec;

		CFastHeapSettings();
	};

	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
