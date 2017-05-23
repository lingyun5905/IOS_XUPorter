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

#include "PNString.h"
#if !defined(_WIN32)
    #include "BasicTypes.h"
#endif

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

#ifdef _WIN32
// À©µµ ¹öÀüÀÌ¶óµµ #include <oledb.h>¸¦ includeÇÒ ¼ö ¾ø´Â È¯°æ ¶§¹®¿¡ Àü¹æ ¼±¾ğ¸¸ ÇÑ´Ù.
struct tagDBTIMESTAMP;
typedef tagDBTIMESTAMP DBTIMESTAMP;
#endif // _WIN32

namespace Proud 
{
#if defined(_WIN32)

	/** \addtogroup util_group
	*  @{
	*/

	/** 
	\~korean
	µÎ ³¯Â¥½Ã°£ÀÇ ½Ã°£Â÷   

	\~english
	Time difference between two different dates

	\~chinese
	??ìíÑ¢??îÜ??ó¬¡£

	\~japanese
	?ìíÜõãÁÊàªÎãÁÊàó¬
	\~
	*/
	class PROUD_API CPnTimeSpan
	{
		// Constructors
	public:
		/** 
		\~korean
		»ı¼ºÀÚ  

		\~english
		Constructor

		\~chinese
		ßæà÷íº¡£

		\~japanese
		ßæà÷í­
		\~
		*/
		CPnTimeSpan() throw();

		/** 
		\~korean
		»ı¼ºÀÚ  

		\~english
		Constructor

		\~chinese
		ßæà÷íº¡£

		\~japanese
		ßæà÷í­
		\~
		*/
		CPnTimeSpan(double dblSpanSrc) throw();
		/** 
		\~korean
		»ı¼ºÀÚ  

		\~english
		Constructor

		\~chinese
		ßæà÷íº¡£

		\~japanese
		ßæà÷í­
		\~
		*/
		CPnTimeSpan(int32_t lDays, int nHours, int nMins, int nSecs, int nMillisecs) throw();

		// Attributes
		enum DateTimeSpanStatus
		{
			valid = 0,
			invalid = 1,    // Invalid span (out of range, etc.)
			null = 2,       // Literally has no value
		};

		double m_span;
		DateTimeSpanStatus m_status;

		void SetStatus(DateTimeSpanStatus status) throw();
		DateTimeSpanStatus GetStatus() const throw();

		/** 
		\~korean
		ÀÏ,½Ã,ºĞ,ÃÊ,¹Ğ¸®ÃÊ·Î ÃÑ°è È¯»êÇÑ´Ù.  

		\~english
		Converts into day,hour,minute,second,millisecond format. 

		\~chinese
		éÄìí¡¢?¡¢İÂ¡¢õ©¡¢ûÆõ© ???ß©¡£

		\~japanese
		ìí¡¢ãÁ¡¢İÂ¡¢õ©¡¢«ß«êõ©ªÇ?Íªüµß©ª·ªŞª¹¡£
		\~
		*/
		double GetTotalDays() const throw();    // span in days (about -3.65e6 to 3.65e6)

		/** 
		\~korean
		ÀÏ,½Ã,ºĞ,ÃÊ,¹Ğ¸®ÃÊ·Î ÃÑ°è È¯»êÇÑ´Ù.  

		\~english
		Converts into day,hour,minute,second,millisecond format. 

		\~chinese
		éÄìí¡¢?¡¢İÂ¡¢õ©¡¢ûÆõ© ???ß©¡£

		\~japanese
		ìí¡¢ãÁ¡¢İÂ¡¢õ©¡¢«ß«êõ©ªÇ?Íªüµß©ª·ªŞª¹¡£
		\~		*/
		double GetTotalHours() const throw();   // span in hours (about -8.77e7 to 8.77e6)

