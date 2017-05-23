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

#include <assert.h>
#include "Ptr.h"
#include "BasicTypes.h"
#include "Singleton.h"
#include "Enums.h"
#include <assert.h>

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif
	extern const char* CannotUseFastHeapForFilledCollectionErrorText;

	/** \addtogroup util_group
	*  @{
	*/

	/**

	\~korean
	�ſ� ������ ó�� �Ǵ� Linked List.
	- ���������� CFastHeap �� ����Ͻʽÿ�. �׷��� element�� �߰�/���� �ϴ� ����� �پ����Դϴ�.
	��, <a target="_blank" href="http://guide.nettention.com/cpp_ko#fast_heap" >Fast heap</a> �� ��õ� ���ǻ����� �ؼ��Ͻʽÿ�.
	- CFastArray �ʹ� �ٸ��� class ���� ������, �Ҹ���, ���� ���� �����ڿ� �Բ� ����� �� �ֽ��ϴ�.

	\param E collection�� �׸� Ÿ��.
	\param ETraits Collection �׸��� �ٷ�� Ư��.
	\param AllocT AllocType �� �� �ϳ�.

	\~english
	Linked List that can be processed with extremely fast.
	- Uses CFastHeap internally. Therefore, has little cost at adding/deleting element.
	  However, it must correctly follow all the rules described in <a target="_blank" href="http://guide.nettention.com/cpp_en#fast_heap" >Fast heap</a>.
	- In contrast with CFastArray, classes can be used with constructor, destructor and copy assignment operator.

	\param E clause type of collection
	\param ETraits characteristic that handles collection clause
	\param AllocT one of the values of AllocType

	\~chinese
	��������?����Linked List��
	-?�?ݻ����CFastHeap��??ʦ�?�?element����ʥ/?�?�ġ�
	ӣ?����<a target="_blank" href="http://guide.nettention.com/cpp_zh#fast_heap" >Fast heap</a>��٥��?黡�
	-?CFastArray���ң�ʦ���?����class?Constructor��Destructor��?�???ߩݬ��

	\param E Collection��?��?����
	\param ETraits ����Collection?����������
	\param AllocT AllocType?���顣

	\~japanese
	�������ܪ�������?�⪵��� Linked List.
	- ?ݻ�ܪ� CFastHeap�����Ī��ƪ������������������ element����ʥ/��𶪹��ި�Ī����骻�ު���
	�������� <a target="_blank" href="http://guide.nettention.com/cpp_jp#fast_heap" >Fast heap</a>��٥�ƪ���ƪ�������������������ƪ���������
	- CFastArray �Ȫ��ުê� class������ϰ���(���󫹫ȫ髯��)��������ǫ��ȫ髯����, Copy ������ߩ�(Copy assignment operator)����?�����ĪǪ��ު���

	\param E collection�����ͫ�����
	\param ETraits Collection ���ͪ��⪦����
	\param AllocT AllocType �������1��

	\~
	*/
	template < typename E, typename ETraits = CPNElementTraits< E > >
	class CFastList
	{
	public:
		typedef typename ETraits::INARGTYPE INARGTYPE;

	private:
		class CNode : public __Position
		{
		public:
			inline CNode()
			{
			}
			inline CNode( INARGTYPE element)
				:m_element( element )
			{
			}
			inline ~CNode() throw()
			{
			}

		public:
			CNode* m_pNext;
			CNode* m_pPrev;
			E m_element;

		private:
			CNode( const CNode& ) throw();
		};

	public:

		CFastList() throw()
		{
			m_nElements = 0;
			m_pHead = NULL;
			m_pTail = NULL;
		}

#if defined(_MSC_VER)
		__declspec(property(get = GetCount)) intptr_t Count;
#endif

		inline intptr_t GetCount() const throw()
		{
			return( m_nElements );
		}

		/**
		\~korean
		\return �ƹ��� �����Ͱ� ������ true, �����ϸ� false�� ����

		\~english 
		If there is no data then true, otherwise return false. 

		\~chinese
		\return ?������?����?true�������?����false��

		\~japanese
		\return ����Ϋ�?�����ʪ����true��������false��꫿?�󪷪ު���
		\~
		*/
		inline bool IsEmpty() const throw()
		{
			return( m_nElements == 0 );
		}

		/**
		\~korean
		\return list�� ù��° data�� �����մϴ�.

		\~english 
		Return the first data in the \return list. 

		\~chinese
		\return ����list�����?data��

		\~japanese
		\return list��������?����꫿?�󪷪ު���
		\~
		*/
		inline E& GetHead()
		{
			assert( m_pHead != NULL );
			return( m_pHead->m_element );
		}

		/**
		\~korean
		\return list�� ù��° data�� const ������ �����մϴ�.

		\~english 
		\return the first data in list as a const variable. 

		\~chinese
		\return ����list�����?data?const??��

		\~japanese
		\return list��������?����const??�˫꫿?�󪷪ު���
		\~
		*/
		inline const E& GetHead() const
		{
			assert( m_pHead != NULL );
			return( m_pHead->m_element );
		}

		/**
		\~korean
		\return list�� ������ Data�� �����մϴ�.

		\~english 
		\return the last data in list. 

		\~chinese
		\return ����list������data��

		\~japanese
		\return list��������?����꫿?�󪷪ު���
		\~
		*/
		inline E& GetTail()
		{
			assert( m_pTail != NULL );
			return( m_pTail->m_element );
		}

		/**
		\~korean
		\return list�� ������ Data�� const ������ �����մϴ�.

		\~english 
		\return the last data in list as a const variable. 

		\~chinese
		\return ����list������data?const??��

		\~japanese
		\return list��������?����const??�˫꫿?�󪷪ު���
		\~
		*/
		inline const E& GetTail() const
		{
			assert( m_pTail != NULL );
			return( m_pTail->m_element );
		}

		/**
		\~korean
		list �� ù��° Data�� list������ �����ϰ� ������ �ݴϴ�.
		\return list���� ���ŵ� data

		\~english 
		Deletes the first data within the list and returns it. 
		\return Data deleted from \return list

		\~chinese
		?list??�?����list�����?data��
		\return �list��?���data��

		\~japanese
		List��������?����꫹��?�����۪��ƫ꫿?�󪷪ު���
		\return list�����۪��쪿��?�� 
		\~
		*/
		inline E RemoveHead()
		{
			assert( m_pHead != NULL );

			CNode* pNode = m_pHead;
			E element( pNode->m_element );

			m_pHead = pNode->m_pNext;
			if ( m_pHead != NULL )
			{
				m_pHead->m_pPrev = NULL;
			}
			else
			{
				m_pTail = NULL;
			}
			FreeNode( pNode );

			return( element );
		}

		/**
		\~korean
		list �� ������ Data�� list������ �����ϰ� ������ �ݴϴ�.
		\return list���� ���ŵ� data

		\~english 
		Deletes the first data within the list and returns it. 
		\return Data deleted from \return list

		\~chinese
		?list??�?����list������data��
		\return �list��?���data��

		\~japanese
		List�������Ϋ�?����꫹��?����۪��ƫ꫿?�󪷪ު���
		\return list�����۪��쪿��?��
		\~
		*/
		inline E RemoveTail()
		{
			assert( m_pTail != NULL );

			CNode* pNode = m_pTail;

			E element( pNode->m_element );

			m_pTail = pNode->m_pPrev;
			if ( m_pTail != NULL )
			{
				m_pTail->m_pNext = NULL;
			}
			else
			{
				m_pHead = NULL;
			}
			FreeNode( pNode );

			return( element );
		}

		/**
		\~korean
		list�� ù��° data�� �����մϴ�.

		\~english 
		First data of the list is deleted. 

		\~chinese
		?�list�����?data��

		\~japanese
		List��������?������۪��ު���
		\~
		*/
		inline void RemoveHeadNoReturn() throw()
		{
			assert( m_pHead != NULL );

			CNode* pNode = m_pHead;

			m_pHead = pNode->m_pNext;
			if ( m_pHead != NULL )
			{
				m_pHead->m_pPrev = NULL;
			}
			else
			{
				m_pTail = NULL;
			}
			FreeNode( pNode );
		}

		/**
		\~korean
		list�� ������ data�� �����մϴ�.

		\~english 
		Last data of the list is deleted. 

		\~chinese
		?�list������data��

		\~japanese
		List��������?������۪��ު���
		\~
		*/
		inline void RemoveTailNoReturn() throw()
		{
			assert( m_pTail != NULL );

			CNode* pNode = m_pTail;

			m_pTail = pNode->m_pPrev;
			if ( m_pTail != NULL )
			{
				m_pTail->m_pNext = NULL;
			}
			else
			{
				m_pHead = NULL;
			}
			FreeNode( pNode );
		}

		/**
		\~korean
		Data�� ����ִ� �ش��� �߰��Ѵ�.
		\return ���� �߰��� ����� Position

		\~english 
		An empty header without data is added. 
		\return Position of the newly added node 

		\~chinese
		��ʥdata?����header��
		\return ����ʥ��?��Position��

		\~japanese
		��?���������ƪ���ثë�?����ʥ���ު���
		\return �檿����ʥ���쪿��?�ɪ�Position
		\~
		*/
		inline Proud::Position AddHead()
		{
			CNode* pNode = NewNode( NULL, m_pHead );
			if ( m_pHead != NULL )
			{
				m_pHead->m_pPrev = pNode;
			}
			else
			{
				m_pTail = pNode;
			}
			m_pHead = pNode;

			return( Proud::Position( pNode ) );
		}

		/**
		\~korean
		����� �߰��մϴ�.
		\param element ���ο� ����� ���� Data
		\return ���� �߰��� ����� Position

		\~english 
		Add a header 
		\param element Data to be inserted to a new header
		\return Position of a newly added node

		\~chinese
		��ʥheader��
		\param element ������header?����data��
		\return ����ʥ��?����Position��

		\~japanese
		�ثë�?����ʥ���ު���
		\param element �檷���ثë�?��������?��
		\return �檿����ʥ���쪿��?�ɪ�Position
		\~
		*/
		inline Proud::Position AddHead( INARGTYPE element )
		{
			CNode* pNode;

			pNode = NewNode( element, NULL, m_pHead );

			if ( m_pHead != NULL )
			{
				m_pHead->m_pPrev = pNode;
			}
			else
			{
				m_pTail = pNode;
			}
			m_pHead = pNode;

			return( Proud::Position( pNode ) );
		}

		/**
		\~korean
		����� ���ο� list�� �߰��մϴ�.
		\param plNew ����� �߰��� list

		\~english 
		A new list is added to the header
		\param plNew List to be added to the header 

		\~chinese
		��header��ʥ����list��
		\param plNew ���header��ʥ��list��

		\~japanese
		�ثë�?���檷��List����ʥ���ު���
		\param plNew �ثë�?����ʥ����List
		\~
		*/
		inline void AddHeadList( const CFastList* plNew )
		{
			assert( plNew != NULL );

			Proud::Position pos = plNew->GetTailPosition();
			while ( pos != NULL )
			{
				INARGTYPE element = plNew->GetPrev( pos );
				AddHead( element );
			}
		}

		/**
		\~korean
		list�� �������� �� ��带 �߰��Ѵ�.
		\return ���� �߰��� ����� Position

		\~english 
		An empty node is added to the end of the list. 
		\return Position of the newly added node. 

		\~chinese
		��list��������ʥ��?�á�
		\return ����ʥ��?��Position��

		\~japanese
		List������������?�ɪ���ʥ���ު���
		\return �檿����ʥ���쪿��?�ɪ�Position
		\~
		*/
		inline Proud::Position AddTail()
		{
			CNode* pNode = NewNode( m_pTail, NULL );
			if ( m_pTail != NULL )
			{
				m_pTail->m_pNext = pNode;
			}
			else
			{
				m_pHead = pNode;
			}
			m_pTail = pNode;

			return( Proud::Position( pNode ) );
		}

		/**
		\~korean
		list�� �������� node�� �߰�
		\param element ������ ��忡 ������ Data
		\return ���� �߰��� ����� Position

		\~english 
		Add a node at the end of the list
		\param element Data to be inserted to the last node 
		\return Position of the newly added node

		\~chinese
		��list��������ʥnode��
		\param element ������?��?����data��
		\return ����ʥ��?����Position��

		\~japanese
		list��������node����ʥ
		\param element �����Ϋ�?�ɪ�?�������?��
		\return �檿����ʥ���쪿��?�ɪ�Position
		\~
		*/
		inline Proud::Position AddTail( INARGTYPE element )
		{
			CNode* pNode;

			pNode = NewNode( element, m_pTail, NULL );

			if ( m_pTail != NULL )
			{
				m_pTail->m_pNext = pNode;
			}
			else
			{
				m_pHead = pNode;
			}
			m_pTail = pNode;

			return( Proud::Position( pNode ) );
		}

		/**
		\~korean
		List�� ��������忡 ���ο� List�� �߰�
		\param plNew �߰��� List

		\~english 
		A new list is added to the last node of the list
		\param plNew List to be added 

		\~chinese
		��list������?����ʥ����list��
		\param plNew ���ʥ��list��

		\~japanese
		List��������?�ɪ��檷���꫹�Ȫ���ʥ
		\param plNew ��ʥ����List
		\~
		*/
		inline void AddTailList( const CFastList* plNew )
		{
			assert( plNew != NULL );

			Proud::Position pos = plNew->GetHeadPosition();
			while ( pos != NULL )
			{
				INARGTYPE element = plNew->GetNext( pos );
				AddTail( element );
			}
		}

		/**
		\~korean
		��� �����͸� ����. Clear()�� ����.

		\~english 
		Delete all data. Same as Clear()

		\~chinese
		?����?�ߡ�?Clear()��?��

		\~japanese
		��ƪΫ�?������ۡ� Clear()���Ҫ��Ǫ���
		\~
		*/
		inline void RemoveAll() throw()
		{
			while ( m_nElements > 0 )
			{
				CNode* pKill = m_pHead;
				assert( pKill != NULL );

				m_pHead = m_pHead->m_pNext;
				FreeNode( pKill );
			}

			assert( m_nElements == 0 );
			m_pHead = NULL;
			m_pTail = NULL;
		}

		/**
		\~korean
		��� �����͸� ����.RemoveAll()����.

		\~english 
		Delete all data. Same as RemoveAll()

		\~chinese
		?����?�ߡ�?RemoveAll()��?��

		\~japanese
		��ƪΫ�?������ۡ�RemoveAll()���Ҫ��Ǫ���
		\~
		*/
		inline void Clear() { RemoveAll(); }

		/**
		\~korean
		\return ����� Position�� ����

		\~english 
		\return the position of the header.

		\~chinese
		\return ����header��Position��

		\~japanese
		\return �ثë�?��Position��꫿?��
		\~
		*/
		inline Proud::Position GetHeadPosition() const throw()
		{
			return( Proud::Position( m_pHead ) );
		}

		/**
		\~korean
		\return list�� ������ ����� Position�� ����

		\~english 
		\return the position of the last node of list.

		\~chinese
		\return ����llist������?����Position��
		\~japanese
		\return list��������?�ɪ�Position��꫿?��
		\~
		*/
		inline Proud::Position GetTailPosition() const throw()
		{
			return( Proud::Position( m_pTail ) );
		}

		/**
		\~korean
		���ڷ� ���� Position�� ���� node Position�� ��´�.
		\param pos ���� Position
		\return ���� ����� Data�� ����

		\~english 
		Obtain the next node position of the position inserted as a factor 
		\param pos Current position.
		\return the data of the next node.

		\~chinese
		?��?��?�����Position������node Position��
		\param pos ?���Position��
		\return ��������?����data��

		\~japanese
		\~
		*/
		inline E& GetNext( Proud::Position& pos )
		{
			CNode* pNode;

			assert( pos != NULL );
			pNode = (CNode*)pos;
			pos = Proud::Position( pNode->m_pNext );

			return( pNode->m_element );
		}

		/**
		\~korean
		���ڷ� ���� Position�� ���� node Position�� ��´�.
		\param pos ���� Position
		\return ���� ����� Data�� const������ ����

		\~english 
		Obtain the next node position of the position inserted as a factor
		\param pos Current position
		\return Return the data of the next node

		\~chinese
		?��?��?�����Position������node Position��
		\param pos ?���Position��
		\return ��������?����data?const??��

		\~japanese
		�������쪿Position����node Position����ު���
		\param pos ��� Position
		\return �Ϋ�?�ɪΫ�?����const??�˫꫿?��
		\~
		*/
		inline const E& GetNext( Proud::Position& pos ) const
		{
			CNode* pNode;

			assert( pos != NULL );
			pNode = (CNode*)pos;
			pos = Proud::Position( pNode->m_pNext );

			return( pNode->m_element );
		}

		/**
		\~korean
		���ڷ� ���� Position�� �� node Position�� ��´�.
		\param pos ���� Position
		\return �� ����� Data

		\~english 
		Obtain the previous node position of the position inserted as a factor
		\param pos Current position
		\return Data of the previous node 

		\~chinese
		�������쪿Position������node Position����ު���
		\param pos ?���Position��
		\return ����?����data��

		\~japanese
		�������쪿Position������node Position����ު���
		\param pos ��� Position
		\return ���?�ɪ�Data
		\~
		*/
		inline E& GetPrev( Proud::Position& pos )
		{
			CNode* pNode;

			assert( pos != NULL );
			pNode = (CNode*)pos;
			pos = Proud::Position( pNode->m_pPrev );

			return( pNode->m_element );
		}

		/**
		\~korean
		���ڷ� ���� Position�� �� node Position�� ��´�.
		\param pos ���� Position
		\return �� ����� Data�� const ������ �����Ѵ�.

		\~english 
		Obtain the previous node position of the position inserted as a factor
		\param pos Current position 
		\return Return the data of the previous node as a const variable 

		\~chinese
		?��?��?�����Position������node Position��
		\param pos ?���Position��
		\return ��������?����data?const??��

		\~japanese
		�������쪿Position������node Position����ު���
		\param pos ��� Position
		\return ���?�ɪΫ�?����const ??�˫꫿?�󪷪ު���
		\~
		*/
		inline const E& GetPrev( Proud::Position& pos ) const throw()
		{
			CNode* pNode;

			assert( pos != NULL );
			pNode = (CNode*)pos;
			pos = Proud::Position( pNode->m_pPrev );

			return( pNode->m_element );
		}

		/**
		\~korean
		���� ����� Data �� ��´�.
		\param pos ���� ����� Position
		\return ���� ����� Data

		\~english 
		Obtain the data of the current node 
		\param pos Position of the current node
		\return Data of the current node 

		\~chinese
		?��?�?����data��
		\param pos ?�?����Position��
		\return ?�?����data��

		\~japanese
		���?�ɪΫ�?������ު���
		\param pos ���?�ɪ�Position
		\return ���?�ɪ�Data
		\~
		*/
		inline E& GetAt( Proud::Position pos )
		{
			assert( pos != NULL );
			CNode* pNode = (CNode*)pos;
			return( pNode->m_element );
		}

		/**
		\~korean
		���� ����� Data �� const ������ ��´�.
		\param pos ���� ����� Position
		\return ���� ����� Data�� const ���� ����

		\~english 
		Obtain the data of the current node as a const variable
		\param pos Position of the current node 
		\return Return the const variable of the current node data

		\~chinese
		?��?�?����data?const??��
		\param pos ?�?����Position��
		\return ����?�?����data?const??��

		\~japanese
		���?�ɪΫ�?����const??������롣
		\param pos ���?�ɪ� Position
		\return ���?�ɪΫ�?����const??��꫿?��
		\~
		*/
		inline const E& GetAt( Proud::Position pos ) const
		{
			assert( pos != NULL );
			CNode* pNode = (CNode*)pos;
			return( pNode->m_element );
		}

		/**
		\~korean
		���� Position�� ����Ű�� ����� Data�� �����Ѵ�.
		\param pos ���� ����� Position
		\param element ������ data

		\~english 
		Configure the data of the node pointed by the current position
		\param pos Position of the current node 
		\param element Data to be configured 

		\~chinese
		?��?�Position��?����data��
		\param pos ?�?����Position��
		\return �?����data��


		\~japanese
		���Position��򦪹��?�ɪΫ�?�������Ҫ��ު���
		\param pos ���?�ɪ� Position
		\param element ���Ҫ����?��
		\~
		*/
		inline void SetAt( Proud::Position pos, INARGTYPE element )
		{
			assert( pos != NULL );
			CNode* pNode = (CNode*)pos;
			pNode->m_element = element;
		}

		/**
		\~korean
		���� Position�� ����Ű�� node �� �����ϰ� ���� Position�� ������ �ش�.
		\param pos �����ϰ��� �ϴ� node�� Position
		\return ���ŵ� Position�� ���� Position

		\~english 
		Delete the node pointed by the current position and then return the next position
		\param pos Position of the node to be deleted
		\return Next position of the deleted position 

		\~chinese
		?�?�Position����node����������Position��
		\param pos ��?���node��Position��
		\return ��?���Position������Position��


		\~japanese
		���Position��򦪹��?�ɪ���۪�����Position��꫿?�󪷪ު���
		\param pos ��۪�������?�ɪ� Position
		\return ��۪��쪿Position����Position
		\~
		*/
		inline Proud::Position RemoveAt( Proud::Position pos ) throw()
		{
			Proud::Position newPos = pos;

			GetNext(newPos);  // ���� ��ġ�� �̸� ���д�.
			assert( pos != NULL );

			CNode* pOldNode = (CNode*)pos;

			// remove pOldNode from list
			if ( pOldNode == m_pHead )
			{
				m_pHead = pOldNode->m_pNext;
			}
			else
			{
#if defined(_WIN32)
				assert( AtlIsValidAddress( pOldNode->m_pPrev, sizeof(CNode) ));
#endif
				pOldNode->m_pPrev->m_pNext = pOldNode->m_pNext;
			}
			if ( pOldNode == m_pTail )
			{
				m_pTail = pOldNode->m_pPrev;
			}
			else
			{
#if defined(_WIN32)
				assert( AtlIsValidAddress( pOldNode->m_pNext, sizeof(CNode) ));
#endif
				pOldNode->m_pNext->m_pPrev = pOldNode->m_pPrev;
			}
			FreeNode( pOldNode );

			return newPos;
		}

		/**
		\~korean
		���� Position�� ����Ű�� node�� �տ� ���ο� node�� �߰��Ѵ�.
		\param pos ���� node�� ����Ű�� Position
		\param element �߰��� �� ����� Data

		\~english 
		Add a new node in front of the node pointed by the current position 
		\param pos Position pointing the current node 
		\param element Data of the new node to be added 

		\~chinese
		��?�Position����node������ʥ����node��
		\param pos ���?�node��Position��
		\param element ���ʥ����?����data��

		\~japanese
		���Position��򦪹��?�ɪ�����檷����?�ɪ���ʥ���ު���
		\param pos ���?�ɪ�򦪹Position
		\param element ��ʥ�����檷����?�ɪΫ�?��
		
		\~
		*/
		inline Proud::Position InsertBefore( Proud::Position pos, INARGTYPE element )
		{
#if defined(_WIN32)
			ATLASSERT_VALID(this);
#endif

			if ( pos == NULL )
				return AddHead( element ); // insert before nothing -> head of the list

			// Insert it before position
			CNode* pOldNode = (CNode*)pos;
			CNode* pNewNode = NewNode( element, pOldNode->m_pPrev, pOldNode );

			if ( pOldNode->m_pPrev != NULL )
			{
#if defined(_WIN32)
				assert(AtlIsValidAddress(pOldNode->m_pPrev, sizeof(CNode)));
#endif
				pOldNode->m_pPrev->m_pNext = pNewNode;
			}
			else
			{
				assert( pOldNode == m_pHead );
				m_pHead = pNewNode;
			}
			pOldNode->m_pPrev = pNewNode;

			return( Proud::Position( pNewNode ) );
		}

		/**
		\~korean
		���� Position�� ����Ű�� node�� �ڿ� ���ο� node�� �߰��Ѵ�.
		\param pos ���� node�� ����Ű�� Position
		\param element �߰��� �� ����� Data

		\~english 
		Add a new node behind the node pointed by the current position 
		\param pos Position pointing the current node 
		\param element Data of the new node to be added 

		\~chinese
		��?�Position����node������ʥ����node��
		\param pos ���?�node��Position��
		\param element ���ʥ����?����data��

		\~japanese
		���Position��򦪹��?�ɪ������檷����?�ɪ���ʥ���ު���
		\param pos ���?�ɪ�򦪹Position
		\param element ��ʥ�����檷����?�ɪΫ�?��
		\~
		*/
		inline Proud::Position InsertAfter( Proud::Position pos, INARGTYPE element )
		{
#ifdef _WIN32
			ATLASSERT_VALID(this);
#endif // _WIN32

			if ( pos == NULL )
				return AddTail( element ); // insert after nothing -> tail of the list

			// Insert it after position
			CNode* pOldNode = (CNode*)pos;
			CNode* pNewNode = NewNode( element, pOldNode, pOldNode->m_pNext );

			if ( pOldNode->m_pNext != NULL )
			{
				assert(AtlIsValidAddress(pOldNode->m_pNext, sizeof(CNode)));
				pOldNode->m_pNext->m_pPrev = pNewNode;
			}
			else
			{
				assert( pOldNode == m_pTail );
				m_pTail = pNewNode;
			}
			pOldNode->m_pNext = pNewNode;

			return( Proud::Position( pNewNode ) );
		}

		/**
		\~korean
		Data�� node�� ã�´�.
		\param element ã�� node�� data
		\param posStartAfter �� Position���ĺ��� ���Ͽ� ã�´�.

		\~english 
		Find a node with data
		\param element Data of the node to be searched for
		\param posStartAfter Search by comparing after this position

		\~chinese
		�data??node��
		\param element �?��node��data��
		\param posStartAfter ???Position����?���???��

		\~japanese
		��?���ǫ�?�ɪ������ު���
		\param element ������?�ɪΫ�?��
		\param posStartAfter ����Position�˽�������򪷪������ު���
		\~
		*/
		inline Proud::Position Find( INARGTYPE element, Proud::Position posStartAfter = NULL ) const throw()
		{
#ifdef _WIN32
			ATLASSERT_VALID(this);
#endif // _WIN32

			CNode* pNode = (CNode*)posStartAfter;
			if ( pNode == NULL )
			{
				pNode = m_pHead;  // start at head
			}
			else
			{
#ifdef _WIN32
				assert(AtlIsValidAddress(pNode, sizeof(CNode)));
#endif
				pNode = pNode->m_pNext;  // start after the one specified
			}

			for ( ; pNode != NULL; pNode = pNode->m_pNext )
			{
				if ( ETraits::CompareElements( pNode->m_element, element ) )
					return( Proud::Position( pNode ) );
			}

			return( NULL );
		}

		/**
		\~korean
		����� ���� iElement���� ��ŭ�� ���� node�� Position�� ����
		\param iElement �������� �Ѿ ����� ����
		\return node�� Position

		\~english 
		Return the position of the next node for the number if iElement from the header 
		\param iElement Number of the node to be passed after iElement
		\return Position of node

		\~chinese
		����?header?���?��iElement??����node��Position��
		\param iElement �ԯ?����?����??��
		\return node��Position��

		\~japanese
		�ثë�?����iElement?�������Ϋ�?�ɪ�Position��꫿?��
		\param iElement ���ƪ����?�ɪ�?
		\return node��Position
		\~
		*/
		inline Proud::Position FindIndex( intptr_t iElement ) const throw()
		{
#ifdef _WIN32
			ATLASSERT_VALID(this);
#endif // _WIN32

			if ( iElement >= m_nElements )
				return NULL;  // went too far

			if (m_pHead == NULL)
				return NULL;

			CNode* pNode = m_pHead;
			for ( intptr_t iSearch = 0; iSearch < iElement; iSearch++ )
			{
				pNode = pNode->m_pNext;
			}

			return( Proud::Position( pNode ) );
		}

		/**
		\~korean
		���� Position�� ����Ű�� node�� list�� ó������ ������.
		\param pos ���� node�� Position

		\~english 
		Send the node pointed by the current position to the beginning of the list 
		\param pos Position of the current node 

		\~chinese
		��?���Position����node?����list����������
		\param pos ?�node��Position��

		\~japanese
		���Position��򦪹��?�ɪ�꫹�Ȫ����������ު���
		\param pos ���?�ɪ�Position
		\~
		*/
		inline void MoveToHead( Proud::Position pos )
		{
			assert( pos != NULL );

			CNode* pNode = static_cast< CNode* >( pos );

			if ( pNode == m_pHead )
			{
				// Already at the head
				return;
			}

			if ( pNode->m_pNext == NULL )
			{
				assert( pNode == m_pTail );
				m_pTail = pNode->m_pPrev;
			}
			else
			{
				pNode->m_pNext->m_pPrev = pNode->m_pPrev;
			}

			assert( pNode->m_pPrev != NULL );  // This node can't be the head, since we already checked that case
			pNode->m_pPrev->m_pNext = pNode->m_pNext;

			m_pHead->m_pPrev = pNode;
			pNode->m_pNext = m_pHead;
			pNode->m_pPrev = NULL;
			m_pHead = pNode;
		}

		/**
		\~korean
		���� Position�� ����Ű�� node�� list�� ���������� ������.
		\param pos ���� node�� Position

		\~english 
		Send the node pointed by the current position to the end of the list 
		\param pos Position of the current node 

		\~chinese
		��?�Position����node?����list��������
		\param pos ?�node��Position��

		\~japanese
		���Position��򦪹��?�ɪ�꫹�Ȫ����������ު���
		\param pos ���?�ɪ�Position
		\~
		*/
		inline void MoveToTail( Proud::Position pos )
		{
			assert( pos != NULL );
			CNode* pNode = static_cast< CNode* >( pos );

			if ( pNode == m_pTail )
			{
				// Already at the tail
				return;
			}

			if ( pNode->m_pPrev == NULL )
			{
				assert( pNode == m_pHead );
				m_pHead = pNode->m_pNext;
			}
			else
			{
				pNode->m_pPrev->m_pNext = pNode->m_pNext;
			}

			pNode->m_pNext->m_pPrev = pNode->m_pPrev;

			m_pTail->m_pNext = pNode;
			pNode->m_pPrev = m_pTail;
			pNode->m_pNext = NULL;
			m_pTail = pNode;
		}

		/**
		\~korean
		�� ����� ��ġ�� �ٲ۴�. Elenemt�� ���� Swap���ְԵǸ� ū ���� ���� �� �������� �� ��忡 �ش� ������ ���� �ٲپ��ش�.
		\param pos1 �ٲ� ù��° node�� Position
		\param pos2 �ٲ� �ι�° node�� Position

		\~english 
		Switch the position of the two nodes. As a big waste may occur if you directly swap the elements so you change the relevant pointers of the two nodes. 
		\param pos1 Position of the first node to be changed 
		\param pos2 Position of the second node to be changed

		\~chinese
		��????�������ǡ���������Swap Elenemt��?��?��??����?����???��??�����?��
		\param pos1 ��?�����?node��Position��
		\param pos2 ��?����?node��Position��

		\~japanese
		?��?�ɪ����Ǫ�?���ު���Element������Swap�������?̺���˪ʪ�ު��Ϊǡ�?��?�ɪ���?�ݫ���?��?���ƪ���ު���
		\param pos1 ?����������?�ɪ�Position
		\param pos2 ?����2���ͫ�?�ɪ�Position
		\~
		*/
		void SwapElements( Proud::Position pos1, Proud::Position pos2 ) throw()
		{
			assert( pos1 != NULL );
			assert( pos2 != NULL );

			if ( pos1 == pos2 )
			{
				// Nothing to do
				return;
			}

			CNode* pNode1 = static_cast< CNode* >( pos1 );
			CNode* pNode2 = static_cast< CNode* >( pos2 );
			if ( pNode2->m_pNext == pNode1 )
			{
				// Swap pNode2 and pNode1 so that the next case works
				CNode* pNodeTemp = pNode1;
				pNode1 = pNode2;
				pNode2 = pNodeTemp;
			}
			if ( pNode1->m_pNext == pNode2 )
			{
				// Node1 and Node2 are adjacent
				pNode2->m_pPrev = pNode1->m_pPrev;
				if ( pNode1->m_pPrev != NULL )
				{
					pNode1->m_pPrev->m_pNext = pNode2;
				}
				else
				{
					assert( m_pHead == pNode1 );
					m_pHead = pNode2;
				}
				pNode1->m_pNext = pNode2->m_pNext;
				if ( pNode2->m_pNext != NULL )
				{
					pNode2->m_pNext->m_pPrev = pNode1;
				}
				else
				{
					assert( m_pTail == pNode2 );
					m_pTail = pNode1;
				}
				pNode2->m_pNext = pNode1;
				pNode1->m_pPrev = pNode2;
			}
			else
			{
				// The two nodes are not adjacent
				CNode* pNodeTemp;

				pNodeTemp = pNode1->m_pPrev;
				pNode1->m_pPrev = pNode2->m_pPrev;
				pNode2->m_pPrev = pNodeTemp;

				pNodeTemp = pNode1->m_pNext;
				pNode1->m_pNext = pNode2->m_pNext;
				pNode2->m_pNext = pNodeTemp;

				if ( pNode1->m_pNext != NULL )
				{
					pNode1->m_pNext->m_pPrev = pNode1;
				}
				else
				{
					assert( m_pTail == pNode2 );
					m_pTail = pNode1;
				}
				if ( pNode1->m_pPrev != NULL )
				{
					pNode1->m_pPrev->m_pNext = pNode1;
				}
				else
				{
					assert( m_pHead == pNode2 );
					m_pHead = pNode1;
				}
				if ( pNode2->m_pNext != NULL )
				{
					pNode2->m_pNext->m_pPrev = pNode2;
				}
				else
				{
					assert( m_pTail == pNode1 );
					m_pTail = pNode2;
				}
				if ( pNode2->m_pPrev != NULL )
				{
					pNode2->m_pPrev->m_pNext = pNode2;
				}
				else
				{
					assert( m_pHead == pNode1 );
					m_pHead = pNode2;
				}
			}
		}

#ifdef _DEBUG
		void AssertValid() const
		{
			if ( IsEmpty() )
			{
				// empty list
				assert(m_pHead == NULL);
				assert(m_pTail == NULL);
			}
			else
			{
				// �޸𸮸� �ܴ��� �����Ѵ�.
				CNode* node = m_pHead;
				while(node!=NULL)
				{
					node = node->m_pNext;
				}
				// non-empty list
				// 		assert(AtlIsValidAddress(m_pHead, sizeof(CNode)));
				// 		assert(AtlIsValidAddress(m_pTail, sizeof(CNode)));
			}
		}

#endif  // _DEBUG

		// Implementation
	private:
		CNode* m_pHead;
		CNode* m_pTail;
		intptr_t m_nElements;

	private:
		inline CNode* NewNode( CNode* pPrev, CNode* pNext )
		{
			CNode* ret = (CNode*)CProcHeap::Alloc(sizeof(CNode));
			if(ret == NULL)
				ThrowBadAllocException();

			CallConstructor<CNode>(ret);

			ret->m_pPrev = pPrev;
			ret->m_pNext = pNext;

			m_nElements++;

			return ret;
		}
		inline CNode* NewNode( INARGTYPE element, CNode* pPrev, CNode* pNext )
		{
			CNode* ret = (CNode*)CProcHeap::Alloc(sizeof(CNode));
			if(ret == NULL)
				ThrowBadAllocException();

			CallConstructor<CNode>(ret, element);

			ret->m_pPrev = pPrev;
			ret->m_pNext = pNext;

			m_nElements++;

			return ret;
		}

		inline void FreeNode( CNode* pNode ) throw()
		{
			CallDestructor<CNode>(pNode);

				CProcHeap::Free(pNode);
			m_nElements--;
		}

	public:
		inline ~CFastList() throw()
		{
			RemoveAll();
			assert( m_nElements == 0 );
		}

	private:
		// Private to prevent use
		CFastList( const CFastList& ) throw();
		CFastList& operator=( const CFastList& ) throw();

	public:

		class value_type
		{
		public:
			Proud::Position m_pos;
			CFastList* m_owner;
		};

		class iterator;
		friend class iterator;

#ifndef PROUDNET_NO_CONST_ITERATOR
		class const_iterator;
		friend class const_iterator;

		/**
		\~korean
		STL�� const_iterator�� ���� ������ �Ѵ�.

		\~english
		Performs the same role as const_iterator of STL

		\~chinese
		���?STL��const_iterator��?�����ġ�

		\~japanese
		STL��const_iterator�Ϊ誦����ܪ򪷪ު���
		\~
		*/
		class const_iterator:public value_type
		{
		public:
			inline const_iterator() {}
			inline const_iterator(const iterator& src):value_type(src) {}

			inline const_iterator& operator++()
			{
				// preincrement
                value_type::m_owner->GetNext(value_type::m_pos);
				return (*this);
			}

			inline const_iterator operator++(int)
			{
				// postincrement
				const_iterator _Tmp = *this;
				++*this;
				return (_Tmp);
			}

			inline bool operator==(const const_iterator& a) const
			{
				return value_type::m_pos==a.m_pos && value_type::m_owner==a.m_owner;
			}

			inline bool operator!=(const const_iterator& a) const
			{
				return !(value_type::m_pos==a.m_pos && value_type::m_owner==a.m_owner);
			}

			inline const E& operator*() const
			{
				return value_type::m_owner->GetAt(value_type::m_pos);
			}
		};
#endif
		/**
		\~korean
		STL�� iterator�� ���� ������ �Ѵ�.

		\~english
		Performs the same role as iterator of STL

		\~chinese
		���?STL��iterator��?�����ġ�

		\~japanese
		STL��iterator�Ϊ誦����ܪ򪷪ު���
		\~
		*/
		class iterator:public value_type
		{
		public:
			inline iterator() {}
			inline iterator(const const_iterator& src):value_type(src) {}

			inline bool operator==(const iterator& a) const
			{
				return value_type::m_pos==a.m_pos && value_type::m_owner==a.m_owner;
			}

			inline bool operator!=(const iterator& a) const
			{
				return !(value_type::m_pos==a.m_pos && value_type::m_owner==a.m_owner);
			}

			inline iterator& operator++()
			{
				// preincrement
				value_type::m_owner->GetNext(value_type::m_pos);
				return (*this);
			}

			inline iterator operator++(int)
			{
				// postincrement
				iterator _Tmp = *this;
				++*this;
				return (_Tmp);
			}

			inline E& operator*() const
			{
				return value_type::m_owner->GetAt(value_type::m_pos);
			}
		};

		/**
		\~korean
		STL�� ���� �޼���� ���� ������ �Ѵ�.

		\~english
		Performs the same role as the same named method of STL

		\~chinese
		���?STL����٣۰����?�����ġ�

		\~japanese
		STL����٣�᫽�ëɪΪ誦����ܪ򪷪ު���
		\~
		*/
		inline iterator begin()
		{
			iterator ret;
			ret.m_pos = GetHeadPosition();
			ret.m_owner=this;

			return ret;
		}

		/**
		\~korean
		STL�� ���� �޼���� ���� ������ �Ѵ�.

		\~english
		Performs the same role as the same named method of STL

		\~chinese
		���?STL����٣۰����?�����ġ�

		\~japanese
		STL����٣�᫽�ëɪΪ誦����ܪ򪷪ު���
		\~
		*/
		inline iterator end()
		{
			iterator ret;
			ret.m_pos=NULL;
			ret.m_owner=this;

			return ret;
		}

#ifndef PROUDNET_NO_CONST_ITERATOR
		/**
		\~korean
		STL�� ���� �޼���� ���� ������ �Ѵ�.

		\~english
		Performs the same role as the same named method of STL

		\~chinese
		���?STL����٣۰����?�����ġ�

		\~japanese
		STL����٣�᫽�ëɪΪ誦����ܪ򪷪ު���
		\~
		*/
		inline const_iterator begin() const
		{
			const_iterator ret;
			ret.m_pos = GetHeadPosition();
			ret.m_owner = (CFastList*)this;

			return ret;
		}

		/**
		\~korean
		STL�� ���� �޼���� ���� ������ �Ѵ�.

		\~english
		Performs the same role as the same named method of STL

		\~chinese
		���?STL����٣۰����?�����ġ�

		\~japanese
		STL����٣�᫽�ëɪΪ誦����ܪ򪷪ު���
		\~
		*/
		inline const_iterator end() const
		{
			const_iterator ret;
			ret.m_pos=NULL;
			ret.m_owner = (CFastList*)this;

			return ret;
		}
#endif

		/**
		\~korean
		STL�� ���� �޼���� ���� ������ �Ѵ�.

		\~english
		Performs the same role as the same named method of STL

		\~chinese
		���?STL����٣۰����?�����ġ�

		\~japanese
		STL����٣�᫽�ëɪΪ誦����ܪ򪷪ު���
		\~
		*/
		inline iterator erase(iterator iter)
		{
			if(iter.m_owner!=this)
			{
				ThrowInvalidArgumentException();
			}
			iterator ret = iter;
			ret++;
			RemoveAt(iter.m_pos);

			return ret;
		}

		/**
		\~korean
		���� CFastList �� �ٸ� CFastList �� ������ ������ ���Ѵ�. Data�� ���� ���Ͽ� Ȯ���Ѵ�..
		\param rhs ���� CFastList
		\return ������ true �ٸ��� false ����

		\~english 
		Compare whether the content of the current CFastList and other CFastList are the same. Directly compare the data to confirm. 
		\param rhs CFastList to be compared 
		\return True if the same, otherwise return false. 

		\~chinese
		��??��� CLinkedList%������ CLinkedList%��?��������ҡ�������?data???��
		\param rhs ���?�� CLinkedList%��
		\return ��?��?true��������?����false��

		\~japanese
		���CFastList�����CFastList��?黪��Ҫ��Ǫ��몫�ɪ��������򪷪ު�����?�����������򪷪����㪷�ު���
		\param rhs ���򪹪� CFastList
		\return �Ҫ��Ǫ����true���ު���false��꫿?��
		\~
		*/
		inline bool Equals(const CFastList& rhs) const
		{
			if(rhs.GetCount()!=GetCount())
				return false;

			Proud::Position i1=GetHeadPosition();
			Proud::Position i2=rhs.GetHeadPosition();
			while( i1!=NULL && i2!=NULL )
			{
				if(GetAt(i1)!=rhs.GetAt(i2))
					return false;
				GetNext(i1);
				rhs.GetNext(i2);
			}

			return true;
		}
	};

	/**  @} */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
