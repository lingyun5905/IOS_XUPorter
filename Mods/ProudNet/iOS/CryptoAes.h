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
#include "ByteArray.h"
#include "EncryptEnum.h"
#include "ByteArrayPtr.h"

#ifdef _MSC_VER
#pragma warning(disable:4267)
#endif // __MARMALADE__

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif

	class CCryptoAesKey;
	class CMessage;

	/** \addtogroup util_group
	*  @{
	*/

	/**
	\~korean
	Rijndael(���δ�)�� �� ��ȣȭ �˰����Դϴ�. ���δ��� Joan Daeden�� Vincent Rijmen�� ���� ��������� AES�� �ĺ������ϴ�.
	�� ��ȣȭ �˰����� �پ��� ũ���� �� ���̿� Ű ���̸� �����ϴ�. Ű ���̴� 128,192.256��Ʈ�̸� ���� ũ��� 128,192,256��Ʈ�Դϴ�.
	Ű ���̿� ��� ���̴� �پ��ϰ� ���õǾ �˴ϴ�. ��� ����, Ű ���� ��� 32��Ʈ�� ����� ���� Ȯ�� �����մϴ�.

	���δ��� �ſ� �پ��� ������ �ϵ���� ���μ������� �ſ� ȿ�������� ������ �� �ֽ��ϴ�.

	�� ������ Crptix tookit�� ���� Javaj ������ ���ʷ� ���۵Ǿ����� �̴� �Ʒ����� ã�� �� �ֽ��ϴ�.
	<a href="http://www.efgh.com/software/rijndael.zip" target="_blank">http://www.efgh.com/software/rijndael.zip</a>

	Java �ڵ� �ۼ���: Raif S. Naffah, Paulo S. L. M. Barreto

	�� ������ �������ڿ� ���� ������ KAT �׽�Ʈ���� ����Ǿ����� ����� �̻󹫿����ϴ�.

	\~english
	Rijndael (pronounced Reindaal) is a block cipher, designed by Joan Daemen and Vincent Rijmen as a candidate algorithm for the AES.
	The cipher has a variable block length and key length. The authors currently specify how to use keys with a length
	of 128, 192, or 256 bits to encrypt blocks with length of 128, 192 or 256 bits (all nine combinations of
	key length and block length are possible). Both block length and key length can be extended very easily to
	multiples of 32 bits.

	Rijndael can be implemented very efficiently on a wide range of processors and in hardware.

	This implementation is based on the Java Implementation used with the Cryptix toolkit found at:
	<a href="http://www.efgh.com/software/rijndael.zip" target="_blank">http://www.efgh.com/software/rijndael.zip</a>

	Java code authors: Raif S. Naffah, Paulo S. L. M. Barreto

	This Implementation was tested against KAT test published by the authors of the method and the
	results were identical.

	\~chinese
	Rijndael��blockʥ��ߩ����Rijndael���Joan Daeden��Vincent Rijmen?���AES����?��
	�ʥ��ߩ��?�����?�������block?����key?����key?����128,192.256bit��block�������128,192,256bit��
	key?����block?��ʦ���???��block?����key?��Դʦ���??�32bit����?��
	Rijndael���?������?������?ު��������??��?.
	Rijndael��Crptix tookit��Java?��?����ܣ�ʦ�������?��
	<a href="http://www.efgh.com/software/rijndael.zip" target="_blank">http://www.efgh.com/software/rijndael.zip</a>
	Java��?����Raif S. Naffah, Paulo S. L. M. Barreto
	Rijndael�������?��KAT??߾???��?����?�ȡ�

	\~japanese
	Rijndael(�쫤�����)�ϫ֫�ë���?�����뫴�꫺��Ǫ����쫤������Joan Daeden��Vincent Rijmen�˪�ê��ª���AES�����ͣ�Ǫ�����
	������?�����뫴�꫺�����?�ʫ������Ϋ֫�ë������ȫ�?���������ު�����?��������128,192.256�ӫëȪǡ��֫�ë��Ϋ�������128,192,256�ӫëȪǪ���
	��?�����ȫ֫�ë���������?����?����ƪ��ު��Ǫ����֫�ë���������?�����Ȫ�32�ӫëȪ���?����?��?��Ǫ��ު���
	�쫤�����ϪȪƪ���?����׾�Ϋ�?�ɫ������׫��ë�?�ǪȪƪ�?���ܪ�?�ު���몳�Ȫ��Ǫ��ު���
	����?�ުϡ�Crptix tookit���Ū�쪿Javaj?�ު���������������ơ����������̸�Ī��몳�Ȫ��Ǫ��ު���
	<ahref="http://www.efgh.com/software/rijndael.zip" target="_blank">http://www.efgh.com/software/rijndael.zip</a>
	Java ��?��������Raif S. Naffah, Paulo S. L. M. Barreto
	����?�ު�������˪�ê����Ҫ��쪿KAT�ƫ��Ȫ�������̿������Ȫ���ު���Ǫ�����
	\~
	*/
	class CCryptoAes
	{
	public:
		/**
		\~korean
		- ECB, CBC, CFB ���
		- ECB ��� : ���� ���� �ι� ��ȣȭ �ϸ� ������ ��ȣȭ ���� ���� ������ ���ɴϴ�.
		- CBC ��� : ���� ���� xor������ �� ��ȣȭ �մϴ�.
		- CFB ��� : �ش� ���� ��ȣȭ �� ���� ���� xor������ �մϴ�.

		\~english
		- ECB, CBC, CFB Mode
		- ECB Mode: when the same block is encrypted twice, the original unencrypted test appears. 
		- CBC mode: the previous block and xor calculation is encrypted afterwards. 
		- CFB mode: after the block is encrypted, it does xor calculation with the previous block. 
		

		\~chinese
		- ECB��CBC��CFBټ��
		- ECBټ�ң�ʥ����?��block��??��?�??��ʥ���������
		- CBCټ�ң�?������block��xor?ߩ����ʥ�ˡ�
		- CFBټ�ң�ʥ����?block���?������block xor?ߩ��

		\~japanese
		- ECB, CBC, CFB ��?��
		- ECB��?�ɣ��Ҫ��֫�ë���2����?���������?����?������ʪ��ê���������ު���
		- CBC��?�ɣ����Ϋ֫�ë���xor��ߩ�����êƪ�����?�����ު���
		- CFB��?�ɣ���?�֫�ë�����?�������������Ϋ֫�ë���xor��ߩ�������ު���
		\~
		*/
		enum EncryptMode
		{
			ECB = 0,
			CBC = 1,
			CFB = 2
		};

	public:
		enum { DEFAULT_BLOCK_SIZE = 16 };
		enum { MAX_BLOCK_SIZE = 32, MAX_ROUNDS = 14, MAX_KC = 8, MAX_BC = 8 };

	public:
		CCryptoAes();
		virtual ~CCryptoAes();

	public:
		/**
		\~korean
		Ű�� ����� ���� 128��Ʈ�� �� - 9����
		- Ű �Ǵ� ����� ���̰� 192��Ʈ�� �� - 11����
		- Ű �Ǵ� ����� ���̰� 256��Ʈ�� �� - 13����
		- �������� : �ѹ��� ��ȣȭ �Ǵ� ������

		\param outKey ������ ��ȣȭ Ű�� ����˴ϴ�..
		\param inputKey 128/192/256-bit �� ����� �� ������ �ʱ� AesŰ�� ����� ���� ���� �� �������Դϴ�.
		\param keyLength 16, 24 �Ǵ� 32 bytes �Դϴ�.
		\param blockSize Aes �˰��� ���� �� ������ �Դϴ�. (16, 24 or 32 bytes).

		\~english TODO:translate needed.
		When the length of the key and the block is 128bit ? 9 rounds 
		- When the length of the key and the block is 192bit ? 9 rounds
		- When the length of the key and the block is 256bit ? 9 rounds
		- Block size: size that can be encrypted at once. 


		\param outKey Generated encryption key is saved
		\param inputKey The 128/192/256-bit can be used and this is the random block data to make the initial Aes key. 
		\param keyLength It��s either 16, 24 or 32 bytes
		\param This is the block size within the Aes algorithm (16, 24 or 32 bytes). 

		\~chinese
		Key��block��?����128bit��?�� ? 9����
		- key���block��?����192bit��?�� ? 11����
		- key���block��?����256bit��?�� ? 13����
		- block��᳣������ʥ�������

		\param outKey ?��������ʥ����key
		\param inputKey ʦ�����128/192/256-bit��?��?�����Aes key��?��block?�ߡ�
		\param keyLength 16��24���32bytes��
		\param blockSize Aesߩ��?��bolck��᳣�16��24���32bytes��

		\~japanese
		��?�ȫ֫�ë�������128�ӫëȪǪ����� ? 9�髦���
		- ��?�ު��ϫ֫�ë���������192�ӫëȪǪ����� ? 11�髦���
		- ��?�ު��ϫ֫�ë���������256�ӫëȪǪ����� ? 13�髦���
		- �֫�ë�����������������?������뫵����

		\param outKey �������쪿��?����?��������ު���
		\param inputKey 128/192/256-bit ���Ū����Ȫ��Ǫ�����ѢAes��?���ª몿��Ϋ�����֫�ë���?���Ǫ���
		\param keyLength 16, 24 �ު��� 32 bytes �Ǫ���
		\param blockSize Aes ���뫴�꫺��?�Ϋ֫�ë��������Ǫ���(16, 24 or 32 bytes).
		\~
		*/
		PROUD_API static bool ExpandFrom(CCryptoAesKey &outKey, const uint8_t* const inputKey, int keyLength = DEFAULT_BLOCK_SIZE, int blockSize = DEFAULT_BLOCK_SIZE);

		/**
		\~korean
		\param key ��ĪŰ�Դϴ�.
		\param inputLength ��ȣȭ�� �������� ����
		\return ��ȣȭ�� �������� ����

		\~english
		\param key Symmetric key
		\param inputLength Size of plain text
		\return Size of Encrypted result

		\~chinese
		\param key ??key
		\param inputLength �ʥ����?��?��
		\return ʥ����?��?��

		\~japanese
		\param key ??��?�Ǫ���
		\param inputLength ��?�������?��������
		\return ��?�����쪿��?��������
		\~
		*/
		PROUD_API static int GetEncryptSize(const CCryptoAesKey &key, int inputLength);

		/**
		\~korean
		�����͸� ��ȣȭ �մϴ�.
		\param key ��ĪŰ�Դϴ�.
		\param input �� �޽����Դϴ�.
		\param inputLength ���� �������Դϴ�.
		\param output ��ȣȭ�� ������Դϴ�.
		\param outputLength ��ȣȭ�� ����� �������Դϴ�.
		\param initializationVector CBC, CFB ��忡�� ��ȣȭ�� ���� �ʱ�ȭ �Ҷ� ����ϴ� �����Դϴ�.
		\param initializationVectorLength initializationVector�� ����Ʈ ���� �Դϴ�.
		\param encryptMode ��ȣȭ ��� �Դϴ�. ECB, CBC, CFB ��尡 �ֽ��ϴ�.

		\~english
		Encrypt data
		\param key Symmetric key
		\param input Plain text message
		\param inputLength Size of plain text
		\param output Encrypted result value
		\param outputLength Size of Encrypted result
		\param initializationVector Initialization Vector (IV) for CBC or CFB mode encryption.
		\param initializationVectorLength Length of initializationVector in bytes.
		\param encryptMode Encryption mode. (ECB, CBC, CFB mode)

		\~chinese
		ʥ��?�ߡ�
		\param key ??key��
		\param input ٥�����ӡ�
		\param inputLength ٥�������
		\param output ʥ����?��?��
		\param outputLength ʥ����?����᳡�
		\param initializationVector �CBC��CFBټ����?ʥ��?�������?�������Vector��
		\param initializationVectorLength �� initializationVector Byte?����
		\param encryptMode ʥ��ټ�ҡ���ECB��CBC��CFBټ�ҡ�

		\~japanese
		��?������?�����ު���
		\param key ??��?�Ǫ���
		\param input ������ë�?���Ǫ���
		\param inputLength �����Ϋ������Ǫ���
		\param output ��?�����쪿̿�����Ǫ���
		\param outputLength ��?�����쪿̿���Ϋ������Ǫ���
		\param initializationVector CBC, CFB ��?�ɪ���?���Ϊ������Ѣ�������Ū��٫��ȫ�Ǫ���
		\param initializationVectorLength initializationVector�ΫЫ��������Ǫ���
		\param encryptMode ��?����?�ɪǪ���ECB, CBC, CFB��?�ɪ�����ު���
		\~
		*/
		PROUD_API static bool Encrypt(
			const CCryptoAesKey &key, 
			const uint8_t* const input, 
			int inputLength, 
			uint8_t *output, 
			int &outputLength, 
			uint8_t * initializationVector = NULL, 
			int initializationVectorLength = 0, 
			EncryptMode encryptMode = ECB
			);

		/**
		\~korean
		�����͸� ��ȣȭ �մϴ�.
		\param key ��ĪŰ �Դϴ�.
		\param input ��ȣȭ�� �޽����Դϴ�.
		\param inputLength ��ȣȭ�� �޽����� �������Դϴ�.
		\param output ��ȣȭ�� ����� �Դϴ�.
		\param outputLength ��ȣȭ�� ������� �������Դϴ�.
		\param initializationVector CBC, CFB ��忡�� ��ȣȭ�� ���� �ʱ�ȭ �Ҷ� ����ϴ� �����Դϴ�.
		\param initializationVectorLength initializationVector�� ����Ʈ ���� �Դϴ�.
		\param encryptMode ��ȣȭ ��� �Դϴ�. ECB, CBC, CFB ��尡 �ֽ��ϴ�.

		\~english
		Decrypt data
		\param key Symmetric key
		\param input Encrypted message
		\param inputLength Size of Encrypted message
		\param output Decrypted result value
		\param outputLength Size of Decrypted text
		\param initializationVector Initialization Vector (IV) for CBC or CFB mode encryption.
		\param initializationVectorLength Length of initializationVector in bytes.
		\param encryptMode Encryption mode. (ECB, CBC, CFB mode)

		\~chinese
		��??�ߡ�
		\param key ??key��
		\param input ʥ�������ӡ�
		\param inputLength ʥ�����������
		\param output ??��?��?��
		\param outputLength ??��?����᳡�
		\param initializationVector �CBC��CFBټ����?ʥ��?�������?�������Vector��
		\param initializationVectorLength �� initializationVector Byte?����
		\param encryptMode ʥ��ټ�ҡ���ECB��CBC��CFBټ�ҡ�

		\~japanese
		��?������?�����ު���
		\param key ??��?�Ǫ���
		\param input ��?�����쪿��ë�?���Ǫ���
		\param inputLength ��?�����쪿��ë�?���Ϋ������Ǫ���
		\param output ��?�����쪿̿�����Ǫ���
		\param outputLength ��?�����쪿̿�����Ϋ������Ǫ���
		\param initializationVector CBC, CFB ��?�ɪ���?���Ϊ������Ѣ�������Ū��٫��ȫ�Ǫ���
		\param initializationVectorLength initializationVector�ΫЫ��������Ǫ���
		\param encryptMode ��?����?�ɪǪ��� ECB, CBC, CFB ��?�ɪ�����ު���
		\~
		*/
		PROUD_API static bool Decrypt(
			const CCryptoAesKey &key, 
			const uint8_t* const input, 
			int inputLength, 
			uint8_t *output, 
			int &outputLength, 
			uint8_t * initializationVector = NULL, 
			int initializationVectorLength = 0,
			EncryptMode encryptMode = ECB
			);

		/**
		\~korean
		ByteArray�� ��ȣȭ �մϴ�.
		\param key ��ĪŰ�Դϴ�.
		\param input �� �޽����Դϴ�.
		\param output ��ȣȭ�� ������Դϴ�.
		\param initializationVector CBC, CFB ��忡�� ��ȣȭ�� ���� �ʱ�ȭ �Ҷ� ����ϴ� �����Դϴ�.
		\param initializationVectorLength initializationVector�� ����Ʈ ���� �Դϴ�.
		\param encryptMode ��ȣȭ ��� �Դϴ�. ECB, CBC, CFB ��尡 �ֽ��ϴ�.

		\~english
		Encrypt ByteArray
		\param key Symmetric key
		\param input Plain text message
		\param output Encrypted result value
		\param initializationVector Initialization Vector (IV) for CBC or CFB mode encryption.
		\param initializationVectorLength Length of initializationVector in bytes.
		\param encryptMode Encryption mode. (ECB, CBC, CFB mode)

		\~chinese
		ʥ�� ByteArray��
		\param key ??key��
		\param input ٥�����ӡ�
		\param output ʥ����?��?��
		\param initializationVector �CBC��CFBټ����?ʥ��?�������?�������Vector��
		\param initializationVectorLength �� initializationVector Byte?����
		\param encryptMode ʥ��ټ�ҡ���ECB��CBC��CFBټ�ҡ�

		\~japanese
		ByteArray����?�����ު���
		\param key ??��?�Ǫ���
		\param input ������ë�?���Ǫ���
		\param output ��?�����쪿̿�����Ǫ���
		\param initializationVector CBC, CFB��?�ɪ���?���Ϊ������Ѣ�������Ū��٫��ȫ�Ǫ���
		\param initializationVectorLength initializationVector�ΫЫ��������Ǫ���
		\param encryptMode ��?����?�ɪǪ���ECB, CBC, CFB ��?�ɪ�����ު���
		\~
		*/
		PROUD_API static bool EncryptByteArray(
			const CCryptoAesKey &key, 
			const ByteArray &input, 
			ByteArray &output, 
			uint8_t * initializationVector = NULL, 
			int initializationVectorLength = 0, 
			EncryptMode encryptMode = ECB
			);

		/**
		\~korean
		ByteArray�� ��ȣȭ �մϴ�.
		\param key ��ĪŰ �Դϴ�.
		\param input ��ȣȭ�� �޽����Դϴ�.
		\param output ��ȣȭ�� ����� �Դϴ�.
		\param initializationVector CBC, CFB ��忡�� ��ȣȭ�� ���� �ʱ�ȭ �Ҷ� ����ϴ� �����Դϴ�.
		\param initializationVectorLength initializationVector�� ����Ʈ ���� �Դϴ�.
		\param encryptMode ��ȣȭ ��� �Դϴ�. ECB, CBC, CFB ��尡 �ֽ��ϴ�.

		\~english
		Decrypt ByteArray
		\param key Symmetric key
		\param input Encrypted message
		\param output Decrypted result value
		\param initializationVector Initialization Vector (IV) for CBC or CFB mode encryption.
		\param initializationVectorLength Length of initializationVector in bytes.
		\param encryptMode Encryption mode. (ECB, CBC, CFB mode)

		\~chinese
		��? ByteArray��
		\param key ??key��
		\param input ʥ�������ӡ�
		\param output ��?��?��?��
		\param initializationVector �CBC��CFBټ����?ʥ��?�������?�������Vector��
		\param initializationVectorLength �� initializationVector Byte?����
		\param encryptMode ʥ��ټ�ҡ���ECB��CBC��CFBټ�ҡ�

		\~japanese
		ByteArray����?�����ު���
		\param key ??��?�Ǫ���
		\param input ��?�����쪿��ë�?���Ǫ���
		\param output ��?�����쪿̿�����Ǫ���
		\param initializationVector CBC, CFB ��?�ɪ���?���Ϊ������Ѣ�������Ū��٫��ȫ�Ǫ���
		\param initializationVectorLength initializationVector�ΫЫ��������Ǫ���
		\param encryptMode ��?����?�ɪǪ���ECB, CBC, CFB��?�ɪ�����ު���
		\~
		*/
		PROUD_API static bool DecryptByteArray(
			const CCryptoAesKey &key,
			const ByteArray &input, ByteArray &output, 
			uint8_t * initializationVector = NULL, 
			int initializationVectorLength = 0, 
			EncryptMode encryptMode = ECB
			);

		/**
		\~korean
		Message�� ��ȣȭ �մϴ�.
		\param key ��ĪŰ�Դϴ�.
		\param input �� �޽����Դϴ�.
		\param output ��ȣȭ�� ������Դϴ�.
		\param offset �� �޽������� ��ȣȭ�� ������ ��ġ
		\param initializationVector CBC, CFB ��忡�� ��ȣȭ�� ���� �ʱ�ȭ �Ҷ� ����ϴ� �����Դϴ�.
		\param initializationVectorLength initializationVector�� ����Ʈ ���� �Դϴ�.
		\param encryptMode ��ȣȭ ��� �Դϴ�. ECB, CBC, CFB ��尡 �ֽ��ϴ�.

		\~english
		Encrypt Message
		\param key Symmetric key
		\param input Plain text message
		\param output Encrypted result value
		\param offset Encrypt start position at plain text message
		\param initializationVector Initialization Vector (IV) for CBC or CFB mode encryption.
		\param initializationVectorLength Length of initializationVector in bytes.
		\param encryptMode Encryption mode. (ECB, CBC, CFB mode)

		\~chinese
		ʥ��Message��
		\param key ??key��
		\param input ٥�����ӡ�
		\param output ʥ����?��?��
		\param offset �٥������?�ʥ�������ǡ�
		\param initializationVector �CBC��CFBټ����?ʥ��?�������?�������Vector��
		\param initializationVectorLength �� initializationVector Byte?����
		\param encryptMode ʥ��ټ�ҡ���ECB��CBC��CFBټ�ҡ�

		\~japanese
		Message����?�����ު���
		\param key ??��?�Ǫ���
		\param input ������ë�?���Ǫ���
		\param output ��?�����쪿̿�����Ǫ���
		\param offset ������ë�?������?������㷪�������
		\param initializationVector CBC, CFB ��?�ɪ���?���Ϊ������Ѣ�������Ū��٫��ȫ�Ǫ���
		\param initializationVectorLength initializationVector�ΫЫ��������Ǫ���
		\param encryptMode ��?����?�ɪǪ���ECB, CBC, CFB��?�ɪ�����ު���
		\~
		*/
		PROUD_API static bool EncryptMessage(
			const CCryptoAesKey &key, 
			const CMessage &input, 
			CMessage &output, 
			int offset, 
			uint8_t * initializationVector = NULL, 
			int initializationVectorLength = 0, 
			EncryptMode encryptMode = ECB
			);

		/**
		\~korean
		Message�� ��ȣȭ �մϴ�.
		\param key ��ĪŰ �Դϴ�.
		\param input ��ȣȭ�� �޽����Դϴ�.
		\param output ��ȣȭ�� ����� �Դϴ�.
		\param offset ��ȣȭ�� �޽������� ��ȣȭ�� ������ ��ġ
		\param initializationVector CBC, CFB ��忡�� ��ȣȭ�� ���� �ʱ�ȭ �Ҷ� ����ϴ� �����Դϴ�.
		\param initializationVectorLength initializationVector�� ����Ʈ ���� �Դϴ�.
		\param encryptMode ��ȣȭ ��� �Դϴ�. ECB, CBC, CFB ��尡 �ֽ��ϴ�.

		\~english
		Decrypt Message
		\param key Symmetric key
		\param input Encrypted message
		\param output Decrypted result value
		\param offset Decrypt start position at encrypted message
		\param initializationVector Initialization Vector (IV) for CBC or CFB mode encryption.
		\param initializationVectorLength Length of initializationVector in bytes.
		\param encryptMode Encryption mode. (ECB, CBC, CFB mode)

		\~chinese
		��?Message��
		\param key ??key��
		\param input ʥ�������ӡ�
		\param output ��?��?��?��
		\param offset �ʥ������?���?�����ǡ�
		\param initializationVector �CBC��CFBټ����?ʥ��?�������?�������Vector��
		\param initializationVectorLength �� initializationVector Byte?����
		\param encryptMode ʥ��ټ�ҡ���ECB��CBC��CFBټ�ҡ�

		\~japanese
		Message����?�����ު���
		\param key ??��?�Ǫ���
		\param input ��?�����쪿��ë�?���Ǫ���
		\param output ��?�����쪿̿�����Ǫ���
		\param offset ��?�����쪿��ë�?������?������㷪�������
		\param initializationVector CBC, CFB ��?�ɪ���?���Ϊ������Ѣ�������Ū��٪��ȫ�Ǫ���
		\param initializationVectorLength initializationVector�ΫЫ��������Ǫ���
		\param encryptMode ��?����?�ɪǪ���ECB, CBC, CFB��?�ɪ�����ު���
		\~
		*/
		PROUD_API static bool DecryptMessage(
			const CCryptoAesKey &key, 
			const CMessage &input, 
			CMessage &output, 
			int offset, 
			uint8_t * initializationVector = NULL, 
			int initializationVectorLength = 0, 
			EncryptMode encryptMode = ECB
			);

	private:
		static bool DefaultEncryptBlock(const CCryptoAesKey &key, const uint8_t* in, uint8_t *result);
		static bool DefaultDecryptBlock(const CCryptoAesKey &key, const uint8_t* in, uint8_t *result);
		static bool EncryptBlock(const CCryptoAesKey &key, const uint8_t* in, uint8_t *result);
		static bool DecryptBlock(const CCryptoAesKey &key, const uint8_t* in, uint8_t *result);
		static int Mul(int a, int b);
		static int Mul4(int a, char b[]);
		static void Xor(uint8_t *buff, const uint8_t* chain, const int blockSize);

	private:
		/** Null chain */
		static char const* m_chain0;

		static const int m_alog[256];
		static const int m_log[256];

		static const int8_t m_s[256];

		static const int8_t m_si[256];

		static const int m_t1[256];
		static const int m_t2[256];
		static const int m_t3[256];
		static const int m_t4[256];

		static const int m_t5[256];
		static const int m_t6[256];
		static const int m_t7[256];
		static const int m_t8[256];

		static const int m_u1[256];
		static const int m_u2[256];
		static const int m_u3[256];
		static const int m_u4[256];
		static const int8_t m_rcon[30];
		static const int m_shifts[3][4][2];
	};

	class CCryptoAesKey
	{
		friend class CCryptoAes;

	public:
		CCryptoAesKey()
		{
			m_keyLength = 0;
		}

		/**
		\~korean
		aes Ű ���̸� ���ɴϴ�. (byte)
		\return aes Ű ����

		\~english
		Gets length of AES key. (byte)
		\return AES key length

		\~chinese
		?��aes key?������byte��
		\return aes key?��

		\~japanese
		aes ��?����������ު���(byte)
		\return aes ��?������
		\~
		*/
		int GetKeyLength() const;

		/**
		\~korean
		�� ����� ���ɴϴ�. (byte)
		\return m_blockSize

		\~english
		Gets block size. (byte)
		\return m_blockSize

		\~chinese
		?��block��᳡���byte��
		\return m_blockSize

		\~japanese
		�֫�ë�����������ު���(byte)
		\return m_blockSize

		\~
		*/
		int	GetBlockSize() const;

		/**
		\~korean
		���� ���� ���ɴϴ�.
		\return m_rounds

		\~english
		Gets number of round.
		\return m_rounds

		\~chinese
		?������?��
		\return m_rounds

		\~japanese
		�髦���?����ު���
		\return m_rounds

		\~
		*/
		int GetRounds() const;

		/**
		\~korean
		Ű�� �̹� �����Ǿ������� Ȯ���մϴ�.

		\~english
		Check key is already existed or not.

		\~chinese
		??key�����?��������

		\~japanese
		��?��?����������ƪ��몫�����㪷�ު���
		\~
		*/
		bool KeyExists() const;

		void Clear();

	private:
		// ��ȣȭ�� ���Ǵ� round key
		int m_ke[CCryptoAes::MAX_ROUNDS + 1][CCryptoAes::MAX_BC];
		// ��ȣȭ�� ���Ǵ� round key
		int m_kd[CCryptoAes::MAX_ROUNDS + 1][CCryptoAes::MAX_BC];
		// Ű ���� (byte)
		int m_keyLength;
		// �� ������
		int	m_blockSize;
		// ���� ��
		int m_rounds;

#ifdef _WIN32
#pragma push_macro("new")
#undef new
		// �� Ŭ������ ProudNet DLL ��츦 ���� Ŀ���� �Ҵ��ڸ� ���� fast heap�� ���� �ʴ´�.
		DECLARE_NEW_AND_DELETE
#pragma pop_macro("new")
#endif // __MARMALADE__

	};

	/**  @} */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif