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
	RSA Key ������ Ŭ���� �Դϴ�.

	\~english
	RSA Key data class.

	\~chinese
	RSA Key?��?��

	\~japanese
	RSA Key ��?�����髹�Ǫ���
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
		ByteArray �� �̷���� ����Ű�� CRsaKey �� Import �մϴ�.
		\param blob CRsaKey ���� �̾��� ByteArray ����Ű 

		\~english
		Import public key with CRsaKey that made with ByteArray.
		\param blob ByteArray public key delegated from CRsaKey

		\~chinese
		� ByteArray%?������?key import? CRsaKey%��
		\param blob ? CRsaKey%?�� ByteArray%��?key��

		\~japanese
		ByteArray����ʪ����ҫ�?��CRsaKey��Import���ު���
		\param blob CRsaKey����Ԫ�쪿ByteArray���ҫ�? 
		\~
		*/
		PROUD_API bool FromBlob(const ByteArray& blob);

		/** 
		\~korean
		CRsaKey ���� ����Ű�� ByteArray �� �̾Ƴ��ϴ�.
		\param outBlob Ű���� �̾Ƴ� ����Ű�� ByteArray �Դϴ�. 

		\~english
		Delegate public key with ByteArray from CRsaKey.
		\param outBlob ByteArray of public key that delegated from key.

		\~chinese
		? CRsaKey%?��?key? ByteArray��
		\param outBlob ?key?����?key�� ByteArray%��

		\~japanese
		CrsaKey������ҫ�?��ByteArray���ڪ�����ު���
		\param outBlob ��?����ڪ����ê����ҫ�?��ByteArray�Ǫ��� 
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
		// �� Ŭ������ ProudNet DLL ��츦 ���� Ŀ���� �Ҵ��ڸ� ���� fast heap�� ���� �ʴ´�.
		DECLARE_NEW_AND_DELETE
#pragma pop_macro("new")
#endif

	};

	typedef RefCount<CCryptoRsaKey> CRsaKeyPtr;

	/** 
	\~korean
	RSA ����Ű, �����Ű ��ȣȭ Ŭ���� 

	\~english
	Encryption class of RSA publick key, private key

	\~chinese
	RSA��?key��ު��?key��ʥ��?��

	\~japanese
	RSA���ҫ�?��ު���ҫ�?��?�����髹
	\~
	*/
	class CCryptoRsa
	{
	public:
		/** 
		\~korean
		Random Block �� �����մϴ�.
		\param output ������ �������� ByteArray �Դϴ�.
		\param length ������ �������� �����Դϴ�. 
		\return ������ ������ �����ϸ� true�� �����ϰ�, �����ϸ� false �����մϴ�.

		\~english TODO:translate needed.
		Generate a random block.
		\param output This is the ByteArray of the random block to be generated. 
		\param length This is the length of the random block to be generated. 
		\return true if successful in generating a random block or otherwise return false. 

		\~chinese
		����Random Block��
		\param output �������?��block�� ByteArray%��
		\param length �������?��block��?���� 
		\return ��������?��block��?����true����?��?����false��

		\~japanese
		Random Block���������ު���
		\param output ��������������֫�ë���ByteArray�Ǫ���
		\param length �������������֫�ë��������Ǫ��� 
		\return ������֫�ë����������������true��꫿?�󪷪ơ����������false��꫿?�󪷪ު���
		\~
		*/
		PROUD_API static bool CreateRandomBlock(ByteArray &output, int length);

		/** 
		\~korean
		RSA ����Ű�� �����Ű�� �����մϴ�.
		\param outXchgKey ������ RSA Ű �Դϴ�.
		\param outPubKeyBlob ������ RSA Ű���� export �� ����Ű�� ByteArray ���Դϴ�. 
		\return Ű ������ �����ϸ� true�� �����ϰ�, �����ϸ� false �����մϴ�.

		\~english TODO:translate needed.
		Generate a public key and a private key. 
		\param outXchgKey This is an RSA key to be generated
		\param outPubKeyBlob This is the value of ByteArray of a public key exported from the RSA key to be generated. 
		\return true if successful in generating a key or otherwise return false.

		\~chinese
		����RSA��?key��ު��?key��
		\param outXchgKey �������RSA key��
		\param outPubKeyBlob ?�������RSA key��export����?key�� ByteArray%?�� 
		\return ��������key��?����true����?��?����false��

		\~japanese
		RSA���ҫ�?��ު���ҫ�?���������ު���
		\param outXchgKey ���������RSA��?�Ǫ���
		\param outPubKeyBlob ���������RSA��?���export���쪿���ҫ�?��ByteArray���Ǫ���
		\return ��?���������������true��꫿?�󪷪ơ����������false��꫿?�󪷪ު���
		\~
		*/
		PROUD_API static bool CreatePublicAndPrivateKey(CCryptoRsaKey &outXchgKey, ByteArray &outPubKeyBlob);

		/** 
		\~korean
		����Ű�� ���� ��ȣȭ�մϴ�.
		- randomBlock �� ����� key �� Modulus N �� ������ �ʰ��ϸ� Encrypt�� �� �� �����ϴ�. 
		\param outEncryptedSessionKey ��ȣȭ �� �������Դϴ�.
		\param randomBlock ��ȣȭ �� �������Դϴ�.
		\param publicKeyBlob RSA ����Ű�Դϴ�.
		\return ����Ű�� ��ȣȭ�� ��ĪŰ�� ��µ� �����ϸ� true�� �����ϰ�, �����ϸ� false �����մϴ�.

		\~english TODO:translate needed.
		Encode the block with the public key
		- If the size of randomBlock exceeds the Modulus N value of the key, you cannot do encryption. 
		\param outEncryptedSessionKey This is the random block to be encrypted.
		\param randomBlock This is the random block you will encrypt. 
		\param publicKeyBlob  This is the RSA public key. 
		\return true if successful in obtaining an encrypted symmetric key with the public key or otherwise return false. 

		\~chinese
		����?keyʥ��block��
		- randomBlock�������?key��Modulus N��?��?����Encrypt��
		\param outEncryptedSessionKey ���ʥ����?��block��
		\param randomBlock �ʥ����?��block��
		\param publicKeyBlob RSA��?key��
		\return ����?key?��ʥ����??key������?����true����?��?����false��
		
		\~japanese
		���ҫ�?�ǫ֫�ë�����?�����ު���
		- randomBlock �Ϋ���������?��Modulus N��������Φ�����Encrypt���Ǫ��ު���
		\param outEncryptedSessionKey ��?������������֫�ë��Ǫ���
		\param randomBlock ��?�����������֫�ë��Ǫ���
		\param publicKeyBlob RSA ���ҫ�?�Ǫ���
		\return ���ҫ�?����?�����쪿??��?����몳�Ȫ��������true��꫿?�󪷪ơ����������false��꫿?�󪷪ު���
		\~
		*/
		PROUD_API static bool EncryptSessionKeyByPublicKey(ByteArray &outEncryptedSessionKey, const ByteArray &randomBlock, const ByteArray &publicKeyBlob);

		/** 
		\~korean
		�����Ű�� ��ȣȭ�� ���� ��ȣȭ�մϴ�.
		\param outRandomBlock ��ȣȭ �� ByteArray
		\param encryptedSessionKey ��ȣȭ�� ByteArray
		\param privateKey �����Ű�Դϴ�. 
		\return ����Ű�� ��ȣȭ�� ��ĪŰ�� ��ȣȭ �Ͽ� ��µ� �����ϸ� ErrorInforPtr�� �����մϴ�.

		\~english TODO:translate needed.
		Decode the encrypted block with the private key.
		\param outRandomBlock ByteArray to decrypt.
		\param encryptedSessionKey Encrypted ByteArray.
		\param privateKey This is a private key.
		\return When you fail to obtain an encrypted symmetric key with a private key, returns ErrorInforPtr. 

		\~chinese
		��ު��?key��?��ʥ����block��
		\param outRandomBlock ���?�� ByteArray%��
		\param encryptedSessionKey ʥ���� ByteArray%��
		\param privateKey ު��?key��
		\return ��?��key��?���ʥ����??key��?��?����ErrorInforPtr��

		\~japanese
		ު���ҫ�?����?�����쪿�֫�ë�����?�����ު���
		\param outRandomBlock ��?������ ByteArray
		\param encryptedSessionKey ��?�����쪿 ByteArray
		\param privateKey ު���ҫ�?�Ǫ��� 
		\return ���ѫ�?����?�����쪿??��?����?��������몳�Ȫ���������� ErrorInforPtr��꫿?�󪷪ު���
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