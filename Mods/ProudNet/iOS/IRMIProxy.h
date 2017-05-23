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
#include "FakeClr.h"
#include "Enums.h"
#include "IRmiHost.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup net_group
	*  @{
	*/

	class RmiContext;
	class CNetCoreImpl;
	class CMessage;
	class MessageSummary;

	/** 
	\~korean
	PIDL �����Ϸ��� ������ Proxy Ŭ������ ���̽� Ŭ����

	���� ����
	- �� Ŭ������ ������ ���� �������� �� ��. PIDL �����Ϸ����� ������ ���� ������ �ؾ� �Ѵ�.

	\~english
	Base class of Proxy class created by PIDL compiler

	Note
	- User must not create this class. Must be realized by PIDL compiler.

	\~chinese
	PIDL??��������Proxy?������?��

	�������
	- ��?�������??�?���PIDL??�������??��?ड�

	\~japanese
	PIDL����ѫ���?����������Proxy���髹�Ϋ�?�����髹

	���������
	- ���Ϋ��髹���?��?������?�ު��ʪ����ȡ�PIDL����ѫ���?�˪�ê�?�ު�����Ϊ��Ū��誦�˪��ު���
	\~
	*/
	class IRmiProxy
	{
	public:
		IRmiHost* m_core;
		bool m_internalUse; // true�̸� ProudNet ����. ����ڴ� �ǵ��� ����
		int m_signature;

		/** 
		\~korean
		true�� �����ϸ� NotifySendByProxy �� ȣ����� �� �ִ�.
		- true�� �����ϸ� ���� ������ ���� ��������. ������ �� ���� ���̵� �Ʊ�� ��Ȳ�̶�� �� ���� false�� �������ָ� �ȴ�.
		- �⺻���� true�̴�.

		\~english
		If set as true then NotifySendByProxy can be called
		- When set as true, it lowers process performance  by a little. But, if you cannot afford to hasve the loss then set this as false.
		- Default is true.

		\~chinese
		?��?true��?ʦ���УNotifySendByProxy��
		- ?��?true��??������?��ڰ��˽��ӣ?������������������?�����??��?false?ʦ��
		- ��??��true��

		\~japanese
		true�����Ҫ����NotifySendByProxy�������󪷪ƪ�骨�ު���
		- true�����Ҫ����?��������ᴪ�ժ���ު����������������������ê����ʪ�?�Ϫʪ骳������false�����Ҫ��ƪ���������
		- ��������ture�Ǫ���
		\~
		*/
		bool m_enableNotifySendByProxy;

		/** 
		\~korean
		����ڴ� �� �Լ��� �������̵����� ���ʽÿ�.

		\~english
		User must not override this function.

		\~chinese
		��?����������?��

		\~japanese
		��?��?�Ϫ���??��?��?�髤�ɪ��ʪ��Ǫ���������
		\~
		*/
		virtual RmiID* GetRmiIDList() = 0;
		/** 
		\~korean
		����ڴ� �� �Լ��� �������̵����� ���ʽÿ�.

		\~english
		User must not override this function.

		\~chinese
		��?����������?��

		\~japanese
		-��?��?�Ϫ���??��?��?�髤�ɪ��ʪ��Ǫ���������
		\~
		*/
		virtual int GetRmiIDListCount() = 0;
	
		/** 
		\~korean
		�޽��� �۽��� ���� RMI�� ȣ���� ��(�� proxy���� ȣ���ϱ�)���� �� �Լ��� callback�˴ϴ�.
		�����ʷ��� RMI ��� �α׸� ������� �� �� �� �Լ��� ����Ͻø� �˴ϴ�. �ڼ��� ������ <a target="_blank" href="http://guide.nettention.com/cpp_ko#monitor_rmi_proxy" >�۽���(Proxy) ȣ�� ������ �����ϱ�</a> �� �����Ͻʽÿ�.
		- �����ڰ� ������ ��� ������ ȣ��˴ϴ�. 
		- �⺻ �Լ��� �ƹ��͵� ���� �ʽ��ϴ�.
		
		���� �۽� ������ RmiContext �� ���� ������ �� �ִ� ��ȸ�� �����մϴ�. 
		(��ȸ�� �ִ� ����: �۽Ž� �߸��� ���� ������ ���� �Բ� ���� ������ �����Դϴ�.
		���º�Ÿ���������� ���� �м��� �ذ��� ���ÿ� �ؾ� �ϴϱ��. )
		\param sendTo ������
		\param summary ������ RMI �޽����� ��� ����
		\param rmiContext ����ڰ� ȣ���� RmiContext ���Դϴ�.

		\~english
		This function is called back every time RMI is called for message send(e.g. calling from proxy).
		This function is used when there is a need to leave porfiler or RMI use log. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#monitor_rmi_proxy" >Approaching Transmission (Proxy) call</a>.
		- Multiple reciever cause multiple calling.
		- Base function does not do anything. 
		
		Plus, this provides a cance to finally modify RmiContext before sending.
		(Why the last chance is given: for the case there is an incorrect value and to notify, warn and modify finally. During OBT, we need to do prob analysis and solving at the same time.)
		\param sendTo reciever
		\param summary gist of RMI message to be sent
		\param rmiContext RmiContext value called by user

		\~chinese
		?��������?�꣬��?��УRMI��?��(?�proxy��У)�����??callback��
		���profiler���RMI����log��?ʦ��������?��???�??��<a target="_blank" href="http://guide.nettention.com/cpp_zh#monitor_rmi_proxy" >����۰(Proxy) �����������</a>%��
		- ������??����?����У?󭡣
		- ������?����������ס�

		���?�����������?����RmiContext����?��
		��?��?����릣�?��?��?������???���?��ͱ������?���ǡ����??���??��??�������?��
		\param sendTo �����
		\param summary ?����RMI������?����ӡ�
		\param rmiContext ��?��У��RmiContext?��

		\~japanese
		��ë�?������Ϊ����RMI������������?����proxy�������󪹣����Ȫ˪���??��callback����ު���
		�׫�ի�?��?�Ȫ�RMI���ī���?��������������??���Ūêƪ����������٪����ϡ�\ref monitor_rmi_proxy��?�Ϊ���������
		- ��������?�Ǫ����������?�������󪵪�ު���
		- ����??�����⪷�ު���

		�ު�������������RmiContext���������᪹��Ѧ?����ꪷ�ު���
		��Ѧ?��?������릣������������ުê������������ͱ�ȪȪ����������Ϊ���Ǫ���
		��?�׫�٫�?���êǪ������ప���̽�������˪��ʪ���Ъʪ�ު��󪫪飩
		\param sendTo �����
		\param summary ���RMI��ë�?����������
		\param rmiContext ��?��?�������󪷪�RmiContext ���Ǫ���
		\~
		*/
		PROUD_API virtual void NotifySendByProxy(const HostID* remotes, int remoteCount, const MessageSummary &summary, RmiContext &rmiContext, const CMessage &msg);
		
		/** 	
		\~korean
		���� �Լ��Դϴ�. ����ڴ� �� �Լ��� �������̵����� ���ʽÿ�. 
		ProudClr ���� �������̵��ϱ����� public ���� �ؾ���

		\~english
		User must not override this function.
		Must be public in order to override at ProudClr 

		\~chinese
		?ݻ��?����?����������?��
		�ProudClr��?�������public��

		\~japanese
		?ݻ??�Ǫ�����?��?�Ϫ���??��?��?�髤�ɪ��ʪ��Ǫ���������
		ProudClr�ǫ�?��?�髤�ɪ��몿��˪�public�˪��ƪ���������
		\~
		*/
		PROUD_API virtual bool RmiSend(const HostID* remotes, int remoteCount, RmiContext &rmiContext, const CMessage &msg, const PNTCHAR* RMIName, RmiID RMIId);

		PROUD_API IRmiProxy();
		PROUD_API virtual ~IRmiProxy();
	};

	extern const PNTCHAR* ProxyBadSignatureErrorText;

	/**  @} */
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
