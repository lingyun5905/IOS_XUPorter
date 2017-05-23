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
#include <map>
#include "FastHeap.h"
#include "BasicTypes.h"
#include "Singleton.h"
#include "LookasideAllocator.h"
#include "FastArray.h"
#include "Enums.h"
#include "sysutil.h"
#include "Exception.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

#if defined(_MSC_VER)
#pragma warning(disable:4290)
#endif

namespace Proud
{
	/** \addtogroup util_group
	*  @{
	*/

	/**
	\~korean
	(Key,Value) pair�� hash �˰��� ��� map class�Դϴ�. ���� ������ <a target="_blank" href="http://guide.nettention.com/cpp_ko#hash_map" >�� Ŭ����</a> �� �ֽ��ϴ�.
	- CAtlMap�� ������ �����մϴ�. �׷��鼭�� STL.map�� iterator �� �Ϻ� �޼���� �����ϰ� ����� �� �ֽ��ϴ�.
	�Դٰ� .Net framework�� Dictionary class�� ���� �������ε� �� �� �ֽ��ϴ�.
	- �� Ŭ������ iterator�� STL.map�� iterator���� ������ �ξ� ���� ������ ���ϴ�.

	\param K �ݷ����� Ű Ÿ��
	\param V �ݷ����� �� Ÿ��
	\param KTraits �ݷ����� Ű Ÿ���� �ٷ�� Ư���� ������ Ŭ����
	\param VTraits �ݷ����� �� Ÿ���� �ٷ�� Ư���� ������ Ŭ����
	\param AllocT AllocType �� �� �ϳ�

	\~english
	An hash algorithm base map class of (Key,Value) pair. Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#hash_map" >Map class</a> for further detail.
	- Has very same usage as CAtlMap while still can be used same as iterator of STL.map and some methods.
	  Plus, can be used as same format as Dictionary class of .NET framework.
	- The iterator of this class performs much faster that the iterator of STL.map.

	\param K key type of collection
	\param V value tpe of collection
	\param KTraits class that defines the characteristics that handle key type of collection
	\param VTraits class that defines the characteristics that handle value type of collection

	\~chinese
	��(Key,Value) pair��hashߩ����?��map class��???��<a target="_blank" href="http://guide.nettention.com/cpp_zh#hash_map" >Map?</a>%��
	- ? CAtlMap%����۰�����ȡ�����? STL.map%��iterator������۰���������ġ�ʥ߾��?.Net framework ��Dictionary class�����������ҡ�
	- �?��iterator�� STL.map%��iterator?����������������

	\param K collection key?����
	\param V collection??����
	\param KTraits ��?��?��collection��key?����������?��
	\param VTraits ��?��?��collection��??����������?��
	\param AllocT AllocType?�����顣

	\~japanese
	(Key,Value) pair��hash���뫴�꫺��������map class�Ǫ����٪����ϡ�\ref hash_map�˪���ު���
	- CAtlMap�����������Ҫ��Ǫ�����������STL.map��iterator�����ݻ�Ϋ᫽�ëɪ���������Ī��몳�Ȫ��Ǫ��ު���
	�����.Net framework��Dictionary class���Ҫ����ҪǪ��Ū��ު���
	- ���Ϋ��髹��iterator��STL.map��iterator�����������ê��ܪ��Ǫ���
	\param K ���쫯�����Ϋ�?������
	\param V ���쫯�����Ϋ�?������
	\param KTraits ���쫯�����Ϋ�?�����ת��⪦�����������������髹
	\param VTraits ���쫯�����Ϋ�?�����ת��⪦�����������������髹
	\param AllocT AllocType �������

	\~

	example code of traits class

	\code

	class Foo
	{
		public:
		string a;
		int b;
	};

	class FooTraits
	{
	public:
		// returns hash value of element
		uint32_t Hash(const Foo& v)
		{
			// regularily, variables are XORed for hashing values.
			return Hash(v.a) ^ Hash(v.b);
		}

		// true if two values are the same
		inline static bool CompareElements(const Foo& e1, const Foo& e2)
		{
			return e1.a == e2.a && e1.b == e2.b;
		}

		// negative value if left is smaller.
		// zero if the same.
		// positive value if left is larger.
		inline static int CompareElementsOrdered(const Foo& e1, const Foo& e2)
		{
			if (e1.a < e2.a)
				return -1;
			if (e1.a > e2.a)
				return 1;
			else
			{
				return e1.b - e2.b;
			}
		}
	};

	CFastMap<Foo, int, FooTraits> fooToIntMap;

	\endcode

	*/
	template < typename K, typename V, typename KTraits = CPNElementTraits< K >, typename VTraits = CPNElementTraits< V > >
	class CFastMap
	{
	public:
#ifndef PROUDNET_NO_CONST_ITERATOR
		class const_iterator;
		friend class const_iterator;
#endif
		typedef typename KTraits::INARGTYPE KINARGTYPE;
		typedef typename KTraits::OUTARGTYPE KOUTARGTYPE;
		typedef typename VTraits::INARGTYPE VINARGTYPE;
		typedef typename VTraits::OUTARGTYPE VOUTARGTYPE;
		typedef typename CFastMap<K,V>::const_iterator ConstIterType;
	public:
		class CPair : public __Position
		{
		protected:
			inline CPair(KINARGTYPE key) :
				 m_key( key )
				 {
				 }
		private:
			inline CPair& operator =(const CPair&);

		public:
			K m_key;
			V m_value;

		};

	private:
		class CNode :
			public CPair
		{
		public:
			inline CNode( KINARGTYPE key ) :
				CPair( key )
			{
				m_pNext = NULL;
				m_pPrev = NULL;
			}
			inline ~CNode()
			{

			}

		private:
			inline const CNode& operator =(const CNode&);

		public:
			// bin���� ������ node�� ��� next�� �ٸ� bin�� head node�� ����Ų��.  next=NULL�� ��� �� node�� last bin�� last node�̴�.
			// prev�� next�� �ݴ� ������ �Ѵ�. prev = NULL�� ���, �� node�� head bin�� head node�̴�
			CNode *m_pNext, *m_pPrev;

			// �� node�� hashed key ��. rehash�� �� �� ������ hash �Լ� ����� �����ϱ� ����.
			uint32_t m_nHash;

			// �� ��尡 �� ��° bin�� �� �ִ°�.
			// rehash�� �� ������ �ٲ�. �� �ܿ��� �� �ٲ�.
			uint32_t m_nBin;
		};
	private:
		bool m_enableSlowConsistCheck;
		// hash table. �迭�� N��° �׸��� hash % bin size�� N�� ��ü���� linked list head�̴�.
		// �Ҵ�/������ ProudNet DLL�� ��Ÿ�� ������ ���ϱ� ���� CFirstHeap�� ����.
		CNode** m_ppBins;

		// �� bin�� head node�� �ٸ� bin�� tail node�̴�. �� ������ head bin, �� �ٸ� bin�� tail node�� ������ �ƴ�
		// ����̴�. �� iteration�� ���� ������� �ǹ��Ѵ�.
		CNode* m_pHeadBinHead;

		// ���� �������� ����ִ� �׸�
		CNode* m_pTailBinTail;
		// �� map�� �ִ� �� �׸��� ����
		intptr_t m_nElements;

		// hash table ũ��
		uint32_t m_nBins;

		float m_fOptimalLoad;
		float m_fLoThreshold;
		float m_fHiThreshold;
		intptr_t m_nHiRehashThreshold;
		intptr_t m_nLoRehashThreshold;
		uint32_t m_nLockCount;

		CFastHeap* m_refHeap;
	private:
		void InitVars( uint32_t nBins, float fOptimalLoad, float fLoThreshold, float fHiThreshold )
		{
			m_ppBins= NULL;
			m_pHeadBinHead=NULL;
			m_pTailBinTail = NULL;
			m_nBins=nBins ;
			m_nElements= 0 ;
			m_nLockCount=0;  // Start unlocked
			m_fOptimalLoad= fOptimalLoad ;
			m_fLoThreshold= fLoThreshold ;
			m_fHiThreshold= fHiThreshold ;
			m_nHiRehashThreshold= UINT_MAX ;
			m_nLoRehashThreshold= 0 ;

			SetOptimalLoad( fOptimalLoad, fLoThreshold, fHiThreshold, false );
		}

	public:
		/**
		\~korean
		�������Դϴ�.

		\param nBins �⺻ �ؽ� ���̺��� ũ���Դϴ�. �ڼ��� �����ؾ� �� ������ ���ϴ�. ���� ������ <a target="_blank" href="http://guide.nettention.com/cpp_ko#hash_map" >�� Ŭ����</a> �� �ֽ��ϴ�.
		\param fOptimalLoad ���� ���� �����Դϴ�. ���� ������ <a target="_blank" href="http://guide.nettention.com/cpp_ko#hash_map_load" >�� Ŭ������ ����</a> �� �ֽ��ϴ�.
		\param fLoThreshold �ּ� ���� �����Դϴ�. ���� ������ <a target="_blank" href="http://guide.nettention.com/cpp_ko#hash_map_load" >�� Ŭ������ ����</a> �� �ֽ��ϴ�.
		\param fHiThreshold �ִ� ���� �����Դϴ�. ���� ������ <a target="_blank" href="http://guide.nettention.com/cpp_ko#hash_map_load" >�� Ŭ������ ����</a> �� �ֽ��ϴ�.

		\~english
		This is constructor

		\param nBins The size of base hash table. Performs ok when set with prime number. Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#hash_map" >Map class</a> for further detail.
		\param fOptimalLoad Optimized load proportion. Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#hash_map_load" >Load of map class</a> for further detail.
		\param fLoThreshold Minimum load proportion. Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#hash_map_load" >Load of map class</a> for further detail.
		\param fHiThreshold Maximum load proportion. Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#hash_map_load" >Load of map class</a> for further detail.

		\~chinese
		��������

		\param nBins ������hash table����᳡�?��?��?���???��������???��<a target="_blank" href="http://guide.nettention.com/cpp_zh#hash_map" >Map ?��?��</a>%��
		\param fOptimalLoad ��ʢ?�����㡣???�� <a target="_blank" href="http://guide.nettention.com/cpp_zh#hash_map_load" >Map ?��?��</a> %��
		\param fLoThreshold ���?�����㡣???�� <a target="_blank" href="http://guide.nettention.com/cpp_zh#hash_map_load" >Map ?��?��</a> %��
		\param fHiThreshold ����?�����㡣???�� <a target="_blank" href="http://guide.nettention.com/cpp_zh#hash_map_load" >Map ?��?��</a> %��

		\~japanese
		�����Ǫ���
		\param nBins ����ϫë����?�֫�Ϋ������Ǫ����?�����Ҫ��ʪ�������������?�ƪǪ��ު����٪����ϡ�\ref hash_map��?�Ϊ���������
		\param fOptimalLoad ����ݶ������Ǫ����٪����ϡ�\ref hash_map_load��?�Ϊ���������
		\param fLoThreshold ���ݶ������Ǫ����٪����ϡ�\ref hash_map_load��?�Ϊ���������
		\param fHiThreshold ����ݶ������Ǫ����٪����ϡ�\ref hash_map_load��?�Ϊ���������

		\~
		*/
		CFastMap( uint32_t nBins = 17, float fOptimalLoad = 0.75f, float fLoThreshold = 0.25f, float fHiThreshold = 2.25f)
		{
			m_enableSlowConsistCheck = false;
			m_refHeap = NULL;

			assert( nBins > 0 );

			InitVars(nBins, fOptimalLoad, fLoThreshold, fHiThreshold);
		}

#if defined(_MSC_VER)
		/**
		\~korean
		�̹� ���� �ִ� �׸��� ������ ���Ѵ�.

		\~english
		Gets number of item that already owned

		\~chinese
		ϴ�?��?����?�ᡣ

		\~japanese
		?���êƪ�������?��ϴ��ު���
		\~
		*/
		__declspec(property(get = GetCount)) intptr_t Count;
#endif

		inline intptr_t GetCount() const throw()
		{
			return( m_nElements );
		}

		/**
		\~korean
		�̹� ���� �ִ� �׸��� ������ ���Ѵ�.

		\~english
		Gets number of item that already owned

		\~chinese
		ϴ�?��?����?�ᡣ

		\~japanese
		?���êƪ�������?��ϴ��ު���
		\~
		*/
		inline intptr_t size() const
		{
			return GetCount();
		}

		/**
		\~korean
		�ֺ� �����ΰ�?

		\~english
		Is it empty?

		\~chinese
		����?����

		\~japanese
		����?���Ǫ�����
		\~
		*/
		inline bool IsEmpty() const throw()
		{
			return( m_nElements == 0 );
		}

		/**
		\~korean
		key�� �����ϴ� value�� ��´�.
		\param [in] key ã�� Ű
		\param [out] value ã�� Ű�� �����ϴ� ���� ����� ��
		\return key�� ã������ true�� �����Ѵ�.

		\~english
		Gets value correspnds to key
		\param [in] key key to find
		\param [out] value a space where the value corresponds to the key found to be stored
		\return returns true if key is found.

		\~chinese
		?��??key��value��
		\param [in] key �?��key��
		\param [out] value ?���?��key��?���?�������ǡ�
		\return ?��key��?����true��

		\~japanese
		Key��??����value����ު���
		\param [in] key ������?
		\param [out] value ��������?��??����������������
		\return key���������顢true��꫿?�󪷪ު���

		\~
		 */
		bool Lookup( KINARGTYPE key, VOUTARGTYPE value ) const
		{
			// �� ���� ���� ã�ƹ�����.
			if(m_nElements == 0)
				return false;

			uint32_t iBin;
			uint32_t nHash;
			CNode* pNode;

			pNode = GetNode( key, iBin, nHash );
			if ( pNode == NULL )
			{
				return false;
			}

			value = pNode->m_value;

			return true;
		}

		/**
		\~korean
		key�� �����ϴ� value�� ã��, CPair ��ü�� �����Ѵ�.

		\~english
		Finds value corrsponds to key but returns CPair object

		\~chinese
		???key��value������ CPair%?�ڡ�

		\~japanese
		Key��??����value�������ު�����CPair���֫������Ȫ�꫿?�󪷪ު���
		\~
		*/
		const CPair* Lookup( KINARGTYPE key ) const throw()
		{
			// �� ���� ���� ã�ƹ�����.
			if(m_nElements == 0)
				return NULL;

			uint32_t iBin;
			uint32_t nHash;
			CNode* pNode;

			pNode = GetNode( key, iBin, nHash );

			return( pNode );
		}

		/**
		\~korean
		key�� �����ϴ� value�� ã��, CPair ��ü�� �����Ѵ�.

		\~english
		Finds value corrsponds to key but returns CPair object.

		\~chinese
		???key��value������ CPair%?�ڡ�

		\~japanese
		Key��??����value�������ު�����CPair���֫������Ȫ�꫿?�󪷪ު���
		\~
		*/
		CPair* Lookup( KINARGTYPE key ) throw()
		{
			// �� ���� ���� ã�ƹ�����.
			if(m_nElements == 0)
				return NULL;

			uint32_t iBin;
			uint32_t nHash;
			CNode* pNode;

			pNode = GetNode( key, iBin, nHash );

			return( pNode );
		}

		/**
		\~korean
		key�� �����ϴ� value ���� ã�´�. ���� ��� �� entry�� ���������� �����

		\return �̹� �ְų� ���� �߰��� entry�� reference�� �����Ѵ�.

		\~english
		Finds value corrsponds to key. If not existed then internally creates a new entry.

		\return returns reference of entry that is eiter alread existing or newly added

		\~chinese
		???key��value?��?����?�?ݻ?������entry��

		\return ��������������ʥ��entry��reference��

		\~japanese
		key��??����value���������ު���������檷��entry��?ݻ�ܪ��ª�ު���
		\return ?�˪��몫���檿����ʥ���쪿entry��reference��꫿?�󪷪ު���

		\~
		*/
		V& operator[]( KINARGTYPE key ) throw()
		{
			CNode* pNode;
			uint32_t iBin;
			uint32_t nHash;

			pNode = GetNode( key, /*out */ iBin, /*out */ nHash);
			if ( pNode == NULL )
			{
				pNode = CreateNode( key, iBin, nHash );
			}

			return( pNode->m_value );
		}

		/**
		\~korean
		key,value pair�� ���� �߰��Ѵ�. �̹� ������ ��������Ʈ�Ѵ�.
		\param key �߰��� Ű��
		\param value �߰��� �� ��ü
		\return �߰��� �� �� �߰� ��ġ�� ����Ű�� ������. Position�� ���̽� Ŭ�����̹Ƿ� �ٷ� Position�� ���ϰ����� �����ص� �ȴ�.

		\~english
		Newly addes key and value pair. If already exist then overwrites.
		\param key key value to be added
		\param value value object to be added
		\return pointer that points additional location after adding. Since Position is a base class, it is possible to regards Position as return value.

		\~chinese
		����ʥkey,value pair�������?�����̡�
		\param key ���ʥ��key?��
		\param value ���ʥ��??�ڡ�
		\return ��ʥ�������ʥ�������?����?Position����??��ʦ�������Position����������?��

		\~japanese
		key,value pair���檿����ʥ���ު���?�˪���Ы�?��?�髤�Ȫ��ު���
		\param key ��ʥ���뫭?��
		\param value ��ʥ���뫪�֫�������
		\return ��ʥ�򪷪�������ʥ���Ǫ�򦪹�ݫ���?��Position����?�����髹�ʪΪǡ�����Position��꫿?������̸�ʪ��ƪ��ު��Ǫ���
 
		\~
		*/
		CNode* SetAt( KINARGTYPE key, VINARGTYPE value )
		{
			CNode* pNode;
			uint32_t iBin;
			uint32_t nHash;

			pNode = GetNode( key, iBin, nHash );
			if ( pNode == NULL )
			{
				pNode = CreateNode( key, iBin, nHash );
        pNode->m_value = value;
			}
			else
			{
				pNode->m_value = value;
			}

			return pNode;/*( Position( pNode ) ); */
		}

		/**
		\~korean
		������ ���� Position ��ü�� ����Ű�� ���� value�� ���� �ִ´�.
		\param pos value�� ���� node�� Position
		\param value node�� ���� data

		\~english 
		Insert a new value of the place where the previously obtained position object points at. 
		\param pos Position of the node to insert the value
		\param value Data to be inserted into the node

		\~chinese
		��?�����?����Position?�������������value��
		\param pos �ۯ��value��node��Position��
		\param value ���nodeۯ����data��

		\~japanese
		���������Position���֫������Ȫ�򦪹ᶪ�value���檿������ު���
		\param pos value�������node��Position
		\param value node��������?��

		\~
		*/
		void SetValueAt( Proud::Position pos, VINARGTYPE value )
		{
			if( pos == NULL )
			{
				assert(0);
			}
			else
			{
				CNode* pNode = static_cast< CNode* >( pos );
				pNode->m_value = value;
			}
		}

		/**
		\~korean
		\copydoc ����

		\~english
		\copydoc Remove

		\~chinese
		\copydoc Remove

		\~japanese
		\copydoc Remove
		\~
		*/
		bool RemoveKey( KINARGTYPE key,bool rehashOnNeed=false ) throw()
		{
			CNode* pNode;
			uint32_t iBin;
			uint32_t nHash;

			pNode = GetNode( key, iBin, nHash );
			if ( pNode == NULL )
			{
				return( false );
			}

			RemoveNode( pNode,rehashOnNeed );

			return( true );
		}

		/**
		\~korean
		������ ����

		\~english
		Completely empty it

		\~chinese
		����?����

		\~japanese
		����������˪��ު���
		\~
		*/
		inline void Clear()
		{
			RemoveAll();
		}

		/**
		\~korean
		key�� ����Ű�� �׸��� ã�� �����Ѵ�.
		\param key ������ Ű
		\param rehashOnNeed true�� ���, hash table�� ����� �۾��� ��� hash table�� �������Ѵ�.
		�̶� ������̴� iterator�� Position �� ���� ��� �̴� ��ȿȭ���� �����ؾ� �Ѵ�.
		\return ã�Ƽ� ���Ÿ� ������ true�� �����Ѵ�. ��ã������ false��.

		\~english
		Finds the clause pointed by key then removes it.
		\param key key to be removed
		\param rehashOnNeed if ture then hash table is re-modified when hash table became small enough
		Must pay attention to the fact that if there exists either iterator and/or Position during the process, it/they will be nullified.
		\return returns if found and removed. False if failed to find.

		\~chinese
		?��key�����?��??𶡣
		\param key �?���key��
		\param rehashOnNeed ��true��?���hash table����?�?����?����?��hash table��
		����??��������������iterator �� Position�����?��?������
		\return ?��??�����?����true��?��?����?��false��

		\~japanese
		��?��򦪹���ͪ���������۪��ު���
		\param key ��۪��뫭?
		\param rehashOnNeed true�����ꡢhash table�����ᳪ����ʪê����ꡢhash table������ڪ��ު��� 
		���������Ūêƪ���iterator��Position���������ꡢ����Ϫ�?������몳�Ȫ���򪷪ʪ���Ъʪ�ު���
		\return ��������۪����顢true��꫿?�󪷪ު����������Ȫ��Ǫ��ʪ��ê���false�Ǫ���

		\~
		*/
		inline bool Remove( KINARGTYPE key,bool rehashOnNeed=false )
		{
			return RemoveKey(key,rehashOnNeed);
		}

		/**
		\~korean

		\~english

		\~chinese

		\~japanese

		\~
		\copydoc Clear
		*/
		void RemoveAll()
		{
			DisableAutoRehash();

			AssertConsist();

			// ��� node���� �����Ѵ�.
			// map�� ��� node���� bin ���� �����ϰ� ��� ����Ǿ� �ִ�.
			CNode* pNode;
			int removeCount = 0;
			for (pNode = m_pHeadBinHead; pNode != NULL; )
			{
				CNode* pNext = pNode->m_pNext; // save
				assert(m_nElements > 0);
				FreeNode(pNode,false);
				pNode = pNext; // restore
				removeCount++;
			}

			assert(m_nElements == 0);

			CProcHeap::Free(m_ppBins);
			m_ppBins = NULL;

			m_nElements = 0;

			m_pHeadBinHead = NULL;

			m_pTailBinTail = NULL;

			AssertConsist();

			if ( !IsLocked() )
			{
				if(!InitHashTable( PickSize( m_nElements ), false ))
					ThrowBadAllocException();
			}

			AssertConsist();

			EnableAutoRehash();
		}

