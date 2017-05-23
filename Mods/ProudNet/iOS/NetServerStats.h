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
	\brief ���� ��Ȳ ��� ����
	- ���� ������ ���� �뵵�̴�.

	\~english
	\brief server status statistics information
	- To check performance

	\~chinese
	\brief ��?��????���ӡ�
	- ?������?������Բ��

	\~japanese
	\brief ��?��??����ͪ����
	- �������ҪΪ������Բ�Ǫ���
	\~
	*/
	class CNetServerStats:public CNetCoreStats
	{
	public:
		/**
		\~korean
		Ŭ���̾�Ʈ���� ������ P2P ������ �� ����
		- ��, ���� P2P ����� �� ���� �������� P2P ���� ��ü�� �õ����� ���� P2P ������ ���迡�� ���ܵȴ�.

		\~english
		Number of all direct/indirect P2P connection among clients
		- However, this does not include the P2P connections that are not even attempted yet since there has been no P2P communication attempted.

		\~chinese
		Client��?��?��P2P?����???��
		- ӣ?ڱ?��?P2P���ᣬ���������?P2P?�������Դ?��??��P2P?����⡣

		\~japanese
		���髤����������?����P2P��?��??
		- ӣ�����ު�P2P��������ê����Ȫ�ʪ��Ϊǡ�P2P��?�?���˪��������ʪ��ê�P2P��?�ϡ��ͪ�����⪵��ު���
		\~
		*/
		uint32_t m_p2pConnectionPairCount;

		/**
		\~korean
		Ŭ���̾�Ʈ���� ���� P2P ������ �� ����
		- ��, ���� P2P ����� �� ���� �������� P2P ���� ��ü�� �õ����� ���� P2P ������ ���迡�� ���ܵȴ�.

		\~english
		Number of all direct P2P connection among clients
		- However, this does not include the P2P connections that are not even attempted yet since there has been no P2P communication attempted.

		\~chinese
		Client��?��?��P2P?����???��
		- ӣ?ڱ?��?P2P���ᣬ���������?P2P?�������Դ?��??��P2P?����⡣

		\~japanese
		���髤����������?����P2P��?��??
		- ӣ�����ު�P2P��������ê����Ȫ�ʪ��Ϊǡ�P2P��?�?���˪��������ʪ��ê�P2P��?�ϡ��ͪ�����⪵��ު���
		\~
		*/
		uint32_t m_p2pDirectConnectionPairCount;

		/**
		\~korean
		�� Ŭ���̾�Ʈ ����

		\~english
		Number of all clients

		\~chinese
		?client??��

		\~japanese
		���髤�����??
		\~
		*/
		uint32_t m_clientCount;

		/**
		\~korean
		UDP ����� �����ϰ� �ִ� (TCP fallback�� ���ϰ� �ִ�) Ŭ���̾�Ʈ ����

		\~english
		Number of clients that sustain UDP communications(not doing TCP fallback)

		\~chinese
		?�UDP�����ܣ�?��?��TCP fallback��client??��

		\~japanese
		UDP������򥪷�ƪ���(TCP fallback�򪷪ƪ��ʪ�)���髤�����?
		\~
		*/
		uint32_t m_realUdpEnabledClientCount;

		/**
		\~korean
		������� UDP ��Ʈ�� �����Դϴ�.
		- ServerUdpAssignMode_Static�� ������̸� �� ���� ���ǹ��մϴ�.
		- ServerUdpAssignMode_PerClient�� ������̸� �� ���� ���� ������� ��Ʈ�� ������ �����մϴ�.
		�Ϲ�������, ������ ����� Ŭ���̾�Ʈ�� ������ ���� �����մϴٸ� ���� �������� �̸�
		����ϼŵ� �˴ϴ�.

		\~english
		Number of UDP ports that are in use
		- This value is meaningless if ServerUdpAssignMode_Static is in use.
		- If ServerUdpAssignMode_PerClient is in use then this value returns the number of ports that are currently in use.
		In general, this is same as the numer of clients connnected to server but you can use this as diagnosis.

		\~chinese
		��������UDPӮϢ??��
		- ����ServerUdpAssignMode_Static����?�?������?����
		- ����ServerUdpAssignMode_PerClient����?�?����?���������ӮϢ??��
		����?���?��?����client???�����ң�ʦ��??�������ġ�

		\~japanese
		���Ī��ƪ���UDP��?�Ȫ�?�Ǫ���
		- ServerUdpAssignMode_Static�����Ī��ƪ���ȡ�������������ګ�Ǫ���
		- ServerUdpAssignMode_PerClient�����Ī��ƪ���ȡ���������������Ī��ƪ����?�Ȫ�?��꫿?�󪷪ު���
		�����ܪˡ���?��?�˪Īʪ��ê����髤����Ȫ�?�Ȫ۪��Ҫ��Ǫ�������?���ܪǪ�������Ī��ƪ��ު��Ǫ���
		\~
		*/
		int m_occupiedUdpPortCount;

		CNetServerStats();
		virtual String ToString() const;
	};
}
#ifdef _MSC_VER
#pragma pack(pop)
#endif