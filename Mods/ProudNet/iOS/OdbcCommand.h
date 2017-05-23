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

#include "OdbcEnum.h"
#include "OdbcException.h"
#include "OdbcVariant.h"
#include "PNString.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	class COdbcCommandImpl;
	class COdbcConnection;
	class COdbcRecordset;

	/**
	 \~korean
	 Prepared Statement�� ó���ϱ� ���� Ŭ���� �Դϴ�.
	 COdbcConnection�� Execute�ʹ� �޸� �� �� ������ ������ �Ķ���� ���� �����Ͽ� ��� ����� �� �����մϴ�.
	 Input, Output, Input&Output �Ķ���Ͱ� �ʿ��� Stored Procedure�� ������ ���� ��� �˴ϴ�.

	 \~english
	 It is a class that deals with Prepared Statement.
	 It is useful for continuous use by changing parameter value of a query, differently from Execute in COdbcConnection.
	 Also used when executing Stored Procedure that Input, Output and  Input&Output parameter need. 

	 \~chinese
	 ?��Prepared Statement��class��
	 ?COdbcConnection�� Execute ���ң�����?���?�������query��???��?������??���ġ�
	 �?��Input, Output, Input&Output ??����� Stored Procedure?��������ġ�

	 \~japanese
	 Prepared Statement��?�⪹�몿��Ϋ��髹�Ǫ���
	 COdbcConnection�� Execute�Ȫ�춪ʪꡢ�������Ҫ��쪿������?��ѫ��?��������?�ڪ������Ī�?����������ء���ު���
	 Input, Output, Input&Output �ѫ��?������驪�Stored Procedure��?������Ȫ��˪����Ī���ު���


	 \~
	 */
	class COdbcCommand
	{
	public:
		COdbcCommand();
		~COdbcCommand();

		/**
		 \~korean
		 �������� �Է��� �� ����մϴ�.
		 �������� Value�� ?�� �Է��մϴ�. (ex> INSERT INTO test(id, name) VALUES(?, ?))
		 ���� ������ ����̳� ���̺� �̸�, �ʵ� �̸����� ?�� �Է��� �� �����ϴ�.
		 \param conn COdbcConnection ��ü
		 \param query ������

		 \~english
		 It is used when inputting a query.
		 Input the query as ?. (ex> INSERT INTO test(id, name) VALUES(?, ?)).
		 Table name and field name cannot be inputted as ?. 
		 \param conn COdbcConnection Object
		 \param query Query

		 \~chinese
		 �?��query����?���ġ�
		 ?query������Value?��?����(ex> INSERT INTO test(id, name) VALUES(?, ?))
		 ���?�����٤ֵ��table٣?��field٣?����ʦ?��?����
		 \param conn COdbcConnection ?��
		 \param query query����

		 \~japanese
		 ������?�������������������Ī��ު���.
		 ������?���� Value��?���������ު��� (ex> INSERT INTO test(id, name) VALUES(?, ?))
		 ����𶪤��٤ֵ���?�֫�٣���ի�?���٣�ʪɪ�?��������?�ު���
		 \param conn COdbcConnection ���֫�������
		 \param query������?��

		 \~
		 */
		void Prepare(COdbcConnection &conn, const String& query);

		/**
		 \~korean
		 Input �Ķ���͸� �Է��� �� ���˴ϴ�.
		 ������ ���� ���������� �����Ͽ� �����ϰ��� �� ��� ������ �������� �����͸� �Է��ϸ� �˴ϴ�.
		 �����ͷ� �Է��� ��� �ش� ������ Scope�� ���� ������ �߻����� �ʴ��� Ȯ���ؾ� �մϴ�.
		 1.	int a = 10;
		 2.	cmd.AppendInputParameter(a); // a�� ���� ����Ǿ� Call by Value �������� �۵��մϴ�.
		 3.	cmd.AppendInputParameter(&a); // a�� �ּҰ��� ����ϴ� Call by Pointer �������� �۵��մϴ�.

		 �Է� �����Ϳ� ���� sqlType�� �ڵ������� �����Ǳ� ������ �����ͺ��̽��� ��������� ���ϴ� Ÿ���� �ְ� ���� ��� OdbcSqlDataType�� �Է��ϸ� �˴ϴ�.
		 ex> int32_t Ÿ���� ������ int64_tŸ���� �����ͷ� �����ͺ��̽��� �ְ� ���� ���
		 1.	int a = 10;
		 2.	cmd.AppendInputParameter(a, OdbcSqlDataType_BIGINT);

		 ���� �����͸� �Է��� ��� Proud::COdbcByteData Ŭ������ �̿��ؾ� �մϴ�.
		 COdbcByteData�� �����ͷθ� �Է��� �� �ֽ��ϴ�.
		 1. unsigned char byte[10000] = "........................."; // 1000����Ʈ ������ �Է�
		 2. COdbcByteData byteData(byte, 1000, 10000);
		 3. cmd.AppendInputParameter(&byteData);

		 \~english
		 It is used when inputting ��Input parameter��.
		 You can just input data in the form of pointer in case you want to change variables only. 
		 In case of inputting in the form of pointer, you must check if there is problem occurred by scope of the relevant variable. 
		 1.         int a = 10;
		 2.         cmd.AppendInputParameter(a); // It is executed in the form of Call by Value as ��a�� is copied.
		 3.         cmd.AppendInputParameter(&a); // It is executed in the form of Call by Pointer that uses ��a�� address. 
		 
		 Depending on inputted data, sqlType is automatically decided, so in case you input a type you want in the database, you can input OdbcSqlDataType.
		 ex> In case of inputting variable whose type is int32_t as data whose type is int64_t, 
		 1.         int a = 10;
		 2.         cmd.AppendInputParameter(a, OdbcSqlDataType_BIGINT);
		 
		 In case of inputting binary data, you must use Proud::COdbcByteData class.
		 COdbcByteData is only allowed to be inputted by the pointer. 
		 1. unsigned char byte[10000] = "........................."; // Input 1,000 byte data.
		 2. COdbcByteData byteData(byte, 1000, 10000);
		 3. cmd.AppendInputParameter(&byteData);

		 \~chinese
		 ?�� Input???���ġ�
		 ������������?��????������?���pointer������?��?��?ʦ��
		 �pointer������?��?����??��???��Scope������??��??��
		 1.         int a = 10;
		 2.         cmd.AppendInputParameter(a); // a��?��?𤣬� Call by Value ����?����.
		 3.         �����cmd.AppendInputParameter(&a); // a��?��Call by Pointer ����?����
		 
		 ��?�?��?�������ң�sqlType?�??�ң����������?��?��٥?�ۯ�����type?��?��OdbcSqlDataType?ʦ��
		 ������?ex> int32_t type��??�int64_t type��?��ۯ��?��??
		 1.         int a = 10;
		 2.         cmd.AppendInputParameter(a, OdbcSqlDataType_BIGINT);
		 
		 ?���?�?��?��?���� Proud::COdbcByteData class��
		 COdbcByteData������pointer?����
		 1. ?��unsigned char byte[10000] = "........................."; // 1000 byte ?�ߡ�
		 2. COdbcByteData byteData(byte, 1000, 10000);
		 3. cmd.AppendInputParameter(&byteData);

		 \~japanese
		 Input �ѫ��?�������������������Ī���ު���
		 ??���������?�ܪ�?�ڪ���?�����誦�Ȫ������ꡢ�ݫ���?���Ҫǫ�?�����������ƪ���������
		 �ݫ���?�������������ꡢ��???��Scope�˪����𹪬?�檷�ʪ������㪹����驪�����ު���
		 1.         int a = 10;
		 2.         cmd.AppendInputParameter(a); // a����������?����Call by Value���Ҫ����Ѫ��ު���
		 3.         cmd.AppendInputParameter(&a); // a�Ϋ��ɫ쫹�������Ī���Call by Pointer���Ҫ����Ѫ��ު���

		 ������?���˪��sqlType������ܪ�̽�Ҫ���몿�ᡢ��?����?����٥���ܪ��Ъ૿���ת����쪿������˪�OdbcSqlDataType���������ƪ���������
		 ex> int32_t �����ת�??��int64_t�����תΫ�?���ǫ�?����?�������쪿������
		 1.         int a = 10;
		 2.         cmd.AppendInputParameter(a, OdbcSqlDataType_BIGINT);

		 �ѫ��ʫ��?���������������� Proud::COdbcByteData ���髹�����Ī��ƪ���������
		 COdbcByteData�ϫݫ���?�Ǫ��������Ǫ��ު���
		 1. unsigned char byte[10000] = "........................."; // 1000�Ы��ȫ�?������
		 2. COdbcByteData byteData(byte, 1000, 10000);
		 3. cmd.AppendInputParameter(&byteData);

		 \~
		 */
		void AppendInputParameter(const COdbcVariant &param, OdbcSqlDataType sqlType = OdbcSqlDataType_UNKNOWN);

		/**
		 \~korean
		 Output �Ķ���͸� ������ �� ���˴ϴ�.
		 �����͸� �޾ƾ� �ϹǷ� ������ �������θ� �����͸� �Է��� �� �ֽ��ϴ�.
		 �����ͷ� �Է��� ��� �ش� ������ Scope�� ���� ������ �߻����� �ʴ��� Ȯ���ؾ� �մϴ�.
		 1.	int a;
		 2.	cmd.AppendOutputParameter(&a);

		 �Է� �����Ϳ� ���� sqlType�� �ڵ������� �����Ǳ� ������ �����ͺ��̽��� ��������� ���ϴ� Ÿ���� �ְ� ���� ��� OdbcSqlDataType�� �Է��ϸ� �˴ϴ�.
		 ex> �����ͺ��̽��� ���� int64_t Ÿ���� �����͸� int32_tŸ���� ������ �ް� ���� ���
		 1.	int a;
		 2.	cmd.AppendOutputParameter(a, OdbcSqlDataType_BIGINT);

		 ���ڿ��� ���� ��� �ݵ�� Excute ���Ŀ� Proud::String Ŭ������ GetBuffer�� ReleaseBuffer�� ����ؾ� �մϴ�.
		 1. String str;
		 2. str.GetBuffer(100);
		 3. cmd.AppendOutputParameter(&str);
		 4. cmd.Execute();
		 5. str.ReleaseBuffer();
		 6. str.GetBuffer(100);	// 2, 4, 5�� �ݺ��ؾ� �մϴ�.
		 7. cmd.Execute();
		 8. str.ReleaseBuffer();

		 ���� �����͸� ���� ��� Proud::COdbcByteData Ŭ������ ����ؾ� �մϴ�.
		 COdbcByteData�� �����ͷθ� �Է��� �� �ֽ��ϴ�.
		 1. unsigned char byte[10000];
		 2. COdbcByteData byteData(byte, 0, 10000);
		 3. cmd.AppendOutputParameter(&byteData);
		 4. cmd.Execute();

		 \~english
		 It is used when designating ��Output parameter��.
		 You can only input data in the form of pointer in order to receive data. 
		 In case of inputting in the form of pointer, you must check if there is problem occurred by scope of the relevant variable. 
		 1.         int a;
		 2.         cmd.AppendOutputParameter(&a);
		 
		 Depending on inputted data, sqlType is automatically decided, so in case you input a type you want in the database, you can input OdbcSqlDataType.
		 ex> In case of receiving data whose type is int64_t as variable whose type is int32_t, 
		 1.         int a;
		 2.         cmd.AppendOutputParameter(a, OdbcSqlDataType_BIGINT);
		 
		 In case of receiving string, you must use GetBuffer�� ReleaseBuffer of Proud::String class before/after execution.
		 1. String str;
		 2. str.GetBuffer(100);
		 3. cmd.AppendOutputParameter(&str);
		 4. cmd.Execute();
		 5. str.ReleaseBuffer();
		 6. str.GetBuffer(100);       // You must repeat 2, 4 and 5.
		 7. cmd.Execute();
		 8. str.ReleaseBuffer();
		 
		 In case of receiving binary data, you must use Proud::COdbcByteData class. 
		 COdbcByteData is only allowed to be inputted by the pointer.
		 1. unsigned char byte[10000];
		 2. COdbcByteData byteData(byte, 0, 10000);
		 3. cmd.AppendOutputParameter(&byteData);
		 4. cmd.Execute();
		 
		 \~chinese
		 ���Output???���ġ�
		 �������?�ߣ��������pointer������?��?�ߡ�
		 �pointer������?��?����??��???��Scope������??��??��
		 1.         int a;
		 2.         cmd.AppendOutputParameter(&a);
		 
		 ��?�?��?�������ң�sqlType?�??�ң����������?��?��٥?�ۯ�����type?��?��OdbcSqlDataType?ʦ��
		 ������?ex> int32_t type��??�int64_t type��?��ۯ��?��??
		 1.         int a;
		 2.         cmd.AppendOutputParameter(a, OdbcSqlDataType_BIGINT);
		 
		 ����ݬ��?����?� Excute ��������Proud::String class�� GetBuffer�� ReleaseBuffer��
		 1. String str;
		 2. str.GetBuffer(100);
		 3. cmd.AppendOutputParameter(&str);
		 4. cmd.Execute();
		 5. str.ReleaseBuffer();
		 6. str.GetBuffer(100);       // ����?2, 4, 5
		 7. cmd.Execute();
		 8. str.ReleaseBuffer();
		 
		 ����?�?��?�������� Proud::COdbcByteData class��
		 COdbcByteData�����pointer������?����
		 1. unsigned char byte[10000];
		 2. COdbcByteData byteData(byte, 0, 10000);
		 3. cmd.AppendOutputParameter(&byteData);
		 4. cmd.Execute();

		 \~japanese
		 Output �ѫ��?������Ҫ���Ȫ����Ī���ު���
		 ��?���������몿��ݫ���?���ҪǪ�����?���������Ǫ��ު���
		 �ݫ���?�������������ꡢ��???��Scope�˪����𹪬?�檷�ʪ������㪹����驪�����ު���
		 1.         int a;
		 2.         cmd.AppendOutputParameter(&a);

		 ������?���˪��sqlType������ܪ�̽�Ҫ���몿���?����?����٥���ܪ��Ъ૿���ת����쪿�����ꡢOdbcSqlDataType���������ƪ���������
		 ex> ��?����?������int64_t�����תΫ�?����int32_t�����ת�??��������������
		 1.         int a;
		 2.         cmd.AppendOutputParameter(a, OdbcSqlDataType_BIGINT);
		 
		 ���֪�����������ꡢ����Excute������Proud::String���髹��GetBuffer��ReleaseBuffer�����Ī��ƪ���������
		 1. String str;
		 2. str.GetBuffer(100);
		 3. cmd.AppendOutputParameter(&str);
		 4. cmd.Execute();
		 5. str.ReleaseBuffer();
		 6. str.GetBuffer(100);       // 2, 4, 5���۪������ƪ���������
		 7. cmd.Execute();
		 8. str.ReleaseBuffer();
		 
		 �ѫ��ʫ��?��������������Proud::COdbcByteData���髹�����Ī��ƪ���������
		 CodbcByteData�ϫݫ���?�Ǫ��������Ǫ��ު���
		 1. unsigned char byte[10000];
		 2. COdbcByteData byteData(byte, 0, 10000);
		 3. cmd.AppendOutputParameter(&byteData);
		 4. cmd.Execute();

		 \~
		 */
		void AppendOutputParameter(const COdbcVariant &param, OdbcSqlDataType sqlType = OdbcSqlDataType_UNKNOWN);

		/**
		 \~korean
		 Input&Output �Ķ���͸� ������ �� ���˴ϴ�.
		 �����͸� �޾ƾ� �ϹǷ� ������ �������θ� �����͸� �Է��� �� �ֽ��ϴ�.
		 �����ͷ� �Է��� ��� �ش� ������ Scope�� ���� ������ �߻����� �ʴ��� Ȯ���ؾ� �մϴ�.
		 1.	int a;
		 2.	cmd.AppendInputOutputParameter(&a);

		 �Է� �����Ϳ� ���� sqlType�� �ڵ������� �����Ǳ� ������ �����ͺ��̽��� ��������� ���ϴ� Ÿ���� �ְ� ���� ��� OdbcSqlDataType�� �Է��ϸ� �˴ϴ�.
		 ex> int32_tŸ���� ������ int64_t Ÿ���� �����ͷ� �����ͺ��̽��� ���� ����� �ϰ� ���� ���
		 1.	int a;
		 2.	cmd.AppendInputOutputParameter(a, OdbcSqlDataType_BIGINT);

		 ���ڿ��� ����� �� ��� �ݵ�� Excute ���Ŀ� Proud::String Ŭ������ GetBuffer�� ReleaseBuffer�� ����ؾ� �մϴ�.
		 1. String str;
		 2. str = "ABCD";	// 2, 3�� ������ �ٲ�� �ȵ˴ϴ�.
		 3. str.GetBuffer(100);
		 4. cmd.AppendInputOutputParameter(&str);
		 5. cmd.Execute();
		 6. str.ReleaseBuffer();
		 7. str = "EFGH"; // 2, 3, 5, 6�� �ݺ��ؾ� �մϴ�.
		 8. str.GetBuffer(100);
		 9. cmd.Execute();
		 10. str.ReleaseBuffer();

		 ���� �����͸� ���� ��� Proud::COdbcByteData Ŭ������ ����ؾ� �մϴ�.
		 COdbcByteData�� �����ͷθ� �Է��� �� �ֽ��ϴ�.
		 1. unsigned char byte[10000];
		 2. COdbcByteData byteData(byte, 0, 10000);
		 3. cmd.AppendOutputParameter(&byteData);
		 4. cmd.Execute();

		 \~english
		 It is used when designating ��Input&Output parameter��.
		 You can only input data in the form of pointer in order to receive data. 
		 In case of inputting in the form of pointer, you must check if there is problem occurred by scope of the relevant variable. 
		 1.         int a;
		 2.         cmd.AppendInputOutputParameter(&a);
		 
		 Depending on inputted data, sqlType is automatically decided, so in case you input a type you want in the database, you can input OdbcSqlDataType.
		 ex> In case of inputting & outputting variable whose type is int32_t as data whose type is int64_t, 
		 1.         int a;
		 2.         cmd.AppendInputOutputParameter(a, OdbcSqlDataType_BIGINT);
		 
		 In case of inputting & outputting string, you must use GetBuffer�� ReleaseBuffer of Proud::String class before/after execution.
		 1. String str;
		 2. str = "ABCD";  // 2 and 3 must be right order. 
		 3. str.GetBuffer(100);
		 4. cmd.AppendInputOutputParameter(&str);
		 5. cmd.Execute();
		 6. str.ReleaseBuffer();
		 7. str = "EFGH"; // You must repeat 2,3,5 and 6. 
		 8. str.GetBuffer(100);
		 9. cmd.Execute();
		 10. str.ReleaseBuffer();
		 
		 In case of receiving binary data, you must use Proud::COdbcByteData class. 
		 COdbcByteData is only allowed to be inputted by the pointer.
		 1. unsigned char byte[10000];
		 2. COdbcByteData byteData(byte, 0, 10000);
		 3. cmd.AppendOutputParameter(&byteData);
		 4. cmd.Execute();
		 
		 \~chinese
		 ���Input&Output???���ġ�
		 �������?�ߣ��������pointer������?��?�ߡ�
		 �pointer������?��?����??��???��Scope������??��??��
		 1.         int a;
		 2.         cmd.AppendInputOutputParameter(&a);
		 
		 ��?�?��?�������ң�sqlType?�??�ң����������?��?��٥?�ۯ�����type?��?��OdbcSqlDataType?ʦ��
		 ������?ex> int32_t type��??�int64_t type��?��ۯ��?��??
		 1.         int a;
		 2.         cmd.AppendInputOutputParameter(a, OdbcSqlDataType_BIGINT);
		 
		 ����ݬ��?����?� Excute ��������Proud::String class�� GetBuffer�� ReleaseBuffer��
		 1. String str;
		 2. str = "ABCD";  // ��ʦ??2, 3��?��
		 3. str.GetBuffer(100);
		 4. cmd.AppendInputOutputParameter(&str);
		 5. cmd.Execute();
		 6. str.ReleaseBuffer();
		 7. str = "EFGH"; // ����?2, 3, 5, 6
		 8. str.GetBuffer(100);
		 9. cmd.Execute();
		 10. str.ReleaseBuffer();
		 
		 ����?�?��?�������� Proud::COdbcByteData class��
		 COdbcByteData�����pointer������?����
		 1. unsigned char byte[10000];
		 2. COdbcByteData byteData(byte, 0, 10000);
		 3. cmd.AppendOutputParameter(&byteData);
		 4. cmd.Execute();

		 \~japanese
		 Input&Output �ѫ��?������Ҫ���Ȫ������Ī���ު���
		 ��?���������몿�ᡢ�ݫ���?���ҪǪ�����?���������Ǫ��ު���
		 �ݫ���?����������������???��Scope�˪����𹪬?�檷�ʪ������㪹����驪�����ު���
		 1.         int a;
		 2.         cmd.AppendInputOutputParameter(&a);

		 ������?���˪��sqlType������ܪ�̽�Ҫ���몿���?����?����٥���ܪ��Ъ૿���ת����쪿������OdbcSqlDataType���������ƪ���������
		 ex> int32_t�����ת�??��int64_t �����תΫ�?���ǫ�?����?����������������������
		 1.         int a;
		 2.         cmd.AppendInputOutputParameter(a, OdbcSqlDataType_BIGINT);
		 
		 ���֪��������������������Excute������Proud::String���髹��GetBuffer��ReleaseBuffer�����Ī��ƪ���������
		 1. String str;
		 2. str = "ABCD";  // 2, 3�����㪬?���ʪ��誦�˪���򪯪�������
		 3. str.GetBuffer(100);
		 4. cmd.AppendInputOutputParameter(&str);
		 5. cmd.Execute();
		 6. str.ReleaseBuffer();
		 7. str = "EFGH"; // 2, 3, 5, 6���۪������ƪ���������
		 8. str.GetBuffer(100);
		 9. cmd.Execute();
		 10. str.ReleaseBuffer();
		 
		 �ѫ��ʫ��?��������������Proud::COdbcByteData���髹�����Ī�����驪�����ު���
		 COdbcByteData�ϫݫ���?�Ǫ��������Ǫ��ު���
		 1. unsigned char byte[10000];
		 2. COdbcByteData byteData(byte, 0, 10000);
		 3. cmd.AppendOutputParameter(&byteData);
		 4. cmd.Execute();

		 \~
		 */
		void AppendInputOutputParameter(const COdbcVariant &param, OdbcSqlDataType sqlType = OdbcSqlDataType_UNKNOWN);

		/**
		 \~korean
		 �Ķ���͸� NULL ���¸� �����մϴ�.
		 DB�� �����͸� NULL�� �Է��ϰ� ���� ��� �� �Լ��� �̿��� NULL ���¸� TRUE�� ���� �մϴ�.
		 �ѹ� ������ ���´� ���������� ���ǹǷ� �� ���·� ������ ���ؼ� Execute �Ŀ� FALSE�� �ٽ� �����ؾ� �մϴ�.
		 \param paramIndex �Ķ���� Index (ex> 1, 2, 3, ...)
		 \param state true or false

		 \~english
		 Set a parameter as NULL.
		 In case you want to input data as NULL in the database, change the status of NULL to TRUE by using this function.
		 Once setting is done, the status is continuously used, so in case of restring the status, you must reset it as FALSE after execution. 
		 \param paramIndex parameter Index (ex> 1, 2, 3, ...)
		 \param state true or false
		 
		 \~chinese
		 ????��? NULL??��
		 �������DB?��NULL?��?������?��?? NULL ???��?TRUE??��
		 ��?�������???���������ģ���?��?ꫣ���� Execute���FALSE??����?�ǡ�
		 \param paramIndex �Ķ���� Index (ex> 1, 2, 3, ...)
		 \param state true or false

		 \~japanese
		 �ѫ��?���� NULL?�������Ҫ��ު���
		 DB�˫�?����NULL���������������ꡢ����??�����Ī�NULL?����TRUE��?�ڪ��ު���
		 �������Ҫ��쪿?�����?�ܪ����Ī���몿��ꪪ�?����?������˪�Execute����FALSE�Ǫ⪦�������ëƫ��󫰪�����驪�����ު���
		 \param paramIndex �ѫ��?��Index (ex> 1, 2, 3, ...)
		 \param state true or false

		 \~
		 */
		void SetNullParameter(unsigned int paramIndex, bool state);

		/**
		 \~korean
		 ������ �����մϴ�.
		 ���� �������� ������ ���� Row ������ ��ȯ�մϴ�.

		 \~english
		 Execute the query.

		 \~chinese
		 ?��query��

		 \~japanese
		 ������?��?�����ު���

		 \~
		 */
		int Execute(COdbcWarnings* odbcWarnings = NULL);

		/**
		 \~korean
		 ������ �����մϴ�.
		 ���� �������� ������ ���� Row ������ ��ȯ�մϴ�.
		 \param recordset ���� ������ �޾����� Recordset ��ü

		 \~english
		 Execute the query.
		 \param recordset It is a Recordset object that is received after query execution.

		 \~chinese
		 ?��query��
		 \param recordset query ?����������� Recordset ?��

		 \~japanese
		 ������?��?�����ު���
		 \param recordset ������??����������Recordset���֫�������

		 \~
		 */
		int Execute(COdbcRecordset &recordset, COdbcWarnings* odbcWarnings = NULL);

	private:
		COdbcCommandImpl* m_pImpl;

		// ���� ����
		COdbcCommand(const COdbcCommand& other);
		COdbcCommand& operator=(const COdbcCommand& other);
	};
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif