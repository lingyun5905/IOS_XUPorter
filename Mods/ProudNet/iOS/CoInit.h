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

#include "BasicTypes.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup db_group
	*  @{
	*/

	/** 
	\~korean
	CoInitialize, CoUninitialize ȣ�� ���� �����.
	- �Ϲ������� CoInitialize�� CoUninitialize�� ȣ�� Ƚ���� ������ ����� �ϸ�, �� ������ ���� ȣ���ؾ� �ϴ� �޼����̴�.
	�ڼ��� ���� �� API�� ������ ������ ��.
	- ���� CoInitialize(), CoUninitialize()�� ȣ���ϴ� �ͺ��� �� Ŭ������ ���� ������ �����ϴ� ���� �� �������̴�.
	�� Ŭ������ �ڵ����� CoUninitialize()�� �ʿ��� �� ȣ���ϱ� �����̴�.
	
	\~english
	This method works in a set of CoInitialize and CoUninitialize call.
	- It needs to be called per each threads and normally the number of calls for CoInitialize and CoUninitialize should be balanced.
	Refer to API document for more detailed information.
	- It's safer to declare this class as a local variable rather than directly calling for CoInitialize() and CoUninitialize(),
	since it automatically calls for CoUninitialize() when needed.
	
	\~chinese
	CoInitialize, CoUninitialize��У??��
	- ����??CoInitialize��CoUninitialize����У�?�?�����������?����У��۰�ҡ�
	??��??����API���졣
	- ����������УCoInitialize()��CoUninitialize()۰�������?�ͱ?���??��?�ҡ�
	��?�?���CoUninitialize()��?��?�?��У��
	
	\~japanese
	CoInitialize, CoUninitialize �����󪷫ګ�����請�ު���
	- �����ܪˡ�CoInitialize��CoUninitialize����������?�˫Ы�󫹪�������驪����êơ�������ë�ܬ�������󪵪ʪ���Ъʪ�ʪ��᫽�ëɪǪ���
	�٪�������API��������?�Ϊ���������
	- ����CoInitialize(), CoUninitialize()�������󪹪��Ȫ��ϡ����Ϋ��髹���?����??����몷��۰����ê������ܪǪ���
	���Ϋ��髹����Ѫ�CoUninitialize()����驪Ȫ������������󪹪���Ǫ���
	\~
	*/
	class CCoInitializer
	{
		bool m_success;
	public:
		PROUD_API CCoInitializer();
		PROUD_API ~CCoInitializer();
	};

	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif