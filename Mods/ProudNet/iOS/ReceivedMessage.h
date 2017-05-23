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
#include "AddrPort.h"
#include "ProcHeap.h"
#include "CompressEnum.h"
#include "ClassBehavior.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif
	/* 
	\~korean
	���ŵ� �޽���. ���� �뵵��. 

	\~english
	Received messge. Internal purpose.

	\~chinese
	�����������?ݻ�ġ�

	\~japanese
	���᪷����ë�?����?ݻ��Բ�Ǫ���
	\~
	*/
	class CReceivedMessage
	{
		// ���� ����� ũ��. CFinalUserWorkItem�� ������ �ؼ� ���� �ȵǰ� �Ѵ�.
		NO_COPYABLE(CReceivedMessage)

	public:
		// ���� �������� fast heap�� �ܺ� �����ϱ� ������ ��ü �ı��� main ��ü�� ��װ� �� ���� fast heap access�� �ؾ� ������
		// ������ �׷� ����� ������� ���� obj-pool ����� ���� ������ unsafe�� �ƴ�.
		// ����: Final user work item�� ��� �̰��� RMI ID���� �����ϴ� �����̴�. �� MessageType_XXX�� ���ŵ� ���´�.
		CMessage m_unsafeMessage;

		// �۽���
		HostID m_remoteHostID;

		// UDP ������ ��쿡 ��ȿ�� ��� ����
		AddrPort m_remoteAddr_onlyUdp;

		// �����̷� �Դ�?
		bool m_relayed;

		// ACR
		int m_messageID; // m_hasMessgeID=true�϶��� ��ȿ 
		bool m_hasMessageID;

		//double m_actionTime;

		EncryptMode m_encryptMode;
		CompressMode m_compressMode;

		// ���� ��� ȣ�� Ƚ���� �ſ� ���� �޼��������� inline���� �д�.
		inline CReceivedMessage()
		{
			Clear();
		}

		inline CMessage &GetWriteOnlyMessage()
		{
			return m_unsafeMessage;
		}
		inline CMessage &GetReadOnlyMessage()
		{
			return m_unsafeMessage;
		}
		inline AddrPort GetRemoteAddr()
		{
			return m_remoteAddr_onlyUdp;
		}
		inline HostID GetRemoteHostID()
		{
			return m_remoteHostID;
		}
		inline bool IsRelayed()
		{
			return m_relayed;
		}

		// PIDL compiler output���� ȣ���ϹǷ�, getter method�� �ǵ��� ��.
		inline EncryptMode GetEncryptMode()
		{
			return m_encryptMode;
		}

		// PIDL compiler output���� ȣ���ϹǷ�, getter method�� �ǵ��� ��.
		inline CompressMode GetCompressMode()
		{
			return m_compressMode;
		}

		// called by BiasManagedPointer.
		inline void Clear()
		{
			m_relayed = false;
			m_remoteHostID = HostID_None;
			m_remoteAddr_onlyUdp = AddrPort::Unassigned;

			m_messageID = 0;
			m_hasMessageID = false;

			m_encryptMode = EM_None;
			m_compressMode = CM_None;

			m_unsafeMessage.Clear();
		}

	};


#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
