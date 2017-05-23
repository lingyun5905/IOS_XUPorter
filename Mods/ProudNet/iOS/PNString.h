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

#include <new>
#include <exception>

#include "BasicTypes.h"

#include <exception>
#include <stdio.h>
#include <stdarg.h>
#include "ProcHeap.h"
//#include "CriticalSect.h"
#include "atomic.h"
#include "StringEncoder.h"


#ifdef _MSC_VER // pragma warning�� VC++����
#pragma warning(push)
#pragma warning(disable:4324)
#endif // __MARMALADE__

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

#if (_MSC_VER>=1400)
#pragma managed(push,off)
#endif

namespace Proud
{
	PROUD_API _Noreturn void ThrowInvalidArgumentException();

	/** \addtogroup util_group
	*  @{
	*/

	class AnsiStrTraits
	{
	public:
		typedef char CharType;

		static int SafeStringLen(const CharType* str);

		static void CopyString(CharType* dest, const CharType* src,int length);

		static int StringCompare(const CharType* a,const CharType*b);
		static int StringCompareNoCase(const CharType* a,const CharType*b);
		static int GetFormattedLength(const char* pszFormat, va_list args);
		static int __cdecl Format( char* pszBuffer, size_t nlength, const char* pszFormat, va_list args ) throw();

// �ذ� ����� ã���� ���� ���Ƴ���.
#if defined(_WIN32) 
		static char* StringUppercase(char* psz, size_t size ) throw();
		static char* StringLowercase(char* psz, size_t size ) throw();
#endif
		static const char* __cdecl StringFindString( const char* pszBlock, const char* pszMatch ) throw();
		static char* __cdecl StringFindString( char* pszBlock, const char* pszMatch ) throw();
		static const char* __cdecl StringFindChar( const char* pszBlock, char chMatch ) throw();
		static int __cdecl StringSpanIncluding( const char* pszBlock, const char* pszSet ) throw();
		static int __cdecl StringSpanExcluding( const char* pszBlock, const char* pszSet ) throw();
		static char* __cdecl CharNext( const char* p ) throw();
		static int __cdecl IsDigit( char ch ) throw();
		static int __cdecl IsSpace( char ch ) throw();

		static char* NullString;
	};

	class UnicodeStrTraits
	{
	public:
		typedef wchar_t CharType;

		static int SafeStringLen(const CharType* str);
		static void CopyString(CharType* dest, const CharType* src,int length);
		static int StringCompare(const CharType* a,const CharType*b);
		static int StringCompareNoCase(const CharType* a,const CharType*b);
		static int GetFormattedLength(const wchar_t* pszFormat, va_list args);
		static int __cdecl Format(wchar_t* pszBuffer, size_t nLength, const wchar_t* pszFormat, va_list args) throw( );

// �ذ� ����� ã���� ���� ���Ƴ���.
#if defined(_WIN32) 
		static wchar_t* StringUppercase(wchar_t* psz, size_t size) throw( );
		static wchar_t* StringLowercase(wchar_t* psz, size_t size) throw( );
#endif
		static const wchar_t* __cdecl StringFindString(const wchar_t* pszBlock, const wchar_t* pszMatch) throw( );
		static wchar_t* __cdecl StringFindString(wchar_t* pszBlock, const wchar_t* pszMatch) throw( );
		static const wchar_t* __cdecl StringFindChar(const wchar_t* pszBlock, wchar_t chMatch) throw( );
		static int __cdecl StringSpanIncluding(const wchar_t* pszBlock, const wchar_t* pszSet) throw( );
		static int __cdecl StringSpanExcluding(const wchar_t* pszBlock, const wchar_t* pszSet) throw( );
		static wchar_t* __cdecl CharNext(const wchar_t* psz) throw( );
		static int __cdecl IsDigit( wchar_t ch ) throw();
		static int __cdecl IsSpace( wchar_t ch ) throw();

		static wchar_t* NullString;
	};

	/** 
	\~korean
	���ڿ� Ŭ����
	- �� Ŭ������ ���� ������� ���� Proud.String, Proud.StringW, Proud.StringA �� ���� ���� ���� �����մϴ�.
	- �ڼ��� ���� <a target="_blank" href="http://guide.nettention.com/cpp_ko#string" >���ڿ� Ŭ����</a>�� ����ٶ��ϴ�.

	\~english
	Text string class
	- It is recommended not to use this class directly but to use via Proud.String, Proud.StringW and Proud.StringA.
	- Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#string" >String Class</a>.

	\~chinese
	�ݬ��?
	- ������������?����?��? Proud.String, Proud.StringW,  Proud.StringA%���ġ�
	- ????��<a target="_blank" href="http://guide.nettention.com/cpp_zh#string" >���֪��?</a>%��

	\~japanese
	���֪���髹
	- ���Ϋ��髹�������Ū諸��Proud.String, Proud.StringW, Proud.StringA���ת��Ū����Ȫ�?�᪷�ު���
	- �٪����ϡ�\ref string��?�Ϊ���������
	\~
	*/
	template<typename XCHAR, typename StringTraits>
	class StringT 
	{
		// copy-on-write �� shared ptr ���¸� ��� �����Ѵ�.
		// ���ڿ� ���� �ٷ� �մܿ� ��ġ�Ѵ�. 
		// NOTE: Tombstone�� ���� ���ڿ� ��ü�� �ϴ� �ѹ� �����ǰ� ���� �Ҹ��� ������ ���빰�� ���� �ٲ��� ���ƾ� �Ѵ�.
		// �ֳ��ϸ� ���� �������� �� ���ڿ� �����͸� ��� ���� �����ϱ� �����̴�.
		// �� �������� �ڱⰡ ���� ���ڿ� �����͸� �����ϰ��� �ϴ� ��� 
		// �����ϴ� ���ڿ� �����͸� ���� �� �� tombstone�� �� ������ ������ �־�� �Ѵ�.
		class Tombstone
		{
		public:
			// ĳ�̵� ���ڿ� ����
			int m_length;

			// ���� Ƚ��
			PROUDNET_VOLATILE_ALIGN intptr_t m_refCount;

			inline Tombstone()
			{
				m_length = 0;
				m_refCount = 1;
			}

			inline XCHAR* GetBuffer() 
			{
				return (XCHAR*)(this+1);
			}
		};

		// ���ڿ� Ŭ������ �� ������ ������� �����ϰ� ������ �ϸ� vtable�� ���� �� ����.
		// �׷��� printf �迭���� ��ü ��ü�� ���� �־ �� �۵��ϴϱ�.
		// �� �����Ͱ� ����Ű�� �� �ٷ� �տ� Tombstone�� �ִ�.
		XCHAR* m_strPtr; 

		// ����ڰ� �� ��ü�� zeromem�ؼ� ���� ���� ������ �ϰ� �ϱ� ����(F���)
		void AdjustNullPtr()
		{
			if(m_strPtr == 0)
			{
				m_strPtr = StringTraits::NullString;
			}
		}

		void ShareFrom(const StringT& src)
		{
			AdjustNullPtr();
			if(src.m_strPtr != m_strPtr)
			{
				ReleaseTombstone();
				
				m_strPtr = src.m_strPtr;
				
				if(GetTombstone())
                {
					AtomicIncrementPtr(&GetTombstone()->m_refCount);
                }
			}
		}

		void ReleaseTombstone()
		{
			AdjustNullPtr();
			
			Tombstone* ts = GetTombstone();
			if(ts)
			{
				intptr_t result = AtomicDecrementPtr(&ts->m_refCount);
				if(result == 0)
				{
					CProcHeap::Free(ts);
				}
			}			
			m_strPtr = StringTraits::NullString;
		}

		inline Tombstone* GetTombstone() const
		{
			if(m_strPtr == StringTraits::NullString || !m_strPtr)
				return NULL;

			uint8_t* ptr = (uint8_t*)m_strPtr;
			return (Tombstone*) (ptr-sizeof(Tombstone));
		}

		// strlen: sz�����ϰ�. char�� ��� ����Ʈ,wchar_t�� ��� ���ڼ�.
		static size_t GetBlockLen( int strLen )
		{
			if(strLen<0)
				ThrowInvalidArgumentException();
			return sizeof(Tombstone) + sizeof(XCHAR) * ((size_t)strLen+1);
		}

		void PrepareCopyOnWrite()
		{
			AdjustNullPtr();

			if (GetTombstone() == NULL)
			{
				// ������ ���� �����.
				size_t blockLen = GetBlockLen(0);
				Tombstone* ts = (Tombstone*)CProcHeap::Alloc(blockLen);
				if(ts == NULL)
					ThrowBadAllocException();

                memset(ts,0,blockLen);
				CallConstructor<Tombstone>(ts);
				m_strPtr = ts->GetBuffer();
			}
			else if(GetTombstone()->m_refCount > 1) // ���� �����̸� �纻 �ߴ� ���� ���ǹ��ϴ�.
			{
				// �纻
				Tombstone* newTS = (Tombstone*) CProcHeap::Alloc( GetBlockLen(GetLength()));
				if( newTS == NULL )
					ThrowBadAllocException();

				CallConstructor<Tombstone>(newTS);
				newTS->m_length = GetLength();				

				StringTraits::CopyString(newTS->GetBuffer(), GetString(), GetLength()); // sz�� �������.
				
				// ���� ��ü
				ReleaseTombstone();

				m_strPtr = newTS->GetBuffer();
			}
		}

		inline void InitVars()
		{
			m_strPtr = StringTraits::NullString;
		}

		inline void ReleaseBufferSetLength(int length)
		{
			length = PNMAX(length, 0);
			length = PNMIN(length, GetLength());

			Tombstone* ts = GetTombstone();
			if (ts != NULL)
			{
				ts->m_length = length;
				ts->GetBuffer()[length] = 0; // sz mark				
			}
		}

		void Truncate( int nNewLength )
		{
			assert( nNewLength <= GetLength() );
			GetBuffer( nNewLength );
			ReleaseBufferSetLength( nNewLength );
		}

		// length: byte(char) or ���ڼ�(wchar_t)
		void SetMaxLength(int length)
		{
			AdjustNullPtr();

			length = PNMAX(length, 0);
			if(length == 0)
			{
				ReleaseTombstone();
			}
			else if(length != GetLength())
			{
				// �ٸ� ������ ���� ���ϰ� ������ �׳� realloc�Ѵ�.
				Tombstone* ts = GetTombstone();
				if (ts != NULL && ts->m_refCount == 1)
				{
					ts = (Tombstone*)CProcHeap::Realloc(ts, GetBlockLen(length));
					ts->m_length = length;
					m_strPtr = ts->GetBuffer(); // realloc�� ���� ts�� �ٲ� ��츦 ����
					m_strPtr[length] = 0;	// ũ�Ⱑ �پ�� ��츦 ���� sz����ó��
				}
				else
				{
					// �ٸ� ������ �����ϰ� ������ ������ �ǵ帮�� �ȵȴ�. 
					// ���� ũ�� �ٸ� �纻 �� copy on write�� ���� �غ� �Ѵ�.
					Tombstone* newTS = (Tombstone*)CProcHeap::Alloc(GetBlockLen(length));
					if( newTS == NULL)
						ThrowBadAllocException();

					CallConstructor<Tombstone>(newTS);
					newTS->m_length = length;

					StringTraits::CopyString(newTS->GetBuffer(), GetString(), PNMIN(length,GetLength()));

					// ���� ��ü
					ReleaseTombstone();

					m_strPtr = newTS->GetBuffer();
				}
			}
		}

	public:
		/**
		\~korean
		������

		\~english
		Constructor

		\~chinese
		�����

		\~japanese
		�����
		\~
		*/
		StringT()
		{
			InitVars();
		}

		/**
		\~korean
		�ı���

		\~english
		Destructor

		\~chinese
		��?�

		\~japanese
		��?�
		\~
		*/
		~StringT()
		{
			ReleaseTombstone();
		}

		/**
		\~korean
		src�� ����Ű�� ���ڿ��� �����´�.

		\~english
		Gets string that pointed by src

		\~chinese
		��?src�����ݬ����

		\~japanese
		src��򦪹���֪������?�ߪު���
		\~
		*/
		inline StringT(const StringT& src)
		{
			InitVars();
			ShareFrom(src);
		}

		/**
		\~korean
		���ڿ��� �����´�. 

		\~english
		Gets a string

		\~chinese
		��?�ݬ����

		\~japanese
		���֪������?�ߪު���
		\~
		*/
		StringT(const XCHAR* src, int length = 0)
		{
			InitVars();
			int len = StringTraits::SafeStringLen(src);
			
			if(length > 0)
				len = PNMIN(len, length);
			
			XCHAR* buf = GetBuffer(len);
			StringTraits::CopyString(buf,src,len);
			ReleaseBuffer();
		}

		/**
		\~korean
		�� ���ڿ��ΰ�? 

		\~english
		Is it an empty string ?

		\~chinese
		�����ݬ��??

		\~japanese
		�����֪�Ǫ�����
		\~
		*/
		inline bool IsEmpty() const
		{
			return GetLength() == 0;
		}

		/** 
		\~korean
		���ڿ� �����͸� �Ʒ� ����ó�� �ٷ� ���� �� �ְ� ���ش�. 
        \code
            Proud::String a = L"abc";
            const wchar_t *b = a; // ��ü a�� �ִ� ���ڿ� �����͸� b�� �޴´�.
        \endcode

		\~english
		Let's read text string data directly as shown below 
        \code
            Proud::String a = L"abc";
            const wchar_t *b = a; // Text sting pointer in object a is received by b.
        \endcode

		\~chinese
		?�ݬ��?����������ʦ�����?��
\code
            Proud::String a = L"abc";
            const wchar_t *b = a; // �?b����?��a�����ݬ����
        \endcode

		\~japanese
		���֪��?�����������ƪΪ誦�˪���?���誦�˪��ު���

\code
		Proud::String a = L"abc";
		const wchar_t *b = a; // ���֫�������a�˪������֪�ݫ���?��b����������ު���
\endcode


		\~
		*/
		inline operator const XCHAR* () const
		{			
			return GetString();
		}


		/** 
		\~korean
		���ڿ� �����͸� ���� �� �ְ� �Ѵ�. 

		\~english
		Let's read text string data

		\~chinese
		ʦ�����?���ݬ��?�ߡ�

		\~japanese
		���֪��?����?���誦�˪��ު���
		\~
		*/
		inline const XCHAR* GetString() const 
		{
			if(m_strPtr == 0)
				return StringTraits::NullString;

			return m_strPtr;
		}

		/** 
		\~korean
		���ڿ� �����͸� �б� �� ���⸦ ���� �����͸� ������ �� ���� �޼����Դϴ�.
		- �� �޼��带 ���� ������ ReleaseBuffer�� ��������� �մϴ�. �̸� ���ϰ� �Ϸ���
		StrBufA�� StrBufW�� ���� �˴ϴ�.

		\~english
		Method used to access string pointer to read from and write to string data.
		- After using this method, it must be ended by calling ReleaseBuffer(). To use this easily, use Proud::StrBufA or Proud::StrBufW.

		\~chinese
		?��?����??���֪?��?������??�������۰����
		- ���۰���������ReleaseBuffer?�֡���?������������?����StrBufA���StrBufW?ʦ��

		\~japanese
		���֪��?����?������?����?�ߪΪ���˫ݫ���?���ΪŪ������Ū��᫽�ëɪǪ���
		- ���Ϋ᫽�ëɪ��Ūêƪ����ReleaseBuffer����߾���ƪ��������������?�˪���������ϡ�StrBufA�Ȫ�StrBufW���Ū����ު��Ǫ���
		\~ 
		\~korean ��� ����
		\~english Usage example
		\~chinese �������
		\~japanese
		��������
		\~

		\code
        Proud::String a = L"abc";
        wchar_t* pa = a.GetBuffer(100);
        _wsprintf(pa, L"%d", 123);
        a.ReleaseBuffer();
        \endcode

		\~
		
		\~korean �� ���� ��� ����
		\~english Better usage example
		\~chinese ��������������
		\~japanese ��ê��ު���������
		\~ \code
		Proud::String a = L"abc";
		Proud::StrBuf pa(a, 100);
		_wsprintf(pa, L"%d", 123);
		\endcode

		\~
		\~korean �б� ���� ��� ����
		\~english Example for read-only access
		\~chinese ��?����������
		\~japanese ?������?����������
		\~
		\code
		Proud::String a = L"abc";
		wchar_t* pa = a;
		\endcode
		*/
		XCHAR* GetBuffer(int length = 0)
		{
			// length�� �ּ� 1���ڴ� ������ �� �ִ� ��� ������ ũ�⸦ �����.
			// �׷��� ����ڰ� ��ȿ�� ���ڿ� �ּҸ� �����Ƿ�.
			length = PNMAX(length, GetLength());
			length = PNMAX(length, 1);

			if(GetLength() != length)
			{
				// copy-on-write with resize
				// ���� ũ�⺸�� ���� ũ�⸦ �������� �Ѵ� �ϴ���, �ٸ� �������� �ٸ� ������ �� tombstone�� �����ϰ� ���� ��쿡 ���ʵ� �ٲ�� �ȵǹǷ�
				// �̷��� copy-on-write ó���� ���־�� ��.
				SetMaxLength(length);
			}
			else
			{
				// copy-on-write without resize
				PrepareCopyOnWrite();
			}

			return (XCHAR*)GetString();
		}

		/**
		\~korean
		���ڿ� ���̸� ����ϴ�. 

		\~english
		Gets length of string.

		\~chinese
		?���ݬ��?����

		\~japanese
		���֪����������ު���
		\~

		\return length Number of characters if wchar_t is used, number of bytes if char is used, regardless of multibyte or unicode encoding.
		*/
		int GetLength() const
		{
			if(m_strPtr == NULL)
				return 0;

			if(m_strPtr == StringTraits::NullString)
				return 0;

			else 
				return GetTombstone()->m_length;
		}

		/** 
		\~korean
		���ڿ� ���̸� �������Ѵ�. 
		\param length Number of characters if wchar_t is used, number of bytes if char is used, regardless of multibyte or unicode encoding.

		\~english
		Re-modifies the length of text string
		\param length Number of characters if wchar_t is used, number of bytes if char is used, regardless of multibyte or unicode encoding.

		\~chinese
		����?���ݬ��?����
		\param length Number of characters if wchar_t is used, number of bytes if char is used, regardless of multibyte or unicode encoding.

		\~japanese
		���֪������������ڪ��ު���
		\param length Number of characters if wchar_t is used, number of bytes if char is used, regardless of multibyte or unicode encoding.
		\~

		*/
		void SetLength(int length)
		{
			length = PNMIN(length, StringTraits::SafeStringLen(GetString()) );
			SetMaxLength(length);
		}

		/** 
		\~korean
		���ڿ� �ڿ� �ٸ� ���ڿ��� �����δ�. 

		\~english
		Adds another text string after text string

		\~chinese
		���ݬ��������ʥ�����ݬ����

		\~japanese
		���֪������������֪������ʥ���ު���
		\~
		*/
		inline void Append(const StringT& src)
		{
			if(src.GetLength() > 0)
			{
				int oldLen = GetLength();
				XCHAR* buf = GetBuffer(oldLen + src.GetLength());
				StringTraits::CopyString(buf + oldLen, src.GetString(), src.GetLength() );
				ReleaseBufferSetLength(oldLen + src.GetLength());
			}
		}

		/** 
		\~korean
		���ڿ� �ڿ� �ٸ� ���ڿ��� �����δ�. 

		\~english
		Adds another text string to text string

		\~chinese
		���ݬ��������ʥ�����ݬ����

		\~japanese
		���֪������������֪������ʥ���ު���
		\~
		*/
		inline void Append(const XCHAR* src)
		{
			if (src != NULL)
			{
				int srcLen = StringTraits::SafeStringLen(src);
				
				int oldLen = GetLength();
				XCHAR* buf = GetBuffer(oldLen + srcLen);
				StringTraits::CopyString(buf + oldLen, src, srcLen );
				ReleaseBufferSetLength(oldLen + srcLen);
			}
		}

		/** 
		\~korean
		�� ��ü�� ���ڿ��� src�� ����Ű�� ���ڿ��� ���Ѵ�. �� ��ü�� ���ڿ��� �� '������ ��'�̸� ������, ������ 0, �׷��� ������ ����� ���ϵȴ�. 

		\~english
		Compare this objective��s string to string that src indicates. If this objective��s string is smaller than src, negative number will be returned (if same, 0 will be returned & if it is bigger than src, positive number will be returned).

		\~chinese
		��?�?�����ݬ����src�����ݬ���������?�����ݬ����src�����??����������0����?������?��

		\~japanese
		���Ϋ��֫������Ȫ����֪��src���ƪ����֪�����򪷪ު������Ϋ��֫������Ȫ����֪��src���ᳪ��������?���Ҫ�����У��������Ǫʪ������?���꫿?�󪵪�ު���

		\~
		*/
		inline int Compare(const StringT& src) const
		{
			XCHAR* strPtr = m_strPtr;
			if (strPtr == NULL)
				strPtr = StringTraits::NullString;;

			if(strPtr == src.m_strPtr)
				return 0;

			return StringTraits::StringCompare(GetString(), src.GetString());
		}

		/** 
		\~korean
		�� ��ü�� ���ڿ��� src�� ����Ű�� ���ڿ��� ���Ѵ�. �� ��ü�� ���ڿ��� �� '������ ��'�̸� ������, ������ 0, �׷��� ������ ����� ���ϵȴ�. 

		\~english
		Compare this objective��s string to string that src indicates. If this objective��s string is smaller than src, negative number will be returned (if same, 0 will be returned & if it is bigger than src, positive number will be returned).

		\~chinese
		��?�?�����ݬ����src�����ݬ���������?�����ݬ����src�����??����������0����?������?��

		\~japanese
		���Ϋ��֫������Ȫ����֪��src���ƪ����֪�����򪷪ު������Ϋ��֫������Ȫ����֪��src���ᳪ��������?���Ҫ�����У��������Ǫʪ������?���꫿?�󪵪�ު���

		\~
		*/
		inline int Compare(const XCHAR* src) const
		{
			return StringTraits::StringCompare(GetString(), src);
		}

		/** 
		\~korean
		�� ��ü�� ���ڿ��� src�� ����Ű�� ���ڿ��� ���Ѵ�. �� ��ü�� ���ڿ��� �� '������ ��'�̸� ������, ������ 0, �׷��� ������ ����� ���ϵȴ�. 
		��, ��ҹ��� ������ ���� �ʴ´�. 

		\~english
		Compare this objective��s string to string that src indicates. If this objective��s string is smaller than src, negative number will be returned (if same, 0 will be returned & if it is bigger than src, positive number will be returned). 
		But, not classify capital and small letter.

		\~chinese
		��?�?�����ݬ����src�����ݬ���������?�����ݬ����src�����??����������0����?������?��
		ӣ����?������ٽ��

		\~japanese
		���Ϋ��֫������Ȫ����֪��src���ƪ����֪�����򪷪ު������Ϋ��֫������Ȫ����֪��src���ᳪ��������?���Ҫ�����У��������Ǫʪ������?���꫿?�󪵪�ު���
		���������������?ܬ�򪷪ު���
		\~
		*/
		inline int CompareNoCase(const StringT& src) const
		{
			const XCHAR* p1 = src.m_strPtr;
			const XCHAR* p2 = m_strPtr;
			if(!p1) p1 = StringTraits::NullString;
			if(!p2) p2 = StringTraits::NullString;
			if(p1==p2)
				return 0;

			return StringTraits::StringCompareNoCase(GetString(), src.GetString());
		}

		/** 
		\~korean
		�� ��ü�� ���ڿ��� src�� ����Ű�� ���ڿ��� ���Ѵ�. �� ��ü�� ���ڿ��� �� '������ ��'�̸� ������, ������ 0, �׷��� ������ ����� ���ϵȴ�. 
		��, ��ҹ��� ������ ���� �ʴ´�. 

		\~english
		Compare this objective��s string to string that src indicates. If this objective��s string is smaller than src, negative number will be returned (if same, 0 will be returned & if it is bigger than src, positive number will be returned). 
		But, not classify capital and small letter.

		\~chinese
		��?�?�����ݬ����src�����ݬ���������?�����ݬ����src�����??����������0����?������?��
		ӣ����?������ٽ��

		\~japanese
		���Ϋ��֫������Ȫ����֪��src���ƪ����֪�����򪷪ު������Ϋ��֫������Ȫ����֪��src���ᳪ��������?���Ҫ�����У��������Ǫʪ������?���꫿?�󪵪�ު���
		���������������?ܬ�򪷪ު���
		\~
		*/
		inline int CompareNoCase(const XCHAR* src) const
		{
			return StringTraits::StringCompareNoCase(GetString(),src);
		}

		/**
		\~korean
		Format �޼ҵ�� �Ȱ��� ����� ������, static �޼ҵ��̸� ���ο� ��ü�� �����Ѵ�.

		\~english
		It performs the same function as the Format method, but it is a static method and returns a new object. 

		\~chinese
		?Format ۰�����������ң�ӣ?��??۰��������?�ڡ�

		\~japanese
		Format�᫽�ëɪ��Ҫ�Ѧ���򪷪ު�����static�᫽�ëɪ��檷�����֫������Ȫ�꫿?�󪷪ު���
		\~
		*/
		static inline StringT NewFormat(const XCHAR* pszFormat, ...)
		{
			assert(pszFormat != NULL);

			StringT ret;

			va_list argList;
			va_start(argList, pszFormat);
			ret.FormatV(pszFormat, argList);
			va_end(argList);

			return ret;
		}

		/** 
		\~korean
		printf ó�� ���ڿ��� �����. ( <a target="_blank" href="http://guide.nettention.com/cpp_ko#string_format" >���ڿ� ����� ���(format)</a>  ����) 

		\~english
		Creates text string as printf (Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#string_format" >Creating a string(format)</a>)

		\~chinese
		��printf��??���ݬ������?�� <a target="_blank" href="http://guide.nettention.com/cpp_zh  #string_format" >?�����֪��������(format)</a>��

		\~japanese
		printf �Ϊ誦�����֪���ª�ު��� ( \ref string_format ?��) 
		\~
		*/
		inline void Format( const XCHAR* pszFormat, ... )
		{
			assert( pszFormat != NULL );

			va_list argList;
			va_start( argList, pszFormat );
			FormatV( pszFormat, argList );
			va_end( argList );
		}

		/** 
		\~korean
		printf ó�� ���ڿ��� �����. (  <a target="_blank" href="http://guide.nettention.com/cpp_ko#string_format" >���ڿ� ����� ���(format)</a> ����) 

		\~english
		Creates text string as printf (Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#string_format" >Creating a string(format)</a>)

		\~chinese
		��printf��??���ݬ������?�� <a target="_blank" href="http://guide.nettention.com/cpp_zh  #string_format" >?�����֪��������(format)</a>��

		\~japanese
		printf �Ϊ誦�����֪���ª�ު��� ( \ref string_format ?��) 
		\~
		*/
		void FormatV( const XCHAR* pszFormat, va_list args )
		{
			assert( pszFormat != NULL );

			if(pszFormat == NULL)
            {
				ThrowInvalidArgumentException();
            }

			int nLength = StringTraits::GetFormattedLength(pszFormat, args) + 1;
			
			XCHAR* buf = GetBuffer(nLength);
			StringTraits::Format(buf, nLength, pszFormat, args);
			buf[nLength] = 0;

			ReleaseBuffer();
		}

		/** 
		\~korean
		GetBuffer�� ȣ�������� �̰ɷ� �������� ����� �Ѵ�. �ȱ׷��� ���ڿ� ���̸� ��Ȯ�ϰ� ������ ���� �� �ִ�.
		�ڼ��� ���� GetBuffer ���� ����. 

		\~english
		Once GetBuffer is called then this must end to finalize. Otherwise, the exact length of text string may not be acquired.
		Please refer GetBuffer description

		\~chinese
		��УGetBuffer��?���?�֡���?��ʦ��������??���ݬ��?����
		????��GetBuffer?٥��

		\~japanese
		GetBuffer�������󪷪��顢�������߾������驪�����ު����������ʪ���С����֪���������������Ī��Ȫ��Ǫ��ʪ�������ު���
		�٪����ϡ�GetBuffer?٥��?�Ϊ���������
		\~
		*/
		inline void ReleaseBuffer()
		{
			ReleaseBufferSetLength(StringTraits::SafeStringLen(GetString()));
		}

		/** 
		\~korean
		���ڿ� �� chOld�� ����Ű�� ���ڸ� chNew �� �ٲ۴�. 

		\~english
		Among text strings, replace the character pointed by chOld with the character pointed by chNew.

		\~chinese
		?�ݬ����chOld�������?��chNew��

		\~japanese
		���֪�Ϊ���chOld��򦪹����chNew��?���ު���
		\~
		*/
		int Replace( XCHAR chOld, XCHAR chNew )
		{
			int nCount = 0;

			// short-circuit the nop case
			if( chOld != chNew )
			{
				// otherwise modify each character that matches in the string
				bool bCopied = false;
				XCHAR* pszBuffer = const_cast< XCHAR* >( GetString() );  // We don't actually write to pszBuffer until we've called GetBuffer().

				int nLength = GetLength();
				int iChar = 0;
				while( iChar < nLength )
				{
					// replace instances of the specified character only
					if( pszBuffer[iChar] == chOld )
					{
						if( !bCopied )
						{
							bCopied = true;
							pszBuffer = GetBuffer( nLength );
						}
						pszBuffer[iChar] = chNew;
						nCount++;
					}
					iChar = int( StringTraits::CharNext( pszBuffer+iChar )-pszBuffer );
				}
				if( bCopied )
				{
					ReleaseBufferSetLength( nLength );
				}
			}

			return( nCount );
		}

		/** 
		\~korean
		���ڿ� �� pszOld�� ����Ű�� ���ڿ��� pszNew �� �ٲ۴�. 

		\~english
		Among text strings, replace the character pointed by pszOld with the character pointed by pszNew.

		\~chinese
		?�ݬ����pszOld�������?��pszNew��

		\~japanese
		���֪�Ϊ���pszOld��򦪹���֪��pszNew��?���ު���
		\~
		*/
		int Replace( const XCHAR* pszOld, const XCHAR* pszNew )
		{
			// can't have empty or NULL lpszOld

			// nSourceLen is in XCHARs
			int nSourceLen = StringTraits::SafeStringLen( pszOld );
			if( nSourceLen == 0 )
				return( 0 );
			// nReplacementLen is in XCHARs
			int nReplacementLen = StringTraits::SafeStringLen( pszNew );

			// loop once to figure out the size of the result string
			int nCount = 0;
			{
				const XCHAR* pszStart = GetString();
				const XCHAR* pszEnd = pszStart+GetLength();
				while( pszStart < pszEnd )
				{
					const XCHAR* pszTarget;
					while( (pszTarget = StringTraits::StringFindString( pszStart, pszOld ) ) != NULL)
					{
						nCount++;
						pszStart = pszTarget+nSourceLen;
					}
					pszStart += StringTraits::SafeStringLen( pszStart )+1;
				}
			}

			// if any changes were made, make them
			if( nCount > 0 )
			{
				// if the buffer is too small, just
				//   allocate a new buffer (slow but sure)
				int nOldLength = GetLength();
				int nNewLength = nOldLength+(nReplacementLen-nSourceLen)*nCount;

				XCHAR* pszBuffer = GetBuffer( PNMAX( nNewLength, nOldLength ) );

				XCHAR* pszStart = pszBuffer;
				XCHAR* pszEnd = pszStart+nOldLength;

				// loop again to actually do the work
				while( pszStart < pszEnd )
				{
					XCHAR* pszTarget;
					while( (pszTarget = StringTraits::StringFindString( pszStart, pszOld ) ) != NULL )
					{
						int nBalance = nOldLength-int(pszTarget-pszBuffer+nSourceLen);
#if (_MSC_VER>=1400)
						memmove_s( pszTarget+nReplacementLen, nBalance*sizeof( XCHAR ), 
							pszTarget+nSourceLen, nBalance*sizeof( XCHAR ) );
						memcpy_s( pszTarget, nReplacementLen*sizeof( XCHAR ), 
							pszNew, nReplacementLen*sizeof( XCHAR ) );
#else
						memmove( pszTarget+nReplacementLen,
							pszTarget+nSourceLen, nBalance*sizeof( XCHAR ) );
						memcpy( pszTarget, 
							pszNew, nReplacementLen*sizeof( XCHAR ) );
#endif
						pszStart = pszTarget+nReplacementLen;
						pszTarget[nReplacementLen+nBalance] = 0;
						nOldLength += (nReplacementLen-nSourceLen);
					}
					pszStart += StringTraits::SafeStringLen( pszStart )+1;
				}
				assert( pszBuffer[nNewLength] == 0 );
				ReleaseBufferSetLength( nNewLength );
			}

			return( nCount );
		}

		/** 
		\~korean
		���ڿ��� �빮��ȭ�Ѵ�. 

		\~english
		Capitalizes text string

		\~chinese
		?�ݬ����?�ٽ����

		\~japanese
		���֪������������ު���
		\~
		*/
		inline StringT& MakeUpper()
		{
			int nLength = GetLength();
			XCHAR* pszBuffer = GetBuffer( nLength );
			StringTraits::StringUppercase( pszBuffer, nLength+1 );
			ReleaseBufferSetLength( nLength );

			return( *this );
		}

		/** 
		\~korean
		���ڿ��� �ҹ���ȭ�Ѵ�. 

		\~english
		De-capitalize text string

		\~chinese
		?�ݬ���?�ٽ����

		\~japanese
		���֪������������ު���
		\~
		*/
		inline StringT& MakeLower()
		{
			int nLength = GetLength();
			XCHAR* pszBuffer = GetBuffer( nLength );
			StringTraits::StringLowercase( pszBuffer, nLength+1 );
			ReleaseBufferSetLength( nLength );

			return( *this );
		}

		/** 
		\~korean
		�� ������ 

		\~english
		Comparison operator

		\~chinese
		��??ߩݬ��

		\~japanese
		������ߩ�
		\~
		*/
		inline bool operator==(const StringT &src) const
		{
			return Compare(src) == 0;
		}

		inline bool operator<(const StringT& src) const
		{
			return Compare(src) < 0;
		}

		/** 
		\~korean
		�� ������ 

		\~english
		Comparison operator

		\~chinese
		��??ߩݬ��

		\~japanese
		������ߩ�
		\~
		*/
		inline bool operator!=(const StringT& src) const
		{
			return Compare(src) != 0;
		}

		/** 
		\~korean
		�� ������ 

		\~english
		Comparison operator

		\~chinese
		��??ߩݬ��

		\~japanese
		������ߩ�
		\~
		*/
		inline bool operator==(const XCHAR* src) const
		{
			return Compare(src) == 0;
		}

		/** 
		\~korean
		�� ������ 

		\~english
		Comparison operator

		\~chinese
		��??ߩݬ��

		\~japanese
		������ߩ�
		\~
		*/
		inline bool operator!=(const XCHAR* src) const
		{
			return Compare(src) != 0;
		}

		/** 
		\~korean
		���ڿ� �����̱� ������ 

		\~english
		Text string adding operator

		\~chinese
		�ݬ��ʥ��?ߩݬ��

		\~japanese
		���֪����ʥ����ߩ�
		\~
		*/
		inline StringT& operator+=(const StringT& src)
		{
			Append(src);
			return *this;
		}

		/** 
		\~korean
		���ڿ� �����̱� ������ 

		\~english
		Text string adding operator

		\~chinese
		�ݬ����ʥ?ߩݬ��

		\~japanese
		���֪����ʥ����ߩ�
		\~
		*/
		inline StringT& operator+=(const XCHAR* src)
		{
			Append(src);
			return *this;
		}

		/** 
		\~korean
		���ڿ� ���� ���� ������ 

		\~english
		String copy assignment operator

		\~chinese
		�ݬ��?�?ߩݬ��

		\~japanese
		���֪����?������ߩ�
		\~
		*/
		inline StringT& operator=(const StringT& src)
		{
			ShareFrom(src);
			return *this;
		}

		/** 
		\~korean
		���ڿ� ���� ���� ������ 

		\~english
		String copy assignment operator

		\~chinese
		�ݬ��?�?ߩݬ��

		\~japanese
		���֪����?������ߩ�
		\~
		*/
		inline StringT& operator=(const XCHAR* src)
		{
			StringT r(src);
			ShareFrom(r);
			return *this;
		}

		/** 
		\~korean
		���ڿ��� iStart ��° ĳ���ͺ��� �˻��ؼ� ch �� ����Ű�� ������ ��ġ�� ã�´�. ��ã���� -1�� �����Ѵ�. 

		\~english
		Finds the location of the character that is pointed by ch through searching from 'iStart'th character of text string. Returns -1 when not found.

		\~chinese
		?�ݬ�����iStart?����?���㣬??ch����������ǡ�?��?����?����-1��

		\~japanese
		���֪��iStart���ͪΫ���髯��?����?�㪷��ch��򦪹�������Ǫ������ު��������ʪ����-1��꫿?�󪷪ު��� 
		\~
		*/
		int Find( XCHAR ch, int iStart = 0 ) const throw()
		{
			// iStart is in XCHARs
			assert( iStart >= 0 );

			// nLength is in XCHARs
			int nLength = GetLength();
			if( iStart < 0 || iStart >= nLength)
			{
				return( -1 );
			}

			// find first single character
			const XCHAR* psz = StringTraits::StringFindChar( GetString()+iStart, ch );

			// return -1 if not found and index otherwise
			return( (psz == NULL) ? -1 : int( psz-GetString() ) );
		}

		/** 
		\~korean
		���ڿ��� iStart ��° ĳ���ͺ��� �˻��ؼ� pszSub �� ����Ű�� ���ڿ��� ù ���� ��ġ�� ã�´�. ��ã���� -1�� �����Ѵ�. 

		\~english
		Finds the location of the character that is pointed by pszSub through searching from 'iStart'th character of text string. Returns -1 when not found.

		\~chinese
		?�ݬ�����iStart?����?���㣬??pszSub�����ݬ�������?����ǡ�?��?����?����-1��

		\~japanese
		���֪��iStart���ͪΫ���髯��?����?�㪷��pszSub��򦪹���֪�������������Ǫ������ު��������ʪ����-1��꫿?�󪷪ު���
		\~
		*/
		int Find( const XCHAR* pszSub, int iStart = 0 ) const throw()
		{
			// iStart is in XCHARs
			assert( iStart >= 0 );

			if(pszSub == NULL)
			{
				return( -1 );
			}
			// nLength is in XCHARs
			int nLength = GetLength();
			if( iStart < 0 || iStart > nLength )
			{
				return( -1 );
			}

			// find first matching substring
			const XCHAR* psz = StringTraits::StringFindString( GetString()+iStart, pszSub );

			// return -1 for not found, distance from beginning otherwise
			return( (psz == NULL) ? -1 : int( psz-GetString() ) );
		}

