/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 177 92 124 113 87 79 17 155 171 239 138 133 88 235 28 112 146 102 93 52 214 131 240 31 138 179 248 115 127 118 107 31 112 91 111 14 243 1 121 131 22 69 144 19 214 101 65 133 253 32 122 175 12 198 63 134 23 240 109 90 59 142 194 194 160 148 139 101 68 220 217 181 32 240 36 47 59 74 18 182 145 116 17 29 255 115 236 11 29 111 122  */
#pragma once 

/* The _Noreturn keyword of draft C1X.  */
// iconv �ҽ����� ����.
// http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1453.htm
#ifdef _MSC_VER
#  define _Noreturn __declspec (noreturn)
#else
#  define _Noreturn __attribute__ ((__noreturn__))
#endif


// #ifndef _Noreturn
// # if (3 <= __GNUC__ || (__GNUC__ == 2 && 8 <= __GNUC_MINOR__) \
// 	  || 0x5110 <= __SUNPRO_C)
// #  define _Noreturn __attribute__ ((__noreturn__))
// # elif 1200 <= _MSC_VER
// #  define _Noreturn __declspec (noreturn)
// # else
// #  define _Noreturn
// # endif
// #endif

#ifdef _MSC_VER
#define _Noinline __declspec(noinline)
#else
#define _Noinline __attribute__ ((noinline))
#endif

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/* C++ exception�� throw �ϴ� ������ ������ �Լ���.
	
	Q: �� ���� throw�� ���ϰ� �Լ��� �����߳���?
	A: NDK, PS4, UE4 �� �Ϻ� ��Ȳ������ throw keyword�� �� ���ϴ�. �� exception handling�� ���ϴ� �����Ϸ� ������ ���ϴ�.
	�̷��� ��Ȳ������ �̷��� �Լ��� ���ε� ���� �� ���ۿ� �����ϴ�.
	����, �׷��� ��������, ȣ��Ǵ� �Լ�X�� throw�� �ϸ� �ȵ�����, ȣ��Ǵ� �Լ����� ȣ���ϴ� ���� �Լ���Y�� throw�� �ϴ���,
	X���� catch�� ���شٸ�, ���� �����ϴ�. 
	
	Q: exception.h�� ������ ���ٵ���?
	A: exception.h�� pnstring.h�� include�ϴµ�, pnstring.h�� �Ʒ� �Լ����� ���ϴ�.
	*/
	_Noreturn void ThrowInvalidArgumentException();
	_Noreturn void ThrowArrayOutOfBoundException();
	_Noreturn void ThrowBadAllocException();
	_Noreturn void ThrowException(const char* text);
}
#ifdef _MSC_VER
#pragma pack(pop)
#endif