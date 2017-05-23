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

#include "sysutil.h"
#include "Singleton.h"
#include "MiniDumpAction.h"

#if defined(_WIN32)
#include <DbgHelp.h>
#pragma comment(lib,"dbghelp.lib")
#endif

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

#if defined(_WIN32)

	/**
	\~korean
	�̴� ������ ����ϱ� ���� �����ؾ� �ϴ� �Ķ����

	\~english
	It is a parameter that needs to be provided for using mini dump.

	\~chinese
	?������Mini dump��������??��

	\~japanese
	�߫˫���ת����Ī��몿�����ꪹ��ѫ��?��
	*/
	class CMiniDumpParameter
	{
	public:
		/**
		\~korean
		�̴� ������ ������ ���� �̸��� ��θ� ä���ִ´�.

		\~english
		Please input the directory of file name that mini dump is going to create.

		\~chinese
		?��Mini dump?��������٣����?��

		\~japanese
		�߫˫���ת���������ի�����٣��?�ت�����롣
		*/
		Proud::String m_dumpFileName;

		/**
		\~korean
		�̴� ���� Ÿ���� �����Ѵ�.

		\~english
		Sets the type of mini dump

		\~chinese
		���ڰ��???����

		\~japanese
		�߫˫���׫����ת���Ҫ��롣
		*/
		MINIDUMP_TYPE m_miniDumpType;

		CMiniDumpParameter();
	};

#define SmallMiniDumpType MiniDumpNormal // MiniDumpWithDataSegs�� ���� �����ϴٰ� ������ 6MB�� �Ǵϱ� �������� �� �Ⱥ�����.

	/**
	\~korean
	�̴� ���� ���

	Ư¡
	- �� ��ü�� ���� ũ���� �߻��� .DMP ������ �����.
	- .DMP ������ visual studio.net���� ���� ��� ���� ��ġ�� �����ϴµ� ������ �ȴ�.
	- ���� �ٹ������� ���� �����忡�� unhandled exception�� �߻��ص� ���� 1ȸ�� ���� ���� ���ϸ� �����ȴ�.
	������ ������� ������ ���������� ����Ѵ�. �׷��� �����߿� ���μ����� �� ������ ������ �ʴ´�.

	�Ϲ��� �뵵
	- �� ��ü�� �̱����̴�. �ϴ� �� ��ü�� Delegate�� ���������� JIT creation�� �ȴ�. Delegate ������
	Init()�� �Ѵ�. ���ĺ��ʹ� ���α׷� ������ ���� ���α׷��� �۵��Ѵ�.
	- ���� �̴� ������ ������ Dump()�� �Ѵ�.

	\~english
	Mini dump module

	Characterictics
	- This object creates .DMP files when server crash occurs.
	- .DMP can be opened by visual studio.net directly and helps tracking where error occurred.
	- The first cump file will be created even if there are multiple unhandled exceptionals occured from many thread simultaneously.
	Other thread will standby until dump ends. There will be no other problems while dumping the process by doing so.

	General usage
	- This object is Singleton. This will become JIT creation by designating Delegate of this object. Delegate is designated by using Init(). From this point and then, dump program will automatically run when error occurs.
	- Dump() is used to create manual mini dump.

	\~chinese
	ڰ��??ټ?��

	����
	- �?���?����?��crash��?��?��.DMP��
	- .DMP�����visual  studio.net%������??�������?��?𾡣
	- ?����?���?������??��߾?��unhandled exception��������?���������??���졣
	�����?������???�֡�??����??��������??������??��

	������Բ
	- �?����singleton�������?����Delegate����?JIT creation����Init()?��Delegate����ҡ�������������?��??��??������???��
	- �?����ڰ��??����Dump()��

	\~japanese
	�߫˫���׫⫸��?��

	��?
	-���Ϋ��֫������ȪϪ�?�Ы���ë���?������.DMP �ի�������ª�ު���
	-.DMP�ի������visual studio.net�������Ҫ��ƫ���?�����Ǫ����檹��Ϊ�浪�ء���ު���
	-������?�ܪ���?�ʫ���ëɪ�unhandled exception��?�檷�ƪ��������ު�?�������׫ի����������������ު���
	?��Ϋ���ëɪϫ���ת������ު���Ѧ���ު����������ʪ��ȫ�����顢�׫����������𹪬?�檷�ު���

	�����ܪ���Բ
	-���Ϋ��֫������Ȫϫ��󫰫�ȫ�Ǫ�����ө���Ϋ��֫������Ȫ�Delegate����Ҫ��몳�Ȫ�JIT creation�˪ʪ�ު��� Delegate��Ҫ�
	Init()�˪��ު������쪫��ϫ׫����Ϋ���?������׫׫���બ���Ѫ��ު���
	-��ѫ߫˫���ת������� Dump()�˪��ު���
	*/
	class CMiniDumper : public CSingleton<CMiniDumper>
	{
		/**
		\~korean
		���� �����忡�� ������ ������ ���δ�. ���� �̰ɷ� ����ȭ�Ѵ�.

		\~english
		Will cras if many threads stack dump. So must be serialized by using this.

		\~chinese
		�???����???��?����������??��?����

		\~japanese
		��?�ʫ���ëɪǫ���׫ի������?���Ȫ�����ު����Ǫ��ΪǪ������֪�����ު���
		*/
		CriticalSection m_filterWorking;

		/**
		\~korean
		TopLevelFilter �� �۵��� 1ȸ�� �����ϴ� ����

		\~english
		To limit the real execution of TopLevelFilter by once.

		\~chinese
		TopLevelFilter ���????1�������ܡ�

		\~japanese
		TopLevelFilter?���Ѫ����ު���ڪ�������
		*/
		PROUDNET_VOLATILE_ALIGN LONG m_hitCount;

		PROUD_API void SetUnhandledExceptionHandler();

		PROUD_API uint32_t CreateProcessAndWaitForExit(const PNTCHAR *args, MINIDUMP_TYPE miniDumpType, _EXCEPTION_POINTERS *pExceptionInfo = NULL);

		static LONG WINAPI TopLevelFilter(_EXCEPTION_POINTERS *pExceptionInfo);
		LONG TopLevelFilter_(_EXCEPTION_POINTERS *pExceptionInfo);

#if defined(_WIN64)
		bool DumpWithFlags(const PNTCHAR *dumpFileName, const uint32_t processID, const MINIDUMP_TYPE minidumpFlags, const uint32_t threadID, const uint64_t exceptionInfoAddr);
#else
		bool DumpWithFlags(const PNTCHAR *dumpFileName, const uint32_t processID, const MINIDUMP_TYPE minidumpFlags, const uint32_t threadID, const uint32_t exceptionInfoAddr);
#endif

	private:
		/**
		\~korean
		�̴� ������ ����ϱ� ���� �Ķ����

		\~english 
		The parameter to use the mini dump. 

		\~chinese 
		����mini dumper��??
		\~

		\~japanese 
		�߫˫���ת��Ū�����Ϋѫ��?��?
		\~
		*/
		CMiniDumpParameter m_parameter;

	public:
		CMiniDumper();
		~CMiniDumper();

		/**
		\~korean
		�ʱ�ȭ �Լ��Դϴ�.
		\param cmdLine ���� Command-Line argument�� ���ڸ� �־��ֽø� �˴ϴ�.

		ProudNet�� �ۿ��� ���� �߻� ��, �� �ڽ��� ���ο� ���μ����� �����մϴ�.
		�� ��, Startup �Լ����� �ν��� �� �ִ� Ư�� ������ Commad Line Argument�� �߰��Ͽ� ���ο� ���μ����� �����ϰ� �˴ϴ�.

		�� �Լ��� Win32 ���� ���α׷� �� MFC �������α׷����� ȣ���Ͻø� �˴ϴ�.
		\code
		void main(int argc, char* argv[])
		{
		...

		CMiniDumpParameter parameter;
		switch(CMiniDumper::GetSharedPtr()->Startup(parameter))
		{
		case MiniDumpAction_AlarmCrash:
		// ���� �߻����� ���ο� ���μ������� ���� ������ ������ ��, �� ���� return�� �˴ϴ�.
		// ������ ���� ������ ���Ϸ� �����ų� ���� â�� ���̴� �� ������ ���� ���� ���� ��, ó���ؾ��� �۾��� ó�����ֽø� �˴ϴ�.
		...
		break;

		case MiniDumpAction_DoNothing:
		// ���� ȣ��� ���ο� ���μ������� ���� ������ ������ ��, �� ���� ��ȯ�˴ϴ�.
		// �� ��쿡�� �ƹ��͵� ���� ���ƾ��մϴ�.
		break;

		default: // MiniDumpAction_None
		// �Ϲ������� �� ���� ��, �� ���� ��ȯ�˴ϴ�.
		// ���⼭�� �Ϲ������� ó���ؾ��� ���� ó�����ֽø� �˴ϴ�.
		...
		break;
		}
		}
		\endcode

		\~english
		It is an initialized function.
		\param cmdLine Please insert Command-Line argument factor of application.

		When an error occurs in application, ProudNet executes the application with new process.
		\code
		void main(int argc, char* argv[])
		{
		...

		CMiniDumpParameter parameter;
		switch(CMiniDumper::GetSharedPtr()->Startup(parameter))
		{
		case MiniDumpAction_AlarmCrash:
		// After dump file creation at a new process due to error occurrence, this value will return.
		// Please proceed with works (such as sending created dump file by email & error window management) that need to be done right after dump file creation.
		...
		break;

		case MiniDumpAction_DoNothing:
		// After dump file creation at a new process by user calling, this value will return.
		// In this case, you should not do anything.
		break;

		default: // MiniDumpAction_None
		// Generally, this value returns when executing the application.
		// At this time, you should proceed with the relevant works.
		...
		break;
		}
		}
		\endcode

		\~chinese
		�������?��
		\param cmdLine ?��App��Command-Line argument ???ʦ��

		�App?������?��??��ProudNet?������Process?��App��
		�??�Command-Line Argument����ʥStartup��?ʦ�??�����?ϣ��?������Process��.
		\code
		void main(int argc, char* argv[])
		{
		...

		CMiniDumpParameter parameter;
		switch(CMiniDumper::GetSharedPtr()->Startup(parameter))
		{
		case MiniDumpAction_AlarmCrash:
		// ��???�������Process������Dump�������??��return��
		// ?������?��?���������Dump���졢?��???Ϣ����?����Dump��������?��������?ʦ��
		...
		break;

		case MiniDumpAction_DoNothing:
		// ����?���������Process������Dump������?��?�?��
		// �??���?���������¡�
		break;

		default: // MiniDumpAction_None
		// �����?��App??��?�?��
		// �?��?���������?��������?ʦ��
		...
		break;
		}
		}
		\endcode

		\~japanese
		��Ѣ����??�Ǫ���
		\param cmdLine App(Application)��Command-Line argument�Ϋѫ��?��?������ƪ���������

		ProudNet��App�ǫ���?��?�檹���,App�����檷���׫���(Process)��?�����ު���
		����𷡢Startup ??�����۪Ǫ������ϰ���� Commad Line Argument����ʥ�����檷���׫�����?�����ު���
		\code
		void main(int argc, char* argv[])
		{
		...

		CMiniDumpParameter parameter;
		switch(CMiniDumper::GetSharedPtr()->Startup(parameter))
		{
		case MiniDumpAction_AlarmCrash:
		// ����?��?����檷���׫����ǫ���׫ի���������������������� return����ު���
		// �������쪿����׫ի�������?�����ê��ꫨ��?��?����̸����ʪɫ�?��������׫ի��������������?�⪷�ʪ���Ъʪ�ʪ�������?�⪷�ƪ���������
		...
		break;

		case MiniDumpAction_DoNothing:
		// ��?���������󪷪��檷���׫����˫���׫ի������������������������������ު���
		// ��������˪����⪷�ʪ��Ǫ���������
		break;

		default: // MiniDumpAction_None
		// �����ܪ˪�App?����,����������������ު���
		// �����Ǫ������ܪ�?�⪷�ʪ���Ъʪ�ʪ����Ȫ�?�⪷�ƪ���������
		...
		break;
		}
		}
		\endcode
		*/
		static MiniDumpAction Startup(const CMiniDumpParameter &parameter);
	private:
		MiniDumpAction Startup_(const CMiniDumpParameter &parameter);
	public:

		/***
		\~korean
		���� ȣ�⿡ ���� �̴� ���� ������ �����Ѵ�. ��, �޸� ��ü ������ �ϹǷ� �뷮�� ū ������ �����ȴ�.

		\~english
		Create mini dump file by user calling, however, the capacity of file becomes larger because the whole memory is dumped.

		\~chinese
		����?��У����ڰ��??���졣ӣ������??��?����ݻ??��?��������������졣

		\~japanese
		��?���������󪷪˪��߫˫���׫ի�������������ު���������������?��?�����ת���Ϊ������ު����ի����몬��������ު���
		*/
		PROUD_API void ManualFullDump();

		/**
		\~korean
		���� ȣ�⿡ ���� �̴� ���� ������ �����Ѵ�.

		\~english
		Create mini dump file by user calling.

		\~chinese
		����?��У����ڰ��??���졣

		\~japanese
		��?���������󪷪˪��߫˫���׫ի�������������ު���
		*/
		PROUD_API void ManualMiniDump();

		/**
		\~korean
		�� �Լ��� ȣ���� ���������� ���μ��� ���¸� ���� ���Ϸ� �����.
		\param fileName ���� ���� �̸�. Ȯ���ڴ� dmp�� ������ ��.

		\~english
		Process status of calling this function as dump file
		\param fileName Name of dump file. Its extension must be .dmp.

		\~chinese
		?��У���?��?��������??׺???���졣
		\param filename ??����٣��?������?dmp��

		\~japanese
		����??�������󪷪����êǪΫ׫���?�������׫ի������?���ު���
		\param fileName����׫ի������٣��?����dmp����Ҫ��몳�ȡ�
		*/
		PROUD_API static void WriteDumpFromHere(const PNTCHAR* fileName, bool fullDump = false);
		//		PROUD_API static void WriteDumpAtExceptionThrower(const PNTCHAR* fileName, bool fullDump = false);
	};

	/**
	\~korean
	CExceptionLogger ���� �ʿ���ϴ� delegate ��ü�̴�. �����ڴ� �� ��ü�� �������̵��� �� CExceptionLogger ��
	�����ϴ� ���� �� ��ü�� �����ؾ� �Ѵ�.

	\~english
	Delegate object that is needed by CExceptionLogger. Developer must sustain this object while CExceptionLogger exists after overriding this object.

	\~chinese
	� CExceptionLogger%�����delegate?�ڡ�??�����?���������� CExceptionLogger%�����Ѣ?�?��?�ڡ�

	\~japanese
	CExceptionLogger����驪Ȫ��� delegate���֫������ȪǪ�����?�Ϫ��Ϋ��֫������Ȫ�?��?�髤�ɪ������� CExceptionLogger��
	������ࡢ���Ϋ��֫������Ȫ��򥪷�ʪ�Ъʪ�ު���

	*/
	class IExceptionLoggerDelegate
	{
	public:
		/**
		\~korean
		Dump ���ϵ��� ����� ������ �����Ѵ�. ��� ��� �Ǵ� ���� ��θ� ������ �� �ִ�.
		�����ڴ� �� �޼��带 �������̵��ؾ� �Ѵ�.

		\~english
		Returns the folder where Dump files are to be stored. Either relative or absolute path can be designated.
		Developer must override this method.

		\~chinese
		��������dump����������?��ʦ������?��?���??��?��??�����۰�����̡�

		\~japanese
		Dump�ի����몿�����������ի����?��꫿?�󪷪ު�����??�تު����??�ت���ҪǪ��ު���
		��?�Ϫ��Ϋ᫽�ëɪ�?��?�髤�ɪ��ʪ���Ъʪ�ު���
		*/
		virtual String GetDumpDirectory() = 0;
	};

	/**
	\~korean
	ũ���� �� ���α׷����� ���ܰ� �߻��� ��� ���ܰ� �߻��� ������ DMP ���Ϸμ� �α׸� �����
	����ؼ� ���α׷��� �����Ű�� ������ �ϴ� ��ü
	- �ڼ��� ���� <a target="_blank" href="http://guide.nettention.com/cpp_ko#exception_logger" >�ߴܾ��� ���������ý���(Exception Logger)</a> �� ������ ��
	- Windows XP �Ǵ� 2003 Server �̻��� �ʿ�� �Ѵ�.
	- Singleton ��ü�θ� ����� �� �ִ�. �ڼ��� ���� CSingleton ����.

	\~english
	The object that records the point where exception occurred as DMP file when crash occurs then has a role to keep running the program
	- Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#exception_logger" >Pauseless error dump system (Exception Logger)</a>.
	- Requires Windows XP or 2003 Server or later version
	- Can be only used as Singleton object. Please refer CSingleton.

	\~chinese
	�crash��������?��������?������?�������������DMP����׺log�����???��������������?�ڡ�
	- ????��<a target="_blank" href="http://guide.nettention.com/cpp_zh#exception_logger" >����?��??logͧ?(Exception Logger)</a>%��
	- ���Windows XP���2003 Server�߾��
	- ��������Singleton?�ڡ�????�� CSingleton%��

	\~japanese
	����ë���ʪɫ׫��������⪬?�檹�����ꡢ���⪬?�檷����ê�DMP�ի�����ǫ���?����
	?���ƫ׫�����?����������ܪ򪹪뫪�֫�������
	- �٪�����<a target="_blank" href="http://guide.nettention.com/cpp_jp#exception_logger" >��??????ͧ?(Exception Logger)</a>��?�Ū��ƪ���������
	- Windows XP�ު���2003 Server�߾����驪Ȫ��롣
	- Singleton���֫������Ȫ��������ĪǪ��ު����٪����� CSingleton��?�Ū��ƪ���������
	*/
	class CExceptionLogger : public CSingleton<CExceptionLogger>
	{
		CriticalSection m_cs;

		// ���� ������ ����� ���͸�
		String m_directory;
		// ���� ������ �̸�
		String m_dumpName;
		// ���� ���Ͽ� ������ �Ϸ� ��ȣ
		int m_dumpSerial;
		// ���� �������� ������ ���� �ð�
		uint32_t m_lastLoggedTick;

		IExceptionLoggerDelegate* m_dg;

		static LONG CALLBACK ExceptionLoggerProc(PEXCEPTION_POINTERS pExceptionInfo);
	private:
		LONG ExceptionLoggerProc_(PEXCEPTION_POINTERS pExceptionInfo);

	public:
		/**
		\~korean
		�� �α� �ý����� �غ��Ѵ�.
		\param dg �� �ý����� �ʿ�� �ϴ� �߰����� ����� ������ delegate ��ü�� ������

		\~english
		Prepares this log system
		\param dg Pointer of the delegate object that will provide additional functions required by this system

		\~chinese
		��?��logͧ?��
		\param dg ����ͧ?�����ݾʥ������delegate?�����?��

		\~japanese
		��������ƫ�����᪷�ު���
		\param dg�����Ϋ����ƫબ��驪Ȫ�����ʥ�ܪ�Ѧ������ꪹ�� delegate���֫������ȪΫݫ���?
		*/
		void Init(IExceptionLoggerDelegate* dg, Proud::String dumpName = _PNT("dump"));


		inline int GetDumpSerial() { return m_dumpSerial; }
	};
#endif

	/**  @} */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
