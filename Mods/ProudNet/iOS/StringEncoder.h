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
	/** \addtogroup util_group
	*  @{
	*/

	class CPnIconv;
	class CStringEncoderImpl;

	/** 
	\~korean
	iconv ���� Ŭ�����Դϴ�.
	- Create�� ���� �� �ʿ��� ������ ���� �����μ� GetIconv-ReleaseIconv�� ���ø� �˴ϴ�.
	- ���� �����忡���� ���� ������ ���� ������Ʈ Ǯ���� ���·� iconv ��ü�� �����մϴ�. 
	���� �ӵ��� �����ϴ�. 

	ProudNet�� ���ڿ� ó���� ���� ���������� �̰��� ����ؼ� �۵��մϴ�. 
	���ſ��� win32 ����� ��������� ��Ƽ�÷��� ����ȭ�� ���ؼ��Դϴ�.

	\~english
	It is a wrapper class. 
	- After creating by ��create��, you can use GetIconv-ReleaseIconv as the local variable whenever needed. 
	- iconv objective is provided as the form of object pooling for concurrent access to many threads. 
	As a result of this, it is fast. 

	ProudNet used win32 function in the past but for unifying multi-platform, it uses this in Windows for string processing.

	\~chinese
	iconv ����??��
	- ��Create������������?����?������GetIconv-ReleaseIconv?ʦ��
	- �����??����??����?������?������ң����iconv?�ڡ��������?�ᡣ 

	??���ݬ����ProudNet�Windows��������iconv?����
	?��������win32������ӣ?�����iconv��?����������?������

	\~japanese
	iconv��wrapper���髹�Ǫ���.
	- Create���������ƪ�����驪����˫�?����??�Ȫ��� GetIconv-ReleaseIconv���Ūêƪ���������
	- ��?�ʫ���ëɪǪ��������ΪΪ���Ϋ��֫�������?��󫰪������� iconv ���֫������Ȫ���ꪷ�ު��� 
	���������ê��������ܪ��Ǫ���

	 ProudNet�����֪?��Ϊ����Windows�Ǫ⪳����Ūê����Ѫ��ު��� 
	 Φ�۪˪� win32Ѧ�������Ī��ު���������ϫޫ���׫�ëȫի�?��?�����Ϊ�����Ϊ誦��?�ڪ���ު�����

	\~

	Example code:
	\code
	StringA2W(a, b); // use platform-specific default encoder

	// use the encoder you select
	shared_ptr<CStringEncoder> e(CStringEncoder::Create("UTF-8", "UTF-16LE"));
	StringA2W(a, b, e);
	\endcode

	*/
	class CStringEncoder
	{
	private:
		CStringEncoder(const char* srcCodepage, const char* destCodepage);
	public:
		static CStringEncoder* Create(const char* srcCodepage, const char* destCodepage);
		virtual ~CStringEncoder();
		CPnIconv* GetIconv();
		void ReleaseIconv(CPnIconv *obj);
	private:
		CStringEncoderImpl* m_pimpl;
	};

	PROUD_API void iconv_string_convert(CStringEncoder* encoder, const char* input, size_t* inbytesleft, char* out, size_t* outbytesleft);

/**  @} */
}
#ifdef _MSC_VER
#pragma pack(pop)
#endif