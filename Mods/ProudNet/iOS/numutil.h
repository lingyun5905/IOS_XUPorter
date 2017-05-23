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

#include "BasicTypes.h"
#include "quicksort.h"
#include "pnstdint.h" 

#if defined(_WIN32)
    #include <algorithm>
#endif

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup util_group
	*  @{
	*/

	/** 
	\~korean
	�� �� v1,v2�� v1->v2���� ���а� ratio�� ���Ѵ�.
	ratio�� 0�� �������� v1�� ������. 

	\~english
	Obtains a interior division ratio of two values of v1,v2, v1->v2.
	As ratio gets closer to 0, it gets closer to v1.

	\~chinese
	ϴ��???v1��v2��v1->v2��??ratio��
	Ration ������0��?������v1.

	\~japanese
	?��v1��v2��v1->v2�ت�?����ratio��ϴ��ު���
	ratio��0���ΪŪ��۪�v1���Ϊ��Ǫ���
	\~
	*/
	template<typename T>
	inline T Lerp(T v1, T v2, T ratio)
	{
		return v1 + (v2 - v1)*ratio;
	}


	/**
	\~korean
 	Lerp�� ������ ����. ratio�� ���ڴ� ratio1,�и�� ratio2

	\~english TODO:translate needed.
	Integer version of Lerp. Numerator of the ratio is ratio 1. Denominator is ratio 2. 

	\~chinese
	Lerp ����?�����⡣Ratio �������ratio1����ٽ��ratio2.

	\~japanese
	Lerp����?����?�����Ratio������ratio1����ٽ��ratio2
	\~
	*/
	template<typename T>
	inline T LerpInt(T v1, T v2,T ratio1, T ratio2)
	{
		return (v1 + ((v2 - v1)*ratio1)/ratio2);
	}

	/** 
	\~korean
	Round robin ���� ���� ������.

	\~english
	Round robin slot number generator 

	\~chinese
	Round robin ?�ˣ�slot��?�������

	\~japanese
	Round robin ����ë�?������
	\~
	*/
	class CRoundRobinNumberGenerator
	{
		int m_number;
	public:
		PROUD_API CRoundRobinNumberGenerator();

		PROUD_API int Next(int maxNumber);
	};
	/**  @} */

	// ��ó: http://www.java2s.com/Tutorial/Cpp/0260__template/Genericquicksort.htm

// 	template<typename T>
// 	inline void swap(T& v1,T& v2)
// 	{
// 		T temp=v2;
// 		v2=v1;
// 		v1=temp;
// 	}

}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
