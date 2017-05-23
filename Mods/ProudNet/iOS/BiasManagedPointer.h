/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 177 92 124 113 87 79 17 155 171 239 138 133 88 235 28 112 146 102 93 52 214 131 240 31 138 179 248 115 127 118 107 31 112 91 111 14 243 1 121 131 22 69 144 19 214 101 65 133 253 32 122 175 12 198 63 134 23 240 109 90 59 142 194 194 160 148 139 101 68 220 217 181 32 240 36 47 59 74 18 182 145 116 17 29 255 115 236 11 29 111 122  */
#pragma once

#include "ProcHeap.h"

namespace Proud
{
	/* Type�� ����Ű�� ��ü Ÿ�� ��ü�� ���� Ư¡�� ������ �Ѵ�.
	- ��ü ��ü�� ����Ʈ ������ Ÿ���� �ǰ� �Ѵ�. �� ���� ����� ������ �Ѵ�.
	- ��ü�� ������ ���� ��ü(substance)�� class level�� ���� object pool���� ����ǰ� �Ѵ�. �� ��ü ����/�Ҵ� ����� ������ �� �ְ� ���ش�.

	���ǻ���: ���� �ʱ�ȭ�� ���� ������ü�� ����ȴٴ� ���� ������, ��� �������� �������� �� �ִ�. �� �ʿ�� ��� �������� ���� û���� �־�� �Ѵ�.
	Type�� Clear(), SuspendShrink()�� ������ �Ѵ�. �ƹ��͵� ���ϴ���.
	���� ����ڴ� ���� ��� �Ұ����� Ŭ����. src/ �ȿ����� ����. */
	template<typename Type, bool ClearOnDrop>
	class BiasManagedPointer
	{
	public:
		// ���� ī��Ʈ�� ��ü ��ü�� �� �޸� ���� ��� ������.
		class Tombstone
		{
		public:
			// ���� ������ ��ü
			Type m_substance;

			// ���� ī��Ʈ
			volatile intptr_t m_refCount;

			inline Tombstone()
			{
				m_refCount = 0;
			}

			// �迭 ���̳� ���� �ִ� ���۰� ���Ƶ��� ���̴� ����� �����Ѵ�.
			void SuspendShrink()
			{
				m_substance.SuspendShrink();
			}
			void OnRecycle() {}
			void OnDrop()
			{
				m_substance.OnDrop();
			}


			DECLARE_NEW_AND_DELETE
		};

	private:
		// refcount�� Type ��ü�� ������ ��ü.
		Tombstone* m_tombstone;

		//////////////////////////////////////////////////////////////////////////
		// src/ �ȿ��� ������. ��� ���Ͽ� ���� ����. 

		static Tombstone* AllocTombstone();
		static void FreeTombstone(Tombstone* tombstone);

		//////////////////////////////////////////////////////////////////////////

	protected:
		// �Ļ� Ŭ���� �ȿ��� ��ü�� �׼����� �� ���δ�.
		inline Tombstone* GetTombstone() const
		{
			return m_tombstone;
		}

	public:
		inline BiasManagedPointer()
			: m_tombstone(NULL)  // ó������ Tombstone ��ü�� ����. ������� ����ڰ� InitTombstoneIfEmpty()�� �� �ؾ� �Ѵ�.
		{
		}

		// ���� ������
		inline BiasManagedPointer(const BiasManagedPointer& src)
		{
			// src�� tombstone�� �����Ѵ�.
			if (src.m_tombstone)
			{
				AtomicIncrementPtr(&src.m_tombstone->m_refCount);
				m_tombstone = src.m_tombstone;
			}
			else
				m_tombstone = NULL;
		}

#ifdef SUPPORTS_CPP11
		// �̵� ������
		inline BiasManagedPointer(BiasManagedPointer&& src)
		{
			if (src.m_tombstone)
			{
				// smart ptr�̹Ƿ� �̵� �����ڰ� �� �δ�.
				m_tombstone = src.m_tombstone;
				// �̵� �������̹Ƿ�, src�� ��� ������.
				src.m_tombstone = NULL;
			}
			else
				m_tombstone = NULL;
		}
#endif

		// ���� ������
		inline BiasManagedPointer& operator=(const BiasManagedPointer& src)
		{
			if (src.m_tombstone != m_tombstone)
			{
				UninitTombstone(); // ���� �� ����

				if (src.m_tombstone != NULL)
				{
					AtomicIncrementPtr(&src.m_tombstone->m_refCount);
					m_tombstone = src.m_tombstone;
				}
			}

			return *this;
		}

#ifdef SUPPORTS_CPP11
		// �̵� ������
		inline BiasManagedPointer& operator=(BiasManagedPointer&& src)
		{
			if (&src != this)
			{
				UninitTombstone(); // ���� �� ����

				// ������ �̾�
				m_tombstone = src.m_tombstone;
				// src�� ��� ������.
				src.m_tombstone = NULL;
			}

			return *this;
		}
#endif

		inline ~BiasManagedPointer()
		{
			UninitTombstone(); 
		}

	protected:
		// Tombstone�� ������ �ʱ� ���·� ����.
		inline void UninitTombstone()
		{
			if (m_tombstone)
			{
				// ���۷��� ī��Ʈ ���̰� 0�� �Ǹ�
				if (AtomicDecrementPtr(&m_tombstone->m_refCount) == 0)
				{
					// ��û�Ͽ� ���빰 û��
					if(ClearOnDrop)
						m_tombstone->m_substance.Clear();

					// obj-pool�� ��ȯ
					FreeTombstone(m_tombstone);
				}
				m_tombstone = NULL;
			}
		}

		// Tombstone�� �Ҵ��Ѵ�. �̹� ���� ������ skip.
		// Tombstone �Ҵ��̶� ����, Type subtance ��ü�� �� �������� �ǹ��Ѵ�.
		// ����, object-pool���� �����´�.
		inline void InitTombstoneIfEmpty()
		{
			if(!m_tombstone)
			{
				m_tombstone = AllocTombstone();
				m_tombstone->SuspendShrink();
				m_tombstone->m_refCount = 1;
			}
		}
	};
}

#include "BiasManagedPointer.inl"
