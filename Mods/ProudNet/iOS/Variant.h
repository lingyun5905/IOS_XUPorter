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

// NOTE: �� ����� ���� �����̴�. UE4 ����� OLE-COM API�� ��� �Ұ��ϹǷ�.

#if defined(_WIN32)
    #include <comutil.h>
#endif

#include "ByteArrayPtr.h"
#include "pnguid-win32.h"
#include "./FakeClrBase.h"
#include "./PnTime.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup db_group
	*  @{
	*/

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4244)
#endif

#if defined(_WIN32)
	extern _variant_t ToVariant(LONGLONG x);
	extern _variant_t ToVariant(ULONGLONG x);
	extern LONGLONG ToLongLong(const _variant_t &r);
	extern ULONGLONG ToULongLong(const _variant_t &r);

	/** 
	\~korean
	variant.
	_variant_t�� ����� ������ ������, UUID, int64 ���� ó�� ����� �ΰ������� �� �ִ�.
	- �� ��ü�� UUID�� bracket string���� ��ȯ�ؼ� ������.
	- �� ��ü�� int64�� VariantChangeType()��� ��ü ������ ��ȯ�⸦ ������. 
	(VariantChangeType���� 64bit integer ������ Windows XP�������� �����ϱ� �����̴�.) 

	\~english
	variant.
	This module works similar to _variant_t, but additionally handles UUID, int64 and etc.
	- This object has an UUID after converting it to braket string.
	- This object has a custom converter of int64 instead of VariantChangeType(). 
	(Because VariantChangeType���� 64bit integer is already supported in Windows XP.)

	\~chinese
	variant.
	���?_variant_���������ģ�ӣ?��?��ʥ��UUID, int64��?��������
	- �?����UUID��bracket string??�?����
	- �?��?������VariantChangeType()?int64?�����??��??����
	���VariantChangeType����64bit integer����??Windows XP?��򥡣��

	\~japanese
	variant.
	_variant_t��׾�Ī�����ܪ򪷪ު�����UUID��int64�ʪɪ�?��Ѧ������ʥ�ܪ����êƪ��ު���
	- ���Ϋ��֫������Ȫ�UUID��bracket string��?���������ު���
	- ���Ϋ��֫������Ȫ�int64��VariantChangeType()���۪�����?�ު���?��������ު��� 
	(VariantChangeType�Ǫ�64bit integer�Ϋ���?�Ȫϡ�Windows XP���髵��?�Ȫ��몫��Ǫ���) 
	\~
	*/
	class CVariant
	{
	public:
		_variant_t m_val;

		// �Ʒ� ���� constructor���� _variant_t���� ���� ���̴�. �ʿ��� ��� 
		// �̷��� �͵�(constructor,operator=,extractor operator)�� ���鵵�� ����. 
		inline CVariant() {}
		inline CVariant(const _variant_t &src) { m_val=src; }
		inline CVariant(VARENUM vartype){V_VT(&m_val) = vartype;}

		inline CVariant(char a) { m_val=(long)a; }
		inline CVariant(short a) { m_val=(long)a; }
		inline CVariant(int a) { m_val=(long)a; }
		inline CVariant(long a) { m_val=a; }
		inline CVariant(int64_t a) { m_val=ToVariant(a); } // Windows 2000 ȣȯ�� ����
		inline CVariant(unsigned char a) { m_val=a; }
		inline CVariant(unsigned short a) { m_val=a; }
		inline CVariant(unsigned int a) { m_val=a; }
		inline CVariant(unsigned long a) { m_val=a; }
		inline CVariant(uint64_t a) { m_val=ToVariant(a); } // Windows 2000 ȣȯ�� ����
		inline CVariant(float a) { m_val=a; }
		inline CVariant(double a) { m_val=a; }
		inline CVariant(const wchar_t* a) { m_val = _bstr_t(a); }
		inline CVariant(const char* a) { m_val=_bstr_t(a); }
		inline CVariant(const String& a) { m_val=_bstr_t(a); }
		inline CVariant(UUID a) { m_val = Win32Guid::From(a).ToBracketString(); }
		inline CVariant(Guid a) { m_val = a.ToBracketString(); }
		inline CVariant(bool a) { m_val=(long)a; }
		inline CVariant(const CPnTime& a) { m_val=a.m_dt; m_val.vt=VT_DATE; }
		inline CVariant(const ByteArray& a){FromByteArray(a);}
		inline CVariant(const ByteArrayPtr a){FromByteArray(a);}

		/** 
		\~korean
		���ϰ� �������Դϴ�. ���� �� ��ü�� null ���� ���� ������ ���ܰ� throw�˴ϴ�. ���� �ʿ��� ��� IsNull()�� ���� null���� ���θ� Ȯ���Ͻʽÿ�. 

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		����??ߩݬ�������?��?��null?��?������?��throw����������?���IsNull()??null��?����

		\~japanese
		�꫿?������ߩ�Ǫ����⪷�����Ϋ��֫������Ȫ�null�����êƪ�������⪬throw�˪ʪ�ު�����êơ���驪����ꡢIsNull()�Ǫު�null�ʪΪ��ɪ��������㪷�ƪ��������� 
		\~
		*/
		inline operator char() const { ThrowIfNull(); return (long)m_val; }

		/** 
		\~korean
		���ϰ� �������Դϴ�. ���� �� ��ü�� null ���� ���� ������ ���ܰ� throw�˴ϴ�. ���� �ʿ��� ��� IsNull()�� ���� null���� ���θ� Ȯ���Ͻʽÿ�. 

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		����??ߩݬ�������?��?��null?��?������?��throw����������?���IsNull()??null��?����

		\~japanese
		�꫿?������ߩ�Ǫ����⪷�����Ϋ��֫������Ȫ�null�����êƪ�������⪬throw�˪ʪ�ު�����êơ���驪����ꡢIsNull()�Ǫު�null�ʪΪ��ɪ��������㪷�ƪ��������� 
		\~
		*/
		inline operator short() const { ThrowIfNull(); return (long)m_val; }

		/** 
		\~korean
		���ϰ� �������Դϴ�. ���� �� ��ü�� null ���� ���� ������ ���ܰ� throw�˴ϴ�. ���� �ʿ��� ��� IsNull()�� ���� null���� ���θ� Ȯ���Ͻʽÿ�. 

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		����??ߩݬ�������?��?��null?��?������?��throw����������?���IsNull()??null��?����

		\~japanese
		�꫿?������ߩ�Ǫ����⪷�����Ϋ��֫������Ȫ�null�����êƪ�������⪬throw�˪ʪ�ު�����êơ���驪����ꡢIsNull()�Ǫު�null�ʪΪ��ɪ��������㪷�ƪ��������� 
		\~
		*/
		inline operator int() const { ThrowIfNull(); return (long)m_val; }

		/** 
		\~korean
		���ϰ� �������Դϴ�. ���� �� ��ü�� null ���� ���� ������ ���ܰ� throw�˴ϴ�. ���� �ʿ��� ��� IsNull()�� ���� null���� ���θ� Ȯ���Ͻʽÿ�. 

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		����??ߩݬ�������?��?��null?��?������?��throw����������?���IsNull()??null��?����

		\~japanese
		�꫿?������ߩ�Ǫ����⪷�����Ϋ��֫������Ȫ�null�����êƪ�������⪬throw�˪ʪ�ު�����êơ���驪����ꡢIsNull()�Ǫު�null�ʪΪ��ɪ��������㪷�ƪ��������� 
		\~
		*/
		inline operator long() const { ThrowIfNull(); return m_val; }

		/** 
		\~korean
		���ϰ� �������Դϴ�. ���� �� ��ü�� null ���� ���� ������ ���ܰ� throw�˴ϴ�. ���� �ʿ��� ��� IsNull()�� ���� null���� ���θ� Ȯ���Ͻʽÿ�. 

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		����??ߩݬ�������?��?��null?��?������?��throw����������?���IsNull()??null��?����

		\~japanese
		�꫿?������ߩ�Ǫ����⪷�����Ϋ��֫������Ȫ�null�����êƪ�������⪬throw�˪ʪ�ު�����êơ���驪����ꡢIsNull()�Ǫު�null�ʪΪ��ɪ��������㪷�ƪ��������� 
		\~
		*/
		inline operator unsigned char() const { ThrowIfNull(); return m_val; }

		/** 
		\~korean
		���ϰ� �������Դϴ�. ���� �� ��ü�� null ���� ���� ������ ���ܰ� throw�˴ϴ�. ���� �ʿ��� ��� IsNull()�� ���� null���� ���θ� Ȯ���Ͻʽÿ�.

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		����??ߩݬ�������?��?��null?��?������?��throw����������?���IsNull()??null��?����

		\~japanese
		�꫿?������ߩ�Ǫ����⪷�����Ϋ��֫������Ȫ�null�����êƪ�������⪬throw�˪ʪ�ު�����êơ���驪����ꡢIsNull()�Ǫު�null�ʪΪ��ɪ��������㪷�ƪ��������� 
		\~
		*/
		inline operator unsigned short() const { ThrowIfNull(); return m_val; }

		/** 
		\~korean
		���ϰ� �������Դϴ�. ���� �� ��ü�� null ���� ���� ������ ���ܰ� throw�˴ϴ�. ���� �ʿ��� ��� IsNull()�� ���� null���� ���θ� Ȯ���Ͻʽÿ�. 

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		����??ߩݬ�������?��?��null?��?������?��throw����������?���IsNull()??null��?����

		\~japanese
		�꫿?������ߩ�Ǫ����⪷�����Ϋ��֫������Ȫ�null�����êƪ�������⪬throw�˪ʪ�ު�����êơ���驪����ꡢIsNull()�Ǫު�null�ʪΪ��ɪ��������㪷�ƪ��������� 
		\~
		*/
		inline operator unsigned int() const { ThrowIfNull(); return m_val; }

		/** 
		\~korean
		���ϰ� �������Դϴ�. ���� �� ��ü�� null ���� ���� ������ ���ܰ� throw�˴ϴ�. ���� �ʿ��� ��� IsNull()�� ���� null���� ���θ� Ȯ���Ͻʽÿ�. 

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		����??ߩݬ�������?��?��null?��?������?��throw����������?���IsNull()??null��?����

		\~japanese
		�꫿?������ߩ�Ǫ����⪷�����Ϋ��֫������Ȫ�null�����êƪ�������⪬throw�˪ʪ�ު�����êơ���驪����ꡢIsNull()�Ǫު�null�ʪΪ��ɪ��������㪷�ƪ��������� 
		\~
		*/
		inline operator unsigned long() const { ThrowIfNull(); return m_val; }

		/** 
		\~korean
		���ϰ� �������Դϴ�. ���� �� ��ü�� null ���� ���� ������ ���ܰ� throw�˴ϴ�. ���� �ʿ��� ��� IsNull()�� ���� null���� ���θ� Ȯ���Ͻʽÿ�. 

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		����??ߩݬ�������?��?��null?��?������?��throw����������?���IsNull()??null��?����

		\~japanese
		�꫿?������ߩ�Ǫ����⪷�����Ϋ��֫������Ȫ�null�����êƪ�������⪬throw�˪ʪ�ު�����êơ���驪����ꡢIsNull()�Ǫު�null�ʪΪ��ɪ��������㪷�ƪ��������� 
		\~
		*/
		inline operator float() const { ThrowIfNull(); return m_val; }

		/** 
		\~korean
		���ϰ� �������Դϴ�. ���� �� ��ü�� null ���� ���� ������ ���ܰ� throw�˴ϴ�. ���� �ʿ��� ��� IsNull()�� ���� null���� ���θ� Ȯ���Ͻʽÿ�. 

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		����??ߩݬ�������?��?��null?��?������?��throw����������?���IsNull()??null��?����

		\~japanese
		�꫿?������ߩ�Ǫ����⪷�����Ϋ��֫������Ȫ�null�����êƪ�������⪬throw�˪ʪ�ު�����êơ���驪����ꡢIsNull()�Ǫު�null�ʪΪ��ɪ��������㪷�ƪ��������� 
		\~
		*/
		inline operator double() const { ThrowIfNull(); return m_val; }

		/**
		\~korean
		���ϰ� �������Դϴ�. ���� �� ��ü�� null ���� ���� ������ ���ܰ� throw�˴ϴ�. ���� �ʿ��� ��� IsNull()�� ���� null���� ���θ� Ȯ���Ͻʽÿ�. 

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		����??ߩݬ�������?��?��null?��?������?��throw����������?���IsNull()??null��?����

		\~japanese
		�꫿?������ߩ�Ǫ����⪷�����Ϋ��֫������Ȫ�null�����êƪ�������⪬throw�˪ʪ�ު�����êơ���驪����ꡢIsNull()�Ǫު�null�ʪΪ��ɪ��������㪷�ƪ��������� 
		\~
		*/
		inline operator String() const { ThrowIfNull(); return String((const PNTCHAR*)(_bstr_t)m_val); }

		/** 
		\~korean
		���ϰ� �������Դϴ�. ���� �� ��ü�� null ���� ���� ������ ���ܰ� throw�˴ϴ�. ���� �ʿ��� ��� IsNull()�� ���� null���� ���θ� Ȯ���Ͻʽÿ�. 

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		����??ߩݬ�������?��?��null?��?������?��throw����������?���IsNull()??null��?����

		\~japanese
		�꫿?������ߩ�Ǫ����⪷�����Ϋ��֫������Ȫ�null�����êƪ�������⪬throw�˪ʪ�ު�����êơ���驪����ꡢIsNull()�Ǫު�null�ʪΪ��ɪ��������㪷�ƪ��������� 
		\~
		*/
		inline operator UUID() const { ThrowIfNull(); return Win32Guid::ToNative(Guid::GetFromString((_bstr_t)m_val)); }

		/** 
		\~korean
		���ϰ� �������Դϴ�. ���� �� ��ü�� null ���� ���� ������ ���ܰ� throw�˴ϴ�. ���� �ʿ��� ��� IsNull()�� ���� null���� ���θ� Ȯ���Ͻʽÿ�. 

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		����??ߩݬ�������?��?��null?��?������?��throw����������?���IsNull()??null��?����

		\~japanese
		�꫿?������ߩ�Ǫ����⪷�����Ϋ��֫������Ȫ�null�����êƪ�������⪬throw�˪ʪ�ު�����êơ���驪����ꡢIsNull()�Ǫު�null�ʪΪ��ɪ��������㪷�ƪ��������� 
		\~
		*/
		inline operator Guid() const { ThrowIfNull(); return Guid::GetFromString((_bstr_t)m_val); }

		/** 
		\~korean
		���ϰ� �������Դϴ�. ���� �� ��ü�� null ���� ���� ������ ���ܰ� throw�˴ϴ�. ���� �ʿ��� ��� IsNull()�� ���� null���� ���θ� Ȯ���Ͻʽÿ�. 

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		����??ߩݬ�������?��?��null?��?������?��throw����������?���IsNull()??null��?����

		\~japanese
		�꫿?������ߩ�Ǫ����⪷�����Ϋ��֫������Ȫ�null�����êƪ�������⪬throw�˪ʪ�ު�����êơ���驪����ꡢIsNull()�Ǫު�null�ʪΪ��ɪ��������㪷�ƪ��������� 
		\~
		*/
		inline operator bool() const { ThrowIfNull(); return m_val; }	

		/** 
		\~korean
		���ϰ� �������Դϴ�. ���� �� ��ü�� null ���� ���� ������ ���ܰ� throw�˴ϴ�. ���� �ʿ��� ��� IsNull()�� ���� null���� ���θ� Ȯ���Ͻʽÿ�. 

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		����??ߩݬ�������?��?��null?��?������?��throw����������?���IsNull()??null��?����

		\~japanese
		�꫿?������ߩ�Ǫ����⪷�����Ϋ��֫������Ȫ�null�����êƪ�������⪬throw�˪ʪ�ު�����êơ���驪����ꡢIsNull()�Ǫު�null�ʪΪ��ɪ��������㪷�ƪ��������� 
		\~
		*/
		inline operator CPnTime() const 
		{
			ThrowIfNull();
			return CPnTime::FromDATE(m_val);			
		}

		/** 
		\~korean
		���ϰ� �������Դϴ�. ���� �� ��ü�� null ���� ���� ������ ���ܰ� throw�˴ϴ�. ���� �ʿ��� ��� IsNull()�� ���� null���� ���θ� Ȯ���Ͻʽÿ�. 

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		����??ߩݬ�������?��?��null?��?������?��throw����������?���IsNull()??null��?����

		\~japanese
		�꫿?������ߩ�Ǫ����⪷�����Ϋ��֫������Ȫ�null�����êƪ�������⪬throw�˪ʪ�ު�����êơ���驪����ꡢIsNull()�Ǫު�null�ʪΪ��ɪ��������㪷�ƪ��������� 
		\~
		*/
		inline operator int64_t() const { ThrowIfNull(); return ToLongLong(m_val); } // Windows 2000 ȣȯ�� ����

		/** 
		\~korean
		���ϰ� �������Դϴ�. ���� �� ��ü�� null ���� ���� ������ ���ܰ� throw�˴ϴ�. ���� �ʿ��� ��� IsNull()�� ���� null���� ���θ� Ȯ���Ͻʽÿ�. 

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		����??ߩݬ�������?��?��null?��?������?��throw����������?���IsNull()??null��?����

		\~japanese
		�꫿?������ߩ�Ǫ����⪷�����Ϋ��֫������Ȫ�null�����êƪ�������⪬throw�˪ʪ�ު�����êơ���驪����ꡢIsNull()�Ǫު�null�ʪΪ��ɪ��������㪷�ƪ��������� 
		\~
		*/
		inline operator uint64_t() const { ThrowIfNull(); return ToULongLong(m_val); } // Windows 2000 ȣȯ�� ����
		//inline operator ByteArray() const {return ToByteArray();}
		inline operator ByteArrayPtr() const {return ToByteArrayPtr();}

		/** 
		\~korean
		���� ����ִ��� üũ�Ѵ�. 

		\~english
		This method checks whether or not a value is included.

		\~chinese
		??������?��

		\~japanese
		�������êƪ��몫������ë����ު���
		\~
		*/
		inline bool IsNull() const { return m_val.vt == VT_NULL; } 

		/** 
		\~koeran
		���� ������ �� ���·� �����͸� �����Ѵ�. 

		\~english
		This method returns data in byte data block.

		\~chinese
		�byte?��block��������?�ߡ�

		\~japanese
		����?���֫�ë������ǫ�?����꫿?�󪷪ު���
		\~
		*/
		PROUD_API void ToByteArray(ByteArray &output) const;

		/**
		\~korean
		���� ������ �� ���·� �����͸� �����Ѵ�. 

		\~english
		This method returns data in byte data block.

		\~chinese
		�byte?��block��������?�ߡ�

		\~japanese
		����?���֫�ë������ǫ�?����꫿?�󪷪ު���
		\~
		*/
		PROUD_API ByteArrayPtr ToByteArrayPtr() const;

		/** 
		\~korean
		���� ������ ���� �Է¹޴´�. 

		\~english
		This method inputs data in byte data block.

		\~chinese
		?��byte?��block��

		\~japanese
		����?���֫�ë����������ƪ�骤�ު���
		\~
		*/
		PROUD_API void  FromByteArray(const ByteArray& input);

		/** 
		\~korean
		���� ������ ���� �Է¹޴´�. 

		\~english
		This method inputs data in byte data block.

		\~chinese
		?��byte?��block��

		\~japanese
		����?���֫�ë����������ƪ�骤�ު���
		\~
		*/
		PROUD_API void  FromByteArray(const ByteArrayPtr input);
	//private: VariantToByteArray ������ public
		void ThrowIfNull() const;
	};
#endif

#ifdef _MSC_VER
#pragma warning(pop)
#endif

	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
