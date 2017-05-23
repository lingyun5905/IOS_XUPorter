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

#include "CallbackContext.h"
#include <functional>
#include "Ptr.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

//////////////////////////////////////////////////////////////////////////
// ���ٽ� ���� �����Ϸ��� ������ �����Ϸ� ��θ� ���� �Լ� ��ü ���� ���ǵ� 
// ���� ���� ����̹Ƿ�. �������� ������.

namespace Proud
{
	/* �Ķ���� ������ ��� ������� ó�� ������ �Ϲ����� ���ٽ� ��ü�� ���̽� Ŭ����.
	���������� std::function�� �����Ƿ�, �׻� ���� ũ�� Ŭ�������� �����Ѵ�.
	�׸��� C++11�� ���ų� ���ٽ� ������ �����Ϸ������� �� Ŭ������ ���簡 �����ϴ�.
	���� �̸� ����� ���̺귯�������� �̽ļ��� �����Ѵ�.
	RETURN���� ���ٽ��� ���� Ÿ���� ����. void�� ����.

	��� ��:
	shared_ptr<LambdaBase_Param0<void>> p1;

	std::function<void()> f = [](){...}; // �Լ� ��ü
	p1 = new Lambda_Param0<void()>(f); // �Լ� ��ü�� �ִ´�.


	Q: ���ٽ� ������ �����Ϸ������� �̰��� ����� �ϳ���?
	A: ��ü ����̱� ������ ������ ã�� ���� ���׷� �̾��� �� �ֽ��ϴ�.
	�ڼ��� ���� Sole/doc �� Lambda support.pptx�� �����Ͻñ�.
	*/


	// �Լ� ��ü�� ������ ������ Ŭ������ �������̽� Ŭ����.
	// ���ٽ� ������ �����Ϸ������� ���� �����ϴ�.
	template<typename RETURN>
	class LambdaBase_Param0
	{
	public:
		virtual RETURN Run() = 0;
		virtual ~LambdaBase_Param0() {}
	};

#ifdef SUPPORTS_LAMBDA_EXPRESSION
	// �Լ� ��ü�� ������ ������ Ŭ����.
	// RETURN: void() or bool() ���� ���� �ȴ�. �Ķ���� 0��.
	template<typename RETURN>
	class Lambda_Param0 :public LambdaBase_Param0 < RETURN >
	{
		// thread and context
		std::function<RETURN()> m_lambda;
	public:
		Lambda_Param0(const std::function<RETURN()> &lambda) { m_lambda = lambda; }
		void Run() { m_lambda(); }
	};

#endif

	/*

	��뿹

	LambdaBaseHolder_Param0 p;
	std::function<...> f = [](){...};
	p = f;
	*/

	template<typename RETURN>
	class LambdaBaseHolder_Param0
	{
		typedef LambdaBase_Param0<RETURN> BaseType;
#ifdef SUPPORTS_LAMBDA_EXPRESSION
		typedef Lambda_Param0<RETURN> LambdaType;
#endif

	public:
		// �Լ� ��ü ��ü.
		// ���� ������ �����Ϸ������� ����� �����ؾ�. ���� ����̹Ƿ�.
		// We don't use shared_ptr as this is public in include/ folder.
		RefCount<BaseType> m_functionObject;

#ifdef SUPPORTS_LAMBDA_EXPRESSION
		LambdaBaseHolder_Param0& operator=(const std::function<RETURN()>& lambda)
		{
			m_functionObject = RefCount<BaseType>(new LambdaType(lambda));
		}
#endif
	};



	//////////////////////////////////////////////////////////////////////////
	// �Ʒ� Ŭ�������� ������ ����, ���� �Ķ���� ������ �ٸ���.

	template<typename RETURN, typename PARAM1>
	class LambdaBase_Param1
	{
	public:
		virtual RETURN Run(PARAM1 param1) = 0;
		virtual ~LambdaBase_Param1() {}
	};

#ifdef SUPPORTS_LAMBDA_EXPRESSION
	template<typename RETURN, typename PARAM1>
	class Lambda_Param1 :public LambdaBase_Param1 < RETURN, PARAM1 >
	{
		// thread and context
		std::function<RETURN(PARAM1)> m_lambda;
	public:
		Lambda_Param1(const std::function<RETURN(PARAM1)> &lambda) { m_lambda = lambda; }
		void Run(PARAM1 param1) { m_lambda(param1); }
	};
#endif

	template<typename RETURN, typename PARAM1>
	class LambdaBaseHolder_Param1
	{
		typedef LambdaBase_Param1<RETURN, PARAM1> BaseType;
#ifdef SUPPORTS_LAMBDA_EXPRESSION
		typedef Lambda_Param1<RETURN, PARAM1> LambdaType;
#endif

	public:
		// ���� ������ �����Ϸ������� ����� �����ؾ�. ���� ����̹Ƿ�.
		RefCount<BaseType> m_functionObject;

#ifdef SUPPORTS_LAMBDA_EXPRESSION
		LambdaBaseHolder_Param1& operator=(const std::function<RETURN(PARAM1)>& lambda)
		{
			m_functionObject = RefCount<BaseType>(new LambdaType(lambda));
			return *this;
		}
#endif
	};

