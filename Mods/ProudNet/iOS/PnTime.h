/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 177 92 124 113 87 79 17 155 171 239 138 133 88 235 28 112 146 102 93 52 214 131 240 31 138 179 248 115 127 118 107 31 112 91 111 14 243 1 121 131 22 69 144 19 214 101 65 133 253 32 122 175 12 198 63 134 23 240 109 90 59 142 194 194 160 148 139 101 68 220 217 181 32 240 36 47 59 74 18 182 145 116 17 29 255 115 236 11 29 111 122  */
/*
ProudNet 1.7.34387-dev003-10


�� ���α׷��� ���۱��� ���ټǿ��� �ֽ��ϴ�.
�� ���α׷��� ����, ���, ������ ���õ� ������ �� ���α׷��� �������ڿ��� ����� ������,
����� �ؼ����� �ʴ� ��� ��Ģ������ ���� ����� �����մϴ�.
���� ��뿡 ���� å���� �� ���α׷��� �������ڿ��� ��༭�� ��õǾ� �ֽ��ϴ�.

** ���� : ���۹��� ���� ���� ��ø� �������� ���ʽÿ�.


This program is soley copyrighted by Nettention.
Any use, correction, and distribution of this program are subject to the terms and conditions of the License Agreement.
Any violated use of this program is prohibited and will be cause of immediate termination according to the License Agreement.

** WARNING : PLEASE DO NOT REMOVE THE LEGAL NOTICE ABOVE.


���������??Nettention�������
?����������ǡ����ġ�?����?����?���������������?���??��
������???��?�������������ġ�
���������?��٥���?��������?�������?�졣

** ��������?�����ڪ��߾��٥�ơ�


���Ϋ׫���������?��Nettention�˪���ު���
���Ϋ׫��������ᡢ���ġ����֪�?������������׫��������?�Ȫ���峪�?����
��峪��������ʪ����ꡢ����ܪ���?���Ī��ת��ު���
��?���Ī˪���������׫��������?�Ȫ��������٥�ƪ���ƪ��ު���

** �������ڪ��?����߾����٥�ƪ���۪��ʪ��Ǫ���������

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
// ���� �����̶� #include <oledb.h>�� include�� �� ���� ȯ�� ������ ���� ���� �Ѵ�.
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
	�� ��¥�ð��� �ð���   

	\~english
	Time difference between two different dates

	\~chinese
	??��Ѣ??��??󬡣

	\~japanese
	?��������������
	\~
	*/
	class PROUD_API CPnTimeSpan
	{
		// Constructors
	public:
		/** 
		\~korean
		������  

		\~english
		Constructor

		\~chinese
		������

		\~japanese
		�����
		\~
		*/
		CPnTimeSpan() throw();

		/** 
		\~korean
		������  

		\~english
		Constructor

		\~chinese
		������

		\~japanese
		�����
		\~
		*/
		CPnTimeSpan(double dblSpanSrc) throw();
		/** 
		\~korean
		������  

		\~english
		Constructor

		\~chinese
		������

		\~japanese
		�����
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
		��,��,��,��,�и��ʷ� �Ѱ� ȯ���Ѵ�.  

		\~english
		Converts into day,hour,minute,second,millisecond format. 

		\~chinese
		����?���¡��������� ???ߩ��

		\~japanese
		�������¡������߫�����?ͪ��ߩ���ު���
		\~
		*/
		double GetTotalDays() const throw();    // span in days (about -3.65e6 to 3.65e6)

		/** 
		\~korean
		��,��,��,��,�и��ʷ� �Ѱ� ȯ���Ѵ�.  

		\~english
		Converts into day,hour,minute,second,millisecond format. 

		\~chinese
		����?���¡��������� ???ߩ��

		\~japanese
		�������¡������߫�����?ͪ��ߩ���ު���
		\~		*/
		double GetTotalHours() const throw();   // span in hours (about -8.77e7 to 8.77e6)

		/** 
		\~korean
		��,��,��,��,�и��ʷ� �Ѱ� ȯ���Ѵ�.  

		\~english
		Converts into day,hour,minute,second,millisecond format.

		\~chinese
		����?���¡��������� ???ߩ��

		\~japanese
		�������¡������߫�����?ͪ��ߩ���ު���
		\~
		*/
		double GetTotalMinutes() const throw(); // span in minutes (about -5.26e9 to 5.26e9)

		/** 
		\~korean
		��,��,��,��,�и��ʷ� �Ѱ� ȯ���Ѵ�.  

		\~english
		Converts into day,hour,minute,second,millisecond format. 

		\~chinese
		����?���¡��������� ???ߩ��

		\~japanese
		�������¡������߫�����?ͪ��ߩ���ު���
		\~
		*/
		double GetTotalSeconds() const throw(); // span in seconds (about -3.16e11 to 3.16e11)

		/** 
		\~korean
		��,��,��,��,�и��ʷ� �Ѱ� ȯ���Ѵ�.  

		\~english
		Converts into day,hour,minute,second,millisecond format. 

		\~chinese
		����?���¡��������� ???ߩ��

		\~japanese
		�������¡������߫�����?ͪ��ߩ���ު���
		\~
		*/
		double GetTotalMilliseconds() const throw();	// span in milliseconds

		/** 
		\~korean
		��,��,��,�ʸ� ��´�.  

		\~english
		Gets day,hour,minute,second.

		\~chinese
		?����?���¡�����

		\~japanese
		�������¡�������ު���
		\~
		*/
		int32_t GetDays() const throw();       // component days in span

		/** 
		\~korean
		��,��,��,�ʸ� ��´�.  

		\~english
		Gets day,hour,minute,second.

		\~chinese
		?����?���¡�����

		\~japanese
		�������¡�������ު���
		\~
		*/
		int32_t GetHours() const throw();      // component hours in span (-23 to 23)

		/** 
		\~korean
		��,��,��,�ʸ� ��´�.  

		\~english
		Gets day,hour,minute,second.

		\~chinese
		?����?���¡�����

		\~japanese
		�������¡�������ު���
		\~
		*/
		int32_t GetMinutes() const throw();    // component minutes in span (-59 to 59)

		/** 
		\~korean
		��,��,��,�ʸ� ��´�.  

		\~english
		Gets day,hour,minute,second.

		\~chinese
		?����?���¡�����

		\~japanese
		�������¡�������ު���
		\~
		*/
		int32_t GetSeconds() const throw();    // component seconds in span (-59 to 59)

		int GetMilliseconds() const throw();

		/** 
		\~korean
		���� ���� ������  

		\~english
		Copy assignment operator

		\~chinese
		?�???ߩݬ��

		\~japanese
		����?������ߩ�
		\~
		*/
		CPnTimeSpan& operator=(double dblSpanSrc) throw();

		/** 
		\~korean
		�� ������  

		\~english
		Comparison operator

		\~chinese
		��??ߩݬ��

		\~japanese
		������ߩ�
		\~
		*/
		bool operator==(const CPnTimeSpan& dateSpan) const throw();
		/** 
		\~korean
		�� ������  

		\~english
		Comparison operator

		\~chinese
		��??ߩݬ��

		\~japanese
		������ߩ�
		\~
		*/
		bool operator!=(const CPnTimeSpan& dateSpan) const throw();
		/** 
		\~korean
		�� ������  

		\~english
		Comparison operator

		\~chinese
		��??ߩݬ��

		\~japanese
		������ߩ�
		\~
		*/
		bool operator<(const CPnTimeSpan& dateSpan) const throw();

		/** 
		\~korean
		�� ������  

		\~english
		Comparison operator

		\~chinese
		��??ߩݬ��

		\~japanese
		������ߩ�
		\~
		*/
		bool operator>(const CPnTimeSpan& dateSpan) const throw();

		/** 
		\~korean
		�� ������  

		\~english
		Comparison operator

		\~chinese
		��??ߩݬ��

		\~japanese
		������ߩ�
		\~
		*/
		bool operator<=(const CPnTimeSpan& dateSpan) const throw();

		/** 
		\~korean
		�� ������  

		\~english
		Comparison operator

		\~chinese
		��??ߩݬ��

		\~japanese
		������ߩ�
		\~
		*/
		bool operator>=(const CPnTimeSpan& dateSpan) const throw();

		/** 
		\~korean
		��¥ ��Ģ������  

		\~english
		Four-fundamental operator for date

		\~chinese
		��Ѣ��??ߩݬ��

		\~japanese
		\~
		*/
		CPnTimeSpan operator+(const CPnTimeSpan& dateSpan) const throw();

		/** 
		\~korean
		��¥ ��Ģ������  

		\~english
		Four-fundamental operator for date

		\~chinese
		��Ѣ��??ߩݬ��

		\~japanese
		����������ߩ�
		\~
		*/
		CPnTimeSpan operator-(const CPnTimeSpan& dateSpan) const throw();

		/** 
		\~korean
		��¥ ��Ģ������  

		\~english
		Four-fundamental operator for date

		\~chinese
		��Ѣ��??ߩݬ��

		\~japanese
		����������ߩ�
		\~
		*/
		CPnTimeSpan& operator+=(const CPnTimeSpan dateSpan) throw();

		/** 
		\~korean
		��¥ ��Ģ������  

		\~english
		Four-fundamental operator for date

		\~chinese
		��Ѣ��??ߩݬ��

		\~japanese
		����������ߩ�
		\~
		*/
		CPnTimeSpan& operator-=(const CPnTimeSpan dateSpan) throw();

		/** 
		\~korean
		��¥ ��Ģ������  

		\~english
		Four-fundamental operator for date

		\~chinese
		��Ѣ��??ߩݬ��

		\~japanese
		����������ߩ�
		\~
		*/
		CPnTimeSpan operator-() const throw();

//		operator double() const throw();

		/** 
		\~korean
		��¥�ð� ����  

		\~english
		Setting date and time

		\~chinese
		?����Ѣ??��

		\~japanese
		������������
		\~
		*/
		void SetDateTimeSpan(int32_t lDays, int nHours, int nMins, int nSecs, int nMillisecs) throw();

		/** 
		\~korean
		��¥�ð��� ���ڿ��� �����.  

		\~english
		Converts date and time into text string

		\~chinese
		����Ѣ????���ݬ����

		\~japanese
		������������֪���ª�ު���
		\~
		*/
		String Format(const PNTCHAR *pFormat) const;

		/** 
		\~korean
		��¥�ð��� ���ڿ��� �����.  

		\~english
		Converts date and time into text string

		\~chinese
		����Ѣ????���ݬ����

		\~japanese
		������������֪���ª�ު���
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
	��¥�ð� ������ Ÿ��

	\~english
	Date and time data type  

	\~chinese
	��Ѣ???��?����

	\~japanese
	���������?��������
	\~
	*/
	class PROUD_API CPnTime  // CTime�̳� CDateTime, CPnTime�� ATL ��� �̸��� ȥ���� �� �����Ƿ�
	{
		// Constructors
	public:
		static CPnTime GetCurrentTime() throw();

		/** 
		\~korean
		������  

		\~english
		Constructor

		\~chinese
		������

		\~japanese
		�����
		\~
		*/
		CPnTime() throw();

		/** 
		\~korean
		������  

		\~english
		Constructor

		\~chinese
		������

		\~japanese
		�����
		\~
		*/
		CPnTime(const VARIANT& varSrc) throw();
		//CPnTime(DATE dtSrc) throw();

		/*
		\~korean
		������

		\~english
		Constructor

		\~chinese
		������

		\~japanese
		�����
		\~
		*/
		// 		CPnTime(__time32_t timeSrc) throw();

		/**
		\~korean
		������

		\~english
		Constructor

		\~chinese
		������

		\~japanese
		�����
		\~
		*/
		//CPnTime(__time64_t timeSrc) throw();

		/** 
		\~korean
		������ 

		\~english
		Constructor

		\~chinese
		������

		\~japanese
		�����
		\~
		*/
		CPnTime(const SYSTEMTIME& systimeSrc) throw();

		/** 
		\~korea
		������  

		\~english
		Constructor

		\~chinese
		������

		\~japanese
		�����
		\~
		*/
		CPnTime(const FILETIME& filetimeSrc) throw();

		/** 
		\~korean
		������  

		\~english
		Constructor

		\~chinese
		������

		\~japanese
		�����
		\~
		*/
		CPnTime(int nYear, int nMonth, int nDay,
			int nHour, int nMin, int nSec, int nMillisec) throw();

		/** 
		\~korean
		������  

		\~english
		Constructor

		\~chinese
		������

		\~japanese
		�����
		\~
		*/
		CPnTime(uint16_t wDosDate, uint16_t wDosTime) throw();

		/** 
		\~korean
		DATE Ÿ�����κ��� �� ��ü�� ����   

		\~english
		Creates this object from date type

		\~chinese
		?DATE?�������?�ڡ�

		\~japanese
		DATE�����ת��骳�Ϋ��֫������Ȫ�����
		\~
		*/
		static CPnTime FromDATE(DATE dtSrc);

#ifdef _WIN32
		CPnTime( const DBTIMESTAMP& dbts) throw();
		bool GetAsDBTIMESTAMP( DBTIMESTAMP& dbts ) const throw();
#endif // _WIN32

		/** 
		\~korean
		��¥�ð��� ��ȿ ���� 

		\~english
		Valid state of date and time

		\~chinese
		��Ѣ??������??��

		\~japanese
		�����������??��
		\~
		*/
		enum DateTimeStatus
		{
			/** 
			\~korean
			���� 

			\~english
			Error

			\~chinese
			??��

			\~japanese
			����?
			\~
			*/
			error = -1,

			/** 
			\~korean
			��ȿ 

			\~english
			Valid

			\~chinese
			������

			\~japanese
			��?
			\~
			*/
			valid = 0,

			/** 
			\~korean
			�߸��� ��¥ (���� �ʰ� ��)

			\~english
			Invalid date (out of range, etc.)

			\~chinese
			??����Ѣ��������?����

			\~japanese
			���ުê���������?��Φ�ʪɣ�

			\~

			*/
			invalid = 1,

			/** 
			\~korean
			�� �״�� ���� ����.

			\~english
			Literally has no value

			\~chinese
			�����?

			\~japanese
			����ת�������ʪ�

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
		������ ��´�.

		\~english
		Gets year

		\~chinese
		?��Ҵ����

		\~japanese
		Ҵ�������
		\~
		*/
		int GetYear() const throw();

		/** 
		\~korean
		�� ���� ��´�.

		\~english
		Gets month value

		\~chinese
		?����?��

		\~japanese
		���������
		\~
		*/
		int GetMonth() const throw();

		/** 
		\~korean
		�� ���� ��´�.

		\~english
		Gets day value

		\~chinese
		?����?��

		\~japanese
		���������
		\~
		*/
		int GetDay() const throw();

		/** 
		\~korean
		�� ���� ��´�.

		\~english
		Gets hour value

		\~chinese
		?��??��

		\~japanese
		���������
		\~
		*/
		int GetHour() const throw();

		/** 
		\~korean
		�� ���� ��´�.

		\~english
		Gets minute value

		\~chinese
		?����?��

		\~japanese
		���������
		\~
		*/
		int GetMinute() const throw();

		/** 
		\~korean
		�� ���� ��´�.

		\~english
		Gets second value

		\~chinese
		?����?��

		\~japanese
		���������
		\~
		*/
		int GetSecond() const throw();

		/** 
		\~korean
		 �и��� ���� ��´�.

		\~english
		Gets millisecond value

		\~chinese
		?������?��

		\~japanese
		�߫����������
		\~
		*/
		int GetMillisecond() const throw();

		/** 
		\~korean
		���� ���� ��´�. (1: �Ͽ���, 2: ������...)

		\~english
		Gets day of the week value (1: Sunday, 2: Monday...) 

		\~chinese
		?����Ѣ?����1����Ѣ��2����Ѣ�顣������

		\~japanese
		����������루1��������2����������
		\~
		*/
		int GetDayOfWeek() const throw();

		/** 
		\~korean
		1���� ���° �������� ��´�. (1: 1�� 1��)

		\~english
		Gets which day in a year (1: 1st January) 

		\~chinese
		?������Ҵ����?��������1����������

		\~japanese
		1Ҵ�������ͪ���ʪΪ�����루1��1��1��
		\~
		*/
		int GetDayOfYear() const throw();

		/** 
		\~korean
		���� ���� ������  

		\~english
		Copy assignment operator

		\~chinese
		?�???ߩݬ��

		\~japanese
		����?������ߩ�
		\~
		*/
		CPnTime& operator=(const VARIANT& varSrc) throw();
		//CPnTime& operator=(DATE dtSrc) throw();

// 		
		/*
		\~korean
		���� ���� ������  

		\~english
		Copy assignment operator

		\~chinese
		?�???ߩݬ��
		*/
// 		CPnTime& operator=(const __time32_t& timeSrc) throw();

		/** 
		\~korean
		���� ���� ������

		\~english
		Copy assignment operator

		\~chinese
		?�???ߩݬ��

		\~japanese
		����?������ߩ�
		\~
		*/
//		CPnTime& operator=(const __time64_t& timeSrc) throw();

		/** 
		\~korean
		���� ���� ������  

		\~english
		Copy assignment operator

		\~chinese
		?�???ߩݬ��

		\~japanese
		����?������ߩ�
		\~
		*/
		CPnTime& operator=(const SYSTEMTIME& systimeSrc) throw();

		/** 
		\~korean
		���� ���� ������  

		\~english
		Copy assignment operator

		\~chinese
		?�???ߩݬ��

		\~japanese
		����?������ߩ�
		\~
		*/
		CPnTime& operator=(const FILETIME& filetimeSrc) throw();

		/** 
		\~korean
		���� ���� ������  

		\~english
		Copy assignment operator

		\~chinese
		?�???ߩݬ��

		\~japanese
		����?������ߩ�
		\~
		*/
		CPnTime& operator=(const UDATE& udate) throw();

		/** 
		\~korean
		�� ������ 

		\~english
		Comparison operator

		\~chinese
		��??ߩݬ��

		\~japanese
		������ߩ�
		\~
		*/
		bool operator==(const CPnTime& date) const throw();

		/** 
		\~korean
		�� ������ 

		\~english
		Comparison operator

		\~chinese
		��??ߩݬ��

		\~japanese
		������ߩ�
		\~
		*/
		bool operator!=(const CPnTime& date) const throw();

		/** 
		\~korean
		�� ������  

		\~english
		Comparison operator

		\~chinese
		��??ߩݬ��

		\~japanese
		������ߩ�
		\~
		*/
		bool operator<(const CPnTime& date) const throw();

		/** 
		\~korean
		�� ������ 

		\~english
		Comparison operator

		\~chinese
		��??ߩݬ��

		\~japanese
		������ߩ�
		\~
		*/
		bool operator>(const CPnTime& date) const throw();

		/** 
		\~korean
		�� ������ 

		\~english
		Comparison operator

		\~chinese
		��??ߩݬ��

		\~japanese
		������ߩ�
		\~
		*/
		bool operator<=(const CPnTime& date) const throw();

		/** 
		\~korean
		�� ������ 

		\~english
		Comparison operator

		\~chinese
		��??ߩݬ��

		\~japanese
		������ߩ�
		\~
		*/
		bool operator>=(const CPnTime& date) const throw();

		/** 
		\~korean
		��¥ ��Ģ������

		\~english
		Four-fundamental operator for date

		\~chinese
		��Ѣ��??ߩݬ��

		\~japanese
		����������ߩ�
		\~
		*/
		CPnTime operator+(CPnTimeSpan dateSpan) const throw();

		/** 
		\~korean
		��¥ ��Ģ������  

		\~english
		Four-fundamental operator for date 

		\~chinese
		��Ѣ��??ߩݬ��

		\~japanese
		����������ߩ�
		\~
		*/
		CPnTime operator-(CPnTimeSpan dateSpan) const throw();
		
		/** 
		\~korean
		��¥ ��Ģ������  

		\~english
		Four-fundamental operator for date 

		\~chinese
		��Ѣ��??ߩݬ��

		\~japanese
		����������ߩ�
		\~
		*/
		CPnTime& operator+=(CPnTimeSpan dateSpan) throw();

		/** 
		\~korean
		��¥ ��Ģ������  

		\~english
		Four-fundamental operator for date 

		\~chinese
		��Ѣ��??ߩݬ��

		\~japanese
		����������ߩ�
		\~
		*/
		CPnTime& operator-=(CPnTimeSpan dateSpan) throw();

		/** 
		\~korean
		��¥ ��Ģ������ 

		\~english
		Four-fundamental operator for date 

		\~chinese
		��Ѣ��??ߩݬ��

		\~japanese
		����������ߩ�
		\~
		*/
		CPnTimeSpan operator-(const CPnTime& date) const throw();

		//operator DATE() const throw();

		/** 
		\~korean
		��¥�ð� ���� 

		\~english
		Setting date and time

		\~chinese
		?����Ѣ??��

		\~japanese
		������������
		\~
		*/
		int SetDateTime(int nYear, int nMonth, int nDay,
			int nHour, int nMin, int nSec, int nMillisec) throw();

		/** 
		\~korean
		��¥�ð� ���� 

		\~english
		Setting date and time

		\~chinese
		?����Ѣ??��

		\~japanese
		������������
		\~
		*/
		int SetDate(int nYear, int nMonth, int nDay) throw();

		/** 
		\~korean
		��¥�ð� ����  

		\~english
		Setting date and time

		\~chinese
		?����Ѣ??��

		\~japanese
		������������
		\~
		*/
		int SetTime(int nHour, int nMin, int nSec, int nMillisec) throw();

		/** 
		\~korean
		��¥�ð��� ���ڿ��κ��� ��´�. 

		\~english
		Gets date and time from text string

		\~chinese
		?�ݬ��?����Ѣ??��

		\~japanese
		������������֪�������
		\~
		*/
		bool ParseDateTime(const PNTCHAR* lpszDate, uint32_t dwFlags = 0,
			LCID lcid = LANG_USER_DEFAULT) throw();

		/** 
		\~korean
		��¥�ð��� ���ڿ��� �����. 

		\~english
		Converts date and time into text string

		\~chinese
		����Ѣ????���ݬ����

		\~japanese
		������������֪�������
		\~
		*/
		String Format(uint32_t dwFlags = 0, LCID lcid = LANG_USER_DEFAULT) const;

		/** 
		\~korean
		��¥�ð��� ���ڿ��� �����.  

		\~english
		Converts date and time into text string 

		\~chinese
		����Ѣ????���ݬ����

		\~japanese
		������������֪�������
		\~
		*/
		String Format(const PNTCHAR* lpszFormat) const;

		/** 
		\~korean
		��¥�ð��� ���ڿ��� �����.  

		\~english
		Converts date and time into text string 

		\~chinese
		����Ѣ????���ݬ����

		\~japanese
		������������֪�������
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
