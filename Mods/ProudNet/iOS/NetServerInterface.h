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

//#define TEST_DISCONNECT_CLEANUP �׽�Ʈ �뵵

#include "BasicTypes.h"
#include "HostIDArray.h"
#include "AddrPort.h"
#include "Enums.h"
#include "EncryptEnum.h"
#include "RMIContext.h"
#include "ErrorInfo.h"
#include "ServerParam.h"
#include "NetServerStats.h"
#include "NetClientInterface.h"
#include "LambdaEventHandler.h"
#include "acr.h"

#define PN_DEPRECATED /*__declspec(deprecated) */

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4324)
#endif

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif

	/** \addtogroup net_group
	*  @{
	*/

	class MessageSummary;
	class CTestStats2;
	class CMessage;
	class CNetConnectionParam;
	class CNetPeerInfo;
	class CNetClientInfo;
	class CP2PGroup;
	class CP2PGroups;
	class CSendFragRefs;
	class ErrorInfo;
	class INetClientEvent;
	class INetServerEvent;
	class IRmiProxy;
	class IRmiStub;
	class ReliableUdpHostStats;
	struct SendOpt;





	/**
	\~korean
	\brief GetSuitableSuperPeerRankListInGroup���� ä������ �迭�� �� �����Դϴ�.

	\~english
	\brief Each element of array filled at GetSuitableSuperPeerRankListInGroup

	\~chinese
	\brief �GetSuitableSuperPeerRankListInGroup?����?������ȡ�

	\~japanese
	\brief GetSuitableSuperPeerRankListInGroup��?���������֪������ȪǪ���
	\~
	*/
	struct SuperPeerRating
	{
		/**
		\~korean
		P2P �׷� ���� �Ǿ� ID �Դϴ�.

		\~english
		Peer ID in P2P group

		\~chinese
		P2P??��peerID��

		\~japanese
		P2P����?��?��Peer ID�Ǫ���
		\~
		*/
		HostID m_hostID;

		/**
		\~korean
		�� �Ǿ� ID�� �����Ǿ� ���� �˻翡�� ���� �����Դϴ�.
		�� �׸��� ���Ե� �迭�� �ٸ� ���ҿ� �������� ���� Ŭ���� �����Ǿ�μ��� ���� ������ ������ �ǹ��մϴ�.

		\~english
		Result from superpeer qualified testing by this peer ID.
		If value is bigger than others, it means, it is close to qualification of superpeer

		\~chinese
		�peer ID�superpeer����̫??��?������?��
		?�����?����??�������������?��?���?������ګ��superpeer��?̫������ԡ�

		\~japanese
		����Peer ID��Super Peer��̫?�۪�������?�Ǫ���
		�������ͪ��ߪު쪿��֪�������Ȫ����򪷪����������ު����۪�Super Peer�Ȫ��ƪ���̫��٫몬�Ԫ����Ȫ���ګ���ު���

		\~
		*/
		double m_rating;

		/**
		\~korean
		�������� UDP ����� ����ǰ� ������ true�Դϴ�. �������� UDP�� �Ǿ�� ��Ȱ�� P2P ����� ����� �� �ֽ��ϴ�.

		\~english
		If it communicates to server with UDP, it is true. You can expect reliable P2P if it communicates with UDP

		\~chinese
		?��?����UDP����������?true��?��?����UDP�������Ѣ��?����P2P���ᡣ

		\~japanese
		��?��?�Ȫ�UDP�������������true�Ǫ�����?��?�Ȫ�UDP���Ǫ��ƪ���������P2P�����Ѣ�⪹�몳�Ȫ��Ǫ��ު���
		\~
		*/
		bool m_realUdpEnabled;

		/**
		\~korean
		������ �ڿ� �ִ� ȣ��Ʈ�̸� true�Դϴ�. �����Ⱑ ���� ȣ��Ʈ�� ��� ��Ȱ�� �����Ǿ� ������ ����� �� �ֽ��ϴ�.

		\~english
		If it locates behind of router then it is true. You can expect relialbe superpeer when host does not use router

		\~chinese
		����������������?��true��?��������������?����Ѣ��superpeer�����ġ�

		\~japanese
		��?��?������˪���۫��Ȫʪ�true�Ǫ�����?��?�Ϊʪ��۫��Ȫ����ꡢ������Super Peer��ܪ�Ѣ�⪹�몳�Ȫ��Ǫ��ު���
		\~
		*/
		bool m_isBehindNat;

		/**
		\~korean
		�ֱ� Ŭ���̾�Ʈ-������ �����Ͻ��Դϴ�. �и��� �����Դϴ�. Ŭ���� �����Ǿ�μ��� ������ ����ϱ� ��ƽ��ϴ�.

		\~english
		Latency between client to server. It is a second unit. If it is high, do not except working as superpeer

		\~chinese
		����client-��?����?latency������?�ȡ�������?Ѣ����?superpeer�����ġ�

		\~japanese
		���Ρ����髤����ȫ�?��?��Ϋ�?�ƫ�?�Ǫ����߫���?�ȪǪ����ު����۪�Super Peer�Ȫ��ƪ���ܪ�Ѣ�⪷�˪����Ǫ���
		\~
		*/
		int m_recentPingMs;

		/**
		\~korean
		Ÿ �Ǿ���� ��� �����Ͻ��Դϴ�. �и��� �����Դϴ�. Ŭ���� �����Ǿ�μ��� ������ ����ϱ� ��ƽ��ϴ�.

		\~english
		Average latency with other peers. It is a second unit. If it is high, do not except working as superpeer

		\~chinese
		?����peer����гlatency������?�ȡ�������?Ѣ����?superpeer�����ġ�

		\~japanese
		���Peer�Ȫ���г��?�ƫ�?�Ǫ����߫���?�ȪǪ����ު����۪�Super Peer�Ȫ��ƪ���ܪ�Ѣ�⪷�񪤪Ǫ���
		\~
		*/
		int64_t m_P2PGroupTotalRecentPingMs;

		/**
		\~korean
		�۽� �ִ� ���� �ӵ��Դϴ�.
		�ε��Ҽ��� Ÿ��������, ����Ʈ �����Դϴ�. (1 �̸��� ��ŷ��� üũ�ϱ� ���ؼ�) Ŭ���� �����Ǿ�μ��� ������ ����� �� �ֽ��ϴ�.

		\~english
		Maximum sending speed.
		It is a floating-point type but byte. (to check traffic that under 1) If it is high, you can except working as superpeer

		\~chinese
		?����������ʦ��������
		ݩ���?��?����byte?�ȡ���?����??ڱ?1�������ᣩ����ʦ�Ѣ����?superpeer�����ġ�

		\~japanese
		��������ʦ�������Ǫ���
		�����?�ë����תǪ������Ы���?�ȪǪ���(1ڱ?�������������ë����몿���)�ު����۪�Super Peer�Ȫ��ƪ���ܪ�Ѣ�⪹�몳�Ȫ��Ǫ��ު���

		\~
		*/
		double m_sendSpeed;

		/**
		\~korean
		P2P �׷쿡 ���� �� ���� �ð��Դϴ�.
		�̹� �ٸ� �Ǿ �����Ǿ��϶� �� �Ǿ �����Ǿ�� ��ȯ�Ǵ°� ������ �� �ֽ��ϴ�.

		\~english
		Past time that after joined P2P group.
		If other peer is already superpeer it may hasty to change superpeer

		\~chinese
		?��P2P?��??��??��
		�?������peer?superpeer��?�����peer???superpeerʦ��?�������ᡣ

		\~japanese
		P2P����?�ת����êƪ���Φ��������Ǫ���
		?�����Peer��Super Peer�Ǫ�����������Peer��Super Peer��﷪����몳�ȪϪ���ê��ܪ�������ު���

		\~
		*/
		int64_t m_JoinedTime;

		/**
		\~korean
		����ڿ� ���� �Էµ� �ʴ� ������ ����(frame rate)�Դϴ�. Proud.CNetClient.SetApplicationHint ���� �Էµ˴ϴ�.

		\~english
		Frame rate (second) that entered by user. It enters at Proud.CNetClient.SetApplicationHint

		\~chinese
		����??��������?��??��frame rate����� Proud.CNetClient.SetApplicationHint%��?����

		\~japanese
		��?��?�˪�ê��������쪿��?����ի�?��?(frame rate)�Ǫ���Proud.CNetClient.SetApplicationHint����������ު���
		\~
		*/
		double m_frameRate;
	};

	/**
	\~korean
	\brief ���� �Ǿ� ���� ��å

	\~english
	\brief super peer selection policy

	\~chinese
	\brief superpeer?��������

	\~japanese
	\brief Super Peer���ҫݫ꫷?
	\~
	*/
	class CSuperPeerSelectionPolicy
	{
	public:

		/**
		\~korean
		�������� UDP ����� �������� �� �������Ǵ� ����ġ. �е������� ����ġ�� �ſ� Ŀ�� �Ѵ�.

		\~english
		The weight added when UDP communication to server is on. This weight must be overwhelming.

		\~chinese
		?��?����UDP����??��?��ʥ����ʥ��?��ʥ��?�?�������ޡ�

		\~japanese
		��?��?�Ȫ�UDP���᪬�ު����ʪêƪ�������ʥߩ�ê˪ʪ�ʥ������?���ܪ�ʥ�������ު����ʪ���Ъʪ�ު���
		\~
		*/
		double m_realUdpWeight;
		/**
		\~korean
		���ͳ� ������ ����, �� ���� IP�� ���� ����ϴ� Ŭ���̾�Ʈ�� �������Ǵ� ����ġ. Ȧ��Ī �������� �����Ƿ� ����ġ�� ���� ��� ���� ����.

		\~english
		The weight added to client that directly uses public IP - which means using no internet router. It is recommended to set this as relatively high since hole-punching rate is kept high.

		\~chinese
		?��������ܣ�??����������?IP��client��?ʥ����ʥ��?������?����ԣ���?��ʥ��?������?����

		\~japanese
		����?�ͫëȫ�?��?�Ϊʪ���?���ѫ֫�ë�IP�������Ū����髤����Ȫ�ʥߩ�ê˪ʪ�ʥ��������?��ѫ���󫰪����㪬�Ԫ��Ϊ�ʥ�������Ԫ����ê�۰���ު��Ǫ���
		\~
		*/
		double m_noNatDeviceWeight;
		/**
		\~korean
		�������� �����Ͻ� 1�� �з��� ���� �����Ǵ� ����ġ. �����Ǿ �������� ����� ���� �ϴ� ��� ����ġ�� ũ�� ��� ���� ����.

		\~english
		The weight added for each second of time of latency to server. If a super peer is communicating with server often then this must be set high.

		\~chinese
		?��?����latency��������?����ʥ��?������superpeer?��?��?��������??��ʥ��?������?����

		\~japanese
		��?��?�ȪΫ�?�ƫ�?1�������?�������ê˪ʪ�ʥ������Super Peer����?��?�Ȫ������誯������ꡢʥ�������ު������ê�۰���ު��Ǫ���
		\~
		*/
		double m_serverLagWeight;
		/**
		\~korean
		Ÿ �Ǿ� 1������ �����Ͻ� 1�� �з��� ���� �����Ǵ� ����ġ. m_serverLagWeight ���� �۰� ����� �Ǿ��� ������ �����Ҽ��� �� ���� ����ġ���� �����Ѵ�.
		�� ���� CStartServerParameter.m_enablePingTest ���� true�� �������� ������, ������ �ʽ��ϴ�.

		\~english
		The weight to be deducted for each second of time of latency to other peer. This increases as the number of peers increase even if set smaller than m_serverLagWeight.
		It is not calculated, if you do not set CStartServerParameter.m_enablePingTest as true.

		\~chinese
		?����peer��?��latency��������?����ʥ��?��?����m_serverLagWeight?����᳣�peer ��??����ʥ�?������?��ʥ��?��ʥ��
		���� CStartServerParameter.m_enablePingTest%??����true��?���?��?��?ߩ��

		\~japanese
		���Peer 1���ȪΫ�?�ƫ�?1�������?�������ê����ʥ������ m_serverLagWeight���ᳪ������êƪ�Peer��?��?ʥ����۪�?��?��?ʥ�������?ʥ���ު���
		CStartServerParameter.m_enablePingTest ����true�����Ҫ��ʪ����ͪߩ����ު���

		\~
		*/
		double m_peerLagWeight;
		/**
		\~korean
		�۽� �ӵ� 10Mbps�� ���� �������Ǵ� ����ġ. ������ ���ͳݿ����� ���ε� �ӵ��� ���� ���̱� ������ �� ����ġ�� �ʿ��� ���� �ִ�.

		\~english
		The weight added to transmission speed of 10Mbps. This weight may be needed as home internet connection has relatively low spees for uploading.

		\~chinese
		??������10Mbpsʥ����ʥ��?����?ʫ������??߾?������ط��ʦ��?����ʥ��?��

		\~japanese
		��������10Mbps��?����ʥߩ�ê˪ʪ�ʥ������ʫ���ī���?�ͫëȪǪϫ��ë׫�?��������?���Ϊǡ�����ʥ��������驪˪ʪ몫����ު���
		\~
		*/
		double m_sendSpeedWeight;
		/**
		\~korean
		����ڰ� ������ �����ӷ���Ʈ���� ����ġ�Դϴ�.
		- ������ ����Ʈ �� 1�� ����ؼ� �� ���� �����մϴ�. ���� ��� 60�������� �� �����ϸ� �����Ǿ�μ� �����̰� 20������ �����̸�
		�����Ǿ�μ� �������ϰ� ���ϰ��� �Ѵٸ�, 4�� ���� ��� 20������ * 4 = 80, 60������*4 = 240, �� 160�� �������� ���� �˴ϴ�.
		- ������ ������ ����Ʈ�� Proud.CNetClient.SetApplicationHint �� ���� �Է��Ͻʽÿ�.

		\~english
		The weight to the frame rate measured by user
		- This value increases proportional to frame rate value 1. For an example, if assumed that sustaining 60 fps is regarded as an ideal super peer and lower than 20 fps as to be avoided,
		then entering 4 gives 20 fps * 4 = 80, 60 fps * 4 = 240 resulting 160 points in difference.
		- Measured frame rate is to be entered via Proud.CNetClient.SetApplicationHint.

		\~chinese
		��??����??����ʥ��?��
		- ??��?1����??��ʥ��������?��??����?�60?��?����?superpeer����̫�ܣ�20?������?������̫��?��?��4��?20?*4=80��60?*4=240��??���160�¡�
		- ?����?��?��? Proud.CNetClient.SetApplicationHint%?����

		\~japanese
		��?��?�����Ҫ����ի�?���?�ȪȪ�ʥ�����Ǫ���
		- �ի�?���?����1�����Ǫ��ƪ�������?ʥ���ު����Ǫ��С�60�ի�?���誯�򥪹���Super Peer�Ȫ�����̫�ǡ�20�ի�?������Ǫ����Super Peer�Ȫ������������?����Ȫ����顢4����������ꡢ20�ի�?��*4=80��60�ի�?��*4=240��?����160����?󬪬���誦�˪ʪ�ު���
		- ���Ҫ��쪿�ի�?���?�Ȫϡ�Proud.CNetClient.SetApplicationHint���ת��������ƪ���������

		\~
		*/
		double m_frameRateWeight;

		/**
		\~korean
		P2P �׷쿡 ������ Ŭ���̾�Ʈ�� ������ �� ���� �ð��� ���⼭ ������ �ð� �����̸� �����Ǿ� �������� ���� �����Ѵ�. �и��� ������.
		- 0���� �����ϸ� �̷��� ������ ���� �ʴ´�.
		- ��������� ���� �����Ǿ� ������ ���� ���� ���� �����Ѵ�.

		\~english
		To be disregarded as super peer when the time from the moment that the client participated to the P2P group to now is less than the time designated here. This is in millisecond.
		- Set as 0 then the disregard will not occur.
		- Usually set to prevent super peer eing changed too often.

		\~chinese
		??P2P?��client?ʥ��??��??���?�����??�����?��?superpeer?������𶡣����?�ȡ�
		- ���?0��?��?�??��𶡣
		- ����?������?����superpeer��?�����?��

		\~japanese
		P2P����?�ת�?ʥ�������髤����Ȫ�?ʥ������?Φ���બ��������Ҫ�����������Ǫ����Super Peer���ҪǪ۪���𶪷�ު����߫���?�ȪǪ���
		- 0����Ҫ���Ъ��Ϊ誦�����򪷪ު���
		- ���ȡ�޺���Super Peer��?�ڪ����������������Ҫ��ު���

		\~
		*/
		int64_t m_excludeNewJoineeDurationTimeMs;

		CSuperPeerSelectionPolicy();

		inline bool operator==(const CSuperPeerSelectionPolicy& rhs) const
		{
			return m_realUdpWeight == rhs.m_realUdpWeight &&
				m_noNatDeviceWeight == rhs.m_noNatDeviceWeight &&
				m_serverLagWeight == rhs.m_serverLagWeight &&
				m_peerLagWeight == rhs.m_peerLagWeight &&
				m_sendSpeedWeight == rhs.m_sendSpeedWeight &&
				m_frameRateWeight == rhs.m_frameRateWeight;
		}

		/**
		\~korean
		�Ϲ������� ���̴� �������� ���� �̸� �����ؼ� �����Ѵ�.

		\~english
		Previously prepared type are set and then returned.

		\~chinese
		��������������?�������?��?�����ޡ�

		\~japanese
		�����ܪ��Ū���׾�����������ê����Ҫ��ƫ꫿?�󪷪ު���
		\~
		*/
		static CSuperPeerSelectionPolicy GetOrdinary();

		/**
		\~korean
		���� ����

		\~english
		DO NOT USE THIS.

		\~chinese
		������ġ�

		\~japanese
		�Ū�ʪ����ȡ�
		\~
		*/
		static CSuperPeerSelectionPolicy GetNull();
	};

	/**
	\~korean
	\brief P2P ���ῡ ���� ����Դϴ�.

	\~english
	\brief Statistics to P2P connection

	\~chinese
	\brief ?P2P?����??��

	\~japanese
	\brief P2P��?��?������ͪ�Ǫ���
	\~
	*/
	class CP2PConnectionStats
	{
	public:
		/**
		\~korean
		��ü ���� P2P���� �����Դϴ�.

		\~english
		Number of all connected P2P pairs

		\~chinese
		��ݻP2P?������???��

		\~japanese
		��?��?P2P�ګ���?�Ǫ���
		\~
		*/
		uint32_t m_TotalP2PCount;

		/**
		\~korean
		���� ���� P2P���� �����Դϴ�.

		\~english
		Number of directly connected P2P pairs

		\~chinese
		����P2P?������???

		\~japanese
		������?P2P�ګ���?�Ǫ���
		\~
		*/
		uint32_t m_directP2PCount;

		/**
		\~korean
		�ش� Ŭ���̾�Ʈ�� �ٸ� Ŭ���̾�Ʈ���� Udp packet ������ �õ��� �� Ƚ��
		- CNetServer ������ ���� ä�����ϴ�. ( CLanServer ������ udp�� �����ϹǷ�. )
		- group�� CP2PConnectionStats ��� ��� �׷���� Ƚ���� �ջ�˴ϴ�.

		\~english
		Total attempted number of Udp packet sending from client to other client.
		- Value will fill at only CNetServer (Because CLanServer does not use udp.)
		- All group members attempt will be added, if it is CP2PConnectionStats of group.

		\~chinese
		?��?client������client???��UDP packet��?�?��
		- ��� CNetServer%?��?��������?� CLanServer%������UDP��
		- group�� CP2PConnectionStats%��?���??���?Դ?����ߩ��

		\~japanese
		��?���髤����Ȫ���Ϋ��髤����Ȫ�UDP�ѫ��ëȪ�?����˪���?��?
		- CNetServer �ǪΪ�����?������ު��� (CLanServer�Ǫ�UDP�����Ī��ު���Ϊ�)
		- group��CP2PConnectionStats�ʪ���ƪΫ���?�׫���?����?����ߩ����ު���

		\~
		*/
		uint32_t m_toRemotePeerSendUdpMessageTrialCount;

		/**
		\~korean
		�ش� Ŭ���̾�Ʈ�� �ٸ� Ŭ���̾�Ʈ���� Udp packet ������ ������ �� Ƚ��
		- CNetServer ������ ���� ä�����ϴ�. ( CLanServer ������ udp�� �����ϹǷ�. )
		- group�� CP2PConnectionStats ��� ��� �׷���� Ƚ���� �ջ�˴ϴ�.

		\~english
		Total successful number of Udp packet sending from client to other client
		- Value will fill at only CNetServer (Because CLanServer does not use udp.)
		- All group members attempt will be added, if it is CP2PConnectionStats of group.

		\~chinese
		?��?client������client����?��UDP packet��?�?��
		- ��� CNetServer%?��?��������?� CLanServer%������UDP��
		- group�� CP2PConnectionStats%��?���??���?Դ?����ߩ��

		\~japanese
		��?���髤����Ȫ���Ϋ��髤����Ȫ�UDP�ѫ��ëȪ�?���������?��?
		- CNetServer �ǪΪ�����?������ު���(CLanServer�Ǫ�UDP�����Ī��ު���Ϊ�)
		- group��CP2PConnectionStats�Ǫ������ƪΫ���?�׫���?����?����ߩ����ު���

		\~
		*/
		uint32_t m_toRemotePeerSendUdpMessageSuccessCount;
	};

	/**
	\~korean
	\brief RemoteA �� RemoteB ������ Udp �޽�¡ �õ��� ���������Դϴ�.

	\~english
	\brief Number of attempt and success Udp messaging between RemoteA and Remote B.

	\~chinese
	\brief RemoteA��RemoteB��?UDP messaging??������??��

	\~japanese
	\brief RemoteA��RemoteB���UDP��ë�?���󫰪��˪�������?�Ǫ���
	\~
	*/
	class CP2PPairConnectionStats
	{
	public:
		/**
		\~korean
		A�� B���� �õ��� Udp ����

		\~english
		Number of attempted Udp from A to B

		\~chinese
		A?B??��UDP??��

		\~japanese
		A��B���˪���UDP?
		\~
		*/
		uint32_t m_toRemoteBSendUdpMessageTrialCount;

		/**
		\~korean
		A�� B���� ������ Udp ����

		\~english
		Number of succeed Udp  from A to B

		\~chinese
		A?B������UDP??��

		\~japanese
		A��B��������UDP?
		\~
		*/
		uint32_t m_toRemoteBSendUdpMessageSuccessCount;

		/**
		\~korean
		B�� A���� �õ��� Udp ����

		\~english
		Number of attempted Udp from B to A

		\~chinese
		B?A??��UDP??��

		\~japanese
		B��A���˪���UDP?
		\~
		*/
		uint32_t m_toRemoteASendUdpMessageTrialCount;

		/**
		\~korean
		A�� B���� �õ��� Udp ����

		\~english
		Number of attempted Udp from A to B

		\~chinese
		A?B??��UDP??��

		\~japanese
		A��B���˪���UDP?
		\~
		*/
		uint32_t m_toRemoteASendUdpMessageSuccessCount;

		/**
		\~korean
		������ ����� �ϰ� ������ true�Դϴ�.

		\~english
		true if relayed mode.

		\~chinese
		�������?��Relay������????true��

		\~japanese
		���?����򪷪ƪ����true�Ǫ���
		\~
		*/
		bool m_isRelayed;
	};

	/**
	\~korean
	\brief ���ӿ� ��Ʈ��ũ ����

	���ӿ� ��Ʈ��ũ �����Դϴ�. �ڼ��� ���� <a target="_blank" href="http://guide.nettention.com/cpp_ko#server_overview" >ProudNet ����</a> �� �ֽ��ϴ�.
	- MMO ���ӿ��� �� �� �ִ�.
	- CNetClient �� ������ �޴´�.
	- Ŭ���̾�Ʈ���� HostID �� �������ִ� ������ �Ѵ�.
	- HostID �� �Ű�ü�� �ϴ� RMI�� �����ϰ� �Ѵ�.
	- �Ϲ����� ���� ������ �ʿ��� �⺻�� �ɼ��� �����Ǿ� �ִ�.
	- Ŭ���̾�Ʈ�� P2P ������ �����Ѵ�. �� ���� ��ü�� Ŭ���̾�Ʈ�� P2P ������ ������ ���
	������ ���� ���ҵ� �����Ѵ�.

	�Ϲ��� ���
	- �� ��ü�� �����Ѵ�. Proud.CNetServer.Create() ���.
	- Start()�� ������ �����Ѵ�.
	- INetServerEvent �� �����Ѵ�. ���� INetServerEvent.OnClientJoin() ���� �����Ѵ�.
	�̰͵��� Ŭ���̾�Ʈ ���� � ���� �̺�Ʈ �ڵ鷯�̴�.
	- ���۽� SetEventSink()�� �̺�Ʈ �ڵ鷯�� �����ְ�,
	AttachProxy(), AttachStub()�� �Ἥ 1�� �̻��� �۽� �Ǵ�
	���ſ� RMI �������̽��� �����Ѵ�.

	P2P ���� �׷� �����
	- CNetServer �� ����� Ŭ���̾�Ʈ�� 1�� �̻��� P2P �׷��� ���� �� �ִ�.
	P2P �׷����� �����ִ� Ŭ���̾�Ʈ������ HostID �� ���ڷ� RMI �� ���� �ְ� ���� �� �ִ�.
	- �� P2P group�� ����/�����ϱ�: �������� ������ �ִ�.
	CreateP2PGroup(),DestroyP2PGroup() �� ���ؼ�. Ŭ���̾�Ʈ������ OnP2PMemberJoin ���� ȣ��ȴ�.
	- peer �� �� ���� P2P group�� �߰�/�����ϱ�:
	JoinP2PGroup(), LeaveP2PGroup(). Ŭ���̾�Ʈ������ OnP2PMemberJoin ���� ȣ��ȴ�.

	Relay server�μ��� ����
	- HostID �� ������ P2P ������ �������ε� �̷������. ������ P2P ������ ������
	���� �������� ���� peer���̶� ��밡 P2P group�� ���������� ����� HostID
	�� ������ RMI�� ���������� ��뿡�� ����. relay server�� �ߵ� ������ ����Ѵ�.
	���� RMI ���� �޽����� �װ��� relay server�� �����ߴ��� ���θ� �������� RMI ���źο���
	RmiContext.m_relayed �� ������ �ȴ�.

	������ Ǯ��
	- �⺻������ ������ Ǯ�� ����Ѵ�. ���� ���� ���۽� ������ ���� �ּ� 1���� �����ؾ� �Ѵ�.
	- ������ Ǯ�� ����� ���°� ������ ���: 1�� CPU�̸鼭 CPU time ó���� ������ ����(������ ������ ����)
	- ������ Ǯ�� ����� �Ѵ°� ������ ���: ��Ƽ CPU �Ǵ� device time ó���� ���� ����(������ MMO ���� ����)
	- ������ Ǯ �Լ��� CoInitialize()�� �غ�� ���¿��� ȣ��ǹǷ� �� CoInitialize()�� CoUninitialize() ȣ�� ���ʿ�.

	UDP ȣ��Ʈ ��Ʈ ���� ���� ���� ����
	- CNetServer.Start �� ���� ��Ʈ �Ķ���ͷ� UDP ȣ��Ʈ ��Ʈ ������ ������ �� �ִ�.
	Ŭ���̾�Ʈ�� ������ ������ �� �Ķ���Ϳ� �ִ� ��Ʈ �� �ϳ��� ������ ����ȴ�.

	P2P ���� ��� ���� ���ɼ� ��Ʈ
	- P2P�� ������ real IP, Full-cone NAT�� ��� direct P2P ����� �����Ѵ�.
	- ���� ������ NAT �ڿ��� �۵��� ���, Start()�� ���� �ּҸ� �־�� �Ѵ�. (�ڼ��� ���� Start()�� ���� ����)
	��, �̷��� �Ѵ� �ϴ��� ���� ���� ���� NAT �ڿ� �ִ� �� �ٸ� ȣ��Ʈ���� ����Ǵ� Ŭ���̾�Ʈ�� �ܺ� ���ͳ�
	�� Ŭ���̾�Ʈ�� ���� P2P ����� �������� ���Ѵ�. ������ �ִ� NAT ��ġ�� ���� �ܺ� ���ͳ� �ּ� ��� NAT�� ����
	IP�� �νĵǱ� �����̴�.

	\~english
	\brief Gaming network server

	A network server for gaming. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#server_overview" >ProudNet Server</a>.
	- Can be used for a MMO title
	- Receives CNetClient connection
	- Allocates HostID to client
	- Allows RMI requires HostID
	- Basic options are set in order to support what a general game server needs
	- Supports P2P connection between clients. This server object supports to be a rela server when P2P connection fails between clients.

	General usage
	- Creates this object. Use Proud.CNetServer.Create().
	- Use Start() to start server.
	- Realize INetServerEvent, such as realizing INetServerEvent.OnClientJoin() and so on.
	Those are event handlers for client connections and so on.
	- Intertwines SetEventSink() to event andlers when started and links 1 or more of transmission or reception RMI interface using AttachProxy(), AttachStub().

	Creating P2P connection group
	- The client connected to CNetServer can create 1 or more P2P group.
	Among the clients linked as P2P group can transmit/receive RMI as HostID being index.
	- Creating/removing a new P2P group: Only server has rights.
	OnP2PMemberJoin and so on will be called at client via CreateP2PGroup(),DestroyP2PGroup().
	- Adding/removig peer to/from  existing P2P group: JoinP2PGroup(), LeaveP2PGroup(). OnP2PMemberJoin and so on will be called at client.

	Roles as relay server
	- As long as using HostID, P2P connection occurs virtually as well.
	For an example, even if the opponent is a member of P2P group, between clients that P2P connection was not successful in real then RMI is successfully sent to opponent's HostID.
	Relay server manages the carrying.
	Tough for same RMI reception message, it is to read RmiContext.m_relayed at RMI read part to get whether went through relay server.

	Thread pooling
	- Basically uses thread pool. So there must be at least 1 or more thread when server starts.
	- When turning thread pooling off is better: server with 1 CPU and all it does is CPU time process (e.g. relay server)
	- When turning thread pooling on is better: server with multip CPU or server that has often device time process (e.g. MMO game server)
	- Since thread pool function is called when CoInitialize()is ready there is no need to call CoInitialize() or CoUninitialize().

	Server performance related to number of UDP host port
	- Can designate number of UDP host port as server port parameter of CNetServer.Start
	Client will be connected to one of the ports among parameter when connected to server.

	Success rate of P2P direct communication note
	- Direct P2P communication will be successful when an end of P2P is real IP, Full-cone NAT.
	- When game server operatedbehind NAT it is necessary to enter server address to Start(). (Please refer Start() manual.)
	However, there will be no direct P2P communication between the client run by other host that is in front of game server and behind of NAT and the client of outer internet.
	This is because the internal IP of NAT will be recognized other than outer internet address by NAT device in server.

	\~chinese
	\brief ��?��??��?�

	��?��??��?�??���<a target="_blank" href="http://guide.nettention.com/cpp_zh#server_overview" >ProudNet ��?��</a>%�졣
	- �ʦ��MMO��?���ġ�
	- ��� CNetClient%��?�ȡ�
	- ���?client����Host ID�����ġ�
	- ?RMIʦ��Host ID?��?��
	- ?���������?��?�����������??��
	- ��client��?P2P?�ȡ����?��?���client��?P2P?����?��?��?��relay��?�������ġ�

	��������۰��
	- �����?�ڡ����� Proud.CNetServer.Create()��
	- ��Start()?���?�
	- ??INetServerEvent������?? INetServerEvent.OnClientJoin()����
	?����?client?������event handler��
	- ?�?��SetEventSink()?event handler������AttachProxy(), AttachStub()?����?�߾��?����������RMIͣ����

	?��P2P?��?��
	- ?�� CNetServer%��clientʦ�?����?�߾��P2P?��
	?��P2P?��client��?ʦ��Host ID?���������?RMI��
	- ����/?���P2P group��������?����?����
	��?CreateP2PGroup(),DestroyP2PGroup()���client��УOnP2PmemberJoin����
	- ��peer������P2P group��ʥ/?𶣺
	JoinP2PGroup(), LeaveP2PGroup()���client��УOnP2PMemberJoin����

	Relay server������
	- ?������Host ID��P2P?��?????������?����P2P?��??߾??��������Peer��?��?۰?��P2P group��??����?۰Host ID��RMI?������?��??۰��Relay server���??�����ġ�?����������������ӣ����Գ?����?�relay server��?�RMI���ݻ? RmiContext.m_relayed%?ʦ��

	?��pooling
	- ����Դ����?��pool������?��?�?��������??��?��
	- ???��pool����?��������?������?CPU��CPU time?������ݻ����?�����relay��?���
	- ???��pool����?��������?����CPU���device time?��?������?�����MMO��?��?���
	- ?��pool��?�CoInitialize()��?��??����У���������CoInitialize()���CoUninitialize()

	UDP���ӮϢ??��?��?��������
	- �� CNetServer.Start%����?��ӮϢ??ʦ����UDP���ӮϢ??��
	Client?��?��?����?����??�������ӮϢ����?��?��?��?�ȡ�

	P2P������������ʦ����??��
	- P2P��?��۰real IP, Full-cone NAT ��?��direct P2P��������
	- ��?��?���NAT����??��?�����Start()?����?���򣡣��????��Start()?٥��
	ӣ?��??����?��?��������NAT������������������?����client����ݻ��??client��?����������ʿ��???�� ��?������?����NAT?�ǣ���??��������ݻ��??�߾�����?ݻIP��

	\~japanese
	\brief ��?���īͫëȫ�?����?��?
	��?���īͫëȫ�?����?��?�Ǫ����٪����ϡ�\ref server_overview�˪���ު���
	- MMO ��?��˪��Ū��ު���
	- CNetClient �������?�������ު���
	- ���髤����Ȫ�HostID���ܪ�?�ƪ���ܪ򪷪ު���
	- HostID����˿?�Ȫ���RMI��ʦ���˪��ު���
	- �����ܪʫ�?�૵?��?����驪������ܪʫ��׫�������Ҫ���ƪ��ު���
	- ���髤��������P2P��?�򫵫�?�Ȫ��ު������Ϋ�?��?���֫������Ȫϫ��髤��������P2P��?�������������ꡢ���?��?��?��ܪ򫵫�?�Ȫ��ު���

	�����ܪ�����
	- ���Ϋ��֫������Ȫ��������ު���Proud.CNetServer.Create() ����
	- Start()�ǫ�?��?����㷪��ު���
	- INetServerEvent��?�ު��ު���?��INetServerEvent.OnClientJoin()�ʪɪ�?�ު��ު���
	�����ϫ��髤�������?�ʪɪ�?���뫤�٫�ȫϫ�ɫ�?�Ǫ���
	- �������SetEventSink()�ǫ��٫�ȫϫ�ɫ�?���ڪ�ǡ�AttachProxy()��AttachStub()���Ūê�1���߾������ު���������RMI����?�ի�?����֧�ͪ��ު���

	P2P��?����?������
	- CNetServer ����?���쪿���髤����Ȫ�1���߾��P2P����?�ת��ª몳�Ȫ��Ǫ��ު���
	P2P����?�ת��ڪ��ƪ��뫯�髤�������Ǫ�HostID������RMI��������Ǫ��ު���
	- �檷��P2P group������/��۪��룺��?��?�Ϊߪ�?�ڪ�����ު���
	CreateP2PGroup(),DestroyP2PGroup()���ת������髤����ȪǪ�OnP2PMemberJoin�ʪɪ������󪵪�ު���
	- peer��?�������P2P group����ʥ?��۪��룺
	JoinP2PGroup(), LeaveP2PGroup(). ���髤����ȪǪ�OnP2PMemberJoin�ʪɪ������󪵪�ު���

	Relay server�Ȫ��ƪ����
	- HostID���Ū��ڪꡢP2P��?��?�̪Ǫ������ު����Ǫ��С�P2P��?��?�˪ު������ʪ��ê�Peer��Ǫ���⢪�P2P group��?���ƪ������⢪�HostID�����RMI�������ܪ���⢪������ު���relay server����Բ��ܪ�??���ު���
	�Ҫ�RMI�����ë�?���Ǫ⪽�쪬relay server����પ����Ϊ��ɪ�������몿��˪ϡ�RMI����ݻ��RmiContext.m_relayed��?��Ъ����Ǫ���

	����ëɫ�?���
	- �����ܪ˫���ëɫ�?������Ī��ު�����êơ���?��?������˫���ë�?����᳣�������Ҫ��ʪ���Ъʪ�ު���
	- ����ëɫ�?���Ѧ���򫪫ժ���Ϊ����ת����꣺1����CPU�Ǫ���ʪ���CPU time?�⪬��ݻ�Ǫ��뫵?��?(�Ǫ��С����?��?��?)
	- ����ëɫ�?���Ѧ���򫪫󪹪�Ϊ����ת����꣺�ޫ��CPU�ު���device time?�⪬޺��ʫ�?��?(�Ǫ��С�MMO��?�૵?��?)
	- ����ëɫ�?��??�ϡ�CoInitialize()�����᪵�쪿?���������󪵪�ު��Ϊǡ��ު���CoInitialize()�Ȫ�CoUninitialize()�������󪷪���驡�

	UDP�۫��ȫ�?��?��?֧���뫵?��?����
	- CNetServer.Start�Ϋ�?��?��?�ȫѫ��?��?��UDP�۫��ȫ�?��?����Ҫ��몳�Ȫ��Ǫ��ު���
	���髤����Ȫϫ�?��?����?�������˫ѫ��?��?�˪����?�ȪΪ�����Īǫ�?��?����?���ު���

	P2P������������ʦ������?��
	- P2P��������real IP, Full-cone NAT�Ǫ������ꡢdirect P2P���᪬�����ު���
	- ��?�૵?��?��NAT����������Ѫ������ꡢStart()�˫�?��?���ɫ쫹���������驪�����ު���(�٪�����Start()��?٥��?�Ϊ���������)
	ӣ�������Ϊ誦�˪���Ȫ��ƪ⡢��?�૵?��?�����NAT������˪�����Ϋ۫��Ȫ�?������뫯�髤����Ȫ���ݻ����?�ͫëȪΫ��髤������������P2P�����?�ު���ު��󡣫�?��?�˪���NAT?�Ǫ˪�ê���ݻ����?�ͫëȫ��ɫ쫹�������NAT��?ݻIP�����۪���몫��Ǫ���

	\~
	*/
	class CNetServer : public IRmiHost, public HasCoreEventFunctionObjects
	{
	public:
		virtual ~CNetServer() {}

		/**
		\~korean
		�� �ν��Ͻ��� �����մϴ�.

		\~english
		Creates new instance.

		\~chinese
		��������?�ǡ�

		\~japanese
		�檷�����󫹫��󫹪��������ު���
		\~
		*/
		static CNetServer* Create();

		/**
		\~korean
		Ŭ���̾�Ʈ �Ǵ� ä�� �׷쿡 ���� ��� Ŭ���̾�Ʈ�� �ѾƳ���.
		\return �ش� Ŭ���̾�Ʈ�� ������ false.

		\~english
		Kicks out all clients in client group and/or chatting group
		\return false if there is no realted client.

		\~chinese
		?��?��Client�������?�����client��
		\return ?����?client��?false��

		\~japanese
		���髤����Ȫު��ϫ���ëȫ���?�ת�?������ƪΫ��髤����Ȫ��ڪ��󪷪ު���
		\return ��?���髤����Ȫ��ʪ����false.

		\~
		*/
		virtual bool CloseConnection(HostID clientHostID) = 0;

		/**
		\~korean
		��� Ŭ���̾�Ʈ�� �߹��Ѵ�.

		\~english
		Kicks out all clients

		\~chinese
		?�����client��

		\~japanese
		��ƪΫ��髤����Ȫ��ڪ��󪷪ު���
		\~
		*/
		virtual void CloseEveryConnection() = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P �׷�</a> �� �����մϴ�. 
		- �̷��� ������ �׷� ���� �Ǿ�鳢���� ��� ���ΰ� �޽�¡�� �ص� �˴ϴ�.  (����: <a target="_blank" href="http://guide.nettention.com/cpp_ko#robust_p2p" >ProudNet�� P2P ��� ����</a>)
		- Ŭ���̾�Ʈ ���(clientHostIDs,clientHostIDNum)�� ���� ��� �̹� ����� ä���� �ִ� P2P group�� �����Ѵ�. 
		�� �� �迭�� ���� ��� ��� 0��¥�� P2P �׷��� ������ �� �ִ�. (��, AllowEmptyP2PGroup �� ���� �ٸ���.) 
		- �� �޼��� ȣ�� ��, CNetClient ������ P2P �׷��� �� ����� ����(�ڱ� �ڽ� ����) 
		INetClientEvent.OnP2PMemberJoin �� ���̾ ȣ��ȴ�.
		- HostID_Server �� ���� �Ǵ��� ���δ� <a target="_blank" href="http://guide.nettention.com/cpp_ko#server_as_p2pgroup_member" >P2P �׷� ����μ� ������ ���Խ�Ű��</a> �� �����Ͻʽÿ�. 

		\param clientHostIDs ���� P2P �׷��� ��� ����Ʈ. HostID_Server �� ����� �Ұ����ϴ�. count=0�϶� �� ���� ���õȴ�. 
		\param count clientHostIDs�� �迭 ��� ����. 0�� ���� ��� ����� ���� P2P group �� �������� �ǹ��Ѵ�. 
		\param customField P2P �׷��� �߰��ϸ鼭 �������� ���� Ŭ���̾�Ʈ�鿡�� ������ �޽���. �����ϼŵ� �˴ϴ�. 
		- INetClientEvent.OnP2PMemberJoin ���� �״�� �޾����ϴ�. 
		\param option P2P �׷� ���� �������� ����ڰ� �����ϰ� ���� �߰� �ɼ��Դϴ�. �����ϼŵ� �˴ϴ�. 
		\param assignedHostID ����ڰ� ���ϴ� HostID �� ���� P2P �׷��� ������ �� �ֽ��ϴ�. �⺻���� None�Դϴ�. None�� �����ϸ� �ڵ� �Ҵ�˴ϴ�. ���� �̹� ������� HostID �� �Է��� ��� P2P group ������ �����ϰ� None�� ������ �� �ֽ��ϴ�.
		\return ������� P2P �׷��� Host ID �Դϴ�. Ÿ���� HostID �Դϴ�.

		\~english 
		Generate a <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a>. 
		- The peers in the group generated in this way can do messaging with one another immediately (<a target="_blank" href="http://guide.nettention.com/cpp_en#robust_p2p" >P2P performance of ProudNet</a>)
		- After calling this method, for each member of P2P group(including itself), INetClientEvent.OnP2PMemberJoin will be called one after another to CNetClient.
		When you insert an empty array, you can generate a P2P group with 0 members (however, it depends on AllowEmptyP2PGroup).
		- After calling this method, in CNetClient, INetClientEvent.OnP2PMemberJoin is called continuously to each member of the P2P group (including itself).
		- To find out whether HostID_Server can enter or not, please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#server_as_p2pgroup_member" >How to include a server as a peer - to - peer group member</a> .

		\param clientHostIDs The member list of the P2P group to make clientHostIDs. HostID_Server is not possible as a member. When count=0, this value is ignored. 
		\param count The number of array elements of clientHostIDs. If you input 0, it means it will generate a P2P group without a member. 
		\param The message to be sent to the related clients from the server when a P2P group is added. You can skip it. 
		- It is received in INetClientEvent.OnP2PMemberJoin as it is. 
		\param This is an additional option that users want to designate during creation of a P2P group. You can skip it. 
		\param You can create a P2P group with the HostID users want. The default value is None. If you select None, it is automatically allocated. If you enter a HostID already being used, P2P group creation will fail and None can be returned. 
		\return HostID of the created P2P group. The type is HostID.  

		\~chinese
		����<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%��
		- ??������??peer��?ʦ�ء??��������?��messaging����?�ţ�<a target="_blank" href="http://guide.nettention.com/cpp_zh#robust_p2p" >ProudNet ��P2P��������</a>��
		- ���client��?��clientHostIDs,clientHostIDNum����?�����??����?��P2P group��
		- ?����??��?������0?��?��P2P?����ӣ����AllowEmptyP2Pgroup?������ң�
		- ��У�۰����?P2P?����?��?�������������� CNetClient%??��У INetClientEvent.OnP2PmemberJoin��
		- HostID_Server ������?��??��<a target="_blank" href="http://guide.nettention.com/cpp_zh#server_as_p2pgroup_member" >�P2P��?��?������?��</a>%��

		\param clientHostIDs �?����P2P?��?list�� HostID_Server ��ʦ����?��?��Count=0?����?��
		\param count clientHostIDs��??����??��?��0��?��ګ�����?����?��P2Pgroup
		\param customField ��ʥP2P?��?ʦ�������?������?client?�������ӡ�
		- � INetClientEvent.OnP2PMemberJoin%��?������⥡�

		\param option �P2P?������?������?����������ʥ??��ʦ����ԡ�
		\param assignedHostID ʦ����������?������HostID��P2P?������?��None���������?None??�??�����ա�����?������������ HostID%��?����P2P group??��?������Return None��
		\return ?����P2P?Host ID��?����Host ID��

		\~japanese
		\ref p2p_group ���������ު���
		- ���Ϊ誦��������������?��?��Peer��������˫�?��?��ǫ�ë�?���󫰪򪷪ƪ��ު��Ǫ���(?�ţ� \ref robust_p2p)
		- ���髤����ȫ꫹��(clientHostIDs,clientHostIDNum)�����������ꡢ?�˫���?��?������ƪ���P2P group���������ު���
		������֪����������ꡢ����?0����P2P����?�ת��������몳�Ȫ��Ǫ��ު���(ӣ����AllowEmptyP2PGroup �˪�ê��ު��ު���)
		- ���Ϋ᫽�ëɪ�����������CNetClient�Ǫ�P2P����?�ת�������?��?����(��������ߪ�)
		INetClientEvent.OnP2PMemberJoin��?�����������󪵪�ު���
		- HostID_Server �����êƪ��ު��Ϊ��ɪ����ϡ�\ref server_as_p2pgroup_member��?�Ϊ���������
		\param clientHostIDs �ª�P2P����?�תΫ���?�꫹�ȡ�HostID_Server�ϫ���?����ʦ���Ǫ���count=0�Ǫ������������������ʪ���ު���
		\param count clientHostIDs����֪���?��0����������ꡢ����?���ʪ�P2P group���������몳�Ȫ���ګ���ު���
		\param customField P2P����?�ת���ʥ���ʪ��顢��?��?��?֧���髤����Ȫ�����ë�?�������Ԫ��ƪ��ު��Ǫ���
		- INetClientEvent.OnP2PMemberJoin �Ǫ��Ϊު��������ު���
		\param option P2P ����?�ת�����Φ��ǫ�?��?����Ҫ�������ʥ���׫����Ǫ������Ԫ��ƪ��ު��Ǫ���
		\param assignedHostID ��?��?���Ъ�HostID����P2P����?�ת��������몳�Ȫ��Ǫ��ު�����������None�Ǫ���None����Ҫ��������ܪ�?�ƪ��ު����⪷��?��������Ǫ���HostID�������������ꡢP2P group���������������ơ�None��꫿?��Ǫ��ު���
		\return �ª�쪿P2P����?�ת�Host ID�Ǫ��������ת�HostID�Ǫ���

		\~
		*/
		virtual HostID CreateP2PGroup(const HostID* clientHostIDs, int count, ByteArray customField = ByteArray(), CP2PGroupOption &option = CP2PGroupOption::Default, HostID assignedHostID = HostID_None) = 0;

		/**
		\~korean
		����� ���� P2P �׷��� ����ϴ�.
		- AllowEmptyP2PGroup ������ ���� �׷� ������ ������ ���� �ִ�.
		\param customField P2P �׷��� �߰��ϸ鼭 �������� ���� Ŭ���̾�Ʈ�鿡�� ������ �޽����Դϴ�. �����ϼŵ� �˴ϴ�.
		\param assignedHostID ����ڰ� ���ϴ� HostID �� ���� P2P �׷��� ������ �� �ֽ��ϴ�. �⺻���� None�Դϴ�. None�� �����ϸ� �ڵ� �Ҵ�˴ϴ�. ���� �̹� ������� HostID �� �Է��� ��� P2P group ������ �����ϰ� None�� ������ �� �ֽ��ϴ�.
		\return ������� P2P �׷��� Host ID �Դϴ�. Ÿ���� HostID �Դϴ�.

		\~english 
		Create a P2P group without a member. 
		- Group creation may fail depending on the AllowEmptyP2PGroup configuration. 
		\param customField This is the message sent to related clients from the server when adding a P2P group. You can skip it. 
		\param You can create a P2P group with the HostID users want. The default value is None. If you select None, it is automatically allocated. If you enter a HostID already being used, P2P group creation will fail and None can be returned.
		\return HostID of the created P2P group. The type is HostID.

		\~chinese
		?��?����?��P2P?��
		- ����AllowEmptyP2PGroup?�ǣ�?������ʦ��?��?��
		\param customField ��ʥP2P?��?ʦ�������?������?client?�������ӡ�
		\return ?����P2P?��Host ID��?����HostID��

		\~japanese
		����?�Ϊʪ�P2P����?�ת��ª�ު���
		- AllowEmptyP2PGroup ���Ҫ˪�êƫ���?���������������몳�Ȫ⪢��ު���
		\param customField P2P ����?�ת���ʥ���ʪ��髵?��?��?֧���髤����Ȫ�����ë�?���Ǫ������Ԫ��ƪ��ު��Ǫ���
		\param assignedHostID ��?��?���Ъ�HostID����P2P����?�ת��������몳�Ȫ��Ǫ��ު�����������None�Ǫ���None����Ҫ��������ܪ�?�ƪ��ު����⪷��?��������Ǫ���HostID�������������ꡢP2P group����������������None��꫿?��Ǫ��ު���
		\return �ª�쪿P2P����?�ת�Host ID�Ǫ��������ת�HostID�Ǫ���

		\~
		*/
		inline HostID CreateP2PGroup(ByteArray customField = ByteArray(), CP2PGroupOption &option = CP2PGroupOption::Default, HostID assignedHostID = HostID_None)
		{
			return CreateP2PGroup(NULL, 0, customField, option, assignedHostID);
		}

		/**
		\~korean
		1�� ����� ������ P2P �׷��� ����ϴ�.
		- �̷��� ������ �׷� ���� �Ǿ�鳢���� ��� ���ΰ� �޽�¡�� �ص� �˴ϴ�. (����: \ref robust_p2p) 

		\param memberID �׷쿡 ó�� �� ���� ����� HostID �Դϴ�.
		\param customField P2P �׷��� �߰��ϸ鼭 �������� ���� Ŭ���̾�Ʈ�鿡�� ������ �޽����Դϴ�. �����ϼŵ� �˴ϴ�.
		\param assignedHostID ����ڰ� ���ϴ� HostID �� ���� P2P �׷��� ������ �� �ֽ��ϴ�. �⺻���� None�Դϴ�. None�� �����ϸ� �ڵ� �Ҵ�˴ϴ�. ���� �̹� ������� HostID �� �Է��� ��� P2P group ������ �����ϰ� None�� ������ �� �ֽ��ϴ�.
		\return ������� P2P �׷��� Host ID �Դϴ�. Ÿ���� HostID �Դϴ�.

		\~english 
		You can create a P2P group consisted of one member
		- The peers in the group generated in this way can do messaging with one another immediately (refer to: \ref robust_p2p)

		\param memberID The HostID of the member when joining the group for the first time. 
		\param customField This is the message sent to related clients from the server when adding a P2P group. You can skip it.
		\param You can create a P2P group with the HostID users want. The default value is None. If you select None, it is automatically allocated. If you enter a HostID already being used, P2P group creation will fail and None can be returned.
		\return HostID of the created P2P group. The type is HostID.

		\~chinese
		?�����?��??����P2P?��
		- ??������??peer��?ʦ�ء??��������messaging����?�ţ�<a target="_blank" href="http://guide.nettention.com/cpp_en#robust_p2p" >P2P performance of ProudNet</a>��
		\param memberID ����?��?����?Host ID��
		\param customField ��ʥP2P?��?ʦ�������?������?client?�������ӡ�
		\param assignedHostID ʦ����������?������HostID��P2P?������?��None���������?None??�??�����ա�����?������������ HostID%��?����P2P group??��?������Return None��
		\return ?����P2P?��Host ID��?����HostID��

		\~japanese
		1���Ϋ���?����ϰ�����쪿P2P����?�ת��ª�ު���
		- ���Ϊ誦��������������?��?��Peer��Ǫϡ������˪�������ë�?���󫰪򪷪ƪ��ު��Ǫ���(?�ţ�\ref robust_p2p)
		\param memberID ����?�ת���������êƪ������?��HostID�Ǫ���
		\param customField P2P ����?�ת���ʥ���ʪ��顢��?��?��?֧���髤����Ȫ�����ë�?���Ǫ������Ԫ��ƪ��ު��Ǫ���
		\param assignedHostID ��?��?���Ъ�HostID����P2P����?�ת��������몳�Ȫ��Ǫ��ު�����������None�Ǫ���None����Ҫ��������ܪ�?�ƪ��ު����⪷��?��������Ǫ���HostID�������������ꡢP2P group�������������ơ�None��꫿?��Ǫ��ު���
		\return �ª�쪿P2P����?�ת�Host ID�Ǫ��������ת�HostID�Ǫ���

		\~
		*/
		inline HostID CreateP2PGroup(HostID memberID, ByteArray customField = ByteArray(), CP2PGroupOption &option = CP2PGroupOption::Default, HostID assignedHostID = HostID_None)
		{
			return CreateP2PGroup(&memberID, 1, customField, option, assignedHostID);
		}

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P �׷�</a> �� �ı��Ѵ�.
		- �ȿ� �ִ� ��� member���� P2P �׷쿡�� Ż��ȴٴ� �̺�Ʈ(Proud.INetClientEvent.OnP2PMemberLeave)�� ��Ƽ�޴´�.
		����, �������� ������ �����ȴ�.
		\param groupHostID �ı��� P2P �׷��� ID
		\return �ش� P2P �׷��� ������ false.

		\~english
		Destructs <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a>
		- All members within will receive an event(Proud.INetClientEvent.OnP2PMemberLeave) that they will be withdrawn from P2P group. Of course, the connection to server will be sustained.
		\param groupHostID ID of P2P group to be destructed
		\return false if there is no P2P group related

		\~chinese
		��?<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%��
		- ����������member�����?P2P?������event��Proud.INetClientEvent.OnP2PMemberLeave����
		?�ԣ�???�?��?����?�ȡ�
		\param groupHostID ���?��P2P?ID��
		\return ?����?P2P?��?false��

		\~japanese
		\ref p2p_group ����?���ު���
		- ?ݻ�˪��ê���ƪΫ���?�ϡ�P2P����?�ת��?�ܪ����Ȫ������٫��(Proud.INetClientEvent.OnP2PMemberLeave)����򱪷�ƪ�骤�ު���
		ڨ�塢��?��?�Ȫ���?���򥪵��ު���
		\param groupHostID ��?����P2P����?�ת�ID
		\return ��?P2P����?�ת��ʪ����false.

		\~
		*/
		virtual bool DestroyP2PGroup(HostID groupHostID) = 0;

		/**
		\~korean
		������ �����Ǿ� �ִ� ��� <a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P �׷�</a> �� ������, ����� ���� ���� P2P �׷츸 ��� ��� �ı��Ѵ�.

		\~english
		Search all <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a> that is created within server then destructs all P2P groups consist of 0 member.

		\~chinese
		??���?����������� <a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%����???����?��P2P?����ݻ��?��

		\~japanese
		��?��?����������ƪ�����ƪ�\ref p2p_group�������ơ�����?���絛�ʪ�P2P����?�ת������Ԫ�������?���ު���
		\~
		*/
		virtual void DestroyEmptyP2PGroups() = 0;

		/**
		\~korean
		���� ��Ȳ�� ���ڿ��� �����Ѵ�. ����׿����� �����ϴ�.

		\~english
		Returns internal status as text string. Useful when debugging.

		\~chinese
		���ݬ������?ݻ��?��ʦ����??�ġ�

		\~japanese
		?ݻ?�Ϫ����֪�ǫ꫿?�󪷪ު����ǫЫë��Ī��Ū�?��������ު���
		\~
		*/
		virtual String DumpGroupStatus() = 0;

		/**
		\~korean
		������ Ŭ���̾�Ʈ ������ ��´�.

		\~english
		Gets the number of connected clients

		\~chinese
		?��?����client??��

		\~japanese
		��?�������髤�����?����ު���
		\~
		*/
		virtual int GetClientCount() = 0;

		/**
		\~korean
		���� ó���� ��踦 ��´�.

		\~english
		Gets server process statistics

		\~chinese
		?����?��?����??��

		\~japanese
		��?��??�������ͪ����ު���
		\~
		*/
		virtual void GetStats(CNetServerStats &outVal) = 0;

		/**
		\~korean
		Ŭ���̾�Ʈ HostID ����� ��´�.
		- �� �޼���� ��� ����� ȣ���� ������ �������� ���̴�. �� �Լ��� ���ϵ� �Ŀ���
		Ŭ���̾�Ʈ ����� ������ ���� ������ ���¿� �������� ���������� �ʴ´�.
		���� ��Ȯ�� Ŭ���̾�Ʈ ����Ʈ�� ����� �ϸ� INetServerEvent.OnClientJoin,
		INetServerEvent.OnClientLeave ���� ������ �ʿ�� �ϴ� Ŭ���̾�Ʈ ����Ʈ�� ����
		����� �����ϴ� ���� �����Ѵ�.
		\param output HostID ����� ä���� ��
		\param outputLength ����� �ִ� ũ��
		\return ���� ä���� �׸��� ����

		\~english
		Gets client HostID list
		- The list acquired by this method is only a snapshot. After this function is returned, there is no guarantee that the contents in the list matche the status of real server.
		Therefore, in order to get precise client list, it is recommended to create and manage a separate client list needed by user at INetServerEvent.OnClientJoin, INetServerEvent.OnClientLeave.
		\param output Where HostID list to be filled
		\param outputLength Maximum size of the list
		\return The number of clause really filled

		\~chinese
		?��client Host ID��?��
		- ���۰��?������?�������У��?����snapshot�쫡����?�����������?client��?��?�???��?��??���ҡ�
		����?����?��client list��?����?� INetServerEvent.OnClientJoin,
		INetServerEvent.OnClientLeave%?��?��?η����?�����client list��
		\param output HostID��??�����۰��
		\param outputLength ��?��������᳡�
		\return ???����?��??��

		\~japanese
		���髤�����Host ID�꫹�Ȫ���ު���
		- ���Ϋ᫽�ëɪ����꫹�Ȫ����������êΫ��ʫë׫���ëȪǪ�������Ǫ�������??���꫿?�󪵪쪿���˪⫯�髤����ȫ꫹�Ȫ�?黪�?𷫵?��?��?�����Ҫ��Ǫ��몳�Ȫ�����몳�ȪϪ���ު���
		��êơ������ʫ��髤����ȫ꫹�Ȫ��𪿪�����ϡ�INetServerEvent.OnClientJoin, INetServerEvent.OnClientLeave�ǫ�?��?����驪Ȫ��뫯�髤����ȫ꫹�Ȫ�ܬ���ªê�η�⪹�몳�Ȫ�?�᪷�ު���
		\param output HostID �꫹�Ȫ�?��������
		\param outputLength �꫹�Ȫ����ޫ�����
		\return ?�?�����쪿���ͪ�?

		\~
		*/
		virtual int GetClientHostIDs(HostID* output, int outputLength) = 0;

		/**
		\~korean
		clientHostID�� ����Ű�� peer�� �����ϰ� �ִ� P2P group ����Ʈ�� ��´�.

		\~english
		Gets P2P group list of peer that is pointed by clientHostID

		\~chinese
		?��clientHostID����peer??��P2P group list��

		\~japanese
		clientHostID��򦪹Peer��?ʥ���ƪ���P2P group �꫹�Ȫ���ު���
		\~
		*/
		virtual bool GetJoinedP2PGroups(HostID clientHostID, HostIDArray& output) = 0;

		/**
		\~korean
		Ŭ���̾�Ʈ�� ������ �����Ͻø� ��´�.
		\param clientID ã������ Ŭ���̾�Ʈ�� HostID.
		\return ping time�� �и��ʴ����� �����Ѵ�. �� ������ -1�� �����Ѵ�.

		\~english
		Gets the last latency of client
		\param clientID HostID of client to find
		\return returns ping time in millisecond. Returns -1 when there is none.

		\~chinese
		?��client������latency��
		\param clientID �?��client��Host ID��
		\return ping��time�����?�����ޡ�ӣ?����?����-1��

		\~japanese
		���髤����Ȫ������Ϋ�?�ƫ�?����ު���
		\param clientID �����������髤����Ȫ�HostID.
		\return ping time��߫���?�Ȫǫ꫿?�󪷪ު���ӣ�����ʪ����-1��꫿?�󪷪ު���

		\~
		\~
		*/
		inline double GetLastPingSec(HostID clientID, ErrorType* error = NULL)
		{
			int ms = GetLastUnreliablePingMs(clientID, error);

			if (ms < 0)
				return (double)ms;

			return ((double)ms) / 1000;
		}

		/**
		\~korean
		Ŭ���̾�Ʈ�� ������ �����Ͻø� ��´�.
		\param clientID ã������ Ŭ���̾�Ʈ�� HostID.
		\return ping time�� �и��ʴ����� �����Ѵ�. �� ������ -1�� �����Ѵ�.

		\~english
		Gets the last latency of client
		\param clientID HostID of client to find
		\return Returns ping time in millisecond.Returns -1 when there is none.

		\~chinese
		?��client������latency��
		\param clientID �?��client��Host ID��
		\return ping��time�����?�����ޡ�ӣ?����?����-1��

		\~japanese
		���髤����Ȫ������Ϋ�?�ƫ�?����ު���
		\param clientID �����������髤����Ȫ�HostID.
		\return ping time��߫���?�Ȫǫ꫿?�󪷪ު���ӣ�����ʪ����-1��꫿?�󪷪ު���

		\~
		*/
		virtual int GetLastUnreliablePingMs(HostID clientID, ErrorType* error = NULL) = 0;

		/**
		\~korean
		Ŭ���̾�Ʈ�� �ֱ� �����Ͻø� ��´�.
		\param clientID ã������ Ŭ���̾�Ʈ�� HostID.
		\return ping time�� �ʴ����� �����Ѵ�. �� ������ -1�� �����Ѵ�.

		\~english
		Gets the recent latency of client
		\param clientID HostID of client to find
		\return Returns ping time in millisecond. Returns -1 when there is none.

		\~chinese
		?��client������latency��
		\param clientID �?��client��Host ID��
		\return ping��time�����?�����ޡ�ӣ?����?����-1��

		\~japanese
		���髤����Ȫ����Ϋ�?�ƫ�?����ު���
		\param clientID �����������髤����Ȫ�HostID.
		\return ping time����?�Ȫǫ꫿?�󪷪ު���ӣ�����ʪ����-1��꫿?�󪷪ު���

		\~
		*/
		inline double GetRecentPingSec(HostID clientID, ErrorType* error = NULL)
		{
			int ms = GetRecentUnreliablePingMs(clientID, error);

			if (ms < 0)
				return (double)ms;

			return ((double)ms) / 1000;
		}

		/**
		\~korean
		Ŭ���̾�Ʈ�� �ֱ� �����Ͻø� ��´�.
		\param clientID ã������ Ŭ���̾�Ʈ�� HostID.
		\return ping time�� �и��ʴ����� �����Ѵ�. �� ������ -1�� �����Ѵ�.

		\~english
		Gets the recent latency of client
		\param clientID HostID of client to find
		\return Returns ping time in millisecond.Returns -1 when there is none.

		\~chinese
		?��client������latency��
		\param clientID �?��client��Host ID��
		\return ping��time�����?�����ޡ�ӣ?����?����-1��

		\~japanese
		���髤����Ȫ����Ϋ�?�ƫ�?����ު���
		\param clientID �����������髤����Ȫ�HostID.
		\return ping time��߫���?�Ȫǫ꫿?�󪷪ު���ӣ�����ʪ����-1��꫿?�󪷪ު���

		\~
		*/
		virtual int GetRecentUnreliablePingMs(HostID clientID, ErrorType* error = NULL) = 0;

		/**
		\~korean
		�� �Ǿ�� �ֱ� �� ������ �޽��ϴ�.

		\~english
		Gets recent ping information between two peers

		\~chinese
		���??peer��?������ping���ӡ�

		\~japanese
		��Peer�������ping���ê������ު���
		\~
		*/
		virtual int GetP2PRecentPingMs(HostID HostA, HostID HostB) = 0;

		/**
		\~korean
		P2P group 1���� ������ ��´�.

		\~english
		Gets the information of 1 P2P group

		\~chinese
		?��P2P group��?���ӡ�

		\~japanese
		P2P group 1�������ê���ު���
		\~
		*/
		virtual bool GetP2PGroupInfo(HostID groupHostID, CP2PGroup &output) = 0;

		/**
		\~korean
		HostID �� ��ȿ���� Ȯ���Ѵ�.
		\param id ��ȿ���� Ȯ���� HostID.
		\return true�̸� ��ȿ�� Ŭ���̾�Ʈ, ���� Ȥ�� <a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P �׷�</a> �� HostID���� �ǹ��Ѵ�.

		\~english
		Checks if HostID is valid
		\param id HostID to be used to check if valid
		\return true then valid HsstID of client or server or <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a>

		\~chinese
		??Host ID����������
		\param id �??������������Host ID��
		\return true��?������client����ګ�����?�����<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%��Host ID��

		\~japanese
		HostID ����?�ʪΪ������㪷�ު���
		\param id ��?�ʪΪ������㪹�� HostID.
		\return true�Ǫ������?�ʫ��髤����ȡ���?��?�ު���\ref p2p_group��HostID����ګ���ު���

		\~
		*/
		virtual bool IsValidHostID(HostID id) = 0;

		/**
		\~korean
		��� P2P group list�� ��´�.
		- �纻 ī�Ǹ� �Ѵ�.

		\~english
		Gets all P2P group list
		- Makes a back up copy

		\~chinese
		?�����P2P group list��
		- ?�����⡣

		\~japanese
		��ƪ�P2P group list����ު���
		- ����?���ު���

		\~
		*/
		virtual void GetP2PGroups(CP2PGroups& output) = 0;

		/**
		\~korean
		�����Ǿ� �ִ� P2P group�� �� ������ ��´�.

		\~english
		Gets the total number of opened P2P group.

		\~chinese
		?��??��P2P group��???��

		\~japanese
		���⪵��ƪ���P2P group��??����ު���
		\~
		*/
		virtual int GetP2PGroupCount() = 0;

		/**
		\~korean
		�� ��ü�� ����� peer 1���� ������ ��´�.
		\param peerHostID ã������ peer�� HostID
		\param output ã�� peer�� ����. �� ã���� �ƹ��͵� ä������ �ʴ´�.
		\return true�̸� ã�Ҵٴ� ��

		\~english
		Gets the information of 1 peer connected to this object
		\param peerHostID HostID of peer to find
		\param output Infoof foudn peer. Nothing will be filled when found nothing.
		\return true when found

		\~chinese
		?��?��?�?������?peer���ӡ�
		\param peerHostID �?��peer��HostID��
		\param output ?����peer���ӡ�?��?����?��?������?ड�
		\return true��?���������֡�

		\~japanese
		���Ϋ��֫������Ȫ���?���쪿Peer 1�������ê���ު���
		\param peerHostID ��������Peer��HostID
		\param output ������Peer�����á������ʪ��ê�������?������ު���
		\return true�Ǫ�����������Ȫ�����ګ

		\~
		*/
		virtual bool GetClientInfo(HostID clientHostID, CNetClientInfo& output) = 0;

		/**
		\~korean
		clientHostID�� ����Ű�� Ŭ���̾�Ʈ�� ���������� üũ�Ѵ�.
		\return �������� Ŭ���̾�Ʈ�̸� true�� �����Ѵ�.

		\~english
		Checks if the client pointed by clientHostID is logged on
		\return if found to be logged on client then returns true

		\~chinese
		??clientHostID����client������?���顣
		\return ?������client��?����true��

		\~japanese
		clientHostID��򦪹���髤����Ȫ���?��ʪΪ�������ë����ު���
		\return ��?��Ϋ��髤����ȪǪ����ture��꫿?�󪷪ު���

		\~
		*/
		virtual bool IsConnectedClient(HostID clientHostID) = 0;

		/**
		\~korean
		GetClientInfo�� ���� ������ �ϸ�, ���� �� �̻� �Ⱦ��� �Լ���. ��� GetClientInfo�� ����ϴ� ���� �����Ѵ�.

		\~english
		Performs roles as GetClientInfo but not to be used any more. It is recommended to use GetClientInfo instead.

		\~chinese
		���?GetClientInfo��?�����ģ����������������?����?����GetClientInfo?����

		\~japanese
		GetClientInfo���Ҫ���ܪ򪷪ơ������߾�Ū�ʪ�??�Ǫ����۪���GetClientInfo���Ū����Ȫ�?�᪷�ު���
		\~
		*/
		PN_DEPRECATED inline bool GetPeerInfo(HostID clientHostID, CNetClientInfo& output)
		{
			return GetClientInfo(clientHostID, output);
		}

		/**
		\~korean
		�� ȣ��Ʈ�� ����� �ٸ� ȣ��Ʈ(������ ��� Ŭ���̾�Ʈ��, Ŭ���̾�Ʈ�� ��� �Ǿ��)�� �������� tag�� �����մϴ�. <a target="_blank" href="http://guide.nettention.com/cpp_ko#host_tag" >�� ȣ��Ʈ�� ���� ����� ���� ������(Tag)</a> ����Դϴ�.
		- �ڱ� �ڽ�(���� Ȥ�� Ŭ���̾�Ʈ)�� ���� tag �� ������ �� �ֽ��ϴ�.

		\~english
		Designates tag to each of other hosts(clients for servers, peers for clients) that are connected to this host. A <a target="_blank" href="http://guide.nettention.com/cpp_en#host_tag" >User-defined data(Tag) for each host</a> function.
		- Can designate tag to itself(server or client)

		\~chinese
		�����??���?���������������?������client��client��?peer����tag��<a target="_blank" href="http://guide.nettention.com/cpp_zh#host_tag" >?��?�������?��??�ߣ�Tag��</a>%������
		- �ʦ�������������?�����client����tag��

		\~japanese
		���Ϋ۫��Ȫ���?���쪿��Ϋ۫���(��?��?������ϫ��髤����ȡ����髤����Ȫ������Peer)�Ϊ��쪾���tag����Ҫ��ު���\ref host_tag Ѧ���Ǫ���
		- ������(��?��?�ު��ϫ��髤�����)��?����tag����Ҫ��몳�Ȫ��Ǫ��ު���

		\~
		*/
		virtual bool SetHostTag(HostID hostID, void* hostTag) = 0;

		/**
		\~korean
		������ ���� �ð��� ��´�. CNetClient.GetServerTimeMs()�� ���� ���� ���̴�.

		\~english
		Gets current time of server. Has almost same value as CNetClient.GetServerTimeMs().

		\~chinese
		?����?����?�??��? CNetClient.GetServerTimeMs()����������?��

		\~japanese
		��?��?������������ު���CNetClient.GetServerTimeMs()�Ȫ۪��Ҫ����Ǫ���
		\~
		*/
		virtual int64_t GetTimeMs() = 0;

		/**
		\~korean
		Ŭ���̾�Ʈ memberHostID�� �� ���� <a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P �׷�</a>  groupHostID�� �ߵ� �����ϰ� �մϴ�.
		- ���� �õ��� �Ǿ��� ������ �����Ǿ� �ִ� �Ǿ�� ������ ��� ���ΰ� �޽�¡�� �ص� �˴ϴ�.  (����: <a target="_blank" href="http://guide.nettention.com/cpp_ko#robust_p2p" >ProudNet�� P2P ��� ����</a>)

		\param memberHostID P2P �׷쿡 ������ ����� Host ID. HostID_Server �� ���� �Ǵ��� ���δ� <a target="_blank" href="http://guide.nettention.com/cpp_ko#server_as_p2pgroup_member" >P2P �׷� ����μ� ������ ���Խ�Ű��</a> �� �����Ͻʽÿ�.
		\param groupHostID �̹� ������� P2P �׷��� Host ID�Դϴ�.
		\param customField P2P �׷��� �߰��ϸ鼭 �������� ���� Ŭ���̾�Ʈ�鿡�� ������ �޽����Դϴ�. INetClientEvent.OnP2PMemberJoin ���� �״�� �޾����ϴ�.
		\return ������ true�� �����մϴ�.

		\~english
		Lets client memberHostID enter into existing <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a> groupHostID
		- Messaging can do between existed peer and new peer. (Reference: <a target="_blank" href="http://guide.nettention.com/cpp_en#robust_p2p" >P2P performance of ProudNet</a>)

		\param memberHostID HostID of member to join P2P group. Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#server_as_p2pgroup_member" >How to include a server as a peer-to- peer group member</a> to find out if HostID_Server can join.
		\param groupHostID HostID of existing P2P group
		\param customField Message to be sent to related clients from server when adding P2P group. Will be accepted as it is at INetClientEvent.OnP2PMemberJoin.
		\return returns true if successful

		\~chinese
		?Client��memberHostID�������� <a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a> groupHostID��Բ??��
		- ????��peer������??��peer��?ʦ�ء??��messaging��?�� <a target="_blank" href="http://guide.nettention.com/cpp_zh#robust_p2p" >ProudNet ��P2P��������</a>����

		\param memberHostID ??P2P?����?Host ID�� HostID_Server �������?��??��<a target="_blank" href="http://guide.nettention.com/cpp_zh#server_as_p2pgroup_member" >�P2P��?��?������?��</a>%��
		\param groupHostID �??����P2P?��Host ID��
		\param customField ��ʥP2P?��?����?������?client?�������ӡ�� INetClientEvent.OnP2PMemberJoin%�����?������⥡�
		\return ������?������true��

		\~japanese
		���髤�����memberHostID��?�����\ref p2p_group  groupHostID����Բ?ʥ����誦�˪��ު���
		- ?ʥ���˪���Peer��?���?ʥ���ƪ���Peer��Ǫϡ������˫�ë�?���󫰪򪷪ƪ��ު��Ǫ���(?�ţ�\ref robust_p2p)
		\param memberHostID P2P ����?�ת�?ʥ�������?��Host ID��HostID_Server�����êƪ⪤�����ϡ�\ref server_as_p2pgroup_member��?�Ϊ���������
		\param groupHostID ?���ª�쪿P2P����?�ת�Host ID�Ǫ���
		\param customField P2P ����?�ת���ʥ���ʪ��顢��?��?���?֧���髤����Ȫ�����ë�?���Ǫ��� INetClientEvent.OnP2PMemberJoin ��ꪽ�Ϊު����������ު���
		\return ��������true��꫿?�󪷪ު���

		\~
		*/
		virtual bool JoinP2PGroup(HostID memberHostID, HostID groupHostID, ByteArray customField = ByteArray()) = 0;

		/**
		\~korean
		Ŭ���̾�Ʈ memberHostID�� <a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P �׷�</a>  groupHostID �� ������ �Ѵ�.
		- �߹�Ǵ� Ŭ���̾�Ʈ������ P2P �׷��� ��� ����� ����(�ڱ� �ڽ� ����) INetClientEvent.OnP2PMemberLeave �� �������� ȣ��ȴ�.
		����, P2P group�� ������ ������� �߹�Ǵ� Ŭ���̾�Ʈ�� ���� INetClientEvent.OnP2PMemberLeave �� ȣ��޴´�.
		- ����� ���� ����, �� ����ִ� P2P group�� �� ��� AllowEmptyP2PGroup�� ������ ���� �ڵ� �ı��ǰų� ���� �� ���� �����ϴ�.

		\param memberHostID �߹��� ����� Host ID
		\param groupHostID � �׷����κ��� �߹��ų ���ΰ�
		\return ���������� �߹�� true�� ����

		\~english
		Client memberHostID lets <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a> groupHostID go out
		- At the client being kicked out, INetClientEvent.OnP2PMemberLeave will be called one after another for all members of P2P group(including itself).
		On the other hand, INetClientEvent.OnP2PMemberLeave will be called for other members of P2P group that are to be kicked out.
		- For those of no members, in other words for an empty P2P group, they will be either auto-destructed by AllowEmptyP2PGroup setting or can be re-used after its survival.

		\param memberHostID HostID of member to be kicked out
		\param groupHostID to be kicked out from which group?
		\return returns true if successfully kicked out

		\~chinese
		Client ��memberHostID? <a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a> groupHostID����
		- ���?������client?P2P?�������?�������������INetClientEvent.OnP2PmemberLeave%??��У��
		��۰��P2P group�������??����У??����client�� INetClientEvent.OnP2PMemberLeave��
		- ?����?��?��?��?����P2P group��?������AllowEmptyP2Pgroup��?��ʦ��?��?���?׺������ġ�

		\param memberHostID �?����Host ID��
		\param groupHostID �?????��
		\return ?��������?����true��

		\~japanese
		���髤�����memberHostID��\ref p2p_group  groupHostID ����������誦�˪��ު���
		- �ڪ��󪵪�뫯�髤����ȪǪϡ�P2P����?�ת���ƪΫ���?��?����(��������ߪ�) INetClientEvent.OnP2PMemberLeave��֧?�������󪵪�ު���
		��۰��P2P group��?��Ϋ���?�ϡ��ڪ��󪵪�뫯�髤����Ȫ�?����INetClientEvent.OnP2PMemberLeave�������󪷪ƪ�骤�ު���
		- ����?���絛�ʪ������ʪ�������ƪ���P2P group�˪ʪ����ꡢAllowEmptyP2PGroup�����Ҫ˪�ê������?����몫��?����������Ī�ʦ���Ǫ���
		\param memberHostID �ڪ��󪵪�����?��Host ID
		\param groupHostID �ɪΫ���?�ת����ڪ��󪵪��몫��
		\return �ڪ��󪷪�����������true��꫿?��

		\~
		*/
		virtual bool LeaveP2PGroup(HostID memberHostID, HostID groupHostID) = 0;

		/**
		\~korean
		�̺�Ʈ�� ���� �� �ִ� ��ü�� �����Ѵ�.
		- �ϳ��� ���� �����ϴ�.
		- �� �޼���� Ŭ���̾�Ʈ�� ������ ������ �õ��ϱ� ������ ȣ���� �� �ִ�. �ȱ׷��� exception�� throw�ȴ�.

		\~english
		Sets an object that can receive event
		- Can set only 1 object
		- This method can only be called before client attempts to connect to server. Otherwise, an execption will be 'throw'n.

		\~chinese
		?��ʦ����event��?�ڡ�
		- ����?����?��
		- �۰���client???����?������������??exception�� throw��

		\~japanese
		���٫�Ȫ��������뫪�֫������Ȫ����Ҫ��ު���
		- ���Ϋ᫽�ëɪϫ��髤����Ȫ���?��?��?���˪���Ϊ������󪹪��Ȫ��Ǫ��ު����������ʪ���С�exception��throw����ު���

		\~
		*/
		virtual void SetEventSink(INetServerEvent* eventSink) = 0;

		// ����: ���� ��ü�̹Ƿ� SUPPORTS_LAMBDA_EXPRESSION�� ������ �� ��.

		/// See Proud.INetServerEvent.OnClientJoin for details.
		LambdaBaseHolder_Param1<void, CNetClientInfo*> OnClientJoin;
		/// See Proud.INetServerEvent.OnClientLeave for details.
		LambdaBaseHolder_Param3<void, CNetClientInfo *, ErrorInfo *, const ByteArray& > OnClientLeave;
		/// See Proud.INetServerEvent.OnClientHackSuspected for details.
		LambdaBaseHolder_Param2<void, HostID, HackType > OnClientHackSuspected;
		/// See Proud.INetServerEvent.OnClientOffline for details.
		LambdaBaseHolder_Param1<void, CRemoteOfflineEventArgs &> OnClientOffline;
		/// See Proud.INetServerEvent.OnClientOnline for details.
		LambdaBaseHolder_Param1<void, CRemoteOnlineEventArgs &> OnClientOnline;
		/// See Proud.INetServerEvent.OnConnectionRequest for details.
		LambdaBaseHolder_Param4<void, AddrPort, ByteArray&, ByteArray&, bool*> OnConnectionRequest;
		/// See Proud.INetServerEvent.OnP2PGroupJoinMemberAckComplete for details.
		LambdaBaseHolder_Param3<void, HostID, HostID, ErrorType > OnP2PGroupJoinMemberAckComplete;
		/// See Proud.INetServerEvent.OnP2PGroupRemoved for details.
		LambdaBaseHolder_Param1<void, HostID > OnP2PGroupRemoved;
		/// See Proud.INetServerEvent.OnUserWorkerThreadBegin for details.
		LambdaBaseHolder_Param0<void> OnUserWorkerThreadBegin;
		/// See Proud.INetServerEvent.OnUserWorkerThreadEnd for details.
		LambdaBaseHolder_Param0<void> OnUserWorkerThreadEnd;


	public:
		/**
		\~korean
		������ �����մϴ�. ���� ������ ���� ���� ��� Proud.Exception�� throw �˴ϴ�.
		\param ���� ������ ���� ���� �����Դϴ�. TCP listen port ���� �����մϴ�.

		\~english
		The server starts. If the server does not start, Proud.Exception will throw.
		Setting for the initiating the \param server. Able to indicate TCP listen port.

		\~chinese
		?�??��?���������??? Proud.Exception ?�� throw��
		\param ��?��??��??��?黣���� TCP listen port ����


		\~japanese
		��?��?�����Ѫ��ު��� ��?�Ъ����Ѫ��ƪ��ʪ������Proud.Exception��throw����ު���
		\Param ��?�Ъ����Ѫ��몿�����ء��?黪Ǫ��� TCP listen port������Ҫ��ު���
		*/
		virtual void Start(CStartServerParameter &param) = 0;

		/**
		\~korean
		������ �����սô�. ���� ������ ���� ���� ��� outError�� ���� ������ ���ϴ�.
		�ڼ��� ���� Proud.CNetServer.Start(CStartServerParameter&)�� �����Ͻʽÿ�.

		\~english
		The server starts. If the server does not start, error information goes in to outError.
		For detail information please refer to Proud.CNetServer.Start(CStartServerParameter&).

		\~chinese
		?�??��?���������??????�??�� outError��
		???�??�� Proud.CNetServer.Start(CStartServerParameter&)��

		\~japanese
		��?��?�����Ѫ��ު�����?�Ъ����Ѫ��ƪ��ʪ������outError�˫���?��?黪�����ު���
		��ᬪ˪Ī��ƪ� Proud.CNetServer.Start(CStartServerParameter&)��?�Ϊ��ƪ���������
		*/
		virtual void Start(CStartServerParameter &param, ErrorInfoPtr& outError) = 0;

		/**
		\~korean
		������ �����Ѵ�.
		-����!! �� �Լ��� rmi�� UserWorkerThread���� ȣ���ϴ� �Լ��������� ȣ���ؼ��� �ȵ˴ϴ�.

		\~english
		Stop server.
		- Warning!! This function never call in function that call from UserWorkerThread such as rmi.

		\~chinese
		?���?�
		- ������������?�rmi��UserWorkerThread��У����??��У��

		\~japanese
		��?��?���������ު���
		-�����!! ����??��rmi�ʪ�UserWorkerThread��������???�Ǫ������󪷪ƪϪ����ު���

		\~
		*/
		virtual void Stop() = 0;

		/**
		\~korean
		����� ���� ���� <a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P �׷�</a> �� ������ �� �ֵ��� �����ϴ� �ɼ�. �⺻�����δ� true�� �����Ǿ� �ִ�.
		- true�� ������ ���: CreateP2PGroup ȣ��� ��� 0��¥�� P2P �׷��� �����ص� �����Ѵ�. ����� 0��¥�� P2P �׷��� ��� �����Ѵ�.
		�̷��� ��� ����ڴ� ����� 0���� P2P �׷��� ����ؼ� ������ ���� �ʵ���, �ʿ��� ��� DestroyP2PGroup �Ǵ� DestroyEmptyP2PGroups �� ȣ���ؾ� �Ѵ�.
		- false�� ������ ���: CreateP2PGroup ȣ��� ��� 0��¥�� P2P �׷��� ������ �� ����. P2P �׷��� ����� 0���� �Ǹ� �� P2P �׷��� �ڵ� �ı��ȴ�.

		\~english
		Option to set <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a> without member can be sustained. Default is true.
		- When set as true: Creating P2P group of 0 member will succeed when CreateP2PGroup is called. The P2P group of 0 member will sustain.
		In this case, user must call DestroyP2PGroup or DestroyEmptyP2PGroups to prevent the P2P group of 0 member to be left in server.
		- When set as false: Creating P2P group of 0 member will fail when CreateP2PGroup is called. If the number of P2P group becomes 0 then the P2P group will be destructed automatically.

		\~chinese
		?����<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%?����??���?���??����??��?true��
		- ?��?true��?����УCreateP2Pgroup��?��?������0?��?��P2P?�?����0?��?��P2P???���
		??����?���?0?��?��P2P???�������?�?������?��УDestroyP2PGroup���DestroyEmptyP2PGroups��
		- ?��?false��?����УCreateP2PGroup?��������0?��?��P2P?��P2P ?����??��0?��?��?P2P??�?��?��

		\~japanese
		����?���絛�ʪ�\ref p2p_group���򥪵���誦�����Ҫ��뫪�׫���������ܪ˪�true�����Ҫ���ƪ��ު���
		- true�����Ҫ�������꣺CreateP2PGroup����������������?0����P2P����?�ת��������ƪ������ު�������?��0����P2P����?�ת�?��������ު���
		���Ϊ誦�����ꡢ��?��?�ϫ���?��0���Ǫ���P2P����?�ת�?���ƫ�?��?��?��ʪ��誦�ˡ���驪����ꡢDestroyP2PGroup�ު���DestroyEmptyP2PGroups�������󪵪ʪ���Ъʪ�ު���
		- false�����Ҫ�������꣺CreateP2PGroup����������������?0����P2P����?�ת��������몳�ȪϪǪ��ު���P2P����?�תΫ���?��0���˪ʪ�Ȫ���P2P����?�ת������?����ު���

		\~
		*/
		virtual void AllowEmptyP2PGroup(bool enable) = 0;

		/**
		\~korean
		Ŭ���̾�Ʈ���� �ν� ������ ������ ������ �ּ� ����Ʈ�� ��´�.
		- ���� ���۽� ���� ���� �ּҸ� ���� �����Ѵ�. NAT�� 2�� �̻��� ��ī�尡 �ִ� ��� �����ϴ�.

		\~english
		Gets listening port address of the server that can be recognized by client
		- Returns values based on the server addresses that are received when server started. This is useful when using NAT or 2 or more LAN cards.

		\~chinese
		?���clientʦ�??����?��listening��list��
		- ??��?��?������?�������ޡ���NAT���2?�߾LAN?��?�����ġ�

		\~japanese
		���髤����Ȫ�����ʦ���ʫ�?��?�Ϋ꫹�˫󫰫��ɫ쫹����ު���
		- ��?��?�����������������?��?���ɫ쫹�������˫꫿?�󪷪ު���NAT�Ȫ�2���߾��LAN��?�ɪ������������ĪǪ���

		\~
		*/
		virtual void GetRemoteIdentifiableLocalAddrs(CFastArray<NamedAddrPort> &output) = 0;

		/**
		\~korean
		TCP listener port�� ���� �ּ� ����Ʈ�� ��´�. ���� ��� ���� ��Ʈ�� ���� �Ҵ��� ��� �̰��� ���� ���� ������ ������ ��Ʈ ��ȣ�� ���� �� �ִ�.

		\~english
		Gets local address of TCP listener port. For an example, it is possible to acquire the listening port number of real server through this when the server ports are dynamically allocated.

		\~chinese
		?��TCP listener port�������list������??������?��ӮϢ��?������???ʦ�?��??��?����listeningӮϢ??��

		\~japanese
		TCP listener port�Ϋ�?���뫢�ɫ쫹�꫹�Ȫ���ު����Ǫ��С���?��?��?�Ȫ�����ʫ߫ë����ܪ�?�ƪ����ꡢ������ת�?𷫵?��?�Ϋ꫹�˫󫰫�?����?����몳�Ȫ��Ǫ��ު���
		\~
		*/
		virtual void GetTcpListenerLocalAddrs(CFastArray<AddrPort> &output) = 0;

		/**
		\~korean
		UDP listener port�� ���� �ּ� ����Ʈ�� ��´�. ���� ��� ���� ��Ʈ�� ���� �Ҵ��� ��� �̰��� ���� ���� ������ ������ ��Ʈ ��ȣ�� ���� �� �ִ�.

		\~english
		Gets local address of UDP listener port. For an example, it is possible to acquire the listening port number of real server through this when the server ports are dynamically allocated.

		\~chinese
		?��UDP listener port�����list������??������?��ӮϢ��?������???ʦ�?��??��?����listeningӮϢ??��

		\~japanese
		UDP listener port�Ϋ�?���뫢�ɫ쫹�꫹�Ȫ���ު����Ǫ��С���?��?��?�Ȫ�����ʫ߫ë����ܪ�?�ƪ����ꡢ������ת�?𷫵?��?�Ϋ꫹�˫󫰫�?����?����몳�Ȫ��Ǫ��ު���
		\~
		*/
		virtual void GetUdpListenerLocalAddrs(CFastArray<AddrPort> &output) = 0;

		/**
		\~korean
		�ʹ� �������� ������ ������� ���ϸ� ������ �����ϱ� ���� Ÿ�� �ƿ� �Ӱ谪(�и���)�� �����Ѵ�.
		- CNetServer.Start ȣ�� ������ ����� �� �ִ�. �� ���ĺ��� ȣ���� ��� ���õȴ�.
		- �������� ��� ���� ��õ���� �ʴ´�. ������ ���� ������ ������ ���� ����� �ڸ���� �����̴�. �׷����� ���� 1�ð��� �Ŵ� ���� ����.
		�ݸ�, 1�� �� �ʹ� ���� ���� ������ �������� Ŭ���̾�Ʈ�� �Ѱܳ� ������ �����Ƿ� ���ؾ� �Ѵ�.
		- �⺻���� ProudNetConfig.DefaultNoPingTimeoutTime �̴�.
		- ����: <a target="_blank" href="http://guide.nettention.com/cpp_ko#debug_pause_problem" >����ſ� ���� �Ͻ������ϸ� �������� ������ �������� ���� �ذ��</a>

		\~english
		Sets the critical value of time out(millisecond) to disconnect the connection with server when it has been long not communicating with it
		- Can only be used before calling CNetServer.Start. Caliing after that point will be ignored.
		- It is not recommended setting it as permanent since it will remain as an infinite connection after unexpected disconnection. It is better setting it as an hour than the case.
		- Default is ProudNetConfig.DefaultNoPingTimeoutTime.
		- Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#debug_pause_problem" >How to maintain the connection with server when the program stops due to debugger</a>.

		\~chinese
		????����?��?��������?�����?�����?������??ͣ?��millisecond����
		- ����� CNetServer.Start t ��У�������ġ�����?���У��??����?��
		- ����???���ڡ���?ު����?��??��?���������?�ȡ�������?��?1�?��
		������?�����?��?��client ʦ��?����?��������?��
		- ��??�� ProudNetConfig.DefaultNoPingTimeoutTime%��
		- ?�ţ�<a target="_blank" href="http://guide.nettention.com/cpp_zh#debug_pause_problem" >��Debug��??��?��?��???��?����?۰��</a>��

		\~japanese
		�Ȫƪ������૵?��?������Ǫ��ʪ��ê��顢��?����𶪹�몿��Ϋ����ૢ������ͣ��(��)����Ҫ��ު���
		- CNetServer.Start ����������Ϊ��Ū����Ȫ��Ǫ��ު���������������������������ʪ���ު���
		- ���ڪ˪��몳�ȪϪ�?�᪷�ު��������?����������ڪ�?����?�˪ʪ몫��Ǫ����ʪΪǡ��ષ��1����˪���۰���ު��Ǫ���
		����������1���ʪ�ᳪ�������������������Ȫʫ��髤����Ȫ��ڪ��󪵪����?������ު��Ϊ�������٪��Ǫ���
		- ��������ProudNetConfig.DefaultNoPingTimeoutTime�Ǫ���
		- ?�ţ�\ref debug_pause_problem

		\~
		*/
		virtual void SetDefaultTimeoutTimeMs(int newValInMs) = 0;

		/**
		\~korean
		�ʹ� �������� ������ ������� ���ϸ� ������ �����ϱ� ���� Ÿ�� �ƿ� �Ӱ谪(�и���)�� �����մϴ�.
		SetDefaultTimeoutTimeMs �� �ٸ����� Ư�� ȣ��Ʈ�� ���ؼ��� ��Ÿ���߿��� Ÿ�Ӿƿ��� ���� �� �� �ֽ��ϴ�.
		- ������ ���� ��, �� ��� ���� ��� �� �� �ֽ��ϴ�.
		- Ư�� ȣ��Ʈ(Ŭ���̾�Ʈ)���� ���� ��ŵ�ϴ�.
		- ���� ��Ÿ�� ��, Ŭ���̾�Ʈ���Ե� �����ϹǷ� stale ������ ���� �� �ֽ��ϴ�.
		(�� ��� Ŭ���̾�Ʈ�� Ÿ�Ӿƿ� �ð��� ������ Ÿ�� �ƿ� �ð��� �޶� ���� ���� �ð��� ���� ���� �� �� �ֽ��ϴ�.)

		\~english
		Specify timeout threshold(msec.) for disconnection in case of disconnected from server too long.
		Difference from SetDefaultTimeoutTimeMS is that you can change timeout during runtime for specific host.
		-You can use it regardless of before or after starting the server.
		-Applied to specific host(client).
		-During server runtime, as this is also applied to the client, stale problem can occur.
		(In this case, disconnection time can be different as timeout time between client and server is different)

		\~chinese TODO:translate needed.
		Specify timeout threshold(msec.) for disconnection in case of disconnected from server too long.
		Difference from SetDefaultTimeoutTimeMS is that you can change timeout during runtime for specific host.
		-You can use it regardless of before or after starting the server.
		-Applied to specific host(client).
		-During server runtime, as this is also applied to the client, stale problem can occur.
		(In this case, disconnection time can be different as timeout time between client and server is different)


		\~japanese TODO:translate needed.
		Specify timeout threshold(msec.) for disconnection in case of disconnected from server too long.
		Difference from SetDefaultTimeoutTimeMS is that you can change timeout during runtime for specific host.
		-You can use it regardless of before or after starting the server.
		-Applied to specific host(client).
		-During server runtime, as this is also applied to the client, stale problem can occur.
		(In this case, disconnection time can be different as timeout time between client and server is different)
		*/
		virtual void SetTimeoutTimeMs(HostID host, int newValInMs) = 0;

		/**
		\~korean
		m_enableAutoConnectionRecovery�� true�̸� SetDefaultTimeoutSec�̳� SetDefaultTimeouMs���� ������ Ÿ�Ӿƿ� �ð��� ��ȿ���� �ʰ� �˴ϴ�.
		���� ACR�� ���� ���� �ð��� ��� ��������� �ϴµ�, �� �Լ��� ���Ͽ� �������� �� �ֽ��ϴ�.
		- �⺻���� 60 * 1000 �Դϴ�. ��, 1���Դϴ�.

		\~english
		If m_enableAutoConnectionRecovery is true, The time of TimeOut is not valid.
		So, You should set the ACR time by using this method.
		- Default is 60 * 1000. ( 1 minute )

		\~chinese TODO:translate needed.

		If m_enableAutoConnectionRecovery is true, The time of TimeOut is not valid.
		So, You should set the ACR time by using this method.
		- Default is 60 * 1000. ( 1 minute )

		\~japanese TODO:translate needed.

		If m_enableAutoConnectionRecovery is true, The time of TimeOut is not valid.
		So, You should set the ACR time by using this method.
		- Default is 60 * 1000. ( 1 minute )

		*/
		virtual void SetAutoConnectionRecoveryGiveUpWaitTimeMs(int newValInMs) = 0;

		/**
		\~korean
		Ŭ���̾�Ʈ�� UDP ����� ��� ���������� ������ ������ �������� �����ϴ� �޼����.
		- ������� �ǵ����� ������ Ŭ���̾�Ʈ�� �������� �Ǵ� peer���� UDP ����� �����ϰ��� �� ��
		�� �޼��带 �� �� �ִ�.
		- �ؾ��� ��Ȳ, ���� ��� UDP ��� ��ְ� �ɰ��ϰ� �߻��ϴ� �������� �ӽù������� �� �ɼ��� �Ѽ�
		������ �Ͻ������� ���� �� �ִ�. ������ UDP ����� ���� ���񽺿��� �߿��ϱ� ������
		�ִ��� ���� ������ �ذ� �� �� �ɼ��� �ٽ� �Ѵ� ���� ����.

		- �� ���� ������ �� ���� �����ϴ� Ŭ���̾�Ʈ�� ���ؼ��� ����ȴ�.
		- �ʱ� ���´� FallbackMethod_None �̴�.

		\param newValue ���� ��å. Proud.FallbackMethod_CloseUdpSocket �� �� �� ����.

		\~english
		The method to set limits to how far the client uses UDP communication
		- This method can be used to block UDP communication between client and server or client and peer due to intentional reason by user.
		- The worst case, for an example, if there occurs a serious UDP communication hurdle at a server then the problem can be temporarily reduced by turning this option up.
		However, since UDP communication is crucial to game service so it is recommended to solve the problems ASAP then thrun this option back on.

		- Only applied to those newly connected clients after this value is changed
		- The initial status is FallbackMethod_None.

		\param newValue a limitation policy. Proud.FallbackMethod_CloseUdpSocket cannot be used.

		\~chinese
		?��client����UDP������?������۰����
		- ����?ͺ�������?client����?�����peer��UDP������?����ʦ������۰����
		- ��?����?�������UDP�������?��?������?�����?��۰��??�??��?ʦ�???��??��ӣ��UDP�������?��?��?��驣�?����??��?������??�???����

		- ��?�����?�������?����client���ġ�
		- ���??��FallbackMethod_None��

		\param newValue ����������������� Proud.FallbackMethod_CloseUdpSocket%��

		\~japanese
		���髤����Ȫ�UDP�����ɪ�۪ɪު��Ū��誦����ڪ��몫�����Ҫ���᫽�ëɪǪ���
		- ��?��?����?�ܪ���릪ǫ��髤����Ȫ���?��?�ȪΡ��ު���Peer���UDP������?���誦�Ȫ����������Ϋ᫽�ëɪ��Ū����Ȫ��Ǫ��ު���
		- ��?��?�ϡ��Ǫ��С�UDP����������ʾ��?�檹�뫵?��?������۰���Ȫ��ƪ��Ϋ��׫�����Ī������������ܪ����骵���몳�ȪϪǪ��ު�����������UDP����ϫ�?�૵?��?����驪ʪΪǡ������ڪ��ܪ�������̽�������Ϋ��׫������������۰���ު��Ǫ���
		- ��������?�ڪ��������檿����?���뫯�髤����Ȫ�?���ƪΪ����Ī���ު���
		- ��Ѣ?����FallbackMethod_None�Ǫ���
		\param newValue ��ګݫ꫷?��Proud.FallbackMethod_CloseUdpSocket���Ū����Ȫ��Ǫ��ު���

		\~
		*/
		virtual void SetDefaultFallbackMethod(FallbackMethod newValue) = 0;

		/**
		\~korean
		���� ���� �α׸� ���Ϸ� ����� ����� �Ҵ�.
		- �� ����� �ʿ��� ���� ���� ����. Nettention���� ������ �����ϱ� ���� �������� ���ȴ�.
		- �̹� EnableLog �� �� ���¿��� �� �Լ��� �� ȣ���ϸ� �� �Լ��� �ƹ��͵� ���� �ʴ´�. ���� �ٸ� ���ϸ�����
		�α׸� ����ؼ� �װ� ������ DisableLog�� ȣ�� �� EnableLog�� ȣ���ؾ� �Ѵ�.
		\param logFileName �α� ���� �̸�

		\~english
		Turns on the option that leaves internal execution log as file
		- There are not many cases that require this function. Used to collect problems at Nettention.
		- Calling this function again while already 'EnableLog'ed, this function will not do anything. If you need to keep stacking the log with other file name the you must call DisableLog then call EnableLog.
		\param logFileName log file name

		\~chinese
		??��?ݻ?��log��׺?������������
		- ����?��������������?�� Nettention ���???���������������
		- �EnableLog��??����У���?��?�����?��?��������ס�����������������٣??��?log��?�����УDisableLog������УEnableLog��
		\param logFileName log����٣��

		\~japanese
		?ݻ?������ի������?��Ѧ���������ު���
		- ����Ѧ������驪������ܬ�˪���ު���Nettention������?󢪹�몿������ܪ��Ū��ު���
		- ?��EnableLog�򪷪�?���Ǫ���??��ު������󪹪Ȫ���??�����⪷�ު��󡣪⪷����Ϋի�����٣�ǫ���?�����������������DisableLog�������󪷪�����EnableLog�������󪷪ƪ���������
		\param logFileName ���ի�����٣

		\~
		*/
		virtual void EnableLog(const PNTCHAR* logFileName) = 0;

		/**
		\~korean
		EnableLog�� �� �α׸� ����.

		\~english
		Turns off the log that is thrned on by EnableLog

		\~chinese
		??EnableLog��log��

		\~japanese
		EnableLog�ǪĪ������򫪫ժ��ު���
		\~
		*/
		virtual void DisableLog() = 0;

		/**
		\~korean
		���ǵ��� Ž�� ����� �������� ������ �����մϴ�.
		- 0~100 ���� ������ �����մϴ�. 100�� �������� �����ϰ� ���ǵ����� Ž���Ѵ�.
		- ProudNet�� ���ǵ��� Ž�� ����� Ŭ���̾�Ʈ�� �������� ping�� Ÿ�ӽ����� ������ �۵��մϴ�.
		0�� ����� ���� ������ ���� ���ǵ����� ���� Ŭ���̾�Ʈ�� Ž���ϴ� �� �ɸ��� �ð��� ª��������
		���ǵ����� ���� �������� �ұ��ϰ� ��� ȸ���� �ҷ����� ���� ping�� �ұ�Ģ�ϰ� �����ϴ� Ŭ���̾�Ʈ������
		���ǵ����� ���� Ŭ���̾�Ʈ�� ���ε� ���ɼ��� �������ϴ�.
		- �ʱⰪ�� 1�Դϴ�.
		- �������� ������ ������ �� ���ĺ��� �����ϴ� Ŭ���̾�Ʈ�� ���� ����� ���� ����˴ϴ�.

		\~english
		Set the intensity of speed hack detection
		- Sets between the value of 0 and 100. Closer to 100 detects with more intensity.
		- The speed hack detection function of ProudNet operates based on ping among servers and time stamp values.
		Using the value closer to 0 provides less time taken for detection but those clients with inconsistant ping can be detected as a speed hack.

		- Initial value is 100.
		- Changed value will be applied to clients connected after the intensity is changed.

		\~chinese
		?��speed hack���������?��������
		- ?����0~100��??��������1��?�����speed hack��
		- ProuNet��speed hack�������???client����?����?ping��time stamp?��
		?��?������0��?���������speed hack��client��??��??ӭ��?��������speed hack����?����?�������ޣ�ping ��??��?��client��???������speed hack��client��ʦ����?��ʥ��
		- ��??��1��
		- ?��?������������������?����client������������?��

		\~japanese
		����?�������Ѧ����?�쪵�����������Ҫ��ު���
		- 0~100������������Ҫ��ު���100���Ϊ��۪�?��˫���?��������򱪷�ު���
		- ProudNet�Ϋ���?�������Ѧ���ϡ����髤����Ȫȫ�?��?���ping�ȫ����ૹ������������Ѫ��ު���
		0���Ϊ��������Ҫ���誦�˫���?�������Ū����髤����Ȫ���򱪹��˪����������ӭ���ʪ�ު���������?�������Ū�ʪ��˪�?��骺���������ʪ����ު˪�ê�ping����Ю�Ϊ���ӹ���뫯�髤����Ȫ����⫹��?�������Ū����髤����Ȫ���㪵���ʦ�������Ԫ��ʪ�ު���
		- ��Ѣ����1�Ǫ���
		- ?�쪵����������ｪ��������˽������?���뫯�髤����Ȫ��ڪê�?�ڪ��쪿�������Ī���ު���

		\~
		*/
		virtual void SetSpeedHackDetectorReckRatioPercent(int newValue) = 0;

		/**
		\~korean
		���ǵ��� Ž�� ����� �Ѱų� ����.
		\param clientID ���ǵ��� Ž�� ����� ���ų� �� Ŭ���̾�Ʈ�� HostID
		\param enable �ѷ��� true.
		\return ��ȿ�� Ŭ���̾�Ʈ�� ã������ true. ������ Ŭ���̾�Ʈ�� ���� ��� false.

		\~english
		Turns on/off speed hack detection function
		\param clientID HostID of client that speed hack detection to be turned on/off
		\param enable must set true to turn on
		\return True if found valid client, false if no related clients.

		\~chinese
		??���??speed hack���������
		\param clientID �??���??speed hack���������client Host ID��
		\param enable ??��?true��
		\return ?��������client��?true��?����������client��?false��

		\~japanese
		����?�������Ѧ���򫪫�?���ժ��ު���
		\param clientID ����?�������Ѧ���򫪫�?���ժ��뫯�髤����Ȫ�HostID
		\param enable�Ī��몿��˪�true.
		\return ��?�ʫ��髤����Ȫ���������true�����Ī��뫯�髤����Ȫ��ʪ������false

		\~
		*/
		virtual bool EnableSpeedHackDetector(HostID clientID, bool enable) = 0;

		/**
		\~korean
		��ŷ�� Ŭ���̾�Ʈ���� �����߷����� �޽��� ����� ���� ���(Ư�� �޽��� ũ�� �κ�)
		�̸� �����ϱ� ���ؼ��� ���������� �޴� �޽��� ũ���� ���Ѽ��� �����ؾ� �Ѵ�.
		�� �޼���� �� ���Ѽ��� �����ϴ� ������ �Ѵ�.
		�ʱⰪ�� 64KB�̴�.
		\param value_s serverMessageMaxLength
		\param value_c clientMessageMaxLength

		\~english
		To stop the damaged message header sent by a hacked client(especially the size part), it is crucial to set the maximum size of messages received by server.
		This method sets the limit and the default value is 64KB.
		\param value_s serverMessageMaxLength
		\param value_c clientMessageMaxLength

		\~chinese
		?������client?����?������header��?������?���������ݻ�£���?����???�������?��۰��������������߾�ڡ�
		�۰����������?߾�������ġ�
		���?��64KB��
		\param value_s serverMessageMaxLength
		\param value_c clientMessageMaxLength

		\~japanese
		�ϫë��󫰪��쪿���髤����Ȫ�?���ƪ�������ë�?���ثë�?���������(��ˡ���ë�?��������ݻ��)
		���Ϋ᫽�ëɪϪ���߾���ʪ���Ҫ�����ܪ򪷪ު���
		��Ѣ����64kb�Ǫ���
		\param value_s serverMessageMaxLength
		\param value_c clientMessageMaxLength
		

		\~
		*/
		virtual void SetMessageMaxLength(int value_s, int value_c) = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#delayed_send" >TCP ���� �۽� ��ɰ� Nagle �˰���</a> ���¸� ��´�.

		\~english
		Gets <a target="_blank" href="http://guide.nettention.com/cpp_en#delayed_send" >TCP delayed transmitting function and Nagle algorism</a> condition.

		\~chinese
		?��<a target="_blank" href="http://guide.nettention.com/cpp_zh#delayed_send" >TCP ��?����������Nagleߩ��</a>%??��

		\~japanese
		\ref delayed_send  ?������ު���
		
		\~
		*/
		virtual bool IsNagleAlgorithmEnabled() = 0;

		// ProudNet�� �������� unit test�� �����Ѵ�. DLL ������ ��� ���� API�� export�� �Ұ����ϹǷ� �̷��� �����Ǿ� �ִ�.
		// virtual void TEST_SomeUnitTests() = 0;

		/**
		\~korean
		������ Ŭ���̾�Ʈ�� ���� �� �ִ� �ִ� Direct P2P ���� ������ �����մϴ�.
		- ���⼭ ������ ���� �ʰ��� ������ P2P ������ �׻� Relayed�� �˴ϴ�.
		- Direct P2P�� ���� ������ ���⼭ ������ �� ���ϰ� ���� �� �ִµ�, �̴� ProudNet�� <a target="_blank" href="http://guide.nettention.com/cpp_ko#jit_p2p" >JIT(Just-in-time) P2P ����</a> ��� �����̸�, �������� ��Ȳ�Դϴ�.

		\~english
		Designates the maximum number of Direct P2P connections that the desinated clients can be connected to
		- Those other P2P connections that have values that exceed the designated value will always be relayed.
		- Actual number of P2P connections may be less than newVal due to <a target="_blank" href="http://guide.nettention.com/cpp_ko#jit_p2p" >JIT(Just-in-time) P2P connection</a>, but it is not a problem.

		\~chinese
		����������clientʦ�?��������Direct P2P?��??��
		- �?����?���??��P2P?������?Relayed��
		- Direct P2P��????ʦ��?���?�������?�����?����?ProudNet��<a target="_blank" href="http://guide.nettention.com/cpp_zh#jit_p2p" >JIT(Just-in-time) P2P?��</a> %��������������?��

		\~japanese
		��Ҫ������髤����Ȫ�̿�٪�����Direct P2P��??����Ҫ��ު���
		- ��������Ҫ���������Φ����?���P2P��?�Ϫ��Ī�Relayed����ު���
		- Direct P2P��?�?�Ϫ�������Ҫ���������˪ʪ몳�Ȫ�����ު����������ProudNet��\ref jit_p2pѦ���Ϊ���ǡ����Ȫ�?�ϪǪ���

		\~
		*/
		virtual void SetMaxDirectP2PConnectionCount(HostID clientID, int newVal) = 0;

		/**
		\~korean
		Ŭ���̾�Ʈ�� P2P Ȧ��Ī�� �����ϱ� ���� ������ �����մϴ�. �ڼ��� ���� <a target="_blank" href="http://guide.nettention.com/cpp_ko#jit_p2p" >JIT(Just-in-time) P2P ����</a> �� �����Ͻʽÿ�.
		- �� �޼��带 ȣ���� ���Ŀ� ������ Ŭ���̾�Ʈ���� �� ���� ����˴ϴ�.
		- �⺻���� JIT �Դϴ�.

		\param newVal Ŭ���̾�Ʈ�� P2P ����� ���� Ȧ��Ī�� �����ϴ� �����Դϴ�.
		\return ���������� �ݿ��� true�� �����մϴ�.

		\~english

		\todo retranslate required.

		Designates the condition to begin P2P hole-punching among clients <a target="_blank" href="http://guide.nettention.com/cpp_en#jit_p2p" >JIT(Just-in-time) P2P connection</a>
		- The clients that the designated value will be applied to are the client that connected after this method is called.
		- Default is the value that is designated at Proud.CNetConfig.DefaultDirectP2PStartCondition.

		\param newVal the condition to begin P2P hole-punching among clients
		\return returns true if successfully applied

		\~chinese
		?��?�P2P��������?�졣????��<a target="_blank" href="http://guide.nettention.com/cpp_zh#jit_p2p" >JIT(Just-in-time) P2P?��</a> %��
		- ��У�۰�����?����client?������?��
		- ��??��JIT��

		\param newVal ?�?��client��?P2P������?�졣
		\return �������?����true��

		\~japanese
		���髤�������P2P��?��ѫ���󫰪���㷪��몿���?�����Ҫ��ު����٪����ϡ�\ref jit_p2p��?�Ϊ���������
		- ���Ϋ᫽�ëɪ������󪷪�������?�������髤����Ȫ�����������Ī���ު���
		- ��������JIT�Ǫ���
		\param newVal ���髤��������P2P����Ϊ���Ϋ�?��ѫ���󫰪���㷪���?��Ǫ���
		\return ��籪���������true��꫿?�󪷪ު���

		\~
		*/
		virtual bool SetDirectP2PStartCondition(DirectP2PStartCondition newVal) = 0;

		/**
		\~korean
		���� �Ǿ�μ� ���� ������ ������ �� Ŭ���̾�Ʈ�� ã�´�.
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#super_peer" >Super Peer(�����Ǿ� Ȥ�� ȣ��Ʈ) �߽��� P2P ��Ʈ��ŷ</a> ������ ������ �������� ���, �� �޼���� groupID�� ����Ű�� P2P�׷� �� �ִ� ����� ��
		���� ������ ���� �Ǿ ã�Ƽ� �˷��ش�.
		- �� �޼���� P2P �׷��� �����ϰų� ������ ���� �ٷ� ���� ��� ����� ã�� ���� �� �ִ�.
		- ó�� �� �޼��带 ȣ���� �ĺ��� �� 2~5�� ���� ���� �Ŀ� �ٽ� ȣ���ϸ� �� ��Ȯ�� �����Ǿ ã�´�.
		\param groupID �� <a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P �׷�</a> ���� ã�´�
		\param policy ���� �Ǿ �����ϴ� ��å. �ڼ��� ������ CSuperPeerSelectionPolicy ����.
		\param exclusdees groupID�� ����Ű�� <a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P �׷�</a> �� ��� �� exclusdees�� ����ִ� ������� �����ϰ� �����Ѵ�.
		���� ��� �̹� ����ϴ� �����Ǿ �ڰ� ��Ż�� ��� �ٽ� �̰��� �� ���ߵ��� �ǵ������� ������ �� �� �����ϴ�.
		\return �����Ǿ�μ� ���� ������ Ŭ���̾�Ʈ�� HostID. P2P �׷��� ã�� ���ϰų� excludees�� ���� ��ΰ� ���͸��Ǹ� HostID_None �� �����մϴ�.

		\~english
		Finds the clients that can perform best as super peer
		When developing game of <a target="_blank" href="http://guide.nettention.com/cpp_en#super_peer" >P2P Networking for Super Peer (Super Peer or host)</a> format, this method finds and notifies the best possible super peer among members of the P2P group that is pointed by groupID.
		- There are possibilities that this method cannot find properly right after P2P group is eiter created or modified.
		- It will find more suitable super peer when called about 2 to 5 seconds after this method is called.
		\param groupID finds within this <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a>
		\param policy policy that designates super peer. Please refer CSuperPeerSelectionPolicy.
		\param exclusdees Selects excluding the members within excludees among <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a> that is pointed by groupID
		For an example, it is useful to prevent intentionally the super peer to be re-selected when the super peer wass once disqualified.
		\return HostID of the best possible client as super peer. Returns HostID_None either when no P2P group was found or all filtered by excludees.

		\~chinese
		??��?super peer���������������client��
		���??<a target="_blank" href="http://guide.nettention.com/cpp_zh#super_peer" >Super Peer(�����) ������P2P����</a>%������?��?���۰��??���groupID����P2P?��?����������superpeer?ͱ򱡣
		- �۰�������P2P?���������ء??����?��ʦ��??����?��?��
		- ?���У�۰�������?2~5����������У��?��?����?��superpeer��
		\param groupID ��<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%??��
		\param policy ?��superpeer��������????�� CSuperPeerSelectionPolicy%��
		\param exclusdees groupID����<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%��?����exclusdees������?�������?����
		�����������superpeer��???̫�������ͺ�����?������?����?�����ġ�
		\return ��?superpeer��������clientHost ID��?����P2P?�����excludees��ݻ??��?����HostID_None��

		\~japanese
		��?��?��?���Ȫ���������̫����ܪ򪹪뫯�髤����Ȫ������ު���
		\ref super_peer  ���ҪΫ�?�����?������ꡢ���Ϋ᫽�ëɪ�groupID��򦪹P2P����?�ת˪������?�Ϊ�����������ʫ�?��?��?���������ƪ���ު���
		- ���Ϋ᫽�ëɪ�P2P����?�ת�����������?�ڪ�������������������ꡢ��������������Ȫ��Ǫ��ʪ����ꪬ����ު���
		- ����ƪ��Ϋ᫽�ëɪ������󪷪��������2~5���۪ɪ�Φ��������������󪹪Ȫ�ê������ʫ�?��?��?���������ު���
		\param groupID ����\ref p2p_group�������ު���
		\param policy ��?��?��?�������Ҫ���ݫ꫷?���٪����ϡ�CSuperPeerSelectionPolicy ��?�Ϊ���������
		\param exclusdees groupID��򦪹\ref p2p_group�Ϋ���?�Ϊ�����exclusdees�����êƪ������?����⪷����ܬ���ު���
		�Ǫ��С�?���Ūêƪ�����?��?��?������̫��?�����쪿���ꡢӪ��쪬��?����몳�Ȫ���?�ܪ����������������ĪǪ���
		\return ��?��?��?���Ȫ���������̫�ʫ��髤����Ȫ�HostID��P2P����?�ת��������Ȫ��Ǫ��ʪ��Ȫ���excludees�˪�ê���ƪ��ի��뫿��󫰪�����HostID_None��꫿?�󪷪ު���

		\~
		*/
		virtual HostID GetMostSuitableSuperPeerInGroup(HostID groupID, const CSuperPeerSelectionPolicy& policy = CSuperPeerSelectionPolicy::GetOrdinary(), const HostID* excludees = NULL, intptr_t excludeesLength = 0) = 0;

		/**
		\~korean
		���� �޼��� ������ ����ٶ�

		\~english
		Please refer same name method.

		\~chinese
		??����٣۰��?٥��

		\~japanese
		��٣�᫽�ëɪ�?٥��?�Ϊ���������
		\~
		*/
		virtual HostID GetMostSuitableSuperPeerInGroup(HostID groupID, const CSuperPeerSelectionPolicy& policy, HostID excludee) = 0;

		/**
		\~korean
		GetMostSuitableSuperPeerInGroup�� ���� ������ <a target="_blank" href="http://guide.nettention.com/cpp_ko#super_peer" >Super Peer(�����Ǿ� Ȥ�� ȣ��Ʈ) �߽��� P2P ��Ʈ��ŷ</a> �� ��� ����Դϴ�.
		�� �Լ��� ���� ������ �����Ǿ� �Ӹ� �ƴ϶� ������ ���� �����Ǿ���� ����� �����մϴ�.
		�� �Լ��� �����ϴ� ����Ʈ�� ù��° �׸��� GetMostSuitableSuperPeerInGroup���� �����ϴ� �����Ǿ�� �����մϴ�.

		\param groupID �� <a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P �׷�</a> ���� ���� �����Ǿ� ����� �����մϴ�.
		\param ratings ���⿡ ���� �����Ǿ� ����� ä�����ϴ�. ���� ������ �����Ǿ� ������ ���ĵǾ� ä�����ϴ�.
		\param ratingsBufferCount rating �� �迭 �׸� �����Դϴ�. �� �Լ��� �����ϴ� �迭�� ũ��� �� ũ�� �̻��� ä���� �ʽ��ϴ�.
		\param policy GetMostSuitableSuperPeerInGroup ���� ���� �̸��� �Ķ���͸� �����Ͻʽÿ�.
		\param excludees GetMostSuitableSuperPeerInGroup ���� ���� �̸��� �Ķ���͸� �����Ͻʽÿ�.
		\return ratings �� ä���� �׸��� �����Դϴ�. P2P �׷��� ã�� ���ϰų� excludees �� ���� ��ΰ� ���͸��Ǹ� 0�� �����մϴ�.

		\~english
		GetMostSuitableSuperPeerInGroup is the function to get the best possible <a target="_blank" href="http://guide.nettention.com/cpp_en#super_peer" >P2P Networking for Super Peer (Super Peer or host)</a>.
		Provides not only the best possible super peer but also the list of the next to the best possible super peer as well
		The first clause of the list that this function returns is same as the super peer returned by GetMostSuitableSuperPeerInGroup.

		\param groupID Provides the list of the best possible super peer among this <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a>
		\param ratings This is where the list of super peer will be filled. The best super peer is to be at the top as sorted.
		\param ratingsBufferCount The number of array clause of rating. The size of the array returned by this function does not fill more than this size.
		\param policy Please refer the same name parameter at	GetMostSuitableSuperPeerInGroup.
		\param excludees Please refer the same name parameter at	GetMostSuitableSuperPeerInGroup.
		\return the number of clause that is filled at ratings. Returns 0 either when no P2P group was found or filtered all of them by excludees.

		\~chinese
		GetMostSuitableSuperPeerInGroup ��?��<a target="_blank" href="http://guide.nettention.com/cpp_zh#super_peer" >Super Peer(�����) ������P2P����</a>%��������������
		���?��?���superpeer����?����?��������superpeer����?��
		���?������list�����??��?�GetMostSuitableSuperPeerInGroup������superpeer���ҡ�
		\param groupID �<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%���������superpeer����?��
		\param ratings �?��?��������superpeer��?�����������superpeer?������?����
		\param ratingsBufferCount rating???��??�����?������??��??�������߾����᳡�
		\param policy �GetMostSuitableSuperPeerInGroup?������٣���??��
		\param excludees �GetMostSuitableSuperPeerInGroup?������٣���??��
		\return ��ratings?����?��??��?����P2P?�����excludees��ݻ??��?����0��

		\~japanese
		GetMostSuitableSuperPeerInGroup��������̫��\ref super_peer �����Ѧ���Ǫ���
		����??��������̫�ʫ�?��?��?�������Ǫʪ�������Ȫ���̫��?��?��?���Ϋ꫹�Ȫ���ꪷ�ު���
		����??���꫿?�󪹪�꫹�Ȫ��������ͪϡ�GetMostSuitableSuperPeerInGroup���꫿?�󪹪뫹?��?��?�����Ҫ��Ǫ���
		\param groupID ����\ref p2p_group����̫��?��?��?���꫹�Ȫ���ꪷ�ު���
		\param ratings ��������̫��?��?��?���꫹�Ȫ�?������ު���������̫�ʫ�?��?��?����������֪�����?������ު���
		\param ratingsBufferCount rating ����֪����?�Ǫ�������??���꫿?�󪹪���֪�Ϋ������Ϫ����߾��?�����ު���
		\param policy GetMostSuitableSuperPeerInGroup ���Ҫ�٣��Ϋѫ��?��?��?�Ϊ���������
		\param excludees GetMostSuitableSuperPeerInGroup ���Ҫ�٣��Ϋѫ��?��?��?�Ϊ���������
		\return ratings ��?�����쪿���ͪ�?�Ǫ���P2P����?�ת��������Ȫ��Ǫ��ʪ��Ȫ���excludees�˪�ê���ƪ��ի��뫿��󫰪�����0��꫿?�󪷪ު���

		\~
		*/
		virtual int GetSuitableSuperPeerRankListInGroup(HostID groupID, SuperPeerRating* ratings, int ratingsBufferCount, const CSuperPeerSelectionPolicy& policy = CSuperPeerSelectionPolicy::GetOrdinary(), const CFastArray<HostID> &excludees = CFastArray<HostID>()) = 0;

		/**
		\~korean
		�������� �غ�� UDP ���� �ּҵ��� ��´�.

		\~english
		Gets UDP socket addresses that are prepared by server

		\~chinese
		?�����?����?��UDP socket�򣡣

		\~japanese
		��?��?�����᪵�쪿UDP�����ëȫ��ɫ쫹����ު���
		\~
		*/
		virtual void GetUdpSocketAddrList(CFastArray<AddrPort> &output) = 0;

		/**
		\~korean
		���� �������� ������ ��´�. �� ���� Ŭ���̾�Ʈ���� ��� ���� �������� ������ �ٸ��� ������ ����ȴ�.

		\~english
		Gets engine protocol version. Connection will be rejected if this value is different to engine protocol version from client.

		\~chinese
		?������??���⡣�???client?��������??����������?����??�ȡ�

		\~japanese
		���󫸫�׫�ȫ����?��������ު��������������髤����Ȫ����뫨�󫸫�׫�ȫ�?���?�������ު�����?�����ɪ˪ʪ�ު���
		\~
		*/
		virtual int GetInternalVersion() = 0;

		/**
		\~korean
		������ ���� ���õ� ��� P2P ������ ���� ��踦 ����ϴ�.
		���� Direct P2P�� relayed P2P�� ������ ���� �� �� �޼��尡 �����մϴ�.
		\param remoteHostID Ŭ���̾�Ʈ �Ǵ� <a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P �׷�</a> �� HostID �Դϴ�.
		- 1�� Ŭ���̾�Ʈ�� HostID �� ���, �� �޼���� �� Ŭ���̾�Ʈ�� P2P ����ϴ� �ٸ� �Ǿ����� ���� ��踦 ��ȯ�մϴ�.
		- 1�� P2P �׷��� HostID �� ���, �� �޼���� �� P2P �׷� ���� ��� Ŭ���̾�Ʈ������ P2P ��ſ� ���� ��踦 ��ȯ�մϴ�.
		\param status P2PĿ�ؼ� ���� �������� ���⿡ ä�����ϴ�.
		\return remoteHostID�� ��ȿ�ϸ� true,��ȿ���� ������ false�� ���� �մϴ�.

		\~english
		Gets status statistics of all P2P connections related to designated target
		This method is useful to get the proportion of Direct P2P and relayed P2P.
		\param remoteHostID HostID of client or <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a>
		- If this is HostID of 1 client then this method returns connection statistics of other peers that the client is P2P communicating with.
		- If this is HostID of 1 P2Pgroup then this method returns the statistics of all P2P communications among all clients in the P2P group.
		\param status P2P connection related vairables are to be filled in here.
		\return Returns true if remoteHostID is valid, false if not valid

		\~chinese
		?��?�����?����?�����P2P?��????��
		����?��Direct P2P��relayed P2P��������?���۰�����ġ�
		\param remoteHostID client���<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%��Host ID��
		- ��?client��Host ID��?���۰��������?client?����peer?��P2P������?��??��
		- ��?P2P?��Host ID��?���۰������?��?P2P??�����client��?P2P������??��
		\param status ?��?��P2P connection��???��
		\return remoteHostID������?true��������?����false��

		\~japanese
		��Ҫ���?�ڪ�?�����ƪ�P2P��?��?����ͪ����ު���
		�⪷��Direct P2P��relayed P2P�����������������Ϋ᫽�ëɪ����ĪǪ���
		\param remoteHostID ���髤����Ȫު���\ref p2p_group��HostID�Ǫ���
		- 1���髤����Ȫ�HostID�Ǫ������ꡢ���Ϋ᫽�ëɪϪ��Ϋ��髤����Ȫ�P2P���᪹�����Peer�Ȫ���?��ͪ���������ު���
		- ��P2P����?�ת�HostID�����ꡢ���Ϋ᫽�ëɪϪ���P2P����?��?����ƪΫ��髤����Ȫ�P2P�����?������ͪ���������ު���
		\param status P2P���ͫ������?֧??��������?������ު���
		\return remoteHostID����?�Ǫ����true����?�Ǫ������false��꫿?�󪷪ު���

		\~
		*/
		virtual bool GetP2PConnectionStats(HostID remoteHostID,/*output */CP2PConnectionStats& status) = 0;

		/**
		\~korean
		remoteA �� remoteB ������ udp message �õ�Ƚ���� ����Ƚ���� ��ȯ���ݴϴ�.
		- ��� �ڴ� �̸� �������� udp �ս��� ���� ����Ҽ��ֽ��ϴ�.

		\~english
		Return attempted number and succeed number of udp message between remoteA and remoteB
		- User can calculate udp loss rate based on it.

		\~chinese
		����remoteA?remoteB��?udp message??�?�������?��
		- ��?ʦ���?��??ߩUDP?��������

		\~japanese
		remoteA ��remoteB���udp message��?����?������ͭ?���������ު���
		- ��?��?�Ϫ����������UDP������ʪɪ�ͪߩ���몳�Ȫ��Ǫ��ު���

		\~
		*/
		virtual bool GetP2PConnectionStats(HostID remoteA, HostID remoteB, CP2PPairConnectionStats& status) = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#thread_pool" >������ Ǯ(Thread pool)</a> �� �� �������� ������ ����ϴ�.
		\param output ���⿡ ������ ä�����ϴ�.

		\~english
		Gets the information of each thread of <a target="_blank" href="http://guide.nettention.com/cpp_en#thread_pool" >Thread pool</a>
		\param output this is where the information has filled in.

		\~chinese
		?��<a target="_blank" href="http://guide.nettention.com/cpp_zh#thread_pool" >?���(Thread pool)</a>%����?�����ӡ�
		\param output ��?��?�����ӡ�

		\~japanese
		\ref thread_pool ��������ëɪ����ê���ު���
		\param output ���������ê�?������ު���

		\~
		*/
		virtual void GetUserWorkerThreadInfo(CFastArray<CThreadInfo> &output) = 0;

		/**
		\~korean
		��Ʈ��ŷ �������� ������ ����ϴ�.
		ProudNet�� <a target="_blank" href="http://guide.nettention.com/cpp_ko#thread_pool" >������ Ǯ(Thread pool)</a> �� ������ ��Ʈ��ũ I/Oó���� ����ϴ� �����尡 ����Ǿ� �ֽ��ϴ�. �̰��� ������ ����ϴ�.
		\param output ���⿡ ������ ä�����ϴ�.

		\~english
		Gets the information of networking thread
		ProudNet has a thread that manages network I/O that is independent to <a target="_blank" href="http://guide.nettention.com/cpp_en#thread_pool" >Thread pool</a>. This gets the information of the thread.
		\param output this is where the information is filled.

		\~chinese
		?��???�������ӡ�
		ProudNet ?<a target="_blank" href="http://guide.nettention.com/cpp_zh#thread_pool" >?���(Thread pool)</a>%���ң�?���?��??I/O?����?�?��?�����ӡ�
		\param output ��?��?�����ӡ�

		\~japanese
		�ͫëȫ�?���󫰫���ëɪ����ê���ު���
		ProudNet�ϡ�\ref thread_pool�Ȫ�ܬ�˫ͫëȫ�?��I/O?���??���뫹��ëɪ�??����ƪ��ު�����������ê���ު���
		\param output ���������ê�?������ު���

		\~
		*/
		virtual void GetNetWorkerThreadInfo(CFastArray<CThreadInfo> &output) = 0;

		/**
		\~korean
		����� ���� �޽����� �����մϴ�. �ڼ��� ���� <a target="_blank" href="http://guide.nettention.com/cpp_ko#send_user_message" >RMI�� ���� �Ⱦ��� ����� ���� �޽����� �ְ� �ޱ�</a> �� �����Ͻʽÿ�.
		\param remotes ������ �迭�Դϴ�. RMI�� ����������, Ŭ���̾�Ʈ, ����(HostID_Server), <a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P �׷�</a>  ���� ���� �� �ֽ��ϴ�.
		\param remoteCount ������ �迭 ũ��
		\param rmiContext �۽� �ΰ�����. �ڼ��� ���� <a target="_blank" href="http://guide.nettention.com/cpp_ko#protocol_overview" >ProudNet�� �������� ����</a> �� �����Ͻʽÿ�.
		\param payload ���� �޽��� ������
		\param payloadLength ���� �޽��� �������� ����. ����Ʈ �����Դϴ�.

		\~english
		Send user defined message. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#send_user_message" >Exchanging user-defined message without using RMI at all</a> for more detail
		\param remotes Receiver array. You can put client, server(HostID_Server), <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a>, etc like RMI.
		\param remoteCount Size of receiver array
		\param rmiContext Additional information of sending. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#protocol_overview" >Protocol type of ProudNet</a>.
		\param payload Message data for sending.
		\param payloadLength Length of sending message data. It is byte.

		\~chinese
		?����?��?���ӡ�????��<a target="_blank" href="http://guide.nettention.com/cpp_zh#send_user_message" >����������RMI��?��?��?����</a>%��
		\param remotes ����??��?RMI����ʦ�?��client����?�HostID_Server����<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%����
		\param remoteCount ����??��᳡�
		\param rmiContext ?��������ݾʥ���ӡ�????��<a target="_blank" href="http://guide.nettention.com/cpp_zh#protocol_overview" >ProudNet ��??????</a>%��
		\param payload �?��������?�ߡ�
		\param payloadLength �?��������?��?����Byte?�ȡ�

		\~japanese
		��?��?������ë�?����?�ꪷ�ު����٪����ϡ�\ref send_user_message��?�Ϊ���������
		\param remotes �������֪�Ǫ���RMI����?�ˡ����髤����ȡ���?��?(HostID_Server)�� \ref p2p_group  �ʪɪ�����몳�Ȫ��Ǫ��ު���
		\param remoteCount �������֪������
		\param rmiContext �����?������ʥ���á��٪����ϡ�\ref protocol_overview ��?�Ϊ���������
		\param payload ����ë�?����?��
		\param payloadLength ����ë�?����?���������Ы���?�ȪǪ���

		\~
		*/
		virtual bool SendUserMessage(const HostID* remotes, int remoteCount, const RmiContext &rmiContext, uint8_t* payload, int payloadLength) = 0;

		/**
		\~korean
		����� ���� �޽����� �����մϴ�. �ڼ��� ���� <a target="_blank" href="http://guide.nettention.com/cpp_ko#send_user_message" >RMI�� ���� �Ⱦ��� ����� ���� �޽����� �ְ� �ޱ�</a> �� �����Ͻʽÿ�.
		\param remote ������
		\param rmiContext �۽� �ΰ�����. �ڼ��� ���� <a target="_blank" href="http://guide.nettention.com/cpp_ko#protocol_overview" >ProudNet�� �������� ����</a> �� �����Ͻʽÿ�.
		\param payload ���� �޽��� ������
		\param payloadLength ���� �޽��� �������� ����. ����Ʈ �����Դϴ�.

		\~english
		Sending user defined message. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#send_user_message" >Exchanging user-defined message without using RMI at all</a> for more detail.
		\param remote receiver
		\param rmiContext Additional information of sending. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#protocol_overview" >Protocol type of ProudNet</a>.
		\param payload Message data for sending.
		\param payloadLength Length of sending message data. It is byte.

		\~chinese
		?����?��?���ӡ�????��<a target="_blank" href="http://guide.nettention.com/cpp_zh#send_user_message" >����������RMI��?��?��?����</a>%��
		\param remote �����
		\param rmiContext ?��������ݾʥ���ӡ�????��<a target="_blank" href="http://guide.nettention.com/cpp_zh#protocol_overview" >ProudNet ��??????</a>%��
		\param payload �?��������?�ߡ�
		\param payloadLength �?��������?��?����Byte?�ȡ�

		\~japanese
		��?��?������ë�?����?�ꪷ�ު����٪����ϡ�\ref send_user_message��?�Ϊ���������
		\param remote �����
		\param rmiContext �����?������ʥ���á��٪����ϡ�\ref protocol_overview ��?�Ϊ���������
		\param payload ����ë�?����?��
		\param payloadLength ����ë�?����?�����������Ы���?�ȪǪ���

		\~
		*/
		inline bool SendUserMessage(HostID remote, const RmiContext &rmiContext, uint8_t* payload, int payloadLength)
		{
			return SendUserMessage(&remote, 1, rmiContext, payload, payloadLength);
		}

		/** @copydoc Proud::CNetClient::SetCoalesceIntervalMs() */
		virtual ErrorType SetCoalesceIntervalMs(HostID remote, int intervalMs) = 0;
		/** @copydoc Proud::CNetClient::SetCoalesceIntervalToAuto() */
		virtual ErrorType SetCoalesceIntervalToAuto(HostID remote) = 0;

		virtual void TEST_SetOverSendSuspectingThresholdInBytes(int newVal) = 0;

		virtual void TEST_SetTestping(HostID hostID0, HostID hostID1, int ping) = 0;

		// TCP ������ ������ ���� ������ �ź��Ѵ�. ������ �����ڸ��� �Ѱܳ��� Ŭ���̾�Ʈ�� �׽�Ʈ�ϱ� ����.
		// Ŭ�������� ���� �źθ� �̸� �ɰ� ������ �͵� ���������, �������� TCP ������ �����ڸ��� �װ��� üũ�ϱ⿡�� �ʹ� �ʴ�.
		virtual void TEST_ForceDenyTcpConnection() = 0;

		/**
		\~korean
		�Ϲ����� �¶��� ���ӿ����� unreliable �޽�¡�� ��ü Ʈ������ ��κ��� �������Կ� ���� ���� unreliable �޽�¡ ��ɿ� Ʈ���� �ν����� ��� ����� �߰��մϴ�.
		��Ŷ �ν��� ������
		\param remoteHostID ��� remote ���� ��ſ� ���� �ν����� ���� ������. �ڱ� �ڽ� peer, server ������ �Է� �����մϴ�. �ڱ� �ڽ��̸� 0% �Դϴ�
		\param outputPercent ��Ŷ �ν����� %������ ä����(�� 0~100)

		\~english 
		As unreliable messaging takes most of the entire traffic in common on-line games, we add the feature to get the traffic loss rate in the existing unreliable messaging feature.
		Packet loss rate measuring device

		\param remoteHostID Which loss rate with communication with which remote would be obtained. You can input anything, including your own peer, server, etc. If it is itself, it is 0%.
		\param outputPercent The packet loss rate is filled up in % unit (i.e., 0 to 100)

		\~chinese
		������?��?��?Unreliable������??���������?��ݻ��?������Unreliable��������߾��ʥ?��������Loss����������
		?����Loss��?��?��
		\param remoteHostID �?��??��?remote?������Loss�㣬ʦ�?�������Peer��server���������������???0%��
		\param outputPercent  ?������Loss��?�%?��?������?0~100��

		\~japanese
		�����ܪʫ���髤��?��Ǫϡ�unreliable��ë�?���󫰪���?�ȫ�ի��ë��Ϊ۪Ȫ�ɪ�￪�몳�Ȫ˪�êơ�?���unreliable��ë�?����Ѧ���˫ȫ�ի��ë���������Ѧ������ʥ���ު���
		�ѫ��ëȫ�������Ѧ
		\param remoteHostID �ɪΫ��?�ȪȪ������?����������몫���������peer��server �ʪ�Ǫ�����ʦ���Ǫ���������Ǫ����0%�Ǫ���
		\param outputPercent���ѫ��ëȫ��㪬%?�Ȫ�?������ު���(���ʪ����0~100)

		\~
		*/
		virtual ErrorType GetUnreliableMessagingLossRatioPercent(HostID remotePeerID, int *outputPercent) = 0;

		//		virtual void SetTimerCallbackIntervalMs(int newVal) = 0;
	};

	PROUD_API const PNTCHAR* ToString(ConnectionState cs);

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif

	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#ifdef _MSC_VER
#pragma warning(pop)
#endif