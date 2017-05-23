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
#include "Vector3D.h"

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

	class CPositionFollower_Interior;

	/**
	\~korean
	remote object�� jittering�Ǵ� position,velocity�� linear interpolation����
	smoothing ó���ϴ� class�̴�.

	���� ���, remote object�� dead reckoning�� �� �� �����ϴ�.

	(���߿�, �� class�� �����ؼ�, orientation�� quaternion ������ interpolation�ϴ�
	����� �߰��Ǿ �����ϰڴ�.)

	�Ϲ����� ����
	- <a target="_blank" href="http://guide.nettention.com/cpp_ko#dead_reckoning" >���� �׹�(dead reckoning)</a>  ����

	�߷¿� ���� ��� ����
	- ���� ���� �ִ� ���ӿ����� ĳ���Ͱ� ���� �� ���� �̵��� ����� ���ۿ� ����.
	���� �����߿��� �߷��� �ۿ��ؼ� ����ؼ� ���� ��� �׷��� �Ѵ�.
	�̷� �� SetGravity�� ���� �߷� ���� �̸� �־�� �� �ִ�.

	\~english
	Class that smoothing processes position,velocity of remote object that are 'jittering'ed into linear interpolation

	For an example, it is useful when dead reckoning remote object.

	(Later, it'd be useful if this class is strengthened to have interpolation function that converts orientation into quarternion.)

	General usage
	- Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#dead_reckoning" >Dead Reckoning</a>

	Considerations on gravity
	- In a game that has jump motions, the character jumps while moving in linear fashion must be somewhat un-natural.
	So, during jump motion, there must be gravity acting to result downward curve motion.
	In that case, you can use SetGravity to pre-input the gravity value.

	\~chinese
	��remote object��jittering��position,velocity ��linear interpolation?��smoothing?����class��

	������remote object?��dead reckoning��?�����ġ�

	�����ʥ˭�?����orientation��quaternion��?��interpolation��������ʥ?�����??����

	��������۰��
	- ?��<a target="_blank" href="http://guide.nettention.com/cpp_  #dead_reckoning" >��?۰�� (dead reckoning)</a>%��

	?��������?��?��
	- ��ԯ?������?������ԯ?������?�?����?����ԡ�����ԯ?�����������������???��������?��??��ʦ���?SetGravity��?�?������?��

	\~japanese
	remote object��jittering�����position��velocity��linear interpolation��smoothing?�⪹��class�Ǫ���
	�Ǫ��С� remote object��dead reckoning�򪹪��������ĪǪ���
	(���ǡ�����class����?���ơ�orientation��quaternion�ʪɪ�interpolation����Ѧ������ʥ����ƪ��ު����֪��ު�)
	�����ܪ�����۰��
	- \ref dead_reckoning  ?��

	������?������������
	- �����תʪɪ����뫲?��Ǫϡ�����髯��?�����������������ѪϪ������ʪ���������ު���
	��êơ���������˪����������Ī���?�������������ʪ��ڪ���驪�����ު���
	���Ϊ誦������SetGravity���ת������������ê�������Ǫ���驪�����ު���
	\~
	*/
	class CPositionFollower
	{
		CPositionFollower_Interior* m_interior;

	public:
		PROUD_API CPositionFollower();
		PROUD_API ~CPositionFollower();

		/**
		\~korean
		�߷��� �����Ѵ�.
		- �߷��� �����ϰ� �Ǹ�, follower�� target�� ��� ������ �޴´�.
		���� ���, ������ �ϴ� ĳ���Ͷ�� �� �޼��尡 �ʿ��� ���̴�.

		\~english
		Sets gravity
		- Once gravity is set then both follower and taget are affected.
		For an example, if it is a jumping character then it will need this method.

		\~chinese
		?��������
		- ?��������?follower��targetԴ?�����?��
		���������������ԯ?������ʦ��?����۰����

		\~japanese
		���������Ҫ��ު���
		- ���������Ҫ��몳�Ȫ˪ʪ�ȡ�follower��target�������ª������ު���
		�Ǫ��С������ת��뫭��髯��?�ʪ骳�Ϋ᫽�ëɪ���驪Ǫ���
		\~
		*/
		PROUD_API void SetGravity(const Vector3 &value);

		/**
		\~korean
		position follower�� �Ѿư� ���� ������Ʈ�� �ӵ��� �����Ѵ�.
		- Ÿ ȣ��Ʈ�κ��� ���� ĳ������ ��ġ�� ������ �� �޼��带 ȣ���� �ʿ䰡 ���� ���̴�.

		\~english
		Sets the speed of invisible object that position follower is to follow
		- When the location of opponent character is received from other host, there is a need to call this method.

		\~chinese
		?��position follower��?����٥object��������
		- ?����������?۰������������?��?�������У�۰����

		\~japanese
		position follower���Ī���������٥���֫������Ȫ����������Ҫ��ު��� 
		- ��Ϋ۫��Ȫ�����⢪Ϋ���髯��?�����Ǫ�������ȡ����Ϋ᫽�ëɪ���������驪�����ު���
		\~
		*/
		PROUD_API void SetTargetVelocity(const Vector3 &value);

		/**
		\~korean
		position follower�� �Ѿư� ���� ������Ʈ�� ��ġ�� �����Ѵ�.
		- Ÿ ȣ��Ʈ�κ��� ���� ĳ������ ��ġ�� ������ �� �޼��带 ȣ���� �ʿ䰡 ���� ���̴�.

		\~english
		Sets the location of invisible object that position follower is to follow
		- When the location of opponent character is received from other host, there is a need to call this method.

		\~chinese
		?��position follower��?����٥object�����ǡ�
		- ?����������?۰������������?��?�������У�۰����

		\~japanese
		position follower���Ī���������٥���֫������Ȫ����Ǫ����Ҫ��ު��� 
		- ��Ϋ۫��Ȫ�����⢪Ϋ���髯��?�����Ǫ�������ȡ����Ϋ᫽�ëɪ���������驪�����ު���
		\~
		*/
		PROUD_API void SetTargetPosition(const Vector3 &value);

		/**
		\~korean
		spline ���·� �Ѿư��� follower�� ��ġ�� ��´�.

		\~english
		Gets the location of follower that moves in spline shape

		\~chinese
		?���spline������?��follwer�����ǡ�

		\~japanese
		Spline����������������follower�����Ǫ���ު���
		\~
		*/
		PROUD_API Vector3 GetSplineFollowerPosition() const;

		/**
		\~korean
		spline ���·� �Ѿư��� follower�� �� �ӵ��� ��´�.

		\~english
		Gets the current speed of follower moves in spline shape

		\~chinese
		?���spline������?��follwer��?������

		\~japanese
		Spline����������������follower�������������ު���
		\~
		*/
		PROUD_API Vector3 GetSplineFollowerVelocity() const;

		/**
		\~korean
		���������� �Է��� �߷� ���� ��´�.

		\~english
		Gets the last input value of gravity

		\~chinese
		?������?��������?��

		\~japanese
		������������������������ު���
		\~
		*/
		PROUD_API Vector3 GetGravity() const;

		/**
		\~korean
		position follower�� �Ѿư��� ��ǥ ������ ���� �ӵ��� ��´�.

		\~english
		Gets the current speed of target location that position follower is following

		\~chinese
		?��position follower��?������?�����?������

		\~japanese
		position follower���Ī�������������ê������������ު���
		\~
		*/
		PROUD_API Vector3 GetTargetVelocity() const;

		/**
		\~korean
		position follower�� �Ѿư��� ��ǥ ������ ���� ��ġ�� ��´�.
		- SetTargetPosition���� �Է��� ���� �ٸ� �� �ִ�. �ֳ��ϸ� FrameMove�� ���� ���������� ���ŵǱ� �����̴�.

		\~english
		Get the current location of target location that position follower is following
		- Can be different to the value entered in SetTargetPosition since it is continuously updated by FrameMove

		\~chinese
		?��position follower��?������?�����?���ǡ�
		- ʦ��?�SetTargetPosition?����?���ҡ���?��FrameMove�?���档

		\~japanese
		position follower���Ī�������������ê�������Ǫ���ު���
		- SetTargetPosition���������������ު����Ȫ�����ު����ʪ��ʪ顢FrameMove�˪�ê��?�ܪ����檵��몫��Ǫ���
		\~
		*/
		PROUD_API Vector3 GetTargetPosition() const;

		/**
		\~korean
		position follower ��ü�� �ӵ��� �����Ѵ�.
		- remote object�� �ʱ� ���¸� ������ ���� ���δ�.

		\~english
		Sets the speed of position follower itself
		- Used to set the initial condition of remote object

		\~chinese
		���position follower������������
		- ������?��remote object�����???��

		\~japanese
		position follower �?����������Ҫ��ު���
		- remote object����Ѣ?�������Ҫ��������Ū��ު���
		\~
		*/
		PROUD_API void SetFollowerVelocity(const Vector3 &value);

		/**
		\~korean
		position follower ��ü�� ��ġ�� �����Ѵ�.
		- remote object�� �ʱ� ���¸� ������ ���� ���δ�.

		\~english
		Sets the location of position follower itself
		- Used to set the initial condition of remote object

		\~chinese
		���position follower���������ǡ�
		- ������?��remote object�����???��

		\~japanese
		position follower �?�����Ǫ���Ҫ��ު���
		- remote object����Ѣ?�������Ҫ��������Ū��ު���
		\~
		*/
		PROUD_API void SetFollowerPosition(const Vector3 &value);

		/**
		\~korean
		position follower ��ü�� ���� �ӵ��� ��´�.
		- SetFollowerVelocity���� �Է��� ���� �ٸ� �� �ִ�. �ֳ��ϸ� FrameMove�� ���� ���������� ���ŵǱ� �����̴�.

		\~english
		Gets the current speed of position follower itself
		- Can be different to the value entered in SetFollowerVelocity since it is continuously updated by FrameMove

		\~chinese
		?��position follower������?������
		- ʦ��?�SetFollowerVelocity?����?���ҡ���?��FrameMove�?���档

		\~japanese
		position follower �?�������������ު���
		- SetFollowerVelocity��������������춪ʪ����ꪬ����ު����ʪ��ʪ顢FrameMove�˪�ê��?�ܪ����檵��몫��Ǫ���
		\~
		*/
		PROUD_API Vector3 GetFollowerVelocity() const;

		/**
		\~korean
		position follower ��ü�� ���� ��ġ�� ��´�.
		- SetFollowerPosition���� �Է��� ���� �ٸ� �� �ִ�. �ֳ��ϸ� FrameMove�� ���� ���������� ���ŵǱ� �����̴�.

		\~english
		Gets the current location of position follower itself
		- Can be different to the value entered in SetFollowerPosition since it is continuously updated by FrameMove

		\~chinese
		?��position follower������?���ǡ�
		- ʦ��?�SetFollowerPosition?����?���ҡ���?��FrameMove�?���档

		\~japanese
		position follower �?��������Ǫ���ު���
		- SetFollowerVelocity��������������춪ʪ����ꪬ����ު����ʪ��ʪ顢FrameMove�˪�ê��?�ܪ����檵��몫��Ǫ���
		\~
		*/
		PROUD_API Vector3 GetFollowerPosition() const;

		/**
		\~korean
		���� ���� ���� target position�� follower���� �Ÿ����� ����ġ�� ū ���, �ǵ��� ����, ������
		Ȥ�� ����ģ ������ ���� ��ġ ������ �� �ִ�. �̷� ��� ��ġ ������ ������ �̻��� ����� �߱��Ѵ�.
		warp threshold�� ���س����� ����ġ�� ū ��ġ ������ ��� ������ ���� �ʰ� ������ follower�� target ��ġ��
		��ġ��Ų��.
		\param warpThreshold ��ġ ������ ������ �� �ִ� �Ӱ谪���μ��� �Ÿ�

		\~english
		If newly received target position is too far from the location of follower, it may be location error due to intentional warp, resapwn or extreme lags. In this case, performing location correction will make the situation worse.
		    if warp threshold is set then it does not perform correction but forcefully synchronizes follower with target location.
		\param warpThreshold distance as critical value that can ignore location correction

		\~chinese
		�����������target position?follower����?���?����?��ʦ������?warp��resapwn�����?����lag������?󬡣??�����������������������?����
		?��warp threshold��?����??��������?�����??����?�����ᣬ���˭�������follower?target������?�����ա�
		\param warpThreshold ��?ʦ���?��������?ͣ?����?��

		\~japanese
		�⪷���檿��������target position��follower�Ȫ�����󬪬���ު�˪��ު������ꡢ��?�ܪʫ�?�ס��쫹��?��ު��ϫ�ë��˪��������Ǫ��몫����ު��󡣪��Ϊ�����ꡢ��������Ϫષ��������̿�����ê����ު���
		warp threshold��̽����Ǫ��Ъ��ު�˪��ު�������������ꡢ����򪷪ʪ�?��follower target���Ǫ����Ȫ����ު���
		\param warpThreshold ������������ʪǪ�����ͣ���Ȫ��ƪ�����
		\~
		*/
		PROUD_API void SetWarpThreshold(double warpThreshold);

		/**
		\~korean
		FrameMove()�� 1ȸ �̻� ���Ǿ��°�?

		\~english
		FrameMove() used more than once?

		\~chinese
		FrameMove()������?����߾?��

		\~japanese
		FrameMove()��1���߾�Ū�쪿�Ϊ���
		\~
		*/
		PROUD_API bool IsFirstUse();

		/**
		\~korean
		follower�� target���� �ٴٸ��� �ð��� �����Ѵ�.
		- EnableAutoFollowDuration(true)�� ȣ���� �����̸� �� �޼���� ������ ���õȴ�. ���, ���������� ������
		duration�� �ڵ����� ã�´�.
		- �� ���� �Ϲ������� SetTargetPosition,SetTarget,SetTargetVelocity�� ȣ��Ǵ� �ֱ⺸�� �ణ ��� ��� ���� ����.
		����ġ�� ���� ���� ������ �������� �ʹ� Ƣ��, �ʹ� ū ���� ������ �������� ��Ȯ���� ��������.
		\param duration follower�� target���� �ٴٸ��� �ð�(�ʴ���)

		\~english
		Sets the time taken that follower gets to target
		- This method will be ignored if EnableAutoFollowDuration(true) is called. Instead, it automatically finds suitable duration internally.
		- Usually, it is ideal to set this value a little bit larger than the period that calls SetTargetPosition,SetTarget,SetTargetVelocity.
		  If the value is too small then the movement will be jumpy but if too large then the precision of movement will be lost.
		\param duration time taken that follower gets to target (in second)

		\~chinese
		?��follower��?target��??��
		- ��������УEnableAutoFollowDuration(true)��??��?�۰����?��?����?����?�?ݻ?�???������duration��
		- �������??������SetTargetPosition,SetTarget,SetTargetVelocity ����У���Ѣ��ڰ??����
		?��?�?��??��?��?�ѣ�?��?��??������?��?˽�
		\param duration follower��?target��??����?�ȣ���

		\~japanese
		Follower��target�ު�����������Ҫ��ު���
		- EnableAutoFollowDuration(true)�������󪷪�?���Ǫ���С����Ϋ᫽�ëɪ�?�������ʪ���ު����۪��ˡ�?ݻ�ܪ���﷪�duration����Ѫ������ު���
		- �������������ܪ�SetTargetPosition,SetTarget,SetTargetVelocity�������󪵪���Ѣ���ᴪ��������ê�۰���ު��Ǫ���
		���ު�˪�ᳪ��������������Ѫ����Ȫƪ���ء�êơ����ު�˪��ު��������������Ѫ�����������ժ���ު���
		\param duration follower��target�ު�������(��?��) 
		\~
		*/
		PROUD_API void SetFollowDuration(double duration);
		/**
		\~korean
		���������� SetFollowDuration���� �Է��� ���� ����Ѵ�.

		\~english
		Outputs the last value entered to SetFollowDuration

		\~chinese
		?��������SetFollowDuration?����?��

		\~japanese
		������SetFollowDuration���������������������ު��� 
		\~
		*/
		PROUD_API double GetFollowDuration();
		/**
		\~korean
		true�� �����ϸ� follower�� target���� �ٴٸ��� �ð��� �ڵ����� �����Ѵ�.

		\~english
		If set as true then it automatically controls the time taken for follower to get to taget.

		\~chinese
		?��?true��?�??��follower��?target��??��

		\~japanese
		True�����Ҫ����follower��target�ު�������������ｪ��ު��� 
		\~
		*/
		PROUD_API void EnableAutoFollowDuration(bool val);

		/**
		\~korean
		follower�� ���󰡴� target�� pos, vel�� ���Ѵ�.
		\param position ���� Ÿ���� ��ġ vector3
		\param velocity ���� Ÿ���� �ӵ� vector3

		\~english TODO:translate needed.
		Calculate the pos and vel of the target followed by the follower. 
		\param position Vector 3 location of the target to be obtained for the position. 
		\param velocity Vector 3 speed of the target to be obtained for the velocity.

		\~chinese
		ϴfollower��?��target��pos, vel��
		\param position �?����target����vector3��
		\param velocity �?����target����vector3��

		\~japanese
		Follower���Ī�������target��pos, vel��ϴ��ު���
		\param position ���?�뫿?���ëȪ����� vector3
		\param velocity ���?�뫿?���ëȪ����� vector3
		\~
		*/
		PROUD_API void GetTarget(Vector3 &position, Vector3 &velocity) const;

		/**
		\~korean
		follower�� position, velocity�� ���Ѵ�.
		\param position ���� Follower�� ��ġ vector3
		\param velocity ���� Follower�� �ӵ� vector3

		\~english TODO:translate needed.
		Gets position, velocity of follower

		\~chinese
		ϴfollower��?��target��position, velocity��
		\param position �?����target����vector3��
		\param velocity �?����target����vector3��

		\~japanese
		Follower��position, velocity��ϴ��ު���
		\param velocity ���?��Follower������ vector3 
		\~
		*/
		PROUD_API void GetFollower(Vector3 &position, Vector3 &velocity) const;

		/**
		\~korean
		SetFollowerVelocity,SetFollowerPosition�� �ѹ��� ��� ȣ���Ѵ�.

		\~english
		Calls SetFollowerVelocity,SetFollowerPosition at the same time

		\~chinese
		�������ݻ��УSetFollowerVelocity,SetFollowerPosition��

		\~japanese
		SetFollowerVelocity,SetFollowerPosition����������ƪ������󪷪ު��� 
		\~
		*/
		PROUD_API void SetFollower(Vector3 position, Vector3 velocity);

		/**
		\~korean
		�� Ÿ�� �����Ӹ��� �� �޼��带 ȣ���ؾ� �Ѵ�.
		\param elapsedTime �� �������� �ð�(��)

		\~english
		This method must be called by each time frame.
		\param elapsedTime length of a frame(in second)

		\~chinese
		����?time frame��У�۰����
		\param elapsedTime ��?frame��??��������

		\~japanese
		������ի�?�઴�Ȫ˪��Ϋ᫽�ëɪ������󪵪ʪ���Ъʪ�ު���
		\param elapsedTime ��ի�?�������(��) 
		\~
		*/
		PROUD_API virtual void FrameMove(double elapsedTime);

		/**
		\~korean
		SetTargetPosition�� SetTargetVelocity�� �ѹ��� ��� ȣ���Ѵ�.

		\~english
		Calls SetTargetPosition and SetTargetVelocity at the same time

		\~chinese
		�������ݻ��УSetTargetPosition��SetTargetVelocity��

		\~japanese
		SetTargetPosition��SetTargetVelocity����������ƪ������󪷪ު���
		\~
		*/
		PROUD_API virtual void SetTarget(Vector3 position, Vector3 velocity);
	};

	/**  @} */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
