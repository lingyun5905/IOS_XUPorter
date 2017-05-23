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

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud 
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif

	/* a,b�� ����Ű�� �ΰ��� int32 �迭�� ��� ���θ� �Ǻ��Ѵ�.
	memcmp(a,b,16)�� ���� ������ �Ѵ�. �ٸ� ũ�Ⱑ ���� ��� �̰��� �� ���� �ӵ��� ���� �̰��� �� ���� �ִ�.
	�迭 ũ�Ⱑ ���ø� ���ڶ� loop unroll ����ȭ�� �̷������.
	#TODO �ƴҼ��� �ִ�. compiler�� �˾Ƽ� 16����Ʈ ���� ũ���
	intrinsic level�� ����ȭ�� �ڵ尡 ���� �� �ִ�.
	�ϴ��� ���������� ������ ���� üũ�ؼ� �� �Լ��� �������� �����ϴ��� ����. */
	template<int LENGTH> 
	int CompareInt32Array(const void* a, const void* b)
	{
		const int32_t* a2 = (const int32_t*)a;
		const int32_t* b2 = (const int32_t*)b;
		for (int i = 0; i < LENGTH; i++)
		{
			int c = (*a2) - (*b2);
			if (c != 0)
				return c;
			a2++;
			b2++;
		}
		// ������ �� ���ص� �����ϴ�.
		return 0;
	}



	// ���� ũ���� �����Ϳ� ���� memcpy. memcpy ��ü�� ���������� SIMD ����ȭ�� ������ CPU ��Ȳ�̶���� ���������� �˾ƺ��� �ڽ�Ʈ�� ũ��.
	// ������ ���� ũ��� �̰� �� ����.
	inline void SmallMemcpy(uint8_t*dst, const uint8_t*src, size_t size)  
	{
		static const size_t sizetSize = sizeof(size_t);

		size_t i;

#if defined(_WIN64) || defined(__LP64__)
		assert(sizetSize == 8);
		size_t pad = size & 7; // X mod 8�� ���� ����
		size_t blsize = size >> 3; // X / 8 �� ���� ����
#else
		assert(sizetSize == 4);
		size_t pad = size & 3; // X mod 8�� ���� ����
		size_t blsize = size >> 2; // X / 8 �� ���� ����
#endif
		for (i = 0; i < blsize; i++)
		{
			*(size_t*)dst = *(size_t*)src;
			dst += sizetSize;
			src += sizetSize;
		}
		for (i = 0; i < pad; i++)
		{
			*(uint8_t *)dst = *(uint8_t *)src;
			dst++;
			src++;
		}
	}

	inline void UnsafeFastMemmove(void *dest,const void* src,size_t length)
	{
		// array.add���� length=0�� ��찡 ���.
		if(length==0)
			return;

		// memmove_s�� memcpy_s�� memmove, memcpy���� �ξ� ������. �������� �ٿ�� üũ�� �������� zeromem ó���� �ֱ� �����̴�.
		// ���� �̰� �׳� ����.
		// ���Ŀ��� AMD64,IA64,Itanium,Win32�� ���� ��� ��ƾ�� ���� ����� ���� �� ��������.
		memmove(dest,src,length);
	}

// sysutil.cpp�� �̰� �� ������ ����Ǿ� ����
// Steam OS���� �����3���� ũ���� �̽��� ���� Unsafememcopy ��� ��Ȱ��ȭ �ϵ��� USE_UnsafeFastMemcpy define �ּ� ó��
//#define USE_UnsafeFastMemcpy

#ifdef USE_UnsafeFastMemcpy

	inline void UnsafeFastMemcpy(void *dest, const void* src, size_t length)
	{
		// array.add���� length=0�� ��찡 ���.
		if ( length == 0 )
			return;

#if defined(__MARMALADE__) || defined(__ANDROID__) || defined(__arm__) // RVCT�� ���� ��� __packed keyword�� ���� ������ gcc�� ���Ƿ� 
		memcpy(dest,src,length);
		// memmove_s�� memcpy_s�� memmove, memcpy���� �ξ� ������. �������� �ٿ�� üũ�� �������� zeromem ó���� �ֱ� �����̴�.
		// ���� �̰� �׳� ����.
		// ���Ŀ��� AMD64,IA64,Itanium,Win32�� ���� ��� ��ƾ�� ���� ����� ���� �� ��������.
#else
		if ( length <= 256 ) // 32���� ����. memcpy�� ȣ���ϴ� ������ �����ؼ� ������ �÷���.
			SmallMemcpy((uint8_t*)dest, (uint8_t*)src, length);
		else
			memcpy(dest, src, length);
#endif
	}

#else 

#	define UnsafeFastMemcpy memcpy 

#endif

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif

}

#ifdef _MSC_VER
#pragma pack(pop)
#endif