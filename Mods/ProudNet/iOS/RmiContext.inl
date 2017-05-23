#pragma once 

#include "NetConfig.h"
#include "Enums.h"
#include "CompressEnum.h"

//////////////////////////////////////////////////////////////////////////
// ���� ȣ��Ǵ� �Լ������� inl�� ����

namespace Proud
{
	inline RmiContext::RmiContext()
		: m_relayed(false)
		, m_sentFrom(HostID_None)
		, m_unreliableS2CRoutedMulticastMaxCount(0)
		, m_unreliableS2CRoutedMulticastMaxPingMs(CNetConfig::UnreliableS2CRoutedMulticastMaxPingDefaultMs)
		, m_maxDirectP2PMulticastCount(CNetConfig::DefaultMaxDirectP2PMulticastCount)
		, m_uniqueID(0)
		, m_priority(MessagePriority_Medium)
		, m_reliability(MessageReliability_Reliable)
		, m_enableLoopback(true)
		, m_hostTag(NULL)
		, m_enableP2PJitTrigger(true)
		, m_allowRelaySend(true)
		, m_forceRelayThresholdRatio(0)
		, m_INTERNAL_USE_isProudNetSpecificRmi(false)
		, m_fragmentOnNeed(CNetConfig::FraggingOnNeedByDefault)
		, m_encryptMode(EM_None)
		, m_compressMode(CM_None)
	{}

	inline RmiContext::RmiContext(MessagePriority priority, MessageReliability reliability, int unreliableS2CRoutedMulticastMaxCount, EncryptMode encryptMode)
		: m_relayed(false)
		, m_sentFrom(HostID_None)
		, m_unreliableS2CRoutedMulticastMaxCount(unreliableS2CRoutedMulticastMaxCount) // ���� ���� Ʈ���� �ڽ�Ʈ�� ���̱� ���ؼ� �߰�
		, m_unreliableS2CRoutedMulticastMaxPingMs(CNetConfig::UnreliableS2CRoutedMulticastMaxPingDefaultMs)
		, m_maxDirectP2PMulticastCount(CNetConfig::DefaultMaxDirectP2PMulticastCount)
		, m_uniqueID(0)
		, m_priority(priority)
		, m_reliability(reliability)
		, m_enableLoopback(true)
		, m_hostTag(NULL)
		, m_enableP2PJitTrigger(true)
		, m_allowRelaySend(true)
		, m_forceRelayThresholdRatio(0)
		, m_INTERNAL_USE_isProudNetSpecificRmi(false)
		, m_fragmentOnNeed(CNetConfig::FraggingOnNeedByDefault)
		, m_encryptMode(encryptMode)
		, m_compressMode(CM_None)
	{
	}

}