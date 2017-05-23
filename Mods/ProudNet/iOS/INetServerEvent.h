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
#include "AddrPort.h"
#include "NetClientInfo.h"
#include "acr.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	//class CUserWorkerThreadCallbackContext;
	/** \addtogroup net_group
	*  @{
	*/

	/** 
	\~korean
	CNetServer �� event sink

	���
	- �� ��ü�� �����Ѵ�.
	- CNetServer �� �Ķ���ͷ� �����Ѵ�.

	\~english
	event sink for CNetServer

	Usage
	- Realize this object
	- Pass to CLanServer as a parmeter.

	\~chinese
	CNetServer ��event sink

	����
	- ??�?�ڡ�
	- ��???��? CNetServer%��

	\~japanese
	CnetServer��event sink

	����
	- ���Ϋ��֫������Ȫ�?�ު��ު���
	- CNetServer�˫ѫ��?��?��?ӹ���ު���
	\~
	*/
	class INetServerEvent : public INetCoreEvent
	{
	public:
		virtual ~INetServerEvent() {}

		/** 
		\~korean
		Ŭ���̾�Ʈ�� ������ ������ �߻��ϴ� �̺�Ʈ
		- OnConnectionRequest���� ���� �㰡�� �� Ŭ���̾�Ʈ�� ���ؼ��� �ݹ�ȴ�.
		\param clientInfo ������ ���� Ŭ���̾�Ʈ

		\~english
		Event that occurs when client attempts to connect
		- Only called back for the client that received access permission from OnConnectionRequest  
		\param clientInfo client requested to connect

		\~chinese
		��?��ʫ��?����??����event��
		- ��?�OnConnectionRequest��??������ʫ��?��
		\param clientInfo ��??������ʫ��

		\~japanese
		���髤����Ȫ���?������?�檹�뫤�٫��
		- OnConnectionRequest��������ʦ�򪷪����髤����Ȫ�?���ƪΪ߫�?��Ыë�����ު���
		\param clientInfo ��?���쪿���髤�����
		\~
		*/
		virtual void OnClientJoin(CNetClientInfo *clientInfo) = 0;

		/** 
		\~korean
		Ŭ���̾�Ʈ�� ������ �����ϸ� �߻��ϴ� �̺�Ʈ�Դϴ�.
		\param clientInfo ������ ������ Ŭ���̾�Ʈ�� �����Դϴ�.
		\param errorInfo ������ ������ Ŭ���̾�Ʈ�� ���� ���� �����Դϴ�. 
		ErrorInfo.m_type ���� ���� ������ ������, ErrorInfo.
		�ڼ��� ���� ErrorInfo ���򸻿� �ֽ��ϴ�.
		\param comment Ŭ���̾�Ʈ�� CNetClient.Disconnect �� �Ķ���� comment �� ���� ������ ���ڿ��Դϴ�.

		\~english
		Event that occurs when client terminates connection
		\param clientInfo client info that is disconnected
		\param errorInfo disconnection info of client that is disconneced 
		ErrorInfo.m_type value shows how disconnection processed
		Please refer ErrorInfo help section.
		\param comment text string sent by client via parameter comment of CNetClient.Disconnect

		\~chinese
		��ʫ���?����??����event��
		\param clientInfo ���?������ʫ���ӡ�
		\param errorInfo ���?����ʫ��?��������ӡ�
		ErrorInfo.m_type ?����?�������??��
		??���ErrorInfo?��졣
		\param comment ��ʫ��? CNetClient.Disconnect%��??comment???���ݬ����

		\~japanese
		���髤����Ȫ���?����𶪹���?�檹�뫤�٫�ȪǪ���
		\param clientInfo ��?����𶪵�쪿���髤����Ȫ����êǪ���
		\param errorInfo ��?����𶪵�쪿���髤����Ȫ���?������êǪ��� 
		ErrorInfo.m_type ������?����?�ժ�ErrorInfo��
		�٪����ϡ�ErrorInfo�Ϋث�ת�?�Ϊ���������
		\param comment ���髤����Ȫ� CNetClient.Disconnect �Ϋѫ��?��?�����Ȫ��ת����쪿���֪�Ǫ���
		\~
		*/
		virtual void OnClientLeave(CNetClientInfo *clientInfo, ErrorInfo *errorinfo, const ByteArray& comment) = 0;

		/**
		\~korean
		Ŭ���̾�Ʈ�� ������ �� �ݹ� �˴ϴ�.
		�ش� �̺�Ʈ�� �ݹ��� �� ��, �� ������ �̷������ ������
		OnClientLeave �� �ݹ� �˴ϴ�.
		(�ش� �Լ��� NetClient ��  NetConnectionParam.m_enableAutoConnectionRecovery �� true �� ���� �Ǿ�� �մϴ�.)

		\param args ������ ���� Ŭ���̾�Ʈ�� ������ ��� �ֽ��ϴ�.

		\~english
		A callback occurs when the client is disconnected.
		A callback occurs for OnClientLeave if reconnection does not occur.
		(The particular function shall have NetConnectionParam.m_enableAutoConnectionRecovery of NetClient as ��True��)

		\param ars It contains information on a disconnected client.

		\~chinese
		??��?Ӯ��??��?
		��?������?�������������?������??? OnClientLeave����?Ӯ??��??����?��
		����?��? NetClient��??��?Ӯ���� NetConnectionParam.m_enableAutoConnectionRecovery��???������_��?��?�??�ȣ�???��? true����?򢣩

		\param args(?�ᣩ?����?����?Ӯ��?����

		\~japanese
		���髤����Ȫ��?���쪿�Ȫ��˫�?��Ыë�����ު���
		���Ϋ��٫�Ȫ���?��Ыë����쪿�������?�������ʪ������
		OnClientLeave����?��Ыë�����ު���
		(����??��NetClient��NetConnectionParam.m_enableAutoConnectionRecovery��true�����Ҫ�����驪�����ު���)

		\param args��?���?���쪿���髤����Ȫ����ê��ߪ�Ǫ��ު���

		\~
		*/
		virtual void OnClientOffline(CRemoteOfflineEventArgs& /*args*/) {}

		/**
		\~korean
		Ŭ���̾�Ʈ�� ���� �� �� ���� �Ǿ��� �� �ݹ� �˴ϴ�.
		(�ش� �Լ��� NetClient ��  NetConnectionParam.m_enableAutoConnectionRecovery �� true �� ���� �Ǿ�� �մϴ�.)

		\param args �� ������ �� Ŭ���̾�Ʈ�� ������ ��� �ֽ��ϴ�.

		\~english
		A callback occurs when the client is disconnected and then reconnected.
		(The particular function shall have NetConnectionParam.m_enableAutoConnectionRecovery of NetClient as ��True��)

		\param args It contains information on a reconnected client.

		\~chinese
		��?Ӯ��?������?��??����?
		����?��? NetClient��??��?Ӯ���� NetConnectionParam.m_enableAutoConnectionRecovery��???������_��?��?�??�ȣ�???��? true����?򢣩

		\param args(?�ᣩ����?������?Ӯ����?����

		\~japanese
		���髤����Ȫ��?���쪿�������?�����Ȫ��˫�?��Ыë�����ު���
		(����??��NetClient��NetConnectionParam.m_enableAutoConnectionRecovery��true�����Ҫ�����驪�����ު���)

		\param args���?������쪿���髤����Ȫ����ê��ߪ�Ǫ��ު���
		\~
		*/
		virtual void OnClientOnline(CRemoteOnlineEventArgs& /*args*/) {}


		/** 
		\~korean
		Ŭ���̾�Ʈ�� ������ ó�� ������ �õ��ϸ� �ݹ�Ǵ� �̺�Ʈ
		- �� �̺�Ʈ������ ������ Ŭ���� ���� �õ��� ������ ������ ������ �������� �����Ѵ�.
		���� ������ ��� Ŭ���̾�Ʈ�� �������� ������ �����ϸ� Ŭ���̾�Ʈ��
		ErrorType_NotifyServerDeniedConnection �� �ް� �ȴ�.
		���� ������ ��� Ŭ���̾�Ʈ�� �������� ������ �����ϰ� �Ǹ� Ŭ���̾�Ʈ�� �� HostID ��
		�Ҵ�ް� �ȴ�. �̶� ������ OnClientJoin �̺�Ʈ�� �ݹ�ȴ�.

		���ǻ���
		- ����! ���⿡�� ������ �α׿� ����(���̵�,��й�ȣ)�� �ְ���� ���ƾ� �Ѵ�.
		�ֳ��ϸ� ���⼭ Ŭ���̾�Ʈ�� ������ ������ Ŀ���� �����ʹ� �� ��ȣȭ�Ǿ� �ֱ�
		�����̴�.

		\param clientAddr Ŭ���̾�Ʈ�� ���ͳ� �ּ�
		\param userDataFromClient Ŭ���̾�Ʈ���� ���� Ŀ���� ������. �� ���� Ŭ���̾�Ʈ���� ������ �����
		�־��� �Ķ���� CNetConnectionParam::m_userData ���� �־��� ���̴�.
		\param reply �� �̺�Ʈ �ݹ鿡�� �� �ʵ忡 ���� ä��� Ŭ���̾�Ʈ�� �������� ���� ���
		INetClientEvent::OnJoinServerComplete ���� �ް� �ȴ�.
		\return Ŭ���̾�Ʈ�κ����� ������ ������ ���̶�� �� �Լ��� true�� �����ϸ� �ȴ�. 

		\~english
		 Event called back when client attempts to connect to server for the first time
		- This event is where to decide if server accepts the attempt or not
		If refused then client fails to connect to server and client receives ErrorType_NotifyServerDeniedConnection.
		If accepted then client succeeds to connect to server and a new HostID will be allocated to client.
   		This is when OnClientJoin event is called back to server

		Note
		- NEVER! to send/receive user logon info(user account name and/or password) in here.
	 	  That is because the custom data from cliet to server is not encrypted.

		\param clientAddr Internet address of client
		\param userDataFromClient The custom data from client
					    This value is the value that was entered at parameter CNetConnectionParam::m_userData when client was connected to server.
		\param reply If this event callback fills a value to this field then client will receive the result of connection to server from INetClientEvent::OnJoinServerComplete.
		\return If to accept the connection reqeust from client then this function should return true.

		\~chinese
		��ʫ���???����?��?��?��event��
		- ��event?����?���?��ʫ��???��?����?��
		������?��?����ʫ?��?����?��?��?����ʫ?���ErrorType_NotifyServerDeniedConnection��
		�����?��?����ʫ?��?����?��?������ʫ?����������Host ID��??����?����?OnClientJoin event��

		�������
		- ??���?��������?��?����?���ӣ�??����?����?�١�
		��?�?����ʫ����?��?����custom?����ުʥ���ܡ�

		\param clientAddr ��ʫ����??�򣡣
		\param userDataFromClient ��ʫ?����custom?�ߡ�???��?��ʫ?������?����?��?�����?? CNetConnectionParam::m_userData%?����?��
		\param reply �����event����?��?��???���?��?����ʫ?��?����?��?��?INetClientEvent::OnJoinServerComplete ��⥡�
		\return ��??��ʫ��?��?�������?����true?ʦ��

		\~japanese
		���髤����Ȫ���?��?���������?���˪��ȫ�?��Ыë�����뫤�٫�ȪǪ���
		- ���Ϋ��٫�ȪǪϫ�?��?�����髤����Ȫ���?����������몫��ﾪ��몫��̽�Ҫ��ު���
		�⪷����ﾪ������ꡢ���髤����Ȫϫ�?��?�Ȫ���?���������ơ����髤����Ȫ�
		ErrorType_NotifyServerDeniedConnection ��������誦�˪ʪ�ު���
		�⪷��������������ꡢ���髤����Ȫϫ�?��?�Ȫ���?�������ơ����髤����Ȫ��檷��HostID���ܪ�?�ƪƪ�骦���Ȫ˪ʪ�ު�������������?��?��OnClientJoin���٫�Ȫ���?��Ыë�����ު���

		���������
		- �?�������ǫ�?��?�Ϋ���������(ID���ѫ���?��)�������ꪷ�ƪϪ����ު���
		�ʪ��ʪ顢�����ǫ��髤����Ȫ���?��?����뫫�������?����ު��?������ƪ��몫��Ǫ���

		\param clientAddr ���髤����ȪΫ���?�ͫëȫ��ɫ쫹
		\param userDataFromClient ���髤����Ȫ�����ê����������?�����������ϫ��髤����Ȫ�ꫵ?��?����?�������쪿�ѫ��?��?��CNetConnectionParam::m_userData�����쪿���Ǫ���
		\param reply ���Ϋ��٫�ȫ�?��Ыë��Ǫ��Ϋի�?��ɪ����������ȡ����髤����Ȫϫ�?��?�Ȫ���?̿����INetClientEvent::OnJoinServerComplete��������誦�˪ʪ�ު���
		\return ���髤����Ȫ������?�����������ʪ顢����??��true��꫿?�󪷪ު��� 
		\~
		*/
		virtual bool OnConnectionRequest(AddrPort /*clientAddr*/, ByteArray& /*userDataFromClient*/, ByteArray& /*reply*/) {
			return true;
		}

		/** 
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P �׷�</a> �� �� ����� �߰��Ǵ� ������ ��� Ŭ���̾�Ʈ������ �Ϸ�Ǹ� �߻��ϴ� �̺�Ʈ�Դϴ�.
		- ���� �׷� G�� �� ��� M1,M2,M3�� �ִٰ� ������ ��� �ű� ��� M4�� �ִ´ٰ� �սô�.
		�̶� JoinP2PGroup()�� ���� M4�� �߰��Ǵ��� ��� �Ϸ�Ǵ� ���� �ƴմϴ�. �� Ŭ���̾�Ʈ
		M1,M2,M3������ ���� 'M4�� �߰��Ǿ���' ����(INetClientEvent.OnP2PMemberJoin)�� ���� �ʾҰ� M4������ M1,M2,M3,M4 ��ο� ���� '�߰��Ǿ��� ����'(INetClientEvent.OnP2PMemberJoin)�� ���� �ʾұ� �����Դϴ�.
		�� �̺�Ʈ�� M4�� ����, M1,M2,M3,M4���� �̵��� ��� ���� ���� �������� Ȯ���� �Ŀ��� �߻��˴ϴ�.
		- CreateP2PGroup�� ���ؼ��� ���������� �� �̺�Ʈ�� �߻��մϴ�. 
		
		\param groupHostID \ref �׷��� HostID
		\param memberHostID �׷� ����� HostID
		\param result ErrorType_Ok �̸� ���������� �߰������� �ǹ��ϸ�,ErrorType_AlreadyExists �̸� �̹� �׷쳻 ���ִ� ������� �ǹ� �մϴ�.(���� �ߴٴ� �ǹ̴� �ƴ�)
		�׿� �ٸ� ���̸� �߰��� ���������� �ǹ��մϴ�. 
		���� ��� CNetServer.CreateP2PGroup Ȥ�� CNetServer.JoinP2PGroup ȣ�� �Ŀ� �� �ݹ��� �ֱ� ����
		CNetServer.LeaveP2PGroup Ȥ�� CNetServer.DestroyP2PGroup �� ȣ�� �ϰų�, �ش� Ŭ���̾�Ʈ�� ���ÿ� �������� ������ ���� �ִ� ���̾��ٸ�
		�ٸ� ���� ���⿡ �� �� �ֽ��ϴ�. 

		\~english
		The event that occurs when the process adding a new member to <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a> is completed in all client
		- Assuming that there are existing member M1, M2 and M3 in group G and we try to add a new member M4.
		Even if M4 is added by JoinP2PGroup(), the process is not to be completed immediately.
		This is because each client M1, M2 and M3 did not yet receive the report(INetClientEvent.OnP2PMemberJoin) that 'M4 is added',
		and M4 did not yet receive the report(INetClientEvent.OnP2PMemberJoin) that M4 is added to M1, M2, M3 and M4. 
		This event, for M4, occurs only after server acknowledges that M1, M2, M3 and M4 received necesary info.
		- The event also occurs for CreateP2PGroup. 
		
		\param groupHostID HostId of \ref group
		\param memberHostID HostID of group member
		\param result If ErrorType_Ok then it means successfully added, if ErrorType_AlreadyExists then it is a member that already in group. (does not mean it falied to)
		If has other values then it means failed to add. 
		For an example,
		Case1. Calling CNetServer.LeaveP2PGroup or CNetServer.DestroyP2PGroup between the moment after calling CNetServer.CreateP2PGroup or CNetServer.JoinP2PGroup and the moment before this callback occurs, OR  
		Case2. the client was terminating its connection to server at the same time,
		For each case, an other value can enter here.

		\~chinese
		��<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%��ʥ����?��?��������ʫ���?����???����event��
		- ����ʣ??G�����?����?M1��M2��M3����ʥ����?M4.
		???����JoinP2PGroup()��ʥM4����?ء?��?����?��?��ʫM1,M2,M3 ??�����M4����ʥ����?ͱ��INetClientEvent.OnP2PmemberJoin�����M4�?�����?M1��M2��M3��M4������ܡ����ʥ����?ͱ��INetClientEvent.OnP2PMemberJoin����
		�event?M4�����?��??M1��M2��M3��M4��ݻ�������??�档
		- �?CreateP2PGroup?���event��

		\param groupHostID \ref ?��Host ID��
		\param memberHostID ?��?��Host ID��
		\param result ErrorType_Ok ��?��ګ���ʥ����������ErrorType_AlreadyExists��?��ګ����?��??����?����������?�������֣�
		�������ʥ����?��?��ګ���?��
		��������У CNetServer.CreateP2PGroup%��� CNetServer.JoinP2PGroup%����?��ʫ��?��??��?����?��?��������?ʦ�?��?�졣

		\~japanese
		\ref p2p_group���檷������?����ʥ�����Φ�窱��ƪΫ��髤����ȪǪ�����������?�檹�뫤�٫�ȪǪ���
		- �⪷������?��G��?�����?M1,M2,M3�������?�Ҫ������ꡢ��Ю����?M4�������Ȫ��ު��窦��
		��������JoinP2PGroup()�˪�ê�M4����ʥ�����Ȫ��ƪ����������������缾�ǪϪ���ު��������髤�����M1,M2,M3�ǪϪު���M4����ʥ���쪿���Ȫ�����ͱ(INetClientEvent.OnP2PMemberJoin)�������ƪ��ʪ���M4�Ǫ�M1,M2,M3,M4����ƪ�?���롸��ʥ���쪿���Ȫ�����ͱ(INetClientEvent.OnP2PMemberJoin)�������ƪ��ʪ�����Ǫ���
		���Ϋ��٫�Ȫ�M4��?���ơ�M1,M2,M3,M4�Ǫ����������������Ϊ�?��?�����㪷�ƪ���?�檵��ު���
		- CreateP2PGroup��?���ƪ���?�˪��Ϋ��٫�Ȫ�?�檷�ު���

		\param groupHostID \ref ����?�ת� HostID
		\param memberHostID ����?�׫���?�� HostID
		\param result ErrorType_Ok �Ǫ������ʥ�����������Ȫ���ګ���ơ�ErrorType_AlreadyExists�Ǫ����?�˫���?��?�����êƪ������?�Ǫ��몳�Ȫ���ګ���ު���(���������Ȫ�����ګ�ǪϪ���ު���)
		����������Ǫ������ʥ�������������Ȫ���ګ���ު���
		�Ǫ��С�CNetServer.CreateP2PGroup �ު���CNetServer.JoinP2PGroup�������󪷪��������Ϋ�?��Ыë���������ˡ�CNetServer.LeaveP2PGroup�ު���CNetServer.DestroyP2PGroup�������󪹪�����?���髤����Ȫ������˫�?��?�Ȫ���?��﷪êƪ�����Ǫ����顢����������������몳�Ȫ��Ǫ��ު��� 

		\~
		*/
		virtual void OnP2PGroupJoinMemberAckComplete(HostID groupHostID, HostID memberHostID, ErrorType result) = 0;

		/** 
		\~korean
		user work thread pool�� �����尡 ������ �� �� �޼��尡 ȣ��ȴ�.

		\~english
		This method is called when thread of user work thread pool starts.

		\~chinese
		user work thread pool��?��?���?�����۰��?����У��

		\~japanese
		user work thread pool�Ϋ���ëɪ���㷪������˪��Ϋ᫽�ëɪ������󪵪�ު���
		\~
		*/
		virtual void OnUserWorkerThreadBegin() = 0;

		/** 
		\~korean
		user work thread pool�� �����尡 ������ �� �� �޼��尡 ȣ��ȴ�.

		\~english
		This method is called when thread of user work thread pool terminates.

		\~chinese
		user work thread pool��?��?���?�����۰��?����У��

		\~japanese
		user work thread pool�Ϋ���ëɪ���㷪������˪��Ϋ᫽�ëɪ������󪵪�ު���
		\~
		*/
		virtual void OnUserWorkerThreadEnd() = 0;

		/** 
		\~korean
		Ŭ���̾�Ʈ�� ��ŷ���ߴٴ� ��Ȥ�� ���� �� �� �޼��尡 ȣ��ȴ�.
		\param clinetID �ǽɵǴ� client�� HostID
		\param hackType ��ŷ�� ���� 

		\~english TODO:translate needed.
		This method is called when there is suspicion that the client has been hacked. 
		\param clinetID HostID of the client under suspicion
		\param hackType Type of hacking. 

		\~chinese
		������ʫ������?�����۰������У��
		\param clinetID ʦ����client��Host ID��
		\param hackType ����??��

		\~japanese
		���髤����Ȫ��ϫë��󫰪��쪿�Ȫ����������������˪��Ϋ᫽�ëɪ������󪵪�ު���
		\param clinetID ������client��HostID
		\param hackType �ϫë��󫰪���׾
		\~
		*/
		virtual void OnClientHackSuspected(HostID /*clientID*/,HackType /*hackType*/) {}

		/** 
		\~korean
		P2P group�� ���ŵ� ���� �� �޼��尡 ȣ��˴ϴ�.
		- P2P group�� ���ŵǴ� ������ Proud.CNetServer.DestroyP2PGroup �� ȣ���ϰų� P2P group �� �Ҽӵ� ������ �����
		�������� ������ ������ �� ���Դϴ�.

		\~english
		This method is called right after P2P group is removed. 
		- The condition P2P froup is removed is EITHER calling Proud.CNetServer.DestroyP2PGroup OR the last member of P2P group terminates its connection to server.

		\~chinese
		P2P group��?��������۰������У��
		- P2P group��?���?������У Proud.CNetServer.DestroyP2PGroup%���?�?��P2P group��������?��?��?�����?����

		\~japanese
		P2P group����۪��쪿�����˪��Ϋ᫽�ëɪ������󪵪�ު���
		- P2P group����۪����?��ϡ�Proud.CNetServer.DestroyP2PGroup�������󪹪���P2P group���?���쪿�����Ϋ���?����?��?�Ȫ���?�������������ʪɪǪ���
		\~
		*/
		virtual void OnP2PGroupRemoved(HostID /*groupID*/) {}

		/** 
		\~korean
		RMI ȣ�� �Ǵ� �̺�Ʈ �߻����� ���� user worker���� callback�� ȣ��Ǳ� ������ ȣ��˴ϴ�.
		���α׷� ���� ���� ������ ���� ����ϼŵ� �˴ϴ�.

		\~english
		Called right before calling callback by either RMI calling or user worker due to event occur. Also can be used for performance test purpose.

		\~chinese
		��?RMI�������event��?�棬�user worker��callback��У������У��
		�ʦ��?������?������?���ġ�

		\~japanese
		RMI�����󪷪ު��ϫ��٫�Ȫ�?��˪�ê�user worker�ǫ�?��Ыë��������󪵪������������󪵪�ު���
		�׫�����?���������ҪΪ�����Ūêƪ��ު��Ǫ���
		\~
		*/
		//virtual void OnUserWorkerThreadCallbackBegin(CUserWorkerThreadCallbackContext* ctx){}
		/** 
		\~korean
		RMI ȣ�� �Ǵ� �̺�Ʈ �߻����� ���� user worker���� callback�� ������ ���Ŀ� ȣ��˴ϴ�.
		���α׷� ���� ���� ������ ���� ����ϼŵ� �˴ϴ�.

		\~english
		Called right before calling callback by either RMI calling or user worker due to event occur. Also can be used for performance test purpose.

		\~chinese
		��?RMI�������event��?�棬�user worker��callback����������У��
		�ʦ�?������?������?������ġ�

		\~japanese
		RMI�����󪷪ު��ϫ��٫�Ȫ�?��˪�ê�user worker�ǫ�?��Ыë����꫿?�󪷪������������󪵪�ު���
		�׫�����?���������ҪΪ�����Ūêƪ��ު��Ǫ���
		\~
		*/
		//virtual void OnUserWorkerThreadCallbackEnd(CUserWorkerThreadCallbackContext* ctx){}

		/** 
		\~korean
		���� �ð����� user worker thread pool���� �ݹ�Ǵ� �Լ��Դϴ�.  <a target="_blank" href="http://guide.nettention.com/cpp_ko#server_timer_callback" >�������� Ÿ�̸� ���� RMI �̺�Ʈ ó���ϱ�</a>����Դϴ�. 		
		\param context CStartServerParameter.m_timerCallbackContext ���� �Էµ� ���� �����մϴ�.

		\~english
		Function called back at user worker thread pool periodically. This is a <a target="_blank" href="http://guide.nettention.com/cpp_en#server_timer_callback" >Managing Timer loop RMI Event from server</a> function.		
		\param context same as the value entered at CStartLanServerParameter.m_timerCallbackContext

		\~chinese
		��̰��ӫ??�user worker thread pool��?����?��<a target="_blank" href="http://guide.nettention.com/cpp_zh#server_timer_callback" >���?��?��Timer Loop��RMI��Event</a> ������
		\param context ?� CStartLanServerParameter.m_timerCallbackContext%?����?���ҡ�

		\~japanese
		������઴�Ȫ�user worker thread pool�ǫ�?��Ыë������??�Ǫ���\ref server_timer_callback Ѧ���Ǫ��� 
		\param context CStartServerParameter.m_timerCallbackContext ���������쪿�����Ҫ��Ǫ���
		\~
		*/
		//virtual void OnTick(void* context){}

	};

	/** 
	\~korean
	������ ���� �ݹ� ���� ����ü�Դϴ�.
	������ �����Ǵ� ������ �����ϴٸ�, ����ȣȯ���� ���� �̸� �غ�Ǿ� ���� ���Դϴ�.

	\~english
	Callback factor structure that related with thread
	It does not supply any variable yet. It exists for lower compatibility.

	\~chinese
	��?��?����?���?��?��
	?�??���������??������?����?������������?���쫡�

	\~japanese
	����ë�?֧��?��Ыë����ϰ��?�Ǫ���
	�ު���ꪵ��ʪ�??�Ϫ���ު��󪬡������������Ϊ�������ê����᪵��ƪ�������Ǫ���
	\~
	*/
// 	class CUserWorkerThreadCallbackContext
// 	{
// 	};
	/**  @} */
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
