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
#include "FakeClr.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	class CThreadPool;

	/** \addtogroup net_group
	*  @{
	*/

	/**
	\~korean
	������ �����ϱ� ���� ���� ����ü

	\~english
	Informtion structure of making server connection

	\~chinese
	?��?����?��������?��?��

	\~japanese
	��?��?����?���몿�������ϰ��?
	\~
	 */
	class CNetConnectionParam
	{
	public:
		/**
		\~korean
		������ ������ �ּ�
		- ��: 111.222.111.222(IP �ּҽ�) Ȥ�� game.mydomain.net(ȣ��Ʈ �̸���)
		- ��Ʈ���� �׽�Ʈ�� �ϴ� ��쿡 �Ѳ����� ���� Ŭ���̾�Ʈ�� ������ �����ؾ� �մϴ�. �̷��� ���
		���� �ּҰ� ȣ��Ʈ �̸����� ��� ���� �ӵ��� �ſ� ���� �� �ֽ��ϴ�. ���� ��Ʈ���� �׽�Ʈ�� �� ���
		���� �ּҷ� IP �ּҽ��� ���� ���� �����մϴ�.

		\~english
		Address of server to coneec to
		- ex: 111.222.111.222(IP address) or game.mydomain.net(host name)
		- During a stress test, lots of clients need to be connected to the server at the same time.
		If the server address is a type of a host name, it can be seriously laggy.
		It is strongly recommended to use IP address format for server address.

		\~chinese
		�?������?���򣡣
		- �ǣ�111.222.111.222��IP ���ң��� game.mydomain.net�����٣�ң���
		- �?��??����?����?����?��?Ӯ��??��?��?���������٣����?��?������ʦ��??ط������?��??��?����?��IP������?��?���򣡣

		\~japanese
		��?���뫵?��?�Ϋ��ɫ쫹
		- ��: 111.222.111.222(IP���ɫ쫹����)�ު��� game.mydomain.net(�۫���٣����)
		- ���ȫ쫹�ƫ��Ȫ򪹪�������������������髤����Ȫ���?��?����?���ʪ���Ъʪ�ު��󡣪��Ϊ誦������
		��?��?���ɫ쫹���۫���٣���ҪǪ������ꡢ��?������ު�Ȫ�?�����ꪬ����ު�����êơ����ȫ쫹�ƫ��Ȫ򪹪����ꡢ��?��?���ɫ쫹�Ȫ���IP���ɫ쫹���Ҫ��Ū����Ȫ�?�᪷�ު���
		\~
		 */
		String m_serverIP;

		/**
		\~korean
		������ ������ TCP ��Ʈ�Դϴ�.

		\~english
		The TCP port of the server to be connected.

		\~chinese
		�?������?��TCPӮϢ��

		\~japanese
		��?���뫵?��?��TCP��?�ȪǪ���
		\~
		 */
		uint16_t m_serverPort;

		/**
		\~korean
		IPv4 literal ���ڿ��� ������ �����ϴ��� IPv6 ��Ʈ��ũ Ŭ���̾�Ʈ������ ������ �����ϰ� ���ִ� �����Դϴ�.
		�ڼ��� ���� <a target="_blank" href="http://guide.nettention.com/cpp_ko#apple_ipv6_workaround" >Apple�� IPv6 ��å ��ȸå</a> �� �����Ͻʽÿ�.

		\~english
		It is the variable that enables connection from IPv6 network client even if connects to server by IPv4 literal string.
		For more details, please refer to tips for resolving <a target="_blank" href="http://guide.nettention.com/cpp_en#apple_ipv6_workaround" >Apple's IPv6 enforcement.</a>

		\~chinese
		It is the variable that enables connection from IPv6 network client even if connects to server by IPv4 literal string.
		For more details, please refer to tips for resolving <a target="_blank" href="http://guide.nettention.com/cpp_zh#apple_ipv6_workaround" >Apple's IPv6 enforcement.</a>

		\~japanese
		It is the variable that enables connection from IPv6 network client even if connects to server by IPv4 literal string.
		For more details, please refer to tips for resolving <a target="_blank" href="http://guide.nettention.com/cpp_jp#apple_ipv6_workaround" >Apple's IPv6 enforcement.</a>
		*/
		String m_publicDomainName1;

		/** \copydoc m_publicDomainName1 */
		String m_publicDomainName2;

 		/**
		\~korean
		Ŭ���̾�Ʈ���� �����ϴ� UDP socket�� ����� local port ��ȣ���Դϴ�.

		�� ����� ������ peer���� ���� ������ ���� 1���� UDP port�� ����մϴ�. �̶� m_localUdpPortPool ���� ������
		��Ʈ ��ȣ���� local port�� ��� UDP socket���� �����ϰ� �˴ϴ�. ���� m_localUdpPortPool���� ������
		��Ʈ ��ȣ�� ���ų� m_localUdpPortPool���� ������ ��Ʈ ��ȣ���� ��� �ٸ����� ������� ��� ������
		��Ʈ ��ȣ�� �����Ǿ� UDP socket�� �����˴ϴ�.

		�Ϲ������δ� m_localUdpPortPool ���� �׳� �νô� ���� �����ϴ�. ������ �ǵ������� local UDP socket��
		port ��ȣ�� ������ �����ϰ��� �� �� m_localUdpPortPool �ȿ� ���Ͻô� ������ �����ʽÿ�.

		\~english
		Numbers of UDP ports for newly created UDP sockets.

		This host module uses an UDP port for each server or peer connection. Values in m_localUdpPortPool are
		used for binding local UDP port to every UDP socket created by this module. Arbitrary UDP port number
		will be taken if m_localUdpPortPool is empty or no available UDP port corresponding to m_localUdpPortPool
		exists.

		In ordinary case, m_localUdpPortPool should be left unchanged. You should add values into m_localUdpPortPool
		if you want to bind some local UDP ports to UDP sockets created by this module.

		\~chinese
		���?Ӯ������UDP socket�������local port??��
		�ټ??��?��?�����peer��?�ȣ���������?UDP port��???�����m_localUdpPortPool�����ӮϢ???local port��UDP socket��
		����?���m_localUdpPortPool�����ӮϢ??������m_localUdpPortPool�����ӮϢ??Դ�?���۰��������?��������ӮϢ???�����?����UDP socket��
		��������?�����������?m_localUdpPortPool?��ӣ����˭����local UDP socket��port��?������m_localUdpPortPool��ۯ�����?��

		\~japanese
		���髤����Ȫ���������UDP socket�����Ī���Local port��?�Ǫ���
		���Ϋ⫸��?��ϫ�?��?�Ȫ�peer�Ȫ�֧̿�Ϊ���˪��쪾��1����UDP port�����Ī��ު�����������m_localUdpPortPool����Ҫ�����?����?��Local port�Ȫ���UDP socket����������誦�˪ʪ�ު����⪷��m_localUdpPortPool�����᪷����?����?���ʪ��Ȫ���m_localUdpPortPool����Ҫ�����?����?������ު�ᶪ�����������ꡢ����Ϋ�?����?����Ҫ���UDP socket����������ު���
		�����ܪ�m_localUdpPortPool���Ϫ��Ϊު��Ǫ���۰���ު��Ǫ�������������?�ܪ�local UDP socket��port��?��?����Ҫ��������ꡢm_localUdpPortPool?�����Ъ�����������ƪ���������
		\~
		 */
		CFastArray<int> m_localUdpPortPool;

		/**
		\~korean
		������ �����ϱ� ����, �������� �������� ��Ī�� ���� ���Դϴ�.
		- CNetServer.Start���� �Է��ߴ� protocol version�� �������� ������ �����մϴ�. �׷��� ���� ���
		ErrorType_ProtocolVersionMismatch�� ���� ���� �� �������� �ɴϴ�.

		\~english
		This is the value to match the protocol with servers before connecting to the severs.
		- The connection to the server with the protocol version that was input at CNetServer.Start.
		If not, ErrorType_ProtocolVerionMismatch is to be returned after connected to the server.

		\~chinese
		?����?������?��?��?��protocol������?��
		- � CNetServer.Start%?����protocol version����?��?������������??����?������?����ErrorType_ProtocolVersionMismatch��

		\~japanese
		��?��?����?������ˡ���?��?�ȪΫ׫�ȫ���ޫë��󫰪Ϊ�������Ǫ���
		- CNetServer.Start����������protocol version�ȫ�?��?�Ȫ���?�������ު��������ǪϪʪ����ꡢErrorType_ProtocolVersionMismatch����?��?��?����?�ͪȪ���?�ު���
		\~
		 */
		Guid m_protocolVersion;
		/**
		\~korean
		������ ������ �߰� ���� �����Դϴ�. INetServerEvent.OnConnectionRequest()���� �� �����Ͱ� �޾����ϴ�.

		\~english
		This is an additional connection info to be sent to the server.
 		This data is received at INetServerEvent.OnConnectRequest().

		\~chinese
		���?��?��?��ݾʥ?�����ӡ�
		� INetServerEvent.OnConnectionRequest()���?�ߡ�

		\~japanese
		��?��?�������ʥ��?���êǪ���INetServerEvent.OnConnectionRequest()�Ǫ��Ϋ�?�������������ު���
		\~
		 */
		ByteArray m_userData;

		/**
		\~korean
		�⺻���� false �Դϴ�.
		true �� ������ ��� Reliable P2P �� ���ۼӵ��� 1MB/sec�� ������ �� �����ϴ�.
		�׷��� ó�� ������ ���������ϴ�. ���� Ŭ���̾�Ʈ �׽�Ʈ�� �� ������ true �� �����Ͻʽÿ�.

		\~english
		Default is false.
		If setting it as true, Reliable P2P transmission speed cannot support 1MB/sec.
		But performance will be improved, so set it as true only for dummy client test.

		\~chinese
		����??false��
		����?�?��?true��Reliable P2P��?������?�����?1MB/sec��
		ӣ?���?��������?���?��????�??��?true��

		\~japanese
		�ǫի�������� false�Ǫ���
		true �����Ҫ�������Reliable P2P��?�������� 1MB/sec��ұ���몳�ȪϪǪ��ު���
		������?���������誯�ʪ�ު�������?���髤����ȫƫ��Ȫ򪹪������� true �����Ҫ��ƪ���������

		\~
		*/
		bool m_slowReliableP2P;

		// coalesce interval. �׽�Ʈ���̹Ƿ� ��ҿ��� �մ��� �� ��. 0�̸� �⺻�� ���͹� ������ ��ü���� �ǹ��ϸ�, �� �� ��ü�� �⺻���� 0�̴�.
		int m_tunedNetworkerSendIntervalMs_TEST;

		/**
		\~korean
		\brief Simple network protocol mode.

		�⺻���� false �Դϴ�.
		��Ŷ ĸ�� �� ���� ������� ���� Ŭ���̾�Ʈ �׽�Ʈ�� �����ϰ� �ϱ� ���ؼ� �� ���� true�� �����Ͻʽÿ�.
		��, ���񽺰� ��Ŀ�� ���ݿ� ����� ���� UDP networking�� direct P2P ����� ����� �� �����ϴ�. (��� relay �� �����մϴ�.)
		���̺� ���񽺸� ���ؼ��� false�� �����Ͻʽÿ�.

		��Ŷ ĸ�Ŀ� ���÷��� �׽�Ʈ���� ����:
		������ ���� Ŭ���̾�Ʈ�� �ڽ��� HostID�� Ȯ���� �� �����ϴ�.
		CreateP2PGroup() �� ���� P2P �׷� ���� �Լ��� ȣ���� ��� ����ġ ���� ��Ȳ�� �߻��� �� �ֽ��ϴ�.

		\~english
		\brief Simple network protocol mode.

		Default is false.
		Setting this to true allows dummy client test via packet capture and replication method.
		However, it will make service vulnerable to hackers, and does not allow UDP networking
		and direct P2P communication (will be relayed instead.)
		You should set this to false for live service.

		Notice for packet capture and replay test:
		- Each dummy client cannot identify self HostID.
		Unexpected behavior may occur if you call P2P group functions such as CreateP2PGroup().

		\~chinese
		\brief Simple network protocol mode.

		����??false��
		��?���������?���۰�ң�?��??����?Ӯ????�??��?true��
		ӣ??ʦ��?������������?���������UDP networking��Direct P2P���ᡣ��ӣ???��relay?�꣩��
		?��?���??��???�??��?false��

		?�������?Replay??����??黣�
		��??��?Ӯ����??�����HostID��
		��CreateP2PGroup()����УP2P?��?��??ʦ��??��?��??����??��

		\~japanese
		\brief Simple network protocol mode.

		�ǫի�������� false �Ǫ���
		Packet capture������۰�Ҫ�dummy client �ƫ��Ȫ�ʦ���˪��몿��˪������� true�����Ҫ��ƪ���������
		����������?�ӫ���Hacker����?����尪˪ʪꡢ UDP networking�� direct P2P������Ū����Ȫ��Ǫ��ު��� (�۪��� relay��?�ꪷ�ު���)
		Live��?�ӫ��Ϊ���˪� false�����Ҫ��ƪ���������

		Packet capture�ȫ�׫�?�ƫ���?֧?�
		��?�� dummy client ����ª� HostID�����㪬�Ǫ��ު���
		CreateP2PGroup() �Ϊ誦�� P2P����?��?֧??�����������ꡢ�������?�Ϫ�?�檹����쪬����ު���

		\~
		*/
		bool m_simplePacketMode;

		/**
		\~korean
		- OnException �ݹ� ����� ����� �� ���θ� �����մϴ�.
		- �⺻���� true�Դϴ�.
		- ���� false�� �����ϸ� ���� �ݹ鿡�� ����ġ ���� Exception �߻� �� OnException�� ȣ����� �ʰ� ũ���ð� �߻��մϴ�.

		\~english
		- Decide whether it uses OnException callback function or not.
		- Default value is true.
		- If setting it as false, when exception occurs during  user callback, crash will occur as OnException is not called.

		\~chinese
		- ??�������� OnException Callback������
		- ����?? true��
		- �������false����?�Callback?����?������������ Exception ?��OnException?���������?��Crash��

		\~japanese
		- OnException CallbackѦ�������Ī��몫�ɪ�������?���ު���
		- �ǫի��������true�Ǫ���
		- �⪷false����Ҫ���ȫ�?��?Callback�������̪Ǫ��ʪ�Exception��?�檷������OnException�������󪵪쪺�˫���ë��媬?�檷�ު���
		\~
		*/
		bool m_allowOnExceptionCallback;

		/**
		\~korean
		������ Ŭ���̾�Ʈ�� NAT ����� �ڿ� �ִ� ���¿��� �ٸ� Ŭ���̾�Ʈ�� P2P ����� �ؾ� �� ��� �ʿ��� �� �ֽ��ϴ�.
		���� Ŭ���̾�Ʈ�� ���� �÷��̸� ó���ϴ� super peer�� �Ǿ�� �ϴ� ���,
		�׸��� super peer�� ������ ���� host�� ���,
		super peer �ȿ����� ���⿡ super peer�� public �ּҸ� �����ñ� �ٶ��ϴ�.

		\~english
		It is variable used when trying to set the clients' external address by force.
		It might be necesaary to make a P2P communication with other clients when a server and client is behind the NAT router.
		For example, if it should be the super peer that the client deal with game play and if it is the host that has a same server with the super peer, put the public address of the super peer here in the super peer.

		\~chinese
		��?��˭�?����?Ӯ����ݻ����?��������?�ᡣ
		��?������?Ӯ�NAT�����������??��?������?ӮP2P������?��ʦ����驡�
		?����?Ӯ��client�����?����?��super peer, ��super peer ����?����?��host����?����super peer�����super peer��public�򣡣
		��?���?����̫��

		\~japanese
		���髤����Ȫ���ݻ���ɫ쫹��?��ܪ����Ҫ��誦�Ȫ��������Ī����??�Ǫ���
		��?��?�ȫ��髤����Ȫ�NAT��?��?������˪���?���ǡ���Ϋ��髤����Ȫ�P2P����򪷪ʪ���Ъʪ�ʪ����ꡢ��驪˪ʪ몫�⪷��ު���
		?�˫��髤����Ȫ���?��׫쫤��?�⪹��super peer�˪ʪ�ʪ���Ъʪ�ʪ����ꡢ
		������super peer�ȫ�?��?���Ҫ�host�����ꡢ
		super peee?�Ǫϡ�������super peer��public���ɫ쫹���������ƪ���������
		��ӫ���������Ҫ��ʪ��Ǫ���������

		\~
		*/
		String m_clientAddrAtServer;

		/** <a target="_blank" href="http://guide.nettention.com/cpp_ko#acr" >���� ���� ��� ����ϱ�</a> �� �Ѱų� ���ϴ�. �⺻������ ���� �ֽ��ϴ�. */
		bool m_enableAutoConnectionRecovery;

		/**
		\ref
		RMI, �̺�Ʈ �� �ݹ� ���� ������ ���� �����մϴ�.

		- SingleThreaded ������ ����ڴ� NetClient.FrameMove �Լ��� ȣ�� �� �� RMI, �̺�Ʈ�� �ݹ� �˴ϴ�.
		- MultiThreaded ������ RMI, �̺�Ʈ �ݹ��� ��Ƽ ������� �ݹ� �˴ϴ�.
		- UseExternalThreadPool ������ m_externalUserWorkerThreadPool �� ���� �� ����� ���� ������ Ǯ�� �۵� �˴ϴ�.
		�⺻ �ɼ��� SingleThreaded �Դϴ�.

		(����! SingleThreaded �ɼ� ���� ����ڴ� NetClient.FrameMove �Լ��� �ݵ�� ȣ�� �ؾ� �մϴ�.)
		*/
		ThreadModel m_userWorkerThreadModel;

		/**
		\ref
		��Ʈ��ũ I/O ó�� �۾��� ���� ������ ���� �����մϴ�.

		- SingleThreaded ������ ����ڴ� NetClient.FrameMove �Լ��� ȣ�� �� �� I/O ó���� �մϴ�.
		- MultiThreaded ������ ���� ���� ������Ǯ���� ��Ƽ ������� ó���� �˴ϴ�.
		- UseExternalThreadPool ������ m_externalNetWorkerThreadPool �� ���� �� ����� ���� ������ Ǯ�� �۵� �˴ϴ�.
		 (���� ���� ������Ǯ�̶�, NetClient ��ü�� �������� �Ǵ��� ���� ������ �ϳ��� ������Ǯ���� ó���� �˴ϴ�.)

		�⺻ �ɼ��� MultiThreaded �Դϴ�.

		(����! SingleThreaded �ɼ� ���� ����ڴ� NetClient.FrameMove �Լ��� �ݵ�� ȣ�� �ؾ� �մϴ�.)
		*/
		ThreadModel m_netWorkerThreadModel;

		/**
		\ref
		RMI, �̺�Ʈ �ݹ� �� �پ��� �۾��� ������� ������ Ǯ���� �۵� �ϵ��� �մϴ�.
		m_userWorkerThreadModel ���� ThreadModel_UseExternalThreadPool ���� �� �ݵ�� �� ���� ���� �ؾ� �մϴ�.
		*/
		CThreadPool* m_externalUserWorkerThreadPool;

		/**
		\ref
		��Ʈ��ũ I/O ó���� ������� ������ Ǯ���� �۵� �ϵ��� �մϴ�.
		m_netWorkerThreadModel ���� ThreadModel_UseExternalThreadPool ���� �� �ݵ�� �� ���� ���� �ؾ� �մϴ�.
		*/
		CThreadPool* m_externalNetWorkerThreadPool;

		/**
		\~korean
		Timer callback �ֱ� �Դϴ�. <a target="_blank" href="http://guide.nettention.com/cpp_ko#server_timer_callback" >�������� Ÿ�̸� ���� RMI �̺�Ʈ ó���ϱ�</a>  ����Դϴ�.
		�̰��� �����ϸ� milisec������ �ѹ��� INetServerEvent.OnTick �� ȣ��˴ϴ�.
		- 0�̸� �ݹ����� �ʽ��ϴ�.
		- �⺻���� 0�Դϴ�.

		\~english
		This sets the period of timer callback. A function described in <a target="_blank" href="http://guide.nettention.com/cpp_en#server_timer_callback" >Managing Timer loop RMI Event from server</a>.
		When this is activated, INetServerEvent.OnTimerCallback will be called at every period set by millisecond unit.
		- Ther is no callback when this is set as 0.
		- The default value is 0

		\~chinese
		Timer callback�Ѣ��<a target="_blank" href="http://guide.nettention.com/cpp_zh#server_timer_callback" >���?��?��Timer Loop��RMI��Event</a> ������
		?��??��?�� INetServerEvent.OnTick%?�milisec?����У��󭡣
		- 0����?��?��?��
		- ��??��0��

		\~japanese
		Timer callback �Ѣ�Ǫ���\ref server_timer_callback  Ѧ���Ǫ���
		��������Ҫ���ȡ��߫���?�Ȫ���������INetServerEvent.OnTick�������󪵪�ު���
		- 0�Ǫ���Ы�?��Ыë����ު���
		- ��������0�Ǫ���
		\~
		*/
		uint32_t m_timerCallbackIntervalMs;

		/**
		\~korean
		Timer callback�� ���� �� ���� user worker thread���� ȣ��� �� �ִ����� ���մϴ�.
		�⺻���� 1�Դϴ�. ��� user worker thread�� ����ϰ� �ʹٸ� INT_MAX�� �Է��ص� �˴ϴ�.

		\~english TODO:translate needed.

		\~chinese
		?��Timer callback��?���??user worker thread����У��
		��??��1�����������user worker thread��?�ʦ�?��INT_MAX��

		\~japanese
		Timer callback�������˪����Ī�user worker thread�������󪵪�몳�Ȫ��Ǫ���Ϊ���̽��ު���
		��������1�Ǫ�����ƪ�user worker thread�����Ī���������ϡ�INT_MAX���������ƪ��ު��Ǫ���
		\~
		*/
		int32_t m_timerCallbackParallelMaxCount;

		/**
		\~korean
		�������� �����ֱ⿡ �ѹ��� �ݹ��� �ҽÿ� ���ڷ� ���Ǵ� ���� �������Դϴ�.
		Proud.INetServerEvent.OnTick �� ȣ��ɽÿ� ���ڰ����� ���ϴ�. <a target="_blank" href="http://guide.nettention.com/cpp_ko#server_timer_callback" >�������� Ÿ�̸� ���� RMI �̺�Ʈ ó���ϱ�</a> ����Դϴ�.
		- �⺻���� NULL�Դϴ�.

		\~english
		This is a user data used as an index when the server calls back each time in every period.
		This value is to be input as an index when Proud.INetServerEvent.OnTimerCallback is called. A function described in <a target="_blank" href="http://guide.nettention.com/cpp_en#server_timer_callback" >Managing Timer loop RMI Event from server</a>.
		- The default value is NULL.

		\~chinese
		���?���������Ѣ��?�����?��������������??�ߡ�
		Proud.INetServerEvent.OnTick%����У��?��?��������?����<a target="_blank" href="http://guide.nettention.com/cpp_zh#server_timer_callback" >���?��?��Timer Loop��RMI��Event</a>%������
		- ��??��NULL��

		\~japanese
		��?��?������Ѣ���������ī�?��Ыë��򪹪��������Ȫ����Ū����?��?��?���Ǫ���
		Proud.INetServerEvent.OnTick�������󪵪������������Ȫ�������ު���\ref server_timer_callback Ѧ���Ǫ���
		- ��������NULL�Ǫ���
		\~
		*/
		void* m_timerCallbackContext;

		PROUD_API CNetConnectionParam();
	};

	/**  @} */
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