		/** 
		\~korean
		���ڿ� �ȿ��� iFirst�� ����Ű�� ������ ������ ���ڸ� �߷��� �����Ѵ�. 

		\~english
		Returns the characters collected from the location where pointed by iFirst to the end in text string.

		\~chinese
		��ݬ����������??iFirst�����۰?����������������ޡ�

		\~japanese
		���֪?��iFirst��򦪹�Ȫ�����?��������Ԫ��󪷪ƫ꫿?�󪷪ު���
		\~
		*/
		inline StringT Mid( int iFirst ) const
		{
			return( Mid( iFirst, GetLength()-iFirst ) );
		}

		/** 
		\~korean
		���ڿ� �ȿ��� iFirst�� ����Ű�� ������ nCount ��ŭ�� ���ڸ� �߷��� �����Ѵ�. 

		\~english
		Returns the characters collected from the location where pointed by iFirst to the point where the amount of characters become nCount in text string.

		\~chinese
		��ݬ��������?iFirst�����۰?���?����?��nCount��������ޡ�

		\~japanese
		���֪?��iFirst��򦪹�Ȫ�����nCount�����������Ԫ��󪷪ƫ꫿?�󪷪ު���
		\~
		*/
		StringT Mid( int iFirst, int nCount ) const
		{
			// nCount is in XCHARs

			// out-of-bounds requests return sensible things
			if (iFirst < 0)
				iFirst = 0;
			if (nCount < 0)
				nCount = 0;

			if( iFirst + nCount > GetLength() )
			{
				nCount = GetLength()-iFirst;
			}
			if( iFirst > GetLength() )
			{
				nCount = 0;
			}

			assert( (nCount == 0) || ((iFirst+nCount) <= GetLength()) );

			// optimize case of returning entire string
			if( (iFirst == 0) && ((iFirst+nCount) == GetLength()) )
			{
				return( *this );
			}

			return( StringT( GetString()+iFirst, nCount) );
		}

		/** 
		\~korean
		���ڿ� ������ �������κ��� nCount��ŭ�� ���ڿ��� �߷��� �����Ѵ�. 

		\~english
		Returns the text stings that are collected from RHS to the point where the amount of characters become nCount in text string.

		\~chinese
		��ݬ����������??��??�����?��nCount��������ޡ�

		\~japanese
		���֪?����������nCount���������֪�������Ԫ��󪷪ƫ꫿?�󪷪ު���
		\~
		*/
		StringT Right( int nCount ) const
		{
			// nCount is in XCHARs
			if (nCount < 0)
				nCount = 0;

			int nLength = GetLength();
			if( nCount >= nLength )
			{
				return( *this );
			}

			return( StringT( GetString()+nLength-nCount, nCount ) );
		}

		/** 
		\~korean
		���ڿ� ������ �������κ��� nCount��ŭ�� ���ڿ��� �߷��� �����Ѵ�. 

		\~english
		Returns the text stings that are collected from LHS to the point where the amount of characters become nCount in text string.

		\~chinese
		��ݬ����������??�??�����?��nCount��������ޡ�

		\~japanese
		���֪?���������nCount���������֪�������Ԫ��󪷪ƫ꫿?�󪷪ު���
		\~
		*/
		StringT Left( int nCount ) const
		{
			// nCount is in XCHARs
			if (nCount < 0)
				nCount = 0;

			int nLength = GetLength();
			if( nCount >= nLength )
			{
				return( *this );
			}

			return( StringT( GetString(), nCount ) );
		}

		/** 
		\~korean
		pszToken�� ����Ű�� �����ڵ�� ������ ���ڿ��� ���� �ϳ��� �����Ѵ�.
		

		\~english
		Collects the text strings distinguished by distinguishers pointed by ofpszToken one by one then returns them one by one. 
		

		\~chinese
		??pszToken�����?����?�����ݬ������??���ޡ�


		\~japanese
		pszToken��򦪹?���ʪɪ�?ܬ���쪿���֪���Ԫ��󪷪���Ī��ī꫿?�󪷪ު���


		\~


			Example:
        \code
            Proud::String str(L"%First Second#Third");
            Proud::String resToken;
            int curPos = 0;

            resToken= str.Tokenize(L"% #",curPos);
            while (resToken != L"")
            {
                _tprintf_s(L"Resulting token: %s\n", resToken);
                resToken = str.Tokenize(L"% #", curPos);
            };   
        \endcode 

		*/
        StringT Tokenize( const XCHAR* pszTokens, int& iStart ) const
		{
			assert( iStart >= 0 );

			if(iStart < 0)
			{
				ThrowInvalidArgumentException();
			}

			if( (pszTokens == NULL) || (*pszTokens == (XCHAR)0) )
			{
				if (iStart < GetLength())
				{
					return( StringT( GetString()+iStart ) );
				}
			}
			else
			{
				const XCHAR* pszPlace = GetString()+iStart;
				const XCHAR* pszEnd = GetString()+GetLength();
				if( pszPlace < pszEnd )
				{
					int nIncluding = StringTraits::StringSpanIncluding( pszPlace,
						pszTokens );

					if( (pszPlace+nIncluding) < pszEnd )
					{
						pszPlace += nIncluding;
						int nExcluding = StringTraits::StringSpanExcluding( pszPlace, pszTokens );

						int iFrom = iStart+nIncluding;
						int nUntil = nExcluding;
						iStart = iFrom+nUntil+1;

						return( Mid( iFrom, nUntil ) );
					}
				}
			}

			// return empty string, done tokenizing
			iStart = -1;

			return( StringT() );
		}

		/** 
		\~korean
		���ڿ� ������ ���� �����ִ� �� ���ڵ��� �߶󳻹�����. 

		\~english
		Cuts off the empty characters are left at RHS end of text string

		\~chinese
		����׺��ݬ����?��������

		\~japanese
		���֪����������Ӯ��?�êƪ���������﷪��תƪު���
		\~
		*/
		StringT& TrimRight()
		{
			// find beginning of trailing spaces by starting
			// at beginning (DBCS aware)

			const XCHAR* psz = GetString();
			const XCHAR* pszLast = NULL;

			while( *psz != 0 )
			{
				if( StringTraits::IsSpace( *psz ) )
				{
					if( pszLast == NULL )
						pszLast = psz;
				}
				else
				{
					pszLast = NULL;
				}
				psz = StringTraits::CharNext( psz );
			}

			if( pszLast != NULL )
			{
				// truncate at trailing space start
				int iLast = int( pszLast-GetString() );

				Truncate( iLast );
			}

			return( *this );
		}

		/** 
		\~korean
		���ڿ� ���� ���� �����ִ� �� ���ڵ��� �߶󳻹�����. 

		\~english
		Cuts off the empty characters are left at LHS end of text string

		\~chinese
		����׺��ݬ���?��������

		\~japanese
		���֪���������Ӯ��?�êƪ���������﷪��תƪު���
		\~
		*/
		StringT& TrimLeft()
		{
			// find first non-space character

			const XCHAR* psz = GetString();

			while( StringTraits::IsSpace( *psz ) )
			{
				psz = StringTraits::CharNext( psz );
			}

			if( psz != GetString() )
			{
				// fix up data and length
				int iFirst = int( psz-GetString() );
				XCHAR* pszBuffer = GetBuffer( GetLength() );
				psz = pszBuffer+iFirst;
				int nDataLength = GetLength()-iFirst;
#if (_MSC_VER>=1400)
				memmove_s( pszBuffer, (GetLength()+1)*sizeof( XCHAR ), 
					psz, (nDataLength+1)*sizeof( XCHAR ) );
#else
				memmove( pszBuffer,
					psz, (nDataLength+1)*sizeof( XCHAR ) );
#endif
				ReleaseBufferSetLength( nDataLength );
			}

			return( *this );
		}

		/** 
		\~korean
		���ڿ� ���� ���� �����ִ� �� ���ڵ��� �߶󳻹�����. 

		\~english
		Cuts off the empty characters are left at RHS end and at LHS end of text string

		\~chinese
		����׺��ݬ��??��������

		\~japanese
		���֪��?������Ӯ��?�êƪ���������﷪��תƪު���
		\~
		*/
		StringT& Trim()
		{
			return( TrimRight().TrimLeft() );
		}

		/** 
		\~korean
		���ڿ� ���� ���� �����ִ� chTarget�� ����Ű�� ���ڵ��� �߶󳻹�����. 

		\~english
		Cuts off the characters pointed by chTarget and are left at RHS end and at LHS end of text string

		\~chinese
		����׺��ݬ��??chTarget���������

		\~japanese
		���֪��?������Ӯ��?�êƪ���chTarget��򦪹����﷪��תƪު���
		\~
		*/
		StringT& Trim( XCHAR chTarget )
		{
			return( TrimRight( chTarget ).TrimLeft( chTarget ) );
		}

		/** 
		\~korean
		���ڿ� ���� ���� �����ִ� pszTargets�� ����Ű�� ���ڵ��� �߶󳻹�����. 

		\~english
		Cuts off the characters pointed by pszTargets and are left at RHS end and at LHS end of text string

		\~chinese
		����׺��ݬ��??pszTargets���������

		\~japanese
		���֪��?������Ӯ��?�êƪ���pszTargets��򦪹����﷪��תƪު���
		\~
		*/
		StringT& Trim( const XCHAR* pszTargets )
		{
			return( TrimRight( pszTargets ).TrimLeft( pszTargets ) );
		}

		/** 
		\~korean
		���ڿ� ���� ���� �����ִ� chTarget�� ����Ű�� ���ڵ��� �߶󳻹�����. 

		\~english
		Cuts off the characters pointed by chTarget and are left at RHS end of text string 

		\~chinese
		����׺��ݬ����?chTarget���������

		\~japanese
		���֪����������Ӯ��?�êƪ���chTarget��򦪹����﷪��תƪު��� 
		\~
		*/
		StringT& TrimRight( XCHAR chTarget )
		{
			// find beginning of trailing matches
			// by starting at beginning (DBCS aware)			

			const XCHAR* psz = GetString();
			const XCHAR* pszLast = NULL;

			while( *psz != 0 )
			{
				if( *psz == chTarget )
				{
					if( pszLast == NULL )
					{
						pszLast = psz;
					}
				}
				else
				{
					pszLast = NULL;
				}
				psz = StringTraits::CharNext( psz );
			}

			if( pszLast != NULL )
			{
				// truncate at left-most matching character  
				int iLast = int( pszLast-GetString() );
				Truncate( iLast );
			}

			return( *this );
		}

		/** 
		\~korean
		���ڿ� ���� ���� �����ִ� pszTargets�� ����Ű�� ���ڵ��� �߶󳻹�����. 

		\~english
		uts off the characters pointed by pszTargets and are left at RHS end of text string

		\~chinese
		����׺��ݬ����?pszTargets���������

		\~japanese
		���֪����������Ӯ��?�êƪ���pszTarget��򦪹����﷪��תƪު��� 
		\~
		*/
		StringT& TrimRight( const XCHAR* pszTargets )
		{
			// if we're not trimming anything, we're not doing any work
			if( (pszTargets == NULL) || (*pszTargets == 0) )
			{
				return( *this );
			}

			// find beginning of trailing matches
			// by starting at beginning (DBCS aware)

			const XCHAR* psz = GetString();
			const XCHAR* pszLast = NULL;

			while( *psz != 0 )
			{
				if( StringTraits::StringFindChar( pszTargets, *psz ) != NULL )
				{
					if( pszLast == NULL )
					{
						pszLast = psz;
					}
				}
				else
				{
					pszLast = NULL;
				}
				psz = StringTraits::CharNext( psz );
			}

			if( pszLast != NULL )
			{
				// truncate at left-most matching character  
				int iLast = int( pszLast-GetString() );
				Truncate( iLast );
			}

			return( *this );
		}

		/** 
		\~korean
		���ڿ� ���� ���� �����ִ� chTarget�� ����Ű�� ���ڵ��� �߶󳻹�����. 

		\~english
		Cuts off the characters pointed by chTarget and are left at LHS end of text string 

		\~chinese
		����׺��ݬ���?chTarget���������

		\~japanese
		���֪���������Ӯ��?�êƪ���chTarget��򦪹����﷪��תƪު��� 
		\~
		*/
		StringT& TrimLeft( XCHAR chTarget )
		{
			// find first non-matching character
			const XCHAR* psz = GetString();

			while( chTarget == *psz )
			{
				psz = StringTraits::CharNext( psz );
			}

			if( psz != GetString() )
			{
				// fix up data and length
				int iFirst = int( psz-GetString() );
				XCHAR* pszBuffer = GetBuffer( GetLength() );
				psz = pszBuffer+iFirst;
				int nDataLength = GetLength()-iFirst;
#if (_MSC_VER>=1400)
				memmove_s( pszBuffer, (GetLength()+1)*sizeof( XCHAR ), 
					psz, (nDataLength+1)*sizeof( XCHAR ) );
#else
				memmove( pszBuffer,
					psz, (nDataLength+1)*sizeof( XCHAR ) );
#endif
				ReleaseBufferSetLength( nDataLength );
			}

			return( *this );
		}

		/** 
		\~korean
		���ڿ� ���� ���� �����ִ� pszTargets�� ����Ű�� ���ڵ��� �߶󳻹�����. 

		\~english
		Cuts off the characters pointed by pszTargets and are left at RHS end of text string

		\~chinese
		����׺��ݬ���?pszTargets���������

		\~japanese
		���֪���������Ӯ��?�êƪ���pszTarget��򦪹����﷪��תƪު��� 
		\~
		*/
		StringT& TrimLeft( const XCHAR* pszTargets )
		{
			// if we're not trimming anything, we're not doing any work
			if( (pszTargets == NULL) || (*pszTargets == 0) )
			{
				return( *this );
			}

			const XCHAR* psz = GetString();
			while( (*psz != 0) && (StringTraits::StringFindChar( pszTargets, *psz ) != NULL) )
			{
				psz = StringTraits::CharNext( psz );
			}

			if( psz != GetString() )
			{
				// fix up data and length
				int iFirst = int( psz-GetString() );
				XCHAR* pszBuffer = GetBuffer( GetLength() );
				psz = pszBuffer+iFirst;
				int nDataLength = GetLength()-iFirst;
#if defined(_WIN32)
				Checked::memmove_s( pszBuffer, (GetLength()+1)*sizeof( XCHAR ), 
					psz, (nDataLength+1)*sizeof( XCHAR ) );
#else
                memmove(pszBuffer, psz, (nDataLength+1)*sizeof( XCHAR ));
#endif
				ReleaseBufferSetLength( nDataLength );
			}

			return( *this );
		}

#ifdef _WIN32
#pragma push_macro("new")
#undef new
		// �� Ŭ������ ProudNet DLL ��츦 ���� Ŀ���� �Ҵ��ڸ� ����.
		// proc heap�� ����. ���� ������ ������ ���⵵ �ϴϱ�.
		DECLARE_NEW_AND_DELETE
#pragma pop_macro("new")
#endif // __MARMALADE__

	};
	
	template<typename XCHAR, typename StringTraits>
	StringT<XCHAR,StringTraits> operator+(const StringT<XCHAR,StringTraits> &a,const StringT<XCHAR,StringTraits> &b)
	{
		StringT<XCHAR,StringTraits> ret = a;
		ret += b;
		return ret;
	}

	template<typename XCHAR, typename StringTraits>
	StringT<XCHAR,StringTraits> operator+(const StringT<XCHAR,StringTraits> &a,const XCHAR* b)
	{
		StringT<XCHAR,StringTraits> ret = a;
		ret += b;
		return ret;
	}

	template<typename XCHAR, typename StringTraits>
	StringT<XCHAR,StringTraits> operator+(const XCHAR* a,const StringT<XCHAR,StringTraits> &b)
	{
		StringT<XCHAR,StringTraits> ret = a;
		ret += b;
		return ret;
	}

	/** 
	\~korean
	CStringT.GetBuffer, CStringT.ReleaseBuffer �� ȣ���� �ڵ�ȭ�Ѵ�. 

	\~english
	Automates calling CStringT.GetBuffer, CStringT.ReleaseBuffer

	\~chinese
	�?�� CStringT.GetBuffer,  CStringT.ReleaseBuffer%����У��

	\~japanese
	CStringT.GetBuffer, CStringT.ReleaseBuffer�������󪷪���������ު��� 
	\~
	*/
	template<typename XCHAR, typename StringTraits>
	class StrBufT
	{
		StringT<XCHAR,StringTraits>* m_obj;
		XCHAR* m_bufPtr;
	public:
		StrBufT(StringT<XCHAR,StringTraits>& src, int maxLength = 0)
		{
			m_obj = &src;
			m_bufPtr = src.GetBuffer(maxLength); 
		}

		~StrBufT()
		{
			m_obj->ReleaseBuffer();
		}

		operator XCHAR*()
		{
			return m_bufPtr;
		}

		XCHAR* GetBuf()
		{
			return m_bufPtr;
		}
	};

	template<typename XCHAR, typename StringTraits>
	class StringTraitsT
	{
	public:
		typedef const StringT<XCHAR,StringTraits>& INARGTYPE;
		typedef StringT<XCHAR,StringTraits>& OUTARGTYPE;

		static uint32_t __cdecl Hash( INARGTYPE str )
		{
			assert( str.GetString() != NULL );
			uint32_t nHash = 0;
			const XCHAR* pch = str;
			while( *pch != 0 )
			{
				nHash = (nHash<<5)+nHash+(*pch);
				pch++;
			}

			return( nHash );
		}

		static bool __cdecl CompareElements( INARGTYPE str1, INARGTYPE str2 )
		{
			return( StringTraits::StringCompare( str1, str2 ) == 0 );
		}

		static int __cdecl CompareElementsOrdered( INARGTYPE str1, INARGTYPE str2 )
		{
			return( StringTraits::StringCompare( str1, str2 ) );
		}
	};

	/** 
	\~korean
	ANSI ĳ���� ���ڿ� 

	\~english
	ANSI character text string

	\~chinese
	ANSI �����ݬ����

	\~japanese
	ANSI����髯��?���֪
	\~
	*/
	typedef StringT<char,AnsiStrTraits> StringA;
	/** 
	\~korean
	Unicode ĳ���� ���ڿ� 

	\~english
	Unicode character text string

	\~chinese
	Unicode �����ݬ����

	\~japanese
	Unicode����髯��?���֪
	\~
	*/
	typedef StringT<wchar_t,UnicodeStrTraits> StringW;
    
	/**
	\~korean
	���ڿ� Ŭ�����Դϴ�.
	Windows�� Marmalade������ UTF-16�� �����ϴ� wchar_t Ÿ�� ���ڿ������� ��Ÿ �÷��������� UTF-8�� �����ϴ� char Ÿ�� ���ڿ��Դϴ�.

	\~english
	It is a string class.
	The string is a wchar_t type that supports UTF-16 at Windows & Marmalade but at the other platforms, it is a char type string that supports UTF-8.

	\~chinese
	�ݬ�� class ��
	?���Windows��Marmalade������ UTF-16 �� wchar_t type ���ݬ����ӣ����������������� UTF-8 �� char type ���ݬ����

	\~japanese
	���֪���髹�Ǫ���
	Windows��Marmalade�Ǫ�UTF-16���굪���wchar_t���������֪�Ǫ�������Ϋ׫�ëȫի�?��Ǫ�UTF-8���굪���char���������֪�Ǫ���
	*/
#if defined(_PNUNICODE) // VC++������ �̰��� ���� �ִ�. MBS���� �ɼ��� �����ϸ� ������ ������ ���� �ô뿡 ���� �׷��ڴ°�?
	typedef StringW String;
#else
	typedef StringA String;
#endif

	/** 
	\~korean
	ANSI ĳ���� ���ڿ��� ���ڿ� ���� ������ ���� Ŭ���� 

	\~english
	Class for manipulating ANSI character text string buffer

	\~chinese
	?��ANSI�����ݬ�����ݬ����?buffer��?��

	\~japanese
	ANSI����髯��?���֪�����֪�Ыëի�?���ªΪ���Ϋ��髹
	\~
	*/
	typedef StrBufT<char,AnsiStrTraits> StrBufA;

	/** 
	\~korean
	Unicode ĳ���� ���ڿ��� ���ڿ� ���� ������ ���� Ŭ���� 

	\~english
	Class for manipulating Unicode character text string bufferUnicode

	\~chinese
	?��Unicode�����ݬ�����ݬ����?buffer��?��

	\~japanese
	Unicode����髯��?���֪�����֪�Ыëի�?���ªΪ���Ϋ��髹
	\~
	*/
	typedef StrBufT<wchar_t,UnicodeStrTraits> StrBufW;
    
	typedef StringTraitsT<char,AnsiStrTraits> StringTraitsA;
	typedef StringTraitsT<wchar_t,UnicodeStrTraits> StringTraitsW;

	/** 
	\~korean
	ĳ���� ���ڿ� ��ȯ�Լ�

	\~english
	Convert to String Function

	\~chinese
	�����ݬ��??��?��

	\~japanese
	����髯��?���֪?��??
	\~
	*/

	StringA StringW2A(const wchar_t *src, CStringEncoder* encoder = NULL);		
	StringW StringA2W(const char *src, CStringEncoder* encoder = NULL);

	/* Win32, Marmalade������ wchar_t�� �ֿ������� unix������ char�� �ֿ��Ѵ�.
	char ���ڿ��� UTF-8�� ó���ϱ� �����̴�. 
	*/
#ifdef _PNUNICODE
	#define StringT2A StringW2A
	#define StringA2T StringA2W
	#define StringT2W(x) (::Proud::String(x))
	#define StringW2T(x) (::Proud::String(x))
	typedef StringTraitsW StringTraits;
	typedef StrBufW StrBuf;
#else
	#define StringT2A(x) (::Proud::String(x))
	#define StringA2T(x) (::Proud::String(x))
	#define StringT2W StringA2W
	#define StringW2T StringW2A
	typedef StringTraitsA StringTraits;
	typedef StrBufA StrBuf;
#endif

}

// NOTE: CPNElementTraits�� specialized template�� namespace �ٱ����� ����.
// CFastMap��� ����° ���� �� �־ �ǰ� �Ϸ���.
template<>
class CPNElementTraits<Proud::StringW> :public Proud::StringTraitsW{};

template<>
class CPNElementTraits<Proud::StringA> :public Proud::StringTraitsA{};

/**  @} */

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#ifdef _MSC_VER 
#pragma warning(pop)
#endif // __MARMALADE__
