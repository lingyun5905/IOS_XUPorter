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

#include "PropNode.h"
#include "FakeClrBase.h"

#include "Variant.h"

#ifdef _WIN64
#include "./_x64/msado15.tlh"
#else
#include "msado15.tlh"
#endif

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	// UUID�� string���� ��ȯ�Ǹ� character ��
	static const int UUIDVarcharLength = 38;

	/*
	\~korean
	'#import' ������ ���� ��� tlh, tli�� #include�մϴ�.
	- �̷��� �ؾ� /MP �ɼ��� �� �۵��մϴ�.
	- ���� ������ c:\program files\common files\system\ado�� �߰��ϴ� ���� ���ϴ�.

	\~english
	#include tlh and tli instead of #import syntax.
	- This method makes /MP options to operate better.
	- And user doesn't have to add c:\program files\common files\system\ado.

	\~chinese
	#include tlh ��tli instead����#import ?����
	- ??���?/MP ??������??��
	- ����??����ʥc:\program files\common files\system\ado ��ث?��

	\~japanese
	'#import' ϰ�����Ū��۪���tlh��tli��#include���ު���
	- ���Ϊ誦�˪����/MP���׫���󪬪誯���Ѫ��ު���
	- �ު�����?��?��c:\program files\common files\system\ado����ʥ����ҽ���򪷪ʪ��ƪ��ު��Ǫ���
	\~
	 */

	/** \addtogroup db_group
	*  @{
	 */

	/**
	\~korean
	<a target="_blank" href="http://guide.nettention.com/cpp_ko#ado_overview" >ADO Wrapper API</a> �� ���� ����üĿ
	- �� ��ü�� ����ڰ� ������� �ʽ��ϴ�.���� �뵵�� ���˴ϴ�.

	\~english
	This method monitors and checks delay of <a target="_blank" href="http://guide.nettention.com/cpp_en#ado_overview" >ADO Wrapper API</a>.
	- This object is for the internal purpose only, not usable by user.

	\~chinese
	<a target="_blank" href="http://guide.nettention.com/cpp_zh#ado_overview" >ADO Wrapper API</a>%����?���??��
	- ��?������???��,������?ݻ��Բ��

	\~japanese
	\ref ado_overview��?���������ë�?
	- ���Ϋ��֫������Ȫϫ�?��?���Ū��ު���?ݻ��Բ���Ū��ު���
	\~
	*/
	class CQueryChecker
	{
	protected:
		void	ExecuteBegin();
		void	ExecuteEnd(const PNTCHAR* command);
	protected:
		uint32_t	m_prevTime;
	};

	/**
	\~korean
	\brief DBMS ���ٽ� �̺�Ʈ�� �޴� ��ü�� �������̽� Ŭ�����Դϴ�.
	- ����ڴ� �� �������̽��� ��ӹ޾� �̺�Ʈ�� ��Ƽ�� �޽��ϴ�.
	- <a target="_blank" href="http://guide.nettention.com/cpp_ko#ado_access_tracker" >ADO �۵� �����ϱ�</a> �� �����Ͻʽÿ�.

	\~english
	\brief DBMS Interface class of object that receives event when it access.
	- User inherits this interface and receives notification of event.
	- Refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#ado_access_tracker" >Tracking ADO operation</a> for more details.

	\~chinese
	\brief DBMS����?��������?�����ͣ��?��
	- ��ʫ�����ͣ���������event��
	- ??��<a target="_blank" href="http://guide.nettention.com/cpp_zh#ado_access_tracker" >���ADO??</a>%��

	\~japanese
	\brief DBMS �����������˫��٫�Ȫ������뫪�֫������ȪΫ���?�ի�?�����髹�Ǫ���
	- ��?��?�Ϫ��Ϋ���?�ի�?������?���ƫ��٫�Ȫ���򱪷��᮪��ު���
	- \ref ado_access_tracker��?�Ϊ���������
	
	\~
	 */
	class IDbmsAccessEvent
	{
	public:
		virtual ~IDbmsAccessEvent();

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_  #ado_overview" >ADO Wrapper API</a> �� ���ÿ� �����Ǵ� Ŀ�ǵ带 �߽߰ÿ� �ݹ�˴ϴ�.
		\param lpszcommand ���� Ŀ�ǵ� �Դϴ�. ���� �����̰ų� ���ν��� �̸��Դϴ�.
		\param curtime ������ ����� �ð��Դϴ�.
		\param querytick Ŀ�ǵ带 ����ϴµ� ������ �ð��Դϴ�. (�и��ʴ���)

		\~english
		This method callbacks when it spots any delayed command while using <a target="_blank" href="http://guide.nettention.com/cpp_  #ado_overview" >ADO Wrapper API</a>.
		\param lpszcommand The list of commands in use. They are either in query or procedure name.
		\param curtime The exact time of a delayed command detected.
		\param querytick The delayted time of command being used (in milliseconds).

		\~chinese
		<a target="_blank" href="http://guide.nettention.com/cpp_  #ado_overview" >ADO Wrapper API</a>%����????�����ֵ?�?��?��
		\param lpszcommand ��������٤ֵ��??��������٣?��
		\param curtime ��?????��
		\param querytick ٤ֵ������?��?����??��(����??��)

		\~japanese
		\ref ado_overview����������?�Ū���뫳�ޫ�ɪ�̸�Ī��ê��髳?��Ыë�����ު���
		\param lpszcommand ���Ī��쪿���ޫ�ɪǪ���������?��ϣ���׫�?����٣�Ǫ���
		\param curtime ��򱪵�쪿?��������Ǫ���
		\param querytick ���ޫ�ɪ��Ū�����?�Ū��������Ǫ������߫���?�ȣ�

		\~
		*/
		virtual void OnQueryDelayed(const PNTCHAR* lpszcommand, CPnTime curtime, uint32_t querytick) = 0;
	};

	/**
	\~korean
	<a target="_blank" href="http://guide.nettention.com/cpp_ko#ado_overview" >ADO Wrapper API</a> �� ���ÿ� �̺�Ʈ�� ��Ƽ�ϴ� ��ü�Դϴ�.
	- �������� ���˴ϴ�.
	- <a target="_blank" href="http://guide.nettention.com/cpp_ko#ado_access_tracker" >ADO �۵� �����ϱ�</a> �� �����Ͻʽÿ�.

	\~english
	The main which notifies events while using  <a target="_blank" href="http://guide.nettention.com/cpp_en#ado_overview" >ADO Wrapper API</a>.
	- Can be used globally.
	- Refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#ado_access_tracker" >Tracking ADO operation</a> for more details.

	\~chinese
	<a target="_blank" href="http://guide.nettention.com/cpp_zh#ado_overview" >ADO Wrapper API</a>%����?event������?��
	- ʦ���۰�����ġ�
	- ??�� <a target="_blank" href="http://guide.nettention.com/cpp_zh#ado_access_tracker" >���ADO?? </a>

	\~japanese
	\ref ado_overview ���������˫��٫�Ȫ���򱪹���?�Ǫ���
	- ��洪��Ū��ު���
	- \ref ado_access_tracker ��?�Ϊ���������
	

	\~
	*/
	class CDbmsAccessTracker
	{
		friend CQueryChecker;

		CDbmsAccessTracker();
	public:
		~CDbmsAccessTracker();
		/**
		\~korean
		�̺�Ʈ�� ��Ƽ ���� �������̽��� �����մϴ�.
		\param pEvent �̺�Ʈ�� ��Ƽ���� �������̽��� �������Դϴ�.

		\~english
		This method appoints an interface that will receive notification of event.
		\param pEvent The pointer of interface receiving notification of event.

		\~chinese
		���?�����������ͣ����
		\param pEvent ���������ͣ����??�á�

		\~japanese
		���٫�Ȫ���򱪷��᮪�����?�ի�?������Ҫ��ު���
		\param pEvent ���٫�Ȫ���򱪷��᮪�����?�ի�?���Ϋݫ���?�Ǫ���

		\~
		*/
		static void SetAdoWrapEvent(IDbmsAccessEvent* pEvent);

	private:
		static IDbmsAccessEvent*	m_DbmsAcessEvent;
	public:
		/**
		\~korean
		�������� �̺�Ʈ �ð�
		- <a target="_blank" href="http://guide.nettention.com/cpp_  #ado_overview" >ADO Wrapper API</a> �� ���ÿ� Ŀ�ǵ�(Ȥ�� ����)�� �� �ð��̻��� �����Ǹ� IDbmsAccessEvent�� �̺�Ʈ�� ��Ƽ�մϴ�.
		- �⺻���� 500���� �����Ǿ� �ֽ��ϴ�.

		\~english
		Query delay event time
		- This method notifies event through IDbmsAccessEvent when command(query) is delayed for a specified time as using <a target="_blank" href="http://guide.nettention.com/cpp_  #ado_overview" >ADO Wrapper API</a>.
		- The default time is 500.

		\~chinese
		??��?event??��
		- <a target="_blank" href="http://guide.nettention.com/cpp_  #ado_overview" >ADO Wrapper API</a>%����?��٤ֵ����??��?����??��?�??��?��IDbmsAccessEvent���event��
		- ��??��500��

		\~japanese
		������??�ū��٫������
		- \ref ado_overview ���������˫��ޫ��(�ު��ϫ�����?)�����������߾?�Ū�����IDbmsAccessEvent�˫��٫�Ȫ���򱪷�ު���
		- ��������500�����Ҫ���ƪ��ު���
		\~
		*/
		PROUD_API static uint32_t	DelayedAccessThresholdMilisec;
	};

	enum DbOpenFor { OpenForRead,OpenForFastRead,OpenForReadWrite,OpenForAppend };
	enum DbmsType  { MsSql,MySql};

	class CAdoRecordset;
	class CAdoOfflineRecord;
	class CVariant;

	/**
	\~korean
	<a target="_blank" href="http://guide.nettention.com/cpp_  #ado_overview" >ADO Wrapper API</a> �� DBMS ���� ��ü
	- �������� �� ��ü�� �ξ ���� �����忡�� �����ϴ� ���� �������� ����(���� race condition)�� �߱��մϴ�.
	���� �ʿ��� ������ �� ��ü�� ���� �����μ� �����ؼ� ���� ���� �ٶ����մϴ�. ����, ������ ���ؼ� ���Ḹ �ϰ� �ٸ� �뵵�� ������ �ʴ� ���μ��� ����
	��ü�� �ϳ� �δ� ���� �����ϴ�. �ڼ��� ���� <a target="_blank" href="http://guide.nettention.com/cpp_ko#ado_connect" >ADO�� �����ͺ��̽��� �����ϱ�</a>ion_pooling �� �����Ͻʽÿ�.
	- �� ��ü�� �����ϱ� ����, �ּ� 1ȸ�� CoInitialize�� ȣ���ؾ� �մϴ�.
	�׳� ������ ���� �Լ��� ������ ���� ������ �־�θ� ���� ���Դϴ�.
	\code
	Proud::CCoInitializer coi;
	\endcode
	- DB�� �＼���ϴ� ���� critical section�� �ǵ��� ������ üũ�ϴ� ���: ADODB_RefCriticalSection, ADODB_RecommendCriticalSectionProc

	\~english
	DMBS link object of <a target="_blank" href="http://guide.nettention.com/cpp_  #ado_overview" >ADO Wrapper API</a>

	- If you access other thread with this object, it will occur some problems (e.g. race condition)
	So we recommend to use this object with changing local variable when you needed. However it is better to leave process object without using to improve performance.
	Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#ado_connect" >Accessing database with ADO</a>ion_pooling for more detail.
	- Before creating this object, at least once of Colnitialize must be called.
	It will be much convenient if the following syntax is included in the thread main function.
	\code
	Proud::CCoInitializer coi;
	\endcode
	- Function that checks whether or not critical section has been touched while accessing DB: ADODB_RefCriticalSection, ADODB_RecommendCriticalSectionProc

	\~chinese
	<a target="_blank" href="http://guide.nettention.com/cpp_  #ado_overview" >ADO Wrapper API</a>%��DBMS?��?��
	- ��������?��??��?��������??�����??(��race condition)��
	��󮣬��?�����?�����?������?���??�����������ܡ�?�⣬?����������?׺��?��?��������������Բ���������?�ڡ�??��??��<a target="_blank" href="http://guide.nettention.com/cpp_zh#ado_connect" >��ADO???��?</a>ion_pooling%��
	- �����?������������У���CoInitialize��
	�?�����?����ʥ���?���??۰���ܡ�
	\code
	Proud::CCoInitializer COI;
	\endcode
	- ?��DB��?��?��?critical section������������ADODB_RefCriticalSection �� ADODB_RecommendCriticalSectionProc

	\~japanese
	\ref ado_overview��DBMS֧̿���֫�������
	- ��洪˪��Ϋ��֫������Ȫ��Ǫ�����?�Ϋ���ëɪ�ꫢ���������몳�Ȫ�??����𹣨�Ǫ��С�race condition�����ڪ��ê����ު�����êơ���驪������Ȫ˪��Ϋ��֫������Ȫ��?����??�����������Ū��Ϊ��Ъު����Ǫ�����۰�������Ϊ������?�����򪷪������Բ�Ǫ��Ū��ʪ��׫�����洪Ϋ��֫������Ȫ�����Ǫ���۰���ު��Ǫ����٪�����\ref ado_connection_pooling��?�Ϊ���������
	- ���Ϋ��֫������Ȫ�����������ˡ����1�ު�CoInitialize����������驪�����ު�������������ëɪΫ᫤��??���Ϊ誦��ϰ����������Ǫ������תǪ���
	\code
	Proud::CCoInitializer coi;		
	\endcode
	- DB�򫢫�����������˪�critical section��?��ʪ��ȫ����ë�����Ѧ����ADODB_RefCriticalSection��ADODB_RecommendCriticalSectionProc 
	\~
	 */
	class CAdoConnection:public ADODB::_ConnectionPtr,protected CQueryChecker
	{
		// Execute���� ����ϴ� �Ҵ� �޸𸮾�
		const static size_t SQLTEXTLEN = 12800;

		//CAdoConnectionPool* m_connectionPool; // NULL�̸� connection pool�� ���� �ʰ� ������ �ǹ��Ѵ�.
	public:
		PROUD_API CAdoConnection(ADODB::_Connection *conn);
		//CAdoConnection(CAdoConnectionPool* connectionPool);
		PROUD_API CAdoConnection();
		PROUD_API ~CAdoConnection();
	private:
		// ���� ����. ADODB COM smartptr�� �����ϰ� ������, ���� �� �Լ��� dtor���� close�� �ϱ� ������.
		CAdoConnection& operator=(const CAdoConnection&);
		CAdoConnection(const CAdoConnection&);
	public:
		/**
		\~korean
		DB�� �����Ѵ�. ADODB.Connection�� Ȯ���� ����� ���� �ִ�.
		\param pszConnStr DBMS ���� ���ڿ�
		- ADO DB connection string �Ծ��� ������. �ڼ��� ���� <a href="http://www.connectionstrings.com/" target="_blank">http://www.connectionstrings.com/</a> ����.
		- Driver Ȥ�� Provider�� ���� �ʴ´ٸ�,sqloledb�� provider�� ����Ѵ�.
		�Ʒ��� �� ���̴�.
		\code
		Data Source=.;Database=ProudDB-Test;Trusted_Connection=yes // .�� �����, localhost�� ���� �� ��. �Ϻ� �Ŀ��� ���� ���� ������ �̾���.
		Data Source=.;Database=ProudDB-Test;user id=xxx;password=yyy
		\endcode

		\param AppName SQL Server Enterprise Manager���� ǥ�õǴ� �̸�. connection�� �̸��� Ư�� ��ƾ�� �ǹ��ϴ� �̸��� �߰��ϰ� ������ �̰� ������ ����� ���� ������ �� �� ������ �ȴ�. �� ������ ���õȴ�.

		\~english
		This method connects to DB. It has a function that expanse ADODB.Connection.
		\param pszConnStr DBMS link string
		- It follows the rule of ADO DB connection string. Refer to <a href="http://www.connectionstrings.com/" target="_blank">http://www.connectionstrings.com/</a> for more details.
		- If Driver or Provider is not included, use sqloledb as provider.
		Below is an example.
		\code
		Data Source=.;Database=ProudDB-Test;Trusted_Connection=yes // use . instead of localhost. using localhost causes connection error in some computers.
		Data Source=.;Database=ProudDB-Test;user id=xxx;password=yyy
		\endcode

		\param AppName Name being displayed on SQL Server Enterprise Manager. This method helps detecting dead-lock when adding a name that points to a specific routine to the name of connection. If you don't insert this method, this will be ignores.

		\~chinese
		?����DB��?��?�� ADODB.Connection ��������
		\param pszConnStr DBMS?���ݬ��
		- ����ADO DB connection string??��????�� <a href="http://www.connectionstrings.com/" target="_blank">http://www.connectionstrings.com/</a> ��
		- ?��Driver���Provider��?����sqloledb����provider��
		����������?����
		\code
		Data Source=localhost;Database=ProudDB-Test;Trusted_Connection=yes
		Data Source=localhost;Database=ProudDB-Test;user id=xxx;password=yyy
		\endcode

		\param AppName �SQL ServeEnterprise Manager?����٣?�����connection��٣�߾��ʥ��ګ�����routine����?٣����ʥ???�??��?����?�����?𾡣����ʥ��??�����ԡ�

		\~japanese
		DB��֧̿���롣ADODB.Connection��?�媷��Ѧ�����êƪ��ު���
		\param pszConnStr DBMS֧̿���֪
		- ADO DB connection string Ю峪�?���ު����٪�����<a href="http://www.connectionstrings.com/" target="_blank">http://www.connectionstrings.com/</a>��?�Ϊ���������
		- Driver�ު���Provider������ʪ���С�sqloledb��provider�Ȫ����Ū��ު���
		�������ǪǪ��� 
		\code
		Data Source=.;Database=ProudDB-Test;Trusted_Connection=yes // .���Ūêơ�localhost���Ū�ʪ����ȡ���ݻ�Ϋ���ԫ�?��?�Ǫ�֧̿�����Ϋ���?�˪Īʪ���ު���
		Data Source=.;Database=ProudDB-Test;user id=xxx;password=yyy
		\endcode
		\param AppName SQL Server Enterprise Manager�����ƪ����٣��Connection��٣������ҪΫ�?�������ګ����٣�����ʥ����������ϡ�����������Ыǫëɫ�ë��ʪɪ���򱪹������𾪫��ު�������ʪ�������ʪ���ު��� 

		\~
		 */
		PROUD_API void OpenEx(const PNTCHAR* pszConnStr, const PNTCHAR* AppName);

		/**
		\~korean
		DB�� �����Ѵ�. �ڼ��� ���� OpenEx ���� ����
		\param pszConnStr DB Connection String

		\~english
		This method connects to DB. Refer to OpenEx guideline for more details.
		\param pszConnStr DB Connection String

		\~chinese
		?����DB��??��??��OpenEx?𾡣
		\param pszConnStr DB Connection String

		\~japanese
		DB��֧̿���ު����٪����ϡ�OpenEx��ث�ת�?�Ϊ���������
		\param pszConnStr DB Connection String

		\~
		*/
		inline void Open(const PNTCHAR* pszConnStr)
		{
			OpenEx(pszConnStr,0);
		}

		/**
		\~korean
		DB�� �����Ѵ�. ADODB.Connection�� Ȯ���� ����� ���� �ִ�.
		\param pszConnStr DBMS ���� ���ڿ�
		- ADO DB connection string �Ծ��� ������. �ڼ��� ���� <a href="http://www.connectionstrings.com/" target="_blank">http://www.connectionstrings.com/</a> ����.
		�Ʒ��� �� ���̴�.
		\code
		Data Source=.;Database=ProudDB-Test;Trusted_Connection=yes // .�� �����, localhost�� ���� �� ��. �Ϻ� �Ŀ��� ���� ���� ������ �̾���.
		Data Source=.;Database=ProudDB-Test;user id=xxx;password=yyy

		//MySql
		Driver={MySQL ODBC 5.1 Driver};server=xxx.xxx.xxx.xxx;port=3306;Database=TableName;User ID=UserID;Password=yyy;
		\endcode

		\param AppName SQL Server Enterprise Manager���� ǥ�õǴ� �̸�. connection�� �̸��� Ư�� ��ƾ�� �ǹ��ϴ� �̸��� �߰��ϰ� ������ �̰� ������ ����� ���� ������ �� �� ������ �ȴ�. �� ������ ���õȴ�.
		\param Type DbmsType������ enum���� �ֽ��ϴ�.MsSql,MySql���� �ֽ��ϴ�.(MsSql�� ���������� sqloledb Provider�� ����ϰ� �ֽ��ϴ�.)

		\~english TODO:translate needed.
		This method connects to DB. It has a function that expans ADODB.Connection.
		\param pszConnStr DBMS link string
		- It follows the rule of ADO DB connection string. Refer to <a href="http://www.connectionstrings.com/" target="_blank">http://www.connectionstrings.com/</a> for more details.
		Below is one example.
		\code
		Data Source=.;Database=ProudDB-Test;Trusted_Connection=yes // .�� �����, localhost�� ���� �� ��. �Ϻ� �Ŀ��� ���� ���� ������ �̾���.
		Data Source=.;Database=ProudDB-Test;user id=xxx;password=yyy

		//MySql
		Driver={MySQL ODBC 5.1 Driver};server=xxx.xxx.xxx.xxx;port=3306;Database=TableName;User ID=UserID;Password=yyy;
		\endcode

		\param AppName Name being displayed on SQL Server Enterprise Manager. This method helps detecting dead-lock when adding a name that points to a specific routine to the name of connection. It ignores if you don't insert this method.
		\param Type This inserts enum value of DbmsType such as for Sql,MySql and etc.(MsSql internally uses sqloledb Provider.)

		\~chinese
		?����DB��?��?�� ADODB.Connection ��������
		\param pszConnStr DBMS?���ݬ��
		- ����ADO DB connection string??��????�� <a href="http://www.connectionstrings.com/" target="_blank">http://www.connectionstrings.com/</a> ��
		����������?����
		\code
		Data Source=localhost;Database=ProudDB-Test;Trusted_Connection=yes
		Data Source=localhost;Database=ProudDB-Test;user id=xxx;password=yyy

		//MySql
		Driver={MySQL ODBC 5.1 Driver};server=xxx.xxx.xxx.xxx;port=3306;Database=TableName;User ID=UserID;Password=yyy;
		\endcode

		\param AppName �SQL ServeEnterprise Manager?����٣?�����connection��٣�߾��ʥ��ګ�����routine����?٣����ʥ???�??��?����?�����?𾡣����ʥ��??�����ԡ�
		\param Type ۯ��DbmsType������enum?����.MsSql��MySql ������MsSql ?ݻ����sqloledb Provider����

		\~japanese
		DB��֧̿���ު���ADODB.Connection��?�媹��Ѧ�����êƪ��ު���
		\param pszConnStr DBMS֧̿���֪
		- ADO DB connection string Ю峪�?���ު����٪����ϡ� <a href="http://www.connectionstrings.com/" target="_blank">http://www.connectionstrings.com/</a>��?�Ϊ���������
		�������ǪǪ���
		\code
		Data Source=.;Database=ProudDB-Test;Trusted_Connection=yes // .���Ūêơ�localhost���Ū�ʪ����ȡ���ݻ�Ϋ���ԫ�?��?�Ǫ�֧̿��������?�˪Īʪ���ު���
		Data Source=.;Database=ProudDB-Test;user id=xxx;password=yyy

		//MySql
		Driver={MySQL ODBC 5.1 
		Driver};server=xxx.xxx.xxx.xxx;port=3306;Database=TableName;User ID=UserID;Password=yyy;
		\endcode

		\param AppName SQL Server Enterprise Manager�����ƪ����٣��Connection��٣������ҪΫ�?�������ګ����٣�����ʥ����������ϡ�����������Ыǫëɫ�ë��ʪɪ���򱪹������𾪫��ު�������ʪ�������ʪ���ު��� 
		\param Type DbmsType������enum��������ު���MsSql,MySql�ʪɪ�����ު���(MsSql��?ݻ�ܪ�sqloledb Provider�����Ī��ƪ��ު���)

		\~
		*/
		PROUD_API void OpenEx(const PNTCHAR* pszConnStr, const PNTCHAR* AppName, DbmsType Type);

		/**
		\~korean
		DB�� �����Ѵ�. �ڼ��� ���� OpenEx ���� ����
		\param pszConnStr DB Connection String
		\param type

		\~english
		This method connects to DB. Refer to OpenEx guideline for more details.
		\param pszConnStr DB Connection String

		\~chinese
		?��DB��??��??��OpenEx?𾡣
		\param pszConnStr DB Connection String
		\param type

		\~japanese
		DB����?���ު����٪����ϡ�OpenEx�Ϋث�ת�?�Ϊ���������
		\param pszConnStr DB Connection String
		\param type
		(���ޣ���\param type�� ש��)

		\~
		*/
		inline void Open(const PNTCHAR* pszConnStr, DbmsType Type)
		{
			OpenEx(pszConnStr,0,Type);
		}

		/**
		\~korean
		ADODB�� �ݽ��ϴ�.

		\~english
		ADODB will be closed.

		\~chinese
		??ADODB

		\~japanese
		ADODB���ͪ��ު���
		\~
		*/
		PROUD_API void Close();

		/**
		\~korean
		ADODB�� �ݽ��ϴ�.
		- throw�� �߻���Ű�� �ʽ��ϴ�

		\~english
		ADODB will be closed.
		- throw will not occur.

		\~chinese
		??ADODB��
		- ��??��throw��

		\~japanese
		ADODB���ͪ��ު���
		- throw��?�檵���ު���
		\~
		*/
		PROUD_API void Close_NoThrow();

		/**
		\~korean
		ADO ��ü�� DB ������ ����ƴ���?
		\return ���� �����ϸ� true�� �����ϰ�, �����ϸ� false�� �����մϴ�.

		\~english
		 Is ADO object connected to DB server?
		\return true if it succeed to connect DB;false if it failed to connect DB

		\~chinese
		ADO ?������?DB��?��?�ȣ�
		\return ?��������?����true����?����false��

		\~japanese
		ADO���֫������Ȫ�DB��?��?�˪Īʪ��êƪ��ު�����
		\return ֧̿���������true��꫿?�󪷪ơ����������false��꫿?�󪷪ު���
		\~
		*/
		PROUD_API bool IsOpened();

		/**
		\~korean
		SQL ������ �����Ѵ�. printf()ó�� ��� ����.
		\param lpszSQL ���� ����
		\return stored procedure�� ���� ������� record�� ����, ������� ���� ���ų� ���н� 0, Select �����̸� -1 ����

		\~english
		Executes SQL syntax. Can use as printf().
		\param lpszSQL SQL syntax
		\return Number of records affected by stored procedure; 0 if no rows were affected or the statement failed; and -1 for SELECT statements

		\~chinese
		?��SQL?ϣ��?printf()��?ʦ����ġ�
		\param lpszSQL SQL ?ϣ
		\return ��stored procedure���?��record��??��?�����?���������??��0��Select ?ϣ��?����-1��

		\~japanese
		SQLϰ����?�����ު���printf()�Ϊ誦������ʦ���Ǫ���
		\param lpszSQL ������?ϰ��
		\return stored procedure�˪�ê���ª��쪿record��?����ª������������ʪ��Ȫ�������0��Selectϰ���Ǫ����-1��꫿?��
		\~
		  */
		PROUD_API long Execute(const PNTCHAR* lpszSQL);

		/**
		\~korean
		SQL ������ �����մϴ�.����� outputRecords�� ����˴ϴ�.
		\param outRecordset �޾ƿ� ��� ���ڵ��.
		\param lpszSQL ���� ����
		\return stored procedure�� ���� ������� record�� ����, ������� ���� ���ų� ���н� 0, Select �����̸� -1 ����

		\~english
		Executes SQL syntax. The result gets stored at outputRecords.
		\param outRecordset Recordset of results to get.
		\param lpszSQL SQL syntax
		\return Number of records affected by stored procedure; 0 if no rows were affected or the statement failed; and -1 for SELECT statements

		\~chinese
		?��SQL?ϣ��?��?����outputRecords��
		\param outRecordset �����Recordset?��
		\param lpszSQL SQL ?ϣ
		\return ��stored procedure���?��record��??��?�����?���������??��0��Select ?ϣ��?����-1��

		\~japanese
		SQLϰ����?�����ު���̿����outputRecords��������ު���
		\param outRecordset ����������̿���쫳?�ɫ��ëȡ�
		\param lpszSQL ������?ϰ��
		\return stored procedure�˪�ê���ª��쪿record?����ª��쪿�����ʪ���������0��Selectϰ���Ǫ����-1��꫿?��
		\~
		 */
		PROUD_API long Execute(CAdoRecordset& outputRecords, const PNTCHAR* lpszSQL);

		/**
		\~korean
		DB Ʈ������� �����մϴ�.

		\~english
		DB transaction begins

		\~chinese
		DB transaction ��?�

		\~japanese
		DB�ȫ�󫶫���������㷪��ު���
		\~
		  */
		inline void BeginTrans() {  (*this)->BeginTrans(); }

		/**
		\~korean
		DB Ʈ����� �ѹ�

		\~english
		DB transaction rollback

		\~chinese
		DB transaction ����?

		\~japanese
		DB�ȫ�󫶫�������?��Ыë�
		\~
		  */
		inline void RollbackTrans() {  (*this)->RollbackTrans(); }

		/**
		\~korean
		DB Ʈ����� Ŀ��

		\~english
		 DB transaction commit

		\~chinese
		DB transaction �����

		\~japanese
		DB�ȫ�󫶫�����󫳫߫ë�
		\~
		  */
		inline void CommitTrans() {  (*this)->CommitTrans(); }
	private:
	};

	extern CriticalSection* ADODB_RefCriticalSection;

	typedef void(*ADODB_RecommendCriticalSectionProc_t)( const PNTCHAR* text );
	extern ADODB_RecommendCriticalSectionProc_t ADODB_RecommendCriticalSectionProc;

	/**
	\~korean
	ADO Recordset Ŭ���� + ��� ��� ���

	�뵵
	- CAdoConnection �� ȥ���Ѵ�.

	\~english
	 ADO Recordset class + some enhanced functions

	Use
	- Use this method with CAdoConnection.

	\~chinese
	ADO Recordset ?+??������?

	��Բ
	- ? CAdoConnection%���ġ�

	\~japanese
	ADO Recordset���髹�����Ī�����Ѧ����߾
	��Բ
	- CAdoConnection�����Ī��ު���
	\~
	  */
	class CAdoRecordset:public ADODB::_RecordsetPtr,protected CQueryChecker
	{
	public:
		PROUD_API CAdoRecordset();

		inline CAdoRecordset(ADODB::_Recordset *rc)
		{
			if(rc)
				Attach(rc,true);		// AddRef, not Attach
		}

		inline ~CAdoRecordset()
		{
			Close_NoThrow(); // �̰� �ִ� ������ ~CAdoConnection()�� ��������. �ݵ�� �־�� ��.
		}

		inline CAdoRecordset& operator=(ADODB::_Recordset *rc)
		{
			if(rc)
				Attach(rc,true);

			return *this;
		}
	private:
		// ���� ����. ADODB COM smartptr�� �����ϰ� ������, ���� �� �Լ��� dtor���� close�� �ϱ� ������.
		CAdoRecordset& operator=(const CAdoRecordset&);
		CAdoRecordset(const CAdoRecordset&);
	public:

		// various ways of accessing bind data

/*		inline void GetFV(bool& value,LPCWSTR pszFieldName)
		{ value=GetInterfacePtr()->GetCollect(pszFieldName); }

		inline void SetFV(LPCWSTR pszFieldName,bool value)
		{ GetInterfacePtr()->PutCollect(pszFieldName,value); }

		inline void GetFV(long& value,LPCWSTR pszFieldName)
		{ value=GetInterfacePtr()->GetCollect(pszFieldName); }

		inline void SetFV(LPCWSTR pszFieldName,long value)
		{ GetInterfacePtr()->PutCollect(pszFieldName,value); }

		inline void GetFV(float& value,LPCWSTR pszFieldName)
		{ value=GetInterfacePtr()->GetCollect(pszFieldName); }

		inline void SetFV(LPCWSTR pszFieldName,float value)
		{ GetInterfacePtr()->PutCollect(pszFieldName,value); }

		inline void GetFV(DATE& value,LPCWSTR pszFieldName)
		{ value=GetInterfacePtr()->GetCollect(pszFieldName); }

		inline void SetFV(LPCWSTR pszFieldName,DATE value)
		{ GetInterfacePtr()->PutCollect(pszFieldName,value); }

		inline void GetFV(String &value,LPCWSTR pszFieldName)
		{ value=(LPCWSTR)(_bstr_t)GetInterfacePtr()->GetCollect(pszFieldName); }

		inline void SetFV(LPCWSTR pszFieldName,LPCWSTR value)
		{ GetInterfacePtr()->PutCollect(pszFieldName,value); } */

		PROUD_API bool GetFieldValue(const PNTCHAR* pszFieldName, String &var);
		PROUD_API bool GetFieldValue(const PNTCHAR* pszFieldName, UUID &var);
		PROUD_API bool GetFieldValue(const PNTCHAR* pszFieldName, CPnTime &var);

		PROUD_API CVariant GetFieldValue(const PNTCHAR* pszFieldName);
		PROUD_API void SetFieldValue(const PNTCHAR* pszFieldName, const CVariant &value);

		PROUD_API CVariant GetFieldValue(int index);
		PROUD_API void SetFieldValue(int index,const CVariant &value);

		/**
		\~korean
		�ʵ��� ���� �а� ����.
		- �Ķ���ͷ� CVariant�� ���Ƿ� ��� Ÿ���� �����͵��� �а� �� �� �ִ�.
		- �迭 ���ڷ� �ʵ� ���ڿ��̳� 0 based �ε��� ���ڸ� �� �� �ִ�.

		\~english
		Reads and writes field value.
		- It can read and write just about any type of data since it use CVariant as parameter.
		- It can use field string or 0 based index number as array factor.

		\~chinese
		???���?��
		- ��??? CVariant%�������??����?����?�ߡ�
		- ����֪���???��ݬ�����0 base����?�ߡ�

		\~japanese
		�ի�?�������?�������ު���
		- �ѫ��?��?�Ȫ���CVariant���Ū��ު��Ϊǡ��ɪΫ����תΫ�?����?�������Ǫ��ު���
		- ��֪���Ȫ��ƫի�?��ɪ����֪��0 based����ǫë���?���������Ȫ��Ǫ��ު���
		\~
		*/
#if defined (_MSC_VER)
		__declspec(property(get=GetFieldValue,put=SetFieldValue)) CVariant FieldValues[];
#endif

		PROUD_API _bstr_t GetFieldNames(int index);

		/**
		\~korean
		�ʵ��� �̸��� ��´�.
		- �迭 ���ڷ� 0 based �ε��� ���ڸ� �� �� �ִ�.

		\~english
		This method obtain name of field.
		- It can use 0 based index number as an array factor.

		\~chinese
		?��?���٣?��
		- ����֪���?��0 based����?��

		\~japanese
		�ի�?���٣������?�ߪު���
		- ��֪����0 based����ǫë���?���Ū����Ȫ��Ǫ��ު���
		\~
		*/
#if defined (_MSC_VER)
		__declspec(property(get=GetFieldNames)) _bstr_t FieldNames[];
#endif
		/**
		\~korean
		ADODB�� �ݽ��ϴ�.

		\~english
		ADODB will be closed.

		\~chinese
		??ADODB��

		\~japanese
		ADODB���ͪ��ު���
		\~
		*/
		PROUD_API void Close();

		/**
		\~korean
		ADODB�� �ݽ��ϴ�.
		- throw�� �߻���Ű�� �ʽ��ϴ�

		\~english
		ADODB will be closed.
		- throw will not occur.

		\~chinese
		??ADODB��
		- ��??��throw��

		\~japanese
		ADODB���ͪ��ު���
		- throw��?�檵���ު���
		\~
		*/
		PROUD_API void Close_NoThrow();

		/**
		\~korean
		���ڵ��� ������ Ȯ���մϴ�.
		\return ���̸� true �ƴϸ� false

		\~english TODO:translate needed.
		Check whether this is the end of the record
		\return If it is the end, then true, otherwise false. 

		\~chinese
		??������record��������
		\return ?����?true��������?false��

		\~japanese
		�쫳?�ɪ���Ӯ�Ϊ������㪷�ު���
		\return ��Ӯ�Ǫ����true��false
		\~
		*/
		inline bool IsEOF()
		{
			return GetInterfacePtr()->adoEOF?true:false;
		}

		/**
		\~korean
		ADODB�� open�������� Ȯ���մϴ�.
		\return open �����̸� true, close �����̸� false

		\~english TODO:translate needed.
		Check whether ADODB is in open status. 
		\return If open, true. If close, false. 

		\~chinese
		??ADODB������open??��
		\return open??��?true��close ??��?false��

		\~japanese
		ADODB��open?���ʪΪ������㪷�ު���
		\return open?���Ǫ����true��close?���Ǫ����false
		\~
		*/
		PROUD_API bool IsOpened();

		/**
		\~korean
		DbmsSave�Լ��� ���Ͽ� ����� �����͸� ������Ʈ ��ŵ�ϴ�.

		\~english TODO:translate needed.
		Through DbmsSave function, update the saved data


		\~chinese
		��?DbmsSave��?��������?��?�ߡ�

		\~japanese
		DbmsSave??���ת������쪿��?���򫢫ë׫�?�Ȫ����ު���
		
		\~
		*/
		PROUD_API void Update();

		/**
		\~korean
		���ο� �����͸� �߰��� ���� �����մϴ�.

		\~english TODO:translate needed.
		Reserve to add new data


		\~chinese
		??��ʥ����?�ߡ�

		\~japanese
		�檷����?������ʥ���몳�Ȫ���峪��ު���
		\~
		*/
		PROUD_API void AddNew();

		/**
		\~korean
		�����͸� �����մϴ�.

		\~english TODO:translate needed.
		Get rid of data


		\~chinese
		?�?�ߡ�

		\~japanese
		��?������۪��ު���
		\~
		*/
		PROUD_API void Delete();

		/**
		\~korean
		Recordset�� ����.
		\param conn DB ���� ��ü
		\param openFor OpenForRead: �б� ����, OpenForReadWrite, OpenForAppend: �б�/����. ���� �����󿡼� �뵵�� ����ȭ�� ���̴�.
		\param lpszSQL ���� ����.

		\~english
		This method opens Recordset.
		\param conn DB Link Object
		\param openFor OpenForRead: Read Only, OpenForReadWrite, OpenForAppend: Read/Write. The most optimized values for game server use.
		\param lpszSQL Query Syntax.

		\~chinese
		��?Recordset��
		\param conn DB?��?��
		\param openFor OpenForRead:?����?��OpenForReadWrite, OpenForAppend:?/?����?��?������Բ��?����?��
		\param lpszSQL SQL?ϣ��

		\~japanese
		Recordset���Ҫ���
		\param conn DB֧̿���֫�������
		\param openFor OpenForRead��?������?�ġ�OpenForReadWrite, OpenForAppend��?������/����?�ߡ���?�૵?��?߾����Բ�����������쪿���Ǫ��� 
		\param lpszSQL ������?ϰ��
		\~
		*/
		PROUD_API void Open(ADODB::_Connection *conn, DbOpenFor openFor, const PNTCHAR* lpszSQL);

		/**
		\~korean
		Recordset�� ����.
		\param conn DB ���� ��ü
		\param cursorType ADODB::CursorTypeEnum
		\param lockType ADODB::LockTypeEnum
		\param lpszSQL ���� ����.

		\~english
		This method opens Recordset.
		\param conn DB Link Object
		\param cursorType ADODB::CursorTypeEnum
		\param lockType ADODB::LockTypeEnum
		\param lpszSQL Query Syntax.

		\~chinese
		��?Recordset��
		\param conn DB?��?��
		\param cursorType ADODB::CursorTypeEnum
		\param lockType ADODB::LockTypeEnum
		\param lpszSQL SQL?ϣ��

		\~japanese
		Recordset���Ҫ�
		\param conn DB֧̿���֫�������
		\param cursorType ADODB::CursorTypeEnum
		\param lockType ADODB::LockTypeEnum		
		\param lpszSQL ������?ϰ��
		
		\~
		*/
		PROUD_API void Open(ADODB::_Connection *conn, ADODB::CursorTypeEnum cursorType, ADODB::LockTypeEnum lockType, const PNTCHAR* lpszSQL);

		/**
		\~korean
		��� parameter�� default value�� �Ͽ� ����.
		ADO command���� return�� recordset object�� open�� �� ���� �� �ִ�.

		\~english
		This method opens all parameters as default value.
		This can be used when opening recordset object returned by ADO command.

		\~chinese
		�������parameter?�default value��?��
		ʦ����?ADO commandreturn��recordset object��?��ʦ����ġ�

		\~japanese
		��ƪ�parameter��default value�˪����Ҫ��ު���
		ADO command��return����recordset object��open���������Ū��몳�Ȫ��Ǫ��ު���
		\~
		*/
		PROUD_API void Open(void);

		/**
		\~korean
		ADODB::adOpenStatic Ÿ���� Cursor �� recordset �� ����.
		ADO command���� return�� recordset object�� open�� �� ���� �� �ִ�.

		\~english
		This method opens all parameters as default value.
		This can be used when opening recordset object returned by ADO command.

		\~chinese
		��ADODB::adOpenStatic ?����cursor��?recordset��
		ʦ����?ADO commandreturn��recordset object��?�����ġ�

		\~japanese
		ADODB::adOpenStatic �����ת�Cursor��recordset���Ҫ��ު���
		ADO command��return����recordset object��open���������Ū��몳�Ȫ��Ǫ��ު���
		\~
		*/
		PROUD_API void OpenForUpdate();

		/**
		\~korean
		\param src \ref CAdoOfflineRecord�� �ִ� key���� value���� ���ʷ� �����ؿɴϴ�.

		\~english TODO:translate needed.
		The key value and the value in \param src \ref CAdoOfflineRecord is copied one by one. 


		\~chinese
		\param src ���?�\ref CAdoOfflineRecord%��key?��value?��

		\~japanese
		\param src \ref CAdoOfflineRecord�˪���key����value�������˫���?���ƪ��ު���
		\~
		*/
		PROUD_API void CopyFrom(CAdoOfflineRecord &src);
		const static int defaultCacheSize=100;

		/**
		\~korean
		���� ���ڵ�� Ŀ���� �ű��.

		\~english
		This method moves cursor to the next record.

		\~chinese
		����?�?������?record߾��

		\~japanese
		�Ϋ쫳?�ɪ˫�?�����칪��ު���
		\~
		 */
		PROUD_API void MoveNext();

		/**
		\~korean
		ó�� ���ڵ�� Ŀ���� �ű��.

		\~english
		This method moves cursor to the initial record

		\~chinese
		����?�?�����record߾��

		\~japanese
		�����Ϋ쫳?�ɪ˫�?�����칪��ު���
		\~
		 */
		PROUD_API void MoveFirst();

		/**
		\~korean
		���� ���ڵ�� Ŀ���� �ű��.

		\~english
		This method moves cursor to the previous record

		\~chinese
		����?�?��߾��?record߾��

		\~japanese
		���Ϋ쫳?�ɪ˫�?�����칪��ު���
		\~
		 */
		PROUD_API void MovePrevious();

		/**
		\~korean
		 ������ ���ڵ�� Ŀ���� �ű��.

		\~english
		This method moves cursor to the last record.

		\~chinese
		����?�?��������?record߾��

		\~japanese
		�����Ϋ쫳?�ɪ˫�?�����칪��ު���
		\~
		 */
		PROUD_API void MoveLast();

		/**
		\~korean
		���� ���ڵ������ �̵��մϴ�.
		- ���� ���ڵ���� �ڱ��ڽſ��� �Ҵ��մϴ�.
		\param recordsAffected ������ ������ ���� ���ڵ� ����

		\~english
		This method moves to the next recordset.
		- Assign the next recordset to itself.
		\param recordsAffected Number of records being affected by query

		\~chinese
		�?������?recordset��
		- ������?recordset����?�����
		\param recordsAffected ��SQL�?��record??

		\~japanese
		�Ϋ쫳?�ɫ��ëȪ���Ѫ��ު���
		- �Ϋ쫳?�ɫ��ëȪ���������ܪ�?�ƪު���
		\param recordsAffected ������?�˪�ê���ª��������쫳?��?
		\~
		 */
		PROUD_API bool MoveNextRecordset(long *recordsAffected = NULL);
		/**
		\~korean
		���� ���ڵ���� �ٸ� �ν��Ͻ����� �Ѱ��ݴϴ�.
		\param outRecordset ���� ���ڵ���� �Ѱܹ��� ���ڵ�� �ν��Ͻ�
		\param recordsAffected ������ ������ ���� ���ڵ� ����

		\~english
		This method passes the next recordset to a different instance.
		\param outRecordset Recordset instance which will receive the next recordset
		\param recordsAffected Number of records being affected by query

		\~chinese
		������?recordset?����instance
		\param outRecordset ��������?recordset��recordset instance
		\param recordsAffected ��query�?��recordset??

		\~japanese
		�Ϋ쫳?�ɫ��ëȪ���Ϋ��󫹫��󫹪��ڪ�Ԥ���ު���
		\param outRecordset �Ϋ쫳?�ɫ��ëȪ��ڪ�Ԥ���쫳?�ɫ��ëȪΫ��󫹫���
		\param recordsAffected ������?�˪�ê���ª��������쫳?��?
		\~
		 */
		PROUD_API void NextRecordset(OUT CAdoRecordset& outRecordset,OUT long *recordsAffected=NULL);
	};

	/**
	\~korean
	ADO Command object�� wrapping�� Ŭ�����̴�.

	�̰����� stored procedure�� ȣ���ϴ� ����� ������ ����.
	- Prepare�� ȣ���� stored procedure, active connection�� �����Ѵ�.
	- Parameters ����� �Է� �ƱԸ�Ʈ�� �����Ѵ�.
	- Execute�� �غ�� stored procedure�� ȣ���Ѵ�.
	- Parameters ����� ��� �ƱԸ�Ʈ�� ���Ѵ�.

	\~english
	This is a class wrapping ADO Command object.

	How to call stored procedure with this method is shown in below.
	- Set stored procedure and active connection to call as Prepare.
	- Set input arguments with Parameters member.
	- Call already prepared stored procedure with Execute.
	- Get output argument with Parameters member.

	\~chinese
	��ADO Command object wrapping��?��
	��??��Уstored procedure��۰��������
	- ?����prepare������stored procedure, active connection��
	- ��parameters��??��?��arguments��
	- ���� ��У��execute��?��stored procedure��
	- ��parameter��??��arguments��


	\~japanese
	ADO Command object��wrapping�������髹�Ǫ���
	�����stored procedure��������۰�������ת�Ǫ���
	- Prepare��������stored procedure, active connection�����Ҫ��ު���
	- Parameters ����?��������?������Ȫ����Ҫ��ު���
	- Execute�����᪵�쪿stored procedure�������󪷪ު���
	- Parameters ����?��������?������Ȫ�ϴ��ު���

	Example
	\code
	CAdoConnection db;
	db.Open(L"Data Source=.;Database=ProudDB-Test;Trusted_Connection=yes");
	CAdoCommand co;
	co.Prepare(db,L"pn_sum");
	co.Parameters[1]=1L;
	co.Parameters[2]=2L;
	co.Execute();
	long x=co.Parameters[3]; 
	\endcode 

	\~
	*/
	class CAdoCommand:public ADODB::_CommandPtr,protected CQueryChecker
	{
	public:
		PROUD_API CAdoCommand(ADODB::_Command *conn);
		PROUD_API CAdoCommand();
	private:
		// ���� ����. ADODB COM smartptr�� �����ϰ� ������, ���� �� �Լ��� dtor���� close�� �ϱ� ������.
		CAdoCommand& operator=(const CAdoCommand&);
		CAdoCommand(const CAdoCommand&);
	public:

		/**
		\~korean
		stored procedure�� ȣ���� �غ� �Ѵ�. ��, ADO Connection, stored procedure name, inout argument �غ� �Ѵ�.
		\param connection
		\param storedProcName

		\~english
		This method sets ready to call stored procedure. Meaning, it prepares ADO Connection, stored procedure name and inout argument.
		\param connection
		\param storedProcName

		\~chinese
		��?��Уstored procedure��?��?ADO Connection, stored procedure name, inout argument��
		\param connection
		\param storedProcName

		\~japanese
		stored procedure������������򪷪ު���?����ADO Connection, stored procedure name, inout argument ����򪷪ު���
		\param connection
		\param storedProcName
		\~
		*/
		PROUD_API void /*FASTCALL */ Prepare(ADODB::_Connection* connection, const PNTCHAR* storedProcName, ADODB::CommandTypeEnum cmdType = ADODB::adCmdStoredProc);

		/**
		\~korean
		PrepareSP�� �����Ǿ��� stored procedure�� �����Ѵ�.
		\param recordsAffected stored procedure�� ���� ������� record�� ����

		\~english
		Execute the appointed stored procedure at PrepareSP.
		\param recordsAffected Number of records affected by stored procedure

		\~chinese
		?����PrepareSP�����stored procedure��
		\param recordsAffected ��stored procedure�?��record��??��

		\~japanese
		PrepareSP����Ҫ��쪿stored procedure��?�����ު���
		\param recordsAffected stored procedure�˪�ê���ª�������record?
		\~
		  */
		PROUD_API void /*FASTCALL */ Execute(OUT long *recordsAffected=NULL);

		/**
		\~korean
		PrepareSP�� �����Ǿ��� stored procedure�� �����Ѵ�.
		\param outRecordset �޾ƿ� ��� ���ڵ��.
		\param recordsAffected stored procedure�� ���� ������� record�� ����

		\~english
		Execute the appointed stored procedure at PrepareSP.
		\param outRecordset Recordset of results to get.
		\param recordsAffected Number of records affected by stored procedure

		\~chinese
		?����PrepareSP�����stored procedure��
		\param outRecordset ���?����recordset
		\param recordsAffected ��stored procedure�?��record??

		\~japanese
		PrepareSP����Ҫ��쪿stored procedure��?�����ު���
		\param outRecordset����������̿���Ϋ쫳?�ɫ��ë�
		\param recordsAffected stored procedure�˪�ê���ª�������record��?
		\~
		  */
		PROUD_API void /*FASTCALL */ Execute(OUT CAdoRecordset& outRecordset,OUT long *recordsAffected=NULL);


		/**
		\~korean
		index�� ����Ű�� ��°�� paramter ���� ���Ѵ�. PrepareSP�� ȣ���� �Ŀ� ����� �� �ִ�.
		\return ���ϵǴ� parameter ��.
		\param index ���° parameter�� ���� ���� ���ΰ�?
		0�� stored procedure�� return value��, ������ parameter�� 1-based index�̴�.

		\~english
		Get parameter value of nth pointed by index. This can be used after PrepareSP is called.
		\return Returned parameter value.
		\param Which nth of parameter value do you want to get?
		0 is return value of stored procedure and the res of parameters are 1-based index.

		\~chinese
		index �����n?paramter?������PrepareSP��ʦ����ġ�
		\return ������parameter?
		\param index ���ϴ�??parameter��?��
		0��stored procedure��return value�������parameter��1-based index��

		\~japanese
		\~
		*/
		PROUD_API CVariant /*FASTCALL */ GetParam(int index);

		/**
		\~korean
		index�� ����Ű�� ��°�� parameter ���� �����Ѵ�. PrepareSP�� ȣ���� �Ŀ� ����� �� �ִ�.
		\param index ���° parameter�� ���� ������ ���ΰ�?
		0�� stored procedure�� return value��, ������ parameter�� 1-based index�̴�.
		\param value ������ paramter ��

		\~english
		This method sets value of nth parameter pointed by index. It can be used after PrepareSP is called.
		\param index Which nth parameter value do you want to set?
		0 is return value of stored procedure and the res of parameters are 1-based index.
		\param value Setting paramter value

		\~chinese
		?��index�����n?paramter?������ УPrepareSP��ʦ����ġ�
		\param index �?���??parameter��?��
		0��stored procedure��return value�������parameter��1-based index��
		\param value �?����parameter?

		\~japanese
		index��򦪹paramter����ϴ��ު���PrepareSP�������󪷪������Ū����Ȫ��Ǫ��ު���
		\return�꫿?�󪵪��parameter��
		\param index �����ͪ�parameter����ϴ��ު����� 
		0��stored procedure��return value��?��parameter��1-based index�Ǫ���
		\~

		**NOTE** This function is very slow because of executing an additional stored procedure for getting procedure information.
		It is not recommended to use this function. The workaround is to use AppendParameter() instead.
		*/
		PROUD_API void /*FASTCALL */ SetParam(int index,const CVariant &value);
#if defined (_MSC_VER)
		__declspec(property(get=GetParam,put=SetParam)) CVariant Parameters[];
#endif
		/**
		\~korean
		parameter ���� ���δ�.MsSQL������ ���� ���� ���� ������, MySQL������ SetParam��� �� �޼ҵ带 ����ؾ� �Ѵ�.
		\return ������� _ParameterPtr
		\param paramName ȣ���� ���ν����� parameter�� �̸�
		\param paramType �������� Ÿ�� ADODB::DataTypeEnum ����.
		\param paramDirection �������� �� ���� ADODB::ParameterDirectionEnum ����.(MySQL�� adParamInput�� ��������.output ���� ����)
		\param defaultValue ���� ���ν����� ���޵� ��

		\~english
		Add parameter value. This is not commonly used in MsSQL, but this method must be used in MySQL instead of SetParam.
		\return Created _ParameterPtr
		\param paramName Name of parameter procedure to call for
		\param paramType Refer to Data Type ADODB::DataTypeEnum
		\param paramDirection Refer to Data insertion direction ADODB::ParameterDirectionEnum.(MySQL must use adParamInput only. Output is not supported.)
		\param defaultValue Value that will be passed to the actual procedure

		\~chinese
		��?parameter?��?���MsSQL�������ģ��MySQL������۰��?����SetParam��
		\return ?����_ParameterPtr
		\param paramName ���У������parameter��٣?
		\param paramType ?��?��?��ADODB::DataTypeEnum
		\param paramDirection ?��?��������?��ADODB::ParameterDirectionEnum����MySQL ����?��adParamInput������output��
		\param defaultValue ????��������?��

		\~japanese
		parameter������������ު���MsSQL�Ǫ�ܬ���Ū��몳�Ȫ�����ު��󪬡�MySQL�Ǫ�SetParam���۪��˪��Ϋ᫽�ëɪ��Ū�ʪ���Ъʪ�ު���
		\return �ª�쪿_ParameterPtr
		\param paramName �����󪹫׫�?�����parameter٣
		\param paramType ��?���Ϋ����� ADODB::DataTypeEnum ?��
		\param paramDirection ��?������������ ADODB::ParameterDirectionEnum ?��(MySQL��adParamInput�Ϊߪ��Ū�����驪�����ު���Output�ϫ���?�Ȫ���ު���)
		\param defaultValue ?�˫׫�?�����?��쪿��
		\~
		*/
		PROUD_API ADODB::_ParameterPtr /*FASTCALL */ AppendParameter(const PNTCHAR* paramName, ADODB::DataTypeEnum paramType, ADODB::ParameterDirectionEnum paramDirection, const CVariant &defaultValue);

		/**
		\~korean
		���� �޼ҵ� ����
		\param defaultValue ���� ���ν����� ��Ʈ�� ��

		\~english
		Refer to the same method
		\param defaultValue String value of the actual procedure

		\~chinese
		?����٣۰��
		\param defaultValue ������??�ݬ��?

		\~japanese
		��٣�᫽�ë�?��
		\param defaultValue ?�׫�?����˫��ȫ����
		\~
		*/
		PROUD_API ADODB::_ParameterPtr /*FASTCALL */ AppendParameter(const PNTCHAR* paramName, ADODB::DataTypeEnum paramType, ADODB::ParameterDirectionEnum paramDirection, const PNTCHAR* defaultValue);
		PROUD_API ADODB::_ParameterPtr /*FASTCALL */ AppendParameter(ADODB::DataTypeEnum paramType, ADODB::ParameterDirectionEnum paramDirection, const PNTCHAR* defaultValue);

		/**
		\~korean
		���� �޼ҵ� ���� �ٸ�, ���������� _variant_t�� ��

		\~english
		Refer to the same method but internally _variant_t will be added

		\~chinese
		?����٣۰����ӣ?ݻ?��_variant_t��

		\~japanese
		��٣�᫽�ë�?�Ρ�ӣ����?ݻ�ܪ�_variant_t������ު���
		\~
		*/
		PROUD_API ADODB::_ParameterPtr /*FASTCALL */ AppendParameter(const PNTCHAR* paramName, ADODB::DataTypeEnum paramType, ADODB::ParameterDirectionEnum paramDirection);

		/**
		\~korean
		���� �޼ҵ� ����
		\param defaultValue ���� ���ν����� ��Ʈ�� ��
		\param length ��Ʈ���� �ִ� ����

		\~english
		Refer to the same method
		\param defaultValue String value of the actual procedure
		\param length The maximum length of string

		\~chinese
		?����٣۰��
		\param defaultValue ������??�ݬ��?
		\param length �ݬ��������?��

		\~japanese
		��٣�᫽�ë�?��
		\param defaultValue ?�׫�?����˫��ȫ����
		\param length ���ȫ�󫰪���������
		\~
		*/
		PROUD_API ADODB::_ParameterPtr /*FASTCALL */ AppendParameter(const PNTCHAR *paramName, ADODB::DataTypeEnum paramType, ADODB::ParameterDirectionEnum paramDirection, const PNTCHAR* defaultValue, long length);

		/**
		Convenient function for AppendParameter.
		*/
		ADODB::_ParameterPtr AppendInputParameter(const PNTCHAR *paramName, const Guid& value);

		ADODB::_ParameterPtr AppendReturnValue();

	private:
		void WarnIfParameterHasProblem();
	};

	/**
	\~korean
	ADO Record�� field ���뿡�� ����� �纻 ��ü
	ADO record�� close�ϰ� ������ �� ������ ����� �� �����ϴ�.
	ADO recordset�� field�� �纻�� ī���ϵ�, ���� recordset�� close�ص� �б� �＼�� ������
	�� �� �ִ� ADO object�� �����ϸ�, �װ��� �� Ŭ���� ������� �ᵵ �ǰ�����, ������ �����
	�׷��� ���� �����Ƿ� �� Ŭ������ ��� �������.
	MSSQL server�� Ư����, field name�� case insensitive�̴�.

	\~english
	ven after closing ADO Record, its copy ADO Record is useful
	when using the field contetns contained within.
	If there is ADO object containing copied contents of recordset
	that can be read even after its source recordset is closed,
	you may use that method but since its performance is not guaranteed,
	the below class has been made.
	Due to the characterics of MSSQL server, field name must be case insensitive.

	\~chinese
	�ADO Record��field?���?�������?��
	??ADO Record���?ʦ�������������??黡�
	�� ?��ADO Record������?�ԣ�ӣ��??���recordset�ʦ?ADDobject���������?��
	�����������?��?������������??ण���������???��
	MSSQL server ������߾��field name ��case insensitive��

	\~japanese
	ADO Record��field?黪�ꫳ��?���쪿����?���֫�������
	ADO record��close���ƪ���⪽��?黪��Ū��������ĪǪ���
	ADO recordset��field�Ϋ���?�򫳫�?���ު��������recordset��close���ƪ�?�����ꫢ�������۪ɪϪǪ���ADO object�������С�����򪳪Ϋ��髹���۪����Ūêƪ��ު��Ǫ�������������?���쪿��Ϊ��ʪ��Ϊǡ����Ϋ��髹���۪����ª�ު�����
	MSSQL server���������顢field name��case insensitive�Ǫ���
	\~
	  */
	class CAdoOfflineRecord:public CProperty
	{
	public:
		/**
		\~korean
		���� recordset�� ����Ű�� cursor���� 1���� record�� �����Ѵ�.
		���� recordset�� cursor���� ������ ��ġ�� �ʴ´�.
		\param src  ���� recordset

		\~english
		Copy one record of the source recordset pointed by cursor.
		This does not cursor of the source recordset.
		\param src  Source recordset

		\~chinese
		���recordset����cursor߾?���?record��
		��?���recordset��cursor�ʥ�?��
		\param src ���recordset

		\~japanese
		���recordset��򦪹cursor��1����record�򫳫�?���ު���
		���recordset��cursor�˪���ª���ܪ��ު���
		\param src ��� recordset
		\~
		*/
		PROUD_API void CopyFrom(CAdoRecordset &src);

		inline CAdoOfflineRecord()
		{
		}

		inline CAdoOfflineRecord& operator=(CAdoRecordset& source)
		{
			CopyFrom(source);
			return *this;
		}
		inline CAdoOfflineRecord(CAdoRecordset& source)
		{
			CopyFrom(source);
		}
	};

	/**
	\~korean
	CAdoRecordset�� DBMS���� ������ ������ ä�� ���ڵ带 �����ϴµ�, �̿� �޸� CAdoOfflineRecordset��
	DBMS���� ������ ���� ä�� ���ڵ带 �����ϰ� ���ݴϴ�.
	�̸� ���� CAdoRecordset���κ��� IterateAndCopyFrom �Ǵ� IterateAndAppendFrom�� ���� ���ڵ� ������ �纻��
	�� ��ü�� ������ �� �ֽ��ϴ�.

	�� ��ü�� Ȱ���ϸ�, ���� ���, DBMS���� ���� �����ð��� �ּ�ȭ�ϴ� DBMS ���ٹ��� �����ϰ� ���ݴϴ�.

	�� ��ü�� CAdoOfflineRecord�� �迭 ��ü�Դϴ�.

	����: ToVariant(), ToLongLong() ���� ����. Windows 2000 ���� ���� �����̴�.

	\~english
	CAdoRecordset accesses record as maintaining the connection with DBMS
	while CAdoOfflineRecordset can do so without being connected DBMS.
	In order for this, you can save the copy of record through or
	IterateAndAppendFrom from CAdoRecordset as an object.
	This object can help minimizing the connection duration time of DBMS as accessing DBMS.

	This object is an array object of CAdoOfflineRecord.

	CAUTION: Refer to ToVariant(), ToLongLong(). This issue could arise in OS below than Windows 2000.

	\~chinese
	CAdoRecordset ��?�?DBMS��?������?������record��?������� CAdoOfflineRecordset%��?��?DBMS��?������?������record��
	?��??? CAdoRecordset%��IterateAndCopyFrom�����?IterateAndAppendFrom��record?���?����?���?�ڡ�
	�����?����?�������������?DBMS��?������??��DBMS������??ʦ����
	�?���� CAdoOfflineRecord%����֪?�ڡ�
	���?��ToVariant(), ToLongLong()?٥����Windows 2000�����???��

	\~japanese
	CAdoOfflineRecordset��DBMS�Ȫ�֧̿���ʪ�?���ǫ쫳?�ɪ򫢫������Ǫ���誦�˪��ު���
	���Ϊ���ˡ�CAdoRecordset����IterateAndCopyFrom�ު���IterateAndAppendFrom���ת����쫳?��?黪Ϋ���?�򪳪Ϋ��֫������Ȫ������몳�Ȫ��Ǫ��ު���
	���Ϋ��֫������Ȫ����Ī���ȡ��Ǫ��С�DBMS�Ȫ�֧̿����������������DBMS��������۰����ʦ���˪��ު���
	���Ϋ��֫������Ȫ�CAdoOfflineRecord����֪���֫������ȪǪ���
	�����ToVariant(), ToLongLong()��?٥��?�Ϊ���������Windows 2000����Ǫ�?֧���Ǫ���
	\~
	*/
	class CAdoOfflineRecordset:public CFastArray<CAdoOfflineRecord>
	{
	public:

		/**
		\~korean
		source�� ��� ���ڵ带 �����ؿɴϴ�.
		���簡 ������ source�� cursor�� EOF�� �˴ϴ�.
		\param source  ���� recordset

		\~english
		This method copies all records of source.
		When copying is done, cursor of source becomes EOF.
		\param source  Source recordset

		\~chinese
		?�source�����record��
		?�?����?source��cursor??��EOF��
		\param source ���recordset

		\~japanese
		source����ƪΫ쫳?�ɪ򫳫�?���ƪ��ު���
		����?������ê��顢source��cursor��EOF�˪ʪ�ު���
		\param source  ��� recordset
		
		\~
		*/
		PROUD_API void IterateAndCopyFrom(CAdoRecordset &source);

		/**
		\~korean
		source�� ��� ���ڵ带 �� ��ü�� ���� ���ڵ���� �������� �߰��մϴ�.
		���簡 ������ source�� cursor�� EOF�� �˴ϴ�.
		\param source  ���� recordset

		\~english
		Add all records of source to the last line of existing records within this object.
		When copying is done, cursor of source becomes EOF.
		\param source  Source recordset

		\~chinese
		��source�����record��ʥ���?�������record��������
		?�?����?source��cursor??��EOF��

		\~japanese
		source����ƪΫ쫳?�ɪ򪳪Ϋ��֫������Ȫ�?��쫳?�ɪ���������ʥ���ު���
		����?������ê���source��cursor��EOF�˪ʪ�ު���
		\param source  ��� recordset
		\~
		*/
		PROUD_API void IterateAndAppendFrom(CAdoRecordset &source);
	};

	// Disconnected Recordset - Sample Source //
	// ���� ������ ���ڵ�� - ���� �ҽ� //
	/*
	try
	{
	ADODB::_RecordsetPtr spRS(__uuidof(ADODB::Recordset));
	ADODB::_ConnectionPtr spConn(__uuidof(ADODB::Connection));

	// Connect and get recordset.
	spConn->Open(OLESTR("dsn=SQLServer"),OLESTR("sa"),
	OLESTR(""), -1);

	spRS->CursorLocation = ADODB::adUseClient;
	spRS->Open(OLESTR("select * from Table1"),
	spConn.GetInterfacePtr(),
	ADODB::adOpenForwardOnly, ADODB::adLockBatchOptimistic, -1);

	// Disassociate the connection from the recordset.
	spRS->PutRefActiveConnection(NULL);

	// Change the value.
	spRS->Fields->Item[0L]->Value = OLESTR("NewValue");

	// Re-connect.
	spRS->PutRefActiveConnection(spConn);

	// Send updates.
	spRS->UpdateBatch(ADODB::adAffectAll);

	spRS->Close();
	spConn->Close();

	}
	catch( _com_error e)
	{
	// Do Exception handling.
	}
	*/

	struct ExecuteSQLAsyncParam
	{
		String connectionString,stmt;
	};

	/**
	\~korean
	src���ڿ� ���� "'"���ڴ� ���۵��� ������ �� �ֱ� ������ "''"�� �ٲپ� �ݴϴ�.

	\~english TODO:translate needed.

	\~chinese
	Src �ݬ��?��"'"���ʦ��??��ͺ���?"''"��

	\~japanese
	src���֪?��"'"���ϡ�����Ѫ��ڪ��ê���ʦ���������몿�ᡢ"''"���ڪ������ު���
	\~
	*/
	PROUD_API String gds(const PNTCHAR *src);

	PROUD_API void RecommendNoCriticalSectionLock();

	/**
	\~korean
	�� ��ü�� ���� ������ ���� �ִ� ������ ������� DB�� �＼���ϴ� �߿� critical section�� lock�Ǿ� �ִ� �ϴ��� ��� ǥ�ø�
	�����ϰ� �Ѵ�. �Ұ��������� �󵵰� �ſ� ���� DB ������ �����ϱ� ���ؼ� �� Ŭ������ �� �� �ִ�.

	����:
	- �̰� �������� ����. DB ������ �����ϴ°��̴ϸ�ŭ ���� ����ȭ �������� �̰� ������ ���� �߿��� ������ �� ã�� �� �ִ�.
	- ���� �����θ� �� ��ü�� ������ �� �ִ�.

	\~english
	Thread holding this object as a loval variable ignores warning notice even though critical section is locked as accessing DB.
	This class can be used to ignore DB bottleneck that is inevitable but low in frequency of use.

	CAUTION:
	- DO NOT USE THIS TOO MUCH. Setting to ignore DB bottleneck can cause serious issues such as skipping important DB bottleneck in the process of server optimization.
	- This object can be created only by local variable.

	\~chinese
	���?��?��?���????��?����?��DB��?��?ηcritical section��lock���?��?��ͱ?򤡣?����ʦ����?����??��?���DB??��ʦ������?��
	���
	- ����?���?����?����?DB??�����?��?��?����ʦ����????���������??��
	- �������??��ʦ������?�ڡ�

	\~japanese
	���Ϋ��֫������Ȫ��?����??���êƪ���?���Ϋ���ëɪϡ�DB�򫢫������������critical section����ë�����ƪ���Ȫ��ƪ���ͱ���ƪ����ʪ���誦�˪ʪ�ު��������𪺪�޺���ΪȪƪ��DB�Ϋܫëȫ�ͫë������ʪ��몿��˪��Ϋ��髹���Ū����Ȫ��Ǫ��ު���
	�����
	- �����ս�Ī��ʪ����ȡ�DB�ܫëȫ�ͫëȪ����ʪ��몳�ȪʪΪǡ���?��?��������Φ��ǪϪ��쪬��ת˪ʪê���驪ʫܫëȫ�ͫëȪ�̸�Ī����ʪ����ꪬ����ު���
	- ��?����??�ΪߪǪ��Ϋ��֫������Ȫ��������몳�Ȫ��Ǫ��ު���
	\~
	   */
	class CAdoDBTemporaryBottleneckCheckDisabler
	{
	public:
		PROUD_API CAdoDBTemporaryBottleneckCheckDisabler();
		PROUD_API ~CAdoDBTemporaryBottleneckCheckDisabler();
	};

	/**
	\~korean
	ProudDB ������ �߻��Ǵ� ���� ��ü
	- ���� �߻� �� ILogWriterDelegate::OnLogWriterException�Լ��� ���Ͽ� CallBack������ �� �ֽ��ϴ�.
	- AdoException::what()�Լ��� ���Ͽ� �߻��� ������ String�� ������ �� �ֽ��ϴ�.

	\~english TODO:translate needed.
	Error object that could occur as running ProudDB
	-When a problem occurs, you can get it called back using ILogWriterDelegate::OnLogWriterException function
	-Through - AdoException::what() function, you can get the string of what has occurred. 

	\~chinese
	ProudDB ?��??����???��
	- ???��?��?ILogWriterDelegate::OnLogWriterException ��?����CallBack��
	- ��? AdoException::what()%��?ʦ�����?��?���String��

	\~japanese
	ProudDB ?�����?�檹�뫨��?���֫�������
	- ��𹪬?������ILogWriterDelegate::OnLogWriterException??���ת���?��Ыë����������ު���
	- AdoException::what()??���ת�?�檷��?黪�String����몳�Ȫ��Ǫ��ު���
	
	\~
	  */
	class AdoException:public Exception
	{
	public:
		/**
		\~korean
		ProudDB�� ADO�� ���� �ִ�. ProudDB�� ���� ADO�� _com_error�� ���ܷ� �����µ�
		�װ��� ���⿡ ����.

		\~english
		ProudDB uses ADO. ADO of ProudDB throws _com_error as exception
		which gets stored in here.

		\~chinese
		ProudDB ��ADO�� ProudDB ������ADO�������_com_error����?????�졣

		\~japanese
		ProudDB��ADO���Ūêƪ��ު���ProudDB���Ū�ADO��_com_error������Ȫ������ު��������쪬����������ު���
		\~
		  */
		_com_error m_comError;

		PROUD_API AdoException(const PNTCHAR *txt, _com_error &e);
	};





	/**  @}  */


}

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif //_WIN32
