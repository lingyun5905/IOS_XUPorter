/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 177 92 124 113 87 79 17 155 171 239 138 133 88 235 28 112 146 102 93 52 214 131 240 31 138 179 248 115 127 118 107 31 112 91 111 14 243 1 121 131 22 69 144 19 214 101 65 133 253 32 122 175 12 198 63 134 23 240 109 90 59 142 194 194 160 148 139 101 68 220 217 181 32 240 36 47 59 74 18 182 145 116 17 29 255 115 236 11 29 111 122  */
#pragma once 

#include "BasicTypes.h"
#include "PNString.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	class CMessage;

	struct PNGUID
	{
		uint32_t Data1;
		uint16_t Data2;
		uint16_t Data3;
		uint8_t Data4[8];
	};

	/** Platform independent Global Unique ID object. 
	For Win32 features, refer to Proud::Win32Guid class.
	*/
	class Guid:public PNGUID
	{
	public:
		/**
		\~korean
		GUID�� �������� �����մϴ�. NewGuid()�� �޸�, �� ���� �������� ������� �ʽ��ϴ�.

		\~english
		Generates a 'random' GUID. Unlike NewGuid(), this does not guarantee uniqueness.

		\~chinese
		?������GUIDE��?NewGuid�������ң��?�����ͳ������

		\~japanese
		GUID���������������ު���NewGuid()�Ȫ��ުêơ���������ͳ�����������ʪ���Ъʪ�ު���
		\~
		*/
		PROUD_API static Guid RandomGuid();

		Guid();
		Guid(PNGUID src);

		/**
		\~korean
		Guid�� String������ ��ȯ�� �ݴϴ�.

		\~english TODO:translate needed.
		It converts Guid to a string value. 

		\~chinese
		��Guid??��String?��

		\~japanese
		Guid��String����?�����ƪ���ު���
		\~
		*/
		PROUD_API String ToString() const;

		/**
		\~korean
		Guid�� Bracket({}) �� ������ String���� ��ȯ�� �ݴϴ�.

		\~english TODO:translate needed.
		It converts Guid with a string including brakets({}). 

		\~chinese
		��Guid??������Bracket({})��String��

		\~japanese
		Guid��Bracket({})���ߪ��String��?�����ƪ���ު���
		\~
		*/
		PROUD_API String ToBracketString() const;

		/**
		\~korean
		Guid�� String������ ��ȯ�� �ݴϴ�.
		\param uuid Guid�Դϴ�.
		\param uuidStr uuid�� String���·� ��ȯ�� ������ ���� reference �Դϴ�
		\return ��ȯ�� ���� true, ���� false

		\~english TODO:translate needed.
		It converts Guid to a string value.
		\param This is uuid Guid. 
		\param This is the reference to hold the information which is uuid converted into a string format. 
		\return True when successful in conversion, otherwise false. 


		\~chinese
		��Guid??��String?��
		\param uuid ��Guid��
		\param uuidStr ���������uuid??��String����������reference��
		\return ??������?true����?��?false��

		\~japanese
		Guid��String����?�����ƪ���ު���
		\param uuid Guid�Ǫ���
		\param uuidStr uuid��String������?���������ê������reference�Ǫ���
		\return ?�����������true�����������false
		\~
		*/
		PROUD_API static bool  ConvertUUIDToString(const Guid &uuid, String &uuidStr);

		/**
		\~korean
		Guid�� Bracket({}) �� ������ String���� ��ȯ�� �ݴϴ�.
		\param uuid Guid�Դϴ�.
		\param uuidStr uuid�� String���·� ��ȯ�� ������ ���� reference �Դϴ�
		\return ��ȯ�� ���� true, ���� false

		\~english TODO:translate needed.
		It converts Guid to a string value
		\param This is uuid Guid.
		\param This is the reference to hold the information which is uuid converted into a string format. 
		\return True when successful in conversion, otherwise false.

		

		\~chinese
		��Guid??������Bracket({}) ��String��
		\param uuid ��Guid��
		\param uuidStr ���������uuid??��String����������reference��
		\return ??������?true����?��?false��

		\~japanese
		Guid��Bracket({})���ߪ��String��?�����ƪ���ު���
		\param uuid Guid�Ǫ���
		\param uuidStr uuid��String������?���������ê������reference�Ǫ���
		\return ?�����������true�����������false
		\~
		*/
		PROUD_API static bool  ConvertUUIDToBracketString(const Guid &uuid, String &uuidStr);

		/**
		\~korean
		String�� uuid������ ��ȯ�մϴ�.
		\param uuidStr uuid�� String���� �Դϴ�.
		\param uuidStr String���� uuid�� ��ȯ�� ������ ���� reference �Դϴ�
		\return ��ȯ�� ���� true, ���� false

		\~english TODO:translate needed.
		It converts string to a uuid value.
		\param uuidStr This is the string type of uuid. 
		\param uuidStr This is the reference to hold the information which is string converted into an uuid format.
		\return True when successful in conversion, otherwise false.


		\~chinese
		��String??��uuid?��
		\param uuidStr ��uuid��String���ҡ�
		\param uuidStr �������?String??��uuid������reference��
		\return ??������?true����?��?false��

		\~japanese
		String��uuid����?������s����
		\param uuidStr uuid��String�����Ǫ���
		\param uuidStr String��uuid��?���������ê������reference�Ǫ���
		\return ?�����������true�����������false
		
		\~
		*/
		PROUD_API static bool  ConvertStringToUUID(String uuidStr, Guid &uuid);

		/**
		\~korean
		Guid�� String������ ��ȯ�� �ݴϴ�.
		\param uuid Guid�Դϴ�.
		\return String

		\~english TODO:translate needed.
		It converts Guid to a string value.
		\param This is Guid. 
		\return String


		\~chinese
		��Guid??��String?��
		\param uuid ��Guid��
		\return String

		\~japanese
		Guid��String����?�����ƪ���ު���
		\param uuid Guid�Ǫ���
		\return String

		\~
		*/
		static inline String GetString(const Guid &uuid)
		{
			String ret;
			if (ConvertUUIDToString(uuid, ret))
				return ret;
			else
				return String();
		}

		String GetString() const
		{
			return Guid::GetString(*this);
		}

		/**
		\~korean
		Guid�� Bracket({}) �� ������ String���� ��ȯ�� �ݴϴ�.
		\param uuid Guid�Դϴ�.
		\return String

		\~english TODO:translate needed.
		It converts Guid with a string including brakets({}). 
		\param This is Guid.
		\return String


		\~chinese
		��Guid??������Bracket({})��String��
		\param uuid ��Guid��
		\return String

		\~japanese
		Guid��Bracket({})���ߪ��String��?�����ƪ���ު���
		\param uuid Guid�Ǫ���
		\return String

		\~
		*/
		static inline String GetBracketString(const Guid &uuid)
		{
			String ret;
			if (ConvertUUIDToBracketString(uuid, ret))
				return ret;
			else
				return String();
		}

		/**
		\~korean
		String�� uuid������ ��ȯ�մϴ�.
		\param uuidStr uuid�� String���� �Դϴ�.
		\return Guid ��ȯ�� Guid �Դϴ�.

		\~english TODO:translate needed.
		It converts string to a uuid value.
		\param uuidStr This is the string type of uuid. 
		\return Guid This is the converted Guid. 


		\~chinese
		��String??��uuid?��
		\param uuidStr ��uuid��String���ҡ�
		\return Guid��??��Guid��

		\~japanese
		String��uuid����?�����ު���
		\param uuidStr uuid��String�����Ǫ���
		\return Guid ?�����쪿Guid�Ǫ���
		\~
		*/
		static inline Guid GetFromString(const PNTCHAR* uuidStr)
		{
			Guid uuid;
			if (ConvertStringToUUID(uuidStr, uuid))
				return uuid;
			else
				return Guid();
		}

		/**
		\~korean
		PNGUID ��ü�κ����� ĳ����
		\param uuid	PNGUID�Դϴ�.
		\return Guid��ü

		\~english TODO:translate needed.
		Casting from PNGUID object
		\param uuid  This is PNGUID
		\return Guid object. 


		\~chinese TODO:translate needed.
		?PNGUID ?��?�casting
		\paramuuid	PNGUID
		\return Guid?��

		\~japanese TODO:translate needed.
		PNGUID ���֫������Ȫ���Ϋ��㫹�ƫ���
		\param uuid	PNGUID�Ǫ���
		\return Guid���֫�������
		\~
		*/
		static inline Guid From(const PNGUID& uuid)
		{
			return Guid(uuid);
		}

	};

	inline bool operator<(const Guid& d1, const Guid& d2)
	{
		return memcmp(&d1, &d2, sizeof(Guid)) < 0;
	}

	inline bool operator<=(const Guid& d1, const Guid& d2)
	{
		return memcmp(&d1, &d2, sizeof(Guid)) <= 0;
	}

	inline bool operator>(const Guid& d1, const Guid& d2)
	{
		return memcmp(&d1, &d2, sizeof(Guid)) > 0;
	}

	inline bool operator>=(const Guid& d1, const Guid& d2)
	{
		return memcmp(&d1, &d2, sizeof(Guid)) >= 0;
	}

	inline bool operator==(const Guid& d1, const Guid& d2)
	{
		return memcmp(&d1, &d2, sizeof(Guid)) == 0;
	}

	inline bool operator!=(const Guid& d1, const Guid& d2)
	{
		return memcmp(&d1, &d2, sizeof(Guid)) != 0;
	}

	CMessage& operator>>(CMessage &a, Guid &b);
	CMessage& operator<<(CMessage &a, const Guid &b);
	void AppendTextOut(String &a, const Guid &b);


};

/**
\~korean
CFastMap � ������ �̰��� �ʿ��ϴ�.

\~english
This is needed to use CFastMap or others.

\~chinese
������ CFasTMap%����?���??��

\~japanese
CFastMap �ʪɪ��Ū�����˪Ϫ��쪬��驪Ǫ���
\~
*/
template<>
class CPNElementTraits < Proud::Guid >
{
public:
	typedef const Proud::Guid& INARGTYPE;
	typedef Proud::Guid& OUTARGTYPE;

	inline static uint32_t Hash(INARGTYPE element)
	{
		uint32_t ret = 0;
		uint32_t* data = (uint32_t*)&element;
		for (int i = 0; i < 4; i++)
		{
			ret ^= data[i];
		}

		return ret;
	}

	inline static bool CompareElements(INARGTYPE element1, INARGTYPE element2)
	{
		return (element1 == element2) ? true : false;
	}

	inline static int CompareElementsOrdered(INARGTYPE element1, INARGTYPE element2)
	{
		if (element1 < element2)
			return -1;
		else if (element1 > element2)
			return 1;
		else
			return 0;
	}
};

#ifdef _MSC_VER
#pragma pack(pop)
#endif