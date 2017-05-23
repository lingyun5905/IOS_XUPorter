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

#if defined(__unix__)
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#elif defined(_WIN32)
#include <winsock2.h>
#include <ws2ipdef.h>
#pragma comment(lib,"Ws2_32.lib")
#else
#include <arpa/inet.h>
#include <errno.h>
#endif

#if defined(__ORBIS__)
#include "OrbisIPv6.h"
#endif

#ifdef PF_MAX
#undef PF_MAX
#endif

#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup net_group
	*  @{
	*/
	class CFastSocket;

	struct ExtendSockAddr;
	struct NamedAddrPort;

	/**

	\~korean
	���� ���� �ڵ�

	\~english
	Socket Error Code

	\~chinese
	Socket ??��?

	\~japanese
	�����ëȫ���?��?��
	\~
	*/
	enum SocketErrorCode
	{
		SocketErrorCode_Ok = 0,
		// EINTR�� WSAEINTR�� ���� �ٸ� ���̴�. ���� Win32������ EINTR�� ���� �ȵȴ�.
		// ����, ��¿ �� ���� �Ʒ��� ���� ���� �ٸ��� ������ ���ۿ� ����.
#if !defined(_WIN32)
		SocketErrorCode_Error = -1,
		SocketErrorCode_Timeout = ETIMEDOUT,
		SocketErrorCode_ConnectionRefused = ECONNREFUSED,
		SocketErrorCode_ConnectResetByRemote = ECONNRESET,
		SocketErrorCode_AddressNotAvailable = EADDRNOTAVAIL,
		SocketErrorCode_NotSocket = ENOTSOCK,
		SocketErrorCode_WouldBlock = EWOULDBLOCK,
		SocketErrorCode_AccessError = EACCES,
		SocketErrorCode_InvalidArgument = EINVAL,
		SocketErrorCode_Intr = EINTR, // EINTR in linux
		SocketErrorCode_InProgress = EINPROGRESS, // operation�� �̹� �������̴�.
		SocketErrorCode_Again = EAGAIN, // win32������ would-block�� ��ü.
		SocketErrorCode_AlreadyIsConnected = EISCONN,
		SocketErrorCode_AlreadyAttempting = EALREADY, // The socket is nonblocking and a previous connection attempt has not yet been completed.
		SocketErrorCode_NetUnreachable = ENETUNREACH,
#else
		SocketErrorCode_Error = SOCKET_ERROR,
		SocketErrorCode_Timeout = WSAETIMEDOUT,
		SocketErrorCode_ConnectionRefused = WSAECONNREFUSED,
		SocketErrorCode_ConnectResetByRemote = WSAECONNRESET,
		SocketErrorCode_AddressNotAvailable = WSAEADDRNOTAVAIL,
		SocketErrorCode_NotSocket = WSAENOTSOCK,
		SocketErrorCode_ShutdownByRemote = WSAEDISCON,	// FD_CLOSE or FD_SEND������ �̺�Ʈ
		SocketErrorCode_WouldBlock = WSAEWOULDBLOCK,
		SocketErrorCode_IoPending = WSA_IO_PENDING,
		SocketErrorCode_AccessError = WSAEACCES,
		SocketErrorCode_OperationAborted = ERROR_OPERATION_ABORTED,
		SocketErrorCode_InvalidArgument = WSAEINVAL,
		SocketErrorCode_Intr = WSAEINTR, // EINTR in linux
		SocketErrorCode_InProgress = WSAEINPROGRESS, // operation�� �̹� �������̴�.
		SocketErrorCode_AlreadyIsConnected = WSAEISCONN,
		SocketErrorCode_AlreadyAttempting = WSAEALREADY,
		SocketErrorCode_Cancelled = WSAECANCELLED,
		SocketErrorCode_NetUnreachable = WSAENETUNREACH,
#endif
	};

	enum ShutdownFlag
	{
#if !defined(_WIN32)
		ShutdownFlag_Send = SHUT_WR,
		ShutdownFlag_Receive = SHUT_RD,
		ShutdownFlag_Both = SHUT_RDWR,
#else
		ShutdownFlag_Send = SD_SEND,
		ShutdownFlag_Receive = SD_RECEIVE,
		ShutdownFlag_Both = SD_BOTH,
#endif
	};

	static const int PN_IPV6_ADDR_LENGTH = 16;

	// ��ȿ�� ���� �ڵ鰪.
#ifdef _WIN32
	// ���������� invalid fd = INVALID_SOCKET = 0�̴�.
	const int InvalidSocket = 0; // INVALID_SOCKET
#else 
	// unix������ ������ ��ȿ ���� fd ���̴�.
	const int InvalidSocket = -1;
#endif

	/**
	\~korean
	IP, Port �ĺ���

	\~english
	IP, Port Identifier

	\~chinese
	IP, Port??�

	\~japanese
	IP����?����ܬ�
	\~
	*/
	struct PROUD_API AddrPort
	{

		/* PN_ALIGN(1) ��,  __declspec(align) �� 1����Ʈ�� ��� ���� �� VC++������ "4 �̸��� �����Ѵ�"�� warning�� ���.
		���� align 4�� �ϵ�, ����Ǵ� �������� 4��� ũ��� �����ϵ��� �Ѵ�.
		� �����Ϸ��� �⺻ align 8�̹Ƿ� align 4�� ���־�� �Ѵ�.
		*/
		union PN_ALIGN(4) ExtendAddr
		{
			// ���� �� ����ü ���� ������ �Ժη� �߰� ���� ���ʽÿ�.
			struct PN_ALIGN(4)
			{
				uint8_t  __dummy[PN_IPV6_ADDR_LENGTH - sizeof(uint32_t)]; // 12����Ʈ => 4��� ����
				uint32_t v4; // 4����Ʈ => 4��� ����
			};

			uint16_t v6Short[PN_IPV6_ADDR_LENGTH / 2]; // 16����Ʈ => 4��� ����
			uint8_t  v6Byte[PN_IPV6_ADDR_LENGTH]; // 16����Ʈ => 4��� ����
		} m_addr;

		/**
		\~korean
		��Ʈ ��ȣ
		- native endian�̰�, network endian�� �ƴϴ�. �� socket �Լ� htons�� ntohs�� ���� ��ȯ�� �ʿ䰡 ���� �״�� ����ص� �ȴ�.

		\~english
		Port Number
		- It's native endian, not network endian. So it can be used as-is without converting it through htons or ntohs.

		\~chinese
		ӮϢ??
		- ��native endian�������network endian�������?��?�������?socket��?htons��ntohs??���ʦ��������ġ�

		\~japanese
		��?����?
		? native endian�ǡ�network endian�ǪϪ���ު���?����socket??��htons��ntohs���ת�?��������驪��ʪ����Ϊު��Ūêƪ��ު��Ǫ���		

		\~
		*/
		uint16_t m_port;

		// #TODO �Ʒ� �ּ����� code review �� doxygen ���·� ���� �ؾ� �ȴ�.

		/**
		IPv4 �ּҰ� ���������, true�� �����մϴ�.
		RFC 4291 ���� ���� �ϰ� �ִ�, ǥ�� IPv4 ǥ�� ����� ���½��ϴ�.
		��: 11.22.33.44�� ::ffff:11.22.33.44 �������� ����Ǹ�, �̶� �� �Լ��� true�� �����մϴ�.
		*/
		bool IsIPv4MappedIPv6Addr() const;

		/*
		RFC 4291 ���� ���� �ϰ� �ִ� ǥ�� IPv4 ǥ�� ������� ���� �մϴ�.
		(::1.2.3.4 �� ::FFFF:1.2.3.4 �ΰ��� ������, ������ݿ����� ���� ������� ��� �մϴ�.)
		*/
		void SetIPv4MappedIPv6Address(uint32_t ipv4Address);

		/*
		IPv6 �ּҷ� ���� �մϴ�.
		addr ���ڰ� v4 mapped v6 �ּҷ� ���� �Ǿ� �־ �˴ϴ�.
		*/
		void SetIPv6Address(const in6_addr& addr);

		void SetIPv6Address(const uint8_t* src, const size_t length);

		// ���� ���� �Լ�. ���� ���ʿ�.
		void Synthesize(const uint8_t* pref, const size_t prefLength, const uint32_t v4BinaryAddress);

		/* IPv4 �ּҸ� 32��Ʈ ���̳ʸ��μ� ��´�.
		AddrPort �� RFC 6052, RFC 4291 ���� ���� �ϰ� �ִ� v4 ǥ�� ����� ������ �־�� �մϴ�.

		��: 11.22.33.44 => ::ffff:11.22.33.44

		���� NAT64 �ּ��̰ų�, IPv6 ȣ��Ʈ�� ����Ű�� �ּ��� ���, �� �Լ��� �����մϴ�.

		\param outIPv4Address �� IPv4 �ּҰ�.
		\return ���������� ���� true.
		*/
		bool GetIPv4Address(uint32_t* outIPv4Address) const;

		inline bool IsAddressEqualTo(const AddrPort &a) const
		{
			return memcmp(m_addr.v6Byte, a.m_addr.v6Byte, PN_IPV6_ADDR_LENGTH) == 0 ? true : false;
		}

		/**
		\~korean
		������

		\~english
		Generator

		\~chinese
		�����

		\~japanese
		�����
		\~
		*/
		inline AddrPort()
		{
			memset(m_addr.v6Byte, 0xFF, PN_IPV6_ADDR_LENGTH);
			m_port = 0xFFFF;
		}

		/**
		\~korean
		Socket API �Ķ���� sockaddr_in ����ü�κ��� ���� �����´�.

		\~english
		This method gets a value from Socket API Parameter, sockaddr_in structure.

		\~chinese
		?Socket API??��sockaddr_in?��??��?��

		\~japanese
		Socket API�ѫ��?��?sockaddr_inϰ��?������������?�ߪު���

		\~
		*/
		void ToNativeV4(ExtendSockAddr& out) const;

		void ToNativeV6(ExtendSockAddr& out) const;


		/**
		\~korean
		Socket API �Ķ���� sockaddr_in ����ü���� ���� �ش�.

		\~english
		This method passes a value to Socket API Parameter, sockaddr_in structure.

		\~chinese
		?��Socket API??sockaddr_in?��???��

		\~japanese
		Socket API�ѫ��?��?��sockaddr_inϰ��?������?���ު���

		\~
		*/
		void FromNativeV4(const sockaddr_in& in);

		void FromNativeV6(const sockaddr_in6& in);

		void FromNative(const ExtendSockAddr& in);

		/**
		\~korean
		xxx.xxx.xxx.xxx:xxxx ���ڿ� ����

		\~english
		Extract xxx.xxx.xxx.xxx:XXXX string

		\~chinese
		�����ݬ�� xxx.xxx.xxx.xxx:XXXX

		\~japanese
		xxx.xxx.xxx.xxx:xxxx ���֪��������?��
		\~
		*/
		virtual String ToString() const;

		/**
		\~korean
		xxx.xxx.xxx.xxx ���ڿ� ����

		\~english
		Extract xxx.xxx.xxx.xxx string

		\~chinese
		�����ݬ�� xxx.xxx.xxx.xxx

		\~japanese
		xxx.xxx.xxx.xxx ���֪��������?��
		\~
		*/
		virtual String IPToString() const;

		/**
		\~korean
		IP address ���ڿ��� port�� �Է¹޾�, AddrPort ��ü�� �����մϴ�.
		host name�� ó���� �� �����ϴ�. ��� FromHostNamePort()�� ����ϼ���.
		\param ipAddress IP �ּ� ���Դϴ�. ���� ��� "11.22.33.44"�Դϴ�.
		\param port ��Ʈ ���Դϴ�.

		\~english
		Input an IP address string and a port to get the return value from AddrPort object.
		Host name can��t be processed. Use FromHostNamePort() instead.
		\param ipAddress IP is the address value. Ex. ��11.22.33.44��
		\param port is the port value.

		\~chinese
		��??��IP���ݬ����ӮϢ����AddrPort?�ڡ�
		host name����?�⣬?����FromHostNamePort()��
		\param ipAddress IP��?������"11.22.33.44"��
		\param port ӮϢ?��

		\~japanese
		\param ipAddress IP���ɫ쫹���Ǫ����Ǫ��С�"11.22.33.44"�Ǫ���
		\param port ��?�����Ǫ���

		\~
		*/
		static AddrPort FromIPPortV4(const String& ipAddress, uint16_t port);

		static AddrPort FromIPPortV6(const String& ipAddress, uint16_t port);

		static AddrPort FromIPPort(const int32_t& af, const String& ipAddress, uint16_t port);

		/** Set to Any:port. */
		static AddrPort FromAnyIPPort(const int32_t& af, uint16_t port);

		static AddrPort FromHostNamePort(const String& hostName, uint16_t port);

		/**
		\~korean
		NamedAddrPort ��ü�κ��� ���� �����´�.
		- NamedAddrPort�� host name�� "my.somename.net" ������ ��� �̸� IP address�� ��ȯ�ؼ� �����´�.

		\~english
		This method gets a value from NamedAddrPort object.
		- If host name of NamedAddrPort is in "my.somename.net" format, then this method converts the host name to IP address and returns it.

		\~chinese
		?NamedAddrPort?����?��
		- ?NamedAddrPort��host name��"my.somename.net"��?��?����???��IP address�����ޡ�

		\~japanese
		NamedAddrPort ���֫������Ȫ�����������?�ߪު���
		- NamedAddrPort��host name��"my.somename.net"�����Ǫ������ꡢ�����IP address��?����������?�ߪު���
		\~
		*/
		static AddrPort From(const NamedAddrPort& src);

		/**
		\~korean
		������ IP ��ü. ����Ʈ ���̴�.

		\~english
		Undesignated IP object. It is default value.

		\~chinese
		ڱ�����IP?�ڣ�����??��

		\~japanese
		ڱ���IP���֫������ȡ��ǫի�������Ǫ���
		\~
		*/
		static AddrPort Unassigned;

		/**
		\~korean
		��ε�ĳ��Ʈ �ּҵ� �ƴϰ�, null �ּҵ� �ƴ�, 1�� ȣ��Ʈ�� 1�� ��Ʈ�� ����Ű�� �������� �ּ��ΰ�?

		\~english
		Is it correct address that point 1 port of 1 host instead of broadcast address, null address?

		\~chinese
		����broadcast�򣣬�����null�򣣬���������?���߾��?ӮϢ�������򣣿

		\~japanese
		�֫�?�ɫ��㫹�ȫ��ɫ쫹�Ǫ�ʪ���null���ɫ쫹�Ǫ�ʪ���1�۫��Ȫ�1��?�Ȫ�򦪹���Ȫʫ��ɫ쫹�Ǫ�����
		\~
		*/
		bool IsUnicastEndpoint() const;

		bool IsAnyOrUnicastEndpoint() const;

		static bool IsEqualAddress(const AddrPort& a, const AddrPort& b)
		{
			return a.IsAddressEqualTo(b);
		}

		inline uint32_t Hash() const
		{
			assert(PN_IPV6_ADDR_LENGTH == 16); // �� �Լ��� IPv6 or IPv4 mapped IPv6 �ּҸ� ó���� �� �ִ�.

			uint32_t* p = (uint32_t*)&m_addr;
			uint32_t v = 0;
			for (int i = 0; i < 4; i++)
			{
				v ^= *p;
				p++;
			}
			v ^= m_port;

			return v;
		}

		inline bool operator!=(const AddrPort &rhs) const
		{
			assert(PN_IPV6_ADDR_LENGTH == 16); // �� �Լ��� IPv6 or IPv4 mapped IPv6 �ּҸ� ó���� �� �ִ�.

			if (CompareInt32Array<4>(m_addr.v6Byte, rhs.m_addr.v6Byte) != 0 ||
				m_port != rhs.m_port)
			{
				return true;
			}

			return false;
		}
		inline bool operator==(const AddrPort &b) const
		{
			assert(PN_IPV6_ADDR_LENGTH == 16); // �� �Լ��� IPv6 or IPv4 mapped IPv6 �ּҸ� ó���� �� �ִ�.

			if (CompareInt32Array<4>(m_addr.v6Byte, b.m_addr.v6Byte) == 0 &&
				m_port == b.m_port)
			{
				return true;
			}

			return false;
		}

		inline bool operator<(const AddrPort& b) const
		{
			int compareResult = CompareInt32Array<4>(m_addr.v6Byte, b.m_addr.v6Byte);
			if (compareResult < 0)
				return true;
			if (compareResult > 0)
				return false;
			return m_port - b.m_port < 0;
		}
	};

	/**
	\~korean
	AddrPort�� ��������� m_addr�� ���ڿ��� ����.
	- ���ڿ����� 111.222.111.222 ���� �Ǵ� game.aaa.com ������ �̸��� �� �� �ִ�.
	- AddrPort�� 111.222.111.222 ���¸��� ����� �� �ִ� �Ѱ� ������ �� ����ü�� �ʿ��ѰŴ�.

	\~english
	It's similar to AddrPort but string can be inserted in m_addr.
	- At string, either 111.222.111.222 format or game.aaa.com format can be added.
	- This structure is needed since AddrPort can only store 111.222.111.222 format.

	\~chinese
	?AddrPortt���ģ�ӣ��m_addr�����ݬ����
	- �ݬ����?��111.222.111.222̫�ң����game.aaa.com̫����٣?��
	- ��?AddrPort������?111.222.111.222̫�ң�������?�㡣

	\~japanese
	AddrPort��׾�Ī��ƪ��ު�����m_addr�����֪������ު���
	- ���֪�˪�111.222.111.222�����ު���game.aaa.com���Ҫ�٣�����몳�Ȫ��Ǫ��ު���
	- AddrPort��111.222.111.222�����Ϊ�����Ǫ���Ȫ�����ͣ�Ϊ��ᡢ����ϰ��?����驪Ǫ���
	\~
	*/
	struct NamedAddrPort
	{
		/**
		\~korean
		ȣ��Ʈ �̸�
		- ���ڿ����� 111.222.111.222 ���� �Ǵ� game.aaa.com ������ �̸��� �� �� �ִ�.

		\~english
		Host name
		- At string, either 111.222.111.222 format or game.aaa.com format can be added.

		\~chinese
		���٣
		- �ݬ����ʦ���ʥ111.222.111.222���game.aaa.com̫����٣?��

		\~japanese
		�۫���٣
		- ���֪�˪�111.222.111.222�����ު���game.aaa.com���Ҫ�٣�����몳�Ȫ��Ǫ��ު���
		\~
		*/
		String m_addr;

		/**
		\~korean
		��Ʈ ��

		\~english
		Port Value

		\~chinese
		ӮϢ?

		\~japanese
		��?����
		\~
		*/
		uint16_t m_port;

		/**
		\~korean
		�� �ּ�

		\~english
		Empty Address

		\~chinese
		����

		\~japanese
		�����ɫ쫹
		\~
		*/
		static NamedAddrPort PROUD_API Unassigned;

		/**
		\~korean
		Ư�� hostname, ��Ʈ ��ȣ�κ��� �� ��ü�� �����Ѵ�.

		\~english
		Generate this object from a specific hostname and port number.

		\~chinese
		������hostname��?ӮϢ??�����?�ڡ�

		\~japanese
		����hostname����?����?���骳�Ϋ��֫������Ȫ��������ު���
		\~
		*/
		static NamedAddrPort PROUD_API FromAddrPort(String addr, uint16_t port);

		/**
		\~korean
		AddrPort ��ü�κ��� �� ��ü�� �����Ѵ�

		\~english
		Generate this object from AddrPort object

		\~chinese
		?AddrPort?������???�ڡ�

		\~japanese
		AddrPort���֫������Ȫ��骳�Ϋ��֫������Ȫ��������ު���
		\~
		*/
		static NamedAddrPort PROUD_API From(const AddrPort &src);

		/**
		\~korean
		hostname�� ����ִ� ���ڿ��� ��� ����ִ� ���ڿ��� �� ȣ��Ʈ �̸��� �����Ѵ�.

		\~english
		Appoint a new host name with the string inside of hostname.

		\~chinese
		��hostname�ݬ������?������?��ݬ������������٣��

		\~japanese
		hostname���������֪�����ꡢ���êƪ������֪���檷���۫���٣����Ҫ��ު���
		\~
		*/
		PROUD_API void OverwriteHostNameIfExists(const String &hostName);

		/**
		\~korean
		�� ������

		\~english
		Comparison Operator

		\~chinese
		��??ߩݬ

		\~japanese
		������ߩ�
		\~
		*/
		inline bool operator==( const NamedAddrPort &rhs ) const
		{
			return m_addr == rhs.m_addr && m_port == rhs.m_port;
		}

		/**
		\~korean
		�� ������

		\~english
		Comparison Operator

		\~chinese
		��??ߩݬ

		\~japanese
		������ߩ�
		\~
		*/
		inline bool operator!=( const NamedAddrPort &rhs ) const
		{
			return !( m_addr == rhs.m_addr && m_port == rhs.m_port );
		}

		/**
		\~korean
		���빰�� ���ڿ��� �����.

		\~english
		This method makes the contents into string.

		\~chinese
		��?������ݬ����

		\~japanese
		?�ڪ�����֪�˪��ު���
		\~
		*/
		String PROUD_API ToString() const;

		/**
		\~korean
		��ε�ĳ��Ʈ �ּҵ� �ƴϰ�, null �ּҵ� �ƴ�, 1�� ȣ��Ʈ�� 1�� ��Ʈ�� ����Ű�� �������� �ּ��ΰ�?

		\~english
		Is it correct address that point 1 port of 1 host instead of broadcast address, null address?

		\~chinese
		����broadcast�򣣬�����null�򣣬�����������?���߾��?ӮϢ�������򣣿

		\~japanese
		�֫�?�ɫ��㫹�ȫ��ɫ쫹�Ǫ�ʪ���null���ɫ쫹�Ǫ�ʪ���1�۫��Ȫ�1��?�Ȫ�򦪹���Ȫʫ��ɫ쫹�Ǫ�����
		\~
		*/
		bool IsUnicastEndpoint();
	};

	inline void AppendTextOut(String& a, AddrPort &b)
	{
		a += b.ToString();
	}

	inline void AppendTextOut(String& a, NamedAddrPort &b)
	{
		a += b.ToString();
	}

	/**
	\~korean
	��Ʈ��ũ ���α׷��� ���� ��ƿ��Ƽ Ŭ����

	\~english
	Network programming related utility class

	\~chinese
	???����?��?������?

	\~japanese
	�ͫëȫ�?���׫���߫�?֧��?�ƫ���ƫ�?���髹
	\~
	*/
	class CNetUtil
	{
	public:
//#if !defined __MARMALADE__ && !defined __FreeBSD__
		/**
		\~korean
		ȣ��Ʈ�� ���� �ִ� ���� IP �ּҸ� ��� �����ϴ�.

		\~english
		Gets every local IP addresses that host has.

		\~chinese
		�������?����������IP�򣡣

		\~japanese
		�۫��Ȫ��êƪ����?����IP���ɫ쫹������������ު���
		\~
		*/
		PROUD_API static void GetLocalIPAddresses(CFastArray<String> &output);
//#endif // !defined(__MARMALADE__)

		PROUD_API static int GetIPVersionFromString(const String& rhs);

		/** Returns true if address is filled with 255 or 0xffff. */
		static bool IsAddressAny(const String& address);

		/** Returns true if address is filled with 0. */
		static bool IsAddressUnspecified(const String& address);

		/** Returns true if address is not Any, Unspecified nor Loopback. */
		static bool IsAddressPhysical(const String& address);

		/** Returns true if addres is Loopback. For example, "127.0.0.1", "::1" or "localhost". */
		static bool IsAddressLoopback(const String& address);

#if defined(_WIN32)

		/**
		\~korean
		�Ϻ� �º��� ������ ��Ʈ��ũ �ƴ�Ÿ�� ��� �ϵ����� �����ϴ� TCP offload ��ɿ� ������ ���� �� �ֽ��ϴ�.
		�� �޼���� ������ ������Ʈ������ �ش� ����� �����ϸ� ������� �ʿ�� �մϴ�.
		\return ErrorType_Ok �̸� ���������� ����������, ������� ���մϴ�. Windows Vista �̻��� OS ���� ������ ������ ȹ������ ������ ErrorType_PermissionDenied ������ �߻��� �� �ֽ��ϴ�. ��Ÿ ������ ��� ErrorType_Unexpected �� ���ϵ˴ϴ�.

		\~english
		TCP offload function will occur problem with some cheap network adapter that intergrated on the mother board.
		This method is controlled by Windows registry and it require restart a machine.
		It successfully applied, if \return ErroType_Ok is true. and it require restart. ErrorType_PermissionDenied will occur, if you do not get aminitrator permission on Windows Vista or above version. ErrorType_Unexpected will return with other errors

		\~chinese
		����֯����??�����������ʦ��?���������TCP offload����?��??��??۰��?�Windows�?��߾�����?������?�������??����
		\return ErrorType_Ok��?����?������������??���Windows Vista�߾��OS����?��η��?�ڣ�??��ErrorType_PermissionDenied??������??��?��?����ErrorType_Unexpected��

		\~japanese
		��ݻ�����?��������ͫëȫ�?�������׫�?�����ꡢ��?�ɫ������ǫ���?�Ȫ���TCP offloadѦ������𹪬�������ꪬ����ު���
		���Ϋ᫽�ëɪϫ�����ɫ��쫸���ȫ�?����?Ѧ������٪�������Ѫ���驪Ȫ��ު���
		\return ErrorType_Ok�Ǫ��������?�ߪǪ��Ϊ�����Ѫ��ƪ���������Windows Vista�߾��OS��η����?�ڪ����𪷪ʪ����ErrorType_PermissionDenied����?��?�檹��ʦ����������ު��������⫨��?�����ꡢErrorType_Unexpected������?����ު���
		\~
		*/
		PROUD_API static ErrorType EnableTcpOffload(bool enable);
#endif
	};

	/**  @}  */
}

template<>
class CPNElementTraits < Proud::AddrPort >
{
public:
	typedef const Proud::AddrPort& INARGTYPE;
	typedef Proud::AddrPort& OUTARGTYPE;

	inline static uint32_t Hash(INARGTYPE a)
	{
		uint32_t sumVal = 0;
		for (int32_t i = 0; i < Proud::PN_IPV6_ADDR_LENGTH; i++)
		{
			sumVal += a.m_addr.v6Byte[i];
		}

		return sumVal ^ a.m_port;
	}

	inline static bool CompareElements(INARGTYPE element1, INARGTYPE element2)
	{
		return element1 == element2;
	}

	inline static int CompareElementsOrdered(INARGTYPE element1, INARGTYPE element2)
	{
 		if (element1 < element2)
 			return -1;
 		if (element1 == element2)
 			return 0;
		return 1;
	}
};

// template<>
// class CPNElementTraits<Proud::AddrPort>
// {
// public:
// 	typedef const Proud::AddrPort& INARGTYPE;
// 	typedef Proud::AddrPort& OUTARGTYPE;
//
// 	inline static ULONG Hash( INARGTYPE element )
// 	{
// 		assert(sizeof(element.m_binaryAddress) == 4);
// 		return element.m_binaryAddress ^ element.m_port;
//
// 		return ret;
// 	}
//
// 	inline static bool CompareElements( INARGTYPE element1, INARGTYPE element2 ) throw()
// 	{
// 		return ( element1 == element2 ) ? true:false;
// 	}
//
// 	inline static int CompareElementsOrdered( INARGTYPE element1, INARGTYPE element2 ) throw()
// 	{
// 		if(element1.m_binaryAddress < element2.m_binaryAddress)
// 			return -1;
// 		else if(element1.m_binaryAddress < element2.m_binaryAddress)
// 			return 1;
// 		if(element1.m_port < element2.m_port)
// 			return -1;
// 		else if(element1.m_port > element2.m_port)
// 			return 1;
// 		return 0;
// 	}
// };

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif

