/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 177 92 124 113 87 79 17 155 171 239 138 133 88 235 28 112 146 102 93 52 214 131 240 31 138 179 248 115 127 118 107 31 112 91 111 14 243 1 121 131 22 69 144 19 214 101 65 133 253 32 122 175 12 198 63 134 23 240 109 90 59 142 194 194 160 148 139 101 68 220 217 181 32 240 36 47 59 74 18 182 145 116 17 29 255 115 236 11 29 111 122  */
/*
ProudNet 1.7.34387-dev003-10


�� ���α׷��� ���۱��� ���ټǿ��� �ֽ��ϴ�.
�� ���α׷��� ����, ���, ������ ���õ� ������ �� ���α׷��� �������ڿ��� ����� ������,
����� �ؼ����� �ʴ� ��� ��Ģ������ ���� ����� �����մϴ�.
���� ��뿡 ���� å���� �� ���α׷��� �������ڿ��� ��༭�� ��õǾ� �ֽ��ϴ�.

** ����: ���۹��� ���� ���� ��ø� �������� ���ʽÿ�.


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

#if defined(_WIN32)
#include "Ptr.h"
#include "NetServerInterface.h"
#include "dbenums.h"
#include "DbLoadedData2.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif
	/** \addtogroup db_group
	*  @{
	*/
	class IDbCacheClientDelegate2;


	/**
	\~korean
	DB cache server�� �����ϱ� ���� ���� ����

	\~english
	Connect information in order to connect to DB cache server

	\~chinese
	?��?��DB cache server ��?�����ӡ�

	\~japanese
	DB cache server����?���몿�����?����
	\~
	*/
	class CDbCacheClient2ConnectParameter
	{
	public:
		/**
		\~korean
		���� �ּ�

		\~english
		Server address

		\~chinese
		��?����

		\~japanese
		��?��?���ɫ쫹
		\~
		*/
		String m_serverAddr;

		/**
		\~korean
		Ŭ���̾�Ʈ�� ������ ������ ���ε��� �ּ��Դϴ�.
		- �ʱⰪ�� �� ���ڿ��Դϴ�.
		- ��������� �� ���ڿ��� ���������� Ŭ���̾�Ʈ�� ��Ʈ��ũ �������̽�(NIC)�� 2�� �̻� ������ ���,
		�׸��� �װ͵� �� �ϳ����� �ٸ� CLanClient���� ���� ���� ��û�� ���� �� �ִ� ��� ���⿡ �ش�˴ϴ�.
		NIC�� ������ IP �Ǵ� ȣ��Ʈ �̸��� �����ؾ� �մϴ�. ȣ��Ʈ�� �ִ� NIC �ּ� ����Ʈ�� �������� Proud.GetLocalIPAddresses�� �� �� �ֽ��ϴ�.
		- ȣ��Ʈ �̸��� ������ ��� Ŭ���̾�Ʈ�� ������ �����ϱ� ���� �ּҷ� localhost�� �Է��� ��� ���� ���и� �� �� �ֽ��ϴ�. �̷��� ���
		Ŭ���̾�Ʈ�� ������ �����ϱ� ���� ���� ȣ��Ʈ�� �ּҸ� ��������� �Է��ؾ� �մϴ�.

		\~english
		The address that the listening socket of the client to be bound.
		- The initial value is an empty string.
		- Usually set as an empty string but in case when the client has 2 or more of network interfaces (NICs)
		and when only one of them is able to recieve the connection request from other CLanClient, it is the case to use this.
		The IP address or the host name designated by the NIC must be used. Proud.GetLocalIPAddresses can be used to get the NIC address list located in the host.
		- In the case that a host name is used, a connection failure can occur when localhost is set as the address to connect to the server for a client.
		In this case, the client must be set clearly as the server host address in order to connect to the server.

		\~chinese
		��ʫ���??Ϣ���boud���򣡣
		- ��??�����ݬ?��
		- ����?��������ݬ����?��ʫ?��??�߾??ͣ����NIC����?����?������������?����??�� CLanClient%??��?���?��?��??�??��
		����?NIC�����IP������٣�����?�������NIC��֪����?ʦ����� Proud.GetLocalIPAddresses%��
		- ������٣���?������ʫ?��?����?��?��localhot��?��ʦ��??����?��??����?������??��?����?��??٥������?����?��������򣡣

		\~japanese
		���髤����ȪΫ꫹�˫󫰫����ëȪ��Ы���ǫ��󫰪���뫢�ɫ쫹�Ǫ���
		- ��Ѣ�����������֪�Ǫ���
		- ���ȡ��������֪����Ҫ��ު��������髤����Ȫ��ͫëȫ�?������?�ի�?��(NIC)��2���߾�êƪ������ꡢ�����ƪ����Ϊ�����ĪΪߪ��ު�CLanClient����?����?���������������ꪬ�������?���ު���
		NIC����Ҫ��쪿IP�ު��ϫ۫���٣����Ҫ��ʪ���Ъʪ�ު��󡣫۫��Ȫ˪���NIC���ɫ쫹�꫹�Ȫ���몿��˪�Proud.GetLocalIPAddresses���Ū����Ȫ��Ǫ��ު���
		- �۫���٣����Ҫ������ꡢ���髤����Ȫϫ�?��?����?���몿��Ϋ��ɫ쫹��localhost�������������ꡢ��?������ʦ����������ު������Ϊ誦�����ꡢ���髤����Ȫϫ�?��?����?���몿��˫�?��?�۫��ȪΫ��ɫ쫹��٥���ܪ��������ʪ���Ъʪ�ު���

		\~
		*/
		String m_localNicAddr;

		/**
		\~korean
		���� ��Ʈ

		\~english
		Server port

		\~chinese
		��?��ӮϢ

		\~japanese
		��?��?��?��
		\~
		*/
		uint16_t m_serverPort;

		/**
		\~korean
		���� ����Ű. CDbCacheServer2StartParameter.m_authenticationKey �� ���� ���̾�� �մϴ�.

		\~english
		Server authentication key. It has to same value with bCacheServer2StartParameter.m_authenticationKey

		\~chinese
		��?��???���? CDbCacheServer2StartParameter.m_authenticationKey%��?��?��

		\~japanese
		��?��?��?��?��CDbCacheServer2StartParameter.m_authenticationKey���Ҫ����ǪϪʪ���Ъʪ�ު���
		\~
		*/
		String m_authenticationKey;

		/**
		\~korean
		�̺�Ʈ �ݹ��� �ޱ� ���� delegate ��ü

		\~english
		Delegate object to receive event callback

		\~chinese
		?������event��?��delegate?�ڡ�

		\~japanese
		���٫�ȫ�?��Ыë��������몿���delegate���֫�������
		\~
		*/
		IDbCacheClientDelegate2* m_delegate;

		/**
		\~korean
		������ Ǯ�� ������ ����. �ּ��� 1�� �����Ǿ�� �մϴ�.
		- �ʱⰪ�� 0�̴�. 0�� �����ϸ� CPU ������ �����˴ϴ�.

		\~english
		The number of threads in thread pool. Must be set as at least 1.
		- The initial value is 0. If it is set as 0 then it is set as the number of CPUs.

		\~chinese
		?������?��??���������?1��
		- ���?��0�����0��?��?���?CUP??��

		\~japanese
		����ëɫ�?��Ϋ���ë���?�������1����Ҫ���ʪ���Ъʪ�ު���
		- ��Ѣ����0�Ǫ���0����Ҫ����CPU?����Ҫ���ު���
		\~
		*/
		int m_userWorkerThreadCount;

		/**
		\~korean
		�� ���� null�� �ƴϸ�, �ܺ� networker thread �� ����մϴ�.
		Proud.CStartLanServerParameter.m_externalNetWorkerThreadPool �� ���� ������ �մϴ�.

		\~english
		If this value is not null, an external networker thread will be used.
		It acts as Proud.CStartLanServerParameter.m_externalNetWorkerThreadPool.

		\~chinese
		�?����null��?������ݻnetworker thread��
		���? Proud.CStartLanServerParameter.m_externalNetWorkerThreadPool%��?�����ġ�

		\~japanese
		��������null�ǪϪʪ����ꡢ��ݻ networker threa �����Ī��ު���
		Proud.CStartLanServerParameter.m_externalNetWorkerThreadPool ���Ҫ���ܪ򪷪ު���

		*/
		CThreadPool* m_externalNetWorkerThreadPool;

		/**
		\~korean
		�� ���� null�� �ƴϸ�, �ܺ� user worker thread�� ����մϴ�.
		Proud.CStartLanServerParameter.m_externalUserWorkerThreadPool �� ���� ������ �մϴ�.

		\~english
		If this value is not null, an external user worker thread will be used.
		It acts as Proud.CStartLanServerParameter.m_externalUserWorkerThreadPool.

		\~chinese
		�?����null��?��������ݻuser worker thread��
		���? Proud.CStartLanServerParameter.m_externalUserWorkerThreadPool%��?�����ġ�


		\~japanese
		��������null�ǪϪʪ����ꡢ��ݻ user worker threa �����Ī��ު���
		Proud.CStartLanServerParameter.m_externalUserWorkerThreadPool ���Ҫ���ܪ򪷪ު���

		*/
		CThreadPool* m_externalUserWorkerThreadPool;

		/**
		\~korean
		- OnException �ݹ� ����� ����� �� ���θ� �����մϴ�.
		- �⺻���� true�Դϴ�.
		- ���� false�� �����ϸ� ���� �ݹ鿡�� ����ġ ���� Exception �߻� �� OnException�� ȣ����� �ʰ� ũ���ð� �߻��մϴ�.

		\~english
		- Decide whether it uses OnException callback function or not.
		- Default value is true.
		- If setting it as false, when exception occurs during  user callback, crash will occur as OnException is not called.

		\~chinese
		- ??�������� OnException Callback������
		- ����?? true��
		- �������false����?�Callback?����?������������ Exception ?��OnException?���������?��Crash��

		\~japanese
		- OnException CallbackѦ�������Ī��몫�ɪ�������?���ު���
		- �ǫի��������true�Ǫ���
		- �⪷false����Ҫ���ȫ�?��?Callback�������̪Ǫ��ʪ�Exception��?�檷������OnException�������󪵪쪺�˫���ë��媬?�檷�ު���

		\~
		*/
		bool m_allowOnExceptionCallback;

		CDbCacheClient2ConnectParameter();
	};

	/**
	\~korean
	DB cache client2�κ����� �̺�Ʈ �ݹ��� �ޱ� ���� delegate ��ü

	\~english
	Delegate object to receive event callback from DB cache client

	\~chinese
	?��?DB cache client2����event��?����delegate?�ڡ�

	\~japanese
	DB cache client2����Ϋ��٫�ȫ�?��Ыë��������몿���delegate���֫�������
	\~
	*/
	class IDbCacheClientDelegate2
	{
	public:
		/**
		\~korean
		�̺�Ʈ�� �ݹ��������� Arguments

		\~english
		Arguments when event called back

		\~chinese
		event ��?��?����Arguments��

		\~japanese
		���٫�Ȫ���?��Ыë���������Arguments
		\~
		*/
		class CCallbackArgs
		{
		public:
			/**
			\~korean
			������ Ʈ�� 1���� ���� ������ ���� Ŭ�����Դϴ�.

			\~english
			This is a class containing the information on one data tree.

			\~chinese
			������??��?������?��

			\~japanese
			��?���ī�?1����?�������ê����쪿���髹�Ǫ���

			\~
			*/
			class CItem
			{
			public:
				/**
				\~korean
				DBCacheClient�� �޼ҵ�� �� message�� ���ڷ� �޴� ��û����
				�ش� ��û���� ���� ������ �޴� �ٸ� Loader Ȥ�� ��û�ڿ��� message�� ���� �� �� �ֽ��ϴ�.
				�� message�� ���޹޴� �Ķ���Ͱ� �ٷ� �̰��Դϴ�.

				\~english
				The requests receiving the message as a factor amongst the methods of DBCacheClient can deliver the message to another loader or the requester. 
				The parameter receiving the message is this.

				\~chinese
				�DBCacheClient��۰����������??��?ϴʦ�������??ϴ�?������Loader��?ϴ�?����ӡ�
				���?�����??����??��

				\~japanese
				DBCacheClient�Ϋ᫽�ëɪΪ���message���������������ϡ���?���˪�ê���ª���������Ϋ�?��?�ު��������message��?ӹ���몳�Ȫ��Ǫ��ު���
				����message��?ӹ���ƪ�骦�ѫ��?��?����������Ǫ���

				\~
				*/
				ByteArray m_message;

				/**
				\~korean
				�ش� Callback�� ���õ� �������� Session�Դϴ�.

				\~english
				The data session related to the Callback. 

				\~chinese
				??Callback��?��?��??��

				\~japanese
				��?Callback��?֧���쪿��?����Session�Ǫ���
				\~
				*/
				Guid m_sessionGuid;

				/**
				\~korean
				�ش� Callback�� ���õ� �������� RootUUID

				\~english
				The data RootUUID related to the Callback

				\~chinese
				??Callback��?��?����RootUUID

				\~japanese
				��?Callback��?֧���쪿��?����RootUUID
				\~
				*/
				Guid m_rootUUID;

				/**
				\~korean
				- �߰�,������Ʈ, �����ÿ� �۾��� �Ϸ�� ��ü data�� ������ (�̰��� �����ϴ� ���� ���� ���� ���� ����� �ƹ��� ������ �����ϴ�.)
				- �ش� Callback�� ���õ� ������ Ʈ���Դϴ�.

				\~english
				Snapshot of all completed data when you do add, update, remove (Changing this value does not affect saving actual game information)

				\~chinese
				��ʥ���?��?���?��������������ݻdata��snapshot����?�????��?������?��?������?ͧ������

				\~japanese
				- ��ʥ�����ë׫�?�ȡ���������������������쪿��?��?���Ϋ��ʫë׫���ë�(��������?�ڪ��몳�Ȫ�?𷫲?�����ê�����������?֧������ު���)
				- ��?Callback��?֧���쪿��?���ī�?�Ǫ���

				\~
				*/
				CLoadedData2Ptr m_loadedData;

				/**
				\~korean
				�ش� Callback�� �����Ͽ� ������ �Ͼ ����� UUID

				\~english
				The UUID of the node where a change occurred related to the Callback

				\~chinese
				??Callback��?����?����?����UUID

				\~japanese
				��?Callback��?֧����?�ڪ��ê�����?�ɪ�UUDI
				\~
				*/
				Guid m_UUID;

				/**
				\~korean
				- �߰�,������Ʈ, �����ÿ� �۾��� �Ϸ�� ���۾� data�� ������ (�̰��� �����ϴ� ���� ���� ���� ���� ����� �ƹ��� ������ �����ϴ�.)
				- �ش� Callback�� ���õ� ����Դϴ�.

				\~english
				Snapshot of actual data when you do add, update, remove (Changing this value does not affect saving actual game information)

				\~chinese
				��ʥ���?��?���?��������������ݻdata��snapshot����?�????��?������?��?������?ͧ������

				\~japanese
				- ��ʥ�����ë׫�?�ȡ���������������������쪿�ꫢ��������?���Ϋ��ʫë׫���ë�(��������?�ڪ��몳�Ȫ�?𷫲?�����ê�����������?֧������ު���)
				-����?Callback��?֧���쪿��?�ɪǪ���

				\~
				*/
				CPropNodePtr m_data;

				/**
				\~korean
				- ���� �� ������ ����.
				- ��û�� ����/���� ���θ� �����Ϸ��� �� ���� ErrorType_Ok�� �ƴ��� Ȯ���ؾ� �մϴ�.

				\~english
				- Reason for the failure when failed
				- whether the request has succeeded or failed should be determined, check to make sure whether this value is ErrorType_Ok or not. 

				\~chinese
				- ��?��릡�
				- ?��?ϴ����������������??�?������ErrorType_Ok��

				\~japanese
				- �������������������
				- ��������/����ʦ����?�ª��몿��˪ϡ���������ErrorType_OK�ǪϪʪ������㪹����驪�����ު���

				\~
				*/
				ErrorType m_reason;

				/**
				\~korean
				���� �� ���� �ڸ�Ʈ

				\~english
				When it failed, comment about reason

				\~chinese
				��??��?��??�?��

				\~japanese
				��������?֧������
				\~
				*/
				String m_comment;

				/**
				\~korean
				���нÿ� ����HRESULT �̰��� S_OK��� com_error�� �����Ѱ��� �ƴմϴ�.

				\~english
				HRESULT from when it failed. If it is S_OK, it is not failed with com_error

				\~chinese
				��??��?��HRESULT��S_OK��?����com_error��?��

				\~japanese
				����������HRESULT�����쪬S_OK�ʪ�com_error�����������ΪǪϪ���ު���
				\~
				*/
				HRESULT m_hResult;

				/**
				\~korean
				���нÿ� ���� source �̰��� ���ٸ� ������ �����Ѱ��� �ƴմϴ�.

				\~english
				Source from when it failed. If it have not got this, it is not failed during quary

				\~chinese
				��???����?source���������quary?��?�ܡ�

				\~japanese
				����������source�����쪬�ʪ���Ы�����?������������ΪǪϪ���ު���
				\~
				*/
				String m_source;

				CItem();
			};
			typedef CFastArray<CItem> Items;

			/**
			\~korean
			��û�� ���õ� ������ Ʈ������ ���� ����Դϴ�.
			������� byQuery �迭�� ��û���� ���� ���ǿ� �´� ���� ���� ������ Ʈ������ ��ȯ�ϰ� �Ǵµ�
			�̵��� �޾� ó���Ϸ��� �� ����� ��ȸ�ؾ� �մϴ�.

			\code
			// example
			void IDbCacheClientDelegate2::OnExclusiveLoadDataComplete(CCallbackArgs& args)
			{
			    for ( CLoadResults::iterator it=m_loadResults.begin(); it!=m_loadResults.end(); ++it )
			    {
			        CLoadResult& result = *it;
			        if ( result.m_reason == ErrorType_Ok )
			        {
			            // success
			        }
			        else
			        {
			            // fail
			        }
			    }
			    // ...
			}

			\endcode

			\~english
			This is the list containing the data trees related to the request. 
			. For example, the byQuery series requests return several data trees matching the query condition and to receive to process them, this list must be circulated. 


			\~chinese
			����?ϴ��??��?��֪����
			������byQuery ֪ͧ��?ϴ?����ݬ��?������??��?��?��?��?�����?֪��?����?��

			\endcode

			\~japanese
			����?֧������?���ī�?��?�ᪿ�꫹�ȪǪ���
			�Ǫ��С�byQuery֪ͧ�����ϫ�����??����ꪦ��?�Ϋ�?���ī�?����������誦�˪ʪ�ު����������������?�⪹�몿��˪Ϫ��Ϋ꫹�Ȫ����ު��ʪ���Ъʪ�ު���

			\endcode

			\~

			\code
			// example
			void IDbCacheClientDelegate2::OnExclusiveLoadDataComplete(CCallbackArgs&args)
			{
				for ( CLoadResults::iterator it=m_loadResults.begin(); it!=m_loadResults.end(); ++it )
				{
					CLoadResult& result = *it;
					if ( result.m_reason == ErrorType_Ok )
					{
						// success
					}
					else
					{
						// fail
					}
				}
				// ...
			}
			\endcode
			*/
			Items m_items;

			/**
			\~korean
			��û �� ȣ���ڰ� �־��� ����� ���� ��. ������ �����ͷ� ���˴ϴ�.
			tag�� �޴� ��û���� ȣ�� �� �Է��� tag���� ���信�� �� ������ ���� �״�� �����ݴϴ�.

			\~english
			User defined value that entered by invoker when it requested.
			Normally it uses for pointer. If you request with it then will receive same thing

			\~chinese
			�??��У�?������?��?��?������������pointer������???���?? ?�����?����?��

			\~japanese
			����������������쪿��?��?�����������תϫݫ���?�����Ī���ު���
			Tag������������������������������tag����?�ͪǪ���??���ת����Ϊު������ު���

			\~
			*/
			intptr_t m_tag;

			CCallbackArgs();
		};

		virtual ~IDbCacheClientDelegate2() {}

		/**
		\~korean
		���� ���� �õ� ����� �����մϴ�.
		\param info ������������ ���������Դϴ�. �����ÿ��� info.m_errorType �� ErrorType_Ok �Դϴ�.

		\~english
		Returns the results of server connection attempts.
		\param info This is failed information. When it succeed, ErrorType_Ok will be in info.m_errorType.

		\~chinese
		������?��???����?����
		\param info ��??������?���ӡ�����?� info.m_errorType%?ErrorType_Ok��

		\~japanese
		��?��?��?�˪���̿����꫿?�󪷪ު���
		\param info �������������������êǪ����������˪�info.m_errorType��ErrorType_Ok�Ǫ���

		\~
		*/
		virtual void OnJoinDbCacheServerComplete(ErrorInfo *info) = 0;

		/**
		\~korean
		DB cache server���� ������ ���������� ��Ƽ�մϴ�.
		- �̰��� ȣ��� ��Ȳ������, �̹� DB cache client�� ��� �����Ͱ� unload�� �����Դϴ�.
		\param reason �������� ����

		\~english
		Notifies that the connection to DB cache server is finished
		- Under the circumstance that this is called, all data in DB cache client is already unloaded.
		\param reason reason to disconnecting

		\~chinese
		���?DB cache server ��?�����������
		- ??����У����?����DB cache client �����?���?��unload��??��
		\param reason ���?������릡�

		\~japanese
		DB cache server�Ȫ���?����𶪵�쪿���Ȫ���򱪷�ު���
		- ���쪬�����󪵪쪿?�ϪǪϪ��Ǫ�DB cache client����ƪΫ�?����unload���쪿?���Ǫ���
		\param reason ��?������

		\~
		*/
		virtual void OnLeaveDbCacheServer(ErrorType reason) = 0;

		/**
		\~korean
		DB cache server���� DBMS�� ����ϴ� ������ ���� ������ �����ϴ� �̺�Ʈ�Դϴ�.
		\param type ��۾��� �ߴ��������� type�Դϴ�.
		\param loadedDataGuid �Ϸ��� �۾� data�� Guid�Դϴ�.

		\~english
		Receiving event when writting process to DBMS on DB cache server.
		\param type Type for what process has done.
		\param loadedDataGuid Guid of finished work data

		\~chinese
		��??DB cache server ?��?DBM???����?����?��event��
		\param type ��?����?������type��
		\param loadedDataGuid ?��������data��Guid��

		\~japanese
		DB cache server��DBMS����?����Φ�窱����������Ȫ���󷪹�뫤�٫�ȪǪ���
		\param type �ɪ�������򪷪��Ϊ���?����type�Ǫ���
		\param loadedDataGuid ��������������?����Guid�Ǫ���

		\~
		*/
		virtual void OnDbmsWriteDone(DbmsWritePropNodePendType type, Guid loadedDataGuid) = 0;

		/**
		\~korean
		- �����ε� ��û�� ���� �����Դϴ�.
		- ��û �� �Է��� �˻� ���ǿ� ���� args.m_items�� ���� ������ ������ Ʈ���� ���� ���� �ֽ��ϴ�.
		- args.m_items���� �����ε忡 ������ ����� ������ ����� �������� �� �ִµ� CItem.m_reason���� ErrorType_Ok�̸� ������ ����Դϴ�.
		- ������ ��� CItem��ü�� ������� �� m_loadedData, m_data, m_sessionGuid, m_rootUUID, m_UUID, m_message�� ���� ������ ��ϵ˴ϴ�.
		- ������ ��� CItem��ü�� ������� �� m_reason, m_comment, m_UUID, m_hResult, m_message�� ���� ������ ��ϵ˴ϴ�.
		- m_message�� �ش� �����Ͱ� �̹� �����Ǿ��ִ� ��� ���� �����ڰ� ������ �̾� �Ǵ� �źθ� �ϸ鼭 �ѱ� �޽����� ��ϵ˴ϴ�.
		- args.m_tag�� ��û �� ����ڰ� ���Ƿ� �Է��ߴ� tag���� �״�� ���ƿ��Ƿ� �̸� ���� � ��û�� ���� �������� �� �� �ֽ��ϴ�.

		\~english
		- This is the response for the exclusive load request. 
		- When requesting, you may receive multiple data trees through args.m_items depending on the input search conditions. 
		- args.m_items may have successful results and failed results mixed for exclusive load and if the value of CItem.m_reason is ErrorType_Ok, then this is a successful result. 
		- If successful, the related information is recorded in m_loadedData, m_data, m_sessionGuid, m_rootUUID, m_UUID and m_message among the member variables of the CItem object.
		- If failed, the related information is recorded in m_reason, m_comment, m_UUID, m_hResult and m_message among the member variable of the CItem object. 
		- When the data is already excluded, the message transmitted by the current excluder when it transfers or rejects the exclusivity is recorded in m_message.
		- When requesting to args.m_tag, the tag value input randomly by the user is returned as the original value so you can see this is a response to which request. 

		\~chinese
		- ????ʥ??ϴ��??��
		- ����?ϴ??�������?�죬���?args.m_items?����??��?��
		- args.m_items��ʦ������������?������?��?��������CItem.m_reason��?? ErrorType_Ok������������
		- ��������CItem?������??������m_loadedData, m_data, m_sessionGuid, m_rootUUID, m_UUID, m_message??��?���ӡ�
		- ������?��CItem?������??������m_reason, m_comment, m_UUID, m_hResult, m_message??��?���ӡ�
		- ?����??�??����??????�������???��m_message��
		- ��args.m_tag?ϴ?����?����?����tag??�?���ޣ���???ʦ��Գ��??��??ϴ��??��

		\~japanese
		- ?￫�?������?����?�ͪǪ���
		- ���������������?��?��˪�ê�args.m_items���ת���?�Ϋ�?���ī�?�������몳�Ȫ�Ǫ��ު���
		- args.m_items�˪�?￫�?�ɪ�������̿������������̿�����誸�êƪ��몳�Ȫ�����ު�����CItem.m_reason����ErrorType_Ok�Ǫ����������̿���Ǫ���
		- ���������ꡢCItem���֫������ȪΫ���???�Ϊ�����m_loadedData, m_data, m_sessionGuid, m_rootUUID, m_UUID, m_message��?֧���ê���?����ު���
		- �����������ꡢCItem���֫������ȪΫ���???�Ϊ�����m_reason, m_comment, m_UUID, m_hResult, m_message��?֧���ê���?����ު���
		- m_message����?��?����?��?￪˪ʪêƪ������ꡢ?���?���?�?���?�ު��������򪷪ʪ���Ԥ������ë�?������?����ު���
		- args.m_tag��������˫�?��?���������������tag�������Ϊު�?�êƪ��ު��Ϊǡ�������ת����ɪ������?����?�ͪʪΪ���ު���


		\~
		*/
		virtual void OnExclusiveLoadDataComplete(CCallbackArgs& args) = 0;

		/**
		\~korean
		�ٸ� DB cache client2�� <a target="_blank" href="http://guide.nettention.com/cpp_ko#exclusive_load" >������ �ҷ�����</a> �� �õ��ϴ� �ٶ��� �̹� �ε��ߴ� �������� ���� ���� ������ �ҽ��� ������ �����Ҽ� �ִ� �̺�Ʈ �Դϴ�.
		- args.m_loadResults[index].m_loadedData �� ���� ä�����ϴ�.
		- DbCacheClient �� DenyUnloadData �� �� �ϰų�, UnloadDataBySessionGuid �� ���Ͽ� �������� �Ѱ� �ٰ����� �����Ҽ� �ֽ��ϴ�.
		\param args IDbCacheClientDelegate2�� �̺�Ʈ argument ����ü�Դϴ�. ���� \ref CCallbackArgs

		\~english
		This is event that decide losing exclusive loading or not because other DB cahce client2 tried <a target="_blank" href="http://guide.nettention.com/cpp_en#exclusive_load" >Exclusive Load</a>
		- Value will write to args.m_loadResults[index].m_loadedData
		- It can choose passing exclusive rights with calling DenyUnloadData or UnloadDataBySessionGuid in DbCacheClient
		\param args Event argument object of IDbCacheClientDelegate2

		\~chinese
		��?����DB cache client2?? <a target="_blank" href="http://guide.nettention.com/cpp_zh#exclusive_load" >?�������</a>%��?������?���?ʥ?��?��?�����?����event��
		-?��?�� args.m_loadResults[index].m_loadedData��
		- ʦ�? DbCacheClient��DenyUnloadData%���? UnloadDataBySessionGuid%��?����������?�?��
		\param args IDbCacheClientDelegate2��event��argument?��?��?��\ref CcallbackArgs%��

		\~japanese
		���DB cache client2��\ref exclusive_load���˪������ᡢ?�˫�?�ǫ��󫰪�����?����?￫�������?�ڪ�������몫�ɪ�����̽�ҪǪ��뫤�٫�ȪǪ���
		- args.m_loadResults[index].m_loadedData������?������ު���
		- DbCacheClient��DenyUnloadData�������󪹪���UnloadDataBySessionGuid�������󪷪�?�?��Ԥ�����ɪ�����̽�Ҫ��몳�Ȫ��Ǫ��ު���
		\param args IDbCacheClientDelegate2�Ϋ��٫��argumentϰ��?�Ǫ���?�� \ref CCallbackArgs

		*/
		virtual void OnDataUnloadRequested(CCallbackArgs& args) = 0;

		/**
		\~korean
		Ư�� �����Ͱ� �����κ��� ������ Unload �Ǿ��� �� �߻��ϴ� �̺�Ʈ�Դϴ�.
		���� �����ε� ���� �����Ϳ� �Ǵٸ� ������û�� ������ ��� OnDataUnloadRequested()�� �ݹ������,
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_isolate_overview" >DB cache�� �ٷ�� �����͸� DB�� ���� �＼���ϱ�</a> �� �Ϸ��� �ϴ� ��쿡�� �Ұ����ϰ� �� �Լ��� �ݹ�˴ϴ�.

		\~english
		This is the event when particular data is forcibly unloaded from the server.
		If another exclusivity request is received by the data exclusively loaded currently, OnDataUnloadRequested() is called back, but
		If \ref dbc2_isolate_overview is attempted, inevitably this function is called back. 

		\~chinese
		?����?��?��?��˭�߾???�������졣
		????�����??����?��?��������???ϴ����?��?OnDataUnloadRequested()�������?��\ref dbc2_isolate_overview �� ?��ʦ�������?���?��

		\~japanese
		���ҫ�?������?��?����?��Unload���쪿����?�檹�뫤�٫�ȪǪ���
		���?￫�?����Ǫ����?���˪ު��ު�?���몬�������ꡢ OnDataUnloadRequested()����?��Ыë�����ު�����
		\ref dbc2_isolate_overview �򪷪誦�Ȫ�������˪Ϫ����𪺪˪���??����?��Ыë�����ު���

		*/
		virtual void OnDataForceUnloaded(CCallbackArgs& args) = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_isolate_overview" >DB cache�� �ٷ�� �����͸� DB�� ���� �＼���ϱ�</a> ����Դϴ�.
		Proud.CDbCacheClient2.RequestIsolateData() ���� ������ �˸��ϴ�.
		args���� m_rootUUID, m_data, m_sessionGuid�� ä�����ϴ�.

		\~english
		<a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_isolate_overview" >DB directly has access to data that DB cache deals with </a> function.
		Proud.CDbCacheClient2.RequestIsolateData() inform you of execution success.
		m_rootUUID, m_data and m_sessionGuid are included in args.

		\~chinese
		<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_isolate_overview" >DB����??DB cache������?��</a> ������
		ͱ�Proud.CDbCacheClient2.RequestIsolateData() ?������
		�args��??�� m_rootUUID, m_data, m_sessionGuid��

		\~japanese
		<a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_isolate_overview" >DB cache���ê��?����DB�����ȫ�������</a>Ѧ���Ǫ���
		Proud.CDbCacheClient2.RequestIsolateData()?����������骻�ު���
		Args�˪�m_rootUUID, m_data, m_sessionGuid���ت���ު���
		*/
		virtual void OnIsolateDataSuccess(CCallbackArgs& args) = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_isolate_overview" >DB cache�� �ٷ�� �����͸� DB�� ���� �＼���ϱ�</a> ����Դϴ�.
		Proud.CDbCacheClient2.RequestIsolateData() ���� ���и� �˸��ϴ�.
		args���� m_rootUUID, m_data, m_sessionGuid�� ä�����ϴ�.

		\~english
		<a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_isolate_overview" >DB directly has access to data that DB cache deals with </a> function.
		Proud.CDbCacheClient2.RequestIsolateData() inform you of execution failure.
		m_rootUUID, m_data and m_sessionGuid are included in args.

		\~chinese
		<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_isolate_overview" >DB����??DB cache������?��</a> ������
		ͱ�Proud.CDbCacheClient2.RequestIsolateData() ?����?��
		�args??�� m_rootUUID, m_data, m_sessionGuid��

		\~japanese
		<a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_isolate_overview" >DB cache���ê��?����DB�����ȫ�������</a>Ѧ���Ǫ���
		Proud.CDbCacheClient2.RequestIsolateData() ?�����������骻�ު���
		Args�˪�m_rootUUID, m_data, m_sessionGuid���ت���ު���
		*/
		virtual void OnIsolateDataFailed(CCallbackArgs& args) = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_isolate_overview" >DB cache�� �ٷ�� �����͸� DB�� ���� �＼���ϱ�</a> ����Դϴ�.
		Proud.CDbCacheClient2.RequestDeisolateData() ���� ������ �˸��ϴ�.
		args���� m_rootUUID, m_data, m_sessionGuid�� ä�����ϴ�.

		\~english
		<a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_isolate_overview" >DB directly has access to data that DB cache deals with </a> function.
		Proud.CDbCacheClient2.RequestDeisolateData() inform you of execution success.
		m_rootUUID, m_data and m_sessionGuid are included in args.

		\~chinese
		<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_isolate_overview" >DB����??DB cache������?��</a> ������
		ͱ�Proud.CDbCacheClient2.RequestDeisolateData() ?������
		�args��??�� m_rootUUID, m_data, m_sessionGuid��

		\~japanese
		<a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_isolate_overview" >DB cache���ê��?����DB�����ȫ�������</a>Ѧ���Ǫ���
		Proud.CDbCacheClient2.RequestDeisolateData() ?����������骻�ު���
		Args�˪� m_rootUUID, m_data, m_sessionGuid���ت���ު���
		*/
		virtual void OnDeisolateDataSuccess(CCallbackArgs& args) = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_isolate_overview" >DB cache�� �ٷ�� �����͸� DB�� ���� �＼���ϱ�</a> ����Դϴ�.
		Proud.CDbCacheClient2.RequestDeisolateData() ���� ���и� �˸��ϴ�.
		args���� m_rootUUID, m_data, m_sessionGuid�� ä�����ϴ�.

		\~english
		<a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_isolate_overview" >DB directly has access to data that DB cache deals with </a> function.
		Proud.CDbCacheClient2.RequestDeisolateData() inform you of execution failure.
		m_rootUUID, m_data and m_sessionGuid are included in args.

		\~chinese
		<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_isolate_overview" >DB����??DB cache������?��</a> ������
		ͱ�Proud.CDbCacheClient2.RequestDeisolateData() ?����?��
		�args��??�� m_rootUUID, m_data, m_sessionGuid��

		\~japanese
		<a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_isolate_overview" >DB cache���ê��?����DB�����ȫ�������</a>Ѧ���Ǫ���
		Proud.CDbCacheClient2.RequestDeisolateData()?�����������骻�ު���.
		Args�˪� m_rootUUID, m_data, m_sessionGuid���ت���ު���
		*/
		virtual void OnDeisolateDataFailed(CCallbackArgs& args) = 0;

		/**
		\~korean
		CDbCacheClient2.RequestAddData, CDbCacheClient2.BlockedAddData ���� ���������� �����ϴ� �̺�Ʈ�Դϴ�.
		- args.m_loadResults[index].m_reason,args.m_loadResults[index].m_comment�� ���� ä�����ϴ�.
		\param args IDbCacheClientDelegate2�� �̺�Ʈ argument ����ü�Դϴ�. ���� \ref CCallbackArgs

		\~english
		This event will arrive when it failed in CDbCacheClient2.RequestAddData or CDbCacheClient2.BlockedAddData
		- Value will write to args.m_loadResults[index].m_reason, args.m_loadResults[index].m_comment
		\param args Event argument object of IDbCacheClientDelegate2

		\~chinese
		� CDbCacheClient2.RequestAddData, CDbCacheClient2.BlockedAddData%��??��?��Event��
		- ?��?�� args.m_loadResults[index].m_reason,args.m_loadResults[index].m_comment��
		\param args IDbCacheClientDelegate2%������argument?��?��?��\ref CCallbackArgs%��

		\~japanese
		CDbCacheClient2.RequestAddData, CDbCacheClient2.BlockedAddData����������������󷪹�뫤�٫�ȪǪ���
		- args.m_loadResults[index].m_reason,args.m_loadResults[index].m_comment������?������ު���
		\param args IDbCacheClientDelegate2�Ϋ��٫��argument��ϰ��?�Ǫ���?�� \ref CCallbackArgs

		\~
		*/
		virtual void OnAddDataFailed(CCallbackArgs& args) = 0;

		/**
		\~korean
		CDbCacheClient2.RequestAddData, CDbCacheClient2.BlockedAddData ���� ���������� �����ϴ� �̺�Ʈ�Դϴ�.
		- args.m_loadResults[index].m_loadedData,args.m_loadResults[index].m_data�� ���� ä�����ϴ�.
		\param args IDbCacheClientDelegate2�� �̺�Ʈ argument ����ü�Դϴ�. ���� \ref CCallbackArgs

		\~english
		This event will arrive when it succeed in CDbCacheClient2.RequestAddData or CDbCacheClient2.BlockedAddData
		- Value will write to args.m_loadResults[index].m_reason,args.m_loadResults[index].m_comment
		\param args Event argument object of IDbCacheClientDelegate2

		\~chinese
		� CDbCacheClient2.RequestAddData, CDbCacheClient2.BlockedAddData%����?��?��event��
		- �� args.m_loadResults[index].m_loadedData,args.m_loadResults[index].m_data ?��?��
		\param args IDbCacheClientDelegate2��event��argument?��?��?��\ref CCallbackArgs%��

		\~japanese
		CDbCacheClient2.RequestAddData, CDbCacheClient2.BlockedAddData ��������������󷪹�뫤�٫�ȪǪ���
		- args.m_loadResults[index].m_loadedData,args.m_loadResults[index].m_data������?������ު���
		\param args IDbCacheClientDelegate2�Ϋ��٫��argumentϰ��?�Ǫ���?�� \ref CCallbackArgs

		*/
		virtual void OnAddDataSuccess(CCallbackArgs& args) = 0;

		/**
		\~korean
		\ref OnAddDataFailed ����.
		- args.m_loadResults[index].m_reason,args.m_loadResults[index].m_comment�� ���� ä�����ϴ�.
		\param args IDbCacheClientDelegate2�� �̺�Ʈ argument ����ü�Դϴ�. ���� \ref CCallbackArgs

		\~english
		Refer to OnAddDataFailed
		- Value will write to args.m_loadResults[index].m_reason,args.m_loadResults[index].m_comment
		\param args Event argument object of IDbCacheClientDelegate2

		\~chinese
		?��\ref OnAddDataFailed%��
		- ?��?�� args.m_loadResults[index].m_reason,args.m_loadResults[index].m_comment��
		\param args IDbCacheClientDelegate2��event��argument?��?��?��\ref CCallbackArgs%��

		\~japanese
		\ref OnAddDataFailed ?��
		- args.m_loadResults[index].m_reason,args.m_loadResults[index].m_comment������?������ު���
		\param args IDbCacheClientDelegate2�Ϋ��٫��argumentϰ��?�Ǫ���?�� \ref CCallbackArgs

		\~
		*/
		virtual void OnUpdateDataFailed(CCallbackArgs& args) = 0;

		/**
		\~korean
		\ref OnAddDataSuccess ����.
		-  args.m_loadResults[index].m_loadedData,args.m_loadResults[index].m_data�� ���� ä�����ϴ�.
		\param args IDbCacheClientDelegate2�� �̺�Ʈ argument ����ü�Դϴ�. ���� \ref CCallbackArgs

		\~english
		Refer to OnAddDataSuccess
		- Value will write to args.m_loadResults[index].m_loadedData,args.m_loadResults[index].m_data
		\param args Event argument object of IDbCacheClientDelegate2

		\~chinese
		?�� \ref OnAddDataSuccess%��
		-?��?�� args.m_loadResults[index].m_loadedData,args.m_loadResults[index].m_data��
		\param args IDbCacheClientDelegate2%��event��argument?��?��?��\ref CCallbackArgs%��

		\~japanese
		\ref OnAddDataSuccess ?��
		-  args.m_loadResults[index].m_loadedData,args.m_loadResults[index].m_data������?������ު���
		\param args IDbCacheClientDelegate2�Ϋ��٫��argumentϰ��?�Ǫ���?�� \ref CCallbackArgs

		\~
		*/
		virtual void OnUpdateDataSuccess(CCallbackArgs& args) = 0;

		/**
		\~korean
		\ref OnAddDataFailed ����.
		-  args.m_loadResults[index].m_reason,args.m_loadResults[index].m_comment�� ���� ä�����ϴ�.
		\param args IDbCacheClientDelegate2�� �̺�Ʈ argument ����ü�Դϴ�. ���� \ref CCallbackArgs

		\~english
		Refer to OnAddDataFailed
		- Value will write to args.m_loadResults[index].m_reason,args.m_loadResults[index].m_comment
		\param args Event argument object of IDbCacheClientDelegate2

		\~chinese
		?�� \ref OnAddDataFailed%��
		- ?��?�� args.m_loadResults[index].m_reason,args.m_loadResults[index].m_comment��
		\param args IDbCacheClientDelegate2%��event��argument?��?��?��\ref CCallbackArgs%��

		\~japanese
		\ref OnAddDataFailed ?��
		-  args.m_loadResults[index].m_reason,args.m_loadResults[index].m_comment������?������ު���
		\param args IDbCacheClientDelegate2�Ϋ��٫��argumentϰ��?�Ǫ���?�� \ref CCallbackArgs

		\~
		*/
		virtual void OnRemoveDataFailed(CCallbackArgs& args) = 0;

		/**
		\~korean
		\ref OnAddDataFailed ����.
		-  args.m_loadResults[index].m_reason,args.m_loadResults[index].m_comment�� ���� ä�����ϴ�.
		\param args IDbCacheClientDelegate2�� �̺�Ʈ argument ����ü�Դϴ�. ���� \ref CCallbackArgs

		\~english
		Refer to OnAddDataFailed
		- Value will write to args.m_loadResults[index].m_reason,args.m_loadResults[index].m_comment
		\param args Event argument object of IDbCacheClientDelegate2

		\~chinese
		?�� \ref OnAddDataFailed%��
		-?��?�� args.m_loadResults[index].m_reason,args.m_loadResults[index].m_comment��
		\param args IDbCacheClientDelegate2%��event��argument?��?��?��\ref CCallbackArgs%��

		\~japanese
		\ref OnAddDataFailed ?��
		-  args.m_loadResults[index].m_reason,args.m_loadResults[index].m_comment������?������ު���
		\param args IDbCacheClientDelegate2�Ϋ��٫��argumentϰ��?�Ǫ���?�� \ref CCallbackArgs

		\~
		*/
		virtual void OnRemoveDataSuccess(CCallbackArgs& args) = 0;

		/**
		\~korean
		- ���� ��ȸ ��û�� ���� �����Դϴ�.
		- ��û �� �Է��� �˻� ���ǿ� ���� args.m_items�� ���� ������ ������ Ʈ���� ���� ���� �ֽ��ϴ�.
		- args.m_items���� ��ȸ�� ������ ����� ������ ����� �������� �� �ִµ� CItem.m_reason���� ErrorType_Ok�̸� ������ ����Դϴ�.
		- ������ ��� CItem��ü�� ������� �� m_loadedData, m_data, m_sessionGuid, m_rootUUID, m_UUID�� ���� ������ ��ϵ˴ϴ�.
		- ������ ��� CItem��ü�� ������� �� m_reason, m_comment, m_UUID, m_hResult�� ���� ������ ��ϵ˴ϴ�.
		- args.m_tag�� ��û �� ����ڰ� ���Ƿ� �Է��ߴ� tag���� �״�� ���ƿ��Ƿ� �̸� ���� � ��û�� ���� �������� �� �� �ֽ��ϴ�.

		\~english
		- This is the request for the nonexclusive search request. 
		- When requesting, you may receive multiple data trees through args.m_items depending on the input search conditions
		- args.m_items may have successful results and failed results mixed for search success and if the value of CItem.m_reason is ErrorType_Ok, then this is a successful result.
		- If successful, the related information is recorded in m_loadedData, m_data, m_sessionGuid, m_rootUUID and m_UUID among the member variables of the CItem object.
		- If failed, the related information is recorded in m_reason, m_comment, m_UUID and m_hResult among the member variable of the CItem object.
		- When requesting to args.m_tag, the tag value input randomly by the user is returned as the original value so you can see this is a response to which request.


		\~chinese
		- ??ު?????ϴ��??��
		- ����?ϴ??�������?�죬���?args.m_items?����??��?��
		- args.m_items��ʦ������������?������?��?��������CItem.m_reason��?? ErrorType_Ok������������
		- ��������CItem?������??������m_loadedData, m_data, m_sessionGuid, m_rootUUID, m_UUID, m_message??��?���ӡ�
		- ������?��CItem?������??������m_reason, m_comment, m_UUID, m_hResult, m_message??��?���ӡ�
		- ��args.m_tag?ϴ?����?����?����tag??�?���ޣ���???ʦ��Գ��??��??ϴ��??��

		\~japanese
		- ު?���?����?����?�ͪǪ���
		- ���������������?��?��˪�ê�args.m_items���ת���?�Ϋ�?���ī�?�������몳�Ȫ�Ǫ��ު���
		- args.m_items�˪���?��������̿������������̿�����誸���ު�����CItem.m_reason����ErrorType_Ok�Ǫ����������̿���Ǫ���
		- ���������ꡢCItem���֫������ȪΫ���???�Ϊ�����m_loadedData, m_data, m_sessionGuid, m_rootUUID, m_UUID��?֧���ê���?����ު���
		- �����������ꡢCItem���֫������ȪΫ���???�Ϊ�����m_reason, m_comment, m_UUID, m_hResult��?֧���ê���?����ު���	
		- args.m_tag��������˫�?��?���������������tag�������Ϊު�?�êƪ���Ϊǡ�������ת��ɪ������?����?�ͪʪΪ����ު���

		\~
		*/
		virtual void OnNonExclusiveSnapshotDataComplete(CCallbackArgs& args) { args; }

		/**
		\~korean
		������ ���ٿ� ���� �ݹ�. <a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >������ ������ �����ϱ�</a> ����.
		- ���нÿ�  args.m_loadResults[index].m_reason, args.m_loadResults[index].m_comment�� ���� ä�����ϴ�.
		- �����ÿ�  args.m_loadResults[index].m_rootUUID, args.m_loadResults[index].m_data�� ���� ä�����ϴ�.
		\param args IDbCacheClientDelegate2 �� �̺�Ʈ argument ����ü�Դϴ�. ���� \ref CCallbackArgs

		\~english
		A callback to non monopolistic approach. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a>.
		- Value will write in to args.m_loadResults[index].m_reason, args.m_loadResults[index].m_comment when it succeed.
		- Value will write in to args.m_loadResults[index].m_rootUUID, args.m_loadResults[index].m_data when it failed.
		\param args Event argument object of IDbCacheClientDelegate2.

		\~chinese
		?ު?�����������?��??��<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??������?��</a>%��
		- ��???��?��  args.m_loadResults[index].m_reason,args.m_loadResults[index].m_comment��
		- ����??��?��  args.m_loadResults[index].m_rootUUID,args.m_loadResults[index].m_data��
		\param args IDbCacheClientDelegate2%��event��argument?��?��?��\ref CCallbackArgs%��

		\~japanese
		ު?������Ϊ�?���뫳?��Ыë� <a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> ?��
		- �������˪�  args.m_loadResults[index].m_reason, args.m_loadResults[index].m_comment�������ت���ު���
		- �������˪�  args.m_loadResults[index].m_rootUUID, args.m_loadResults[index].m_removeUUID�������ت���ު���
		\param args IDbCacheClientDelegate2 �Ϋ��٫�� argument ϰ��?�Ǫ��� ?�� \ref CCallbackArgs

		\~
		*/
		virtual void OnNonExclusiveAddDataAck(CCallbackArgs& args) { args; }

		/**
		\~korean
		������ ���ٿ� ���� �ݹ�. <a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >������ ������ �����ϱ�</a> ����.
		- ���нÿ�  args.m_loadResults[index].m_reason, args.m_loadResults[index].m_comment�� ���� ä�����ϴ�.
		- �����ÿ�  args.m_loadResults[index].m_rootUUID, args.m_loadResults[index].m_removeUUID�� ���� ä�����ϴ�.
		\param args IDbCacheClientDelegate2 �� �̺�Ʈ argument ����ü�Դϴ�. ���� \ref CCallbackArgs

		\~english
		A callback to non monopolistic approach. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a>.
		- Value will write in to args.m_loadResults[index].m_reason, args.m_loadResults[index].m_comment when it succeed.
		- Value will write in to args.m_loadResults[index].m_rootUUID, args.m_loadResults[index].m_data when it failed.
		\param args Event argument object of IDbCacheClientDelegate2.

		\~chinese
		?ު?�����������?��??��<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??������?��</a>%��
		- ��???��?��  args.m_loadResults[index].m_reason, args.m_loadResults[index].m_comment��
		- ����??��?��  args.m_loadResults[index].m_rootUUID, args.m_loadResults[index].m_removeUUID��
		\param args IDbCacheClientDelegate2��event��argument?��?��?��\ref CCallbackArgs%��

		\~japanese
		ު?������Ϊ�?���뫳?��Ыë�<a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a>?��
		- �������˪�  args.m_loadResults[index].m_reason, args.m_loadResults[index].m_comment�������ت���ު���
		- �������˪�  args.m_loadResults[index].m_rootUUID, args.m_loadResults[index].m_removeUUID�������ت���ު���
		\param args IDbCacheClientDelegate2 �Ϋ��٫�� argument ϰ��?�Ǫ��� ?�� \ref CCallbackArgs


		\~
		*/
		virtual void OnNonExclusiveRemoveDataAck(CCallbackArgs& args) { args; }


		/**
		\~korean
		������ ���ٿ� ���� �ݹ�. <a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >������ ������ �����ϱ�</a> ����.
		-  args.m_loadResults[index].m_rootUUID, args.m_loadResults[index].m_data�� ���� ä�����ϴ�.
		\param args IDbCacheClientDelegate2 �� �̺�Ʈ argument ����ü�Դϴ�. ���� \ref CCallbackArgs

		\~english
		A callback to non monopolistic approach. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a>.
		- Value will write in to args.m_loadResults[index].m_rootUUID, args.m_loadResults[index].m_data.
		\param args Event argument object of IDbCacheClientDelegate2.

		\~chinese
		?ު?�����������?��??��<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??������?��</a>%��
		- ?��?��  args.m_loadResults[index].m_rootUUID, args.m_loadResults[index].m_data��
		\param args IDbCacheClientDelegate2%��event��argument?��?��?��\ref CCallbackArgs%��

		\~japanese
		ު?������Ϊ�?���뫳?��Ыë� <a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> ?��
		-  args.m_loadResults[index].m_rootUUID, args.m_loadResults[index].m_data�������ت���ު���
		\param args IDbCacheClientDelegate2 �Ϋ��٫��argument ϰ��?�Ǫ��� ?�� \ref CCallbackArgs

		\~
		*/
		virtual void OnNonExclusiveModifyValueSuccess(CCallbackArgs& args) { args; }

		/**
		\~korean
		������ ���ٿ� ���� �ݹ�. <a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >������ ������ �����ϱ�</a> ����.
		-  args.m_loadResults[index].m_reason, args.m_loadResults[index].m_comment�� ���� ä�����ϴ�.
		\param args IDbCacheClientDelegate2 �� �̺�Ʈ argument ����ü�Դϴ�. ���� \ref CCallbackArgs

		\~english
		A callback to non monopolistic approach. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a>.
		- Value will write in to args.m_loadResults[index].m_reason, args.m_loadResults[index].m_comment.
		\param args Event argument object of IDbCacheClientDelegate2.

		\~chinese
		?ު?�����������?��??��<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??������?��</a>%��
		- ?��?��  args.m_loadResults[index].m_reason, args.m_loadResults[index].m_comment��
		\param args IDbCacheClientDelegate2%������argument?��?��?��\ref CCallbackArgs%��

		\~japanese
		ު?������Ϊ�?���뫳?��Ыë� <a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> ?��
		-  args.m_loadResults[index].m_reason, args.m_loadResults[index].m_comment�������ت���ު���
		\param args IDbCacheClientDelegate2 �Ϋ��٫��argument ϰ��?�Ǫ��� ?�� \ref CCallbackArgs

		\~
		*/
		virtual void OnNonExclusiveModifyValueFailed(CCallbackArgs& args) { args; }

		/**
		\~korean
		������ ���ٿ� ���� �ݹ�. <a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >������ ������ �����ϱ�</a> ����.
		-  args.m_loadResults[index].m_rootUUID, args.m_loadResults[index].m_data�� ���� ä�����ϴ�.
		\param args IDbCacheClientDelegate2 �� �̺�Ʈ argument ����ü�Դϴ�. ���� \ref CCallbackArgs

		\~english
		A callback to non monopolistic approach. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a>.
		- Value will write in to args.m_loadResults[index].m_rootUUID, args.m_loadResults[index].m_data.
		\param args Event argument object of IDbCacheClientDelegate2.

		\~chinese
		?ު?�����������?��??��<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??������?��</a>%��
		- ?��?��  args.m_loadResults[index].m_rootUUID, args.m_loadResults[index].m_data��
		\param args IDbCacheClientDelegate2%������argument?��?��?��\ref CCallbackArgs%��

		\~japanese
		ު?������Ϊ�?���뫳?��Ыë� <a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> ?��
		-  args.m_loadResults[index].m_rootUUID, args.m_loadResults[index].m_data�������ت���ު���
		\param args IDbCacheClientDelegate2 �Ϋ��٫��argument ϰ��?�Ǫ��� ?�� \ref CCallbackArgs

		\~
		*/
		virtual void OnNonExclusiveSetValueIfSuccess(CCallbackArgs& args) { args; }

		/**
		\~korean
		������ ���ٿ� ���� �ݹ�. <a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >������ ������ �����ϱ�</a> ����.
		-  args.m_loadResults[index].m_reason, args.m_loadResults[index].m_comment�� ���� ä�����ϴ�.
		\param args IDbCacheClientDelegate2 �� �̺�Ʈ argument ����ü�Դϴ�. ���� \ref CCallbackArgs

		\~english
		A callback to non monopolistic approach. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a>.
		- Value will write in to args.m_loadResults[index].m_reason, args.m_loadResults[index].m_comment.
		\param args Event argument object of IDbCacheClientDelegate2.

		\~chinese
		?ު?�����������?��??��<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??������?��</a>%��
		- ?��?��  args.m_loadResults[index].m_reason, args.m_loadResults[index].m_comment��
		\param args IDbCacheClientDelegate2%������argument?��?��?��\ref CCallbackArgs%��

		\~japanese
		ު?������Ϊ�?���뫳?��Ыë� <a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> ?��
		-  args.m_loadResults[index].m_reason, args.m_loadResults[index].m_comment�������ت���ު���
		\param args IDbCacheClientDelegate2 �Ϋ��٫��argument ϰ��?�Ǫ��� ?�� \ref CCallbackArgs

		\~
		*/
		virtual void OnNonExclusiveSetValueIfFailed(CCallbackArgs& args) { args; }

		/**
		\~korean
		������ ���ٿ� ���� �ݹ�. <a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >������ ������ �����ϱ�</a> ����.
		- args.m_loadResults[index].m_loadedData, args.m_loadResults[index].m_data, args.m_loadResults[index].m_message�� ���� ä�����ϴ�.
		\param args IDbCacheClientDelegate2 �� �̺�Ʈ argument ����ü�Դϴ�. ���� \ref CCallbackArgs

		\~english
		A callback to non monopolistic approach. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a>.
		- Value will write in to args.m_loadResults[index].m_loadedData and args.m_loadResults[index].m_data,  args.m_loadResults[index].m_message.
		\param args Event argument object of IDbCacheClientDelegate2.

		\~chinese
		?ު?�����������?��??��<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??������?��</a>%��
		- ?��?�� args.m_loadResults[index].m_loadedData, args.m_loadResults[index].m_data, args.m_loadResults[index].m_message��
		\param args IDbCacheClientDelegate2������argument?��?��?��\ref CCallbackArgs%��

		\~japanese
		ު?������Ϊ�?���뫳?��Ыë� <a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> ?��
		- args.m_loadResults[index].m_loadedData, args.m_loadResults[index].m_data, args.m_loadResults[index].m_message�������ت���ު���
		\param args IDbCacheClientDelegate2 �Ϋ��٫��argument ϰ��?�Ǫ��� ?�� \ref CCallbackArgs

		\~
		*/
		virtual void OnSomeoneAddData(CCallbackArgs& args) { args; }

		/**
		\~korean
		������ ���ٿ� ���� �ݹ�. <a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >������ ������ �����ϱ�</a> ����.
		- args.m_loadResults[index].m_loadedData, args.m_loadResults[index].m_data, args.m_loadResults[index].m_message�� ���� ä�����ϴ�.
		\param args IDbCacheClientDelegate2 �� �̺�Ʈ argument ����ü�Դϴ�. ���� \ref CCallbackArgs

		\~english
		A callback to non monopolistic approach. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a>.
		- Value will write in to args.m_loadResults[index].m_loadedData and args.m_loadResults[index].m_data,  args.m_loadResults[index].m_message.
		\param args Event argument object of IDbCacheClientDelegate2.

		\~chinese
		?ު?�����������?��??��<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??������?��</a>%��
		- ?��?�� args.m_loadResults[index].m_loadedData, args.m_loadResults[index].m_data,  args.m_loadResults[index].m_message��
		\param args IDbCacheClientDelegate2%��event��argument?��?��?��\ref CCallbackArgs%��

		\~japanese
		ު?������Ϊ�?���뫳?��Ыë� <a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> ?��
		- args.m_loadResults[index].m_loadedData, args.m_loadResults[index].m_data,  args.m_loadResults[index].m_message�������ت���ު���
		\param args IDbCacheClientDelegate2 �Ϋ��٫��argument ϰ��?�Ǫ��� ?�� \ref CCallbackArgs

		\~
		*/
		virtual void OnSomeoneRemoveData(CCallbackArgs& args) { args; }

		/**
		\~korean
		������ ���ٿ� ���� �ݹ�. <a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >������ ������ �����ϱ�</a> ����.
		- args.m_loadResults[index].m_loadedData, args.m_loadResults[index].m_data,  args.m_loadResults[index].m_message�� ���� ä�����ϴ�.
		\param args IDbCacheClientDelegate2 �� �̺�Ʈ argument ����ü�Դϴ�. ���� \ref CCallbackArgs

		\~english
		A callback to non monopolistic approach. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a>.
		- Value will write in to args.m_loadResults[index].m_loadedData and args.m_loadResults[index].m_data,  args.m_loadResults[index].m_message.
		\param args Event argument object of IDbCacheClientDelegate2.

		\~chinese
		?ު?�����������?��??��<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??������?��</a>%��
		- ?��?�� args.m_loadResults[index].m_loadedData, args.m_loadResults[index].m_data,  args.m_loadResults[index].m_message��
		\param args IDbCacheClientDelegate2%��event��argument?��?��?��\ref CCallbackArgs%��

		\~japanese
		ު?������Ϊ�?���뫳?��Ыë� <a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> ?��
		- args.m_loadResults[index].m_loadedData, args.m_loadResults[index].m_data,  args.m_loadResults[index].m_message�������ت���ު���
		\param args IDbCacheClientDelegate2 �Ϋ��٫��argument ϰ��?�Ǫ��� ?�� \ref CCallbackArgs

		\~
		*/
		virtual void OnSomeoneModifyValue(CCallbackArgs& args) { args; }

		/**
		\~korean
		������ ���ٿ� ���� �ݹ�. <a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >������ ������ �����ϱ�</a> ����.
		- args.m_loadResults[index].m_loadedData, args.m_loadResults[index].m_data,  args.m_loadResults[index].m_message�� ���� ä�����ϴ�.
		\param args IDbCacheClientDelegate2 �� �̺�Ʈ argument ����ü�Դϴ�. ���� \ref CCallbackArgs

		\~english
		A callback to non monopolistic approach. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a>.
		- Value will write in to args.m_loadResults[index].m_loadedData and args.m_loadResults[index].m_data,  args.m_loadResults[index].m_message.
		\param args Event argument object of IDbCacheClientDelegate2.

		\~chinese
		?ު?�����������?��??��<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??������?��</a>%��
		- ?��?�� args.m_loadResults[index].m_loadedData, args.m_loadResults[index].m_data, args.m_loadResults[index].m_message��
		\param args IDbCacheClientDelegate2%��event��argument?��?��?��\ref CCallbackArgs%��

		\~japanese
		ު?������Ϊ�?���뫳?��Ыë� <a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> ?��
		- args.m_loadResults[index].m_loadedData, args.m_loadResults[index].m_data, args.m_loadResults[index].m_message�������ت���ު���
		\param args IDbCacheClientDelegate2 �Ϋ��٫��argument ϰ��?�Ǫ��� ?�� \ref CCallbackArgs

		\~
		*/
		virtual void OnSomeoneSetValue(CCallbackArgs& args) { args; }

		/**
		\~korean
		Data Access ����
		- �ݹ�Ǵ� �� : ��û�� �޼��尡 ����Ǵ� ���̿� �Ϲ��� �޼��尡 ȣ��Ȱ��
		������Ʈ�ÿ� ������Ʈ�� �����͸� ��ã�� ���, Ȥ�� �������� �����͸� ��ã�� ��� �� �� �̺�Ʈ�� ȣ��˴ϴ�.
		\param args IDbCacheClientDelegate2�� �̺�Ʈ argument ����ü�Դϴ�. ���� \ref CCallbackArgs

		\~english
		Data Access error
		- Example of callback : This event will call some situation such as one-sided method is called while requested method is running, could not find update data or could not find data that need to delete.
		\param args Event argument object of IDbCacheClientDelegate2

		\~chinese
		Data Access ??
		- ��?���ǣ��?��۰��?��Ѣ?��?۰����۰����У����?���???�����??������?�����?��?���?���?������?��?���event?����У��
		\param args IDbCacheClientDelegate2��event��argument?��?��?��\ref CCallbackArgs%��

		\~japanese
		Data Access ����?
		- ��?��Ыë�������ǣ�������᫽�ëɪ�?������������۰�ܪ˫᫽�ëɪ������󪵪������
		���ë׫�?�����˫��ë׫�?�Ȫ����?����̸�Ī���ʪ����ꡢ�ު�����𶪹�٪���?����̸�Ī���ʪ�����ʪɪ˪��Ϋ��٫�Ȫ������󪵪�ު���
		\param args IDbCacheClientDelegate2�Ϋ��٫��argumentϰ��?�Ǫ���?�� \ref CCallbackArgs

		\~
		*/
		virtual void OnAccessError(CCallbackArgs& args) = 0;

		/**
		\~korean
		���� ���� �߻��� ȣ��˴ϴ�
		\param errorInfo ������ ���� �����Դϴ�. ErrorInfo::ToString ���� ���ϰ� �ڼ��� Error ������ Ȯ���Ͻ� �� �ֽ��ϴ�.

		\~english
		It calls when it occurs internal error.
		Information of \param errorinfo error.

		\~chinese
		?ݻ?��????����У��
		\param errorInfo ???�����ӡ����� ErrorInfo::ToString()%��?��۰��������??��Error���ӡ�

		\~japanese
		?ݻ����?��?�����������󪵪�ު���
		\param errorInfo ����?��?�������êǪ���ErrorInfo::ToString��?���٪���Error���ê����㪹�몳�Ȫ��Ǫ��ު���

		\~
		*/
		virtual void OnError(ErrorInfo *errorInfo) = 0;

		/**
		\~korean
		���� ��� �߻��� ȣ��˴ϴ�. �������ٴ� ���� ������ ������ ������.
		\param errorInfo ������ ���� �����Դϴ�. ErrorInfo::ToString ���� ���ϰ� �ڼ��� Error ������ Ȯ���Ͻ� �� �ֽ��ϴ�.

		\~english
		It calls when it occurs internal warning. It reports problem that not serious than error.
		Information of \param errorinfo error.

		\~chinese
		?ݻ?����ͱ??����У��?ͱ��??������??��
		\param errorInfo ???�����ӡ����� ErrorInfo::ToString()%��?��۰��������??��Error���ӡ�

		\~japanese
		?ݻ��ͱ��?�����������󪵪�ު�������?�������٫��������ͱ���ު���
		\param errorInfo ����?��?�������êǪ���ErrorInfo::ToString ��?���٪���Error���ê����㪹�몳�Ȫ��Ǫ��ު���

		\~
		*/
		virtual void OnWarning(ErrorInfo *errorInfo) = 0;

		/**
		\~korean
		Proud.Exception ���� ���յǾ����ϴ�.
		- �Ϲ������� ���� �ڵ忡�� ���� ������ ó���մϴ�.
		- ������ �ʿ��� �͵��� �����ϸ� �˴ϴ�.
		- ExceptionType ���� �ش� Exception ��ü�� �� ����ϸ� �˴ϴ�.
		- _com_error, void*, std::exception ���� ��� ó���մϴ�.
		���� catch(...)�� ó���ϴ� OnUnhandledException()�� �ֽ��ϴ�.
		- void*�� ���� ��ü�� Ÿ���� ĳ�����ؼ� ���� �� �ֽ��ϴ�. ���� MFC CException�� �޴µ� ���˴ϴ�.

		\~english
		Merge to Proud.Exception
		- It handle error that occur from user code.
		- User realize things that user needed.
		- You can use Exceptiontype that obtain Exception object.
		- It process _com_error, void*, std::exception, etc. Also there is OnUnhandledException() that handle catch(...)
		- void* can obtain exceptional object type by casting. For example, it uses obtaining MFC CException.

		\~chinese
		?���� Proud.Exception%��
		- ����?��?��?��??����??��
		- ��?���??�����?ड�
		- ��ExceptionType?����?Exception??������?ʦ��
		- ?��_com_error, void*, std::exception ����ݻ��
		?��?��catch(...)��OnUnhandledException()��
		- ??����?����?�����ʦ����void*���������MFC CException ��?�����ġ�

		\~japanese
		Proud.Exception �����ꪵ��ު�����
		- �����ܪ˫�?��?��?�ɪ�����뫨��?��?�⪷�ު���
		- ��?��?����驪ʪ��Ȫ�?�ު�����ު��Ǫ���
		- ExceptionType ����?Exception�Ϋ��֫������Ȫ�����Ū����ު��Ǫ���
		- _com_error, void*, std::exception �ʪɪ����?�⪷�ު���
		�ު���catch(...)��?�⪹��OnUnhandledException()�⪢��ު���
		- void*�����⫪�֫������ȪΫ����ת򫭫㫹�ƫ��󫰪��ƪ�骦���Ȫ��Ǫ��ު���?��MFC CException�������몳�Ȫ��Ū��ު���

		\~
		*/
		virtual void OnException(const Exception &e) = 0;

	};

	/**
	\~korean
	<a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_client_server" >DB cache Ŭ���̾�Ʈ�� ����</a> �Դϴ�.

	\~english
	<a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_client_server" >DB cache client and server</a>

	\~chinese
	�� <a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_client_server" >DB cache��?Ӯ����?��</a> %��

	\~japanese
	\ref dbc2_client�Ǫ���
	\~
	*/
	class CDbCacheClient2
	{
	protected:
		CDbCacheClient2() {}
	public:
		virtual ~CDbCacheClient2() {}

		/**
		\~korean
		DB cache client2 �ν��Ͻ��� �����մϴ�.

		\~english
		Creates DB cache client2 instance

		\~chinese
		����DB cache client2?�ǡ�

		\~japanese
		DB cache client2 ���󫹫��󫹪��������ު���
		\~
		*/
		PROUDSRV_API static CDbCacheClient2* New();

		/**
		\~korean
		DB cache server2�� ������ �õ��մϴ�.
		\param param CDbCacheClient2�� �����ϰ� DBCacheServer2�� �����ϱ� ���� ���� ��ü �Դϴ�.

		\~english
		Attempts to connect to DB cache server2

		\~chinese
		???DB cache server2?�ȡ�
		\param param ?? CDbCacheClient2%��?��?��DBCacheServer2������?�ڡ�

		\~japanese
		DB cache server2����?���˪��ު���
		\param param CDbCacheClient2��?�Ѫ���DBCacheServer2����?���몿������ë��֫������ȪǪ���

		\~
		*/
		virtual bool Connect(CDbCacheClient2ConnectParameter& param, ErrorInfoPtr& outError) = 0;
		virtual bool Connect(CDbCacheClient2ConnectParameter& param) = 0;

		/**
		\~korean
		DB cache server2�� ������ �����ϰ� ��� �����͸� �ϼ��մϴ�.

		\~english
		Disconnect from DB cache server2 and sweep all data

		\~chinese
		?�?DB cache server2��?�ȣ�?����?�ߡ�

		\~japanese
		DB cache server2����?������������ƪΫ�?������ᷪ��ު���
		\~
		*/
		virtual void Disconnect() = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#exclusive_load" >������ �ҷ�����</a> ��û �޼����Դϴ�.
		\param rootTableName �߰��� �������� root ���̺� �̸�
		\param fieldName ã�� fieldName�Դϴ�.
		\param cmpValue ã�Ƽ� ���� ���Դϴ�.
		\param tag IDbCacheClientDelegate2.OnExclusiveLoadDataComplete ������ ���� �� �״�� �������� ����� ���� �������Դϴ�. �� ���� ���� args.m_tag�� ���� �����޽��ϴ�.
		\param message �̹� �����ε��Ǿ��ִ� �����͸� ��û�� ��� ���� �����ڿ��� ���޵Ǵ� ����� ���� �������Դϴ�. ���� �����ڴ� IDbCacheClientDelegate2.OnDataUnloadRequested�� ���� args.m_loadResults[index].m_message�� ���� �� �޽����� ���޹޽��ϴ�.


		\~english
		<a target="_blank" href="http://guide.nettention.com/cpp_en#exclusive_load" >Exclusive Load</a> request method.
		\param rootTbaleName root table name of additional data
		\param fieldName fieldName that will search
		\param cmpValue coparable value
		\param tag It is a user random data that returns when IDbCacheClientDelegate2.OnExclusiveLoadDataComplete is responded. This value returns through parameter args.m_tag.
		\param message It is a user random data that is sent to the existing sole owner in case of requesting exclusive data (loaded exclusively). This message is sent to the existing sole owner through parameter args.m_loadResults[index].m_message of IDbCacheClientDelegate2.OnDataUnloadRequested.

		\~chinese
		<a target="_blank" href="http://guide.nettention.com/cpp_zh#exclusive_load" >?�������</a> �?۰����
		\param rootTableName ���ʥ��root table ٣?��
		\param fieldName �?��fieldName��
		\param cmpValue ?��?���?��?��
		\param tag ������ IDbCacheClientDelegate2.OnExclusiveLoadDataComplete��?��?���?�����������??�ߡ��?��?Parameter args.m_tag��ޡ�
		\param message�?ϴ?�ʥ?����?��?�� ????��?����������??�ߡ�


		\~japanese
		<a target="_blank" href="http://guide.nettention.com/cpp_jp#exclusive_load" >?��ܫ�?��</a> ����ë��ɪǪ���
		\param rootTableName ��ʥ�����?����root��?�֫�٣
		\param fieldName ���� fieldName�Ǫ���
		\param cmpValue ��������٪����Ǫ���
		\param tag IDbCacheClientDelegate2.OnExclusiveLoadDataComplete?�ͪ����������˪��Ϊު�������᮪���?��?�����?���Ǫ��������������args.m_tag���ת���������᮪��ު���
		\param message ?��?￫�?�ǫ��󫰪���ƪ����?������몹�����ꡢ?��?���?ӹ������?��?�����?���Ǫ���
		?��?��� IDbCacheClientDelegate2.OnDataUnloadRequested����� args.m_loadResults[index].m_message���ת��ƪ��Ϋ�ë�?���������ު���

		*/
		virtual void RequestExclusiveLoadData(String rootTableName, String fieldName, CVariant cmpValue, intptr_t tag, const ByteArray& message = ByteArray()) = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#exclusive_load" >������ �ҷ�����</a> ��û �޼����Դϴ�.
		\param rootTableName �߰��� �������� root ���̺� �̸�
		\param rootUUID ã�� rootUUID�Դϴ�.
		\param tag IDbCacheClientDelegate2.OnExclusiveLoadDataComplete ������ ���� �� �״�� �������� ����� ���� �������Դϴ�. �� ���� ���� args.m_tag�� ���� �����޽��ϴ�.
		\param message �̹� �����ε��Ǿ��ִ� �����͸� ��û�� ��� ���� �����ڿ��� ���޵Ǵ� ����� ���� �������Դϴ�. ���� �����ڴ� IDbCacheClientDelegate2.OnDataUnloadRequested�� ���� args.m_loadResults[index].m_message�� ���� �� �޽����� ���޹޽��ϴ�.

		\~english
		<a target="_blank" href="http://guide.nettention.com/cpp_en#exclusive_load" >Exclusive Load</a> it is a request method.
		\param rootTableName it is a root table name of data that needs to be added.
		\param rootUUID it is rootUUID that needs to be found.
		\param tag It is a user random data that returns when IDbCacheClientDelegate2.OnExclusiveLoadDataComplete is responded. This value returns through parameter args.m_tag.
		\param message It is a user random data that is sent to the existing sole owner in case of requesting exclusive data (loaded exclusively). This message is sent to the existing sole owner through parameter args.m_loadResults[index].m_message of IDbCacheClientDelegate2.OnDataUnloadRequested.

		\~chinese
		<a target="_blank" href="http://guide.nettention.com/cpp_zh#exclusive_load" >?�������</a> ��?ϴMethod��
		\param rootTableName ���ʥ��?��root Table٣
		\param rootUUID �??�� rootUUID
		\param tag ������ IDbCacheClientDelegate2.OnExclusiveLoadDataSuccess �� IDbCacheClientDelegate2.OnExclusiveLoadDataFailed��?��?���?�����������??�ߡ��?��?Parameter args.m_tag��ޡ�
		\param message�?ϴ?�ʥ?����?��?�� ????��?����������??�ߡ�

		\~japanese
		<a target="_blank" href="http://guide.nettention.com/cpp_jp#exclusive_load" >?��ܫ�?��</a> ���᫽�ëɪǪ���
		\param rootTableName ��ʥ�����?���� root ��?�֫��٣��
		\param rootUUID ���� rootUUID�Ǫ���
		\param tag IDbCacheClientDelegate2.OnExclusiveLoadDataSuccess �ު��� IDbCacheClientDelegate2.OnExclusiveLoadDataFailed?�ͪ����������˪��Ϊު�������᮪���?��?�����?���Ǫ��������������args.m_tag���ת���������᮪��ު���
		\param message ?��?￫�?�ǫ��󫰪���ƪ����?������몹�����ꡢ?��?���?ӹ������?��?�����?���Ǫ���
		?��?��� IDbCacheClientDelegate2.OnDataUnloadRequested����� args.m_loadResults[index].m_message���ת��ƪ��Ϋ�ë�?���������ު���

		\~
		*/

		virtual void RequestExclusiveLoadDataByGuid(String rootTableName, Guid rootUUID, intptr_t tag, const ByteArray &message = ByteArray()) = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#exclusive_load" >������ �ҷ�����</a> ��û �޼����Դϴ�.
		\param rootTableName �߰��� �������� root ���̺� �̸�
		\param queryString RootUUID�� ã������ "select RootUUID from %s where %s" ������ ���� ������ ������ �Ǵµ� ù��° ���ڴ� rootTableName�̰� where���� �ʵ忡 �� ���ڿ��̴�.
		SQL������ �°� �ۼ��ؾ� �Ѵ�.
		\param tag IDbCacheClientDelegate2.OnExclusiveLoadDataComplete ������ ���� �� �״�� �������� ����� ���� �������Դϴ�. �� ���� ���� args.m_tag�� ���� �����޽��ϴ�.
		\param message �̹� �����ε��Ǿ��ִ� �����͸� ��û�� ��� ���� �����ڿ��� ���޵Ǵ� ����� ���� �������Դϴ�. ���� �����ڴ� IDbCacheClientDelegate2.OnDataUnloadRequested�� ���� args.m_loadResults[index].m_message�� ���� �� �޽����� ���޹޽��ϴ�.

		\~english
		<a target="_blank" href="http://guide.nettention.com/cpp_en#exclusive_load" >Exclusive Load</a> it is a request method.
		\param rootTableName it is a root table name of data that needs to be added.
		\param queryString send the query like "select RootUUID from %s where %s" to find RootUUID. The first parameter is rootTableName and it is a string that is going to be inserted into a field after where.
		It must be written in accordance with SQL syntax.
		\param tag It is a user random data that returns when IDbCacheClientDelegate2.OnExclusiveLoadDataComplete is responded. This value returns through parameter args.m_tag.
		\param message It is a user random data that is sent to the existing sole owner in case of requesting exclusive data (loaded exclusively). This message is sent to the existing sole owner through parameter args.m_loadResults[index].m_message of IDbCacheClientDelegate2.OnDataUnloadRequested.

		\~chinese
		<a target="_blank" href="http://guide.nettention.com/cpp_zh#exclusive_load" >?�������</a> ��?ϴMethod��
		\param rootTableName ���ʥ��?�� root Table٣
		\param queryString ???RootUUID�� "select RootUUID from %s where %s" ??������Query,���???? rootTableName�����where��??��Field�����ݬ����
		�������SQL?����¡�
		\param tag ������ IDbCacheClientDelegate2.OnExclusiveLoadDataSuccess �� IDbCacheClientDelegate2.OnExclusiveLoadDataFailed��?��?���?�����������??�ߡ��?��?Parameter args.m_tag��ޡ�
		\param message�?ϴ?�ʥ?����?��?�� ????��?����������??�ߡ�

		\~japanese
		<a target="_blank" href="http://guide.nettention.com/cpp_jp#exclusive_load" >?��ܫ�?��</a> ���᫽�ëɪǪ���
		\param rootTableName ��ʥ�����?����root��?�֫��٣��
		\param queryString RootUUID�����������"select RootUUID from %s where %s"�Ϊ誦�ʫ�����?����몬��1���ͪΫѫ��?��?�� rootTableName�Ǫ��ꡢ where�˽�Ϋի�?��ɪ��������֪�Ǫ���
		SQL�������ꪦ�誦���������ʪ���Ъʪ�ު���
		\param tag IDbCacheClientDelegate2.OnExclusiveLoadDataSuccess �ު��� IDbCacheClientDelegate2.OnExclusiveLoadDataFailed?�ͪ����������˪��Ϊު�������᮪���?��?�����?���Ǫ��������������args.m_tag���ת���������᮪��ު���
		\param message ?��?￫�?�ǫ��󫰪���ƪ����?������몹�����ꡢ?��?���?ӹ������?��?�����?���Ǫ���
		?��?��� IDbCacheClientDelegate2.OnDataUnloadRequested����� args.m_loadResults[index].m_message���ת��ƪ��Ϋ�ë�?���������ު���

		\~
		*/
		virtual void RequestExclusiveLoadDataByQuery(String rootTableName, String queryString, intptr_t tag, const ByteArray &message = ByteArray()) = 0;

		/**
		\~korean
		RootTable�� �����͸� �߰��ϰ� �ٷ� ����Ҷ� ���Ǵ� �Լ��Դϴ�.
		- �Ʒ��� ��뿹�Դϴ�.

		\code
		CPropNodePtr newNode = CPropNodePtr(new CPropNode(L"Gamer"));
		newNode->Fields[L"GamerID"] = "Ulelio";

		intptr_t tag; // User Defined Identifier
		m_dbCacheClient->RequestExclusiveLoadNewData(L"Gamer", newNode, tag, transaction);
		\endcode

		\param rootTableName �߰��� �������� root ���̺� �̸�
		\param addData �߰��� ������
		\param tag IDbCacheClientDelegate2.OnExclusiveLoadDataComplete ������ ���� �� �״�� �������� ����� ���� �������Դϴ�. �� ���� ���� args.m_tag�� ���� �����޽��ϴ�.
		\param transaction ����û�� transaction�� ������ ���� �����Դϴ�.

		\~english
		Function use for add data to RootTable and use it immediately.
		- Sample is as followed

		\code
		CPropNodePtr newNode = CPropNodePtr(new CPropNode(L"Gamer"));
		newNode->Fields[L"GamerID"] = "Ulelio";

		intptr_t tag; // User Defined Identifier
		m_dbCacheClient->RequestExclusiveLoadNewData(L"Gamer", newNode, tag, transaction);
		\endcode

		\param rootTbaleName root table name of additional data
		\param addData Additional data
		\param tag It is a user random data that returns when IDbCacheClientDelegate2.OnExclusiveLoadDataComplete is responded. This value returns through parameter args.m_tag.
		\param transaction Do transaction as request whether or not

		\~chinese
		��RootTable��ʥ?����ء?��������?��
		- �����������ǡ�

		\code
		CPropNodePtr newNode = CPropNodePtr(new CPropNode(L"Gamer"));
		newNode->Fields[L"GamerID"] = "Ulelio";

		intptr_t tag; // User Defined Identifier
		m_dbCacheClient->RequestExclusiveLoadNewData(L"Gamer", newNode, tag, transaction);
		\endcode

		\param rootTableName ���ʥ��?����root table ٣?
		\param addData ���ʥ��?�ߡ�
		\param tag ������ IDbCacheClientDelegate2.OnExclusiveLoadDataSuccess �� IDbCacheClientDelegate2.OnExclusiveLoadDataFailed��?��?���?�����������??�ߡ��?��?Parameter args.m_tag��ޡ�
		\param transaction ?��?�����transaction��?����

		\~japanese
		RootTable�˫�?������ʥ���ƪ������Ī��������Ū���??�Ǫ���
		- ���������ǪǪ���
		\code
		CPropNodePtr newNode = CPropNodePtr(new CPropNode(L"Gamer"));
		newNode->Fields[L"GamerID"] = "Ulelio";
		intptr_t tag; // User Defined Identifier
		m_dbCacheClient->RequestExclusiveLoadNewData(L"Gamer", newNode, tag, transaction);
		\endcode
		\param rootTableName ��ʥ�����?����root��?�֫�٣
		\param addData ��ʥ�����?��
		\param tag IDbCacheClientDelegate2.OnExclusiveLoadDataComplete ?�ͪ��������������Ϊު������ƪ�骦��?��?����Ϋ�?���Ǫ�������������� args.m_tag���ת������ƪ�骤�ު���
		\param transaction ������transaction�򪹪몫�ɪ����Ǫ���

		\~
		*/
		virtual void RequestExclusiveLoadNewData(String rootTableName, CPropNodePtr addData, intptr_t tag, bool transaction = false) = 0;

		/**
		\~korean
		��û ������ �޼����Դϴ�.
		- field�� constraints�� �ִ� ��� �� �޼��带 ���� �˴ϴ�.
		- �� �Լ������� Sucess �� failed �̺�Ʈ�� �����մϴ�.
		- �����͸� �޸𸮿� ĳ���ѵ� ���߿� DBMS�� ����ϴ°� �ƴ϶� ��û�� DBMS�� ����� �޸𸮿� ������Ʈ�˴ϴ�.
		- �Ʒ��� ��� ���Դϴ�.
		\code
		intptr_t tag = new object;
		RequestAddData(rootUUID,ownerUUID,addData,tag);

		->����
		OnAddDataSuccess(CCallbackArgs &args)
		{
		args.m_tag;//����� �Ʊ� ������ ���� ���ɴϴ�.
		}
		\endcode
		\param rootUUID add�� �������� rootUUID
		\param ownerUUID add�� �������� ownerUUID
		\param addData add�� ������
		\param tag �� ��û������ ����ڰ� �־��� �ĺ� ���Դϴ�. �ݹ�� \ref CCallbackArg ���� m_tag �� ���ϴ�.

		\~english
		Request response type method
		- If field contain constraints, use this method
		- Succeed or failed event will arrive to each functions
		- It writes data to DBMS then update to memory rather than cached to memory then write to DBMS.
		- Example is as followed
		\code
		intptr_t tag = new object;
		RequestAddData(rootUUID,ownerUUID,addData,tag);

		->����
		OnAddDataSuccess(CCallbackArgs &args)
		{
		args.m_tag;// Setting value will be here
		}
		\endcode
		\param rootUUID rootUUID of additional data
		\param ownerUUID ownerUUID of additional data
		\param addData additional data
		\param tag Verifying value about request that user need to put in. When you callback, it go throuth m_tag in CCallbackArg.

		\~chinese
		�??����۰����
		- field����constraints����?��??۰��?ʦ��
		- ?��?��?��?Success��failedevent��
		- ������?��?����?��������DBMS??������????�DBMS����?���?��
		- ����������ǡ�
		\code
		intptr_t tag = new object;
		RequestAddData(rootUUID,ownerUUID,addData,tag);

		->����
		OnAddDataSuccess(CCallbackArgs &args)
		{
		args.m_tag;//����?����?��?�졣
		}
		\endcode
		\param rootUUID �add��?��rootUUID
		\param ownerUUID �add��?��ownerUUID
		\param addData �add��?��
		\param tag ?��?����?�?����???����???��\ref CcallbackArg%��m_tag��

		\~japanese
		���?�����᫽�ëɪǪ���
		- field�� constraints���������ꡢ���Ϋ᫽�ëɪ��Ū����ު��Ǫ���
		- ��??��?����Success���failed���٫�Ȫ���󷪷�ު���
		- ��?�������?�˫���ë��媷�ơ�����DBMS����?����ΪǪϪʪ����������DBMS����?������?�˫��ë׫�?�Ȫ���ު���
		- ���������ǪǪ���
		\code
		intptr_t tag = new object;
		RequestAddData(rootUUID,ownerUUID,addData,tag);

		->�˽
		OnAddDataSuccess(CCallbackArgs &args)
		{args.m_tag;//������໪����Ҫ����������êƪ��ު���}
		\endcode
		\param rootUUID add�����?����rootUUID
		\param ownerUUID add�����?����ownerUUID
		\param addData add�����?��
		\param tag ��������?�����?��?������ƪ������ܬ���Ǫ�����?��Ыë�����\ref CCallbackArg?��m_tag������ު���

		\~
		*/
		virtual bool RequestAddData(Guid rootUUID, Guid ownerUUID, CPropNodePtr addData, intptr_t tag) = 0;

		/**
		\~korean
		�ڼ��� ������ \ref RequestAddData ����
		\param updateData ����� ����� data
		\param tag �� ��û������ ����ڰ� �־��� �ĺ� ���Դϴ�. �ݹ�� \ref CCallbackArg ���� m_tag �� ���ϴ�.

		\~english
		Refer to RequestAddData
		\param updateData
		\param tag

		\~chinese
		???٥??��\ref RequestAddData%��
		\param updateData ������node��data
		\param tag ?��?��?���ʥ��???����???��\ref CCallbackArg%����m_tag��

		\~japanese
		�٪����ϡ�\ref RequestAddData��?��
		\param updateData ?�ڪ��쪿��?�ɪΫ�?��
		\param tag ��������?�����?��?������ƪ������ܬ���Ǫ�����?��Ыë�����\ref CCallbackArg?��m_tag������ު���

		\~
		*/
		virtual bool RequestUpdateData(CPropNodePtr updateData, intptr_t tag) = 0;

		/**
		\~korean
		�ڼ��� ������ \ref RequestAddData ����
		\param rootUUID root�� UUID
		\param removeUUID ������ UUID
		\param tag �� ��û������ ����ڰ� �־��� �ĺ� ���Դϴ�. �ݹ�� \ref CCallbackArg ���� m_tag�� ���ϴ�.

		\~english TODO:translate needed.
		Refer to RequestAddData

		\~chinese
		???٥??��\ref RequestAddData%��
		\param rootUUID root ��UUID��
		\param removeUUID �?���UUID��
		\param tag ?��?��?���ʥ��???����???��\ref CCallbackArg%����m_tag��

		\~japanese
		�٪����ϡ�\ref RequestAddData��?��
		\param rootUUID root��UUID
		\param removeUUID ��۪��� UUID
		\param tag ��������?�����?��?������ƪ������ܬ���Ǫ�����?��Ыë�����\ref CCallbackArg?��m_tag������ު���

		\~
		*/
		virtual bool RequestRemoveData(Guid rootUUID, Guid removeUUID, intptr_t tag) = 0;

		/**
		\~korean
		RequestUpdateData(CPropNodePtr,Guid&)�� �޸� LoadedData�� ������ �ִ�
		������ ��� node �� �˻��Ͽ� add,update,remove���� ó���� �ݴϴ�.
		- transactional�� �������� ������ �����Ͽ����� �Ϻ� �����Ͱ� dbms �� commit �Ǿ����� �ֽ��ϴ�.
		- Notify�� �ޱ������� �����͸� �ŷ� �Ͻø� �ȵ˴ϴ�.
		- �������� ��� �ѹ��Ͻ÷��� GetClonedDataBySessionGuid �� ����Ͻʽÿ�.
		\param loadedData ��ȭ�� ������ LoadedData�Դϴ�.
		\param tag �̿�û������ ����ڰ� �־��� �ĺ� ���Դϴ�. �ݹ�� \ref CCallbackArg ���� m_tag�� ���ϴ�.
		\param transactional ����û�� transaction�� ������ ���� �����Դϴ�.

		\~english
		Instead RequestUpdateData(CPropNodePtr,Guid&), it process add, update, remove, etc to search all under node that LoadedData owned.
		- If you do not set transactional, some data will commit to dbms when it failed.
		- Do not believe data before you receive Notify.
		- Use GetClonedDataBySessionGuid when you need to roll-back.
		\param loadedData LoadedData to save changes
		\param tag Verifying value about request that user need to put in. When you callback, it go throuth m_tag in CCallbackArg.
		\param transactional Do transaction as request whether or not

		\~chinese
		?RequestUpdateData(CPropNodePtr,Guid&)���ң����LoadedData?������?�����node??��add,update,remove ����
		- �����transactional��?��?��?��?����ݻ��?��ʦ���dbms��commit��
		- ����Notify����������??�ߡ�
		- ��?��?����roll-back ��??����GetClonedDataBySessionGuid��
		\param loadedData ?��?����LoadedData��
		\param tag ?��?��?���ʥ��???����???��\ref CCallbackArg%����m_tag��
		\param transactional ?��?�����transaction��?����

		\~japanese
		RequestUpdateData(CPropNodePtr,Guid&)�Ȫ��ުêơ�LoadedData���êƪ������Ȫ���ƪΫ�?�ɪ�?�㪷��add,update,remove�ʪɪ�?�⪷�ު���
		- transactional����Ҫ��ʪ���С���������������ݻ�Ϋ�?����dbms��commit���쪿ʦ����������ު���
		- Notify����������˪ϫ�?������?���ƪϪ����ު���
		- �����������ꡢ��?��Ыë����몿��˪ϡ�GetClonedDataBySessionGuid���Ūêƪ���������
		\param loadedData ?����������LoadedData�Ǫ���
		\param tag ��������?�����?��?������ƪ������ܬ���Ǫ�����?��Ыë�����\ref CCallbackArg?��m_tag������ު���
		\param transactional ��������transaction�򪹪몫�ɪ�����?����ʦ���Ǫ���

		\~
		*/
		virtual bool RequestRecursiveUpdateData(CLoadedData2Ptr loadedData, intptr_t tag, bool transactional = false) = 0;

		/**
		\~korean
		����� �޼��� �Դϴ�.
		- ��û�������� ���������� ���� DBMS�� ����� �޸𸮿� ������Ʈ �˴ϴ�.
		- ��û���������� ���̴� ��û�� ó���Ǳ� ������ �������� �ʽ��ϴ�. ��û�� ó���Ǹ� �����մϴ�.
		\param rootUUID add�� �������� rootUUID
		\param ownerUUID add�� �������� ownerUUID
		\param addData add�� ������
		\param timeOutTime ���ѷ����� ������ �ʱ����� ������ ��ٸ��½ð�. default 30sec
		\param outError ����Ÿ��

		\~english
		Block type method.
		- It write to DBMS first then update to memory like request response type.
		- Only difference is not return before request has done. Once request is finished then return.
		\param rootUUID rootUUID of additional data
		\param ownerUUID ownerUUID of additional data
		\param addData additional data
		\param timeOutTime Waiting time to prevent unlimited roop. default 30sec
		\param outError Error type

		\~chinese
		Block ��۰����
		- ?�??������?�����DBMS??���?��?��
		- ?�??������??�����?��?��������?���ޡ��?��?����??���ޡ�
		\param rootUUID �add��?��rootUUID
		\param ownerUUID �add��?��ownerUUID
		\param addData �add��?�ߡ�
		\param timeOutTime ?������������roop����������??��default 30sec��
		\param outError ???����

		\~japanese
		�֫�ë����᫽�ëɪǪ���
		- ���?��������?��໪�DBMS����?������?�˫��ë׫�?�Ȫ���ު���
		- ���?�����Ȫ�����몬?�⪵�����ުǫ꫿?�󪷪ު�����몬?�⪵�쪿��꫿?�󪷪ު���
		\param rootUUID add�����?����rootUUID
		\param ownerUUID add�����?����ownerUUID
		\param addData add�����?��
		\param timeOutTime ���ګ�?�ת�ժ���ʪ��誦�˪��몿�ᡢ�꫿?���������ࡣdefault 30sec
		\param outError ����?������

		\~
		*/
		virtual bool BlockedAddData(Guid rootUUID, Guid ownerUUID, CPropNodePtr addData, uint32_t timeOutTime = 30000, ErrorInfoPtr outError = ErrorInfoPtr()) = 0;

		/**
		\~korean
		�ڼ��� ������ \ref BlockedNonCacheAddData ����
		\param updateData update�� node
		\param timeOutTime ���ѷ����� ������ �ʱ����� ������ ��ٸ��½ð�. default 30sec
		\param outError ����Ÿ��

		\~english
		For a detailed explanation, refer to \ref BlockedNonCacheAddData
		\param updateData Node to be updated.
		\param timeOutTime  The time waiting for the return to avoid falling into an infinite loop. Default is 30 seconds. 
		\param outError Error type

		\~chinese
		???٥??��\ref BlockedNonCacheAddData%��
		\param updateData �update��?�ߡ�
		\param timeOutTime ?������������roop����������??��default 30sec��
		\param outError ???����

		\~japanese
		�٪����ϡ�\ref BlockedNonCacheAddData ?��
		\param updateData update����node
		\param timeOutTime ���ګ�?�ת�ժ���ʪ��誦�˪��몿�ᡢ�꫿?���������ࡣdefault 30sec
		\param outError ����?������

		\~
		*/
		virtual bool BlockedUpdateData(CPropNodePtr updateData, uint32_t timeOutTime = 30000, ErrorInfoPtr outError = ErrorInfoPtr()) = 0;

		/**
		\~korean
		BlockedNonCacheAddData ����
		\param rootUUID add�� �������� rootUUID
		\param removeUUID �����ϰ��� �ϴ� UUID
		\param timeOutTime ���ѷ����� ������ �ʱ����� ������ ��ٸ��½ð�. default 30sec
		\param outError ����Ÿ��

		\~english
		Refer to BlockedNonCacheAddData
		\param rootUUID rootUUID of the data to be added 
		\param removeUUID to be deleted
		\param The time waiting for the return to avoid falling into an infinite loop. Default is 30 seconds.
		\param outError type

		\~chinese
		?��BlockedNonCacheAddData��
		\param rootUUID �add��?��rootUUID��
		\param removeUUID �?���UUID��
		\param timeOutTime ?������������roop����������??��default 30sec��
		\param outError ???����

		\~japanese
		BlockedNonCacheAddData ?��
		\param rootUUID add�����?����rootUUID
		\param removeUUID ��۪��誦�Ȫ���UUID
		\param timeOutTime ���ګ�?�ת�ժ���ʪ��誦�˪��몿�ᡢ�꫿?���������ࡣdefault 30sec
		\param outError ����?������

		\~
		*/
		virtual bool BlockedRemoveData(Guid rootUUID, Guid removeUUID, uint32_t timeOutTime = 30000, ErrorInfoPtr outError = ErrorInfoPtr()) = 0;

		/**
		\~korean
		BlockedUpdateData(CPropNodePtr,...)�� �޸� LoadedData�� ������ �ִ� ������ ��� node�� �˻��Ͽ� add,update,remove���� ó���� �ݴϴ�.
		- transactional�� �������� ������ �����Ͽ����� �Ϻ� �����Ͱ� dbms�� commit�Ǿ����� �ֽ��ϴ�.
		- Notify�� �ޱ������� �����͸� �ŷ� �Ͻø� �ȵ˴ϴ�.
		- �������� ��� �ѹ��Ͻ÷��� GetClonedDataBySessionGuid�� ����Ͻʽÿ�.
		\param loadedData ��ȭ�� ������ LoadedData�Դϴ�.
		\param transactional ����û�� transaction�� ������ ���� �����Դϴ�.
		\param timeOutTime ���Ѵ�⿡ ������ �ʱ����� ������ ��ٸ��� �ð�.default 30sec
		\param outError ����Ÿ��

		\~english
		Instead BlockedUpdateData(CPropNodePtr,...), it process add, update, remove, etc to search all under node that LoadedData owned.
		- If you do not set transactional, some data will commit to dbms when it failed.
		- Do not believe data before you receive Notify.
		- Use GetClonedDataBySessionGuid when you need to roll-back.
		\param loadedData LoadedData to save changes
		\param transactional Do transaction as request whether or not
		\param timeOutTime Waiting time to prevent unlimited roop. default 30sec
		\param outError Error type

		\~chinese
		?RequestUpdateData(CPropNodePtr,Guid&)���ң����LoadedData?������?�����node??��add,update,remove ����
		- �����transactional��?��?��?��?����ݻ��?��ʦ���dbms��commit��
		- ����Notify����������??�ߡ�
		- ��?��?����roll-back ��??����GetClonedDataBySessionGuid��
		\param loadedData ?��?����LoadedData��
		\param transactional ?��?�����transaction��?����
		\param timeOutTime ?������������roop����������??��default 30sec��
		\param outError ???����

		\~japanese
		BlockedUpdateData(CPropNodePtr,...)�Ȫ��ުêơ�LoadedData���êƪ������Ȫ���ƪ�node��?�㪷��add,update,remove�ʪɪ�?�⪷�ު���
		- transactional����Ҫ��ʪ������������������ݻ�Ϋ�?����dbms��commit���쪿ʦ����������ު���
		- Notify����������˪ϫ�?������?���ƪϪ����ު���
		- �����������ꡢ��?��Ыë����몿��˪ϡ�GetClonedDataBySessionGuid���Ūêƪ���������
		\param loadedData ?����������LoadedData�Ǫ���
		\param transactional ��������transaction�򪹪몫�ɪ����Ǫ���
		\param timeOutTime ���ګ�?�ת�ժ���ʪ��誦�˪��몿�ᡢ�꫿?���������ࡣdefault 30sec
		\param outError ����?������

		\~
		*/
		virtual bool BlockedRecursiveUpdateData(CLoadedData2Ptr loadedData, bool transactional = false, uint32_t timeOutTime = 30000, ErrorInfoPtr outError = ErrorInfoPtr()) = 0;

		/**
		\~korean
		�Ϲ���(Unilateral) �޼����Դϴ�.
		- �����Ͱ� �޸𸮿� Cache�ȵ� ���߿� DBMS�� ��ϵ˴ϴ�.
		- ������ DbCacheClient �� ��������Դϴ�.
		- field�� constraints�� ���ٸ� �̹���� ���°��� �����մϴ�.
		- �Ϲ�޼����̱� ������ ���� �̺�Ʈ �ݹ��� ���� �ʽ��ϴ�.
		\param rootUUID add�� �������� rootUUID
		\param ownerUUID add�� �������� ownerUUID
		\param addData add�� ������
		\param writeDbmsImmediately true�̸� DBMS�� ������ �߰� ����� �ִ��� ���� ����� �����Ѵ�.

		\~english
		Unilateral method
		- Data get cached to memory first then write to DBMS
		- Same type as DbCacheClient
		- We recommend to use it if field does not contain constraints.
		- It does not send event callback because it is one-sided method
		\param rootUUID rootUUID of additional data
		\param ownerUUID ownerUUID of additional data
		\param addData additional data
		\param writeDbmsImmediately If it is true, it write information of added item to DBMS as soon as possible.

		\~chinese
		��?۰����Unilateral��۰����
		- ?���?��Cache�������DBMS??��
		- ??����DbCacheClient������۰�ҡ�
		- field��?��constraints��?��?�����۰�ҡ�
		- ��?��?۰��۰������??���?��?event��
		\param rootUUID �add��?����rootUUID��
		\param ownerUUID �add��?����ownerUUID��
		\param addData �add��?�ߡ�
		\param writeDbmsImmediately true ��?��������?��??�DBMS��ʥԳ�������ס�

		\~japanese
		��۰��(Unilateral)�ʫ᫽�ëɪǪ���
		- ��?��������?��Cache����ơ�����DBMS����?����ު���
		- ?���DbCacheClient���Ҫ�۰�ҪǪ���
		- field��constraints���ʪ���Ъ���۰�Ҫ��Ū����Ȫ�?�᪷�ު���
		- ��۰�᫽�ëɪǪ��몿�ᡢܬ�˫��٫�ȫ�?��Ыë���?�ު���
		\param rootUUID add�����?����rootUUID
		\param ownerUUID add�����?����ownerUUID
		\param addData add�����?��
		\param writeDbmsImmediately true�Ǫ����DBMS�˫����ƫ���ʥ��?�������ڪ��ܪ���?���������ު���

		\~
		*/
		virtual bool UnilateralAddData(Guid rootUUID, Guid ownerUUID, CPropNodePtr addData, bool writeDbmsImmediately = true) = 0;

		/**
		\~korean
		�ڼ��� ������ \ref UnilateralAddData ����
		\param update �ϰ��� �ϴ� node�� data
		\param writeDbmsImmediately true�̸� DBMS�� �ִ��� ���� ����� ����

		\~english TODO:translate needed.
		For a detailed explanation, refer to \ref UnilateralAddData
		\param update Node data to be updated
		\param writeDbmsImmediately     If true, execute record as fast as possible in DBMS. 

		\~chinese
		??��??��\ref UnilateralAddData%��
		\param update �����node��data��
		\param writeDbmsImmediately true ��?��������?��??��

		\~japanese
		�٪����ϡ�\ref UnilateralAddData ?��
		\param update ������node��data
		\param writeDbmsImmediately true�Ǫ����DBMS�������ڪ��ܪ���?������

		\~
		*/
		virtual bool UnilateralUpdateData(CPropNodePtr updateData, bool writeDbmsImmediately = true) = 0;


		/**
		\~korean
		�Ϲ���(Unilateral) �޼����Դϴ�.
		- �����Ͱ� �޸𸮿� Cache�ȵ� ���߿� DBMS�� ��ϵ˴ϴ�.
		- ������ ���(rootUUID,nodeUUID)�� ������ Ʈ�� ���(destRootUUID,destNodeUUID) ������ �̵� �� ŵ�ϴ�.
		- field�� constraints�� ���ٸ� �̹���� ���°��� �����մϴ�.
		- �����Ͱ� �̵��� DBCacheClient ���� �̺�Ʈ�� �ݹ�˴ϴ�.
		\param rootUUID move�� rootUUID ���
		\param ownerUUID move�� ownerUUID ���
		\param destRootUUID attach�� destRootUUID ���
		\param destNodeUUID attach�� destNodeUUID ���

		\~english
		Unilateral method
		- Data get cached to memory first then write to DBMS
		- Data node(rootUUID,nodeUUID) attach to specified tree node(destRootUUID,destNodeUUID)
		- We recommend to use it if field does not contain constraints.
		- An event is callbacked to DBCacheclient in which data has been moved.
		\param rootUUID rootUUID of move node
		\param ownerUUID ownerUUID of move node
		\param destRootUUID destNodeUUID of attach node
		\param writeDbmsImmediately If it is true, it write information of added item to DBMS as soon as possible.

		\~chinese
		��?۰����Unliateral����۰����
		- Data?�?��Cashe������?��??��DBMS��
		- ?Datanode(rootUUID,nodeUUID)���?����Treenode(destRootUUID,destNodeUUID)�����ȡ�
		- ����field??��constraints?����?�����۰����
		- ?���??����DBCacheClient��?Event��
		\param rootUUID �move��rootUUID node��
		\param ownerUUID �move��ownerUUID node��
		\param destRootUUID �attach��destRootUUID node��
		\param destNodeUUID  �attach��destNodeUUID node��

		\~japanese
		��۰��(Unilateral)�᫽�ëɪǪ���
		- ��?��������?��Cache����ơ�����DBMS����?����ު���
		- ��?����?��(rootUUID,nodeUUID)��̽�ުê��ī�?��?��(destRootUUID,destNodeUUID)�����Ȫ���Ѫ����ު���
		- field��constraints���ʪ���Ъ���۰�Ҫ��Ū����Ȫ�?�᪷�ު���
		- ��?������Ѫ��쪿DBCacheClient�˫��٫�Ȫ���?��Ыë�����ު���
		\param rootUUID move���� rootUUID ��?��
		\param ownerUUID move���� ownerUUID ��?��
		\param destRootUUID attach���� destRootUUID ��?��
		\param destNodeUUID attach���� destNodeUUID ��?��

		\~
		*/
		virtual bool UnilateralMoveData(String rootTableName, Guid rootUUID, Guid nodeUUID, Guid destRootUUID, Guid destNodeUUID, bool writeDbmsImmediately = true) = 0;

		/**
		\~korean
		�ڼ��� ������ \ref UnilateralAddData ����
		\param rootUUID root�� UUID
		\param removeUUID ������ UUID
		\param writeDbmsImmediately true�̸� DBMS�� �ִ��� ���� ����� ����

		\~english TODO:translate needed.
		For a detailed explanation, refer to \ref UnilateralAddData
		\param rootUUID     UUID of the root
		\param removeUUID      UUID to be deleted
		\param writeDbmsImmediately          If true, execute record as fast as possible in DBMS.

		\~chinese
		????��\ref UnilateralAddData%��
		\param rootUUID ��root��UUID��
		\param removeUUID �?���UUID��
		\param writeDbmsImmediately true ��?���������DBMS?��??��

		\~japanese
		�٪����ϡ�\ref UnilateralAddData ?��
		\param rootUUID root�� UUID
		\param removeUUID ��۪��� UUID
		\param writeDbmsImmediately true�Ǫ����DBMS���������ܪ���?���������ު���

		\~
		*/
		virtual bool UnilateralRemoveData(Guid rootUUID, Guid removeUUID, bool writeDbmsImmediately = true) = 0;

		/**
		\~korean
		�ڼ��� ������ \ref UnilateralAddData ����
		\param loadedData �ε�� Data
		\param transactional Ʈ������ ��� ��� ����
		\param writeDbmsImmediately true�̸� DBMS�� �ִ��� ���� ����� ����

		\~english TODO:translate needed.
		For a detailed explanation, refer to \ref UnilateralAddData
		\param loadedData         Data Loaded data
		\param transactional      Whether to use the transaction feature 
		\param writeDbmsImmediately      If true, execute record as fast as possible in DBMS.

		\~chinese
		???٥??��\ref UnilateralAddData%��
		\param loadedData ʥ?��Data��
		\param transactional ����transaction����?����
		\param writeDbmsImmediately true ��?���������DBMS?��??��

		\~japanese
		�٪����ϡ�\ref UnilateralAddData ?��
		\param loadedData ��?�ɪ��쪿Data
		\param transactional �ȫ�󫶫������Ѧ��������ʦ��
		\param writeDbmsImmediately true�Ǫ����DBMS�������ڪ��ܪ���?���������ު���

		
		\~
		*/
		virtual bool UnilateralRecursiveUpdateData(CLoadedData2Ptr loadedData, bool transactional = false, bool writeDbmsImmediately = true) = 0;


		/**
		\~korean
		- Ư�� Session�� Unload�� ��û�ϰ� �ش� �������� �������� �����մϴ�.
		- \ref OnUnloadDataRequested �� ȣ��Ǿ��� �� ��û�ڿ��� �������� �Ѱ��ַ��� �� �Լ��� ȣ���ؾ� �մϴ�.
		\param sessionGuid Unload �� �������� session Guid�Դϴ�.
		\param messageToNextLoader ������ ��û�ڿ��� �����ϴ� ����� ���� �޽����Դϴ�. ��û�ڴ� IDbCacheClientDelegate2.OnExclusiveLoadDataSuccess�� args.m_loadResults[index].m_message�� ���� �ش� �޽����� Ȯ�� �� �� �ֽ��ϴ�.

		\~english
		- It requests Unload of the certain session and abandons the exclusive right of the relevant data.
		- In order to devolve the exclusive right upon a requester, you need to call this function when \ref OnUnloadDataRequested is called.
		\param sessionGuid It is a session Guid of data that needs to be unloaded.
		\param messageToNextLoader It is a user random message that is sent to the exclusive right requester. The requester may check the relevant message through args.m_loadResults[index].m_message of IDbCacheClientDelegate2.OnExclusiveLoadDataSuccess.

		\~chinese
		- ?ϴ����Session��Unload����ۯ???��??��?�?��
		- \ref OnUnloadDataRequested������?�����??�?????ϴ���?�����������?��
		\param sessionGuid Unload?����session Guid��
		\param messageToNextLoader ????�??ϴ���������?���ӡ�?ϴ���? IDbCacheClientDelegate2.OnExclusiveLoadDataSuccess�� args.m_loadResults[index].m_message��ʦ�???��ӡ�

		\~japanese
		- ���� Session�� Unload����몷����?��?����?��������ު���
		- \ref OnUnloadDataRequested �������󪵪쪿���������?�?��Ԥ������˪Ϫ���??����������驪�����ު���
		\param sessionGuid Unload �����?����session Guid�Ǫ���
		\param messageToNextLoader ?�?�����?ӹ�����?��?�����ë�?���Ǫ��������IDbCacheClientDelegate2.OnExclusiveLoadDataSuccess�� args.m_loadResults[index].m_message���ת�����?��ë�?��������Ǫ��ު���
		*/
		virtual bool UnloadDataBySessionGuid(Guid sessionGuid, const ByteArray& messageToNextLoader = ByteArray()) = 0;


		/**
		\~korean
		Unload�� �������� �ʽ��ϴ�.
		- \ref OnUnloadDataRequested �� �ݹ��� �� ���� ȣ���ؾ� �ϴ� �������̽��Դϴ�.
		- �� �Լ��� ȣ���ϸ� �ٸ� Ŭ���̾�Ʈ�� �������� �Ѱ����� �ʽ��ϴ�.
		\param sessionGuid �������� �������� session Guid�Դϴ�.
		\messageToRequester ������ ��û�ڿ��� �����ϴ� ����� ���� �޽����Դϴ�. ��û�ڴ� IDbCacheClientDelegate2.OnExclusiveLoadDataFailed�� args.m_loadResults[index].m_message�� ���� �ش� �޽����� Ȯ�� �� �� �ֽ��ϴ�.

		\~english
		It does not admit Unload
		- This interface has to call after callback arrived to \ref OnUnloadDataRequested.
		- If you call this function, it does not pass exclusive rights to other client.
		\param sessionGuid It is a session Guid of the exclusive data.
		\param messageToRequester It is a user random message that is sent to the exclusive right requester. The requester may check the relevant message through args.m_loadResults[index].m_message of IDbCacheClientDelegate2.OnExclusiveLoadDataFailed.

		\~chinese
		���?unload��
		- ��?��\ref OnUnloadDataRequested%������У��?�ǡ�
		- ��У���?��?����??������ʫ��?�?��
		\param sessionGuid ?���?����session Guid��
		\param messageToRequester ????�??ϴ���������?���ӡ�?ϴ���?IDbCacheClientDelegate2.OnExclusiveLoadDataFailed�� args.m_loadResults[index].m_message��ʦ�???��ӡ�

		\~japanese
		Unload�����ު���
		- \ref OnUnloadDataRequested �˫�?��Ыë���?�������������驪����뫤��?�ի�?���Ǫ���
		- ����??�����󪷪����ު����髤����Ȫ�?�?��Ԥ���ު���
		\param sessionGuid ?���Ϋ�?���� session Guid�Ǫ���
		\param messageToRequester ?�?�����?ӹ�����?��?�����ë�?���Ǫ�������� IDbCacheClientDelegate2.OnExclusiveLoadDataFailed�� args.m_loadResults[index].m_message���ת�����?��ë�?��������Ǫ��ު���

		*/
		virtual void DenyUnloadData(Guid sessionGuid, const ByteArray& messageToRequester = ByteArray()) = 0;

		/*
		\~korean
		���� �̸��� �޼��� ����

		\~english
		Refer to same name method

		\~chinese
		?����٣��۰����

		\~japanese
		��٣�Ϋ᫽�ë�?��
		\~
		*/
		/*inline bool UnloadDataBySessionGuid(CLoadedDataPtr data)
		{
		return UnloadDataBySessionGuid(data->m_sessionGuid);
		} */

		/**
		\~korean
		Data tree�� DB cache�κ��� ������ unload�� �����ϴ�. DB cache client�Ӹ� �ƴ϶�
		DB cache server������ unload�� �մϴ�.

		DB cache�� ������� data tree�� ���� DB �＼���� ���� �ٷ���� �Ѵٸ�,
		�� �Լ� ��� <a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_isolate_overview" >DB cache�� �ٷ�� �����͸� DB�� ���� �＼���ϱ�</a> ����� ����Ͻʽÿ�.

		\param rootUUID unload�ϰ��� �ϴ� data tree�� root UUID�Դϴ�.

		\~english
		Data tree is completely uploaded from DB cache. It must be uploaded in DB
		cache client and DB cache server.

		If you want to deal with data tree that DB cache is using by direct DB access,
		you need to use <a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_isolate_overview" >DB directly has access to data that DB cache deals with </a> function instead of this function.

		\param rootUUID this is root UUID of data tree that is going to be unloaded.

		\~chinese
		?DB cache����unload Data tree�����DB cache client��
		�DB cache server���?�� unload��

		����DB cache�����?DB??���������������data tree��
		?�� <a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_isolate_overview" >DB����??DB cache������?��</a> �����������?��

		\param rootUUID �?��unload��data tree�� root UUID.

		\~japanese
		Data tree��DB cache���������unload���ު��� DB cache client�����ǪϪʪ��ơ�
		DB cache server�Ǫ�unload�򪷪ު���

		DB cache���������data tree������ DB�����������ת����⪪���Ȫ����˪ϡ�
		����??���۪��� <a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_isolate_overview" >DB cache���ê��?����DB�����ȫ�������</a> ��Ѧ�������Ī��ƪ���������

		\param rootUUID unload���誦�Ȫ��� data tree��root UUID�Ǫ���
		*/
		virtual void ForceCompleteUnload(Guid rootUUID) = 0;

		/**
		\~korean
		���������� data�� �ֽ� ���¸� ���ɴϴ�. <a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >������ ������ �����ϱ�</a> ����Դϴ�. \n
		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataFailed (CCallbackArgs args)

		\param rootTableName root ���̺��� �̸�
		\param fieldName �ʵ��
		\param cmpValue ���� ��. �̸� SQL���� �����ϸ� WHERE fieldName = cmpValue �� �����մϴ�.
		\param tag �̿�û������ ����ڰ� �־��� �ĺ� ���Դϴ�.�ݹ�� \ref CCallbackArg ���� m_tag�� ���ϴ�.

		\~english
		Gets the latest status value as non-exclusively. <a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> function.
		\param rootTableName Name of root table
		\param fieldName
		\param cmpValue
		\param tag Verifying value about request that user need to put in. When you callback, it go throuth m_tag in CCallbackArg.

		\~chinese
		ު?�����?��������??����<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??������?��</a>%������\n
		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataFailed (CCallbackArgs args)
		\param rootTableName root table ��٣?��
		\param fieldName
		\param cmpValue
		\param tag ?��?��?�?����???����???��\ref CCallbackArg%��m_tag��

		\~japanese
		ު?��ܪ˫�?��������?������ƪ��ު���\ref pndb_nonexclusive_access Ѧ���Ǫ���\n
		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataFailed (CCallbackArgs args)
		\param rootTableName root ��?�֫�٣
		\param rootUUID ��?��?���RootUUID
		\param tag ��������?�����?��?������ƪ������ܬ���Ǫ�����?��Ыë�����\ref CCallbackArg?��m_tag������ު���

		\~
		*/
		virtual void RequestNonExclusiveSnapshotData(String rootTableName, String fieldName, CVariant cmpValue, intptr_t tag) = 0;

		/**
		\~korean
		���������� data�� �ֽ� ���¸� ���ɴϴ�. <a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >������ ������ �����ϱ�</a> ����Դϴ�. \n
		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataFailed (CCallbackArgs args)

		\param rootTableName root ���̺��� �̸�
		\param rootUUID ������ �˻��� RootUUID
		\param tag �̿�û������ ����ڰ� �־��� �ĺ� ���Դϴ�.�ݹ�� \ref CCallbackArg ���� m_tag�� ���ϴ�.

		\~english
		Gets the latest status value as non-exclusively. <a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> function.
		\param rootTableName Name of root table
		\param rootUUID
		\param tag Verifying value about request that user need to put in. When you callback, it go throuth m_tag in CCallbackArg.

		\~chinese
		ު?�����?��������??����<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??������?��</a>%������\n
		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataFailed (CCallbackArgs args)
		\param rootTableName root table ��٣?��
		\param rootUUID
		\param tag ?��?��?�?����???����???��\ref CCallbackArg%��m_tag��

		\~japanese
		
		\~
		*/
		virtual void RequestNonExclusiveSnapshotDataByGuid(String rootTableName, Guid rootUUID, intptr_t tag) = 0;

		/**
		\~korean
		���������� data�� �ֽ� ���¸� ���ɴϴ�. <a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >������ ������ �����ϱ�</a> ����Դϴ�. \n
		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataFailed (CCallbackArgs args)

		\param rootTableName root ���̺��� �̸�
		\param searchString ������ �˻��� ���� ������ ( where�� ���Ŀ� �� ���� )
		\param tag �̿�û������ ����ڰ� �־��� �ĺ� ���Դϴ�.�ݹ�� \ref CCallbackArg ���� m_tag�� ���ϴ�.

		\~english
		Gets the latest status value as non-exclusively. <a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> function.
		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataFailed (CCallbackArgs args)

		\param rootTableName Name of root table
		\param searchString Query for data searching( For after "where")
		\param tag Verifying value about request that user need to put in. When you callback, it go throuth m_tag in CCallbackArg.

		\~chinese
		ު?�����?��������??����<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??������?��</a>%������\n
		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataFailed (CCallbackArgs args)

		\param rootTableName root table ��٣?��
		\param searchString ?��?�������query?ϣ����where ���?����?ϣ��
		\param tag ?��?��?�?����???����???��\ref CCallbackArg%��m_tag��

		\~japanese
		ު?��ܪ� data������?����?��?�ߪު��� <a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> Ѧ���Ǫ���\n
		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataFailed (CCallbackArgs args)

		\param rootTableName root ��?�֫��٣��
		\param searchString ��?��?��Ϊ���Ϋ�����?�� ( whereｪ��˽������ϰ��)
		\param tag ��������?���ƫ�?��������������ܬ�����Ǫ�����?��Ыë��� \ref CCallbackArg ��� m_tag������ު���

		\~
		*/
		virtual void RequestNonExclusiveSnapshotDataByQuery(String rootTableName, String searchString, intptr_t tag) = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >������ ������ �����ϱ�</a> ����Դϴ�.
		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveAddDataAck (CCallbackArgs args)

		�������� DB Cache Client Callback:
		- IDbCacheClientDelegate2::OnSomeoneAddData(CCallbackArgs& args)

		\param rootTableName root���̺��� �̸��Դϴ�.
		\param rootUUID root�� UUID�Դϴ�.
		\param ownerUUID owner�� UUID�Դϴ�.
		\param addData �߰��� node�� data�Դϴ�.
		\param tag ��û �ĺ��� ���� ����� ���� �������Դϴ�. �ݹ� �� \ref CCallbackArg �� m_tag�� ���� �����޽��ϴ�.
		\param messageToLoader �ش� �������� �����ڿ��� �����ϴ� ����� ���� �޽����Դϴ�. �����ڴ� IDbCacheClientDelegate2::OnSomeoneAddData�� args.m_loadResults[index].m_message�� ���� �̸� ���޹޽��ϴ�.


		\~english
		<a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> function.
		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveAddDataAck (CCallbackArgs args)

		Exclusive DB Cache Client Callback:
		- IDbCacheClientDelegate2::OnSomeoneAddData(CCallbackArgs& args)

		\param rootTableName it is name of root table.
		\param rootUUID it is UUID of root.
		\param ownerUUID it is UUID of owner.
		\param addData it is data of node that is going to be added.
		\param tag Verifying value about request that user need to put in. When you callback, it go throuth m_tag in CCallbackArg.
		\param messageToLoader It is a user random message that is sent to a sole owner of the relevant data. The sole owner has this through args.m_loadResults[index].m_message of IDbCacheClientDelegate2::OnSomeoneAddData.


		\~chinese
		��<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??������?��</a>%������
		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveAddDataAck (CCallbackArgs args)

		?�����DB Cache Client Callback:
		- IDbCacheClientDelegate2::OnSomeoneAddData(CCallbackArgs& args)
		\param rootTableName root table ��٣?��
		\param rootUUID ��root��UUID��
		\param ownerUUID ��owner��UUID��
		\param addData ���ʥ��node��data��
		\param tag ?��?����?�?����???����???��\ref CcallbackArg%��m_tag��
		\param messageToLoader ???? ��??��?��?����������?���ӡ�?����?IDbCacheClientDelegate2::OnSomeoneAddData�� args.m_loadResults[index].m_message������ӡ�

		\~japanese
		<a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> Ѧ���Ǫ���
		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveAddDataAck (CCallbackArgs args)

		?���� DB Cache Client Callback:
		- IDbCacheClientDelegate2::OnSomeoneAddData(CCallbackArgs& args)

		\param rootTableName root��?�֫��٣��Ǫ���
		\param rootUUID root�� UUID�Ǫ���
		\param ownerUUID owner�� UUID�Ǫ���
		\param addData ��ʥ����node�� data�Ǫ���
		\param tag ��������?���ƫ�?��������������ܬ�����Ǫ�����?��Ыë��� \ref CCallbackArg ��� m_tag������ު���
		\param messageToLoader ��?��?����?���Ԥ����?��?�����ë�?���Ǫ���?��� IDbCacheClientDelegate2::OnSomeoneAddData�� args.m_loadResults[index].m_message���ת��ƪ����?ӹ����ު���

		\~
		*/
		virtual void RequestNonExclusiveAddData(String rootTableName, Guid rootUUID, Guid ownerUUID, CPropNodePtr addData, intptr_t tag, const ByteArray &messageToLoader=ByteArray()) = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >������ ������ �����ϱ�</a> ����Դϴ�.

		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveRemoveDataAck (CCallbackArgs args)

		���� ���� DB Cache Client Callback:
		- IDbCacheClientDelegate2::OnSomeoneRemoveData (CCallbackArgs& args)

		\param rootTableName root���̺��� �̸��Դϴ�.
		\param rootUUID root�� UUID�Դϴ�.
		\param removeUUID �����ϰ��� �ϴ� UUID�Դϴ�.
		\param tag ��û �ĺ��� ���� ����� ���� �������Դϴ�. �ݹ� �� \ref CCallbackArg �� m_tag�� ���� �����޽��ϴ�.
		\param messageToLoader �ش� �������� �����ڿ��� �����ϴ� �޽����Դϴ�. �����ڴ� IDbCacheClientDelegate2::OnSomeoneRemoveData�� args.m_loadResults[index].m_message�� ���� �̸� ���޹޽��ϴ�.


		\~english
		<a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> function.

		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveRemoveDataAck (CCallbackArgs args)

		Exclusive DB Cache Client Callback:
		- IDbCacheClientDelegate2::OnSomeoneRemoveData (CCallbackArgs& args)

		\param rootTableName it is name of root table.
		\param rootUUID it is UUID of root.
		\param removeUUID it is UUID that is going to be eliminated.
		\param tag Verifying value about request that user need to put in. When you callback, it go throuth m_tag in CCallbackArg.
		\param messageToLoader It is a user random message that is sent to a sole owner of the relevant data. The sole owner has this through args.m_loadResults[index].m_message of IDbCacheClientDelegate2::OnSomeoneAddData.


		\~chinese
		��<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??������?��</a>%������
		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveRemoveDataAck (CCallbackArgs args)

		?�����DB Cache Client Callback:
		- IDbCacheClientDelegate2::OnSomeoneRemoveData (CCallbackArgs& args)
		\param rootTableName root table ��٣?��
		\param rootUUID ��root��UUID��
		\param removeUUID �?���UUID��
		\param tag ?��?����?�?����???����???��\ref CcallbackArg%��m_tag��
		\param messageToLoader ???? ��??��?��?����������?���ӡ�?����?IDbCacheClientDelegate2::OnSomeoneAddData�� args.m_loadResults[index].m_message������ӡ�


		\~japanese
		<a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> Ѧ���Ǫ���

		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveRemoveDataAck (CCallbackArgs args)

		?����DB Cache Client Callback:
		- IDbCacheClientDelegate2::OnSomeoneRemoveData (CCallbackArgs& args)

		\param rootTableName root��?�֫��٣��Ǫ���
		\param rootUUID root�� UUID�Ǫ���
		\param removeUUID ��۪��誦�Ȫ���UUID�Ǫ���
		\param tag ��������?���ƫ�?��������������ܬ�����Ǫ�����?��Ыë��� \ref CCallbackArg ��� m_tag������ު���
		\param messageToLoader ��?��?����?���Ԥ����?��?�����ë�?���Ǫ���?��� IDbCacheClientDelegate2::OnSomeoneAddData�� args.m_loadResults[index].m_message���ת��ƪ����?ӹ����ު���

		\~
		*/
		virtual void RequestNonExclusiveRemoveData(String rootTableName, Guid rootUUID, Guid removeUUID, intptr_t tag, const ByteArray &messageToLoader=ByteArray()) = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >������ ������ �����ϱ�</a> ����Դϴ�.
		- DBCacheServer�� �ε�Ǿ��ִ� �������� compareValue�� ���Ͽ� ������ �����ϸ� newValue�� �����մϴ�.

		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveSetValueIfSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveSetValueIfFailed (CCallbackArgs args)

		���� ���� DB Cache Client Callback:
		- IDbCacheClientDelegate2::OnSomeoneSetValue (CCallbackArgs& args)

		\param rootTableName root���̺��� �̸��Դϴ�.
		\param rootUUID root�� UUID�Դϴ�.
		\param nodeUUID node�� UUID�Դϴ�.
		\param propertyName ���� setting�� �Ӽ��� �̸��Դϴ�.
		\param newValue �� ������ �����ϴ� ��� ���� ���Ե� ���Դϴ�.
		\param compareType �� ���� type�Դϴ�.
		\param compareValue ���� ���� ���� ���Դϴ�.
		\param tag ��û �ĺ��� ���� ����� ���� �������Դϴ�. �ݹ� �� \ref CCallbackArg �� m_tag�� ���� �����޽��ϴ�.
		\param messageToLoader �ش� �������� �����ڿ��� �����ϴ� �޽����Դϴ�. �����ڴ� IDbCacheClientDelegate2::OnSomeoneSetValue�� args.m_loadResults[index].m_message�� ���� �̸� ���޹޽��ϴ�.


		\~english
		<a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a>	 function.
		It is changed to newValue if the conditions are satisfied, after comparing the existing value that has been loaded at DBCacheServer and compareValue.

		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveSetValueIfSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveSetValueIfFailed (CCallbackArgs args)

		Exclusive DB Cache Client Callback:
		- IDbCacheClientDelegate2::OnSomeoneSetValue (CCallbackArgs& args)

		\param rootTableName it is name of root.
		\param rootUUID it is UUID of root.
		\param nodeUUID it is UUID of node.
		\param propertyName it is name of attribute that sets values.
		\param newValue It is a value that will be substituted in case relation condition is satisfied.
		\param compareType it is the type of relation condition.
		\param compareValue It is a value that will be compared with the existing value.
		\param tag Verifying value about request that user need to put in. When you callback, it go throuth m_tag in CCallbackArg.
		\param messageToLoader It is a user random message that is sent to a sole owner of the relevant data. The sole owner has this through args.m_loadResults[index].m_message of IDbCacheClientDelegate2::OnSomeoneAddData.


		\~chinese
		��<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??������?��</a>%������
		?��?��DBCacheServer��������??compareValue��������?��������??��? newValue��

		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveSetValueIfSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveSetValueIfFailed (CCallbackArgs args)

		?�����DB Cache Client Callback:
		- IDbCacheClientDelegate2::OnSomeoneSetValue (CCallbackArgs& args)
		\param rootTableName root table ��٣?��
		\param rootUUID ��root��UUID��
		\param nodeUUID ��node��UUID��
		\param propertyName �setting��?��?��٣��
		\param newValue �?��?����������?��?��������?��
		\param compareType ��??��type��
		\param compareValue ?����??����?��
		\param tag ?��?����?�?����???����???��\ref CcallbackArg%��m_tag��
		\param messageToLoader ???? ��??��?��?����������?���ӡ�?����?IDbCacheClientDelegate2::OnSomeoneAddData�� args.m_loadResults[index].m_message������ӡ�


		\~japanese
		<a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> Ѧ���Ǫ���
		DBCacheServer�˫�?�ɪ���ƪ�����?������ compareValue�����򪷡�?���?�������� newValue��?�ڪ��ު���

		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveSetValueIfSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveSetValueIfFailed (CCallbackArgs args)

		?����DB Cache Client Callback:
		- IDbCacheClientDelegate2::OnSomeoneSetValue (CCallbackArgs& args)

		\param rootTableName root��?�֫��٣��Ǫ���
		\param rootUUID root�� UUID�Ǫ���
		\param nodeUUID node�� UUID�Ǫ���
		\param propertyName ���� setting����?����٣��Ǫ���
		\param newValue ����?���?���������檷��������������Ǫ���
		\param compareType ����?�� type�Ǫ���
		\param compareValue ?���������򪹪����Ǫ���
		\param tag ��������?���ƫ�?��������������ܬ�����Ǫ�����?��Ыë��� \ref CCallbackArg ��� m_tag������ު���
		\param messageToLoader ��?��?����?���Ԥ����?��?�����ë�?���Ǫ���?��� IDbCacheClientDelegate2::OnSomeoneAddData�� args.m_loadResults[index].m_message���ת��ƪ����?ӹ����ު���

		\~
		*/
		virtual void RequestNonExclusiveSetValueIf(String rootTableName, Guid rootUUID, Guid nodeUUID, String propertyName, CVariant newValue, ValueCompareType compareType, CVariant compareValue, intptr_t tag, const ByteArray &messageToLoader=ByteArray()) = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >������ ������ �����ϱ�</a> ����Դϴ�.

		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveModifyValueSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveModifyValueFailed (CCallbackArgs args)

		���� ���� DB Cache Client Callback:
		- IDbCacheClientDelegate2::OnSomeoneModifyValue (CCallbackArgs& args)

		\param rootTableName root���̺��� �̸��Դϴ�.
		\param rootUUID root�� UUID�Դϴ�.
		\param nodeUUID node�� UUID�Դϴ�.
		\param propertyName ���� setting�� �Ӽ��� �̸��Դϴ�.
		\param operType ���� Ÿ��
		\param value �����ų ���Դϴ�.
		\param tag ��û �ĺ��� ���� ����� ���� �������Դϴ�. �ݹ� �� \ref CCallbackArg �� m_tag�� ���� �����޽��ϴ�.
		\param messageToLoader �ش� �������� �����ڿ��� �����ϴ� �޽����Դϴ�. �����ڴ� IDbCacheClientDelegate2::OnSomeoneModifyValue�� args.m_loadResults[index].m_message�� ���� �̸� ���޹޽��ϴ�.


		\~english
		<a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> function.

		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveModifyValueSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveModifyValueFailed (CCallbackArgs args)

		Exclusive DB Cache Client Callback:
		- IDbCacheClientDelegate2::OnSomeoneModifyValue (CCallbackArgs& args)

		\param rootTableName it is name of root table.
		\param rootUUID it is UUID of root.
		\param nodeUUID it is UUID of node.
		\param propertyName it is name of attribute that sets values.
		\param operType it is the type of calculation.
		\param value it is value that is going to be applied.
		\param tag Verifying value about request that user need to put in. When you callback, it go throuth m_tag in CCallbackArg.
		\param messageToLoader It is a user random message that is sent to a sole owner of the relevant data. The sole owner has this through args.m_loadResults[index].m_message of IDbCacheClientDelegate2::OnSomeoneAddData.


		\~chinese
		��<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??������?��</a>%������

		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveModifyValueSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveModifyValueFailed (CCallbackArgs args)

		?�����DB Cache Client Callback:
		- IDbCacheClientDelegate2::OnSomeoneModifyValue (CCallbackArgs& args)
		\param rootTableName root table ��٣?��
		\param rootUUID ��root��UUID��
		\param nodeUUID ��node��UUID��
		\param propertyName �setting��?��?��٣��
		\param operType ?ߩ����
		\param value �������?��
		\param tag ?��?����?�?����???����???��\ref CcallbackArg%��m_tag��
		\param messageToLoader ???? ��??��?��?����������?���ӡ�?����?IDbCacheClientDelegate2::OnSomeoneAddData�� args.m_loadResults[index].m_message������ӡ�


		\~japanese
		<a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> Ѧ���Ǫ���

		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveModifyValueSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveModifyValueFailed (CCallbackArgs args)

		?����DB Cache Client Callback:
		- IDbCacheClientDelegate2::OnSomeoneModifyValue (CCallbackArgs& args)

		\param rootTableName root��?�֫��٣��Ǫ���
		\param rootUUID root�� UUID�Ǫ���
		\param nodeUUID node�� UUID�Ǫ���
		\param propertyName ���� setting����?����٣��Ǫ���
		\param operType ��ߩ������
		\param value ���Ī��������Ǫ���
		\param tag ��������?���ƫ�?��������������ܬ�����Ǫ�����?��Ыë��� \ref CCallbackArg ��� m_tag������ު���
		\param messageToLoader ��?��?����?���Ԥ����?��?�����ë�?���Ǫ���?��� IDbCacheClientDelegate2::OnSomeoneAddData�� args.m_loadResults[index].m_message���ת��ƪ����?ӹ����ު���

		\~
		*/
		virtual void RequestNonExclusiveModifyValue(String rootTableName, Guid rootUUID, Guid nodeUUID, String propertyName, ValueOperType operType, CVariant value, intptr_t tag, const ByteArray &messageToLoader=ByteArray()) = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_isolate_overview" >DB cache�� �ٷ�� �����͸� DB�� ���� �＼���ϱ�</a> ����Դϴ�.
		DB cache�� ������� data tree�� ���� DB �＼���� ���� ������ �� �ֵ��� ��û�մϴ�.
		DB cache�� ����ڰ� �����ϰ� ������ �� �ֵ��� ĳ���ϴ� Data tree �� unload �մϴ�.

		isolate ��û�� �����ϸ� DB cache �� data tree �� ���� �������� �ʽ��ϴ�.
		����ڴ� �� �Լ��� ȣ���� �� data �� ���� �＼���մϴ�.
		����ڴ� �۾��� �Ϸ��ϸ� RequestDeisolateData �� ȣ���Ͽ� DB cache �� �۾��� �������� �˷��� �մϴ�.

		- DB cache ���� data tree �� ���������� isolate �Ǹ� OnIsolateDataSuccess �̺�Ʈ�� �߻��մϴ�.
		- data tree �� �̹� isolate �����̰ų� unload �� �����ϸ� OnIsolateDataFailed �̺�Ʈ�� �߻��մϴ�.

		\param rootUUID isolate�ϰ��� �ϴ� data tree�� root UUID�Դϴ�.
		\param rootTableName isolate�ϰ��� �ϴ� data tree�� root���̺��� �̸��Դϴ�.
		\param [out] outSessionGuid session �ĺ����Դϴ�.

		\~english
		<a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_isolate_overview" >DB directly has access to data that DB cache deals with </a> function.
		It requests access to data tree that DB cache is using by direct DB access.
		DB cache unloads data tree that is the process of caching for user��s safe access.

		If isolate request is successful, DB cache will never have access to data tree.
		After calling this function, a user has access to data directly.
		Once works are done, a user must inform DB cache by calling RequestDeisolateData that works have been done.

		- If data tree is successfully isolated from DB cache, OnIsolateDataSuccess event will occur.
		- If data tree has been already isolated or unloading fails, OnIsolateDataFailed event will occur.

		\param rootUUID It is root UUID of data tree that is going to be isolated.
		\param rootTableName It is root table name of data tree that is going to be isolated.
		\param [out] outSessionGuid session identifier.

		\~chinese
		<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_isolate_overview" >DB����??DB cache������?��</a> ������
		?ϴDB cache��?��?DB??����??�����������data tree��
		?��?��?����??��DB cache unload���Caching��Data tree��

		����isolate ?ϴ����?DB cache?��?? data tree��
		��?�������?��ʦ�����??data��
		��??��������������� RequestDeisolateData ����DB cacheͱ��?�����¡�

		- �DB cache �� data tree ����?�� isolate ��??�� OnIsolateDataSuccess ���졣
		- ����data tree �?�� isolate ??�� unload ��????��OnIsolateDataFailed ���졣

		\param rootUUID �?�� isolate�� data tree�� root UUID��
		\param rootTableName �?��isolate�� data tree�� root Table٣��
		\param [out] outSessionGuid session ??��

		\~japanese
		<a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_isolate_overview" >DB cache���ê��?����DB�����ȫ�������</a>Ѧ���Ǫ���
		DB cache���������data tree������DB�����������ת������ΪǪ���誦����몷�ު���
		DB cache�ϫ�?������������ΪǪ���誦��Caching���ƪ���Data tree��unload ���ު���

		isolate��몬�������DB cache��data tree�����Ϊ��ު���
		��?���Ϫ���??�������󪷪���, data�����ȫ����������ު���
		��?������������������� RequestDeisolateData�������󪷪� DB cache���������������骻�ʪ���Ъʪ�ު���

		- DB cache��data tree�������ܪ�isolate������OnIsolateDataSuccess���٫�Ȫ�?�檷�ު���
		- data tree��?��isolate?���Ǫ��ê�unload�����������OnIsolateDataFailed ���٫�Ȫ�?�檷�ު���

		\param rootUUID isolate���誦�Ȫ��� data tree��root UUID�Ǫ���
		\param rootTableName isolate���誦�Ȫ���data tree��root��?�֫��٣��Ǫ���
		\param [out] outSessionGuid session��ܬ�Ǫ���
		*/
		virtual bool RequestIsolateData(Guid rootUUID, String rootTableName, Guid &outSessionGuid) = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_isolate_overview" >DB cache�� �ٷ�� �����͸� DB�� ���� �＼���ϱ�</a> ����Դϴ�.
		isolate �� data tree �� deisolate �ϵ��� ��û�մϴ�.

		deisolate ��û�� �����ϸ� �ٽ� DB cache �� load & save �� �� �ִ� ���°� �˴ϴ�.

		- DB cache ���� data tree �� ���������� deisolate �Ǹ� OnDeisolateDataSuccess �̺�Ʈ�� �߻��մϴ�.
		- data tree �� �̹� isolate �����̰ų� deisolate �� �����ϸ� OnDeisolateDataFailed �̺�Ʈ�� �߻��մϴ�.

		\param rootUUID deisolate�ϰ��� �ϴ� data tree�� root UUID�Դϴ�.
		\param rootTableName deisolate�ϰ��� �ϴ� data tree�� root���̺��� �̸��Դϴ�.
		\param [out] outSessionGuid session �ĺ����Դϴ�.

		\~english
		<a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_isolate_overview" >DB directly has access to data that DB cache deals with </a> function.
		Request for deisolating data tree that has been isolated.

		If deisolating request is successful, DB cache will be ready to be loaded & saved.

		- If data tree is successfully deisolated from DB cache, OnDeisolateDataSuccess event will occur.
		- If data tree has been already isolated or deisolating fails, OnDeisolateDataFailed event will occur.

		\param rootUUID It is root UUID of data tree that is going to be deisolated.
		\param rootTableName It is root table name of data tree that is going to be deisolated.
		\param [out] outSessionGuid session identifier.

		\~chinese
		<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_isolate_overview" >DB����??DB cache������?��</a> ������
		?ϴ?�?��isolate �� data tree ?�� deisolate��

		deisolate ?ϴ������ DB cache ʦ�?�� load & save ��

		- �DB cache �� data tree ����?���� deisolate ???�� OnDeisolateDataSuccess ���졣
		- ����data tree�?�� isolate ??�� deisolate ��????�� OnDeisolateDataFailed ���졣

		\param rootUUID �?��deisolate�� data tree�� root UUID��
		\param rootTableName �?��deisolate�� data tree�� root Table٣��
		\param [out] outSessionGuid session ??��

		\~japanese
		<a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_isolate_overview" >DB cache���ê��?����DB�����ȫ�������</a>Ѧ���Ǫ���
		Isolate����data tree��deisolate����誦����몷�ު���

		Deisolate����몬��������DB cache��load & save�Ǫ���?���˪ʪ�ު���

		- DB cache��data tree�������ܪ�deisolate������OnDeisolateDataSuccess���٫�Ȫ�?�檷�ު���
		- data tree��?��isolate��?���Ǫ��ê���deisolate�����������OnDeisolateDataFailed ���٫�Ȫ�?�檷�ު���

		\param rootUUID deisolate���誦�Ȫ��� data tree��root UUID�Ǫ���
		\param rootTableName deisolate���誦�Ȫ��� data tree��root��?�֫��٣��Ǫ���
		\param [out] outSessionGuid session��ܬ䫪Ǫ���
		*/
		virtual bool RequestDeisolateData(Guid rootUUID, String filterText, Guid &outSessionGuid) = 0;

		/**
		\~korean
		�������� �ֽ� ���� ���� ��´�.
		\param sessionGuid RequestExclusiveLoadData �� RequestExclusiveLoadNewData ���� ���� session guid
		\return ���� ������ ��ü. �纻�̹Ƿ� ���� ��ü�� ���� �����ص� ���� DB�� ������Ʈ���� ���Ѵ�.
		���� DB�� ������Ʈ�Ϸ��� ������ �� ��ü�� UpdateData �Լ��� ���� ������ �����ؾ� �Ѵ�.

		\~english
		Gets the latest status value of data
		\param sessionGuid Session guid obtained from RequestExclusiveLoadData or RequestExclusiveLoadNewData
		\return Obtained object It does not update to actual DB because it is a copy
		If you want to update it to actual DB, you need send it to server through UpdateData function.

		\~chinese
		?��?��������???��
		?\param sessionGuid RequestExclusiveLoadData��RequestExclusiveLoadNewData�����session guid��
		\return ?����?����?�ڡ���?�����⣬��??����?��?�����?߾?��??DB��
		��߾?��??DB��?�������������?����?UpdateData��??������?�

		\~japanese
		��?��������?��������ު���
		\param sessionGuid RequestExclusiveLoadData��RequestExclusiveLoadNewData���������session guid
		\return �𪿫�?�����֫������ȡ�����?�ʪΪ��𪿫��֫������Ȫ�����?�ڪ��ƪ�?�DB�˫��ë׫�?�Ȫ���ު���
		?�DB�˫��ë׫�?�Ȫ��몿��˪�?�ڪ����������֫������Ȫ�UpdateData??���ת���?��?��?�ꪷ�ʪ���Ъʪ�ު���

		\~
		*/
		virtual CLoadedData2Ptr GetClonedLoadedDataBySessionGuid(Guid sessionGuid) = 0;

		/**
		\~korean
		�� \ref GetClonedLoadedDataBySessionGuid �� ���� �Լ��̳�, rootUUID�� ã�´�.
		�ڼ��� ������ \ref GetClonedLoadedDataBySessionGuid �� ����.
		\return ���� ������ ��ü. �纻�̹Ƿ� ���� ��ü�� ���� �����ص� ���� DB�� ������Ʈ���� ���Ѵ�.
		���� DB�� ������Ʈ�Ϸ��� ������ �� ��ü�� UpdateData �Լ��� ���� ������ �����ؾ� �Ѵ�.

		\~english TODO:translate needed.
		It��s the same function as the above \ref GetClonedLoadedDataBySessionGuid, but it is searched with rootUUID. 
		Check out \ref GetClonedLoadedDataBySessionGuid. For a detailed explanation, refer to \ref GetClonedLoadedDataBySessionGuid
		\Obtained data object. Since this is a copy, it is not updated in the real DB even though you transform the value of the obtained object. 
		If you want to update it in the actual DB, you have to transmit the object through the UpdateData function. 

		\~chinese
		?߾����\ref GetClonedLoadedDataBySessionGuid%��?����?����rootUUID??��
		???٥??��\ref GetClonedLoadedDataBySessionGuid%��
		\return ?����?��?�ڡ���?�����⣬��??����?��?�����?߾?��??DB��
		��߾?��??DB��?�������������?����?UpdateData��??������?�

		\~japanese
		߾����\ref GetClonedLoadedDataBySessionGuid���Ҫ�??�Ǫ�����rootUUID�������ު���
		�٪����ϡ�\ref GetClonedLoadedDataBySessionGuid ��?�š�
		\return �𪿫�?�����֫������ȡ�����?�ʪΪ��𪿫��֫������Ȫ�����?�ڪ��ƪ�?�DB�˫��ë׫�?�Ȫ���ު���
		?�DB�˫��ë׫�?�Ȫ��몿��˪ϡ�?�ڪ��������֫������Ȫ�UpdateData??���ת���?��?��?�ꪷ�ʪ���Ъʪ�ު���

		\~
		*/
		virtual CLoadedData2Ptr GetClonedLoadedDataByUUID(Guid rootUUID) = 0;

		/**
		\~korean
		�� Ŭ���̾�Ʈ�� HostID�� ��´�.

		\~english
		Obtain HostID of this client

		\~chinese
		?�����ʫ��Host ID��

		\~japanese
		���Ϋ��髤����Ȫ�HostID����ު���
		\~
		*/
		virtual HostID GetLocalHostID() = 0;

		/**
		\~korean
		�� DB cache client2�� DB cache server2�� �α׿�(����)�� �Ϸ�� �������� ���θ� ���Ѵ�.
		\return �α��� �Ǿ� ������ true.

		\~english
		Find out DB cache client2 has got authentication from DB cache server2 whether or not.

		\~chinese
		ϴ�DB cache client2��������?��??��DB cache server2��???��?����

		\~japanese
		����DB cache client2��DB cache server2�˫�����(��?)���������쪿?���ʪΪ��ɪ�����ϴ��ު���
		\return �����󪵪�ƪ����true

		\~
		*/
		virtual bool IsLoggedOn() = 0;

	};
	/**  @} */

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
#endif