		/**
		\~korean
		Position�� ����Ű�� ���� key-value pair�� �����Ѵ�.
		\param pos ������ ���� Position ��. �� ���� ��ȿ�� ���̾�� �Ѵ�!
		\param rehashOnNeed true�� ��, hash table�� ����� �۾��� ��� hash table�� �������Ѵ�.
		�̶� ������̴� iterator�� Position �� ���� ��� �̴� ��ȿȭ���� �����ؾ� �Ѵ�.

		\~english
		Removes key-value pair of where pointed by Position
		\param pos Position value acquired before. This value must be valid!
		\param rehashOnNeed if ture then hash table is re-modified when hash table became small enough
		Must pay attention to the fact that if there exists either iterator and/or Position during the process, it/they will be nullified.

		\~chinese
		?�Position������۰��key-value pair��
		\param pos ���?����Position?���?����������?��
		\param rehashOnNeed true?����hash table����?᳣�?�����?��hash table��
		����??�������iterator��Position�����???��������

		\~japanese
		Position��򦪹ᶪ�key-value pair����۪��ު���
		\param pos ���������Position��������������?�����ǪϪʪ���Ъʪ�ު���
		\param rehashOnNeed true������hash table�����ᳪ����ʪê����ꡢhash table������ڪ��ު��� 
		���������Ūêƪ��� iterator��Position���������ꡢ�������?������몳���Ȫ���򪷪ʪ���Ъʪ�ު���

		\~
		*/
		void RemoveAtPos( Proud::Position pos ,bool rehashOnNeed=false) throw()
		{
			assert( pos != NULL );

			CNode* pNode = static_cast< CNode* >( pos );

			RemoveNode( pNode ,rehashOnNeed);
		}

		/**
		\~korean
		�����ϰ� �ִ� �׸� �� �� ���� ���� ��´�. �ַ� iteration�� ���ؼ� ���δ�.
		GetNext ���� �Ἥ ���� �׸��� iteration�� ���� �� �ִ�.
		\return �Ǿ� �׸��� Position

		\~english
		Gets the foremost thing among possessed clauses. Mainly used for iteration.
		It is possible to perform iteration to next clause by using GetNext or others.
		\return position of the foremost clause

		\~chinese
		?���?����?������������?�͡���?��iteration��ġ�
		�����GetNext���������?��iteration������?�͡�
		\return ������?����Position��

		\~japanese
		���󪷪ƪ������ͪΪ�������໪Ϊ�Ϊ���ު�����iteration�Ϊ�����Ū��ު���
		GetNext �ʪɪ��Ūê������ͪ�iteration�����������Ȫ��Ǫ��ު���
		\return ����໪����ͪ�Position

		\~
		*/
		inline Proud::Position GetStartPosition() const throw()
		{
			if ( IsEmpty() )
			{
				return( NULL );
			}

			return Proud::Position(m_pHeadBinHead);
		}

		/**
		\~korean
		�����ϰ� �ִ� �׸� �� �� ���� ���� ��´�.�ַ� reverse_iteration�� ���ؼ� ���δ�.
		GetPrev ���� �Ἥ ���� �׸��� iteration�� ���� ���ִ�.
		\return �� ������ �׸��� Position

		\~english
		Gets the very last thing among possessed clauses. Mainly used for reverse_iteration.
		It is possible to perform iteration to next clause by using GetPrev or others.
		\return position of the last clause

		\~chinese
		?��?����?������������?�͡���?��reverse_iteration��ġ�
		�����GetPrev���������?��iteration������?�͡�
		\return ����?����Position��


		\~japanese
		���󪷪ƪ������ͪΪ�����������Ϊ�Ϊ���ު�����reverse_iteration�Ϊ�����Ū��ު���
		GetPrev �ʪɪ��Ūê������ͪ�iteration���������ު���
		\return �������������ͪ�Position

		\~
		*/
		inline Proud::Position GetEndPosition() const throw()
		{
			if( IsEmpty() )
			{
				return ( NULL );
			}

			return Proud::Position(m_pTailBinTail);
		}


		/**
		\~korean
		���� �׸��� ��´�.
		\param [in,out] pos ���� �׸��� Position��
		\param [out] key �����׸��� key
		\param [out] value ���� �׸��� ��

		\~english 
		Obtain the following
		\param [in,out] Position value of the next item. 
		\param [out] Key of the next item. 
		\param [out] Value of the next item. 

		\~chinese
		?������?�͡�
		\param [in,out] pos ����?����Position?��
		\param [out] key ����?����key��
		\param [out] value ����?����?��

		\~japanese
		�����ͪ���ު���
		\param [in,out] pos �����ͪ�Position��
		\param [out] key �����ͪ�key
		\param [out] value �����ͪ���

		\~
		*/
		void GetNextAssoc( Proud::Position& pos, KOUTARGTYPE key, VOUTARGTYPE value ) const
		{
			CNode* pNode;
			CNode* pNext;

			assert( m_ppBins != NULL );
			assert( pos != NULL );

			pNode = (CNode*)pos;
			pNext = pNode != NULL? pNode->m_pNext : NULL; //FindNextNode( pNode );

			pos = Proud::Position( pNext );
			key = pNode->m_key;
			value = pNode->m_value;
		}

		/**
		\~korean
		���� �׸��� ��´�.
		\param pos ����Ű�� �ִ� node�� ���� Position�� ���´�.
		\return ���� node�� const CPair���� ����

		\~english 
		Obtain the following:
		\param pos Obtain the next position of the node being pointed at. 
		\return Return the const CPair value of the next node

		\~chinese
		?��������?�͡�
		\param pos ?������node������Position��
		\return ��������node��const CPair%?��

		\~japanese
		�����ͪ���ު���
		\param pos 򦪷�ƪ���node����Position����ƪ��ު���
		\return ��node��const CPair����꫿?��

		\~
		*/
		const CPair* GetNext( Proud::Position& pos ) const throw()
		{
			CNode* pNode;
			CNode* pNext;

			assert( m_ppBins != NULL );
			assert( pos != NULL );

			pNode = (CNode*)pos;
			pNext = pNode != NULL? pNode->m_pNext : NULL; //FindNextNode( pNode );

			pos = Proud::Position( pNext );

			return( pNode );
		}

		/**
		\~korean
		���� �׸��� ��´�.
		\param pos pos ����Ű�� �ִ� node�� ���� Position�� ���´�.
		\return ���� node�� \ref CPair ���� ����

		\~english 
		Obtain the next item.
		\param pos Obtain the next position of the node being pointed at. 
		\return Return the const CPair value of the next node


		\~chinese
		?��������?�͡�
		\param pos pos?������node������Position��
		\return ��������node��\ref CPair%? ��

		\~japanese
		�����ͪ���ު���
		\param pos pos 򦪷�ƪ���node����Position����ު���
		\return ��node��\ref CPair ����꫿?��

		\~
		*/
		CPair* GetNext( Proud::Position& pos ) throw()
		{
			assert( m_ppBins != NULL );
			assert( pos != NULL );

			CNode* pNode = static_cast< CNode* >( pos );
			CNode* pNext = pNode != NULL? pNode->m_pNext : NULL; //FindNextNode( pNode );

			pos = Proud::Position( pNext );

			return( pNode );
		}

		/**
		\~korean
		���� �׸��� ��´�.
		\param pos pos�� ����Ű�� �ִ� node�� ���� Position�� ���´�.
		\return ��������� \ref CPair ��

		\~english 
		Obtain the previous item. 
		\param pos Obtain the next position of the node being pointed at by this pos.
		\return Key value of the next node. 

		\~chinese
		?������?�͡�
		\param pos ?��pos����node������Position��
		\return ����node��\ref CPair%? ��

		\~japanese
		�������ͪ���ު���
		\param pos pos��򦪷�ƪ���node������Position����ƪ��ު���
		\return ����?�ɪ�\ref CPair��

		\~
		*/
		CPair* GetPrev( Proud::Position& pos ) throw()
		{
			assert( m_ppBins != NULL );
			assert( pos != NULL );

			CNode* pNode = static_cast< CNode* >( pos );
			CNode* pNext = FindPrevNode( pNode );

			pos = Proud::Position( pNext );

			return( pNode );
		}

		/**
		\~korean
		���� �׸��� ��´�.
		\param pos �� pos ����Ű�� �ִ� node�� ���� Position�� ���´�.
		\return ���� node�� key��

		\~english 
		Obtain the next item
		\param pos Obtain the next position of the node being pointed at by this pos.
		\return const value of the next node 

		\~chinese
		?������?�͡�
		\param pos ?��??pos����node������Position��
		\return ����node��key?��

		\~japanese
		�����ͪ���ު���
		\param pos ����pos��򦪷�ƪ���node����Position����ƪ��ު���
		\return ��node��key��

		\~
		*/
		const K& GetNextKey( Proud::Position& pos ) const
		{
			CNode* pNode;
			CNode* pNext;

			assert( m_ppBins != NULL );
			assert( pos != NULL );

			pNode = (CNode*)pos;
			pNext = pNode != NULL? pNode->m_pNext : NULL; //FindNextNode( pNode );

			pos = Proud::Position( pNext );

			return( pNode->m_key );
		}

		/**
		\~korean
		���� �׸��� ��´�.
		\param pos �� pos ����Ű�� �ִ� node�� ���� Position�� ���´�.
		\return ���� node�� const value��

		\~english 
		Obtain the next item
		\param pos Obtain the next position of the node being pointed at by this pos.
		\return const value of the next node 

		\~chinese
		?������?�͡�
		\param pos ?��??pos����node������Position��
		\return ����node��const value?��

		\~japanese
		�����ͪ���ު���
		\param pos ����pos��򦪷�ƪ���node����Position����ƪ��ު���
		\return ��node��const value��

		\~
		*/
		const V& GetNextValue( Proud::Position& pos ) const
		{
			CNode* pNode;
			CNode* pNext;

			assert( m_ppBins != NULL );
			assert( pos != NULL );

			pNode = (CNode*)pos;
			pNext = pNode != NULL? pNode->m_pNext : NULL; //FindNextNode( pNode );

			pos = Proud::Position( pNext );

			return( pNode->m_value );
		}

		/**
		\~korean
		���� �׸��� ��´�.
		\param pos �� pos ����Ű�� �ִ� node�� ���� Position�� ���´�.
		\return ���� node�� value��

		\~english 
		Obtain the next item
		\param pos Obtain the next position of the node being pointed at by this pos.
		\return Value of the next node

		\~chinese
		?��������?�͡�
		\param pos ?��??pos����node������Position��
		\return ����node��value?��

		\~japanese
		�����ͪ���ު���
		\param pos ����pos��򦪷�ƪ���node����Position����ƪ��ު���
		\return ��node��value��

		\~
		*/
		V& GetNextValue( Proud::Position& pos )
		{
			CNode* pNode;
			CNode* pNext;

			assert( m_ppBins != NULL );
			assert( pos != NULL );

			pNode = (CNode*)pos;
			pNext = pNode != NULL? pNode->m_pNext : NULL; //FindNextNode( pNode );

			pos = Proud::Position( pNext );

			return( pNode->m_value );
		}

		/**
		\~korean
		Position�� ����Ű�� �ִ� ���� key�� value�� ��´�.
		\param pos ��带 ����Ű�� Position
		\param key �ش����� key�� ����
		\param value �ش� ����� data�� ����

		\~english 
		Obtain the key and value of the place where the position is pointing at. 
		\param pos Position pointing the node 
		\param key Obtain the key of the node
		\param value Obtain the data of the node

		\~chinese
		?��Position����������key��value��
		\param pos ���node��Position��
		\param key ?����?node��key��
		\param value ?����?node��data��

		\~japanese
		Position��򦪷�ƪ���ᶪ�key��value����ު���
		\param pos ��?�ɪ�򦪹Position
		\param key ��?��?�ɪ�key����ƪ��ު���
		\param value ��?��?�ɪΫ�?������ƪ��ު���

		\~
		*/
		inline void GetAt( Proud::Position pos, KOUTARGTYPE key, VOUTARGTYPE value ) const
		{
			assert( pos != NULL );

			CNode* pNode = static_cast< CNode* >( pos );

			key = pNode->m_key;
			value = pNode->m_value;
		}

