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

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

#ifdef USE_HLA
#include "HlaEntity_S.h"
#include "HlaDelagate_Common.h"

namespace Proud 
{
	class CHlaEntityManagerBase_S;
	class CriticalSection;
	class CHlaSpace_S;
	class IHlaDelegate_S;

	/**
	\~korean
	HLA ���� ���� �޼��� �������̽��Դϴ�.

	\~english TODO:translate needed.
	This is a HLA session server method interface. 

	\~chinese
	��HLA session��?��۰��ͣ����

	\~japanese
	HLA���ë����?��?�᫽�ëɫ���?�ի�?���Ǫ���
	\~
	*/
	class IHlaHost_S
	{
	public:
		virtual ~IHlaHost_S() {};

		/** 
		\~korean
		HLA entity class�� ����մϴ�. 
		HLA entity class�� HLA compiler output�̾�� �մϴ�. 

		\~english TODO:translate needed.
		An HLA entity class is registered. 
		An HLA entity class must be HLA complier output. 
	
		\~chinese
		��?HLA entity class��
		HLA entity class����HLA compiler output��

		\~japanese
		HLA entity class����?���ު���
		HLA entity class��HLA compiler output�ǪϪʪ���Ъʪ�ު���

		*/
		virtual void HlaAttachEntityTypes(CHlaEntityManagerBase_S* entityManager) = 0;

		/** 
		\~korean
		�� ��⿡ ���� �ݹ�Ǵ� �޼������ ������ ��ü�� �޾Ƶ��Դϴ�. 

		\~english TODO:translate needed.
		This receives the objects that implements the methods called back by this module. 
	
		\~chinese
		����??���ټ?����?۰����?�ڡ�

		\~japanese
		���Ϋ⫸��?��˪�êƫ�?��Ыë������᫽�ëɪ�?�ު������֫������Ȫ���������ު���

		*/
		virtual void HlaSetDelegate(IHlaDelegate_S* dg) = 0;

		/** 
		\~korean
		����ڴ� �� �Լ��� ���� �ð����� �� �ؾ� �մϴ�. 

		\~english TODO:translate needed.
		Users must call this function at a certain interval. 
	
		\~chinese
		��?����̰��ӫ???���?��

		\~japanese
		��?��?�Ϫ���??��������઴�Ȫ������󪵪ʪ���Ъʪ�ު���

		*/
		virtual void HlaFrameMove() = 0;
		
		virtual CHlaSpace_S* HlaCreateSpace() = 0;
		virtual void HlaDestroySpace(CHlaSpace_S* space) = 0;

		virtual CHlaEntity_S* HlaCreateEntity(HlaClassID classID) = 0;
		virtual void HlaDestroyEntity(CHlaEntity_S* Entity) = 0;

		virtual void HlaViewSpace(HostID viewerID, CHlaSpace_S* space, double levelOfDetail = 1) = 0;
		virtual void HlaUnviewSpace(HostID viewerID, CHlaSpace_S* space) = 0;
	};

	/** 
	\~korean
	HLA ���� ������ ���� �ݹ�Ǵ� �������̽��Դϴ�. 
	
	����
	- C++ �̿� ���������� �� �޼���� delegate callback ������ �� �ֽ��ϴ�. 

	\~english
	This is an interface called back by the HLA session server.

	Note
	- In versions other than C++, this method may be in the form of delegate callback. 
	
	\~chinese
	��HLA??��?����?����Ϣ�� 
	?��
	- �C++ ��������������۰��ʦ���delegate callback���ҡ� 

	\~japanese
	HLA���ë����?��?�˪�êƫ�?��Ыë�����뫤��?�ի�?���Ǫ���
	
	?��
	- C++ ���Ϋ�?�����Ǫϡ���᫽�ëɪ�delegate callback�����Ǫ������ꪬ����ު���

	*/
	class IHlaDelegate_S:public IHlaDelegate_Common
	{
	public:
		virtual ~IHlaDelegate_S() {}

	};
}
#endif
#ifdef _MSC_VER
#pragma pack(pop)
#endif