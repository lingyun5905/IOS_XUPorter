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

#include "./Exception.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud 
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif
	
	extern const char* ConsistencyProblemText;
	
	/** \addtogroup util_group
	*  @{
	*/

	/** 
	\~korean
	double linked list �� �����ϴ� node�̴�.
	- CListOwner �� �ٴ� ��쿡�� ���� ���踦 ������ �� �ִ�. 

	\~english
	node that consist double linked list
	- A linkage can be set only if attached to CListOwner.

	\~chinese
	?��double linked list��node��
	- �����?�� CListOwner%����?�����?��?��?ͧ��

	\~japanese
	double linked list��ϰ������node�Ǫ���
	- ClistOwner����������Ϊ�֧̿?����ϰ�����몳�Ȫ��Ǫ��ު��� 
	\~
	*/
	template<typename T>
	class CListNode
	{
	public:	
		class CListOwner
		{
			T* m_first;
			T* m_last;
			int m_count;

			void AssertInThis(bool expResult)
			{
				if (m_enableAssertInThis && !expResult)
					ThrowException(ConsistencyProblemText);
			}

			// ���� ������ �ϰ��� �˻�
			// �� �Լ��� ������ ������. ���� �� �ʿ��� ��쿡�� ����� ����.
			void AssertConsist()
			{
				if (m_enableAssertInThis)
				{
					T* node = m_first;

					if (m_first == NULL)
					{
						// �ֺ� ����� �˻�
						AssertInThis(m_count == 0);
						AssertInThis(m_last == NULL);
					}

					while (node != NULL)
					{
						// ������ ���鼭 prev-node-next ���� �ϰ��� �˻�
						AssertInThis(node->m_listOwner == this);

						if (node->m_prev == NULL)
						{
							AssertInThis(m_first == node);
						}
						else
						{
							AssertInThis(node->m_prev->m_next == node);
						}
						if (node->m_next == NULL)
						{
							AssertInThis(m_last == node);
						}
						else
						{
							AssertInThis(node->m_next->m_prev == node);
						}
						node = node->m_next;
					}
				}
			}

		public:
			// �� ���� true�� �����ϸ� �ϰ��� �˻縦 �ϴ� ��ƾ�� �۵��Ѵ�.
			// ������ ũ�� �������Ƿ� ���� ���.
			// debug or release ������� �Ѱų� �� �� �־�� �ؼ� �߰���.
			bool m_enableAssertInThis;

			inline CListOwner()
			{
				m_first = NULL;
				m_last = NULL;
				m_count = 0;
				m_enableAssertInThis = false;
			}

			inline ~CListOwner()
			{
				UnlinkAll();
			}

			/**
			\~korean
			����� ��ũ�� �����մϴ�.

			\~english 
			Removed the connected link 

			\~chinese
			?�?����?�ȡ�

			\~japanese
			֧̿���쪿��󫯪���۪��ު���
			\~
			*/
			inline void UnlinkAll()
			{
				while(!IsEmpty())
				{
					Erase(m_first);
				}
			}

			/**
			\~korean
			��尡 ������� Ȯ���Ѵ�. \return ������� true, ������� ������ false ����

			\~english 
			Check to see if the node is empty. \return Return true if empty, false if not. 
			
			\~chinese
			???����������
			\return ����?true����������?����false��

			\~japanese
			��?�ɪ������ƪ��몫���㪷�ު���\return�������ƪ����true�������ƪ��ʪ����false��꫿?��
			\~
			*/
			inline bool IsEmpty() const
			{
				return m_first == NULL;
			}

			// node�� this container���� �����Ѵ�.
			void Erase(T* node)
			{
				// ���� �˻�
				AssertInThis(node->m_listOwner == this);

				T* nextNode = node->m_next;
				T* prevNode = node->m_prev;

				if (nextNode == NULL)
				{
					AssertInThis(m_last == node);
				}

				if (prevNode == NULL)
				{
					AssertInThis(m_first == node);
				}

				// ������ ������Ʈ.
				// �̷��� �˻� ������ ������Ʈ ������ ������� �κи� �����ϴ� ���� ���� ����.
				if (nextNode != NULL)
					nextNode->m_prev = prevNode;

				if (prevNode != NULL)
					prevNode->m_next = nextNode;

				if (nextNode == NULL)
				{
					m_last = prevNode;
				}

				if (prevNode == NULL)
				{
					m_first = nextNode;
				}

				node->m_prev = NULL;
				node->m_next = NULL;
				node->m_listOwner = NULL;

				m_count--;

				AssertConsist();
			}

			// prevNode�� �ڿ� node�� �߰��Ѵ�.
			// prevNode=null�̸� �� �տ� �߰��Ѵ�.
			void Insert(T* prevNode, T* node)
			{
				// ����: �˻縦 ��� ��ġ�� ������ ������ ������ ������ �� ��
				AssertInThis(node->m_listOwner == NULL);

				if (prevNode == NULL)
				{
					// �� �տ� �߰�
					if (m_first != NULL)
					{
						m_first->m_prev = node;
						node->m_next = m_first;
						m_first = node;
					}
					else
					{
						m_first = m_last = node;
					}
				}
				else
				{
					// prevNode �ڿ� �߰�
					AssertInThis(prevNode->m_listOwner == this);

					T* node_next = prevNode->m_next;
					prevNode->m_next = node;
					node->m_prev = prevNode;
					node->m_next = node_next;
					if (node_next == NULL)
					{
						// prevNode�� last����. ���� node�� last�� �Ǿ�� �Ѵ�.
						m_last = node;
					}
					else
					{
						// next�� ���µ� �����ؾ�
						node_next->m_prev = node;
					}
				}
				node->m_listOwner = this;
				m_count++;
				AssertConsist();
			}

			// �� �ڿ� �߰��Ѵ�.
			inline void PushBack(T* node)
			{
				Insert(m_last, node);
			}

			/* ���� ����� ��ġ�� ���ο� ���� ��ü�Ѵ�.
			node: ���� ��� newNode ������ ��� */
			inline void Replace(T* node, T* newNode)
			{
				T* prev = node->m_prev;

				// �Ʒ� erase-insert�� partially done�� �Ǹ� �ȵǹǷ� ���⼭ ���� �˻縦 �� �ع����� �Ѵ�.
				AssertInThis(node->m_listOwner == this);
				AssertInThis(newNode->m_listOwner == NULL);

				Erase(node);
				Insert(prev, newNode);
			}

			/**
			\~korean
			first ��带 ���Ϲ޽��ϴ�.

			\~english 
			Get the first node returned

			\~chinese
			�������first?�á�

			\~japanese
			first ��?�ɪ�꫿?�󪷪ƪ�骤�ު���
			\~
			*/
			inline T* GetFirst() const
			{
				return (T*)m_first;
			}

			/**
			\~korean
			last��带 ���Ϲ޽��ϴ�.

			\~english 
			Get the last node returned

			\~chinese
			�������last?�á�

			\~japanese
			last��?�ɪ�꫿?�󪷪ƪ�骤�ު���
			\~
			*/
			inline T* GetLast() const
			{
				return (T*)m_last;
			}

			/**
			\~korean
			����Ǿ� �ִ� ����� ī��Ʈ�� ���Ϲ޽��ϴ�.

			\~english 
			Get the count of the connected node

			\~chinese
			��������?����?����?��

			\~japanese
			֧̿����ƪ����?�ɪΫ�����Ȫ�꫿?�󪷪ƪ�骤�ު���
			\~
			*/
			inline int GetCount() const
			{
				return m_count;
			}

#if defined(_MSC_VER)
			__declspec(property(get=GetCount)) int Count;
#endif
		};

	private:
		friend class CListOwner;
		T* m_prev, *m_next;
		CListOwner* m_listOwner;

	public:
		inline CListNode(void)
		{
			m_prev = NULL;
			m_next = NULL;
			m_listOwner = NULL;
		}

		inline ~CListNode(void)
		{
			if(m_listOwner!=NULL)
				m_listOwner->Erase((T*)this);
		}

		/**
		\~korean
		�� node�� ������ �ִ� owner�� �����մϴ�.

		\~english 
		Return the owner who has this node

		\~chinese
		����?���node��woner��

		\~japanese
		����node���êƪ���owner��꫿?�󪷪ު���
		\~
		*/
		inline CListOwner* GetListOwner() const 
		{
			return m_listOwner;
		}

		/**
		\~korean
		������带 ���Ϲ޽��ϴ�.

		\~english 
		Get the next node returned

		\~chinese
		�������������?�á�

		\~japanese
		�Ϋ�?�ɪ�꫿?�󪷪ƪ�骤�ު���
		\~
		*/
		inline T* GetNext() const
		{
			return (T*)m_next;
		}

		/**
		\~korean
		���� ��带 ���Ϲ޽��ϴ�.

		\~english 
		Get the previous node returned

		\~chinese
		�������������?�á�

		\~japanese
		���Ϋ�?�ɪ�꫿?�󪷪ƪ�骤�ު���
		\~
		*/
		inline T* GetPrev() const
		{
			return (T*)m_prev;
		}

		/* \~korean owner ���� ��ũ�� �����մϴ�. \~english Remove the link with the owner \~chinese ?�?owner��?�ȡ�
		\~japanese owner�ȪΫ�󫯪���۪��ު���
		�̰� �� ??���
		inline void UnlinkSelf()
		{
			if(m_pListOwner!=NULL)
				m_pListOwner->Erase((T*)this);
		}
\~
*/
	};

	/**  @} */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
