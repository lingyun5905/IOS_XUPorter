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
#include <sys/types.h>

#include "OdbcByteData.h"
#include "OdbcEnum.h"
#include "PNString.h"
#include "pnstdint.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	// *********************** WARNING ***********************
	// �� Ŭ������ ������� ODBC API ���ο��� ���Ǵ� Ŭ�����Դϴ�.
	// ���� �� Ŭ������ �̿��Ͽ� �ڵ����� ���ñ� �ٶ��ϴ�.
	// This class is used internally by ProudNet ODBC API.
	// Please never use this class.
	// *******************************************************

	class COdbcVariant
	{
	private:
		OdbcDataType m_type;

		// ���� �����͸� ������ ��� ���⿡ ���빰�� ����ȴ�.
		union OdbcUnionValue
		{
			// PDT type��
			bool m_boolVal;
			PNTCHAR m_tcharVal;
			int8_t m_int8Val;
			int16_t m_int16Val;
			int32_t m_int32Val;
			int64_t m_int64Val;
			uint8_t m_uint8Val;
			uint16_t m_uint16Val;
			uint32_t m_uint32Val;
			uint64_t m_uint64Val;
			float m_floatVal;
			double m_doubleVal;

			// non-PDT type��
			String* m_stringPtr;
			COdbcByteData* m_binaryPtr;
			TIMESTAMP_STRUCT* m_timePtr;
		} m_val;

		// �������� �ּҰ�.
		void* m_ptr;

		// ����ڰ� ���� �ִ� ������ �����ϴ� �������̸� true, �� ����� �����͸� ����Ű�� false
		bool m_isRef;

	public:
		COdbcVariant();
		COdbcVariant(bool from);
		COdbcVariant(bool* from);
		COdbcVariant(PNTCHAR from);
		COdbcVariant(int8_t from);
		COdbcVariant(int8_t* from);
		COdbcVariant(int16_t from);
		COdbcVariant(int16_t* from);
		COdbcVariant(int32_t from);
		COdbcVariant(int32_t* from);
		COdbcVariant(int64_t from);
		COdbcVariant(int64_t* from);
		COdbcVariant(uint8_t from);
		COdbcVariant(uint16_t from);
		COdbcVariant(uint16_t* from);
		COdbcVariant(uint32_t from);
		COdbcVariant(uint32_t* from);
		COdbcVariant(uint64_t from);
		COdbcVariant(uint64_t* from);
		COdbcVariant(float from);
		COdbcVariant(float* from);
		COdbcVariant(double from);
		COdbcVariant(double* from);
		COdbcVariant(const PNTCHAR* from);
		COdbcVariant(const String& from);
		COdbcVariant(String* from);
		COdbcVariant(COdbcByteData* from);
		COdbcVariant(const TIMESTAMP_STRUCT& from);
		COdbcVariant(TIMESTAMP_STRUCT* from);
		~COdbcVariant();

		operator bool() const;
		operator PNTCHAR() const;
		operator int8_t() const;
		operator int16_t() const;
		operator int32_t() const;
		operator int64_t() const;
		operator uint8_t() const;
		operator uint16_t() const;
		operator uint32_t() const;
		operator uint64_t() const;
		operator float() const;
		operator double() const;
		operator String() const;
		operator COdbcByteData*() const;
		operator TIMESTAMP_STRUCT() const;

		COdbcVariant(const COdbcVariant& other);
		COdbcVariant& operator=(const COdbcVariant& other);

		void Initialize();
		SQLSMALLINT GetType() const;
		void* GetPtr() const;
		bool IsRef() const;
		void ChangeRefToData();

	private:
		void ThrowIfNull() const;
		void Clean();
		void Copy(const COdbcVariant &other);

		// unsigned char*�� BYTE�� �Ǵ�
		COdbcVariant(const unsigned char* from);
	};

}

#ifdef _MSC_VER
#pragma pack(pop)
#endif