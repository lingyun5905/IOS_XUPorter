/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 177 92 124 113 87 79 17 155 171 239 138 133 88 235 28 112 146 102 93 52 214 131 240 31 138 179 248 115 127 118 107 31 112 91 111 14 243 1 121 131 22 69 144 19 214 101 65 133 253 32 122 175 12 198 63 134 23 240 109 90 59 142 194 194 160 148 139 101 68 220 217 181 32 240 36 47 59 74 18 182 145 116 17 29 255 115 236 11 29 111 122  */
#pragma once 

#ifndef _WIN32
//#include <alloca.h>
#endif

/* ����: _MALLOCA, _FREEA�� ����
�� �Լ����� ���ÿ� ����� ������ ������ ���ÿ� �Ҵ���, �׷��� ������ heap�� �Ҵ��� �Ѵ�.
�� �ſ� ���� ũ�Ⱑ �ƴ� �̻� heap�� �Ҵ��ϴ� ������ �Ѵ�. �� ���� ���к��ٴ� ������ ���ϵǴ��� heap�� �׼����ϴ� ���̴�.
���� ����� �Ҵ��ϰ��� �ϴ� ũ�Ⱑ ū ��찡 ���� ��� �� �Լ��� �׻� heap�� �׼����� ���̴�. �� ������ ������ ���� ���Ѵ�.
�̷��� ��쿡�� _MALLOCA ��� object pooling�� �϶�. ���� Proud.CPooledArrayObjectAsLocalVar�� ���� ���� �ξ� ����.

*/

/* _malloca�� ���� ũ������ heap access�� �ع�����. �׷��� win32���� ������ ũ�� �����Ѵ�. 
���� TLS ��� obj-pool�� ����. �ƹ�ư �����ϸ� �׳� _alloca�� ����, _malloc�� ������. 
���� �ſ� ���� ũ�⿡ ���ؼ� ��� �ϰڰ�.
*/
#if 0 

#if !defined(_WIN32)
#define _MALLOCA alloca
#define _FREEA(...) 
#else
#if (_MSC_VER>=1400)
#define _MALLOCA _malloca
#define _FREEA _freea
#else
#define _MALLOCA _alloca
#define _FREEA __noop
#endif
#endif

#else  // 0

#	ifndef _WIN32
#		define _MALLOCA alloca
#		define _FREEA(...) 
#	else 
#		define _MALLOCA _alloca
#		define _FREEA 
#	endif

#endif  // 1

/* ���ÿ� C++ ��ü�� �Ҵ�/�����ϴ� ��ũ��.

���ǻ���:
���ÿ� �ʹ� ū ũ�⸦ �Ҵ����� �� ��. �����̶�� �� ��ü�� �뷮 ���ڶ�� �� ���� ȯ���̱� �����̴�.
������ win32 _malloca������ 1KB �̻��� �׳� heap �Ҵ��� ������. 
1KB �̸��� ���� ũ�Ⱑ �ƴ϶�� NEW_ON_STACK�̳� _MALLOCA ��� POOLED_LOCAL_VAR�� �� ��.

��뿹:
int arrayLength;
NEW_ON_STACK(array, MyType, arrayLength);

...

FREE_ON_STACK(array);


*/

#define NEW_ON_STACK(VARNAME, TYPE, LENGTH) \
	TYPE* VARNAME = (TYPE*)_MALLOCA(sizeof(TYPE) * LENGTH); \
	CallConstructors(VARNAME, LENGTH); 

#define FREE_ON_STACK(VARNAME, LENGTH) \
	CallDestructors(VARNAME, LENGTH); \
	_FREEA(VARNAME);
