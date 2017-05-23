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
#include "ThreadPool.h"
#include "IRmiHost.h"
#include "P2PGroup.h"
#include "StartServerParameterBase.h"
#include "ServerUdpAssignMode.h"

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
Parameters for NetServer startup.
*/
	class CStartServerParameter : public CStartServerParameterBase
	{
	public:
		/**
		\~korean
		TCP ������ ��Ʈ ���.
		- ��Ʈ�� ������ ���� �������� Listening socket�� �����Ҽ� �ֽ��ϴ�.
		- ����� ä���� ������ 0�� ���ϴ�. 0�� �����ϸ� TCP ������ ��Ʈ �Ѱ��� �ڵ� �Ҵ�˴ϴ�. �ڵ� �Ҵ��� ������ ����,
		Ŭ���̾�Ʈ�� ������ �����ϱ� ���� �ڵ� �Ҵ�� ��Ʈ ��ȣ�� ���� ���,
		���� ��� ��Ʈ���� �׽�Ʈ�� ���� ��Ư�� �ټ��� ������ ����� �ϴ� ����Դϴ�.
		�̶� Ŭ���̾�Ʈ���� �ڵ��Ҵ�� ��Ʈ �ּҸ� �˷���� �մϴ�.
		�ڵ� �Ҵ�� ��Ʈ ��ȣ�� GetServerAddrPort()�� ���� �� �ֽ��ϴ�.

		\~english
		TCP listening port
		- The initial value is 0. The TCP listening port is to be allocated automatically when 0 is designated.
		It is useful to use the automatic allocation when a client received an automatically allocated port number before connected to the server,
		for exmple, when you need to launch multiple anonymous servers for a stress test.
		If this is the case, then the server must let the clients know the automatically allocated port addresses.
		The automatically allocated port numbers can be acquired using GetServerAddrPort().

		\~chinese
		TCP listingӮϢ��?
		- ?��??ӮϢ���ʦ�����??Listening socket��
		- ��?����?��???��0�����0��?TCP listing��?port?�?���ա��?������������?����client�?����?����������?������port??��?��������?��?��??�����?����������?��?����?����
		??���ͱ?client�?������port�򣡣
		�?������port??ʦ��GetServerAddrPort()?��

		\~japanese
		TCP�꫹�˫󫰫�?�ȫ꫹��
		- ��?�Ȫ���?�ªê���?��Listening socket���������몳�Ȫ��Ǫ��ު���
		- �꫹�Ȫ�?�����ʪ����0������ު���0����Ҫ����TCP�꫹�˫󫰫�?��1��������ܪ�?�ƪ��ު���
		�����?�����Ī�����ϡ�
		���髤����Ȫ���?��?����?�����������ܪ�?�ƪ�쪿��?����?�����������ꡢ
		�Ǫ��С����ȫ쫹�ƫ��ȪΪ������������?�Ϋ�?��?�����Ѫ��ʪ���Ъʪ�ʪ�����Ǫ���
		�����������髤����Ȫ�����ܪ�?�ƪ�쪿��?�ȫ��ɫ쫹���骻�ʪ���Ъʪ�ު���
		����ܪ�?�ƪ�쪿��?����?�� GetServerAddrPort()������ު���
		\~
		*/
		CFastArray<int> m_tcpPorts;

		/**
		\~korean
		UDP ȣ��Ʈ ��Ʈ ����Դϴ�.
		m_udpAssignMode�� Proud.ServerUdpAssignMode_PerClient �� ��� �� ����� ���õ˴ϴ�.

		m_udpAssignMode�� Proud.ServerUdpAssignMode_Static �� ��� �� ����� ������ ���� �۵��մϴ�.
		- 0�� ����ִ� �迭�� ���: 0�� ����ִ� ������ŭ ���� ��Ʈ ��ȣ�� ������ UDP ���ϵ��� �̸� �غ�˴ϴ�.
		�̶� ���� ������ ��Ʈ ��ȣ�� �������� CNetServer.GetServerUdpAddrPort()�� ����ϸ� �˴ϴ�.
		- 0 �̿��� ������ ����ִ� �迭�� ���: �迭�� ����ִ� ���� ���� UDP ���ϵ��� �̸� �غ�˴ϴ�.

		- UDP ȣ��Ʈ ��Ʈ ����� ������ ��ȭ�� ������ ������ �ݴϴ�. <a target="_blank" href="http://guide.nettention.com/cpp_ko#firewall_setting" >���������� ��ȭ�� ����</a> �� �����Ͻʽÿ�.
		- ��Ʈ ������ �������� ���ؼ��� <a target="_blank" href="http://guide.nettention.com/cpp_ko#server_udp_assign" >������ UDP ��Ʈ ��� ���</a> �� �����Ͻʽÿ�.
		- ���信 ���ؼ��� <a target="_blank" href="http://guide.nettention.com/cpp_ko#server_listen" >�������� Ŭ���̾�Ʈ ���� �ޱ⸦ �����ϱ�</a> �� �����Ͻʽÿ�.

		\~english
		This is a list of UDP host port
		When m_udpAssignMode is same as Proud.ServerUdpAssignMode_PerClient, this list will be ignored;

		When m_udpAssignMode is same as Proud.ServerUdpAssignMode_Static, this list will work as followings;
		- in the case the allocation containing 0 value: The UDP sockets, as many as of the number of 0s containing, with random port numbers will be prepared.
		CNetServer.GetServerUdpAddrPort() is used to get the port numbers that are actually allocated.
		- in the case the allocation containing other values other than 0: The UDP sockets with the values contained within the allocation will be prepared.

		- The list of UDP host port affects a firewall settings for servers. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#firewall_setting" >Setting firewall from server</a> for more details.
		- About reasonable number of port, please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#server_udp_assign" >Method of using Server UDP Port</a>.
		- For the summary, please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#server_listen" >How to start receiving client connection</a>.

		\~chinese
		��UDP���ӮϢ��?��
		m_udpAssignMode�� Proud.ServerUdpAssignMode_PerClient%��?�����?��?��

		m_udpAssignMode�� Proud.ServerUdpAssignMode_Static%��?�����??����??��
		- ��0��??��?����??���??����?����0?��������port??��UDP socket��
		�?��?��??������port??��?��ʦ����� CNetServer.GetServerUdpAddrPort()��
		- ��0���?��??��?����?���??��??����?��UDP socket��

		- UDP���port??��?��������??��?���?��??��<a target="_blank" href="http://guide.nettention.com/cpp_zh#firewall_setting" >?����?������?</a>%��
		- ?port??������???��<a target="_blank" href="http://guide.nettention.com/cpp_zh#server_udp_assign" >��?��UDPӮϢ����۰��</a>%��
		- ??�??��<a target="_blank" href="http://guide.nettention.com/cpp_zh#server_listen" >���?��?��?������?Ӯ?��</a>%��

		\~japanese
		UDP�۫��ȫ�?�ȫ꫹�ȪǪ���
		m_udpAssignMode��Proud.ServerUdpAssignMode_PerClient�Ǫ������ꡢ��꫹�Ȫ����ʪ���ު���
		
		m_udpAssignMode��Proud.ServerUdpAssignMode_Static�Ǫ������ꡢ��꫹�Ȫ��Ϊ誦�����Ѫ��ު���
		- 0�����êƪ�����֪�����꣺0�����êƪ���?�����������?����?����UDP�����ëȪ����ê����᪵��ު���
		��������?��ܪ�?�ƪ�쪿��?����?����몿��˪ϡ�CNetServer.GetServerUdpAddrPort()���Ū����ު��Ǫ���
		- 0�����������êƪ�����֪�����꣺��֪�����êƪ���������UDP�����ëȪ����ê����᪷�ު���
		- UDP �۫��ȫ�?�ȫ꫹�Ȫϫ�?��?�īի���������?�����Ҫ���ª�?���ު���\ref firewall_setting��?�Ϊ���������
		- ��?��?�������ʪ�?���ƪϡ�\ref server_udp_assign��?�Ϊ���������
		- ?驪�?���ƪϡ�\ref server_listen��?�Ϊ���������
		\~
		*/
		CFastArray<int> m_udpPorts;

		/**
		\~korean
		UDP ȣ��Ʈ ��Ʈ ��� ��å�Դϴ�.
		- UDP ȣ��Ʈ ��Ʈ ����� ������ ��ȭ�� ������ ������ �ݴϴ�. <a target="_blank" href="http://guide.nettention.com/cpp_ko#firewall_setting" >���������� ��ȭ�� ����</a> �� �����Ͻʽÿ�.
		- �� ������ ������ ���ɿ� ������ �ݴϴ�. (�ڼ��� ����: <a target="_blank" href="http://guide.nettention.com/cpp_ko#server_udp_assign" >������ UDP ��Ʈ ��� ���</a>)
		- ���信 ���ؼ��� <a target="_blank" href="http://guide.nettention.com/cpp_ko#server_listen" >�������� Ŭ���̾�Ʈ ���� �ޱ⸦ �����ϱ�</a> �� �����Ͻʽÿ�.

		\~english
		This is the policy of using UDP port.
		- The UDP host port list affects the firewall settings for the servers. Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#firewall_setting" >Setting firewall from server</a>.
		- This setting affects server functions. (for more details, please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#server_udp_assign" >Method of using Server UDP Port</a>.)
		- For the smmary, please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#server_listen" >How to start receiving client connection</a>.

		\~chinese
		UDP���ӮϢ����������
		- UDP���port��??��?������??��?���?��??��<a target="_blank" href="http://guide.nettention.com/cpp_zh#firewall_setting" >?����?������?</a>%��
		- �?��?��?��������?���?����???黣�<a target="_blank" href="http://guide.nettention.com/cpp_zh#server_udp_assign" >��?��UDPӮϢ����۰��</a>��
		- ??�??��<a target="_blank" href="http://guide.nettention.com/cpp_zh#server_listen" >���?��?��?������?Ӯ?��</a>%��

		\~japanese
		UDP�۫��ȫ�?�����īݫ꫷?�Ǫ���
		- UDP �۫��ȫ�?�ȫ꫹�Ȫϫ�?��?�īի���������?�����Ҫ���ª�?���ު���\ref firewall_setting ��?�Ϊ���������
		- �������Ҫϫ�?��?����������ª�?���ު���(�٪����ϡ�\ref server_udp_assign)
		- ?驪�?���ƪϡ�\ref server_listen��?�Ϊ���������
		\~
		*/
		ServerUdpAssignMode m_udpAssignMode;

		/**
		\~korean

		\~english

		\~chinese

		\~japanese
		\~
		FOR TEST USE! DO NOT MODIFY THIS
		*/
		bool m_enableIocp;

		/**
		\~korean
		Ŭ���̾�Ʈ���� �ʿ�� universal plug and play(UPNP) ����� �õ��� �������� ���� �����Դϴ�.
		- �⺻���� true�Դϴ�.
		- ������ ��ſ��� CNetClient �� ���� ��� ���ʿ��� �� �ִµ� �̶� �� ���� false�� �������ָ� �˴ϴ�.

		\~english
		This is used to decide wheter to use universal plug and play function for the clients when required.
		- The default vlaue is true.
		- It may not be necessary when CNetClient is used between server communications then set tis value as false.

		\~chinese
		Client���?�����??universal plug and play(UPNP)������?����
		- ��??��true��
		- ��?����?���������� CNetClient%��?��ʦ��?����驣�??�����??��?false?ʦ��

		\~japanese
		���髤����Ȫ��������universal plug and play(UPNP)Ѧ�����˪����ɪ�����?����ʦ���Ǫ���
		- ��������true�Ǫ���
		- ��?��?��������CNetClient���Ū����ꡢ��驪����ꪬ����ު���������������������false�����Ҫ�����ު��Ǫ���
		\~
		*/
		bool m_upnpDetectNatDevice;

		/**
		\~korean
		true�̸� Ŭ���̾�Ʈ���� �ʿ�� universal plug and play(UPNP) ����� �̿��Ͽ� TCP Ȧ��Ī ������ ���� ��Ʈ ����
		��ŵ�ϴ�.
		- �� ����� ���� ������ TCP���� ������ ����ȭ �ϱ� ���� TCP Ȧ��Ī ���ῡ ���� upnp ��Ʈ���� ������ �����մϴ�.
		- �Ϲ������� TCP ������ ���� ������ �� ����� ���� �ʿ������� �ʽ��ϴ�. ���� �⺻���� false�Դϴ�.

		\~english TODO:translate needed.
		If true, the TCP hole punching connection is forced to be port mapped using the universal plug and play (UPNP) feature if needed in the client. 
		- If this feature is turned on, it controls the upnp port mapping connection to the TCP hole punching connection to stabilize the connection to TCP. 
		- If the TCP connection is open in general, this feature is not really necessary. Therefore, the basic value is false. 

		\~chinese
		True��?client���?����universal plug and play(UPNP)������TCP����?��?��˭�port mapping��
		- �����??��?��?��?��?TCP��?�ȣ��??TCP����?����upnp port mapping?�ȡ�
		- ������?��TCP?��?���?��������������??��fasle��

		\~japanese
		True�Ǫ���Ы��髤����Ȫ��������universal plug and play(UPNP)Ѧ�����Ūê�TCP��?��ѫ������?��?��?�ȫޫëԫ󫰪����ު���
		- ����Ѧ��������˪ʪêƪ����TCP�Ȫ���?�����������몿��ˡ�TCP��?��ѫ������?��?����upne��?�ȫޫëԫ���?����٪��ު���
		- �����ܪ�TCP��?���Ҫ��ƪ���С�����Ѧ������驪ǪϪ���ު��󡣪�êơ���������false�Ǫ���
		\~
		*/
		bool m_upnpTcpAddPortMapping;


		/**
		\~korean
		������ ��ȭ������ ICMP ��Ŷ�� ���� ȣ��Ʈ�� ������ �� ȣ��Ʈ�κ����� ��� ������ �����
		�� �����ع����� '����������' ��å�� �ִ� ��� �� ���� true�� ������ �־�� �մϴ�. ��, Per client
		UDP assign mode�� ����ϴ� ��� �� ���� true�� �������� �ʾƵ� �� �۵��� �� �ִµ�, �̷��� ���
		false�� ���� ���� �����մϴ�.
		- ��� ���������� ��å�� ���� ������� �ʽ��ϴ�. �ֳ��ϸ� TTL�� ������ ��Ŷ ��ȯ�� �Ұ����ϱ�
		������, �Ϻ� ���忡�� ������ ���ͳ� ������(�����)�� ������ �ֿ���� �����ع����� ���°�
		���� �� �ֱ� �����Դϴ�.
		- �⺻���� false�Դϴ�.

		\~english
		If there exists a strong policy that totally eliminates all types of communications from the host with ICMP packet from server firewalls, then this value must be set as true.
		However, there could be some cases when Per client UDP asigne mode is used and working well while this value is not set as true, but it is recommended to set this value as false.
		- The policy mentioned above is not recommended to stick with since it makes the exchange of the packets that restricted TTL impossible, causing some routers detect the servers as mullware.
		- The default value is false.

		\~chinese
		���?��?������???��ICMP?�����������?�������?��ݻ���������??�����ܡ�?�??����������?�����??��?true��ӣ������Per client UDP assign mode��?����?�������??��?true�???��??����?��fasle��
		- ������?߾��?�??����������?���TTL��?������ʦ����?��ʦ��??��?��ݻ����?��?��??�����?����?�����?mullware����?��
		- ��??��false��

		\~japanese
		��?��?���Ϋի���������?���ICMP�ѫ��ëȪ����êƪ���۫��Ȫ������������Ϋ۫��Ȫ������ƪ���׾��������?���ƪ��ު���Φ???�����ݫ꫷?���������ꡢ��������ture�����Ҫ��ު���ӣ����Per client UDP assign mode���Ū����ꡢ��������ture�����Ҫ��ʪ��ƪ�誯���Ѫ��몳�Ȫ�����ު��������Ϊ誦������ϡ�false���Ū����Ȫ�?�᪷�ު���
		- ߾����Φ???���ݫ꫷?��ܬ��??���ު��󡣪ʪ��ʪ顢TTL����ڪ����ѫ��ë���������ʦ���Ǫ��몿�ᡢ��ݻ�����ު����?�뫤��?�ͫëȫ�?��?����?��?��ޫ뫦��������򱪷�ƪ��ު����Ȫ�������몫��Ǫ���
		- ��������false�Ǫ���
		\~
		*/
		bool m_usingOverBlockIcmpEnvironment;

		/**
		\~korean
		������ HostID�� �߱��ϴ� ����� �����մϴ�.
		- default�� HostIDGenerationPolicy_NoRecycle �Դϴ�.

		\~english
		Server will select method of issuing HostID
		- Default is HostIDGenerationPolicy_NoRecycle.

		\~chinese
		��?�����?ۯHost ID��۰�ҡ�
		- default��HostIDGenerationPolicy_NoRecycle��

		\~japanese
		��?��?��HostID��?������۰�Ҫ���Ҫ��ު���
		- default��HostIDGenerationPolicy_NoRecycle�Ǫ���
		\~
		*/
		//HostIDGenerationPolicy m_HostIDGenerationPolicy;

		/**
		\~korean
		Ŭ���̾�Ʈ�� ���ܾ� �� ��� �α� ���μ��Դϴ�.
		- default�� 0�Դϴ�.
		- �̰��� �����ϸ�, NetClient ���� SendEmergencyLog �� ȣ���ϴ� ���
		EmergencyLogServer �α����Ͽ� �ش� ���μ� ��ŭ ���αװ� ����˴ϴ�.

		\~english
		This is number of emergency log line for client
		- Default is 0
		- Once you set this value, client create LogFile when NetClient call DumpEmergencyLog.

		\~chinese
		Client�׺����?��log line?��
		- default��0��
		- ����?��?���NetClient��УSendEmergencyLog��?������EmergencyLogServer log����?����?����?line?��?��log��

		\~japanese
		���髤����Ȫ�?���٪�ު�ȫ��髤��?�Ǫ���
		- ��������0�Ǫ���
		- ����������Ҫ���ȡ�NetClient��SendEmergencyLog������������
		EmergencyLogServer ���ի��������?�髤��?������ު�ȫ���������ު���
		\~
		*/
		uint32_t	m_clientEmergencyLogMaxLineCount;

		/*
		\~korean
		��� �Ǿ�� ���� �����ϴ� ����Դϴ�.
		- �ʱⰪ�� false �Դϴ�.
		- true�� �ϸ� Peer�� ���� ����Ǿ� �ִ� ��� �Ǿ�� �ΰ��� ��� ��� �ɴϴ�.
		- �� ����� �������� �ʴٸ� Superpeer ������ �־� Peer�� ���� ���� �� ��������, m_peerLagWeight���� ������� �ʽ��ϴ�.

		\~english TODO:translate needed.
		This is the feature to collect the ping between every peer. 
		- The initial value is false. 
		- If set true, the ping value among all peers connected from the peer is obtained entirely. 
		- If this feature is not turned on, you cannot get the ping among peers when selecting the superpeer, so it does not calculate m_peerLagWeight value. 

		\~chinese
		�����peer��?��ping������
		- ���?��false��
		- ??true��?��?��ݻ?��?peer?�?�������peer��?ping?��
		- �����?��??��?���Superpeer?��߾�������peer��?��ping������?ߩm_peerLagWeight?��

		\~japanese
		��ƪ�Peer���ping��?󢪹��Ѧ���Ǫ���
		- ��Ѣ����false�Ǫ���
		- ture�˪����Peer������?����ƪ�����ƪ�Peer���ping���������ƪ��ު���
		- ����Ѧ�������ժ˪ʪêƪ���ȡ�Superpeer���Ҫ˪����ơ�Peer���ping�������몳�Ȫ��Ǫ��ʪ����ᡢm_peerLagWeight����ͪߩ���ު���
		\~
		*/
		bool m_enablePingTest;


		/**
		\~korean
		�̰��� true�� ������� m_udpports�� �̹� ������� port�� ������� ���������ʰ� ������Ʈ�� bind�ϰ� �˴ϴ�.
		- �ʱⰪ�� false�Դϴ�.
		- ������ port ����� m_failedBindPorts �ȿ� ���ϴ�.

		\~english
		When you set this value to true, it bind next port if it has port that already using in m_udpports.
		- Default is false
		- Failed port list will go through to m_failedBindPorts

		\~chinese
		���???true��?���m_udpports�?����������port��?����?��?�����?bind����?ӮϢ��
		- ���?��false��
		- ��?��port��??��m_failedBindPorts��

		\~japanese
		��������true�˪������ꡢm_udpports��?�����Ī��ƪ���port���������ꡢ�������ʪ��Ϋ�?�Ȫ�֫髤��ɪ��ު���
		- ��Ѣ����false�Ǫ���
		- ��������port�꫹�Ȫ� m_failedBindPorts?������ު���
		\~
		*/
		bool m_ignoreFailedBindPort;

		/**
		\~korean
		m_ignoreFailedBindPort�� true�� �������, �̾ȿ� bind ������ port����� ���� �˴ϴ�.
		- m_ignoreFailedBindPort�� fasle�϶��� ���� ä������ �ʽ��ϴ�.

		\~english
		When you set m_ignoreFailedBindPort to true, port list of failed bind will be there.
		- When m_ignoreFailedBindPort is false, value does not fill in.

		\~chinese
		��m_ignoreFailedBindPort??true��?����?��?��bind��?��port��?��
		- m_ignoreFailedBindPort?fasle��?����??���?��

		\~japanese
		m_ignoreFailedBindPort��true�˪������ꡢ�������bind����������port�꫹�Ȫ�����誦�˪ʪ�ު���
		- m_ignoreFailedBindPort��fasle�Ǫ�����������?������ު���
		\~
		*/
		CFastArray<int> m_failedBindPorts;

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
		HostID ���� ��� �ɼ��Դϴ�.
		- HostIDGenerationPolicy_Recycle�� �����Ǿ� ������� CNetConfig�� HostIDRecycleAllowTimeMs���� ���� HostID�� ����Ǿ� ���ϴ�.
		- HostIDGenerationPolicy_NoRecycle�� �����Ǿ� ������� INT_MAX���� Unique�� HostID���� �����մϴ�.

		�⺻���� HostIDGenerationPolicy_Recycle�Դϴ�.

		\~english
		It is an option for HostID reuse function.
		- If HostIDGenerationPolicy_Recycle is set, HostID will be reused according to HostIDRecycleAllowTimeMs of CNetConfig.
		- If HostIDGenerationPolicy_NoRecycle is set, unique HostID (until INT_MAX) will be guaranteed.

		Default value is HostIDGenerationPolicy_Recycle.

		\~chinese
		HostID�����������??��
		- �?��? HostIDGenerationPolicy_Recycle ?��?� CNetConfig�� HostIDRecycleAllowTimeMs ?�� HostID������ġ�
		- �?��? HostIDGenerationPolicy_NoRecycle ? ����� Unique �� INT_MAX �� HostID?��

		����?? HostIDGenerationPolicy_Recycle��

		\~japanese
		HostID �����Ѧ�����׫����Ǫ���
		- HostIDGenerationPolicy_Recycle�����Ҫ���ƪ������ꡢ CNetConfig��HostIDRecycleAllowTimeMs���˪��HostID������Ī���ު���
		- HostIDGenerationPolicy_NoRecycle�����Ҫ���ƪ������ꡢINT_MAX�ު�Unique��HostID��������ު���

		�ǫի��������HostIDGenerationPolicy_Recycle�Ǫ���

		\~
		*/
		HostIDGenerationPolicy m_hostIDGenerationPolicy;

		/**
		\~korean
		�ش� ���� �����Ǹ� NetServer ���� �߻��� ���� ���� ������ �����˴ϴ�.
		Ư���� ��찡 �ƴ϶�� �Ժη� �� ���� �������� ���ʽÿ�.

		\~english
		When the value is set, a warning and a dump file are generated when NetServer bottleneck occurs. 
		Unless it is a special situation, do not carelessly set this value. 

		\~chinese
		��ө?��??���NetServer?��????������ͱ��dump���졣
		�ު�����?�����?���?��

		\~japanese
		��?�������Ҫ�����NetServer�ܫëȫ�ͫë���?��������ͱ�ȫ���׫ի����몬��������ު���
		��ܬ������ǪϪʪ�����⢪˪����������Ҫ��ʪ��Ǫ���������


		\~
		*/
		CriticalSectionSettings m_bottleneckWarningSettings;

		/**
		\~korean
		������ �޼����Դϴ�.

		\~english
		Constructor method

		\~chinese
		�����۰����

		\~japanese
		�����᫽�ëɪǪ���
		\~
		*/
		PROUD_API CStartServerParameter();
	};


	/**  @} */

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif

}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
