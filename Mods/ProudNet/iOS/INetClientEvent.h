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

#include "INetCoreEvent.h"
#include "acr.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup net_group
	*  @{
	*/

	/**
	\~korean
	CNetClient �� event sink

	���
	- �� ��ü�� �����Ѵ�.
	- CNetClient �� �Ķ���ͷ� �����Ѵ�.

	\~english
	Event sink for CNetClient

	Usage
	- Realize this object.
	- Passed as a parameter to CNetClient

	\~chinese
	CNetClient ��event sink

	����
	- ??�?�ڡ�
	- ��???��? CNetClient%��

	\~japanese
	CNetClient �� event sink

	����
	- ���Ϋ��֫������Ȫ�?�ު��ު���
	- CNetClient�˫ѫ��?��?��?ӹ���ު���
	\~
	*/
	class INetClientEvent : public INetCoreEvent
	{
	public:
		INetClientEvent() {}
		virtual ~INetClientEvent() {}

		/**
		\~korean
		CNetServer.Connect �� ���� ���� ������ �õ��� ����� �����ϸ� �߻��ϴ� �̺�Ʈ�̴�.

		\param info ���� ���� ����� ���� ��ü. �������� ������ ������ ��� ErrorInfo.m_type �� success value�� ���´�.
		�������� ������ ������ ��� �� ���� �����ϸ� �ȴ�. �ڼ��� ���� ErrorInfo Ŭ���� ������ ����.
		\param replyFromServer �����κ��� ���� �߰� �޽����̴�. �� ����
		INetServerEvent.OnConnectionRequest ���� ���� ���̴�.

		\~english
		Event that occurs after arrival of the result of attempt to connect to server through CNetServer.Connect

		\param info object that contains the result of connection to server. ErrorInfo.m_type has success value when it is successful.
		View this value when connection attempt to server failed. Please refer ErrorInfo class description.
		\param replyFromServer Additional message from server. This value is from INetServerEvent.OnConnectionRequest.

		\~chinese
		��? CNetServer.Connect%??��?��?����?����?��??����event��

		\param info ������?��?����?����?�ڡ�?��?����?��������?�� ErrorInfo.m_type%?��success value��
		?��?����?����?��?��?���??ʦ��??��??��ErrorInfo??٥��
		\param replyFromServer ?��?�������ݾʥ���ӡ��?��? INetServerEvent.OnConnectionRequest%?����?��

		\~japanese
		CNetServer.Connect���ת���?��?��?���˪���̿������󷪹���?�檹�뫤�٫�ȪǪ���

		\param info��?��?��?��̿�����Ϋ��֫������ȡ���?��?�Ȫ���?�����������ꡢErrorInfo.m_type��success value�����ު���
		��?��?�Ȫ���?�������������ꡢ��������??������ު��Ǫ����٪����ϡ�ErrorInfo���髹��?٥��?�Ϊ���������
		\param replyFromServer ��?��?������������ʥ��ë�?���Ǫ����������ϡ�
		INetServerEvent.OnConnectionRequest������쪿���Ǫ��� 
		\~
		*/
		virtual void OnJoinServerComplete(ErrorInfo *info, const ByteArray& replyFromServer) = 0;

		/**
		\~korean
		���� ���� ������ �߻� �̺�Ʈ�Դϴ�.
		- Ŭ���̾�Ʈ���� ���� ���� ����(Disconnect ȣ��)�� �� ��쿡�� �� �̺�Ʈ�� �߻����� �ʽ��ϴ�.
		�׷���, NetClient.FrameMove�� ȣ���ϴ� �����尡 NetClient.Disconnect �Ǵ� NetClient.Dispose�� ȣ���ϴ� �����尡 ������ �ݹ�� �� �ֽ��ϴ�.
		\param errorInfo � ������ �������� ������ �����Ǿ������� ��� �ֽ��ϴ�. �ڼ��� ���� ErrorInfo ���򸻿� �ֽ��ϴ�.

		\~english
		Event that occurs when server connection is terminated
		- This event also occurs when client terminates the connection to server.
		However, it will be called back if the thread where NetClient.FrameMove is called and NetClient.Disconnect is called are same.
		\param errorInfo Contains the reason why the connection was terminated. Please refer ErrorInfo.

		\~chinese
		��?�����?��??�������졣
		- ��ʫ����?���ܣ���УDisconnect��?����??�档
		However, it will be called back if the thread where NetClient.FrameMove is called and NetClient.Disconnect is called are same.
		\param errorInfo ??�?��?����?���������릡�??���ErrorInfo?��졣

		\~japanese
		��?��?��?���������?�檹�뫤�٫�ȪǪ���
		- ���髤����Ȫ�໪���?���(Disconnect������)�򪷪�����˪ϡ����Ϋ��٫�Ȫ�?�檷�ު���
		�������� NetClient.FrameMove�������󪹫���ëɪ�NetClient.Disconnect�ު���NetClient.Dispose�������󪹫���ëɪ��Ҫ��Ǫ���Ы�?��Ыë�����몳�Ȫ�����ު���
		\param errorInfo ������릪ǫ�?��?�Ȫ���?����𶪵�쪿�Ϊ����êƪ��ު����٪����ϡ�ErrorInfo�Ϋث�ת˪���ު���
		\~
		*/
		virtual void OnLeaveServer(ErrorInfo *errorInfo) = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P �׷�</a> �� �����ǰų� P2P�׷쿡 �� ����� �߰��Ǵ� ��� �� �޼��尡 �ݹ�˴ϴ�.
		���� ȣ��Ʈ �ڽſ� ���ؼ��� �̰��� ȣ��˴ϴ�.

		���� ��� Ŭ���̾�Ʈ A�� �̹� �� �ִ� �׷� G�� B�� ���� ������
		A�� (B,G)�� �ް�, B�� (A,G), (B,G)�� �ް� �˴ϴ�.

		\param memberHostID �ڱ� �Ǵ� Ÿ peer�� HostID�Դϴ�.
		\param groupHostID P2P �׷��� HostID�Դϴ�.
		\param memberCount ó���� �� ��� �� �Դϴ�.
		\param customField CNetServer.CreateP2PGroup �Ǵ� CNetServer.JoinP2PGroup ���� ����ڰ� �Է��� Ŀ���� �����Ͱ� ���⿡�� �״�� ���޵˴ϴ�.

		\~english
		This method is to be called back either when <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a> is created or when a new member is added to P2P group.
		Also called for local host iteself.

		For an example, if B enters into group G which already has client A in it, then A receives (B,G) and B recieves (A,G) and (B,G).
		\param memberHostID HostID of itself or other peer
		\param groupHostID HostID of P2P group
		\param memberCount The number of menebers after being processed
		\param customField The custom data entered by user via either CNetServer.CreateP2PGroup or CNetServer.JoinP2PGroup will be passed onto here as they are.

		\~chinese
		?��<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%�������P2P?��ʥ����?��?����?�۰����
		??�?������������У��

		������B ?����ʫA�??����?G��?��A ���(B,G)��B ���(A,G)��(B,G)��

		\param memberHostID ����������peer��HostID��
		\param groupHostID P2P?��HostID��
		\param memberCount ��?��������??��
		\param customField � CNetServer.CreateP2PGroup%��� CNetServer.JoinP2PGroup ����??����custom?��?��?�?���?���ꡣ

		\~japanese
		\ref p2p_group���������쪿�ꡢP2P����?�ת��檷������?����ʥ��������ꡢ���Ϋ᫽�ëɪ���?��Ыë�����ު���
		��?����۫��Ȫ�����?���ƪ⪳�쪬�����󪵪�ު���
		�Ǫ��С����髤�����A��?�����êƪ��뫰��?��G��B���檿�����ê���A��(B,G)�������ơ�B��(A,G), (B,G)�������몳�Ȫ˪ʪ�ު���

		\param memberHostID ��ªު������peer��HostID�Ǫ���
		\param groupHostID P2P����?�ת�HostID�Ǫ���
		\param memberCount ?�⪵�쪿���Ϋ���??�Ǫ���
		\param customField CNetServer.CreateP2PGroup�ު���CNetServer.JoinP2PGroup�ǫ�?��?�������������������?���������Ǫ��Ϊު�?ӹ����ު���
		\~
		*/
		virtual void OnP2PMemberJoin(HostID memberHostID, HostID groupHostID, int memberCount, const ByteArray& customField) = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P �׷�</a> �� �����ǰų� ���� P2P�׷쿡�� �Ǿ Ż��� �� �޼��尡 �ݹ�˴ϴ�.
		���� ȣ��Ʈ �ڽſ� ���ؼ��� �̰��� ȣ��˴ϴ�.

		\param memberHostID �ڱ� �Ǵ� Ÿ peer�� HostID�Դϴ�.
		\param groupHostID P2P �׷��� HostID�Դϴ�.
		\param memberCount ó���� �� ��� ���Դϴ�.

		\~english
		This method is to be called back either when <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a> is created or when a peer withdraws.
		Also called for local host iteself.

		\param memberHostID HostID of itself or other peer
		\param groupHostID HostID of P2P group
		\param memberCount The number of members after processed

		\~chinese
		<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%���������peer?������P2P?����?�۰��?����?��
		?����������??�?����У��

		\param memberHostID ����������peer��HostID��
		\param groupHostID P2P?��HostID��
		\param memberCount ��?��������??��

		\~japanese
		\ref p2p_group����������몫��?���P2P����?�תǫ�?����?�����˪��Ϋ᫽�ëɪ���?��Ыë�����ު���
		��?����۫��Ȫ�����?���ƪ⪳�쪬�����󪵪�ު���
		\param memberHostID ����ªު������peer��HostID�Ǫ���
		\param groupHostID P2P����?�ת�HostID�Ǫ���
		\param memberCount ?�⪵�쪿���Ϋ���??�Ǫ���
		\~
		*/
		virtual void OnP2PMemberLeave(HostID memberHostID, HostID groupHostID, int memberCount) = 0;

		/**
		\~korean
		Ÿ Ŭ���̾�Ʈ���� P2P ��� ���(������ Ȥ�� ����)�� �ٲ�� ���� �� �޼��尡 ȣ��˴ϴ�.
		- �ٲ� �� ȣ��Ǵ� ���̹Ƿ� CNetClient.GetPeerInfo �� ȣ���ؼ� CNetPeerInfo.Proud.CNetPeerInfo.m_RelayedP2P �� ���� �����ص� �˴ϴ�.
		- �̰��� �ݹ�Ǵ� �Ͱ� ������� P2P�� ���� ����� �׻� �����մϴ�. �ٸ�, �Ǿ �޽�¡�� �����̸� �ϴ��� ���� �̷���������� ���̰� ���� ���Դϴ�.
		- ProudNet�� P2P ��� ��ο� ���� �ڼ��� ������ <a target="_blank" href="http://guide.nettention.com/cpp_ko#robust_p2p" >ProudNet�� P2P ��� ����</a> �� �����Ͻʽÿ�.

		\param remoteHostID P2P ������ �Ǿ� �ִ� Ÿ peer�� HostID
		\param reason P2P ������ ������ ��쿡�� ErrorType_Ok �� ����ִ�. ��Ÿ�� ���� ���� '�� ������ relay�� �ٲ������'�� ��´�.

		\~english
		This method is called at the moment the connection status to other client via P2P (relay or not) changes.
		Since it is called after the change so it is ok to call CNetClient.GetPeerInfo to view the value of CNetPeerInfo.Proud.CNetPeerInfo.m_RelayedP2P.
		<a target="_blank" href="http://guide.nettention.com/cpp_en#robust_p2p" >P2P performance of ProudNet</a>

		\param remoteHostID HostID of other peer that is connected via P2P
		\param reason If the P2P connection is successful then contains ErrorType_Ok. For other values it contain 'why the connection changed to relay'.

		\~chinese
		?������ʫ��P2P������?��relay ������ȣ���?����?���۰��?����У��
		- ��?����?�������У�ܣ�ʦ���У CNetClient.GetPeerInfo%���?�� CNetPeerInfo.Proud.CNetPeerInfo.m_RelayedP2P%��?��
		- ???��?��?��P2P ��?������������ʦ���ܡ��������peer��?��messaging?��relay?������?����??��
		- ?ProudNet��P2P������?��???�??��<a target="_blank" href="http://guide.nettention.com/cpp_zh#robust_p2p" >ProudNet ��P2P��������</a>%��

		\param remoteHostID P2P?����������peer��Host ID��
		\param reason P2P?��������?����ErrorType_Ok������?��?���ߡ�?��?�?��?��relay������

		\~japanese
		��Ϋ��髤����ȪȪ�P2P����?��(���?�ު�������)��?������ࡢ���Ϋ᫽�ëɪ������󪵪�ު���
		- ?��ê����������󪵪�ު��Ϊǡ�CNetClient.GetPeerInfo�������󪷪�CNetPeerInfo.Proud.CNetPeerInfo.m_RelayedP2P������??���ƪ��ު��Ǫ���
		- ���쪬��?��Ыë������Ϊ�?���ʪ�P2P��Ϊ�����������Ϫ��Ī�ʦ���Ǫ���ӣ����Peer��Ϋ�ë�?���󫰪����?�򪹪몫������������Ϊ���󬪬��������Ǫ���
		- ProudNet��P2P����?�ت�?�����٪���?黪ϡ�\ref robust_p2p��?�Ϊ���������

		\param remoteHostID P2P��?���Ǫ��ƪ������peer��HostID
		\param reason P2P ��?������������˪ϡ�ErrorType_Ok�����êƪ��ު��������������ϡ����ɪ�������?�����?��?��ê��Ϊ��������ު���
		\~
		*/
		virtual void OnChangeP2PRelayState(HostID remoteHostID, ErrorType reason) = 0;

		/**
		\~korean
		�������� ������ ������ �� �ݹ� �˴ϴ�.
		�ش� �̺�Ʈ�� �ݹ��� �� ��, ������ �� ������ �̷������ ������
		OnLeaveServer �� �ݹ� �˴ϴ�.
		(�ش� �Լ��� NetClient ��  NetConnectionParam.m_enableAutoConnectionRecovery �� true �� ���� �Ǿ�� �մϴ�.)

		\param args ������ ������ �� �������� ������ ��� �ֽ��ϴ�.

		\~english
		When connection to the server is lost, a callback is called. After the callback is called for a particular event, if reconnection to the server is not established, a callback occurs for OnLeaveServer.
		(The particular function shall have NetConnectionParam.m_enableAutoConnectionRecovery of NetClient as ��True��)

		\param args When connection is lost, it has a variety of information.

		\~chinese
		?��?��?����??ʦ���?����?������?��������������?����?�� OnLeaveServer��??��?�??����?��
		����?��? NetClient��??��?Ӯ���� NetConnectionParam.m_enableAutoConnectionRecovery��???������_��?��?�??�ȣ�???��? true����?򢣩

		\param args (?�ᣩ�?����Ӯ?��������?����

		\~japanese
		��?�ЪȪ���?���?���쪿�Ȫ��˫�?��Ыë�����ު������Ϋ��٫�Ȫ���?��Ыë����쪿������?�Ъ����?�������ʪ������OnLeaveServer����?��Ыë�����ު���
		(����??��NetClient��NetConnectionParam.m_enableAutoConnectionRecovery��true�����Ҫ�����驪�����ު���)

		\param args��?���?���쪿�Ȫ��������Ī������ê��ߪ�Ǫ��ު���

		\~
		*/
		virtual void OnServerOffline(CRemoteOfflineEventArgs& /*args*/) {}

		/**
		\~korean
		�������� ������ ���� �� �� ������ �̷������ �ݹ� �˴ϴ�.
		(�ش� �Լ��� NetClient ��  NetConnectionParam.m_enableAutoConnectionRecovery �� true �� ���� �Ǿ�� �մϴ�.)

		\param args �� ���ῡ ���� ������ ��� �ֽ��ϴ�.

		\~english
		After connection to the server is lost and then established again, a callback occurs.
		(The particular function shall have NetConnectionParam.m_enableAutoConnectionRecovery of NetClient as ��True��)

		\param args It has information on reconnection.

		\~chinese
		?��?��?����?���??������?��??����?
		����?��? NetClient��??��?Ӯ���� NetConnectionParam.m_enableAutoConnectionRecovery��???������_��?��?�??�ȣ�???��? true����?򢣩

		\param args (?�ᣩ����?������?����

		\~japanese
		��?�ЪȪ���?���?���쪿�������?��������ȫ�?��Ыë�����ު���
		(����??��NetClient��NetConnectionParam.m_enableAutoConnectionRecovery��true�����Ҫ�����驪�����ު���)

		\param args���?��?�������ê��ߪ�Ǫ��ު���

		\~
		*/
		virtual void OnServerOnline(CRemoteOnlineEventArgs& /*args*/) {}

		/**
		\~korean
		�ڽ��� ���� P2P Group ���� Ÿ �Ǿ �������� ������ ������ �� �ݹ� �˴ϴ�.
		(�ش� �Լ��� NetClient ��  NetConnectionParam.m_enableAutoConnectionRecovery �� true �� ���� �Ǿ�� �մϴ�.)

		\param args ������ ���� �Ǿ��� ������ ��� �ֽ��ϴ�.

		\~english
		When other peers within the P2P group where it belongs to lost connection to the server, a callback occurs.
		(The particular function shall have NetConnectionParam.m_enableAutoConnectionRecovery of NetClient as ��True��)

		\param args It has information on the peers that have lost connection.

		\~chinese
		�����?�� P2P Group��P2P����?���������������� PEER��?��??������?��?��?����??ʦ�?����?
		����?��? NetClient��??��?Ӯ���� NetConnectionParam.m_enableAutoConnectionRecovery��???������_��?��?�??�ȣ�???��? true����?򢣩

		\param args (?�ᣩ?����?��PEER��?��??����������?����

		\~japanese
		��ª�?���ƪ���P2P Group?����Ϋԫ�����?�ЪȪ���?���?���쪿�Ȫ�����?��Ыë�����ު���
		(����??��NetClient��NetConnectionParam.m_enableAutoConnectionRecovery��true�����Ҫ�����驪�����ު���)

		\param args��?���?���쪿�ԫ������ê��ߪު�ƪ��ު���

		\~
		*/
		virtual void OnP2PMemberOffline(CRemoteOfflineEventArgs& /*args*/) {}

		/**
		\~korean
		�ڽ��� ���� P2P Group ���� Ÿ �Ǿ �������� ������ ���� �� �� ������ �̷������ �ݹ� �˴ϴ�.
		(�ش� �Լ��� NetClient ��  NetConnectionParam.m_enableAutoConnectionRecovery �� true �� ���� �Ǿ�� �մϴ�.)

		\param args �� ������ �� �Ǿ��� ������ ��� �ֽ��ϴ�.

		\~english
		When other peers within the P2P group where it belongs to lost connection to the server and then gains reconnection, a callback occurs.
		(The particular function shall have NetConnectionParam.m_enableAutoConnectionRecovery of NetClient as ��True��)

		\param args It contains information of the peer reconnected.

		\~chinese
		�����?�� P2P Group��P2P����?���������������� PEER��?��??������?��?��?����??ʦ�?����?
		����?��? NetClient��??��?Ӯ���� NetConnectionParam.m_enableAutoConnectionRecovery��???������_��?��?�??�ȣ�???��? true����?򢣩

		\param args(?�ᣩ����?����PEER��?��??����������?����

		\~japanese
		��ª�?���ƪ���P2P Group?����Ϋԫ�����?�ЪȪ���?���?���쪿�������?���������˫�?��Ыë�����ު���
		(����??��NetClient��NetConnectionParam.m_enableAutoConnectionRecovery��true�����Ҫ�����驪�����ު���)

		\param args���?������쪿�ԫ������ê��ߪު�ƪ��ު���

		\~
		*/
		virtual void OnP2PMemberOnline(CRemoteOnlineEventArgs& /*args*/) {}


		/**
		\~korean
		�������� UDP ����� �������̳��� ���ΰ� �ٲ�� ���� �� �޼��尡 ȣ��ȴ�.
		\param reason ErrorType_Ok �� ��� �������� UDP ����� ���������� �������̸� �������� unreliable RMI �޽�¡�� UDP�� �����Ѵ�.
		��Ÿ ���� ��� �������� UDP ����� �Ұ����ϰ� ������ �ǹ��ϸ� �� �Ⱓ ���� �������� unreliable RMI �޽�¡�� TCP�� �����Ѵ�.

		\~english
		This method is called at the moment that the communication status of UDP communication with server change.
		\param reason If ErrorType_Ok then UDP communication with server is normal and unreliable RMI messaging goes to server via UDP.
		Having other values means UDP communication witer server is unavailable and during this state, unreliable RMI messaging goes to server via TCP.

		\~chinese
		?��?����UDP��������?����?����?���۰������У��
		\param reason ErrorType_Ok ��?��?��?����UDP����?�����ȣ�?��?����unreliable RMI messaging?�UDP��
		����?��?��ګ�����?��?����UDP?�����ᣬ?Ѣ??��?����unreliable RMI messaging?�TCP��

		\~japanese
		��?��?�Ȫ�UDP���᪬���ȪʪΪ��ɪ�����?������ࡢ���Ϋ᫽�ëɪ������󪵪�ު���
		\param reason ErrorType_Ok �����ꡢ��?��?�Ȫ�UDP���᪬���Ȫ�������ʪΪǡ���?��?�Ȫ�unreliable RMI��ë�?���󫰪�UDP��?릪��ު���
		����������ꡢ��?��?�Ȫ�UDP���᪬�Ǫ��ʪ��ʪê����Ȫ���ګ���ơ�����Ѣ����˫�?��?�Ȫ�unreliable RMI��ë�?���󫰪�TCP��?릪��ު���
		\~
		*/
		virtual void OnChangeServerUdpState(ErrorType /*reason*/) {}

		/**
		\~korean
		�������� �ð��� ����ȭ �� ������ ȣ��ȴ�.
		���� �ð� ����ȭ�� �� �޼����� ȣ�� Ƚ���� �����Ҽ��� ���� ��Ȯ���� �����Ѵ�.
		�� �޼��� �������� GetServerTimeMs()�� ȣ���ص� �ȴ�.

		\~english
		Called every time when time is synchronized with server
		Server time sybchronization becomes more accurate with as frequency of calling this method increases.
		It is also possible to call GetServerTimeMs() within this metod.

		\~chinese
		��??��?����??������?������У��
		��?��??��������?��۰���������?��ʥ���ʥ��
		��۰��?�ʦ�����GetServerTime()��

		\~japanese
		��?��?�Ȫ����બ��Ѣ������������Ȫ������󪵪�ު���
		��?��?�������Ѣ���ϡ����Ϋ᫽�ëɪ���������?��?ʥ����۪���?����������?ʥ���ު���
		���Ϋ᫽�ë�?�Ǫ� GetServerTimeMs()�������󪷪ƪ��ު��Ǫ���
		\~
		*/
		virtual void OnSynchronizeServerTime() = 0;
	};

	/**  @} */
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
