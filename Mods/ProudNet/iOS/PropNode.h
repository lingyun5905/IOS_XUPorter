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

#if defined(_WIN32)

#include <map>
#include <vector>
#include "FakeClr.h"
#include "Singleton.h"
#include "Marshaler.h"
#include "Message.h"
#include "PNString.h"
#include "Variant.h"

#include "strpool.h"
#include "ReaderWriterMonitor.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif
	/** \addtogroup db_group
	*  @{
	 */

	class CProperty;

	/**
	\~korean 
	PropCollection�� Message ����ȭ ���� ��� 
	
	\~english 
	PropCollection's Message serialization helper functions

	\~chinese
	PropCollection ��Message��?helper������

	\~japanese
	PropCollection��Message��֪���ث��?Ѧ�� 
	\~
	*/
	PROUD_API CMessage& operator<<(CMessage& packet, const CProperty &rhs);

	/**
	\~korean 
	PropCollection�� Message ����ȭ ���� ��� 
	
	\~english 
	PropCollection's Message deserialization helper functions

	\~chinese
	PropCollection ��Message??helper������

	\~japanese
	PropCollection��Message?֪���ث��?Ѧ�� 
	\~
	*/
	PROUD_API CMessage& operator>>(CMessage& packet,CProperty &rhs);

	/** 
	\~korean
	\brief 0�� �̻��� Named Property�� ������ Collection ��ü�̴�. 
	
	����
	- Unique key container associated with one value. ��,
	Set of (key as case insensitive string, value as variant).
	��, key������ ��ҹ��ڸ� �Ȱ����� string�� ���ٴ� ���� �����ϸ� Visual Basic�� 
	Collection�� ���� ������ �Ѵ�. ���� ���, 
	\code
		{ ('name','baehj'), ('id',123), ('height',176) }
	\endcode

	���
	- value type�� _variant_t type�̹Ƿ�, �� ������ �ٷ� ���� ������
	�� �״�� ����ȴ�.(���� ���, long�� ���� �� ������ int�� ȣȯ�� �ȵ�)
	- PropCollection ��ü ��ü�� _variant_t ��ü�� ĳ���õ� �� �ִ�. ���� �ݴ뵵
	�����ϴ�. �̶�, PropCollection�� ������ _variant_t�� serialize�ȴ�.
	�̴� OLE DB���� PropCollection�� ������ binary type field�� ������ �� �ִ�.

	��� ��
	\code
		PropCollection a;
		a.Fields[L"name"]=L"baehj";
		a.Fields[L"id"]=123L;
		a.Fields[L"height"]=176L;
	\endcode
	���� a���� { ('name','baehj'), ('id',123), ('height',176) }�� ����.
	\code
		_bstr_t name=a.GetField(L"name");  -- name �������� "baehj"�� ����.
		_variant_t serialized=a;  //-- serialized���� a�� serialize�� ������ binary type data�� ����.
		PropCollection b;
		b=serialized;	 //-- b�� a�� ���� �ȴ�. 
	\endcode 

	\~english
	\brief A collection object that has more than 0 unit of Named Property 
	
	Definition
	- Unique key container associated with one value. ��, Set of (key as case insensitive string, value as variant).
	  In other words, except the fact that a sting that does not distinguish capital/small letters as key value enters, this acts as Collection of Visual Basic.
	For an example, 
	\code
		{ ('name','baehj'), ('id',123), ('height',176) }
	\endcode

	Function
	- Since its value type is _variant_t type, the considerations must be taken when using this variable apply directly. (For an example, long can be used but int cannot be compatible.)
	- PropCollection object itself can be casted to _variant_t object. And the opposite is also possible. At that time, the contents of PropCollection will serialize to _variant_t.
	  This allows the contents of PropCollection can be stored at binary type field in OLE DB.

	Usage example
	\code
		PropCollection a;
		a.Fields[L"name"]=L"baehj";
		a.Fields[L"id"]=123L;
		a.Fields[L"height"]=176L;
	\endcode
	Now a has { ('name','baehj'), ('id',123), ('height',176) }.
	\code
		_bstr_t name=a.GetField(L"name");  -- "baehj" enters to name variable.
		_variant_t serialized=a;  //-- binary type data that a is serialized will enter serialized.
		PropCollection b;
		b=serialized;	 //-- b becomes equal to a. 
	\endcode 

	\~chinese
	\brief ?��0?�߾Named Property��Collection?�ڡ�

	��?
	- Unique key container associated with one value. ?,
	Set of (key as case insensitive string, value as variant).
	?�������key?��?����������string��?����?�����?Visual Basic��Collection��?�����ġ�������
	\code
		{ ('name','baehj'), ('id',123), ('height',176) }
	\endcode

	����
	- ��?value type��_variant_t type�������??��?���������??�����?�������ġ�������longʦ������ģ�ӣ��int��������黣�
	- PropCollection?������ʦ���casting?_variant_t?�ڡ����������ʦ����??PropCollection��?��_variant_t��serialize��?ʦ��OLE DB��PropCollection��?�?���binary type field�顣

	������
	\code
		PropCollection a;
		a.Fields[L"name"]=L"baehj";
		a.Fields[L"id"]=123L;
		a.Fields[L"height"]=176L;
	\endcode
	����?a��?��{ ('name','baehj'), ('id',123), ('height',176) }��
	\code
		_bstr_t name=a.GetField(L"name");  -- name??��?��"baehj"��
		_variant_t serialized=a;  //-- serialized��?��a��serialize������binary type data��
		PropCollection b;
		b=serialized;	 //-- b?a?���ҡ� 
	\endcode

	\~japanese
	\brief 0���߾��Named Property����Collection���֫������ȪǪ��� 

	����
	- Unique key container associated with one value. ?����
	Set of (key as case insensitive string, value as variant).
	
	?������?�����������Ϭ�骺��string������Ȫ����ê���⪷����Visual Basic��Collection�Ϊ誦����ܪ򪷪ު����Ǫ��С� 
	\code
	{ ('name','baehj'), ('id',123), ('height',176) }
	\endcode

	Ѧ��
	- value type��_variant_t type�ʪΪǡ�����??���⪦��������ê����Ϊު����Ī���ު���(�Ǫ��С�long���Ū��ު�����int����������ު�)
	- PropCollection ���֫��������?�ϡ�_variant_t ���֫������Ȫǫ��㫹�ƫ��󫰪Ǫ��ު����ު�����?��ʦ���Ǫ�����������PropCollection��?黪ϡ�_variant_t��serialize����ު���
	�����OLE DB��PropCollection��?黪�binary type field�������몳�Ȫ��Ǫ��ު���

	������
	\code
	PropCollection a;
	a.Fields[L"name"]=L"baehj";
	a.Fields[L"id"]=123L;
	a.Fields[L"height"]=176L;
	\endcode

	�⪦��a�˪�{ ('name','baehj'), ('id',123), ('height',176) }������ު���
	\code
	_bstr_t name=a.GetField(L"name");  -- name ??�˪�"baehj"������ު���
	_variant_t serialized=a;  //-- serialized�˪�a��serialize���쪿������binary type data������ު���
	PropCollection b;
	b=serialized;	 //-- b��a�Ϊ誦�˪ʪ�ު��� 
	\endcode 



	\~
	*/
	class CProperty
	{
		friend CMessage& operator<<(CMessage& packet, const CProperty &rhs);
		friend CMessage& operator>>(CMessage& packet,CProperty &rhs);
		CStringPool::Holder m_strpool;

	public:
		/** 
		\~korean
		field �̸��� ���� �����ϴ� map ��ü�̴�.
		- ����!! iteration�� ���� �� ������ ����� ���� �����ϴ� ���� ����ϳ�, �б� �������θ� ���� ���� ����Ѵ�.  

		\~english
		Map object that corresponds to field name and value
		- Caution!! It is allowed to directly access to this data member for iteration, but only allowed to write as read only.

		\~chinese
		??field٣��?��map?�ڡ�
		-��򣡣�?��?��iteration�����?�ߣ�ӣ����??��?���졣

		\~japanese
		field٣������??����ޫë׫��֫������ȪǪ���
		- �����!! Iteration�Ϊ���˪��Ϋ�?������?�����ȫ����������몳�Ȫ���ʦ���ު�����?������?�ĪǪΪ��Ū����Ȫ���ʦ���ު���  
		\~
		*/
		typedef CFastMap<String, CVariant, StringTraits> MapType;
	protected:
		// ����: ���⿡ ���� value�� �ݵ�� CStringPool::GetUnsafeRef().GetString(String(key).MakeUpper()) ���� ���� �͸� ����!
		MapType m_map;
	private:
#ifdef _DEBUG
		RefCount<CReaderWriterAccessChecker> m_RWAccessChecker;
#endif // _DEBUG
	public:
		class const_iterator 
		{
			friend CProperty;

//			CProperty* m_owner;
			MapType::const_iterator m_intl;
		public:
			const_iterator() {}
			inline const_iterator(const const_iterator &src) 
			{
//				m_owner = src.m_owner;
				m_intl = src.m_intl;
			}

			inline const_iterator& operator=(const const_iterator &src) 
			{
//				m_owner = src.m_owner;
				m_intl = src.m_intl;

				return *this;
			}

			const_iterator& operator++()
			{
				// preincrement
				m_intl++;
				return (*this);
			}

			const_iterator operator++(int)
			{
				// postincrement
				const_iterator _Tmp = *this;
				++(*this);
				return (_Tmp);
			}

			inline bool operator==(const const_iterator& a) const 
			{
				return m_intl==a.m_intl /*&& m_owner==a.m_owner */;
			}

			inline bool operator!=(const const_iterator& a) const 
			{
				return !(m_intl==a.m_intl /*&& m_owner==a.m_owner */);
			}

			const String GetKey()
			{
				return m_intl->GetFirst();
			}
			CVariant GetValue()
			{
				return m_intl->GetSecond();
			}
			void SetValue(const CVariant &val)
			{
				m_intl->SetSecond(val);
			}
		
#if defined (WIN32)
			__declspec(property(get=GetKey)) const String Key;
			__declspec(property(get=GetValue,put=SetValue)) CVariant Value;
#endif

		};

		const_iterator begin() const
		{
			AssertThreadID(eAccessMode_Read);
			const_iterator ret;
			ret.m_intl = m_map.begin();
			
			ClearThreadID();
			return ret;
		}

		const_iterator end() const
		{
			AssertThreadID(eAccessMode_Read);
			const_iterator ret;
			ret.m_intl = m_map.end();

			ClearThreadID();
			return ret;
		}

		inline size_t GetCount() const
		{
			AssertThreadID(eAccessMode_Read);
			size_t count = m_map.GetCount();
			ClearThreadID();
			return count;
		}
#if defined (WIN32)
		__declspec(property(get = GetCount)) size_t Count;
#endif

		inline void Remove(const String& key)
		{
			AssertThreadID(eAccessMode_Write);
			m_map.Remove(String(key).MakeUpper());
			ClearThreadID();
		}
		inline void Clear()
		{
			AssertThreadID(eAccessMode_Write);
			m_map.Clear();
			ClearThreadID();
		}
		inline bool TryGetValue(const String& key, CVariant& ret)
		{
			AssertThreadID(eAccessMode_Read);
			bool bRet = m_map.TryGetValue(String(key).MakeUpper(), ret);
			ClearThreadID();

			return bRet;
		}
		inline bool ContainsKey(const String& key)
		{
			AssertThreadID(eAccessMode_Read);
			bool bRet = m_map.ContainsKey(String(key).MakeUpper());
			ClearThreadID();
			return bRet;
		}
		inline bool Add(const String& key, const CVariant& val)
		{
			AssertThreadID(eAccessMode_Write);
			bool bRet =m_map.Add(CStringPool::GetUnsafeRef().GetString(String(key).MakeUpper()),val);
			ClearThreadID();
			return bRet;
		}
		inline void CopyKeysTo(CFastArray<String> &dest)
		{
			AssertThreadID(eAccessMode_Read);
			dest.Clear();
			for(const_iterator i = begin(); i!=end();i++)
			{
				dest.Add(i.Key);
			}

			ClearThreadID();
		}

	protected:
		virtual void	AssertThreadID(eAccessMode eMode) const;
		virtual void	ClearThreadID() const;
	public:
		/** 
		\~korean
		�� collection ��ü�� �ִ� Ư�� (key, value) pair�� ���Ѵ�.
		- �� �޼��� ��� Fields[]�� ���� �ٷ�� ���� �� ���ϹǷ� ����ȴ�.
		\return pair�� value. ���� key�� �ش��ϴ� pair�� ������ empty type variant�� �����Ѵ�.
		\param name key of pair whose value should be retrieved  

		\~english
		Gets a specific (key, value) pair in this collection object
		- Direct handling of Fields[] is recommended since it is easier than using this method.
		\return value of the pair. Returns empty type variant when there is no pair corresponds to key.
		\param name key of pair whose value should be retrieved
		\~chinese
		ϴ��collection?��������(key, value) pair��
		- ����??۰������������Fields[]��۰���������?����?��
		\return pair��value������?����?key��pair��?����empty type variant��
		\param name key of pair whose value should be retrieved

		\~japanese
		����collection���֫������Ȫ˪�������(key, value)�ګ���ϴ��ު���
		- ���Ϋ᫽�ëɪ��۪���Fields[]�������⪦�Ϊ���ê�?�Ǫ��ΪǪ�?�᪷�ު���
		\return pair��value���⪷��key����?����pair���ʪ����empty type variant��꫿?�󪷪ު���
		\param name key of pair whose value should be retrieved  
		\~
		*/
		PROUD_API CVariant GetField(const String &name);

		/** 
		\~korean
		�� collection ��ü�� Ư�� (key, value) pair�� �ִ´�. �̹� ���� key�� ������ pair�� ������ �װ��� ���ɷ� ��ü�Ѵ�.
		- �� �޼��� ��� Fields[]�� ���� �ٷ�� ���� �� ���ϹǷ� ����ȴ�.
		\param name key of pair
		\param value value of pair  

		\~english
		Specific (key, value) pair to be entered to this collection object. If there is the pair that has same key than new comer replaces itself with old one.
		- Direct handling of Fields[] is recommended since it is easier than using this method.
		\param name key of pair
		\param value value of pair

		\~chinese
		��??collection?��?������(key, value) pair���������?������key��pair��?������������
		- ����??۰������������Fields[]��۰���������?����?��
		\param name key of pair
		\param value value of pair

		\~japanese
		����collection���֫������Ȫ�����(key, value)pair������ު���?���Ҫ�key����pair������С�������檷����Ϊ������𪨪ު���
		- ���Ϋ᫽�ëɪ��۪���Fields[]�������⪦���Ȫ���ê����תǪ��ΪǪ�?�᪷�ު���
		\param name key of pair
		\param value value of pair  

		\~
		*/
		PROUD_API virtual void SetField(const String &name,const CVariant &value);

		/** 
		\~korean
		�� collection ��ü���� Ư�� (key, value) pair�� �����Ѵ�.
		\param name ������ pair�� key ��  

		\~english
		Removes specific (key, value) pair from this collection object
		\param name key value of pair to be removed

		\~chinese
		?collection?��?�����(key, value) pair��
		\param name �?���pair��key?��

		\~japanese
		����collection���֫������Ȫ�����(key, value) pair����۪��ު���
		\param name ��۪���pair��key��  
		\~
		*/
		PROUD_API virtual void RemoveField(const String &name);

		/** 
		\~korean
		serialize�� �Ǿ� �ִ� bytearray type�� variant�� ������ deserialize�ؼ� �� ��ü�� ä���.
		\param from.. ���� ����  

		\~english
		The contents of variant of serialized bytearray type are to be deserialized and to be filled to this object.
		\param from.. oriinal to copy

		\~chinese
		��serialize�� bytearray type��variant?�?��deserialize��?�����?�ڡ�
		\param from.. ?����

		\~japanese
		Serialize����ƪ���bytearray type��variant��?黪�deserialize���ƪ��Ϋ��֫������Ȫ�?�����ު���
		\param from.. ����?��� 
		\~
		*/
		PROUD_API virtual void FromVariant(_variant_t from);

		virtual void FromByteArray(const ByteArray &from);

		PROUD_API virtual void FromByteArray(const uint8_t* data,int length);

		PROUD_API virtual void ToByteArray(ByteArray &output);


		/** 
		\~korean
		�⺻ ������  

		\~english
		Base constructor

		\~chinese
		����������

		\~japanese
		���������  
		\~
		*/
		PROUD_API CProperty();
		PROUD_API CProperty(const CProperty& rhs);

		virtual ~CProperty();

		/** 
		\~korean 
		CVariant type�� ȣȯ�ǰ� �ϴ� helper function 
		
		\~english 
		Helper function that make compatibility with CVariant type

		\~chinese
		? CVariant type�����helper function

		\~japanese
		CVariant type�����������誦�˪���helper function 
		\~
		*/
		CProperty(_variant_t from);

		/** 
		\~korean 
		_variant_t type�� ȣȯ�ǰ� �ϴ� helper function 
		
		\~english 
		Helper function that make compatibility with _variant_t type

		\~chinese
		?_variant_t type �����helper function��

		\~japanese
		_variant_t type�����������誦�˪���helper function 
		\~
		*/
		PROUD_API operator _variant_t() const;
		PROUD_API operator ByteArrayPtr() const;

		/** 
		\~korean 
		���� ������ 
		
		\~english 
		Copy creator

		\~chinese
		?�������

		\~japanese
		����?�����
		\~
		*/
		inline CProperty & operator=( const _variant_t &from)
		{
			FromVariant(from);
			return *this;
		}
		inline CProperty & operator=( ByteArray &from)
		{
			FromByteArray(from);
			return *this;
		}

		inline CProperty & operator=( const CProperty &rhs)
		{
			rhs.AssertThreadID(eAccessMode_Read);
			AssertThreadID(eAccessMode_Write);
			m_map = rhs.m_map;
			ClearThreadID();
			rhs.ClearThreadID();

			return *this;
		}

		/** 
		\~korean
		�ʵ��� ���� �аų� ����� �� ����Ѵ�. �ڼ��� ���� \ref dbc1_adding_fields  ����.  

		\~english
		Used to read or write field value. Please refer \ref db_adding_fields

		\~chinese
		?���???�?��?�����ġ�????��\ref dbc1_adding_fields%��

		\~japanese
		�ի�?��ɪ�����?�������?���������Ū��ު����٪����ϡ�\ref dbc1_adding_fields��?�Ϊ���������
		\~
		*/
#if defined (WIN32)
		__declspec(property(get=GetField,put=SetField)) CVariant Fields[];
#endif

		/** 
		\~korean
		�� �ݷ��� ��ü�� ������ ���ڿ��� ���� ����Ѵ�. 
		- ������� �� �� �����ϴ�.  

		\~english
		Converts the contents of this collection object into text string then outputs 
		- Useful when debugging

		\~chinese
		���collection?����?�??���ݬ����?��
		- ?��??��?��????�档

		\~japanese
		���Ϋ��쫯����󫪫֫������Ȫ�?黪����֪���ªê��������ު���
		- �ǫЫë��󫰪򪹪������涪Ǫ���
		\~
		*/
		PROUD_API String GetDumpedText();
	};

	class CDbCacheServerImpl;
	class CDbCacheClientImpl;
    class CDbCacheServer2Impl;
    class CDbCacheClient2Impl;
	class CLoadedData;
	class CLoadedData_S;
	class CLoadedData2;
	class CLoadedData2_S;
	class CPropForest;
	class CPropNode;
	typedef RefCount<CPropNode> CPropNodePtr;

	/** 
	\~korean 
	PropCollection�� Message ����ȭ ���� ��� 
	
	\~english 
	PropCollection's Message serialization helper functions 

	\~chinese
	PropCollection ��Message��?helper������

	\~japanese
	PropCollection��Message��֪���ث��?Ѧ�� 
	\~
	*/
	PROUD_API CMessage& operator<<(CMessage& packet,CPropNode &rhs);

	/** 
	\~korean 
	PropCollection�� Message ����ȭ ���� ��� 
	
	\~english 
	PropCollection's Message deserialization helper functions 

	\~chinese
	PropCollection ��Message??helper������

	\~japanese
	PropCollection��Message?֪���ث��?Ѧ�� 
	\~
	*/
	PROUD_API CMessage& operator>>(CMessage& packet,CPropNode &rhs);

	/** 
	\~korean
	Property �� ��ӹ��� Ŭ�����μ� CPropForest �� �Ѱ��� ��带 ����Ų��.
	CPropNodePtr �� �����Ͽ� CLoadedData �� �����Լ��鿡�� �����̳� ������ �ϸ� �ȴ�.
	CPropNodePtr node = new(CPropNode(L"���̺��̸�"));
	��뿹�� CProperty �� ����.

	\~english
	As the class that inherited Property, it points a node of CPropForest.
	Created using CPropNodePtr and to perform insertion or deletion at the functions provided by CLoadedData
	CPropNodePtr node = new(CPropNode(L"table name"));
	Please refer CProperty for how to use.

	\~chinese
	��?�Property��?����� CPropForest%����??�á�
	�� CPropNodePtr%������� CLoadedData%�������??�����?�?ʦ��
	CPropNodePtr node = new(CPropNode(L"��̫٣�"));
	������??�� CProperty%��

	\~japanese
	Property����?���ƪ��ê����髹�Ȫ���CPropForest�����?�ɪ�򦪷�ު���
	CPropNodePtr����������CLoadedData�����??�ʪɪ�?���ު�����𶪹����ު��Ǫ���
	CPropNodePtr node = new(CPropNode(L"��?�֫�٣"));
	�����Ǫ�CProperty��?�Ϊ���������
	\~
	*/
	class CPropNode:public CProperty
	{
		// NOTE: children�� ������. child=���� ���, sibling=���� ���
		friend CLoadedData;
		friend CLoadedData_S;
		friend CLoadedData2;
		friend CLoadedData2_S;
		friend CPropForest;
		friend CMessage& operator<<(CMessage& packet,CPropNode &rhs);
		friend CMessage& operator>>(CMessage& packet,CPropNode &rhs);
		friend CDbCacheClientImpl;
		friend CDbCacheServerImpl;

		friend CDbCacheClient2Impl;
		friend CDbCacheServer2Impl;

	private:
		//modify by rekfkno1 - ���� ptr�� �����ϰ� ������ ������ �ı����� �ʴ� 
		// ������ �ִ�!!!! ��!!! �����ͷ� ����Ұ�...

		/** 
		\~korean
		��ü�� child�� �����ϰ� �ִ� Node�� ������

		\~english
		Pointer of node that refer to object as child

		\~chinese
		��?��?��?child��Node���?��

		\~japanese
		���֫������Ȫ�child��?�Ϊ��ƪ���Node�Ϋݫ���?
		\~
		*/
		CPropNode*  m_parent;

		/** 
		\~korean
		��ü�� parent�� �����ϰ� �ִ� Node�� ������

		\~english
		Pointer of node that refer to object as parent

		\~chinese
		��?��?��?parent��Node�?��

		\~japanese
		���֫������Ȫ�parent��?�Ϊ��ƪ���Node�Ϋݫ���?
		\~
		*/
		CPropNode*  m_child;

		/** 
		\~korean
		��ü�� ������ ���� ������

		\~english
		Reference point that has same level with object

		\~chinese
		??����??��?���?��

		\~japanese
		���֫������Ȫ������?�Ϋݫ���?
		\~
		*/
		CPropNode*  m_sibling;
 
		/*
		sibling ����� ������ �����͸� ������ �ִ�.
		*/
		CPropNode*  m_endSibling;

		// 3���� �⺻ �ʵ�. ��� ��ü�� guid
		Guid		m_UUID;
		// ���� ����� guid
		Guid		m_ownerUUID;
		// �ֻ��� ����� guid. loaded data�� �����̱⵵ �ϴ�.
		Guid		m_RootUUID;

		// 1�� �̻��� field�� ����Ǿ����� ���� DB�� ��ϵ��� �ʾ����� true
		bool		m_dirtyFlag;

		// ���� �޸𸮰� ��ȭ�ϸ� ���õǴ� ��.(soft=unilateral, hard=request/response)
		bool		m_issuedSoft;
	public:
		/** 
		\~korean
		�� ����� Ÿ���̸�.
		- DbCacheSystem ������ ���� ���̺� �̸����� ���˴ϴ�.

		\~english
		Type name of this node.
		- It use for normal table name at DbCacheSystem

		\~chinese
		�?����?��٣��
		- �DbCacheSystem������������̫٣��

		\~japanese
		���Ϋ�?�ɪΫ�����٣
		- DbCacheSystem�Ǫ����׫�?�֫�٣�����Ī���ު���
		\~
		*/
		String	m_INTERNAL_TypeName;
		inline const PNTCHAR* GetTypeName() const { return m_INTERNAL_TypeName; }
		void SetTypeName(const PNTCHAR* str);

		inline String GetStringTypeName() const {return m_INTERNAL_TypeName;}
		void SetStringTypeName(String str);
	private:
		virtual void FromVariant(_variant_t from) PN_OVERRIDE;

		virtual void FromByteArray(const ByteArray &from) PN_OVERRIDE;

		virtual void FromByteArray(const uint8_t* data,int length) PN_OVERRIDE;
		void	FromByteArray(const uint8_t* data,int length,Guid& siblingUUID);

		void	SoftWorkIssued(){m_issuedSoft = true;}
		void	ClearSoftWorkIssued(){m_issuedSoft = false;}
	public:

		/** 
		\~korean 
		�ڽ� ��带 ������ �纻�� �����մϴ�. 

		\~english
		Clones of this node without children. 

		\~chinese
		к��???��?������(TODO: translation review needed)

		\~japanese
		��?�ɪ���⪷������?���������ު���
		\~ 
		*/
		CPropNodePtr CloneNoChildren();

	public:

		/** 
		\~korean
		�� node ��ü�� Ư�� (key, value) pair�� �ִ´�. �̹� ���� key�� ������ pair�� ������ �װ��� ���ɷ� ��ü�Ѵ�.
		- �� �޼��� ��� Fields[]�� ���� �ٷ�� ���� �� ���ϹǷ� ����ȴ�.
		\param name key of pair
		\param value value of pair  

		\~english
		Put specific (key, value) pair to node object. If pair with same key is existed then replace it to brandnew one.
		- We recommend to use Fields[] instead of this method.
		\param name key of pair
		\param value value of pair  

		\~chinese
		��??node?��?������(key, value) pair���������?������key��pair��?������������
		- ����??۰������������Fields[]��۰���������?����?��
		\param name key of pair
		\param value value of pair

		\~japanese
		����node���֫������Ȫ�����(key, value) pair������ު���?���Ҫ�key����pair������Ъ�����檷����Ϊ������𪨪ު���
		- ���Ϋ᫽�ëɪ��۪���Fields[]��������ê�۰����ê�?�Ǫ��ΪǪ�?�᪷�ު���
		\param value value of pair  
		\~
		*/
		PROUD_API virtual void SetField(const String &name,const CVariant &value) PN_OVERRIDE;

		/** 
		\~korean
		�� node ��ü���� Ư�� (key, value) pair�� �����Ѵ�.
		\param name ������ pair�� key ��  

		\~english
		Remove specific (key, value) pair from this node object.
		\param name Key value of pair that need to remove

		\~chinese
		?node?��?�����(key, value) pair��
		\param name �?���pair��key?��

		\~japanese
		����node���֫������Ȫ�����(key, value) pair����۪��ު���
		\param name ��۪���pair��key��
		\~
		*/
		PROUD_API virtual void RemoveField(const String &name) PN_OVERRIDE;

		/** 
		\~korean
		������ ������ ByteArray �� ����ϴ�.
		- ���� ����ڴ� ����� ���� �����ϴ�.

		\~english
		Put data information to ByteArray.
		- Ordinary user does not need to use.

		\~chinese
		��?������?�� ByteArray��
		- ��������?��������ġ�

		\~japanese
		��?�����ê� ByteArray������ު���
		- ���׫�?��?�����Ī��몳�Ȫ�����ު���
		\~
		*/
		PROUD_API virtual void ToByteArray(ByteArray &output) PN_OVERRIDE;

		inline CPropNode* GetChild(){return m_child;}
		inline CPropNode* GetSibling(){return m_sibling;}
		inline CPropNode* GetEndSibling(){ return m_endSibling; }
#if defined (WIN32)
		__declspec(property(get=GetChild)) CPropNode* Child;
		__declspec(property(get=GetSibling)) CPropNode* Sibling;
		__declspec(property(get = GetEndSibling)) CPropNode* EndSibling;
#endif

		inline Guid	GetUUID() { return m_UUID; }
		inline Guid	GetOwnerUUID() { return m_ownerUUID;  }
		inline Guid GetRootUUID() { return m_RootUUID; }

#if defined (WIN32)
		__declspec(property(get=GetUUID)) Guid UUID;
		__declspec(property(get=GetOwnerUUID)) Guid OwnerUUID;
		__declspec(property(get=GetRootUUID)) Guid RootUUID;
		__declspec(property(get=GetStringTypeName,put=SetStringTypeName)) String TypeName; 
#endif

		bool	IsSoftWorkIssued(){return m_issuedSoft;}
		
		/**
		\~korean
		�⺻ ������ 

		\~english
		Base constructor

		\~chinese
		����������

		\~japanese
		���������
		\~
		*/
		PROUD_API CPropNode(const PNTCHAR* TypeName);
		PROUD_API CPropNode(const CPropNode& from);
		virtual ~CPropNode();

		inline CPropNode & operator=( const CPropNode& from )
		{
			AssertThreadID(eAccessMode_Write);
			m_map = from.m_map;
			m_parent = from.m_parent;
			m_child = from.m_child;
			m_sibling = from.m_sibling;
			m_endSibling = from.m_endSibling;
			m_INTERNAL_TypeName = CStringPool::GetUnsafeRef().GetString(String(from.m_INTERNAL_TypeName));
			m_UUID = from.m_UUID;
			m_ownerUUID = from.m_ownerUUID;
			m_RootUUID = from.m_RootUUID;
			m_dirtyFlag = from.m_dirtyFlag;
			ClearThreadID();
			return *this;
		}

		inline CPropNode& operator =(const CProperty& from)
		{
			CProperty::operator=(from);
			return *this;
		}

#ifdef _WIN32
#pragma push_macro("new")
#undef new
		// �� Ŭ������ ProudNet DLL ��츦 ���� Ŀ���� �Ҵ��ڸ� ���� fast heap�� ���� �ʴ´�.
		DECLARE_NEW_AND_DELETE
#pragma pop_macro("new")
#endif
	};

	

	/** 
	\~korean
	CPropForest �� 1�� �̻��� tree�� ������ �� ��ü�Դϴ�.
	CPropForest �� ���� CPropNode Ÿ���Դϴ�. 
	- ����ڴ� ������ ������� ���ʽÿ�.

	������ ��� �����Դϴ�.
	\code

		CPropForest f; // ���赵�Դϴ�.

		// jack�� ��Ʈ�� �ٽ��ϴ�.
		CPropNode* jack = new CPropNode;
		f.InsertChild(NULL, jack);

		// jane�� jack�� ��ȥ�߽��ϴ�.
		CPropNode* jane = new CPropNode;
		f.InsertSiblingAfter(jack, jane);

		// �� wendy�� �¾���ϴ�.
		CPropNode* wendy = new CPropNode;
		f.InsertChild(jack, wendy);

		// wendy�� �Ŷ� tony�� ��ȥ�߽��ϴ�. 
		CPropNode* tony = new CPropNode;
		f.InsertSiblingBefore(wendy, tony);

		// tony�� wendy ���̿� terry�� �¾���ϴ�.
		CPropNode* terry = new CPropNode;
		f.InsertChild(tony, terry);

		// tony�� �ٶ����� ���������ϴ�. terry�� ���� ������ ���Ƚ��ϴ�. 
		f.RemoveNode(tony);

	\endcode

	\~english
	CPropForest is a forest type object that has more than 1 tres.
	    Node of CPropForest is CpropNode type. 

	Following is an example for usage.
	\code

		CPropForest f; // Family tress

		// Jack is attached to root.
		CPropNode* jack = new CPropNode;
		f.InsertChild(NULL, jack);

		// Jane is married to Jack.
		CPropNode* jane = new CPropNode;
		f.InsertSiblingAfter(jack, jane);

		// Daughter Wendy is born.
		CPropNode* wendy = new CPropNode;
		f.InsertChild(jack, wendy);

		// Wendy is married to Tony. 
		CPropNode* tony = new CPropNode;
		f.InsertSiblingBefore(wendy, tony);

		// Tony and Wendy bore Terry.
		CPropNode* terry = new CPropNode;
		f.InsertChild(tony, terry);

		// Tony left haveing an affair. He took Terry as well. 
		f.RemoveNode(tony);
	\endcode

	\~chinese
	CpropForest ��?����?�߾��tree��ߵ��?�ڡ�
	CPropForest ��?���� CPropNode%?����
	- ��??ʦ��������ġ�

	�������������
	\code

		CPropForest f; // ʫͧ?��

		// jack??��?��.
		CPropNode* jack = new CPropNode;
		f.InsertChild(NULL, jack);

		// jane?jack?������
		CPropNode* jane = new CPropNode;
		f.InsertSiblingAfter(jack, jane);

		// ҳ?wendy��������
		CPropNode* wendy = new CPropNode;
		f.InsertChild(jack, wendy);

		// wendy?����tony?������ 
		CPropNode* tony = new CPropNode;
		f.InsertSiblingBefore(wendy, tony);

		// tony?wendy��?terry��������
		CPropNode* terry = new CPropNode;
		f.InsertChild(tony, terry);

		// tony����Ա?����?Terry�����?������ 
		f.RemoveNode(tony);

	\endcode

	\~japanese
	CPropForest ��1���߾��tree����ߵ���֫������ȪǪ���
	CPropForest�Ϋ�?�ɪ�CPropNode�����תǪ���
	- ��?��?�Ϫʪ�٪��Ū�ʪ��Ǫ���������
	���������ƪǪ���
	\code
	CPropForest f; // ʫͧ?�Ǫ���
	// jack����?�Ȫ˪Ī��ު���
	CPropNode* jack = new CPropNode;
	f.InsertChild(NULL, jack);

	// jane��jack��̿�檷�ު�����.
	CPropNode* jane = new CPropNode;
	f.InsertSiblingAfter(jack, jane);

	// Ҧ��wendy����ު�ު�����
	CPropNode* wendy = new CPropNode;
	f.InsertChild(jack, wendy);

	// wendy����?��tony��̿�檷�ު�����
	CPropNode* tony = new CPropNode;
	f.InsertSiblingBefore(wendy, tony);

	// tony��wendy�����terry����ު�ު�����
	CPropNode* terry = new CPropNode;
	f.InsertChild(tony, terry);

	// tony��ݩ?�򪷪�Ա���ƪ��ު��ު�����Terry����?��֧��������ު����� 
	f.RemoveNode(tony);
	\endcode


	\~
	*/


	/**  @}  */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif // _WIN32