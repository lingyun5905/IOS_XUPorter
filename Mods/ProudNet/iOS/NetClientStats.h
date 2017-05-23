/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 177 92 124 113 87 79 17 155 171 239 138 133 88 235 28 112 146 102 93 52 214 131 240 31 138 179 248 115 127 118 107 31 112 91 111 14 243 1 121 131 22 69 144 19 214 101 65 133 253 32 122 175 12 198 63 134 23 240 109 90 59 142 194 194 160 148 139 101 68 220 217 181 32 240 36 47 59 74 18 182 145 116 17 29 255 115 236 11 29 111 122  */
#pragma once

#include "NetCoreStats.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/**
	\~korean
	Ŭ���̾�Ʈ�� ��Ȳ ��� �����Դϴ�.
	���� ���� ��� ���˴ϴ�.
	
	\~english
	Client status information.
	Used for performance check.
	
	\~chinese
	��?Ӯ????���ӡ�
	��������??��
	
	\~japanese
	���髤����Ȫ�?�Ϫ���ͪ���êǪ���
	�ѫի�?�ޫ󫹪����������Ū��ƪ��ު���
	*/
	class CNetClientStats :public CNetCoreStats
	{
	public:

		/**
		\~korean
		���� ����Ǿ��ִ� remote peer�� ����

		\~english
		Number of remote peer that in currently connected

		\~chinese
		?��?����remote peer��??��

		\~japanese
		��Īʪ��êƪ���remote peer��?
		\~
		*/
		uint32_t m_remotePeerCount;

		/**
		\~korean
		true�̸� �������� UDP ����� �������� �ǹ��Ѵ�.
		false�̸� UDP�� ���� ���ϸ�, �������� unreliable �޽�¡�� TCP�� �ְ�޾����� ������ �ǹ��Ѵ�.

		\~english
		true means the UDP communication with server is ok
		Cannot use UDP when false and also means the unreliable messaging with server is done via TCP.

		\~chinese
		True��?��ګ�?��?����UDP�������ȡ�
		False��?��������UDP����ګ�?unreliable messaging�������TCP?�ȡ�

		\~japanese
		True�Ǫ���Ы�?��?�Ȫ�UDP���᪬���ȪǪ��몳�Ȫ���ګ���ު���
		False�Ǫ����UDP���Ū�������?��?�Ȫ�unreliable��ë�?���󫰪�TCP�Ǫ�����ꪹ�몳�Ȫ���ګ���ު���
		\~
		*/
		bool m_serverUdpEnabled;

		/**
		\~korean
		Direct P2P�� �Ǿ��ִ� remote peer�� ����

		\~english
		Number of remote peer that consisted Direct P2P

		\~chinese
		Direct P2P��remote peer??��

		\~japanese
		Direct P2P�˪ʪêƪ���remote peer��?
		\~
		*/
		uint32_t m_directP2PEnabledPeerCount;


		/**
		\~korean
		TCP, UDP Send Queue�� �����ִ� �� ũ��, Send Queue �� ũ��

		\~english
		Total size left in TCP and UDP Send Queue. Total size of the Send Queue


		\~chinese
		TCP, UDP Send Queue�������?�����, Send Queue��?���

		\~japanese
		TCP, UDP Send Queue��?�êƪ��뫵������ͪ��Send Queue�Ϋ�������ͪ
		\~
		*/
		uint32_t m_sendQueueTotalBytes;
		uint32_t m_sendQueueTcpTotalBytes;
		uint32_t m_sendQueueUdpTotalBytes;


		CNetClientStats();

		virtual String ToString() const;
	};
}
#ifdef _MSC_VER
#pragma pack(pop)
#endif