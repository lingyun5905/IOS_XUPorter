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

#include <winsvc.h>
#include "NTServiceStartParameter.h"
#include "Singleton.h"
#include "FastArray.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif
	/** \addtogroup ntservice_group
	*  @{
	*/

	/**
	\~korean
	CNTService �� �ʿ�� �ϴ� event sink ��ü

	�� ��ü�� CNTService �� �䱸�ϴ� ���� ����� �����ϴ� ������ �Ѵ�. ������ �� Ŭ������ �����ؾ� �Ѵ�.
	- ���� ���� ��ƾ
	- �α� ����� �Լ� �� �߰� ���

	\~english
	Event sink that CNTService needs

	This object provides the following functions requested by CNTService. User must realize this class.
	- Server main routine
	- Addtional functions such as function that leaves log

	\~chinese
	CNTService �����event sink?�ڡ�

	�?�������� CNTService%���������?���������ġ���?�??�?��
	- ��?���routine��
	- ׺log��?����ʥ��������

	\~japanese
	CNTService ����驪Ȫ���event sink���֫�������

	���Ϋ��֫������Ȫ�CNTService���ϴ������Ѧ������ꪹ����ܪ򪷪ު�����?��?�Ϫ��Ϋ��髹�����ު�����驪�����ު���
	- ��?��?�᫤���?����
	- ��?��??�ʪɪ���ʥѦ��
	*/
	class INTServiceEvent
	{
	public:
		virtual ~INTServiceEvent() {}

		/**
		\~korean
		�̺�Ʈ �α׸� �����.
		\param type EVENTLOG_ERROR_TYPE,EVENTLOG_WARNING_TYPE,EVENTLOG_INFORMATION_TYPE �� �ϳ�
		\param text ���� ���ڿ�

		\~english
		Leaves event log
		\param type Either EVENTLOG_ERROR_TYPE or EVENTLOG_WARNING_TYPE or EVENTLOG_INFORMATION_TYPE
		\param text Text string to be left

		\~chinese
		׺������log��
		\param type EVENTLOG_ERROR_TYPE,EVENTLOG_WARNING_TYPE,EVENTLOG_INFORMATION_TYPE �����顣
		\param text �׺���ݬ����

		\~japanese
		���٫�ȫ���?���ު���
		\param type EVENTLOG_ERROR_TYPE,EVENTLOG_WARNING_TYPE,EVENTLOG_INFORMATION_TYPE �����
		\param text ?�����֪
		*/
		virtual void Log(int type, const PNTCHAR* text) = 0;

		/**
		\~korean
		���� ��� ���� �Լ�
		�� �Լ��� ���� ��⿡ ���� ȣ��Ǵ� ���� �Լ��̴�. �� �Լ��� ���� ���α׷� ���� ��ƾ�� ȣ��Ǿ�� �Ѵ�.
		�� �Լ��� ������ �� ���񽺰� �����Ѵ�.

		�䱸 ����
		- �� �Լ� ���ο��� Ű �Է¿� ���� ���� �Ǵ� Win32 �޽��� ���μ��� ��ƾ�� �ݵ�� ���� �Ѵ�.
		�ֳ��ϸ� SCM�� ���� ���� ���� ����� �־��� ��� WM_QUIT�� �����ϱ� �����̴�. �Ʒ��� ���� �ڵ带 �����϶�.

		����
		- argc,argv�� CNTService::Instance() �κ��� ���� �� �ִ�. �׹ۿ� CNTService::Instance() �κ��� �������� �ɼ���
		���� �� �ִ�.

		���� �ҽ�
		\code
			while(1)
			{
				Sleep(100);
				if(_kbhit())
				{
					switch(getch())
					{
					case VK_ESCAPE:
						break;
					}
				}

				MSG msg;
				// �ִ� ���� ª�� �ð�����, �ܼ� �Է�, ���� �޽��� ����, ���� ������ ���� �� �ϳ��� ��ٸ���.
				MsgWaitForMultipleObjects(0,0,TRUE,100,QS_ALLEVENTS);
				if(PeekMessage(&msg,NULL,0,0,PM_NOREMOVE))
				{
					if(!GetMessage(&msg,NULL,NULL,NULL))
						break;
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
			}
		\endcode

		\~english
		Service module main function
		    This function is the main function that is called by service module. Server program main routine must be called to this function.
		    Service is terminated when this function is returned.

		Requirements
		- Either a termination by keyboard input or Win32 message process routine must be entered to this function.
		  This is since when service termination order is given by SCM then it recieves WM_QUIT. Please refer the example code shown below.

		Reference
		- argc,argv can be acquired from CNTService::Instance(). And other various options can be acquired from CNTService::Instance().

		Example source
		\code
			while(1)
			{
				Sleep(100);
				if(_kbhit())
				{
					switch(getch())
					{
					case VK_ESCAPE:
						break;
					}
				}

				MSG msg;
				// Waits for one of console input, Windows message reception, mina thread termination for max shcedule and short time.
				MsgWaitForMultipleObjects(0,0,TRUE,100,QS_ALLEVENTS);
				if(PeekMessage(&msg,NULL,0,0,PM_NOREMOVE))
				{
					if(!GetMessage(&msg,NULL,NULL,NULL))
						break;
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
			}
		\endcode

		\~chinese
		��?ټ?���?��
		���?������?ټ?��У�����?��������?��У��?�������routine��
		���?������?����??򭡣

		�ϴ��?
		- ����??ݻ��?�?����key?����?����Win32��������routine��
		��??SCM�����??�٤ֵ��?��?���WM_QUIT��??���������?��

		?��
		- argc,argv ��? CNTService::Instance()%?�������? CNTService::Instance()%?����???��

		��source
		\code
			while(1)
			{
				Sleep(100);
				if(_kbhit())
				{
					switch(getch())
					{
					case VK_ESCAPE:
						break;
					}
				}

				MSG msg;
				// ��������ӭ???������console?����window��������⥡���?��?�������?��
				MsgWaitForMultipleObjects(0,0,TRUE,100,QS_ALLEVENTS);
				if(PeekMessage(&msg,NULL,0,0,PM_NOREMOVE))
				{
					if(!GetMessage(&msg,NULL,NULL,NULL))
						break;
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
			}
		\endcode

		\~japanese
		-	��?�ӫ��⫸��?��᫤��??
		����??�ϫ�?�ӫ��⫸��?��˪�������󪵪��᫤��??�Ǫ�������??�˫�?��?�׫����᫤���?���������󪵪����驪�����ު���
		����??���꫿?�󪹪�������?�ӫ����������ު���

		�ϴ����
		- ����??��?ݻ�˫�?�����˪���������ު���Win32��ë�?���׫�����?������������ƪ���������
		��ͺ�ʪ�SCM�˪�ꫵ?�ӫ�����٤ֵ��?����������WM_QUIT�����᪹�몫��Ǫ�������Ϋ�?���Ǫ�?�Ū���������

		?��
		- argc,argv��CNTService::Instance()��������ު����������CNTService::Instance() ����??�ʫ��׫���������ު���

		��?����
		\code
			while(1)
			{
				Sleep(100);
				if(_kbhit())
				{
					switch(getch())
					{
					case VK_ESCAPE:
						break;
					}
				}

				MSG msg;
				// ��������ӭ��������ࡢ����?���������������?��ë�?�����ᡢ�᫤�󫹫�ë���������Ī�����ު���
				MsgWaitForMultipleObjects(0,0,TRUE,100,QS_ALLEVENTS);
				if(PeekMessage(&msg,NULL,0,0,PM_NOREMOVE))
				{
					if(!GetMessage(&msg,NULL,NULL,NULL))
						break;
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
			}
		\endcode
		*/
		virtual void Run() = 0;

		virtual void Stop() = 0;

		virtual void Pause() = 0;

		virtual void Continue() = 0;
	};

	class CNTServiceInternal;

	/**
	\~korean
	Windows ���� (daemon) ��� Ŭ����
	- CNTService �� singleton �̴�. �׳� Instance()�� �����ϸ� �ȴ�.

	�Ϲ��� ���
	- ::WinMain �̳� ::main()���� WinMain()�� ȣ���Ѵ�. �Ķ���ʹ� ::WinMain �̳� ::main()���� ���� ���� �ѱ�� �ȴ�.
	�̶� �̸� �غ��� INTServiceEvent ��ü�� attach�ؾ� �Ѵ�.
	- IsInstalled(), IsStartedBySCM() ���� ���� ���� ���࿡ ���õ� �������� ���� ���¸� ���� �� �ִ�.

	���α׷� ���� �Ķ����
	- -AR : SCM�� ��� �� �� �ɼ��� �߰��ϸ� ���񽺰� ũ���� �� ��� �Ŀ� �ڵ� �����ϰ� �Ѵ�. ���� ���������
	��������̶�� ������ ¥���� �����Կ� ����.
	- -install : SCM�� ����Ѵ�.
	- -uninstall : SCM���� ��� �����Ѵ�.
	- -console : �� �ɼ��� ���񽺸� �Ϲ� EXE ���·� �����ϰ� �Ѵ�. ������� �ؾ� �ϴ� ��Ȳ ��
	SCM������ ������ ������ �ʴ� ��� �� �ɼ��� ��� �Ѵ�.

	\~english
	 Windows service (daemon) module class
	- CNTService is Singleton. It can be accessed by Instance().

	General usage
	- Calls WinMain() either from ::WinMain or ::main(). Can pass parameters from ::WinMain or ::main().
	  At this time, the previously prepared INTServiceEvent obkect must be attached.
	- Various setting status related to service execution can be acquired through IsInstalled(), IsStartedBySCM() and others.

	Program execution parameter
	- -AR : If this option is added when registered to SCM, servive will auto-start after facing a crash. A handy function but can cause major irritation while debugging.
	- -install : Registers at SCM
	- -uninstall : Withdraws from SCM
	- -console : This option allows service to run as a general EXE form. When not wanted running it at SCM, you must use this option.

	\~chinese
	Windows��?��daemon��ټ??��
	- CNTService%��singleton������Instance()?��?ʦ��

	��������۰��
	- �::WinMain ��� ::main()��УWinMain()��?�::WinMain ��� ::main()�����???ʦ��
	??�attach�����?��INTServiceEvent?�ڡ�
	- ��?IsInstalled(), IsStartedBySCM()ʦ�?����??����????��??��

	����?��??
	- ��-AR : SCM��??��ʥ�??��?����?crash??��?��?�??㷡�?����?������������������??����?����???����
	- -install : ��?��SCM��
	- -uninstall : �SCM�����?��
	- -console : �??����??��?����EXE���ҡ������SCM��?����?������??��

	\~japanese
	Windows ��?�ӫ� (daemon) �⫸��?�뫯�髹
	- CNTService �� singleton �Ǫ���Instance()�����Ϊ�����ު��Ǫ���

	����������
	- ::WinMain�� ::main()���� WinMain()�������󪷪ު����ѫ��?���� ::WinMain �� ::main()����᮪ê��Ϊ�Ԥ�����ު��Ǫ���
	��������?�����򪷪� INTServiceEvent ���֫������Ȫ� attach������驪�����ު���
	- IsInstalled(), IsStartedBySCM() �ʪɪ��ת��ƫ�?�ӫ�?����?֧���쪿??������?��������ު���

	�׫����?���ѫ��?��
	- -AR : SCM����?�������Ϋ��׫�������ʥ����ȫ�?�ӫ�������ë���?���쪿����������ѫ���?�Ȫ��ު������ת�Ѧ���Ǫ���
	�ǫЫë�����ʪ�ષ���٪�ء�Ī�����ު���
	- -install : SCM����?���롣
	- -uninstall : SCM������?��𶪹�롣
	- -console : ���Ϋ��׫����ϫ�?�ӫ�������EXE������?������誦�˪��ު����ǫЫë��󫰪򪹪���驪����뫷���嫨?�����ʪ�
	SCM�Ǫ�?�����Ъުʪ����ꡢ���Ϋ��׫��������Ī�����驪�����ު���
	*/
	class CNTService: public CSingleton<CNTService>
	{
		CNTServiceInternal* m_internal;

		static void WINAPI _ServiceMain(DWORD dwArgc, PNTCHAR** lpszArgv);

		void SetServiceStatus(uint32_t dwState);
		void Run();
		void ServiceMain(int argc, PNTCHAR* argv[]);
		void Handler(uint32_t dwOpcode);
		static void WINAPI _Handler(DWORD dwOpcode);

		void WinMain_ActualService();
		void WinMain_Console();

		BOOL Install(CServiceParameter &param);
		BOOL Uninstall();

		void WinMain_Internal(CNTServiceStartParameter &param);
		void Log(int type, const PNTCHAR* fmt, ...);

	public:

		CNTService(void);
		~CNTService(void);

		/*
		\~korean
		winmain�̳� main���� ������ ���� �Ķ���͸� ��´�.

		\~english
		Gets execution parameter either from winmain or main

		\~chinese
		?��?winmain���main?����?��??��
		\~japanese
		winmain�� main�������쪿?���ѫ��?������ު���
		*/
		void GetArgv_Internal(CFastArray<String>& output);


		/*
		\~korean
		winmain�̳� main���� ������ ���� �Ķ���͸� ��´�.

		\~english
		Gets execution parameter either from winmain or main

		\~chinese
		?��?winmain���main?����?��??��
		\~japanese
		winmain��main�������쪿?���ѫ��?������ު���
		*/
		void GetEnvp_Internal(CFastArray<String>& output);

		/*
		\~korean
		SCM���� ������ ���� �Ķ���͸� ��´�.

		\~english
		Gets execution parameter from SCM

		\~chinese
		?��?SCM?����?��??��

		\~japanese
		SCM�������쪿?���ѫ��?������ު���
		*/
		void GetArgvFromSCM_Internal(CFastArray<String>& output);

		/**
		\~korean
		INTServiceEvent ���� ���� �̸��� �����Ѵ�.

		\~english
		Returns the name acquired from INTServiceEvent

		\~chinese
		����INTServiceEvent?����٣��

		\~japanese
		INTServiceEvent�������쪿٣��꫿?�󪷪ު���
		*/
		const PNTCHAR* GetName();

		/**
		\~korean
		SCM�� ���� ����� �����ΰ�?

		\~english
		Is it run by SCM?

		\~chinese
		����SCM?����???��

		\~japanese
		SCM�˪��?�����쪿?������
		*/
		bool IsStartedBySCM() const;

		bool FindArg(const PNTCHAR* name);
		String CreateArg();
		BOOL IsInstalled();

		/**
		\~korean
		���� ��� ���� �Լ�. main()�̳� ::WinMain()���� �� �޼��带 ȣ���ؾ� �Ѵ�. ���� ����� ����Ѵ�.
		- ���� �Ķ���� ó��: ���� ���/����, �ܼ� ��� ���� ��
		- �̺�Ʈ ��ũ ��ü ��������
		- ���� ���� �Լ�(INTServiceEvent.Run()) ����
		\param argc main()���� ���� ��
		\param argv main()���� ���� ��
		\param envp main()���� ���� ��
		\param param CNTService�� ���� ��

		\~english
		This method must be called either by service mudule main function main() or ::WinMain(). Manages followings.
		- Execution parameter handling: service register/withdraw, running console more and so on.
		- Getting event sink object
		- Running service main function(INTServiceEvent.Run())
		\param argc value received from main()
		\param argv value received from main()
		\param envp value received from main()
		\param param Setting Value of CNTService

		\~chinese
		��?ټ?���?���main()��� ::WinMain()��У���?��?�����������
		- ?��???�⣺��?��?/��𶡢console ټ��?������
		- ?��event sink?�ڡ�
		- ��?���?(INTServiceEvent.Run())?����
		\param argc �main()�����?��
		\param argv �main()�����?��
		\param envp �main()�����?��
		\param param CNTService��?��?

		\~japanese
		��?�ӫ��⫸��?��᫤��??. main()�� ::WinMain()���骳�Ϋ�ë��ɪ���������驪�����ު�����Ѧ����??���ު���
		- ?���ѫ��?��?��: ��?�ӫ���?/��𶡢����?���?��?���ʪ�
		- ���٫�ȫ��󫯫��֫��������êƪ���
		- ��?�ӫ��᫤��??(INTServiceEvent.Run())?��
		\param argc main()����᮪ê���
		\param argv main()����᮪ê���
		\param envp main()����᮪ê���
		\param param CNTService��������
		*/
		static void WinMain(int argc, char* argv[], char* envp[], CNTServiceStartParameter &param);

		/**
		\~korean
		���� ��� ���� �Լ�. main()�̳� ::WinMain()���� �� �޼��带 ȣ���ؾ� �Ѵ�. ���� ����� ����Ѵ�.
		- ���� �Ķ���� ó��: ���� ���/����, �ܼ� ��� ���� ��
		- �̺�Ʈ ��ũ ��ü ��������
		- ���� ���� �Լ�(INTServiceEvent.Run()) ����
		\param argc main()���� ���� ��
		\param argv main()���� ���� ��
		\param envp main()���� ���� ��
		\param param CNTService�� ���� ��

		\~english
		Service module main function. Must be called either by ::WinMain()main() or ::WinMain(). Manages followings.
		- Execution parameter handling: service register/withdraw, running console more and so on.
		- Getting event sink object
		- Running service main function(INTServiceEvent.Run())
		\param argc value received from main()
		\param argv value received from main()
		\param envp value received from main()
		\param param Setting Value of CNTService

		\~chinese
		��?ټ?���?���main()��� ::WinMain()��У���?��?������������
		- ?��???�⣺��?��?/��𶡢console ټ��?������
		- ?��event sink?�ڡ�
		- ��?���?(INTServiceEvent.Run())?����
		\param argc �main()�����?��
		\param argv �main()�����?��
		\param envp �main()�����?��
		\param param CNTService��?��?

		\~japanese
		��?�ӫ��⫸��?��᫤��??. main()�� ::WinMain()���骳�Ϋ�ë��ɪ���������驪�����ު�����Ѧ����??���ު���
		- ?���ѫ��?��?��: ��?�ӫ���?/��𶡢����?���?��?���ʪ�
		- ���٫�ȫ��󫯫��֫��������êƪ���
		- ��?�ӫ��᫤��??(INTServiceEvent.Run())?��
		\param argc main()����᮪ê���
		\param argv main()����᮪ê���
		\param envp main()����᮪ê���
		\param param CNTService��������
		*/
		static void WinMain(int argc, wchar_t* argv[], wchar_t* envp[], CNTServiceStartParameter &param);

		void FrequentWarning(const PNTCHAR* text);
		void FrequentWarningWithCallStack(const PNTCHAR* text);


	public:
		/*
		\~korean
		winmain�̳� main���� ������ ���� �Ķ���͸� ��´�.

		\~english
		Gets execution parameter either from winmain or main

		\~chinese
		?��?winmain���main?����?��??��
		\~japanese
		winmain��main�������쪿?���ѫ��?������ު���
		*/
		static void GetArgv(CFastArray<String>& output);

		/*
		\~korean
		winmain�̳� main���� ������ ���� �Ķ���͸� ��´�.

		\~english
		Gets execution parameter either from winmain or main

		\~chinese
		?��?winmain���main?����?��??��
		\~japanese
		winmain��main�������쪿?���ѫ��?������ު���
		*/
		static void GetEnvp(CFastArray<String>& output);

		/*
		\~korean
		SCM���� ������ ���� �Ķ���͸� ��´�.

		\~english
		Gets execution parameter from SCM

		\~chinese
		?��?SCM?����?��??��

		\~japanese
		SCM�������쪿?���ѫ��?������ު���
		*/
		static void GetArgvFromSCM(CFastArray<String>& output);
	};

	/**  @} */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
