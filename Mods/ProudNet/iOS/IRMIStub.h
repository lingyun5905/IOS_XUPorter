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

#include "Enums.h"
#include "FakeClr.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup net_group
	*  @{
	*/

	class CNetCoreImpl;
	class CReceivedMessage;
	class IRmiHost;
	class BeforeRmiSummary;
	class AfterRmiSummary;

	/** 
	\~korean
	PIDL ÄÄÆÄÀÏ·¯°¡ »ı¼ºÇÑ Stub Å¬·¡½ºÀÇ º£ÀÌ½º Å¬·¡½º

	ÁÖÀÇ »çÇ×
	- ÀÌ Å¬·¡½º¸¦ À¯Àú°¡ Á÷Á¢ ±¸ÇöÇÏÁö ¸» °Í. PIDL ÄÄÆÄÀÏ·¯¿¡¼­ ±¸ÇöÇÑ °ÍÀ» ¾²µµ·Ï ÇØ¾ß ÇÑ´Ù.

	\~english
	Base class of Stub class created by PIDL compiler

	Note
	- User must not create this class. Must be realized by PIDL compiler.

	\~chinese
	PIDL??Ğïßæà÷îÜStub?îÜĞñÜâ?¡£

	ñ¼ëòŞÀßÚ
	- éÄ?Üôé©òÁïÈ??ó®?¡£î¤PIDL??Ğïé©ŞÅéÄ??îÜ?à¤¡£

	\~japanese
	PIDL«³«ó«Ñ«¤«é?ª¬ßæà÷ª·ª¿Stub«¯«é«¹ªÎ«Ù?«¹«¯«é«¹

	ª´ñ¼ëòŞÀú£
	- ª³ªÎ«¯«é«¹ªò«æ?«¶?ª¬òÁïÈ?úŞª·ªÊª¤ª³ªÈ¡£PIDL«³«ó«Ñ«¤«é?ªÇ?úŞª·ª¿ªâªÎªòŞÅª¦ªèª¦ªËª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£
	\~
	*/
	class IRmiStub
	{
	public:
		IRmiHost *m_core;
		bool m_internalUse; // trueÀÌ¸é ProudNet Àü¿ë. »ç¿ëÀÚ´Â °ÇµéÁö ¸»°Í

		/** 
		\~korean
		true·Î ¼¼ÆÃÇÏ¸é NotifyCallFromStub À» È£Ãâ¹ŞÀ» ¼ö ÀÖ´Ù.
		±×·¯³ª, ±× ´ñ°¡·Î ½ÇÇà ¼Óµµ°¡ ÇöÀúÈ÷ ¶³¾îÁø´Ù. µğ¹ö±ëÀ» ÇÒ ¶§¸¸ ÄÑ´Â
		°ÍÀ» ±ÇÀåÇÑ´Ù.

		\~english
		If set as true then calls NotifyCallFromStub.
		But in return, process speed will be lowered significantly. It is recommended to use this when debugging.

		\~chinese
		?öÇ?trueîÜ?Ê¦ì¤û¼Ğ£NotifyCallFromStub¡£
		Ó£?ú¼áÜÓø?Ù¥?ù»Ë½¡£Ëï?ñşî¤??îÜ?ı¦öè?¡£

		\~japanese
		trueªËàâïÒª¹ªëªÈNotifyCallFromStubªòû¼ªÓõóª·ªÆªâªéª¦ª³ªÈª¬ªÇª­ªŞª¹¡£
		ª·ª«ª·¡¢ª½ªÎ??ªÇ?ú¼áÜÓøª¬îÊª·ª¯ÕªªÁªŞª¹¡£«Ç«Ğ«Ã«®«ó«°ªòª¹ªëãÁªÎªßªÄª±ªëª³ªÈªòªª?ªáª·ªŞª¹¡£
		\~
		*/
		bool m_enableNotifyCallFromStub;

		/** 
		\~korean
		true·Î ¼³Á¤ÇÏ¸é BeforeRmiInvocation,AfterRmiInvocation ¸¦ Äİ¹éÇÑ´Ù.
		±×·¯³ª ±× ´ñ°¡·Î ½ÇÇà ¼Óµµ°¡ ¾à°£ ¶³¾îÁø´Ù. ¼º´É ÃÖÀûÈ­¸¦ À§ÇØ RMI ÇÔ¼ö Á¾·ùº° ½ÇÇà
		½Ã°£À» Ã¼Å©ÇÒ ¶§¸¸ ÄÑ´Â °ÍÀ» ±ÇÀåÇÑ´Ù.

		\~english
		If set as true then BeforeRmiInvocation and AfterRmiInvocation are called back.
		But in return, process speed will be lowered a little. It is recommended to use this when checking running time of RMI function of each type.

		\~chinese
		?öÇ?trueîÜ?üŞ?BeforeRmiInvocation,AfterRmiInvocation¡£
		Ó£?ú¼áÜÓø?Ù¥?ù»Ë½¡£?ÖõàõÒöîÜ?ûù£¬Ëï?ñşî¤??RMIùŞ????ú¼??îÜ?ı¦öè?¡£

		\~japanese
		trueªËàâïÒª¹ªëªÈ¡¢BeforeRmiInvocation,AfterRmiInvocationªò«³?«ë«Ğ«Ã«¯ª·ªŞª¹¡£
		ª·ª«ª·¡¢ª½ªÎ??ªÇ?ú¼áÜÓøª¬á´ª·ÕªªÁªŞª¹¡£àõÒöªÎõÌîêûùªÎª¿ªáªËRMI??ªÎğú×¾Ü¬?ú¼ãÁÊàªò«Á«§«Ã«¯ª¹ªëãÁªÎªßªÄª±ªëª³ªÈªòªª?ªáª·ªŞª¹¡£
		\~
		*/
		bool m_enableStubProfiling;

		/** 
		\~korean
		ÀÌ ÇÔ¼ö¸¦ ±¸ÇöÇÏÁö ¸» °Í. PIDL ÄÄÆÄÀÏ·¯ÀÇ °á°ú¹°ÀÌ overrideÇÑ´Ù.

		\~english
		DO NOT realize this function. The outcome of PIDL compiler will override.

		\~chinese
		Üôé©??ó®ùŞ?¡£PIDL ??ĞïîÜ?Úª?override¡£

		\~japanese
		ª³ªÎ??ªò?úŞª·ªÊª¤ª³ªÈ¡£PIDL«³«ó«Ñ«¤«é?ªÎÌ¿ÍıÚªª¬«ª?«Ğ?«é«¤«ÉªµªìªŞª¹¡£
		\~
		*/
		virtual RmiID* GetRmiIDList() = 0;
		/** 
		\~korean
		ÀÌ ÇÔ¼ö¸¦ ±¸ÇöÇÏÁö ¸» °Í. PIDL ÄÄÆÄÀÏ·¯ÀÇ °á°ú¹°ÀÌ overrideÇÑ´Ù.

		\~english
		DO NOT realize this function. The outcome of PIDL compiler will override.

		\~chinese
		Üôé©??ó®ùŞ?¡£PIDL ??ĞïîÜ?Úª?override¡£

		\~japanese
		ª³ªÎ??ªò?úŞª·ªÊª¤ª³ªÈ¡£PIDL«³«ó«Ñ«¤«é?ªÎÌ¿ÍıÚªª¬«ª?«Ğ?«é«¤«ÉªµªìªŞª¹¡£
		\~
		*/
		virtual int GetRmiIDListCount() = 0;
		/** 
		\~korean
		ÀÌ ÇÔ¼ö¸¦ ±¸ÇöÇÏÁö ¸» °Í. PIDL ÄÄÆÄÀÏ·¯ÀÇ °á°ú¹°ÀÌ overrideÇÑ´Ù.

		\~english
		DO NOT realize this function. The outcome of PIDL compiler will override.

		\~chinese
		Üôé©??ó®ùŞ?¡£PIDL ??ĞïîÜ?Úª?override¡£

		\~japanese
		ª³ªÎ??ªò?úŞª·ªÊª¤ª³ªÈ¡£PIDL«³«ó«Ñ«¤«é?ªÎÌ¿ÍıÚªª¬«ª?«Ğ?«é«¤«ÉªµªìªŞª¹¡£
		\~
		*/
		virtual bool ProcessReceivedMessage(CReceivedMessage& pa, void* hostTag) = 0;
		/** 
		\~korean
		RMI°¡ ½ÇÇàµÈ Á÷ÈÄ È£ÃâµÈ´Ù.

		\~english
		Called right after RMI is run

		\~chinese
		RMI?ú¼ı¨Ø¡?ù¬û¼Ğ£¡£

		\~japanese
		RMIª¬?ú¼ªµªìª¿ı­ªËû¼ªÓõóªµªìªŞª¹¡£
		\~
		*/
		virtual void AfterRmiInvocation(const AfterRmiSummary& summary);
		/** 
		\~korean
		RMI°¡ ½ÇÇàµÇ±â Á÷Àü¿¡ È£ÃâµÈ´Ù.

		\~english
		Called right after RMI is run

		\~chinese
		RMI?ú¼ñıîñù¬û¼Ğ£¡£

		\~japanese
		RMIª¬?ú¼ªµªìªëîñªËû¼ªÓõóªµªìªŞª¹¡£
		\~
		*/
		virtual void BeforeRmiInvocation(const BeforeRmiSummary& summary);

		/** 
		\~korean
		À¯Àú°¡ ÀÌ ÇÔ¼ö¸¦ overrideÇÏ¸é, RMI°¡ ½ÇÇàµÇ¸é¼­ ¹ŞÀº ÆÄ¶ó¸ŞÅÍ¸¦ ¹®ÀÚ¿­·Î ¸ğµÎ Ç¥½ÃÇÒ ¼ö ÀÖ°Ô ÇØÁØ´Ù.
		´Ü, ¼º´ÉÀÌ ¸Å¿ì ¶³¾îÁö°Ô µÇ¹Ç·Î ÁÖÀÇÇØ¼­ ¾²µµ·Ï ÇÏÀÚ.

		\~english
		If user override this function then it lets parameter received from RMI be displayed as text string.
		But in return, process speed will be lowered significantly so be careful when you use this.

		\~chinese
		éÄ?overrideó®ùŞ?îÜ?£¬Ê¦ì¤÷êRMI?ú¼îÜ?ı¦ïÈâ¥îÜá¶êó???ãÆ?í®İ¬Íú¡£
		Ó£ãÀ£¬àõÒö?ù»Ë½£¬á¶ì¤ŞÅéÄ?é©ñ¼ëò¡£

		\~japanese
		«æ?«¶?ª¬ª³ªÎ??ªò«ª?«Ğ?«é«¤«Éª¹ªìªĞ¡¢RMIª¬?ú¼ªµªìªÊª¬ªéáôª±ª¿«Ñ«é«á?«¿?ªòÙşí®ÖªªÇîïªÆøúãÆªÇª­ªëªèª¦ªËª·ªŞª¹¡£
		Ó£ª·¡¢àõÒöª¬ŞªßÈªËÕªªÁªëªèª¦ªËªÊªëªÎªÇñ¼ëòª·ªÆŞÅªÃªÆª¯ªÀªµª¤¡£
		\~
		*/
		virtual void NotifyCallFromStub(HostID remote, RmiID RMIId, String methodName, String parameters);

		PROUD_API void ShowUnknownHostIDWarning(HostID remoteHostID);

		PROUD_API IRmiStub();
		PROUD_API virtual ~IRmiStub();
	};

	extern const PNTCHAR* DecryptFailedError;

	/**  @} */
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
