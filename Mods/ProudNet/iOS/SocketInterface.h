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

namespace Proud
{
	class CSocket;

#ifdef _WIN32

	/** \addtogroup net_group
	*  @{
	*/

	/** 
	\~korean
	SocketSelectContext class
	- ���� ������ Sample�� SimpleHttpConnect�� �����Ͻø� �˴ϴ�.
	- socket�� select() non-block model �� ���� �뵵
	- ����: Wait ȣ�� �Ŀ��� FD_SET�� ������ �ٲ��. ���� �� ��ü�� 1ȸ������ ������ �Ѵ�. 
	- Win32������ �����ϴ� ����Դϴ�. iOS, linux������ �̰� ��� ::poll()�� ����Ͻʽÿ�.

	\~english TODO:translate needed.
	SocketSelectContext class
-
	- This it for select() non-block model of socket
	- Note: After Wait calling, informationf of FD_SET will be changed. So this object has to use for once.
	- This class can work only in Win32 platform. Use ::poll() in iOS or Linux.

	\~chinese
	SocketSelectContext class
	- ����۰�����?��sample��SimpleHttpConnect?ʦ��
	- ?��socket��select() non-block model����Բ��
	- ���Wait��У���?��?FD_SET��?黡����?��������������
	- ���Win32ʦ��򥡣�iOS, linux����::poll()?����??��

	\~japanese
	\~
	*/
	class SocketSelectContext
	{
	public:
		SocketSelectContext() {}

		virtual void AddWriteWaiter(CSocket& socket) = 0;
		virtual void AddExceptionWaiter( CSocket& socket ) = 0;
		virtual void Wait(uint32_t miliSec) = 0;
		virtual bool GetConnectResult(CSocket& socket, SocketErrorCode& outCode) = 0;

		PROUD_API static SocketSelectContext *New();
	};
#endif // _WIN32

	/** 
	\~korean
	Socket Delegate Interface 
	- Socket�� ���õ� ������ OnSocketWarning �Լ����� ������ �ִ�. 

	\~english
	Socket Delegate Interface 
	- You can receive Socket related error from OnSocketWarning function.

	\~chinese
	Socket Delegate Interface 
	- Socket��?��??ʦ��OnSocketWarning��?����⥡�

	\~japanese
	\~
	*/
	class ISocketDelegate
	{
	public:
		virtual ~ISocketDelegate() {}
		virtual void OnSocketWarning(CSocket* soket, String msg) = 0;
	};

	/** 
	\~korean
	CSocket class 
	- Proud�� NetClient �� ���� �ʰ� �ܺ��� Server�� http�� �����Ҷ� ���� �����ϴ�.
	- ���������� Proud::FastSocket �� ����Ѵ�. 

	\~english
	CSocket class 
	- It is useful when you access external Server or http without NetClient of ProudNet.
	- Use Proud::FastSocket internally

	\~chinese
	CSocket class
	- ������Proud��NetClient��??��ݻ��Server���http��?��������?���ġ�
	- ����?ݻ Proud::FastSocket%��

	\~japanese
	\~
	*/
	class CSocket
	{
	public:
		virtual ~CSocket(){}

	public:
		virtual bool Bind() = 0;
		virtual bool Bind(int port) = 0;
		virtual bool Bind( const PNTCHAR* addr, int port ) = 0;

		/** 
		\~kore?an
		Connect �Ѵ�. 
		\param hostAddr host �� �ּ� 
		\param hostPort host �� port 
		
		\~english TODO:translate needed.
		
		\~chinese
		?��connect��
		\param hostAddr host���򣡣
		\param hostPort host��port��

		\~japanese
		\~
		*/
		virtual SocketErrorCode Connect(String hostAddr, int hostPort) = 0;

#if !defined(_WIN32)
// 		virtual SocketErrorCode NonBlockedRecvFrom(int length) = 0;
// 		virtual SocketErrorCode NonBlockedSendTo( BYTE* data, int count, AddrPort sendTo ) = 0;
// 		virtual SocketErrorCode NonBlockedRecv(int length) = 0;
// 		virtual SocketErrorCode NonBlockSend( BYTE* data, int count) = 0;
#else
		/**
		\~korean 
		UDP socket
		- Recv�� Issue�Ѵ�.
		\param length ������ ũ��
		\return ���� Error�� �������ݴϴ�. SocketErrorCode_Ok �̸� ����

		\~english TODO:translate needed.

		\~chinese
		UDP socket
		- ��Recv?��issue��
		\param length buffer����᳡�
		\return ����socket��Error��SocketErrorCode_Ok ��?���ȡ�

		\~japanese
		\~
		*/
		virtual SocketErrorCode IssueRecvFrom(int length) = 0;
		
		/**
		\~korean 
		UDP socket
		- Send�� Issue�Ѵ�.
		\param data ���� data�� �迭
		\param count �迭�� ũ��
		\param sendTo ���� �ּ�
		\return ���� Error�� �������ݴϴ�. SocketErrorCode_Ok �̸� ����

		\~english TODO:translate needed.

		\~chinese
		UDP socket
		- ��Send?��Issue��
		\param data �?����data��??��
		\param count ??����᳡�
		\param sendTo �?�����򣡣
		\return ����socket��Error��SocketErrorCode_Ok ��?���ȡ�

		\~japanese
		\~
		*/
		virtual SocketErrorCode IssueSendTo( uint8_t* data, int count, AddrPort sendTo ) = 0;
		
		/**
		\~korean 
		TCP socket
		- Recv�� Issue�Ѵ�.
		\param length ������ ũ��
		\return ���� Error�� �������ݴϴ�. SocketErrorCode_Ok �̸� ����

		\~english TODO:translate needed.

		\~chinese
		UDP socket
		- ��Recv?��issue��
		\param length buffer����᳡�
		\return ����socket��Error��SocketErrorCode_Ok ��?���ȡ�

		\~japanese
		\~
		*/	
		virtual SocketErrorCode IssueRecv(int length) = 0;

		/**
		\~korean 
		TCP socket
		- Send �� Issue �Ѵ�.
		\param data ���� data �� �迭
		\param count �迭�� ũ��
		\return ���� Error �� �������ݴϴ�. SocketErrorCode_Ok�̸� ����

		\~english TODO:translate needed.

		\~chinese
		UDP socket
		- ��Send?��Issue��
		\param data �?����data��??��
		\param count ??����᳡�
		\return ����socket��Error��SocketErrorCode_Ok ��?���ȡ�

		\~japanese
		\~
		*/
		virtual SocketErrorCode IssueSend( uint8_t* data, int count) = 0;

		/**
		\~korean
		async issue�� ����� ��ٸ���.
		- ���� �ƹ��͵� �Ϸ���� �ʾ����� null�� �����Ѵ�.
		- ���� �Ϸ� ���� �Ǵ� ���� ���� ���� ���а� ����� ��ü�� �����ϵ� m_errorCode�� ä���� �ִ�.
		\param waitUntilComplete �Ϸ�ɶ����� ��ٸ� ������ �����Ѵ�.
		\param ret ��� \ref OverlappedResult ����
		\return �����̸� true, �����̸� false����

		\~english TODO:translate needed.

		\~chinese
		����async issue��?����
		- �?Դ?��?����?����null��
		- ��������?�����?��socket??����?����?������?��ӣ��??��m_errorCode��
		\param waitUntilComplete ?�����������?�֡�
		\param ret ?��?��\ref OverlappedResult%��
		\return ������?true����?��?����false��

		\~japanese
		\~
		*/
		virtual bool GetRecvOverlappedResult(bool waitUntilComplete, OverlappedResult &ret) = 0;
		
		/**
		\~korean
		async issue�� ����� ��ٸ���.
		- ���� �ƹ��͵� �Ϸ���� �ʾ����� null�� �����Ѵ�.
		- ���� �Ϸ� ���� �Ǵ� ���� ���� ���� ���а� ����� ��ü�� �����ϵ� m_errorCode�� ä���� �ִ�.
		\param waitUntilComplete �Ϸ�ɶ����� ��ٸ� ������ �����Ѵ�.
		\param ret ��� \ref OverlappedResult ����
		\return �����̸� true, �����̸� false����

		\~english TODO:translate needed.

		\~chinese
		��async issue��?����
		- �?Դ?��?����?����null��
		- ��������?�����?��socket??����?����?������?��ӣ��??��m_errorCode��
		\param waitUntilComplete ?�����������?�֡�
		\param ret ?��?��\ref OverlappedResult%��
		\return ������?true����?��?����false��

		\~japanese
		\~
		*/
		virtual bool GetSendOverlappedResult(bool waitUntilComplete, OverlappedResult &ret) = 0;

		
#endif
        
		/** 
		\~korean 
		������ �ּҸ� �����´�. 
		
		\~english TODO:translate needed.

		\~chinese
		��?socket���򣡣

		\~japanese
		\~
		*/
		virtual AddrPort GetSockName() = 0;

		/** 
		\~korean 
		peer �� ���� ������ �ּҸ� �����´�. 
		
		\~english TODO:translate needed.

		\~chinese
		��??peer��socket�򣡣

		\~japanese
		\~
		*/
		virtual AddrPort GetPeerName() = 0;

		/** 
		\~korean 
		��ſ� ���Ͽ� ��ŷ ��带 ����� ������ �����Ѵ�. 
		
		\~english TODO:translate needed.

		\~chinese
		???������������blockingټ�ҡ�

		\~japanese
		\~
		*/
		virtual void SetBlockingMode(bool isBlockingMode) = 0;

		/** 
		\~korean 
		recv ������ �����͸� ���´�. 
		
		\~english TODO:translate needed.

		\~chinese
		?��recv buffer���?��

		\~japanese
		\~
		*/
		virtual uint8_t* GetRecvBufferPtr() = 0;
		
		/** 
		\~korean 
		recv host�� ip Address�� ���´�. 
		
		\~english TODO:translate needed.

		\~chinese
		?��recv host��ip Address��

		\~japanese
		\~
		*/
		PROUD_API static String GetIPAddress(String hostName);

		/** 
		\~korean 
		CSocket ��ü�� �����Ѵ�. 
		\param auxSocket socket��ü
		\param dg ������ �̺�Ʈ�� ���� ��ü. \ref ISocketDelegate �� ����

		\~english TODO:translate needed.

		\~chinese
		���� CSocket%?�ڡ�
		\param auxSocket socket?�ڡ�
		\param dg ���socket��event��?�ڡ�?��\ref ISocketDelegate%��

		\~japanese
		\~
		*/
	//	PROUD_API static CSocket *New(SOCKET auxSocket,ISocketDelegate* dg);

		/** 
		\~korean 
		CSocket ��ü�� �����Ѵ�. 
		\param type ������ Type�� ���Ѵ�.  
		\param dg ������ �̺�Ʈ�� ���� ��ü. \ref ISocketDelegate �� ����

		\~english TODO:translate needed.

		\~chinese
		���� CSocket%?�ڡ�
		\param type ���socket��Type��
		\param dg ���socket��event��?�ڡ�?��\ref ISocketDelegate%��

		\~japanese
		\~
		*/
		PROUD_API static CSocket *New(SocketType type, ISocketDelegate *dg);
	};

	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
