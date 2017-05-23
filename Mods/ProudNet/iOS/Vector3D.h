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

#include <assert.h>
#include <math.h>

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup util_group
	*  @{
	*/

	/** 
	\~korean
	�� �� v1,v2�� v1->v2���� ���а� ratio�� ���Ѵ�.
	ratio�� 0�� �������� v1�� ������. 

	\~english
	Get a ratio of interior division of v1 and v2 by v1 -> v2.
	As ratio is closer to 0, it's closer to v1.

	\~chinese
	ϴ???v1��v2��v1->v2��?��?ratio��
	Ratio ������0����?������v1��

	\~japanese
	?��v1��v2��v1->v2�ت�?����ratio��ϴ��ު���
	Ratio��0���ΪŪ��۪�v1���Ϊ��Ǫ���
	\~
	*/
	template<typename FloatType>
	inline FloatType ScalarLerp(const FloatType v1, const FloatType v2, const FloatType ratio)
	{
		return v1 + (v2 - v1) * ratio;
	}

	/** 
	\~korean
	Vector 3D Ŭ����
	- Vector3T ���� �������� �ұ��ϰ� ���� ������ ������, �÷��� �� ������ �����̴�. 
	- ���� ���� ��Ȯ���� ����(��: ���ְ��� ����� �¶��� ����) FloatType�� ���� �ִ�. ���� ���� �뷮�� �ʿ�� �ϴ� ��� Vector3T ���
	�ٸ� ��ü Ÿ���� ���� ���� �����Ѵ�.
	- ��Ģ ���� �����ڸ� �����Ѵ�. ���� �Ʒ��� ���� �ڵ��� �����ϴ�.

	\~english
	Vector 3D Class
	- The purpose of this class is to avoid platform depedence even though Vector 3 already exists.
	- To increase the accuracy(i.e. Online game with the outer space backgroundw), FloatType is used. If you require the lower specification then we suggest
	to use a different object type rather than Vector 3.
	- This module supports arithmetic operators thus it's possible to code as shown in below.

	\~chinese
	Vector 3D?
	- ?����Vector3T��?�?��??�������?����?������ݾ?��
	- ?����������?�㣨�ǣ������?������??��?���������FloatType�������������?����?�������Vector3T�������?��?����
	- ����??ߩ?ߩݬ�����ʦ�����?�

	\~japanese
	Vector3D���髹
	- Vector3T�ʪɪ�����˪�?��骺��ܬ��?�ު��쪿��릪ϡ��׫�ëȫի�?��ު??�Ϊ���Ǫ���
	- ����Ԫ��������Ϊ����(�ǣ�����������تΫ���髤��?��)FloatType���Ūêƪ��ު�������������驪Ȫ������ꡢVector3T���۪�����Ϋ��֫������ȫ����ת��Ū����Ȫ�?�᪷�ު���
	- ������ߩ��ߩ���굪��ު�����êơ����Ϊ誦�ʫ�?�ǫ��󫰪�ʦ���Ǫ���

	\~


	\code
	Vector3T a = Vector3T(1,2,3);
	Vector3T b = Vector3T(4,5,6);
	Vector3T c = (a * b) + c - d;
	\endcode

	*/
	template <typename FloatType>
	struct Vector3T
	{
		/// x
		FloatType x;
		/// y
		FloatType y;
		/// z
		FloatType z;
	public:
		inline Vector3T() {};

		inline Vector3T( const FloatType * from)
		{
			x = from[0];
			y = from[1];
			z = from[2];
		}

		inline Vector3T( FloatType x, FloatType y, FloatType z )
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		// casting
		inline operator FloatType* () {
			return &x;
		}
		inline operator const FloatType* () const {
			return &x;
		}

#ifdef _WIN32
		template<typename D3DXVECTOR3>
		__forceinline Vector3T(const D3DXVECTOR3 &from)
		{
			x = from.x;
			y = from.y;
			z = from.z;
		}

		template<typename D3DXVECTOR3>
		__forceinline operator D3DXVECTOR3 const ()
		{
			D3DXVECTOR3 ret;
			ret.x = x;
			ret.y = y;
			ret.z = z;
			return ret;
		}
#endif // _WIN32

		// assignment operators
		inline Vector3T& operator += ( const Vector3T& src )
		{
			x += src.x;
			y += src.y;
			z += src.z;
			return *this;
		}

		inline Vector3T& operator -= ( const Vector3T& src)
		{
			x -= src.x;
			y -= src.y;
			z -= src.z;
			return *this;
		}

		inline Vector3T& operator *= ( FloatType scale)
		{
			x *= scale;
			y *= scale;
			z *= scale;
			return *this;
		}

		inline Vector3T& operator /= ( FloatType scale)
		{
			x /= scale;
			y /= scale;
			z /= scale;
			return *this;
		}

		// unary operators
		inline Vector3T operator + () const
		{			
			return *this;
		}

		inline Vector3T operator - () const
		{
			return Vector3T(-x,-y,-z);			
		}

		// binary operators
		inline Vector3T operator + ( const Vector3T& src) const
		{
			Vector3T ret;
			ret.x = x + src.x;
			ret.y = y + src.y;
			ret.z = z + src.z;

			return ret;
		}

		inline Vector3T operator - ( const Vector3T& src) const
		{
			Vector3T ret;
			ret.x = x - src.x;
			ret.y = y - src.y;
			ret.z = z - src.z;

			return ret;
		}

		inline Vector3T operator * ( FloatType scale) const
		{
			Vector3T ret;
			ret.x = x * scale;
			ret.y = y * scale;
			ret.z = z * scale;

			return ret;
		}

		inline Vector3T operator / ( FloatType scale) const
		{
			Vector3T ret;
			ret.x = x / scale;
			ret.y = y / scale;
			ret.z = z / scale;

			return ret;
		}

		inline bool operator == ( const Vector3T& rhs) const
		{
			return x == rhs.x && y == rhs.y && z == rhs.z;
		}
		inline bool operator != ( const Vector3T& rhs) const
		{
			return x != rhs.x || y != rhs.y || z != rhs.z;
		}

#if defined(_WIN32)        
		__declspec(property(get = GetLengthSq)) FloatType LengthSq;
		__declspec(property(get = GetLength)) FloatType Length;
#endif

		/** 
		\~korean 
		Normal Vector�� ���մϴ�.		
		
		\~english 
		Calculates the normal vector. 

		\~chinese
		ϴNormal Vector��

		\~japanese
		Normal Vector��ϴ��ު���
		\~
		*/
		inline Vector3T GetNormal() const
		{
			FloatType length=GetLength();
			return (length==0) ? Vector3T(0,0,0) : (*this) / length;
		}

		/** 
		\~korean 
		������ ������ ���մϴ�.		
		
		\~english 
		Calculate the square value of the length.	

		\~chinese
		ϴ?������۰��

		\~japanese
		�������?��ϴ��ު���
		\~
		*/
		inline FloatType GetLengthSq() const
		{
			return x*x + y*y + z*z;
		}

		/** 
		\~korean 
		vector�� ����		
		
		\~english 
		Length of the vector

		\~chinese
		Vector ��?����

		\~japanese
		Vector������
		\~
		*/
		inline FloatType GetLength() const
		{
			return sqrt(x*x + y*y + z*z);
		}

		/** 
		\~korean 
		�� vector�� �����մϴ�.  
		- a + (b - a) * ratio

		\~english 
		Interpolate two vectors.  
		- a + (b - a) * ratio


		\~chinese
		?��??vector��
		- a + (b - a) * ratio

		\~japanese
		?Vector�����ષ�ު���
		- a + (b - a) * ratio

		\~
		*/
		static inline Vector3T Lerp(const Vector3T &a,const Vector3T &b,FloatType ratio)
		{
			Vector3T ret;
			ret.x=ScalarLerp(a.x,b.x,ratio);
			ret.y=ScalarLerp(a.y,b.y,ratio);
			ret.z=ScalarLerp(a.z,b.z,ratio);
			
			return ret;
		}

		/** 
		\~korean 
		�� vector�� ������ ���մϴ� 
		
		\~english 
		Calculate the interval of two vectors

		\~chinese
		ϴ??vector��??��

		\~japanese
		?Vector��?�ݪ�ϴ��ު���
		\~
		*/
		static inline FloatType Dot(const Vector3T &a,const Vector3T &b)
		{
			return a.x*b.x+a.y*b.y+a.z*b.z;
		}

		inline FloatType Distance(const Vector3T &a) const
		{
			Vector3T d(a.x - x, a.y - y, a.z - z);
			return d.GetLength();
		}

		inline FloatType Distance2(const Vector3T &a) const
		{
			Vector3T d(a.x - x, a.y - y, a.z - z);
			return d.GetLengthSq();
		}

		/** 
		\~korean 
		������ ������ ������ ä ���̸� �����մϴ�.

		\~english 
		Sets the length of the vector to a specified length without changing the orientation.

		\~chinese 
		����?۰������?����?��?�����?��������?����

		\~japanese
		�٫��ȫ��۰�����򥪷���ުު����������ڪ��ު���
		\~
		*/
		inline void SetLength( FloatType length ) 
		{
			Vector3T n = GetNormal();
			n*=length;
			*this = n;
		}


	};

	template <typename FloatType>
	inline Vector3T<FloatType> operator * (FloatType scale, const struct Vector3T<FloatType>& src)
	{
		Vector3T<FloatType> ret;
		ret.x = scale * src.x;
		ret.y = scale * src.y;
		ret.z = scale * src.z;
		return ret;
	}

	typedef Vector3T<double> Vector3;
	typedef Vector3T<float> FloatVector3;


	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif