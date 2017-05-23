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

#include "Marshaler.h"
#include <vector>
#include <list>
#include <map>

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	template<typename K, typename V>
	__forceinline CMessage& operator>>(CMessage &a, std::map<K, V> &b)
	{
		int64_t length;
		a.ReadScalar(length);

		b.clear();

		for (int64_t i = 0; i<length; i++)
		{
			K key; V val;
			a>>key>>val;
			b.insert(typename std::map<K, V>::value_type(key, val));
		}
		return a;
	}

	template<typename K, typename V>
	__forceinline CMessage& operator<<(CMessage &a, const std::map<K, V> &b)
	{
		int64_t length = b.size();
		a.WriteScalar(length);

		for ( typename std::map<K, V>::const_iterator i=b.begin(); i!=b.end(); ++i )
		{
            const K& key = i->first;
            const V& val = i->second;
			a << key << val;
		}
		return a;
	}

	template<typename K, typename V>
	__forceinline void AppendTextOut(String &a, const std::map<K, V> &b)
	{
		String temp;
		temp.Format(_PNT("std::map(Size=%d){"), b.size());
		a += temp;
		for ( typename std::map<K, V>::const_iterator i=b.begin(); i!=b.end(); ++i )
		{
            const K& key = i->first;
            const V& val = i->second;
            
			a+=_PNT("(");
			AppendTextOut(a, key);
			a+=_PNT(",");
			AppendTextOut(a, val);
			a+=_PNT(")");
		}
		a+=_PNT("}");
	}

	// vector���� ����� �� �ִ� serialization functions
	// for output to stream
	template<typename elem>
	__forceinline CMessage& operator>>(CMessage &a, std::vector<elem> &b)
	{
		// ũ�⸦ ��´�.
		int64_t length;
		a.ReadScalar(length);

		// length�� ��ŷ�Ǿ� ���� �ȵǴ� ���̸� ���� ó���ϱ�
		// ���� ��� ��츦 ������ �������� (sizeof elem ��������) �׷��� �ּ� 1����Ʈ�� ���״�.
		// ������ ������ ����Ʈ �������� ���� ���� ����.
		if (length<0 || length > a.GetLength() - a.GetReadOffset())
			ThrowExceptionOnReadArray(length);

		// �޸� frag�� ���̱� ����
        b.reserve((size_t)length);
		b.resize(0);

		// �迭 �׸� �ϳ� �ϳ��� �д´�.
		for (size_t i = 0; i < (size_t)length; i++)
		{
            elem e;
			a >> e;
            b.push_back(e);
		}
		return a;
	}

	template<typename elem>
	__forceinline CMessage& operator<<(CMessage &a, const std::vector<elem> &b)
	{
		// �迭 ũ�⸦ ����Ѵ�.
		int64_t size = (int64_t)b.size();
		a.WriteScalar(size);

		// �� �迭 ���ڸ� ����Ѵ�.
		for ( typename std::vector<elem>::const_iterator i = b.begin(); i != b.end(); ++i )
		{
            const elem& e = *i;
			a << e;
		}
		return a;
	}

	template<typename elem>
	__forceinline void AppendTextOut(String &a, std::vector<elem> &b)
	{
		Proud::String x;
		x.Format(_PNT("<std::vector %d>"), b.size());
		a += x;
	}

	template<typename elem>
	__forceinline CMessage& operator>>(CMessage &a, std::list<elem> &b)
	{
		// ũ�⸦ ��´�.
		int64_t length;
		a.ReadScalar(length);

		// length�� ��ŷ�Ǿ� ���� �ȵǴ� ���̸� ���� ó���ϱ�
		// ���� ��� ��츦 ������ �������� (sizeof elem ��������) �׷��� �ּ� 1����Ʈ�� ���״�.
		// ������ ������ ����Ʈ �������� ���� ���� ����.
		if (length<0 || length >(int64_t)(a.GetLength() - a.GetReadOffset()))
			ThrowExceptionOnReadArray(length);

		b.clear();

		// �迭 �׸� �ϳ� �ϳ��� �д´�.
		for ( int64_t i = 0; i < length; i++ )
		{
			elem e;
			a >> e;
			b.push_back(e);
		}
		return a;
	}

	template<typename elem>
	__forceinline CMessage& operator<<(CMessage &a, std::list<elem> &b)
	{
		int64_t size = (int64_t)b.size();
		a.WriteScalar(size);

		for ( typename std::list<elem>::const_iterator i = b.begin(); i != b.end(); ++i )
		{
            const elem& e = *i;
			a << e;
		}

		return a;
	}

	template<typename elem>
	__forceinline void AppendTextOut(String &a, std::list<elem> &b)
	{
		Proud::String x;
		x.Format(_PNT("<std::list %d>"), b.size());
		a += x;
	}
}
#ifdef _MSC_VER
#pragma pack(pop)
#endif