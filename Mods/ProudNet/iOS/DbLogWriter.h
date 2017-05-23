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

#if defined(_WIN32)

#include "AdoWrap.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif

	/** \addtogroup util_group
	*  @{
	*/

	/** 
	\~korean
	LogWriter���� ������ ���� �� ���� �޽����� ���� Ŭ���� �Դϴ�. ��� �Ͽ� �Լ��� ������ �ֽø� �˴ϴ�.
	- CDbLogWriter ������ ���ڷ� �־��ְ� �˴ϴ�.

	\~english
	This class is to receive error message when error occur at LogWriter. You can define function that using inherit.
	- When you creates CDbLogWriter, put it as a factor.

	\~chinese
	�LogWriter��??�����??������?��߾??��?��??ʦ��
	- CDbLogWriter%����?ۯ��?����

	\~japanese
	LogWriter�ǫ���?�˪ʪê���������?��ë�?���������뫯�髹�Ǫ�����?��������??���������ƪ���������
	- CD��LogWriter������������������ƪ���������
	\~
	*/
	class ILogWriterDelegate
	{
	public:
		virtual void OnLogWriterException(Proud::AdoException &Err)=0;	//LogWriterException(exception��ü�� �Ķ���ͷ�)
	};
	
	/** 
	\~korean
	CDbLogWriter ���� ���Ǵ� ����ü

	\~english
	Structure used in CDbLogWriter 

	\~chinese
	� CDbLogWriter%������?��?��

	\~japanese
	CDbLogWriter���Ū���ϰ��?
	\~
	*/
	class CDbLogParameter
	{
	public:
		/** 
		\~korean
		�α� ����� ���� �����ͺ��̽��� �����ϴ� DBMS Connection String�Դϴ�. �ڼ��� ���� <a target="_blank" href="http://guide.nettention.com/cpp_ko#logwriter_db" >�����ͺ��̽��� �α׸� ����ϱ�</a> �� �����Ͻʽÿ�.

		\~english
		DBMS Connection String accesses to DB that log record will be written on. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#logwriter_db" >Recording a log in database</a>.

		\~chinese
		����log??׺����?��?��DBMS Connection String��????��<a target="_blank" href="http://guide.nettention.com/cpp_zh#logwriter_db" >�?��?��??log</a>%��

		\~japanese
		����?��?���?����?���򫢫���������DBMS Connection String�Ǫ����٪����ϡ�\reflogwriter_db��?�Ϊ���������
		\~
		*/
		String m_dbmsConnectionString;
		
		/** 
		\~korean
		�α׸� ����ϴ� ��ü�� �̸��Դϴ�. ���� ��� �� �α׸� ����ϴ� ���μ����� �̸�, ���� "BattleServer #33"�� �����ø� �˴ϴ�.

		\~english
		Name of the subject that writes log. For an example, the name of the process that writes this log, such as "BattleServer #33"

		\~chinese
		??log���?��٣?��������??�log��������٣?��ۯ��"BattleServer #33"?ʦ��

		\~japanese
		������?�����?٣�Ǫ����Ǫ��С����Ϋ�����?����׫�����٣��?��"BattleServer #33"������ƪ���������
		\~
		*/
		String m_loggerName;

		/** 
		\~korean
		�α׸� ����ϴ� DbmsŸ���Դϴ�.MsSql,MySql���� �����մϴ�.

		\~english
		DBMS type that writes log. Supports MSSQL, MySQL and etc.

		\~chinese
		??log��Dbms?������MsSql,MySql ����

		\~japanese
		������?����Dbms�����תǪ���MsSql��MySql�ʪɪ򫵫�?�Ȫ��ު���
		\~
		*/
		DbmsType m_dbmsType;

		/**
		\~korean
		�α� ����� �� DB�� �ִ� �α����̺�� �Դϴ�. default �� DbLog �Դϴ�.

		\~english 
		This is the log table name in the DB to record the log. The default is DbLog. 

		\~chinese
		??log��?�����?DB��log table٣��Default��DbLog��

		\~japanese
		����?�򪹪�DB�˪������?�֫�٣�Ǫ���Default��Dblog�Ǫ���
		\~
		*/
		String m_dbLogTableName;

		PROUD_API CDbLogParameter();
	};


	

	/** 
	\~korean
	DBMS �� �α׸� ����մϴ�. ( <a target="_blank" href="http://guide.nettention.com/cpp_ko#logwriter_db" >�����ͺ��̽��� �α׸� ����ϱ�</a> ����)

	�Ϲ��� �뵵
	- CDbLogWriter �� ����ϱ� ���� ProudNet/Sample/DbmsSchema/LogTable.sql �� �����Ͽ� DbLog ���̺��� �����ؾ� �մϴ�.
	- CDbLogWriter.New �� �Ἥ �� ��ü�� �����մϴ�. 
	- WriteLine, WriteLine �� �Ἥ �α׸� ����մϴ�. ����� �α״� �񵿱�� ����˴ϴ�.
	- �⺻������ LoggerName, LogText, DateTime �� ��ϵ˴ϴ�. ������ ���ϴ� �÷��� �������� WriteLine�� CPropNode �� ����ϸ� �˴ϴ�.

	\~english
	 Write log to DBMS (Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#logwriter_db" >Recording a log in database</a>)

	General usage
	- Before using CDbLogWriter, you must create Dblog table by running ProudNet/Sample/DbmsSchema/LogTable.sql
	- Create this object by using CDbLogWriter.New
	- Record log by using WriteLine, WriteLine. (Note: maybe a typo) The recorded log will be regarded as asynchronous.
	- Basically LoggerName, LogText and DateTime will be recorded. In order to add a column that user wants, use CPropNode of WriteLine

	\~chinese
	��DBMS??log��?�� <a target="_blank" href="http://guide.nettention.com/cpp_zh#logwriter_db" >�?��?��??log</a>��
	
	��������Բ
	- ���� CDbLogWriter%����?��ProudNet/Sample/DbmsSchema/LogTable.sql�������DbLogtable��
	- ���� CDbLogWriter.New%�����?�ڡ�
	- ����WriteLine, WriteLine??log��?����log?����??�ơ�
	- ����???LoggerName, LogText, DateTime����ۯ����?�����??��?����WriteLine�� CPropNode%?ʦ��

	\~japanese
	DBMS�˫�����?���ު���( \ref logwriter_db ?��)

	�����ܪ���Բ
	- CDbLogWriter�����Ī������ProudNet/Sample/DbmsSchema/LogTable.sql��?������DbLog��?�֫���������ʪ���Ъʪ�ު���
	- CDbLogWriter.New ���Ūêƪ��Ϋ��֫������Ȫ��������ު��� 
	- WriteLine��WriteLine���Ūêƫ�����?���ު��������쪿����ު��Ѣ��������ު���
	- �����ܪ�LoggerName, LogText, DateTime����?����ު�����?��?���Ъ૫��������몿��˪ϡ�WriteLine��CPropNode ���Ūêƪ���������
	\~
	*/
	class CDbLogWriter
	{
	protected:
		CDbLogWriter() {} // use CDbLogWriter::New() instead.
	public:
		/** 
		\~korean
		CDbLogWriter �ν��Ͻ��� �����մϴ�.
		\param logParameter �α� ��ϱ��� ������ ���� ���������Դϴ�.
		\param pDelegate �α� ��ϱⰡ ���� �� �ʿ�� �ϴ� �ݹ��� �����ϴ� delegate�Դϴ�.

		\~english
		Create CDbLogWriter instance.
		\param logPramerter Setup value to start log writer.
		\param pDelegate It is delegate for realizing callback that requires during log writer running.

		\~chinese
		���� CDbLogWriter%?�ǡ�
		\param logParameter ?��log???��?���?��?��
		\param pDelegat ??log????�����������?��delegate��

		\~japanese
		CDbLogWriter ���󫹫��󫹪��������ު���
		\param logParameter ����?�����㷪Ϊ�����������Ǫ���
		\param pDelegate ����?�窱?�������驪Ȫ��뫳?��Ыë���?�ު���delegate�Ǫ���
		\~
		*/
		PROUD_API static CDbLogWriter* New(CDbLogParameter& logParameter, ILogWriterDelegate *pDelegate);

		virtual ~CDbLogWriter() {}

		/** 
		\~korean
		�� ���� �α׸� ����մϴ�. 
		- �� �Լ��� �񵿱�� ����˴ϴ�. ��, ��� ���ϵ˴ϴ�.
		\param logText ���� �α� ���ڿ�
		\param pProperties ����ڰ� �߰��� �ʵ忡 �� �����Դϴ�. ��� ���� <a target="_blank" href="http://guide.nettention.com/cpp_ko#logwriter_db" >�����ͺ��̽��� �α׸� ����ϱ�</a> �� �����Ͻʽÿ�.

		\~english
		Records 1 log 
		- this function runs as asynchronous. In other words, it will be returned immediately.
		\param logText log text string
		\param pProperties Values to be entered to the fields that were added by user. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#logwriter_db" >Recording a log in database</a>.

		\~chinese
		??��?log��
		- ���??��?���������?ʦ�ء?���ޡ�
		\param logText log�ݬ����
		\param pProperties ?����?��ʥ��?���?��������??��<a target="_blank" href="http://guide.nettention.com/cpp_zh#logwriter_db" >�?��?��??log</a>%��

		\~japanese
		1���Ϋ�����?���ު���
		- ����??��ު��Ѣ��?������ު���?���������˫꫿?�󪵪�ު���
		\param logText ?�������֪
		\param pProperties ��?��?����ʥ�����ի�?��ɪ��������Ǫ��������Ǫϡ�\ref logwriter_db ��?�Ϊ���������
		\~
		*/
		virtual void WriteLine( String logText, CProperty* const pProperties=NULL) = 0;
	};

	/**  @} */

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif //_WIN32