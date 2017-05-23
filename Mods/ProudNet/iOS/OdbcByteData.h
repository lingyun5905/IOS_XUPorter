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

#include <sqltypes.h>

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/**
	 \~korean
	 ODBC API�� ���� �����͸� ������Ҷ� ���˴ϴ�.
	 ���� �����Ͱ� ��ġ�� �ſ� ū ���, ������ ����� �������� ���ʿ��� ���� ������ �����ϱ� ���� �� Ŭ������ ���˴ϴ�.
	 ����ڰ� ���� �����͸� ���� �����ؾ� �ϰ�, �� Ŭ������ �� �����͸� �����ϴ� ������ �մϴ�.

	 \~english
	 It is used for input & output of binary data at ODBC API.
	 If the size of binary data is too big, this class will be used to omit unnecessary copy process in the process of data input & output. 
	 A user must possess binary data and this class refers to the data. 

	 \~chinese
	 �ODBC API?�����?�?��?���ġ�
	 �?�?����ު����?��?���?����?����?���������������?�?�����?class��
	 ��??��������?�?�ߣ��?class����?��??�������ġ�

	 \~japanese
	 ODBC API�˫ѫ��ʫ��?��������������������Ū��ު���
	 �ѫ��ʫ��?���Ϋ���������?�ު������ꡢ��?��������Φ�������驪ʫ���?Φ������Ԫ��몿��˪��Ϋ��髹�����Ī���ު���
	 ��?��?���ѫ��ʫ��?����������󪹪���驪����ꡢ���Ϋ��髹�Ϫ��Ϋ�?����?�Ϊ�����ܪ򪷪ު���

	 \~
	 */
	class COdbcByteData
	{
	private:
		// ����ڰ� ������� ���� �� �� ���� ���� �Դϴ�.
		// dataPtr�� ������ ����� ������ ���� ���δ� ������� ������ �� ������ �� ��ü ��ü(�����Ͱ�)�� ����Ǹ� �ȵ˴ϴ�.
		// ��ü�� ������� ���ϱ� ������ maxLen�� �ѹ� �����ϸ� �ٲ��� ���մϴ�.
		SQLCHAR* m_dataPtr;

		SQLLEN m_dataLength;
		SQLULEN m_maxLength;

	public:
		/**
		 \~korean
		 ������ �Լ�. ���⼭ ����ڰ� ���� �ִ� ���� �������� �ּҿ� ũ�⸦ �Է��Ͻʽÿ�.
		 \param pData ���� �������� �ּ�
		 \param dataLength ���� �������� ��ȿ�� ���� ũ���Դϴ�
		 \param maxLength ���� �����Ͱ� ����Ǵ� �ִ� ũ��

		 \~english
		 Constructor function. Please input the size & address of binary data that a user has. 
		 \param pData Address of binary data.
		 \param dataLength Current valid size of binary data. 
		 \param maxLength Maximum size of binary data saving.

		 \~chinese
		 ����� ��?����?����?���?�?����������᳡�
		 \param pData �?�?������
		 \param dataLength �?�?����?��������᳡�
		 \param maxLength �?�?��ʦ����������������

		 \~japanese
		 �����??�������ǫ�?��?���êƪ���ѫ��ʫ��?���Ϋ��ɫ쫹�ȫ��������������ƪ���������
		 \param pData �ѫ��ʫ��?���Ϋ��ɫ쫹
		 \param dataLength �ѫ��ʫ��?������?����������Ǫ���
		 \param maxLength �ѫ��ʫ��?������?�֪�������ޫ�����

		 \~
		 */
		COdbcByteData(SQLCHAR* pData, SQLLEN dataLength, SQLULEN maxLength);

		/**
		 \~korean
		 ������ �������� �ּҸ� ���� �ɴϴ�.

		 \~english
		 Get the data address that has been set. 

		 \~chinese
		 ?���?����?���򣡣

		 \~japanese
		 ���Ҫ��쪿��?���Ϋ��ɫ쫹���?�ɪ��ު���

		 \~
		 */
		SQLCHAR* GetDataPtr();

		/**
		 \~korean
		 ������ �������� ũ�⸦ ���� �ɴϴ�.

		 \~english
		 Get the data size that has been set. 

		 \~chinese
		 ?���?����?����᳡�

		 \~japanese
		 ���Ҫ��쪿��?���Ϋ��������?�ɪ��ު���.

		 \~
		 */
		SQLLEN GetDataLength();

		/**
		 \~korean
		 �������� ũ�⸦ �������մϴ�.
		 �����ڿ��� ������ ����� ������ ���۸� �����Ͽ��� �� �װ��� ���̰� �ٲ�� �� �Լ��� ȣ���Ͽ� ũ�⸦ �����ؾ� �մϴ�.

		 \~english
		 Readjust the size of data.
		 If the length of data buffer changes when modifying data buffer that has been set by a constructor, you will be required to change the size by calling this function. 

		 \~chinese
		 ����?��?����᳡�
		 ����������������??��buffer?������??�������?�����������??�����?�ڡ�

		 \~japanese
		 ��?���Ϋ�����������ڪ��ު���
		 ��������Ҫ�����?��?��?���Ыëի�?�����᪷���Ȫ��������������?���Ȫ���??�������󪷡���������?�ڪ�����驪�����ު���

		 \~
		 */
		void SetDataLength(SQLLEN dataLength);

		/**
		 \~korean
		 ������ �������� �ִ� ũ�⸦ ����ϴ�.

		 \~english
		 Obtain the maximum size of data. 

		 \~chinese
		 ?���?��?��������?��

		 \~japanese
		 ���Ҫ��쪿��?�������ޫ����������𪷪ު���

		 \~
		 */
		SQLULEN GetMaxLength();

	private:
		// ���� ����
		COdbcByteData(const COdbcByteData& other);
		COdbcByteData& operator=(const COdbcByteData& other);
	};
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif