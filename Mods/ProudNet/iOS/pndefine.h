/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 177 92 124 113 87 79 17 155 171 239 138 133 88 235 28 112 146 102 93 52 214 131 240 31 138 179 248 115 127 118 107 31 112 91 111 14 243 1 121 131 22 69 144 19 214 101 65 133 253 32 122 175 12 198 63 134 23 240 109 90 59 142 194 194 160 148 139 101 68 220 217 181 32 240 36 47 59 74 18 182 145 116 17 29 255 115 236 11 29 111 122  */
#pragma once

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

#ifdef _MSC_VER // pragma warning is VC++ specific.
#pragma warning(disable:4127) // We know that compiler optimizes JCX instruction if constant is used and we make use of them.
#endif

#define PNDEFINE_USED

// Windows SDK와 Playstation SDK는 iconv가 기본 제공되지 않는다.
// TODO: tiniconv로 갈아탈까?
#if defined _WIN32 || defined __ORBIS__ || defined __ANDROID__  // NOTE: ProudNet_android.vcxproj에서는 NDK 내 iconv를 찾을 수 없음.
#	define PROUDNET_HAS_ICONV
#endif

// NOTE: 소켓 모델에 따른 운영체제 define 정의
//
#if defined(__MACH__)
#define USE_KQUEUE_ONLY_ON_MACH
#endif

#if defined(__FreeBSD__)
#define USE_KQUEUE_ONLY_ON_FREEBSD
#endif

#if defined(__MACH__) || defined(__FreeBSD__)
#define USE_KQUEUE_ONLY
#endif

#if defined(__linux__)
#define USE_EPOLL_ONLY_ON_LINUX
#endif

#if defined(__linux__) || defined(__MACH__) || defined(__FreeBSD__)
#define USE_EPOLL_OR_KQUEUE
#endif

#if defined(_WIN32)
#define USE_IOCP_ONLY_ON_WINDOWS
#endif

#if defined(__MARMALADE__)
#define USE_POLL_ONLY
#endif

#if defined(_WIN32) || defined(__linux__) || defined(__MACH__) || defined(__FreeBSD__)
#define USE_IOCP_AND_EPOLL_AND_KQUEUE
#endif

// 스레드,핸들 등 커널 리소스 수가 제법 제약되는 플랫폼
#if defined(__ANDROID__) || defined(TARGET_OS_IPHONE) || defined(__ORBIS__) || defined(__MARMALADE__)
#define KERNEL_RESOURCE_SHORTAGE
#endif

// critical section or mutex의 thread ID 값을 얻어올수 있는 환경에서만 정의됩니다.
#if defined (_WIN32) || defined (__linux__) || defined (__ANDROID__) /*|| defined (__MACH__)*/
#define PN_LOCK_OWNER_SHOWN
#endif

#ifdef _MSC_VER // VC++계열이면
#define PN_ALIGN(val) __declspec(align(val))
#else //이외 컴파일러 계열이면
#define PN_ALIGN(val) __attribute__((aligned(val)))
#endif

// std::chrono를 쓸 수 있는지?
#if (_MSC_VER>=1800) || (__cplusplus > 199711L)
// 예전에는 이거였음 => defined(SUPPORTS_CPP11) && !((defined(__MACH__) && defined(__GLIBCXX__)) || defined(_PN_BOOST))
#define PN_USE_CHRONO 1
#else
#define PN_USE_CHRONO 0
#endif


#ifdef _MSC_VER
#pragma pack(pop)
#endif