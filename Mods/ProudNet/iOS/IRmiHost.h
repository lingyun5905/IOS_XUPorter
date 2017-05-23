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

//#define TEST_DISCONNECT_CLEANUP �׽�Ʈ �뵵


#include "BasicTypes.h"
//#include "ConnectParam.h"
#include "HostIDArray.h"
#include "AddrPort.h"
#include "Enums.h"
#include "EncryptEnum.h"
#include "RMIContext.h"
#include "ErrorInfo.h"
#include "LambdaEventHandler.h"

#define PN_DEPRECATED /*__declspec(deprecated) */

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4324)
#endif

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif

	/** \addtogroup net_group
	*  @{
	*/

	class CMessage;	
	class CSendFragRefs;
	class ErrorInfo;
	class IRmiProxy;
	class IRmiStub;
	class RmiContext;
	class MessageSummary;
	class FavoriteLV;

	struct SendOpt;

	/** 
	\~korean
	\brief ProudNet RMI�� �����ϴ� ��Ʈ��ũ ȣ��Ʈ �������̽��Դϴ�.
	������ �� Ŭ������ ���� ����� �ʿ䰡 �����ϴ�. 

	\~english
	\brief ProudNet Network host interface that is referred by RMI.
	User does not have to use this class directly.

	\~chinese
	\brief ProudNet RMI?����??���ͣ����
	��?�������������?��

	\~japanese
	\brief ProudNet RMI��?�Ϊ���ͫëȫ�?���۫��ȫ���?�ի�?���Ǫ���
	��?��?�Ϫ��Ϋ��髹�������Ū���驪�����ު���
	\~
	*/
	class IRmiHost
	{
		friend class IRmiProxy;
	public:
		virtual ~IRmiHost() {}

		/** 
		\~korean
		PIDL �����Ϸ��� ����� �� proxy�� �� ��ü�� ����Ѵ�. 

		\~english
		Registers proxy among the results of PIDL compiler to this object

		\~chinese
		PIDL ??����?ڪ����proxy��?���?�ڡ�

		\~japanese
		PILD����ѫ���?��̿��ڪ�Ϊ���proxy�򪳪Ϋ��֫������Ȫ���?���ު���
		\~
		*/
		virtual void AttachProxy(IRmiProxy* proxy) = 0;
		// no-throw version for UE4, etc.
		void AttachProxy(IRmiProxy *proxy, ErrorInfoPtr& outError);

		/** 
		\~korean
		PIDL �����Ϸ��� ����� �� stub�� �� ��ü�� ����Ѵ�. 

		\~english
		Registers stub among the results of PIDL compiler to this object

		\~chinese
		PIDL ??��?ڪ����stub��?���?�ڡ�

		\~japanese
		PILD����ѫ���?��̿��ڪ�Ϊ���stub�򪳪Ϋ��֫������Ȫ���?���ު���
		\~
		*/
		virtual void AttachStub(IRmiStub* stub) = 0;
		// no-throw version for UE4, etc.
		void AttachStub(IRmiStub* stub, ErrorInfoPtr& outError);
		/** 
		\~korean
		AttachProxy �� �ݴ�μ�, �� ��ü���� ��� ������ �Ѵ�. 

		\~english
		As opposite to AttachProxy, this object cancels the registration.

		\~chinese
		��AttachProxy�����㣬�����?������?��

		\~japanese
		AttachProxy����?�Ȫ��ơ����Ϋ��֫������Ȫ���?���򪷪ު���
		\~
		*/
		virtual void DetachProxy(IRmiProxy* proxy) = 0;
		// no-throw version for UE4, etc.
		void DetachProxy(IRmiProxy* proxy, ErrorInfoPtr& outError);
		/** 
		\~korean
		AttachStub �� �ݴ�μ�, �� ��ü���� ��� ������ �Ѵ�. 

		\~english
		As opposite to AttachStub, this object cancels the registration.

		\~chinese
		��AttachStub�����㣬�����?������?��

		\~japanese
		AttachStub����?�Ȫ��ơ����Ϋ��֫������Ȫ���?���򪷪ު���
		\~
		*/
		virtual void DetachStub(IRmiStub* stub) = 0;
		// no-throw version for UE4, etc.
		void DetachStub(IRmiStub* stub, ErrorInfoPtr& outError);

		// Set any value you wish. For example, owner of this object.
		virtual void SetTag(void* value) = 0;
		virtual void* GetTag() = 0;

#ifdef SUPPORTS_LAMBDA_EXPRESSION
	public:
		/**
		
		����� ���� �Լ��� ���ٽ��� �񵿱�� �����մϴ�. �ڼ��� ���� \page run_async�� �����Ͻʽÿ�.

		\param taskOwner � Host�� ���� �񵿱� ���������� ����ŵ�ϴ�.
		\param func �Լ� Ȥ�� ���ٽ��Դϴ�. �Ϲ������� ���ٽ��� ����� �����մϴ�.
		\return taskOwner�� ��ȿ�ϸ� true�� �����մϴ�. false�� ������ ��� func �� ������� �ʽ��ϴ�.
		*/
		inline bool RunAsync(HostID taskOwner, const std::function<void()> &func)
		{
			return RunAsync(taskOwner, new Lambda_Param0<void>(func));
		}

#endif
		// ���ٽ� ������ �����Ϸ������� �� ������, ���� �Լ��� ���� ����̹Ƿ�, 
		// ���Ǻ� ������ �� �ٱ��� �־�� �Ѵ�.
		virtual bool RunAsync(HostID taskOwner, LambdaBase_Param0<void>* func) = 0;

	protected:
		// ���� �뵵 �Լ��̴�. ����ڴ� ȣ������ �� ��.
		// �� �Լ��� ���� ������ CNetClientImpl�� ����
		virtual bool Send(const CSendFragRefs &sendData,
			const SendOpt& sendContext,
			const HostID *sendTo, int numberOfsendTo, int &compressedPayloadLength,
			FavoriteLV& favoriteLV) = 0;

	public:

		/** 
		\~korean
		simple packet mode�� ����ϰ� �ִ��� Ȯ���Ѵ�.

		\~english
		Check to see whether simple packet mode is being used. 

		\~chinese
		??��������simple packet mode��

		\~japanese
		simple packet mode���Ūêƪ��몫�����㪷�ު���
		\~
		*/
		virtual bool IsSimplePacketMode() = 0;

		/** 
		\~korean
		���� �Լ�. ����ڴ� ȣ�� ����. 

		\~english
		Internal function. User must not call this.

		\~chinese
		?ݻ��?����?�����У��

		\~japanese
		?ݻ??����?��?�����������
		\~
		*/
		virtual void ShowError_NOCSLOCK( ErrorInfoPtr errorInfo ) = 0;
		virtual void ShowNotImplementedRmiWarning(const PNTCHAR* RMIName) = 0;
		virtual void PostCheckReadMessage(CMessage& msg, const PNTCHAR* RMIName) = 0;

		/** 
		\~korean
		���� �Լ�. ����ڴ� ȣ�� ����. 

		\~english
		Internal function. User must not call this.

		\~chinese
		?ݻ��?����?�����У��

		\~japanese
		?ݻ??����?��?�����������
		\~
		*/
		virtual void ConvertGroupToIndividualsAndUnion( int numberOfsendTo, const HostID * sendTo, HostIDArray& output, FavoriteLV& favoriteLV) = 0;

		virtual CriticalSection& GetCriticalSection() = 0;

#ifdef VIZAGENT
		virtual void EnableVizAgent(const PNTCHAR* vizServerAddr, int vizServerPort, const String &loginKey) = 0;

		virtual void Viz_NotifySendByProxy(const HostID* remotes, int remoteCount, const MessageSummary &summary, const RmiContext& rmiContext) = 0;
		virtual void Viz_NotifyRecvToStub(HostID sender, RmiID RmiID, const PNTCHAR* RmiName, const PNTCHAR* paramString) = 0;
#endif
	};

	/** 
	\~korean
	\brief clientWorker�� ������ ��� ����ü. 

	\~english
	\brief Structure that contain information of clientWorker

	\~chinese
	\brief ����clientWorker������?��?��

	\~japanese
	\brief clientWorker�����ê������ϰ��? 
	\~
	*/
	class CClientWorkerInfo
	{
	public:

		//bool m_isWorkerThreadEnded;

		int m_connectCallCount;

		int m_disconnectCallCount;

		ConnectionState m_connectionState;

		int m_finalWorkerItemCount;

//		int64_t m_lastTcpStreamTimeMs;

		int64_t m_currentTimeMs;

		int m_peerCount;
#if !defined(_WIN32)
		pthread_t m_workerThreadID;
#else
		uint32_t m_workerThreadID;
#endif
	};

	/** 
	\~korean
	\brief socket�� ������ ��� ����ü�Դϴ�.

	\~english
	\brief Structure that contain information of socket

	\~chinese
	\brief ����socket������?��?��

	\~japanese
	\brief socket�����ê������ϰ��?�Ǫ���
	\~
	*/
	class CSocketInfo
	{
	public:
		/** 
		\~korean
		TCP socket handle�Դϴ�. �������� ������ ���� socket�Դϴ�. 

		\~english
		It is TCP socket handle. This socket is for connecting to server

		\~chinese
		��TCP socket handle��?��?��?��?����socket��

		\~japanese
		TCP socket handle�Ǫ�����?��?�Ȫ���?�Ϊ����socket�Ǫ���
		\~
		*/
		SOCKET m_tcpSocket;

		/** 
		\~korean
		UDP socket handle�Դϴ�. ���� Ȥ�� P2P peer���� ������ ���� socket�Դϴ�. 

		\~english
		It is UDP socket handle. This socket is for connecting to server or P2P peer.

		\~chinese
		��UDP socket handle��?��?��?�����P2P peer��?����socket��

		\~japanese
		UDP socket handle�Ǫ�����?��?�ު���P2P peer�Ȫ���?�Ϊ����socket�Ǫ��� 
		\~
		*/
		SOCKET m_udpSocket;

		inline CSocketInfo()
		{
			m_tcpSocket = InvalidSocket;
			m_udpSocket = InvalidSocket;
		}
	};

	/** 
	\~korean
	\brief 1���� �����忡 ���� ������ ����� �ִ� ����ü. 

	\~english
	\brief Construct contains information of 1 thread

	\~chinese
	\brief ����?��??��������?��?��

	\~japanese
	\brief 1���Ϋ���ëɪ�?�������ê����êƪ���ϰ��? 
	\~
	*/
	class CThreadInfo
	{
	public:
		/**
		\~korean
		Thread�� ID 

		\~english
		ID of thread

		\~chinese
		Thread��ID��

		\~japanese
		Thread��ID 
		\~
		*/
		uint64_t m_threadID;

		/**
		\~korean
		Thread�� Handle 

		\~english
		Handle of thread

		\~chinese
		Thread��Handle��

		\~japanese
		Thread��Handle 
		\~
		*/
#if defined(_WIN32)
		HANDLE m_threadHandle;
#else
		pthread_t m_threadHandle;
#endif
	};

	/** 
	\~korean
	\brief ����� ���α׷����� ������ �����ϴ� �Է� �Ķ���� 

	\~english
	Input parameter delivered from \brief user program to engine

	\~chinese
	\brief ���?�����飬������??��?��??��

	\~japanese
	\brief ��?��?�׫����ǫ��󫸫��?ӹ���������ѫ��?��? 
	\~
	*/
	class CApplicationHint 
	{
	public:
		/** 
		\~korean
		����ڰ� ������, ���� ���α׷��� ������ ����Ʈ�Դϴ�. 

		\~english
		Frame rate of application program measured by user

		\~chinese
		��??���ܣ�?��������?���㡣

		\~japanese
		��?��?�����Ҫ������׫꫱?�����׫����Ϋի�?���?�ȪǪ��� 
		\~
		*/
		double m_recentFrameRate; 

		CApplicationHint()
		{
			m_recentFrameRate = 0;
		}
	};

	/** 
	\~korean
	\brief ��� ����. ������̳� ���� ������ ���� 

	\~english
	\brief statistics information. For debugging or performance test

	\~chinese
	\brief ??���ӡ�?��??������?�ҡ�

	\~japanese
	\brief ��ͪ���á��ǫЫë��󫰪Ȫ��������ҪΪ���Ϊ�ΪǪ���
	\~
	*/
	class ReliableUdpHostStats
	{
	public:
		// ���� ������ ����ִ� ������ ����, ���� �̾Ƴ��� ���� ��Ʈ�� ũ��, ������ ���� ��Ʈ�� ũ��, ������ ���� ������ ����, �ֱٿ� ������ �޴� ������ �ӵ�
		int m_receivedFrameCount, m_receivedStreamCount, m_totalReceivedStreamLength, m_totalAckFrameCount;
		int m_senderWindowLength;
		int m_senderWindowMaxLength;
		int m_senderWindowWidth;	// first~last�� number ����
		int m_expectedFrameNumberToReceive;
		int m_nextFrameNumberToSend;

		/** 
		\~korean
		�۽�ť�� �׿��ִ� ��Ʈ�� ũ��

		\~english
		Stream size that stacked at sending queue

		\~chinese
		��?�?��queue��׵��᳡�

		\~japanese
		���᫭��?���ݪ�êƪ��뫹�ȫ�?�૵����
		\~
		*/
		int m_sendStreamCount;

		/** 
		\~korean
		�ʼ۽� ������ ����ִ� ������ ����

		\~english
		Number of frame that located in first sending window

		\~chinese
		����?��?��???��

		\~japanese
		�����᫦����ɫ������êƪ���ի�?��?
		\~
		*/
		int m_senderWindowDataFrameCount;
		
        /**
		\~korean
		��۽� ������ ����ִ� ������ ����

		\~english
		Number of frame that located in resend window

		\~chinese
		���?��?��???��

		\~japanese
		����᫦����ɫ������êƪ���ի�?��?
		\~
		*/
		int m_resendFrameCount;

		/** 
		\~korean
		������ ���� ��Ʈ�� ũ��

		\~english
		Total size of sent stream

		\~chinese
		���?����׵��᳡�

		\~japanese
		����ު���ê����ȫ�?�૵����
		\~
		*/
		int m_totalSendStreamLength;

		/** 
		\~korean
		������ �ʼ۽��� ������ ����
		- �ʼ۽��� ������ ������ ���� ������ ��۽��� ������ ������ ����ġ�� �����ϸ� P2P Reliable �޽�¡�� �� �̷������ ������ �ǹ��Ѵ�.

		\~english
		Total number of first send frame
		- If number of resent frame is dramarically increased compare to number of first send frame, it mean, it does not working P2P Reliable messaing unstably

		\~chinese
		������?����???��
		- �������?����???�����?����????����ʥ��?����ګ�P2P Reliable messaging?��?����������

		\~japanese
		����ު������᪷���ի�?��?
		- �����᪷���ի�?��?����١�����ު�����᪷���ի�?��?��?ʥ��Φ�����顢P2P Reliable��ë�?���󫰪��誯�����ʪ����Ȫ���ګ���ު���
		\~
		*/
		int m_totalFirstSendCount;

		/** 
		\~korean
		������ ��۽��� ������ ����

		\~english
		Total number of resent frame

		\~chinese
		�����?����???��

		\~japanese
		����ު�����᪷���ի�?��?
		\~
		*/
		int m_totalResendCount;

		/// if zero, it means nothing to show, or the number is zero indeed.
		int m_senderWindowLastFrame;

		int m_totalReceiveDataCount;
		int m_lastReceivedAckNumber;
		String ToString();
	};

	// ����: �̰� ���� �����忡�� �ʹ� ���� ������ ��,��Ƽ�ھ� ȯ�濡�� ���κ���󿡼��� ������ ���ߵǴ���.
	class CTestStats
	{
	public:
		static double TestAllowedMaxSendSpeed;
		static double TestRecentReceiveSpeed;
		static double TestRecentSendSpeedAtReceiverSide;
	};

	// ����: �̰� ���� �����忡�� �ʹ� ���� ������ ��,��Ƽ�ھ� ȯ�濡�� ���κ���󿡼��� ������ ���ߵǴ���.
	class CTestStats2
	{
	public:
		bool m_C2SReplyRecentReceiveSpeedDone;
		bool m_C2CRequestRecentReceiveSpeedDone;
		bool m_C2CReplyRecentReceiveSpeedDone;

		CTestStats2()
		{
			m_C2SReplyRecentReceiveSpeedDone = false;
			m_C2CRequestRecentReceiveSpeedDone = false;
			m_C2CReplyRecentReceiveSpeedDone = false;
		}
	};

	/** 
	\~korean
	Disconnect()���� ����ϴ� �����Դϴ�.

	\~english TODO:translate needed.
	This is the factor used in Disconnect()

	\~chinese
	Disconnect()����������
	\~japanese
	Disconnect()���Ū����Ǫ���
	\~
	*/
	class CDisconnectArgs
	{
	public:
		/**
		\~korean
		graceful disconnect�� �����ϴµ� �ɸ��� �ִ� �ð��Դϴ�.
		�� �ð��� �Ѿ�� Proud.CNetClient.Disconnect()�� ������ return�ϰ� �ǰ�, ���������� Ŭ���̾�Ʈ�� ���� ������ 
		��� �ν����� ���մϴ�. 
		�� �ʿ��� ��찡 �ƴϸ� �� ���� �������� ���ʽÿ�. 

		\~english TODO:translate needed.
		If you exceed this time, Proud.CNetClient.Disconnect() unconditionally returns and the server cannot immediately recognize the disconnection of the client. 
		Unless absolutely necessary, do not change this value. 

		\~chinese
		?��graceful disconnect��������???��
		���������??��? Proud.CNetClient.Disconnect()%???��return����?��?����ءʾ??��?Ӯ��?����𶡣
		�����������?��???���?��

		\~japanese
		graceful disconnect����������˪�������������Ǫ���
		�������બ?Φ������Proud.CNetClient.Disconnect()����?��ǫ꫿?�󪵪�ơ���?��?�Ǫϫ��髤����Ȫ���?�������������۪Ǫ��ʪ��ʪ�ު��� 
		������驪�����ǪϪʪ���С���������?�ڪ��ʪ��Ǫ���������
		\~
		*/
		int64_t m_gracefulDisconnectTimeoutMs;

		/**
		\~korean
		�̰����� Disconnect���� ����ϴ� Sleep �ð��� ������ �� �ֽ��ϴ�.

		\~english TODO:translate needed.
		With this, you can adjust the sleep time waiting during disconnection. 

		\~chinese TODO:translate needed.
		��???ʦ�?��???������Sleep??��

		\~japanese TODO:translate needed.
		�����Disconnect������Ѧ����Sleep�������ｪ��몳�Ȫ��Ǫ��ު���
		\~
		*/
		uint32_t m_disconnectSleepIntervalMs;

		/**
		\~korean
		�������� Ŭ���̾�Ʈ ���� ���� ������ �̰��� ���� ������ �� �ֽ��ϴ�.

		\~english TODO:translate needed.
		In the server, you can transmit the client disconnection reason through this. 

		\~chinese
		��?��?��?�?����?Ӯ?�������ס�
		\~japanese
		��?��?�ǫ��髤�������?������릪򡢪�����ת�?�ꪹ�몳�Ȫ��Ǫ��ު���
		\~
		*/
		ByteArray m_comment;

		CDisconnectArgs();
	};

	extern StringA policyFileText;

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif

	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#ifdef _MSC_VER
#pragma warning(pop)
#endif