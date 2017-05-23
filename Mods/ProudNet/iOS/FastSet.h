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

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup util_group
	*  @{
	*/

	/** 
	\~korean
	CFastMap �� �޸� key���� ������ Ŭ�����̴�. 
	- �������� CFastMap �� ������ ����. CFastMap �� ������ ��. 

	\param K �ݷ����� �� Ÿ��
	\param KTraits �ݷ����� �� Ÿ���� �ٷ�� Ư���� ������ Ŭ����
	\param AllocT AllocType �� �� �ϳ�

	\~english
	Not like CFastMap, this is a class that only possesses key. 
	- Has same nature as CFastMap for the rest. Please refer CFastMap. 

	\param K value type of collection
	\param KTraits class that defines the characteristics that handle value type of collection
	\param AllocT one of the values of AllocType

	\~chinese
	? CFastMap%���ң���?��key��?��
	- �����?? CFastMap%?�����ҡ�??�� CFastMap%��

	\param K collection��??����
	\param KTraits ��??��collection??����������?��
	\param AllocT AllocType?�����顣

	\~japanese
	CfastMap�Ȫ��ުêơ���?�Ϊߪ��ī��髹�Ǫ��� 
	- ?���CFastMap���������Ҫ��Ǫ���CFastMap ��?�Ϊ��������� 

	\param K ���쫯��������������
	\param KTraits ���쫯�������������ת��⪦�����������������髹
	\param AllocT AllocType �������
	\~
	*/
	template < typename K, typename KTraits = CPNElementTraits< K > >
	class CFastSet
	{
		typedef CFastMap<K,char,KTraits, CPNElementTraits< char > > MapType;
		MapType m_intl;
	public:
		class iterator;
		friend class iterator;
		
		/** 
		\~korean
		STL�� iterator�� ���� ������ �Ѵ�.

		\~english
		Performs a role as iterator of STL

		\~chinese
		���?STL��interator��?�����ġ�

		\~japanese
		STL��iterator�Ϊ誦����ܪ򪷪ު���
		\~
		*/
		class iterator 
		{
			friend class CFastSet;
		public:
			typename MapType::iterator m_iterIntl;

			iterator& operator++()
			{
				// preincrement
				m_iterIntl++;
				return (*this);
			}

			iterator operator++(int)
			{
				// postincrement
				iterator _Tmp = *this;
				m_iterIntl++;
				return (_Tmp);
			}

			inline bool operator==(const iterator& a) const 
			{
				return m_iterIntl == a.m_iterIntl;
			}

			inline bool operator!=(const iterator& a) const 
			{
				return !(m_iterIntl == a.m_iterIntl);
			}

			const K& operator*() const
			{
				return m_iterIntl->GetFirst();
			}

		};

		/** 
		\~korean
		STL�� ���� �޼���� ���� ������ �Ѵ�.

		\~english
		Performs a role as same name method of STL

		\~chinese
		���?STL����٣۰����?�����ġ�

		\~japanese
		STL����٣�᫽�ëɪΪ誦����ܪ򪷪ު���
		\~
		*/
		inline iterator begin()
		{
			iterator ret;
			ret.m_iterIntl = m_intl.begin();

			return ret;
		}

		/** 
		\~korean
		STL�� ���� �޼���� ���� ������ �Ѵ�.

		\~english
		Performs a role as same name method of STL

		\~chinese
		���?STL����٣۰����?�����ġ�

		\~japanese
		STL����٣�᫽�ëɪΪ誦����ܪ򪷪ު���
		\~
		*/
		inline iterator end()
		{
			iterator ret;
			ret.m_iterIntl = m_intl.end();

			return ret;
		}

		/** 
		\~korean
		STL�� ���� �޼���� ���� ������ �Ѵ�.

		\~english
		Performs a role as same name method of STL

		\~chinese
		���?STL����٣۰����?�����ġ�

		\~japanese
		STL����٣�᫽�ëɪΪ誦����ܪ򪷪ު���
		\~
		*/
		inline void insert(const K& val)
		{
			m_intl.Add(val,0);
		}

		/** 
		\~korean
		STL�� ���� �޼���� ���� ������ �Ѵ�.

		\~english
		Performs a role as same name method of STL

		\~chinese
		���?STL����٣۰����?�����ġ�

		\~japanese
		STL����٣�᫽�ëɪΪ誦����ܪ򪷪ު���
		\~
		*/
		inline intptr_t GetCount()
		{
			return m_intl.GetCount();
		}

#if defined(_MSC_VER)       
		__declspec(property(get=GetCount)) intptr_t Count;
#endif

		inline bool empty()
		{
			return m_intl.IsEmpty();
		}

		inline bool IsEmpty()
		{
			return m_intl.IsEmpty();
		}

		/** 
		\~korean
		STL�� ���� �޼���� ���� ������ �Ѵ�.

		\~english
		Performs a role as same name method of STL

		\~chinese
		���?STL����٣۰����?�����ġ�

		\~japanese
		STL����٣�᫽�ëɪΪ誦����ܪ򪷪ު���
		\~
		*/
		inline void RemoveAll()
		{
			m_intl.Clear();
		}
		/** 
		\~korean
		STL�� ���� �޼���� ���� ������ �Ѵ�.

		\~english
		Performs a role as same name method of STL

		\~chinese
		���?STL����٣۰����?�����ġ�

		\~japanese
		STL����٣�᫽�ëɪΪ誦����ܪ򪷪ު���
		\~
		*/
		inline void Clear()
		{
			m_intl.Clear();
		}

		/** 
		\~korean
		STL�� ���� �޼���� ���� ������ �Ѵ�.

		\~english
		Performs a role as same name method of STL

		\~chinese
		���?STL����٣۰����?�����ġ�

		\~japanese
		STL����٣�᫽�ëɪΪ誦����ܪ򪷪ު���
		\~
		*/
		inline iterator erase(iterator iter)
		{
			iterator ret;
			ret.m_iterIntl = m_intl.erase(iter.m_iterIntl);
			return ret;
		}

		/** 
		\~korean
		STL�� ���� �޼���� ���� ������ �Ѵ�.

		\~english
		Performs a role as same name method of STL

		\~chinese
		���?STL����٣۰����?�����ġ�

		\~japanese
		STL����٣�᫽�ëɪΪ誦����ܪ򪷪ު���
		\~
		*/
		inline void erase( const K &key,bool rehashOnNeed = false)
		{
			m_intl.Remove(key,rehashOnNeed);
		}

		/** 
		\~korean
		�׸� �ϳ��� ã�Ƽ� �����Ѵ�.

		\~english
		Finds a clause and removes it

		\~chinese
		?����??��??𶡣

		\~japanese
		�����ͪ���������۪��ު���
		\~
		*/
		inline bool Remove( const K& key,bool rehashOnNeed=false ) 
		{
			return m_intl.Remove(key,rehashOnNeed);
		}

		/** 
		\~korean
		STL�� ���� �޼���� ����

		\~english
		Same as same name method of STL

		\~chinese
		?STL����٣۰����?��

		\~japanese
		STL����٣�᫽�ëɪ��Ҫ��Ǫ���
		\~
		*/
		inline K front()
		{
			return m_intl.front().GetFirst();
		}

		/** 
		\~korean
		key �� �� �����̳ʿ� ������ true�� �����Ѵ�.

		\~english
		Returns true when key is in this container

		\~chinese
		Key �container����?����true��

		\~japanese
		��?�����Ϋ���ƫ�?�˪����true��꫿?�󪷪ު���
		\~
		*/
		inline bool ContainsKey(const K& key)
		{
			return m_intl.ContainsKey(key);
		}

		/** 
		\~korean
		�� �׸��� �߰��Ѵ�.
		\param key �߰��� �׸��� key
		\return ���������� ������ true, �ƴϸ� false�� �����Ѵ�.

		\~english
		Adds a new clause
		\param key key of the clause to be added
		\return True if successfully entered, otherwise returns false.

		\~chinese
		��ʥ��?�͡�
		\param key ��ʥ?����key��
		\return ����?����?true��������?����false��

		\~japanese
		�檷�����ͪ���ʥ���ު���
		\param key ��ʥ�������ͪΫ�?
		\return �����ܪ����ê���true������ǪϪʪ����false��꫿?�󪷪ު���
		\~
		*/
		inline bool Add(const K& key)
		{
			if(ContainsKey(key))
				return false;

			m_intl[key] = 0;
			return true;
		}

		void UseFastHeap(CFastHeap* heap)
		{
			m_intl.UseFastHeap(heap);		
		}
	};

	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
