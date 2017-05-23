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

//#if defined(_WIN32)
    #include <deque>
    #include "FastArrayPtr.h"
//#endif

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
//#if defined(_WIN32)
	/** \addtogroup util_group
	*  @{
	*/
	template<typename T>
	class Deque: public std::deque<T>
	{
        typedef typename std::deque<T> DeqType;
        
	public:
		/**
		\~korean 
		\return DataÀÇ ¼ö¸¦ ¸®ÅÏÇÕ´Ï´Ù.

		\~english 
		\return the number of data.

		\~chinese
		\return Ú÷üŞdataîÜ?¡£

		\~japanese
		\return DataªÎ?ªò«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		int GetCount()
		{
			return (int)DeqType::size();
		}
#if defined (_MSC_VER)
		__declspec(property(get = GetCount)) int Count;
#endif

        inline bool IsEmpty() const { return DeqType::empty(); }

		/**
		\~korean 
		Å¥¿¡ Data¸¦ Ãß°¡ÇÕ´Ï´Ù.
		\param data Ãß°¡ÇÒ DataÀÔ´Ï´Ù.

		\~english TODO:translate needed.		
		\param data Data to be added 

		\~chinese
		?Öª×ìôÕÊ¥Data¡£
		\param data é©ôÕÊ¥îÜData¡£

		\~japanese
		«­«å?ªË«Ç?«¿ªòõÚÊ¥ª·ªŞª¹¡£
		\param data õÚÊ¥ª¹ªë«Ç?«¿ªÇª¹¡£
		\~
		*/
		void PushBack(const T& data)
		{
			this->push_back(data);
		}

		/**
		\~korean 
		°¡Àå ¾Õ¿¡ ÀÖ´Â Data¸¦ º¹»ç¹Ş½À´Ï´Ù.
		\param [out] ret º¹»ç¹ŞÀ» referenceÀÔ´Ï´Ù.

		\~english TODO:translate needed.
		Get the very front data copied. 
		\param [out] ret This is a reference to be copied

		\~chinese
		?ğ¤õÌîñØüîÜdata¡£
		\param [out] ret ÔğÓğ?ğ¤îÜreference¡£

		\~japanese
		ìéÛãîñªËª¢ªë«Ç?«¿ªò«³«Ô?ª·ªÆªâªéª¤ªŞª¹¡£
		\param [out] ret «³«Ô?ª·ªÆªâªéª¦referenceªÇª¹¡£
		\~
		*/
		void PeekFront(T& ret)
		{
			ret = DeqType::front();
		}

		/**
		\~korean 
		\return °¡Àå ¾ÕÀÇ µ¥ÀÌÅÍ

		\~english 
		\return The first data.

		\~chinese
		\return õÌîñØüîÜ?Ëß¡£

		\~japanese
		\return ìéÛãîñªÎ«Ç?«¿
		\~
		*/
		T PeekFront()
		{
			return DeqType::front();
		}

		/**
		\~korean 
		°¡Àå ¾ÕÀÇ µ¥ÀÌÅÍ¸¦ Å¥¿¡¼­ Á¦°ÅÇÏ°í ¸®ÅÏ¹Ş½À´Ï´Ù.
		\return °¡Àå ¾Õ¿¡ ÀÖ¾ú´ø µ¥ÀÌÅÍ

		\~english 
		Removes the very front data from the queue and get it returned. 
		\return The very front data.

		\~chinese
		??Öª×ì?ğ¶õÌîñØüîÜ?Ëßı¨Ú÷üŞ¡£
		\return î¤õÌîñØüîÜ?Ëß¡£

		\~japanese
		ìéÛãîñªÎ«Ç?«¿ªò«­«å?ªèªêğ¶ËÛª·ªÆ«ê«¿?«óª·ªÆªâªéª¤ªŞª¹¡£
		\return ìéÛãîñªËª¢ªÃª¿«Ç?«¿
		\~
		*/
		T PopFront()
		{
			T ret = DeqType::front();
            DeqType::pop_front();
			return ret;
		}

		/**
		\~korean
		°¡Àå ¾ÕÀÇ µ¥ÀÌÅÍ¸¦ Å¥¿¡¼­ Á¦°ÅÇÏ°í reference·Î ¹Ş½À´Ï´Ù.
		\param [out] ret Data¸¦ ¹ŞÀ» reference

		\~english 
		Deletes the very first data from the queue and get it as reference. 
		\param [out] ret             Reference to receive data

		\~chinese
		??Öª×ì?ğ¶õÌîñØüîÜ?Ëßı¨£¬ïÈâ¥reference¡£
		\param [out] ret           ïÈâ¥DataîÜreference¡£

		\~japanese
		ìéÛãîñªÎ«Ç?«¿ªò«­«å?ªèªêğ¶ËÛª·ªÆreferenceªÈª·ªÆªâªéª¤ªŞª¹¡£
		\param [out] ret           Dataªòáôª±ªëreference
		\~
		*/
		void PopFront(T& ret)
		{
			ret = DeqType::front();
            DeqType::pop_front();
		}

		/**
		\~korean
		¸ğµç µ¥ÀÌÅÍ Á¤º¸¸¦ Á¦°ÅÇÕ´Ï´Ù.

		\~english 
		Deletes all data information.

		\~chinese
		?ğ¶á¶êó?ËßãáãÓ¡£

		\~japanese
		îïªÆªÎ«Ç?«¿ï×ÜÃªòğ¶ËÛª·ªŞª¹¡£
		\~
		*/
		void Clear()
		{
            DeqType::clear();
		}

		// ÀÌ ¸Ş¼­µå´Â deque.iterator ÀÚÃ¼°¡ ´À¸®±â ¶§¹®¿¡ ºñÈ¿À²ÀûÀÌ´Ù.
		// 		void CloneToArray(CFastArray<T> &dest)
		// 		{
		// 			dest.SetCount(size());
		// 			int c=0;
		// 			for(iterator i=begin();i!=end();i++)
		// 			{
		// 				dest[c++]=*i;
		// 			}
		// 		}
	};

	/**  @} */
//#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
