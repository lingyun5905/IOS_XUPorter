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

#include "IRmiHost.h"
#include "HlaHost_C.h"
#include "BasicTypes.h"
#include "ConnectParam.h"
#include "HostIDArray.h"
#include "AddrPort.h"
#include "Enums.h"
#include "ErrorInfo.h"
#include "EncryptEnum.h"
#include "RMIContext.h"
#include "ErrorInfo.h"
#include "NetClientStats.h"
#include "LambdaEventHandler.h"
#include "acr.h"

#define PN_DEPRECATED /*__declspec(deprecated) */

#ifdef _MSC_VER // pragma warning�� VC++����
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

	class MessageSummary;
	class CTestStats2;
	class CMessage;
	class CNetConnectionParam;
	class CNetPeerInfo;
	class CP2PGroup;

	class CSendFragRefs;
	class ErrorInfo;
	class INetClientEvent;
	class IRmiProxy;
	class IRmiStub;
	class ReliableUdpHostStats;
	class CUserWorkerThreadCallbackContext;

	struct SendOpt;



	/**
	\~korean
	\brief Ŭ���̾�Ʈ FrameMove ó�� ���
	- FrameMove���� �޽����� �̺�Ʈ�� �󸶳� ó�� �Ǿ����� �� ��� �Դϴ�.

	\~english
	\brief client FrameMove process result
	- The result that shows how much of messages and events were processed by FrameMove

	\~chinese
	\brief clientFrameMove?��?����
	- �FrameMove������?event?�������?����

	\~japanese
	\brief ���髤�����FrameMove��?��̿��
	- FrameMove�ǫ�ë�?���ȫ��٫�Ȫ��ɪ����?�⪵�쪿�Ϊ���̿���Ǫ��� 

	\~
	*/
	class CFrameMoveResult
	{
	public:

		/**
		\~korean
		FrameMove ȣ�� ���� RMI ȣ�� Ƚ���Դϴ�.

		\~english
		Number of RMI caling after calling FrameMove

		\~chinese
		FrameMove��У���RMI��У�?��

		\~japanese
		FrameMove �������˽��RMI��������?�Ǫ���
		\~
		*/
		uint32_t	m_processedMessageCount;

		/**
		\~korean
		FrameMove ȣ�� ���� INetClientEvent �ݹ� Ƚ���Դϴ�.

		\~english
		Number of INetClientEvent callback after calling FrameMove

		\~chinese
		FrameMove��У���INetClientEvent��?�?��

		\~japanese
		FrameMove �������˽��INetClientEvent ��?��Ыë���?�Ǫ���
		\~
		*/
		uint32_t	m_processedEventCount;

		CFrameMoveResult():
		m_processedMessageCount(0),
		m_processedEventCount(0)
		{

		}
	};

	/**
	\~korean
	\brief �������� ���� ���¸� ���� ���

	\~english
	\brief Acquired result of the connection status to server

	\~chinese
	\brief ?��?��?����?��??��?����

	\~japanese
	\brief ��?��?�Ȫ���??������̿�� 
	\~
	*/
	class CServerConnectionState
	{
	public:
		/**
		\~korean
		�������� UDP ������ �� �Ǿ� �ִ� �����̸� true�̴�.
		�̰� false�� ���, unreliable �޽�¡�� TCP�� ���� ����ȴ�.

		\~english
		True if UDP connection to server is well
		If false then unreliable messaging is done via TCP

		\~chinese
		?��?����UDP?��??������?true��
		?��false��?��unreliable messaging��?TCP?����

		\~japanese
		��?��?�Ȫ�UDP��?���誯�Ǫ��ƪ���?���ʪ�true�Ǫ���
		���쪬false�Ǫ������ꡢunreiable��ë�?���󫰪�TCP���ת��������ު���

		\~
		*/
		bool m_realUdpEnabled;

		CServerConnectionState()
		{
			m_realUdpEnabled = false;
		}
	};

	/**
	\~korean
	\brief ProudNet ���ο��� Direct P2P ����� ���� �����ϰ� �ִ� �ּ� ���� �����Դϴ�.
	CNetClient.GetDirectP2PInfo ��� ���˴ϴ�.

	\~english
	\brief Information that contains addresses and others for internal P2P communication in ProudNet.
	Used at CNetClient.GetDirectP2PInfo and so on.

	\~chinese
	\brief �ProudNet?ݻ?��Direct P2P�������׺���������ӡ�� CNetClient.GetDirectP2PInfo%�����ġ�

	\~japanese
	\brief ProudNet ?ݻ��Direct P2P����Ϊ�������󪷪ƪ��뫢�ɫ쫹�ʪɪ����êǪ��� 
	CNetClient.GetDirectP2PInfo �ʪɪ��Ū��ު���

	\~
	*/
	class CDirectP2PInfo
	{
	public:
		/**
		\~korean
		CNetClient�� ��� �Ǿ���� Direct P2P ����� ���� ���� �ִ� UDP ������ ���� �ּ�
		- CNetClient.GetLocalUdpSocketAddr�� ���� ���̴�.

		\~english
		Local address of UDP socket possessed by CNetClient for it to use direct P2P communication with opponent peer
		- Has same value as CNetClient.GetLocalUdpSocketAddr

		\~chinese
		CNetClient ??۰peer��Direct P2P�����?����UDP socket����򣡣
		- ? CNetClient.GetLocalUdpSocketAddr%��?��?��

		\~japanese
		CNetClient�����peer�Ȫ�Direct P2P����Ϊ�����êƪ���UDP�����ëȪΫ�?���뫢�ɫ쫹 	
		- CNetClient.GetLocalUdpSocketAddr���Ҫ����Ǫ��� 

		\~
		*/
		AddrPort m_localUdpSocketAddr;

		/**
		\~korean
		��� �Ǿ�� Direct P2P�� ��Ŷ�� �۽Ž� ��� �Ǿ��� ���� �ּ��̴�.
		socket API sendto()�� ���̱⵵ �Ѵ�.

		\~english
		Reception address of opponent peer when packets sent through Direct P2P
		Can be used at socket API sendto()

		\~chinese
		??۰peer��Direct P2P?��?����??۰peer������򣡣
		��socket API sendto()�����ġ�

		\~japanese
		���Peer��Direct P2P�ǫѫ��ëȪ������������peer����᫢�ɫ쫹�Ǫ���
		socket API sendto()���Ū�쪿�ꪷ�ު��� 

		\~
		*/
		AddrPort m_localToRemoteAddr;

		/**
		\~korean
		��� �Ǿ�κ��� Direct P2P �� ��Ŷ�� ���Ž� ��� �Ǿ��� �۽� �ּ��̴�.
		socket API recvfrom()�� ���̱⵵ �Ѵ�.

		\~english
		Transmission address of opponent peer when packets received through Direct P2P
		Can be used at socket API recvfrom()

		\~chinese
		??۰peer��Direct P2P���?����??۰peer��?���򣡣
		��socket API recvfrom()�����ġ�

		\~japanese
		���peer����Direct P2P�ǫѫ��ëȪ������������peer�����᫢�ɫ쫹�Ǫ���
		socket API recvfrom()���Ū�쪿�ꪷ�ު��� 

		\~
		*/
		AddrPort m_remoteToLocalAddr;

		inline CDirectP2PInfo()
		{
			m_localToRemoteAddr = AddrPort::Unassigned;
			m_remoteToLocalAddr = AddrPort::Unassigned;
			m_localUdpSocketAddr = AddrPort::Unassigned;
		}

		/**
		\~korean
		P2P Ȧ��Ī�� ����Ǿ Ȯ���� �����ΰ�?

		\~english
		Is this acquired after P2P hole-punching is completed?

		\~chinese
		��P2P����������?��������?��

		\~japanese
		P2P ��?��ѫ���󫰪��������������쪿���êʪΪ��� 
		\~
		*/
		inline bool HasBeenHolepunched()
		{
			return m_localUdpSocketAddr.IsUnicastEndpoint() && m_localToRemoteAddr.IsUnicastEndpoint() && m_remoteToLocalAddr.IsUnicastEndpoint();
		}
	};

	/**
	\~korean
	\brief ��Ʈ��ũ Ŭ���̾�Ʈ

	���� Ŭ���̾�Ʈ�� ���� ������ ��Ʈ��ŷ�� ��Ʈ��ũ Ŭ���̾�Ʈ���� P2P ����� ���� Ŭ���̾�Ʈ�Դϴ�.

	�ڼ��� ������ <a target="_blank" href="http://guide.nettention.com/cpp_ko#client_overview" >��Ʈ��ũ Ŭ���̾�Ʈ</a> �� �ֽ��ϴ�.

	\~english
	\brief Network Client

	A network client class for client-to-server networking and client-to-client (P2P) networking.

	<a target="_blank" href="http://guide.nettention.com/cpp_en#client_overview" >Network Client</a> explains the details.

	\~chinese
	\brief ??client��

	?����?client����?��?����??��??client��?P2P������client��

	???��<a target="_blank" href="http://guide.nettention.com/cpp_zh#client_overview" >??��?Ӯ</a>%�졣

	\~japanese
	\brief �ͫëȫ�?�����髤�����
	��?�૯�髤����Ȫȫ�?�૵?��?�Ϋͫëȫ�?���󫰪ȫͫëȫ�?�����髤��������P2P����Ϊ���Ϋ��髤����ȪǪ���
	�٪����ϡ�\ref client_overview�˪���ު���

	\~
	*/
	class CNetClient : public IRmiHost, public IHlaHost_C, public HasCoreEventFunctionObjects
	{
	public:
		virtual ~CNetClient() {}

		/**
		\~korean
		�� �ν��Ͻ��� �����մϴ�.

		\~english
		Creates new instance.

		\~chinese
		������?�ǡ�

		\~japanese
		�檷�����󫹫��󫹪��������ު���
		\~
		*/
		static CNetClient* Create();

		/*
		\~korean
		�������� �� ������ ��Ų��. �۽�, ���Žÿ� ��� ����ȴ�.
		��������� 300,100�� �ణ ���� �� ȯ���� �䳻����.

		\~english
		Virtually causes laggy situation. Applies to both transmission and reception.	Usually, 300,100 causes an average laggy situation.

		\~chinese
		????lag��?�����������?Դ�����ġ�
		����300,100ټ???����lag?�ѡ�

		\~japanese
		?�̪ǫ�ë����?�����ު�������������������Ī���ު���
		�����ܪ�300,100��ᴪ��Ҫɪ���ë����Ѫ�?�Īު���

		\~
		*/
#ifdef DEPRECATE_SIMLAG
		virtual void SimulateBadTraffic(uint32_t minExtraPing, uint32_t extraPingVariance) = 0;
#endif // DEPRECATE_SIMLAG

		/**
		\~korean
		���� ���� ������ �����մϴ�.
		- �� �Լ��� ��� �����մϴ�. ����, �� �Լ��� �����ߴٰ� �ؼ� �������� ������ ��� ���� ���� �ƴմϴ�.
		- �� �Լ� ȣ�� �� INetClientEvent.OnJoinServerComplete() �̺�Ʈ�� ������ �Ŀ��� ���� ������ ���� ���θ� �ľ��� �� �ֽ��ϴ�.

		\param param ������ ���� �����Դϴ�.
		\return �̹� �ٸ� ������ ����� �����̸� false�� �����Ѵ�. ���������� ���� ��û�� ���������� true�� ���ϵ˴ϴ�.

		\~english

		Initialtes server connection request.

		- This function returns immediately. Being this function returned does not mean that the connection to server is completed.
		- It is possible to verify if connection to server is completed only after INetClientEvent.OnJoinServerComplete event arrives after calling this function.

		\param connectionInfo specifies server information to connect to.
		\return Returns false is already connected to other server. Returns true if successfully connected.

		\~chinese
		?�?��?����?��?�
		- ���?ء?���ޡ����?����������?��?����?����ݻ?�֡�
		- ���?��У�� INetClientEvent.OnJoinServerComplete() event��?���ʦ��Գ��?��?��������?����

		\param param �?������?�����ӡ�
		\return �?��?������?��?����??��?����false������?���?���?��?����true��

		\~japanese
		��?��?��?Φ�����㷪��ު���
		����??�������˫꫿?�󪷪ު�����êơ�����??���꫿?�󪷪��Ȫ��ƫ�?��?�Ȫ���?���������ê��ΪǪϪ���ު���
		- ����??�������󪷪�����INetClientEvent.OnJoinServerComplete() ���٫�Ȫ���󷪷�����˪ʪêƫ�?��?��?������ʦ�������Ī��몳�Ȫ��Ǫ��ު���
		\param param ��?���뫵?��?���êǪ���
		\return ?����Ϋ�?��?����?���쪿?���Ǫ����false��꫿?�󪷪ު�����?������㷪�����true���꫿?�󪵪�ު���

		\~
		*/
		virtual bool Connect(const CNetConnectionParam &connectionInfo) = 0;
		virtual bool Connect(const CNetConnectionParam &connectionInfo, ErrorInfoPtr &outError) = 0;

		/**
		\~korean
		�������� ������ �����Ѵ�. �ƿ﷯ ��� P2P �׷쿡���� Ż���Ѵ�.
		- �ڼ��� ���� ���� �޼��� ����

		\~english
		 Terminates the connection to server and withdraws from all P2P group.
		- Please refer to same name method for more detail.

		\~chinese
		���?��?����?�ȡ������������P2P?��
		- ????����٣۰����

		\~japanese
		��?��?�Ȫ���?����𶪷�ު������ʪߪˡ����٪ƪ�P2P����?�ת����?�ܪ��ު���
		- �٪����ϡ���٣�᫽�ëɪ�?�Ϊ���������

		\~
		*/
		virtual void Disconnect() = 0;

		/**
		\~korean
		�������� ������ �����Ѵ�. �ƿ﷯ ��� P2P �׷쿡���� Ż���Ѵ�.
		\param gracefulDisconnectTimeout �������� ������ �����ϴ� ������ ó���ϱ� ���� Ŭ���̾�Ʈ�� ���� �ð���
		�ð��� �䱸�Ѵ�. �� ���� �������� ������ �����ϴ� ������ ����ϴ� �ִ� �ð�(��)�̴�.
		�� ���� ��������� 1 �̳��� ����������, �ʹ� ����ġ�� ���� ���� ��� ���, Ŭ���̾�Ʈ�� ��������
		������ ���������� ���������� Ŭ���̾�Ʈ�� ���� ������ ��� �������� ���ϴ� ��찡 ���� �� �ִ�.
		\param comment ���⿡ ä���� �����ʹ� INetServerEvent.OnClientLeave���� �޾�����.
		�� Ŭ���̾�Ʈ�� �������� ������ �����ϵ� �������� ���������� �����͸� �������� �� ��(��: ������ ���� ������ ������) �����ϴ�.
		gracefulDisconnectTimeout�� �ʹ� ª���� �� ���� �ִ�.

		\~english
		Terminates the connection to server and withdraws from all P2P group.
		\param gracefulDisconnectTimeout Client requires a certain amount of time in order to process the steps to terminate the connection to server. This value is the maximum time(in second) that allowed to complete the termination.
		Usually 1 is reasonable for the value but if it is too small then there can be some cases that server cannot detect clinet's diconnection immediately after client terminated the connection.
		\param comment The data filled in here will be received at INetServerEvent.OnClientLeave.
		In other words, it is useful when client need to send its last data to server before terminating its connection to server.(e.g. sending why terminating the connection)
		If gracefulDisconnectTimeout is too short then there is a chance the sending fails.

		\~chinese
		���?��?����?�ȡ������������P2P?��
		\param gracefulDisconnectTimeout ?��?��?��?��?�������?�client �ϴ����??��??���?�����?��?����?������?������??��������
		�?����1�??��?����?���?��?ʦ��??��client?��?����?��?�?򭣬��?��۰����ء?���client��?���������?��
		\param comment ��?��?����?��� INetServerEvent.OnClientLeave%��⥡�?client���?��?����?�ȣ�������?��?��?��?����?�����ģ��ǣ�?��???������릣���
		gracefulDisconnectTimeout ��ӭ��?ʦ��������?��

		\~japanese
		��?��?�Ȫ���?����𶪷�ު������ʪߪˡ����٪ƪ�P2P����?�ת����?�ܪ��ު���
		\param gracefulDisconnectTimeout ��?��?�Ȫ���?����𶪹��Φ���?�⪹�몿��ˡ����髤����Ȫ��������������ϴ��ު����������ϫ�?��?�Ȫ���?���ުǪ���ʦ������������(��)�Ǫ���
		�������������ܪ�1�?����?�Ǫ��������ު�˪�ᳪ��������������ꡢ���髤����Ȫϫ�?��?�Ȫ���?���������ު���������?��?���ǫ��髤����Ȫ���?�������������Ǫ��ʪ����ꪬ������ު���
		\param comment ���������쪿��?���ϡ�INetServerEvent.OnClientLeave������������ު���
		?�������髤����Ȫ���?��?�Ȫ���?����𶪷�ު�������?��?�������˫�?������꪿����(�ǣ���?��﷪���릪����)���ĪǪ���
		gracefulDisconnectTimeout�����ު�˪�ӭ����?���ʪ����ꪬ����ު��� 

		\~
		*/
		virtual void Disconnect(const CDisconnectArgs &args) = 0;

		/**
		\~korean
		�������� ������ �����Ѵ�. �ƿ﷯ ��� P2P �׷쿡���� Ż���Ѵ�.
		UE4/PS4 �� ���� ����� �ܿ��� try/catch �� ��� �� �� ���� ȯ�濡��, ���� �޼����� �뺸 ���� �� ��� �ϵ��� �Ѵ�.
		- �ڼ��� ���� ���� �޼��� ����

		\~english
		It disconnects the connection to the server. Additionally, it withdraws from all P2P groups. 
		In an environment where try/catch cannot be used from the user side such as UE4/PS4, it shall be used when an error message is notified. 
		- For details, refer to the method with the same name. 

		\~chinese
		 ���?��?����?�ȡ���??���P2P?����
		��UE4/PS4??�������?Ӯ����try/catch��?���飬?��??���?���ġ�
		- ??��?�??����٣۰��

		\~japanese
		��?��?�Ȫ���?����𶪷�ު������ʪߪˡ����٪ƪ�P2P����?�ת����?�ܪ��ު���
		UE4/PS4�Ϊ誦�ˡ���?��?����try/catch�����ĪǪ��ʪ����Ѫǡ�����?��ë�?�������ê��ƪ�骦�����Ū��誦�˪��ު���
		- �٪������Ȫ���٣�Ϋ᫽�ëɪ�?�Ϊ��ƪ���������

		\~
		*/
		virtual void Disconnect(ErrorInfoPtr& outError) = 0;

		/**
		\~korean
		�������� ������ �����Ѵ�. �ƿ﷯ ��� P2P �׷쿡���� Ż���Ѵ�.
		UE4/PS4 �� ���� ����� �ܿ��� try/catch �� ��� �� �� ���� ȯ�濡��, ���� �޼����� �뺸 ���� �� ��� �ϵ��� �Ѵ�.
		- �ڼ��� ���� ���� �޼��� ����

		\~english
		It disconnects the connection to the server. Additionally, it withdraws from all P2P groups. 
		In an environment where try/catch cannot be used from the user side such as UE4/PS4, it shall be used when an error message is notified. 
		- For details, refer to the method with the same name. 

		\~chinese
		 ���?��?����?�ȡ���??���P2P?����
		��UE4/PS4??�������?Ӯ����try/catch��?���飬?��??���?���ġ�
		- ??��?�??����٣۰��

		\~japanese
		��?��?�Ȫ���?����𶪷�ު������ʪߪˡ����٪ƪ�P2P����?�ת����?�ܪ��ު���
		UE4/PS4�Ϊ誦�˫�?��?����try/catch�����ĪǪ��ʪ����Ѫǡ�����?��ë�?�������ê��ƪ��ê������Ū��誦�˪��ު���
		- �٪�������٣�᫽�ëɪ�?�Ϊ���������

		\~
		*/
		virtual void Disconnect(const CDisconnectArgs &args, ErrorInfoPtr& outError) = 0;

		// Added for emergency use if Disconnect() never returns though it has automatic non-wait functionality.
		virtual void DisconnectAsync(const CDisconnectArgs &args) = 0;

		/**
		\~korean
		[������] ��ü P2P �׷��� ���¸� ������ �����.

		\~english
		[Debugging] Leaves the status of entire P2P group as a dump

		\~chinese
		[??��] ����ݻP2P?��??׺???��

		\~japanese
		[�ǫЫë�����]��?P2P����?�ת�?�������ת�?���ު���
		\~
		*/
		//virtual String DumpStatus() = 0;

		/**
		\~korean
		���ŵ� RMI�� �̺�Ʈ�� ó���մϴ�.
		���� �������� FrameMove�� ȣ���� ���ĺ��� ���ݱ��� �����κ��� ���ŵ� RMI�� INetClientEvent�� �ݹ� �̺�Ʈ�� Ŭ���̾�Ʈ �޸𸮿� �����Ǿ� �ֽ��ϴ�.
		�׸��� �װ͵��� �� �޼��忡 ���� ������ �ݹ��� �߻��ϰ� �մϴ�.
		- ����ڴ� ���� �ð����� �̸� ȣ���ؼ� RMI ���� ó�� �� �߻� �̺�Ʈ�� ó���ϵ��� �ؾ� �մϴ�. �Ϲ����� ��� ����ڴ� �� �޼��带 �� ���� �����Ӹ��� ȣ���մϴ�.
		- �� �޼��带 ��ð� ȣ�� ���Ѵٰ� �ؼ� Ÿ ȣ��Ʈ�� �������� ������ �������� ���� �����ϴ�.

		\param maxWaitTimeMs ó���� �̺�Ʈ�� ���� �޽����� ���� ������, �󸶳� ���� ��ٸ� �������� ���� ���Դϴ�. 0�̸� ��ٸ��� �ʰ� ��� �����մϴ�.
		���� �� ������ ���� �ȿ����� 0�� �Ϲ����̸�, ������ ������ ���� �Ϲ� �ۿ����� ������ �� (���� 200ms)�� �ֽ��ϴ�.
		\param outResult FrameMove ȣ��� ó�� ��� ���� ����ϴ�. ���� ������ �Ķ�����Դϴ�.

		\~english
		Handles received RMI or event
		All of RMI from server or callbcak event of INetClientEvent occurred since the last FrameMove call are stacked within memory.
		And those let callbacks happen by this method.
		- User is to call this periodically in order to handle RMI reception process and event occurred. Usually, user calls this method at every render frame.
		- By not calling this method for a long time does not cause the connection between server or other hosts terminated.

		\param maxWaitTimeMs  It is the value of how long it will wait until there is a processed event or in-coming message,  If it is 0, do not wait and return immediately.
		0 is general in the rendering loop including game, and etc.  Put the appropriate value (for example, 200ms) in the general app without the rendering loop.
		\param outResult Gets the report to process result when FrameMove is called. Ignorable parameter.

		\~chinese
		?�������RMI���event��
		?������УFrameMove?���?�?��?�������RMI���INetClientEvent����?event׫?�client?���졣
		���������۰����??����?��
		- ��?������ӫ??��У??��RMI���?����event?��?�⡣��������?����?���۰�����?render frame��У��
		- ��??����?��???��У�۰���?������������?����?��??�����ס�

		\param maxWaitTimeMs  ��?�?������?����������������?��?�,����������???����̫�������� 0 ��?,?ء?����,��?���⡣
		���?��?�����,0����������, �?��?�����?��?����,ۯ����?����̫(����200ms)��
		\param outResult FrameMove��У??��?��?��?ͱ��ʦ�������??��

		\~japanese
		���᪵�쪿RMI�Ȫ����٫�Ȫ�?�⪷�ު���
		����������FrameMove�������󪷪������顢����ުǫ�?��?������᪷��RMI�Ȫ�INetClientEvent�Ϋ�?��Ыë����٫�Ȫϫ��髤����ȫ���?��׫�ݪ���ƪ��ު���
		�����ơ������򪳪Ϋ᫽�ëɪ˪�ê���?�˫�?��Ыë���?�檹��誦�˪��ު���
		- ��?��?��������઴�Ȫ˪���������󪷪�RMI����?�����?�櫤�٫�Ȫ�?�⪹��誦�˪��ʪ���Ъʪ�ު��������ܪ����ꡢ��?��?�Ϫ��Ϋ᫽�ëɪ�?�ޫ���?��󫰫ի�?�઴�Ȫ������󪷪ު���
		- ���Ϋ᫽�ëɪ������������󪵪ʪ��Ȫ�����Ϋ۫��Ȫ䫵?��?�Ȫ���?��﷪�몳�ȪϪ���ު���
		\param maxWaitTimeMs ?�⪹�뫤�٫�Ȫ������ë�?�����������ުǡ��ɪ����������Ī���?�������Ǫ���0�Ǫ�����⪿���������˫꫿?�󪷪ު���
		��?��ʪɫ���?��󫰫�?��?�Ǫ�0�������ܪǡ�����?��󫰫�?�ת��ʪ��������׫�Ǫ���?����(?��200ms)������ު���
		\param outResult FrameMove ����������?��̿������ͱ����ު�������ʦ���ʫѫ��?��?�Ǫ��� 


		\param maxWaitTimeMs  ?�⪹�뫤�٫�Ȫ������ë�?��������ުǡ��ɪ�۪�������ĪΪ��˪Ī������Ǫ���0�˪��⪿���������˫꫿?�󪷪ު���
		��?��ʪɫ�����󫰫�?�ת���Ǫ�0�������ܪǪ��ꡢ������󫰫�?�ת��ʪ��������׫�Ǫ���?����(�Ǫ��С�200ms)������ު���

		\~
		*/
		virtual void FrameMove(int maxWaitTime = 0, CFrameMoveResult* outResult = NULL) = 0;
		/** No-throw function. Exception is stored to outError. Used for UE4, etc. */
		virtual void FrameMove(int maxWaitTime, CFrameMoveResult* outResult, ErrorInfoPtr& outError) = 0;

		/**
		\~korean
		�� client�� �����ϰ� �ִ� P2P group �� �ϳ��� groupHostID�� �����ϰ� �ִ�
		�ٸ� peer���� HostID list�� ��´�.

		\~english
		Gets the HostID list of other peers participating groupHostID that is one of P2P groups that this client is participating

		\~chinese
		?��??�client??��P2P group������groupHost ID������peer HostID list��

		\~japanese
		���Ϋ��髤����Ȫ�?ʥ���ƪ���P2P����?�ת���ĪǪ���groupHostID��?ʥ���ƪ������Peer��HostID list����ު���
		\~
		*/
		virtual void GetGroupMembers(HostID groupHostID, HostIDArray &output) = 0;

		/**
		\~korean
		�ٸ� peer���� ������ ���� ���� �ð��� ���Ѵ�.

		\~english
		Gets the server time that other peer has

		\~chinese
		ϴ����peer??������?��??��

		\~japanese
		���Peer���êƪ��뫵?��?�����ϴ��ު���
		\~
		*/
		virtual int64_t GetIndirectServerTimeMs(HostID peerHostID) = 0;

		/**
		\~korean
		�� ȣ��Ʈ�� local HostID�� ���Ѵ�. HostID_None�̸� ������ ���� �ȵƴٴ� ��.

		\~english
		Gets local HostID of this host. If HostID_None then means not connected to server

		\~chinese
		ϴ������local Host ID��HostID_None ��?����?��?��?��?�ȡ�

		\~japanese
		���Ϋ۫��Ȫ�local HostID��ϴ��ު���HostID_None�Ǫ���Ы�?��?����?����ʪ��ê��Ȫ�����ګ��
		\~
		*/
		virtual HostID GetLocalHostID() = 0;

		/**
		\~korean
		�� Ŭ���̾�Ʈ�� ���� ��Ʈ��ũ�� �۵����� ���ͳ� ������ ��ġ(NAT device)��
		�̸��� ��´�.

		\~english
		Gets the name of Internet router device(NAT device) that is active at the network that this client is participating.

		\~chinese
		?�client�?��???��??������??�����?�ǣ�NAT device����٣��

		\~japanese
		���Ϋ��髤����Ȫ�?�����ͫëȫ�?����������Ϋ���?�ͫëȫ�?��?(NAT device)��٣�����ު���
		\~
		*/
		virtual String GetNatDeviceName() = 0;

		/**
		\~korean
		�� ȣ��Ʈ�� ������ ��� P2P �׷� ����Ʈ�� ��´�.

		\~english
		Gets the entire P2P group list that this host is participating

		\~chinese
		?������ʥ�������P2P?֪����

		\~japanese
		���Ϋ۫��Ȫ�ʥ��������ƪ�P2P����?�׫꫹�Ȫ���ު���
		\~
		*/
		virtual void GetLocalJoinedP2PGroups(HostIDArray &output) = 0;

		/**
		\~korean
		���� �̷� ������ ó���� ��踦 ��´�.

		\~english
		Gets the statistics of process collected since beginning

		\~chinese
		?��?���?����?����??��

		\~japanese
		����?��?󢪵�쪿?�������ͪ����ު���
		\~
		*/
		virtual void GetStats(CNetClientStats &outVal) = 0;

		/**
		\~korean
		P2P group�� ���� �ð��� ��´�.
		�̴� groupHostID�� ����Ű�� P2P group�� ��� GetIndirectServerTime()���� ����̴�.

		\~english
		Gets server time of P2P group
		This is an average value of all GetIndirectServerTime() values within the P2P group that groupHostID points.

		\~chinese
		?��P2P group����?��??��
		?��groupHostID����P2P group�����GetIndirectServerTime()?����г��

		\~japanese
		P2P����?�תΫ�?��?�������ު���
		�����groupHostID��򦪹P2P����?�ת���ƪ�GetIndirectServerTime()������г�Ǫ���

		\~
		*/
		virtual int64_t GetP2PServerTimeMs(HostID groupHostID) = 0;

		/**
		\~korean
		�� ȣ��Ʈ�� Ÿ Peer���� ����� ���� ���������� ���� �ִ� UDP socket�� ���� �ּҸ� ��´�.
		- <a target="_blank" href="http://guide.nettention.com/cpp_ko#use_alternative_p2p" >ProudNet�� ���� �ʰ� ProudNet�� Ȧ��Ī ������ ���� ���� UDP �������� ����ϱ�</a>  ���� ���Ǳ⵵ �Ѵ�.

		\param remotePeerID �� ȣ��Ʈ�� P2P ����� �ϰ� �ִ� Ÿ Peer�� HostID.
		\return CNetClient ���ο��� �����ϰ� �ִ� UDP socket�� ��Ʈ��ȣ �Ǵ� (�ּ�,��Ʈ��ȣ). ����ڴ� ���⼭ ��Ʈ ��ȣ�� ������ ���� �ȴ�.
		- P2P �׷쿡 ����� peer�� ������ �� �ȵ� ��� �� ���� AddrPort.Unassigned�� �� �ִ�. �ֳ��ϸ� ProudNet�� ���� ����� ����
		UDP socket�� ��� ������ �ʱ� �����̴�. ���� �̷��� ��� ��� �ڿ� �ٽ� �� �޼��带 ȣ���ؼ� ���� �� �ִ�.

		\~english
		Gets the local address of UDP socket that this host has internally for communicating with other peer
		- Also used in <a target="_blank" href="http://guide.nettention.com/cpp_en#use_alternative_p2p" >Communicating with a separated UDP socket based on ProudNet hole-punched information without using ProudNet.</a>

		\param remotePeerID HostID of other peer that P2P communicates with this host
		\return CNetClient Port number or (address, port number) of UDP socket that is possessed internally. User can use this as port number.
		- This value can be AddrPort.Unassigned when the opponent peer entered P2P group recently.
		This is because ProudNet does not create UDP socket immediately for performance reason. So, if this happens then you must call this method again some moments later.

		\~chinese
		?������?��?����peer�����ᣬ?ݻUDP socket������򣡣
		-  ��<a target="_blank" href="http://guide.nettention.com/cpp_zh#use_alternative_p2p" >������ProudNet��������ProudNet��������?��?����UDPSocket?������</a>%���ġ�

		\param remotePeerID ������P2P?������������peer��Host ID��
		\return CNetClient%?ݻ��׺��UDP socket��ӮϢ??������ӮϢ??����???����ӮϢ???ʦ��
		- ��P2P??۰peer?��?�����??��?���?ʦ���� AddrPort.Unassigned%����?ProudNet?�����������?ء??��UDP socket����??����?��ʦ��������У�۰��?��

		\~japanese
		���Ϋ۫��Ȫ����Peer�Ȫ�����Ϊ����?ݻ�ܪ��êƪ���UDP�����ëȪΫ�?���뫢�ɫ쫹����ު���
		- \ref use_alternative_p2p���Ū��몳�Ȫ⪢��ު��� 
		\param remotePeerID ���Ϋ۫��Ȫ�P2P����򪷪ƪ������Peer��HostID.
		\return CNetClient ?ݻ�����󪷪ƪ���UDP�����ëȪΫ�?����?�ު���(���ɫ쫹����?����?)����?��?�Ϫ����ǫ�?����?������?����Ū����ު��Ǫ���
		- P2P����?�ת��������Peer�����ê����ʪ����ꡢ��������AddrPort.Unassigned�Ǫ��몳�Ȫ⪢��ު����ʪ��ʪ顢ProudNet��������߾�Ϊ����UDP�����ëȪ��������ª�ʪ�����Ǫ�����êơ����Ϊ誦�����ꡢ���Ъ骯����Ӫ��Ϋ᫽�ëɪ������󪷪���몳�Ȫ��Ǫ��ު���

		\~
		*/
		virtual AddrPort GetLocalUdpSocketAddr(HostID remotePeerID) = 0;

		/**
		\~korean
		�� ȣ��Ʈ�� remotePeerID�� ����Ű�� Ÿ Peer���� ����� ���� Ȧ��Ī�� ������ ��´�.
		- <a target="_blank" href="http://guide.nettention.com/cpp_ko#use_alternative_p2p" >ProudNet�� ���� �ʰ� ProudNet�� Ȧ��Ī ������ ���� ���� UDP �������� ����ϱ�</a>  ���� ���Ǳ⵵ �Ѵ�.

		\param remotePeerID Ÿ �Ǿ��� ID
		\param outInfo Ÿ �Ǿ���� ����� ���� Ȧ��Ī ������ ä���� ��
		\return Ȧ��Ī�� Peer�� ��� true, �� ���� ��� false�� �����Ѵ�. ���� false�� ������ ��� ���� Ȧ��Ī���� ���� peer�� ��쿡�� 0.3~1�� ��������
		�� �޼��带 ���������� ȣ���ϴ� ���� true�� ������ ���� �ִ�. �ֳ��ϸ� Ȧ��Ī�� ����Ǵ� �ð��� �׻� �ٸ��� �����̴�.

		\~english
		Gets the hole-punched information for this host to communicate with other peer that remotePeerID points
		- Also used in <a target="_blank" href="http://guide.nettention.com/cpp_en#use_alternative_p2p" >Communicating with a separated UDP socket based on ProudNet hole-punched information without using ProudNet.</a>

		\param remotePeerID ID of other peer
		\param outInfo where the hole-punching information for communicating with other peer to be filled
		\return True if hole-punched peer, otherwise returns false.
		For the peer that is not hole-punched yet, there are some occasions that it returns true when calling this method in every 0.3 ~ 1 seconds.
		This happens since the moment when hole-punching is completed differs all the time.
		\~chinese
		����?��?remotePeerID��������peer������?���������ӡ�
		- ��<a target="_blank" href="http://guide.nettention.com/cpp_zh#use_alternative_p2p" >������ProudNet��������ProudNet��������?��?����UDPSocket?������</a>%���ġ�

		\param remotePeerID ����peer��ID��
		\param outInfo ?��?����peer�������������������?�����۰��
		\return ������peer��?true����������?����false����������false��?��??��������peer����?���0.3~1?̰���?��У�۰����?������true��?������?����������???�����ҡ�

		\~japanese
		���Ϋ۫��Ȫ�remotePeerID��򦪹���Peer�Ȫ�����Ϊ���˫�?��ѫ���󫰪��쪿���ê���ު���
		- \ref use_alternative_p2p���Ū��몳�Ȫ⪢��ު��� 		
		\param remotePeerID ���Peer��ID
		\param outInfo ���Peer�Ȫ�����Ϊ���Ϋ�?��ѫ�������ê�?��������
		\return ��?��ѫ���󫰪��쪿Peer�������true��������������false��꫿?�󪷪ު����⪷��false��꫿?�󪷪����ꡢ�ު���?��ѫ���󫰪���ƪʪ�peer�������0.3~1������̰�Ǫ��Ϋ᫽�ëɪ��?�ܪ������󪷪ʪ���̸��ȡ�true��꫿?�󪹪���������ު����ʪ��ʪ顢��?��ѫ���󫰪�����������Ϫ��Ī��ު�����Ǫ��� 

		\~
		*/
		virtual bool GetDirectP2PInfo(HostID remotePeerID, CDirectP2PInfo &outInfo) = 0;

		/**
		\~korean
		����� ������ �ּҸ� ���Ѵ�.

		\~english
		Gets the address of connected server

		\~chinese
		ϴ?������?���򣡣

		\~japanese
		��?���쪿��?��?�Ϋ��ɫ쫹��ϴ��ު���
		\~
		*/
		virtual AddrPort GetServerAddrPort() = 0;

		/**
		\~korean
		�� ��ü�� ����� peer 1���� ������ ��´�.
		\param peerHostID ã������ peer�� HostID
		\param output ã�� peer�� ����. �� ã���� �ƹ��͵� ä������ �ʴ´�.
		\return true�̸� ã�Ҵٴ� ��

		\~english
		Gets the information of 1 peer connected to this object
		\param peerHostID HostID of peer to find
		\param output the information of peer found. Nothing will be filled when found nothing.
		\return True means found

		\~chinese
		?��?���?������?peer���ӡ�
		\param peerHostID �?��peer��HostID��
		\param output ?����peer�����ӡ�?��?����?��?������?ड�
		\return true��?��?�������֡�

		\~japanese
		���Ϋ��֫������Ȫ˪Īʪ��ê�Peer 1�������ê���ު���
		\param peerHostID ��������peer��HostID
		\param output ������peer�����á��������Ȫ��Ǫ��ʪ��ê�������?������ު���
		\return true�Ǫ�����������Ȫ�����ګ

		\~
		*/
		virtual bool GetPeerInfo(HostID peerHostID, CNetPeerInfo& output) = 0;

		/**
		\~korean
		�� ȣ��Ʈ�� ����� �ٸ� ȣ��Ʈ(������ ��� Ŭ���̾�Ʈ��, Ŭ���̾�Ʈ�� ��� �Ǿ��)�� �������� tag�� �����մϴ�. <a target="_blank" href="http://guide.nettention.com/cpp_ko#host_tag" >�� ȣ��Ʈ�� ���� ����� ���� ������(Tag)</a> ����Դϴ�.
		- �ڱ� �ڽ�(���� Ȥ�� Ŭ���̾�Ʈ)�� ���� tag�� ������ �� �ֽ��ϴ�.

		\~english
		Desigantes tag to each of other hosts(client for server, peer for client) aht are connected to this host. A <a target="_blank" href="http://guide.nettention.com/cpp_en#host_tag" >User-defined data(Tag) for each host</a> function.
		- Can designate tag to itself (server or client)

		\~chinese
		??�������������������?����?client��client ��?peer�����tag��<a target="_blank" href="http://guide.nettention.com/cpp_zh#host_tag" >?��?�������?��??�ߣ�Tag��</a> %������
		- �ʦ�?���������?�����client�����tag��

		\~japanese
		���Ϋ۫��Ȫ˪Īʪ��ê���Ϋ۫���(��?��?������ϫ��髤����ȡ����髤����Ȫ�����ϫ�?��)�Ϊ��쪾���tag����Ҫ��ު���\ref host_tag Ѧ���Ǫ���
		- ������(��?��?�ު��ϫ��髤�����)��?����tag����Ҫ��몳�Ȫ��Ǫ��ު��� 

		\~
		*/
		virtual bool SetHostTag(HostID hostID, void* hostTag) = 0;

		/**
		\~korean
		������ ���� �ð��� ���Ѵ�. (�� ����)
		�� ���� ���� �ð����� �����Ͻõ� ����Ǿ� ���Ǵ� ������ �ð��̴�.

		\~english
		Gets current time of server (in second)
		This value is the server time that considered periodic latency

		\~chinese
		ϴ��?����?�??����?�ȣ���
		�?����̰��ӫ??��?latency�?ߩ����?��??��

		\~japanese
		��?��?����������ϴ��ު���(��?��)
		��������������઴�Ȫ˫�?�ƫ�?�����窵���ͪߩ����뫵?��?������Ǫ���

		\~
		*/
		virtual int64_t GetServerTimeMs() = 0;

		/**
		\~korean
		Ŭ���̾�Ʈ�� �������� �ð� ���� ���Ѵ�.

		\~english
		Gets the time difference between client and server

		\~chinese
		ϴclient?��?����??󬡣

		\~japanese
		���髤����Ȫȫ�?��?�Ȫ�������ϴ��ު���
		\~
		*/
		virtual int64_t GetServerTimeDiffMs() = 0;

		/**
		\~korean
		�������� ���� ���� ���¸� �����մϴ�.
		- ������ ���� ���¸� �����մϴ�. ������ ����Ǿ������� OnJoinServerComplete�� �ݹ�˴ϴ�.
		\param output �������� ���� ���°� ä������ ����
		\return �������� ���� ����

		\~english
		Returns connection status to server
		\param output where the status is filled
		\return connection status to server

		\~chinese
		������?����socket?��??��
		- ?����socket?��??����������?����OnJoinServerComplete��?��
		\param output ?��?��?����?��??����?��
		\return ?��?����?��??��

		\~japanese
		��?��?�ȪΫ����ë���??����꫿?�󪷪ު���
		- �����ëȪ���??���Ϊߪ�꫿?�󪷪ު�������˪Īʪ��êƪ��몫��OnJoinServerComplete�˫�?��Ыë�����ު���
		\param output ��?��?�Ȫ���??����?�����������
		\return ��?��?�Ȫ���??�� 

		\~
		*/
		virtual ConnectionState GetServerConnectionState(CServerConnectionState &output) = 0;


		virtual void GetWorkerState(CClientWorkerInfo &output) = 0;

		/**
		\~korean
		�������� ���� ���� ���θ� �����մϴ�.
		- ������ ������ ���� �Ǿ������� ���θ� �����մϴ�.

		\~english
		Return connect socket to server or not.
		- Only return connected socket to server or not.

		\~chinese
		����?��?����socket?��?����
		- ��������?����socket?��?����

		\~japanese
		��?��?�ȪΫ����ë���?ʦ����꫿?�󪷪ު���
		- ��?��?�ȫ����ëȪ���?����ƪ��몫�ɪ����Ϊߪ�꫿?�󪷪ު���

		\~
		*/
		inline bool HasServerConnection()
		{
			CServerConnectionState stat;
			return GetServerConnectionState(stat)==ConnectionState_Connected;
		}

		/**
		\~korean
		�̺�Ʈ�� ���� �� �ִ� ��ü�� �����Ѵ�.
		- �ϳ��� ���� �����ϴ�.
		- �� �޼���� Ŭ���̾�Ʈ�� ������ ������ �õ��ϱ� ������ ȣ���� �� �ִ�. �ȱ׷��� exception�� throw�ȴ�.

		\~english
		Sets the object can receive event
		- Only 1 object can be set.
		- This method can only be called before client attempts to connect to server. Otherwise, an execption will be 'throw'.

		\~chinese
		?��ʦ����event��?�ڡ�
		- ����?����?��
		- �۰�������client???����?��������У����??exception �� throw��

		\~japanese
		���٫�Ȫ��������뫪�֫������Ȫ����Ҫ��ު���
		- ��ĪΪ�����ʦ���Ǫ���
		- ���Ϋ᫽�ëɪϫ��髤����Ȫ���?��?����?���˪���Ϊ������󪹪��Ȫ��Ǫ��ު�������Ȫ⡢exception��throw����ު��� 

		\~
		*/
		virtual void SetEventSink(INetClientEvent* eventSink) = 0;

		// rarely used for diagnostics.
		virtual INetClientEvent* GetEventSink() = 0;

	public:


		// ����: ���� ��ü�̹Ƿ� SUPPORTS_LAMBDA_EXPRESSION�� ������ �� ��.

		/// See Proud.INetClientEvent.OnJoinServerComplete for details.
		LambdaBaseHolder_Param2<void, ErrorInfo*, const ByteArray&> OnJoinServerComplete;
		/// See Proud.INetClientEvent.OnLeaveServer for details.
		LambdaBaseHolder_Param1<void, ErrorInfo*> OnLeaveServer;
		/// See Proud.INetClientEvent.OnP2PMemberJoin for details.
		LambdaBaseHolder_Param4<void, HostID, HostID, int, const ByteArray &> OnP2PMemberJoin;
		/// See Proud.INetClientEvent.OnP2PMemberLeave for details.
		LambdaBaseHolder_Param3<void, HostID, HostID, int> OnP2PMemberLeave;
		/// See Proud.INetClientEvent.OnChangeP2PRelayState for details.
		LambdaBaseHolder_Param2<void, HostID, ErrorType > OnChangeP2PRelayState;
		/// See Proud.INetClientEvent.OnChangeServerUdpState for details.
		LambdaBaseHolder_Param1<void, ErrorType> OnChangeServerUdpState;
		/// See Proud.INetClientEvent.OnP2PMemberOffline for details.
		LambdaBaseHolder_Param1<void, CRemoteOfflineEventArgs &> OnP2PMemberOffline;
		/// See Proud.INetClientEvent.OnP2PMemberOnline for details.
		LambdaBaseHolder_Param1<void, CRemoteOnlineEventArgs &> OnP2PMemberOnline;
		/// See Proud.INetClientEvent.OnServerOffline for details.
		LambdaBaseHolder_Param1<void, CRemoteOfflineEventArgs &> OnServerOffline;
		/// See Proud.INetClientEvent.OnServerOnline for details.
		LambdaBaseHolder_Param1<void, CRemoteOnlineEventArgs &> OnServerOnline;
		/// See Proud.INetClientEvent.OnSynchronizeServerTime for details.
		LambdaBaseHolder_Param0<void> OnSynchronizeServerTime;


	public:
		/**
		\~korean
		Remote peer�� ������ �����Ͻø� ��´�.
		\param remoteHostID ã������ remote peer�� HostID. HostID_Server�� �����ϸ� �������� �����Ͻø� ��´�.
		\param error ���� ���θ� �����Ѵ�. �������� ��� ErrorType_Ok, Ping�� ���� ���� ��� ErrorType_ValueNotExist�� ����ȴ�.
		\return ping time�� �ʴ����� �����Ѵ�. �� ������ -1�� �����Ѵ�.

		\~english
		Gets the last latency of Remote peer
		\param remoteHostID HostID of remote peer to find. Gets the latency with server when set HostID_Server.
		\param error It returns whether an error occurs or not. In case of normal case, ErrorType_Ok will be saved, however, ErrorType_ValueNotExist will be saved in case Ping is not received.
		\return returns ping time(in second). Returns -1 if there is none.

		\~chinese
		?��remote peer������latency��
		\param remoteHostID �?��remote peer��HostID�����HostID_Server��??��?��?����latency��
		\param error ����???������������??ErrorType_Ok������?��?��Ping???��ErrorType_ValueNotExist��
		\return ping��time���?�����ޡ�?����?����-1��

		\~japanese
		Remote peer�������Ϋ쫤�ƫ󫷪���롣
		\param remoteHostID �������Ȫ���remote peer��HostID. HostID_Server����Ҫ���ȫ�?�ЪȪΫ쫤�ƫ󫷪���롣
		\param error ����?�����몫�ʪ�����꫿?�󪹪롣�����ܪ������ErrorType_Ok, Ping����ʪ��ê�����˪�ErrorType_ValueNotExist��������롣
		\return ping time����?�Ȫǫ꫿?�󪹪롣�������� ping time�����Ҫ���ƪ��ʪ����-1��꫿?�󪹪롣

		\~
		*/
		inline double GetLastUnreliablePingSec(HostID remoteHostID, ErrorType* error = NULL)
		{
			int ret=GetLastUnreliablePingMs(remoteHostID, error);
			if(ret<0)
				return (double)ret;
			else
				return (double)(ret/1000);
		}
		/**
		\~korean
		Remote peer�� ������ �����Ͻø� ��´�.
		\param remoteHostID ã������ remote peer�� HostID. HostID_Server�� �����ϸ� �������� �����Ͻø� ��´�.
		\param error ���� ���θ� �����Ѵ�. �������� ��� ErrorType_Ok, Ping�� ���� ���� ��� ErrorType_ValueNotExist�� ����ȴ�.
		\return ping time�� �и��ʴ����� �����Ѵ�. �� ������ -1�� �����Ѵ�.

		\~english
		Gets the last latency of Remote peer
		\param remoteHostID HostID of remote peer to find. Gets the latency with server when set HostID_Server.
		\param error It returns whether an error occurs or not. In case of normal case, ErrorType_Ok will be saved, however, ErrorType_ValueNotExist will be saved in case Ping is not received.
		\return returns ping time(in millisecond). Returns -1 if there is none.

		\~chinese
		?��Remote peer������latency��
		\param remoteHostID �?��remote peer��HostID�����HostID_Server��??��?��?����latency��
		\param error ����???������������??ErrorType_Ok������?��?��Ping???��ErrorType_ValueNotExist��
		\return ping��time�����?�����ޡ�?����?����-1��

		\~japanese
		Remote peer�������Ϋ쫤�ƫ󫷪���롣
		\param remoteHostID �������Ȫ���remote peer��HostID. HostID_Server����Ҫ���ȫ�?�ЪȪΫ쫤�ƫ󫷪���롣
		\param error ����?�����몫�ʪ�����꫿?�󪹪롣�����ܪ������ErrorType_Ok, Ping����ʪ��ê�����˪�ErrorType_ValueNotExist��������롣
		\return ping time��߫���?�Ȫǫ꫿?�󪹪롣�������� ping time�����Ҫ���ƪ��ʪ����-1��꫿?�󪹪롣

		\~
		*/
		virtual int GetLastUnreliablePingMs(HostID remoteHostID, ErrorType* error = NULL) = 0;

		/**
		\~korean
		Remote peer�� ������ �����Ͻø� ��´�. GetLastUnreliablePing���� Unreliable�� �ΰ��� ���ϴ� �ݸ� �ش��Լ��� ReliableUdp�� �����Ѵ�.
		\param remoteHostID ã������ remote peer�� HostID. HostID_Server�� �����ϸ� �������� �����Ͻø� ��´�.
		\param error ���� ���θ� �����Ѵ�. �������� ��� ErrorType_Ok, Ping�� ���� ���� ��� ErrorType_ValueNotExist�� ����ȴ�.
		\return ping time�� �и��ʴ����� �����Ѵ�. �� ������ -1�� �����Ѵ�.

		\~english
		Gets the last latency of Remote peer. GetLastUnreliablePing value is found by Unreliable but the relevant function is measured by ReliableUdp.
		\param remoteHostID HostID of remote peer to find. Gets the latency with server when set HostID_Server.
		\param error It returns whether an error occurs or not. In case of normal case, ErrorType_Ok will be saved, however, ErrorType_ValueNotExist will be saved in case Ping is not received.
		\return returns ping time(in millisecond). Returns -1 if there is none.

		\~chinese
		?��Remote peer������Latency��GetLastUnreliablePing ?��Unreliableϴping?��ӣ��?��?��ReliableUdp?�ҡ�
		\param remoteHostID �?��remote peer��HostID�����HostID_Server��??��?��?����latency��
		\param error ����???������������??ErrorType_Ok������?��?��Ping???��ErrorType_ValueNotExist��
		\return ping��time�����?�����ޡ�?����?����-1��

		\~japanese
		Remote peer�������Ϋ쫤�ƫ󫷪���롣 GetLastUnreliablePing����Unreliable��PING����ϴ�����������???�� ReliableUdp�����Ҫ��롣
		\param remoteHostID �������Ȫ���remote peer��HostID. HostID_Server����Ҫ���ȫ�?�ЪȪΫ쫤�ƫ󫷪���롣
		\param error ����?�����몫�ʪ�����꫿?�󪹪롣�����ܪ������ErrorType_Ok, Ping����ʪ��ê�����˪�ErrorType_ValueNotExist��������롣
		\return ping time��߫���?�Ȫǫ꫿?�󪹪롣�������� ping time�����Ҫ���ƪ��ʪ����-1��꫿?�󪹪롣

		\~
		*/
		virtual int GetLastReliablePingMs(HostID remoteHostID, ErrorType* error = NULL) = 0;

		/**
		\~korean
		Remote peer�� ������ �����Ͻø� ��´�. GetLastUnreliablePing���� Unreliable�� �ΰ��� ���ϴ� �ݸ� �ش��Լ��� ReliableUdp�� �����Ѵ�.
		\param remoteHostID ã������ remote peer�� HostID. HostID_Server�� �����ϸ� �������� �����Ͻø� ��´�.
		\param error ���� ���θ� �����Ѵ�. �������� ��� ErrorType_Ok, Ping�� ���� ���� ��� ErrorType_ValueNotExist�� ����ȴ�.
		\return ping time�� �ʴ����� �����Ѵ�. �� ������ -1�� �����Ѵ�.

		\~english
		Gets the last latency of Remote peer. GetLastUnreliablePing value is found by Unreliable but the relevant function is measured by ReliableUdp.
		\param remoteHostID HostID of remote peer to find. Gets the latency with server when set HostID_Server.
		\param error It returns whether an error occurs or not. In case of normal case, ErrorType_Ok will be saved, however, ErrorType_ValueNotExist will be saved in case Ping is not received.
		\return returns ping time(in second). Returns -1 if there is none.

		\~chinese
		?��Remote peer������Latency��GetLastUnreliablePing ?��UnreliableϴPing?��ӣ��?��?��ReliableUDP?�ҡ�
		\param remoteHostID �?��remote peer��HostID�����HostID_Server��??��?��?����latency��?��<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%��Host ID��??��P2P??�������?����гlatency��
		\param error ����???������������??ErrorType_Ok������?��?��Ping???��ErrorType_ValueNotExist��
		\return ping��time���?�����ޡ�?����?����-1��

		\~japanese
		Remote peer�������Ϋ쫤�ƫ󫷪���롣 GetLastUnreliablePing����Unreliable��PING����ϴ�����������???�� ReliableUdp�����Ҫ��롣
		\param remoteHostID �������Ȫ���remote peer��HostID. HostID_Server����Ҫ���ȫ�?�ЪȪΫ쫤�ƫ󫷪���롣
		\param error ����?�����몫�ʪ�����꫿?�󪹪롣�����ܪ������ErrorType_Ok, Ping����ʪ��ê�����˪�ErrorType_ValueNotExist��������롣
		\return ping time����?�Ȫǫ꫿?�󪹪롣�������� ping time�����Ҫ���ƪ��ʪ����-1��꫿?�󪹪롣

		\~
		*/
		inline double GetLastReliablePingSec(HostID remoteHostID, ErrorType* error = NULL)
		{
			int ret=GetLastReliablePingMs(remoteHostID, error);
			if(ret<0)
				return (double)ret;
			else
				return double(ret)/1000;
		}

		/**
		\~korean
		Remote peer�� �ֱ� �����Ͻø� ��´�.
		\param remoteHostID ã������ remote peer�� HostID. HostID_Server�� �����ϸ� �������� �����Ͻø� ��´�. <a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P �׷�</a> �� HostID�� ������ P2P �׷� ��
		��� ������� ��� �����Ͻø� ��´�.
		\param error ���� ���θ� �����Ѵ�. �������� ��� ErrorType_Ok, Ping�� ���� ���� ��� ErrorType_ValueNotExist�� ����ȴ�.
		\return ping time�� �ʴ����� �����Ѵ�. �� ������ -1�� �����Ѵ�.

		\~english
		Gets the recent latency of Remote peer
		\param remoteHostID HostID of remote peer to find. Gets the latency with server when set HostID_Server. Gets the average latency of all members of P2P group when set HostID of <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a>.
		\param error It returns whether an error occurs or not. In case of normal case, ErrorType_Ok will be saved, however, ErrorType_ValueNotExist will be saved in case Ping is not received.
		\return returns ping time(in second). Returns -1 if there is none.

		\~chinese
		?��Remote peer������latency��
		\param remoteHostID �?��remote peer��HostID�����HostID_Server��??��?��?����latency��?��<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%��Host ID��??��P2P??�������?����гlatency��
		\param error ����???������������??ErrorType_Ok������?��?��Ping???��ErrorType_ValueNotExist��
		\return ping��time���?�����ޡ�?����?����-1��

		\~japanese
		Remote peer�����ΪΫ쫤�ƫ󫷪���롣
		\param remoteHostID �������Ȫ���remote peer��HostID. HostID_Server����Ҫ���ȫ�?�ЪȪΫ쫤�ƫ󫷪���롣 <a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a> ��HostID����������� P2P����?��?����ƪΫ���?����г�쫤�ƫ󫷪���롣
		\param error ����?�����몫�ʪ�����꫿?�󪹪롣�����ܪ������ErrorType_Ok, Ping����ʪ��ê�����˪�ErrorType_ValueNotExist��������롣
		\return ping time����?�Ȫǫ꫿?�󪹪롣�������� ping time�����Ҫ���ƪ��ʪ����-1��꫿?�󪹪롣

		\~
		*/
		inline double GetRecentUnreliablePingSec(HostID remoteHostID, ErrorType* error = NULL)
		{
			int ret = GetRecentUnreliablePingMs(remoteHostID, error);
			if(ret<0)
				return (double)ret;
			else
				return (double)(ret/1000);
		}

		/**
		\~korean
		Remote peer�� �ֱ� �����Ͻø� ��´�.
		\param remoteHostID ã������ remote peer�� HostID. HostID_Server�� �����ϸ� �������� �����Ͻø� ��´�.
		\param error ���� ���θ� �����Ѵ�. �������� ��� ErrorType_Ok, Ping�� ���� ���� ��� ErrorType_ValueNotExist�� ����ȴ�.
		\return ping time�� �и��ʴ����� �����Ѵ�. �� ������ -1�� �����Ѵ�.

		\~english
		Gets the recent latency of Remote peer
		\param remoteHostID HostID of remote peer to find. Gets the latency with server when set HostID_Server.
		\param error It returns whether an error occurs or not. In case of normal case, ErrorType_Ok will be saved, however, ErrorType_ValueNotExist will be saved in case Ping is not received.
		\return returns ping time(in millisecond). Returns -1 if there is none.

		\~chinese
		?��Remote peer������latency��
		\param remoteHostID �?��remote peer��HostID�����HostID_Server��??��?��?����latency��
		\param error ����???������������??ErrorType_Ok������?��?��Ping???��ErrorType_ValueNotExist��
		\return ping��time�����?�����ޡ�?����?����-1��

		\~japanese
		Remote peer�����ΪΫ쫤�ƫ󫷪���롣
		\param remoteHostID �������Ȫ���remote peer��HostID. HostID_Server����Ҫ���ȫ�?�ЪȪΫ쫤�ƫ󫷪���롣
		\param error ����?�����몫�ʪ�����꫿?�󪹪롣�����ܪ������ErrorType_Ok, Ping����ʪ��ê�����˪�ErrorType_ValueNotExist��������롣
		\return ping time��߫���?�Ȫǫ꫿?�󪹪롣�������� ping time�����Ҫ���ƪ��ʪ����-1��꫿?�󪹪롣

		\~
		*/
		virtual int GetRecentUnreliablePingMs(HostID remoteHostID, ErrorType* error = NULL) = 0;

		/**
		\~korean
		Remote peer �� �ֱ� �����Ͻø� ��´�. GetRecentUnreliablePing ���� Unreliable�� �ΰ��� ���ϴ� �ݸ� �ش��Լ��� ReliableUdp �� �����Ѵ�.
		\param remoteHostID ã������ remote peer�� HostID. HostID_Server�� �����ϸ� �������� �����Ͻø� ��´�.
		\param error ���� ���θ� �����Ѵ�. �������� ��� ErrorType_Ok, Ping�� ���� ���� ��� ErrorType_ValueNotExist�� ����ȴ�.
		\return ping time�� �и��ʴ����� �����Ѵ�. �� ������ -1�� �����Ѵ�.

		\~english
		Gets the recent latency of Remote peer. GetRecentUnreliablePing value is found by Unreliable but the relevant function is measured by ReliableUdp.
		\param remoteHostID HostID of remote peer to find. Gets the latency with server when set HostID_Server.
		\param error It returns whether an error occurs or not. In case of normal case, ErrorType_Ok will be saved, however, ErrorType_ValueNotExist will be saved in case Ping is not received.
		\return returns ping time(in millisecond). Returns -1 if there is none.

		\~chinese
		?��Remote peer������Latency��GetRecentUnreliablePing ?��UnreliableϴPing?��ӣ��?��??��ReliableUDP?�ҡ�
		\param remoteHostID �?��remote peer��HostID�����HostID_Server��??��?��?����latency��
		\param error ����???������������??ErrorType_Ok������?��?��Ping???��ErrorType_ValueNotExist��
		\return ping��time�����?�����ޡ�?����?����-1��

		\~japanese
		Remote peer�����ΪΫ쫤�ƫ󫷪���롣 GetRecentUnreliablePing����Unreliable��PING����ϴ�����������???�� ReliableUdp�����Ҫ��롣
		\param remoteHostID �������Ȫ���remote peer��HostID. HostID_Server����Ҫ���ȫ�?�ЪȪΫ쫤�ƫ󫷪���롣
		\param error ����?�����몫�ʪ�����꫿?�󪹪롣�����ܪ������ErrorType_Ok, Ping����ʪ��ê�����˪�ErrorType_ValueNotExist��������롣
		\return ping time��߫���?�Ȫǫ꫿?�󪹪롣�������� ping time�����Ҫ���ƪ��ʪ����-1��꫿?�󪹪롣

		\~
		*/
		virtual int GetRecentReliablePingMs(HostID remoteHostID, ErrorType* error = NULL) = 0;

		/**
		\~korean
		Remote peer �� �ֱ� �����Ͻø� ��´�. GetRecentUnreliablePing ���� Unreliable�� �ΰ��� ���ϴ� �ݸ� �ش��Լ��� ReliableUdp �� �����Ѵ�.
		\param remoteHostID ã������ remote peer�� HostID. HostID_Server�� �����ϸ� �������� �����Ͻø� ��´�.
		\param error ���� ���θ� �����Ѵ�. �������� ��� ErrorType_Ok, Ping�� ���� ���� ��� ErrorType_ValueNotExist�� ����ȴ�.
		\return ping time�� �ʴ����� �����Ѵ�. �� ������ -1�� �����Ѵ�.

		\~english
		Gets the recent latency of Remote peer. GetRecentUnreliablePing value is found by Unreliable but the relevant function is measured by ReliableUdp.
		\param remoteHostID HostID of remote peer to find. Gets the latency with server when set HostID_Server.
		\param error It returns whether an error occurs or not. In case of normal case, ErrorType_Ok will be saved, however, ErrorType_ValueNotExist will be saved in case Ping is not received.
		\return returns ping time(in second). Returns -1 if there is none.

		\~chinese
		?��Remote peer������Latency��GetRecentUnreliablePing ?��UnreliableϴPing?��ӣ��?��??��ReliableUDP?�ҡ�
		\param remoteHostID �?��remote peer��HostID�����HostID_Server��??��?��?����latency��
		\param error ����???������������??ErrorType_Ok������?��?��Ping???��ErrorType_ValueNotExist��
		\return ping��time���?�����ޡ�?����?����-1��

		\~japanese
		Remote peer�����ΪΫ쫤�ƫ󫷪���롣 GetRecentUnreliablePing����Unreliable��PING����ϴ�����������???�� ReliableUdp�����Ҫ��롣
		\param remoteHostID �������Ȫ���remote peer��HostID. HostID_Server����Ҫ���ȫ�?�ЪȪΫ쫤�ƫ󫷪���롣
		\param error ����?�����몫�ʪ�����꫿?�󪹪롣�����ܪ������ErrorType_Ok, Ping����ʪ��ê�����˪�ErrorType_ValueNotExist��������롣
		\return ping time����?�Ȫǫ꫿?�󪹪롣�������� ping time�����Ҫ���ƪ��ʪ����-1��꫿?�󪹪롣

		\~

		*/
		inline double GetRecentReliablePingSec(HostID remoteHostID, ErrorType* error = NULL)
		{
			int ret = GetRecentReliablePingMs(remoteHostID, error);
			if(ret<0)
				return (double)ret;
			else
				return double(ret)/1000;
		}

		/**
		\~korean
		���������� ���� �ִ� UDP ������ �ݾƹ����� ���� �� P2P ����� bypass ���·� ���� ��ȯ�Ѵ�.
		- <a target="_blank" href="http://guide.nettention.com/cpp_ko#use_alternative_p2p" >ProudNet�� ���� �ʰ� ProudNet�� Ȧ��Ī ������ ���� ���� UDP �������� ����ϱ�</a>  ���� ���ȴ�.
		- CNetClient�� P2P ����� �ϰ� �ִ� Peer�� ������ŭ�� UDP ������ ���� ������ ������ UDP ������ ���� �ٸ� Peer���� �����
		�����ϰ� �ִ�. �� �޼���� 1�� Peer���� ��Ÿ��� bypass ���·� ���� ��ȯ�Ѵ�.
		- �� �޼��� ȣ�� �� ���浵 direct P2P�� �� �� ���� �ǹǷ� ���浵 �� �޼��带 ȣ���ؾ� �� ���� �ִ�.
		- direct P2P�� �̹� �ƴ� ��쿡�� �� �޼���� ���� Ȧ��Ī�Ǿ��� ������ ä���ش�.

		\param peerID ���� bypass�� ����� peer�� HostID
		\param outDirectP2PInfo ���� bypass�� peer�� �� CNetClient�� P2P ����� �ϱ� ���� CNetClient�� ���������� ���� �ִ� Ȧ��Ī ������ ä���� ��.
		\return ��� �Ǿ �����ϸ� ��� �Ǿ���� Ȧ��Ī�� �� ���� �־��ų� direct P2P�� �����ϰ� �־��ٸ� true�� �����Ѵ�.

		\~english
		Shuts UDP socket that is possessed internally then forcefully converts server and P2P communication to bypass state
		- Used in <a target="_blank" href="http://guide.nettention.com/cpp_en#use_alternative_p2p" >Communicating with a separated UDP socket based on ProudNet hole-punched information without using ProudNet.</a>
		- CNetClient has the same number of UDP sockets as the number of peers that are P2P communiating with and each of UDP sockets manages the communication with each peer.
		  This methos forcefully converts 1 communication with peer to bypass state.
		- Since the opponent cannot use direct P2P after calling this method, the opponent may call this method as well.
		- Also fills previously hole-punched info when not direct P2P

		\param peerID HostId of opponent peer that to be forcefully bypassed
		\param outDirectP2PInfo where the hole-punching information that was possessed by CNetClient in order to perform P2P communication between this CNetClient and forcefully bypassed peer.
		\return Returns true either if hole-punched with opponent peer while opponent peer exists OR sustained direct P2P.

		\~chinese
		???ݻ��UDP socket��˭�??��?����P2P�����bypass??��
		- �<a target="_blank" href="http://guide.nettention.com/cpp_zh#use_alternative_p2p" >������ProudNet��������ProudNet��������?��?����UDPSocket?������</a>%���ġ�
		- CNetClient%?�����?��?��P2P����peer??��UDP socket����?UDP socket???����peer�����ᡣ�۰���bypass??��˭�???��?peer�����ᡣ
		- ��У�۰����?۰���������direct P2P����?۰�ʦ�����У�۰����
		- ����direct P2P����?���۰���?��?�������������ӡ�

		\param peerID �˭�bypass��?۰peer��Host ID��
		\param outDirectP2PInfo ˭�bypass��peer��� CNetClient%?��P2P���ᣬ CNetClient%�?ݻ?��������������?�����۰��
		\return ���?۰peer����???۰peer���������?�direct P2P��?����true��

		\~japanese
		?ݻ�ܪ��êƪ���UDP�����ëȪ��ͪ��ơ���?��?�����P2P�����Ы��ѫ�?����?�﷪��𪨪ު���
		- \ref use_alternative_p2p ���Ū��ު���
		- CNetClient��P2P����򪷪ƪ���Peer��?������UDP�����ëȪ��êƪ��ơ���?��UDP�����ëȪϪ������ު�Peer�Ȫ������??���ƪ��ު������Ϋ᫽�ëɪ�1����Peer�Ȫ�����Ϊߪ�Ы��ѫ�?����?�﷪��𪨪ު���
		- ���Ϋ᫽�ëɪ������󪷪�������⢪�direct P2P���Ū��ʪ��ʪ�ު��Ϊǡ���⢪⪳�Ϋ᫽�ëɪ������󪹪��Ȫ�Ǫ��ު���
		- direct P2P�ǪϪʪ�����˪⪳�Ϋ᫽�ëɪ�Φ�۪˫�?��ѫ���󫰪��쪿���ê�?�����ƪ���ު���
		
		\param peerID ?�˫Ы��ѫ�������⢪�Peer��HostID		
		\param outDirectP2PInfo ?�˫Ы��ѫ����쪿peer�Ȫ���CNetClient��P2P������������ᡢCNetClient��?ݻ�ܪ��êƪ�����?��ѫ�������ê�?�������ᶡ�\return ���Peer����������Peer�ȪΫ�?��ѫ���󫰪����쪿���Ȫ����ê��Ȫ���direct P2P���򥪷�ƪ�����true��꫿?�󪷪ު��� 

		\~
		*/
		virtual bool InvalidateUdpSocket(HostID peerID, CDirectP2PInfo &outDirectP2PInfo ) = 0;

		/**
		\~korean
		InvalidateUdpSocket���� ���ŵ� UDP socket�� �ٽ� �����.
		�׸��� �ش� ����� peer���� UDP Ȧ��Ī�� �簳�Ѵ�.
		- <a target="_blank" href="http://guide.nettention.com/cpp_ko#use_alternative_p2p" >ProudNet�� ���� �ʰ� ProudNet�� Ȧ��Ī ������ ���� ���� UDP �������� ����ϱ�</a>  ���� ���ȴ�.
		- �� �޼��带 ȣ���Ѵٰ� �ؼ� ��� UDP socket�� ����������� �ʴ´�. ���� ������� UDP ������ �ּҸ� ��������
		��� �Ŀ� GetLocalUdpSocketAddr�� ȣ���ؼ� ���;� �Ѵ�.
		- �� �޼��� ȣ�� �� ���浵 direct P2P�� �� �� �־�� �ϹǷ� ���浵 �� �޼��带 ȣ���ؾ� �� ���� �ִ�.

		\param peerID ������ InvalidateUdpSocket�� ����Ǿ��� �Ǿ��� ID.
		\return ���������� �Ϸ�� true. �ش� ����� peer�� ������ false.

		\~english
		 Re-creates UDP socket removed by InvalidateUdpSocket
		    And re-starts UDP hole-punching with opponent peer
		- Used at <a target="_blank" href="http://guide.nettention.com/cpp_en#use_alternative_p2p" >Communicating with a separated UDP socket based on ProudNet hole-punched information without using ProudNet.</a>
		- Calling this method does not mean immediate UDP socket creation. To get the address of newly created UDP socket, must call GetLocalUdpSocketAddr and get the address after a while.
		- Since the opponent cannot use direct P2P after calling this method, the opponent may call this method as well.

		\param peerID ID of peer that InvalidateUdpSocket was executed previously.
		\return true if successfully completed. False if there is no opponent peer.

		\~chinese
		����?����InvalidateUdpSocket?���UDP socket��
		��������?�?��??۰peer��UDP���ס�
		- �<a target="_blank" href="http://guide.nettention.com/cpp_zh#use_alternative_p2p" >������ProudNet��������ProudNet��������?��?����UDPSocket?������</a>%���ġ�
		- ?����У�۰�������?ء??��UDP socket����?������?����UDP socket������?��������УGetLocalUdpSocketAddr��?��
		- �۰����У��?۰������direct P2P����?۰���ʦ��?��У�۰����

		\param peerID ����InvalidateUdpSocket��?����peer��ID��
		\return ����������?true��?����??۰peer��?false��

		\~japanese
		InvalidateUdpSocket����۪��쪿UDP socket����ª�ު��� 
		��������?��⢪�Peer�Ȫ�UDP��?��ѫ���󫰪���Ҫ��ު���
		- \ref use_alternative_p2p ���Ū��ު���
		- ���Ϋ᫽�ëɪ������󪹪Ȫ��ê�������UDP socket���ª��몳�ȪϪ���ު����檿���ª�쪿UDP�����ëȪΫ��ɫ쫹����몿��˪ϡ����Ъ骯����GetLocalUdpSocketAddr�������󪷪���ƪ�����驪�����ު���
		- ���Ϋ᫽�ëɪ������󪷪�������⢪�direct P2P���Ū����Ȫ��Ǫ��ʪ���Ъʪ�ʪ��Ϊǡ���⢪⪳�Ϋ᫽�ëɪ������󪹪��Ȫ⪢��ު���
		\param peerID �������InvalidateUdpSocket��������쪿Peer��ID
		\return �����ܪ���������true����?�������Peer���ʪ����false��

		\~
		*/
		virtual bool RestoreUdpSocket(HostID peerID) = 0;

		// ����ڴ� �̰� ���� ����
		virtual void TEST_FallbackUdpToTcp(FallbackMethod mode) = 0;

		virtual void TEST_EnableVirtualSpeedHack(int64_t multipliedSpeed)=0;

		virtual void TEST_SetPacketTruncatePercent(Proud::HostType hostType, int percent) = 0;

		/**
		\~korean
		P2P���� Reliable �޽�¡ �ý����� �۵� ��踦 ��´�.
		- ���� �����̳� ����� ���� ���� ���ȴ�.

		\~english
		Gets operation statistics of reliable messaging system among P2P
		- Used for performance test or debugging

		\~chinese
		?��P2P��?��Reliable messagingͧ?��????��
		- ?����?�����??������ġ�

		\~japanese
		P2P���Reliable��ë�?���󫰫����ƫ��������ͪ����ު���
		- �������Ҫ�ǫЫë��󫰪ʪɪΪ�������Ī���ު��� 

		\~
		*/
		virtual bool GetPeerReliableUdpStats(HostID peerID,ReliableUdpHostStats &output) = 0;

		/**
		\~korean
		�� Ŭ���̾�Ʈ�� ������ �ڿ� �ִ� Ŭ���̾�Ʈ�ΰ�?
		\return �Ǵ��� �� ������ false ����. �̶� output�� ��ä������.
		\param output ������ �ڿ� �ִ� Ŭ���̾�Ʈ�̸� true�� ä������.

		\~english
		Is this client behind a router?
		\return returns false if cannot be verified. The output will not be filled at this time.
		\param output Fills true if the client is behind a router

		\~chinese
		�client�������������client?��
		\return ������?��?����false��??����?��output��
		\param output �����������client��??��true��

		\~japanese
		���Ϋ��髤����Ȫ���?��?������˪��뫯�髤����ȪʪΪ���
		\return ��?�Ǫ��ʪ����false��꫿?�󡣪�������output��?������ު��� 
		\param output ��?��?������˪��뫯�髤����ȪǪ����true��?������ު��� 

		\~
		*/
		virtual bool IsLocalHostBehindNat(bool &output) = 0;

		/**
		\~korean
		���� �������� ������ ��´�. �� ���� Ŭ���̾�Ʈ���� ��� ���� �������� ������ �ٸ��� ������ ����ȴ�.

		\~english
		Gets the version of engine protocol. If this value differes to engine protocol version from client then the connection will not be accepted.

		\~chinese
		?������??���⡣�???client?��������??����������?����??�ȡ�

		\~japanese
		���󫸫�׫�ȫ����?��������ު��������������髤����Ȫ����뫨�󫸫�׫�ȫ����?�������ުê���?�����ɪ���ު���
		\~
		*/
		virtual int GetInternalVersion() = 0;

		/**
		\~korean
		�ְ���� �� �ִ� RMI Ȥ�� ����� ���� �޽����� �ִ� ũ���.

		\~english
		The maximum size of RMI or user defined message

		\~chinese
		��?����RMI�����?��?��������������᳡�

		\~japanese
		�������Ǫ���RMI�ު��ϫ�?��?������ë�?�������ޫ������Ǫ���
		\~
		*/
		virtual int GetMessageMaxLength() = 0;

		/**
		\~korean
		�������� �νĵ�, �� Ŭ���̾�Ʈ�� ��Ʈ��ũ �ּҸ� ��´�. ��, �� ���� ���ͳ� �ּ�(external addr)�̴�.
		- ������ ����Ǿ� �������� ��ȿ�� ���� �����Ѵ�.

		\~english
		Gets the network address of this client that is recognized by server. In other words, this is a public Internet address(external address).
		- Returns effective values only when connected to server

		\~chinese
		?��?��?��??�ܣ��client��??�򣡣?��?��??�򣣨external addr����
		- ��?��?��?����?����������?��

		\~japanese
		��?��?������۪��쪿���Ϋ��髤����ȪΫͫëȫ�?�����ɫ쫹����ު���?�����ѫ֫�ë�����?�ͫëȫ��ɫ쫹(external addr)�Ǫ���
		- ��?��?����?����ƪ������Ϊ���?������꫿?�󪷪ު���

		\~
		*/
		virtual AddrPort GetPublicAddress() = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#thread_pool" >������ Ǯ(Thread pool)</a> �� �� �������� ������ ����ϴ�.
		\param output ���⿡ ������ ä�����ϴ�.

		\~english
		Gets the information of each thread of <a target="_blank" href="http://guide.nettention.com/cpp_en#thread_pool" >Thread pool</a>
		\param output this is where the information has filled in.

		\~chinese
		?��<a target="_blank" href="http://guide.nettention.com/cpp_zh#thread_pool" >?���(Thread pool)</a>%����?�����ӡ�
		\param output ��?��?�����ӡ�

		\~japanese
		\ref thread_pool��������ëɪ����ê���ު���
		\param output ���������ê�?������ު���

		\~
		*/
		virtual void GetUserWorkerThreadInfo(CFastArray<CThreadInfo> &output) = 0;

		/**
		\~korean
		��Ʈ��ŷ �������� ������ ����ϴ�.
		ProudNet�� <a target="_blank" href="http://guide.nettention.com/cpp_ko#thread_pool" >������ Ǯ(Thread pool)</a> �� ������ ��Ʈ��ũ I/Oó���� ����ϴ� �����尡 ����Ǿ� �ֽ��ϴ�. �̰��� ������ ����ϴ�.
		\param output ���⿡ ������ ä�����ϴ�.

		\~english
		Gets the information of networking thread
		ProudNet has a thread that manages network I/O that is independent to <a target="_blank" href="http://guide.nettention.com/cpp_en#thread_pool" >Thread pool</a>. This gets the information of the thread.
		\param output This is where the information is filled.

		\~chinese
		?��???�����ӡ�
		ProudNet��?<a target="_blank" href="http://guide.nettention.com/cpp_zh#thread_pool" >?���(Thread pool)</a>���ң�?��?��??I/O?����?�?��?�����ӡ�
		\param output ��?��?�����ӡ�

		\~japanese
		�ͫëȫ�?���󫰫���ëɪ����ê���ު���
		ProudNet��\ref thread_pool�Ȫ�ܬ�˫ͫëȫ�?��I/O?���??���뫹��ëɪ�??����ƪ��ު�����������ê���ު���
		\param output ���������ê�?������ު��� 

		\~
		*/
		virtual void GetNetWorkerThreadInfo(CFastArray<CThreadInfo> &output) = 0;

		/**
		\~korean
		ProudNet�� ���� ������� socket handle ���� ����ϴ�. �� ����� Ŭ���̾�Ʈ ���� ����Ʈ����(���� nProtect�� Ahnlab Hack Shield ��)���� �ʿ�� �� ��� �����մϴ�.
		�� �޼��带 ���� ���� socket handle�� ���� ȹ�� �뵵�θ� ����Ͻð�, I/O ó���� �����ϴ� ���� �����մϴ�. ���ۿ��� ���� �� �ֱ� �����Դϴ�.

		\param remoteHostID ���� ������ ���� peer�� HostID�Դϴ�. HostID_Server�� ��� ������ ����� ���� ������ ����ϴ�.
		\param output ���⿡ ������ ä�����ϴ�.
		\return remoteHostID ���� ��ȿ�� ��� true�Դϴ�.

		\~english
		Gets socket handles that made by ProudNet. This function is useful when it need at security software(e.g. nProtect or Ahnlab Hack Shield)
		Please use socket handle from this method for getting information. Do not excute I/O process. Because it may occur bed reaction.

		\param remoteHostID HostID of peer that getting socket information. If it is HostID_Server then it gets socket information from connected server.
		\param output Information fill in here
		\return remoteHostID It is true, if value is available.

		\~chinese
		?����ProudNet?����socket handle��������client����?�죨����nProtect���Ahnlab Hack���������?�����ġ�
		��?�۰��?����socket handle��������?��������Բ�����?��I/O ?�⡣��?ʦ���������ġ�

		\param remoteHostID ?��socket��peer��Host ID��������HostID_Server��??��?��?��?����socket���ӡ�
		\param output ��?��?�����ӡ�
		\return remoteHostID?������?true��

		\~japanese
		ProudNet�˪�ê��ª�쪿socket handle����ު�������Ѧ���ϫ��髤����ȫ������ƫ����իȫ�����(?�ˡ�nProtect�Ȫ�Ahnlab Hack Shield�ʪ�)����驪Ȫ�����������ĪǪ���
		���Ϋ᫽�ëɪ��ת���socket handle������������Բ�ǪΪ��Ūêơ�I/O?����������몳�Ȫ����Ǫ��������Ī�������몫��Ǫ���
		\param remoteHostID �����ë����ê����Peer��HostID�Ǫ���HostID_Server�����ꡢ��?��?����?���쪿�����ë����ê���ު���
		\param output ���������ê�?������ު���
		\return remoteHostID ������?�����ꡢtrue�Ǫ��� 

		\~
		*/
		virtual bool GetSocketInfo(HostID remoteHostID,CSocketInfo& output) = 0;

		/**
		\~korean
		CNetClient�� ����ϴ� �������α׷� ���¸� CNetClient���� �����մϴ�.
		CNetClient�� ������ ������ �ٸ� �����忡�� �����Ű�� ������ ��� ������ ����Ʈ�� CNetClient�� ���� ������ �� ��� ����ڰ� ���� �����ؾ� �մϴ�.
		- �ƹ����� ȣ���ص� ���ɿ� ������ ���� ���ݴϴ�.
		- �� �޼���� �پ��� ���, ���� <a target="_blank" href="http://guide.nettention.com/cpp_ko#super_peer" >Super Peer(�����Ǿ� Ȥ�� ȣ��Ʈ) �߽��� P2P ��Ʈ��ŷ</a> ��� ��� ����մϴ�.

		\~english
		Passes the status of application program that uses CNetClient to CNetClient
		User must measure the frame rate of the game that runs CNetClient in diffrent thread to rendering loop since it cannot be acquired directly by CNetClient.

		- Does not affect performance even called at any time
		- Various functions of this method can be used, e.g. <a target="_blank" href="http://guide.nettention.com/cpp_en#super_peer" >P2P Networking for Super Peer (Super Peer or host)</a> function.

		\~chinese
		? CNetClient%??���� CNetClient%��?������??��
		�����loop������?��?������?��?���� CNetClient%��������ߩ��?�㣬�����?�����?��?�ҡ�
		- ��?�??����У��?������?����?���?��
		- �۰�������?�����������<a target="_blank" href="http://guide.nettention.com/cpp_zh#super_peer" >Super Peer(�����) ������P2P����</a>%�����������ġ�
		\~
		\~japanese
		CNetClient�����Ī��뫢�׫꫱?������?����CNetClient��?ӹ���ު���
		CNetClient�����?��󫰫�?�ת���Ϋ���ëɪ�?�������뫲?������ꡢ�ի�?���?�Ȫ�CNetClient������ߩ��Ǫ�������?��?�����������Ҫ��ʪ���Ъʪ�ު��� 
		- ���������󪷪ƪ������˪۪���ª�?���ު���
		- ���Ϋ᫽�ëɪ���?��Ѧ����?��\ref super_peer Ѧ���ʪɪ����Ī��ު��� 
\~
		*/
		virtual void SetApplicationHint(const CApplicationHint &hint) = 0;

		/**
		\~korean
		����� ���� �޽����� �����մϴ�. �ڼ��� ���� <a target="_blank" href="http://guide.nettention.com/cpp_ko#send_user_message" >RMI�� ���� �Ⱦ��� ����� ���� �޽����� �ְ� �ޱ�</a> �� �����Ͻʽÿ�.
		\param remotes ������ �迭�Դϴ�. RMI�� ����������, Ŭ���̾�Ʈ, ����(HostID_Server), <a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P �׷�</a> ���� ���� �� �ֽ��ϴ�.
		\param remoteCount ������ �迭 ũ��
		\param rmiContext �۽� �ΰ�����. �ڼ��� ���� <a target="_blank" href="http://guide.nettention.com/cpp_ko#protocol_overview" >ProudNet�� �������� ����</a> �� �����Ͻʽÿ�.
		\param payload ���� �޽��� ������
		\param payloadLength ���� �޽��� �������� ����. ����Ʈ �����Դϴ�.

		\~english
		Send user defined message. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#send_user_message" >Exchanging user-defined message without using RMI at all</a> for more detail
		\param remotes Receiver array. You can put client, server(HostID_Server), <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a>, etc like RMI.
		\param remoteCount Size of receiver array
		\param rmiContext Additional information of sending. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#protocol_overview" >Protocol type of ProudNet</a>
		\param payload Message data for sending.
		\param payloadLength Length of sending message data. It is byte.

		\~chinese
		?����?��?���ӡ�????��<a target="_blank" href="http://guide.nettention.com/cpp_zh#send_user_message" >����������RMI��?��?��?����</a>%��
		\param remotes ����??��?RMI��?��ʦ�?��client����?�HostID_Server����<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%����
		\param remoteCount ����??��᳡�
		\param rmiContext ?������ݾʥ���ӡ�????��<a target="_blank" href="http://guide.nettention.com/cpp_zh#protocol_overview" >ProudNet ��??????</a>%��
		\param payload �?��������?�ߡ�
		\param payloadLength �?��������?��?����Byte ?�ȡ�
		\~
		\~japanese
		��?��?������ë�?����?�ꪷ�ު����٪����ϡ�\ref send_user_message��?�Ϊ���������
		\param remotes �������֪�Ǫ���RMI����?�ˡ����髤����ȡ���?��?(HostID_Server)��\ref p2p_group�ʪɪ�����몳�Ȫ��Ǫ��ު���
		\param remoteCount �������֪������
		\param rmiContext ������ʥ���á��٪����ϡ�\ref protocol_overview��?�Ϊ���������
		\param payload ����ë�?����?��
		\param payloadLength ����ë�?����?�����������Ы���?�ȪǪ���
\~
		*/
		virtual bool SendUserMessage(const HostID* remotes, int remoteCount, const RmiContext &rmiContext, uint8_t* payload, int payloadLength) = 0;

		/**
		\~korean
		����� ���� �޽����� �����մϴ�. �ڼ��� ���� <a target="_blank" href="http://guide.nettention.com/cpp_ko#send_user_message" >RMI�� ���� �Ⱦ��� ����� ���� �޽����� �ְ� �ޱ�</a> �� �����Ͻʽÿ�.
		\param remote ������
		\param rmiContext �۽� �ΰ�����. �ڼ��� ���� <a target="_blank" href="http://guide.nettention.com/cpp_ko#protocol_overview" >ProudNet�� �������� ����</a> �� �����Ͻʽÿ�.
		\param payload ���� �޽��� ������
		\param payloadLength ���� �޽��� �������� ����. ����Ʈ �����Դϴ�.

		\~english
		Sending user defined message. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#send_user_message" >Exchanging user-defined message without using RMI at all</a> for more detail.
		\param remote receiver
		\param rmiContext Additional information of sending. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#protocol_overview" >Protocol type of ProudNet</a>.
		\param payload Message data for sending.
		\param payloadLength Length of sending message data. It is byte.

		\~chinese
		?����?��?���ӡ�????��<a target="_blank" href="http://guide.nettention.com/cpp_zh#send_user_message" >����������RMI��?��?��?����</a>%��
		\param remote ����
		\param rmiContext ?������ݾʥ���ӡ�????��<a target="_blank" href="http://guide.nettention.com/cpp_zh#protocol_overview" >ProudNet ��??????</a>%��
		\param payload �?��������?�ߡ�
		\param payloadLength �?��������?��?����Byte ?�ȡ�

		\~japanese
		��?��?������ë�?����?�ꪷ�ު����٪����ϡ�\ref send_user_message��?�Ϊ���������
		\param remote �����
		\param rmiContext ������ʥ���á��٪����ϡ�\ref protocol_overview��?�Ϊ���������
		\param payload ����ë�?����?��
		\param payloadLength ����ë�?����?�����������Ы���?�ȪǪ���

		\~
		*/
		inline bool SendUserMessage(HostID remote, const RmiContext &rmiContext, uint8_t* payload, int payloadLength)
		{
			return SendUserMessage(&remote,1,rmiContext,payload,payloadLength);
		}

		/** \~korean Coalesce interval�� �������� �����մϴ�.
		ProudNet ��ü���� �����Ǵ� ��Ʈ��ũ ǰ�� ��� ������ ���� ������ ����� ������ �ʴ� ǰ���� ���ö� ����Ͻʽÿ�.
		�������� ���� ���� �Է��� ��� �ǵ����� ���� ����� �ʷ��� �� ������ �����Ͻʽÿ�.
		\~english Manually set coalesce interval.
		Use this function if you do not satisfy to the quality of coalesce feature of ProudNet.
		Inapprpriate use of this function may cause unexpected behavior, so care must be taken.

		\~japanese
		Coalesce interval����Ѫ����Ҫ��ު���
		ProudNet �?�����Ҫ����ͫëȫ�?�����������Ϋ�?�������Ѧ�����Ъުʪ������˪ʪ������Ūêƪ���������
		��﷪ǪϪʪ����������������ꡢ��?���ʪ�̿����?�檹�몳�Ȫ�����ު��ΪǪ���򪯪�������

		\~
		*/
		virtual ErrorType SetCoalesceIntervalMs(HostID remote, int intervalMs) = 0;

		/** \~korean Coalesce interval�� �ڵ����� �����մϴ�. �� ������ ����Ʈ�Դϴ�.
		\~english Coalesce interval set to automatic. This is default.

		\~japanese
		Coalesce interval��������Ҫ��ު����������Ҫϫǫի���ȪǪ���
		\~
		*/
		virtual ErrorType SetCoalesceIntervalToAuto(HostID remote) = 0;

/**
		\~korean
		��� �α׸� ��� �α� ���� ����(CEmergencyLogServer)�� �����մϴ�. CEmergencyLogServer�� ���� �����ϼž� �ش����� ���� �ֽ��ϴ�.
		- CStartServerParameter.m_clientEmergencyLogMaxLineCount�� ������ �����ϼž� �մϴ�.
		- �ǵ����� �ʰ� �������� ������ ���� ���, �ش��Լ��� ȣ���ϸ� Ŭ���� �ֱ� ��Ȳ�� ���� ���·α׸� CEmergencyLogServer�� �����մϴ�.
		- logClient�� ���ο��� ���ο� thread�� �����Ͽ� �α� Ŭ���̾�Ʈ�� ����� �ٷ� ������ �αװ� ���۵˴ϴ�. ���� �� �޼��� call �� �ٷ� ���� �����带 �������� ���ƾ� �մϴ�.
		\param serverAddr �α׼��� �ּ��Դϴ�.
		\param serverPort �α׼����� ��Ʈ��ȣ�Դϴ�.
		\return ����, ���� �����Դϴ�. m_clientEmergencyLogMaxLineCount ���� 0�� ��찡 �̿��ش�˴ϴ�.

		\~english TODO:translate needed.
		The emergency log is transmitted to the emergency log collection server (CEmergencyLogServer). You have to run CEmergencyLogServer first in order to use its feature. 	
		- You have to designate the number of CStartServerParameter.m_clientEmergencyLogMaxLineCount. 
		- When the connection to the server is lost unintentionally, the current status log as well as the latest status of the client is transmitted to CEmergencyLogServer. 
		- logClient generates a new thread inside and create a log client and the log is directly transmitted to the server. Therefore, you must not end the main thread after calling this method. 
		\param serverAddr This is the address of the log server. 
		\param serverPort This is the port number of the log server. 
		\return This is either success or failure. The case when the value of m_clientEmergencyLogMaxLineCount is 0 falls under this case. 


		\~chinese
		��?��log?����?��log����?�CEmergencyLogServer������?�� CEmergencyLogServer%��������������
		- ���� CStartServerParameter.m_clientEmergencyLogMaxLineCount%��??��
		- ު��?��???����?������У��?��?��?���� CEmergencyLogServer%?��client������??��?�??log��
		- logClient�?ݻ������thread??��log client��ء?����?��?��log��������У�۰������?���ء??��?�
		\param serverAddr log��?���򣡣
		\param serverPort log��?��ӮϢ??��
		\return ����?���� m_clientEmergencyLogMaxLineCount ��0����??��󮡣

		\~japanese
		������������?󢫵?��?(CEmergencyLogServer)��?�ꪷ�ު���CEmergencyLogServer��໪�?�����ƪ�����?Ѧ�����Ū����Ȫ��Ǫ��ު���		
		- CStartServerParameter.m_clientEmergencyLogMaxLineCount��?����Ҫ��ʪ���Ъʪ�ު���
		- ��?�����˫�?��?�Ȫ���?��﷪쪿���ꡢ��???�������󪹪ȫ��髤����Ȫ�����?�Ϫ����?������CEmergencyLogServer��?�ꪷ�ު���
		- logClient��?ݻ���檷������ëɪ��������ƫ����髤����Ȫ��ªêƪ�����?��?�˫���?�ꪵ��ު�����êơ����Ϋ᫽�ëɪ������󪷪����������᫤�󫹫�ëɪ��������ƪϪ����ު���
		\param serverAddr ����?��?���ɫ쫹�Ǫ���
		\param serverPort ����?��?�Ϋ�?����?�Ǫ���
		\return ��������ʦ���Ǫ���m_clientEmergencyLogMaxLineCount ����0�Ǫ������ꪬ�������?���ު���

		\~
		*/
		#if defined(_WIN32)
		virtual bool SendEmergencyLogData(String serverAddr, uint16_t serverPort) = 0;
		#endif

		/**
		\~korean
		�ʹ� �������� ������ ������� ���ϸ� ������ �����ϱ� ���� Ÿ�� �ƿ� �Ӱ谪(�и��ʴ���)�� �����Ѵ�. 
		- CNetClient.Connect ȣ�� ������ ����� �� �ִ�. �� ���ĺ��� ȣ���� ��� ���õȴ�. 
		- �������� ��� ���� ��õ���� �ʴ´�. ������ ���� ������ ������ ���� ����� �ڸ���� �����̴�. �׷����� ���� 1�ð��� �Ŵ� ���� ����. 
		- OnJoinServerComplete�� �� ���Ŀ��� Server���� �����Ѱ��� ��� ����ȴ�. 
		- Ŭ���̾�Ʈ���� �̰��� ���� �����Ҽ� �ְ� �� ������ �������� ������ ���� �������� Ŭ���̾�Ʈ���� ��ü������ default���� 10�ʰ� �Ǹ� ��������⶧���̴�. 
		- �⺻���� ProudNetConfig.DefaultNoPingTimeoutTime�̴�. 
		- ����: \ref debug_pause_problem 

		\~english
		If not communicating with the server for too long, 
		- It can only be used before calling CNetClient.Connect. If called afterwards, it is ignored. 
		- We do not recommend setting it as limitless. When disconnecting an abnormal connection, it is set as a connection left limitlessly. You might as well set it for one hour. 
		- After OnJoinServerComplete is displayed, the value set in the server is saved instead. 
		- The reason why this value can be set separately in the client is because if it reaches 10 seconds, which is the own default value in the client, before the value set in the server comes, it disconnects. 
		- The default value is ProudNetConfig.DefaultNoPingTimeoutTime
		- Reference: \ref debug_pause_problem

		\~chinese

		\~japanese
		���ު�˪�������˫�?��?�����᪬�Ǫ��ʪ��ʪ����?����𶪹�몿��Ϋ����ૢ������ͣ��(�߫���?��)����Ҫ��ު���
		- CNetClient.Connect ����������Ϊ����Ī��몳�Ȫ��Ǫ��ު���������������������������ʪ���ު���
		- ���ڪ˪��몳�ȪϪ�?�᪷�ު��������?����������ڪ�?����?�˪ʪ몫��Ǫ����ʪΪǡ��ષ��1����򪫪���۰���ު��Ǫ���
		- OnJoinServerComplete�����ƪ��쪿���˪�Server�����Ҫ������������������ު���
		- ���髤����ȪǪ�������ܬ����ҪǪ���誦�˪�����릪ϡ���?��?�����Ҫ�������?����˫��髤����Ȫ��?�ܪ�Default���Ǫ���10���˪ʪ��﷪êƪ��ު�����Ǫ���
		- ��������ProudNetConfig.DefaultNoPingTimeoutTime�Ǫ���
		- ?�ţ�\ref debug_pause_problem 

		\~
		*/
		virtual void SetDefaultTimeoutTimeMs(int newValInMs) = 0;

		virtual AddrPort GetTcpLocalAddr() = 0;
		virtual AddrPort GetUdpLocalAddr() = 0;

		virtual String TEST_GetDebugText() = 0;
		virtual void TEST_GetTestStats(CTestStats2 &output) = 0;

		// ACR test��
		virtual void TEST_FakeTurnOffSendAndReceive() = 0;
		virtual void TEST_SetAutoConnectionRecoverySimulatedDelay(int timeMs) = 0;

#ifdef TEST_DISCONNECT_CLEANUP
		virtual bool IsAllCleanup() = 0;
#endif
		/**
		\~korean
		����ڰ� ������ �ٸ� P2P peer���� ����� ������ relay�� �ǰ� ������ �����ϴ� �Լ��Դϴ�.

		�� ����� ����ϰ� ���̴� ���� ������ �����ϴ�.
		- Ŭ���̾�Ʈ���� P2P ��ŷ��� �����ؼ�, ��� P2P peer���� ����� relay�� ��ȯ�ϰ��� �� ���
		\param remotePeerID Relay ��ȯ��ų Peer �� HostID���Դϴ�.
		\param enable true�̸� ���� relay �� �մϴ�.

		\~english TODO:translate needed.
		This is the function to designate whether the communication with other P2P peers designated by the user should be forced to relay. The following are the cases where this feature comes handy. 
		- When the P2P traffic from the client side is excessive so you want to convert some communication with some P2P peers to relay;
		\param remotePeerID The HostID value of the peer to be converted to relay
		\param enable If true is enabled, forced relay is turned on. 

		\~chinese
		���������?��?�����?����P2P Peer?������˭�?��relay����?��
		��?����������������??������
		��?Ӯ��P2P������?��?����???P2P Peer?������??��relay��?����
		\param remotePeerID Relay�??��Peer��HostID?��
		\param enable ������true???˭�relay��

		\~japanese
		��?��?����Ҫ������P2P Peer�Ȫ������?��relay���몫����Ҫ���??�Ǫ�������Ѧ������?���Ū�����������ת�Ǫ���
		- ���髤���������P2P����������Φ���ơ������Ī���P2P Peer�Ȫ������relay��﷪��𪨪������ꡢ
		\param remotePeerID Relay ﷪��𪨪�Peer��HostID���Ǫ���
		\param enable true�Ǫ����?�relay��Ī��ު���

		\~
		*/
		virtual ErrorType ForceP2PRelay(HostID remotePeerID, bool enable) = 0;

		/**
		\~korean
		�Ϲ����� �¶��� ���ӿ����� unreliable �޽�¡�� ��ü Ʈ������ ��κ��� �������Կ� ���� ���� unreliable �޽�¡ ��ɿ� Ʈ���� �ν����� ��� ����� �߰��մϴ�.
		��Ŷ �ν��� ������
		\param remoteHostID ��� remote ���� ��ſ� ���� �ν����� ���� ������. �ڱ� �ڽ� peer, server ������ �Է� �����մϴ�. �ڱ� �ڽ��̸� 0% �Դϴ�
		\param outputPercent ��Ŷ �ν����� %������ ä����(�� 0~100)

		\~english TODO:translate needed.
		As unreliable messaging takes most of the entire traffic in common on-line games, we add the feature to get the traffic loss rate in the existing unreliable messaging feature. 
		Packet loss rate measuring device
		\param remoteHostID Which loss rate with communication with which remote would be obtained. You can input anything, including your own peer, server, etc. If it is itself, it is 0%
		\param outputPercent The packet loss rate is filled up in % unit (i.e., 0 to 100) 

		\~chinese
		������?��?��?Unreliable������??���������?��ݻ��?������Unreliable��������߾��ʥ?��������Loss����������
		?����Loss��?��?��
		\param remoteHostID �?��??��?remote?������Loss�㣬ʦ�?�������Peer��server ���������������???0%��
		\param outputPercent  ?������Loss��?�%?��?������?0~100��
		
		\~japanese
		�����ܪ˫���髤��?��Ǫ�unreliable��ë�?���󫰪���?�ȫ�ի��ë��Ϊ۪Ȫ�ɪ�￪�ު��Ϊǡ�?���unrelable��ë�?����Ѧ���˫ȫ�ի��ë���������Ѧ������ʥ���ު���
		�ѫ��ëȫ�������Ѧ
		\param remoteHostID �ɪ�remote�Ȫ������?����������몫���������peer��server���Ǫ�����ʦ���Ǫ���������Ǫ����0%�Ǫ���
		\param outputPercent �ѫ��ëȫ��㪬%?�Ȫ�?������ު�(?����0~100)

		\~
		*/
		virtual ErrorType GetUnreliableMessagingLossRatioPercent(HostID remotePeerID, int *outputPercent) = 0;
	};

	PROUD_API const PNTCHAR* ToString(ConnectionState cs);

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
