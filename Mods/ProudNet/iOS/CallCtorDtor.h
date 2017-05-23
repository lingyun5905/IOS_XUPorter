/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 177 92 124 113 87 79 17 155 171 239 138 133 88 235 28 112 146 102 93 52 214 131 240 31 138 179 248 115 127 118 107 31 112 91 111 14 243 1 121 131 22 69 144 19 214 101 65 133 253 32 122 175 12 198 63 134 23 240 109 90 59 142 194 194 160 148 139 101 68 220 217 181 32 240 36 47 59 74 18 182 145 116 17 29 255 115 236 11 29 111 122  */
#pragma once 

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

/** 생성자, 파괴자를 명시적으로 호출하는 함수들.
Container class를 정의할 때 주로 사용된다. */

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

// 복사 생성자를 호출한다.
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

// 주의: 반드시!! 함수 사용시 <T>를 명료하게 붙일 것. 일부 컴파일러는 엉뚱한 것을 템플릿 인스턴스화한다.
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

// 주의: 반드시!! 함수 사용시 <T>를 명료하게 붙일 것. 일부 컴파일러는 엉뚱한 것을 템플릿 인스턴스화한다.
template< typename T >
void CallDestructor(T* pInstance)
{
	pInstance->T::~T();
};

#ifndef __MARMALADE__
#pragma push_macro("new")
#undef new
#endif // __MARMALADE__

// 주의: 반드시!! 함수 사용시 <T>를 명료하게 붙일 것. 일부 컴파일러는 엉뚱한 것을 템플릿 인스턴스화한다.
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

// 주의: 반드시!! 함수 사용시 <T>를 명료하게 붙일 것. 일부 컴파일러는 엉뚱한 것을 템플릿 인스턴스화한다.
template< typename T >
static inline void CallCopyConstructors(T* pElements, const T* pOldElements, intptr_t nElements)
{
	int iElement = 0;

	for (iElement = 0; iElement < nElements; iElement++)
	{
		::new(pElements + iElement) T(pOldElements[iElement]);
	}
}


// 주의: 반드시!! 함수 사용시 <T>를 명료하게 붙일 것. 일부 컴파일러는 엉뚱한 것을 템플릿 인스턴스화한다.
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

#ifdef _MSC_VER
#pragma pack(pop)
#endif