/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 177 92 124 113 87 79 17 155 171 239 138 133 88 235 28 112 146 102 93 52 214 131 240 31 138 179 248 115 127 118 107 31 112 91 111 14 243 1 121 131 22 69 144 19 214 101 65 133 253 32 122 175 12 198 63 134 23 240 109 90 59 142 194 194 160 148 139 101 68 220 217 181 32 240 36 47 59 74 18 182 145 116 17 29 255 115 236 11 29 111 122  */
#pragma once

#include "PNString.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \~korean ��Ȳ ��� �����Դϴ�. 
	\~english Status information.
	\~chinese ????���ӡ�
	\~japanese ?�Ϫ���ͪ���êǪ���
	\~
	*/
	class CNetCoreStats
	{
	public:
		uint64_t m_totalTcpReceiveCount;

		/**
		\~korean
		�� ���ŵ� TCP �޽����� ��(byte). RMI �Ӹ� �ƴ϶� ProudNet ������ ��� ��Ŷ�� ������� �����Ѵ�.

		\~english
		Amount(byte) of all TCP messages received. This includes RMI and the headers of all packets in ProudNet.

		\~chinese
		?�����TCP�����ᣨbyte�������RMI�������ProudNet?ݻ�����?����header��

		\~japanese
		���᪵�쪿TCP��ë�?����?��(byte)��RMI�����ǪϪʪ���ProudNet?ݻ����ƪΫѫ��ëȪΫثë�?�ު��ߪ�ު���
		\~
		*/
		uint64_t m_totalTcpReceiveBytes;

		uint64_t m_totalTcpSendCount;

		/**
		\~korean
		�� �۽ŵ� TCP �޽����� ��(byte). RMI �Ӹ� �ƴ϶� ProudNet ������ ��� ��Ŷ�� ������� �����Ѵ�.

		\~english
		Amount(byte) of all TCP messages sent. This includes RMI and the headers of all packets in ProudNet.

		\~chinese
		??����TCP�����ᣨbyte�������RMI�������ProudNet?ݻ�����?����header��

		\~japanese
		���᪵�쪿TCP��ë�?����?��(byte)��RMI�����ǪϪʪ���ProudNet?ݻ����ƪΫѫ��ëȪΫثë�?�ު��ߪ�ު���
		\~
		*/
		uint64_t m_totalTcpSendBytes;
		
		/**
		\~korean
		�� ���ŵ� UDP �޽����� ����. RMI �Ӹ� �ƴ϶� ProudNet ������ ��� ��Ŷ�� ������� �����Ѵ�.

		\~english
		Number of all UDP messages received. This includes RMI and the headers of all packets in ProudNet.

		\~chinese
		?�����UDP����??�����RMI�������ProudNet?ݻ�����?����header��

		\~japanese
		���᪵�쪿UDP��ë�?����??��RMI�����ǪϪʪ���ProudNet?ݻ����ƪΫѫ��ëȪΫثë�?�ު��ߪ�ު���
		\~
		*/
		uint64_t m_totalUdpReceiveCount;
		/**
		\~korean
		�� ���ŵ� UDP �޽����� ��(byte). RMI �Ӹ� �ƴ϶� ProudNet ������ ��� ��Ŷ�� ������� �����Ѵ�.

		\~english
		Amount(byte) of all UDP messages received. This includes RMI and the headers of all packets in ProudNet

		\~chinese
		?�����UDP�����ᣨbyte�������RMI�������ProudNet?ݻ�����?����header��

		\~japanese
		���᪵�쪿UDP��ë�?����?�ᣨbyte����RMI�����ǪϪʪ���ProudNet?ݻ����ƪΫѫ��ëȪΫثë�?�ު��ߪ�ު���
		\~
		*/
		uint64_t m_totalUdpReceiveBytes;

		/**
		\~korean
		�� �۽ŵ� UDP �޽����� ��(byte). RMI �Ӹ� �ƴ϶� ProudNet ������ ��� ��Ŷ�� ������� �����Ѵ�.

		\~english
		Amount(byte) of all UDP messages sent. This includes RMI and the headers of all packets in ProudNet.

		\~chinese
		??����UDP�����ᣨbyte�������RMI�������ProudNet?ݻ�����?����header��

		\~japanese
		���᪵�쪿UDP��ë�?����?�ᣨbyte����RMI�����ǪϪʪ���ProudNet?ݻ����ƪΫѫ��ëȪΫثë�?�ު��ߪ�ު���
		\~
		*/
		uint64_t m_totalUdpSendBytes;

		/**
		\~korean
		�� �۽ŵ� UDP �޽����� ����. RMI �Ӹ� �ƴ϶� ProudNet ������ ��� ��Ŷ�� ������� �����Ѵ�.

		\~english
		Number of all UDP messages sent. This includes RMI and the headers of all packets in ProudNet.

		\~chinese
		??����UDP����??�����RMI�������ProudNet?ݻ�����?����header��

		\~japanese
		���᪵�쪿UDP��ë�?����??��RMI�����ǪϪʪ���ProudNet?ݻ����ƪΫѫ��ëȪΫثë�?�ު��ߪ�ު���
		\~
		*/
		uint64_t m_totalUdpSendCount;

		inline uint64_t GetTotalReceiveBytes()
		{
			return m_totalTcpReceiveBytes + m_totalUdpReceiveBytes;
		}

		/**
		\~korean
		�� ���ŵ� �޽����� ��(byte). RMI �Ӹ� �ƴ϶� ProudNet ������ ��� ��Ŷ�� ������� �����Ѵ�.

		\~english
		Amount(byte) of all messages sent. This includes RMI and the headers of all packets in ProudNet.

		\~chinese
		?����������ᣨbyte�������RMI�������ProudNet?ݻ�����?����header��

		\~japanese
		���᪵�쪿��ë�?����?�ᣨbyte����RMI�����ǪϪʪ���ProudNet?ݻ����ƪΫѫ��ëȪΫثë�?�ު��ߪ�ު���
		\~
		*/
#if defined(_MSC_VER)
		__declspec(property(get = GetTotalReceiveBytes)) uint64_t m_totalReceiveBytes;
#endif


		inline uint64_t GetTotalSendCount()
		{
			return m_totalTcpSendCount + m_totalUdpSendCount;
		}
		inline uint64_t GetTotalReceiveCount()
		{
			return m_totalTcpReceiveCount + m_totalUdpReceiveCount;
		}
		inline uint64_t GetTotalSendBytes()
		{
			return m_totalTcpSendBytes + m_totalUdpSendBytes;
		}
		/**
		\~korean
		�� �۽ŵ� �޽����� ����. RMI �Ӹ� �ƴ϶� ProudNet ������ ��� ��Ŷ�� ������� �����Ѵ�.

		\~english
		Number of all messages sent. This includes RMI and the headers of all packets in ProudNet.

		\~chinese
		?���������??�����RMI�������ProudNet?ݻ�����?����header��

		\~japanese
		���᪵�쪿��ë�?����??��RMI�����ǪϪʪ���ProudNet?ݻ����ƪΫѫ��ëȪΫثë�?�ު��ߪ�ު���
		\~
		*/
#if defined (_MSC_VER)
		__declspec(property(get = GetTotalSendCount)) uint64_t m_totalSendCount;

		/**
		\~korean
		�� ���ŵ� �޽����� ����. RMI �Ӹ� �ƴ϶� ProudNet ������ ��� ��Ŷ�� ������� �����Ѵ�.

		\~english
		Number of all received messages. This includes RMI and the headers of all packets in ProudNet.

		\~chinese
		?���������??�����RMI�������ProudNet?ݻ�����?����header��

		\~japanese
		���᪵�쪿��ë�?����??��RMI�����ǪϪʪ���ProudNet?ݻ����ƪΫѫ��ëȪΫثë�?�ު��ߪ�ު���
		\~
		*/
		__declspec(property(get = GetTotalReceiveCount)) uint64_t m_totalReceiveCount;

		/**
		\~korean
		�� �۽ŵ� �޽����� ��(byte). RMI �Ӹ� �ƴ϶� ProudNet ������ ��� ��Ŷ�� ������� �����Ѵ�.

		\~english
		Amount(byte) of all sent messages. This includes RMI and the headers of all packets in ProudNet.

		\~chinese
		?������������ᣨbyte�������RMI�������ProudNet?ݻ�����?����header��

		\~japanese
		���᪵�쪿��ë�?����?�ᣨbyte����RMI�����ǪϪʪ���ProudNet?ݻ����ƪΫѫ��ëȪΫثë�?�ު��ߪ�ު���
		\~
		*/
		__declspec(property(get = GetTotalSendBytes)) uint64_t m_totalSendBytes;
		
#endif

		CNetCoreStats();

		/**
		\~korean
		�� ��ü�� ���빰�� ǥ���ϴ� ���ڿ��� �����մϴ�.

		\~english
		Returns a string that represents this object.

		\~chinese
		��������??�����ݬ����

		\~japanese
		���Ϋ��֫������Ȫ�?黪��������ȫ�󫰪�꫿?�󪷪ު���
		\~
		*/
		virtual String ToString() const = 0;
	};
}
#ifdef _MSC_VER
#pragma pack(pop)
#endif