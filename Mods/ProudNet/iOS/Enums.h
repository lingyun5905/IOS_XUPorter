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

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup net_group
	*  @{
	*/

	// ����: �̰͵� �ٲٸ� ProudClr namespace�� ���� �ɺ��� �����ؾ� �Ѵ�.


	/**
	\~korean
	�޽��� �۽� �켱����
	- <a target="_blank" href="http://guide.nettention.com/cpp_ko#message_priority" >�޽��� �۽� �켱���� ���</a> ����.

	\~english 
	Message transmission priority.
	Refer to \ref message_priority.

	\~chinese
	����?��?�?��
	- ?��<a target="_blank" href="http://guide.nettention.com/cpp_zh#message_priority" >����?����?�?��������</a>%��

	\~japanese
	��ë�?������׫髤����ƫ�
	- \ref message_priority ?�� 
	\~
	*/
	enum MessagePriority
	{
	// Most priority. Ping, for example. ProudNet internal. Do not use it.
		MessagePriority_Ring0 = 0,

	// ProudNet internal. Do not use it.
		MessagePriority_Ring1,

		/**
		\~korean
		���� �켱����

		\~english 
		High priority

		\~chinese
		����?�?��

		\~japanese
		�Ԫ��׫髤����ƫ�
		\~
		*/
		MessagePriority_High,

		/**
		\~korean
		���� �켱����. ���� ���� ����.

		\~english 
		Medium priority. Used most frequently

		\~chinese
		����?�?������������

		\~japanese
		���תΫ׫髤����ƫ������������Ū��ު���
		\~
		*/
		MessagePriority_Medium,

		/**
		\~korean
		���� �켱����

		\~english 
		Low priority

		\~chinese
		���?�?��

		\~japanese
		��׫髤����ƫ�
		\~
		*/
		MessagePriority_Low,

// Lowest priority. For ProudNet internal use.
		MessagePriority_Ring99,

		// For internal use. Do not use this.
		MessagePriority_LAST,
	};

	// Ȧ��Ī ��Ŷ�� ���� �� �ִ�. �̰��� Ʈ������ �����ϸ� �ȵǹǷ� �켱������ �������� �д�.
	static const MessagePriority MessagePriority_Holepunch = MessagePriority_Ring99;

	// ����: �̰͵� �ٲٸ� ProudClr namespace�� ���� �ɺ��� �����ؾ� �Ѵ�.

	enum MessageReliability
	{
		MessageReliability_Unreliable = 0,
		MessageReliability_Reliable,
		MessageReliability_LAST,
	};

	// ����: �̰͵� �ٲٸ� ProudClr namespace�� ���� �ɺ��� �����ؾ� �Ѵ�.

	/**
	\~korean
	���� Ÿ�� �ڵ�

	\~english 
	Error type code.

	\~chinese
	???����?��

	\~japanese
	����?�����׫�?��.
	\~
	*/
	enum ErrorType
	{
		/**
		\~korean
		����. ���� ����.

		\~english 
		Success. No problem

		\~chinese
		����?��??��

		\~japanese
		�������ʪ�
		\~
		*/
		ErrorType_Ok = 0,

		/**
		\~korean
		���� ��Ȳ �߻�

		\~english 
		Exception occurred

		\~chinese
		?��������?��

		\~japanese
		����?��?��
		\~
		*/
		ErrorType_Unexpected,

		/**
		\~korean
		�̹� ����Ǿ� ����

		\~english 
		Already connected

		\~chinese
		�?��?��??
		\~japanese
		?����?����ƪ��ު���
		\~
		*/
		ErrorType_AlreadyConnected,

		/**
		\~korean
		TCP ���� ����

		\~english 
		TCP connection failed

		\~chinese
		TCP ?����?��

		\~japanese
		TCP��?����
		\~
		*/
		ErrorType_TCPConnectFailure,

		/**
		\~korean
		�߸��� ��ĪŰ

		\~english 
		Wrong matching key

		\~chinese
		??��??key��

		\~japanese
		���ުê�??��?
		\~
		*/
		ErrorType_InvalidSessionKey,

		/**
		\~korean
		��ȣȭ�� ��������

		\~english 
		Encoding failed

		\~chinese
		ʥ����?��

		\~japanese
		��?�����������ު�����
		\~
		*/
		ErrorType_EncryptFail,

		/**
		\~korean
		��Ŀ�� ���� �����͸� �����߰ų� ��ȣȭ�� ��������

		\~english 
		Either the hacker transmitted corrupt data or decoding failed.

		\~chinese
		����ʦ��?����???�ߣ��������?��?��

		\~japanese
		�ϫë�?��?�쪿��?����?�ꪷ������?�����������ު�����
		\~
		*/
		ErrorType_DecryptFail,

		/**
		\~korean
		���� ���� ������ �ʹ� ���� �ɷ��� ���� ó����

		\~english 
		Processed as failure since the server connection process took too much time.

		\~chinese
		����?��?��????���?��

		\~japanese
		��?��?��?Φ�窱�Ȫƪ⪫����Φ��������?��˪ʪ�ު�����
		\~
		*/
		ErrorType_ConnectServerTimeout,

		/**
		\~korean
		���� ������ ���� �������� ������ �ٸ�

		\~english 
		Protocol version for server connection is different

		\~chinese
		��?��?����????�������ҡ�

		\~japanese
		��?��?��?�Ϊ���Ϋ׫�ȫ����?������ު��ު���
		\~
		*/
		ErrorType_ProtocolVersionMismatch,

		/**
		\~korean
		���� �� ������ ������ ����.

		\~english 
		Problem occured while license validation task.

		\~chinese
Problem occured while license validation task.

		\~japanese
Problem occured while license validation task.
		
		\~
		*/
		ErrorType_InvalidLicense,

		/**
		\~korean
		������ ������ �ǵ������� �ź�����

		\~english 
		Server intentionally rejected connection

		\~chinese
		��?��ͺ����??�ȡ�

		\~japanese
		��?��?����?����?�ܪ��������ު�����
		\~
		*/
		ErrorType_NotifyServerDeniedConnection,

		/**
		\~korean
		���� ���� ����!

		\~english 
		Server connection success!

		\~chinese
		��?��?������

		\~japanese
		��?��?��?����
		\~
		*/
		ErrorType_ConnectServerSuccessful,

		/**
		\~korean
		����� ȣ��Ʈ���� ������ ��������

		\~english 
		The correspondent host removed the connection

		\~chinese
		?۰��������?�ȡ�

		\~japanese
		������Ϋ۫��Ȫ���?����𶪷�ު�����
		\~
		*/
		ErrorType_DisconnectFromRemote,

		/**
		\~korean
		���� ȣ��Ʈ���� ������ ��������

		\~english 
		Our host removed the connection

		\~chinese
		??��������?�ȡ�

		\~japanese
		?���Ϋ۫��Ȫ���?����𶪷�ު�����
		\~
		*/
		ErrorType_DisconnectFromLocal,

		/**
		\~korean
		������ ��Ȳ�� �ҷ��� �� �ִ� ���ڰ� ����

		\~english 
		There is a factor that can cause a dangerous situation

		\~chinese
		���ʦ��������???�����ȡ�

		\~japanese
		��?��?�Ϫ��ڪ��ê���ʦ�����Ϊ�����������ު���
		\~
		*/
		ErrorType_DangerousArgumentWarning,

		/**
		\~korean
		�� �� ���� ���ͳ� �ּ�

		\~english 
		Unknown internet address

		\~chinese
		ڱ�����??�򣡣

		\~japanese
		���ƪ��ʪ�����?�ͫëȫ��ɫ쫹
		\~
		*/
		ErrorType_UnknownAddrPort,

		/**
		\~korean
		���� �غ� ����

		\~english 
		Insufficient server readiness

		\~chinese
		��?����?���롣

		\~japanese
		��?��?��������
		\~
		*/
		ErrorType_ServerNotReady,

		/**
		\~korean
		���� ������ listen�� ������ �� �����ϴ�. TCP �Ǵ� UDP ������ �̹� ������� ��Ʈ���� Ȯ���Ͻʽÿ�.

		\~english
		You cannot start listen of the server socket. Please check whether either the TCP or UDP socket is a port already being used. 

		\~chinese
		����?���ʫsocket��listen�����?UDP��???TCP���UDP socketӮϢ������������?�����������?process��socket?�ᡣ

		\~japanese
		��?��?�����ëȪ�listen����㷪��몳�Ȫ��Ǫ��ު���TCP�ު���UDP�����ëȪ�?��������Ǫ����?�ȪʪΪ������㪷�ƪ���������

		*/
		ErrorType_ServerPortListenFailure,

		/**
		\~korean
		�̹� ��ü�� �����մϴ�.

		\~english 
		Already an object exists.

		\~chinese
		?������

		\~japanese
		?����?������ު���
		\~
		*/
		ErrorType_AlreadyExists,

		/**
		\~korean
		������ �źεǾ����ϴ�.
		- <a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >������ ������ �����ϱ�</a> ��ɿ���, DB cache server�� ������ ���� ����� ���� �ʰڴٴ� ������ �Ǿ� ������ �߻��� �� �ֽ��ϴ�.
		- ������ ��Ÿ�̻��� OS���� �����ڱ����� ���� CNetUtil::EnableTcpOffload( bool enable ) �Լ��� ȣ��Ǹ� �߻��� �� �ֽ��ϴ�.

		\~english
		Access denied.
		- At <a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> function, it could occur if a function that DB cache server does not use exclusive access function has been set.
		- At OS over window vista, It could occur when CNetUtil::EnableTcpOffload( bool enable ) function is called without administration authority.

		\~chinese
		��������?��
		- �<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??������?��</a>%����߾������DB cache server��?������������������������?��??���??��
		- �window��vista �߾��OS�飬?��η��??������ CNetUtil::EnableTcpOffload ( bool enable )��?��?��ʦ��??���??��

		\~japanese
		���Ϊ���������ު�����
		- <a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> Ѧ����, DB cache server��ު?�������Ѧ�������Ī��ʪ������Ҫ���ƪ����?�檹��ʦ����������ު���
		- Window Vista�߾��OS��η���?�ڪʪ��� CNetUtil::EnableTcpOffload( bool enable ) ??�������󪵪���?�檹��ʦ����������ު���

		\~
		*/
		ErrorType_PermissionDenied,

		/**
		\~korean
		�߸��� session Guid�Դϴ�.

		\~english 
		This is a wrong session Guid

		\~chinese
		??��session Guid��

		\~japanese
		���ުê�Session Guid�Ǫ���
		\~
		*/
		ErrorType_BadSessionGuid,

		/**
		\~korean
		�߸��� credential�Դϴ�.

		\~english
		This is a wrong credential.

		\~chinese
		??��credential��

		\~japanese
		���ުê�Credential�Ǫ���
		\~
		*/
		ErrorType_InvalidCredential,

		/**
		\~korean
		�߸��� hero name�Դϴ�.

		\~english 
		This is a wrong hero name.

		\~chinese
		??��hero name��

		\~japanese
		���ުê�Hero name�Ǫ���
		\~
		*/
		ErrorType_InvalidHeroName,

		/**
		\~korean
		�ε� ������ unlock �� lock �� �� ������ �߻��ߴ�

		\~english 
		After the loading is locked after being unlocked, a twist occurred. 

		\~chinese
		ʥ??��unlock�����lock ��?����󢡣

		\~japanese
		��?�ǫ���Φ�窱�����ë����˫�ë������ͪ��쪬?�檷�ު�����
		\~
		*/
		ErrorType_LoadDataPreceded,

		/**
		\~korean
		��� �Ķ���� AdjustedGamerIDNotFilled�� ä������ �ʾҽ��ϴ�.

		\~english 
		The output parameter AdjustedGamerIDNotFilled has not been filled. 

		\~chinese
		?��??AdjustedGamerIDNotFilled?����?����

		\~japanese
		�����ѫ��?��?��AdjustedGamerIDNotFilled��?������ƪ��ު���
		\~
		*/
		ErrorType_AdjustedGamerIDNotFilled,

		/**
		\~korean
		�÷��̾� ĳ���Ͱ� �������� �ʽ��ϴ�.

		\~english 
		The player character does not exist. 

		\~chinese
		��ʫ���������

		\~japanese
		�׫�?��?����髯��?������ު���
		\~
		*/
		ErrorType_NoHero,

		/**
		\~korean
		���� �׽�Ʈ ����

		\~english
		Unit test failed. 

		\~chinese
		?�??��?��

		\~japanese
		��˫ëȫƫ�������
		\~
		*/
		ErrorType_UnitTestFailed,

		/**
		\~korean
		peer-to-peer UDP ����� �������ϴ�.

		\~english 
		Peer-to-peer UDP communication is blocked. 

		\~chinese
		peer-to-peer UDP �������ݡ�

		\~japanese
		peer-to-peer UDP���᪬���ު�ު�����
		\~
		*/
		ErrorType_P2PUdpFailed,

		/**
		\~korean
		P2P reliable UDP�� �����߽��ϴ�.

		\~english 
		P2P reliable UDP failed. 

		\~chinese
		P2P reliable UDP��?��

		\~japanese
		P2P reliable UDP���������ު�����
		\~
		*/
		ErrorType_ReliableUdpFailed,

		/**
		\~korean
		Ŭ���̾�Ʈ-���� UDP ����� �������ϴ�.

		\~english 
		Client-server UDP communication is blocked. 

		\~chinese
		��ʫ-��?����UDP�������ݡ�

		\~japanese
		���髤����ȫ�?��?UDP���᪬���ު�ު�����
		\~
		*/
		ErrorType_ServerUdpFailed,

		/**
		\~korean
		�� �̻� ���� �Ҽӵ� P2P �׷��� �����ϴ�.

		\~english 
		There is no longer a P2P group that belongs together.

		\~chinese
		�?�������?��P2P?��

		\~japanese
		�����߾��?���?���쪿P2P����?�תϪ���ު���
		\~
		*/
		ErrorType_NoP2PGroupRelation,

		/**
		\~korean
		����� ���� �Լ�(RMI ���� ��ƾ Ȥ�� �̺�Ʈ �ڵ鷯)���� exception�� throw�Ǿ����ϴ�.

		\~english
		An exception is thrown in the user defined function (an RMI receiving routine or an event handler).

		\~chinese
		?��?��?��?��RMI ��������������handler��exception ��throw��

		\~japanese
		��?��?����??(RMI�����?����ު��ϫ��٫�ȫϫ�ɫ�?)��exception��throw����ު�����
		\~
		*/
		ErrorType_ExceptionFromUserFunction,

		/**
		\~korean
		������� ��û�� ���� �����Դϴ�.

		\~english 
		This is a failure due to a user request.

		\~chinese
		��?�?��������?��

		\~japanese
		��?��?�����˪�������Ǫ���
		\~
		*/
		ErrorType_UserRequested,

		/**
		\~korean
		�߸��� ��Ŷ �����Դϴ�. ����� ȣ��Ʈ�� ��ŷ�Ǿ��ų� ������ �� �ֽ��ϴ�.

		\~english 
		This is a wrong packet type. Either the correspondent host is hacked or it is a bug.

		\~chinese
		??��?�������ҡ�ʦ����?۰���������������ש�ס�

		\~japanese
		���ުê��ѫ��ë����ҪǪ���������Ϋ۫��Ȫ��ϫë��󫰪��쪿�����Ы��Ǫ���ʦ����������ު���
		\~
		*/
		ErrorType_InvalidPacketFormat,

		/**
		\~korean
		�ʹ� ū ũ���� �޽�¡�� �õ��Ǿ����ϴ�. ��������ο� �����Ͻʽÿ�. �ʿ�� <a target="_blank" href="http://guide.nettention.com/cpp_ko#message_length" >��� �޽����� ũ�� ����</a>  �� �����Ͻʽÿ�.

		\~english 
		A messaging with too big size has been attempted. Please contact the technical support team. If necessary, refer to \ref message_length

		\~chinese
		??������?����messaging��?�?��?��ݻ�����???��<a target="_blank" href="http://guide.nettention.com/cpp_zh#message_length" >��������������</a>%��

		\~japanese
		���ު�˪��ު����������Ϋ�ë�?���󫰪��˪���ު�����������ݻ�ުǪ����ꪻ������������驪˪�êơ�\ref message_length��?�Ϊ���������
		\~
		*/
		ErrorType_TooLargeMessageDetected,

		/**
		\~korean
		Unreliable �޼����� encrypt �Ҽ� �����ϴ�.

		\~english 
		You cannot encrypt an unreliable message. 

		\~chinese
		Unreliable ��������encrypt��

		\~japanese
		Unreliable��ë�?����encrypt�Ǫ��ު���
		\~
		*/
		ErrorType_CannotEncryptUnreliableMessage,

		/**
		\~korean
		�������� �ʴ� ���Դϴ�.

		\~english 
		This value does not exist

		\~chinese
		�������?��

		\~japanese
		����ʪ����Ǫ���
		\~
		*/
		ErrorType_ValueNotExist,

		/**
		\~korean
		Ÿ�Ӿƿ� �Դϴ�.

		\~english 
		This is a time-out. 

		\~chinese
		��?��

		\~japanese
		�����ૢ���ȪǪ���
		\~
		*/
		ErrorType_TimeOut,

		/**
		\~korean
		�ε�� �����͸� ã���� �����ϴ�.

		\~english 
		The loaded data cannot be located. 

		\~chinese
		����?��ʥ?��?�ߡ�

		\~japanese
		��?�ɪ��쪿��?����̸�Ī���ު���
		\~
		*/
		ErrorType_LoadedDataNotFound,

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#send_queue_heavy" >�۽ŷ� ���ٽ� ��� �߻� ���</a>. �۽� queue�� ����ġ�� Ŀ�����ϴ�.

		\~english 
		<a target="_blank" href="http://guide.nettention.com/cpp_en#send_queue_heavy" >Warning function for traffic overload</a>
		\ref send_queue_heavy. Transmission queue became too big. 

		\~chinese
		<a target="_blank" href="http://guide.nettention.com/cpp_zh#send_queue_heavy" >������?��??����ͱ������</a>��?��queue?�ޡ�

		\~japanese
		\ref send_queue_heavy . ���᫭��?�����ު�˪��ު�Φ���Ǫ��� 
		\~
		*/
		ErrorType_SendQueueIsHeavy,

		/**
		\~korean
		Heartbeat�� ��������� �ʹ� ����

		\~english 
		The heartbeat is too slow on average. 

		\~chinese
		Heartbeat ��г��ط��

		\~japanese
		Heartbeat����г�ܪ˪Ȫƪ�?���Ǫ���
		\~
		*/
		ErrorType_TooSlowHeartbeatWarning,

		/**
		\~korean
		�޽��� ������ ���� �Ͽ����ϴ�.

		\~english 
		The message compression has failed. 

		\~chinese
		����??��?��

		\~japanese
		��ë�?��?����������ު�����
		\~
		*/
		ErrorType_CompressFail,

		/**
		\~korean
		Ŭ���̾�Ʈ ������ listen Ȥ�� UDP �غ� �� �� �����ϴ�. TCP �Ǵ� UDP ������ �̹� ������� ��Ʈ����, ���μ����� ���� ���� ������ �ִ��� Ȯ���Ͻʽÿ�.

		\~english
		Unable to listen client socket or prepare UDP.
		Must check if there is limitation in number of socket per process or if either TCP or UDP socket is already in use.

		\~chinese
		����?���ʫsocket��listen�����?UDP��???TCP���UDP socketӮϢ������������?�����������?process��socket?�ᡣ

		\~japanese
		���髤����ȫ����ëȪ�listen����㷪��몳�Ȫ��Ǫ��ު���TCP�ު���UDP�����ëȪ�?��������Ǫ����?�ȪʪΪ������㪯��������
\~
		*/
		ErrorType_LocalSocketCreationFailed,

		/**
		\~korean
		Socket�� ������ �� Port Pool �� port number���� bind�� �����߽��ϴ�. ��� ������ port number�� ���Ǿ����ϴ�. Port Pool�� ������ ������� Ȯ���Ͻʽÿ�.

		\~english
		Failed binding to local port that defined in Port Pool. Please check number of values in Port Pool are sufficient.

		\~chinese
		����socket��?����Port Pool?port number��bind��?������port number���������ġ�???Port Pool��??�������¡�

		\~japanese
		Socket��������������Port Pool?��Port Number�تΫЫ���ɪ��������ު������۪��������Port Number���Ū��ު�����Port Pool��?����ªʪΪ������㪯��������
		\~
		*/
		Error_NoneAvailableInPortPool,

		/**
		\~korean
		Port pool �� ���� �� �ϳ� �̻��� �߸��Ǿ����ϴ�. ��Ʈ�� 0(���� ��Ʈ ���ε�)���� �ϰų� �ߺ����� �ʾҴ��� Ȯ���Ͻʽÿ�.

		\~english
		Range of user defined port is wrong. Set port to 0(random port binding) or check if it is overlaped.

		\~chinese
		Port pool ����?�߾��??��?��??��ӮϢ??0������ӮϢbinding�����������?��

		\~japanese
		Port pool?�����Ϊ�������߾�����ުêƪ��ު�����?�Ȫ�0(�����?�ȫЫ���ǫ���)�˪��몫���ܪ���ƪ��ʪ��������㪯��������
		\~
		*/
		ErrorType_InvalidPortPool,

		/**
		\~korean
		��ȿ���� ���� HostID ���Դϴ�.

		\~english
		Invalid HostID.

		\~chinese
		������HostID��

		\~japanese
		��?�ǪϪʪ�HostID���Ǫ���
		\~
		*/
		ErrorType_InvalidHostID, // CODEREV-FORCERELAY: enum ErrorType�� ������ ���ϼ̱���. �̷��� ��� TypeToString_Kor, TypeToString_Eng,TypeToString_Chn���� ������ ���ؾ� �մϴ�. C#,AS,Java���������� ���������Դϴ�.

		/**
		\~korean
		����ڰ� ��ȭ�ϴ� �޽��� ó�� �ӵ����� ���������� ���̴� �޽����� �ӵ��� �� �����ϴ�.
		����ġ�� �ʹ� ���� �޽����� �۽��Ϸ��� �ߴ���, Ȥ�� ������� �޽��� ���� �Լ��� ����ġ�� ������ �۵��ϰ� �ִ��� Ȯ���Ͻʽÿ�.

		\~english
		The speed of stacking messages are higher than the speed of processing them.
		Check that you are sending too many messages, or your message processing routines are running too slowly.

		\~chinese
		�������?��������?��??��������
		???�?����?�������������?������?��?ط��

		\~japanese
		��?��?����������ë�?��?���������?ݻ�ܪ��ݪ���ë�?������������ê��ܪ��Ǫ���
		���ު�˪���Φ�����ë�?�������᪷�誦�Ȫ��ƪ��ʪ������ު��ϫ�?��?�Ϋ�ë�?������??�����ު�˪�?�����Ѫ��ƪϪ��ʪ��������㪷�ƪ���������
		
		\~
		*/
		ErrorType_MessageOverload,


		/** Accessing database failed. For example, query statement execution failed. You may see the details from comment variable.
		*/
		ErrorType_DatabaseAccessFailed,

		/**
		\~korean �޸𸮰� �����մϴ�.

		\~english Out of memory.

		\~chinese ?������.

		\~japanese ����?�����ު���
		\~
		*/
		ErrorType_OutOfMemory,

		/** �������� ������ �������� ���� ���� ����� �����Ǿ�����, �̰� ������ �����߽��ϴ�. */
		ErrorType_AutoConnectionRecoveryFailed,
	};

	/**
	\~korean
	ProudNet ȣ��Ʈ �ĺ���

	\~english 
	ProudNet host identifier 

	\~chinese
	ProudNet ���??��

	\~japanese
	ProudNet�۫�����ܬ�
	\~
	*/
	enum HostID
	{
		/**
		\~korean
		����

		\~english
		None

		\~chinese
		��

		\~japanese
		�ʪ�
		\~
		*/
		HostID_None = 0,

		/**
		\~korean
		����

		\~english
		Server

		\~chinese
		��?��

		\~japanese
		��?��?
		\~
		*/
		HostID_Server = 1,

		/**
		\~korean
		(������)

		\~english
		(Do not use it)

		\~chinese
		��������ģ�

		\~japanese
		(�������)
		\~
		*/
		HostID_Last = 2
	};

	typedef uint16_t RmiID;

	enum _RmiID
	{
		RmiID_None = 0,
		RmiID_Last = 65535, // marmalade���� RMI ID�� word�� ���� �����ϱ� ����.
	};

	/** \~korean ��� ������ �߻��ϴ� �α��� ���� Ÿ���Դϴ�.
	\~english It is a category type of the log occurred within the module.
	\~chinese �ټ???����Log��??
	\~japanese �⫸��?��?��?�檹����Ϋ��ƫ���?�����תǪ���
	\~ */
	enum LogCategory
	{
		/** \~korean �⺻ �ý���
		\~english Basic System
		\~chinese ��?ͧ?
		\~japanese ���⫷���ƫ�
		\~ */
		LogCategory_System,
		/** \~korean TCP ��� ����
		\~english Relevant to TCP communication
		\~chinese ��? TCP ����
		\~japanese TCP����?֧
		\~ */
		LogCategory_Tcp,
		/** \~korean UDP ��� ����
		\~english Relevant to UDP communication
		\~chinese ��? UDP ����
		\~japanese UDP����?֧
		\~ */
		LogCategory_Udp,
		/** \~korean P2P ��� ����
		\~english Relevant to P2P communication
		\~chinese ��? P2P ����
		\~japanese P2P����?֧
		\~ */
		LogCategory_P2P
	};

	/**
	\~korean
	��ŷ�� ����

	\~english
	Type of hacking

	\~chinese
	������??��

	\~japanese
	�ϫë�����׾
	\~
	*/
	enum HackType
	{
		/**
		\~korean
		��ŷ �ƴ�

		\~english
		No hacking

		\~chinese
		�������ԡ�

		\~japanese
		�ϫë��󫰪ǪϪʪ�
		\~
		*/
		HackType_None,

		/**
		\~korean
		���ǵ���

		\~english
		Speek hack

		\~chinese
		����hack��

		\~japanese
		����?����
		\~
		*/
		HackType_SpeedHack,

		/**
		\~korean
		��Ŷ ����

		\~english
		Handle packet

		\~chinese
		?�������¡�

		\~japanese
		�ѫ��ë�����
		\~
		*/
		HackType_PacketRig,
	};

	/**
	\~korean
	Ÿ ȣ��Ʈ���� ���� ����

	\~english
	Connection status with other hosts

	\~chinese
	?���������?��??��

	\~japanese
	��Ϋ۫��ȪȪ���??��
	\~
	*/
	enum ConnectionState
	{
		/**
		\~korean
		������ ������ ����

		\~english
		Disconnected condition

		\~chinese
		?����?��??��

		\~japanese
		��?��﷪쪿?��
		\~
		*/
		ConnectionState_Disconnected,

		/**
		\~korean
		���� �õ��� ������ ���� ����� �� �� ���� ����

		\~english
		Tried connecting but result is unknown

		\~chinese
		?�???�ȣ�ӣ�����Գ?����??��

		\~japanese
		��?���˪��ު��������ު�̿������ʪ�?��
		\~
		*/
		ConnectionState_Connecting,

		/**
		\~korean
		���� ������ ������ ����

		\~english
		Succeed to connect

		\~chinese
		?��?��������??��

		\~japanese
		��?Φ���������?��
		\~
		*/
		ConnectionState_Connected,

		/**
		\~korean
		���� ���� ������ �������� ����

		\~english
		Disconnecting is in progress

		\~chinese
		�?��?�����?����??��

		\~japanese
		��?���Φ�窱�������?��
		\~
		*/
		ConnectionState_Disconnecting,
	};

	PROUD_API const PNTCHAR* ToString(LogCategory logCategory);
	PROUD_API const PNTCHAR* ToString(ConnectionState val);

	/**
	\~korean
	TCP fallback�� �ǵ������� ������ ���� ���

	\~english
	How to intentially use TCP fallback

	\~chinese
	ͺ��?��TCP fallback?��۰����

	\~japanese
	TCP Fallback����?�ܪ������������۰��
	\~
	*/
	enum FallbackMethod // ������ ���� ������ enum ���� ������ ��
	{
		/**
		\~korean
		Fallback�� ����. �� ���� �� peer���� UDP ����� ��� �����.

		\~english
		No Fallback. In other words, UDP communication to both server and peer are in use.

		\~chinese
		���Fallback��?������ݻ����?����?peer��UDP���ᡣ

		\~japanese
		Fallback�򪷪ʪ���?������?��?�����Peer�Ȫ�UDP�����������Ī��ު���
		\~
		*/
		FallbackMethod_None,
		/**
		\~korean
		�������� UDP ����� �����ϵ� Ÿ Peer����� UDP ��Ÿ��� ���ܵ� ������ ó���Ѵ�. �Ͻ��� ��Ʈ���� ���п� ������ ��Ȳ�� �����Ѵ�. ���� ������ ����.

		\~english
		Regards that UDP with server is sustained but UDP with other peers to be disconnected. Reproduce a circumstance similar to a temporary port mapping failure. This is the lowest option with weakest impact.

		\~chinese
		?�?��?����UDP���ᣬ?��?��?����peer��UDP������?���?��?��ӮϢ�����?��?������?��˭�����

		\~japanese
		��?��?�Ȫ�UDP������򥪹�몬�����Peer�����Ȫ�UDP����Ϊߪ��?���쪿��Ϊ�?�⪷�ު��������ܪ˫�?�ȫޫëԫ�������׾�Ī���?�Ϫ���ު��ު�������?������Ǫ���
		\~
		*/
		FallbackMethod_PeersUdpToTcp,
		/**
		\~korean
		�������� UDP ����� ���ܵ� ������ ó���Ѵ�. �Ͻ��� ��Ʈ���� ���п� ������ ��Ȳ�� �����Ѵ�. �ƿ﷯ Peer����� UDP ��ŵ� ���ܵȴ�. �߰� ������.

		\~english
		 Regards that UDP with server is disconnected. Reproduce a circumstance similar to a temporary port mapping failure. On top of that, it also disconnects UDP with peers. Intermediate impact.


		\~chinese
		?��?��?����peer��UDP������?���?��?��ӮϢ�����?��?������?��?peer��UDP���������?��˭��������

		\~japanese
		��?��?�Ȫ�UDP������?���쪿��Ϊ�?�⪷�ު��������ܪ˫�?�ȫޫëԫ�������׾�Ī���?�Ϫ���ު��ު������ʪߪˡ�Peer�����Ȫ�UDP������?����ު�������?���Ǫ���
		\~
		*/
		FallbackMethod_ServerUdpToTcp,
		/**
		\~korean
		Ŭ���̾�Ʈ�� UDP ������ �ƿ� �ݾƹ�����. �������� UDP ������ ���ϰ� �Ѵ�. ���� ������ ����.
		- Proud.CNetServer.SetDefaultFallbackMethod ������ ����� �� ����.

		\~english
		 All UDP sockets of client will be shut down. UDP restoration will never be possible. Strongest impact.
		- Unable to use in Proud.CNetServer.SetDefaultFallbackMethod

		\~chinese
		����??��ʫ��UDPsocket����?��������UDP��?��˭�����ԡ�

		\~japanese
		���髤����Ȫ�UDP�����ëȪ��ͪ��ު�������ܪ�UDP��?���Ǫ��ʪ����ު�������?�����Ԫ��Ǫ���
		- Proud.CNetServer.SetDefaultFallbackMethod �Ǫ����ĪǪ��ު���
		\~
		*/
		FallbackMethod_CloseUdpSocket,
	};

	/**
	\~korean
	Ŭ���̾�Ʈ�� ���� P2P ����� ���� Ȧ��Ī�� �����ϴ� ����

	\~english
	Conditions to start hole-punching for direct P2P communication among clients

	\~chinese
	?����ʫ��??�����P2P����������?�졣

	\~japanese
	���髤������������P2P����Ϊ���Ϋ�?��ѫ���󫰪���㷪���?��
	\~
	*/
	enum DirectP2PStartCondition
	{
		/**
		\~korean
		�� �ʿ��� ��Ȳ�� �ƴ� �̻� Ȧ��Ī�� ���� �ʴ´�. �����ϸ� �̰��� ���� ���� ����.

		\~english
		Unless really needed, it is recommended not to do hole-punching. Using this is strongly recommended.

		\~chinese
		�����������?��?��?�����ס�������??��

		\~japanese
		������驪�?�ϪǪϪʪ��߾����?��ѫ���󫰪Ϫ��ު��󡣪ʪ��ʪ顢������Ūê�۰���ު��Ǫ���
		\~
		*/
		DirectP2PStartCondition_Jit,
		/**
		\~korean
		CNetServer.CreateP2PGroup �̳� CNetServer.JoinP2PGroup � ���� Ŭ���̾�Ʈ�� P2P ����� ���Ǵ� ������ ������
		Ȧ��Ī ������ �����Ѵ�. ���� ��� <a target="_blank" href="http://guide.nettention.com/cpp_ko#super_peer" >Super Peer(�����Ǿ� Ȥ�� ȣ��Ʈ) �߽��� P2P ��Ʈ��ŷ</a>  ���� ���� �Ǿ ���� �÷��� ���� ���� �ٲ�� �Ѵٸ� �̰���
		�ʿ��� ���� ���� ���̴�.

		\~english
		This forcefully begins hole-punching at the moment when P2P communication among clients is allowed by CNetServer.CreateP2PGroup or CNetServer.JoinP2PGroup or others.
		For an example, if there is a need to change super peer at <a target="_blank" href="http://guide.nettention.com/cpp_en#super_peer" >P2P Networking for Super Peer (Super Peer or host)</a> during game play, this may be needed.

		\~chinese
		�� CNetServer.CreateP2PGroup%��� CNetServer.JoinP2PGroup ����ʫ��?P2P������?����?�����?�����?������<a target="_blank" href="http://guide.nettention.com/cpp_zh#super_peer" >Super Peer(�����) ������P2P����</a>%����??�������super peer��??ʦ�����??��

		\~japanese
		CNetServer.CreateP2PGroup�Ȫ�CNetServer.JoinP2PGroup�ʪɪ˪�êƫ��髤��������P2P���᪬��黪�����������?���?��ѫ����Φ�����㷪��ު����Ǫ��С�\ref super_peer�ǫ�?��?��?����?��׫쫤Բ����Ϫ�?���ʪ���Ъʪ�ʪ��Ȫ����顢���쪬��驪˪ʪ몫�⪷��ު���

		\~
		*/
		DirectP2PStartCondition_Always,
		DirectP2PStartCondition_LAST,
	};
	/**  @} */

	/**
	\~korean
	����� �Ǽ��� ���� ������ ProudNet�� �����ִ� ���

	\~english
	The way Proudnet shows error caused by user

	\~chinese
	ProudNet ?�����?����?������??��۰����

	\~japanese
	��?��?���ު��˪�뫨��?��ProudNet�����ƪ���۰��
	\~
	*/
	enum ErrorReaction
	{
		/**
		\~korean
		��ȭ ���ڸ� �����ش�. ���� ���������� ��������� �������� ���忡���� Ǯ��ũ���� ��� ����¡���� ���� �� �־ �Ƿ� ���� ã�Ⱑ �� ����� �� �ִ�.

		\~english
		Shows chat box. This may be useful during development process but it can also be very troublesome since the chat box can be seen to end users as full screen freezing.

		\~chinese
		?��???��?�???����ު����驣�ӣ?����?��?���?��ʦ��??��?freezing��????ʦ�������ʥ��?��

		\~japanese
		���������ܫë��������ƪ��ު�����?Φ��Ǫ���驪Ǫ���������ɫ�?��?��ء�ުǪϫ�?�뫹����?������ꡢFreezing��̸���몳�Ȫ����ꡢ�����ê����������Ϊ���?�˪ʪ몳�Ȫ⪢��ު���

		\~
		*/
		ErrorReaction_MessageBox,
		/**
		\~korean
		ũ���ø� �����Ѵ�. �������� ���忡���� ũ���÷� ��Ÿ���Ƿ� ������� ��� ������ �� ���� ã�� �� �ִ�.
		��, <a target="_blank" href="http://guide.nettention.com/cpp_ko#minidump_main" >MiniDump (���������ý���)</a>  ���� ȥ���ؾ� �� ��ġ�� �ִ�.

		\~english
		Causes a crash. From end users' point of view, this is definitely a crash so it can be rather easier to find what the problem is when released.
		But, it is more effective when used along with <a target="_blank" href="http://guide.nettention.com/cpp_en#minidump_main" >Error Dump System</a>.

		\~chinese
		??crash�����?��??��?crash��ʦ������?��release����ס�
		ӣ����� <a target="_blank" href="http://guide.nettention.com/cpp_zh#minidump_main" >????ͧ?</a>

		\~japanese
		����ë�����?���ު�������ɫ�?��?��ء�ުǪϫ���ë�����ު�ު��Ϊǡ����?�����쪿���ꡢ�����ê������䪹�����⪷��ު���ӣ����\ref minidump�ʪɪ����Ī��ƪ���?��������ު���
\~ */
		ErrorReaction_AccessViolation,
		/**
		\~korean
		����� ���â������ �������ϴ�. ũ���ó� ��ȭ���ڸ� ����ٸ��� ��Ȳ�� �ƴ϶�� �̿ɼ��� ����Ͻʽÿ�.

		\~english
		It shows only debugger output screen. If you can not pop up crash or message box, please use this option.

		\~chinese
		��?���???��?������?��crash���???����?��?��?�����??��

		\~japanese
		�ǫЫë�?����?���ǪΪ����ƪ���ު�������ë������������ܫë��������ƪ���?�ϪǪϪʪ���Ъ��Ϋ��׫������Ūêƪ���������
		\~
		*/
		ErrorReaction_DebugOutput,
		/**
		\~korean
		����� �극��ũ�� �̴ϴ�. �ش�ɼ��� ����� ��忡���� ����Ͻʽÿ�.
		\~english
		Put on the debugger brake. Please use this option only in the debugging mode. 

		\~japanese
		�ǫЫë�?�֫�?���򪫪��ު�����?���׫����ϫǫЫë���?�ɪǪΪ��Ūêƪ���������
		\~
		 */
		ErrorReaction_DebugBreak
	};

	/**
	\~korean
	���� ����

	\~english
	Operation type

	\~chinese
	?ߩ??��

	\~japanese
	��ߩ��׾
	\~
	*/
	enum ValueOperType
	{
		/**
		\~korean
		����

		\~english
		Addition

		\~chinese
		ʥ����

		\~japanese
		�몷ߩ
		\~
		*/
		ValueOperType_Plus,
		/**
		\~korean
		����

		\~english
		Subtraction

		\~chinese
		?��

		\~japanese
		�ڪ�ߩ
		\~
		*/
		ValueOperType_Minus,
		/**
		\~korean
		����

		\~english
		Multiplication

		\~chinese
		�����

		\~japanese
		�Ъ�ߩ
		\~
		*/
		ValueOperType_Multiply,
		/**
		\~korean
		������

		\~english
		Division

		\~chinese
		�����

		\~japanese
		�ܪ�ߩ
		\~
		*/
		ValueOperType_Division
	};

	/**
	\~korean
	�� ����

	\~english
	Comparison type

	\~chinese
	��???��

	\~japanese
	������׾
	\~
	*/
	enum ValueCompareType
	{
		/**
		\~korean
		ũ�ų� ������

		\~english
		Greater or equal

		\~chinese
		�������͡�

		\~japanese
		�ު��������������
		\~
		*/
		ValueCompareType_GreaterEqual,

		/**
		\~korean
		ũ��

		\~english
		Greater

		\~chinese
		����?��

		\~japanese
		�ު������
		\~
		*/
		ValueCompareType_Greater,

		/**
		\~korean
		�۰ų� ������

		\~english
		Less or equal

		\~chinese
		������͡�

		\~japanese
		ᳪ��������������
		\~
		*/
		ValueCompareType_LessEqual,

		/**
		\~korean
		������

		\~english
		Less

		\~chinese
		���?��

		\~japanese
		ᳪ������
		\~
		*/
		ValueCompareType_Less,

		/**
		\~korean
		������

		\~english
		Equal

		\~chinese
		���͡�

		\~japanese
		���������
		\~
		*/
		ValueCompareType_Equal,

		/**
		\~korean
		�ٸ���

		\~english
		Not equal

		\~chinese
		������?��

		\~japanese
		�ު���
		\~
		*/
		ValueCompareType_NotEqual
	};

	/**
	\~korean
	��ȣȭ ����

	\~english
	Encryption Level

	\~chinese
	ʥ�������

	\~japanese
	��?�����
	\~
	*/
	enum EncryptLevel
	{
		/**
		\~korean
		AES ��ȣȭ ���� ��

		\~english
		AES encryption level Low

		\~chinese
		AES ʥ������

		\~japanese
		AES��?����ޡ���
		\~
		*/
		EncryptLevel_Low = 128,
		/**
		\~korean
		AES ��ȣȭ ���� ��

		\~english
		AES encryption level Middle

		\~chinese
		AES ʥ������顣

		\~japanese
		AES��?����ޡ���
		\~
		*/
		EncryptLevel_Middle = 192,
		/**
		\~korean
		AES ��ȣȭ ���� ��

		\~english
		AES encryption level High

		\~chinese
		AES ʥ�����߾��

		\~japanese
		AES��?����ޡ�߾
		\~
		*/
		EncryptLevel_High = 256,
	};

	/**
	\~korean
	Fast ��ȣȭ ����

	\~english
	Fast encryption level

	\~chinese
	Fast ʥ�������

	\~japanese
	Fast��?�����
	\~
	*/
	enum FastEncryptLevel
	{
		/**
		\~korean
		Fast ��ȣȭ ���� ��

		\~english
		Fast encryption level Low

		\~chinese
		Fastʥ������

		\~japanese
		Fast��?����ޡ���
		\~
		*/
		FastEncryptLevel_Low = 512,
		/**
		\~korean
		Fast ��ȣȭ ���� ��

		\~english
		Fast encryption level Middle

		\~chinese
		Fastʥ������顣

		\~japanese
		Fast��?����ޡ���
		\~
		*/
		FastEncryptLevel_Middle = 1024,
		/**
		\~korean
		Fast ��ȣȭ ���� ��

		\~english
		Fast encryption level High

		\~chinese
		Fastʥ�����߾��

		\~japanese
		Fast��?����ޡ�߾
		\~
		*/
		FastEncryptLevel_High = 2048,
	};

	enum HostType
	{
		HostType_Server,
		HostType_Peer,
		HostType_All,
	};

	/**
	\~korean
	HostID ���� ��� �ɼ��Դϴ�.

	\~english
	It is an option for HostID reuse function.

	\~chinese
	HostID�����������??��

	\~japanese
	HostID�����Ѧ�����׫����Ǫ���

	\~
	*/
	enum HostIDGenerationPolicy
	{
		/**
		\~korean
		HostID ���� ����� ����մϴ�.
		-�⺻���Դϴ�.

		\~english
		It uses a HostID reuse function.
		-It is a default value.

		\~chinese
		HostID ���������������
		-?����?��.

		\~japanese
		HostID�����Ѧ�����Ū��ު���
		?�ǫի�������Ǫ�

		\~
		*/
		HostIDGenerationPolicy_Recycle = 1,

		/**
		\~korean
		HostID ���� ����� ������� �ʽ��ϴ�.

		\~english
		It does not use a HostID reuse function.

		\~chinese
		HostID �����������������.

		\~japanese
		HostID�����Ѧ�����Ū��ު���

		\~
		*/
		HostIDGenerationPolicy_NoRecycle,
	};

	/**
	\~korean
	������ ���Դϴ�.

	\~english
	Thread model.

	\~chinese
	?��ټ����

	\~japanese
	����ëɫ�ǫ�Ǫ���

	\~
	*/
	enum ThreadModel
	{
		/**
		\~korean
		���� ������ ���Դϴ�. ����ڰ� ���� ������ ������ �۵����� �ǹ��մϴ�.
		���� �����尡 �����Ƿ� ����ڴ� Proud::CNetClient::FrameMove�� �ּ� �� 1/60�ʸ��� ���������� ȣ���� �־�� �մϴ�.

		\~english
		Single thread model. Runs code on threads created by user.
		As there is no networker thread, You must call Proud::CNetClient::FrameMove for every 1/60 seconds.

		\~chinese
		??��ټ����?�����??����?��򮡣
		���?��?ء��?���?������ 1/60 ��?̰�??�� Proud::CNetClient::FrameMove��

		\~japanese
		���󫰫뫹��ëɫ�ǫ�Ǫ�����?��?��������������ë�߾�����ª��몳�Ȫ���ګ���ު���
		ܬ�˫���ëɪ��ʪ����ᡢ��?��?��Proud :: CNetClient :: FrameMove�������1/60�����Ȫ�??�ܪ���������驪�����ު���

		\~
		*/
		ThreadModel_SingleThreaded = 1,

		/**
		\~korean
		��Ƽ ������ ���Դϴ�. Thread pool�� ���� ����� �� ������ �۵����� �ǹ��մϴ�.

		\~english
		Multi thread model. Runs code on the separated thread pool.

		\~chinese
		��?��ټ����???��?���??����߾��

		\~japanese
		�ޫ������ëɫ�ǫ�Ǫ��� Thread pool��ܬ?��������������߾�����ª��몳�Ȫ���ګ���ު���
		\~
		*/
		ThreadModel_MultiThreaded,

		/**
		\~korean
		���� ������ ���Դϴ�. ����ڰ� ���� Proud.CThreadPool ������ �۵����� �ǹ��մϴ�.

		\~english
		Use-external-thread model. Runs code on Proud.CThreadPool instance create by user.

		\~chinese
		��ݻ?��ټ����?�����??���� Proud.CThreadPool��

		\~japanese
		��?����ëɫ�ǫ�Ǫ�����?��?����������Proud.CThreadPool߾�����ª��몳�Ȫ���ګ���ު���

		\~
		*/
		ThreadModel_UseExternalThreadPool,
	};
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
