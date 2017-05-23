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
	Information construct of opponent host

	\~chinese
	?۰���������?��?��

	\~japanese
	��⢫۫��Ȫ�����ϰ��?
	\~
	*/
	class CNetPeerInfo
	{
	public:
		/**
		\~korean
		�������� �ٶ� Ŭ���̾�Ʈ�� UDP socket�� �ּ�. ��, Ŭ���̾�Ʈ�� �������� Ȧ��Ī�� �Ϸ�� ���� �νĵ� �ּ�
		- <a target="_blank" href="http://guide.nettention.com/cpp_ko#get_holepunched_info" >Ŭ���̾�Ʈ�� Ȧ��Ī�� �ּҸ� ���</a>  �� <a target="_blank" href="http://guide.nettention.com/cpp_ko#use_alternative_p2p" >ProudNet�� ���� �ʰ� ProudNet�� Ȧ��Ī ������ ���� ���� UDP �������� ����ϱ�</a>  ���� ���ظ� �����մϴ�.
		- ������ ������ �� ���� Ŭ���̾�Ʈ�� AddrPort.Unassigned �̴ٰ� �� �� �̳��� Ȧ��Ī�� ������ �ٲ�ϴ�.
		���� �������� ���� �Ǵ� ������ ������ ���� Ȧ��Ī�� ���������� �������� ���� ���� �ֽ��ϴ�. �̷��� ��� �� ����
		����ؼ� AddrPort.Unassigned �� ���� �ֽ��ϴ�.
		- �ݵ�� �� ���� P2P Ȧ��Ī�� Ŭ���̾�Ʈ�� �ּҸ� �ǹ������� �ʽ��ϴ�. �� ���� ���� ���ο��� �����˴ϴ�.

		\~english
		Address of TCP socket of peer from server perspective. In other words, recognized address after finished t hole-punching from client to server.
		- We recommend to understand <a target="_blank" href="http://guide.nettention.com/cpp_en#get_holepunched_info" >Earning hole-punched address of client</a> and <a target="_blank" href="http://guide.nettention.com/cpp_en#use_alternative_p2p" >Communicating with a separated UDP socket based on ProudNet hole-punched information without using ProudNet.</a> first.
		- The client jsut completed connecting to server has AddrPort.Unassigned value and changed to have hole-punched value within seconds.
		  That means depending ontype and/or settings of router, the hole-punching can never be successful. If this happens, the value can remain as the value of AddrPort.Unassigned.
		- This value does not necessarily mean the address of P2P hole-punched client address. The value is managed internally by engine.

		\~chinese
		���?�����������client��UDP socket�򣡣?��client ?��?����������������??�򣡣
		- ��?<a target="_blank" href="http://guide.nettention.com/cpp_zh#get_holepunched_info" >?����?Ӯ�?����������</a>%��<a target="_blank" href="http://guide.nettention.com/cpp_zh#use_alternative_p2p" >������ProudNet��������ProudNet��������?��?����UDPSocket?������</a>%��?�������
		- ?��?����?��??������ʫ��� AddrPort.Unassigned ��?������������������?��
		��󮣬?��������??����������?�ǣ�����ʦ����?�����������??���?ʦ������?�� AddrPort.Unassigned%��
		- ???������?��ګ�P2P��������client�򣡣��??�����?ݻη�⡣


		\~japanese
		��?��?����̸�����髤����Ȫ�UDP socket�Ϋ��ɫ쫹��?�������髤����Ȫ���?��?�ȪΫ�?��ѫ���󫰪��������쪿�������۫��ɫ쫹
		- \ref get_holepunched_info ��� \ref use_alternative_p2p ��໪��������몳�Ȫ�?�᪷�ު���
		- ��?��?�Ȫ���?������ê��ުުΫ��髤����Ȫ�AddrPort.Unassigned�Ǫ�����?���?�˫�?��ѫ���󫰪��쪿����?���ު�����êơ���?��?����׾�ު��ϫ�?��?���Ҫ˪�êƫ�?��ѫ���󫰪�����ܪ�����Ǫ��ʪ����Ȫ⪢��ު������Ϊ誦�����ꡢ��������?����AddrPort.Unassigned�˪ʪ몳�Ȫ⪢��ު���
		- ��������������P2P��?��ѫ���󫰪��쪿���髤����ȪΫ��ɫ쫹����ګ���몳�ȪϪ���ު��󡣪������ϫ��󫸫�?ݻ��η�⪵��ު���
		\~
		*/
		AddrPort m_UdpAddrFromServer;

		/**
		\~korean
		peer ���ο����� UDP socket�� �ּ�
		- �������� UDP Ȧ��Ī�� ���� �ȳ��� Ŭ���̾�Ʈ, �� TCP�θ� ������� Ŭ���̾�Ʈ�� �� ���� Unassigned�� �� �ֽ��ϴ�. �׷��� ������ ��Ȳ�� �ƴմϴ�.

		\~english
		Address of UDP socket inside of peer
		- The client that has not comp[leted UDP hole-punching with server, in other words the client communicating only through TCP can have this value as unassigned. But this is not abnormal situation.

		\~chinese
		�peer?ݻ��UDP socket�򣡣
		- ?��?����UDP����??��?����client��??������TCP������client���?ʦ��?unassigned��ӣ����ު������?��

		\~japanese
		peer ?ݻ�Ǫ�UDP socket�Ϋ��ɫ쫹
		- ��?��?�Ȫ�UDP��?��ѫ���󫰪��ު�����êƪʪ����髤����ȡ�?����TCP�تΪ����᪷�ƪ��뫯�髤����Ȫϡ���������Unassigned������⪢��ު��������������?�ϪǪϪ���ު��� 
		\~
		*/
		AddrPort m_UdpAddrInternal;

		/**
		\~korean
		CNetServer ���� �Ҵ����� peer �� int.

		\~english
		Int of peer that allocated by CNetServer.

		\~chinese
		� CNetServer%������peer��int��

		\~japanese
		CNetServer����ܪ�?�ƪ�쪿peer��int.
		\~
		*/
		HostID m_HostID;

		/**
		\~korean
		true�̸� �� Ŭ���̾�Ʈ peer���� RMI�� ������ �����ϴ� P2P relay��
		���� �ǹ��մϴ�.
		- CNetClient ������ ��ȿ�� ��.

		\~english
		If true then RMI towards to peer of tis client P2P relayes.
		- Only valid in CNetClient

		\~chinese
		True��?��ګ��client peer��RMI?��?���?����P2P relay��
		- ����� CNetClient%������?��

		\~japanese
		True�Ǫ���Ъ��Ϋ��髤����Ȫ�peer�ت�RMI�ϫ�?��?��?릪���P2P relay����ګ���ު���
		- CNetClient�ǪΪ���?���� 
		\~
		*/
		bool m_RelayedP2P;

		/**
		\~korean
		�� client�� �����ϰ� �ִ� P2P �׷��� ����Ʈ
		- CNetServer, CNetClient ��ο��� ��ȿ�մϴ�.

		\~english
		P2P group list that this client is participating
		- Valid in both CNetServer and CNetClient

		\~chinese
		�client??��P2P?��֪����
		- � CNetServer, CNetClient%��ݻ������

		\~japanese
		���Ϋ��髤����Ȫ�?ʥ���ƪ���P2P����?�תΫ꫹��
		- CNetServer, CNetClient ��?۰����?�Ǫ��� 
		\~
		*/
		HostIDArray m_joinedP2PGroups;

		/**
		\~korean
		true�� ��� �� Ŭ���̾�Ʈ�� NAT ��ġ �ڿ� ������ �ǹ��մϴ�.
		- CNetServer, CNetClient ��ο��� ��ȿ�մϴ�.

		\~english
		If true then this client is behind NAT device
		- Valid in both CNetServer and CNetClient

		\~chinese
		True ��?��ګ��client�NAT?��������
		- � CNetServer, CNetClient%��ݻ������

		\~japanese
		true�����ꡢ���Ϋ��髤����Ȫ�NAT?�Ǫ����˪��몳�Ȫ���ګ���ު���
		- CNetServer, CNetClient ��?۰����?�Ǫ��� 
		\~
		*/
		bool m_isBehindNat;

		/**
		\~korean
		�ֱٿ� ������ ping�� ��� �ð� (�и��ʴ���)
		- CNetClient.GetPeerInfo ���� ���� ���: �ش� P2P peer�� ping�Դϴ�.
		- CNetServer.GetClientInfo ���� ���� ���: ����-Ŭ���� ping�Դϴ�.

		\~english
		Recently measured the average time of ping (in Millisecond)
		- If from CNetClient.GetPeerInfo: ping of the P2P peer
		- If from CNetServer.GetClientInfo: ping between server and client

		\~chinese
		����??��ping����г??������?�ȣ���
		- � CNetClient.GetPeerInfo%?������?����?P2P peer��ping��
		- � CNetServer.GetClientInfo%?������?����?��-client ��?��ping��

		\~japanese
		���Ϊ����Ҫ��쪿ping����г���ࣨ�߫���?�ȣ�
		- CNetClient.GetPeerInfo ��������꣺��?P2P peer��ping�Ǫ��� 
		- CNetServer.GetClientInfo��������꣺��?��?���髤��������ping�Ǫ��� 
		\~
		*/
		int m_recentPingMs;

		/**
		\~korean
		�� peer���� �۽� ������� �޽����� �ѷ�(����Ʈ ����) �Դϴ�.
		- �������� peer �� ���� ��� ��� ����=>Ŭ���̾�Ʈ �۽ſ� ���� �ѷ��Դϴ�.
		- Ŭ���̾�Ʈ���� peer �� ���� ��� ��� Ŭ���̾�Ʈ=>Ŭ���̾�Ʈ �۽ſ� ���� �ѷ�(��, relay�Ǵ� �޽����� ���ؼ��� ����)

		\~english
		Total amount(in byte) of waiting messages to be sent to this peer
		- If getting from peer by server: Total amount of transmission by client
		- If getting from peer by client: Total amount of transmission by client (but excluding relayed messages)

		\~chinese
		���peer������?��������?�ᣨbyte ?�ȣ���
		- ���?��?peer?������?����?��=>client ?��������?�ᡣ
		- �client?peer?������?��client=>client ?��������?�ᣨӣ��?relay���������⣩��

		\~japanese
		����peer�ت��������êƪ����ë�?����?�ᣨ�Ы���?�ȣ��Ǫ���
		- ��?��?���peer��?����������ꡢ��?��?=>���髤����������?����?��Ǫ���
		- ���髤����Ȫ��peer��?����������ꡢ���髤�����=>���髤����������?����?�ᣨӣ����relay����ʪ���ë�?����?���ƪ���⣩
		\~
		*/
		int m_sendQueuedAmountInBytes;

		/**
		\~korean
		����ڰ� ������ tag�� �������Դϴ�.
		- CNetServer.SetHostTag, CNetClient.SetHostTag �� ���� ������ ���Դϴ�.
		- ����! : tag�� ��Ʈ�� ����ȭ�� ���� �ʴ� ���Դϴ�.

		\~english
		Pointer of user defined tag
		- A value set by CNetServer.SetHostTag and CNetClient.SetHostTag
		- Attention!: tag is a value that cannot be network synchronized.

		\~chinese
		��?�����tag�?��
		- ��? CNetServer.SetHostTag,  CNetClient.SetHostTag%�����?��
		- ��򣡣�tag ��?��??������?��

		\~japanese
		��?��?����Ҫ���tag�Ϋݫ���?�Ǫ���
		- CNetServer.SetHostTag, CNetClient.SetHostTag���ת���Ҫ������Ǫ��� 
		- �����!��tag�ϫͫëȫ�?����Ѣ��������ʪ����Ǫ��� 
		\~
		*/
		void* m_hostTag;

		/**
		\~korean
		Ŭ���̾�Ʈ�� Frame Rate �Դϴ�.
		- CNetClient.SetApplicationHint �� ����ڰ� �Է��� ���Դϴ�.
		- P2P �׷��� ���� �� �Ǿ���� Frame Rate �� Ȯ���ϰ��� �� �� ����մϴ�.
		- �ΰ� �Բ� �����Ǿ� ������ ����� �� �ֽ��ϴ�.
		- Frame rate�� ��ŷ� ������ ���Ͽ� ���۽� float������ ��ȯ�Ǿ� �ۼ��� �˴ϴ�.

		\~english
		Frame Rate of client
		- User input value at CNetClient.SetApplicationHint
		- It uses to check Frame Rate that each peers in P2P group
		- You can use to select super peer with ping
		- To reduce traffic, it sends/receives with float value

		\~chinese
		Client ��Frame Rate��
		- ��?� CNetClient.SetApplicationHint%?����?��
		- �?��?��P2P?����peer��Frame Rate��?�����ġ�
		- ?ping����ʦ�������super peer?�ҡ�
		- Frame rate ?��?������ᣬ?��????float?��?�����ӡ�

		\~japanese
		���髤����Ȫ�Frame Rate�Ǫ���
		- CNetClient.SetApplicationHint�˫�?��?�������������Ǫ���
		- P2P����?�ת�̿�������?����Frame Rate�����㪷���������Ū��ު���
		- ping�ȪȪ��super peer�����Ҫ��Ū����Ȫ��Ǫ��ު���
		- Frame rate��������������Ϊ���ˡ�?������float����?�����������᪵��ު��� 
		\~
		*/
		double m_directP2PPeerFrameRate;

		/**
		\~korean
		�ڽ�(CNetClient)�� �ش� Ŭ�󿡰� Udp packet�� ���� �õ��� �� ����

		\~english
		Total attempted number of sending Udp packet from CNetClient to other client

		\~chinese
		���CNetClient��???��?client?��UDP packet��???��

		\~japanese
		���(CNetClient)����?���髤����Ȫ�UDP packet�������?������??
		\~
		*/
		uint32_t m_toRemotePeerSendUdpMessageTrialCount;

		/**
		\~korean
		�ڽ�(CNetClient)�� �ش� Ŭ�󿡰� Udp packet�� �����ؼ� ������ �� ����

		\~english
		Total succeed number of sending Udp packet from CNetClient to other client

		\~chinese
		���CNetClient��?��?client����?��UDP packet��???��

		\~japanese
		���(CNetClient)����?���髤����Ȫ�UDP packet�������������??
		\~
		*/
        uint32_t m_toRemotePeerSendUdpMessageSuccessCount;

		int64_t m_unreliableMessageReceiveSpeed;

		PROUD_API CNetPeerInfo();

		String ToString(bool atServer);

		/**
		\~korean
		UDP Data ���۵Ǵ� ��ü Byte ��

		\~english
		The number of total bytes that transmits the UDP data

		\~chinese
		UDP ۰��??������??


		\~japanese
		UDP Data ���᪵�����?�Ы���?
		\~
		*/
		int64_t m_udpSendDataTotalBytes;



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
