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

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{

	inline CMessage& operator>>(CMessage &a, D3DXVECTOR3 &b)
	{
		a.Read(b.x);
		a.Read(b.y);
		a.Read(b.z);
		return a;
	}
	inline CMessage& operator<<(CMessage &a, const D3DXVECTOR3 &b)
	{
		a.Write(b.x);
		a.Write(b.y);
		a.Write(b.z);
		return a;
	}

	inline CMessage& operator>>(CMessage &a, D3DXMATRIX &b)
	{
		a.Read((uint8_t*)&b,sizeof(b));
		return a;
	}
	inline CMessage& operator<<(CMessage &a, const D3DXMATRIX &b)
	{
		a.Write((const uint8_t*)&b,sizeof(b));
		return a;
	}

	inline CMessage& operator>>(CMessage &a, D3DXQUATERNION &b)
	{
		a.Read((uint8_t*)&b,sizeof(b));
		return a;
	}
	inline CMessage& operator<<(CMessage &a, const D3DXQUATERNION &b)
	{
		a.Write((const uint8_t*)&b,sizeof(b));
		return a;
	}

	inline CMessage& operator>>(CMessage &a,D3DXVECTOR2 &b)
	{
		a>>b.x>>b.y;
		return a;
	}

	inline CMessage& operator<<(CMessage &a,const D3DXVECTOR2 &b)
	{
		a<<b.x<<b.y;
		return a;
	}

	inline void AppendTextOut(String &a,const D3DXMATRIX &b)
	{
		a+=_PNT("<D3DXMATRIX>");
	}
	inline void AppendTextOut(String &a,const D3DXQUATERNION &b)
	{
		String f;
		f.Format(_PNT("{x=%f,y=%f,z=%f,w=%f}"),b.x,b.y,b.z,b.w);
		a+=f;
	}
	inline void AppendTextOut(String &a,const D3DXVECTOR3 &b)
	{
		String f;
		f.Format(_PNT("{x=%f,y=%f,z=%f}"),b.x,b.y,b.z);
		a+=f;
	}

	inline void AppendTextOut(String &a,const D3DXVECTOR2 &b)
	{
		String f;
		f.Format(_PNT("{x=%f,y=%f}"),b.x,b.y);
		a+=f;
	}

}
#ifdef _MSC_VER
#pragma pack(pop)
#endif