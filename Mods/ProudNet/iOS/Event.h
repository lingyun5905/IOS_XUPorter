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



/*
LICENSE

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/



#pragma once

#include "BasicTypes.h"

#if !defined(_WIN32)
#include <pthread.h>
#endif

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup util_group
	*  @{
	*/

	/** 
	\~korean
	��Ƽ������ ���α׷��ֿ����� �̺�Ʈ ��ü�̴�.

	\~english
	Event object in multi-thread programming

	\~chinese
	��?��?����������?�ڡ�

	\~japanese
	�ޫ������ëɫ׫���߫󫰪ǪΫ��٫�ȫ��֫������ȪǪ���
	\~
	*/
	class Event
	{
	public:

#if defined(_WIN32)
		HANDLE m_event;

#elif defined(__linux__) || defined(__MACH__) || defined(__FreeBSD__)

		pthread_mutex_t	m_mutex;
		pthread_cond_t m_condVar;

		bool	m_manualReset;
		bool	m_isSignaled;
#endif

		/**
		\~korean
		������
		\param manualReset ::WaitForSingleObject �Ǵ� WaitAny, WaitAll ���� ���� �� ��ü�� �ñ׳��� ����ϴ� �����尡 �ִ� ���¿���
		�ñ׳��� �߻��ϸ� ��Ⱑ ������ �ȴ�. �̶� �̺�Ʈ ��ü�� �ڵ����� non-singal ����(event reset)�� �ǰ� �� ���̶�� true�� �ֵ��� �Ѵ�.
		\param initialState �� �̺�Ʈ ��ü�� �ñ׳��� ó������ ���� ���·� �����ǰ� �Ϸ��� true

		\~english
		Constructor
		\param manualReset Waiting will end when signal occurs while there exists thread waiting for this object's signal through ::WaitForSingleObject or WaitAny or WaitAll.
		Enter true to make event object be non-signal state (event reset) automatically.
		\param initialState True in order to create this event object as to make it received signal initially.

		\~chinese
		�����
		\param manualReset ��?::WaitForSingleObject ���WaitAny, WaitAll���������??����?��?�������??����?����?��???�����⡣??����?����?���??��non-signal ??��event reset����??��true��
		\param initialState ��?�����?������???�����?��??��?true��

		\~japanese
		�����
		\param manualReset ::WaitForSingleObject �ު��� WaitAny, WaitAll �ʪɪ��ת������Ϋ��֫������ȪΫ����ʫ����Ѧ���뫹��ëɪ�����?���ǫ����ʫ몬?�檹�����Ѧ�������ު��������������٫�ȫ��֫������Ȫ���Ѫ�non-signal?��(event reset)�˪ʪ�誦�˪����������true������ƪ���������
		\param initialState ���Ϋ��٫�ȫ��֫������Ȫ������ʫ����������������?�������������誦�˪���������� true
		\~
		*/
		PROUD_API Event(bool manualReset, bool initialState);

		/**
		\~korean
		�⺻ �ɼ����� �����Ѵ�.
		- auto reset, non signaled�� �����Ѵ�.

		\~english
		Creates with default option
		- Begins as auto reset and non signaled

		\~chinese
		��������??��
		- ?auto reset, non signaled ?㷡�

		\~japanese
		���⫪�׫����Ȫ����������ު���
		- auto reset, non signaled����㷪��ު���
		\~
		*/
		PROUD_API Event();

		/**
		\~korean
		�ı���

		\~english
		Destructor

		\~chinese
		��?�

		\~japanese
		��?�
		\~
		*/
		PROUD_API ~Event();

		/**
		\~korean
		�̺�Ʈ�� �ñ׳��� �ִ´�.

		\~english
		Enters signal into event

		\~chinese
		�����?��ʥ����?��

		\~japanese
		���٫�Ȫ˫����ʫ������ު���
		\~
		*/
		inline void Set()
		{
#if defined(_WIN32)
			::SetEvent(m_event);
#elif defined(__linux__) || defined(__FreeBSD__)
			int ret = 0;

			// mutex lock ��� �۾� �ؾ���
			ret = pthread_mutex_lock(&m_mutex);
			assert(ret == 0);

			m_isSignaled = true;

			// windows event �� manual reset �϶� ��� �����尡 ���
			// (reset �� �Ƚ�Ű�� ��� signal ���¶�...)
			if (m_manualReset)
			{
				ret = pthread_cond_broadcast(&m_condVar);
				assert(ret == 0);
			}
			else  // Auto Reset...
			{
				// WFSO ���� �����忡�� signal ����
				ret = pthread_cond_signal(&m_condVar);
				assert(ret == 0);

				// !! ���⼭ state ���� �����ϸ� �ȵ�
				// ��� �����尡 �ٲ����
				// m_isSignaled = false;
			}

			ret = pthread_mutex_unlock(&m_mutex);
			assert(ret == 0);
#endif
		}

		/**
		\~korean
		�ñ׳��� �����Ѵ�.

		\~english
		Revmoes signal

		\~chinese
		����?��

		\~japanese
		�����ʫ����۪��ު���
		\~
		*/
		inline void Reset()
		{
#if defined(_WIN32)
			::ResetEvent(m_event);
#elif defined(__linux__)
			int ret = 0;

			ret = pthread_mutex_lock(&m_mutex);
			assert(ret == 0);

			m_isSignaled = false;

			ret = pthread_mutex_unlock(&m_mutex);
			assert(ret == 0);
#endif
		}

		/**
		\~korean
		�ñ׳��� �� ������ ��ٸ���.
		\param timeOut (�и���) �ñ׳� ��� �ִ� �ð�. INFINITE�� ������ ������ ��ٸ���.

		\~english
		Waits until signal arrives
		\param timeOut (in milliseconds) signal waiting max time. It waits permanantly when infinite entered.

		\~chinese
		������?��?��
		\param timeOut �����أ�������?����??��ʥ��INFINITE��?���������⡣

		\~japanese
		�����ʫ몬?�����ު�����ު���
		\param timeOut (�߫���) �����ʫ���Ѧ�������ࡣINFINITE�������������Ҫ�����ު���
		\~
		*/
		PROUD_API bool WaitOne(uint32_t timeOut);

		/**
		\~korean
		�ñ׳��� �� ������ ������ ��ٸ���.

		\~english
		Waits indefinitely until signal arrives
		
		\~chinese
		���������?��?��

		\~japanese
		�����ʫ몬?�����ު������Ҫ�����ު���
		\~
		*/
		PROUD_API bool WaitOne();

		/**
		\~korean
		�Էµ� �̺�Ʈ ��ü�� �� �ϳ��� �ñ׳��� �߻��� ������ ��ٸ���.
		\return -1 �Ǵ� �Ϸ� ������ �̺�Ʈ ��ü�� �迭 �׸�

		\~english
		Waits until at least one of event objects entered occurs
		\return -1 or allocation clause of event object that has been successfully completed

		\~chinese
		����?��������??������?����?����?��
		\return -1�����?����������?������֪?�͡�

		\~japanese
		�������쪿���٫�ȫ��֫������ȪΪ�����ĪǪ⫷���ʫ몬?�檹�����ު�����ު���
		\return -1 �ު������������������٫�ȫ��֫������Ȫ���֪����
		\~
		*/
#if defined(_WIN32)
		inline static int WaitAny(Event** events, int count)
		{
			return WaitAny(events, count, PN_INFINITE);
		}
#endif

		/**
		\~korean
		�Էµ� �̺�Ʈ ��ü�� �� �ϳ��� �ñ׳��� �߻��� ������ ��ٸ���.
		\return -1 �Ǵ� �Ϸ� ������ �̺�Ʈ ��ü�� �迭 �׸�

		\~english
		Waits until at least one of event objects entered occurs
		\return -1 or allocation clause of event object that has been successfully completed

		\~chinese
		����?��������??������??����?��
		\return -1�����?����������?������֪?�͡�

		\~japanese
		�������쪿���٫�ȫ��֫������ȪΪ�����ĪǪ⫷���ʫ몬?�檹�����ު�����ު���
		\return -1 �ު������������������٫�ȫ��֫������Ȫ���֪����
		\~
		*/
#if defined(_WIN32)
		static int WaitAny(Event** events, int count, uint32_t timeOut);
#endif

		/**
		\~korean
		�Էµ� �̺�Ʈ ��ü�� ��� �ñ׳��� �߻��� ������ ��ٸ���.

		\~english
		Waits until all of event objects entered occur

		\~chinese
		����������?����ݻ?����?��

		\~japanese
		�������쪿���٫�ȫ��֫���������ƪ˪����ƫ����ʫ몬?�檹�����ު�����ު���
		\~
		*/
#if defined(_WIN32)
		inline static int WaitAll(Event** events, int count)
		{
			return WaitAll(events, count, PN_INFINITE);
		}
#endif

		/**
		\~korean
		�Էµ� �̺�Ʈ ��ü�� ��� �ñ׳��� �߻��� ������ ��ٸ���.

		\~english
		Waits until all of event objects entered occur

		\~chinese
		����������?����ݻ?����?��

		\~japanese
		�������쪿���٫�ȫ��֫���������ƪ˪����ƫ����ʫ몬?�檹�����ު�����ު���
		\~
		*/
#if defined(_WIN32)
		static int WaitAll(Event** events, int count, uint32_t timeOut);
#endif
	private:
#if defined(_WIN32)
		static int WaitForSignal(Event** events, int count, uint32_t timeOut, bool waitForAll);
#endif

	public:
		// called by CObjectPool. does nothing.
		void SuspendShrink() {}
		void OnRecycle() {}
		void OnDrop() {
			// handle�� ������ �ʴ´�. Ŀ�� ���ҽ� ��ü�� �����ϴϱ�.
		}
	};
	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