		/** 
		\~korean
		ÀÏ,½Ã,ºĞ,ÃÊ,¹Ğ¸®ÃÊ·Î ÃÑ°è È¯»êÇÑ´Ù.  

		\~english
		Converts into day,hour,minute,second,millisecond format.

		\~chinese
		éÄìí¡¢?¡¢İÂ¡¢õ©¡¢ûÆõ© ???ß©¡£

		\~japanese
		ìí¡¢ãÁ¡¢İÂ¡¢õ©¡¢«ß«êõ©ªÇ?Íªüµß©ª·ªŞª¹¡£
		\~
		*/
		double GetTotalMinutes() const throw(); // span in minutes (about -5.26e9 to 5.26e9)

		/** 
		\~korean
		ÀÏ,½Ã,ºĞ,ÃÊ,¹Ğ¸®ÃÊ·Î ÃÑ°è È¯»êÇÑ´Ù.  

		\~english
		Converts into day,hour,minute,second,millisecond format. 

		\~chinese
		éÄìí¡¢?¡¢İÂ¡¢õ©¡¢ûÆõ© ???ß©¡£

		\~japanese
		ìí¡¢ãÁ¡¢İÂ¡¢õ©¡¢«ß«êõ©ªÇ?Íªüµß©ª·ªŞª¹¡£
		\~
		*/
		double GetTotalSeconds() const throw(); // span in seconds (about -3.16e11 to 3.16e11)

		/** 
		\~korean
		ÀÏ,½Ã,ºĞ,ÃÊ,¹Ğ¸®ÃÊ·Î ÃÑ°è È¯»êÇÑ´Ù.  

		\~english
		Converts into day,hour,minute,second,millisecond format. 

		\~chinese
		éÄìí¡¢?¡¢İÂ¡¢õ©¡¢ûÆõ© ???ß©¡£

		\~japanese
		ìí¡¢ãÁ¡¢İÂ¡¢õ©¡¢«ß«êõ©ªÇ?Íªüµß©ª·ªŞª¹¡£
		\~
		*/
		double GetTotalMilliseconds() const throw();	// span in milliseconds

		/** 
		\~korean
		ÀÏ,½Ã,ºĞ,ÃÊ¸¦ ¾ò´Â´Ù.  

		\~english
		Gets day,hour,minute,second.

		\~chinese
		?Ôğìí¡¢?¡¢İÂ¡¢õ©¡£

		\~japanese
		ìí¡¢ãÁ¡¢İÂ¡¢õ©ªòÔğªŞª¹¡£
		\~
		*/
		int32_t GetDays() const throw();       // component days in span

		/** 
		\~korean
		ÀÏ,½Ã,ºĞ,ÃÊ¸¦ ¾ò´Â´Ù.  

		\~english
		Gets day,hour,minute,second.

		\~chinese
		?Ôğìí¡¢?¡¢İÂ¡¢õ©¡£

		\~japanese
		ìí¡¢ãÁ¡¢İÂ¡¢õ©ªòÔğªŞª¹¡£
		\~
		*/
		int32_t GetHours() const throw();      // component hours in span (-23 to 23)

		/** 
		\~korean
		ÀÏ,½Ã,ºĞ,ÃÊ¸¦ ¾ò´Â´Ù.  

		\~english
		Gets day,hour,minute,second.

		\~chinese
		?Ôğìí¡¢?¡¢İÂ¡¢õ©¡£

		\~japanese
		ìí¡¢ãÁ¡¢İÂ¡¢õ©ªòÔğªŞª¹¡£
		\~
		*/
		int32_t GetMinutes() const throw();    // component minutes in span (-59 to 59)

		/** 
		\~korean
		ÀÏ,½Ã,ºĞ,ÃÊ¸¦ ¾ò´Â´Ù.  

		\~english
		Gets day,hour,minute,second.

		\~chinese
		?Ôğìí¡¢?¡¢İÂ¡¢õ©¡£

		\~japanese
		ìí¡¢ãÁ¡¢İÂ¡¢õ©ªòÔğªŞª¹¡£
		\~
		*/
		int32_t GetSeconds() const throw();    // component seconds in span (-59 to 59)

		int GetMilliseconds() const throw();

		/** 
		\~korean
		º¹»ç ´ëÀÔ ¿¬»êÀÚ  

		\~english
		Copy assignment operator

		\~chinese
		?ğ¤???ß©İ¬¡£

		\~japanese
		«³«Ô?ÓÛìıæÑß©í­
		\~
		*/
		CPnTimeSpan& operator=(double dblSpanSrc) throw();

		/** 
		\~korean
		ºñ±³ ¿¬»êÀÚ  

		\~english
		Comparison operator

		\~chinese
		İï??ß©İ¬¡£

		\~japanese
		İïÎòæÑß©í­
		\~
		*/
		bool operator==(const CPnTimeSpan& dateSpan) const throw();
		/** 
		\~korean
		ºñ±³ ¿¬»êÀÚ  

		\~english
		Comparison operator

		\~chinese
		İï??ß©İ¬¡£

		\~japanese
		İïÎòæÑß©í­
		\~
		*/
		bool operator!=(const CPnTimeSpan& dateSpan) const throw();
		/** 
		\~korean
		ºñ±³ ¿¬»êÀÚ  

		\~english
		Comparison operator

		\~chinese
		İï??ß©İ¬¡£

		\~japanese
		İïÎòæÑß©í­
		\~
		*/
		bool operator<(const CPnTimeSpan& dateSpan) const throw();

		/** 
		\~korean
		ºñ±³ ¿¬»êÀÚ  

		\~english
		Comparison operator

		\~chinese
		İï??ß©İ¬¡£

		\~japanese
		İïÎòæÑß©í­
		\~
		*/
		bool operator>(const CPnTimeSpan& dateSpan) const throw();

		/** 
		\~korean
		ºñ±³ ¿¬»êÀÚ  

		\~english
		Comparison operator

		\~chinese
		İï??ß©İ¬¡£

		\~japanese
		İïÎòæÑß©í­
		\~
		*/
		bool operator<=(const CPnTimeSpan& dateSpan) const throw();

		/** 
		\~korean
		ºñ±³ ¿¬»êÀÚ  

		\~english
		Comparison operator

		\~chinese
		İï??ß©İ¬¡£

		\~japanese
		İïÎòæÑß©í­
		\~
		*/
		bool operator>=(const CPnTimeSpan& dateSpan) const throw();

		/** 
		\~korean
		³¯Â¥ »çÄ¢¿¬»êÀÚ  

		\~english
		Four-fundamental operator for date

		\~chinese
		ìíÑ¢ŞÌ??ß©İ¬¡£

		\~japanese
		\~
		*/
		CPnTimeSpan operator+(const CPnTimeSpan& dateSpan) const throw();

		/** 
		\~korean
		³¯Â¥ »çÄ¢¿¬»êÀÚ  

		\~english
		Four-fundamental operator for date

		\~chinese
		ìíÑ¢ŞÌ??ß©İ¬¡£

		\~japanese
		ìíÜõŞÌöÎæÑß©í­
		\~
		*/
		CPnTimeSpan operator-(const CPnTimeSpan& dateSpan) const throw();

		/** 
		\~korean
		³¯Â¥ »çÄ¢¿¬»êÀÚ  

		\~english
		Four-fundamental operator for date

		\~chinese
		ìíÑ¢ŞÌ??ß©İ¬¡£

		\~japanese
		ìíÜõŞÌöÎæÑß©í­
		\~
		*/
		CPnTimeSpan& operator+=(const CPnTimeSpan dateSpan) throw();

		/** 
		\~korean
		³¯Â¥ »çÄ¢¿¬»êÀÚ  

		\~english
		Four-fundamental operator for date

		\~chinese
		ìíÑ¢ŞÌ??ß©İ¬¡£

		\~japanese
		ìíÜõŞÌöÎæÑß©í­
		\~
		*/
		CPnTimeSpan& operator-=(const CPnTimeSpan dateSpan) throw();

		/** 
		\~korean
		³¯Â¥ »çÄ¢¿¬»êÀÚ  

		\~english
		Four-fundamental operator for date

		\~chinese
		ìíÑ¢ŞÌ??ß©İ¬¡£

		\~japanese
		ìíÜõŞÌöÎæÑß©í­
		\~
		*/
		CPnTimeSpan operator-() const throw();

//		operator double() const throw();

		/** 
		\~korean
		³¯Â¥½Ã°£ ¼³Á¤  

		\~english
		Setting date and time

		\~chinese
		?öÇìíÑ¢??¡£

		\~japanese
		ìíÜõãÁÊààâïÒ
		\~
		*/
		void SetDateTimeSpan(int32_t lDays, int nHours, int nMins, int nSecs, int nMillisecs) throw();

		/** 
		\~korean
		³¯Â¥½Ã°£À» ¹®ÀÚ¿­·Î ¸¸µç´Ù.  

		\~english
		Converts date and time into text string

		\~chinese
		÷êìíÑ¢????à÷í®İ¬Íú¡£

		\~japanese
		ìíÜõãÁÊàªòÙşí®ÖªªÇíÂªêªŞª¹¡£
		\~
		*/
		String Format(const PNTCHAR *pFormat) const;

		/** 
		\~korean
		³¯Â¥½Ã°£À» ¹®ÀÚ¿­·Î ¸¸µç´Ù.  

		\~english
		Converts date and time into text string

		\~chinese
		÷êìíÑ¢????à÷í®İ¬Íú¡£

		\~japanese
		ìíÜõãÁÊàªòÙşí®ÖªªÇíÂªêªŞª¹¡£
		\~
		*/
		String Format(uint32_t nID) const;

		// Implementation
		void CheckRange();

	private:
		static const double OLE_DATETIME_HALFSECOND;
	};

	/** 
	\~korean
	³¯Â¥½Ã°£ µ¥ÀÌÅÍ Å¸ÀÔ

	\~english
	Date and time data type  

	\~chinese
	ìíÑ¢???Ëß?úş¡£

	\~japanese
	ìíÜõãÁÊà«Ç?«¿«¿«¤«×
	\~
	*/
	class PROUD_API CPnTime  // CTimeÀÌ³ª CDateTime, CPnTimeÀº ATL µî°ú ÀÌ¸§ÀÌ È¥µ¿µÉ ¼ö ÀÖÀ¸¹Ç·Î
	{
		// Constructors
	public:
		static CPnTime GetCurrentTime() throw();

		/** 
		\~korean
		»ı¼ºÀÚ  

		\~english
		Constructor

		\~chinese
		ßæà÷íº¡£

		\~japanese
		ßæà÷í­
		\~
		*/
		CPnTime() throw();

		/** 
		\~korean
		»ı¼ºÀÚ  

		\~english
		Constructor

		\~chinese
		ßæà÷íº¡£

		\~japanese
		ßæà÷í­
		\~
		*/
		CPnTime(const VARIANT& varSrc) throw();
		//CPnTime(DATE dtSrc) throw();

		/*
		\~korean
		»ı¼ºÀÚ

		\~english
		Constructor

		\~chinese
		ßæà÷íº¡£

		\~japanese
		ßæà÷í­
		\~
		*/
		// 		CPnTime(__time32_t timeSrc) throw();

		/**
		\~korean
		»ı¼ºÀÚ

		\~english
		Constructor

		\~chinese
		ßæà÷íº¡£

		\~japanese
		ßæà÷í­
		\~
		*/
		//CPnTime(__time64_t timeSrc) throw();

		/** 
		\~korean
		»ı¼ºÀÚ 

		\~english
		Constructor

		\~chinese
		ßæà÷íº¡£

		\~japanese
		ßæà÷í­
		\~
		*/
		CPnTime(const SYSTEMTIME& systimeSrc) throw();

		/** 
		\~korea
		»ı¼ºÀÚ  

		\~english
		Constructor

		\~chinese
		ßæà÷íº¡£

		\~japanese
		ßæà÷í­
		\~
		*/
		CPnTime(const FILETIME& filetimeSrc) throw();

