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

#include "ProudNetServer.h"
#include "ProudNetClient.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif


	/**
	\~korean
	���� �ð� Ȥ�� OnReportStatsCommand �� ������ Agent �� ������ Report Ŭ����
	- ����ڰ� ���Ƿ� ���� �־ ����Ҽ� �ֽ��ϴ�.
	- ���⼭ �Է��� ���� PNServerAgentConsole ���� Ȯ�ΰ����մϴ�.

	\~english TODO:translate needed.
	The report class to report with Agent after a certain amount of time or when OnReportStatsCommand has come. 
	- Users can input values randomly to use
	- The value input here can be identified in PNServerAgentConsole


	\~chinese
	������??���OnReportStatsCommand��?����Agent?ͱ��Report?��
	- �����ʦ�?������?���ġ�
	- �?��?����?�PNServerAgentConsoleʦ�??��

	\~japanese
	�������ު���OnReportStatsCommand��?������Agent����ͱ����Report���髹
	- ��?��?�����������������Ū����Ȫ��Ǫ��ު���
	- ������������������PNServerAgentConsole������Ǫ��ު���
	\~
	*/
	class CReportStatus
	{
	public:
		/** 
		\~korean
		�̰��� ���� PNLicenseAgentConsole ���� ���ڻ��� �޶����ϴ�. 

		\~english TODO:translate needed.
		Depending on this value, the color of the letters change in PNLicenseAgentConsole


		\~chinese
		?��?���PNLicenseAgentConsole���??��?��?��

		\~japanese
		�������˪�êơ� PNLicenseAgentConsole������䪬�ުêƪ��ު���
		\~
		*/
		enum StatusType { StatusType_OK, StatusType_Warning, StatusType_Error };

		/** 
		\~korean
		AgentConsole �� ���� ������ Ÿ��

		\~english TODO:translate needed.
		Type of the information to be sent to AgentConsole


		\~chinese
		��AgentConsole?��������?����

		\~japanese
		AgentConsole ��������êΫ�����
		\~
		*/
		StatusType m_statusType;

		/** 
		\~korean
		������ ����. �� String�� ���  Data�� ������ �ʽ��ϴ�.

		\~english TODO:translate needed.
		Content of the information. If this string is empty, data is not transmitted


		\~chinese
		������?黡������String����?��?��Data��

		\~japanese
		���ê�?黡�����String�������ȫ�?�������ު���
		\~
		*/
		String m_statusText;
		
		typedef CFastMap<String, String> KeyValueList;
		
		/**
		\~korean
		�߰������� �ʿ��� Data���� ���� List
		- AgentConsole�� property View�� Log�� ���Ͽ� Ȯ���Ͻ� �� �ֽ��ϴ�.
		- AgentConsole�� property View���� Key : Value�� ��µ˴ϴ�.

		\~english TODO:translate needed.
		List List of the data needed additionally
		- You can check with the log of the property view of AgentConsole.
		- It is output as Key : Value of the property view of AgentConsole.


		\~chinese
		?�������Data����List��
		-AgentConsole ��propertyʦ���?View Logʦ�??.
		-AgentConsole ��property�Key : Value?��.

		\~japanese
		��ʥ�ܪ���驪ʫ�?�����ë꫹��
		- AgentConsole��property View��Log���ת����㪹�몳�Ȫ��Ǫ��ު���.
		- AgentConsole��property View��Key : Value����������ު���
		\~
		*/
		KeyValueList m_list;
	};

	/**
	\~korean
	CAgentConnector �� �䱸�ϴ� delegate �������̽�. CAgentConnector �� ������ �� ���ڷ� �ʿ��ϴ�.

	\~english TODO:translate needed.
	The delegate interface required by CAgentConnector. It is required as a factor when generating CAgentConnector


	\~chinese
	CAgentConnector �����delegateͣ������?�������� CAgentConnector%��?����驡�

	\~japanese
	CAgentConnector���ϴ����delegate����?�ի�?����CAgentConnector�����������������Ȫ�����驪Ǫ���
	\~
	*/
	class IAgentConnectorDelegate
	{
	public:
		/** 
		\~korean
		Agent connect�� ������ ������ ��� callback�˴ϴ�.

		\~english TODO:translate needed.
		It is called back when Agent connect��s authentication is successful


		\~chinese
		Agent connect ��??����??callback��

		\~japanese
		Agent connect����?�����������ꡢcallback����ު���
		\~
		*/
		virtual void OnAuthentication(ErrorInfo* errorinfo) = 0;

		/** 
		\~korean
		Server app�� �����Ű��� ����� �°�� callback�˴ϴ�.

		\~english TODO:translate needed.
		It is called back when the command to terminate the server app is received


		\~chinese
		����?��Server app��٤ֵ??callback��

		\~japanese
		Server app������������Ȫ���٤ֵ��?�����ꡢcallback����ު���
		\~
		*/
		virtual void OnStopCommand() = 0;

		/**
		\~korean
		Agent Server �κ��� Report ��û ����� �°�� callback�˴ϴ�.

		\~english TODO:translate needed.
		It is called back when the report request command has come from the agent server


		\~chinese
		?Agent Server����Report�?٤ֵ??callback��

		\~japanese
		Agent Server����Report�ꫯ������٤ֵ��?�����ꡢcallback����ު���
		\~
		*/
		virtual void OnReportStatsCommand() = 0;

		/** 
		\~korean
		Agent�� ����ڰ� �߸��� ������� ����Ͽ��� �ÿ� ȣ��˴ϴ�.

		\~english TODO:translate needed.
		It is called when the agent is used in a wrong way by the user


		\~chinese
		��?�??��۰������Agent��?������

		\~japanese
		Agent���?��?�����ުê�۰�����Ūê����������󪵪�ު���
		\~
		*/
		virtual void OnWarning(ErrorInfo* errorinfo) = 0;
	};

	/**
	\~korean
	Agent�� �����Ͽ� PNServerAgentConsole ���� ������� �������� �������� �����Ҽ� �ֽ��ϴ�.

	\~english TODO:translate needed.
	By connecting with Agent, the server app of the user can be controlled remotely from PNServerAgentConsole


	\~chinese
	?��Agent����PNServerAgentConsoleʦ�?��η����?��server app��

	\~japanese
	Agent��֧̿����PNServerAgentConsole�ǫ�?��?�Ϋ�?��?���׫����?�Ȫ�η�⪹�몳�Ȫ��Ǫ��ު���
	\~
	*/
	class CAgentConnector
	{
	public:
		virtual ~CAgentConnector() {}

		PROUD_API static CAgentConnector* Create(IAgentConnectorDelegate* dg);

		/** 
		\~korean
		Start �� ��ü�� �����ϱ� ������ Agent�� ��� ������ �����մϴ�.
		- ServerAgent�� ���Ͽ� ���� �� ���� �ƴ� ��� Start���� �ʽ��ϴ�.

		\~english TODO:translate needed.
		Before deleting an object after start, it maintains connection with the agent continuously
		- It does not start if it is not executed by ServerAgent


		\~chinese
		Start �������?��?�����????�?Agent��?�ȡ�
		- ������ServerAgent?������?��Start��

		\~japanese
		Start���˫��֫������Ȫ���𶪹����ު�Agent��?����֧̿���򥪷�ު���
		- ServerAgent�˪�ê�?�����쪿�ΪǪϪʪ������Start����ު���
		\~
		*/
		virtual bool Start() = 0;

		/**
		\~korean
		���� �ð� Ȥ�� IAgentConnectorDelegate::OnReportStatsCommand �� ������ �� �Լ��� �̿��Ͽ� CReportStatus �� Agent�� ������ �ֽ��ϴ�.
		\return ServerAgent�� ���Ͽ� ������� �ʾ� Start ���� �ʾҰų� reportStatus�� Data�� �߸��Ǿ��� �ÿ� false 

		\~english TODO:translate needed.
		When a certain time or IAgentConnectorDelegate::OnReportStatsCommand has come, CReportStatus can be sent to the agent using this function
		- False when it has not started because it is not executed by \return ServerAgent or when the data of reportStatus is wrong


		\~chinese
		����??���IAgentConnectorDelegate::OnReportStatsCommand ��?�����������?ʦ��� CReportStatus%?����Agent��
		\return ?����ServerAgent?���?��Start�����reportStatus��Data��?��?��fals��

		\~japanese
		�������ު���IAgentConnectorDelegate::OnReportStatsCommand��?����������??�����Ī���CReportStatus��Agent����몳�Ȫ��Ǫ��ު���
		\return ServerAgent�˪�ê�?�����쪺Start����ʪ��ê��Ȫ���reportStatus��Data�����ުêƪ�������false 
		\~
		*/
		virtual bool SendReportStatus(CReportStatus& reportStatus) = 0;

		/** 
		\~korean
		Agent�� Log�� ������ ��� 
		- ���� �����Ͱ� �ƴ� ������ �α׸� �������� �� �� SendReportStatus�� ������� �ʰ� EventLog�� ���Ͽ� ������ �̿��Ͻ� �� �ֽ��ϴ�.
		\return text�� ����ų� ServerAgent�� Start���� ���Ͽ��� �� false

		\~english TODO:translate needed.
		Feature to send a log to Agent
		- When you wish to send a simple log instead of detailed data, you can conveniently use through an EventLog instead of using SendReportStatus. 
		\False when \return text is empty or ServerAgent does not start


		\~chinese
		��Log?����Agent������
		- ��?������???�����??log��?��������SendReportStatus�����ʦ���?EventLog??���ġ�
		\return text������ServerAgent?Start��?��false��

		\~japanese
		Agent��Log�����Ѧ��
		- �٪�����?���ǪϪʪ���?�ʫ�����꪿������SendReportStatus���Ū�ʪ�EventLog���ת���?�˪����ĪǪ��ު���
		\return text�������ƪ��몫��ServerAgent��Start����ʪ��ê�����false
		\~
		*/
		virtual bool EventLog(CReportStatus::StatusType logType, const PNTCHAR* text) = 0;

		/**
		\~korean
		���� �ð��� �ѹ��� ���־�� �ϴ� �ϵ��� ó���մϴ�.
		- ������ �Ǿ� ���� �ʴٸ� ���� �ð����� �ڵ����� ������ �õ� �մϴ�.

		\~english TODO:translate needed.
		It processes tasks that need to be done every once in a certain period of time.
		- If not connected, it attempts connection automatically every certain time.


		\~chinese
		?�������??��?����������ס�
		- ?��?����??������??�????�ȡ�

		\~japanese
		��������1�ު��������٪����Ȫ�?�⪷�ު���
		- ֧̿����ʪ��ê���������઴�Ȫ���Ѫ�֧̿���˪ߪު���
		*/
		virtual void FrameMove() = 0;

		/**
		\~korean
		FrameMove ���� �ǽð� ���� ���� ���ۿ� ���� Delay Time�� ���մϴ�. 
		- 1/1000�� �����Դϴ�. 
		- default �� 1000�Դϴ�.

		\~english TODO:translate needed.
		It sets the delay time for transmitting the real-time information transmission within FrameMove
		- It is in 1/1000 second unit
		- The default is 1000


		\~chinese
		?��?FrameMove?��????����?����Delay Time��
		- ��1/1000��?�ȡ� 
		- default��1000��


		\~japanese
		FrameMove?�Ϋꫢ�뫿����?�����ê�?���?����Delay Time��̽��ު���
		- 1/1000��?�ȪǪ���
		- default��1000�Ǫ���
		\~
		*/
		virtual void SetDelayTimeAboutSendAgentStatus(uint32_t delay) = 0;

	};


#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif