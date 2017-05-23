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

#include "FastMap.h"
#include "FastList.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** 
	\~korean
	����ũ�� ������ �����ϵ�, ���밡���� ���� �����ϴ� ������ �Ѵ�.
	TCP port numberó��, ���� �����ϵ� ���� �ð� ��Ÿ���� �δ� �������� �۵��Ѵ�.
	VLQ ����ȭ�� ���� �ּ����� ���� �����ؼ� �ٷ��.

	\~english TODO:translate needed.
	Generate a unique integer, however it performs the role of generating a recyclable value. 
	Recycle the value as the TCP port number but it operates in the format to have cool time for a certain period of time. 
	To optimize VLQ, generate and handle the minimum value. 
	

	\~chinese
	����unique����?���������ʦ������?�����ġ�
	����TCP port number��???������?��ʿ?����������ʿ??�����ҡ�
	?��?��VLQ����������������???��?�⡣


	\~japanese
	���?������?���������ު����������ʦ������������������ܪ򪷪ު���
	TCP port number�Ϊ誦�ˡ���������Ī��ު������������Ϋ�?�뫿������Ǫ����Ҫ����Ѫ��ު���
	VLQ���������Ϊ��������ڪ����Ϊߪ��������������⪤�ު���

	\~
	*/
	template<typename TYPE>
	class CRecycleNumberFactoryT
	{
	// TODO: Proud.CRecycleHostIDFactory ���� ������ ����. ��, �� ���� ������ Ư�� ���� skip�ϴ� ����� �����ߴ�. ���߿� �ҽ� ����ȭ����. 
	private:
		class CRecycleBucket
		{
		public:
			TYPE m_number;
			TYPE m_recycleCount;
			int64_t m_droppedTime;

			inline CRecycleBucket() 
			{
				m_number = 0;
				m_recycleCount = 0;
				m_droppedTime = 0;
			}
		};

		// �����뿡 �� ���� ���� �ð� ���� ���� ����. �̰��� �� ���� �ּ� �Ⱓ�̴�.
		double m_issueValidTime;

		// ���� �������� �߱��� ��
		TYPE m_lastIssuedValue;

		CFastMap<TYPE,CRecycleBucket> m_dropMap; //���� ������ �����ϱ����� ��.
		CFastList<TYPE> m_dropList; // ������ �����ϱ� ���� ��.

		TYPE NewNumber()
		{
			m_lastIssuedValue = m_lastIssuedValue + 1;

			return m_lastIssuedValue;
		}

		TYPE GetRecycleCount( TYPE hostID )
		{
			CFastMap<TYPE,CRecycleBucket>::iterator itr = m_dropMap.find(hostID);

			if(itr != m_dropMap.end())
			{
				return itr->GetSecond().m_recycleCount;
			}

			return 0;
		}

	public:
		CRecycleNumberFactoryT( double issueValidTime )
		{
			m_issueValidTime = issueValidTime;
			m_lastIssuedValue = 1;
		}

		~CRecycleNumberFactoryT()
		{
			m_lastIssuedValue = 1;
			m_dropMap.Clear();
			m_dropList.Clear();
		}

		// �������� �� �ȵ� ���� ���� ������ �ּ� ��� �ð��� �־ curTime�� �ʿ�
		TYPE Create( int64_t curTime )
		{
			//drop�� �Ȱ��� ���ٸ� ���� �߱�
			if(m_dropList.GetCount() == 0)
			{
				return NewNumber();
			}

			CFastMap<TYPE,CRecycleBucket>::iterator itr = m_dropMap.find(m_dropList.GetHead());

			//droplist�� �ִµ� map�� ���ٴ�...
			if(itr == m_dropMap.end())
			{
				//error! - �̷� ��Ȳ�� ���� �ȵȴ�.
				m_dropList.RemoveHead();
				return NewNumber();
			}

			//�����ð��� �����͸� ����.
			if(curTime - itr->GetSecond().m_droppedTime > m_issueValidTime)
			{
				//���뿡�� ������ ���� droptime�� 0���� ����� �ش�.
				//����� �Ǽ��� drop�� 2 3�� ȣ���ϴ°��� �̿��� ���� �ϱ����� �÷��׸� �����.
				itr->GetSecond().m_droppedTime = 0;
				++(itr->GetSecond().m_recycleCount);

				return m_dropList.RemoveHead();
			}

			//�ð��� �ȵǾ��ٸ� ���� �߱�.
			return NewNumber();
		}

		void Drop( int64_t curTime,TYPE dropID )
		{
			CFastMap<TYPE,CRecycleBucket>::iterator itr = m_dropMap.find(dropID);

			//���� drop�� �Ȱ��� �ִٸ�, droptime�� update�ϰ� addtail�Ѵ�.
			if(itr != m_dropMap.end())
			{
				//Create������ droptime�� 0���� ����� �ش�.
				//����� �Ǽ��� drop�� 2 3�� ȣ���ϴ°��� �̿��� ���� �ϱ����� �÷��׸� �����.
				if(itr->GetSecond().m_droppedTime != 0)
					return;

				itr->GetSecond().m_droppedTime = curTime;

				m_dropList.AddTail(dropID);
				return;
			}

			CRecycleBucket add;
			add.m_droppedTime = curTime;
			add.m_number = dropID;
			add.m_recycleCount = 0;

			m_dropMap.Add(dropID,add);
			m_dropList.AddTail(dropID);
		}


	};

}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