		/** 
		\~korean
		»ı¼ºÀÚ  

		\~english
		Constructor

		\~chinese
		ßæà÷íº¡£

		\~japanese
		ßæà÷í­
		\~
		*/
		CPnTime(int nYear, int nMonth, int nDay,
			int nHour, int nMin, int nSec, int nMillisec) throw();

		/** 
		\~korean
		»ı¼ºÀÚ  

		\~english
		Constructor

		\~chinese
		ßæà÷íº¡£

		\~japanese
		ßæà÷í­
		\~
		*/
		CPnTime(uint16_t wDosDate, uint16_t wDosTime) throw();

		/** 
		\~korean
		DATE Å¸ÀÔÀ¸·ÎºÎÅÍ ÀÌ °´Ã¼¸¦ »ı¼º   

		\~english
		Creates this object from date type

		\~chinese
		?DATE?úşßæà÷ó®?ßÚ¡£

		\~japanese
		DATE«¿«¤«×ª«ªéª³ªÎ«ª«Ö«¸«§«¯«Èªòßæà÷
		\~
		*/
		static CPnTime FromDATE(DATE dtSrc);

#ifdef _WIN32
		CPnTime( const DBTIMESTAMP& dbts) throw();
		bool GetAsDBTIMESTAMP( DBTIMESTAMP& dbts ) const throw();
#endif // _WIN32

		/** 
		\~korean
		³¯Â¥½Ã°£ÀÇ À¯È¿ »óÅÂ 

		\~english
		Valid state of date and time

		\~chinese
		ìíÑ¢??îÜêóüù??¡£

		\~japanese
		ìíÜõãÁÊàªÎêó??÷¾
		\~
		*/
		enum DateTimeStatus
		{
			/** 
			\~korean
			¿¡·¯ 

			\~english
			Error

			\~chinese
			??¡£

			\~japanese
			«¨«é?
			\~
			*/
			error = -1,

			/** 
			\~korean
			À¯È¿ 

			\~english
			Valid

			\~chinese
			êóüù¡£

			\~japanese
			êó?
			\~
			*/
			valid = 0,

			/** 
			\~korean
			Àß¸øµÈ ³¯Â¥ (¹üÀ§ ÃÊ°ú µî)

			\~english
			Invalid date (out of range, etc.)

			\~chinese
			??îÜìíÑ¢£¨õ±õóÛõ?Ôõ£©

			\~japanese
			ÊàêŞªÃª¿ìíÜõ£¨Ûô?õ±Î¦ªÊªÉ£©

			\~

			*/
			invalid = 1,

			/** 
			\~korean
			¸» ±×´ë·Î °ªÀÌ ¾øÀ½.

			\~english
			Literally has no value

			\~chinese
			Üôğíî¤?

			\~japanese
			åëç¨÷×ªêªËö·ª¬ªÊª¤

			\~

			*/
			null = 2
		};
		
		DATE m_dt;
		DateTimeStatus m_status;

		void SetStatus(DateTimeStatus status) throw();
		DateTimeStatus GetStatus() const throw();

		bool GetAsSystemTime(SYSTEMTIME& sysTime) const throw();
		bool GetAsUDATE( UDATE& udate ) const throw();

		/** 
		\~korean
		¿¬µµ¸¦ ¾ò´Â´Ù.

		\~english
		Gets year

		\~chinese
		?ÔğÒ´Óø¡£

		\~japanese
		Ò´ÓøªòÔğªë
		\~
		*/
		int GetYear() const throw();

		/** 
		\~korean
		¿ù °ªÀ» ¾ò´Â´Ù.

		\~english
		Gets month value

		\~chinese
		?ÔğêÅ?¡£

		\~japanese
		êÅö·ªòÔğªë
		\~
		*/
		int GetMonth() const throw();

		/** 
		\~korean
		ÀÏ °ªÀ» ¾ò´Â´Ù.

		\~english
		Gets day value

		\~chinese
		?Ôğìí?¡£

		\~japanese
		ìíö·ªòÔğªë
		\~
		*/
		int GetDay() const throw();

