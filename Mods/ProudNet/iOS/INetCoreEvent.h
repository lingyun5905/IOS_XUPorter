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

#include "ErrorInfo.h"
#include "Enums.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup net_group
	*  @{
	*/


	class RmiContext;

	/** user worker thread callback context. */
	class CUserWorkerThreadCallbackContext
	{
	};



	/** 
	\~korean
	ProudNet�� event sink
	- �Ļ� Ŭ�������� ����.

	\~english
	Event sink for ProudNet
	- Use it with derivation class

	\~chinese
	ProudNet��event sink��
	- �����?�����ġ�

	\~japanese
	ProudNet�� event sink
	- ���櫯�髹���Ū��ު���
	\~
	*/
	class INetCoreEvent
	{
	public:

	public:
		virtual ~INetCoreEvent();

		/** 
		\~korean
		���� ���� �߻��� ȣ���
		\param errorInfo ���� ����. ErrorInfo::ToString() �� ���Ͽ� �ʿ��� ������ ���� ������ �� �ֽ��ϴ�. �ڼ��� ���� ErrorInfo ���򸻿� �ֽ��ϴ�.

		\~english TODO:translate needed.
		It is called when an internal error is called. 
		\param errorInfo Error information. You can easily obtain the necessary information through ErrorInfo::ToString(). More details are in the ErrorInfo help. 

		\~chinese
		?��?ݻ???����У��
		\param errorInfo ??���ӡ���? ErrorInfo::ToString()%ʦ�?��?����������ӡ�??���ErrorInfo?��졣

		\~japanese
		?ݻ����?��?�����������󪵪�ު���
		\param errorInfo ����?���á�ErrorInfo::ToString()���ת���驪����ê���?��⢪�����몳�Ȫ��Ǫ��ު����٪����ϡ�ErrorInfo�Ϋث�ת�?�Ϊ���������
		\~
		*/
		virtual void OnError(ErrorInfo *errorInfo) = 0;

		/** 
		\~korean
		���� ��� �߻��� ȣ���. �������ٴ� ���� ������ ������ ������.
		\param errorInfo ���� ����. ErrorInfo::ToString() �� ���Ͽ� �ʿ��� ������ ���� ������ �� �ֽ��ϴ�. �ڼ��� ���� ErrorInfo ���򸻿� �ֽ��ϴ�. 

		\~english TODO:translate needed.
		It is called when an internal warning is called. This reports a problem on a lower level than an error. 
		\param errorInfo Error information. You can easily obtain the necessary information through ErrorInfo::ToString(). More details are in the ErrorInfo help.

		\~chinese
		?��?ݻ��ͱ?����У��?ͱ��??�?��??
		\param errorInfo ??���ӡ���? ErrorInfo::ToString()%ʦ�?��?����������ӡ�??���ErrorInfo?��졣

		\~japanese
		?ݻ��ͱ��?�����������󪵪�ު�������?�������٫��������ͱ���ު���
		\param errorInfo ����?���á�ErrorInfo::ToString()���ת���驪����ê���?��⢪�����몳�Ȫ��Ǫ��ު����٪����ϡ�ErrorInfo�Ϋث�ת�?�Ϊ���������
		\~
		*/
		virtual void OnWarning(ErrorInfo *errorInfo) = 0;

		/** 
		\~korean
		���� �˸� �߻��� ȣ���. ���� ��Ȳ ���� ���� ���� ������ ���� ��Ȳ�� ���ϴ� ���� �ƴ�.
		\param errorInfo ���� ����. ErrorInfo::ToString() �� ���Ͽ� �ʿ��� ������ ���� ������ �� �ֽ��ϴ�.

		\~english TODO:translate needed.
		It is called when an internal notification is called. This is for internal status tracing, etc. and does not mean a problem situation. 
		\param errorInfo Error information. You can easily obtain the necessary information through ErrorInfo::ToString(). More details are in the ErrorInfo help.

		\~chinese
		?��?ݻͱ�?����У����?��?ݻ��?�������?����????����?��
		\param errorInfo ??���ӡ���? ErrorInfo::ToString()%ʦ�?��?����������ӡ�

		\~japanese
		?ݻ����?�બ?�����������󪵪�ު���?ݻ?������ʪɪΪ���Ϊ��Ȫǡ����?�Ϫ��몦�ΪǪϪ���ު���
		\param errorInfo ����?���á�ErrorInfo::ToString()���ת���驪����ê���?��⢪�����몳�Ȫ��Ǫ��ު���
		\~
		*/
		virtual void OnInformation(ErrorInfo *errorInfo) = 0;

		/** 
		\~korean
		Proud.Exception ���� ����
		- �Ϲ������� ���� �ڵ忡�� ���� ������ ó���Ѵ�.
		- ������ �ʿ��� �͵��� �����ϸ� �ȴ�.
		- ExceptionType ���� �ش� Exception ��ü�� �� ����ϸ� �ȴ�.
		- _com_error, void*, std::exception ���� ��� ó���Ѵ�.
		���� catch(...)�� ó���ϴ� OnUnhandledException()�� �ִ�.
		- void*�� ���� ��ü�� Ÿ���� ĳ�����ؼ� ���� �� �ִ�. ���� MFC CException �� �޴µ� ���ȴ�.

		\~english
		Merge to Proud.Exception
		- It handles error that occur from user code. 
		- User realize things that user needed. 
		- You can use Exceptiontype that obtain Exception object. 
		- It process _com_error, void*, std::exception, etc. Also there is OnUnhandledException() that handle catch(...) 
		- void* can obtain exceptional object type by casting. For example, it uses obtaining MFC CException. 

 		\~chinese
		��?? Proud.Exception%��
		- ����?�����?��??����??��
		- ��???������?ʦ��
		- ��ExceptionType?����?Exception?��?��ݻ?�⡣
		- ?����ݻ��_com_error, void*, std::exception��
		���?��catch(...)��OnUnhandledException()��
		- void*ʦ�?����?��?��??��⥡������������MFC CException%��

		\~japanese
		Proud.Exception ������
		- �����ܪ˫�?��?��?�ɪ����뫨��?��?�⪷�ު���
		- ��?��?����驪ʪ��Ȫ�?�ު�����ު��Ǫ���
		- ExceptionType����?Exception���֫������Ȫ�����Ū����ު��Ǫ���
		- _com_error, void*, std::exception �ʪɪ����?�⪷�ު���
		�ު���catch(...)��?�⪹��OnUnhandledException()�⪢��ު���
		- void*�����⫪�֫������ȪΫ����ת򫭫㫹�ƫ��󫰪����������ު���?��MFC CException�������몳�Ȫ��Ū��ު���
		\~
		*/
		virtual void OnException(const Exception &e) = 0;

		/** 
		\~korean
		RMI�� ȣ���� �������� Attach�� Stub �߿� �����ϴ� RMI�� ���� ������ �̰��� �ݹ�ȴ�.

		\~english
		When RMI is called but there is no RMI in Stub that attached then this will callback.

		\~chinese
		��RMI��У��ӣ��?��??��Attach��Stub��RMI��?��??����?��

		\~japanese
		RMI�������󪷪�����ު�������Attach���쪿Stub�Ϊ���??����RMI���絛����Ъ��쪬��?��Ыë�����ު���
		\~
		*/
		virtual void OnNoRmiProcessed(RmiID rmiID) = 0;

		/** 
		\~korean
		����ڰ� ������ �޽����� �����ϸ� �� �Լ��� �ݹ�˴ϴ�. ����ڴ� �� �Լ��� �������̵��ؼ� ���ϴ� ó���� �� �� �ֽ��ϴ�.
		�ڼ��� ���� <a target="_blank" href="http://guide.nettention.com/cpp_ko#send_user_message" >RMI�� ���� �Ⱦ��� ����� ���� �޽����� �ְ� �ޱ�</a> �� �����Ͻʽÿ�.
		- Visual Studio 2005 �̻��� �����Ϸ������� override Ű���� ����� �����մϴ�. 
		
		\param sender �޽����� �۽��� ȣ��Ʈ�Դϴ�.
		\param rmiContext ���� �ΰ� �����Դϴ�.
		\param payload ���ŵ� �޽��� �����Դϴ�.
		\param payloadLength ���ŵ� �޽��� ������ ����(����Ʈ)�Դϴ�.

		\~english
		This function will callback once user received defined message. Then user can process as overriding this function.
		Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#send_user_message" >Exchanging user-defined message without using RMI at all</a> for more detail.
		- We recommend to use override keyword on Visual Studio 2005 or above.

		\param sender Host that sent message.
		\param rmiContext Additional information of receiving
		\param payload Main text of received message.
		\param payloadLength Length(byte) of received main text.

		\~chinese
		�����?��?��������?�����?����?����?ʦ��������?��?�������?�⡣
		??��??��<a target="_blank" href="http://guide.nettention.com/cpp_zh#send_user_message" >����������RMI��?��?��?����</a>%��
		- �Visual Studio 2005�߾������������?����override??��

		\param sender ?�������������
		\param rmiContext ���ݾʥ���ӡ�
		\param payload ��������������.
		\param payloadLength ��������������?����byte����

		\~japanese
		��?��?������������ë�?�������᪹��Ъ���??����?��Ыë�����ު�����?��?�Ϫ���??��?��?�髤�ɪ����ê�?��򪹪몳�Ȫ��Ǫ��ު���
		�٪����ϡ�\ref send_user_message��?�Ϊ���������
		- Visual Studio 2005 �߾�Ϋ���ѫ���?�Ǫ�override��?��?�ɪ����Ī�?�᪷�ު��� 

		\param sender ��ë�?�������᪷���۫��ȪǪ���
		\param rmiContext ������ʥ���êǪ���
		\param payload ���᪵�쪿��ë�?���������Ǫ���
		\param payloadLength ���᪵�쪿��ë�?���������������Ы��ȣ��Ǫ���
		\~
		*/
		virtual void OnReceiveUserMessage(HostID sender, const RmiContext &rmiContext, uint8_t* payload, int payloadLength);

		/** 
		\~korean
		���� �ð����� user worker thread pool���� �ݹ�Ǵ� �Լ��Դϴ�. <a target="_blank" href="http://guide.nettention.com/cpp_ko#server_timer_callback" >�������� Ÿ�̸� ���� RMI �̺�Ʈ ó���ϱ�</a> ����Դϴ�. 		
		\param context CStartServerParameter.m_timerCallbackContext ���� �Էµ� ���� �����մϴ�.

		\~english
		Function called back at user worker thread pool periodically. This is a <a target="_blank" href="http://guide.nettention.com/cpp_en#server_timer_callback" >Managing Timer loop RMI Event from server</a> function.		
		\param context same as the value entered at CStartLanServerParameter.m_timerCallbackContext

		\~chinese
		��̰��ӫ??�user worker thread pool��?����?��<a target="_blank" href="http://guide.nettention.com/cpp_zh#server_timer_callback" >���?��?��Timer Loop��RMI��Event</a> ������
		\param context ?� CStartLanServerParameter.m_timerCallbackContext%?����?���ҡ�

		\~japanese
		������઴�Ȫ�user worker thread pool�ǫ�?��Ыë������??�Ǫ���\ref server_timer_callbackѦ���Ǫ���
		\param context CStartServerParameter.m_timerCallbackContext���������쪿�����Ҫ��Ǫ���
		\~
		*/
		virtual void OnTick(void* /*context*/){}	
		
		/** 
		\~korean
		RMI ȣ�� �Ǵ� �̺�Ʈ �߻����� ���� user worker���� callback�� ȣ��Ǳ� ������ ȣ��˴ϴ�.
		���α׷� ���� ���� ������ ���� ����ϼŵ� �˴ϴ�.

		\~english
		It calls before calling callback at user worker because of RMI calling or event occuring.
		You can use it for measuring program running performance.

		\~chinese
		RMI ��У�����event��?�棬�user worker��callback����У������У��
		�ʦ�?��?������?����������ġ�

		\~japanese
		RMI�����󪷪ު��ϫ��٫��?��˪�ê�user worker��callback�������󪵪������������󪵪�ު���
		�׫����?���������ҪΪ�����Ūêƪ��ު��Ǫ���
		\~
		*/
		virtual void OnUserWorkerThreadCallbackBegin(CUserWorkerThreadCallbackContext* /*ctx*/){}
		/** 
		\~korean
		RMI ȣ�� �Ǵ� �̺�Ʈ �߻����� ���� user worker���� callback�� ������ ���Ŀ� ȣ��˴ϴ�.
		���α׷� ���� ���� ������ ���� ����ϼŵ� �˴ϴ�.

		\~english
		It calls right after calling callback at user worker because of RMI calling or event occuring.
		You can use it for measuring program running performance.

		\~chinese
		RMI ��У�����event?�棬�user worker��callback����������У��
		�ʦ����?������?������۰����

		\~japanese
		RMI�����󪷪ު��ϫ��٫��?��˪�ê�user worker��callback���꫿?�󪷪������������󪵪�ު���
		�׫����?���������ҪΪ�����Ūêƪ��ު��Ǫ���
		\~
		*/
		virtual void OnUserWorkerThreadCallbackEnd(CUserWorkerThreadCallbackContext* /*ctx*/){}

	};

	/**  @} */



	/** Add your event handler to these member objects. 
	
	Example:
	\code
	CNetClient* c = CNetClient::Create();
	c->OnError = [&](ErrorInfo* e)->{
		// Your event handler code here.
	};
	\endcode
	*/
	class HasCoreEventFunctionObjects
	{
	public:
		/// See Proud.INetCoreEvent.OnError for details.
		LambdaBaseHolder_Param1<void, ErrorInfo *> OnError;
		/// See Proud.INetCoreEvent.OnException for details.
		LambdaBaseHolder_Param1<void, const Exception&> OnException;
		/// See Proud.INetCoreEvent.OnInformation for details.
		LambdaBaseHolder_Param1<void, ErrorInfo*> OnInformation;
		/// See Proud.INetCoreEvent.OnNoRmiProcessed for details.
		LambdaBaseHolder_Param1<void, RmiID> OnNoRmiProcessed;
		/// See Proud.INetCoreEvent.OnReceiveUserMessage for details.
		LambdaBaseHolder_Param4<void, HostID, const RmiContext&, uint8_t*, int> OnReceiveUserMessage;
		/// See Proud.INetCoreEvent.OnWarning for details.
		LambdaBaseHolder_Param1<void, ErrorInfo*> OnWarning;
		/// See Proud.INetCoreEvent.OnTick for details.
		LambdaBaseHolder_Param1<void, void*> OnTick;
		/// See Proud.INetCoreEvent.OnUserWorkerThreadCallbackBegin for details.
		LambdaBaseHolder_Param0<void> OnUserWorkerThreadCallbackBegin;
		/// See Proud.INetCoreEvent.OnUserWorkerThreadCallbackEnd for details.
		LambdaBaseHolder_Param0<void> OnUserWorkerThreadCallbackEnd;
	};
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