		/**
		\~korean
		�ش� index�� �ִ� ���� key�� value�� ��´�.
		\param index ù��° ������ ���� �� index��ŭ �������� �̵��Ѵ�.
		\return ã�� ����� CPair

		\~english 
		Obtain the key and value of the place located in the index 
		\param index Move to the next node as much as this index from the first information. 
		\return CPair of the searched node

		\~chinese
		?�����?index������key��value��
		\param index ?���?����?��?���?���index�������?������?node��
		\return ?����node�� CPair%��

		\~japanese
		��?index�˪���ᶪ�key��value����ު���
		\param index �����ͪ����ê��骳��index�����Ϋ�?�ɪ���Ѫ��ު���
		\return ��������?�ɪ�CPair

		\~
		*/
		inline CPair* GetPairByIndex(int index) throw()
		{
			assert( index < (int)GetCount() );

			CNode* node = m_pHeadBinHead;

			for (int i = 0; i < index; ++i)
				node = node->m_pNext;

			return( static_cast< CPair* >( node ) );
		}

		/**
		\~korean
		�ش� index�� �ִ� ���� key�� value�� ��´�.
		\param index ù��° ������ ���� �� index��ŭ �������� �̵��Ѵ�.
		\return ã�� ����� const CPair

		\~english 
		Obtain the key and value of the place located in the index
		\param index Move to the next node as much as this index from the first information.
		\return const CPair of the searched node

		\~chinese
		?�����?index������key��value��
		\param index ?���?����?��?���?���index�������?������?node��
		\return ?����node��const CPair%��

		\~japanese
		��?index�˪���ᶪ�key��value����ު���
		\param index �����ͪ����ê��骳��index�����Ϋ�?�ɪ���Ѫ��ު���
		\return ��������?�ɪ�const CPair

		\~
		*/
		inline const CPair* GetPairByIndex(int index) const throw()
		{
			assert( index < (int)GetCount() );

			CNode* node = m_pHeadBinHead;

			for (int i = 0; i < index; ++i)
				node = node->m_pNext;

			 return( static_cast< CPair* >( node ) );
		}

		/**
		\~korean
		Position�� ����Ű�� �ִ� ���� key�� value�� ��´�.
		\param pos Position����
		\return Position�� �ش��ϴ� CPair

		\~english 
		Obtain the key and value of the place where the position is pointing at
		\param pos Position information
		\return CPair corresponding to the position

		\~chinese
		?��Position�����������key��value��
		\param pos Position���ӡ�
		\return ��?��Position�� CPair%��

		\~japanese
		Position��򦪷�ƪ���ᶪ�key��value����ު���
		\param pos Position����
		\return Position����?����CPair

		\~
		*/
		inline CPair* GetAt( Proud::Position pos ) throw()
		{
			assert( pos != NULL );

			return( static_cast< CPair* >( pos ) );
		}

		/**
		\~korean
		Position�� ����Ű�� �ִ� ���� key�� value�� ��´�.
		\param pos Position����
		\return Position�� �ش��ϴ� const CPair

		\~english 
		Obtain the key and value of the place where the position is pointing at
		\param pos Position information
		\return const CPair corresponding to the position

		\~chinese
		?��Position�����������key��value��
		\param pos Position���ӡ�
		\return ��?��Position��const CPair%��

		\~japanese
		Position��򦪷�ƪ���ᶪ�key��value����ު���
		\param pos Position����
		\return Position����?����const CPair

		\~
		 */
		inline const CPair* GetAt( Proud::Position pos ) const throw()
		{
			assert( pos != NULL );

			return( static_cast< const CPair* >( pos ) );
		}

		/**
		\~korean
		Position�� ����Ű�� �ִ� ���� key�� value�� ��´�.
		\param pos node�� ����Ű�� Position
		\return Position�� ����Ű�� node�� key

		\~english 
		Obtain the key and value of the place where the position is pointing at
		\param pos Position pointing at the node
		\return Key of the node pointed at by the position

		\~chinese
		?��Position�����������key��value��
		\param pos ���node��Position��
		\return Position�����node��key��

		\~japanese
		Position��򦪷�ƪ���ᶪ�key��value����ު���
		\param pos node��򦪹Position
		\return Position��򦪹node��key

		\~
		*/
		inline const K& GetKeyAt( Proud::Position pos ) const
		{
			assert( pos != NULL );

			CNode* pNode = (CNode*)pos;

			return( pNode->m_key );
		}

		/**
		\~korean
		Position�� ����Ű�� �ִ� ���� key�� value�� ��´�.
		\param pos node�� ����Ű�� Position
		\return Position�� ����Ű�� node�� const data

		\~english 
		Obtain the key and value of the place where the position is pointing at
		\param Position pointing at the node
		\return const data of the node pointed at by the position

		\~chinese
		?��Position�����������key��value��
		\param pos ���node��Position��
		\return Position�����node��cons data��

		\~japanese
		Position��򦪷�ƪ���ᶪ�key��value����ު���
		\param pos node��򦪹Position
		\return Position��򦪹node��const data

		\~
		*/
		inline const V& GetValueAt( Proud::Position pos ) const
		{
			assert( pos != NULL );

			CNode* pNode = (CNode*)pos;

			return( pNode->m_value );
		}

		/**
		\~korean
		Position�� ����Ű�� �ִ� ���� key�� value�� ��´�.
		\param pos node�� ����Ű�� Position
		\return Position�� ����Ű�� node�� data

		\~english 
		Obtain the key and value of the place where the position is pointing at
		\param pos Position pointing at the node
		\return Data of the node pointed at by the position

		\~chinese
		?��Position�����������key��value��
		\param pos ���node��Position��
		\return Position�����node��data��

		\~japanese
		Position��򦪷�ƪ���ᶪ�key��value����ު���
		\param pos node��򦪹Position
		\return Position��򦪹node��data

		\~
		*/
		inline V& GetValueAt( Proud::Position pos )
		{
			assert( pos != NULL );

			CNode* pNode = (CNode*)pos;

			return( pNode->m_value );
		}

		/**
		\~korean
		hash ���̺��� ũ�⸦ ����ϴ�.

		\~english 
		Get the size of the hash table
		
		\~chinese
		?��hash table����᳡�

		\~japanese
		hash��?�֫�Ϋ���������ު���
		\~
		*/
		uint32_t GetHashTableSize() const throw()
		{
			return( m_nBins );
		}

		/**
		\~korean
		hash ���̺��� �ʱ�ȭ �մϴ�.
		- ��� ������ �ڵ����� ȣ��˴ϴ�.
		\param nBins �콬 ������
		\param bAllocNow �콬 �޸� ���� ���� ����
		\return hash �ʱ�ȭ�� �����ϸ� true, �����ϸ� false ����

		\~english 
		Initialize the hash table. 
		- It automatically calls when generating a node. 
		\param nBins Hash size
		\param bAllocNow Configure whether to generate hash memory
		\return hash True if successful in initializing, false if failed. 


		\~chinese
		�����hash table��
		- ����node��?��?�?����У��
		\param nBins hash����᳡�
		\param bAllocNow ?��hash?������?����
		\return hash�����������?true����?��?����false��

		\~japanese
		hash��?�֫����Ѣ�����ު���
		- ��?������������Ѫ������󪵪�ު���
		\param nBins �ϫë��嫵����
		\param bAllocNow �ϫë������?����ʦ��������
		\return hash ��Ѣ�����������true�����������false��꫿?��

		\~
		*/
		bool InitHashTable( uint32_t nBins, bool bAllocNow = true )
		{
			assert( m_nElements == 0 );
			assert( nBins > 0 );

			if ( m_ppBins != NULL )
			{
				CProcHeap::Free(m_ppBins);
				m_ppBins = NULL;
			}

			if ( bAllocNow )
			{
				m_ppBins = (CNode**)CProcHeap::Alloc(sizeof(CNode*) * nBins);
				if ( m_ppBins == NULL )
				{
					return false;
				}
				memset( m_ppBins, 0, sizeof( CNode* )*nBins );
			}
			m_nBins = nBins;

			UpdateRehashThresholds();

			return true;
		}

		/**
		\~korean
		�ڵ����� Rehash�� �մϴ�.

		\~english 
		Rehash automatically 

		\~chinese
		�?Rehash��

		\~japanese
		��Ѫ�Rehash�򪷪ު���
		\~
		*/
		void EnableAutoRehash() throw()
		{
			assert( m_nLockCount > 0 );
			m_nLockCount--;
		}

		/**
		\~korean
		�ڵ����� Rehash�� ���� �ʽ��ϴ�.

		\~english 
		Do not rehash automatically 

		\~chinese
		���?Rehash��

		\~japanese
		��Ѫ�Rehash�򪷪ު���
		\~
		*/
		void DisableAutoRehash() throw()
		{
			m_nLockCount++;
		}

		/**
		\~korean
		hash ���̺��� �ٽ� �����Ѵ�.
		\param nBins hash���̺��� ũ��

		\~english 
		Generate a hash table again
		\param Size of the hash table 

		\~chinese
		��������hash table��
		\param nBins hash table����᳡�

		\~japanese
		hash ��?�֫������������ު���
		\param nBins hash��?�֫�Ϋ�����

		\~
		*/
		void Rehash( uint32_t nBins = 0 )
		{
			CNode** ppBins = NULL;

			if ( nBins == 0 )
			{
				nBins = PickSize( m_nElements );
			}

			if ( nBins == m_nBins )
			{
				return;
			}

			// NTTNTRACE(atlTraceMap, 2, "Rehash: %u bins\n", nBins );

			if ( m_ppBins == NULL )
			{
				// Just set the new number of bins
				if(!InitHashTable( nBins, false ))
					ThrowBadAllocException();

				return;
			}

			// �� hash table�� �غ��Ѵ�. ���⿡ �� hash table�� �Ű��� ���̴�.
			ppBins = (CNode**)CProcHeap::Alloc(sizeof(CNode*) * nBins);
			if (ppBins == NULL)
				ThrowBadAllocException();

			memset( ppBins, 0, nBins*sizeof( CNode* ) );

			// �� �׸��� hash ���� �ٽ� �� �� ���̺�κ��� �� ���̺�� �ű��. �̶� linked list ���赵 �缳���Ѵ�.
			CNode* pHeadBinHead = NULL;
			CNode* pTailBinTali = NULL;
			int reAddCount = 0;
			for(CNode* pNode = m_pHeadBinHead; pNode != NULL; )
			{
				uint32_t iDestBin;

				CNode* pOldNext = pNode->m_pNext;

				iDestBin = pNode->m_nHash % nBins; // ���� hash ���� ��´�. �׸��� head�μ� �ֵ��� �Ѵ�.
				pNode->m_nBin = iDestBin;

				CNode* pOldBinHead = ppBins[iDestBin];

				// ���� ������ �߰��� ���
				if(reAddCount == 0)
				{
					assert(pHeadBinHead == NULL);
					assert(pOldBinHead == NULL);
					pHeadBinHead = pNode;
					pTailBinTali = pNode;
					pNode->m_pPrev = NULL;
					pNode->m_pNext = NULL;

					ppBins[iDestBin] = pNode;

					reAddCount++; // ������
					//AssertConsist();
				}
				else
				{
					//AssertConsist();

					if(pOldBinHead != NULL)
					{
						// ����ִ� bin�� �߰��ϴ� ��� bin head�μ� �߰��Ѵ�.
						//AssertConsist();

						if(pOldBinHead->m_pPrev != NULL)
						{
							pOldBinHead->m_pPrev->m_pNext = pNode;
						}
						else
						{
							// head bin�̴�. head bin ptr�� ��ü �ʼ�
							pHeadBinHead = pNode;
						}

						pNode->m_pPrev = pOldBinHead->m_pPrev; // pOldBinHead->m_pPrev = NULL OK
						pNode->m_pNext = pOldBinHead;
						pOldBinHead->m_pPrev = pNode;
						assert(pOldBinHead == ppBins[iDestBin]);
						ppBins[iDestBin] = pNode;

						reAddCount++; // ������

						//AssertConsist();
					}
					else
					{
						// �� bin�� �߰��ϴ� ���, ������ linked bin�� �ǰ� rewire�Ѵ�.
						//AssertConsist();

						CNode* pOldHeadBin = pHeadBinHead;

						pNode->m_pPrev = NULL;
						pNode->m_pNext = pOldHeadBin;
						if(pNode->m_pNext != NULL)
							pNode->m_pNext->m_pPrev = pNode;
						pHeadBinHead = pNode;
						ppBins[iDestBin] = pNode;

						reAddCount++; // ������

						//AssertConsist();
					}

				}

				/*pNode->m_pNext = ppBins[iDestBin];
				pNode->m_pPrev = NULL;
				if(ppBins[iDestBin] != NULL)
					ppBins[iDestBin]->m_pPrev = pNode;

				ppBins[iDestBin] = pNode;
				pHeadBinHead = pNode; */

				pNode = pOldNext;
				//reAddCount++;
			}

			assert(reAddCount == m_nElements);

			// �� hash table�� �����ϰ� �� hash table�� ��ü�Ѵ�.
			CProcHeap::Free(m_ppBins);
			m_ppBins = ppBins;
			m_nBins = nBins;
			m_pHeadBinHead = pHeadBinHead;
			m_pTailBinTail = pTailBinTali;

			AssertConsist();

			UpdateRehashThresholds();

#ifdef ENABLE_REHASH_COUNT
			InterlockedIncrement(&FastMap_RehashCount);
#endif // ENABLE_REHASH_COUNT
		}

