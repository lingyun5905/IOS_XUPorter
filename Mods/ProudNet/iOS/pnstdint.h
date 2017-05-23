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

#include "pndefine.h"
#if defined(_MSC_VER) && (_MSC_VER < 1600)

#include <yvals.h> // _C2��� ��ũ�� ������

typedef signed char int8_t;
typedef short int16_t;
typedef int int32_t;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

typedef signed char int_least8_t;
typedef short int_least16_t;
typedef int int_least32_t;

typedef unsigned char uint_least8_t;
typedef unsigned short uint_least16_t;
typedef unsigned int uint_least32_t;

typedef char int_fast8_t;
typedef int int_fast16_t;
typedef int int_fast32_t;

typedef unsigned char uint_fast8_t;
typedef unsigned int uint_fast16_t;
typedef unsigned int uint_fast32_t;

#ifndef _INTPTR_T_DEFINED
#define _INTPTR_T_DEFINED
#ifdef _WIN64
typedef __int64 intptr_t;
#else /* _WIN64 */
typedef _W64 int intptr_t;
#endif /* _WIN64 */
#endif /* _INTPTR_T_DEFINED */

#ifndef _UINTPTR_T_DEFINED
#define _UINTPTR_T_DEFINED
#ifdef _WIN64
typedef unsigned __int64 uintptr_t;
#else /* _WIN64 */
typedef _W64 unsigned int uintptr_t;
#endif /* _WIN64 */
#endif /* _UINTPTR_T_DEFINED */

typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;

typedef __int64 int_least64_t;
typedef unsigned uint_least64_t;

typedef __int64 int_fast64_t;
typedef unsigned uint_fast64_t;

typedef __int64 intmax_t;
typedef unsigned uintmax_t;

/* LIMIT MACROS */
#define INT8_MIN	(-0x7f - _C2)
#define INT16_MIN	(-0x7fff - _C2)
#define INT32_MIN	(-0x7fffffff - _C2)

#define INT8_MAX	0x7f
#define INT16_MAX	0x7fff
#define INT32_MAX	0x7fffffff
#define UINT8_MAX	0xff
#define UINT16_MAX	0xffff
#define UINT32_MAX	0xffffffff

#define INT_LEAST8_MIN		(-0x7f - _C2)
#define INT_LEAST16_MIN		(-0x7fff - _C2)
#define INT_LEAST32_MIN		(-0x7fffffff - _C2)

#define INT_LEAST8_MAX		0x7f
#define INT_LEAST16_MAX		0x7fff
#define INT_LEAST32_MAX		0x7fffffff
#define UINT_LEAST8_MAX		0xff
#define UINT_LEAST16_MAX	0xffff
#define UINT_LEAST32_MAX	0xffffffff

#define INT_FAST8_MIN		(-0x7f - _C2)
#define INT_FAST16_MIN		(-0x7fff - _C2)
#define INT_FAST32_MIN		(-0x7fffffff - _C2)

#define INT_FAST8_MAX		0x7f
#define INT_FAST16_MAX		0x7fff
#define INT_FAST32_MAX		0x7fffffff
#define UINT_FAST8_MAX		0xff
#define UINT_FAST16_MAX		0xffff
#define UINT_FAST32_MAX		0xffffffff

#if _INTPTR == 0 || _INTPTR == 1
#define INTPTR_MAX			0x7fffffff
#define INTPTR_MIN			(-INTPTR_MAX - _C2)
#define UINTPTR_MAX			0xffffffff

#else /* _INTPTR == 2 */
#define INTPTR_MIN			(-_LLONG_MAX - _C2)
#define INTPTR_MAX			_LLONG_MAX
#define UINTPTR_MAX			_ULLONG_MAX
#endif /* _INTPTR */

#define INT8_C(x)	(x)
#define INT16_C(x)	(x)
#define INT32_C(x)	((x) + (INT32_MAX - INT32_MAX))

#define UINT8_C(x)	(x)
#define UINT16_C(x)	(x)
#define UINT32_C(x)	((x) + (UINT32_MAX - UINT32_MAX))

#ifdef _WIN64
#define PTRDIFF_MIN		INT64_MIN
#define PTRDIFF_MAX		INT64_MAX
#else /* _WIN64 */
#define PTRDIFF_MIN		INT32_MIN
#define PTRDIFF_MAX		INT32_MAX
#endif /* _WIN64 */

#define SIG_ATOMIC_MIN	INT32_MIN
#define SIG_ATOMIC_MAX	INT32_MAX

#ifndef SIZE_MAX
#ifdef _WIN64
#define SIZE_MAX		UINT64_MAX
#else /* _WIN64 */
#define SIZE_MAX		UINT32_MAX
#endif /* _WIN64 */
#endif /* SIZE_MAX */

#define WINT_MIN	0x0000
#define WINT_MAX	0xffff

#define INT64_MIN	(-0x7fffffffffffffff - _C2)
#define INT64_MAX	0x7fffffffffffffff
#define UINT64_MAX	0xffffffffffffffffU

#define INT_LEAST64_MIN	(-0x7fffffffffffffff - _C2)
#define INT_LEAST64_MAX	0x7fffffffffffffff
#define UINT_LEAST64_MAX	0xffffffffffffffffU

#define INT_FAST64_MIN		(-0x7fffffffffffffff - _C2)
#define INT_FAST64_MAX		0x7fffffffffffffff
#define UINT_FAST64_MAX	0xffffffffffffffffU

#define INTMAX_MIN		(-0x7fffffffffffffff - _C2)
#define INTMAX_MAX		0x7fffffffffffffff
#define UINTMAX_MAX	0xffffffffffffffffU

#define INT64_C(x)		((x) + (INT64_MAX - INT64_MAX))
#define UINT64_C(x)		((x) + (UINT64_MAX - UINT64_MAX))
#define INTMAX_C(x)		INT64_C(x)
#define UINTMAX_C(x)	UINT64_C(x)

#else
#include <stdint.h>
#endif