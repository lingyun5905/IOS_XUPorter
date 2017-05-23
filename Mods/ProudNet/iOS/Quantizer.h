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

#include "ProcHeap.h"
#include "Exception.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

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
	<a target="_blank" href="http://guide.nettention.com/cpp_ko#quantizer" >������ ����ȭ</a> ����� ����ϴ� Ŭ�����Դϴ�.

	\~english
	Class manages <a target="_blank" href="http://guide.nettention.com/cpp_en#quantizer" >Data Quantization</a> function

	\~chinese
	?��<a target="_blank" href="http://guide.nettention.com/cpp_zh#quantizer" >?�������</a>%������? ��

	\~japanese
	\ref quantizer  Ѧ����??���뫯�髹�Ǫ���
	\~
	*/
	class CQuantizer
	{
		double m_min,m_max;
		uint32_t m_granulation;
	public:
		/** 
		\~korean
		������
		\param min ����ȭ�Ǵ� ���� �� �� ���Ϸδ� ���� �ʽ��ϴ�.
		\param max ����ȭ�Ǵ� ���� �� �� �̻����δ� ���� �ʽ��ϴ�.
		\param granulation ����ȭ�Ǵ� ���� ���� Ÿ���Դϴ�. �� ���� ����ȭ�Ǵ� ���� 0���� �󸶱����� ���������� ��ȯ�Ǵ��ĸ� ��Ī�մϴ�.
		���� Ŭ���� ����ȭ�� ���� ���е��� ������ ����ȭ�� �����Ͱ� �ʿ�� �ϴ� ��Ʈ���� �����ϰ� �˴ϴ�. 

		\~english
		Constructor
		\param min the quantized value will not be entered and no less than this value.
		\param max the quantized value will not be entered and no more than this value.
		\param granulation the quantized value has integer type. This value points that the quantized value is to be converted from 0 to which integer.
		Larger value provides more pricise quantized value but the number of bits required by quantized data.

		\~chinese
		�����
		\param min ?���������?��������?��
		\param ma ?���������?���������?��
		\param granulation �������?����??���?���?�������?????0���������??��
		?���ޣ��������?�������ޣ�ӣ���������?�������bit??��ʥ��

		\~japanese
		�����
		\param min �������������Ϫ���������˪�����ު���
		\param min �������������Ϫ���������˪�����ު���
		\param max ����ȭ�Ǵ� ���� �� �� ���Ϸδ� ���� �ʽ��ϴ�.
		\param granulation ����������������?�����תǪ�������������������������0���骤����ުǪ���?����?������몫��򦪷�ު���
		�����ު����۪���������쪿�������������Ԫ��Ǫ�������������쪿��?������驪Ȫ���ӫë�?��?ʥ���ު���
		\~
		*/
		CQuantizer( double min, double max, uint32_t granulation )
		{
			m_min = min;
			m_max = max;
			m_granulation = granulation;
		}

		/** 
		\~korean
		����ȭ�� �մϴ�. 

		\~english
		Quantizing

		\~chinese
		?���������

		\~japanese
		������򪷪ު���
		\~
		*/
		uint32_t Quantize(double value)
		{
			value = PNMIN(m_max, value);
			value = PNMAX(m_min, value);
			double range = m_max - m_min;
			double offset = value - m_min;
			double offset2 = offset / range * (double)m_granulation;
			return (uint32_t)offset2;
		}

		/** 
		\~korean
		����ȭ�� ���� �����մϴ�. 

		\~english
		Recover quantized value

		\~chinese
		��?�������?��

		\~japanese
		��������쪿������ꪪ��ު���
		\~
		*/
		double Dequantize(uint32_t value)
		{
			double offset = (double)value;
			double range = m_max - m_min;
			double offset2 = offset / (double)m_granulation * range;
			return offset2 + m_min;
		}

#ifdef _WIN32
#pragma push_macro("new")
#undef new
		// �� Ŭ������ ProudNet DLL ��츦 ���� Ŀ���� �Ҵ��ڸ� ���� fast heap�� ���� �ʴ´�.
		DECLARE_NEW_AND_DELETE
#pragma pop_macro("new")
#endif
	};


	/**  @} */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif