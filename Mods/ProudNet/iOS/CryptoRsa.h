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

#pragma once

#include "Enums.h"
#include "FastArray.h"
#include "ErrorInfo.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

typedef struct Rsa_key rsa_key;

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif
	/** \addtogroup util_group
	*  @{
	*/

	/** 
	\~korean
	RSA Key µ¥ÀÌÅÍ Å¬·¡½º ÀÔ´Ï´Ù.

	\~english
	RSA Key data class.

	\~chinese
	RSA Key?Ëß?¡£

	\~japanese
	RSA Key «Ç?«¿«¯«é«¹ªÇª¹¡£
	\~
	*/
	class CCryptoRsaKey
	{
	public:

		/** RSA Key */
		Rsa_key *m_key;

		CCryptoRsaKey();
		~CCryptoRsaKey();

		/** 
		\~korean
		ByteArray ·Î ÀÌ·ç¾îÁø °ø°³Å°¸¦ CRsaKey ·Î Import ÇÕ´Ï´Ù.
		\param blob CRsaKey ¿¡¼­ »Ì¾ÆÁø ByteArray °ø°³Å° 

		\~english
		Import public key with CRsaKey that made with ByteArray.
		\param blob ByteArray public key delegated from CRsaKey

		\~chinese
		ë¦ ByteArray%?à÷îÜÍë?key import? CRsaKey%¡£
		\param blob ? CRsaKey%?îÜ ByteArray%Íë?key¡£

		\~japanese
		ByteArrayª«ªéªÊªëÍëËÒ«­?ªòCRsaKeyªÇImportª·ªŞª¹¡£
		\param blob CRsaKeyªèªêàÔªéªìª¿ByteArrayÍëËÒ«­? 
		\~
		*/
		PROUD_API bool FromBlob(const ByteArray& blob);

		/** 
		\~korean
		CRsaKey ¿¡¼­ °ø°³Å°¸¦ ByteArray ·Î »Ì¾Æ³À´Ï´Ù.
		\param outBlob Å°¿¡¼­ »Ì¾Æ³½ °ø°³Å°ÀÇ ByteArray ÀÔ´Ï´Ù. 

		\~english
		Delegate public key with ByteArray from CRsaKey.
		\param outBlob ByteArray of public key that delegated from key.

		\~chinese
		? CRsaKey%?Íë?key? ByteArray¡£
		\param outBlob ?key?îÜÍë?keyîÜ ByteArray%¡£

		\~japanese
		CrsaKeyªèªêÍëËÒ«­?ªòByteArrayªÇìÚª­ö¢ªêªŞª¹¡£
		\param outBlob «­?ªèªêìÚª­ö¢ªÃª¿ÍëËÒ«­?ªÎByteArrayªÇª¹¡£ 
		\~
		*/
		PROUD_API bool ToBlob(ByteArray &outBlob);

		/** Same to ToBlob(), but it outputs private key.*/
		PROUD_API bool ToBlob_privateKey(ByteArray &outBlob);
	private:
		bool ToBlob_internal(ByteArray &outBlob, int keyType);
	public:

		operator Rsa_key*() 
 		{
 			return m_key;
 		}

#ifdef _WIN32
#pragma push_macro("new")
#undef new
		// ÀÌ Å¬·¡½º´Â ProudNet DLL °æ¿ì¸¦ À§ÇØ Ä¿½ºÅÒ ÇÒ´çÀÚ¸¦ ¾²µÇ fast heapÀ» ¾²Áö ¾Ê´Â´Ù.
		DECLARE_NEW_AND_DELETE
#pragma pop_macro("new")
#endif

	};

	typedef RefCount<CCryptoRsaKey> CRsaKeyPtr;

	/** 
	\~korean
	RSA °ø°³Å°, ºñ°ø°³Å° ¾ÏÈ£È­ Å¬·¡½º 

	\~english
	Encryption class of RSA publick key, private key

	\~chinese
	RSAÍë?key£¬ŞªÍë?keyîÜÊ¥ÚË?¡£

	\~japanese
	RSAÍëËÒ«­?¡¢ŞªÍëËÒ«­?äŞ?ûù«¯«é«¹
	\~
	*/
	class CCryptoRsa
	{
	public:
		/** 
		\~korean
		Random Block À» »ı¼ºÇÕ´Ï´Ù.
		\param output »ı¼ºµÉ ·£´ıºí·°ÀÇ ByteArray ÀÔ´Ï´Ù.
		\param length »ı¼ºÇÒ ·£´ıºí·°ÀÇ ±æÀÌÀÔ´Ï´Ù. 
		\return ·£´ıºí·° »ı¼º¿¡ ¼º°øÇÏ¸é true¸¦ ¸®ÅÏÇÏ°í, ½ÇÆĞÇÏ¸é false ¸®ÅÏÇÕ´Ï´Ù.

		\~english TODO:translate needed.
		Generate a random block.
		\param output This is the ByteArray of the random block to be generated. 
		\param length This is the length of the random block to be generated. 
		\return true if successful in generating a random block or otherwise return false. 

		\~chinese
		ßæà÷Random Block¡£
		\param output é©ßæà÷îÜ?ÏõblockîÜ ByteArray%¡£
		\param length é©ßæà÷îÜ?ÏõblockîÜ?Óø¡£ 
		\return à÷Ííßæà÷?ÏõblockîÜ?Ú÷üŞtrue£¬ã÷?îÜ?Ú÷üŞfalse¡£

		\~japanese
		Random Blockªòßæà÷ª·ªŞª¹¡£
		\param output ßæà÷ªµªìªë«é«ó«À«à«Ö«í«Ã«¯ªÎByteArrayªÇª¹¡£
		\param length ßæà÷ª¹ªë«é«ó«À«à«Ö«í«Ã«¯ªÎíşªµªÇª¹¡£ 
		\return «é«ó«À«à«Ö«í«Ã«¯ªÎßæà÷ªËà÷Ííª¹ªëªÈtrueªò«ê«¿?«óª·ªÆ¡¢ã÷ø¨ª¹ªëªÈfalseªò«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		PROUD_API static bool CreateRandomBlock(ByteArray &output, int length);

		/** 
		\~korean
		RSA °ø°³Å°¿Í ºñ°ø°³Å°¸¦ »ı¼ºÇÕ´Ï´Ù.
		\param outXchgKey »ı¼ºµÉ RSA Å° ÀÔ´Ï´Ù.
		\param outPubKeyBlob »ı¼ºµÉ RSA Å°¿¡¼­ export µÈ °ø°³Å°ÀÇ ByteArray °ªÀÔ´Ï´Ù. 
		\return Å° »ı¼º¿¡ ¼º°øÇÏ¸é true¸¦ ¸®ÅÏÇÏ°í, ½ÇÆĞÇÏ¸é false ¸®ÅÏÇÕ´Ï´Ù.

		\~english TODO:translate needed.
		Generate a public key and a private key. 
		\param outXchgKey This is an RSA key to be generated
		\param outPubKeyBlob This is the value of ByteArray of a public key exported from the RSA key to be generated. 
		\return true if successful in generating a key or otherwise return false.

		\~chinese
		ßæà÷RSAÍë?keyûúŞªÍë?key¡£
		\param outXchgKey é©ßæà÷îÜRSA key¡£
		\param outPubKeyBlob ?é©ßæà÷îÜRSA keyñéexportîÜÍë?keyîÜ ByteArray%?¡£ 
		\return à÷Ííßæà÷keyîÜ?Ú÷üŞtrue£¬ã÷?îÜ?Ú÷üŞfalse¡£

		\~japanese
		RSAÍëËÒ«­?ªÈŞªÍëËÒ«­?ªòßæà÷ª·ªŞª¹¡£
		\param outXchgKey ßæà÷ªµªìªëRSA«­?ªÇª¹¡£
		\param outPubKeyBlob ßæà÷ªµªìªëRSA«­?ªèªêexportªµªìª¿ÍëËÒ«­?ªÎByteArrayö·ªÇª¹¡£
		\return «­?ªÎßæà÷ªËà÷Ííª¹ªëªÈtrueªò«ê«¿?«óª·ªÆ¡¢ã÷ø¨ª¹ªëªÈfalseªò«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		PROUD_API static bool CreatePublicAndPrivateKey(CCryptoRsaKey &outXchgKey, ByteArray &outPubKeyBlob);

		/** 
		\~korean
		°ø°³Å°·Î ºí·°À» ¾ÏÈ£È­ÇÕ´Ï´Ù.
		- randomBlock ÀÇ »çÀÌÁî°¡ key ÀÇ Modulus N ÀÇ °ªº¸´Ù ÃÊ°úÇÏ¸é Encrypt¸¦ ÇÒ ¼ö ¾ø½À´Ï´Ù. 
		\param outEncryptedSessionKey ¾ÏÈ£È­ µÉ ·£´ıºí·°ÀÔ´Ï´Ù.
		\param randomBlock ¾ÏÈ£È­ ÇÒ ·£´ıºí·°ÀÔ´Ï´Ù.
		\param publicKeyBlob RSA °ø°³Å°ÀÔ´Ï´Ù.
		\return °ø°³Å°·Î ¾ÏÈ£È­µÈ ´ëÄªÅ°¸¦ ¾ò´Âµ¥ ¼º°øÇÏ¸é true¸¦ ¸®ÅÏÇÏ°í, ½ÇÆĞÇÏ¸é false ¸®ÅÏÇÕ´Ï´Ù.

		\~english TODO:translate needed.
		Encode the block with the public key
		- If the size of randomBlock exceeds the Modulus N value of the key, you cannot do encryption. 
		\param outEncryptedSessionKey This is the random block to be encrypted.
		\param randomBlock This is the random block you will encrypt. 
		\param publicKeyBlob  This is the RSA public key. 
		\return true if successful in obtaining an encrypted symmetric key with the public key or otherwise return false. 

		\~chinese
		éÄÍë?keyÊ¥ÚËblock¡£
		- randomBlockîÜÓŞá³õ±?keyîÜModulus NîÜ?îÜ?ÜôÒöEncrypt¡£
		\param outEncryptedSessionKey é©ù¬Ê¥ÚËîÜ?Ïõblock¡£
		\param randomBlock é©Ê¥ÚËîÜ?Ïõblock¡£
		\param publicKeyBlob RSAÍë?key¡£
		\return éÄÍë?key?ÔğÊ¥ÚËîÜ??keyà÷ÍíîÜ?Ú÷üŞtrue£¬ã÷?îÜ?Ú÷üŞfalse¡£
		
		\~japanese
		ÍëËÒ«­?ªÇ«Ö«í«Ã«¯ªòäŞ?ûùª·ªŞª¹¡£
		- randomBlock ªÎ«µ«¤«ºª¬«­?ªÎModulus NªÎö·ªòõ±Î¦ª¹ªëªÈEncryptª¬ªÇª­ªŞª»ªó¡£
		\param outEncryptedSessionKey äŞ?ûùªµªìªë«é«ó«À«à«Ö«í«Ã«¯ªÇª¹¡£
		\param randomBlock äŞ?ûùª¹ªë«é«ó«À«à«Ö«í«Ã«¯ªÇª¹¡£
		\param publicKeyBlob RSA ÍëËÒ«­?ªÇª¹¡£
		\return ÍëËÒ«­?ªÇäŞ?ûùªµªìª¿??«­?ªòÔğªëª³ªÈªËà÷Ííª¹ªëªÈtrueªò«ê«¿?«óª·ªÆ¡¢ã÷ø¨ª¹ªëªÈfalseªò«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		PROUD_API static bool EncryptSessionKeyByPublicKey(ByteArray &outEncryptedSessionKey, const ByteArray &randomBlock, const ByteArray &publicKeyBlob);

		/** 
		\~korean
		ºñ°ø°³Å°·Î ¾ÏÈ£È­µÈ ºí·°À» º¹È£È­ÇÕ´Ï´Ù.
		\param outRandomBlock º¹È£È­ ÇÒ ByteArray
		\param encryptedSessionKey ¾ÏÈ£È­µÈ ByteArray
		\param privateKey ºñ°ø°³Å°ÀÔ´Ï´Ù. 
		\return °³ÀÎÅ°·Î ¾ÏÈ£È­µÈ ´ëÄªÅ°¸¦ º¹È£È­ ÇÏ¿© ¾ò´Âµ¥ ½ÇÆĞÇÏ¸é ErrorInforPtrÀ» ¸®ÅÏÇÕ´Ï´Ù.

		\~english TODO:translate needed.
		Decode the encrypted block with the private key.
		\param outRandomBlock ByteArray to decrypt.
		\param encryptedSessionKey Encrypted ByteArray.
		\param privateKey This is a private key.
		\return When you fail to obtain an encrypted symmetric key with a private key, returns ErrorInforPtr. 

		\~chinese
		éÄŞªÍë?key÷ò?ù¬Ê¥ÚËîÜblock¡£
		\param outRandomBlock é©÷ò?îÜ ByteArray%¡£
		\param encryptedSessionKey Ê¥ÚËîÜ ByteArray%¡£
		\param privateKey ŞªÍë?key¡£
		\return éÄ?ìÑkey÷ò?ì«ù¬Ê¥ÚËîÜ??keyã÷?îÜ?Ú÷üŞErrorInforPtr¡£

		\~japanese
		ŞªÍëËÒ«­?ªÇäŞ?ûùªµªìª¿«Ö«í«Ã«¯ªòÜÖ?ûùª·ªŞª¹¡£
		\param outRandomBlock ÜÖ?ûùª¹ªë ByteArray
		\param encryptedSessionKey äŞ?ûùªµªìª¿ ByteArray
		\param privateKey ŞªÍëËÒ«­?ªÇª¹¡£ 
		\return ËÁìÑ«­?ªÇäŞ?ûùªµªìª¿??«­?ªòÜÖ?ûùª·ªÆÔğªëª³ªÈªËã÷ø¨ª¹ªëªÈ ErrorInforPtrªò«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		PROUD_API static ErrorInfoPtr DecryptSessionKeyByPrivateKey(ByteArray &outRandomBlock, const ByteArray &encryptedSessionKey, const CCryptoRsaKey &privateKey);
	};

	typedef uint16_t CryptCount;

	/**  @} */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif