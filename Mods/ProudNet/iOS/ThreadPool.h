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

#include "LambdaWrap.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup net_group
	*  @{
	*/

	/**
	\~korean
	CThreadPool ¿¡¼­ ¹ß»ıÇÏ´Â ÀÌº¥Æ® Äİ¹éÀ» ¹Ş¾Æ Ã³¸®ÇÏ´Â ÀÎÅÍÆäÀÌ½º Å¬·¡½ºÀÔ´Ï´Ù.

	ÀÚ¼¼ÇÑ °ÍÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#thread_pool_sharing" >¼­¹ö¿¡¼­ ¿©·¯ È£½ºÆ® ¸ğµâÀÌ °°Àº Thread Pool¸¦ °øÀ¯ÇÏ±â</a> À» Âü°íÇÏ½Ê½Ã¿À.

	»ç¿ë¹ı
	- °´Ã¼¸¦ »ó¼Ó¹Ş¾Æ ¸Ş¼­µå¸¦ ±¸ÇöÇÕ´Ï´Ù.
	- CThreadPool ¿¡ ÀÌ °´Ã¼¸¦ ÆÄ¶ó¸ŞÅÍ·Î Àü´ŞÇÕ´Ï´Ù.

	\~english
	This is interface class that hand event callback occured from CThreadPool.

	Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#thread_pool_sharing" >Share Thread Pool that has same host module in a server.</a> for more detail.

	Usage
	- Realize this method to inherit object.
	- Pass this object to parameter at CThreadPool

	\~chinese
	ïÈâ¥??×â? CThreadPool%?ßæîÜeventüŞ?îÜÍ£Øü?¡£

	??îÜ??ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#thread_pool_sharing" >î¤Ü×?ĞïñéÍìú½??ñ«ÏõÙ¼?ßÓÔÒîÜThread Pool</a>%¡£

	ŞÅéÄÛ°Ûö
	- ?ã¯?ßÚì¤ı¨??ó®Û°Ûö¡£
	- ÷êó®?ßÚ????áê? CThreadPool%¡£

	\~japanese
	CthreadPoolªÇ?ßæª¹ªë«¤«Ù«ó«È«³?«ë«Ğ«Ã«¯ªòáôª±ªÆ?×âª¹ªë«¤«ó«¿?«Õ«§?«¹«¯«é«¹ªÇª¹¡£

	ßÙª·ª¯ªÏ¡¢\ref thread_pool_sharingªòª´?ğÎª¯ªÀªµª¤¡£

	ŞÅéÄÛ°Ûö
	- «ª«Ö«¸«§«¯«ÈªòßÓ?ª·ªÆªâªéª¤«á«½«Ã«Éªò?úŞª·ªŞª¹¡£
	- CThreadPoolªØª³ªÎ«ª«Ö«¸«§«¯«Èªò«Ñ«é«á?«¿?ªÇ?Ó¹ª·ªŞª¹¡£
	\~
	*/
	class IThreadPoolEvent
	{
	public:
		/**
		\~korean
		thread poolÀÇ ½º·¹µå°¡ ½ÃÀÛÇÒ ¶§ ÀÌ ¸Ş¼­µå°¡ È£ÃâµË´Ï´Ù.

		\~english
		When thread pool started thread, call this method.

		\~chinese
		thread pool ?ïï?ã·îÜ?ı¦û¼Ğ£ó®Û°Ûö¡£

		\~japanese
		thread poolªÎ«¹«ì«Ã«Éª¬ËÒã·ª¹ªëãÁ¡¢ª³ªÎ«á«½«Ã«Éª¬û¼ªÓõóªµªìªŞª¹¡£
		\~
		*/
		virtual void OnThreadBegin() = 0;

		/**
		\~korean
		thread poolÀÇ ½º·¹µå°¡ Á¾·áÇÒ ¶§ ÀÌ ¸Ş¼­µå°¡ È£ÃâµË´Ï´Ù.

		\~english
		When thread pool is terminated, call this method.

		\~chinese
		thread pool ?ïï?áÖîÜ?ı¦û¼Ğ£ó®Û°Ûö¡£

		\~japanese
		thread poolªÎ«¹«ì«Ã«Éª¬ğûÖõª¹ªëãÁ¡¢ª³ªÎ«á«½«Ã«Éª¬û¼ªÓõóªµªìªŞª¹¡£
		\~
		*/
		virtual void OnThreadEnd() = 0;
	};

#ifdef SUPPORTS_CPP11

	// C++11À» »ç¿ëÇÏ½Ç ¼ö ÀÖÀ¸¸é, ÀÌ°ÍÀ» ¾²½Ã´Â °Íµµ Æí¸®ÇÒ °ÍÀÔ´Ï´Ù.
	class CThreadPoolEventFunctional:public IThreadPoolEvent
	{
	public:
		std::function<void()> OnThreadBeginFunction;
		std::function<void()> OnThreadEndFunction;
	
	private:
		void OnThreadBegin() 
		{
			if (OnThreadBeginFunction)
				OnThreadBeginFunction();
		}

		void OnThreadEnd() 
		{
			if (OnThreadEndFunction)
				OnThreadEndFunction();
		}

	};

#endif

	/**
	\~korean
	¼­¹ö»çÀÌµå È£½ºÆ® ¸ğµâ(CNetServer,CLanServer,CLanClient)À» À§ÇÑ thread pool °´Ã¼ÀÔ´Ï´Ù.

	ÀÚ¼¼ÇÑ °ÍÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#thread_pool_sharing" >¼­¹ö¿¡¼­ ¿©·¯ È£½ºÆ® ¸ğµâÀÌ °°Àº Thread Pool¸¦ °øÀ¯ÇÏ±â</a> À» Âü°íÇÏ½Ê½Ã¿À.

	\~english
	This is thread pool object for server-sided host module(CNetServer,CLanServer,CLanClient)

	Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#thread_pool_sharing" >Share Thread Pool that has same host module in a server.</a> for more detail.

	\~chinese
	?Öõserver-sided ñ«ÏõÙ¼úş£¨CNetServer,CLanServer,CLanClient£©îÜthread pool?ßÚ¡£

	????ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#thread_pool_sharing" >î¤Ü×?ĞïñéÍìú½??ñ«ÏõÙ¼?ßÓÔÒîÜThread Pool</a>%¡£

	\~japanese
	«µ?«Ğ?«µ«¤«ÉªÎ«Û«¹«È«â«¸«å?«ë(CNetServer,CLanServer,CLanClient)ªÎª¿ªáªÎthread pool«ª«Ö«¸«§«¯«ÈªÇª¹¡£
	
	ßÙª·ª¯ªÏ¡¢\ref thread_pool_sharingªòª´?ğÎª¯ªÀªµª¤¡£
	\~

	»ç¿ë¹ı
	- tp = CThreadPool.Create();
	- tp.SetEventSink(...); // (optinal)
	- tp.SetThreadCount(n); // n = 0~512
	- NC,NS,LC,LS¿¡¼­ tp¸¦ º¯¼ö·Î ÂüÁ¶
	- delete tp;

	TODO: »ó±â ÁÖ¼® ´ÙµëÀº ÈÄ ´Ù±¹¾îÈ­ÇØ¾ß!

	*/
	class CThreadPool
	{
	public:
		virtual ~CThreadPool();

		// ¿øÇÏ´Â ¼öÀÇ ½º·¹µå·Î °¹¼ö¸¦ Á¶ÀıÇÑ´Ù.
		// 0~512±îÁö °¡´É.
		// ÀÌ ÇÔ¼ö´Â Áï½Ã ¸®ÅÏµÇ°í, ½Ã°£ÀÌ Áö³ª¸é¼­ ¸ñÇ¥Ä¡·Î °¡°Ô µÈ´Ù.
		// 0ÀÌ µÉ °æ¿ì »ç¿ëÀÚ´Â CThreadPool.Process¸¦ ¸Å¹ø È£ÃâÇØ ÁÖ¾î¾ß ÇÑ´Ù.
		virtual void SetDesiredThreadCount(int threadCount) = 0;

		/**
		\~korean
		³×Æ®¿öÅ· ¼­¹ö°£ Åë½Å¿ë ThreadPoolÀ» »ı¼ºÇÕ´Ï´Ù.

		\~english
		Creates ThreadPool for server communications

		\~chinese
		ßæà÷??Ü×?Ğïñı?÷×ãáéÄîÜThreadPool¡£

		\~japanese
		«µ?«Ğ?Êà÷×ãáéÄThreadPoolªòßæà÷ª·ªŞª¹¡£
		\~
		*/
		static CThreadPool *Create(IThreadPoolEvent* eventSink, int threadCount);

		// zero thread poolÀ» À§ÇÑ, heartbeat Ã³¸®¸¦ ÇÑ´Ù.
		// zero thread poolÀÎ °æ¿ì Áö¼ÓÀûÀ¸·Î È£ÃâÇØ¾ß ÇÑ´Ù.
		// ÀÎÀÚ: ÃÖ´ë ´ë±â ½Ã°£. 0À» ³ÖÀ¸¸é ¹«´ë±â ½ÇÇà.
		// TODO: À§ ÁÖ¼®À» Á¤Á¦ÇÏ¿© »ç¿ëÀÚ°¡ ÁÁ¾ÆÇÏ°Ô ÇÏ°í, zero thread pool¿¡ ´ëÇÑ ÇÇÃ³µµ advanced usage Ç×¸ñ¿¡ Ãß°¡ÇÏµµ·Ï ÇÏÀÚ.
		virtual void Process(int timeoutMs) = 0;
	
	};

	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