	template<typename RETURN, typename PARAM1, typename PARAM2>
	class LambdaBase_Param2
	{
	public:
		virtual RETURN Run(PARAM1 param1, PARAM2 param2) = 0;
		virtual ~LambdaBase_Param2() {}
	};

#ifdef SUPPORTS_LAMBDA_EXPRESSION
	template<typename RETURN, typename PARAM1, typename PARAM2>
	class Lambda_Param2 :public LambdaBase_Param2 < RETURN, PARAM1, PARAM2 >
	{
		// thread and context
		std::function<RETURN(PARAM1, PARAM2)> m_lambda;
	public:
		Lambda_Param2(const std::function<RETURN(PARAM1, PARAM2)> &lambda) { m_lambda = lambda; }
		void Run(PARAM1 param1, PARAM2 param2) { m_lambda(param1, param2); }
	};
#endif

	template<typename RETURN, typename PARAM1, typename PARAM2>
	class LambdaBaseHolder_Param2
	{
		typedef LambdaBase_Param2<RETURN, PARAM1, PARAM2> BaseType;
#ifdef SUPPORTS_LAMBDA_EXPRESSION
		typedef Lambda_Param2<RETURN, PARAM1, PARAM2> LambdaType;
#endif

	public:
		// ���� ������ �����Ϸ������� ����� �����ؾ�. ���� ����̹Ƿ�.
		RefCount<BaseType> m_functionObject;

#ifdef SUPPORTS_LAMBDA_EXPRESSION
		LambdaBaseHolder_Param2& operator=(const std::function<RETURN(PARAM1, PARAM2)>& lambda)
		{
			m_functionObject = RefCount<BaseType>(new LambdaType(lambda));
			return *this;
		}
#endif
	};

	template<typename RETURN, typename PARAM1, typename PARAM2, typename PARAM3>
	class LambdaBase_Param3
	{
	public:
		virtual RETURN Run(PARAM1 param1, PARAM2 param2, PARAM3 param3) = 0;
		virtual ~LambdaBase_Param3() {}
	};

#ifdef SUPPORTS_LAMBDA_EXPRESSION
	template<typename RETURN, typename PARAM1, typename PARAM2, typename PARAM3>
	class Lambda_Param3 :public LambdaBase_Param3 < RETURN, PARAM1, PARAM2, PARAM3 >
	{
		// thread and context
		std::function<RETURN(PARAM1, PARAM2, PARAM3)> m_lambda;
	public:
		Lambda_Param3(const std::function<RETURN(PARAM1, PARAM2, PARAM3)> &lambda) { m_lambda = lambda; }
		void Run(PARAM1 param1, PARAM2 param2, PARAM3 param3) { m_lambda(param1, param2, param3); }
	};
#endif

	template<typename RETURN, typename PARAM1, typename PARAM2, typename PARAM3>
	class LambdaBaseHolder_Param3
	{
		typedef LambdaBase_Param3<RETURN, PARAM1, PARAM2, PARAM3> BaseType;
#ifdef SUPPORTS_LAMBDA_EXPRESSION
		typedef Lambda_Param3<RETURN, PARAM1, PARAM2, PARAM3> LambdaType;
#endif

	public:
		// ���� ������ �����Ϸ������� ����� �����ؾ�. ���� ����̹Ƿ�.
		RefCount<BaseType> m_functionObject;

#ifdef SUPPORTS_LAMBDA_EXPRESSION
		LambdaBaseHolder_Param3& operator=(const std::function<RETURN(PARAM1, PARAM2, PARAM3)>& lambda)
		{
			m_functionObject = RefCount<BaseType>(new LambdaType(lambda));
			return *this;
		}
#endif
	};

	template<typename RETURN, typename PARAM1, typename PARAM2, typename PARAM3, typename PARAM4>
	class LambdaBase_Param4
	{
	public:
		virtual RETURN Run(PARAM1 param1, PARAM2 param2, PARAM3 param3, PARAM4 param4) = 0;
		virtual ~LambdaBase_Param4() {}
	};

#ifdef SUPPORTS_LAMBDA_EXPRESSION
	template<typename RETURN, typename PARAM1, typename PARAM2, typename PARAM3, typename PARAM4>
	class Lambda_Param4 :public LambdaBase_Param4 < RETURN, PARAM1, PARAM2, PARAM3, PARAM4 >
	{
		// thread and context
		std::function<RETURN(PARAM1, PARAM2, PARAM3, PARAM4)> m_lambda;
	public:
		Lambda_Param4(const std::function<RETURN(PARAM1, PARAM2, PARAM3, PARAM4)> &lambda) { m_lambda = lambda; }
		void Run(PARAM1 param1, PARAM2 param2, PARAM3 param3, PARAM4 param4) { m_lambda(param1, param2, param3, param4); }
	};
#endif


	template<typename RETURN, typename PARAM1, typename PARAM2, typename PARAM3, typename PARAM4>
	class LambdaBaseHolder_Param4
	{
		typedef LambdaBase_Param4<RETURN, PARAM1, PARAM2, PARAM3, PARAM4> BaseType;
#ifdef SUPPORTS_LAMBDA_EXPRESSION
		typedef Lambda_Param4<RETURN, PARAM1, PARAM2, PARAM3, PARAM4> LambdaType;
#endif

	public:
		// ���� ������ �����Ϸ������� ����� �����ؾ�. ���� ����̹Ƿ�.
		RefCount<BaseType> m_functionObject;

#ifdef SUPPORTS_LAMBDA_EXPRESSION
		LambdaBaseHolder_Param4& operator=(const std::function<RETURN(PARAM1, PARAM2, PARAM3, PARAM4)>& lambda)
		{
			m_functionObject = RefCount<BaseType>(new LambdaType(lambda));
			return *this;
		}
#endif
	};

} // namespace

#ifdef _MSC_VER
#pragma pack(pop)
#endif