		/** 
		\~korean
		½Ã °ªÀ» ¾ò´Â´Ù.

		\~english
		Gets hour value

		\~chinese
		?Ôğ??¡£

		\~japanese
		ãÁö·ªòÔğªë
		\~
		*/
		int GetHour() const throw();

		/** 
		\~korean
		ºĞ °ªÀ» ¾ò´Â´Ù.

		\~english
		Gets minute value

		\~chinese
		?ÔğİÂ?¡£

		\~japanese
		İÂö·ªòÔğªë
		\~
		*/
		int GetMinute() const throw();

		/** 
		\~korean
		ÃÊ °ªÀ» ¾ò´Â´Ù.

		\~english
		Gets second value

		\~chinese
		?Ôğõ©?¡£

		\~japanese
		õ©ö·ªòÔğªë
		\~
		*/
		int GetSecond() const throw();

		/** 
		\~korean
		 ¹Ğ¸®ÃÊ °ªÀ» ¾ò´Â´Ù.

		\~english
		Gets millisecond value

		\~chinese
		?ÔğûÆõ©?¡£

		\~japanese
		«ß«êõ©ö·ªòÔğªë
		\~
		*/
		int GetMillisecond() const throw();

		/** 
		\~korean
		¿äÀÏ °ªÀ» ¾ò´Â´Ù. (1: ÀÏ¿äÀÏ, 2: ¿ù¿äÀÏ...)

		\~english
		Gets day of the week value (1: Sunday, 2: Monday...) 

		\~chinese
		?ÔğàøÑ¢?¡££¨1£ºàøÑ¢ìí¡¢2£ºàøÑ¢ìé¡£¡£¡££©

		\~japanese
		èøìíö·ªòÔğªë£¨1£ºìíèøìí¡¢2£ºêÅèøìí¡¦£©
		\~
		*/
		int GetDayOfWeek() const throw();

		/** 
		\~korean
		1³âÁß ¸î¹øÂ° ³¯ÀÎÁö¸¦ ¾ò´Â´Ù. (1: 1¿ù 1ÀÏ)

		\~english
		Gets which day in a year (1: 1st January) 

		\~chinese
		?ÔğãÀìéÒ´ñéîÜ?ìéô¸¡££¨1£ºìéêÅìéìí£©

		\~japanese
		1Ò´ñéù¼ÛãÙÍªÎìíªÊªÎª«ªòÔğªë£¨1£º1êÅ1ìí£©
		\~
		*/
		int GetDayOfYear() const throw();

		/** 
		\~korean
		º¹»ç ´ëÀÔ ¿¬»êÀÚ  

		\~english
		Copy assignment operator

		\~chinese
		?ğ¤???ß©İ¬¡£

		\~japanese
		«³«Ô?ÓÛìıæÑß©í­
		\~
		*/
		CPnTime& operator=(const VARIANT& varSrc) throw();
		//CPnTime& operator=(DATE dtSrc) throw();

// 		
		/*
		\~korean
		º¹»ç ´ëÀÔ ¿¬»êÀÚ  

		\~english
		Copy assignment operator

		\~chinese
		?ğ¤???ß©İ¬¡£
		*/
// 		CPnTime& operator=(const __time32_t& timeSrc) throw();

		/** 
		\~korean
		º¹»ç ´ëÀÔ ¿¬»êÀÚ

		\~english
		Copy assignment operator

		\~chinese
		?ğ¤???ß©İ¬¡£

		\~japanese
		«³«Ô?ÓÛìıæÑß©í­
		\~
		*/
//		CPnTime& operator=(const __time64_t& timeSrc) throw();

		/** 
		\~korean
		º¹»ç ´ëÀÔ ¿¬»êÀÚ  

		\~english
		Copy assignment operator

		\~chinese
		?ğ¤???ß©İ¬¡£

		\~japanese
		«³«Ô?ÓÛìıæÑß©í­
		\~
		*/
		CPnTime& operator=(const SYSTEMTIME& systimeSrc) throw();

		/** 
		\~korean
		º¹»ç ´ëÀÔ ¿¬»êÀÚ  

		\~english
		Copy assignment operator

		\~chinese
		?ğ¤???ß©İ¬¡£

		\~japanese
		«³«Ô?ÓÛìıæÑß©í­
		\~
		*/
		CPnTime& operator=(const FILETIME& filetimeSrc) throw();

		/** 
		\~korean
		º¹»ç ´ëÀÔ ¿¬»êÀÚ  

		\~english
		Copy assignment operator

		\~chinese
		?ğ¤???ß©İ¬¡£

		\~japanese
		«³«Ô?ÓÛìıæÑß©í­
		\~
		*/
		CPnTime& operator=(const UDATE& udate) throw();

		/** 
		\~korean
		ºñ±³ ¿¬»êÀÚ 

		\~english
		Comparison operator

		\~chinese
		İï??ß©İ¬¡£

		\~japanese
		İïÎòæÑß©í­
		\~
		*/
		bool operator==(const CPnTime& date) const throw();

		/** 
		\~korean
		ºñ±³ ¿¬»êÀÚ 

		\~english
		Comparison operator

		\~chinese
		İï??ß©İ¬¡£

		\~japanese
		İïÎòæÑß©í­
		\~
		*/
		bool operator!=(const CPnTime& date) const throw();

		/** 
		\~korean
		ºñ±³ ¿¬»êÀÚ  

		\~english
		Comparison operator

		\~chinese
		İï??ß©İ¬¡£

		\~japanese
		İïÎòæÑß©í­
		\~
		*/
		bool operator<(const CPnTime& date) const throw();

		/** 
		\~korean
		ºñ±³ ¿¬»êÀÚ 

		\~english
		Comparison operator

		\~chinese
		İï??ß©İ¬¡£

		\~japanese
		İïÎòæÑß©í­
		\~
		*/
		bool operator>(const CPnTime& date) const throw();

		/** 
		\~korean
		ºñ±³ ¿¬»êÀÚ 

		\~english
		Comparison operator

		\~chinese
		İï??ß©İ¬¡£

		\~japanese
		İïÎòæÑß©í­
		\~
		*/
		bool operator<=(const CPnTime& date) const throw();

		/** 
		\~korean
		ºñ±³ ¿¬»êÀÚ 

		\~english
		Comparison operator

		\~chinese
		İï??ß©İ¬¡£

		\~japanese
		İïÎòæÑß©í­
		\~
		*/
		bool operator>=(const CPnTime& date) const throw();

		/** 
		\~korean
		³¯Â¥ »çÄ¢¿¬»êÀÚ

		\~english
		Four-fundamental operator for date

		\~chinese
		ìíÑ¢ŞÌ??ß©İ¬¡£

		\~japanese
		ìíÜõŞÌöÎæÑß©í­
		\~
		*/
		CPnTime operator+(CPnTimeSpan dateSpan) const throw();

		/** 
		\~korean
		³¯Â¥ »çÄ¢¿¬»êÀÚ  

		\~english
		Four-fundamental operator for date 

		\~chinese
		ìíÑ¢ŞÌ??ß©İ¬¡£

		\~japanese
		ìíÜõŞÌöÎæÑß©í­
		\~
		*/
		CPnTime operator-(CPnTimeSpan dateSpan) const throw();
		
		/** 
		\~korean
		³¯Â¥ »çÄ¢¿¬»êÀÚ  

		\~english
		Four-fundamental operator for date 

		\~chinese
		ìíÑ¢ŞÌ??ß©İ¬¡£

		\~japanese
		ìíÜõŞÌöÎæÑß©í­
		\~
		*/
		CPnTime& operator+=(CPnTimeSpan dateSpan) throw();

		/** 
		\~korean
		³¯Â¥ »çÄ¢¿¬»êÀÚ  

		\~english
		Four-fundamental operator for date 

		\~chinese
		ìíÑ¢ŞÌ??ß©İ¬¡£

		\~japanese
		ìíÜõŞÌöÎæÑß©í­
		\~
		*/
		CPnTime& operator-=(CPnTimeSpan dateSpan) throw();

		/** 
		\~korean
		³¯Â¥ »çÄ¢¿¬»êÀÚ 

		\~english
		Four-fundamental operator for date 

		\~chinese
		ìíÑ¢ŞÌ??ß©İ¬¡£

		\~japanese
		ìíÜõŞÌöÎæÑß©í­
		\~
		*/
		CPnTimeSpan operator-(const CPnTime& date) const throw();

		//operator DATE() const throw();

		/** 
		\~korean
		³¯Â¥½Ã°£ ¼³Á¤ 

		\~english
		Setting date and time

		\~chinese
		?öÇìíÑ¢??¡£

		\~japanese
		ìíÜõãÁÊààâïÒ
		\~
		*/
		int SetDateTime(int nYear, int nMonth, int nDay,
			int nHour, int nMin, int nSec, int nMillisec) throw();

		/** 
		\~korean
		³¯Â¥½Ã°£ ¼³Á¤ 

		\~english
		Setting date and time

		\~chinese
		?öÇìíÑ¢??¡£

		\~japanese
		ìíÜõãÁÊààâïÒ
		\~
		*/
		int SetDate(int nYear, int nMonth, int nDay) throw();

		/** 
		\~korean
		³¯Â¥½Ã°£ ¼³Á¤  

		\~english
		Setting date and time

		\~chinese
		?öÇìíÑ¢??¡£

		\~japanese
		ìíÜõãÁÊààâïÒ
		\~
		*/
		int SetTime(int nHour, int nMin, int nSec, int nMillisec) throw();

		/** 
		\~korean
		³¯Â¥½Ã°£À» ¹®ÀÚ¿­·ÎºÎÅÍ ¾ò´Â´Ù. 

		\~english
		Gets date and time from text string

		\~chinese
		?í®İ¬Íú?ÔğìíÑ¢??¡£

		\~japanese
		ìíÜõãÁÊàªòÙşí®Öªª«ªéÔğªë
		\~
		*/
		bool ParseDateTime(const PNTCHAR* lpszDate, uint32_t dwFlags = 0,
			LCID lcid = LANG_USER_DEFAULT) throw();

		/** 
		\~korean
		³¯Â¥½Ã°£À» ¹®ÀÚ¿­·Î ¸¸µç´Ù. 

		\~english
		Converts date and time into text string

		\~chinese
		÷êìíÑ¢????à÷í®İ¬Íú¡£

		\~japanese
		ìíÜõãÁÊàªòÙşí®Öªª«ªéÔğªë
		\~
		*/
		String Format(uint32_t dwFlags = 0, LCID lcid = LANG_USER_DEFAULT) const;

		/** 
		\~korean
		³¯Â¥½Ã°£À» ¹®ÀÚ¿­·Î ¸¸µç´Ù.  

		\~english
		Converts date and time into text string 

		\~chinese
		÷êìíÑ¢????à÷í®İ¬Íú¡£

		\~japanese
		ìíÜõãÁÊàªòÙşí®Öªª«ªéÔğªë
		\~
		*/
		String Format(const PNTCHAR* lpszFormat) const;

		/** 
		\~korean
		³¯Â¥½Ã°£À» ¹®ÀÚ¿­·Î ¸¸µç´Ù.  

		\~english
		Converts date and time into text string 

		\~chinese
		÷êìíÑ¢????à÷í®İ¬Íú¡£

		\~japanese
		ìíÜõãÁÊàªòÙşí®Öªª«ªéÔğªë
		\~
		*/
		String Format(uint32_t nFormatID) const;


	protected:
		static double DoubleFromDate( DATE date ) throw();
		static DATE DateFromDouble( double f ) throw();

		void CheckRange();	
		BOOL ConvertSystemTimeToVariantTime(const SYSTEMTIME& systimeSrc);

	};

	/**  @} */
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
