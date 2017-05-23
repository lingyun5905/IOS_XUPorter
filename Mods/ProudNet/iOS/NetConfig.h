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

#include "FakeClr.h"
#include "Enums.h"
#include "pnstdint.h"

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

	/**
	\~korean
	ProudNet ���� �������� ���� �����̴�.
	- ���� ����ȭ�Ǿ� ���� ���� ������ �Ժη� �������� �� ��.

	\~english
	ProudNet related setting values
	- DO NOT change the values that are separately documented!

	\~chinese
	ProudNet ��?��??��?��
	- ?����?����?���������ǡ�

	\~japanese
	ProudNet��?֧����??���������Ǫ���
	- ܬ������������ƪ��ʪ����ϡ��⢪�?�ڪ��ʪ����ȡ�
	\~

	*/
	class CNetConfig
	{
	public:
		//////////////////////////////////////////////////////////////////////////
		// socket
		PROUD_API static int UdpIssueRecvLength;
		PROUD_API static int UdpRecvBufferLength_Client;
		PROUD_API static int UdpRecvBufferLength_Server;
		PROUD_API static int UdpRecvBufferLength_ServerStaticAssigned;
		PROUD_API static int TcpIssueRecvLength;
		PROUD_API static int TcpRecvBufferLength;
		PROUD_API static int TcpSendBufferLength;
		PROUD_API static int UdpSendBufferLength_Client;
		PROUD_API static int UdpSendBufferLength_Server;
		PROUD_API static int UdpSendBufferLength_ServerStaticAssigned;
		PROUD_API static bool EnableSocketTcpKeepAliveOption;
		PROUD_API static int64_t ReliableUdpHeartbeatIntervalMs_Real;
		PROUD_API static int64_t ReliableUdpHeartbeatIntervalMs_ForDummyTest;

		PROUD_API static int64_t TcpSocketConnectTimeoutMs;
		PROUD_API static int64_t ClientConnectServerTimeoutTimeMs;

		//////////////////////////////////////////////////////////////////////////
		// time
		PROUD_API static int64_t DefaultConnectionTimeoutMs;
		PROUD_API static int64_t MinConnectionTimeoutMs;
		PROUD_API static int64_t MaxConnectionTimeoutMs;
		PROUD_API static uint32_t WaitCompletionTimeoutMs;
		PROUD_API static uint32_t HeartbeatIntervalMs;
		PROUD_API static uint32_t GarbageCollectIntervalMs;

		PROUD_API static int64_t ServerHolepunchIntervalMs;
		PROUD_API static int64_t UdpHolepunchIntervalMs;
		PROUD_API static int64_t ServerUdpRepunchIntervalMs;
		PROUD_API static int ServerUdpRepunchMaxTrialCount;
		PROUD_API static int ServerUdpHolepunchMaxTrialCount;
		PROUD_API static int64_t P2PHolepunchIntervalMs;
		PROUD_API static int P2PShotgunStartTurn;
		PROUD_API static int P2PHolepunchMaxTurnCount;
		PROUD_API static int64_t PurgeTooOldUnmatureClientTimeoutMs;
		PROUD_API static int64_t PurgeTooOldAddMemberAckTimeoutMs;
		PROUD_API static int64_t DisposeGarbagedHostsTimeoutMs;
		PROUD_API static int64_t RemoveTooOldUdpSendPacketQueueTimeoutMs;
		PROUD_API static int64_t AssembleFraggedPacketTimeoutMs;
		PROUD_API static bool EnablePacketDefragWarning;
		PROUD_API static int64_t GetP2PHolepunchEndTimeMs();
		PROUD_API static int ShotgunTrialCount;
		PROUD_API static int ShotgunRange;

		PROUD_API static int64_t UnreliablePingIntervalMs;
		PROUD_API static int64_t ReliablePingIntervalMs;

		PROUD_API static bool UseReportRealUdpCount;
		PROUD_API static int64_t ReportRealUdpCountIntervalMs;

		PROUD_API static uint32_t LanClientHeartbeatIntervalMs;

		PROUD_API static int64_t LanPeerConnectPeerTimeoutTimeMs;
		PROUD_API static int64_t PurgeTooOldJoiningTimeOutIntervalMs;
		PROUD_API static int64_t RemoveLookaheadMessageTimeoutIntervalMs;

		PROUD_API static int RecyclePairReuseTimeMs;
		PROUD_API static int64_t GarbageTooOldRecyclableUdpSocketsIntervalMs;
		PROUD_API static int ServerUdpSocketLatentCloseMs;

		PROUD_API static int64_t TcpInDangerThresholdMs;
		PROUD_API static int64_t TcpUnstableDetectionWaitTimeMs;
		PROUD_API static int64_t PauseUdpSendDurationOnTcpInDangerMs;

		PROUD_API static int64_t RecentAssemblyingPacketIDsClearIntervalMs;

		PROUD_API static int64_t AutoConnectionRecoveryClientTimeoutMs;

		/**
		\~korean
		��� ��� Remote ���� IssueSend�� ��Ƽ� �۽��Ѵ�.
		- �⺻���� 3ms �̴�.
		- �̰��� ��� ������ �۽ŷ��� ����� ������ ���ǿ��! (3ms ~ 10ms)���̰� �����ϴ�.

		\~english
		It sends IssueSend of all other Remotes
		- Defualt value is 3ms
		- It may occur lag of sending, if you set too longe. It will suitable between 3ms ~ 10ms.

		\~chinese
		�����?۰Remote��IssueSend����?�����ӡ�
		- ��??��3ms��
		- ?���������????����?��?ʦ��??��?��?ط?�ڡ���3ms ~ 10ms����??��?��

		\~japanese
		��ƪ����Remote��IssueSend��������᪷�ު���
		- ��������3ms�Ǫ���
		- ����������������������ë���?�檹�몳�Ȫ�����ު��ΪǪ���򪯪�����!(3ms~10ms)�બ��?�Ǫ���
		\~
		*/
		PROUD_API static int EveryRemoteIssueSendOnNeedIntervalMs;

		__forceinline static int64_t GetFallbackServerUdpToTcpTimeoutMs()
		{
			// ���߿�, UdpPingInterval�� ��������. C-S UDP�� �����ϰ� P2P UDP�� �����ϰ� ������ �����ϸ� �������� �Ҿ��Ѱ� ���Ѱ��� �̹Ƿ�.
			assert(UnreliablePingIntervalMs > 0);

			// ���� 3�� ���� ���� �� �޴´ٴ� ���� 80% �̻� ��Ŷ �ν���� �ǹ�. �� ������ Ȧ��Ī �Ǿ� �־ �����̴�.
			// ���� 10->4 ����.
			return UnreliablePingIntervalMs * 4;
		}

		__forceinline static int64_t GetFallbackP2PUdpToTcpTimeoutMs()
		{
			// ���߿�, UdpPingInterval�� ��������. C-S UDP�� �����ϰ� P2P UDP�� �����ϰ� ������ �����ϸ� �������� �Ҿ��Ѱ� ���Ѱ��� �̹Ƿ�.
			assert(UnreliablePingIntervalMs > 0);

			// ���� 3�� ���� ���� �� �޴´ٴ� ���� 80% �̻� ��Ŷ �ν���� �ǹ�. �� ������ Ȧ��Ī �Ǿ� �־ �����̴�.
			// ���� 10->4 ����.
			// GetFallbackServerUdpToTcpTimeoutMs�� GetFallbackP2PUdpToTcpTimeoutMs�� ���� ���� ���̾��. 
			// C-S UDP�� �����ϰ� P2P UDP�� �����ϰ� ������ �����ϸ� �������� �Ҿ��Ѱ� ���Ѱ��� �̹Ƿ�.
			return UnreliablePingIntervalMs * 4;
		}

		// TCP �� Ÿ�� �ƿ��� �ɸ��� �ð�
		// ����: TCP �� Ÿ�� �ƿ��� �����ϱ� ���� ���� �ְ� �޴� �ֱ�� CNetClientImpl::GetReliablePingTimerInterval ���� ����.
		static int DefaultNoPingTimeoutTimeMs;

		/**
		\~korean
		������ȹ��(?)
		- �ʹ� �۰� ������ ���� ��ȭ�� �۾Ƽ� ���� ���� ������ ���� �غ� ���ϰ�
		�ʹ� ũ�� ������ ���� ��ȭ�� Ŀ�� ��ü�� ���� �߰����� �����ϱ� ��ƴ�.

		\~english
		Linear planning(?)
		- If too small then hard to overcome error from exisiting value to its change being too small,
		If too big then hard to keep the mid-point value due to its change being too big.

		\~chinese
		?��??��������
		- ?�����?����??��?����������к������?��??��������?��??�����???���??����?�á�

		\~japanese
		����ͪ?��(?)
		- ���ު�˪�ᳪ������������?����ᳪ�����?�����Ϋ���?����?��?���ƪ��몳�Ȫ��Ǫ��������ު�˪��ު����������?�����ު�������?�����������ê��򥪷�˪����Ǫ���
		\~
		*/
		PROUD_API static int LagLinearProgrammingFactorPercent;

		PROUD_API static int StreamGrowBy;

		PROUD_API static int InternalNetVersion;

		PROUD_API static int InternalLanVersion;

		/** \~korean �� �Լ��� ProudNet Version ������ ��ȯ�մϴ�.
		\~english This function returns ProudNet Version information.
		\~chinese ���?����ProudNet Version����
		\~japanese ����??�� ProudNet Version ���ê��������ު���
		\~ */
		PROUD_API static Proud::String GetVersion();

		PROUD_API static int MtuLength;

		PROUD_API static int64_t ElectSuperPeerIntervalMs;

		/**
		\~korean
		�� ���� �޽����� ���� �� �ִ� �ִ� ũ��
		- ������ ���� �ƴϴ�. �����ڴ� �� ���� �������� �����ص� �ȴ�.
		- �� ���� CNetServer �� CNetClient ��ü�� �����ϱ� ���� �̸� �����ؾ� �Ѵ�.
		- ������ �����ؼ��� �������� �ʴ� ���� �����Ѵ�. ��, ������ ��ſ��� 1���� �޽����� 1MB�� �Ѿ�� �����̶�� ���ܴ�.
		- ��ŷ�� Ŭ���̾�Ʈ���� �߸��� �޽��� ũ�⸦ ������ ��츦 �����Ϸ��� CNetServer.SetMessageMaxLength �� ���� ���� �����Ѵ�.

		\~english
		The maximum size of a message can have
		- Not a fixed value. Developer can change this at any time.
		- This value must be set previously before creating the CNetServer object or CNetClient object.
		- However, it is not recommended to change this. But, there can be an exception when a message has a size around 1 MB among server communications.
		- To stop a hacked client sending incorrect message size, it is recommended to use CNetServer.SetMessageMaxLength.

		\~chinese
		��?������?����������᳡�
		- ����ͳ��?��??�??ʦ������?��
		- �?������ CNetServer%��� CNetClient%?������?�ǡ�
		- ӣ����??��������ǡ���?���?����?������������?1MB�������?���⡣
		- �������client����?��?��??�����������?��?��?���� CNetServer.SetMessageMaxLength%��

		\~japanese
		1���Ϋ�ë�?�����Ī��Ȫ��Ǫ������ޫ�����
		- ͳ�Ҫ��쪿���ǪϪ���ު�����?�Ϫ������򪤪ĪǪ�?�ڪ��ƪ��ު��Ǫ���
		- �������� CNetServer�Ȫ�CNetClient���֫������Ȫ���������������ê����Ҫ��ʪ���Ъʪ�ު���
		- ���������Ǫ����?�ڪ��ʪ����Ȫ�?�᪷�ު���ӣ������?��?��������1���Ϋ�ë�?����1MB��?���ƪ�����ުʪ�����Ǫ���
		- �ϫë��󫰪��쪿���髤����Ȫ����ުê���ë�?���Ϋ����������������?���몿��˪� CNetServer.SetMessageMaxLength���Ū����Ȫ�?�᪷�ު���
		\~
		*/
		// ��
		//PROUD_API static int MessageMaxLength;

		static const int MessageMaxLengthInOrdinaryCase = 64 * 1024;
		static const int MessageMaxLengthInServerLan = 1024 * 1024;

		// �뷫, ���� ũ���� ���� �޽��� ����� ��� ��� ��� ������ ũ��. ũ�Ⱑ �ſ� �����Ƿ� �����ؼ� �� ��!
		static const int MessageMinLength = 128;

		// �޽��� 1���� �ִ� ũ�� �Ѱ� (������)
		static const int MessageMaxLength;

		PROUD_API static int64_t DefaultGracefulDisconnectTimeoutMs;

		/**
		\~korean
		�������� Ŭ���̾�Ʈ�� P2P routed multicast�� �� �� �ִ� ���� �� �ִ� ����(router ������ �ϴ� Ŭ�� ������)

		\~english
		The maximum number of P2P routed multicast from server to client (client that acts as router is excluded)

		\~chinese
		?��?����client?��P2P routed multicast��?����ʦ�?��������??��?router������client���⣩

		\~japanese
		��?��?�ǫ��髤����Ȫ�P2P routed multicast�򪹪��������ު��������?(��?��?��ܪ򪹪뫯�髤����Ȫ���⪹��)
		\~
		*/
		PROUD_API static int MaxS2CMulticastRouteCount;

		PROUD_API static int UnreliableS2CRoutedMulticastMaxPingDefaultMs;

		PROUD_API static bool ForceCompressedRelayDestListOnly;

		/**
		\~korean
		������ �ִ� �����ڼ�

		\~english
		Maximum number of con-current user per server

		\~chinese
		��?��?��������??���?��

		\~japanese
		��?��??��������������?�?
		\~
		*/
		static const int MaxConnectionCount = 60000;

		/**
		\~korean
		�������� �ѹ��� multicast�� �Ҷ� heap alloc�� ���ʿ��� ������ ������� �ִ� �۽ŷ�

		\~english
		Maximum amount of normal communication that does not require heap alloc when server performs 1 multicast

		\~chinese
		���?��?�����multicast��?����heap alloc ������������������?�������ᡣ

		\~japanese
		��?��?�������Ϋޫ�����㫹�Ȫ򪹪���heap alloc����驪���ު������ܪ�����������
		\~
		*/
		static const int OrdinaryHeavyS2CMulticastCount = 100;

		/**
		\~korean
		test splitter�� �� ���ΰ� �� ���ΰ�?
		- �� ��� ��ŷ��� �ణ �����ϳ� splitter test�� ���� ���� serialization�� ã�µ� ������ �ȴ�.

		\~english
		test splitter is to be turned on or off?
		- If on then amount of communication slightly increases but it helps finding cracked serialization through splitter test.

		\~chinese
		����?test splitter��
		- ?��?������?��ڰ��ʥ��ӣ��?��?splitter test??����serialization?��?𾡣

		\~japanese
		test splitter��Ī��몫�Ī��ʪ�����
		- �Ī������ꡢ�������ᴪ�?ʥ���ު�����splitter test���ת�?�쪿serialization�������Ϊ�𾪫��ު���
		\~
		*/
		PROUD_API static const bool EnableTestSplitter;

		static const uint32_t ClientListHashTableValue = 101;
	private:
		/**
		\~korean
		config�� ���� ������ ���� �̰��� �ɾ�� �Ѵ�!

		\~english
		Use it only for changing config value

		\~chinese
		�������config?��?�����ġ�

		\~japanese
		Config������?�ڪ������Ϊߪ���򪫪�����驪�����ު�!
		\~
		*/
		static CriticalSection m_writeCritSec;
	public:
		PROUD_API static bool EnableSpeedHackDetectorByDefault;

		/**
		\~korean
		����ڴ� �� ���� false�� �ٲپ� �޽��� �켱���� ����� �� �� �ִ�. �׽�Ʈ �������θ� ���� ���� �����Ѵ�.

		\~english
		User can turn off message priority function by changing it to false. We recommend to use it for testing

		\~chinese
		��?ʦ����?��?false�??������?�?����������?����test?����?���ġ�

		\~japanese
		��?��?�Ϫ�������false��?���ƫ�ë�?���Ϋ׫髤����ƫ�Ѧ���򫪫ժ��몳�Ȫ��Ǫ��ު����ƫ������ܪǪΪ��Ū����Ȫ�?�᪷�ު���
		\~
		*/
		PROUD_API static bool EnableMessagePriority;

		PROUD_API static const int64_t SpeedHackDetectorPingIntervalMs;

		PROUD_API static CriticalSection& GetWriteCriticalSection();

		PROUD_API static int DefaultMaxDirectP2PMulticastCount;

		PROUD_API static bool UpnpDetectNatDeviceByDefault, UpnpTcpAddPortMappingByDefault;

		PROUD_API static int64_t MeasureClientSendSpeedIntervalMs;

		PROUD_API static int64_t MeasureSendSpeedDurationMs;

		PROUD_API static DirectP2PStartCondition DefaultDirectP2PStartCondition;

		/**
		\~korean
		ProudNet ���� �Ǵ� ProudNet�� ���� �ݹ�Ǵ� �޼���(RMI ���� ��ƾ, �̺�Ʈ �ڵ鷯 ��)���� unhandled exception(���� �޸� �ܱ�)�� �߻������� �װ��� ����ڰ� catch���� ���� ��� roudNet�� ��� catch ó���� �� OnUnhandledException���� �Ѱ��� ������ �ƴϸ� �׳� unhandled exception�� ���� �������� �����ϴ� �����̴�.
		- �⺻���� true�̴�.
		- ����ڴ� �������� �� ���� �ٲ㵵 �ȴ�.

		\~english
		The variable that decides whether:

		1. to pass as OnUnhandledException after Proudnet processes it as catch when unhandled exception(such as scratching memory) occurs at the method(RMI reception routine, event handler)
		called back by either ProudNet internal or ProudNet while user did not catch,

		2. or to leave unhandled exception as it is.
		- Default is true.
		- User can change this value at any time.

		\~chinese
		��ProudNet?ݻ���ProudNet������۰����RMI ���routine��event handler ����?����unhandled exception����??��catch��?����?��ProudNet?catch?����??OnUnhandledException?��??׺�unhandled exception��??��
		- ��??��true��
		- ��?ʦ�??�����?��

		\~japanese
		ProudNet?ݻ�ު���ProudNet�˪�êƫ�?��Ыë������᫽�ë�(RMI�����?���󡢫��٫�ȫϫ�ɫ�?�ʪ�)��unhandled exception��?�檷�ơ�������?��?��catch���ʪ����ꡢroudNet���۪���catch?�⪷������OnUnhandledException���ڪ�Ԥ����������Ȫ⪽�Ϊު�unhandled exception���Ǫ����Ǫ�����̽�Ҫ���??�Ǫ���
		- ��������ture�Ǫ���
		- ��?��?�Ϫ��ĪǪ⪳������?�ڪ��ƪ��ު��Ǫ���

		\~
		*/
		PROUD_API static bool CatchUnhandledException;

		/**
		\~korean
		ProudNet ����ڰ� �Ǽ��� �� ��� ��ȭ ���ڷ� ���� ������ ��Ÿ ������� ó���� ��������
		�����ϴ� ������.
		- ����ڴ� �������� �� ���� �ٲ㵵 �ȴ�.
		- �⺻���� ErrorReaction_MessageBox �̴�.

		\~english
		A variable to decide to display ProudNet user mistake as chat box or other way
		- User can change this value at any time.
		- Default is ErrorReaction_MessageBox.

		\~chinese
		?��ProudNet��?��?��?��??????��������۰��?����??��
		- ��?ʦ�?�������?��
		- ��??��ErrorReaction_MessageBox��

		\~japanese
		ProudNet ��?��?�����ު��򪷪����ꡢ���������ܫë��������ƪ��몫�����۰�Ҫ�?�⪹�몫��̽�Ҫ���??�Ǫ���
		- ��?��?�Ϫ��ĪǪ⪳������?�ڪ��ƪ��ު��Ǫ���
		- ��������ErrorReaction_MessageBox�Ǫ���
		\~
		*/
		PROUD_API static ErrorReaction UserMisuseErrorReaction;

		/**
		\~korean
		CNetClient �� ���� ó���� worker thread �� �켱������ ��󺸴� ���� �����ϴ��� ����
		- �⺻��: true�̴�.
		- Ŭ���̾�Ʈ ���ø����̼ǿ��� CNetClient �ν��Ͻ��� ����ϴ� ��� ������ �������� �������� ���
		�� ���� false�� �����ؼ� ���� �ذ��� �� ���ɼ��� �ֱ⵵ �ϴ�. ������ �幰��. ���� ��ŷ��� ���̴� ���� ����.
		- ������ CNetClient �ν��Ͻ��� ����� ������ �� ���� ������ �� �ִ�.

		\~english
		To decide whether to set priority of internal worker thread of CNetClient to be higher than normal
		- Default: true
		- When using CNetClient instance at client application causes lowering renderinf frames, there is a possibility to solve that by setting this as false. But very rare. It is better to redice communication traffic.
		- This value can be set only, before creating the very first CNetClient.

		\~chinese
		������ CNetClient%��?ݻ?����worker thread��?�?��?����������������
		- ��??��true��
		- �client?�������� CNetClient%?����?��������?��˽��?����ʦ����??��?false?���???��ӣ��?���?��?��?���������������
		- ���?������ CNetClient%?������ʦ�?���?��

		\~japanese
		CNetClient��?ݻ?����worker thread�Ϋ׫髤����ƫ������Ȫ���Ԫ����Ҫ��몫��ʦ��
		- ��������true�Ǫ���
		-�����髤����ȫ��׫꫱?������CNetClient���󫹫��󫹪��Ū����ꡢ������󫰫ի�?�બժ�������ꡢ��������false�����Ҫ��������̽�򪹪�ʦ�����⪢��ު��������������Ǫ����ષ������������骷��۰��?�Ǫ���
		- ������CNetClinet���󫹫��󫹪��ª���Ϊߪ����������Ҫ��몳�Ȫ��Ǫ��ު���
		\~
		*/
		PROUD_API static bool NetworkerThreadPriorityIsHigh;

		/**
		\~korean
		 ������ Shutdown �۾��� abortive or hard���� �����ϰ��� �� �� �����ϴ� �����Դϴ�.
		 �׽�Ʈ �������θ� ���� ���� �����մϴ�.
		- �⺻��: false�̴�.
		\~english
		It is the variable which is setted when progressing shutdown of socket by aboritive or  hard.
		We recommend to use it for testing
		- Default: false
		\~chinese TODO:translate needed.
		It is the variable which is setted when progressing shutdown of socket by aboritive or  hard.
		We recommend to use it for testing
		- Default: false
		\~japanese TODO:translate needed.
		It is the variable which is setted when progressing shutdown of socket by aboritive or  hard.
		We recommend to use it for testing
		- Default: false
		\~
		*/
		PROUD_API static bool EnableAbortiveSocketClose;

		/**
		\~korean
		������� ���ο��� ���ǰ� �ִ� Object Pooling ����� on/off �� �� �ִ� ���� �Դϴ�.
		����ڴ� �� ���� �������� �ʴ� ���� �����մϴ�.
		- �⺻��: true�̴�.
		\~english
		This variable can turn on or off Object Pooling function in ProudNet.
		We recommend not to change it.
		- Default: true
		\~chinese TODO:translate needed.
		This variable can on/off Object Pooling function in ProudNet.
		We recommend not to change it.
		- Default: true
		\~japanese TODO:translate needed.
		This variable can on/off Object Pooling function in ProudNet.
		We recommend not to change it.
		- Default: true
		\~
		*/
		PROUD_API static bool EnableObjectPooling;


		//PROUD_API static double ReportP2PGroupPingIntervalMs;
		PROUD_API static int64_t ReportLanP2PPeerPingIntervalMs;
		PROUD_API static int64_t ReportP2PPeerPingTestIntervalMs;
		PROUD_API static int64_t ReportServerTimeAndPingIntervalMs;
		PROUD_API static int64_t LongIntervalMs;

		PROUD_API static int64_t MinSendSpeed;

		PROUD_API static int DefaultOverSendSuspectingThresholdInBytes;
		PROUD_API static bool ForceUnsafeHeapToSafeHeap;
		PROUD_API static bool EnableSendBrake;
		PROUD_API static int UdpCongestionControl_MinPacketLossPercent;
		PROUD_API static int64_t VizReconnectTryIntervalMs;
		PROUD_API static int64_t SuperPeerSelectionPremiumMs;

		/**
		\~korean
		ProudNet ���� HostID ���� �߱޽� ���ʰ� ������ �߱������� �����ϴ� ���Դϴ�.

		\~english
		It will decide issue timing for issuing HostID re-use at ProudNet.

		\~chinese
		�ProudNet?ۯHost ID������?��?���?�������??ۯ��?��

		\~japanese
		ProudNet�� HostID �����?������������Φ����?�����몫��̽�Ҫ������Ǫ���
		\~
		*/
		PROUD_API static int64_t HostIDRecycleAllowTimeMs;

		/**
		\~korean
		Sendqueue�� �뷮�� �󸶳� �ʰ��Ǹ� warning�� ������ �Ұ������� ���� ���Դϴ�.

		\~english
		It will decide warning message timing depends on amount of Sendqueue

		\~chinese
		?Sendqueue�����?������?warning��?��

		\~japanese
		Sendqueue����᪬�ɪ������Φ�����warning�����ƪ��몫��?�������Ǫ���
		\~
		*/
		PROUD_API static int SendQueueHeavyWarningCapacity;

		PROUD_API static int64_t SendQueueHeavyWarningTimeMs;
		PROUD_API static int64_t SendQueueHeavyWarningCheckCoolTimeMs;

		/**
		\~korean
		emergency log�� ���� NetClientStats �� �纻�� ������ coolTime ���Դϴ�.

		\~english 
		This is the coolTime value to renew the copy of NetClientStats for the emergency log. 

		\~chinese
		?��emergency log�������NetClientStats������coolTime?��

		\~japanese
		emergency log�Ϊ����NetClientStats�Ϋ���?�����檹��coolTime���Ǫ���
		\~
		*/
		PROUD_API static int64_t UpdateNetClientStatCloneCoolTimeMs;

		PROUD_API static bool EnableErrorReportToNettention;

		PROUD_API static int64_t ManagerGarbageFreeTimeMs;
		PROUD_API static unsigned int ManagerAverageElapsedTimeCollectCount;
		PROUD_API static bool	EnableStarvationWarning;

		PROUD_API static bool FraggingOnNeedByDefault;
		PROUD_API static bool CheckDeadLock;
		PROUD_API static bool UseIsSameLanToLocalForMaxDirectP2PMulticast;

		PROUD_API static const int TcpSendMaxAmount;

		/**
		\~korean
		Thread local storage (TLS) �Լ��� ������� ���θ� �����մϴ�.
		�⺻���� true�Դϴ�.
		TLS �Լ��� ����� �� ���� ȯ�濡 ���ؼ�, �� ���� false�� �����Ͻʽÿ�.
		(���� ��� �� ��ŷ ���� 3rd party ����Ʈ���� ȥ���� �ϴ� ���)

		\~english 
		This is to determine whether to use the Thread local storage (TLS) function. 
		The default value is true. 
		For the environment where the TLS function cannot be used only, set this value as false. 
		(for example, when an anti-hacking 3rd party software is used together)

		\~chinese
		?����������Thread local storage (TLS)��?��
		����?��true��
		�������������TLS��??��?����??�??��?false��
		����������??��?3rd party?����?������

		\~japanese
		Thread local storage (TLS)??���Ū����ɪ�����̽�Ҫ��ު���
		��������true�Ǫ���
		TLS??�����ĪǪ��ʪ����Ѫ��ڪêơ���������false�����Ҫ��ƪ���������
		(�Ǫ��С��ϫë������3rd party���իȫ����������Ī�������)
		\~
		*/
		PROUD_API static const bool AllowUseTls;

		PROUD_API static bool ConcealDeadlockOnDisconnect;

		//kdh MessageOverload Warning �߰�
		PROUD_API static int MessageOverloadWarningLimit;
		PROUD_API static int MessageOverloadWarningLimitTimeMs; //sec

		// 		PROUD_API static int64_t LanServerMessageOverloadTimerIntervalMs;
		// 		PROUD_API static int64_t LanClientMessageOverloadTimerIntervalMs;
		// 		PROUD_API static int64_t NetServerMessageOverloadTimerIntervalMs;
		// 		PROUD_API static int64_t NetClientMessageOverloadTimerIntervalMs;
		PROUD_API static int64_t MessageOverloadTimerIntervalMs;
		PROUD_API static int64_t LanRemotePeerHeartBeatTimerIntervalMs;

		PROUD_API static void AssertTimeoutTimeAppropriate(int64_t ms);
		PROUD_API static int P2PFallbackTcpRelayResendTimeIntervalMs;

		PROUD_API static int CleanUpOldPacketIntervalMs;
		PROUD_API static int NormalizePacketIntervalMs;
		PROUD_API static void ThrowExceptionIfMessageLengthOutOfRange(int length);

		PROUD_API static double MessageRecovery_MessageIDAckIntervalMs;

		PROUD_API static bool ListenSocket_RetryOnInvalidArgError;
		PROUD_API static bool AllowOutputDebugString;

		PROUD_API static bool DefensiveSendReadyListAdd;
		PROUD_API static bool DefensiveCustomValueEvent;

		PROUD_API static bool EnablePeriodicDetectingTransitionNetwork;
	};
	/**  @} */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
