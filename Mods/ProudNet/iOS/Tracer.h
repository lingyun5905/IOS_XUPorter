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
#include "PNString.h"
#include "Enums.h"

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
	Tracer.h ������ Include�ؾ� �մϴ�.
	���Ͽ� �α׸� ����ϴ� ����Դϴ�. ( <a target="_blank" href="http://guide.nettention.com/cpp_ko#write_pidl" >PIDL ���� �ۼ��ϱ�</a>  ����)

	�Ϲ��� �뵵
	- CLogWriter.New �� �Ἥ �� ��ü�� �����մϴ�. ������ ������ �α� ���� �̸��� ���ο� ������ ���� ���μ��� �����մϴ�.
	- WriteLine, WriteLine�� �Ἥ �α׸� ����մϴ�. ����� �α״� �񵿱�� ���Ͽ� ����˴ϴ�.

	\~english
	 Module that records log to a file (Refer <a target="_blank" href="http://guide.nettention.com/cpp_en#write_pidl" >Making a PIDL file</a> )

	General usage
	- Use CLogWriter.New to create this object. Designates log file name when created.
	- Use WriteLine, WriteLine to record log. Saved log is saved in file as asynchronous.

	\~chinese
	������??log��ټ?����?�� <a target="_blank" href="http://guide.nettention.com/cpp_zh#write_pidl" >?��PIDL����</a>��

	������Բ
	- ���� CLogWriter.New%�����?�ڡ�������?������������log����٣���?������������?��
	- ����WriteLine, WriteLine??log��������log�ު�����������������졣

	\~japanese
	Tracer.h�ի������Include���ʪ���Ъʪ�ު���
	�ի�����˫�����?����⫸��?��Ǫ�����\ref logwriter_file?�ţ�

	�����ܪ���Բ
	- CLogWriter.New���Ūêƪ��Ϋ��֫������Ȫ��������ު�������������������ի�����٣���檷���ի�������ª�髤��?����Ҫ��ު���
	- WriteLine, WriteLine���Ūêƫ�����?���ު��������쪿����ު��Ѣ�ǫի�����������ު���
	\~
	*/
	class CLogWriter
	{
	public:
		enum eLogType
		{
			eLogTypeNewFile = 0,
			eLogTypeDefault,
			eLogTypeUserDefine
		};
	
		/** 
		\~korean
		\brief �� CLogWriter ��ü�� �����մϴ�.
		\param logFileName �α� ���� �̸�
		\param newFileForLineLimit �α� �� ���� ���⼭ ������ �� �̻����� Ŀ���� �� �α� ���Ͽ� ����ϱ� �����մϴ�. 0�̸� �������Դϴ�.
		\param putFileTimeString true�� �����ϸ� ���ϸ� ���� �ð�����(�����Ͻú���)�� �ٿ� ���ϸ� �ߺ��� �����մϴ�.

		\~english TODO:translate needed.
		\brief Generate a new CLogWriter object.
		\param logFileName log file name. 
		\param newFileForLineLimit If the number of the log lines gets bigger than the designated value her, then it starts recording in a new log file. It is limitless if 0.
		\param putFileTimeString If set as ��true��, the current time information (year/month/date/hour/minute/second) is added to prevent duplication of file names. 

		\~chinese
		\brief �������� CLogWriter%?�ڡ�
		\param logFileName log����٣��
		\param newFileForLineLimit log��?���?�����?������?��?�??���������졣

		\~japanese
		\brief �檷��CLogWriter���֫������Ȫ��������ު���
		\param logFileName ���ի�����٣
		\param newFileForLineLimit ����?����������Ҫ������߾���ު����ʪ���檷�����ի��������?��㷪�ު���0�Ǫ��������ڪǪ���
		\param putFileTimeString true����Ҫ���ȫի�����٣�������������(Ҵ����������)��Ī��ƫի�����٣���ܪ���򭪷�ު���
		\~
		*/
		PROUD_API static CLogWriter* New(const String& logFileName, unsigned int newFileForLineLimit = 0, bool putFileTimeString = true);

	protected:
		CLogWriter(); // CLogWriter::New()�� ��� ����ϼ���!

	public:
		virtual ~CLogWriter();

		/** 
		\~korean
		�α� ������ �ٸ� �̸����� �ٲߴϴ�. ��� ���̴� ������ ������ �ٸ� �̸����� �ٲ� ���Ϸ� ���� �����ϴ�. 
		- �� �Լ��� �񵿱�� ����˴ϴ�.  ��, ��� ���ϵ˴ϴ�.
		- ���� �α� ������ �ٸ� �̸����� �ٲٴ� ���� �����ϸ� �� �Լ��� ������ �������� �ʽ��ϴ�. �� ��� �α׸� ����ϴ� �Լ��� 
		����� �� Proud.Exception ���ܰ� �߻��� ���Դϴ�. 
		\param logFileName �� �α� ���� �̸� 

		\~english
		The log file is changed to another name. The file being recorded is closed and opens newly as a file changed to a different name.
		- This function is executed asynchronously. In other words, it is returned immediately. 
		- If the log file fails to change to a different name, this function does not return the error. Instead, Proud.Exception exception will occur when the function to record the log is used. 
		\param logFileName New log file name

		\~chinese
		�������������?����٣?��??��������?��??����?��?����٣?�����졣 
		- ���?ު����?����?��ء?���ޡ�
		- �������������٣?������?��?������??�� ӣ��������??��???��Proud.Exception���⡣ 
		\paramlogFileName ���������٣? 

		\~japanese
		���ի������٣���?�ڪ��ު�����?���ƪ����ի�������ͪ��ơ�?�ڪ��쪿٣��Ϋի����몬�檿���Ҫ���ު���
		- ����??��ު��Ѣ��?������ު���?���������˫꫿?�󪵪�ު���
		- �⪷�����ի������٣��?�ڪ����������顢����??�ϫ���?��꫿?�󪷪ު��󡣪����۪��˫�����?����??���Ū�����Proud.Exception���⪬?�檷�ު���
		\param logFileName �檷�����ի�����٣
		\~
		*/
		virtual void SetFileName(const String& logFileName) = 0;

		/** 
		\~korean
		�α� ������ ProudNet ��Ŀ� ���� ���Ͽ� ����մϴ�.
		- �� �Լ��� �񵿱�� ����˴ϴ�. ��, ��� ���ϵ˴ϴ�.
		 -�� �Լ��� �Ʒ� ����ó�� ���� ��� �˴ϴ�. 
		  logWriteLineTime: logLevel / logCategory(logHostID): logMessage {logFunction(logLine)}
		\param logLevel �α� ������ �ɰ���
		\param logCategory � ������ �α�����?
		\param logHostID �� �α׸� ������ ȣ��Ʈ
		\param logMessage �α� �޽���
		\param logFunction �α׸� ȣ���� �Լ� �̸�
		\param logLine �α׸� ȣ���� ����

		\~english
		One line of the log is recorded in the file in the ProudNet format. 
		- This function is executed asynchronously. In other words, it is returned immediately.
		- This function is finally output as the examples below.
		logWriteLineTime: logLevel / logCategory(logHostID): logMessage {logFunction(logLine)}
		\param logLevel Severity of the log content
		\param logCategory What type of a log is this?
		\param logHostID The host transmitting this log. 
		\param logMessage Log message
		\param logFunction Name of the function that has called the log
		\param logLine Line that has called the log


		\~chinese
		�������������ProudNet?��??�����졣
		- ���?ު����?����?��ء?���ޡ�
		-���?��?��?���������� 
		logWriteLineTime: logLevel / logCategory(logHostID): logMessage {logFunction(logLine)}
		\param logLevel ���?��������
		\param logCategory ��??�������?
		\param logHostID ??���������
		\param logMessage ������
		\param logFunction ?���������?٣?
		\param logLine ?�������line

		\~japanese
		��1����ProudNet��?�Ҫ���請�ƫի��������?���ު���
		- ����??��ު��Ѣ��?������ު���?���������˫꫿?�󪵪�ު���
		- ����??���������Ϊ誦��������������ު���
		logWriteLineTime: logLevel / logCategory(logHostID): logMessage {logFunction(logLine)}
		\param logLevel ��?黪��ʾ��
		\param logCategory �ɪ����׾�Ϋ��ʪΪ���
		\param logHostID ���Ϋ���?�ꪷ���۫���
		\param logMessage ����ë�?��
		\param logFunction ���������󪷪�??٣
		\param logLine ���������󪷪��髤��
		\~
		*/
		virtual void WriteLine(int logLevel, LogCategory logCategory, HostID logHostID, const String& logMessage, const String& logFunction = _PNT(""), int logLine = 0) = 0;

		/**
		\~korean
		�α� ������ ���Ͽ� ����մϴ�.
		- �� �Լ��� �񵿱�� ����˴ϴ�. ��, ��� ���ϵ˴ϴ�.
		- ��, void WriteLine(TraceID TID, LPCWSTR text) �� �޸� �ƹ��� ����� �������� �ʽ��ϴ�.
		\param logMessage �α׸� ���� ���ڿ�. 
		- String ���� �Ǵ� WriteLine(String::NewFormat(L"Test Log %d", 10)) ���·� ��� �����մϴ�.

		\~english
		Writes a line of log to the file
		- This function is asynchronous so returned immediately.
		- But not like void WriteLine(TraceID TID, LPCWSTR text), does not have any header.
		\param logMessage text string to record log.
		- You are able to use string type or WriteLine(String::NewFormat(L"Test Log %d", 10)) type

		\~chinese
		������log??�����졣
		- ���?�ު����?����?��?ء?���ޡ�
		- ӣ����?void WriteLine(TraceID TID, LPCWSTR text)����?��?��������header��
		\param logMessage ??log���ݬ����
		- You are able to use string type or WriteLine(String::NewFormat(L"Test Log %d", 10)) type

		\~japanese
		��1����ի��������?���ު���
		- ����??��ު��Ѣ��?������ު���?���������˫꫿?�󪵪�ު���
		- ӣ����void WriteLine(TraceID TID, LPCWSTR text)�Ȫ��ުêơ�����Ϋثë�?���ߪ�ު���
		\param logMessage ����?�����֪ 
		- String �����ު���WriteLine(String::NewFormat(L"Test Log %d", 10))����������ʦ���Ǫ���
		\~
		*/
		virtual void WriteLine(const String& logMessage) = 0;

		/**
		\~korean
		- CLogWriter ��ü�� ����(����) �� �� ��ó ������� ���� �α׵��� ���� ������� �Ǵ� �������� ���θ� �����մϴ�.
		- �⺻���� false�Դϴ�.
		- true�� �����Ǹ� ������� ���� �αװ� �־ �����ϰ� ��� �����մϴ�.
		- false�� ������ ��� ������� ���� �α׵��� ��� ��� �� �� ���� ���ᰡ �����˴ϴ�.

		\param flag �� �ɼ��� ������� �����Դϴ�.
		
		\~english 
		- This determines whether to output the rest of the logs not yet output when the object is terminated (ended) or ignore them. 
		- The default value is false. 
		- If set true, it terminates immediately even if there is a log not yet output. 
		- If set false, termination is delayed until not yet output logs are all output. 

		\param flag Whether to use this option or not. 

		\~chinese
		- ??𶣨?�֣�CLogWriter ?��?ڱ��??�������?��???���������������?�ҡ�
		- ��???false��
		- ������true��?�����ڱ?����������?����?ء??�֡�
		- ������false��?������?����?������ڱ?�����������?��

		\param flag ���������??��

		\~japanese
		- CLogWriter ���֫������Ȫ���ۣ����������������ު������Ǫ��ʪ��ê����������ު��������몫���ު������ʪ��몫��̽�Ҫ��ު���
		- ��������false�Ǫ���
		- true�����Ҫ���������Ǫ��ʪ��ê��������êƪ����ʪ����������������ު���
		- false�����Ҫ������ꡢ�����Ǫ��ʪ��ê�������������������ު�������?�Ū���ު���
		\param flag ���Ϋ��׫��������Ī��몫�ɪ����Ǫ���
		
		\~
		*/
		virtual void SetIgnorePendedWriteOnExit(bool flag) = 0;
	};

	/**  @} */

	String GetFileTimeString();
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
