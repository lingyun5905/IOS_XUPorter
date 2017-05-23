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
#include "AddrPort.h"
#include "Enums.h"
#include "HostIDArray.h"

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
	��� ȣ��Ʈ�� ���� ����ü

	\~english
	Information structure of other host

	\~chinese
	?۰���������?��?��

	\~japanese
	��⢫۫��Ȫ�����ϰ��?
	\~
	*/
	class CNetClientInfo
	{
	public:
		/**
		\~korean
		�������� �ٶ� peer�� TCP socket�� �ּ�. �� ���� ���ͳ� �ּ�(external addr)�Դϴ�.
		- ������ ��������� ���� Ȧ��Ī�� ������� ���� Ŭ���̾�Ʈ�� ��·�ų� �ּҴ� ���� �� �־�� �ϹǷ� �� �ʵ尡 �����մϴ�.
		- ������ ����, Ŭ���̾�Ʈ������ Ÿ remote peer�� ���� �� ���� ���� ���մϴ�.

		\~english
		TCP socket address of peer from server side. It is official internet address (external addr).
		- Client is connected to server but it does not success hole-punching yet. Anyway it need to get address so that is why this field exists.
		- Other remote peer can not get this value as security reason.

		\~chinese
		���?�����������peer��TCP socket�򣡣?��?��??�򣣨external addr����
		- ?���??��?��?�ȣ�ӣ��??����������ʫ��?���򣣬�����???洡�
		- ?�������ʫ����?������remote peer��?��

		\~japanese
		��?��?����̸��Peer��TCP socket�Ϋ��ɫ쫹��?�����ѫ֫�ë�����?�ͫëȫ��ɫ쫹(external addr)�Ǫ���
		- ��?��?�˪Īʪ���ު��������ު���?��ѫ���󫰪������ƪ��ʪ����髤����Ȫ�ɪ����ƪ⫢�ɫ쫹�������驪�����ު��Ϊǡ����Ϋի�?��ɪ�����ު���
		- �������ƫ��Ϊ���ˡ����髤����ȪǪ����remote peer��?���몳����������ު���
		\~
		*/
		AddrPort m_TcpAddrFromServer;

		/**
		\~korean
		�������� �ٶ� Ŭ���̾�Ʈ�� UDP socket�� �ּ�. ��, Ŭ���̾�Ʈ�� �������� Ȧ��Ī�� �Ϸ�� ���� �νĵ� �ּ�
		- <a target="_blank" href="http://guide.nettention.com/cpp_ko#get_holepunched_info" >Ŭ���̾�Ʈ�� Ȧ��Ī�� �ּҸ� ���</a>  �� <a target="_blank" href="http://guide.nettention.com/cpp_ko#use_alternative_p2p" >ProudNet�� ���� �ʰ� ProudNet�� Ȧ��Ī ������ ���� ���� UDP �������� ����ϱ�</a>  ���� ���ظ� �����մϴ�.
		- ������ ������ �� ���� Ŭ���̾�Ʈ�� AddrPort.Unassigned �̴ٰ� �� �� �̳��� Ȧ��Ī�� ������ �ٲ�ϴ�.
		���� �������� ���� �Ǵ� ������ ������ ���� Ȧ��Ī�� ���������� �������� ���� ���� �ֽ��ϴ�. �̷��� ��� �� ����
		����ؼ� AddrPort.Unassigned �� ���� �ֽ��ϴ�.
		- �ݵ�� �� ���� P2P Ȧ��Ī�� Ŭ���̾�Ʈ�� �ּҸ� �ǹ������� �ʽ��ϴ�. �� ���� ���� ���ο��� �����˴ϴ�.

		\~english
		Client's UDP socket address from server side. It is recognized address once client finished hole-punching with server.
		- We recommend to understand <a target="_blank" href="http://guide.nettention.com/cpp_en#get_holepunched_info" >Earning hole-punched address of client</a> and <a target="_blank" href="http://guide.nettention.com/cpp_en#use_alternative_p2p" >Communicating with a separated UDP socket based on ProudNet hole-punched information without using ProudNet.</a> first.
		- Client that just finished connecting to server is AddrPort.Unassigned then it changes to hole-punched value within second. So hole-punching never success depends on type or setting of router.
		This case, value can be AddrPort.Unassigned.
		- Sometimes, this value does not mean address of P2P hole-punched client. This value will manange from internal of engine.

		\~chinese
		���?���?��client UDP socket�򣡣?client?��?����������������??���򣡣
		- ��??�����<a target="_blank" href="http://guide.nettention.com/cpp_zh#get_holepunched_info" >?����?Ӯ�?����������</a>%��<a target="_blank" href="http://guide.nettention.com/cpp_zh#use_alternative_p2p" >������ProudNet��������ProudNet��������?��?����UDPSocket?������</a>%��
		- ?��?����?��??������ʫ��� AddrPort.Unassigned%���?���??�������������?��
		��󮣬?��������??����������?�ǣ�����ʦ����?�����������??���?ʦ������?�� AddrPort.Unassigned%��
		- ???������?��ګ�P2P��������client�򣡣��??�����?ݻη�⡣

		\~japanese
		��?��?����̸�����髤����Ȫ�UDP socket�Ϋ��ɫ쫹��?�������髤����Ȫ���?��?�ȪΫ�?��ѫ���󫰪����������������۫��ɫ쫹
		- \ref get_holepunched_info ���\ref use_alternative_p2p��໪��������몳�Ȫ�?�᪷�ު���
		- ��?��?�Ȫ���?������ê��ުުΫ��髤����Ȫϡ�AddrPort.Unassigned�Ǫ��몬��?���?�˫�?��ѫ���󫰪��쪿����?���ު���
		��êơ���?��?����׾�ު��ϫ�?��?���Ҫ˪�êƫ�?��ѫ���󫰪�����ܪ�����Ǫ��ʪ�������ު��󡣪��Ϊ誦�����ꡢ��������?���� AddrPort.Unassigned�˪ʪ몳�Ȫ⪢��ު���
		- ������������P2P��?��ѫ���󫰪��쪿���髤����ȪΫ��ɫ쫹����ګ���몳�ȪϪ���ު��󡣪������ϫ��󫸫�?ݻ��η�⪵��ު���
		\~
		*/
		AddrPort m_UdpAddrFromServer;

		/**
		\~korean
		peer ���ο����� UDP socket�� �ּ�
		- �������� UDP Ȧ��Ī�� ���� �ȳ��� Ŭ���̾�Ʈ, �� TCP�θ� ������� Ŭ���̾�Ʈ�� �� ���� Unassigned�� �� �ֽ��ϴ�. �׷��� ������ ��Ȳ�� �ƴմϴ�.

		\~english
		UDP socket address of inside of peer
		- Client that has not finished UDP hole-punching with server. If client communicate wiht only TCP, it can be Unassigned. However it is not wrong situation.

		\~chinese
		�peer?ݻ��UDP socket�򣡣
		- ?��?����UDP����??��?����client��??������TCP������client���?ʦ��?unassigned��ӣ����ު������?��

		\~japanese
		peer?ݻ�Ǫ�UDP socket�Ϋ��ɫ쫹��
		- ��?��?�Ȫ�UDP��?��ѫ���󫰪��ު�����êƪ��ʪ����髤����ȡ�?����TCP�تΪ����᪷�ƪ��뫯�髤����ȪϪ�������Unassigned�˪ʪ몳�Ȫ�����ު��������������?�ϪǪϪ���ު���

		\~
		*/
		AddrPort m_UdpAddrInternal;

		/**
		\~korean
		CNetServer ���� �Ҵ����� peer �� int.

		\~english
		int of peer that assigned from CNetServer

		\~chinese
		� CNetServer%������peer��int��

		\~japanese
		CNetServer���ܪ�?�ƪ�peer��int.  
		\~
		*/
		HostID m_HostID;

		/**
		\~korean
		true�̸� �� Ŭ���̾�Ʈ peer���� RMI�� ������ �����ϴ� P2P relay��
		���� �ǹ��մϴ�.
		- CNetClient ������ ��ȿ�� ��.

		\~english
		If it is ture, it means this client peer is doing P2P relay with RMI through a server.
		- Available value on CNetClient

		\~chinese
		True��?��ګ��client peer��RMI?��?���?����P2P relay��
		- ����� CNetClient%������?��

		\~japanese
		True�Ǫ���С����Ϋ��髤�����peer�ت�RMI�ϫ�?��?��?릪���P2P relay���������Ȫ���ګ���ު���
		- CNetClient�ǪΪ���?���� 
		\~
		*/
		bool m_RelayedP2P;

		/**
		\~korean
		�� client�� �����ϰ� �ִ� P2P �׷��� ����Ʈ
		- CNetServer, CNetClient ��ο��� ��ȿ�մϴ�.

		\~english
		P2P group list that this client joined with
		- It is available at CNetServer, CNetClient.

		\~chinese
		�client??��P2P?��֪����
		- � CNetServer, CNetClient%��ݻ������

		\~japanese
		���Ϋ��髤����Ȫ�?ʥ���ƪ���P2P����?�תΫ꫹��
		- CNetServer, CNetClient��?۰����?�Ǫ��� 
		\~
		*/
		HostIDSet m_joinedP2PGroups;

		/**
		\~korean
		true�� ��� �� Ŭ���̾�Ʈ�� NAT ��ġ �ڿ� ������ �ǹ��մϴ�.
		- CNetServer, CNetClient ��ο��� ��ȿ�մϴ�.

		\~english
		If it is true, it means this client locates behind of NAT device.
		- It is available at CNetServer, CNetClient.

		\~chinese
		True��?��ګ��client�NAT?��������
		- � CNetServer, CNetClient%��ݻ������

		\~japanese
		True�����ꡢ���Ϋ��髤����Ȫ�NAT?�Ǫ���˪��몳�Ȫ���ګ���ު���
		- CNetServer, CNetClient��?۰����?�Ǫ��� 
		\~
		*/
		bool m_isBehindNat;

		/**
		\~korean
		true�� ��� �� Ŭ���̾�Ʈ�� �������� UDP ����� �����ǰ� ������ �ǹ��մϴ�.
		false�� ��� UDP ����� �Ұ����ϱ� ������ TCP�� UDP ��� ���ǰ� ������ �ǹ��մϴ�.

		\~english
		If it is ture, it means UDP communication between this client and server is still up and running.
		If it is false, it means TCP is being used because UDP communication is impossible.

		\~chinese
		True��?��ګ��client?��?��?����UDP���ᡣ
		False ��?��ګ���?����?��UDP���ᣬTCP ����UDP����ġ�

		\~japanese
		Ture�����ꡢ���Ϋ��髤����Ȫϫ�?��?�Ȫ�UDP���᪬�򥪵��ƪ��몳�Ȫ���ګ���ު���
		False�����ꡢUDP���᪬�Ǫ��ʪ��Ϊǡ�TCP��UDP���۪����Ūêƪ��몳�Ȫ���ګ���ު���
		\~
		*/
		bool m_realUdpEnabled;

		/**
		\~korean
		�� Ŭ���̾�Ʈ�� �۵����� NAT ��ġ�� �̸�
		- CNetServer ������ ���� �� �ֽ��ϴ�.
		- ������ NAT device �ڿ� �ִ� Ŭ���̾�Ʈ�� �ϴ���, �̸��� ��µ��� ��� ������ �ð��� �ʿ��մϴ�. ����
		�ٷ� ������ ���� Ŭ���̾�Ʈ�� ������ ���� ��� �� ���� ���� ä������ ���� �� �ֽ��ϴ�. �̷��� ��� ��� �ڿ�
		�ٽ� Ŭ���̾�Ʈ�� ������ ������ NAT ��ġ�� �̸��� ���� �� �ֽ��ϴ�.

		\~english
		Name of NAT device which operated by this client
		- You can get it from CNetServer only.
		- If client actually locate behind of NAT device, it will take some time to get a name. So if you get client information that just loged on, it may empty.  This case you can get name of NAT device by reloading client information in a few minutes.

		\~chinese
		�client??����NAT?��٣?��
		- ����� CNetServer%��?��
		- ?�����??NAT device������client��?��٣����������??����󮣬?��???����client������?�����?ʦ��?����?����??������������?��client������?��ʦ�?��NAT?����٣��

		\~japanese
		���Ϋ��髤����Ȫ����Ѫ��ƪ���NAT?��٣
		- CNetServer�ǪΪ�����ު���
		- ?��NAT device����˪��뫯�髤����ȪȪ��ƪ⡢٣�����몳�Ȫ˪������������બ��驪Ǫ�����êơ�������?�����êƪ������髤����Ȫ����ê�������ꡢ���������ު�?������ʪ����Ȫ�����ު������Ϊ誦�����ꡢ���Ъ骯����ӫ��髤����Ȫ����ê�����NAT?�Ǫ�٣�����몳�Ȫ��Ǫ��ު���

		\~
		*/
		String m_natDeviceName;

		/**
		\~korean
		�ֱٿ� ������ ping�� ��� �ð� (�ʴ���)
		- CNetClient.GetPeerInfo ���� ���� ���: �ش� P2P peer �� ping�Դϴ�.
		- CNetServer.GetClientInfo ���� ���� ���: ����-Ŭ���� ping�Դϴ�.

		\~english
		Average ping time that measure recently (Second)
		- When it get from CNetClient.GetPeerInfo: Ping of P2P peer
		- When it get from CNetServer.GetClientInfo: Ping between server-client

		\~chinese
		����??��ping����г??����?�ȣ���
		- � CNetClient.GetPeerInfo%?������?����?P2P peer��ping��
		- � CNetServer.GetClientInfo%?������?����?��-client ��?��ping��

		\~japanese
		���Ϊ����Ҫ���ping����г����(��?��)
		- CNetClient.GetPeerInfo���������꣺��?P2P peer��ping�Ǫ��� 
		- CNetServer.GetClientInfo���������꣺��?��?���髤��������ping�Ǫ��� 
		\~
		*/
		int m_recentPingMs;

		/**
		\~korean
		�� peer���� �۽� ������� �޽����� �ѷ�(����Ʈ ����) �Դϴ�.
		- �������� peer�� ���� ��� ��� ����=>Ŭ���̾�Ʈ �۽ſ� ���� �ѷ��Դϴ�.
		- Ŭ���̾�Ʈ���� peer�� ���� ��� ��� Ŭ���̾�Ʈ=>Ŭ���̾�Ʈ �۽ſ� ���� �ѷ�(��, relay�Ǵ� �޽����� ���ؼ��� ����)

		\~english
		Total amount(byte) of waiting message to this peer.
		- When it get about peer from server, it is total sending amount of server to client
		- When it get about peer from client, it is total sending amount of client to client (except message that relayed)

		\~chinese
		���peer������?��������?�ᣨbyte ?�ȣ���
		- ���?��?peer?������?����?��=>client ?��������?�ᡣ
		- �client?peer?������?��client=>client ?��������?�ᣨӣ��?relay���������⣩��

		\~japanese
		����peer�ت��������êƪ����ë�?����?��(�Ы���?��)�Ǫ���
		- ��?��?��peer��?����������ꡢ��?��?=>���髤����������?����?��Ǫ���
		- ���髤����Ȫ�peer��?����������ꡢ���髤�����=>���髤����������?����?��(ӣ����relay������ë�?����?���ƪ����)
		\~
		*/
		int m_sendQueuedAmountInBytes;

		/**
		\~korean
		����ڰ� ������ tag�� �������Դϴ�.
		- CNetServer.SetHostTag, CNetClient.SetHostTag �� ���� ������ ���Դϴ�.
		- ����! : tag�� ��Ʈ�� ����ȭ�� ���� �ʴ� ���Դϴ�.

		\~english
		Pointer of user defined tag.
		- It designates through CNetServer.SetHostTag and CNetClient.SetHostTag
		- Warning!! : tag value does not synchronize with network.

		\~chinese
		��?�����tag�?��
		- ��? CNetServer.SetHostTag, CNetClient.SetHostTag%�����?��
		- ��򣡣�tag ��?��??������?��

		\~japanese
		��?��?����Ҫ���tag�Ϋݫ���?�Ǫ���
		- CNetServer.SetHostTag, CNetClient.SetHostTag ���ת���Ҫ������Ǫ��� 
		- �����!��tag�ϫͫëȫ�?����Ѣ��������ʪ����Ǫ���
		\~
		*/
		void* m_hostTag;

		/**
		\~korean
		Ŭ���̾�Ʈ�� Frame Rate �Դϴ�.
	    - CNetClient.SetApplicationHint ���� ����ڰ� �Է��� ���Դϴ�.
		- �� �Ǿ�� ���޵��� ������, �������� �� Ŭ���̾�Ʈ�� Frame Rate �� Ȯ�� �ϰ��� �� �� ����մϴ�.
		- Frame rate�� ��ŷ� ������ ���Ͽ� ���۽� float������ ��ȯ�Ǿ� �ۼ��� �˴ϴ�.

		\~english
		Frame Rate of client.
		- User enter this value on CNetClient.SetApplicationHint.
		- It does not send to each peer, it only use to check Frame Rate of client at server.
		- To reduce traffic, frame rate will send/receive as float value.

		\~chinese
		Client ��Frame Rate��
		- � CNetClient.SetApplicationHint%��??����?��
		- ������peer??�����?����??��client��Frame Rate��?�����ġ�
		- Frame rate ?��?�������ᣬ?����?��???float?��?����ӡ�

		\~japanese
		���髤����Ȫ�Frame Rate�Ǫ���
		- CNetClient.SetApplicationHint�ǫ�?��?�������������Ǫ���
		- ��peer�˪�?ӹ����ʪ�����?��?�������髤����Ȫ�Frame Rate�����㪷�����������Ī��ު���
		- Frame rate������������Ϊ����?������Float����?������������᪵��ު���
		\~
		*/
		double m_recentFrameRate;

		/**
		\~korean
		�ش� Ŭ���̾�Ʈ�� �������� Udp packet ������ �õ��� �� Ƚ��

		\~english
		Total number of attempt to send Udp packet to server from client

		\~chinese
		��?client?��?��??UDP packet?����?�?��

		\~japanese
		��?���髤����Ȫ���?��?��UDP packet?������ê�??
		\~
		*/
		uint32_t m_toServerSendUdpMessageTrialCount;

		/**
		\~korean
		�ش� Ŭ���̾�Ʈ�� �������� Udp packet ������ ������ �� Ƚ��

		\~english
		Total number of attempt to success sending Udp packet to server from client

		\~chinese
		��?client?��?������?��UDP packet��?�?��

		\~japanese
		��?���髤����Ȫ���?��?��UDP packet?���������??
		\~
		*/
		uint32_t m_toServerSendUdpMessageSuccessCount;

		/**
		\~korean
		Ŭ���̾�Ʈ�� ���� ����ϰ� �ִ� HostID �� ���� Ƚ���Դϴ�.
		- StartParameter.m_HostIDGenerationPolicy �� ������ ������ �����Ҽ� �ֽ��ϴ�.
		- �������� �ʴ� �ɼ��̸� ������ 0�� ���ɴϴ�.

		\~english
		Total reused count of HostID that client is using currently.
		- You can decide reusing with StartParameter.m_HostIDGenerationPolicy.
		- If you select non-recyle option, value will be 0

		\~chinese
		Client ?�������Host ID��������?��
		- ʦ�?������� StartParameter.m_HostIDGenerationPolicy%�����ġ�
		- ������������??��?��?0��

		\~japanese
		���髤����Ȫ�����Ūêƪ���HostID���������?�Ǫ���
		- StartParameter.m_HostIDGenerationPolicy������Ī򪹪몫�ɪ�����̽��몳�Ȫ��Ǫ��ު���
		- ����Ī��ʪ����׫����Ǫ������?��0����ު���
		\~
		*/
		uint32_t m_hostIDRecycleCount;

		int64_t m_unreliableMessageRecentReceiveSpeed;

		PROUD_API CNetClientInfo();

		String ToString(bool atServer);


#ifdef _WIN32
#pragma push_macro("new")
#undef new
		// �� Ŭ������ ProudNet DLL ��츦 ���� Ŀ���� �Ҵ��ڸ� ���� fast heap�� ���� �ʽ��ϴ�.
		DECLARE_NEW_AND_DELETE
#pragma pop_macro("new")
#endif
	};

	/**  @} */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