		/**
		\~korean
		���� ���� ���ϸ� �缳���մϴ�. ���� ���� ���Ͽ� ���ؼ��� <a target="_blank" href="http://guide.nettention.com/cpp_ko#hash_map_load" >�� Ŭ������ ����</a> �� �ֽ��ϴ�.

		\param fOptimalLoad ���� ���� �����Դϴ�.
		\param fLoThreshold ���� ������ �ּ� �Ѱ��Դϴ�.
		\param fHiThreshold ���� ������ �ִ� �Ѱ��Դϴ�.
		\param bRehashNow true�̸� �ؽ����̺� �缳���� ��� ����˴ϴ�.

		\~english
		Re-sets the optimal load to map. Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#hash_map_load" >Load of map class</a> for further detail.

		\param fOptimalLoad Optimal load proportion
		\param fLoThreshold Minimum limit of load proportion
		\param fHiThreshold Maximum limit of load proportion
		\param bRehashNow hash table re-setting proccess runs immediately if true.

		\~chinese
		����?��map����ʢ?�á�?map����ʢ?����?��<a target="_blank" href="http://guide.nettention.com/cpp_zh#hash_map_load" >Map ?��?��</a> %��
		\param fOptimalLoad ��ʢ?�������㡣
		\param fLoThreshold ��ʢ?�����������ͣ�ڡ�
		\param fHiThreshold ��ʢ?������������ͣ�ڡ�
		\param bRehashNow true��??ء??��hash table������?��?ء??����

		\~japanese
		�ޫëת�����ݶ�ê�����Ҫ��ު����ޫëת�����ݶ�ê�?���ƪϡ�\ref hash_map_load�˪���ު���
		\param fOptimalLoad ����ݶ������Ǫ���
		\param fLoThreshold ݶ������������ͣ�Ǫ���
		\param fHiThreshold ݶ�������������ͣ�Ǫ���
		\param bRehashNow true�Ǫ���Ыϫë����?�֫�����Ҫ��������������ު���

		\~
		*/
		void SetOptimalLoad( float fOptimalLoad, float fLoThreshold, float fHiThreshold,
			bool bRehashNow = false )
		{
			assert( fOptimalLoad > 0 );
			assert( (fLoThreshold >= 0) && (fLoThreshold < fOptimalLoad) );
			assert( fHiThreshold > fOptimalLoad );

			m_fOptimalLoad = fOptimalLoad;
			m_fLoThreshold = fLoThreshold;
			m_fHiThreshold = fHiThreshold;

			UpdateRehashThresholds();

			if ( bRehashNow && ((m_nElements > m_nHiRehashThreshold) ||
				(m_nElements < m_nLoRehashThreshold)) )
			{
				Rehash( PickSize( m_nElements ) );
			}
		}

		/**
		\~korean
		lookup ���� ����, �����ؼ��� rehash�� �ִ��� ���ϰ�, �� ��� �޸𸮸� ���� ����ϴ� ����.
		�������� ���� ū���� rehash cost�� ū ��쿡 �����ϴ�.

		\param rehashNow �����ϸ鼭 Rehash�� �Ұ������� �����Ѵ�. true�̸� Rehash�� ��

		\~english 
		Lookup optimum performance. Configuration to avoid rehash as much as possible but instead use a lot of memory. 
		\param Select whether to rehash when configuring. If true, rehash. 

		\~chinese
		Lookup ��ʢ������?ʦ�����������rehash������?��?����?�ǡ�
		��?������?���ޣ�rehash cost ����?��??���ġ�

		\param rehashNow ����?��??�����Rehash��True ��??Rehash��

		\~japanese
		lookup �����������Ǫ����rehash�򪷪ʪ��ơ������۪��˫���?���������Ī������ҡ�
		?���몬�Ȫƪ��ު�������rehash cost���ު�����������ĪǪ���
		\param rehashNow ���Ҫ��ʪ���Rehash�򪹪몫�ɪ�������?���ު���True�Ǫ����Rehash�������ު���

		\~
		*/
		void SetOptimalLoad_BestLookup(bool rehashNow = false)
		{
			SetOptimalLoad(0.1f,0.0000001f,2.1f,rehashNow);
		}


		/**
		\~korean
		�� bin�� ������, �־��� bin, �� ���� ���� item�� ���� bin�� item ������ �����Ѵ�.

		\~english 
		Search each bin and return the worst bin, in other words, the number of items of the bin with the most items. 

		\~chinese
		?��?bin��������?��bin��??������item��bin��item??��

		\~japanese
		��bin�������ơ���?��bin��?����������item����bin��item?��꫿?�󪷪ު���
		\~
		*/
		intptr_t GetWorstBinItemCount()
		{
			intptr_t worstValue = 0;

			CNode* prevNode = NULL;
			intptr_t itemCountInCurrentBin = 0;
			for(CNode* pNode = m_pHeadBinHead; pNode!=NULL;pNode=pNode->m_pNext)
			{
				if(prevNode != NULL && prevNode->m_nBin == pNode->m_nBin)
				{
					itemCountInCurrentBin++;
				}
				else
					itemCountInCurrentBin = 1;
				worstValue = PNMAX(worstValue, itemCountInCurrentBin);
			}

			return worstValue;
		}


// #ifdef _DEBUG
// 		void AssertValid() const
// 		{
		// 			assert( m_nBins > 0 );
// 			// non-empty map should have hash table
// 			assert( IsEmpty() || (m_ppBins != NULL) );
// 		}
// #endif  // _DEBUG

		void EnableSlowConsistCheck()
		{
			m_enableSlowConsistCheck = true;
		}

		/**
		\~korean
		map ��ü�� key���� ���� �迭�� ����� �����մϴ�.

		\~english
		Provide array that contain key of map objects

		\~chinese
		?��?�����map?��key��??��

		\~japanese
		map ���֫������Ȫ�key���ᪿ��֪���ªê���ꪷ�ު���
		\~
		 */
		void KeysToArray(CFastArray<K> &output) const
		{
			output.Clear();
			output.SetCount(GetCount());
			int c = 0;

			for(ConstIterType i=CFastMap<K,V>::begin();i!=CFastMap<K,V>::end();i++)
			{
				output[c] = i.GetFirst();
				c++;
			}
		}

		/**
		\~korean
		map ��ü�� value���� ���� �迭�� ����� �����մϴ�.

		\~english
		Provide array that contain value of map objects

		\~chinese
		?��?�����map?��value��??��

		\~japanese
		map ���֫������Ȫ�value���ᪿ��֪���ªê���ꪷ�ު���
		\~
		 */
		void ValuesToArray(CFastArray<V> &output) const
		{
			output.Clear();
			output.SetCount(GetCount());
			int c = 0;
			for(ConstIterType i=CFastMap<K,V>::begin();i!=CFastMap<K,V>::end();i++)
			{
				output[c] = i.GetSecond();
				c++;
			}
		}

		/**
		\~korean
		���� ���°� ���� ���� ������ Ȯ���Ѵ�.
		- ũ�Ⱑ ũ���� inline���� �ص־� �� �Լ��϶� noop�� �ȴ�. (regardless of compilers)

		\~english
		Must check if there exitst any cracked internal status
		- Must set this as inline though its size is big in order to make noop when function is empty. (regardless of compilers)

		\~chinese
		??������?ݻ??�����ܡ�
		- ?���������inline��������?��?����?noop��(regardless of compilers)

		\~japanese
		?ݻ?����?�쪿��Ϊ��ʪ������㪷�ު���
		- ���������ު����ƪ�inline�˪��ƪ�������??�Ǫ�������noop�˪ʪ�ު���(regardless of compilers)

		\~
		 */
		inline void AssertConsist() const
		{
			// UnitTester���� ������ ���忡���� �۵��ؾ� �ϹǷ�
			if(m_enableSlowConsistCheck)
			{
				int count=0;

				if( ! (IsEmpty() || (m_ppBins != NULL) ) )
				{
					assert(0);
					ThrowException("CFastMap consistency error #0!");
				}

				for(CNode* pNode = m_pHeadBinHead; pNode!=NULL;pNode=pNode->m_pNext)
				{
					if(pNode->m_pNext)
					{
						if(pNode->m_pNext->m_pPrev != pNode)
						{
							assert(0);
							ThrowException("CFastMap consistency error #1!");
						}
					}
					if(pNode==m_pHeadBinHead)
					{
						if(pNode->m_pPrev)
						{
							assert(0);
							ThrowException("CFastMap consistency error #2!");
						}
					}
					if(pNode==m_pTailBinTail)
					{
						if(pNode->m_pNext)
						{
							assert(0);
							ThrowException("CFastMap consistency error #3!");
						}
					}
					count++;
				}

				if(count != (int)m_nElements)
				{
					for(CNode* pNode = m_pHeadBinHead; pNode!=NULL;pNode=pNode->m_pNext)
					{
						NTTNTRACE("Node at Bin #%d\n",pNode->m_nBin);
					}

					assert(0);
					ThrowException("CFastMap consistency error #4!");
				}
			}
		}


		// Implementation
	private:
		inline bool IsLocked() const throw()
		{
			return( m_nLockCount != 0 );
		}

		// map�� ����ִ� �� �׸� ������ �ٰ��ؼ� ���� ������ hash table�� ũ�Ⱚ�� ��´�.
		uint32_t PickSize( intptr_t nElements ) const throw()
		{
			// List of primes such that s_anPrimes[i] is the smallest prime greater than 2^(5+i/3)
			static const uint32_t s_anPrimes[] =
			{
				17, 23, 29, 37, 41, 53, 67, 83, 103, 131, 163, 211, 257, 331, 409, 521, 647, 821,
				1031, 1291, 1627, 2053, 2591, 3251, 4099, 5167, 6521, 8209, 10331,
				13007, 16411, 20663, 26017, 32771, 41299, 52021, 65537, 82571, 104033,
				131101, 165161, 208067, 262147, 330287, 416147, 524309, 660563,
				832291, 1048583, 1321139, 1664543, 2097169, 2642257, 3329023, 4194319,
				5284493, 6658049, 8388617, 10568993, 13316089, UINT_MAX
			};

			intptr_t nBins = (intptr_t)(nElements / m_fOptimalLoad);
			uint32_t nBinsEstimate = uint32_t(  UINT_MAX < (uintptr_t)nBins ? UINT_MAX : nBins );

			// Find the smallest prime greater than our estimate
			int iPrime = 0;
			while ( nBinsEstimate > s_anPrimes[iPrime] )
			{
				iPrime++;
			}

			if ( s_anPrimes[iPrime] == UINT_MAX )
			{
				return( nBinsEstimate );
			}
			else
			{
				return( s_anPrimes[iPrime] );
			}
		}

		// iBin�� ����Ű�� bin�� key ���� ������ �� node�� �߰��ϵ��� �Ѵ�. �̶� hash ���� nHash�̴�.
		CNode* NewNode( KINARGTYPE key, uint32_t iBin, uint32_t nHash )
		{
			//CNode* pNewNode = new CNode( key, nHash );
			CNode* pNewNode;

			if(m_refHeap)
				pNewNode = (CNode*) m_refHeap->Alloc(sizeof(CNode));
			else
				pNewNode = (CNode*) CProcHeap::Alloc(sizeof(CNode));

			if(pNewNode == NULL)
				ThrowBadAllocException();


			CallConstructor<CNode>(pNewNode, key);
			pNewNode->m_nHash = nHash;
			pNewNode->m_nBin = iBin;

			CNode* pOldBinHead = m_ppBins[iBin];

			AssertConsist();

			// ���� ������ �߰��� ���
			if(m_nElements == 0)
			{
				assert(m_pHeadBinHead == NULL);
				assert(pOldBinHead == NULL);
				m_pHeadBinHead = pNewNode;
				m_pTailBinTail = pNewNode;
				pNewNode->m_pPrev = NULL;
				pNewNode->m_pNext = NULL;

				m_ppBins[iBin] = pNewNode;

				m_nElements++; // ������

				AssertConsist();
			}
			else
			{
				//���� ���� ���̹Ƿ� tail���� ��ȭ�� ����.
				AssertConsist();

				if(pOldBinHead != NULL)
				{
					// ����ִ� bin�� �߰��ϴ� ��� bin head�μ� �߰��Ѵ�.
					AssertConsist();

					if(pOldBinHead->m_pPrev != NULL)
					{
						pOldBinHead->m_pPrev->m_pNext = pNewNode;
					}
					else
					{
						// head bin�̴�. head bin ptr�� ��ü �ʼ�
						m_pHeadBinHead = pNewNode;
					}

					pNewNode->m_pPrev = pOldBinHead->m_pPrev; // pOldBinHead->m_pPrev = NULL OK
					pNewNode->m_pNext = pOldBinHead;
					pOldBinHead->m_pPrev = pNewNode;
					assert(pOldBinHead == m_ppBins[iBin]);
					m_ppBins[iBin] = pNewNode;

					m_nElements++; // ������

					AssertConsist();
				}
				else
				{
					// �� bin�� �߰��ϴ� ���, ������ linked bin�� �ǰ� rewire�Ѵ�.
					AssertConsist();

					CNode* pOldHeadBin = m_pHeadBinHead;

					pNewNode->m_pPrev = NULL;
					pNewNode->m_pNext = pOldHeadBin;
					if(pNewNode->m_pNext != NULL)
						pNewNode->m_pNext->m_pPrev = pNewNode;
					m_pHeadBinHead = pNewNode;
					m_ppBins[iBin] = pNewNode;

					m_nElements++; // ������

					AssertConsist();
				}

			}

			AssertConsist();

			// ������ ����ġ�� ���������� rehash�Ѵ�.
			if ( (m_nElements > m_nHiRehashThreshold) && !IsLocked() )
			{
				Rehash( PickSize( m_nElements ) );
			}

			AssertConsist();

			return( pNewNode );
		}

		// node ������ ������ �ܰ�
		void FreeNode( CNode* pNode, bool rehashOnNeed )
		{
			assert( pNode != NULL );
			CallDestructor<CNode>(pNode);
			if(m_refHeap)
				m_refHeap->Free(pNode);
			else
				CProcHeap::Free(pNode);

			//delete pNode;

			assert( m_nElements > 0 );
			m_nElements--;

			if ( rehashOnNeed && (m_nElements < m_nLoRehashThreshold) && !IsLocked() )
			{
				Rehash( PickSize( m_nElements ) );
			}
		}

		/*
		\~korean
		Ư�� key�� ���� node�� ã�� �μ� ������ ���� ã�´�. ���� �Լ�
		\param [out] iBin node�� ���� bin�� index
		\param [out] nHash node�� hashed value
		\param [out] pPrev node�� prev node

		\~english
		Finds the node with certain key but also searches attached info. An internal function.
		\param [out] iBin index of bin that node is possessed
		\param [out] nHash hashed value of node
		\param [out] pPrev prev node of node


		\~chinese
		?��?������key��node����?��?��ݾʥ���ӡ�?ݻ��?��
		\param [out] iBin node�?��bin��index��
		\param [out] nHash node��hashed value��
		\param [out] pPrev node��prey node��

		\~japanese
		����key����node�������ު�������?���ê���?�������ު���?ݻ??
		\param [out] iBin node��?����bin��index
		\param [out] nHash node��hashed value
		\param [out] pPrev node��prev node

		\~
		*/
		CNode* GetNode( KINARGTYPE key, uint32_t& iBin, uint32_t& nHash ) const throw()
		{
			// hash�� ���� ���, ������ bin index�� ��´�.
			nHash = KTraits::Hash( key );
			iBin = nHash % m_nBins;

			// ���� bin�� ������ ��
			if ( m_ppBins == NULL )
			{
				return( NULL );
			}

			// bin���� key�� ���� �׸��� ��ȸ�ϸ� ã�´�.
			for ( CNode* pNode = m_ppBins[iBin];
				(pNode != NULL && iBin == pNode->m_nBin);
				pNode = pNode->m_pNext )
			{
				if ( KTraits::CompareElements( pNode->m_key, key ) )
				{
					return( pNode );
				}
			}

			return( NULL );
		}

		CNode* CreateNode( KINARGTYPE key, uint32_t iBin, uint32_t nHash ) throw(Exception)
		{
			CNode* pNode;

			if ( m_ppBins == NULL )
			{
				if(!InitHashTable( m_nBins ))
					ThrowBadAllocException();
			}

			AssertConsist();

			pNode = NewNode( key, iBin, nHash );

			AssertConsist();

			return( pNode );
		}

		void RemoveNode( CNode* pNode,bool rehashOnNeed=false ) throw(Exception)
		{
			assert( pNode != NULL );
			uint32_t iBin = pNode->m_nBin;

			// �����Ϸ��� node�� ������ ��ü�� ���
			if(m_nElements == 1)
			{
				m_ppBins[iBin] = NULL;
				m_pHeadBinHead = NULL;
				m_pTailBinTail = NULL;
			}
			else
			{
				// �� ��尡 bin�� ������ node�� ��� bin entry�� �����Ѵ�.
				if(IsBinUniqueNode(pNode))
					m_ppBins[iBin] = NULL;
				else if(IsBinHeadNode(pNode, iBin))
					m_ppBins[iBin] = pNode->m_pNext;

				// �� ��尡 head bin�� head node�̸� head bin�� �����Ѵ�.
				if(pNode == m_pHeadBinHead)
				{
					m_pHeadBinHead = pNode->m_pNext;
					pNode->m_pPrev = NULL;
				}

				// �� ��尡 ��ü bin�� ������ ����� ��� ����..
				if(pNode == m_pTailBinTail)
				{
					m_pTailBinTail = pNode->m_pPrev;
					pNode->m_pNext = NULL;
				}

				// �� ����� �յڸ� ���� �����Ѵ�.
				if(pNode->m_pPrev!=NULL)
					pNode->m_pPrev->m_pNext = pNode->m_pNext;
				if(pNode->m_pNext!=NULL)
					pNode->m_pNext->m_pPrev = pNode->m_pPrev;
			}

			// ������ �ܰ�
			FreeNode( pNode ,rehashOnNeed);

			AssertConsist();
		}

		inline bool IsBinUniqueNode(CNode* pNode) const
		{
			if (pNode->m_pPrev != NULL && (pNode->m_pPrev->m_nBin) == pNode->m_nBin)
				return false;

			if (pNode->m_pNext != NULL && (pNode->m_pNext->m_nBin) == pNode->m_nBin)
				return false;

			return true;
		}

		inline bool IsBinHeadNode(CNode* pNode,int iBin) const
		{
			return pNode == m_ppBins[iBin];
		}

		inline CNode* FindNextNode( CNode* pNode ) const throw()
		{
			if (pNode == NULL)
			{
				assert(false);
				return NULL;
			}

			return pNode->m_pNext;
		}

		inline CNode* FindPrevNode( CNode* pNode ) const throw()
		{
			if (pNode == NULL)
			{
				assert(false);
				return NULL;
			}

			return pNode->m_pPrev;
		}

		void UpdateRehashThresholds() throw()
		{
			m_nHiRehashThreshold = intptr_t( m_fHiThreshold * m_nBins );
			m_nLoRehashThreshold = intptr_t( m_fLoThreshold * m_nBins );
			if ( m_nLoRehashThreshold < 17 )
			{
				m_nLoRehashThreshold = 0;
			}
		}

		public:
		~CFastMap()
		{
#if !defined(_WIN32)
		//try
		//{
				RemoveAll();
		//}
		//    catch(...)
		//{
		//        assert(false);
		//    }
#else
			//_ATLTRY
			//try
			//{
				RemoveAll();
			//}
			//_ATLCATCHALL()
			//catch(...)
			//{
			//	assert(false);
			//}
#endif
		}


		/**
		\~korean
		CFastMap �� ���� ������ ��ü�̴�.

		\~english
		CFastMap is an object can be copied.


		\~chinese
		CHashMap ��ʦ�?���?�ڡ�

		\~japanese
		CFastMap�ϫ���?ʦ���ʫ��֫������ȪǪ���
		\~
		 */
		CFastMap( const CFastMap& a)
		{
			m_refHeap = a.m_refHeap;
			m_enableSlowConsistCheck = false;

			InitVars(a.m_nBins,a.m_fOptimalLoad,a.m_fLoThreshold,a.m_fHiThreshold);

			RemoveAll();

			for(iterator i=a.begin();i!=a.end();i++)
			{
				Add(i->GetFirst(),i->GetSecond());
			}
		}

		/**
		\~korean
		CFastMap �� ���� ������ ��ü�̴�.

		\~english
		CFastMap is an object can be copied.


		\~chinese
		CHashMap ��ʦ�?���?�ڡ�

		\~japanese
		CFastMap�ϫ���?ʦ���ʫ��֫������ȪǪ���
		\~
		 */
		CFastMap& operator=( const CFastMap& a)
		{
			RemoveAll();

			m_refHeap = a.m_refHeap;
			for(iterator i=a.begin();i!=a.end();i++)
			{
				Add(i->GetFirst(),i->GetSecond());
			}

			return *this;
		}

		/**
		\~korean
		CFastMap �� ������ container������ �� ������ std.map ���� �����ϴ�.

		\~english
		CFastMap is non-array container so it shows slower comparison operation than std.map

		\~chinese
		��?ChashMap��ު֪?container����??ߩ�� std.map%?ط��

		\~japanese
		CFastMap��ު��֪container���ʪΪ�������ߩ��std.map���?���Ǫ���
		\~
		 */
		bool Equals( const CFastMap& a) const
		{
			if(a.GetCount() != GetCount())
				return false;

			std::map<K,V> t2,a2;
			for(const_iterator i=begin();i!=end();i++)
			{
				t2.insert(typename std::map<K, V>::value_type(i.GetFirst(), i.GetSecond()));
			}

			for(const_iterator i=a.begin();i!=a.end();i++)
			{
				a2.insert(typename std::map<K, V>::value_type(i.GetFirst(), i.GetSecond()));
			}
			return t2==a2;
		}

	public:
		/**
		\~korean
		key ������ ��Ƽ� �ش�.

		\~english
		Collects and gives key

		\~chinese
		��key���??����

		\~japanese
		key ������ƪ��ު���
		\~
		 */
		void CopyKeysTo(CFastArray<K> &dest)
		{
			dest.SetCount(size());
			int c = 0;
			for (iterator i = begin();i != end();i++)
			{
				dest[c++] = i->GetFirst();
			}
		}

		/**
		\~korean
		key�� �ִ��� Ȯ���Ѵ�.
		\return Ű�� ������ true

		\~english
		Checks if there is key
		\return If there is key then true

		\~chinese
		??������key��
		\retur ��key��?true��

		\~japanese
		Key�����몫���㪷�ު��� 
		\return ��?������� true

		\~
		 */
		inline bool ContainsKey(const K& key)
		{
			return find(key) != end();
		}

		/**
		\~korean
		value�� �ִ��� Ȯ���Ѵ�.

		\~english
		Checks if there is value

		\~chinese
		??������value��

		\~japanese
		Value�����몫���㪷�ު���
		\~
		 */
		bool ContainsValue(const V& val)
		{
			for (iterator i = begin();i!= end();i++)
			{
				if (val == i->GetSecond())
					return true;
			}
			return false;
		}

		/**
		\~korean
		key�� �����ϴ� value�� ������ true�� �����Ѵ�.

		\~english
		Returns true if there exist value corresponds to key

		\~chinese
		��??key��value��?����true��

		\~japanese
		Key��??����value������С�true��꫿?�󪷪ު���
		\~
		 */
		inline bool TryGetValue(KINARGTYPE key, VOUTARGTYPE value)
		{
			return Lookup(key, value);
		}

		/**
		\~korean
		�� �׸��� �߰��Ѵ�.
		\param key �߰��� �׸��� key
		\param value �߰��� �׸��� value
		\return ���������� ������ true, �ƴϸ� false�� �����Ѵ�.

		\~english
		Adds a new clause
		\param key key of the clause to be added
		\param value value of the clause to be added
		\return true if successfully entered, otherwise, returns false.

		\~chinese
		��ʥ��?�͡�
		\param key ���ʥ��?����key��
		\param value ���ʥ��?����value��
		\return ����?����?true����?����false��

		\~japanese
		�檷�����ͪ���ʥ���ު���
		\param key ��ʥ�������ͪ�key
		\param value ��ʥ�������ͪ�value
		\return �����ܪ����ê���true������Ȫ�false��꫿?�󪷪ު���

		\~
		 */
		inline bool Add(KINARGTYPE key, VINARGTYPE value)
		{
			// �ߺ� �ڵ������� ���� ���� ȣ��Ǳ⿡ optimize off then code profile�� �� ��
			// �� �� ���̰� �Ѵ�.
			CNode* pNode;
			uint32_t iBin;
			uint32_t nHash;

			pNode = GetNode(key, iBin, nHash);
			if (pNode != NULL)
			{
				// SetAt�� �޸�, ���⼭�� ���� ���� ��ü���� �ʰ�,�׳� �����Ѵ�.
				return false;
			}

			pNode = CreateNode(key, iBin, nHash);
			pNode->m_value = value;

			return true;
		}

		class value_type
		{
		public:
			Proud::Position m_pos;
			CFastMap* m_owner;

#if defined(_MSC_VER)
			__declspec(property(get=GetFirst)) const K& first;
			__declspec(property(get=GetSecond,put=SetSecond)) V& second;
#endif

			inline const K& GetFirst() const { return m_owner->GetKeyAt(m_pos); }
			inline V& GetSecond() const { return m_owner->GetValueAt(m_pos); }
			inline void SetSecond(const V& val) const { return m_owner->SetValueAt(m_pos,val); }
		};

		class iterator;
		friend class iterator;

		class reverse_iterator;
		friend class reverse_iterator;

#ifndef PROUDNET_NO_CONST_ITERATOR

		/**
		\~korean
		STL�� const_iterator�� ���� ������ �Ѵ�.

		\~english
		Performs a role as const_iterator of STL

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

			const_iterator& operator++()
			{
				// preincrement
				value_type::m_owner->GetNext(value_type::m_pos);
				return (*this);
			}

			const_iterator operator++(int)
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

// 			inline const K& first() const
// 			{
// 				return m_owner->GetKeyAt(m_pos);
// 			}
//
// 			inline const V& second() const
// 			{
// 				return m_owner->GetValueAt(m_pos);
// 			}

			inline const value_type& operator*() const
			{
				return *this;
			}

			inline const value_type* operator->() const
			{
				return this;
			}
		};

		class const_reverse_iterator;
		friend class const_reverse_iterator;

		/**
		\~korean
		STL�� iterator�� ���� ������ �Ѵ�.

		\~english
		Performs a role as iterator of STL

		\~chinese
		���?STL��iterator��?�����ġ�

		\~japanese
		STL��iterator�Ϊ誦����ܪ򪷪ު���
		\~
		 */
		class const_reverse_iterator:public value_type
		{
		public:
			inline const_reverse_iterator(){}
			inline const_reverse_iterator(const reverse_iterator& src):value_type(src){}

			const_reverse_iterator& operator++()
			{
				// preincrement
				value_type::m_owner->GetPrev(value_type::m_pos);
				return (*this);
			}

			const_reverse_iterator operator++(int)
			{
				// postincrement
				const_reverse_iterator _Tmp = *this;
				++*this;
				return (_Tmp);
			}

			inline bool operator==(const const_reverse_iterator& a) const
			{
				return value_type::m_pos==a.m_pos && value_type::m_owner==a.m_owner;
			}

			inline bool operator!=(const const_reverse_iterator& a) const
			{
				return !(value_type::m_pos==a.m_pos && value_type::m_owner==a.m_owner);
			}

			inline const value_type& operator*() const
			{
				return *this;
			}

			inline const value_type* operator->() const
			{
				return this;
			}

		};
#endif
		/**
		\~korean
		STL�� iterator�� ���� ������ �Ѵ�.

		\~english
		Performs a role as iterator of STL

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

			/**
			\~korean
			STL iterator�� ���� ������ �ϰ� ���ִ� ������ �Լ�

			\~english
			Operator Function that lets this perform a role as STL iterator

			\~chinese
			�������?STL iterator��?������?ߩ���?��

			\~japanese
			STL iterator�Ϊ誦����ܪ򪹪�誦�˪�����ߩ�??
			\~
			 */
			inline bool operator==(const iterator& a) const
			{
				return value_type::m_pos==a.m_pos && value_type::m_owner==a.m_owner;
			}

			/**
			\~korean
			STL iterator�� ���� ������ �ϰ� ���ִ� ������ �Լ�

			\~english
			Operator Function that lets this perform a role as STL iterator

			\~chinese
			�������?STL iterator��?������?ߩ���?��

			\~japanese
			STL iterator�Ϊ誦����ܪ򪹪�誦�˪�����ߩ�??
			\~
			 */
			inline bool operator!=(const iterator& a) const
			{
				return !(value_type::m_pos==a.m_pos && value_type::m_owner==a.m_owner);
			}

			/**
			\~korean
			STL iterator�� ���� ������ �ϰ� ���ִ� ������ �Լ�

			\~english
			Operator Function that lets this perform a role as STL iterator

			\~chinese
			�������?STL iterator��?������?ߩ���?��

			\~japanese
			STL iterator�Ϊ誦����ܪ򪹪�誦�˪�����ߩ�??
			\~
			 */
			inline iterator& operator++()
			{
				// preincrement
				value_type::m_owner->GetNext(value_type::m_pos);
				return (*this);
			}

			/**
			\~korean
			STL iterator�� ���� ������ �ϰ� ���ִ� ������ �Լ�

			\~english
			Operator Function that lets this perform a role as STL iterator

			\~chinese
			�������?STL iterator��?������?ߩ���?��

			\~japanese
			STL iterator�Ϊ誦����ܪ򪹪�誦�˪�����ߩ�??
			\~
			 */
			inline iterator operator++(int)
			{
				// postincrement
				iterator _Tmp = *this;
				++*this;
				return (_Tmp);
			}

			/**
			\~korean
			STL iterator�� ���� ������ �ϰ� ���ִ� ������ �Լ�

			\~english
			Operator Function that lets this perform a role as STL iterator

			\~chinese
			�������?STL iterator��?������?ߩ���?��

			\~japanese
			STL iterator�Ϊ誦����ܪ򪹪�誦�˪�����ߩ�??
			\~
			 */
			inline iterator& operator--()
			{
				// preincrement
				value_type::m_owner->GetPrev(value_type::m_pos);
				return (*this);
			}

			/**
			\~korean
			STL iterator�� ���� ������ �ϰ� ���ִ� ������ �Լ�

			\~english
			Operator Function that lets this perform a role as STL iterator

			\~chinese
			�������?STL iterator��?������?ߩ���?��

			\~japanese
			STL iterator�Ϊ誦����ܪ򪹪�誦�˪�����ߩ�??
			\~
			 */
			inline iterator operator--(int)
			{
				// predecrement
				--(*this);
				return (*this);
			}

			/**
			\~korean
			STL iterator�� ���� ������ �ϰ� ���ִ� ������ �Լ�

			\~english
			Operator Function that lets this perform a role as STL iterator

			\~chinese
			�������?STL iterator��?������?ߩ���?��

			\~japanese
			STL iterator�Ϊ誦����ܪ򪹪�誦�˪�����ߩ�??
			\~
			 */
			inline const value_type& operator*() const
			{
				return *this;
			}

			/**
			\~korean
			STL iterator�� ���� ������ �ϰ� ���ִ� ������ �Լ�

			\~english
			Operator Function that lets this perform a role as STL iterator

			\~chinese
			�������?STL iterator��?������?ߩ���?��

			\~japanese
			STL iterator�Ϊ誦����ܪ򪹪�誦�˪�����ߩ�??
			\~
			 */
			inline const value_type* operator->() const
			{
				return this;
			}
		};

		/**
		\~korean
		STL�� ���� �޼���� ���� ������ �Ѵ�.

		\~english
		Performs a role as same name method of STL

		\~chinese
		���?STL����٣۰�����������ġ�

		\~japanese
		STL����٣�᫽�ëɪΪ誦����ܪ򪷪ު���
		\~
		 */
		inline iterator begin()
		{
			iterator ret;
			ret.m_pos = GetStartPosition();
			ret.m_owner=this;

			return ret;
		}

		/**
		\~korean
		STL�� ���� �޼���� ���� ������ �Ѵ�.

		\~english
		Performs a role as same name method of STL

		\~chinese
		���?STL����٣۰�����������ġ�

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

		inline value_type front()
		{
			if(GetCount()==0)
				ThrowInvalidArgumentException();

			return *begin();
		}

		/**
		\~korean
		STL�� iterator�� ���� ������ �Ѵ�.

		\~english
		Performs a role as iterator of STL

		\~chinese
		���?STL����٣۰�����������ġ�

		\~japanese
		STL��iterator�Ϊ誦����ܪ򪷪ު���
		\~ */
		class reverse_iterator:public value_type
		{
		public:
			inline reverse_iterator() {}
			inline reverse_iterator(const const_reverse_iterator& src):value_type(src) {}

			/**
			\~korean
			STL reverse_iterator�� ���� ������ �ϰ� ���ִ� ������ �Լ�

			\~english
			Operator Function that lets this perform a role as STL reverse_iterator

			\~chinese
			�������?STL reverse_iterator ����������?ߩ���?��

			\~japanese
			STL reverse_iterator�Ϊ誦����ܪ򪹪�誦�˪�����ߩ�??
			\~
			 */
			inline bool operator==(const reverse_iterator& a) const
			{
				return value_type::m_pos==a.m_pos && value_type::m_owner==a.m_owner;
			}

			/**
			\~korean
			STL reverse_iterator�� ���� ������ �ϰ� ���ִ� ������ �Լ�

			\~english
			Operator Function that lets this perform a role as STL reverse_iterator

			\~chinese
			�������?STL reverse_iterator ����������?ߩ���?��

			\~japanese
			STL reverse_iterator�Ϊ誦����ܪ򪹪�誦�˪�����ߩ�??
			\~
			 */
			inline bool operator!=(const reverse_iterator& a) const
			{
				return !(value_type::m_pos==a.m_pos && value_type::m_owner==a.m_owner);
			}

			/**
			\~korean
			STL reverse_iterator�� ���� ������ �ϰ� ���ִ� ������ �Լ�

			\~english
			Operator Function that lets this perform a role as STL reverse_iterator

			\~chinese
			�������?STL reverse_iterator ����������?ߩ���?��

			\~japanese
			STL reverse_iterator�Ϊ誦����ܪ򪹪�誦�˪�����ߩ�??
			\~
			 */
			inline reverse_iterator& operator++()
			{
				// preincrement
				value_type::m_owner->GetPrev(value_type::m_pos);
				return (*this);
			}

			/**
			\~korean
			STL reverse_iterator�� ���� ������ �ϰ� ���ִ� ������ �Լ�

			\~english
			Operator Function that lets this perform a role as STL reverse_iterator

			\~chinese
			�������?STL reverse_iterator ����������?ߩ���?��

			\~japanese
			STL reverse_iterator�Ϊ誦����ܪ򪹪�誦�˪�����ߩ�??
			\~
			 */
			inline reverse_iterator operator++(int)
			{
				// postincrement
				reverse_iterator _Tmp = *this;
				++*this;
				return (_Tmp);
			}

			/**
			\~korean
			STL reverse_iterator�� ���� ������ �ϰ� ���ִ� ������ �Լ�

			\~english
			Operator Function that lets this perform a role as STL reverse_iterator

			\~chinese
			�������?STL reverse_iterator ����������?ߩ���?��

			\~japanese
			STL reverse_iterator�Ϊ誦����ܪ򪹪�誦�˪�����ߩ�??
			\~
			 */
			inline reverse_iterator& operator--()
			{
				// preincrement
				value_type::m_owner->GetNext(value_type::m_pos);
				return (*this);
			}

			/**
			\~korean
			STL reverse_iterator�� ���� ������ �ϰ� ���ִ� ������ �Լ�

			\~english
			Operator Function that lets this perform a role as STL reverse_iterator

			\~chinese
			�������?STL reverse_iterator ����������?ߩ���?��

			\~japanese
			STL reverse_iterator�Ϊ誦����ܪ򪹪�誦�˪�����ߩ�??
			\~
			 */
			inline reverse_iterator operator--(int)
			{
				// predecrement
				--(*this);
				return (*this);
			}

			/**
			\~korean
			STL reverse_iterator�� ���� ������ �ϰ� ���ִ� ������ �Լ�

			\~english
			Operator Function that lets this perform a role as STL reverse_iterator

			\~chinese
			�������?STL reverse_iterator ����������?ߩ���?��

			\~japanese
			STL reverse_iterator�Ϊ誦����ܪ򪹪�誦�˪�����ߩ�??
			\~
			 */
			inline const value_type& operator*() const
			{
				return *this;
			}

			/**
			\~korean
			STL reverse_iterator�� ���� ������ �ϰ� ���ִ� ������ �Լ�

			\~english
			Operator Function that lets this perform a role as STL reverse_iterator

			\~chinese
			�������?STL reverse_iterator ����������?ߩ���?��

			\~japanese
			STL reverse_iterator�Ϊ誦����ܪ򪹪�誦�˪�����ߩ�??
			\~
			 */
			inline const value_type* operator->() const
			{
				return this;
			}
		};

		/**
		\~korean
		STL�� ���� �޼���� ���� ������ �Ѵ�.

		\~english
		Performs a role as same name method of STL

		\~chinese
		���?STL��٣۰�������������ġ�

		\~japanese
		STL����٣�᫽�ëɪΪ誦����ܪ򪷪ު���
		\~
		*/
		inline reverse_iterator rbegin()
		{
			reverse_iterator ret;
			ret.m_pos = GetEndPosition();
			ret.m_owner=this;

			return ret;
		}

		/**
		\~korean
		STL�� ���� �޼���� ���� ������ �Ѵ�.

		\~english
		Performs a role as same name method of STL

		\~chinese
		���?STL��٣۰�������������ġ�

		\~japanese
		STL����٣�᫽�ëɪΪ誦����ܪ򪷪ު���
		\~
		 */
		inline reverse_iterator rend()
		{
			reverse_iterator ret;
			ret.m_pos=NULL;
			ret.m_owner=this;

			return ret;
		}


#ifndef PROUDNET_NO_CONST_ITERATOR
		/**
		\~korean
		STL�� ���� �޼���� ���� ������ �Ѵ�.

		\~english
		Performs a role as same name method of STL

		\~chinese
		���?STL��٣۰�������������ġ�

		\~japanese
		STL����٣�᫽�ëɪΪ誦����ܪ򪷪ު���
		\~
		*/
		inline const_iterator begin() const
		{
			const_iterator ret;
			ret.m_pos = GetStartPosition();
			ret.m_owner = (CFastMap*)this;

			return ret;
		}

		/**
		\~korean
		STL�� ���� �޼���� ���� ������ �Ѵ�.

		\~english
		Performs a role as same name method of STL

		\~chinese
		���?STL��٣۰�������������ġ�

		\~japanese
		STL����٣�᫽�ëɪΪ誦����ܪ򪷪ު���
		\~
		 */
		inline const_iterator end() const
		{
			const_iterator ret;
			ret.m_pos=NULL;
			ret.m_owner=(CFastMap*)this;

			return ret;
		}

		inline const_reverse_iterator rbegin() const
		{
			const_reverse_iterator ret;
			ret->m_pos = GetEndPosition();
			ret->m_owner = (CFastMap*)this;

			return ret;
		}

		inline const_reverse_iterator rend() const
		{
			const_reverse_iterator ret;
			ret->m_pos = NULL;
			ret->m_owner = (CFastMap*)this;

			return ret;
		}
#endif


		/**
		\~korean
		STL�� ���� �޼���� ���� ������ �Ѵ�.

		\~english
		Performs a role as same name method of STL

		\~chinese
		���?STL��٣۰�������������ġ�

		\~japanese
		STL����٣�᫽�ëɪΪ誦����ܪ򪷪ު���
		\~
		 */
		reverse_iterator erase(reverse_iterator iter)
		{
			if(iter.m_owner!=this)
			{
				ThrowInvalidArgumentException();
			}
			reverse_iterator ret = iter;
			ret++;
			RemoveAtPos(iter.m_pos);

			return ret;
		}

		/**
		\~korean
		STL�� ���� �޼���� ���� ������ �Ѵ�.

		\~english
		Performs a role as same name method of STL

		\~chinese
		���?STL��٣۰�������������ġ�

		\~japanese
		STL����٣�᫽�ëɪΪ誦����ܪ򪷪ު���
		\~
		 */
		iterator erase(iterator iter)
		{
			if(iter.m_owner!=this)
			{
				ThrowInvalidArgumentException();
			}
			iterator ret = iter;
			ret++;
			RemoveAtPos(iter.m_pos);

			return ret;
		}
		/**
		\~korean
		STL�� ���� �޼���� ���� ������ �Ѵ�.

		\~english
		Performs a role as same name method of STL

		\~chinese
		���?STL��٣۰�������������ġ�

		\~japanese
		STL����٣�᫽�ëɪΪ誦����ܪ򪷪ު���
		\~
		 */
		iterator find(const K& key)
		{
			iterator ret;
			ret.m_owner=this;
			uint32_t iBin,nHash;
			CNode* node = GetNode(key,iBin,nHash);
			if(node!=NULL)
			{
				ret.m_pos=Proud::Position(node);
			}
			else
			{
				ret.m_pos=NULL;
			}

			return ret;
		}

#ifndef PROUDNET_NO_CONST_ITERATOR
		/**
		\~korean
		STL�� ���� �޼���� ���� ������ �Ѵ�.

		\~english
		Performs a role as same name method of STL

		\~chinese
		���?STL��٣۰�������������ġ�

		\~japanese
		STL����٣�᫽�ëɪΪ誦����ܪ򪷪ު���
		\~
		 */
		const_iterator find(const K& key) const
		{
			const_iterator ret;
			ret.m_owner=(CFastMap*)this;
			uint32_t iBin,nHash;
			CNode* node = GetNode(key,iBin,nHash);
			if(node!=NULL)
			{
				ret.m_pos=Proud::Position(node);
			}
			else
			{
				ret.m_pos=NULL;
			}

			return ret;
		}

#endif
		/**
		\~korean
		���� ���۷� CFastHeap �� ����Ѵ�.
		\param heap CFastHeap ������

		\~english 
		Use CFastHeap with the internal buffer. 
		\param CFastHeap pointer 

		\~chinese
		���� CFastHeap%??ݻbuffer��
		\param heap CFastHeap%�?��

		\~japanese
		?ݻ�Ыëի�?��CFastHeap�����Ī��ު���
		\param heap CFastHeap �ݫ���?

		*/
		void UseFastHeap(CFastHeap* heap)
		{
			if(heap == NULL)
			{
				ThrowInvalidArgumentException();
			}
			if(GetCount() > 0)
				ThrowException(CannotUseFastHeapForFilledCollectionErrorText);
			m_refHeap = heap;
		}

		inline CFastHeap* GetRefFastHeap() { return m_refHeap; }
	};

#ifdef ENABLE_REHASH_COUNT
	extern PROUDNET_VOLATILE_ALIGN int32_t FastMap_RehashCount;
#endif // ENABLE_REHASH_COUNT

	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif