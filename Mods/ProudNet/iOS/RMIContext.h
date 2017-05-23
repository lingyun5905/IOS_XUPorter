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

#include "Enums.h"
#include "EncryptEnum.h"
#include "BasicTypes.h"
#include "CompressEnum.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup net_group
	*  @{
	*/

	class CReceivedMessage;
	class CMessage;

	/**
	\~korean
	RMI ȣ�⿡ ���õ� ��Ʈ��ŷ �Ӽ� ��

	\~english
	Networkign nature related to RMI calling and others

	\~chinese
	?��RMI������???������

	\~japanese
	RMI�����󪷪�?����ͫëȫ�?����?���ʪ�
	\~
	*/
	// ����: ������ ProudClr�� ���� �ɺ��� �����ؾ� �Ѵ�.
	class RmiContext
	{
	public:
		/**
		\~korean
		relay�� �޽����ΰ�?
		- RMI stub���� ä������ ���Դϴ�.
		- ���� Ŭ���̾�Ʈ�� ���� RMI�� ������ ���� ������(�����н�)�Ǿ��ų�( <a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_comm_overview" >Ŭ���̾�Ʈ�� P2P ����� ����</a> ����),
		������ ���� RMI�� �ٸ� Ŭ���̾�Ʈ�� ���� route�Ǿ����� ( <a target="_blank" href="http://guide.nettention.com/cpp_ko#s2c_routed_multicast" >�������� �ټ��� Ŭ���̾�Ʈ���� routed multicast�� �ϱ�</a> ����)
		�� ���� true�� �� ä RMI �Լ��� �ݹ�˴ϴ�.

		\~english
		Is this a relaysed message?
		- The value filled at RMI stub
		- If RMI from client is relayed via server(Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_comm_overview" >Overview of peer-to-peer communication between clients</a>) or RMI sent by server is routed by other client(Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#s2c_routed_multicast" >Routed multicasting several clients from server</a>),
  		then RMI function wil be called back while this value keeps to be true.

		\~chinese
		Relay ������?��
		- �RMI stub?����?��
		- ����client?����RMI��?��?��relay��bypass������?��<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_comm_overview" >��?Ӯ��?��P2P����?�</a>%�������?��?����RMI��?����client��route��?��?��<a target="_blank" href="http://guide.nettention.com/cpp_zh#s2c_routed_multicast" >���?����?��?��?Ӯ?��routed multicast</a>%�����??�true??����?RMI��?��

		\~japanese
		Relay���쪿��ë�?���ʪΪ���
		- RMI stub��?����������Ǫ���
		- �⪷�����髤����Ȫ���ê�RMI����?��?���ת����?(�Ы��ѫ�)����ƪ��몫(\ref p2p_comm_overview ?��)����?��?����ê�RMI����Ϋ��髤����Ȫ��ת�route���쪿��(\ref s2c_routed_multicast ?��)��������true�˪ʪê��ު�RMI??����?��Ыë�����ު��� 

		\~
		*/
		bool m_relayed;

		/**
		\~korean
		RMI�� �۽��� peer�� HostID �̴�.
		- RMI stub���� ä������ ���̴�.

		\~english
		HostID of peer that transmitted RMI
		- The value filled at RMI stub

		\~chinese
		?��RMI��peer��Host ID��
		- �RMI stub?����?��

		\~japanese
		RMI�����᪷��Peer��HostID�Ǫ���
		- RMI stub��?����������Ǫ���

		\~
		*/
		HostID m_sentFrom;

		/**
		\~korean
		unreliable send�� ���,
		routed multicast�� �� �� �ִ�. �̶� ����� ����ϴ����� ���⼭ �����Ѵ�.
		- ����ڰ� �����ؾ� �Ѵ�.

		\~english
		If unreliable send, can perform routed multicast. This is where to decide how many of them are allowed.
		- User must define.

		\~chinese
		unreliable send ����?��ʦ�?��routed multicast��??�?���������?�??��
		- ���?��ҡ�

		\~japanese
		Unreliable send�����ꡢrouted multicast���Ǫ��ު����������������ު���黪��몫�򪳪�����Ҫ��ު���
		- ��?��?����Ҫ��ު���

		\~
		*/
		int m_unreliableS2CRoutedMulticastMaxCount;

		/**
		\~korean
		unreliable �޽�¡�� ��쿡,
		routed multicast�� �� �� �ִ�. �̶� �� �̻��� �� ������ �Ǿ ��ſ����� ����ϴ����� ���⼭ �����Ѵ�.
		- ����ڰ� �����ؾ� �Ѵ�.

		\~english
		If unreliable messaging, can perform routed multicast. This is where to decide which rate of laggy P2P communications are allowed.
		- User must define.

		\~chinese
		������Unreliable messaging����?��ʦ�?��routed multicast��??�?���������?����߾��lag�����peer��?���ᡣ
		- ���?��ҡ�

		\~japanese
		Unreliable ��ë�?���󫰪����ꡢrouted multicast���Ǫ��ު������������������߾�Ϋ�ë������Peer�������ǪΪ���黪��몫�򪳪�����Ҫ��ު���
		- ��?��?����Ҫ��ު���

		\~
		*/
		int m_unreliableS2CRoutedMulticastMaxPingMs;

		/**
		\~korean
		���� ��Ƽĳ��Ʈ�� �� �� �ִ� �ִ� ����
		- <a target="_blank" href="http://guide.nettention.com/cpp_ko#throttling" >�۽ŷ� �ڵ� ���� ��� (Throttling)</a> ��� �� �ϳ��̴�.
		- P2P �׷��� ������� RMI �۽��� �� ���, �� ���� N���� ������ ���, P2P �׷� ����� N�� ��ŭ�� Ÿ peer���Դ�
		P2P�� ���� �����Ѵ�. (���� Ÿ peer�� ���� P2P ����� �ϰ� �ִ� ��쿡) ������ ������ peer�鿡�Դ�
		Relayed P2P�� �����Ѵ�. ���� ���� P2P ����� �ϰ� �ִ��� ���̴�. 0�� �����ϸ� direct P2P �۽� ��ü�� ������ �ǹ��Ѵ�.
		- �� ����� Ŭ���̾�Ʈ�� �뷮�� ��Ƽĳ��Ʈ�� �ϴ� ���, �׸��� Ŭ���̾�Ʈ�� ���ε� �ӵ��� �Ѱ谡 ū ���(���� ���
		���ε� �ӵ��� ���� ADSL ȸ��) �����ϴ�. �ֳ��ϸ� ProudNet������ relayed P2P�� ��ε�ĳ��Ʈ �������� Ŭ���̾�Ʈ��
		1���� relay�� �޽������� �������� ������, ������ �װ��� ���� Ŭ���̾�Ʈ�鿡�� �����ִ� ������ �ϱ� �����̴�.
		- �⺻��: ������.
		- Ŭ���̾�Ʈ���� ȣ���ϴ� RMI�� �Ķ���Ϳ� ���� �� ���� ����ڰ� ������ �� �ִ�. ���������� �� ���� ������ �ʴ´�.

		\~english
		The maximum number of direct multicast can be performed
		- One of <a target="_blank" href="http://guide.nettention.com/cpp_en#throttling" >Traffic auto-control function (Throttling)</a>
		- When RMI transmitting to P2P group and the value is set as N, for N many of other peers of P2P group members, it will be trasmitted as direct P2P. (Of course when other peers communicate with direct P2P)
		  However, it will be transmitted to the other peers as relayed P2P even if they are performing direct P2P communications. If 0 is set then it means there is no P2P transmission at all.
		- This function is useful when client performs a large amount of multicasts and the speed limit of client upload (e.g. ADSL line with slower upload speed).
                  During broadcasting relayed P2P in Proudnet, client sends only 1 of message to be relayed then server performs the role that sends it to many other clients.
		- Default: infinite
		- User can designate this value to RMI parameter before it is called by client. At server, this value is not used.

		\~chinese
		������?��multi cast������??��
		- <a target="_blank" href="http://guide.nettention.com/cpp_zh#throttling" >�???����?����(Throttling)</a>%���������顣
		- �P2P???��?��RMI��?�������?���?N?��?P2P?��?����?��N?������peer��P2P����?�꣨?�ԣ��������peer����?��P2P��������?������ӣ��?�����peer����relayed P2P?�ꡣ?������?��P2P������������0��?��ګ���?��direct P2P����
		- ������client?������multi cast��?����?��client��߾?������߾������?��������߾?����ط��ADSL���أ�?����������?�ProudNet?��relayed P2P��broadcast?����client������?relay������?��?��?���?��?���?�?��??��client�����ġ�
		- ��??������𤡣
		- �client��У��RMI??������?ʦ�����?�����?�������?��

		\~japanese
		���ȫޫ�����㫹�Ȫ��Ǫ�������?
		- \ref throttling �����Ϊ�����ĪǪ���
		- P2P����?�ת�?�ڪ�RMI����򪹪����ꡢ��������N����Ҫ��쪿���ꡢP2P����?�׫���?���N�����������peer�˪�P2P������?�ꪷ�ު���(���������peer������P2P�����򪷪ƪ�������)��������?���peer�����˪�Relayed P2P��?�ꪷ�ު������Ȫ�������P2P����򪷪ƪ���Ȫ��ƪ�Ǫ���0����Ҫ����direct P2P�����?�򪷪ʪ����Ȫ���ګ���ު���
		- ����Ѧ���ϫ��髤����Ȫ�����Ϋޫ�����㫹�Ȫ򪹪����ꡢ�����ơ����髤����ȪΫ��ë׫�?����������ͣ���ު�������(�Ǫ��С����ë׫�?��������?��ADSL����)����Ǫ����ʪ��ʪ顢ProudNet�Ǫ�relayed P2P�Ϋ֫�?�ɫ��㫹��Φ��ǫ��髤����Ȫ�1����relay������ë�?���Ϊߪ�?��?����êơ���?��?�Ϫ������?�Ϋ��髤����Ȫ������ܪ򪹪몫��Ǫ��� 
		- �������������
		- ���髤����Ȫ�������RMI�Ϋѫ��?��?����˪��������?��?����Ҫ��몳�Ȫ��Ǫ��ު�����?��?�ǪϪ��������Ū��ު���

		\~
		*/
		int m_maxDirectP2PMulticastCount; // NOTE: ������ ����� ��� �� ������ ����ڰ� ���� �������� �ʴ��� �������̴�.

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#message_unique_id" >���� �޽����� �����ϱ�</a> ����� ���� �������Դϴ�.
		- �⺻���� 0�Դϴ�. 0�� ��� ����ȭ���� �ʽ��ϴ�.
		- �۽��� �޽����� �۽� ť���� ����ȭ�ϰ��� �Ѵٸ� �� ���� 0 �̿��� ���� �����Ͻʽÿ�.

		\~english
		Unique ID for <a target="_blank" href="http://guide.nettention.com/cpp_en#message_unique_id" >Transmitting the latest message only</a>.
		- Default is 0 and does not unify if 0.
		- If the mesage to be sent is to be unified at transmission queue then this value must not designate 0 but other value.

		\~chinese
		��?��<a target="_blank" href="http://guide.nettention.com/cpp_zh#message_unique_id" >��?����?����</a> ������ͳ��?��
		- ����??0.����??0?,����?������
		- ���������������������queue��?������??����??��?0�����?��

		\~japanese
		<a target="_blank" href="http://guide.nettention.com/cpp_jp#message_unique_id" >Transmitting the latest message only</a>Ѧ���Ϊ����ͳ�����Ǫ���
		- �ǫի���Ȫϣ��Ǫ����������ꡢ?��������ު���
		- ���᪹���ë�?�������᫭��?��?���������˪ϡ�������������������Ҫ��ƪ���������
		\~
		*/
		int64_t m_uniqueID;

		/**
		\~korean
		�޽��� �۽� �켱����
		- <a target="_blank" href="http://guide.nettention.com/cpp_ko#message_priority" >�޽��� �۽� �켱���� ���</a> ����.
		- ����ڰ� �����ؾ� �Ѵ�.
		- m_reliability�� reliable�� ������ ��� �� ���� ���õȴ�.

		\~english
		Message trnasmission priority
		- Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#message_priority" >Prioritizing message transmission</a>.
		- User must define.
		- If m_reliability = reliable then this value is ignored.

		\~chinese
		����?����?�?��
		- ?��<a target="_blank" href="http://guide.nettention.com/cpp_zh#message_priority" >����?����?�?��������</a>%��
		- ���?��ҡ�
		- m_reliability �����?reliable��?���??��?��

		\~japanese
		��ë�?������׫髤����ƫ�
		- \ref message_priority ?��
		- ��?��?����Ҫ��ʪ���Ъʪ�ު���
		- m_reliability��reliable����Ҫ���ƪ������ꡢ�����������ʪ���ު��� 

		\~
		*/
		mutable MessagePriority m_priority;

		/**
		\~korean
		�޽��� �۽� �޼���
		- ����ڰ� �����ؾ� �Ѵ�.

		\~english
		Message trnasmission method
		- User must define.

		\~chinese
		����?��۰����
		- ���?��ҡ�

		\~japanese
		��ë�?������᫽�ë�
		- ��?��?����Ҫ��ʪ���Ъʪ�ު���

		\~
		*/
		MessageReliability m_reliability;

		/**
		\~korean
		�� ���� false�̸� RMI �����ڰ� P2P �׷� �� �������� ��� �ڱ� �ڽſ��� ������ �޽�¡(loopback)�� ���ܽ�ŵ�ϴ�.
		�⺻���� true�Դϴ�.

		\~english
		While this value is false if there are 2 or more RMI receivers then excludes the messaging to itself(loopback).
		Default is true.

		\~chinese
		�?��false��?RMI����P2P?��???��?����??�����messaging��loopback����⡣
		��??��true��

		\~japanese
		��������false�Ǫ���С�RMI������P2P����?�תʪ���?�Ǫ������ꡢ�����������ë�?����(loopbakc)����⪵���ު���
		��������true�Ǫ���

		\~
		*/
		bool m_enableLoopback;

		/**
		\~korean
		����ڰ� ������ tag ���Դϴ�. <a target="_blank" href="http://guide.nettention.com/cpp_ko#host_tag" >�� ȣ��Ʈ�� ���� ����� ���� ������(Tag)</a> ����Դϴ�.
		- ����! : tag�� ��Ʈ�� ����ȭ�� ���� �ʴ� ���Դϴ�.

		\~english
		User defined tag value. A <a target="_blank" href="http://guide.nettention.com/cpp_en#host_tag" >User-defined data(Tag) for each host</a> function.
		- Caution!: tag is a value that cannot be network synchronized.

		\~chinese
		��?�����tag?����<a target="_blank" href="http://guide.nettention.com/cpp_zh#host_tag" >?��?�������?��??�ߣ�Tag��</a>���� ��
		- ��򣡣�tag ������?��??������?��

		\~japanese
		��?��?����Ҫ�����������Ǫ���\ref host_tagѦ���Ǫ���
		- �����!��tag�ϫͫëȫ�?����Ѣ��������ʪ����Ǫ���

		\~
		*/
		void* m_hostTag;

		// ���� �뵵
		// true�� ��� �� RMI�۽��� JIT P2P Ȧ��Ī�� Ʈ�����Ѵ�. Non-PN RMI������ false�̴�.
		bool m_enableP2PJitTrigger;

		/**
		\~korean
		�� ���� false�̸� Unreliable�� ������ �Ҷ�, ��밡 relay mode�̸�, ������ �ʽ��ϴ�.
		- �⺻���� true�Դϴ�.

		\~english
		While this value is false if opponent is relay mode then do not send it.
		- Default is true.

		\~chinese
		�?��false��?��Unreliable?����?����?۰��relay mode��?��??�ꡣ
		- ��??��true��

		\~japanese
		��������false�Ǫ����Unrelaible������Ȫ���������⢪�Relay mode�Ǫ�������ު���
		- ��������ture�Ǫ���

		\~
		*/
		bool m_allowRelaySend;

        /**
		\~korean
		���� ������ �Ӱ���� ���Դϴ�.
		�� ���� �����ϸ�, P2P�� ��� �ӵ����� �����̰� �� ��� �ӵ��� ���� ��� �����̸� ������ �� �ֽ��ϴ�.

		- ���� ��� �Ǿ ��Ŷ ���� �ð��� ������ ���� �������ϴ� �ð����� 3�� ���� ��쿡�� ���� �Ǿ�� ������
		�� �ִ� �ϴ��� ������ ���� �������ϰ� ���� �� �ֽ��ϴ�. �׷��� ��� �� ���� 1/3���� �����ϸ� �˴ϴ�.
		5�� ���� ��쿡 ���� ���� �����̸� ���� ��� 1/5�� �����ϸ� �˴ϴ�. 0�� �����ϸ� ���� �����̸� ���� �ʽ��ϴ�.
		��, "Relay p2p ping / Direct p2p ping"�� �� ������ ���� ��쿡�� ������ �����̷� �����մϴ�.
		- �߱������� P2P�� ��� �ӵ����� ������ ����ϴ� �ӵ��� �ξ� ��Ȱ�� ȯ���� �ִٰ� �˷��� �ֽ��ϴ�.
		- �⺻���� 0�Դϴ�.

		\~english
		Forced relay critical rate value.
		If you change this value, it can select relay instead of P2P communication when relay is faster than P2p communication.

		-For example, If packet sending time is 3 times slower than relay through a server, you may relay it through server even it can send to peer directly. This case set this value to 1/3.
		Also if it is 5 times slower then set 1/5. If you set 0, it does not do forced relay.
		Therefore it does forced relay when "Relay p2p ping / Direct p2p ping" is smaller than this value.
		- In China, server-client is faster than P2P.
		- Default is 0

		\~chinese
		˭�relay?ͣ����?��
		?���?��?��?relay����������P2P����������?��?��ʦ�??relay��

		- ������peer ��??����?��??����?��?��relay��??ط3����?����?����?������peer?�꣬�ʦ������?��?��relay��??���?���?1/3?ʦ����?ط5������?���˭�relay��?�����1/5?ʦ�������0��?��?˭�relay��?��"Relay p2p ping / Direct p2p ping"���?���?��?��?˭�relay��
		- ��?���??��?��������������P2P��?��������?������
		- ��??��0��

		\~japanese
		?���?��ͣ�������Ǫ���
		����������ｪ���ȡ�P2P����������������?����ê��ܪ����ꡢ���?����?���몳�Ȫ��Ǫ��ު���
		- �Ǫ��С�Peer��Ϋѫ��ë�?�����બ��?��?���ת����?����������3��?������˪ϡ�����Peer��?�ꪹ�몳�Ȫ��Ǫ���Ȫ��ƪ⫵?��?���ת����?���������ꪬ����ު������Ϊ誦�����ꡢ��������1/3����Ҫ�����ު��Ǫ���
		5��?��������ڪê�?���?�����Ъ������ꡢ1/5����Ҫ�����ު��Ǫ���0����Ҫ����?���?���Ǫ��ު���
		?����"Relay p2p ping / Direct p2p ping"�����������ᳪ�������˪ϡ�?���?��?�ꪷ�ު���
		- ��?�Ǫ�P2P�������������ꫵ?��?�����᪹���������Ϫ몫�����������Ѫ���������ƪ��ު���
		- ��������0�Ǫ���

		\~
		*/
        double m_forceRelayThresholdRatio;

        /**
		\~korean
		ProudNet ���� �޽��������� ���� �ĺ����Դϴ�.
        - �⺻ false�Դϴ�. false�̸� udp �޽��� ������ �����մϴ�.
        - Ư���� ��Ȳ�� �ƴϸ� �̰��� true�� �ٲ��� ���ʽÿ�.

		\~english
		Identifying value that message for only ProudNet or not
		- Default is false. If it is false then check number of udp messages.
		- Do not change it to true except special case.

		\~chinese
		?ProudNet?��������???��
		- ��??��false��False ��??��udp����??��
		- ���������?��������?������true��

		\~japanese
		ProudNet?�ī�ë�?���ʪΪ���?������ܬ���Ǫ���
		- ��������false�Ǫ���False�Ǫ����UDP��ë�?��?�����Ҫ��ު���
		- ��ܬ��?�ϪǪϪʪ���Ъ�������ture��?���ʪ��Ǫ���������

		\~
		*/
        bool m_INTERNAL_USE_isProudNetSpecificRmi;

		/** \~korean true�̸�, unreliable �۽ſ� ���̴� �޽����� MTU ũ��� �����ؼ� �����ϴ�.
		UDP ó���� ���� ������ CPU ��뷮�� ������ �̰��� �� ������.
		�⺻���� true �Դϴ�.

		\~english Sends messages after fragmentation.
		If true, the message used in unreliable transmission is divided and sent into MTU size. 
		Turn this off if the server has high CPU use due to UDP processing. 
		The default value is true. 

		\~chinese NOTE: Machanical translation.
		������true����������unreliable??�����������MTU���������?�ꡣ
		������UDP?������CPU�������㣬��????��
		��???true��

		\~japanese NOTE: Machanical translation.
		True�Ǫ���С�unreliable������Ū����ë�?����MTU�����������ܪ������ު���
		UDP?��˪�êƫ�?��?��CPU���������Ԫ���С�����򫪫ժ��ƪ���������
		��������true�Ǫ���

		\~
		*/
		bool m_fragmentOnNeed;


        /**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#encryption_usage" >��� �޽��� ��ȣȭ�ϱ�</a> ���� ���Ǵ� ��ȣȭ �˰��� �����Դϴ�.
		- �⺻���� EM_None �Դϴ�.

		\~english
		<a target="_blank" href="http://guide.nettention.com/cpp_en#encryption_usage" >��� �޽��� ��ȣȭ�ϱ�</a> ���� ���Ǵ� ��ȣȭ �˰��� �����Դϴ�.
		- Default EM_None .

		\~chinese
		??�<a target="_blank" href="http://guide.nettention.com/cpp_zh#encryption_usage" >ʥ����������</a>%������ʥ��ߤ?��
		- ��??��EM_None��

		\~japanese
		\ref encryption_usage���Ū�����?�����뫴�꫺����?�Ǫ��� 
		- ��������EM_None�Ǫ���

		\~
		*/
        EncryptMode m_encryptMode;

		/**
		\~korean
        �޽��� ���� ��� �Դϴ�. �� ���� CM_None �ܸ̿� ������ ��� ������ �Ͽ� �޽����� �����մϴ�.
        - �⺻���� CM_None �Դϴ�.
        - ���� �޽����� ũ�Ⱑ �ʹ� �۰ų�(�� 50����Ʈ) ������ �ص� ũ�Ⱑ �۾����� ������ �������� �ʰ� �����մϴ�.

		\~english TODO:translate needed.
		This is the message compression feature. When things other than CM_None is selected for this value, you can compress to send the message. 
		- The default value is CM_None
		- If the message to be sent is too small (approx. 50 bytes) or does not get smaller even if it��s compressed, then send it uncompressed. 

		\~chinese
		����??���������????CM_None�����?����??���?�����ӡ�
		- ��??��CM_None��
		- �?����������᳣�?50byte������??����?�ꡣ

		\~japanese
		��ë�?��?��Ѧ���Ǫ�����������CM_None������?�������ꡢ?�ꪷ�ƫ�ë�?����?�ꪷ�ު���
		- ��������CM_None�Ǫ���
		- ����ë�?���Ϋ��������Ȫƪ�ᳪ�����(�50�Ы���)��?�ꪷ�ƪ⫵������ᳪ����ʪ�ʪ����?�ꪷ�ʪ���?�ꪷ�ު���

		\~
		*/
        CompressMode m_compressMode;

		// ����: ������ ProudClr�� ���� �ɺ��� �����ؾ� �Ѵ�.
		PROUD_API RmiContext();

		// ����: ������ ProudClr�� ���� �ɺ��� �����ؾ� �Ѵ�.
		PROUD_API RmiContext( MessagePriority priority, MessageReliability reliability, int unreliableS2CRoutedMulticastMaxCount, EncryptMode encryptMode = EM_None);

		/**
		\~korean
		Reliable message�� RMI ȣ��� �̰��� �Ķ���ͷ� ������ �ȴ�.
		- ������ ���ϸ� ������ RmiContext ��ü�� �ֵ� ������ ������� ��� RMI ȣ��� �̰��� �׳� �ᵵ �ȴ�.

		\~english
		This is to be entered as parameter when calling RMI as reliable message.
		- It is ok to use separate RmiContext object if needed but usually if the case is usual then it is ok to use this calling RMI.

		\~chinese
		��Reliable message��УRMI?����???��????ʦ��
		- ��?������?��?׺ RmiContext%?�������������?����УRMI?�ʦ���������??��

		\~japanese
		Reliable message��RMI�����������������ѫ��?��?�������Ъ����Ǫ���
		- ��?��?�����Ъ���С�ܬԲ��RmiContext���֫������Ȫ��Ǫ��ƪ��ު��Ǫ��������Ȫ����ꡢRMI�������󪹪Ȫ���򪽪Ϊު��Ūêƪ��ު��Ǫ���

		\~
		*/
		PROUD_API static RmiContext ReliableSend;

		/**
		\~korean
		EM_Fast ���� ��ȣȭ �Ͽ� Reliable message �� RMI ȣ��� �̰��� �Ķ���ͷ� ������ �ȴ�.
		- ��Ÿ ������ ReliableSend �� �����ϴ�.

		\~english
		Encrypt with EM_Fast mode then put this as parameter when you call RMI with Reliable message.
		- All other details are same as ReliableSend.

		\~chinese
		�EM_Fastټ��ʥ�������Reliable message��УRMI?����???��????ʦ��
		- ����??ReliableSend���ҡ�

		\~japanese
		EM_Fast ��?�ɪ���?�����ơ�Reliable message��RMI�����������������ѫ��?��?���������ު��Ǫ���
		- ������������ReliableSend���Ҫ��Ǫ���

		\~
		*/
		PROUD_API static RmiContext FastEncryptedReliableSend;

		/**
		\~korean
		EM_Secure ���� ��ȣȭ �Ͽ� Reliable message�� RMI ȣ��� �̰��� �Ķ���ͷ� ������ �ȴ�.
		- ��Ÿ ������ ReliableSend �� �����ϴ�.

		\~english
		Encrypt with EM_Secure mode then put this as parameter when you call RMI with Reliable message.
		- All other details are same as ReliableSend.

		\~chinese
		�EM_Secureټ��ʥ�������Reliable message��УRMI?����???��????ʦ��
		- ����??ReliableSend���ҡ�

		\~japanese
		EM_Secure��?�ɪ���?������Reliable message��RMI�����������������ѫ��?��?���������ު��Ǫ���
		- ������������ReliableSend���Ҫ��Ǫ���

		\~
		*/
		PROUD_API static RmiContext SecureReliableSend;





		/**
		\~korean
		Unreliable message�� RMI ȣ��� �̰��� �Ķ���ͷ� ������ �ȴ�.
		- ������ ���ϸ� ������ RmiContext ��ü�� �ֵ� ������ ������� ��� RMI ȣ��� �̰��� �׳� �ᵵ �ȴ�.
		- HIGH priority�� �����Ǿ� �ִ�.

		���� ����
		- �Ϲ����� �¶��� ���ӿ��� ��ü ��ŷ��� ��κ��� ĳ���� �̵�, ���� ���ݰ� ���� �� ������ �޽������� �����ϸ�
		�� ���� ������ �޽������� ���� ������ �����Ѵ�. �׸��� ����� �������� �ʰ� unreliable send�� �� ��� ����
		��ð��� ���� �ذ� �ð����� �̾����� �Ѵ�. �̷��� ������ ��������� �¶��� ���� ���� �ʱ� ���������� ������ �޽�����
		��� reliable send�� ���� ����ٰ� ��Ʈ�� ��ŷ� �����ʸ� ���� ���� ��κ��� ��ŷ��� ���������� ������ ����Ǵ� �޽����鸸
		ã�Ƽ� unreliable send�� �ٲ��ִ� �͵� ���� ���� ����̶� ���� �� �ִ�.

		\~english
		This is to be entered as parameter when calling RMI as reliable message.
		- It is ok to use separate RmiContext object if needed but usually if the case is usual then it is ok to use this calling RMI.
		- Set as HIGH priority.

		Reference
		- Generally in most of online games, most of overall communications consist of a few different types of mesages such as character movement, attacking actions and so on while others have significantly low proportion.
		And there have been many cases where unreliable send was used without enough considerations then caused to spend hours of debugging time.
		Considering those experiences, it is believed to say that making everything use reliable send at the beginning then replace only those that can handle losses to unreliable can be a good way to develop an online game.

		\~chinese
		��Unreliable message��УRMI?����???��????ʦ��
		- ��?������?��?׺ RmiContext%?�������������?����УRMI?�ʦ���������??��
		- �����?HIGH priority��

		?������
		- �������??��?�飬��ݻ����������ݻ����������?��?����?��??��������������?�������������?�����?��������??������unreliable send��?����?��??���???��?��??��?�档��?��????���??��???��Ѣ?����������?������reliable send��?��???��???������profiling�������ݻ�������ᣬӣ��ʦ�??��??׵�������ӣ�??��������unreliable send�ʦ�?��?����??۰����

		\~japanese
		Unreliable message��RMI�����������������ѫ��?��?���������ު��Ǫ���
		- ��?��?�����Ъ���С�ܬԲ��RmiContext���֫������Ȫ��Ǫ��ƪ��ު��Ǫ��������Ȫ����ꡢRMI�������󪹪Ȫ���򪽪Ϊު��Ūêƪ��ު��Ǫ���
		- HIGH priority����Ҫ���ƪ��ު���
		?������
		- �����ܪʫ���髤��?�����?������Ϊ۪Ȫ�ɪϫ���髯��?��ѡ�֧����?�Ϊ誦��?��׾�Ϋ�ë�?���Ϊߪ�￪�ơ��������?������ë�?����������￪�ު��������ơ����?�Ъ�����unreliable send���Ū����ꡢ�Ϫ�������������̽����˪Īʪ��몳�Ȫ�����ު������Ϊ誦��??�����窷����������髤��?����?����ѢΦ��Ǫϡ��۪Ȫ�ɪΫ�ë�?����reliable send���Ū��誦�˪��ơ��ͫëȫ�?���������Ϋ׫�ի�?��󫰪ʪɪ��ת��۪Ȫ�ɪ���������￪�ު�����ש������⢪�ݶ���ʪ���ë�?���Ϊߪ�������unreliable send��?���ƪ���몳�Ȫ��ު���?۰�����모�ު���

		\~
		*/
		PROUD_API static RmiContext UnreliableSend;

		/**
		\~korean
		EM_Fast ���� ��ȣȭ �Ͽ� Unreliable message�� RMI ȣ��� �̰��� �Ķ���ͷ� ������ �ȴ�.
		- ��Ÿ ������ UnreliableSend �� �����ϴ�.

		\~english
		Encrypt with EM_Fast mode then put this as parameter when you call RMI with Reliable message.
		- All other details are same as ReliableSend.

		\~chinese
		�EM_Fastټ��ʥ�������Unreliable message��УRMI?����???��????ʦ��
		- ����??UnreliableSend���ҡ�

		\~japanese
		EM_Fast��?�ɪ���?������Unreliable message��RMI�����������������ѫ��?��?���������ު��Ǫ���
		- ������������UnrelaibleSend���Ҫ��Ǫ���

		\~
		*/
		PROUD_API static RmiContext FastEncryptedUnreliableSend;


		/**
		\~korean
		EM_Secure ���� ��ȣȭ �Ͽ� Unreliable message�� RMI ȣ��� �̰��� �Ķ���ͷ� ������ �ȴ�.
		- ��Ÿ ������ UnreliableSend�� �����ϴ�.

		\~english
		Encrypt with EM_Secure mode then put this as parameter when you call RMI with Reliable message.
		- All other details are same as ReliableSend.

		\~chinese
		�EM_Secureټ��ʥ�������Unreliable message��УRMI?����???��????ʦ��
		- ����??UnreliableSend���ҡ�

		\~japanese
		EM_Secure��?�ɪ���?������Unreliable message��RMI�����������������ѫ��?��?���������ު��Ǫ���
		- ������������UnrelaibleSend���Ҫ��Ǫ���

		\~
		*/
		PROUD_API static RmiContext SecureUnreliableSend;





		/**
		\~korean
		Unreliable server to client multicast message�� RMI ȣ��� �̰��� �Ķ���ͷ� ������ �ȴ�.
		- ������ ���ϸ� ������ RmiContext ��ü�� �ֵ� ������ ������� ��� RMI ȣ��� �̰��� �׳� �ᵵ �ȴ�.
		- Medium priority�� �����Ǿ� �ִ�.
		- �� �����, �������� �������� Ŭ���̾�Ʈ�� unreliable RMI ��ε�ĳ��Ʈ ȣ���� �� �� ������ �� P2P ���� ������ �Ǿ� �ִ� �͵鳢����
		P2P�� ���� routed send�� �ϰ� �Ѵ�. �� ����� ���������� CPU ��뷮�� �ణ ������Ű�� �񰡷� �������� Ŭ���̾�Ʈ���� �۽�
		��ŷ��� �����Ѵ�. (��κ��� ���ӿ��� �����ϰ� ���� �� �ִ�.)

		\~english
		This is unreliable server to client multicast message and this is to be entered as parameter when calling RMI.
		- It is ok to use separate RmiContext object if needed but usually if the case is usual then it is ok to use this calling RMI.
		- Set as HIGH priority.
		- This function performs routed send via P2P for those direct P2P connected among receivers when server calls unreliable RMI broadcast to multiple clients.
		This function saves the amount of transmission from server to client in exchange of increase of CPU use in server. (Can be very useful in most of games.)

		\~chinese
		��Unreliable server to client multicast message��УRMI?����???��????ʦ��
		- ��?������?��?׺ RmiContext%?���ʦ줣�������?����УRMI?�ʦ���������??��
		- ���?Medium priority��
		- ������������?����??client?��unreliable RMI broadcast��У��?����P2P ����?����������???����?P2P��routed send������������ڰ��ʥCPU������?������?�?��?����client��?�������ᡣ

		\~japanese
		Unreliable server to client multicast message��RMI�����������������ѫ��?��?���������ު��Ǫ���
		- ��?��?�����Ъ���С�ܬԲ��RMI Context���֫������Ȫ��Ǫ��ƪ��ު��Ǫ��������Ȫ�����ϡ�RMI����������������򪽪Ϊު��Ūêƪ��ު��Ǫ���
		- Medium priority����Ҫ���ƪ��ު���
		- ����Ѧ���ϡ���?��?����?�Ϋ��髤����Ȫ�unreliable RMI�֫�?�ɫ��㫹�������󪷪򪹪��������������P2P������?���Ǫ��ƪ��������ͪǪ�P2P���ת���routed send���Ǫ���誦�˪��ު�������Ѧ���ϫ�?��?�Ǫ�CPU�������ᴪ�?ʥ������??�Ȫ��ơ���?��?��ꫯ�髤����Ȫت�������������������ު���(�۪Ȫ�ɪΫ�?������Ī��Ū��몳�Ȫ�����ު���)


		\~
		*/
		PROUD_API static RmiContext UnreliableS2CRoutedMulticast;

		PROUD_API void AssureValidation() const;
	};

	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#include "RmiContext.inl"
