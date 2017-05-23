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

#include "PnTime.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif
	/** \addtogroup minidump_group
	*  @{
	*/

	/** 
	\~korean
	���� ������ �䱸�ϴ� delegate

	\~english
	delegate that is requested by dump server

	\~chinese
	??��?�������delegate��

	\~japanese
	����׫�?��?���ϴ����delegate
	\~
	*/
	class IDumpServerDelegate
	{
	public:
		virtual ~IDumpServerDelegate() {}

		/** 
		\~korean
		���� ���� �Ķ���͸� �����ϴ� �޼���.
		������ ���۵Ǵ� ���� �ݹ�ȴ�. ����ڴ� �� �޼��带 ���� �������� ���� ���� �ɼ��� �����ؾ� �Ѵ�.

		\param refParam ���� ���� �ɼ�. �� �Լ����� ����ڴ� Proud.CStartServerParameter.m_tcpPort�� �ݵ�� �����ؾ� �Ѵ�.
		Proud.CStartServerParameter.m_localNicAddr,Proud.CStartServerParameter.m_serverAddrAtClient�� �ʿ�� �����ϵ��� �Ѵ�.
		������ �Ķ���ʹ� �������� �ʾƵ� �ȴ�.
		����! DumpServer�� UDP ����� ���� �ʱ⶧���� m_udpPorts, m_udpAssignMode�� �����ص� UDP ����� ���� �ʴ´�.

		\~english
		Method that sets server execution parameter
		Called back at the moment server is started. User must set server execution option through this method.

		\param refParam server execution option. Within this function, user must set Proud.CStartServerParameter.m_tcpPort at least.
		Proud.CStartServerParameter.m_localNicAddr and Proud.CStartServerParameter.m_serverAddrAtClient can be set as needed.
		Other parameter, they do not have to be set.
		**Note** Since DumpServer does not use UDP, UDP communication will be not available even if m_udpPorts and/or m_udpAssignMode are set.

		\~chinese
		?����?��?��??��۰����
		��?��??����?��?����?���?�۰������?��?����?��?��??��

		\param refParam ��?��?��??������?��?��??�� Proud.CStartServerParameter.m_tcpPort%��
		�������?��?�� Proud.CStartServerParameter.m_localNicAddr, Proud.CStartServerParameter.m_serverAddrAtClient%��
		�����??����?�ǡ�
		���DumpServer ��������UDP�ܣ� ��?��?��m_udpPorts, m_udpAssignMode ���??��UDP���ᡣ

		\~japanese
		��?��??���ѫ��?��?�����Ҫ���᫽�ë�
		��?��?����㷪�������૳?��Ыë�����ު�����?��?�Ϫ��Ϋ᫽�ëɪ��ת���?��?�˫�?��??�����׫��������Ҫ��ʪ���Ъʪ�ު���
		\param refParam ��?��??�����׫���󡣪���??�ǫ�?��?�ϡ�Proud.CStartServerParameter.m_tcpPort���������Ҫ��ʪ���Ъʪ�ު���
		Proud.CStartServerParameter.m_localNicAddr,Proud.CStartServerParameter.m_serverAddrAtClient����驪˪�ê����Ҫ���誦�˪��ު���
		?��Ϋѫ��?��?�����Ҫ��ʪ��ƪ��ު��Ǫ���
		�����DumpServer��UDP���Ī򪷪ʪ����ᡢm_udpPorts��m_udpAssignMode�����Ҫ��ƪ�UDP���᪬�����ު���
		\~
		*/
		virtual void OnStartServer(CStartServerParameter &refParam) = 0;

		/** 
		\~korean
		������ �����ؾ� �ϴ� ��Ȳ(������ ��û ��)�̸� �� �Լ��� true�� �����ϸ� �ȴ�.

		\~english
		In case when server must be terminated(i.e. upon user request), it can be done if this function returns true.

		\~chinese
		��?���?�����?����?���?������?�����?����true?ʦ��

		\~japanese
		��?��?����������?�ϣ���?��?�����ʪɣ��Ǫ���Ъ���??��true��꫿?�󪹪���ު��Ǫ���
		\~
		 */
		virtual bool MustStopNow() = 0;
		
		/** 
		\~korean
		Critical section ��ü�� �����Ѵ�. �����ڴ� �� �Լ��� ���� �̹� ������ ������� critical section�̳�
		������ �غ��� critical section ��ü�� �����ؾ� �Ѵ�.

		\~english
		Returns critical section object. Developer must provide either the critical section that is already used by server through this function or oterwise prepared critical section object.

		\~chinese
		����Critical section?�ڡ�??���?���?������?���?���������critical section���?����?��critical section?�ڡ�

		\~japanese
		Critical section ���֫������Ȫ�꫿?�󪷪ު�����?�Ϫ���??���ת�?�˫�?��?�����Ī��ƪ���critical section�Ȫ�ܬ�����᪷��critical section���֫������Ȫ����媷�ʪ���Ъʪ�ު���
		\~
		 */
		virtual CriticalSection* GetCriticalSection() = 0;
		
		/** 
		\~korean
		���� ������ �Ϸ������ �˸��� �̺�Ʈ
		\param err ���� ������ ���������� NULL��, �׷��� ������ ErrorInfo ��ü�� ����ִ�.

		\~english
		Evnet notifies that server start is completed
		\param err NULL if server start is successful, if not then it contains ErrorInfo object.

		\~chinese
		ͱ���?��??������event��
		\param err ��?��??������?NULL���������ErrorInfo?�ڡ�

		\~japanese
		��?��?��㷪��������쪿���Ȫ��骻�뫤�٫��
		\~
		 */
		virtual void OnServerStartComplete(Proud::ErrorInfo *err) = 0;
		
		/** 
		\~korean
		����� ���� ������ �̸��� �����ڰ� �� �Լ��� ���� �����ؾ� �մϴ�. �Է� �Ķ���͸� �ٰŷ� ������ָ� �����ϴ�.
		\param clientHostID ���� Ŭ���̾�Ʈ�� HostID.
		\param clientAddr Ŭ���̾�Ʈ�� �ܺ� ���ͳ� �ּ� 
		\param dumpTime ������ ���� �ð�

		\~english
		Developer must provide the name of dump file to be recorded through this function. It is ideal if it is based on input parameter.
		\param clientHostID HostID of dump client
		\param clientAddr external internet address of client 
		\param dumpTime time that dump stays

		\~chinese
		??���?���?����??��??������٣?�������?��???����?�
		\param clientHostID ??��ʫ��Host ID��
		\param clientAddr ��ʫ����ݻ��??�򣡣
		\param dumpTime ??�����??��

		\~japanese
		��?�������׫ի������٣�����?������??���ת����媷�ʪ���Ъʪ�ު��������ѫ��?��?����?�˪����ª���ު��Ǫ���
		\param clientHostID ����׫��髤����Ȫ�HostID.
		\param clientAddr ���髤����Ȫ���ݻ����?�ͫëȫ��ɫ쫹
		\param dumpTime ����ת�?������
		\~
		*/
		virtual String GetDumpFilePath(Proud::HostID clientHostID, const Proud::AddrPort& clientAddr, CPnTime dumpTime) = 0;

		/** 
		\~korean
		���� �ð����� ȣ��ȴ�.

		\~english
		Periodically called

		\~chinese
		������??Դ?��У��

		\~japanese
		������઴�Ȫ������󪵪�ު���
		\~
		 */
		virtual void OnFrameMove() {}
	};

	/** 
	\~korean
	���� ����

	�Ϲ��� �뵵
	- ������ Create()�� �Ѵ�.
	- RunMainLoop()�� �����ϸ� ���� ������ ������ ������ ������ �����Ѵ�.

	\~english
	dump server

	General usage
	- To create, use Create().
	- If run RunMainLoop() then it runs until dump server is terminated.

	\~chinese
	??��?�

	������Բ
	- ������?Create()��
	- ?��RunMainLoop()��?��?������������??��?��?򭡣

	\~japanese
	����׫�?��?

	�����ܪ���Բ
	- ������Create()�������ު���
	- RunMainLoop()��?������ȫ���׫�?��?�������������ު���ܪ��������ު���
	\~
	 */
	class CDumpServer
	{
	public:
		virtual ~CDumpServer(void) {}
		/** 
		\~korean
		�� �޼��带 �����ϸ� ���� ������ Ȱ��ȭ�ȴ�. �� �޼���� ������ �۵��� �����϶�� ��û�� IDumpServerDelegate��
		���� ���� ������ �������� �ʴ´�.

		\~english
		Once this method is run, dump server is activated. This method does not return until it receives server down request from IDumpServerDelegate

		\~chinese
		?���۰����??̭��??��?�?���?��??���??����IDumpServerDelegate??�����۰����?���ޡ�

		\~japanese
		���Ϋ᫽�ëɪ�?������ȫ���׫�?��?������������ު������Ϋ᫽�ëɪϫ�?��?�����Ѫ���򭪷��Ȫ�������몬IDumpServerDelegate�˪�ê�?����ުǫ꫿?�󪷪ު���
		\~
		 */
		virtual void RunMainLoop() = 0;

		/** 
		\~korean
		CDumpServer ��ü�� �����Ѵ�.
		\param dg IDumpServerDelegate�� ��ӹ��� �̺�Ʈ Callback�� ���� class ������
		\return ������ CDumpServer ��ü ������

		\~english TODO:translate needed.
		Generates a CDumpServer object. 
		\param dg The class pointer to receive the event callback that inherited IDumpServerDelegate
		\return Generated CDumpServer object pointer

		\~chinese
		���� CDumpServer%?�ڡ�
		\param dg ���?�IDumpServerDelegate��Callbackevent��class pointer��
		\return ������ CDumpServer%?��pointer��

		\~japanese
		CDumpServer���֫������Ȫ��������ު���
		\param dg IDumpServerDelegate����?���ƪ��ê����٫�ȫ�?��Ыë��������뫯�髹�ݫ���?
		\return �������쪿CDumpServer���֫������ȫݫ���?
		\~
		 */
		PROUDSRV_API static CDumpServer* Create(IDumpServerDelegate* dg);
	};
	/**  @} */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif