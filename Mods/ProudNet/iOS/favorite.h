/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 177 92 124 113 87 79 17 155 171 239 138 133 88 235 28 112 146 102 93 52 214 131 240 31 138 179 248 115 127 118 107 31 112 91 111 14 243 1 121 131 22 69 144 19 214 101 65 133 253 32 122 175 12 198 63 134 23 240 109 90 59 142 194 194 160 148 139 101 68 220 217 181 32 240 36 47 59 74 18 182 145 116 17 29 255 115 236 11 29 111 122  */
/*
ProudNet 1.7.34387-dev003-10


ÀÌ ÇÁ·Î±×·¥ÀÇ ÀúÀÛ±ÇÀº ³İÅÙ¼Ç¿¡°Ô ÀÖ½À´Ï´Ù.
ÀÌ ÇÁ·Î±×·¥ÀÇ ¼öÁ¤, »ç¿ë, ¹èÆ÷¿¡ °ü·ÃµÈ »çÇ×Àº º» ÇÁ·Î±×·¥ÀÇ ¼ÒÀ¯±ÇÀÚ¿ÍÀÇ °è¾àÀ» µû¸£¸ç,
°è¾àÀ» ÁØ¼öÇÏÁö ¾Ê´Â °æ¿ì ¿øÄ¢ÀûÀ¸·Î ¹«´Ü »ç¿ëÀ» ±İÁöÇÕ´Ï´Ù.
¹«´Ü »ç¿ë¿¡ ÀÇÇÑ Ã¥ÀÓÀº º» ÇÁ·Î±×·¥ÀÇ ¼ÒÀ¯±ÇÀÚ¿ÍÀÇ °è¾à¼­¿¡ ¸í½ÃµÇ¾î ÀÖ½À´Ï´Ù.

** ÁÖÀÇ : ÀúÀÛ¹°¿¡ °üÇÑ À§ÀÇ ¸í½Ã¸¦ Á¦°ÅÇÏÁö ¸¶½Ê½Ã¿À.


This program is soley copyrighted by Nettention.
Any use, correction, and distribution of this program are subject to the terms and conditions of the License Agreement.
Any violated use of this program is prohibited and will be cause of immediate termination according to the License Agreement.

** WARNING : PLEASE DO NOT REMOVE THE LEGAL NOTICE ABOVE.


ó®ïïßíîÜ÷ú??NettentionÍëŞÉá¶êó¡£
?ó®ïïßíîÜáóËÇ¡¢ŞÅéÄ¡¢?øÖßÓ?îÜŞÀ?é©ñåáúó®ïïßíîÜá¶êó?íºîÜ??¡£
Üôñåáú???é©ê«?àõîÜĞ×ò­ôºí»ŞÅéÄ¡£
ôºí»ŞÅéÄîÜ?ìòÙ¥ãÆî¤?ó®ïïßíá¶êó?íºîÜùêÔÒ?×ì¡£

** ñ¼ëò£ºÜôé©ì¹ğ¶?éÍğ¤íÂÚªîÜß¾âûÙ¥ãÆ¡£


ª³ªÎ«×«í«°«é«àªÎîÊíÂ?ªÏNettentionªËª¢ªêªŞª¹¡£
ª³ªÎ«×«í«°«é«àªÎáóïá¡¢ŞÅéÄ¡¢ÛÕøÖªË?ª¹ªëŞÀú£ªÏÜâ«×«í«°«é«àªÎá¶êó?íºªÈªÎÌøå³ªË?ª¤¡¢
Ìøå³ªòñåáúª·ªÊª¤íŞùê¡¢ê«öÎîÜªËÙí?ŞÅéÄªòĞ×ª¸ªŞª¹¡£
Ùí?ŞÅéÄªËªèªëô¡ìòªÏÜâ«×«í«°«é«àªÎá¶êó?íºªÈªÎÌøå³ßöªËÙ¥ãÆªµªìªÆª¤ªŞª¹¡£

** ñ¼ëò£ºîÊíÂÚªªË?ª¹ªëß¾ÑÀªÎÙ¥ãÆªòğ¶ËÛª·ªÊª¤ªÇª¯ªÀªµª¤¡£

*/

/**
\~korean
Áñ°Ü ¾²´Â Çì´õ ÆÄÀÏµéÀ» ¸ğÀº ÆÄÀÏÀÌ´Ù.
ProudNetÀ» ¾²±â À§ÇØ¼­ ¹İµå½Ã #includeÇØ¾ß ÇÏ´Â ÆÄÀÏÀº ¾Æ´Ï´Ù.

\~english
A collection of favorite header files.
There is no must need to #include this file when using ProudNet.

\~chinese
ãÀßÈéÄ?ÙşËìîÜâ¥íúÙşËì¡£
?ÜôãÀŞÅéÄProudNetá¶ù±?é©#include îÜÙşËì¡£

\~japanese
ªª?ªËìıªêªÎ«Ø«Ã«À?«Õ«¡«¤«ëªòó¢ªáª¿«Õ«¡«¤«ëªÇª¹¡£
ProudNetªòŞÅª¦ª¿ªáªËªÏù±ªº#includeª¹ªÙª­«Õ«¡«¤«ëªÇªÏª¢ªêªŞª»ªó¡£
\~
*/

#pragma once


#if defined(_WIN32)
#include <assert.h>
#include <algorithm>
//#include <comdef.h> ¼­¹ö¿¡¼­¸¸ ¾²ÀÚ. UE4 ¶§¹®¿¡ Å¬¶ó´Â ¾²¸é ¾ÈµÊ.
#include <conio.h>
#include <conio.h>
#include <crtdbg.h>
#include <ctype.h>
#include <deque>
#include <dimm.h>
#include <direct.h>
#include <exception>
#include <float.h>
#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <mbstring.h>
#include <memory.h>
#include <mmreg.h>
#include <WinSock2.h>
#include <mmsystem.h>
//#include <new>
#include <oleauto.h>
#include <process.h>
#include <queue>
//#include <rpcdce.h> UE4 ºñÈ£È¯µÇ¹Ç·Î »èÁ¦
#include <set>
#include <shellapi.h>
#include <sstream>
#include <stack>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
//#include <string>
#include <tchar.h>
#include <time.h>
#include <unknwn.h>
#include <usp10.h>
#include <utility>
#include <vector>
#include <wincrypt.h>
#include <windows.h>
#include <windowsx.h>
#include <wininet.h>
#include <winsock2.h>
#include <xmemory>
#endif
