/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 177 92 124 113 87 79 17 155 171 239 138 133 88 235 28 112 146 102 93 52 214 131 240 31 138 179 248 115 127 118 107 31 112 91 111 14 243 1 121 131 22 69 144 19 214 101 65 133 253 32 122 175 12 198 63 134 23 240 109 90 59 142 194 194 160 148 139 101 68 220 217 181 32 240 36 47 59 74 18 182 145 116 17 29 255 115 236 11 29 111 122  */
#pragma once 

#include "pnguid.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

#if defined(_WIN32) 

// 주의: UE4 project에서는 include하지 말 것! 빌드 오류난다.
#pragma comment(lib,"rpcrt4.lib")
#pragma comment(lib,"winmm.lib")


namespace Proud
{
	/** helper functions for win32 GUID to Proud.Guid. */
	class Win32Guid
	{
	public:
		/** creates a new unique ID. */
		PROUD_API static Guid NewGuid();

		/** gets data from Win32 UUID data. */
		static Guid From(UUID src);

		/** outputs Win32 UUID data. */
		static UUID ToNative(Guid src);
	};
}

#endif // _WIN32
#ifdef _MSC_VER
#pragma pack(pop)
#endif