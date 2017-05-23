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

#include "pnstdint.h" 

#include "BasicTypes.h"
#include "atomic.h"
#include "CriticalSect.h"
#include "Enums.h"
#include "ProcHeap.h"


#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4324)
#endif 

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup util_group
	*  @{
	*/

#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif

	class CLookasideAllocator;

	/** 
	\~korean
	reference count�� ���� �ʴ� �� smart�� pointer�̴�.
	- ATL CAutoPtr�� ���� ������ �Ѵ�.
	- �� ��ü�� �ı��� �� hold�ϰ� �ִ� pointer�� object�� delete�Ѵ�. 

	\~english
	A less smart pointer that does not count reference count
	- Acts as ATL CAutoPtr
	- When this object is destructed, the object of the pointer that is held by this object is deleted.

	\~chinese
	��?reference cout������smart��pointer��
	- ���?ATL CAutoPtr%��?�����ġ�
	- ???������?��?��delete���hold��pointer��object��

	\~japanese
	reference count��?���ʪ����ު꫹��?�ȪǪϪʪ�pointer�Ǫ���
	- ATL CautoPtr�Ϊ誦����ܪ򪷪ު���
	- ���Ϋ��֫������Ȫ���?���������Hold���ƪ���pointer�Ϋ��֫������Ȫ���𶪷�ު���
	\~
	*/
	template<typename T>
	class CHeldPtr
	{
	public:
		T* m_p;

		inline CHeldPtr() : m_p(NULL) {}
		
		inline CHeldPtr(T* p_) : m_p(p_) {}
		
		inline CHeldPtr& operator=(T* p_)
		{
			m_p = p_;
			return *this;
		}

		inline ~CHeldPtr()
		{
			if (m_p)
				delete m_p;
		}

		/**
		\~korean 
		object�� �����Ѵ�. 

		\~english 
		Remove an object. 

		\~chinese
		?�object��

		\~japanese
		Object����۪��ު���
		\~
		*/
		inline void Free()
		{
			if(m_p)
				delete m_p;
			m_p=0;
		}

		/**
		\~korean
		object�� attach�Ѵ�.
		- �̹� �ٸ� ���� attach�ϰ� �ִ� ��� �װ��� delete������ �ʴ´�.
		\param p_ attach�� ��ü�� ������

		\~english 
		Attach an object
		- If something else is already attached, do not delete it. 
		\param p_ Pointer of the object to be attached. 

		\~chinese
		Attach object��
		- ���attach����?��?����?�?��
		\param p_ �attach��?�����?��

		\~japanese
		Object��attach���ު���
		- ?����Ϊ�Ϊ�Attach���ƪ������ꡢ�������𶪹�몳�ȪϪ���ު���
		\param p_ attach���뫪�֫������ȪΫݫ���?
		\~
		*/
		inline void Attach(T* p_)
		{
			m_p = p_;
		}

		/** 
		\~korean
		object�� detach�Ѵ�. ��, hold�ϰ� �ִ� object�� NULL�� �����Ѵ�.
		- ���� attach�� object�� delete������ �ʴ´�.
		- ��, Attach(NULL)�� ���� ������ �Ѵ�.

		\~english 
		Detach an object. In other words, the object being held is set to null. 
		- Do not delete the previously attached object. 
		- In other words, it performs the same role as Attach (NULL). 

		\~chinese
		Detach object��??hold����object?����NULL��
		- ��delete����attach��object��
		- ?���?Attach(NULL)��?�����ġ�

		\~japanese
		Object��detach���ު���?����hold���ƪ���object��NULL�����Ҫ��ު���
		- ?���attach���쪿object����𶪹�몳�ȪϪ���ު���
		- ?����Attach(NULL)�Ϊ誦����ܪ򪷪ު���
		\~
		*/
		inline void Detach()
		{
			m_p = NULL;
		}

		inline operator T*() const
		{
			return m_p;
		}

		inline T* operator->() const
		{
			return m_p;
		}

		NO_COPYABLE(CHeldPtr)
	};

	template<typename T>
	inline bool operator<(const CHeldPtr<T> a, const CHeldPtr<T> b)
	{
		return a.m_p < b.m_p;
	}

	template <typename T> class SmartPtr {
		T* p;
	public:
		SmartPtr(T* p_) : p(p_) {
			p->upcount();
		}
		~SmartPtr(void) {
			p->downcount();
		}
		operator T*(void) {
			return p;
		}
		T& operator*(void) {
			return *p;
		}
		T* operator->(void) {
			return p;
		}
		SmartPtr& operator=(SmartPtr<T> &p_)
		{
			return operator=((T *) p_);
		}
		SmartPtr& operator=(T* p_) {
			p->downcount();
			p = p_;
			p->upcount();
			return *this;
		}
	};

// 	PROUD_API void* RefCount_LookasideAllocator_Alloc(size_t length);
// 	PROUD_API void RefCount_LookasideAllocator_Free(void* ptr);

	/** 
	\~korean
	Smart pointer Ŭ����. �ڼ��� ������ <a target="_blank" href="http://guide.nettention.com/cpp_ko#smart_ptr" >����Ʈ ������</a>�� �ִ�.

	RefCount�� ���� ������ �����ؾ� �Ѵ�.
	- RefCount�� ���ʷ� ��ü�� ������ �� Tombstone�̶�� ���� �����. �׸��� ������ ���� ���� ��ü�� ����� �� tombstone�� �����ȴ�.
	�� tombstone�� ���ʿ� �����ϴ� �ð� ���(�޸� �Ҵ� 1ȸ)�� ���. 
	- ���� �ٸ� ������ Ŭ���� Ÿ������ ĳ������ �ȵȴ�. ������ RefCount<CFile>�� RefCount<CObject>�� ������ �� ����.
	�̷� ���� RefCount�� class type���� ������ ���� base class�� �ְ� �ڵ��� type cast�� �Ź� �ؾ� �Ѵ�. 
	\code
	class Base {};
	class A:public Base {};

	void Foo()
	{
	   RefCount<A> a;
	   RefCount<Base> b;
	   a = b; // ����
	}

	void Foo2()
	{
	   RefCount<Base> a;
	   RefCount<Base> b(new A);
	   a = b; // OK
	   A* p = (A*)a.get(); // Ÿ�� A�� �����Ϸ��� �̷��� �ؾ� �Ѵ�.
	}
	\endcode
	
	\param T ����Ʈ �����Ͱ� �ٷ� ��ü�� Ÿ��
	\param AllocT AllocType �� �� �ϳ�. 
	\param IsThreadSafe <�Ⱦ�!> true�̸� �� ����Ʈ ������ ������ ���� �����尡 ���ÿ� �ٷ� �����ϴ�. �׷��� ���� ���ϰ� �ִ�.

	\~english
	Smart pointer class. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#smart_ptr" >Smart Pointer</a>.

	When using RefCount, the following must be considered.
	- When RefCount refers object for the first time, it creates Tombstone. And when joint reference object appears, this tombstone will be shared.
	  In other words, there is a time cost(memory allocation, 1 time) to create tombstone initially. 
	- Cannot cast to related class types that are different to each other. Which means, RefCount<CFile> cannot be copied to RefCount<CObject>.  
	  Type cast must be performed each time when coding as class type of RefCount entered higher possible base class.
	\code
	class Base {};
	class A:public Base {};

	void Foo()
	{
	   RefCount<A> a;
	   RefCount<Base> b;
	   a = b; // Error
	}

	void Foo2()
	{
	   RefCount<Base> a;
	   RefCount<Base> b(new A);
	   a = b; // OK
	   A* p = (A*)a.get(); // This must be done to refer type A.
	}
	\endcode
	
	\param T Type of object that is to be handled by smart pointer
	\param AllocT one of the values of AllocType 
	\param IsThreadSafe <NEVER USED!> If true then it is safe that many threads handle the variable of this smart pointer. But it reduces overall performance.

	\~chinese
	Smart pointer?��???��<a target="_blank" href="http://guide.nettention.com/cpp_zh#smart_ptr" >Smart�?</a>%��

	����RefCount��?���������?�á�
	- RefCount����?��?����?��?��УTombstone��?ड�������������?��?������??�tombstone��������
	??���������tombstone��???�ģ�?��������󭣩��
	- ����������������????��?��cast������������RefCount<CFile>?�?RefCount<CObject>��
	??��?��RefCount��class type?ʦ��?��߾��base class��?��?���Դ�?��type cast��
	\code
		class Base {};
		class A:public Base {};

		void Foo()
		{
		   RefCount<A> a;
		   RefCount<Base> b;
		   a = b; // ??
		}

		void Foo2()
		{
		   RefCount<Base> a;
		   RefCount<Base> b(new A);
		   a = b; // OK
		   A* p = (A*)a.get(); // ��?��A��?�??񮡣
		}
	\endcode

	\param T smart�?�?����?��?����
	\param AllocT AllocType?�����顣
	\param IsThreadSafe <���ģ�> true��?�?����??���smart�???����ӣ������?��˽��

	\~japanese
	Smart pointer ���髹���٪����ϡ�\ref smart_ptr�˪���ު���

	RefCount��������������򪷪ʪ���Ъʪ�ު���
	- RefCount������ƫ��֫������Ȫ�?������Tombstone�Ȫ������Ȫ��ª�ު��������ơ��˽������?�Ϋ��֫������Ȫ��������˪���tombstone�����󪵪�ު���
	?����tombstone������������������૳����(����?��?1��)��������ު��� 
	- �������ު�?֧�������髹�����תǫ��㫹�ƫ��󫰪�����ު����Ǫ��С�RefCount<CFile>��RefCount<CObject>�˫���?���몳�ȪϪǪ��ު���
	���Ϊ誦�������RefCount��class type�Ǫʪ�٪�߾�Ȫ�base class������ƫ�?�ǫ�������type cast��?�ު��ʪ���Ъʪ�ު��� 
\code
	class Base {};
	class A:public Base {};

	void Foo()
	{
	   RefCount<A> a;
	   RefCount<Base> b;
	   a = b; // ����?��
	}

	void Foo2()
	{
	   RefCount<Base> a;
	   RefCount<Base> b(new A);
	   a = b; // OK
	   A* p = (A*)a.get(); // ������A��?�Ϊ��몿��˪Ϫ��Ϊ誦�˪��ʪ���Ъʪ�ު���
	}
	\endcode

	\param T ����?�ȫݫ���?���⪦���֫������ȪΫ�����
	\param AllocT AllocType ���Ϊ�����ġ� 
	\param IsThreadSafe <�Ū�ʪ�!> true�Ǫ���Ъ��Ϋ���?�ȫݫ���???����?�Ϋ���ëɪ���������êƪ�����Ǫ������������������������ު���

	\~
	*/
	template<typename T>
	class RefCount 
	{
	public:
		typedef RefCount<T> Type;
	private:
		struct Tombstone 
		{
			T* m_ptr;

			/* ���� Ȯ���� �� ����? 64bit������ reference count�� 2^32�� �Ѿ�� ���� �� ����.
			���� �����忡�� ���ÿ� assign�̳� �Ϲ����� scope out�� ���� ��� �󸶵��� thread unsafe�� ���� �� �ִ�. 
			���� �� ���� atomic op���θ� �ٷ������ �Ѵ�. */
			PROUDNET_VOLATILE_ALIGN intptr_t m_count; 
 
			inline Tombstone() {}
			inline ~Tombstone() {
				delete m_ptr;
			}
#ifdef _WIN32
 #pragma push_macro("new")
 #undef new
		private:
			// new,delete oper ������Ŵ
			void* operator new(size_t size);
			void operator delete(void* ptr, size_t size);
		public:
 #pragma pop_macro("new")
#endif
		public:
			/**
			\~korean
			CFirstHeap�� CSingleton ����. 
			- CSingleton�� RefCount�� ����. 
			- ���� CSingleton�� CFirstHeap ��� ����.
			- object�� ���� ����
			- ��ü������ new�� �� �� ���Բ� �Ǿ�����

			\~english TODO:translate needed
			CFirstHeap refers to CSingleton
			- CSingleton refers to RefCount
			- Therefore, CSingleton is forbidden to use CFirstHeap.
			- It generates objects. 
			- It is made not to do new on its own. 

			\~chinese
			CFirstHeap ?�� CSingleton%��
			- CSingleton%?��RefCount��
			- ��� CSingleton%������� CFirstHeap%��
			- ����object��
			- ��?��������new��

			\~japanese
			CFirstHeap��CSingleton��?�Ϊ��������� 
			- CSingleton��RefCount��?�Ϊ��������� 
			- ��êơ�CSingleton��CFirstHeap�������
			- object���������ު���
			- �?�ܪ�new���Ǫ��ʪ��ʪêƪ��ު���
			\~
			*/
			inline static Tombstone* NewInstance()
			{
				Tombstone* ret = (Tombstone*)CProcHeap::Alloc(sizeof(Tombstone));  // �ݵ�� CProcHeap�� ��� �Ѵ�. CFirstHeap�� ���μ��� ������ ��� �Ұ��̹Ƿ�.				
				if(ret == NULL)
				 ThrowBadAllocException();
 
				CallConstructor<typename Type::Tombstone>(ret);// <Type::Tombstone>�� �ٿ��� �����Ϸ��� ������ Ÿ�� ��Ī�� �ϴ� ���׸� ����
 
				return ret;
			}
 
			/**
			\~korean
			 object�� ������.
			- ��ü�� delete�� �� �� ����
			\param object ������ ��ü

			\~english 
			Removes objects. 
			- It cannot delete on its own. 
			\param object Object to be removed. 

			\~chinese
			?�object��
			- ����?��������delete��
			\param object �?���?�ڡ�

			\~japanese
			Object����۪��ު���
			- �?�ܪ�delete���������Ȫ��Ǫ��ު���
			\param object ��۪��뫪�֫�������
			\~
			*/
			inline static void DeleteInstance(Tombstone* object)
			{
				CallDestructor<typename Type::Tombstone>(object);// <Type::Tombstone>�� �ٿ��� �����Ϸ��� ������ Ÿ�� ��Ī�� �ϴ� ���׸� ����
 
				CProcHeap::Free(object);
			}

			NO_COPYABLE(Tombstone)
		};
 
		Tombstone* m_tombstone;
 
	public:
		/** 
		\~korean
		�� ��ü�� �����ϰ� �ִ� �ٸ� ���� ��ü���� ������ �����Ѵ�. �� ���� Ƚ����. 

		\~english
		Returns the number of other variable objects that refer this object. In other words, the number of referring.

		\~chinese
		����?���?��������???��??��??���?��

		\~japanese
		���Ϋ��֫������Ȫ�?�Ϊ��ƪ������??���֫������Ȫ�?��꫿?�󪷪ު���?����?����?�Ǫ���
		\~
		*/
		inline intptr_t GetRefCount() 
		{
			if (!m_tombstone)
				return 0;
 
			return m_tombstone->m_count;
		}
 
		/** 
		\~korean
		������. ������ p�� ����Ű�� ��ü�� �������� �����´�. 

		\~english
		Constructor. Brings the ownership of the object that pointer p points.

		\~chinese
		���������?p����?�������?��

		\~japanese
		�������ݫ���?p��򦪹���֫������Ȫ����?������?�ߪު���
		\~
		*/
		inline explicit RefCount(T* p = 0)			
		{
			if(p)
			{
				m_tombstone = Tombstone::NewInstance();
				
				m_tombstone->m_count = 1;
				m_tombstone->m_ptr = p;
			}
			else
				m_tombstone = 0;
		}
		/** 
		\~korean
		���� ���� ������ 

		\~english
		Copy assignment operator

		\~chinese
		?�???ߩݬ��

		\~japanese
		����?������ߩ�
		\~
		*/
		inline RefCount(const Type& other)
		{
			m_tombstone = 0;
			AssignFrom(other);
		}

		inline ~RefCount()
		{
			Reset();
		}

		inline void Reset()
		{
			if (m_tombstone)
			{
				intptr_t result = AtomicDecrementPtr(&m_tombstone->m_count);
				if (result == 0)
				{
					Tombstone::DeleteInstance(m_tombstone);
				}
			}
			m_tombstone = NULL;
		}

		// shared_ptr.reset�� ����
		inline void reset()
		{
			Reset(); 
		}
 
	private:
		inline void AssignFrom(const Type& other)
		{
			// �̹� �����Ÿ� ��ŵ
			if(other.m_tombstone == m_tombstone)
				return;
 
			// ����� RefCount ����
			if(other.m_tombstone)
			{
				AtomicIncrementPtr(&other.m_tombstone->m_count);
			}
 
			// ���� RefCount ����
			Tombstone* deletePendee = 0;
			if(m_tombstone)
			{
				intptr_t result = AtomicDecrementPtr(&m_tombstone->m_count);
				if(result == 0)
				{
					deletePendee = m_tombstone;
				}
			}
 
			// ����
			m_tombstone = other.m_tombstone;
 
			// �ı��ؾ� �ϴ� ��ü�� �ڴ��� �ı�
			if(deletePendee != NULL)
				Tombstone::DeleteInstance(deletePendee);
		}

	public:
		inline Type& operator=(const Type& other)
		{
			AssignFrom(other);
			return *this;
		}
 
		inline operator T* () const
		{
			return m_tombstone ? m_tombstone->m_ptr : 0;
		}
		inline T* operator->() const
		{
			return m_tombstone ? m_tombstone->m_ptr : 0;
		}
		inline T* get() const
		{
			return m_tombstone ? m_tombstone->m_ptr : 0;
		}
 
	};

	/**
	\~korean
	memory page�� ��°�� alloc/free�� �� �����ϴ�.

	\~english 

	\~chinese
	����?memory page?��alloc/free��?�����ġ�

	\~japanese
	memory page�������Ȫ�alloc/free�����������ĪǪ���
	\~
	*/
#if defined(_WIN32)
	template<typename T>
	class CVirtualAllocPage
	{
	public:
		T* m_p;
		size_t m_dwSizeOnFree;
		uint32_t m_dwTypeOnFree;

		CVirtualAllocPage()
		{
			m_p=NULL;
			m_dwSizeOnFree=0;
			m_dwTypeOnFree=0;
		}

		~CVirtualAllocPage()
		{
			if(m_p!=NULL)
				::VirtualFree(m_p,m_dwSizeOnFree,m_dwTypeOnFree);
		}

		/** 
		\~korean 
		memory page�� �Ҵ��ϵ� �ڵ� ������ ���� ���� �̸� �Է��صд�. 
		
		\~english 
		
		\~chinese
		����memory page����?�?���?���??��������?��

		\~japanese
		memory page���ܪ�?�ƪ몬�������������Ī�����������ê����������Ǫ��ު��� 
		\~
		*/
		void VirtualAlloc(void* lpAddress,size_t dwSize,uint32_t flAllocationType,uint32_t flProtect,size_t dwSizeOnFree,uint32_t dwFreeType)
		{
			void* ret = ::VirtualAlloc(lpAddress,dwSize,flAllocationType,flProtect);
			if(ret == NULL)
				ThrowBadAllocException();

			m_p=(T*)ret;
			m_dwSizeOnFree=dwSizeOnFree;
			m_dwTypeOnFree=dwFreeType;
		}

	public:
#pragma push_macro("new")
#undef new
		// �� Ŭ������ ProudNet DLL ��츦 ���� Ŀ���� �Ҵ��ڸ� ���� fast heap�� ���� �ʴ´�.
		DECLARE_NEW_AND_DELETE
#pragma pop_macro("new")
	};
#endif

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif

	/**  @} */
}

