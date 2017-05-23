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

#include "pnstdint.h"

// interlocked op ���� ��Ƽ�÷��� �ڵ��� ���ϰ� �ϰ��� ��. �� #ifdef ��ĥ�� ������.
#if defined(__MACH__) // mac,ios ����
    #include <libkern/OSAtomic.h>
#endif

#ifdef _MSC_VER
#pragma warning(disable:4800) // warning C4800: 's3eBool' : forcing value to bool 'true' or 'false' (performance warning)
#endif

#ifdef __MARMALADE__

//#include "ProudNetEDK.h"
/*
// ProudNetEDK.h���� �����ؿ���. ���� �������Դ� EDK���� #include�ϰ� �䱸�ϴ°� �����ϱ�.
// ���� �� �Լ��� prototype�� include�ϴ� ���� ���� �ҽ� cpp �ȿ� ����
int32 s3eAtomicIncrement32(int32* target);
int32 s3eAtomicDecrement32(int32* target);
s3eBool s3eAtomicCompareAndSwap(int32 oldValue, int32 newValue, int32* target);*/

#endif

#ifdef _MSC_VER
#pragma pack(push,8)
#endif


namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif

#ifdef UNTRUST_COMPILER_VOLATILE_ALIGN
	#ifdef _MSC_VER // VC++�迭�̸�
	#if defined(__LP64__) || defined(_WIN64)
	#define PROUDNET_VOLATILE_ALIGN __declspec(align(8)) volatile
	#else
	#define PROUDNET_VOLATILE_ALIGN  __declspec(align(4)) volatile
	#endif
	#else //�̿� �����Ϸ� �迭�̸�
	#if defined(__LP64__) || defined(_WIN64)
	#define PROUDNET_VOLATILE_ALIGN __attribute__((aligned(8))) volatile // TODO: ���� ����� �������� �׳� volatile�θ� �����ڷ�. ������ compiler ��ü�� align 8 or 4�ϲ�. (apple developer�� OSAtomicIncrement ��ü�� align4�̸� �ȴٰ� ��ť���� ���������� �� �Ͼ��)
	#else
	#define PROUDNET_VOLATILE_ALIGN __attribute__((aligned(4))) volatile
	#endif
	#endif
#else
	#define PROUDNET_VOLATILE_ALIGN volatile
#endif
// Marmalade �� atomic op ��ü�� �������� �ʴ� �÷��������� �������� �̷��� �۵��ؾ� ��
class CSlowAtomic
{
public:
	// ����: ���� ���� ��
	static int32_t Increment32(volatile int32_t *target);
	// ����: ���� ���� ��
	static int32_t Decrement32(volatile int32_t *target);
	// ����: ���� ���� ��
	static int32_t Exchange32(volatile int32_t *target, int32_t newValue);
	// ����: ���� ���� ��
	static int32_t CompareAndSwap(int32_t oldValue, int32_t newValue, volatile int32_t *target);

	// ����: ���� ���� ��
	static int32_t Swap(int32_t newValue, volatile int32_t *target);
};

	// atomic operation.
	// ����: �翬������, target�� volatile & 32 or 64bit align�� �Ǿ� �־�� �Ѵ�.
	// ����: ���� ���� ��
	inline int32_t AtomicIncrement32(volatile int32_t *target)
	{
#if defined(__MARMALADE__)
		return CSlowAtomic::Increment32(target);
		//return s3eAtomicIncrement32((int32*)target);
#elif defined(_WIN32)
		return InterlockedIncrement((volatile long*)target);
#else
		return __sync_add_and_fetch(target, 1);	// http://ecs.victoria.ac.nz/cgi-bin/info2www?%28gcc%29Atomic+Builtins �� ���ϸ� ���� ���� ��
#endif
	}

//#ifdef _WIN32
//	inline int32_t AtomicAdd32(volatile int32_t* target, int32_t value)
//	{
//		return InterlockedAdd((volatile long*)target, value);
//	}
//#endif

	// atomic operation.
	// ����: �翬������, target�� volatile & 32 or 64bit align�� �Ǿ� �־�� �Ѵ�.
	// ����: ���� ���� ��
	inline int32_t AtomicDecrement32(volatile int32_t *target)
	{
#if defined(__MARMALADE__)
		return CSlowAtomic::Decrement32(target);
#elif defined(_WIN32)
		return InterlockedDecrement((volatile long*)target);
#else
		return __sync_sub_and_fetch(target, 1);
#endif
	}

	// atomic operation.
	// ����: �翬������, target�� volatile & 32 or 64bit align�� �Ǿ� �־�� �Ѵ�.
	// ����: ���� ���� ��
	inline int32_t AtomicCompareAndSwap32(int32_t oldValue, int32_t newValue, volatile int32_t *target)
	{
#if defined(__MARMALADE__)
		return CSlowAtomic::CompareAndSwap(oldValue,newValue,target);
		//return (bool)s3eAtomicCompareAndSwap(oldValue, newValue, (int32*)target);
#elif defined(_WIN32)
		return InterlockedCompareExchange((volatile long*)target, newValue, oldValue);
#else
		return __sync_val_compare_and_swap(target, oldValue, newValue);
#endif
	}


#if defined(_WIN64) || defined(__LP64__)
	// atomic operation.
	// ����: �翬������, target�� volatile & 32 or 64bit align�� �Ǿ� �־�� �Ѵ�.
	// ����: ���� ���� ��
	inline int64_t AtomicIncrement64(volatile int64_t *target)
	{
#if defined(__MARMALADE__)
		#error No 64bit for Marmalde yet
#elif defined(_WIN64)
		return InterlockedIncrement64(target);
#else
		return __sync_add_and_fetch(target, 1);	// http://ecs.victoria.ac.nz/cgi-bin/info2www?%28gcc%29Atomic+Builtins �� ���ϸ� ���� ���� ��
#endif
	}

	// atomic operation.
	// ����: �翬������, target�� volatile & 32 or 64bit align�� �Ǿ� �־�� �Ѵ�.
	// ����: ���� ���� ��
	inline int64_t AtomicDecrement64(volatile int64_t *target)
	{
#if defined(__MARMALADE__)
		#error No 64bit for Marmalde yet
#elif defined(_WIN64)
		return InterlockedDecrement64(target);
#else
		return __sync_sub_and_fetch(target, 1);
#endif
	}

	// atomic operation.
	// ����: �翬������, target�� volatile & 32 or 64bit align�� �Ǿ� �־�� �Ѵ�.
	// ����: Ÿ�� �Ƕ������ �ʱⰪ
	inline int64_t AtomicExchange64(int64_t newValue, volatile int64_t *target)
	{
#if defined(__MARMALADE__)
		#error No 64bit for Marmalde yet
#elif defined(_WIN64)
		return InterlockedExchange64(target, newValue);
#else
		// *target ���� target �� ����Ű�� ���� ���ٸ� newValue �� target �� ����. �ƴϸ� �ƹ��� ������ ����
		return __sync_val_compare_and_swap(target, *target, newValue);
#endif
	}

	// atomic operation.
	// ����: �翬������, target�� volatile & 32 or 64bit align�� �Ǿ� �־�� �Ѵ�.
	// ����: ���� ���� ��
	inline int64_t AtomicCompareAndSwap64(int64_t oldValue, int64_t newValue, volatile int64_t *target)
	{
#if defined(__MARMALADE__)
		#error No 64bit for Marmalde yet
#elif defined(_WIN64)
		return InterlockedCompareExchange64(target, newValue, oldValue);
#else
		return __sync_val_compare_and_swap(target, oldValue, newValue);
#endif
	}

#endif // _WIN64 || __LP64

	// CPU�� 32bit�̰� 64bit�̰� ������� ���� �͵�, ���� object reference count ��� ����
	// NOTE:�������� `#define`�̾�����, OSX���� int32_t=int, intptr_t=long�̶� ������ ������ �߻��Ѵ�. �׷��� �̷��� �����ؼ� ������ ������ ����.
#if defined(_WIN64) || defined(__LP64__) // https://developer.apple.com/library/mac/#documentation/Darwin/Conceptual/64bitPorting/MakingCode64-BitClean/MakingCode64-BitClean.html ����
	// atomic operation.
	// ����: �翬������, target�� volatile & 32 or 64bit align�� �Ǿ� �־�� �Ѵ�.
	inline intptr_t AtomicIncrementPtr(volatile intptr_t *target)
	{
		return AtomicIncrement64((int64_t*)target);
	}

	// atomic operation.
	// ����: �翬������, target�� volatile & 32 or 64bit align�� �Ǿ� �־�� �Ѵ�.
	inline intptr_t AtomicDecrementPtr(volatile intptr_t *target)
	{
		return AtomicDecrement64((int64_t*)target);
	}

	inline void* AtomicCompareAndSwapPtr(void* oldValue, void* newValue, volatile void **target)
	{
		return (void*)AtomicCompareAndSwap64((int64_t)oldValue, (int64_t)newValue, (volatile int64_t*)target);
	}
#else
	// atomic operation.
	// ����: �翬������, target�� volatile & 32 or 64bit align�� �Ǿ� �־�� �Ѵ�.
	inline intptr_t AtomicIncrementPtr(volatile intptr_t *target)
	{
		return AtomicIncrement32((int32_t*)target);
	}

	// atomic operation.
	// ����: �翬������, target�� volatile & 32 or 64bit align�� �Ǿ� �־�� �Ѵ�.
	inline intptr_t AtomicDecrementPtr(volatile intptr_t *target)
	{
		return AtomicDecrement32((int32_t*)target);
	}

	inline void* AtomicCompareAndSwapPtr(void* oldValue, void* newValue, volatile void **target)
	{
		return (void*)AtomicCompareAndSwap32((int32_t)oldValue, (int32_t)newValue, (volatile int32_t*)target);
	}
#endif

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif

}

#ifdef _MSC_VER
#pragma pack(pop)
#endif