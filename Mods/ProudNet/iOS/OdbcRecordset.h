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

#include "OdbcEnum.h"
#include "PNString.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	class COdbcVariant;
	class COdbcRecordsetImpl;
	class COdbcConnection;

	/**
	 \~korean
	 SELECT�� ���� ����� Recordset�� ������ �� �ִ� Ŭ�����Դϴ�.

	 \~english
	 It is a class that can control Recordset that has been received by SELECT.

	 \~chinese
	 ʦ�������?SELECT?����Recordset��class��

	 \~japanese
	 SELECT�Ϊ������𪵪쪿Recordset�򫳫�ȫ�?��Ǫ��뫯�髹�Ǫ���

	 \~
	 */
	class COdbcRecordset
	{
	public:
		COdbcRecordset();
		~COdbcRecordset();

		/**
		 \~korean
		 ù��° ���ڵ�� �̵��մϴ�.
		 ����/���и� ��ȯ�մϴ�.
		 Stored Procedure�� Recordset������ ����� �� �����ϴ�.

		 \~english
		 Move to the first record. 
		 Return success/fail
		 You cannot use it in the Recordset of the stored procedure. 

		 \~chinese
		 �?�����???��
		 ������/��?��
		 �Stored Procedure��Recordset���������ġ�

		 \~japanese
		 �����Ϋ쫳?�ɪ���Ѫ��ު���
		 ����/�������������ު���
		 Stored Procedure��Recordset�Ǫ����ĪǪ��ު���

		 \~
		 */
		bool MoveFirst();
		/**
		 \~korean
		 ������ ���ڵ�� �̵��մϴ�.
		 ����/���и� ��ȯ�մϴ�.
		 Stored Procedure�� Recordset������ ����� �� �����ϴ�.

		 \~english
		 Move to the last record 
		 Return success/fail
		 You cannot use it in the Recordset of the stored procedure. 

		 \~chinese
		 �?��������???��
		 ������/��?��
		 �Stored Procedure��Recordset���������ġ�

		 \~japanese
		 �����Ϋ쫳?�ɪ���Ѫ��ު���
		 ����/�������������ު���
		 Stored Procedure��Recordset�Ǫ����ĪǪ��ު���

		 \~
		 */
		bool MoveLast();
		/**
		 \~korean
		 ���� ���ڵ�� �̵��մϴ�.
		 ����/���и� ��ȯ�մϴ�.
		 Stored Procedure�� Recordset������ ����� �� �����ϴ�.

		 \~english
		 Move to the previous record.
		 Return success/fail
		 You cannot use it in the Recordset of the stored procedure. 

		 \~chinese
		 �?������???��
		 ������/��?��
		 �Stored Procedure��Recordset���������ġ�

		 \~japanese
		 ���Ϋ쫳?�ɪ���Ѫ��ު���
		 ����/�������������ު���
		 Stored Procedure��Recordset�Ǫ����ĪǪ��ު���

		 \~
		 */
		bool MovePrev();
		
		/**
		 \~korean
		 ���� ���ڵ�� �̵��մϴ�.
		 ����/���и� ��ȯ�մϴ�.
		 �����͸� ���� �� �� �Լ��� ���� ȣ���ؾ߸� ���� �� �ֽ��ϴ�.

		 \~english
		 Move to the next record. 
		 Return success/fail
		 You cannot use it in the Recordset of the stored procedure. 

		 \~chinese
		 �?������???��
		 ������/��?��
		 �������?����?���?��?�ߡ�

		 \~japanese
		 �Ϋ쫳?�ɪ���Ѫ��ު���
		 ����/�������������ު���
		 ��?����������ϡ�����??��໪������󪷪ƪ�����몳�Ȫ��Ǫ��ު���

		 \~
		 */
		bool MoveNext();

		/**
		 \~korean
		 �������� ���ڵ���� �������� ��� �� �Լ��� ���� ���� ���ڵ������ ��ȯ�� �� �ֽ��ϴ�.
		 ����/���и� ��ȯ�մϴ�.

		 \~english
		 When you bring many recordsets, you can change to the next recordset using this function. 
		 Return success/fail

		 \~chinese
		 ?����? RecordSet ?��ʦ���??��????����? RecordSet��
		 �?����???�?ʦ��?���?��������/��?��

		 \~japanese
		��?�Ϋ쫳?�ɫ��ëȪ�����?�����ꡢ����??���ת����Ϋ쫳?�ɫ��ëȪ�﷪��𪨪��ު���
		����/�������������ު���

		 \~
		 */
		bool NextRecordSet();

		/**
		 \~korean
		 ��ü Row ������ ��ȯ�մϴ�.

		 \~english
		 Return the total number of Row. 

		 \~chinese
		 ��?��� Row??��

		 \~japanese
		 ��?Row?���������ު���

		 \~
		 */
		SQLLEN GetRowCount();
		/**
		 \~korean
		 ���� Row Index�� ��ȯ�մϴ�. (ex> 0, 1, 2, ...)
		 Row Index�� -1�̸� BOF �����̸�, Row Count�� ���ٸ� EOF �����Դϴ�.

		 \~english
		 Return the current Row Index (ex> 0, 1, 2, ...).
		 If Row Index is -1, its status is BOF and if it is same as Row Count, its status is EOF.

		 \~chinese
		 ?����?Row Index��(ex> 0, 1, 2, ...)
		 Row Index ��� -1?�� BOF??,�?Row Count����?�� EOF ??��

		 \~japanese
		 ���Row Index���������ު���(ex> 0, 1, 2, ...)
		 Row Index��-1�ʪ�BOF?���ǡ�Row Count���Ҫ��ʪ�EOF?���Ǫ���

		 \~
		 */
		SQLLEN GetCurrentRowIndex();
		/**
		 \~korean
		 ��ü Field ������ ��ȯ�մϴ�.

		 \~english
		 Return the total number of Fields. 

		 \~chinese
		 ��?���Field??��

		 \~japanese
		 ��?Field ��?���������ު���

		 \~
		 */
		SQLSMALLINT GetFieldCount();

		/**
		 \~korean
		 BOF�� Index == -1�� �� �̸� ���� ���� �����Ͱ� ���� �����Դϴ�.

		 \~english
		 BOF indicates Index == -1 and it means there is no data that has been read. 

		 \~chinese
		 BOF? Index == -1 ?����ڱ??����??��

		 \~japanese
		 BOF��Index == -1�����ǡ��ު�ڱ?�Ϋ�?�����ʪ�?���Ǫ���

		 \~
		 */
		bool IsBof();
		/**
		 \~korean
		 EOF�� Index == GetRowCount()�� �� �̸� �����͸� ��� ���� �����Դϴ�.

		 \~english
		 EOF indicates Index == GetRowCount() and it means all data has been read. 

		 \~chinese
		 EOF? Index == GetRowCount()?�����?���?����??��

		 \~japanese
		 EOF��Index == GetRowCount()�����Ǫ��ꡢ��ƪΫ�?����??��?���Ǫ���

		 \~
		 */
		bool IsEof();

		/**
		 \~korean
		 Field(Column)�� �̸��� ��� �ɴϴ�.
		 "SELECT COUNT(*) FROM TABLE"�� ���� �÷����� �������� ���� ���������� ���� �۵����� ���� �� �ֽ��ϴ�.
		 �׷� �� �÷��� Alias�� �����Ͽ� "SELECT COUNT(*) AS TOTAL FROM TABLE"�� ���� ����Ͻø� �˴ϴ�.

		 \~english
		 Get the name of Field(Column).
		 It might not be executed normally at a query whose column name has not been defined, such as "SELECT COUNT(*) FROM TABLE".
		 In this case, set Alias in the column name  and use it like "SELECT COUNT(*) AS TOTAL FROM TABLE".

		 \~chinese
		 ?��Field(Column)٣?��
		 ?"SELECT COUNT(*) FROM TABLE"���ң��Column Nameڱ����query�飬��ʦ����������?����
		 ??�Column Name?��Alias����?"SELECT COUNT(*) AS TOTAL FROM TABLE"����۰������?ʦ��

		 \~japanese
		 Field(Column)��٣�����𪷪ު���
		 "SELECT COUNT(*) FROM TABLE"�Ϊ誦�� Column٣��̽����ƪ��ʪ�������?�Ǫ��������Ѫ��ʪ�����⪢��ު���
		 ��������˪�Column٣��Alias�����Ҫ�"SELECT COUNT(*) AS TOTAL FROM TABLE"�Ϊ誦�����Ī��ƪ���������

		 \~
		 */
		String GetFieldName(int fieldIndex);

		/**
		 \~korean
		 Field(Column)�� SqlDataType�� ��� �ɴϴ�.
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~english
		 Get SqlDataType of Field(Column).
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~chinese
		 ?��Field(Column)�� SqlDataType��
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~japanese
		 Field(Column)��SqlDataType�����𪷪ު���
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~
		 */
		OdbcSqlDataType GetFieldSqlType(int fieldIndex);
		/**
		 \~korean
		 Field(Column)�� SqlDataType�� ��� �ɴϴ�.
		 \param fieldName Field(Column) �̸�

		 \~english
		 Get SqlDataType of Field(Column).
		 \param fieldname It is the name of Field(Column).

		 \~chinese
		 ?��Field(Column)�� SqlDataType
		 \param fieldName Field(Column) ٣?��

		 \~japanese
		 Field(Column)��SqlDataType�����𪷪ު���
		 \param fieldName Field(Column) ٣

		 \~
		 */
		OdbcSqlDataType GetFieldSqlType(const String& fieldName);

		/**
		 \~korean
		 Field(Column) �������� ���� ũ�⸦ �����ɴϴ�.
		 NULL�� ��� -1�� ��ȯ �մϴ�.
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~english
		 Bring the current size of Field(Column) data. 
		 In case of NULL, it returns -1. 
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~chinese
		 ?��?�������Field(Column) ?�ߡ�
		 ������NULL����?����? -1��.
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~japanese
		 Field(Column)��?��������������?�ɪ��ު���
		 NULL������ -1���������ު���
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~
		 */
		SQLLEN GetFieldSizeOrNull(int fieldIndex);
		/**
		 \~korean
		 Field(Column) �������� ���� ũ�⸦ �����ɴϴ�.
		 NULL�� ��� -1�� ��ȯ �մϴ�.
		 \param fieldName Field(Column) �̸�

		 \~english
		 Bring the current size of Field(Column) data. 
		 In case of NULL, it returns -1. 
		 \param fieldname It is the name of Field(Column).

		 \~chinese
		 ?��?�������Field(Column) ?�ߡ�
		 ������NULL����?����? -1��.
		 \param fieldName Field(Column)٣?

		 \~japanese
		 Field(Column) ��?��������������?�ɪ��ު���
		 NULL������ -1���������ު���
		 \param fieldName Field(Column) ٣

		 \~
		 */
		SQLLEN GetFieldSizeOrNull(const String& fieldName);

		/**
		 \~korean
		 Field(Column) �������� �ִ� ũ��(�����ͺ��̽� ����)�� �����ɴϴ�.
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~english
		 Bring the maximum size (Database setting) of Field(Column) data.
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~chinese
		 ?��Field(Column)?��������?��?��??�ң���
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~japanese
		 Field(Column) ��?�������ޫ���������?����?�����ң����?�ɪ��ު���
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~
		 */
		SQLULEN GetFieldMaxSize(int fieldIndex);
		/**
		 \~korean
		 Field(Column) �������� �ִ� ũ��(�����ͺ��̽� ����)�� �����ɴϴ�.
		 \param fieldName Field(Column) �̸�

		 \~english
		 Bring the maximum size (Database setting) of Field(Column) data.
		 \param fieldname It is the name of Field(Column).

		 \~chinese
		 ?�� Field(Column)?��������?��?��??�ң���
		 \param fieldName Field(Column) ٣?

		 \~japanese
		 Field(Column) ��?�������ޫ���������?����?�����ң����?�ɪ��ު���
		 \param fieldName Field(Column) ٣

		 \~
		 */
		SQLULEN GetFieldMaxSize(const String& fieldName);

		/**
		 \~korean
		 Field(Column) �������� �Ҽ��� �Ʒ� ���е�(�ڸ���)�� �����ɴϴ�.
		 Real, Float, Double, Timestamp�� ���� ���Ŀ��� ����մϴ�.
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~english
		 Bring a decimal place of Field(Column) data.
		 It is used at types like Real, Float, Double and Timestamp.
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~chinese
		 ?��Field(Column)?�����?������������� ����?����
		 �?Real, Float, Double, Timestamp���������������ġ�
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~japanese
		 Field(Column) ��?�����?�������������?���������?�ɪ��ު���
		 Real, Float, Double, Timestamp�Ϊ誦�����Ҫ����Ī���ު���
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~
		 */
		SQLSMALLINT GetFieldPrecision(int fieldIndex);
		/**
		 \~korean
		 Field(Column) �������� �Ҽ��� �Ʒ� ���е�(�ڸ���)�� �����ɴϴ�.
		 Real, Float, Double, Timestamp�� ���� ���Ŀ��� ����մϴ�.
		 \param fieldName Field(Column) �̸�

		 \~english
		 Bring a decimal place of Field(Column) data.
		 It is used at types like Real, Float, Double and Timestamp.
		 \param fieldname It is the name of Field(Column).

		 \~chinese
		 ?��Field(Column)?�����?������������� ����?����
		 �?Real, Float, Double, Timestamp���������������ġ�
		 \param fieldName Field(Column)٣?

		 \~japanese
		 Field(Column) ��?�����?�������������?���������?�ɪ��ު���
		 Real, Float, Double, Timestamp�Ϊ誦�����Ҫ����Ī��ު���
		 \param fieldName Field(Column) ٣

		 \~
		 */
		SQLSMALLINT GetFieldPrecision(const String& fieldName);

		/**
		 \~korean
		 Field(Column) �����ͷ� NULL�� �Է��� �� �ִ���(�����ͺ��̽� ����)�� ��ȯ�մϴ�.
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~english
		 Return whether or not it can input NULL by Field(Column) data (Database setting).
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~chinese
		 ��?Field(Column) ?������ʦ�?�� NULL��?��??�ң�
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~japanese
		 Field(Column) ��?����NULL�������Ǫ��몫����?����?�����ң����������ު���
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~
		 */
		bool GetFieldNullable(int fieldIndex);
		/**
		 \~korean
		 Field(Column) �����ͷ� NULL�� �Է��� �� �ִ���(�����ͺ��̽� ����)�� ��ȯ�մϴ�.
		 \param fieldName Field(Column) �̸�

		 \~english
		 Return whether or not it can input NULL by Field(Column) data (Database setting).
		 \param fieldname It is the name of Field(Column).

		 \~chinese
		 ��?Field(Column) ?������ʦ�?�� NULL��?��??�ң�
		 \param fieldName Field(Column)٣?

		 \~japanese
		 Field(Column) ��?����NULL�������Ǫ��몫����?����?�����ң����������ު���
		 \param fieldName Field(Column) ٣

		 \~
		 */
		bool GetFieldNullable(const String& fieldName);

		/**
		 \~korean
		 Field(Column) �����͸� ��ȯ�մϴ�.
		 �����Ͱ� � ������ �� ��� GetFieldSqlType()�� �̿��Ͽ� �� �� �ֽ��ϴ�.
		 OdbcSqlDataType�� ���εǴ� Default OdbcDataType�� OdbcEnum.h�� ���� �Ͻʽÿ�.
		 ex> int a = recordset.GetFieldValue(1);
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~english
		 Return Field(Column) data.
		 In case you do not know the type of data, use GetFieldSqlType() to get to know. 
		 Refer to OdbcEnum.h for Default OdbcDataType that is mapped with OdbcSqlDataType.
		 ex> int a = recordset.GetFieldValue(1);
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~chinese
		 ��?Field(Column)?�ߡ�
		 ���Գ?�����?��������?����ʦ����� GetFieldSqlType()�Գ��
		 OdbcSqlDataType�� mapping Default OdbcDataType ??�� OdbcEnum.h��
		 ex> int a = recordset.GetFieldValue(1);
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~japanese
		 Field(Column) ��?�����������ު���
		 ��?��������ʪ�����GetFieldSqlType()�����Ī����몳�Ȫ��Ǫ��ު���
		 OdbcSqlDataType�ȫޫëԫ󫰪Ǫ���Default OdbcDataType��OdbcEnum.h��?�Ū���������
		 ex> int a = recordset.GetFieldValue(1);
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~
		 */
		const COdbcVariant& GetFieldValue(int fieldIndex);
		/**
		 \~korean
		 Field(Column) �����͸� ��ȯ�մϴ�.
		 �����Ͱ� � ������ �� ��� GetFieldSqlType()�� �̿��Ͽ� �� �� �ֽ��ϴ�.
		 OdbcSqlDataType�� ���εǴ� Default OdbcDataType�� OdbcEnum.h�� ���� �Ͻʽÿ�.
		 ex> int a = recordset.GetFieldValue("name");
		 \param fieldName Field(Column) �̸�

		 \~english
		 Return Field(Column) data.
		 In case you do not know the type of data, use GetFieldSqlType() to get to know. 
		 Refer to OdbcEnum.h for Default OdbcDataType that is mapped with OdbcSqlDataType.
		 ex> int a = recordset.GetFieldValue("name");
		 \param fieldname It is the name of Field(Column).

		 \~chinese
		 ��?Field(Column)?�ߡ�
		 ���Գ?�����?��������?����ʦ����� GetFieldSqlType()�Գ��
		 OdbcSqlDataType�� mapping Default OdbcDataType ??�� OdbcEnum.h��
		 ex> int a = recordset.GetFieldValue("name");
		 \param fieldName Field(Column) ٣?

		 \~japanese
		 Field(Column) ��?�����������ު���
		 ��?��������ʪ�����GetFieldSqlType()�����Ī����몳�Ȫ��Ǫ��ު���
		 OdbcSqlDataType�ȫޫëԫ󫰪����Default OdbcDataType�� OdbcEnum.h��?�Ū���������
		 ex> int a = recordset.GetFieldValue("name");
		 \param fieldName Field(Column) ٣

		 \~
		 */
		const COdbcVariant& GetFieldValue(const String& fieldName);

		// WARNING::���ο��� ���Ǵ� �Լ��Դϴ�. ������� ���ñ� �ٶ��ϴ�.
		// WARNING::Internal use only. Don't use this function.
		void SetEnvironment(COdbcConnection* conn, void *hstmt, const SQLLEN &rowcount);

	private:
		COdbcRecordsetImpl* m_pImpl;

		COdbcRecordset(const COdbcRecordset& other);
		COdbcRecordset& operator=(const COdbcRecordset& other);
	};
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif