/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 177 92 124 113 87 79 17 155 171 239 138 133 88 235 28 112 146 102 93 52 214 131 240 31 138 179 248 115 127 118 107 31 112 91 111 14 243 1 121 131 22 69 144 19 214 101 65 133 253 32 122 175 12 198 63 134 23 240 109 90 59 142 194 194 160 148 139 101 68 220 217 181 32 240 36 47 59 74 18 182 145 116 17 29 255 115 236 11 29 111 122  */
/*
ProudNet 1.7.34387-dev003-10


�� ���α׷��� ���۱��� ���ټǿ��� �ֽ��ϴ�.
�� ���α׷��� ����, ���, ������ ���õ� ������ �� ���α׷��� �������ڿ��� ����� ������,
����� �ؼ����� �ʴ� ��� ��Ģ������ ���� ����� �����մϴ�.
���� ��뿡 ���� å���� �� ���α׷��� �������ڿ��� ��༭�� ��õǾ� �ֽ��ϴ�.

** ����: ���۹��� ���� ���� ��ø� �������� ���ʽÿ�.


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

// ������ϰ� LIB�� ���� ������ �ȸ¾Ƽ� ����� ������ �����ϱ� ����
// ���� ������Ʈ�� �� ������(����ϰԶ�) �� ���� �ٲٴ� ���� �����.
#define PROUDNET_H_LIB_SIGNATURE 6


#include <assert.h>

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

#if !defined(_WIN32)
#include <sys/types.h>
#include <limits.h>
#include <string.h>
#endif


// int32_t, int64_t, intptr_t ���� include�ϱ� ����
#ifdef __MARMALADE__
#include <s3eTypes.h>
#include <string.h> // memset�� ���� ����Ǿ� �ִ�
#endif

// fd_set does not name a type ������ ���� �ذ� -> ��� ���� include, __linux__ ����
#ifdef __linux__
#include <sys/select.h>
#endif

#include <new> // for placement new

#include "pnstdint.h"

#define PNMIN(a,b)            (((a) < (b)) ? (a) : (b))
#define PNMAX(a,b)            (((a) > (b)) ? (a) : (b))

#define PN_INFINITE 0xFFFFFFFF

#if defined(WCHAR_MAX) && (WCHAR_MAX > UINT16_MAX)
#	define WCHAR_LENGTH 4
#else
#	if defined(__MARMALADE__) || defined(_WIN32) || defined(__ORBIS__) // NOTE: Marmalade, ORBIS�� Ÿ�� �ӽ��� unix ����ε��� ũ��2��.
#		define WCHAR_LENGTH 2
#	else
#		define WCHAR_LENGTH 4
#	endif
#endif

#include "pndefine.h"

// C4100 warning�� ���� �ʹٸ� ����.
#define _pn_unused(x) ((void)(x))



#if !defined(_WIN32)

// NOTE: DWORD, UINT_PTR ���� �͵��� uint32_t or uintptr_t �� stdint�� ���ǵ� Ÿ������ �� ���̰�, ���������� ���� ���������� ����.
// ã�� ���� ���� ���ͼ� ���������.

typedef int SOCKET;
typedef fd_set FD_SET;

#define WINAPI __stdcall
#define _HEAPOK (-2)

//#define _Noreturn
#define __cdecl
#define __forceinline inline

#if (_MSC_VER < 1300)

#ifndef __noop
#define __noop (void)0 // __noop�� �������� �ʴ� �����Ϸ��� ���� ���
#endif

#endif

#define LOWORD(l) ((uint16_t)(((uint32_t)(l)) & 0xffff))
#define HIWORD(l) ((uint16_t)((((uint32_t)(l)) >> 16) & 0xffff))
#define LOBYTE(w) ((uint8_t)(((uint32_t)(w)) & 0xff))
#define HIBYTE(w) ((uint8_t)((((uint32_t)(w)) >> 8) & 0xff))
#define MAKEWORD(a, b) ((uint16_t)(((uint8_t)(((uint32_t)(a)) & 0xff)) | ((uint16_t)((uint8_t)(((uint32_t)(b)) & 0xff))) << 8))
#define MAKELONG(a, b) ((long)(((uint16_t)(((uint32_t)(a)) & 0xffff)) | ((uint32_t)((uint16_t)(((uint32_t)(b)) & 0xffff))) << 16))

#endif // non win32 platform

#if (_MSC_VER>=1600) || (__cplusplus > 199711L)
// NOTE: IoT ��ü�ο����� C++11�� �����ȵǴ� ��찡 �ִ�. ���� Ŭ�� ��⿡���� C++11 ����� ������ ���ؾ�.
#define SUPPORTS_LAMBDA_EXPRESSION
#endif

#if (_MSC_VER>=1800) || (__cplusplus > 199711L)
//NOTE: VS2013���� �������ø� ���ڸ� �����մϴ�.
#define SUPPORTS_CPP11
#endif

#ifdef SUPPORTS_CPP11
#define MOVE_OR_COPY(arg) std::move(arg)
#else
#define MOVE_OR_COPY
#endif// SUPPORTS_CPP11

#if ((_MSC_VER > 1700) || (__cplusplus > 199711L)) // VS2012 �̻���� final keyword�� ������. C++11�� �����ϸ� NDK ���� ������� �Ʒ� Ű���尡 ��� ������.
#define PN_OVERRIDE override
#define PN_FINAL final
#define PN_SEALED final // sealed�� VC++ specific�̸�, C++11�� final�� ä��.
#elif _MSC_VER >= 1400 
#define PN_OVERRIDE override
#define PN_FINAL sealed
#define PN_SEALED sealed // sealed VS2005���� ���� (MS���� ��ǥ�� Ȯ��)
#else // old compilers
#define PN_OVERRIDE
#define PN_FINAL
#define PN_SEALED
#endif

#define PNMIN(a,b)            (((a) < (b)) ? (a) : (b))
#define PNMAX(a,b)            (((a) > (b)) ? (a) : (b))

#include "pntchar.h"

template< typename T >
void CallConstructor(T* pInstance)
{
#ifndef __MARMALADE__
#pragma push_macro("new")
#undef new
#endif

	::new(pInstance)T();

#ifndef __MARMALADE__
#pragma pop_macro("new")
#endif // __MARMALADE__
};

template< typename T, typename Src >
void CallConstructor(T* pInstance, const Src& src)
{
#ifndef __MARMALADE__
#pragma push_macro("new")
#undef new
#endif // __MARMALADE__

	::new(pInstance)T(src);

#ifndef __MARMALADE__
#pragma pop_macro("new")
#endif // __MARMALADE__
};

// ����: �ݵ��!! �Լ� ���� <T>�� ����ϰ� ���� ��. �Ϻ� �����Ϸ��� ������ ���� ���ø� �ν��Ͻ�ȭ�Ѵ�.
template< typename T, typename Src, typename Src1 >
void CallConstructor(T* pInstance, const Src& src, const Src1 src1)
{
#ifndef __MARMALADE__
#pragma push_macro("new")
#undef new
#endif // __MARMALADE__

	::new(pInstance)T(src, src1);

#ifndef __MARMALADE__
#pragma pop_macro("new")
#endif // __MARMALADE__
};

// ����: �ݵ��!! �Լ� ���� <T>�� ����ϰ� ���� ��. �Ϻ� �����Ϸ��� ������ ���� ���ø� �ν��Ͻ�ȭ�Ѵ�.
template< typename T >
void CallDestructor(T* pInstance)
{
	pInstance->T::~T();
};

#ifndef __MARMALADE__
#pragma push_macro("new")
#undef new
#endif // __MARMALADE__

// ����: �ݵ��!! �Լ� ���� <T>�� ����ϰ� ���� ��. �Ϻ� �����Ϸ��� ������ ���� ���ø� �ν��Ͻ�ȭ�Ѵ�.
template< typename T >
static inline void CallConstructors(T* pElements, intptr_t nElements)
{
	int iElement = 0;

	//	try
	//	{
	for (iElement = 0; iElement < nElements; iElement++)
	{
		::new(pElements + iElement) T;

	}
	//	}
	// 	catch(...)
	// 	{
	// 		while( iElement > 0 )
	// 		{
	// 			iElement--;
	// 			pElements[iElement].~T();
	// 		}
	//
	// 		throw;
	// 	}
}

// ����: �ݵ��!! �Լ� ���� <T>�� ����ϰ� ���� ��. �Ϻ� �����Ϸ��� ������ ���� ���ø� �ν��Ͻ�ȭ�Ѵ�.
template< typename T >
static inline void CallCopyConstructors(T* pElements, const T* pOldElements, intptr_t nElements)
{
	int iElement = 0;

	for (iElement = 0; iElement < nElements; iElement++)
	{
		::new(pElements + iElement) T(pOldElements[iElement]);
	}
}


// ����: �ݵ��!! �Լ� ���� <T>�� ����ϰ� ���� ��. �Ϻ� �����Ϸ��� ������ ���� ���ø� �ν��Ͻ�ȭ�Ѵ�.
template< typename T >
static inline void CallDestructors(T* pElements, intptr_t nElements) throw()
{
	(void)pElements;

	for (int iElement = 0; iElement < nElements; iElement++)
	{
		pElements[iElement].~T();
	}
}
#ifndef __MARMALADE__
#pragma pop_macro("new")
#endif // __MARMALADE__

#if 1
/*
\~korean
���� ProudNet�� DLL�� �������� �ʴ´�. CAtlStringW ������ ������ STL Ÿ�� �Ķ���Ͱ� DLL CRT / Static CRT ��ȣȯ ������ �ִ�(��Ÿ�� ����)
���� CNetServer.Start�� ���� CFastArray<int>�������� ��Ÿ�� ������ ����� ��Ȳ�̴�.
���� ���Ŀ� STL�� �Ⱦ��� ������ �Ϸ�� �Ŀ��� ProudNet DLL�� ������Ű��� ����.

\~english
Since ProudNet doesn't support DLL, there may be a DLL CRT / Static CRT incompatible issue for STL type parameter, which works fine in CAtlStringW(Runtime error).
This is a situation where runtime error occurs immediately from CFastArray<int> of CNetServer.Start.
Consider of supporting ProudNet DLL after completing structure without using STL.

\~chinese
ProudNet ?����DLL��?��?�� CAtlStringW%??��STL ?��??���DLL CRT / Static CRT ު��???��?��????����
??�� CNetServer.Start%�� CFastArray<int>%?�?��?��????����?��?�����������STL��??�����������ProudNet DLL?��

\~japanese
�ު���ProudNet��DLL�򫵫�?�Ȫ��ƪ��ު���CA����StringW���Ϫ���ު��󪬡�STL�����׫ѫ��?��?��DLL CRT / Static CRT��ު������𹪬����ު�����󫿫��૨��?��
��?��CNetServer.Start������CFastArray<int>����󫿫��૨��?��?�檹��?�ϪǪ���
��êơ�STL���Ū�ʪ��誦��?�ު��쪿����ProudNet DLL�򫵫�?�Ȫ���誦�˪��ު��窦��
\~
*/
#	define PROUD_API
#	define PROUDSRV_API
#else
////////////// ProudNet DLLȭ�� ��� �Ʒ��� �������.
#if defined (PROUD_STATIC_LIB)
#	define PROUD_API
#	define PROUDSRV_API
#elif defined(PROUD_EXPORTS)
#	define PROUD_API __declspec(dllexport)
#	define PROUDSRV_API
#elif defined(PROUDSRV_EXPORTS)
#	define PROUD_API __declspec(dllimport)
#	define PROUDSRV_API __declspec(dllexport)
#else
#	define PROUD_API __declspec(dllimport)
#	define PROUDSRV_API __declspec(dllimport)
#endif
#endif

