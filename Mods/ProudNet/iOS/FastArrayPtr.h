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

#include "Ptr.h"
#include "ExternalBufferArray.h"
#include "FastArray.h"

#if !defined(_WIN32)
   #include "atomic.h"
#else
    #include <vector>
#endif

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4324)
#pragma warning(disable:4290)
#pragma pack(push,8)
#endif 

namespace Proud
{
	/** \addtogroup util_group
	*  @{
	*/

	PROUD_API extern const char* ArrayPtrIsNullError;
	PROUD_API extern const char* ArrayPtrIsNotNullError;
	PROUD_API extern const char* MustInternalBufferError;
	PROUD_API extern const char* MustNotExternalBufferError;
	PROUD_API extern const char* MustUnsafeInternalBufferError;
	PROUD_API extern const char* AlreadyHasInternalBufferError;
	PROUD_API extern const char* AlreadyHasUnsafeInternalBufferError;
	PROUD_API extern const char* AlreadyHasExternalBufferError;

	// VC++���� unreachable code ��� ���� _Noreturn�� ����. �� ���� ��� ������?
	PROUD_API /*_Noreturn*/ void ThrowArrayIsNullError();

	/**  @} */
}


#ifdef _MSC_VER
#pragma pack(pop)
#pragma warning(pop)
#endif // __MARMALADE__
