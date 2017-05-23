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

#include "Marshaler.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif

	/** 
	\~korean
	DB cache server���� ������ ������ Table �� ������ ����� ����� ����

	\~english
	Sort of event that actually writting to user defined table in DB cache server

	\~chinese
	�DB cache server߾��?��?��Table??�??��������??��

	\~japanese
	DB cache server�ǫ�?��?����������Table��?����?�����������׾
	\~
	*/
	enum DbmsWritePropNodePendType
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
		DWPNPT_None,

		/**
		\~korean
		\ref PropNode  �߰� 

		\~english
		Add \ref PropNode 

		\~chinese
		��ʥ\ref PropNode%��

		\~japanese
		\ref PropNode  ��ʥ
		\~
		*/
		DWPNPT_AddPropNode,

		/** 
		\~korean
		\ref PropNode  ���� 

		\~english
		Delete \ref PropNode 
		
		\~chinese
		?�\ref PropNode%��

		\~japanese
		\ref PropNode  ���
		\~
		*/
		DWPNPT_RemovePropNode,

		/**
		\~korean
		Request �� ���� \ref PropNode ������Ʈ 
		
		\~english TODO:Translate needed.
		Update \ref PropNode.

		\~chinese TODO:Translate needed.
		�?\ref PropNode%��

		\~japanese
		Request ��?���� \ref PropNode ���ë׫�?��
		\~
		*/
		DWPNPT_RequestUpdatePropNode,

		/**
		\~
		\ref PropNode  SetValueIf
		*/
		DWPNPT_SetValueIf,

		/**
		\~
		\ref PropNode  ModifyValueIf
		*/
		DWPNPT_ModifyValue,

		/** 
		\~korean 
		Request �� ���� \ref PropNode ������Ʈ 
		
		\~english TODO:Translate needed.
		Update \ref PropNod.
		
		\~chinese TODO:Translate needed.
		�?\ref PropNode%��

		\~japanese
		Request �� ���� \ref PropNode ������Ʈ 
		\~
		*/
		DWPNPT_RequestUpdatePropNodeList,

		/** 
		\~korean
		\ref PropNode   �̵� 

		\~english 
		Update \ref PropNod 
		
		\~chinese
		\ref PropNode%�?��
		\~japanese
		\ref PropNode   ���
		\~
		*/
		DWPNPT_MovePropNode,

		/**
		\~korean
		\~english
		\~chinese
		\~japanese
		\~
		Unilateral Update \ref PropNod.
		*/
		DWPNPT_UnilateralUpdatePropNode,

		/**
		\~korean
		\~english
		\~chinese
		\~japanese
		\~
		Unilateral Update \ref PropNod.
		*/
		DWPNPT_UnilateralUpdatePropNodeList,

		/**
		\~korean
		\ref PropNode ������Ʈ

		\~english
		Update \ref PropNode

		\~chinese
		�?\ref PropNode%��

		\~japanese
		\ref PropNode ���ë׫�?��
		\~
		*/
		DWPNPT_UpdatePropNode,
	};

	PROUDSRV_API const PNTCHAR* TypeToString(DbmsWritePropNodePendType t);

	/**  @}  */

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

PROUDNET_SERIALIZE_ENUM(DbmsWritePropNodePendType);

#ifdef _MSC_VER
#pragma pack(pop)
#endif