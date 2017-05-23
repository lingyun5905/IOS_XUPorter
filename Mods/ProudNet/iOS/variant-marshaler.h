/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 177 92 124 113 87 79 17 155 171 239 138 133 88 235 28 112 146 102 93 52 214 131 240 31 138 179 248 115 127 118 107 31 112 91 111 14 243 1 121 131 22 69 144 19 214 101 65 133 253 32 122 175 12 198 63 134 23 240 109 90 59 142 194 194 160 148 139 101 68 220 217 181 32 240 36 47 59 74 18 182 145 116 17 29 255 115 236 11 29 111 122  */
#pragma once 

#include "Variant.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	class CMessage;
	class CVariant;

#if defined(_WIN32)    
	CMessage& operator<<(CMessage &a, const CVariant &b);
	CMessage& operator>>(CMessage &a, CVariant &b);

	void AppendTextOut(String &a, const CVariant &b);
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif