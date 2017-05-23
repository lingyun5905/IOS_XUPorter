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

#include "EncryptEnum.h"
#include "CompressEnum.h"
#include "Enums.h"
#include "PNString.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	class CMessage;

	/** \addtogroup net_group
	*  @{
	*/

	/** 
	\~korean
	���۵Ǵ� �޽����� ��� �����Դϴ�. ���� ��� RMI �α׸� ������ ��, ���� �޽����� � �������� ���� ����Ͽ� ����ڿ��� �����մϴ�. 

	\~english
	This is a quick summary of messages being sent. For instance, when tracking RMI log, this shows a summary of the sent messages to user such as which type they are in.

	\~chinese
	??����������驡�������RMI���log��?����?��?�����������?���������?��?��

	\~japanese
	?�ꪵ����ë�?���������êǪ����Ǫ��С�RMI�������檹��������ê���ë�?�����ɪΪ誦�����ҪʪΪ��ʪɪ��峪��ƫ�?��?����ꪷ�ު���
	\~
	*/
	class MessageSummary
	{
	public:
		/** 
		\~korean
		�޽����� ũ���Դϴ�. ProudNet�� �޽��� ���� ������ ������ �������� �ʽ��ϴ�. 

		\~english
		Size of message. This doesn't include other classes than the ProudNet message class.

		\~chinese
		��������᳡�������ProudNet������??�����??��

		\~japanese
		��ë�?���Ϋ������Ǫ���ProudNet�Ϋ�ë�?��ͭ�������ͭ�����ߪ�ު���
		\~
		*/
		int m_payloadLength;

		/** 
		\~korean
		����� �޽����� ũ���Դϴ�.������ ���� �ʾ�����,0�� ���ϴ�. ProudNet�� �޽��� ���� ������ ������ �������� �ʽ��ϴ�. 

		\~english
		Size of compressed message. This doesn't include other classes than the ProudNet message class.

		\~chinese
		??��������᳡�����?��??��?��0��������ProudNet������??�����??��

		\~japanese
		?�ꪵ�쪿��ë�?���Ϋ������Ǫ���?�ꪬ����ʪ����0������ު���ProudNet�Ϋ�ë�?��ͭ�������ͭ�����ߪ�ު���
		\~
		*/
		int m_compressedPayloadLength;

		/** 
		\~korean
		�� �޽����� RMI �޽����� ��� RMI�� ID���Դϴ�. 

		\~english
		RMI ID if a message is RMI.

		\~chinese
		�����������RMI������?��RMI��ID?��

		\~japanese
		���Ϋ�ë�?����RMI��ë�?���Ǫ������ꡢRMI��ID���Ǫ���
		\~
		*/
		RmiID m_rmiID;
		/** 
		\~korean
		�� �޽����� RMI �޽����� ��� RMI�� �Լ����Դϴ�. 

		\~english
		RMI function name if a message is RMI.

		\~chinese
		�����������RMI������?��RMI����?٣��

		\~japanese
		���Ϋ�ë�?����RMI��ë�?���Ǫ������ꡢRMI��??٣�Ǫ���
		\~
		*/
		const PNTCHAR* m_rmiName;
		/** 
		\~korean
		�� �޽����� ������ ��ȣȭ ����Դϴ�. 

		\~english
		The encrypted method of a message.

		\~chinese
		��??����??��ʥ����?��

		\~japanese
		���Ϋ�ë�?������ꬪ��쪿��?�������Ǫ���
		\~
		*/
		EncryptMode m_encryptMode;
		/** 
		\~korean
		�� �޽����� ������ �������Դϴ�.

		\~english
		The compressed method of a message.

		\~chinese
		��??����??��??۰�ҡ�

		\~japanese
		���Ϋ�ë�?������ꬪ��쪿?��۰�ҪǪ���
		\~
		*/
		CompressMode m_compressMode;
	};

	/**  @} */

	/** 
	\~korean
	IRmiStub::BeforeRmiInvocation ���� ���� �޽����� ��� �����Դϴ�. ���� ��� RMI �α׸� ������ ��, ���� �޽����� � �������� ���� ����Ͽ� ����ڿ��� �����մϴ�. 

	\~english
	Summary of received message at IRmiStub::BeforeRmiInvocation. For exmaple, it provide summary to user such as type of message when you tracking RMI log.

	\~chinese
	�IRmiStub::BeforeRmiInvocation �����������驡�������RMI���log��?����?��?������������?���������?��?��

	\~japanese
	IRmiStub::BeforeRmiInvocation �������ë�?���������êǪ����Ǫ��С�RMI�������檹��������ê���ë�?�����ɪ�����ҪʪΪ��ʪɪ��峪��ƫ�?��?����ꪷ�ު���
	\~
	*/
	class BeforeRmiSummary
	{
	public:
		/** 
		\~korean
		�� �޽����� RMI �޽����� ��� RMI�� ID���Դϴ�. 

		\~english
		RMI ID if a message is RMI.

		\~chinese
		�����������RMI������?��RMI��ID?��

		\~japanese
		���Ϋ�ë�?����RMI��ë�?���Ǫ������ꡢRMI��ID���Ǫ���
		\~
		*/
		RmiID m_rmiID;
		/** 
		\~korean
		�� �޽����� RMI �޽����� ��� RMI�� �Լ����Դϴ�. 

		\~english
		RMI function name if a message is RMI.

		\~chinese
		�����������RMI������?��RMI����?٣��

		\~japanese
		���Ϋ�ë�?����RMI��ë�?���Ǫ������ꡢRMI��??٣�Ǫ���
		\~
		*/
		const PNTCHAR* m_rmiName;
		/** 
		\~korean
		���� Host�� HostID �Դϴ�. 

		\~english
		HostID of Host who sent

		\~chinese
		?����Host��Host ID��

		\~japanese
		��ê�Host��HostID�Ǫ���
		\~
		*/
		HostID m_hostID;
		/** 
		\~korean
		����ڰ� ������ hostTag�� �������Դϴ�. 

		\~english
		Pointer of user defined hostTag.

		\~chinese
		��?�����hostTag���?��

		\~japanese
		��?��?����Ҫ���hostTag�Ϋݫ���?�Ǫ���
		\~
		*/
		void* m_hostTag;
	};

	/**  @} */

	/** \addtogroup net_group
	*  @{
	*/

	/** 
	\~korean
	IRmiStub::AfterRmiInvocation ���� ���� �޽����� ��� �����Դϴ�. ���� ��� RMI �α׸� ������ ��, ���� �޽����� � �������� ���� ����Ͽ� ����ڿ��� �����մϴ�. 

	\~english
	Summary of received message at IRmiStub::AfterRmiInvocation. For exmaple, it provide summary to user such as type of message when you tracking RMI log.

	\~chinese
	�IRmiStub::AfterRmiInvocation �����������驡�������RMI���log��?����?��?������������?���������?��?��

	\~japanese
	IRmiStub::AfterRmiInvocation �������ë�?���������êǪ����Ǫ��С�RMI�������檹��������ê���ë�?�����ɪ�����ҪʪΪ��ʪɪ��峪��ƫ�?��?����ꪷ�ު���
	\~
	*/
	class AfterRmiSummary
	{
	public:
		/** 
		\~korean
		�� �޽����� RMI �޽����� ��� RMI�� ID���Դϴ�. 

		\~english
		RMI ID if a message is RMI.

		\~chinese
		�����������RMI��������?��RMI��ID?��

		\~japanese
		���Ϋ�ë�?����RMI��ë�?���Ǫ������ꡢRMI��ID���Ǫ���
		\~
		*/
		RmiID m_rmiID;
		/** 
		\~korean
		�� �޽����� RMI �޽����� ��� RMI�� �Լ����Դϴ�.

		\~english
		RMI function name if a message is RMI.

		\~chinese
		�����������RMI��������?��RMI����?٣��

		\~japanese
		���Ϋ�ë�?����RMI��ë�?���Ǫ������ꡢRMI��??٣�Ǫ���
		\~
		*/
		const PNTCHAR* m_rmiName;
		/** 
		\~korean
		���� Host�� HostID �Դϴ�. 

		\~english
		HostID of Host who sent

		\~chinese
		?����Host��Host ID��

		\~japanese
		��ê�Host��HostID�Ǫ���
		\~
		*/
		HostID m_hostID;
		/** 
		\~korean
		����ڰ� ������ hostTag�� �������Դϴ�. 

		\~english
		Pointer of user defined hostTag.

		\~chinese
		��?�����hostTag���?��

		\~japanese
		��?��?����Ҫ���hostTag�Ϋݫ���?�Ǫ���
		\~
		*/
		void* m_hostTag;
		/** 
		\~korean
		���� RMI�Լ��� ó���Ǵµ� �ɸ��� �ð� 

		\~english
		Time to process received RMI function.

		\~chinese
		���RMI��?��?��?������??��

		\~japanese
		����RMI??��?�⪵���˪���������
		\~
		*/
		uint32_t m_elapsedTime;
	};

	/**  @} */
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif