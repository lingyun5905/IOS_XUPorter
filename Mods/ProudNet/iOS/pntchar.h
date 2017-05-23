/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 177 92 124 113 87 79 17 155 171 239 138 133 88 235 28 112 146 102 93 52 214 131 240 31 138 179 248 115 127 118 107 31 112 91 111 14 243 1 121 131 22 69 144 19 214 101 65 133 253 32 122 175 12 198 63 134 23 240 109 90 59 142 194 194 160 148 139 101 68 220 217 181 32 240 36 47 59 74 18 182 145 116 17 29 255 115 236 11 29 111 122  */
//////////////////////////////////////////////////////////////////////////
/* Win32, Marmalade������ char = MBS, wchar_t = UTF16�Դϴ�. [1]
������ iOS, Android,Linux ����� char = UTF8, wchar_t = UTF32�Դϴ�. [2]
�̷��� �� ������ [1]������ wchar_t��, [2]������ char�� ��ȣ�մϴ�.
ProudNet�� [1] �÷��������� wchar_t��, [2] �÷��������� char�� ����ϴ� API�� �����մϴ�.
���� ����� ���α׷��� [1]�� [2]���� ��� �������� ���尡 �Ǿ�� �Ѵٸ�, �Ʒ� ���ǵ� �͵��� ����ϼž� �� ���Դϴ�. */

#pragma once 

#ifdef _MSC_VER
#pragma pack(push,8)
#endif


#if defined(_WIN32) || defined(__MARMALADE__)
#define _PNUNICODE
#endif //defined(_WIN32) || defined(__MARMALADE__)

#define __PNSTR2WSTR(str)	L## str
#define _PNSTR2WSTR(str)	__PNSTR2WSTR(str)

// PNTCHAR=char�� ����Ǵ��� �� define�� �����ؾ� �Ѵ�.
// ����: ������ �̰��� ���� �� ��. String ��ȯ ������ ������. 
#ifndef __FUNCTIONW__
#define __FUNCTIONW__		(StringA2W(__FUNCTION__).GetString())

//#define __FUNCTIONW__		_PNSTR2WSTR(__FUNCTION__) 
//  ��Ÿ���Ե� PS4���� ������ L__FUNCTION__ �� ���ٴ� ������ ����. ���� �� ���� ����. ���� ���������� ������ ����� �뵵�ε�.

#endif

#ifndef __FILEW__
//#define __FILEW__		_PNSTR2WSTR(__FILE__)
#define __FILEW__		(StringA2W(__FILE__).GetString())
#endif

// NOTE: ���� �� define�� ������ ����Ű�� �־��� ��� ���� �����ϰ� ������ ����.
// iOS, Android, Linux���� ���� �� �����Ϸ����� __FUNCTION__�� char ���ڿ��� ġȯ �˴ϴ�. �����ڵ� ������� ���̺귯���� �����ϰ� �Ǹ� char -> wchar_t�� ��������� ��ȯ�� ���־�� �մϴ�.

#if defined(_PNUNICODE) // NOTE: UE4�� ��� ����Ͽ����� PNTCHAR = wchar_t�̴�. ���� �̰��� �־�� �Ѵ�.

#define _PNT(x) L##x
#define Tprintf wprintf
#define Tsscanf swscanf
#define Tsprintf swprintf
#define Tstrlen wcslen
#define Tstrcmp wcscmp
#define Tstricmp wcsicmp
#define Tstrcpy wcscpy
#define Tofstream ::std::wofstream 
#define Tstringstream ::std::wstringstream 
typedef wchar_t PNTCHAR;

// ����: ������ �̰��� ���� �� ��. String ��ȯ ������ ������. 
#define __FUNCTIONT__ __FUNCTIONW__

// filesys.h ������
#ifndef TSTRING
#define TSTRING std::wstring
#endif // TSTRING

#else // linux, mac, ...

#define _PNT(x) x
#define Tprintf printf
#define Tsprintf sprintf
#define Tsscanf sscanf
#define Tstrlen strlen
#define Tstrcmp strcmp
#define Tstricmp stricmp
#define Tstrcpy strcpy
#define Tofstream std::ofstream
#define Tstringstream std::stringstream 
typedef char PNTCHAR;

#define __FUNCTIONT__ __FUNCTION__

// filesys.h ������
#ifndef TSTRING
#define TSTRING std::string
#endif

#endif
#ifdef _MSC_VER
#pragma pack(pop)
#endif