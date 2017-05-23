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
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif
	/** \addtogroup util_group
	*  @{
	*/

	/** 
	\~korean
	Ư���� ������ ���� �ε巴�� ������ ��ȭ�ϵ��� �Ѵ�.
	������ �ε巯�� �������� ������ �� ����ϴ� Ŭ�����̴�.
	���� ���, remote character�� ���� ��ȯ�� �ε巴�� �̷������ ó�� � ȿ�����̴�.

	�Ϲ����� ����:
	- GetFollowerAngle()��, follower angle�� �ִ´�. (���� �ʱ� 1ȸ)
	- SetTargetAngle()��, target angle�� �����Ѵ�. ��� �� framemove���� �Ѵ�.
	- FrameMove()�� �� �����Ӹ��� ȣ���Ѵ�.
	- �� �����ӹ̴� GetTargetAngle()�� follower angle�� ��´�.

	\~english
	This method helps changing an angle more smoothly.
	This class is helpful and effective in handling smooth direction change of remote character.

	General Usage:
	- Insert a follower angle with GetFollowerAngle() (Normally at one inital time)
	- Assign a target angle with SetTargetAngle(). Normally set a target at every each framemove.
	- Calll for FrameMove() at each frame.
	- Get a follower angle by GetTargetAngle() at each frame.

	\~chinese
	��������������?������?�?����
	??��������??��?������class��
	������?remote character��۰��??��??����?����������

	��������۰����
	- �� GetFollowerAngle()%ۯ��follower angle����������Ѣ��󭣩
	- �� SetTargetAngle()%���target angle��������framemove���ġ�
	- ��frameԴ���� FrameMove()%��
	- ��frameԴ�� GetTargetAngle()%?��follower angle��

	\~japanese
	���Ҫ��������������骫��������?������誦�˪��ު���
	���������骫���Ѫ���?�ު��������Ū����髹�Ǫ���
	�Ǫ��С�remote character��۰��?�������骫��������?��ʪɪ�?���ܪǪ���

	�����ܪ�����۰����
	- GetFollowerAngle()�� follower angle������ު��������Ȫ���Ѣ1�ޣ�
	- SetTargetAngle()�� target angle����Ҫ��ު������ȡ�framemove���Ȫ������ު���
	- FrameMove()��?�ի�?�઴�Ȫ������󪷪ު���
	- �ի�?�઴�Ȫ�GetTargetAngle()��follower angle����ު���
	\~
	 */
	class CAngleFollower
	{
		double m_followerAngle; // following angle, �� source.
		double m_targetAngle; // following target, �� source�� �� ���� �����ϰ� ���Ѵ�.
		double m_followerAngleVelocity; // follower�� ���ӵ�
	public:
		PROUD_API CAngleFollower(void);
		PROUD_API ~CAngleFollower(void);

		/**
		\~korean
		�� �����Ӹ��� �� �޼��带 ȣ���ؾ� follower�� ���� ��� ���Ѵ�.
		\param elapsedTime ������ ó�� �ð�(in sec)

		\~english TODO:translate needed.
		The follower changes the value constantly when this method is called in every frame
		\param elapsedTime frame processing time (in sec)


		\~chinese
		��frameԴ������method��follower?�ʦ�??��?��
		\param elapsedTime frame��?�����죨in sec��

		\~japanese
		�ի�?�઴�Ȫ˪��Ϋ᫽�ëɪ������󪹪�follower������?����?���ު���
		\param elapsedTime �ի�?��?������(in sec)
		\~
		*/
		PROUD_API void FrameMove(double elapsedTime);

		/**
		\~korean
		follower angle�� �����Ѵ�.
		\param value ����(in radian)

		\~english TODO:translate needed.
		Set the follower angle
		\param value angle (in radian)


		\~chinese
		?��follower angle��
		\param value ������in radian��

		\~japanese
		follower angle�򫻫ëƫ��󫰪��ު���
		\param value ����(in radian)
		\~
		*/
		PROUD_API void SetFollowerAngle(double value);

		/**
		\~korean
		follower angle�� ���Ѵ�.
		\return ����(in radian)

		\~english TODO:translate needed.
		Calculate the follower angle
		\return angle (in radian)


		\~chinese
		ϴfollower angle��
		\return ������in radian��

		\~japanese
		follower angle��ϴ��ު���
		\return ����(in radian)
		\~
		*/
		PROUD_API double GetFollowerAngle();

		/**
		\~korean
		target angle�� �����Ѵ�.
		\param value ����(in radian)

		\~english TODO:translate needed.
		Set the target angle
		\param value angle (in radian)


		\~chinese
		?��target angle��
		\param value ������in radian��

		\~japanese
		target angle�򫻫ëƫ��󫰪��ު���'	
		\param value ����(in radian)
		\~
		*/
		PROUD_API void SetTargetAngle(double value);

		/**
		\~korean
		target angle�� ���Ѵ�.
		\return ����(in radian)

		\~english TODO:translate needed.
		Calculate the target angle
		\return angle (in radian)


		\~chinese
		ϴtarget angle��
		\return ������in radian��

		\~japanese
		target angle��ϴ��ު���
		\return ����(in radian)
		\~
		*/
		PROUD_API double GetTargetAngle();

		/**
		\~korean
		follower�� �̵� ���ӵ��� �ִ´�.
		\param value ���ӵ�(in radian/sec)

		\~english TODO:translate needed.
		Insert the moving angle speed of the follower
		\param value angle speed (in radian/sec)


		\~chinese
		ۯ��follower���?��������
		\param value ��������in radian/sec��

		\~japanese
		follower�����������������ު���
		\param value ������(in radian/sec)
		\~
		*/
		PROUD_API void SetFollowerAngleVelocity(double value);

		/**
		\~korean
		follower�� �̵� ���ӵ��� ���Ѵ�.
		\return ���ӵ�(in radian/sec)

		\~english TODO:translate needed.
		Calculate the moving angle speed of the follower
		\return angle speed (in radian/sec)


		\~chinese
		ϴfollower���?��������
		\return ��������in radian/sec��

		\~japanese
		follower�������������ϴ��ު���
		\return ������(in radian/sec)
		\~
		*/
		PROUD_API double GetFollowerAngleVelocity();
        
#if defined(_MSC_VER)
		__declspec(property(get = GetFollowerAngle, put = SetFollowerAngle)) double followerAngle;
		__declspec(property(get = GetTargetAngle, put = SetTargetAngle)) double targetAngle;
		__declspec(property(get = GetFollowerAngleVelocity, put = SetFollowerAngleVelocity)) double followerAngleVelocity;
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