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
CNetServer.Start �� ���� ������ ������ �� ������ �ʱ� �������Դϴ�.
���� �ʱ� �������� ���� ���ɿ� ������ �ݴϴ�. �ڼ��� ���� <a target="_blank" href="http://guide.nettention.com/cpp_ko#performance_tips" >ProudNet ������ ���� ��</a> �� �����Ͻʽÿ�.

\~english
This is an initial setup value when the server initializes.
The initial values of the server directly affect server functions. Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#performance_tips" >ProudNet Tips for performance enhancement</a> for more details.

\~chinese
��?��� CNetServer.Start%?���?�������?��?��
��?�������?��??��?������?���?��????��<a target="_blank" href="http://guide.nettention.com/cpp_zh#performance_tips" >ProudNet ����</a>%��

\~japanese
CNetServer.Start�˪�êƫ�?��?����㷪���������?��?����Ѣ�������Ǫ���
��?��?��Ѣ�������ϫ�?��?��������ª�?���ު����٪����ϡ�\ref performance_tips��?�Ϊ���������

\~
*/
	class CStartServerParameterBase
	{
	public:
		/**
		\~korean
		������ �ּ��Դϴ�.
		- �ʱⰪ�� �� ���ڿ��Դϴ�.
		- ��������� �� ���ڿ��� ����������, L4 ����ġ�� ���ͳ� ������(NAT) �ڿ��� ������ �۵��� ���
		Ŭ���̾�Ʈ�� �ν��� ������ ȣ��Ʈ �̸��̳� IP address�� �־���� �մϴ�.
		- IP �ּ�(111.111.111.111 ��) Ȥ�� �ν� ������ �̸�(aaa.mydomain.com)�� ���� �� �ֽ��ϴ�. ������ ��Ʈ ��ȣ�� ���� ���մϴ�.

		\~english
		This is a server address.
		- The initial vlaue is an empty string.
		- It is usual to designate an empty value for this but it is necessary to input either the host name of the server or IP address
		when the server is working behind an L4 switch or an Internet router(NAT) for the clients to recognize.
		- An IP address (e.g. 111.111.111.111) or a recognizable name (www.mydomain.com) can be used, but not the port number

		\~chinese
		��?���򣡣
		- ���?�����ݬ����
		- ������������ݬ����ӣ����?���L4 switch���??����NAT������??��?���?��client��??����?�����٣���IP address��
		- ʦ�?��IP��(111.111.111.111��)���ʦ�??��٣�(aaa.mydomain.com)��ӣ������?��ӮϢ??��

		\~japanese
		��?��?�Ϋ��ɫ쫹�Ǫ���
		- ��Ѣ�����������֪�Ǫ���
		- ���ȡ��������֪����Ҫ��ު�����L4�����ë��Ȫ�����?�ͫëȫ�?��?(NAT)������ǫ�?��?�����Ѫ������ꡢ���髤����Ȫ����۪��뫵?��?�Ϋ۫���٣�Ȫ�IP���ɫ쫹���������驪�����ު���
		- IP���ɫ쫹(111.111.111.111�ʪ�)�ު�������ʦ����٣��(aaa.mydomain.com)������몳�Ȫ��Ǫ��ު�������������?����?������몳�Ȫ��Ǫ��ު���

		\~
		*/
		String m_serverAddrAtClient;

		/**
		\~korean
		������ ������ ������ ���ε��� �ּ��Դϴ�.
		- �ʱⰪ�� �� ���ڿ��Դϴ�.
		- ��������� �� ���ڿ��� ���������� ������ ��Ʈ��ũ �������̽�(NIC)�� 2�� �̻� ������ ���,
		�׸��� �װ͵� �� �ϳ����� CNetClient ���� ���� ���� ��û�� ���� �� �ִ� ��� ���⿡ �ش�˴ϴ�.
		NIC�� ������ IP �Ǵ� ȣ��Ʈ �̸��� �����ؾ� �մϴ�. ȣ��Ʈ�� �ִ� NIC �ּ� ����Ʈ�� �������� Proud.GetLocalIPAddresses �� �� �� �ֽ��ϴ�.
		- ȣ��Ʈ �̸��� ������ ��� Ŭ���̾�Ʈ�� ������ �����ϱ� ���� �ּҷ� localhost�� �Է��� ��� ���� ���и� �� �� �ֽ��ϴ�. �̷��� ���
		Ŭ���̾�Ʈ�� ������ �����ϱ� ���� ���� ȣ��Ʈ�� �ּҸ� ��������� �Է��ؾ� �մϴ�.
		- <a target="_blank" href="http://guide.nettention.com/cpp_ko#multiple_nic_at_server" >������ �������� LANī��(NIC)�� ������ ����� ����</a>

		\~english
		This is the address that the listening socket of the server to be bound.
		- The initial value is an empty value.
		- It is usual to designate an empty value for this but it is used in the case that the server has more than
		2 Network Interfces (NIC) and when only one of them is able to receive a connection request from CNetClient.
		Either an IP address or a host name that is registered by the NIC must be designated.
		It is possible to use Proud.GetLocalIPAddresses to acquire the NIC address list in the host.
		- When a hostname is designated, itis possible to cause a connection failure when a localhost is used for the address to connect at the client.
		It is necessary to input correct address of the server host in order to connect to client server.
		- <a target="_blank" href="http://guide.nettention.com/cpp_en#multiple_nic_at_server" >Setup when there are several LAN cards (NIC) are attached.</a>

		\~chinese
		��?����listing socket���bound���򣡣
		- ���?�����ݬ����
		- �������?���ݬ����ӣ����?��?��2?�߾??ͣ����NIC����?���������������������ʦ����? CNetClient%??��?���?��?��?��?�졣
		�����NIC�����IP������٣?����?��������NIC��list��?ʦ����� Proud.GetLocalIPAddresses%��
		- ������٣��?����client ?��?����?���?��������localhost��?ʦ��??����?��??��client?��?����?��٥���?����?��������򣡣
		- <a target="_blank" href="http://guide.nettention.com/cpp_zh#multiple_nic_at_server" >���?����?����?LAN?(NIC)?��?��</a>

		\~japanese
		��?��?�Ϋ꫹�˫󫰫����ëȪ��Ы���ǫ��󫰪���뫢�ɫ쫹�Ǫ���
		- ��Ѣ�����������֪�Ǫ���
		- ���ȡ��������֪����Ҫ��ު�������?��?���ͫëȫ�?������?�ի�?��(NIC)��2���߾�êƪ������ꡢ�����ƪ����Ϊ�����ĪΪߪ�CNetClient����?����?���������������ꡢ�������?���ު���
		NIC����Ҫ��쪿IP�ު��ϫ۫���٣����Ҫ�����驪�����ު����۫��Ȫ˪���NIC���ɫ쫹�꫹�Ȫ���몿��˪ϡ�Proud.GetLocalIPAddresses���Ū����Ȫ��Ǫ��ު��� 
		- �۫���٣����Ҫ������ꡢ���髤����Ȫϫ�?��?����?���몿��Ϋ��ɫ쫹�ǡ�localhost�������������ꡢ֧̿������ʦ����������ު������Ϊ誦�����ꡢ���髤����Ȫϫ�?��?����?���몿��ˡ���?��?�۫��ȪΫ��ɫ쫹��٥���ܪ��������ʪ���Ъʪ�ު���
		- \ref multiple_nic_at_server

		\~
		*/
		String m_localNicAddr;
		/**
		\~korean
		������ Ŭ���̾�Ʈ�� ���ߴ� �������� �����Դϴ�.
		- ���� �������� ������ ���� �ٸ��� ������ Ŭ���̾�Ʈ��
		������ ����(CNetClient.Connect)�Ϸ��� �õ��ϸ�
		Ŭ���̾�Ʈ���� ErrorType_ProtocolVersionMismatch �� Ʈ���ŵ˴ϴ�.

		\~english
		This is a protocaol version that syncs the servers and the clients.
		- When a client with different protocol version to ther server attempt to connect(CNetClient.Connect), the client will trigger ErrorType_ProtocolVersionMismatch.

		\~chinese
		��?����client?����??���⡣
		- ����??�����������������client???�ȣ�CNetClient.Connect����?����?��client?����ErrorType_ProtocolVersionMismatch��

		\~japanese
		��?��?�ȫ��髤����������請��׫�ȫ�?���?�����Ǫ���
		- �⪷���׫�ȫ�?���?����󪬪������ުê���Ҫ��쪿���髤����Ȫ���?��?����?(CNetClient.Connect)���誦�Ȫ����顢���髤����Ȫ�ErrorType_ProtocolVersionMismatch���ȫꫬ?����ު���

		\~
		*/
		Guid m_protocolVersion;

		/**
		\~korean
		����� ���� ��ƾ�� ����Ǵ� �����尡 �� ����� ���� ������ Ǯ���� ����� ���, �� ������ Ǯ�� ������ �����Դϴ�.
		- �⺻���� 0�Դϴ�. 0�� �����ϸ� CPU ������ �����˴ϴ�.
		- m_externalUserWorkerThreadPool�� ���� �Ǿ��� ��� �� ���� ���õ˴ϴ�.

		\~english
		The number of treads in thread pool. It must be at least bigger than 1.
		- The initial value is 0. If 0 is designated, then it is to be disignated as the number of CPUs.
		- When you set m_externalUserWorkerThreadPool then this value is ignored.

		\~chinese
		��?��?routine?����?����ټ?��?��?������?��?������??������?��??��
		- ��??��0�����0��?��?���?CPU??��
		- m_externalUserWorkerThreadPool��?����?���??����?��

		\~japanese
		��?��?������?����?������뫹��ëɪ����Ϋ⫸��?���??����ëɫ�?���?����������ꡢ���Ϋ���ëɫ�?��Ϋ���ë�?�Ǫ���
		- ��������0�Ǫ���0����Ҫ���ȡ�CPU?����Ҫ���ު���
		- m_externalUserWorkerThreadPool�����Ҫ��쪿���ꡢ�����������ʪ���ު���

		\~
		*/
		int m_threadCount;

		/**
		\~korean
		ProudNet�� ���������� I/O ó���� ����ϴ� �����尡 �ֽ��ϴ�. �̰��� ������ �����մϴ�.
		- �⺻���� 0�Դϴ�. 0�� �����ϸ� CPU ������ �����˴ϴ�.
		- ���� ProudNet�� �۵��� ������ 1���� �ӽſ��� CPU �ھ� ������ŭ �۵��ϴ� ��� ��ǻ� ������ ���� ������ ����̳� �ٸ������ϴ�. �̷��� ��쿡�� �� ���� 1�� �����ؼ� 1���� CPU �� ����ϵ��� �������ָ� ProudNet�� ó�� ������ ���˴ϴ�. �� �ܿ��� �� ���� �׳� �δ� ���� �����ϴ�.
		- m_externalNetWorkerThreadPool�� ���� �Ǿ��� ��� �� ���� ���õ˴ϴ�.

		\~english
		ProudNet has a thread that deals with internal I/O. This value designates how many for this.
		- If it is 0 then it is regarded as the number of CPU cores.
		- In case when the server where Proudnet to be working works as many as the number of CPU cores within a machine, it is reasonable to say that the server is one thread base.
		If this is the case, it is ideal to set this value as 1 to use 1 CPU in order to increase the CPU's overall efficiency.
		- If this is not the case, then it is ideal to leave the value as it is.

		\~chinese
		ProudNet ?���?��I/O?����?�����??��
		- ��??��0�����0��?��?���?CPU??��
		- ����??ProudNet����?�����?����??��?��CPU core?����?����??߾��?��??��?����??�����ҡ�??��?����??��?1��?������������?CPU��?��?���ProudNet��?�������������?�?��?����
		- m_externalNetWorkerThreadPool��?����?���??����?��

		\~japanese
		ProudNet��?ݻ�ܪ�I/O?���??���뫹��ëɪ�����ު���������?����Ҫ��ު���
		- ��������0�Ǫ���0����Ҫ����CPU?����Ҫ���ު���
		- �⪷��ProudNet�����Ѫ��뫵?��?��1���Ϋޫ����CPU����?�������Ѫ������ꡢ��?߾��?��?��?�髹��ë���������ު�����ު��󡣪��Ϊ誦������˪ϡ���������1���êƪ�����1����CPU�Ϊ����Ī���誦�����Ҫ����ProudNet��?����������߾����ު���������˪Ϫ������Ϫ��Ϊު��Ǫ���۰���ު��Ǫ���
		- m_externalNetWorkerThreadPool�����Ҫ���ƪ������ꡢ�����������ʪ���ު���

		\~
		*/
		int m_netWorkerThreadCount;
		/**
		\~korean
		ProudNet���� ��ȣȭ�� �޽�¡�� �ְ� ���� ���� ��ȣŰ�� �����Դϴ�. (����: <a target="_blank" href="http://guide.nettention.com/cpp_ko#key_length" >��ȣȭ Ű ����: ��ȣȭ ���ذ� ���� ���̿��� �����ϱ�</a>)
		- AES����� ��������� ��ü ��ȣȭ�� Ű�� �����մϴ�.
		- Proud::EncryptLevel ���� �����Ͽ� �����Ͽ��� �ϸ� �ʱⰪ�� EncryptLevel_Low �Դϴ�.

		\~english
		This is the length of the coded key when ProudNet communicates with encrypted messeges. (Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#key_length" >The length of encryption: mediate between the level of encryption and performance.</a>)
		- It generates encrypted key that based on AES.
		- You need to set it up with refer to Proud::EncryptLevel value and defualt value is EncryptLevel_Low.

		\~chinese
		�ProudNet��?��ʥ����messaging��?������??������?�ţ�<a target="_blank" href="http://guide.nettention.com/cpp_zh#key_length" >ʥ��key?��: �ʥ�����?������??��??</a>��
		- ����AES��?��ProudNet����ʥ����key��
		- �?�� Proud::EncryptLevel%?�?�ǣ����?��EncryptLevel_Low��

		\~japanese
		ProudNet����?�����쪿��ë�?���󫰪������ꪹ��������?��?�������Ǫ���(?�ţ�\ref key_length)
		- AES�����Ϋ׫髦�ɫͫëȪ��?��?����?���������ު���
		- Proud::EncryptLevel ����?�Ϊ������Ҫ��ʪ���Ъʪ�ު��󪷡���Ѣ����EncryptLevel_Low�Ǫ���

		\~
		*/
		EncryptLevel m_encryptedMessageKeyLength;

		/**
		\~korean
		ProudNet���� ��ȣȭ�� �޽�¡�� �ְ� ���� ���� ��ȣŰ�� �����Դϴ�. (����: <a target="_blank" href="http://guide.nettention.com/cpp_ko#key_length" >��ȣȭ Ű ����: ��ȣȭ ���ذ� ���� ���̿��� �����ϱ�</a>)
		- Fast����� ��������� ��ü ��ȣȭ�� Ű�� �����մϴ�.
		- ��Ʈ���� ��ȣȭ ����̱� ������ Ű���� �� �Ϻ�ȣȭ�� �ӵ����� ������ ���� �ʽ��ϴ�.
		- Proud::FastEncryptLevel ���� �����Ͽ� �����Ͽ��� �ϸ� �ʱⰪ�� FastEncryptLevel_Low �Դϴ�.

		\~english
		This is the length of the coded key when ProudNet communicates with encrypted messeges. (Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#key_length" >The length of encryption: mediate between the level of encryption and performance.</a>)
		- It generates encrypted key that based on Fast
		- It does not affect speed of encryption even key value is long because it use streaming encryption type.
		- You need to set it up with refer to Proud::FastEncryptLevel value and defualt value is FastEncryptLevel_Low.

		\~chinese
		�ProudNet��?��ʥ����messaging��?������??������?�ţ�<a target="_blank" href="http://guide.nettention.com/cpp_zh#key_length" >ʥ��key?��: �ʥ�����?������??��??</a>��
		- ����Fast��?��ProudNet����ʥ����key��
		- ��?����׵ʥ��۰�ң�key ??���??ʥ�ˡ���������?���?��
		- �?�� Proud::FastEncryptLevel%?�?�ǣ����?��FastEncryptLevel_Low��

		\~japanese
		ProudNet����?�����쪿��ë�?���󫰪������ꪹ��������?��?�������Ǫ���(?�ţ�\ref key_length)
		- Fast�����Ϋ׫髦�ɫͫëȪ��?��?����?���������ު���
		- ���ȫ�?�߫���?��۰�ҪʪΪǡ���?���������ƪ���?��?���������˪���ª�?���ު���
		- Proud::FastEncryptLevel ����?�Ϊ������Ҫ��ʪ���Ъʪ�ު��󪷡���Ѣ����FastEncryptLevel_Low�Ǫ���

		\~
		*/
		FastEncryptLevel m_fastEncryptedMessageKeyLength;

		/**
		\~korean
		P2P RMI �޼����� encrypt �� �Ѱų� ���±���Դϴ�. �⺻���� false�Դϴ�.
		- ����, ����ڰ� false�� �����ϸ� P2P ��ȣȭ�� RMI�� �Ұ����մϴ�. ��ſ� ���������� ���˴ϴ�.
		- ����ڰ� false�� ���¿��� encrypt �޼�¡�� �Ұ�쿡�� OnError�� �ݹ�ǰ�, P2P �޼����� ���ȣȭ RMI�� ���۵˴ϴ�.

		\~english
		This is used to turn on/off the encryption function of P2P RMI message. The default value is false.
		- If the user sets this as false then it is impossible to use encrypted P2P RMI. Instead, the server performance is improved.
		- If the user uses encrypted messaging with its value being false, then OnError will be called back and the P2P message will be sent as not-encrypted RMI.

		\~chinese
		??��??P2P RMI������encrypt����������??��false��
		- ������??��?false��?P2Pʥ����RMI����ʦ���ܡ�ӣ����?������?��ԡ�
		- ��?�false��??��?��encrypt messaging��?��?��? OnError��P2P%����??����ުʥ��RMI��

		\~japanese
		P2P RMI��ë�?����encrypt�򫪫�?���ժ���Ѧ���Ǫ�����������false�Ǫ���
		- �⪷����?��?��false�����Ҫ����P2P��?�����쪿RMI����ʦ���Ǫ��������۪��˫�?��?��������߾����ު���
		- ��?��?��false��?����encrypt��ë�?���󫰪򪹪�����˪ϡ�OnError����?��Ыë�����ơ�P2P��ë�?����ު��?��RMI��?�ꪵ��ު���

		\~
		*/
		bool m_enableP2PEncryptedMessaging;

		/**
		\~korean
		������ <a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P �׷�</a> �� ����� ���Խ�ų �� �ִ����� �����ϴ� �������Դϴ�.
		- �⺻���� false�Դϴ�.
		- �ڼ��� ������ <a target="_blank" href="http://guide.nettention.com/cpp_ko#server_as_p2pgroup_member" >P2P �׷� ����μ� ������ ���Խ�Ű��</a>�� �����Ͻʽÿ�.

		\~english
		This is a value to decide whether the server can be included as the member of <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a> or not.
		- The default value is false.
		- Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#server_as_p2pgroup_member" >How to include a server as a peer-to- peer group member</a> for more details.

		\~chinese
		?������������?������?<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%����?��?��?��
		- ��??��false��
		- ???�??��<a target="_blank" href="http://guide.nettention.com/cpp_zh#server_as_p2pgroup_member" >�P2P��?��?������?��</a>%��

		\~japanese
		��?��?��\ref p2p_group�Ϋ���?���ߪު��몳�Ȫ��Ǫ��몫��̽�Ҫ����������Ǫ��� 
		- ��������false�Ǫ���
		- �٪����ϡ�\ref server_as_p2pgroup_member��?�Ϊ���������

		\~
		*/
		bool m_allowServerAsP2PGroupMember;


		/**
		\~korean
		Timer callback �ֱ� �Դϴ�. <a target="_blank" href="http://guide.nettention.com/cpp_ko#server_timer_callback" >�������� Ÿ�̸� ���� RMI �̺�Ʈ ó���ϱ�</a> ����Դϴ�.
		�̰��� �����ϸ� milisec������ �ѹ��� INetServerEvent.OnTick �� ȣ��˴ϴ�.
		- 0�̸� �ݹ����� �ʽ��ϴ�.
		- �⺻���� 0�Դϴ�.

		\~english
		This sets the period of timer callback. A function described in <a target="_blank" href="http://guide.nettention.com/cpp_en#server_timer_callback" >Managing Timer loop RMI Event from server</a>.
		When this is activated, INetServerEvent.OnTimerCallback will be called at every period set by millisecond unit.
		- Ther is no callback when this is set as 0.
		- The default value is 0

		\~chinese
		Timer callback�Ѣ��<a target="_blank" href="http://guide.nettention.com/cpp_zh#server_timer_callback" >���?��?��Timer Loop��RMI��Event</a>������
		?��??��?�� INetServerEvent.OnTick%?�milisec?����У��󭡣
		- 0����?��?��?��
		- ��??��0��

		\~japanese
		Timer callback �Ѣ�Ǫ���\ref server_timer_callback Ѧ���Ǫ�����������Ҫ���ȡ�milisec?�Ȫ���������INetServerEvent.OnTick�������󪵪�ު���
		- 0�Ǫ���Ы�?��Ыë����ު���
		- ��������0�Ǫ���

		\~
		*/
		uint32_t m_timerCallbackIntervalMs;

		/**
		\~korean
		Timer callback�� ���� �� ���� user worker thread���� ȣ��� �� �ִ����� ���մϴ�.
		�⺻���� 1�Դϴ�. ��� user worker thread�� ����ϰ� �ʹٸ� INT_MAX�� �Է��ص� �˴ϴ�.

		\~english 
		It determines whether timer callback can be called in how many user worker threads simultaneously.
		The default value is 1. If you want to use all user worker threads, you may enter INT_MAX. 

		\~chinese
		?��Timer callback��?���??user worker thread����У��
		��??��1�����������user worker thread��?�ʦ�?��INT_MAX��

		\~japanese
		Timer callback������������user worker thread�������󪵪�몫��̽��ު���
		��������1�Ǫ�����ƪ�user worker thread���Ū���������ϡ�INT_MAX���������ƪ��ު��Ǫ���

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
		��?��?������Ѣ��1�����ī�?��Ыë������������Ȫ����Ū����?��?��?���Ǫ���
		Proud.INetServerEvent.OnTick�������󪵪������������Ȫ�������ު���\ref server_timer_callback Ѧ���Ǫ���
		- ��������NULL�Ǫ���

		\~
		*/
		void* m_timerCallbackContext;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#delayed_send" >TCP ���� �۽� ��ɰ� Nagle �˰���</a> ����� �Ѱų� ���ϴ�. TCP�� �ַ� ����ϸ鼭 �����Ͻÿ� �ΰ��ϸ�, ��ŷ��� ���� ���� �� ���� false�� �����ϱ⵵ �մϴ�.
		- �⺻���� true�Դϴ�.
		- true�� ��� TCP Nagle �˰����� ������ ProudNet ��ü�� ���� �۽� ����� ���ϴ�.
		- false�� ��� TCP Nagle �˰����� ������ ProudNet ��ü�� ���� �۽� ����� �մϴ�.
		- TCP Nagle �˰����� �ü���� ���� �ٸ��ϴ�. Windows�� ȣ��Ʈ���� WAN������ ���� 0.7�ʰ� ����Ǿ����ϴ�.
		- ProudNet ��ü�� ���� �۽� ����� ���� 0.01���Դϴ�.

		\~english
		Turn on or off <a target="_blank" href="http://guide.nettention.com/cpp_en#delayed_send" >TCP delayed transmitting function and Nagle algorism</a> function. It normally use TCP and sensitive with latency. If application does not require high traffic, sometimes set this value to false.
		- Default value is true
		- If it is true, it will trun on TCP Nagle algorism and turn off delayed sending function.
		- If it is false, it will turn off TCP Nagle algorism and turn on delayed sending function.
		- TCP Nagle algorism is different depends on OS. Longest time that reported is 0.7 second in WAN, Host between Windows.
		- ProudNet's delayed sending function is 0.01 second for longest.

		\~chinese
		?���?<a target="_blank" href="http://guide.nettention.com/cpp_zh#delayed_send" >TCP ��?����������Nagleߩ��</a>%������������TCP��?latency??������������?������?���?false��
		- ��??��true��
		- true��???TCP Nagleߩ����??ProudNet��������??��������
		- false��???TCP Nagleߩ����??ProudNet��������??��������
		- TCP Nagleߩ������???ͧ����ҡ�Windows ?������飬�WAN?ͱ��??0.7����
		- ProudNet��������??����������?��0.01����

		\~japanese
		\ref delayed_send Ѧ���򫪫�?���ժ��ު���TCP�����Ū��ʪ����?�ƫ�?������ǡ���������ᴪʪ����׫�Ϫ�������flase����Ҫ����ꪷ�ު���
		- ��������true�Ǫ���
		- true�����ꡢTCP Nagle���뫴�꫺�બ����˪ʪê�ProudNet�?��?������Ѧ�������ժ˪ʪ�ު���
		- false�����ꡢTCP Nagle���뫴�꫺�બ���ժ˪ʪê�ProudNet�?��?������Ѧ��������˪ʪ�ު���
		- TCP Nagle ���뫴�꫺���OS�˪�ê��ު��ު���Windows��Ϋ۫��Ȫ�WAN�Ǫ�����0.7������ͱ����ƪ��ު���
		- ProudNet �?��?������Ѧ��������0.01���Ǫ���

		\~
		*/
		bool m_enableNagleAlgorithm;

		/**
		\~korean
		P2P Group ������ ����� ����� ������ HostID�� ���۰��Դϴ�. ������ ũ��� m_reservedHostIDCount�� �����Ͻʽÿ�.
		- Ŭ���̾�Ʈ���� HostID�� �� ���� ������ ���ؼ� �����˴ϴ�.
		- CreateP2PGroup()�� �� ���� ������ �ִ� ���� �־ ����ڰ� ���ϴ� HostID���� ���� P2P group�� ������ �� �ֽ��ϴ�.

		\~english 
		This is the starting value of HostID within the reserved range to be used in generation of a P2P group. The size of the range should be set with m_reservedHostIDCount. 
		- The HostID of the clients is generated by avoiding the reserved range. 
		- By inserting the value within this reserved range in CreateP2PGroup(), you can create a P2P group with the HostID value wanted by the user. 

		\~chinese
		�����P2P Group ?�������?����??�� HostID ���?��??��?���?��? m_reservedHostIDCount��
		- ��?������?Ӯ HostID?��????����?������
		- �CreateP2PGroup()��?���?����??��?ʦ�����?����?����� HostID?�� P2P group��

		\~japanese
		P2P Group ���������Ī�����峪��쪿��?��HostID�Ϋ���?�����Ǫ�����?���ު����� m_reservedHostIDCount�����Ҫ��ƪ���������
		- ��?���쪿���髤����Ȫ�����HostID�Ϫ��������?����������������ު���
		- CreateP2PGroup()�˪��������?�˪�����������ƫ�?�����Ъ�HostID�����ê�P2P group�������Ǫ��ު���
		\~
		*/
		HostID m_reservedHostIDFirstValue;

		/**
		\~korean
		P2P Group ������ ����� ����� ������ HostID�� �����Դϴ�. ���۰��� m_reservedHostIDFirstValue�� �����Ͻʽÿ�.

		\~english
		It is the number of HostID in the reserved range that are going to be used for P2P group creation. Start value must be set as m_reservedHostIDFirstValue.

		\~chinese
		�����P2P Group ?�������?����??�� HostID ??��??���??��?m_reservedHostIDFirstValue��

		\~japanese
		P2P Group���������Ī�����峪��쪿��?��HostID��?�Ǫ�������?������m_reservedHostIDFirstValue�����Ҫ��ƪ���������

		\~
		*/
		int m_reservedHostIDCount;

		/**
		\~korean
		����� ���� �޼��带 ����ڰ� �������� ������ thread pool���� �����ϰ� �մϴ�. �ڼ��� ���� <a target="_blank" href="http://guide.nettention.com/cpp_ko#thread_pool_sharing" >�������� ���� ȣ��Ʈ ����� ���� Thread Pool�� �����ϱ�</a> �� �����Ͻʽÿ�.
		- �⺻���� null�Դϴ�.
		- �� ���� �������� ��� m_threadCount�� ���õ˴ϴ�.

		\~english
		Running user defined method in thread pool that created manually by user. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#thread_pool_sharing" >Share Thread Pool that has same host module in a server.</a> for more detail.
		- Default value is null
		- When you set this value, m_threadCount is ignored.

		\~chinese
		���?�?������thread pool��?����?��?۰����????��<a target="_blank" href="http://guide.nettention.com/cpp_zh#thread_pool_sharing" >���?��������??���ټ?������Thread Pool</a>%��
		- ��??��null��
		- ?���?��??��?m_threadCount��

		\~japanese
		��?��?�����᫽�ëɪ��?��?���������������thread pool��?������誦�˪��ު����٪����ϡ�\ref thread_pool_sharing��?�Ϊ���������
		- ��������null�Ǫ���
		- �����������Ҫ������ꡢm_threadCount�����ʪ���ު���

		\~
		*/
		CThreadPool* m_externalUserWorkerThreadPool;

		/**
		\~korean
		network I/O ���� ��ƾ�� ����ڰ� �������� ������ thread pool���� �����ϰ� �մϴ�. �ڼ��� ���� <a target="_blank" href="http://guide.nettention.com/cpp_ko#thread_pool_sharing" >�������� ���� ȣ��Ʈ ����� ���� Thread Pool�� �����ϱ�</a> �� �����Ͻʽÿ�.
		- �⺻���� null�Դϴ�.
		- �� ���� �������� ��� m_networkerThreadCount�� ���õ˴ϴ�. m_externalNetWorkerThreadPool�� ����ڰ� �������� ������ thread pool��

		\~english
		Running network I/O related routine in thread pool that created manually by user. Please refer to  <a target="_blank" href="http://guide.nettention.com/cpp_en#thread_pool_sharing" >Share Thread Pool that has same host module in a server.</a> for more detail.
		- Default value is null
		- When you set this value, m_networkerThreadCount is ignored.

		\~chinese
		���?�?������thread pool��?��network I/O��?routine��????��<a target="_blank" href="http://guide.nettention.com/cpp_zh#thread_pool_sharing" >���?��������??���ټ?������Thread Pool</a>%��
		- ��??��null��
		- ?���?��??��?m_networkerThreadCount��

		\~japanese
		network I/O ?֧��?������?��?����Ѫ���������thread pool��?������誦�˪��ު����٪����ϡ�\ref thread_pool_sharing��?�Ϊ���������
		- ��������null�Ǫ���
		- �����������Ҫ������ꡢm_networkerThreadCount�����ʪ���ު���m_externalNetWorkerThreadPool����?��?����Ѫ���������thread pool�Ǫ���

		\~
		*/
		CThreadPool* m_externalNetWorkerThreadPool;

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
		- ��ȣȭ ����� �Ѱų� ���ϴ�.
		- �Ϲ������δ� ��ȣȭ ����� �Ѵ� ���� �����ϴ�. ������ Ŭ���̾�Ʈ�� ������ ������ �� ���� key ��ȯ�� ���� ������ ���� �ð��� �� ���� �ҿ��ϰ� �˴ϴ�.
		- ��ȣȭ ����� ���� �ʿ� ���� ���� ������� �� ����� ���ô� ���� �����ϴ�.
		- �⺻���� true�Դϴ�.

		\~english
		- Turn on or off the encryption feature. 
		- Generally it��s better to turn on the encryption feature. However, when the client connects to the server, the calculation time of the server is spent more to exchange encryption keys. 
		- If this is a game server without any need for an encryption feature, it��s better to turn off this feature. 
		- The default value is true. 

		\~chinese
		- ??��??ʥ������
		- ��???ʥ��������ӣ���?Ӯ?����?����?������??��?���������?����ߩ??��
		- ������?��?�����������ʥ��ʦ�??��������
		- ��???��true����

		\~japanese
		- ��?��Ѧ���򫪫�?���ժ��ު���
		- �����ܪ˪���?��Ѧ����������۰���ު��Ǫ��������������髤����Ȫ���?��?����?���������������ƫ���?�����Ϊ���˫�?��?����ߩ������ê�������驪Ȫ��ު���
		- ��?��Ѧ�����絛驪�ʪ���?�૵?��?�ʪ���Ѧ����Ἢ���۰���ު��Ǫ���
		- ��������true�Ǫ���

		\~
		*/
		bool m_enableEncryptedMessaging;
	protected:
		CStartServerParameterBase();

	};

	/**  @} */

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif

}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
