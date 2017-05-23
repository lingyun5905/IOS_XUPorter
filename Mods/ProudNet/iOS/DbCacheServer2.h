/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 177 92 124 113 87 79 17 155 171 239 138 133 88 235 28 112 146 102 93 52 214 131 240 31 138 179 248 115 127 118 107 31 112 91 111 14 243 1 121 131 22 69 144 19 214 101 65 133 253 32 122 175 12 198 63 134 23 240 109 90 59 142 194 194 160 148 139 101 68 220 217 181 32 240 36 47 59 74 18 182 145 116 17 29 255 115 236 11 29 111 122  */
/*
ProudNet 1.7.34387-dev003-10


�� ���α׷��� ���۱��� ���ټǿ��� �ֽ��ϴ�.
�� ���α׷��� ����, ���, ������ ���õ� ������ �� ���α׷��� �������ڿ��� ����� ������,
����� �ؼ����� �ʴ� ��� ��Ģ������ ���� ����� �����մϴ�.
���� ��뿡 ���� å���� �� ���α׷��� �������ڿ��� ��༭�� ��õǾ� �ֽ��ϴ�.

** ����: ���۹��� ���� ���� ��ø� �������� ���ʽÿ�.


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

#if defined(_WIN32)
#include "BasicTypes.h"
#include "dbenums.h"
#include "DbLoadedData2.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif
	/** \addtogroup db_group
	*  @{
	*/

	/**
	\~korean
	DB cache�� ���� �ε��Ǵ� ���̺��� �̸����Դϴ�.

	root node�� ���� ���̺� �̸��� child node�� ���� ���̺� �̸����� �����ʽÿ�.
	child node�� ���� ���̺� �̸��� 0�� �̻��̾�� �մϴ�.
	child node�� ���� ���̺� �̸��� �߿��� root node�� ���� ���̺� �̸��� ���� ���� ����� �մϴ�.

	\~english

	\~japanese
	DB cashe�˪�êƫ�?�ɪ�����?�֫�٣�Ǫ���
	root node�Ϊ���Ϋ�?�֫�٣��child node�Ϊ���Ϋ�?�֫�٣�ʪɪ�����ƪ��������� 
	child node�Ϊ���Ϋ�?�֫�٣��0���߾�ǪϪʪ���Ъʪ�ު���
	child node�Ϊ���Ϋ�?�֫�٣����˪ϡ�root node�Ϊ���Ϋ�?�֫�٣���Ҫ���Ϊ����êƪϪ����ު���

	\~
	*/
	class CCachedTableName
	{
	public:
		/** root node�� ���� ���̺� �̸� */
		String m_rootTableName;
		/** child node�� ���� ���̺� �̸� */
		CFastArray<Proud::String> m_childTableNames;
	};

	/**
	\~korean
	CDbCacheServer2���� �ݹ��ϴ� �̺�Ʈ�� �����ڰ� �����ؾ� �ϴ� �޼��带 �ݹ��� ó���ϴ� delegate ��ü

	\~english
	This is delegate object that handle callback event from CDbCacheServer2 or callback method which developer has to realize.

	\~chinese
	� CDbCacheServer2%��??����?event���??��??��۰����delegate?�ڡ�

	\~japanese
	CDbCacheServer2�ǫ�?��Ыë����뫤�٫�ȪȪ���?��?�ު��ʪ���Ъʪ�ʪ��᫽�ëɪ�?��Ыë�����delegate���֫�������
	\~
	*/
	class IDbCacheServerDelegate2
	{
	public:
		virtual ~IDbCacheServerDelegate2() {}

		/**
		\~korean
		���� ���� �߻��� ȣ��˴ϴ�
		\param errorInfo ������ ���� �����Դϴ�. ErrorInfo::ToString()�� �̿��Ͻø� �����ϰ� �ڼ��� ������ ������ ���� �� �ֽ��ϴ�.

		\~english TODO:translate needed
		It is called when an internal error occurs
		\This is the information on an error. If you use ErrorInfo::ToString(), you can see the detailed information of the problem. 

		\~chinese
		?��?ݻ???��У��
		\param errorInfo ???�����ӡ����� ErrorInfo::ToString()%��?ʦ�۰������??�����ӡ�

		\~japanese
		?ݻ����??�����������󪵪�ު���
		\param errorInfo ����?��?�������êǪ���ErrorInfo::ToString()�����Ī������?���٪���������ê�̸���ު���

		\~
		*/
		virtual void OnError(ErrorInfo *errorInfo) = 0;

		/**
		\~korean
		���� ��� �߻��� ȣ��˴ϴ�. �������ٴ� ���� ������ ������ ������.
		\param errorInfo ������ ���� �����Դϴ�. ErrorInfo::ToString()�� �̿��Ͻø� �����ϰ� �ڼ��� ������ ������ ���� �� �ֽ��ϴ�.

		\~english TODO:translate needed
		It is called when an internal warning occurs. This reports a problem with the level lower than an error. 
		\param errorInfo This is the information on an error. If you use ErrorInfo::ToString(), you can see the detailed information of the problem

		\~chinese
		?��?ݻ��ͱ?��У��?ͱ��??������??��
		\param errorInfo ???�����ӡ����� ErrorInfo::ToString()%��?ʦ�۰������??�����ӡ�

		\~japanese
		?ݻ��ͱ��?�����������󪵪�ު�������?�������٫��������ͱ���ު���
		\param errorInfo ����?��?�������êǪ���ErrorInfo::ToString()�����Ī������?���٪���������ê�̸���ު���

		\~
		*/
		virtual void OnWarning(ErrorInfo *errorInfo) = 0;

		/**
		\~korean
		Proud.Exception���� �����մϴ�.
		- �Ϲ������� ���� �ڵ忡�� ���� ������ ó���մϴ�.
		- ������ �ʿ��� �͵��� �����ϸ� �˴ϴ�.
		- ExceptionType���� �ش� Exception ��ü�� �� ����ϸ� �˴ϴ�.
		- _com_error, void*, std::exception���� ��� ó���մϴ�.
		���� catch(...)�� ó���ϴ� OnUnhandledException()�� �ֽ��ϴ�.
		- void*�� ���� ��ü�� Ÿ���� ĳ�����ؼ� ���� �� �ֽ��ϴ�. ���� MFC CException�� �޴µ� ���˴ϴ�.

		\~english
		Merge to Proud.Exception
		- It handle error that occur from user code.
		- User realize things that user needed.
		- You can use Exceptiontype that obtain Exception object.
		- It process _com_error, void*, std::exception, etc. Also there is OnUnhandledException() that handle catch(...)
		- void* can obtain exceptional object type by casting. For example, it uses obtaining MFC CException.

		\~chinese
		�� Proud.Exception%?����?��
		- ����?��?��?��??����??��
		- ��???�����?�?ʦ��
		- ��ExceptionType?��?������?Exception?��?ʦ��
		- ��ݻ?��_com_error, void*, std::exception �������?��catch(...)��OnUnhandledException()��
		- ??����?����?�����ʦ����void*���������MFC CException%��?�����ġ�

		\~japanese
		Proud.Exception�����ꪷ�ު���
		- �����ܪ˫�?��?��?�ɪ��ު�뫨��?��?�⪷�ު���
		- ��?��?����驪ʪ��Ȫ�?�ު�����ު��Ǫ���
		- ExceptionType����?Exception���֫������Ȫ�����Ū����ު��Ǫ���
		- _com_error, void*, std::exception�ʪɪ����?�⪷�ު���
		�ު���catch(...)��?�⪹��OnUnhandledException()�⪢��ު���
		- void*�����⫪�֫������ȪΫ����ת򫭫㫹�ƫ��󫰪���᮪��ު���?�ˡ�MFC CException�������몳�Ȫ��Ū��ު���

		\~
		*/
		virtual void OnException(const Exception &e) = 0;


		/**
		\~korean
		DB cache server2���� DBMS�� ���� ����ϴ� ó���� �񵿱�� ����ȴ�. �� �޼���� �񵿱�� ����ϴ� ó����
		�Ϸ�� ������ DB cache server�� ���� ������κ��� �ݹ�˴ϴ�.
		- Visual Studio 2005 �̻󿡼��� override keyword ����� �����մϴ�.
		\param type �Ϸ�� DBMS ���(PropNode)�� ���� (���� \ref DbmsWritePropNodePendType)

		\~english
		Direct writing process to DBMS is running asynchronously in DB cache server2. When asynchronous writting process has finished, this method will callback from internal thread in DB cache server.
		- We recommend to use override keyword on Visual Studio 2005 or above.
		\param type Sort of finished DBMS history (PropNode)

		\~chinese
		?DB cache server��DBMS����??��?����?��?������??��??��?��������?���۰��???ݻ?����?DB cache server��
		- Visual Studio 2005�߾��?����override keyword��
		\param type ������DBMS??��PropNode����??��?�� \ref DbmsWritePropNodePendType����

		\~japanese
		DB cache serve2��DBMS��������?����?���ު��Ѣ��?������ު������Ϋ᫽�ëɪ�ު��Ѣ����?����?�⪬�������������Ȫ�DB cache server��?ݻ����ëɪ��髳?��Ыë�����ު���
		- Visual Studio 2005�߾�Ǫ�override keyword���Ī�?�᪷�ު���
		\param type �������쪿DBMS��?(PropNode)����׾(?�� \ref DbmsWritePropNodePendType)

		\~
		 */
		virtual void OnDbmsWriteDone(DbmsWritePropNodePendType /*type*/) {}
	};

	/**
	\~korean
	CDbCacheServer2�� ���� �۵��� �����ϱ� ���� �����ؾ� �ϴ� �Ķ����

	\~english
	Parameter that must be provided in order to initiate CDbCacheServer2

	\~chinese
	CDbCacheServer ?����?��?�??�����??��

	\~japanese
	CDbCacheServer2����?��?���Ѫ���㷪��몿�����ꪷ�ʪ���Ъʪ�ʪ��ѫ��?��?
	\~
	 */
	class CDbCacheServer2StartParameter
	{
	public:
		/**
		\~korean
		������ �ּ�. �ڼ��� ���� CStartServerParameter�� ���� �̸��� ��� ����

		\~english
		Server address. Please refer the member of same name at CStartServerParameter for further details.

		\~chinese
		��?���򣡣??��??�� CStartServerParameter%����٣��?��

		\~japanese
		��?��?�Ϋ��ɫ쫹���٪����ϡ�CStartServerParameter���Ҫ�٣��Ϋ���?��?�Ϊ���������
		\~
		 */
		Proud::String m_serverIP;

		/**
		\~korean
		Ŭ���̾�Ʈ�� ������ ������ ���ε��� �ּ��Դϴ�.
		- �ʱⰪ�� �� ���ڿ��Դϴ�.
		- ��������� �� ���ڿ��� ���������� Ŭ���̾�Ʈ�� ��Ʈ��ũ �������̽�(NIC)�� 2�� �̻� ������ ���,
		�׸��� �װ͵� �� �ϳ����� �ٸ� CLanClient���� ���� ���� ��û�� ���� �� �ִ� ��� ���⿡ �ش�˴ϴ�.
		NIC�� ������ IP �Ǵ� ȣ��Ʈ �̸��� �����ؾ� �մϴ�. ȣ��Ʈ�� �ִ� NIC �ּ� ����Ʈ�� �������� Proud.GetLocalIPAddresses�� �� �� �ֽ��ϴ�.
		- ȣ��Ʈ �̸��� ������ ��� Ŭ���̾�Ʈ�� ������ �����ϱ� ���� �ּҷ� localhost�� �Է��� ��� ���� ���и� �� �� �ֽ��ϴ�. �̷��� ���
		Ŭ���̾�Ʈ�� ������ �����ϱ� ���� ���� ȣ��Ʈ�� �ּҸ� ��������� �Է��ؾ� �մϴ�.

		\~english
		The address that the listening socket of the client to be bound.
		- The initial value is an empty string.
		- Usually set as an empty string but in case when the client has 2 or more of network interfaces (NICs)
		   and when only one of them is able to recieve the connection request from other CLanClient, it is the case to use this.
		  The IP address or the host name designated by the NIC must be used. Proud.GetLocalIPAddresses can be used to get the NIC address list located in the host.
		- In the case that a host name is used, a connection failure can occur when localhost is set as the address to connect to the server for a client.
		  In this case, the client must be set clearly as the server host address in order to connect to the server.

		\~chinese
		��ʫ���??Ϣ���boud���򣡣
		- ��??�����ݬ?��
		- ����?��������ݬ����?��ʫ?��??�߾??ͣ����NIC����?����?������������?����??�� CLanClient%??��?���?��?��??�??��
		����?NIC�����IP������٣�����?�������NIC��֪����?ʦ����� Proud.GetLocalIPAddresses%��
		- ������٣���?������ʫ?��?����?��?��localhot��?��ʦ��??����?��??����?������??��?����?��??٥������?����?��������򣡣

		\~japanese
		���髤����ȪΫ꫹�˫󫰫����ëȪ��Ы���ǫ��󫰪���뫢�ɫ쫹�Ǫ���
		- ��Ѣ�����������֪�Ǫ���
		- �����ܪ��������֪����Ҫ��ު��������髤����Ȫ��ͫëȫ�?������?�ի�?��(NIC)��2���߾�êƪ������ꡢ�����ƪ�������ĪΪߪ����CLanClient����?����?���������������ꡢ�������?���ު���
		NIC����Ҫ��쪿IP�ު��ϫ۫���٣����Ҫ��ƪ����������۫��Ȫ˪���NIC���ɫ쫹�꫹�Ȫ���몿��˪ϡ�Proud.GetLocalIPAddresses���Ū����Ȫ��Ǫ��ު���
		- �۫���٣����Ҫ������ꡢ���髤����Ȫϫ�?��?����?���몿��˫��ɫ쫹�ǡ�localhost�������������ꡢ��?������ʦ����������ު������Ϊ誦�����ꡢ���髤����Ȫϫ�?��?����?���몿��˫�?��?�۫��ȪΫ��ɫ쫹��٥���ܪ��������ʪ���Ъʪ�ު���

		\~
		*/
		String m_localNicAddr;

		/**
		\~korean
		TCP ������ ��Ʈ.
		�ڼ��� ���� CStartServerParameter�� ���� �̸��� ��� ����

		\~english
		TCP listening port.
		Please refer the member of same name at CStartServerParameter for further details.

		\~chinese
		TCP �?ӮϢ��
		??��??�� CStartServerParameter%����٣��?��

		\~japanese
		TCP�꫹�˫󫰫�?��
		�٪����ϡ�CStartServerParameter���Ҫ�٣��Ϋ���?��?�Ϊ����������

		\~
		 */
		int m_tcpPort;

		/**
		\~korean
		DBMS�� �����ϱ� ���� connection string.
		- ���ڿ��� ���ؼ��� CAdoConnection.Open ���� ����

		\~english
		Connection string to connect to DBMS.
		- Please refer CAdoConnection.Open help section for text strings

		\~chinese
		?��?��DBMS��connection string��
		- ?�ݬ��??�� CAdoConnection.Open%?𾡣

		\~japanese
		DBMS����?���몿���connection string.		
		- ���֪��?���ƪϡ�CAdoConnection.Open�Ϋث�ת�?�Ϊ���������

		\~
		*/
		Proud::String m_DbmsConnectionString;

		/**
		\~korean
		�� DB ������ ������ �� �ִ� ����Ű
		- ���� �� ���� ���� Ŭ���̾�Ʈ�� ����Ǿ�� �ȵȴ�.
		�� ���� DB cache client(���� ���� ��)�� �� ������ �����ϱ� ���� �������� ���ȴ�.

		\~english
		The authentication key that can connect to this DB server
		- This value MUST NOT be exposed to game clients.
		  This value is used by DB cache client(e.g. game servers and etc.) to connect to main server.

		\~chinese
		ʦ�?���DB��?����???��
		- ?????������ש?��ʫ��
		�?��DB cache client����?��?������?��?��������?��?���������ܡ�

		\~japanese
		����DB��?��?����?�Ǫ�����?��?
		- �?�������ϫ�?�૯�髤����Ȫ����󪵪�ƪϪ����ު��� 
		��������DB cache client(��?�૵?��?�ʪ�)���⫵?��?����?���몿������ܪ��Ū��ު���

		\~
		*/
		Proud::String m_authenticationKey;

		/**
		\~korean
		CDbCacheServer2�� �ʿ�� �ϴ� delegate ��ü�� ������
		- �� ��ü�� CDbCacheServer2 ��ü�� �����ϴ� �� ��� �����ؾ� �մϴ�.

		\~english
		Delegate object's pointer that CDbCacheServer requires
		- This object must exist as long as CDbCacheServer object exists.

		\~chinese
		��� CDbCacheServer2%��delegate?����pointer��
		- ��� CDbCacheServer2%?������?����������

		\~japanese
		CDbCacheServer2����驪Ȫ���delegate���֫������ȪΫݫ���?
		- ���Ϋ��֫������Ȫ�CDbCacheServer2���֫������Ȫ�������ڪꡢ?�����������驪�����ު���

		\~
		*/
		IDbCacheServerDelegate2* m_delegate;

		/**
		\~korean
		DB cache�� ���� �ε�,������ �Ͼ ���̺���� �̸��Դϴ�.
		Root table�� child table���� �̸��� ���⿡ �����ʽÿ�.
		�ڼ��� ���� CCachedTableName �� �����Ͻʽÿ�.

		\~english
		Names of tables to be loaded and saved by DB cache.
		Input names of root and child tables here.
		Refer to CCachedTable for details.

		\~chinese
		�DB?��ʥ?����������٣?��
		��?��Root table��child table��٣?��
		??��??��CCachedTableName��

		\~japanese
		DB cache�˪�êƫ�?�ǫ��󫰡���������?�֫�٣�Ǫ���
		Root table��child ��������٣��򪳪�������ƪ���������
		�٪����ϡ�CCachedTableName��?�Ϊ���������

		\~
		 */
		CFastArray<CCachedTableName> m_tableNames;

		/**
		\~korean
		DBCacheServer2�� ������ ������ ����ϴ����� ���� �����Դϴ�. <a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >������ ������ �����ϱ�</a> ����Դϴ�.
		- �⺻������ false�Դϴ�.

		\~english
		Whether to allow or not to allow a non-exclusive access to DBCacheServer. This is a <a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> function.
		- The default value is false.

		\~chinese
		������??DBCacheServer2��ު?����Ρ���<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??������?��</a>%������
		- ��??false��

		\~japanese
		DBCacheServer2��ު?������Ϊ���黪��몫�ɪ�����?���뫻�ëƫ��󫰪����Ǫ���<a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> Ѧ���Ǫ���
		- �����ܪ� false�Ǫ���

		\~
		*/
		bool	m_allowNonExclusiveAccess;

		/**
		\~korean
		�� ���� null�� �ƴϸ�, �ܺ� networker thread�� ����մϴ�.
		Proud.CStartLanServerParameter.m_externalNetWorkerThreadPool�� ���� ������ �մϴ�.

		\~english 
		If this value is not null, use an external networker thread. 
		It performs the same role as Proud.CStartLanServerParameter.m_externalNetWorkerThreadPool. 

		\~chinese
		�?����null��?��������ݻnetworker thread��
		���? Proud.CStartLanServerParameter.m_externalNetWorkerThreadPool%��?�����ġ�

		\~japanese
		��������null�ǪϪʪ���С���ݻnetworker thread�����Ī��ު���
		Proud.CStartLanServerParameter.m_externalNetWorkerThreadPool���Ҫ���ܪ򪷪ު���

		\~
		*/
		CThreadPool* m_externalNetWorkerThreadPool;

		/**
		\~korean
		�� ���� null�� �ƴϸ�, �ܺ� user worker thread�� ����մϴ�.
		Proud.CStartLanServerParameter.m_externalUserWorkerThreadPool�� ���� ������ �մϴ�.

		\~english 
		If this value is not null, use an external networker thread.
		It performs the same role as Proud.CStartLanServerParameter.m_externalNetWorkerThreadPool.

		\~chinese
		�?����null��?��������ݻuser worker thread��
		���? Proud.CStartLanServerParameter.m_externalUserWorkerThreadPool%��?�����ġ�

		\~japanese
		��������null�ǪϪʪ���С���ݻuser worker thread�����Ī��ު���
		Proud.CStartLanServerParameter.m_externalUserWorkerThreadPool���Ҫ���ܪ򪷪ު���

		\~
		*/
		CThreadPool* m_externalUserWorkerThreadPool;

		/**
		\~korean DB ó���� ���� ������ Ǯ�� ������ �����Դϴ�.
		- �ּ��� 1�� ���� �Ǿ�� �մϴ�.
		- DB ó���� ���������� device time�� ������ ������ ����� ���� ���� �δ� ���� �����ϴ�. (���� 100��)
		- �ʱⰪ�� 10�Դϴ�. 0�� �����ϸ� CPU ������ �����˴ϴ�.

		\~english It is the number of thread pools for DB processing.
		- At least ��1�� should be set.
		- DB processing has the internal device time, so it is recommended to have many threads. (ex. 100)
		- Initial value is ��10��. If setting ��0��, it will be set as the number of CPUs.

		\~chinese ��??��DB��?���?��??��
		- ������?1.
		- DB?��?ݻ?�� device time�������?������?��?�ᡣ����100?��
		- ���??10. �������?0??�����CPU??��

		\~japanese DB?��Ϊ���Ϋ���ëɫ�?��Ϋ���ëɪ���?�Ǫ���
		- ����ڣ�����Ҫ���ʪ���Ъʪ�ު���
		- DB?���?ݻ�ܪ�device time�������몿�����ª�?�����Ҫ���۰���ު��Ǫ�����?��100����
		- �ǫի���Ȫ�10�Ǫ���0����Ҫ����CPU��?������Ҫ���ު���
		\~
		*/
		int m_dbWorkThreadCount;

		/**
		\~korean DB Cache Server���� DBMS�� Query�� ���� ���� CommandTimeout ���Դϴ�.
		- ������ �ʴ����̰� �ʱⰪ�� 30�� �Դϴ�.

		\~english It is CommandTimeout value when sending Query from DB Cache Server to DBMS.
		- Standard unit is second and default value is 30 seconds.

		\~chinese DB Cache Server�� DBMS?�� Query?�� CommandTimeout ?��
		- ���??�ȣ����??30����

		\~japanese DB Cache Server����DBMS��Query������� CommandTimeout���Ǫ���
		-?�Ȫ���?�Ȫǡ���Ѣ����30���Ǫ���

		\~
		*/
		int m_commandTimeoutSec;

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
		- true�� �����Ǹ� RecursiveUpdate�迭 ��û�� ó�� �� �� �� ��û�� ������� �ϳ��� �����մϴ�.
		- ���ɿ� �ǿ����� ��ġ���� Deadlock�� �����ϱ� ���� �ɼ��Դϴ�. ������ �� �� ���� Deadlock�� �߻� �� ���� ����ϴ� ���� �����մϴ�.
		- �⺻���� false�Դϴ�.

		\~english
		- If set to 'true', each of the request for 'RecursiveUpdate' will be conducted in order.
		- Although it can cause harm to its performance, this is an alternative for deadlock prevention. We recommend you to use only as an option when deadlock occurs with an unknown cause.
		- The default value is ��false��.

		\~chinese
		- ?��?true��?,?��RecursiveUpdate֪ͧ��?ϴ?,������?ϴ��?����??�������
		- ?�������߾?��?�?,ӣʿ��?���Deadlock����?���ǡ���?���?�������������Deadlock?��?����ġ�
		- ��??��ʣ�ܡ�

		\~japanese
		- ture�����Ҫ�����RecursiveUpdate֪ͧ������?�⪹�����������������Ī��������ު���
		- ���Ϋ��׫�����������?��ª���ܪ����Ϫ���ު�����Deadlock����������Ϊ�ΪǪ�����תΪ磌��ʪ�Deadlock��?�檷�����Ϊ����Ī��몳�Ȫ�?�᪷�ު���
		- �ǫի��������false�Ǫ���
		\~
		*/
		bool m_serializeRecursiveUpdateWork;

		/**
		\~korean
		- �� ���� true�̸� Ŭ���̾�Ʈ�� ���� ���� �� �ش� Ŭ���̾�Ʈ�� RequestIsolateData�� ��û�� �����͵��� �ݸ��� �ڵ����� �����մϴ�.
		- �⺻���� true�Դϴ�.

		\~english
		- If this value is true, the client will automatically relieve the isolation of data which requested RequestIsolateData when the client is disconnected.
		- The default value is true.

		\~chinese
		- ����?��̫��true��?, ?��?��??,?��??RequestlsolateData��ϴ��?��̰???���?��𶡣
		- ��??��true��

		\~japanese
		- ���� ���� true�ʪ� ���髤����Ȫ� ��? �������� �� ��? ���髤����Ȫ� RequestIsolateData�� ��몷�� ��?�������� ̰��� ����ܪ� ��𶪷�ު���
		- �ǫի��������true�Ǫ���
		\~
		*/
		bool m_autoDeisolateData;

		CDbCacheServer2StartParameter();
	};

	/**
	\~korean
	<a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_client_server" >DB cache Ŭ���̾�Ʈ�� ����</a> �Դϴ�.

	\~english
	<a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_client_server" >DB cache client and server</a>

	\~chinese
	��<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_client_server" >DB cache��?Ӯ����?��</a>%��

	\~japanese
	\ref dbc2_server �Ǫ���
	\~
	 */
	class CDbCacheServer2
	{
	protected:
		CDbCacheServer2() {}
	public:
		virtual ~CDbCacheServer2() {}

		/**
		\~korean
		���ӵ� Ŭ���̾�Ʈ ���� �����մϴ�.

		\~english
		Return the client is connected

		\~chnese
		Return �?������?Ӯ?��

		\~japanese
		��?���쪿���髤�����?��꫿?�󪷪ު���
		\~
		 */
		virtual intptr_t GetCachingDataTreeCount() = 0;

		/**
		\~korean
		DB cache ���� �ν��Ͻ��� �����մϴ�.

		\~english
		Creates DB cache server instance

		\~chinese
		?��DB cache��?��?�ǡ�

		\~japanese
		DB cache��?��?���󫹫��󫹪��������ު���
		\~
		 */
		PROUDSRV_API static CDbCacheServer2* New();

		/**
		\~korean
		Ŭ���̾�Ʈ�κ����� ������ Ȱ��ȭ�ϰ�, DBMS���� ���� ������ �����մϴ�.
		\param params CDbCacheServer2�� �����ϴµ� �ʿ��� ������ (���� \ref CDbCacheServer2StartParameter)

		\~english TODO:translate needed
		Enable the connection from the client and start the actual connection with DBMS. 
		\param params The configuration value required to start CDbCacheServer2 (refer to \ref CDbCacheServer2StartParameter)

		\~chinese
		̭��?��ʫ��?�ȣ�?�?DBMS��???�ȡ�
		\param param ?� CDbCacheServe2r%�����?��?��?�� \ref CDbCacheServer2StartParameter����

		\~japanese
		���髤����Ȫ������?�����������ơ�DBMS�Ȫ�?���?����㷪��ު���
		\param params CDbCacheServer2����㷪������驪�������(?�� \ref CDbCacheServer2StartParameter)

		\~
		 */
		virtual void Start(CDbCacheServer2StartParameter &params) = 0;

		/**
		\~korean
		Ŭ���̾�Ʈ���� ������ ��� ����, �ϴ� �۾��� ��� ó���Ŀ� �����带 ���� �մϴ�.

		\~english
		Disconnect with all clients, finish all works that in process then close thread.

		\~chinese
		???��ʫ��?�ȣ�?����?������������?�?�

		\~japanese
		���髤����ȪȪ���?�����﷪êơ����êƪ������������?�����˫���ëɪ��������ު���
		\~
		*/
		virtual void Stop() = 0;

		/**
		\~korean
		DB cache client2�κ��� ���� ������ �߰�/����/���� ������ ���� �ĺ��� DBMS�� ����� ������
		����ϴ� �ð��Դϴ�.
		- �ʹ� ª���� DBMS�� �ɸ��� ���ϰ� �����մϴ�.
		- �ʹ� ��� DB cache server�� ������ ����(��: ����)�� ��� DBMS�� ������� ���ϰ� �޸𸮿�
		������̴� �����ʹ� �ҽǵ� Ȯ���� Ŀ���ϴ�.
		\param val �и��� ���� �ð�

		\~english TODO:translate needed
		This is the time to stand by from after receiving the data add/modify/delete content from DB cache client 2 until recording it in DBMS. 
		- If too short, the load on DBMS increases
		- If too long, when the DB cache server terminates abnormally (e.g.: power failure), it cannot record in DBMS and the data waiting in the memory is likely to be lost.  
		\param val Time in millisecond unit

		\~chinese
		?DB cache client2�����ʥ/����/?�?����?����������DBMS??��??��
		- ��ӭ��??DBMS��?��?��ʥ��
		- ��?��?��?ު����?򭣨�ǣ���?��DB cache server��?��������DBMS??����?��������?�������?��?��ʥ��
		\param val ��?��??��

		\~japanese
		DB cache client2�����������?������ʥ/?��/���?黪�������������DBMS����?�������ު��������Ǫ���
		- ���ު�˪�ӭ����DBMS�˪�����ݶ�ê�?ʥ���ު���
		- ���ު�˪�������DB cache server���������(�ǣ����)�������ꡢDBMS����?�Ǫ����˫���?����êƪ�����?���������������㪬�ު����ʪ�ު���
		\param val �߫���?������

		\~
		 */
		virtual void SetDbmsWriteIntervalMs(int64_t val)=0;

		/**
		\~korean
		DB cache client2���� unload�� �����Ͱ� DB cache server �޸𸮿����� ������ ������
		������ ����ϴ� �ð��Դϴ�.
		- �ʹ� ª���� DBMS�� �ɸ��� ���ϰ� �����մϴ�.
		- �ʹ� ��� DB cache server2�� �޸� ��뷮�� Ŀ���ϴ�.
		\param val �и��� ���� �ð�

		\~english TODO:translate needed
		Waiting time that the unloaded data at DB cache client waits until it is fully removed from DB cache memory
		- If this is set too short then the work load to DBMS will increase.
		- If this is set too long then it will increase the amount of memory usage in DB cache server.

		\~chinese
		?DB cache client2 unload��?���DB cache server?�������?�������??��
		- ��ӭ��??DBMS��?��?��ʥ��
		- ��?��?DB cache server2��?��������?ʥ�ޡ�
		\param val ����?��??

		\~japanese
		DB cache client2��unload������?����DB cache server����?�Ǫ��������۪�������ު��������Ǫ���
		- ���ު�˪�ӭ����DBMS�˪�����ݶ�ê�?ʥ���ު���
		- ���ު�˪�������DB cache serve2�Ϋ���?�����᪬�ު����ʪ�ު���
		\param val �߫���?������

		\~
		 */
		virtual void SetUnloadedDataHibernateDurationMs(int64_t val)=0;

		/**
		\~korean
		Proud.CNetServer.SetDefaultTimeoutTimeMs�� ���� ������ �մϴ�.

		\~english
		Performs similar role as Proud.CNetServer.SetDefaultTimeoutTimeMs

		\~chinese
		���? Proud.CNetServer.SetDefaultTimeoutTimeMs%��?�����ġ�

		\~japanese
		Proud.CNetServer.SetDefaultTimeoutTimeMs���Ҫ���ܪ򪷪ު���
		\~
		 */
		virtual void SetDefaultTimeoutTimeMs(int newValInMs) = 0;

		/**
		\~korean
		Proud.CNetServer.SetDefaultTimeoutTimeSec�� ���� ������ �մϴ�.
		\param val �� ���� �ð�

		\~english TODO:translate needed.
		Performs similar role as Proud.CNetServer.SetDefaultTimeoutTimeSec
		\param val

		\~chinese
		���? Proud.CNetServer.SetDefaultTimeoutTimeSec%��?�����ġ�
		\param val ��?��??

		\~japanese
		Proud.CNetServer.SetDefaultTimeoutTimeSec���Ҫ���ܪ򪷪ު���
		\param val ��?������

		\~
		 */
		virtual void SetDefaultTimeoutTimeSec(double newValInSec) = 0;


		/**
		\~korean
		�� DB cache server2�� ���� ���� TCP ������ ������ �ּҸ� ����ϴ�.

		\~english
		Gets the address of TCP listening socket opened by this DB cache server

		\~chinese
		?���DB cache server2��?��TCP�??Ϣ�򣡣
		
		\~japanese
		����DB cache server2���Ҫ����Ǫ���TCP�꫹�˫󫰫����ëȪΫ��ɫ쫹����ު���
		 */
		virtual AddrPort GetTcpListenerLocalAddr() = 0;

		/**
		\~korean
		�� DB cache Server2�� ������ DB Cache Cleint2 �鿡 ���� AddrPort ������ ��´�.
		- �� �޼���� ��� ����� ȣ���� ������ �������� ���̴�.
		�� �Լ��� ���ϵ� �Ŀ��� Ŭ���̾�Ʈ ����� ������ ���� ������ ���¿� �������� ���������� �ʴ´�.
		\param output AddrPort���� ����� ä���� ��

		\~english TODO:translate needed.
		Obtain the AddrPort for the DB Cache Client 2 connected to this DB Cache Server2. 
		- The list obtained by this method is only the snapshot at the time of being called. 
		Even after this function is returned, it does not guarantee that the content of the client list is the same as the status of the actual server. 
		\param output Place where the list of AddrPort will be filled out. 

		\~chinese
		?��?��??DB cache Server2��DB Cache Cleint2��AddrPort?��
		- ��??۰��?������?������У?����snapshot�쫡�
		���?�����������������ʫ��?��?�???��?����??�������ܡ�
		\param output AddrPort����?���?�����۰��

		\~japanese
		����DB cache Server2����?����DB Cache Cleint2�ʪɪ�?����AddrPort������ު���
		- ���Ϋ᫽�ëɪ����꫹�Ȫ����������êΫ��ʫë׫���ëȪǪ�������Ǫ���
		����??���꫿?�󪵪쪿���˪⫯�髤����ȫ꫹�Ȫ�?黪�?𷫵?��?��?��������Ǫ��몳�Ȫ�����몳�ȪϪ���ު���
		\param output AddrPort�Ϋ꫹�Ȫ�?��������
		\~
		*/
		virtual bool GetAllRemoteClientAddrPort(CFastArray<AddrPort> &ret) = 0;


		/**
		\~korean
		- ���� �ε� ��û�� ó���� ��ٸ� ���� �ð��� �����մϴ�.
		- �� ������ ������ �ð� �̳��� �ε� �� ������ ȹ���� �Ϸ���� ������ �ش� ��û�� Ÿ�Ӿƿ����� ���� ó���˴ϴ�.
		- �⺻���� 10���Դϴ�. (10000�и���)
		\param timeoutMs ���� �� �ð� �����Դϴ�. (�и��� ����)

		\~english
		Configure the time limit to wait for the processing of exclusive load request. 
		- If the load and exclusivity acquisition is not completed within the time set with this value, the request is processed as a failure as a timeout. 
		- The default value is 10 seconds (10000 milliseconds)
		\param timeoutMs The time limit to be designated (millisecond unit)

		\~chinese
		- ???ʥ??ϴ?������?������??��
		- �����?����???ڱ����ʥ???��???��??ϴ��?����??�⡣
		- ��???10���� (10000ڰ��)
		\paramtimeoutMs �����������𤡣 (ڰ��?��)

		\~japanese
		- ?￫�?������?�����������������Ҫ��ު���
		- �����������Ҫ��쪿�����?�˫�?�����?�?������������ʪ���С���?���ϫ����ૢ���Ȫ�����?��˪ʪ�ު���
		- ��������10���Ǫ���(10000�߫���)
		\param timeoutMs ��Ҫ���������ڪǪ���(�߫���?��)

		\~
		*/
		virtual void SetUnloadRequestTimeoutTimeMs(int64_t timeoutMs) = 0;

		/**
		\~korean
		- ���� �ε� ��û�� Ÿ�Ӿƿ� �������� �и��� ������ ��ȯ�մϴ�.

		\~english
		Return the timeout configuration value of the exclusive load request in millisecond unit. 

		\~chinese
		- ��??ʥ?��??��???��ڰ��?�ȡ�

		\~japanese
		- ?￫�?�����Ϋ����ૢ������������߫���?�Ȫ��������ު���
		\~
		*/
		virtual int64_t GetUnloadRequestTimeoutTimeMs() const = 0;
	};
	/**  @} */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
#endif