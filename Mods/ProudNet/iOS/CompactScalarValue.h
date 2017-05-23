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

namespace Proud
{
	// srcclr���� ���Ƿ� �����Ų API������ ����ڰ� ���� ���°� ����.
	template<typename Type>
	class CCompactScalarValue
	{
		// 1����Ʈ ó��.
		// ���������� ���ȴ�.
		inline void WriteByte(char a)
		{
			char* ptr = (char*)(m_filledBlock + m_filledBlockLength);
			// http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.faqs/ka15414.html �� ���ϸ�,
			// GCC�� char* Ÿ�Կ� ���ؼ� 1byte align�� �����ϰ� �۵��ϰ� �Ǿ��ִ�.
			// ��, �����Ϸ��� �˾Ƽ� 4byte align�� �°� �����ϰ� �۵��ȴ�. 
			// ���� ���� �ڵ�(marmalade������ memcpy���)�� ���ʿ��ϴ�. (memcpy(ptr, &a, sizeof(a));)
			*ptr = a;
			m_filledBlockLength += sizeof(char);
		}

		// 1����Ʈ ó��.
		// ���������� ���ȴ�.
		inline bool ReadByte(char &a)
		{
			if (m_extracteeLength + (int)sizeof(a) > m_srcLength)
				return false;

			// http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.faqs/ka15414.html �� ���ϸ�,
			// GCC�� char* Ÿ�Կ� ���ؼ� 1byte align�� �����ϰ� �۵��ϰ� �Ǿ��ִ�.
			// ��, �����Ϸ��� �˾Ƽ� 4byte align�� �°� �����ϰ� �۵��ȴ�. 
			// ���� ���� �ڵ�(marmalade������ memcpy���)�� ���ʿ��ϴ�. (memcpy(ptr, &a, sizeof(a));)
			a = *(char*)(m_src + m_extracteeLength);

			m_extracteeLength += sizeof(a);

			return true;
		}

		uint8_t* m_src;
		int m_srcLength;
	public:
		// MakeBlock���� ����
		uint8_t m_filledBlock[100];
		int m_filledBlockLength;

		// ExtractValue���� ����
		Type m_extractedValue;
		int m_extracteeLength; // read offset

		//////////////////////////////////////////////////////////////////////////
		// �б�/���� �ֿ� �Լ�

		// ��Ʈ��->��
		inline void MakeBlock(Type src)
		{
			m_filledBlockLength = 0;

			bool bNegative;	 // src�� �����ΰ�?
			if (src < 0)
			{
				bNegative = true;
				src = ~src; // ��: -64 => 63
			}
			else
			{
				bNegative = false;
			}

			while (1)
			{
				char oneByte = 0;
				oneByte = src & 0x7f;  // ���� 7��Ʈ
				src >>= 7;	// ���밪���� ����� ��Ʈ��ŭ ����

				if (src != 0)  // ���� �����ϱ� ���� �� ���� ��Ʈ�� ���ǰ� ������
				{
					WriteByte(oneByte | 0x80);  //  ���� ������ ������ �ǹ��ϴ� 8th bit�� set �� 1����Ʈ ���. �׸��� ���� ������.
				}
				else // ���� ����� ���� 6 or bit�� �ִ� ���
				{
					// ����� ���� 7bit�� ��� 1vvv vvvv 0s00 0000��, 6bit�� ��� 0svv vvvv�� ����Ѵ�.
					if (oneByte & 0x40)
					{
						WriteByte((oneByte | 0x80)); // 7�� ��Ʈ�� ����Ѵ�. 
						oneByte = 0;		// ���� �� �̻� ����� bit�� �����Ƿ� ���� byte������ 0���� zero bit�� ����.
					}

					if (bNegative)
						oneByte |= 0x40; // 6th bit�� sign bit�̴�.

					WriteByte(oneByte); // ����ϰ� ����
					break;
				}

			}
		}
		
		// ��->��Ʈ��
		inline bool ExtractValue(uint8_t* src, int srcLength)
		{
			m_extracteeLength = 0;
			m_src = src;
			m_srcLength = srcLength;

			char oneByte = 0;
			Type fillee = 0; // ���⿡ ������ byte���� ä����
			int leftShiftOffset = 0;

			while (1)
			{
				if (m_extracteeLength == 10)
					return false; // int64���� ������ �ִ� ũ��� 10��. �̸� �Ѿ�ٴ� ����, �����Ͱ� ���� ���� ���̴�.

				if (!ReadByte(oneByte))
					return false;  // �б� ���� ó��

				if ((oneByte & 0x80) == 0) // 8th bit�� ���������� �ڿ� �� ���� ���� ����.
				{
					fillee |= (Type(oneByte & 0x3f) << leftShiftOffset); // 6�� ���� ��Ʈ�� �о �� ä��

					if (oneByte & 0x40) // sign bit
						m_extractedValue = ~fillee;
					else
						m_extractedValue = fillee;

					return true;
				}
				else
				{
					// 7�� bit�� �о� ó���ϰ� �������� �� ó������.
					fillee |= (Type(oneByte & 0x7f) << leftShiftOffset);
					leftShiftOffset += 7;
				}
			}
		}
	};
}