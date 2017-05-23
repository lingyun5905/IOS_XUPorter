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
#include "BasicTypes.h"
#include "PNString.h"

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

	class INTServiceEvent;

	/**
	\~korean
	���񽺸� ����� ��, CreateService �Լ��� ���Ǵ� �������Դϴ�.

	\~english
	It is a setting value that is used for CreateService function when registering a service.

	\~chinese
	�?��??�� ������CreateService��?��?��?��

	\~japanese
	��?�ӫ�����?��������CreateService??�����Ī�����������Ǫ���
	*/
	class CServiceParameter
	{
	public:
		/**
		\~korean
		���񽺿� ���� �׼����� �����մϴ�. �⺻ ���� SERVICE_ALL_ACCESS�Դϴ�.

		\~english
		Appoint the access of the service. Default value is SERVICE_ALL_ACCESS.

		\~chinese
		���?����?��??������??SERVICE_ALL_ACCESS��

		\~japanese
		��?�ӫ���?���뫢����������Ҫ��ު����ǫի��������SERVICE_ALL_ACCESS�Ǫ���
		*/
		DWORD m_desiredAccess;

		/**
		\~korean
		������ Ÿ���� �����մϴ�. �⺻ ���� SERVICE_WIN32_OWN_PROCESS�Դϴ�.

		\~english
		Appoint the service type. Default value is SERVICE_WIN32_OWN_PROCESS.

		\~chinese
		�����??��������??SERVICE_WIN32_OWN_PROCESS��

		\~japanese
		��?�ӫ��Ϋ����ת���Ҫ��ު����ǫի��������SERVICE_WIN32_OWN_PROCESS�Ǫ���
		*/
		DWORD m_serviceType;

		/**
		\~korean
		������ ���� �ɼ��� �����մϴ�. �⺻ ���� SERVICE_DEMAND_START�Դϴ�.

		\~english
		Set the start option of the service. Default value is SERVICE_DEMAND_START.

		\~chinese
		?����???��??������??SERVICE_DEMAND_START��

		\~japanese
		��?�ӫ��Ϋ���?�ȫ��׫��������Ҫ��ު����ǫի�������SERVICE_DEMAND_START�Ǫ���
		*/
		DWORD m_startType;

		/**
		\~korean
		���� ������ ������ ��� ������ ������ �����մϴ�. �⺻ ���� SERVICE_ERROR_NORMAL�Դϴ�.

		\~english
		Appoint the level of an error in case service start fails. Default value is SERVICE_ERROR_NORMAL.

		\~chinese
		�����???��??��??����?������??SERVICE_ERROR_NORMAL��

		\~japanese
		��?�ӫ�����?�Ȫ������������ꡢ����?�Ϋ�٫����Ҫ��ު����ǫի��������SERVICE_ERROR_NORMAL�Ǫ���
		*/
		DWORD m_errorControl;

		/**
		\~korean
		���񽺰� �����ؾ��� ������ �̸��� �����մϴ�.

		\~english
		Appoint the name of an account that the service executes.

		\~chinese
		���?����??��??٣��

		\~japanese
		��?�ӫ���?�����뫢������Ȫ�٣����Ҫ��ު���
		*/
		String m_serviceStartName;

		/**
		\~korean
		m_serviceStartName �Ű� ������ ���� ������ ���� �̸��� ���� ��ȣ�� �����մϴ�.

		\~english
		Appoint the password of the account name that has been appointed by m_serviceStartName parameter. 

		\~chinese
		?����m_serviceStartName??����������??٣�������?��

		\~japanese
		m_serviceStartName??�˪����Ҫ��쪿��������Ȫ�٣��?������?����Ҫ��ު���
		*/
		String m_password;

		/**
		\~korean
		������ �޼����Դϴ�.

		\~english
		It is a constructor method. 

		\~chinese
		�����۰����

		\~japanese
		�����ޫë��ɪǪ���
		*/
		PROUD_API CServiceParameter()
		{
			m_desiredAccess	= SERVICE_ALL_ACCESS;
			m_serviceType	= SERVICE_WIN32_OWN_PROCESS;
			m_startType		= SERVICE_DEMAND_START;
			m_errorControl	= SERVICE_ERROR_NORMAL;
		}
	};


	/**
	\~korean
	CNTService.WinMain �� ���� NTService�� ������ ���� �ʱ� �������Դϴ�.

	\~english
	It is an initial setting value when creating NTService by CNTService.WinMain.

	\~chinese
	��CNTService.WinMain�����NTService?�����?��?��

	\~japanese
	CNTService.WinMain�˪��NTService����������������Ѣ�������Ǫ���
	*/
	class CNTServiceStartParameter
	{
	public:
		/**
		\~korean
		NT ���� �̸��Դϴ�. �ִ� ���ڿ� ���̴� 256���̸�, '/'�� '\'�� ����� �Ұ����մϴ�.

		\~english
		It is the name of NT service. Maximum length of character string is 256 and special characters (such as '/' and '\') are not available. 

		\~chinese
		NT��?��٣?���ݬ?����?��?256?�ݬ�����ʦ���� '/' �� '\'��

		\~japanese
		NT��?�ӫ���٣�Ǫ������֪������256�Ǫ��ꡢ'/'��'\'�����ĪǪ��ު���
		*/
		String m_serviceName;

		/**
		\~korean
		CNTService�� �ʿ�� �ϴ� Event Sink ��ü�Դϴ�.

		\~english
		It is an Even Sink object that CNTService needs. 
		
		\~chinese
		CNTService ����� Event Sink ?�ڡ�

		\~japanese
		CNTService����驪Ȫ���Event Sink���֫������ȪǪ���
		*/
		INTServiceEvent* m_serviceEvent;

		/**
		\~korean
		���񽺸� ����� ��, CreateService �Լ��� ���Ǵ� �������Դϴ�.

		\~english
		It is a setting value that is used for CreateService function when registering a service.  

		\~chinese
		�?��??�� CreateService ��?�������?��?��

		\~japanese
		CNTService����驪Ȫ���Event Sink���֫������ȪǪ���
		*/
		CServiceParameter m_serviceParam;
	};


	/**  @} */

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif

}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
