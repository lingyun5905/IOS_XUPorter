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
	/** 
	\~korean
	����ڴ� �� �޼��嵵 �����ؾ� �մϴ�.
	
	����
	- C++ �̿� ���������� �� �޼���� delegate callback ������ �� �ֽ��ϴ�. 
	
	\~english TODO:translate needed.
	Users must implement this method. 
	
	Note
	- In versions other than C++, this method may be in the form of delegate callback. 

	\~chinese
	��?��????۰����

	?��
	- C++����������۰��ʦ����delegate callback���ҡ�

	\~japanese
	��?��?�Ϫ��Ϋ᫽�ëɪ�?�ު��ʪ���Ъʪ�ު���

	?��
	- C++ ���Ϋ�?�����Ǫϡ����Ϋ᫽�ëɪ�delegate callback�����˪ʪ몳�Ȫ�����ު��� 

	*/
	class IHlaDelegate_Common
	{
	public:
		virtual ~IHlaDelegate_Common() {}
		
		/** 
		\~korean
		HLA ���� ��⿡ ���� ��� ��ȣ�� ��û�Ǹ� �� �޼��尡 �ݹ�˴ϴ�. ����ڴ� �̸� �����ؾ� �մϴ�.
		���� ���, ����� �� ��ƾ���� �޸𸮸� ��ȣ�� critical section ����� �Ͻ� �� �ְڽ��ϴ�. 
		
		\~english TODO:translate needed.
		If lock protection is requested by an HLA internal module, this method is called back. Users must implement this. 
		For example, you may do critical section lock that would protect the memory from this routine. 
		
		\~chinese
		��HLA?ݻټ?�??����?��?�۰��?��?����?�????��
		������?ʦ���routine?����??����critical section?�ҡ�

		\~japanese
		HLA?ݻ�⫸��?��˪�êƫ�ë����ު���몵�쪿�骳�Ϋ᫽�ëɪ���?��Ыë�����ު�����?��?�Ϫ����?�ު��ʪ���Ъʪ�ު���
		�Ǫ��С����ʪ��Ϫ��Ϋ�?����ǫ���?�����ު���critical section��ë��򪹪몳�Ȫ��Ǫ��ު���

		*/
		virtual void HlaOnLockCriticalSection() = 0;

		/** 
		\~korean
		HlaOnLockCriticalSection()�� �ݴ� ������ �մϴ�. 
		
		\~english TODO:translate needed.
		It performs the opposite role of HlaOnLockCriticalSection()
		
		\~chinese
		���HlaOnLockCriticalSection()���������ġ�

		\~japanese
		HlaOnLockCriticalSection()����?��ܪ򪷪ު��� 

		*/
		virtual void HlaOnUnlockCriticalSection() = 0;
	};
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
