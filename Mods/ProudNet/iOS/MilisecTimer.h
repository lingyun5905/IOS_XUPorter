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
#include "BasicTypes.h"
#include "Enums.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif

namespace Proud
{
	/** \addtogroup util_group
	*  @{
	*/

	/** 
	\~korean
	�и��� ������ ���е��� ������ Ÿ�̸��Դϴ�.
	- CMilisecTimer::New �� ���� �����ϰ�, delete�� ���� �մϴ�.
	- ���������� QueryPerformanceCounter�� ����մϴ�.
	- ���е��� ������ ������, windows ����,CPU�� ���� �߸��� ������ �Ͼ� �� �� �ֽ��ϴ�.
	- ��ǻ�͸� �Ѱ� 81706����� ����Ҽ� �ֽ��ϴ�.

	\~english
	It is a timer whose degree of precision is millisecond. 
	Create by ��CMilisecTimer::New�� and delete by ��delete��.
	QueryPerformanceCounter is internally used. 
	No problem with precision but wrong calculation might occur depending on Windows version & CPU.
	Can use it up to  81706 after turning on the computer. 

	\~chinese
	��?��?����?������?�
	-��? CMilisecTimer::New ��������delete?𶡣
	-?ݻ���� QueryPerformanceCounter��
	-��?��?��??��ӣ��??����Windows���⣬CPU��?��??��ߩ��
	-�????��ʦ���������81706Ҵ��

	\~japanese
	�߫���?�Ȫ����������ī�����?�Ǫ���
	- CMilisecTimer::New�����Ī�����������delete����𶪷�ު���
	-?ݻ�ܪ˪�QueryPerformanceCounter�����Ī��ު���
	-�����������Ϫʪ����� windows��?������CPU�˪�ê����ުê���ߩ���ê���ʦ����������ު���
	-����ԫ�?��?���깪������81706Ҵ�ު����ĪǪ��ު���

	\~
	*/
	class CMilisecTimer
	{
	public:
		virtual ~CMilisecTimer(){}

		/**
		\~korean
		Ÿ�̸Ӹ� �ʱ�ȭ�Ѵ�.

		\~english
		Initialize the timer

		\~chinese
		�����Timer��

		\~japanese
		Timer����Ѣ�����롣

		\~
		*/
		PROUD_API virtual void Reset() = 0;

		/**
		\~korean
		Ÿ�̸Ӹ� �����Ѵ�.

		\~english
		Start the timer

		\~chinese
		?�Timer��

		\~japanese
		Timer��Ϫ���롣

		\~
		*/
		PROUD_API virtual void Start() = 0;

		/**
		\~korean
		Ÿ�̸Ӹ� �Ͻ� �����Ѵ�.

		\~english
		Temporarily stop the timer. 

		\~chinese
		???�Timer��

		\~japanese
		Timer��������򭪹�롣

		\~
		*/
		PROUD_API virtual void Stop() = 0;

		/**
		\~korean
		Ÿ�̸Ӹ� 0.1�ʸ�ŭ ����ǰ� �Ѵ�.

		\~english
		Move the timer 0.1 second forward

		\~chinese
		?Timer��?��0.1����

		\~japanese
		Timer��0.1���������������롣

		\~
		*/
		PROUD_API virtual void Advance() = 0;

		/** 
		\~korean
		���� �ð��� ��´�. 

		\~english
		Gets current time

		\~chinese
		?��?���??��

		\~japanese
		����������ު���

		\~
		*/
		PROUD_API virtual int64_t GetTimeMs() = 0; 
		
		/** 
		\~korean
		���� GetElapsedTimeMs() ȣ��� ���� �����ð��� ����ϴ�.
		- MMTimer �� ���, ���е��� ������ ���� �� �ֽ��ϴ�.
		- QPC�� ���, ��Ȯ�� �ð��� ��� ������, GetTickCount()���� 50�� ���� ������.

		\~english TODO:translate needed.
		Get the elapsed time from the previous GetElapsedTimeMs() call. 
		- In the case of MMTimer, there may be a problem with the accuracy. 
		- In the case of QPC, you get accurate time, but it is 50 times slower than GetTickCount(). 

		\~chinese
		?��?����GetElapsedTimeMs()��У?�??��??��
		- MMTimer��?����ʦ��?��??��
		- QPC��?ʦ�?����?��??��ӣ��GetTickCount()ط��?50����ӡ�

		\~japanese
		���GetElapsedTimeMs()�����󪷪���?Φ�����������ު���
		- MMTimer�����ꡢ����������𹪬������ު���
		- QPC�����ꡢ�������������몳�ȪϪ���ު�����GetTickCount()���50�ê۪�?���Ǫ���
		\~
		*/
		PROUD_API virtual int64_t GetElapsedTimeMs() = 0; 

		/** 
		\~korean
		Ÿ�̸Ӱ� ���� �����̸� true�� �����Ѵ�. 

		\~english
		Returns true when timer is paused

		\~chinese
		??�������??��?����true��

		\~japanese
		������?�����?���Ǫ����true��꫿?�󪷪ު���
\~
		*/
		PROUD_API virtual bool IsStopped() = 0; 


		/**
		\~korean
		type�� �����Ͽ� timer�� �����մϴ�.

		\~english TODO:translate needed.
		Designate the type to generate the timer. 

		\~chinese
		���type������timer��

		\~japanese
		Type����Ҫ���timer���������ު���
\~
		*/
		PROUD_API static CMilisecTimer* New();
	};

	/** 
	\~korean
	�ſ� ������ "���� �ð�"�� ��´�. ���е��� 1ms�̸�, ���� ������ ���ϴ� critical section lock 1ȸ�̴�.

	\~english
	Gets very precise "current time". 1ms resolution. the time cost of this function is a critical section lock.

	\~chinese
	?��ު����?�ܡ�???������?��?1ms��?��?��?��?1� critical section lock��

	\~japanese
	�Ȫƪ����˪�"�������"����ު���������1ms�ǡ��������������ݶ�ê�critical section lock 1�ުǪ���
	\~
	*/
	int64_t GetPreciseCurrentTimeMs();


	/**  @} */
	}

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif
