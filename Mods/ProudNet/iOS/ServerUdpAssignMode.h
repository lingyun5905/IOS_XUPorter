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
������, ������ �����ϴ� Ŭ���̾�Ʈ�� ����� �� ����� UDP ������ �����ϴ� ��å�Դϴ�.
�ڼ��� ������ <a target="_blank" href="http://guide.nettention.com/cpp_ko#server_udp_assign" >������ UDP ��Ʈ ��� ���</a> �� �����Ͻʽÿ�.

\~english
This is a policy allocating UDP sockets to be used by the serverwhen communicating with the clients.
Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#server_udp_assign" >Method of using Server UDP Port</a> for more details.

\~chinese
������?��??����?����client������?��������UDP socket��������
????��<a target="_blank" href="http://guide.nettention.com/cpp_zh#server_udp_assign" >��?��UDPӮϢ����۰��</a>%��

\~japanese
��?��?������?��?����?���뫯�髤����Ȫ����᪹�������Ū�UDP�����ëȪ��ܪ�?�ƪ�ݫ꫷?�Ǫ���
�٪����ϡ�\ref server_udp_assign ��?�Ϊ���������
\~
*/
	enum ServerUdpAssignMode
	{
		/**
		\~korean
		�����ȵ�. ����ڴ� �� ���� ���� ���ʽÿ�.

		\~english
		Not designated. Users are not to use this value.

		\~chinese
		?����ҡ���?��������?��

		\~japanese
		ڱ��ҡ���?��?�Ϫ��������ŪêƪϪ����ު���
		\~
		*/
		ServerUdpAssignMode_None,

		/**
		\~korean
		������ ������ �� Ŭ���̾�Ʈ�� ���ؼ� ���� �ٸ� UDP ��Ʈ�� ����մϴ�.
		- �� ���� �⺻���̸�, ����Ǵ� ���Դϴ�.
		- �� ���� Proud.CStartServerParameter.m_udpPorts ���� ������ ��Ĩ�ϴ�.

		\~english
		For each clients that coonects, it is to use different UDP port for each of them.
		- This value is a default and recommended value.
		- This value affects Proud.CStartServerParameter.m_udpPorts also.

		\~chinese
		??����client����������UDPӮϢ��
		- �?����??����������?��?��
		- �?�? Proud.CStartServerParameter.m_udpPorts%?���?��

		\~japanese
		��?�����êƪ��������髤����Ȫ�?���������ު�UDP��?�Ȫ����Ī��ު���
		- ���������������ǡ�??���Ǫ���
		- �������ϡ�Proud.CStartServerParameter.m_udpPorts�˪���ª���ܪ��ު���
		\~
		*/
		ServerUdpAssignMode_PerClient,

		/**
		\~korean
		������ ������ ��� Ŭ���̾�Ʈ�� �̸� �غ�Ǿ� �ִ� ������ ������ UDP ��Ʈ�� �����մϴ�.
		�� ������ ����� ��� UDP�� Ư���� ������ ����� �ϱ� ����� Ŭ���̾�Ʈ���� ���� �� �ֽ��ϴ�.
		- �� �ɼ��� ProudNet�� ���� ȣȯ�� ������ �غ�� ����̸�, �������� �ʴ� ����Դϴ�.
		- �� �ɼ� ���� ��ȭ�� ������ �ʿ��մϴ�. �ڼ��� ���� <a target="_blank" href="http://guide.nettention.com/cpp_ko#block_icmp" >ICMP ���� ��ȭ�� ����</a> �� �����Ͻʽÿ�.
		�� ���� Proud.CStartServerParameter.m_udpPorts ���� ������ ��Ĩ�ϴ�.

		\~english
		All the clients that connect reuse the UDP ports that are already prepared.
		When using this option, it is possible to cause some clients hard to communicate with the server due to UDP characteristics.
		- This is option is prepared for the lower compatibility of Proudnet and it is not recommended to use.
		- It is necessary to use a firewall setup to use this feature. Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#block_icmp" >Firewall setup for ICMP related
</a> for more details.
		This value affects Proud.CStartServerParameter.m_udpPorts also.

		\~chinese
		?����client�������?��?����ͳ��??��UDPӮϢ��
		�����?����?������UDP��������ʦ��??��?��?��?�������client��
		- �??��?��?ProudNet��������������?��������������?��������
		- �����???�������??�ǡ�????��<a target="_blank" href="http://guide.nettention.com/cpp_zh#block_icmp" >ICMP ��?������??��</a>%��
		�?�? Proud.CStartServerParameter.m_udpPorts%?���?��

		\~japanese
		��?�����êƪ�����ƪΫ��髤����Ȫ����ê����᪵��ƪ���ͳ��?��UDP��?�Ȫ�����Ī��ު���
		�������Ҫ����Ī������ꡢUDP���������髵?��?�Ȫ����᪬�񪷪����髤����Ȫ�?�檹�몳�Ȫ�����ު���
		- ���Ϋ��׫�����ProudNet�������������Ϊ������᪵�쪿Ѧ���ǡ�??���ʪ�Ѧ���Ǫ���
		- ���Ϋ��׫������Ū����ϫի���������?�����Ҫ���驪Ǫ����٪����ϡ�\ref block_icmp��?�Ϊ���������
		�������ϡ�Proud.CStartServerParameter.m_udpPorts�˪���ª���ܪ��ު���
		\~
		*/
		ServerUdpAssignMode_Static,
	};

	/**  @} */

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif

}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