//#pragma pack(push,8)

#include "throw.h"

namespace Proud
{
	PROUD_API _Noreturn void ThrowInt32OutOfRangeException(const char* where);

#ifdef _W64
	inline void BoundCheckInt32(int64_t v, const char* where)
	{
		if (v < INT64_MIN || v > INT64_MAX)
			ThrowInt32OutOfRangeException(where);
	}

	inline void BoundCheckUInt32(uint64_t v, const char* where)
	{
		if (v > UINT64_MAX)
			ThrowInt32OutOfRangeException(where);
	}
#else
#	define BoundCheckInt32 __noop
#endif


	struct __Position {};

	typedef __Position *Position;
}

template< typename T >
class CPNElementTraits
{
public:
	typedef const T& INARGTYPE;
	typedef T& OUTARGTYPE;

	// 	static void CopyElements( T* pDest, const T* pSrc, size_t nElements )
	// 	{
	// 		for( size_t iElement = 0; iElement < nElements; iElement++ )
	// 		{
	// 			pDest[iElement] = pSrc[iElement];
	// 		}
	// 	}
	//
	// 	static void RelocateElements( T* pDest, T* pSrc, size_t nElements )
	// 	{
	// 		// A simple memmove works for nearly all types.
	// 		// You'll have to override this for types that have pointers to their
	// 		// own members.
	// 		Checked::memmove_s( pDest, nElements*sizeof( T ), pSrc, nElements*sizeof( T ));
	// 	}

	inline static uint32_t Hash(const T& element) throw()
	{
		//1,2,4,8������ ���ؼ� ����Ʈ �����͸� ���� �����´�.
		// �׳� ���� �����ϰ� �� ���, float�� double�� ��� ������ Ÿ�������� ĳ������ �ϴ� ���� �����ϱ� �ȵȴ�.
		if (sizeof(element) == sizeof(unsigned char)) // NOTE: ��������� �񱳴� �����Ϸ��� �˾Ƽ� ���� ��� ����� ���� ����.
		{
			unsigned char* piece = (unsigned char*)&element; // ���� �ȵ����� �ݺ� �ڵ���ð� ���ø� �Լ��� ���� ����. �����Ϸ� ������ �ʹ� ���� ����.
			return *piece;
		}
		else if (sizeof(element) == sizeof(unsigned short))
		{
			unsigned short* piece = (unsigned short*)&element;
			return *piece;
		}
		else if (sizeof(element) == sizeof(unsigned int))
		{
			unsigned int* piece = (unsigned int*)&element;
			return *piece;
		}
		else if (sizeof(element) == sizeof(int64_t))
		{
			// 64bit ũ�� Ÿ��(double���)�� xor�� �ؽ��ϱ� ���� �յڸ� ���´�.
			// cast to smaller type�� �Ϸ��� �ϴ� clang���� ������ ���⿡, �̷��� �ؾ�.
			uint32_t* piece = (uint32_t*)&element;
			return piece[0] ^ piece[1];
		}
		else
		{
			// 1,2,4,8����Ʈ ���� �� �ٸ� ũ�Ⱑ �ֳ�? ������ ������ ��.
			// ���� C++ plain data type �߿��� ���� ��.
			int* a = 0;
			*a = 1;

			// meaningless
			return 0;
		}
	}


	inline static bool CompareElements(const T& element1, const T& element2)
	{
		return (element1 == element2);
	}

	inline static int CompareElementsOrdered(const T& element1, const T& element2)
	{
		if (element1 < element2)
		{
			return(-1);
		}
		else if (element1 == element2)
		{
			return(0);
		}
		else
		{
			assert(element1 > element2);
			return(1);
		}
	}
};

#define PN_LODWORD(QWordValue) ((uint32_t)(QWordValue))
#define PN_HIDWORD(QWordValue) ((uint32_t)(((QWordValue) >> 32) & 0xffffffff))

#include "atomic.h"

#ifdef _MSC_VER
#pragma pack(pop)
#endif
