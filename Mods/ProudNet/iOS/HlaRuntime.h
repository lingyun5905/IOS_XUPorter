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

#include "HlaDef.h"
#include "Message.h"
#include "Ptr.h"
#include "PNString.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	class SynchEntity_S;
	class SynchEntity_C;
	class SynchViewport_S;

#define DECLARE_HLA_MEMBER(behavior,type,name) \
private: behavior<type> m_##name##_INTERNAL; \
public: type get_##name() { return m_##name##_INTERNAL.Get(); } \
	void set_##name(type newVal) { m_##name##_INTERNAL.Set(newVal); } \
	__declspec(property(get=get_##name,put=set_##name)) type name;

	class SynchEntities_S: public map<HlaInstanceID, SynchEntity_S*>
	{
	};

	class SynchViewports_S: public map<HlaInstanceID, SynchViewport_S*>
	{
	};

	/** 
	\~korean
	SynchEntity Ŭ���̾�Ʈ�� �ݷ���

	��Ʈ
	- ���� �� �ݷ��ǰ� �޸�, �� �ݷ����� ��ü ������ �������� ������ �ִ�. �ֳ��ϸ� �� �ݷ��� �������� ������ ��Ʈ���Ͽ� ����� ������ �ƴϱ� �����̴�.

	\~english
	SynchEntity client-side collection

	Note
	- Unlike the collection in server-side, this collection has the ownership of the objects. Because the collection items are
	created not under control of user.

	\~chinese
	SynchEntity client-side collection

	���
	- ?��?���� collection ���ң�� collection ?������?������?����?� collection Գ���������?�������?���ܡ�

	\~japanese
	SynchEntity ���髤����������쫯�����

	��?��
	- ��?��?���Ϋ��쫯�����Ȫ��ުêơ����Ϋ��쫯�����ϫ��֫��������?�����?���êƪ��ު����ʪ��ʪ顢���Ϋ��쫯����󫢫��ƫ�ϫ�?��?�Ϋ���ȫ�?��������ª����ΪǪϪʪ�����Ǫ���
	\~
	*/
	class SynchEntities_C: public map<HlaInstanceID, RefCount<SynchEntity_C> >
	{
	};

	class IHlaRuntimeDelegate_S
	{
	public:
		virtual ~IHlaRuntimeDelegate_S();

		virtual void Send(HostID dest, Protocol protocol, CMessage& message) = 0;

		// determines if one synch entity is visible (tangible) to one viewport
		virtual bool IsOneSynchEntityTangibleToOneViewport(SynchEntity_S* entity, SynchViewport_S *viewport) = 0;
	};

	/** 
	\~korean
	������ HLA ��Ÿ�� ���

	����
	- �� ��ü�� �����Ѵ�.
	- SWD compiler-generated Ŭ���� �ν��Ͻ��� �����ϰ� �� ��ü�� ��ģ��.

	\~english
	Server-side HLA runtime module

	Usage
	- Create this object
	- Create SWD compiler-generated class instances and associate them to this object

	\~chinese
	��?��۰ HLA ?��??ټ?

	����۰��
	- �����?�ڡ�
	- ���� SWD compiler-generated ??��??�?����?��

	\~japanese
	��?��?��HLA��󫿫���⫸��?��

	����۰��
	- ���Ϋ��֫������Ȫ��������ު���
	- SWD compiler-generated ���髹�Ϋ��󫹫��󫹪��������ƪ��Ϋ��֫������Ȫ���請�ު���
	\~
	*/

	class CHlaRuntime_S
	{
		HlaInstanceID m_instanceIDFactory;
		IHlaRuntimeDelegate_S* m_dg;
	public:
		CHlaRuntime_S(IHlaRuntimeDelegate_S* dg);
		~CHlaRuntime_S(void);

		SynchEntities_S m_synchEntities;
		SynchViewports_S m_synchViewports;

		HlaInstanceID CreateInstanceID();
		void FrameMove(double elapsedTime);

		void Check_OneSynchEntity_EveryViewport(SynchEntity_S *entity);
		void Check_EverySynchEntity_OneViewport(SynchViewport_S *viewport);
		void Check_EverySynchEntity_EveryViewport();
	private:
		void Check_OneSynchEntity_OneViewport( SynchEntity_S * entity, SynchViewport_S* viewport, CMessage appearMsg, CMessage disappearMsg );
		void Send_INTERNAL(vector<HostID> sendTo, Protocol protocol, CMessage &msg);
	public:
		void RemoveOneSynchEntity_INTERNAL(SynchEntity_S* entity);
		void RemoveOneSynchViewport_INTERNAL( SynchViewport_S* entity );
	};

	class IHlaRuntimeDelegate_C
	{
	public:
		virtual ~IHlaRuntimeDelegate_C();
		virtual SynchEntity_C* CreateSynchEntityByClassID(HlaClassID classID) = 0;
	};

	/** 
	\~korean
	Ŭ���̾�Ʈ�� HLA ���� ��Ÿ��

	����
	- �� ��ü�� �����ϰ� SWD �����Ϸ��� ���� ������� �ϳ� �Ǵ� �̻��� HLA ��Ÿ�� delegate��� ��ģ��.
	- ProcessReceivedMessage()�� ���� �� ��ü�� ���� �޼����� �����Ѵ�.
	\~english
	HLA client-side main runtime

	Usage
	- Create this object and associate one or more HLA runtime delegates which are generated by SWD compiler.
	- Pass the received message to this object by ProcessReceivedMessage(). 

	\~chinese
	Client ۰ HLA ��?��??

	����۰��
	- �����?�����?� SWD ������?������?�����?�߾�� HLA ?��?? delegate ?����?��
	- � ProcessReceivedMessage()???�??��������ӡ�

	\~japanese
	���髤�������HLA�᫤���󫿫���

	����۰��
	- ���Ϋ��֫������Ȫ���������SWD����ѫ���?�˪�ê��ª�쪿��Īު��Ϫ����߾��HLA��󫿫���delegate�ʪɪ���請�ު���
	- ProcessReceivedMessage()�˪�êƪ��Ϋ��֫������Ȫ���������ë�?����?ӹ���ު���
	\~
	*/
	class CHlaRuntime_C
	{
		SynchEntity_C* CreateSynchEntityByClassID( HlaClassID classID , HlaInstanceID instanceID);
		typedef vector<IHlaRuntimeDelegate_C*> DgList;
		DgList m_dgList;
		String m_lastProcessMessageReport;
	public:
		SynchEntities_C m_synchEntities;

		CHlaRuntime_C() {}
		~CHlaRuntime_C() {}

		void AddDelegate(IHlaRuntimeDelegate_C *dg);
		void ProcessReceivedMessage(CMessage& msg);
		SynchEntity_C* GetSynchEntityByID(HlaInstanceID instanceID);

		String GetLastProcessMessageReport();
		void Clear();
	};

	Protocol CombineProtocol(Protocol a, Protocol b);
}

//#pragma pack(pop)

?/*
ProudNet

�� ���α׷��� ���۱��� ���ټǿ��� �ֽ��ϴ�.
�� ���α׷��� ����, ���, ������ ���õ� ������ �� ���α׷��� �������ڿ��� ����� ������,
����� �ؼ����� �ʴ� ��� ��Ģ������ ���� ����� �����մϴ�.
���� ��뿡 ���� å���� �� ���α׷��� �������ڿ��� ��༭�� ��õǾ� �ֽ��ϴ�.

** ����: ���۹��� ���� ���� ��ø� �������� ���ʽÿ�.

ProudNet

This program is soley copyrighted by Nettention. 
Any use, correction, and distribution of this program are subject to the terms and conditions of the License Agreement.
Any violated use of this program is prohibited and will be cause of immediate termination according to the License Agreement.

** WARNING : PLEASE DO NOT REMOVE THE LEGAL NOTICE ABOVE. 

ProudNet

���������??Nettention�������
?����������ǡ����ġ�?����?����?���������������?���??��
������???��?�������������ġ�
���������?��٥���?��������?�������?�졣

** ��������?�����ڪ��߾��٥�ơ�

*/

#pragma once

#include "hladef.h"
#include "message.h"
#include "ptr.h"
#include "PNString.h"

#ifndef __GNUC__

//#pragma pack(push,8)

namespace Proud
{
	class SynchEntity_S;
	class SynchEntity_C;
	class SynchViewport_S;

#define DECLARE_HLA_MEMBER(behavior,type,name) \
private: behavior<type> m_##name##_INTERNAL; \
public: type get_##name() { return m_##name##_INTERNAL.Get(); } \
	void set_##name(type newVal) { m_##name##_INTERNAL.Set(newVal); } \
	__declspec(property(get=get_##name,put=set_##name)) type name;

	class SynchEntities_S: public map<HlaInstanceID, SynchEntity_S*>
	{
	};

	class SynchViewports_S: public map<HlaInstanceID, SynchViewport_S*>
	{
	};

	/** 
	\~korean
	SynchEntity Ŭ���̾�Ʈ�� �ݷ���

	��Ʈ
	- ���� �� �ݷ��ǰ� �޸�, �� �ݷ����� ��ü ������ �������� ������ �ִ�. �ֳ��ϸ� �� �ݷ��� �������� ������ ��Ʈ���Ͽ� ����� ������ �ƴϱ� �����̴�.

	\~english
	SynchEntity client-side collection

	Note
	- Unlike the collection in server-side, this collection has the ownership of the objects. Because the collection items are
	created not under control of user.

	\~chinese
	SynchEntity client-side collection

	���
	- ?��?���� collection ���ң�� collection ?������?������?����?� collection Գ���������?�������?���ܡ�

	\~japanese
	SynchEntity ���髤����������쫯�����

	��?��
	- ��?��?���Ϋ��쫯�����Ȫ��ުêơ����Ϋ��쫯�����ϫ��֫��������?�����?���êƪ��ު����ʪ��ʪ顢���Ϋ��쫯����󫢫��ƫ�ϫ�?��?�Ϋ���ȫ�?��������ª�쪿��ΪǪϪʪ�����Ǫ���
	\~
	*/
	class SynchEntities_C: public map<HlaInstanceID, RefCount<SynchEntity_C> >
	{
	};

	class IHlaRuntimeDelegate_S
	{
	public:
		virtual ~IHlaRuntimeDelegate_S();

		virtual void Send(HostID dest, Protocol protocol, CMessage& message) = 0;

		// determines if one synch entity is visible (tangible) to one viewport
		virtual bool IsOneSynchEntityTangibleToOneViewport(SynchEntity_S* entity, SynchViewport_S *viewport) = 0;
	};

	/** 
	\~korean
	������ HLA ��Ÿ�� ���

	����
	- �� ��ü�� �����Ѵ�.
	- SWD compiler-generated Ŭ���� �ν��Ͻ��� �����ϰ� �� ��ü�� ��ģ��.

	\~english
	Server-side HLA runtime module

	Usage
	- Create this object
	- Create SWD compiler-generated class instances and associate them to this object

	\~chinese
	��?��۰ HLA ?��??ټ?

	����۰��
	- �����?�ڡ�
	- ���� SWD compiler-generated ??��??�?����?��

	\~japanese
	��?��?��HLA��󫿫���⫸��?��

	����۰��
	- ���Ϋ��֫������Ȫ��������ު���
	- SWD compiler-generated ���髹���󫹫��󫹪��������ƪ��Ϋ��֫������Ȫ���請�ު���
	\~
	*/
	class CHlaRuntime_S
	{
		HlaInstanceID m_instanceIDFactory;
		IHlaRuntimeDelegate_S* m_dg;
	public:
		CHlaRuntime_S(IHlaRuntimeDelegate_S* dg);
		~CHlaRuntime_S(void);

		SynchEntities_S m_synchEntities;
		SynchViewports_S m_synchViewports;

		HlaInstanceID CreateInstanceID();
		void FrameMove(double elapsedTime);

		void Check_OneSynchEntity_EveryViewport(SynchEntity_S *entity);
		void Check_EverySynchEntity_OneViewport(SynchViewport_S *viewport);
		void Check_EverySynchEntity_EveryViewport();
	private:
		void Check_OneSynchEntity_OneViewport( SynchEntity_S * entity, SynchViewport_S* viewport, CMessage appearMsg, CMessage disappearMsg );
		void Send_INTERNAL(vector<HostID> sendTo, Protocol protocol, CMessage &msg);
	public:
		void RemoveOneSynchEntity_INTERNAL(SynchEntity_S* entity);
		void RemoveOneSynchViewport_INTERNAL( SynchViewport_S* entity );
	};

	class IHlaRuntimeDelegate_C
	{
	public:
		virtual ~IHlaRuntimeDelegate_C();
		virtual SynchEntity_C* CreateSynchEntityByClassID(HlaClassID classID) = 0;
	};

	/** 
	\~korean
	Ŭ���̾�Ʈ�� HLA ���� ��Ÿ��

	����
	- �� ��ü�� �����ϰ� SWD �����Ϸ��� ���� ������� �ϳ� �Ǵ� �̻��� HLA ��Ÿ�� delegate��� ��ģ��.
	- ProcessReceivedMessage()�� ���� �� ��ü�� ���� �޼����� �����Ѵ�.

	\~english
	HLA client-side main runtime

	Usage
	- Create this object and associate one or more HLA runtime delegates which are generated by SWD compiler.
	- Pass the received message to this object by ProcessReceivedMessage().

	\~chinese
	Client۰HLA��?��??

	����۰��
	- �����?�����?�SWD������?������?�����?�߾��HLA?��??delegate?����?��
	- � ProcessReceivedMessage()???�??��������ӡ�

	\~japanese
	���髤�������HLA�᫤���󫿫���

	����۰��
	- ���Ϋ��֫������Ȫ���������SWD����ѫ���?�˪�ê��ª�쪿��Īު��Ϫ����߾��HLA��󫿫���delegate�ʪɪ���請�ު���
	- ProcessReceivedMessage()�˪�êƪ��Ϋ��֫������Ȫ���������ë�?����?ӹ���ު���
	\~
	*/
	class CHlaRuntime_C
	{
		SynchEntity_C* CreateSynchEntityByClassID( HlaClassID classID , HlaInstanceID instanceID);
		typedef vector<IHlaRuntimeDelegate_C*> DgList;
		DgList m_dgList;
		String m_lastProcessMessageReport;
	public:
		SynchEntities_C m_synchEntities;

		CHlaRuntime_C() {}
		~CHlaRuntime_C() {}

		void AddDelegate(IHlaRuntimeDelegate_C *dg);
		void ProcessReceivedMessage(CMessage& msg);
		SynchEntity_C* GetSynchEntityByID(HlaInstanceID instanceID);

		String GetLastProcessMessageReport();
		void Clear();
	};

	Protocol CombineProtocol(Protocol a, Protocol b);
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif // __GNUC__
<<<<
