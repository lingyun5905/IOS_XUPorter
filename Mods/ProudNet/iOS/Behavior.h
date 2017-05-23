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

#include "Message.h"
#include "HlaDef.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	template<typename type>
	class CStaticBehaviorMember
	{
		type m_value_INTERNAL;
	public:
		inline void Set(type value)
		{
			m_value_INTERNAL = value;
		}
		inline type Get()
		{
			return m_value_INTERNAL;
		}

		// does nothing, but it is needed because it is called by SWD compiler output.
		// \return always false
		inline bool GatherTheChangeToMessage(HlaFieldGroupID memberID, CMessage &outputMessage, Protocol &outProtocol)
		{
			outProtocol = Protocol_Undefined;
			return false;
		}

		inline void ClearTheChange()
		{
		}

		inline bool IsChanged()
		{
			return false;
		}

		// does nothing, but it is needed because it is called by SWD compiler output.
		inline void GatherAllToMessage(HlaFieldGroupID memberID, CMessage &outputMessage)
		{
		}
	};

	/** 
	\~korean
	Conditional behavior member�� ���� �ӽ� Class
	
	\~english
	a template class for conditional behavior member
	
	\~chinese
	?��Conditional behavior member��??Class��
	
	\~japanese
	Conditional behavior member�Ϊ�����������髹
	\~
	*/
	template<typename type>
	class CConditionalBehaviorMember
	{
		type m_value_INTERNAL;
		bool m_valueChanged_INTERNAL;
	public:
		inline CConditionalBehaviorMember()
		{
			m_valueChanged_INTERNAL = false;
		}
		inline void Set(type value)
		{
			if (value != m_value_INTERNAL)
			{
				// A variable whose 'changed'
				// is true will be multicasted soon.
				m_valueChanged_INTERNAL = true;
				m_value_INTERNAL = value;
			}
		}
		inline type Get()
		{
			return m_value_INTERNAL;
		}

		// append the value to the message if it has been changed.
		// \return true if the value is written to the message.
		inline bool GatherTheChangeToMessage(HlaFieldGroupID memberID, CMessage &outputMessage, Protocol &outProtocol)
		{
			outProtocol = Protocol_Undefined;
			if (m_valueChanged_INTERNAL)
			{
				outputMessage.Write(memberID);
				outputMessage<<m_value_INTERNAL;
				outProtocol = Protocol_ReliableSend;

				return true;
			}

			return false;
		}

		inline void ClearTheChange()
		{
			m_valueChanged_INTERNAL = false;
		}

		inline bool IsChanged()
		{
			return m_valueChanged_INTERNAL;
		};

		// does nothing, but it is needed because it is called by SWD compiler output.
		inline void GatherAllToMessage(HlaFieldGroupID memberID, CMessage &outputMessage)
		{
			outputMessage.Write(memberID);
			outputMessage<<m_value_INTERNAL;
		}
	};

}

#ifdef _MSC_VER
#pragma pack(pop)
#endif