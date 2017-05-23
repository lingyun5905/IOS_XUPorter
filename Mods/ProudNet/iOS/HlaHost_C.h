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

#include "HlaEntity_C.h"
#include "HlaDelagate_Common.h" 

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud 
{
	class CHlaEntityManagerBase_C;
	class CriticalSection;
	class IHlaDelegate_C;

	/**
	\~korean
	HLA ���� Ŭ���̾�Ʈ �޼��� �������̽��Դϴ�. 

	\~english TODO:translate needed.
	This is the HLA session client method interface. 

	\~chinese
	��HLA session��ʫ۰��ͣ����
	
	\~japanese
	HLA���ë���󫯫髤����ȫ᫽�ëɫ���?�ի�?���Ǫ���
	\~
	*/
	class IHlaHost_C
	{
	public:
		virtual ~IHlaHost_C() {};

		/** 
		\~korean
		HLA entity class�� ����մϴ�. 
		HLA entity class�� HLA compiler output�̾�� �մϴ�. 

		\~english TODO:translate needed.
		Register the HLA entity class
		The HLA entity class shall be HLA complier output. 
	
		\~chinese
		��?HLA entity class��
		HLA entity class����HLA compiler output��

		\~japanese
		HLA entity class����?���ު���
		HLA entity class��HLA compiler output�ǪϪʪ���Ъʪ�ު���
		\~
		*/
		virtual void HlaAttachEntityTypes(CHlaEntityManagerBase_C* entityManager) = 0;

		/** 
		\~korean
		�� ��⿡ ���� �ݹ�Ǵ� �޼������ ������ ��ü�� �޾Ƶ��Դϴ�.

		\~english TODO:translate needed.
		It receives the objects implementing the methods called back by this module. 
	
		\~chinese
		����??���ټ?����?۰����?�ڡ�

		\~japanese
		���Ϋ⫸��?��˪�êƫ�?��Ыë������᫽�ëɪ�?�ު������֫������Ȫ���������ު���
		\~
		*/
 		virtual void HlaSetDelegate(IHlaDelegate_C* dg) = 0;

		/** 
		\~korean
		����ڴ� �� �Լ��� ���� �ð����� �� �ؾ� �մϴ�.

		\~english TODO:translate needed.
		The user shall call this function at a regular interval. 
	
		\~chinese
		��?���̰��ӫ����??��?���?��

		\~japanese
		��?��?�Ϫ���??��������઴�Ȫ˫�?�몷�ʪ���Ъʪ�ު���
		\~
		*/
		virtual void HlaFrameMove() = 0;

	};

	/** 
	\~korean
	HLA ���� Ŭ���̾�Ʈ�� ���� �ݹ�Ǵ� �������̽��Դϴ�. 
	
	����
	- C++ �̿� ���������� �� �޼���� delegate callback ������ �� �ֽ��ϴ�.
	
	\~english TODO:translate needed.
	This is an interface called back by HLA session client. 

	Note
	- In versions other than C++, this method may be in the form of delegate callback. 
	
	\~chinese
	��HLA session��ʫ��?��ͣ����

	?��
	- �C++��������⣬�۰��ʦ����delegate callback���ҡ�

	\~japanese
	HLA���ë���󫯫髤����Ȫ˪�êƫ�?��Ыë�����뫤��?�ի�?���Ǫ���

	?��
	- C++ ���Ϋ�?�����Ǫϡ���᫽�ëɪ�delegate callback �����˪ʪ����ꪬ����ު���
	\~
	*/
	class IHlaDelegate_C:public IHlaDelegate_Common
	{
	public:
		virtual ~IHlaDelegate_C() {}

		/** 
		\~korean
		HLA entity�� �����Ǹ� �� �޼��尡 �ݹ�˴ϴ�.
		HlaOnLockCriticalSection()�� ���� lock�� ������ ���¿��� ȣ��˴ϴ�.

		\~english TODO:translate needed.
		When an HLA entity is generated, this method is called back. 
		This is called when the lock is performed by HlaOnLockCriticalSection()
	
		\~chinese
		����HLA entity��?�۰��?��?��
		��HlaOnLockCriticalSection()?��lock��??��������

		\~japanese
		HLA entity�����������Ъ��Ϋ᫽�ëɪ���?��Ыë�����ު���
		HlaOnLockCriticalSection()�˪�êƫ�ë����������?���������󪵪�ު���
		\~
		*/
		virtual void HlaOnEntityAppear( CHlaEntity_C* entity ) = 0;

		/** 
		\~korean
		HLA entity�� �ı��Ǹ� �� �޼��尡 �ݹ�˴ϴ�.
		����� �� �Լ����� entity�� ������ ���� �ı��ؾ� �մϴ�. �ȱ׷��� memory leak���� �̾����ϴ�.
		(C# ���������� �ı��� �� �ʿ䰡 �����ϴ�. garbage collector�� ���� ���ŵǱ� �����Դϴ�.)
		\code
			delete entity;
		\endcode
		HlaOnLockCriticalSection()�� ���� lock�� ������ ���¿��� ȣ��˴ϴ�.

		\~english TODO:translate needed.
		When an HLA entity is destroyed, this method is called back. 
		You must destroy the entity as shown below, otherwise it will lead to memory leak. 
		(You don��t have to destroy in C# version, for it is removed by the garbage collector)
		\code
		delete entity;
		\endcode It is called while the lock is performed by HlaOnLockCriticalSection()
		
	
		\~chinese
		HLA entity ����?��?�۰��?��?��
		?�����?������?entity����??����memory leak��
		��� C# ����?�������?����??��garbage collector?𶣩
		\code
			delete entity;
		\endcode
		��HlaOnLockCriticalSection()?��lock��??��������

		\~japanese
		HLA entity����?�����Ъ��Ϋ᫽�ëɪ���?��Ыë�����ު���
		���ʪ��Ϫ���??��entity���Ϊ誦����?���ʪ���Ъʪ�ު��󡣪���Ȫ⡢memory leak�˪Īʪ���ު���
		(C#��?�����Ǫ���?������驪�����ު���garbage collector�˪�ê���۪���몿��Ǫ���)
		\code
		delete entity;
		\endcode
		HlaOnLockCriticalSection()�˪�êƫ�ë����������?���������󪵪�ު���
		

		\~
		*/
		virtual void HlaOnEntityDisappear( CHlaEntity_C* entity ) = 0;
	};
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif