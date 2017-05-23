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

#include <vector>

#if defined(_WIN32)
	#include <WinSock2.h>
	#include <MMSystem.h>
#else
	#include <pthread.h>
	#include <sys/types.h>
#endif

#include "BasicTypes.h"
#include "Deque.h"
#include "FastArrayPtr.h"
#include "Ptr.h"
#include "Event.h"
#include "Exception.h"
#include "TimeUtil.h"
#include "PnThread.h"
#include "Singleton.h"
#include "StackNew.h"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4324)
#endif // _MSC_VER


#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup util_group
	*  @{
	*/


	// CLR�� ��� Ŭ���� ����
	class IClonable
	{
	public:
		virtual void Clone() = 0;
		virtual ~IClonable() {}
	};

#ifdef _WIN32
	/** 
	\~korean
	Ÿ�̸� Ŭ����
	- ���� �ð����� �̺�Ʈ ��ü(Proud.Event ����)�� SetEvent, �� �ñ׳��Ѵ�.
	- .Net framework�� System.Timer�� ���� ������ �Ѵ�.

	\~english
	Timer class
	- Periodically lets SetEvent evenrt object(Please refer Proud.Event), in other words, this lets it signal.
	- Acts similar to System.Timer of .NET framework

	\~chinese
	??��?
	- ��̰��ӫ??������?�ڣ� ?�� Proud.Event ��SetEvent��??��?��򱡣
	- ?Net framework�� System.Timer%�����?�����ġ�

	\~japanese
	������?���髹
	- ������઴�Ȫ˫��٫�ȫ��֫������ȣ�Proud.Event��?�ţ���SetEvent��?�������ʫ몷�ު���
	- .Net framework��System.Timer�Ϊ誦����ܪ򪷪ު���
	\~
	*/
	class Timer
	{
		TimerEventHandle m_timerID;
		HANDLE m_eventHandle; // �� ��ü�� ���ؼ� set�� �ȴ�.

		static void EventSetter(void* ctx);

	public:
		/** 
		\~korean
		������
		\param eventHandle ���� �ð����� �ñ׳��� ���� �̺�Ʈ ��ü. Proud.Event�� �Ķ���ͷ� �־ �ȴ�.
		\param interval �ñ׳��� ���� �ֱ�. �и����̴�.

		\~english
		 Constructor
		\param eventHandle Evnet object where signal to be entered periodically. It is possible to use Proud.event as parameter.
		\param interval The period to enter signal. Unit is millisecond.

		\~chinese
		�����
		\param eventHandle ������??ۯ����?������?�ڡ�ʦ��� Proud.Event%ۯ��???��
		\param interval ۯ���������Ѣ��ڰ�ء�

		\~japanese
		�����
		\param eventHandle ������઴�Ȫ˫����ʫ������뫤�٫�ȫ��֫������ȡ�Proud.Event��ѫ��?��?�Ȫ�������ƪ��ު��Ǫ���
		\param interval �����ʫ��������Ѣ���߫����Ǫ���
		\~
		*/
		PROUD_API Timer(HANDLE eventHandle, uint32_t interval, DWORD_PTR dwUser = 0);

		/** 
		\~korean
		�ı���
		- ��ü�� �ı��� ���ĺ��ʹ� �̺�Ʈ ��ü�� �ñ׳��� ���� �ʴ´�.

		\~english
		Destructor
		- From right after destructing objct, it is not to enter signal into event object.

		\~chinese
		��?�
		- ��??����?㷣���������ۯ������?�ڡ�

		\~japanese
		��?�
		- ���֫������Ȫ���?������������ϫ��٫�ȫ��֫������Ȫ˫����ʫ������ު���
		\~
		*/
		PROUD_API ~Timer();
	};
#endif
	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#ifdef _MSC_VER
#pragma warning(pop)
#endif // _MSC_VER
