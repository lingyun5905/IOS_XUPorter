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

#include "LambdaWrap.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup net_group
	*  @{
	*/

	/**
	\~korean
	CThreadPool ���� �߻��ϴ� �̺�Ʈ �ݹ��� �޾� ó���ϴ� �������̽� Ŭ�����Դϴ�.

	�ڼ��� ���� <a target="_blank" href="http://guide.nettention.com/cpp_ko#thread_pool_sharing" >�������� ���� ȣ��Ʈ ����� ���� Thread Pool�� �����ϱ�</a> �� �����Ͻʽÿ�.

	����
	- ��ü�� ��ӹ޾� �޼��带 �����մϴ�.
	- CThreadPool �� �� ��ü�� �Ķ���ͷ� �����մϴ�.

	\~english
	This is interface class that hand event callback occured from CThreadPool.

	Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#thread_pool_sharing" >Share Thread Pool that has same host module in a server.</a> for more detail.

	Usage
	- Realize this method to inherit object.
	- Pass this object to parameter at CThreadPool

	\~chinese
	���??��? CThreadPool%?����event��?��ͣ��?��

	??��??��<a target="_blank" href="http://guide.nettention.com/cpp_zh#thread_pool_sharing" >���?��������??���ټ?������Thread Pool</a>%��

	����۰��
	- ?�?�����??�۰����
	- ���?��????��? CThreadPool%��

	\~japanese
	CthreadPool��?�檹�뫤�٫�ȫ�?��Ыë���������?�⪹�뫤��?�ի�?�����髹�Ǫ���

	�٪����ϡ�\ref thread_pool_sharing��?�Ϊ���������

	����۰��
	- ���֫������Ȫ���?���ƪ�骤�᫽�ëɪ�?�ު��ު���
	- CThreadPool�ت��Ϋ��֫������Ȫ�ѫ��?��?��?ӹ���ު���
	\~
	*/
	class IThreadPoolEvent
	{
	public:
		/**
		\~korean
		thread pool�� �����尡 ������ �� �� �޼��尡 ȣ��˴ϴ�.

		\~english
		When thread pool started thread, call this method.

		\~chinese
		thread pool ?��?���?����У�۰����

		\~japanese
		thread pool�Ϋ���ëɪ���㷪����������Ϋ᫽�ëɪ������󪵪�ު���
		\~
		*/
		virtual void OnThreadBegin() = 0;

		/**
		\~korean
		thread pool�� �����尡 ������ �� �� �޼��尡 ȣ��˴ϴ�.

		\~english
		When thread pool is terminated, call this method.

		\~chinese
		thread pool ?��?����?����У�۰����

		\~japanese
		thread pool�Ϋ���ëɪ����������������Ϋ᫽�ëɪ������󪵪�ު���
		\~
		*/
		virtual void OnThreadEnd() = 0;
	};

#ifdef SUPPORTS_CPP11

	// C++11�� ����Ͻ� �� ������, �̰��� ���ô� �͵� ���� ���Դϴ�.
	class CThreadPoolEventFunctional:public IThreadPoolEvent
	{
	public:
		std::function<void()> OnThreadBeginFunction;
		std::function<void()> OnThreadEndFunction;
	
	private:
		void OnThreadBegin() 
		{
			if (OnThreadBeginFunction)
				OnThreadBeginFunction();
		}

		void OnThreadEnd() 
		{
			if (OnThreadEndFunction)
				OnThreadEndFunction();
		}

	};

#endif

	/**
	\~korean
	�������̵� ȣ��Ʈ ���(CNetServer,CLanServer,CLanClient)�� ���� thread pool ��ü�Դϴ�.

	�ڼ��� ���� <a target="_blank" href="http://guide.nettention.com/cpp_ko#thread_pool_sharing" >�������� ���� ȣ��Ʈ ����� ���� Thread Pool�� �����ϱ�</a> �� �����Ͻʽÿ�.

	\~english
	This is thread pool object for server-sided host module(CNetServer,CLanServer,CLanClient)

	Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#thread_pool_sharing" >Share Thread Pool that has same host module in a server.</a> for more detail.

	\~chinese
	?��server-sided ���ټ����CNetServer,CLanServer,CLanClient����thread pool?�ڡ�

	????��<a target="_blank" href="http://guide.nettention.com/cpp_zh#thread_pool_sharing" >���?��������??���ټ?������Thread Pool</a>%��

	\~japanese
	��?��?�����ɪΫ۫��ȫ⫸��?��(CNetServer,CLanServer,CLanClient)�Ϊ����thread pool���֫������ȪǪ���
	
	�٪����ϡ�\ref thread_pool_sharing��?�Ϊ���������
	\~

	����
	- tp = CThreadPool.Create();
	- tp.SetEventSink(...); // (optinal)
	- tp.SetThreadCount(n); // n = 0~512
	- NC,NS,LC,LS���� tp�� ������ ����
	- delete tp;

	TODO: ��� �ּ� �ٵ��� �� �ٱ���ȭ�ؾ�!

	*/
	class CThreadPool
	{
	public:
		virtual ~CThreadPool();

		// ���ϴ� ���� ������� ������ �����Ѵ�.
		// 0~512���� ����.
		// �� �Լ��� ��� ���ϵǰ�, �ð��� �����鼭 ��ǥġ�� ���� �ȴ�.
		// 0�� �� ��� ����ڴ� CThreadPool.Process�� �Ź� ȣ���� �־�� �Ѵ�.
		virtual void SetDesiredThreadCount(int threadCount) = 0;

		/**
		\~korean
		��Ʈ��ŷ ������ ��ſ� ThreadPool�� �����մϴ�.

		\~english
		Creates ThreadPool for server communications

		\~chinese
		����??��?����?��������ThreadPool��

		\~japanese
		��?��?��������ThreadPool���������ު���
		\~
		*/
		static CThreadPool *Create(IThreadPoolEvent* eventSink, int threadCount);

		// zero thread pool�� ����, heartbeat ó���� �Ѵ�.
		// zero thread pool�� ��� ���������� ȣ���ؾ� �Ѵ�.
		// ����: �ִ� ��� �ð�. 0�� ������ ����� ����.
		// TODO: �� �ּ��� �����Ͽ� ����ڰ� �����ϰ� �ϰ�, zero thread pool�� ���� ��ó�� advanced usage �׸� �߰��ϵ��� ����.
		virtual void Process(int timeoutMs) = 0;
	
	};

	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
