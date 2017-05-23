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

#include <atlcomtime.h>
#include <atlstr.h>

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

/** �� ����� MFC�� D3DX�� �������� �ɺ����� �����Ѵ�.
- __forceinline���� ����� ������ compile time���� �ڵ带 �����ϵ� MFC ��� ���ο� ���� �� �ν��Ͻ� Ÿ����
�޶����� Ŭ����(CString ��)�� ProudNet�� �浹���� �ʰ� �ϱ� �����̴�.
����, ProudNet���� �Ʒ� �ɺ����� �����ϵǾ� ������ �ʴ�. */
namespace Proud
{
	__forceinline CMessage& operator >> (CMessage &a, COleDateTime &b)
	{
		DATE t;
		a >> t;
		b = t;
		return a;
	}

	__forceinline CMessage& operator<<(CMessage &a, const COleDateTime &b)
	{
		DATE t = b;
		a << t;
		return a;
	}

	__forceinline CMessage& operator >> (CMessage &a, CTime &b)
	{
		__time64_t t;
		a >> t;
		b = t;
		return a;
	}

	__forceinline CMessage& operator<<(CMessage &a, const CTime &b)
	{
		__time64_t t = b.GetTime();
		a << t;
		return a;
	}

	__forceinline CMessage& operator >> (CMessage &a, COleDateTimeSpan &b)
	{
		a.Read((uint8_t*)&b, sizeof(b));
		return a;
	}


	__forceinline CMessage& operator<<(CMessage &a, const COleDateTimeSpan &b)
	{
		a.Write((const uint8_t*)&b, sizeof(b));
		return a;
	}

	__forceinline void AppendTextOut(String &a, COleDateTime &b)
	{
#if defined(_UNICODE)
		a += b.Format();
#else
		a += StringA2T(b.Format());
#endif
	}
	__forceinline void AppendTextOut(String &a, COleDateTimeSpan &b)
	{
#if defined(_UNICODE)
		a += b.Format((uint32_t)0);
#else
		a += StringA2T(b.Format((uint32_t)0));
#endif
	}

	__forceinline void AppendTextOut(String &a, CTime &b)
	{
#if defined(_UNICODE)
		a += b.Format(_PNT("%#c"));
#else
		a += StringA2T(b.Format("%#c"));
#endif
	}
	__forceinline void AppendTextOut(String &a, CTimeSpan &b)
	{
#if defined(_UNICODE)
		a += b.Format(_PNT("%#c"));
#else
		a += StringA2T(b.Format("%#c"));
#endif
	}

	// for MFC CString class
	// note: �̹� non-MFC�� CString class(CAtlString)�� ������ �Լ��� ���� �����Ƿ� _AFX ���θ� �����Ѵ�.
	__forceinline CMessage& operator >> (CMessage &a, CStringA &b)
	{
		// �о CStringA�� ��ȯ
		StringA x;
		a >> x;
		b = (const char*)x;
		return a;
	}

	// for MFC CString class
	__forceinline CMessage& operator<<(CMessage &a, const CStringA &b)
	{
		// StringA�� ��ȯ �� ���
		StringA x;
		x = (const char*)b;
		a << x;
		return a;
	}

	// for MFC CString class
	__forceinline void AppendTextOut(String &a, CStringA &b)
	{
		a += StringA2T(b);
	}

	// for MFC CString class
	__forceinline CMessage& operator >> (CMessage &a, CStringW &b)
	{
		// �о CStringW�� ��ȯ
		String x;
		a >> x;
		b = StringT2W(x);
		return a;
	}

	// for MFC CString class
	__forceinline CMessage& operator<<(CMessage &a, const CStringW &b)
	{
		// String�� ��ȯ �� ���
		String x;
		x = StringW2T(b);
		a << x;
		return a;
	}

	// for MFC CString class
	__forceinline void AppendTextOut(String &a, CStringW &b)
	{
		a += StringW2T(b);
	}

	//#TODO-MFC ����� CAtlArray, CAtlMap�� ���� operator<<,>>,AppendTextOut�� �����ϼ���.
	// stlmarshal.inl�� �ִ� std.vector, std.map�� �����ؼ� ���ĸ��弼��.
	// size()��� GetCount�� ���̰� size_t��� intptr_t Ȥ�� int�� ������. ��� ��� �ϴ����� CAtlArray���� �����θ� �����ؼ� �Ͻð��.


#ifdef _AFX
	// 	__forceinline CMessage& operator<<(CMessage& a,const CPoint &b)
	// 	{
	// 		a<<b.x<<b.y;
	// 		return a;
	// 	}
	//
	//
	// 	__forceinline CMessage& operator>>(CMessage& a,CPoint &b)
	// 	{
	// 		a>>b.x>>b.y;
	// 		return a;
	// 	}
	//
	// 	__forceinline void AppendTextOut(String &a,CPoint &b)
	// 	{
	// 		String txt;
	// 		txt.Format(_PNT("(%d,%d)"),b.x,b.y);
	// 		a+=txt;
	// 	}
#endif

#ifdef PREPARED_D3DX_MARSHALER

	__forceinline CMessage& operator >> (CMessage &a, D3DXVECTOR3 &b)
	{
		a.Read(b.x);
		a.Read(b.y);
		a.Read(b.z);
		return a;
	}
	__forceinline CMessage& operator<<(CMessage &a, const D3DXVECTOR3 &b)
	{
		a.Write(b.x);
		a.Write(b.y);
		a.Write(b.z);
		return a;
	}

	__forceinline CMessage& operator >> (CMessage &a, D3DXMATRIX &b)
	{
		a.Read((uint8_t*)&b, sizeof(b));
		return a;
	}
	__forceinline CMessage& operator<<(CMessage &a, const D3DXMATRIX &b)
	{
		a.Write((const uint8_t*)&b, sizeof(b));
		return a;
	}

	__forceinline CMessage& operator >> (CMessage &a, D3DXQUATERNION &b)
	{
		a.Read((uint8_t*)&b, sizeof(b));
		return a;
	}
	__forceinline CMessage& operator<<(CMessage &a, const D3DXQUATERNION &b)
	{
		a.Write((const uint8_t*)&b, sizeof(b));
		return a;
	}

	__forceinline CMessage& operator >> (CMessage &a, D3DXVECTOR2 &b)
	{
		a >> b.x >> b.y;
		return a;
	}

	__forceinline CMessage& operator<<(CMessage &a, const D3DXVECTOR2 &b)
	{
		a << b.x << b.y;
		return a;
	}

	__forceinline void AppendTextOut(String &a, const D3DXMATRIX &b)
	{
		a += _PNT("<D3DXMATRIX>");
	}
	__forceinline void AppendTextOut(String &a, const D3DXQUATERNION &b)
	{
		String f;
		f.Format(_PNT("{x=%f,y=%f,z=%f,w=%f}"), b.x, b.y, b.z, b.w);
		a += f;
	}
	__forceinline void AppendTextOut(String &a, const D3DXVECTOR3 &b)
	{
		String f;
		f.Format(_PNT("{x=%f,y=%f,z=%f}"), b.x, b.y, b.z);
		a += f;
	}

	__forceinline void AppendTextOut(String &a, const D3DXVECTOR2 &b)
	{
		String f;
		f.Format(_PNT("{x=%f,y=%f}"), b.x, b.y);
		a += f;
	}

#endif // PREPARED_D3DX_MARSHALER

#ifdef _INC_COMDEF

#include <string>

	__forceinline CMessage& operator<<(CMessage& packet, const _variant_t &rhs)
	{
		// ��� VARTYPE�� ���������� �ʴ´�. ���� �ʿ信 ���� �߰� ����� ��������.
		packet.Write((uint16_t)rhs.vt);

		switch (rhs.vt)
		{
		case VT_I1:
		case VT_I2:
		case VT_I4:
		case VT_I8:
		case VT_INT:
			// C++/CLI���� int64_t���� ����ȯ�ϸ� ���� �����Ͽ� �Ʒ��� ������� ����.
			//packet.WriteScalar((int64_t)rhs);
			packet.WriteScalar(rhs.llVal);
			break;
		case VT_R4:
			packet.Write((float)rhs);
			break;
		case VT_R8:
		case VT_DATE:
			packet.Write((double)rhs);
			break;
		case VT_CY:
		{
			CY val = (CY)rhs;
			packet.Write(val.int64);
		}
		break;
		case VT_UI1:
		case VT_UI2:
		case VT_UI4:
		case VT_UI8:
		case VT_UINT:
			// C++/CLI���� int64_t���� ����ȯ�ϸ� ���� �����Ͽ� �Ʒ��� ������� ����.
			//packet.WriteScalar((uint64_t)rhs);
			packet.WriteScalar(rhs.ullVal);
			break;
		case VT_BOOL:
			packet.Write((bool)rhs);
			break;
		case VT_BSTR:
		case VT_LPWSTR:
		case VT_LPSTR:
		{
			String val = StringW2T(rhs.bstrVal);
			packet.WriteString(val);
		}
		break;
		case VT_HRESULT:
			packet.Write((int32_t)rhs);
			break;
		case VT_SAFEARRAY:
		case VT_UI1 | VT_ARRAY:
			//case VT_ARRAY:
		{
			uint8_t* pBytes = NULL;

			uint32_t lSize = rhs.parray->rgsabound->cElements;
			HRESULT hr = SafeArrayAccessData(rhs.parray, (void**)&pBytes);

			if (FAILED(hr))
				throw Exception("operator << Failed - SafeArrayAccessData Failed!!");

			packet.Write((const uint8_t*)&lSize, sizeof(lSize));
			packet.Write(pBytes, lSize);

			SafeArrayUnaccessData(rhs.parray);
		}
		break;
		case VT_DECIMAL:
			//���߿� ����...
		{
			packet.Write(rhs.decVal.signscale);
			packet.Write((uint32_t)rhs.decVal.Hi32);
			packet.Write((uint64_t)rhs.decVal.Lo64);
		}
		break;
		case VT_CLSID:
		{
			String val = StringW2T(rhs.bstrVal);
			packet.WriteString(val);
		}
		break;
		}

		return packet;
	}


	__forceinline CMessage& operator >> (CMessage& packet, _variant_t &rhs)
	{
		// ��� VARTYPE�� ���������� �ʴ´�. ���� �ʿ信 ���� �߰� ����� ��������.
		uint16_t vt;
		packet.Read(vt);

		rhs.Clear();

		// VT_UI1|VT_ARRAY�� ��쿡�� ó������ �ʽ��ϴ�.
		// ���, �Ʒ� switch-case �������� �̷��� ���̽��� �ٷ� �� vt�� ���õǹǷ� ok.
		if (vt != (VT_UI1 | VT_ARRAY))
		{
			rhs.ChangeType(vt);
		}

		switch (vt)
		{
		case VT_I1:
		case VT_I2:
		case VT_I4:
		case VT_I8:
		case VT_INT:
		{
			int64_t val;
			packet.ReadScalar(val);

			rhs.llVal = val;
		}
		break;
		case VT_R4:
		{
			float val;
			packet.Read(val);

			rhs = val;
		}
		break;
		case VT_R8:
		case VT_DATE:
		{
			double val;
			packet.Read(val);

			rhs = val;
		}
		break;
		case VT_CY:
		{
			CY val;
			packet.Read(val.int64);

			rhs = val;
		}
		break;
		case VT_UI1:
		case VT_UI2:
		case VT_UI4:
		case VT_UI8:
		case VT_UINT:
		{
			uint64_t val;
			packet.ReadScalar(val);

			rhs.ullVal = val;
		}
		break;
		case VT_BOOL:
		{
			bool val;
			packet.Read(val);

			rhs = val;
		}
		break;
		case VT_BSTR:
		case VT_LPWSTR:
		case VT_LPSTR:
		{
			String val;
			packet.ReadString(val);
			rhs = val;
		}
		break;
		case VT_HRESULT:
		{
			int32_t val;
			packet.Read(val);

			rhs = (HRESULT)val;
		}
		break;
		case VT_SAFEARRAY:
		case VT_UI1 | VT_ARRAY:
			//case VT_ARRAY:
		{
			uint32_t length = 0;
			VARIANT v;
			SAFEARRAY FAR* psa;
			SAFEARRAYBOUND saBound;
			uint8_t byIn = 0;

			packet.Read((uint8_t*)&length, sizeof(length));

			saBound.cElements = length;
			saBound.lLbound = 0;
			psa = SafeArrayCreate(VT_UI1, 1, &saBound);

			VariantInit(&v);
			V_VT(&v) = VT_ARRAY | VT_UI1;
			V_ARRAY(&v) = psa;

			for (long i = 0; i < (long)length; ++i)
			{
				packet >> byIn;

				HRESULT ret = SafeArrayPutElement(psa, &i, (void*)&byIn);
				if (S_OK != ret)
				{
					TSTRING strStm;
					strStm = _PNT("SafeArrayPutElement in ") + StringA2T(__FUNCTION__) + _PNT(" returns error") + ret;
					throw Proud::Exception(strStm.c_str());
				}
			}

			VariantClear(&rhs); // �̰� ������ �Ʒ� ������ ���� ������ �̾��� �� ����. ������ �ִ��� ���־� �ϴϱ�.
			rhs = v;
		}
		break;
		case VT_DECIMAL:
		{
			USHORT signscale;
			uint32_t Hi32;
			uint64_t Lo64;
			packet.Read(signscale);
			packet.Read(Hi32);
			packet.Read(Lo64);

			rhs.decVal.signscale = signscale;
			rhs.decVal.Hi32 = Hi32;
			rhs.decVal.Lo64 = Lo64;
		}
		break;
		case VT_CLSID:
		{
			String val;
			packet.ReadString(val);
			rhs.bstrVal = _bstr_t(val.GetString());
		}
		break;
		}

		return packet;
	}

	__forceinline void AppendTextOut(String &a, const _variant_t &b)
	{
		a += _PNT("<_variant_t>");
	}
#endif // _INC_COMDEF
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
