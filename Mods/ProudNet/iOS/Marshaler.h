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

#include <string>
#include "FakeClr.h"
#include "Message.h" // �̰� ��·�ų� �ʿ�. AppendTextOut ����
#include "AddrPort.h"
#include "Vector3D.h"
#include "Enums.h"
#include "ErrorInfo.h"
#include "FastList.h"
#include "pnguid.h"

// NOTE: ���⼭ stl���� marshaler�� stl�� include�ϸ� �ȵȴ�. ProudNet�� � ������ stl�� ����ڰ� �������� �����ϸ� �ȵǴϱ�.
// �̰��� ��� C++ library�� Ư¡�̱⵵ �ϴ�. (�̰� �����ϴٰ� ������ ���� ������ �����ϰ� ��.)

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup net_group
	*  @{
	*/

	PROUD_API void ThrowExceptionOnReadString(int length);
	PROUD_API void ThrowExceptionOnReadArray(int64_t length);
	inline CMessage& operator<<(CMessage &a, const StringA &str)
	{
		a.WriteString(str);
		return a;
	}
	inline CMessage& operator>>(CMessage &a, StringA &str)
	{
		a.ReadString(str);
		return a;
	}
	inline CMessage& operator<<(CMessage &a, const StringW &str)
	{
		a.WriteString(str);
		return a;
	}
	inline CMessage& operator>>(CMessage &a, StringW &str)
	{
		a.ReadString(str);
		return a;
	}
	inline CMessage& operator<<(CMessage &a, const std::string &str)
	{
		a.WriteString(str);
		return a;
	}
	inline CMessage& operator>>(CMessage &a, std::string &str)
	{
		a.ReadString(str);
		return a;
	}
	inline CMessage& operator<<(CMessage &a, const std::wstring &str)
	{
		a.WriteString(str);
		return a;
	}
	inline CMessage& operator>>(CMessage &a, std::wstring &str)
	{
		a.ReadString(str);
		return a;
	}
	inline CMessage& operator<<(CMessage &a, bool b) {
		a.Write(b);
		return a;
	}
	inline CMessage& operator<<(CMessage &a, int8_t b) {
		a.Write(b);
		return a;
	}
	inline CMessage& operator<<(CMessage &a, uint8_t b) {
		a.Write(b);
		return a;
	}
	inline CMessage& operator<<(CMessage &a, int16_t b) {
		a.Write(b);
		return a;
	}
	inline CMessage& operator<<(CMessage &a, uint16_t b) {
		a.Write(b);
		return a;
	}
	inline CMessage& operator<<(CMessage &a, int32_t b) {
		a.Write(b);
		return a;
	}
	inline CMessage& operator<<(CMessage &a, uint32_t b) {
		a.Write(b);
		return a;
	}
	inline CMessage& operator<<(CMessage &a, uint64_t b) {
		a.Write(b);
		return a;
	}
	inline CMessage& operator<<(CMessage &a, int64_t b) {
		a.Write(b);
		return a;
	}
	inline CMessage& operator<<(CMessage &a, float b) {
		a.Write(b);
		return a;
	}
	inline CMessage& operator<<(CMessage &a, double b) {
		a.Write(b);
		return a;
	}
	inline CMessage& operator<<(CMessage &a, HostID b) {
		a.Write(b);
		return a;
	}
	//void Write(CMessage &a,Size^ b) { a.Write(b); return a; }
	inline CMessage& operator>>(CMessage &a, bool &b) {
		a.Read(b);
		return a;
	}
	inline CMessage& operator>>(CMessage &a, int8_t &b) {
		a.Read(b);
		return a;
	}
	inline CMessage& operator>>(CMessage &a, uint8_t &b) {
		a.Read(b);
		return a;
	}
	inline CMessage& operator>>(CMessage &a, int16_t &b) {
		a.Read(b);
		return a;
	}
	inline CMessage& operator>>(CMessage &a, uint16_t &b) {
		a.Read(b);
		return a;
	}
	inline CMessage& operator>>(CMessage &a, int32_t &b) {
		a.Read(b);
		return a;
	}
	inline CMessage& operator>>(CMessage &a, uint32_t &b) {
		a.Read(b);
		return a;
	}
    inline CMessage& operator>>(CMessage &a, uint64_t  &b) {
		a.Read(b);
		return a;
	}
	inline CMessage& operator>>(CMessage &a, int64_t  &b) {
		a.Read(b);
		return a;
	}
	inline CMessage& operator>>(CMessage &a, float &b) {
		a.Read(b);
		return a;
	}
	inline CMessage& operator>>(CMessage &a, double &b) {
		a.Read(b);
		return a;
	}
	inline CMessage& operator>>(CMessage &a, HostID &b) {
		a.Read(b);
		return a;
	}

	//inline CMessage& operator>>(CMessage &a,DateTime b)
	//{
	//    a.Read(b);
	//}

	//inline CMessage& operator<<(CMessage &a,DateTime b)
	//{
	//    a.Write(b);
	//}

	inline CMessage& operator>>(CMessage &a, AddrPort &b)
	{
		a.Read(b.m_addr.v6Byte, sizeof(b.m_addr));
		a.Read(b.m_port);
		return a;
	}
	inline CMessage& operator<<(CMessage &a, AddrPort b)
	{
		a.Write(b.m_addr.v6Byte, sizeof(b.m_addr));
		a.Write(b.m_port);
		return a;
	}


	inline CMessage& operator>>(CMessage &a, ByteArray	&b)
	{
		a.Read(b);
		return a;
	}

	inline CMessage& operator<<(CMessage &a, const ByteArray &b)
	{
		a.Write(b);
		return a;
	}


	// vector���� ����� �� �ִ� serialization functions
	// for output to stream
	template<typename elem, bool elem_in_ref, bool RAWTYPE, typename INDEXTYPE>
	inline CMessage& operator>>(CMessage &a, CFastArray<elem, elem_in_ref, RAWTYPE, INDEXTYPE> &b)
	{
		// �迭 ũ�⸦ ��´�.
		int64_t length;
		a.ReadScalar(length);

		// length�� ��ŷ�Ǿ� ���� �ȵǴ� ���̸� ���� ó���ϱ�
		// ���� ��� ��츦 ������ �������� (sizeof elem ��������) �׷��� �ּ� 1����Ʈ�� ���״�.
		// ������ ������ ����Ʈ �������� ���� ���� ����.
		if (length< 0 || length > a.GetLength() - a.GetReadOffset())
			ThrowExceptionOnReadArray(length);

		// �迭 ũ�� ���� �� capacity set
		b.SetCount((INDEXTYPE)length);

		// �� �迭 �׸��� �д´�.
		for ( INDEXTYPE i = 0; i < (INDEXTYPE)length; i++ )
		{
			a >> b[i];
		}
		return a;
	}

	// vector, list�� unary item elem ��� ����� �� �ִ� serialization functions
	// for input from stream
	template<typename elem, bool elem_in_ref, bool RAWTYPE, typename INDEXTYPE>
	inline CMessage& operator<<(CMessage &a, const CFastArray<elem, elem_in_ref, RAWTYPE, INDEXTYPE> &b)
	{
		// �迭 ũ�⸦ ����Ѵ�.
		int64_t size = (int64_t)b.GetCount();
		a.WriteScalar(size);

		// �� �迭 ���ڸ� ����Ѵ�.
		for ( INDEXTYPE i = 0; i < (INDEXTYPE)size; i++ )
		{
			a << b[i];
		}
		return a;
	}

	CMessage& operator<<(CMessage &a, const ByteArray &b);
	CMessage& operator>>(CMessage &a, ByteArray &b);
	CMessage& operator<<(CMessage& a, const NamedAddrPort &b);
	CMessage& operator>>(CMessage& a, NamedAddrPort &b);

	PROUD_API void AppendTextOut(String &a, const bool &b);
	PROUD_API void AppendTextOut(String &a, const int8_t &b);
	PROUD_API void AppendTextOut(String &a, const uint8_t &b);
	PROUD_API void AppendTextOut(String &a, const int16_t &b);
	PROUD_API void AppendTextOut(String &a, const uint16_t& b);
	PROUD_API void AppendTextOut(String &a, const int32_t &b);
	PROUD_API void AppendTextOut(String &a, const uint32_t& b);
	PROUD_API void AppendTextOut(String &a, const int64_t &b);
	PROUD_API void AppendTextOut(String &a, const uint64_t &b);

	PROUD_API void AppendTextOut(String &a, const float  &b);
	PROUD_API void AppendTextOut(String &a, const double &b);

	PROUD_API void AppendTextOut(String &a, const char *&b);
	PROUD_API void AppendTextOut(String &a, const wchar_t *&b);

	PROUD_API void AppendTextOut(String &a, const StringA &b);
	PROUD_API void AppendTextOut(String &a, const StringW &b);
#if defined(_WIN32)
	PROUD_API void AppendTextOut(String &a, const std::string & b);
	PROUD_API void AppendTextOut(String &a, const std::wstring & b);
	PROUD_API void AppendTextOut(String &a, const POINT &b);
#endif



	template<typename elem>
	inline void AppendTextOut(String &a, CFastArray<elem> &b)
	{
		Proud::String x;
		x.Format(_PNT("<Array %d>"), b.GetCount());
		a += x;
	}

	PROUD_API void AppendTextOut(String &a, ByteArray &b);


	template <typename FloatType>
	inline CMessage& operator>>(CMessage &a, Vector3T<FloatType> &b)
	{
		a.Read(b.x);
		a.Read(b.y);
		a.Read(b.z);
		return a;
	}

	template <typename FloatType>
	inline CMessage& operator<<(CMessage &a, const Vector3T<FloatType> &b)
	{
		a.Write(b.x);
		a.Write(b.y);
		a.Write(b.z);
		return a;
	}

	inline void AppendTextOut(String &a, const FloatVector3 &b)
	{
		String f;
		f.Format(_PNT("{x=%f,y=%f,z=%f}"), b.x, b.y, b.z);
		a += f;
	}

	inline void AppendTextOut(String &a, const Vector3 &b)
	{
		String f;
		f.Format(_PNT("{x=%lf,y=%lf,z=%lf}"), b.x, b.y, b.z);
		a+=f;
	}

	template<typename K, typename V>
	__forceinline CMessage& operator>>(CMessage &a, CFastMap<K,V> &b)
	{
		int64_t length;
		a.ReadScalar(length);

		// length�� ��ŷ�Ǿ� ���� �ȵǴ� ���̸� ���� ó���ϱ�
		// ���� ��� ��츦 ������ �������� (sizeof elem ��������) �׷��� �ּ� 1����Ʈ�� ���״�.
		// ������ ������ ����Ʈ �������� ���� ���� ����.
		if (length<0 || length > a.GetLength() - a.GetReadOffset())
             ThrowExceptionOnReadArray(length);

		b.Clear();

		for(int64_t i=0;i<length;i++)
		{
			K key; V val;
			a>>key;
			a>>val;
			b.Add(key,val);
		}
		return a;
	}

	template<typename K, typename V>
	__forceinline CMessage& operator<<(CMessage &a, const CFastMap<K,V> &b)
	{
		int64_t length = (int64_t)b.GetCount();
		a.WriteScalar(length);

        typedef typename CFastMap<K,V>::const_iterator ConstIter;

		for(ConstIter i=b.begin();i!=b.end();i++)
		{
			a<<i.GetFirst();
			a<<i.GetSecond();
		}
		return a;
	}

	template<typename K, typename V>
	__forceinline void AppendTextOut(String &a,const CFastMap<K,V> &b)
	{
		String temp;
		temp.Format(_PNT("FastMap(Size=%d){"), b.GetCount());
		a += temp;

         typedef typename CFastMap<K,V>::const_iterator ConstIter;

		for(ConstIter i=b.begin();i!=b.end();i++)
		{
			a+=_PNT("(");
			AppendTextOut(a, i->GetFirst());
			a+=_PNT(",");
			AppendTextOut(a, i->GetSecond());
			a+=_PNT(")");
		}
		a+=_PNT("}");
	}

    template<typename elem>
    __forceinline CMessage& operator>>(CMessage &a, CFastList<elem> &b)
    {
		int64_t length;
		a.ReadScalar(length);

		// length�� ��ŷ�Ǿ� ���� �ȵǴ� ���̸� ���� ó���ϱ�
		// ���� ��� ��츦 ������ �������� (sizeof elem ��������) �׷��� �ּ� 1����Ʈ�� ���״�.
		// ������ ������ ����Ʈ �������� ���� ���� ����.
		if (length<0 || length > a.GetLength() - a.GetReadOffset())
             ThrowExceptionOnReadArray(length);

		b.Clear();

        for(int64_t i=0;i<length;i++)
        {
            elem e;
            a>>e;
            b.AddTail(e);
        }
        return a;
    }

    template<typename elem>
    __forceinline CMessage& operator<<(CMessage &a, const CFastList<elem> &b)
    {
		int64_t length = (int64_t)b.GetCount();
		a.WriteScalar(length);

        typedef typename CFastList<elem>::const_iterator ConstIter;

        for(ConstIter i=b.begin();i!=b.end();i++)
        {
            a<< (*i);
        }
        return a;
    }

    template<typename elem>
    __forceinline void AppendTextOut(String &a,const CFastList<elem> &b)
    {
        Proud::String x;
		x.Format(_PNT("<FastList %d>"), b.GetCount());
        a += x;
    }

	/**
	\~korean
	����ڰ� ���� marshaler �޼��尡 ���������� �۵��ϴ��� �׽�Ʈ�մϴ�.
	����� �뵵�� ����ϼ���.

	\param testee ����ڰ� ���� ���� Ÿ���� ��ü�Դϴ�. �ִ��� �����ϰ� ���� �־ �׽�Ʈ�ϴ� ���� ���մϴ�.
	�� ��ü Ÿ���� Equals() �޼��带 ����� ���� �־�� �մϴ�. Equals()�޼���� �� ���� ���ؼ� ������ true�� �����ؾ�
	�մϴ�.
	\return ������ ������ �� ���ڿ���, �ִ� ��� ���� ������ ��Ƽ� �����մϴ�.

	��� ��
	\code
		MyType a;
		a = ...; // ������ ��´�.
		String err = TestMarshaler(a);
		if(!err.IsEmpty())
		show_error(err);
	\endcode

	\~english
	It tests marshaler method that created by user.
	Please use it for debugging.

	\param testee Variable type object that created by user. We recommend to put complex value for testing.
	This object time has to have Equals() method as member. It has return ture when Equals() method compare two value and if it is the same.
	\return If there in no error, it will send an empty string. If there is error then return information of error.
	Example
	\code
		MyType a;
		a = ...; // Put something in
		String err = TestMarshaler(a);
		if(!err.IsEmpty())
		show_error(err);
	\endcode

	\~chinese
	??��??����marshaler۰����������?����
	?������??��Բ��

	\param testee ��?�����???��?�ڡ���??����������??��??��??��
	�?��?�����Equals()۰��?������?��Equals()۰����????����?��?�����true��
	\return ?��??��?�������ݬ��������??????�?���ޡ�

	������
	\code
		MyType a;
		a = ...; // ?����?�
		String err = TestMarshaler(a);
		if(!err.IsEmpty())
		show_error(err);

	\~japanese
	��?��?���ªê�marshaler�᫽�ëɪ����Ȫ����Ѫ��몫��ƫ��Ȫ��ު���
	�ǫЫë�����Բ���Ūêƪ���������
	\param testee ��?��?���ªê�??�����תΫ��֫������ȪǪ��������ڪ���?����������ƫƫ��Ȫ��몳�Ȫ�?�᪷�ު���
	���Ϋ��֫������ȫ����תϡ�Equals()�᫽�ëɪ����?�Ȫ����êƪ�����驪�����ު���Equals()�᫽�ëɪ�?�������򪷪��Ҫ��Ǫ����true��꫿?�󪹪���驪�����ު���
	\return ����?���ʪ�����������֪�򡢪�������ϫ���??黪�����ƫ꫿?�󪷪ު���

	������
	\code
	MyType a;
	a = ...; // ������ ��´�.������������롣
	String err = TestMarshaler(a);
	if(!err.IsEmpty())
	show_error(err);
	\endcode

	\~
	*/
	template<typename elem>
	String TestMarshaler(const elem& testee)
	{
		CMessage msg;
		msg.UseInternalBuffer();
		msg << testee;

		int msgLength = msg.GetLength();
		msg.SetReadOffset(0);

		elem readee;
		msg >> readee;

		String errText;

		if(msg.GetLength() != msg.GetReadOffset())
		{
			errText.Format(_PNT("An object is serialized into %d bytes of data, but %d bytes are used for deserialization. Its marshaler methods may run incorrectly."), msgLength, msg.GetReadOffset());
			return errText;
		}

		if(!testee.Equals(readee))
		{
			errText = _PNT("The serialzed and deserialized object is not the same to the original object! Its marshaler methods may run incorrectly.");
		}

		return errText;
	}

	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#define PROUDNET_SERIALIZE_ENUM(type) \
namespace Proud \
{ \
	inline CMessage& operator<<(CMessage& a,type b) \
	{ \
		a<<(int32_t)b; \
		return a; \
	} \
	inline CMessage& operator>>(CMessage& a,type& b) \
	{ \
		int32_t x; \
		a>>x; \
		b=(type)x; \
		return a; \
	} \
	inline void AppendTextOut(String &a,type b) \
	{ \
		String txt; \
		txt.Format(_PNT("%d"),(int32_t)b); \
		a+=txt; \
	} \
}

PROUDNET_SERIALIZE_ENUM(Proud::ErrorType);

#if defined(_WIN32) && defined(ATLASSERT)
    #include "AtlDependent.inl"
#endif

#if defined(_WIN32) && defined(_AFX)
#include "MfcDependent.inl"
#endif