/**
\~korean
RefCount ��ü�� CFastMap�̳� CFastSet�� key�� ������ �� Ÿ���� Traits�ν� ����ϸ� ���ϴ�.

\~english
It is convenient to use this type as Traits in order to use RefCount object as key of CFastMap or CFastSet.

\~chinese
����RefCount?������ CHashMap%��� CFastSet%��key�����?������Traits?��۰����

\~japanese
RefCount ���֫������Ȫ�CFastMap�Ȫ�CFastSet�Ϋ�?���Ū�����˪ϡ����Ϋ����ת�Traits�Ȫ����Ū���?�Ǫ���
\~
*/
template<typename T>
class CPNElementTraits<Proud::RefCount<T> >
{
public:
	typedef Proud::RefCount<T> Type;
	typedef const Type& INARGTYPE;
	typedef Type& OUTARGTYPE;

	inline static uint32_t Hash(INARGTYPE a)
	{
		uintptr_t v = (uintptr_t)a.get();
		return CPNElementTraits<uintptr_t>::Hash(v);
	}

	/**
	\~korean
	�� Element�� ���Ѵ�.
	\param element1 ���� ù��° element
	\param element2 ���� �ι�° element
	\return ������ true ���� ������ false

	\~english '
	Compare two elements
	\param element1 First element to be compared
	\param element2 Second element to be compared
	\return True if the same, otherwise false. 


	\~chinese
	��???Element��
	\param element1 ���?�����?element��
	\param element2 ���?����?element��
	\return ������?true��������?false��

	\~japanese
	?Element�����򪷪ު���
	\param element1 ���򪹪�1���ͪ�element
	\param element2 ���򪹪�2���ͪ�element
	\return �Ҫ��Ǫ����true���Ҫ��ǪϪʪ����false
	\~
	*/
	inline static bool CompareElements(INARGTYPE element1, INARGTYPE element2)
	{
		return element1.get() == element2.get();
	}

	/**
	\~korean
	�� Element�� ���Ѵ�.
	\param element1 ���� ù��° element
	\param element2 ���� �ι�° element
	\return element1�� �� ũ�� 1, ������ -1, ������ 0

	\~english 
	Compare two elements
	\param element1 First element to be compared
	\param element2 Second element to be compared
	\return 1 if element 1 is bigger, -1 if smaller, 0 if equal. 


	\~chinese
	��???Element��
	\param element1 ���?�����?element��
	\param element2 ���?����?element��
	\return element1������?1�����?-1��������?0��

	\~japanese
	?Element�����򪷪ު���
	\param element1 ���򪹪�1���ͪ�element
	\param element2 ���򪹪�1���ͪ�element
	\return element1����ê��ު������1��ᳪ������-1���Ҫ��Ǫ����0
	\~
	*/
	inline static int CompareElementsOrdered(INARGTYPE element1, INARGTYPE element2)
	{
		if (element1.get() < element2.get())
			return -1;
		if (element1.get() == element2.get())
			return 0;
		return 1;
	}

};


#ifdef _MSC_VER
#pragma pack(pop)
#endif

#ifdef _MSC_VER
#pragma warning(pop)
#endif 
