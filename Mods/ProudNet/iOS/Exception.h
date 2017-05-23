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

#include <exception>
#include "BasicTypes.h"
#include "PNString.h"
#include "Enums.h"
#include "Ptr.h"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4324)
#endif // __MARMALADE__

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{

	/** \addtogroup util_group
	*  @{
	*/
	class ErrorInfo;

	/**
	\~korean
	Exception Type ��ü
	- type���� �����Ͽ� �ش� exception ��ü�� ������ �� ������ ������ �ֽ��ϴ�.

	\~english
	Exception Type object
	- You can get pointer and information of exception object by classifying type.

	\~chinese
	Exception Type?��
	- �type?����ʦ�?����?exception?�����?�����ӡ�

	\~japanese
	Exception Type ���֫�������
	- type��?�ª�����?exception���֫������ȪΫݫ���?������ê���몳�Ȫ��Ǫ��ު���
	\~
	*/
	enum ExceptionType
	{
		/**
		\~korean
		����

		\~english
		None

		\~chinese
		��

		\~japanese
		�ʪ�
		\~
		*/
		ExceptionType_None = 0,

		/**
		\~korean
		 Exception(LPCWSTR pFormat, ...); ���� ������ Exception

		\~english
		Exception that created by Exception(LPCWSTR pFormat, ...);

		\~chinese
		����?Exception(LPCWSTR pFormat, ...);��Exception��

		\~japanese
		Exception(LPCWSTR pFormat, ...); �����������쪿 Exception
		\~
		*/
		ExceptionType_String,

		/**
		\~korean
		Exception(std::exception& src); ���� ������ Exception

		\~english
		Exception that created by Exception(std::exception& src);

		\~chinese
		����?Exception(std::exception& src);��Exception��

		\~japanese
		Exception(std::exception& src); �����������쪿 Exception
		\~
		*/
		ExceptionType_Std,

		/**
		\~korean
		Exception(_com_error& src); ���� ������ Exception

		\~english
		Exception that created by Exception(_com_error& src);

		\~chinese
		����?Exception(_com_error& src);��Exception��

		\~japanese
		Exception(_com_error& src); �����������쪿 Exception
		\~
		*/
		ExceptionType_ComError,

		/**
		\~korean
		Exception(void* src); ���� ������ Exception

		\~english
		Exception that created by Exception(void* src);

		\~chinese
		����?Exception(void* src);��Exception��

		\~japanese
		Exception(void* src); �����������쪿 Exception
		\~
		*/
		ExceptionType_Void,

		/**
		\~korean
		Exception(ErrorInfo* src); ���� ������ Exception

		\~english
		Exception that created by Exception(ErrorInfo* src);

		\~chinese
		����?Exception(ErrorInfo* src);��Exception��

		\~japanese 
		Exception(ErrorInfo* src); �����������쪿 Exception
		\~
		*/
		ExceptionType_ErrorInfo,

		/**
		\~korean
		Exception() ���� ������ UnhandleException

		\~english
		UnhandleException that created by Exception()

		\~chinese
		����?Exception()��UnhandleException��

		\~japanese
		Exception() �����������쪿 UnhandleException
		\~
		*/
		ExceptionType_Unhandled,

		/**
		\~korean
		CLR�� ����ϴ� ��� Managed code���� �߻��� Exception

		\~english
		Exception occurred in the managed code in case of using a CLR. 

		\~chinese
		����CLR?�Managed code��?����Exception

		\~japanese
		CLR�����Ī������ꡢManaged code���?�檷��Exception

		\~
		*/
		ExceptionType_Clr
	};

	/**
	\~korean
	printf()ó�� ���� �޽����� �޾� ���� �� �ִ� exception ��ü.
	��� ������ ���� ����.

	\~english
	An exception object that can receive and send an error message as printf().
	It's commonly used as followed.

	\~chinese
	��printf()��?�����??��??������exception?�ڡ�
	����?��������

	\~japanese
	printf()�Ϊ誦�˫���?��ë�?������������몳�Ȫ��Ǫ���exception���֫�������
	���ȡ��Ϊ誦�����Ī��ު���

	\~

	\code
		throw Exception("error=%d",error);
	\endcode

	*/
	class Exception : public std::exception // std::exception�� defacto C++ ǥ����. ������ �� ��!
	{
	private:
		void operator= (const Exception& src);

	public:
		/**
		\~korean
		Exception �� ���߽�Ų remote �� hostID

		\~english
		hostID of remote that occured Exception

		\~chinese
		??Exception��remote��host ID��

		\~japanese
		Exception ���?���쪿remote��hostID
		\~
		*/
		HostID m_remote;

		/**
		\~korean
		void*�� Exception ��ü�� �����͸� �����Ѵ�.

		\~english
		Save pointer of void*type Exception object

		\~chinese
		?��void*��Exception?�����?��

		\~japanese
		void*��Exception���֫������ȪΫݫ���?�������ު���
		\~
		*/
		void* m_pVoidSource;

		/**
		\~korean
		std::exception ��ü�� �����͸� �����Ѵ�.

		\~english
		Save pointer of std::exception object

		\~chinese
		?�� std::exception%?�����?��

		\~japanese
		std::exception ���֫������ȪΫݫ���?�������ު���
		\~
		*/
		std::exception *m_pStdSource;

		/**
		\~korean
		Exception Type ��ü

		\~english
		Exception Type object

		\~chinese
		Exception Type?�ڡ�

		\~japanese
		Exception Type ���֫�������
		\~
		*/
		ExceptionType m_exceptionType;

		/**
		\~korean
		ErrorInfo ��ü�� �������� �����Ѵ�.

		\~english 
		Save the copy of ErrorInfo object. 

		\~chinese 
		����ErrorInfo?�������⡣

		\~japanese 
		ErrorInfo ���֫������ȪΫ���?�������ު���
		\~
		*/
		RefCount<ErrorInfo> m_errorInfoSource;

		/**
		\~korean
		- ����� ���� �ݹ鿡�� Exception�� �߻��� ��� �ش� �Լ����� ��ϵ˴ϴ�.
		- ����� ���� RMI Stub���� Exception�� �߻��� ��� �ش� RMI ID�� ��ϵ˴ϴ�.

		\~english
		- The relevant name of function will be recorded in case exception occurs at user definition callback.
		- The relevant RMI ID will be recorded in case exception occurs at user definition RMI Stub.

		\~chinese
		- ����?Callback��?��Exception?��?��?٣?��??��
		- ����?RMI Stub��?��Exception?��?RMI ID?��??��

		\~japanese
		- ��?��?����Callback����Exception��?�檷�����ꡢ��???٣����?����ު���
		- ��?��?����RMI Stub����Exception��?�檷�����ꡢ��?RMI ID����?����ު���
		\~
		*/
		String m_userCallbackName;

		/**
		\~korean
		- ����� ���� �ݹ鿡�� Exception�� �߻��� ��� �ش� �ݹ��� ������ ��ü(SetEventSink�� ����� ��ü)�� �ּҰ� �Էµ˴ϴ�.
		- ����� ���� RMI Stub���� Exception�� �߻��� ��� �ش� Stub�� ������ IRmiStub��ü(AttachStub���� ����� ��ü)�� �ּҰ� �Էµ˴ϴ�.
		- m_userCallbackName���� ������ �Լ��� �Ǻ��ϱ� ����� ��� �� ������ ���� ��Ʈ�� �� �� �ֽ��ϴ�.

		\~english
		- In case exception occurs at user definition callback, the address of object that has been registered by SetEventSink will be inputted.
		- In case exception occurs at user definition RMI Stub, the address of IRmiStub object that has been registered by AttachStub will be inputted.
		- This variable value could be the hint in case it is difficult to find out the problematic function by m_userCallbackName.

		\~chinese
		- ����?Callback��?��Exception?�� ?Callback�??��?�ڣ��SetEventSink�?��?�ڣ�����?��?����
		- ����?RMI Stub��?��Exception?�� ?Stub�??��IRmiStub?�ڣ��AttachStub�?��?�ڣ�����?��?����
		- �m_userCallbackName??��???��??��????�?����ơ�


		\~japanese
		- ��?��?����Callback����Exception��?�檷�����ꡢ��?Callback�����ު��쪿���֫�������(SetEventSink����?���쪿���֫�������)�Ϋ��ɫ쫹����������ު���
		- ��?��?����RMI Stub����Exception��?�檷�����ꡢ��?Stub�����ު��쪿IRmiStub���֫�������(AttachStub����?���쪿���֫�������)�Ϋ��ɫ쫹����������ު���
		- m_userCallbackName������??����ܬ���˪������ꡢ����??�������ҫ�Ȫ˪ʪ�ު���

		\~
		*/
		void* m_delegateObject;

		StringA chMsg;// public because of Exception_UpdateFromComError

	public:
		PROUD_API Exception(void);
		PROUD_API Exception(const char* text);
		PROUD_API Exception(const wchar_t* text);
		PROUD_API Exception(std::exception& src);
		PROUD_API Exception(ErrorInfo* src);
		PROUD_API Exception(const Exception& src);

		PROUD_API ~Exception(void) throw();

		/**
		\~korean
		Exception �� ���� ���ڿ� �����͸� �����մϴ�.

		\~english 
		Return the string pointer to the exception. 

		\~chinese
		����?Exception���ݬ���?��

		\~japanese
		Exception ��?�������֪�ݫ���?��꫿?�󪷪ު���
		\~
		*/
		PROUD_API const char *what( ) const throw();

	};

	PROUD_API void XXXHeapChkImpl(int index = 1); // PN DLL�̸� �̰� ����!

#if defined(CHECK_HEAP_CORRUPTION) && defined(_WIN32)
	#define XXXHeapChk XXXHeapChkImpl
#else
	#if (_MSC_VER>=1500) // 2005 ���� ���Ͽ����� �������� �����ȵ�.
		#define XXXHeapChk(...)
	#else
		#if defined(_WIN32)
			#define XXXHeapChk __noop
		#else
			#define XXXHeapChk(...)
		#endif
	#endif
#endif

	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#ifdef _MSC_VER
#pragma warning(pop)
#endif // __MARMALADE__
