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
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif

    
#if defined(_WIN32)    
	/** \addtogroup minidump_group
	*  @{
	*/

	/** 
	\~korean
	CDumpClient �� �䱸�ϴ� delegate �������̽�. CDumpClient �� ������ �� ���ڷ� �ʿ��ϴ�.

	\~english
	Delegate interface that is requested by CDumpClient. It is needed as as index when creating CDumpClient.

	\~chinese
	CDumpClient �ϴ��delegate?�ǡ����� CDumpClient%��?�����������

	\~japanese
	CDumpClient���ϴ����delegate����?�ի�?����CDumpClient�����������������Ȫ�����驪Ǫ���
	\~
	*/
	class IDumpClientDelegate
	{
	public:
		virtual ~IDumpClientDelegate() {}

		/** 
		\~korean
		CDumpClient �� ���� ������ ������ ������ ���� ���� �ð����� ȣ��ȴ�. ������ ����
		�����⸦ ����� ��� �� �Լ��� true�� �����ϸ� �ȴ�.

		\~english
		Called periodically while CDumpClient sends dump file to server. This function must return true in order to let user cancel the sending process.

		\~chinese
		CDumpClien ��??����?������?����Ѣ?��������??Դ?����У������?���?����?�������?����true?ʦ��

		\~japanese
		CDumpClient������׫ի������?��?��������������઴�Ȫ������󪵪�ު�����?��?�˪�ê�����򫭫�󫻫몹�����ꡢ����??��true��꫿?�󪹪���ު��Ǫ���
		\~
		*/
		virtual bool MustStopNow() = 0;

		/** 
		\~korean
		�۽� ó���� ���ܰ� �߻��� ��� �� �޼��尡 �ݹ�ȴ�.
		\param e �������� Exception::what() �� ���Ͽ� ������ ���õ� String ������ �� �ֽ��ϴ�.

		\~english 
		This method is called back when an exception occurs during processing transmission. 
		\param e      You can get the string related to the problem through the exception information Exception::what().


		\~chinese
		����?��?����?��������?����?�۰����
		\param e ��?�������� Exception::what()%ʦ�?��??��?��String��

		\~japanese
		����?��������⪬?�檹�����ꡢ���Ϋ᫽�ëɪ���?��Ыë�����ު���
		\param e �������� Exception::what() ���ת�����?֧���쪿String���������ު���
		\~
		*/
		virtual void OnException(const Exception &e) = 0;
		
		/** 
		\~korean
		�۽��� �Ϸ�Ǹ� �̰��� ȣ��ȴ�. �۽� ��ȭ ���ڸ� �̶� ������ �ȴ�.

		\~english
		This will be called once sending is completed. Sending chat box can be closed at this point. 

		\~chinese
		?����?��????����У��??��???��????ʦ��

		\~japanese
		���᪬���������骳�쪬�����󪵪�ު���������������ܫë����򪳪������ͪ�����ު��Ǫ���
		\~
		*/
		virtual void OnComplete() = 0;
	};

	/** 
	\~korean
	���� Ŭ���̾�Ʈ
	- CDumpServer ���� ������ �� �� ������ DMP ������ ������ ������ �Ѵ�.
	- HTTP ��Ŀ� ���� ȿ�����̸� ��κ��� �� ȣ���� ���񽺰� ���� ��� �㰡�� ������ ������ ���� ��ü ���� ������
	�Ұ����ϴٴ� ���� �����ϸ� �̷��� ��ü ���������� �� �������̴�.

	�Ϲ��� �뵵
	- ������ Create()�� �Ѵ�.
	- �� ��ü�� ������ �� Start()�� �۽��� �Ѵ�.
	- �� ���� �ð�(�뷫 1�ʿ� 10ȸ �̻�) FrameMove�� ȣ���Ѵ�.
	- �۽��� �ߵ� ��Ȳ�� GetState(),GetSendProgress(),GetSendTotal()�� ���� �� �ִ�. �̰��� ��ȭ ���ڿ� ǥ���ϸ� �ȴ�.
	- OnException, OnComplete�� �� ������ ��ٸ���.

	\~english
	Dump client
	- Manages sending DMP files to server after connected to CDumpServer
	- Inefficeint compared to HTTP and this kind of custom protocol is more realistic since most of web hosting services turn off file record permission pushing publishers to setup own servers.

	General usage
	- Use Create() to create.
	- After creating the object the use Start() to send.
	- Calls FrameMove periodically (approx. 10 or more times per second)
	- The sending status during sending process can be acquired by using GetState(), GetSendProgress() and GetSendTotal(). And those can be displayed in chat box.
	- ait until OnException and OnComplete arrive.

	\~chinese
	??��ʫ
	- ? CDumpServer%��?�������������?��?��DMP���������ġ�
	- ��HTTP۰�������㣬��?��ݻ��web hosting��???����???ʦ����?������?��?������ʦ����??�����protocol����??�ܡ�

	��������Բ
	- �Create()������
	- �����?�������Start()?�ꡣ
	- ������??����?����10���߾����УFrameMove��
	- ����?����??�GetState(),GetSendProgress(),GetSendTotal()?����???���????ʦ��
	- ����OnException, OnComplete��?��

	\~japanese
	����׫��髤�����
	- CDumpServer�تΪ�����������ê�������?��?��DMP�ի�����������ܪ򪷪ު���
	- HTTP۰�Ҫ����?���ܪǡ��۪Ȫ�ɪΫ����֫۫��ƫ��󫰫�?�ӫ����ի�������?��ʦ�򫪫ժ����Ǫ����ᡢ�����ê��?��?��?ϰ�骬������ʪ��Ȫ������Ȫ����ߪ��顢���Ϊ誦���?�׫�ȫ��몬��ê���?�ܪǪ���

	�����ܪ���Բ
	- ������Create()�Ȫ��롣
	- ���Ϋ��֫������Ȫ�������������Start()�����᪷�ު���
	- ������઴�Ȫ�(�1����10���߾)FrameMove�������󪷪ު���
	- ���������Բ?�Ϫϡ�GetState(),GetSendProgress(),GetSendTotal()��������ު����������������ܫë��������ƪ�����ު��Ǫ���
	- OnException, OnComplete��?��ު�����ު���
	\~
	*/
	class CDumpClient
	{
	public:
		enum State { Connecting, Sending, Closing, Stopped};

		virtual ~CDumpClient() {};

		/** 
		\~korean
		���� ������ ���� ������ ������ �����Ѵ�.
		\param serverAddr ���� �ּ�
		\param serverPort ���� ��Ʈ
		\param filePath ������ ���

		\~english TODO:translate needed.
		Start sending dump file to dump server.
		\param serverAddr
		\param serverPort
		\param filePath

		\~chinese
		��??��?��?�?��??���졣
		\param serverAddr ��?���򣡣
		\param serverPort ��?��ӮϢ��
		\param filePath ��������?��

		\~japanese
		����׫�?��?�ǫ���׫ի���������㷪�ު���
		\param serverAddr ��?��?���ɫ쫹
		\param serverPort ��?��?��?��
		\param filePath �ի������?��
		\~
		*/
		virtual void Start(String serverAddr, uint16_t serverPort, String filePath) = 0;

		/** 
		\~korean
		���� �ð����� �� �޼��带 ȣ������� �۽� ������ ����� �� �ִ�.

		\~english
		Sending process is sustained by calling this method periodically.

		\~chinese
		������??��У�۰����?��?�����?����

		\~japanese
		������઴�Ȫ˪��Ϋ᫽�ëɪ������󪷪ƪ�������Φ�窱��������몳�Ȫ��Ǫ��ު���
		\~
		*/
		virtual void FrameMove() = 0;

		/** 
		\~korean
		���� ���� ���� �۽� ����� ��´�.

		\~english
		Gets current dump file sending status

		\~chinese
		?��?���??����?��?����

		\~japanese
		�����׫ի����������̿������ު���
		\~
		*/
		virtual State GetState() = 0;

		/** 
		\~korean
		���� ���� ���� �۽��� �� ����Ʈ�� �������� ��´�.

		\~english
		Gets how many bytes of dump file has been completed

		\~chinese
		?��?�??����?��?������?��

		\~japanese
		�����׫ի���������᪬���Ы����������ƪ��몫����ު���
		\~
		*/
		virtual int GetSendProgress() = 0;

		/** 
		\~korean
		������ �ϴ� �� �۽� �����͸� ��´�.

		\~english
		Gets total sending data to be sent

		\~chinese
		?���?����??��?�ߡ�

		\~japanese
		���٪�?�����?������ު���
		\~
		*/
		virtual int GetSendTotal() = 0;

		/** 
		\~korean
		CDumpClient ��ü�� �����Ѵ�.
		\param dg IDumpClientDelegate �� ������

		\~english TODO:translate needed.
		Generate CDumpClient object
		\param dg Pointer of IDumpClientDelegate

		\~chinese
		CDumpClient ����?��
		\param dg IDumpClientDelegate��pointer��

		\~japanese
		CDumpClient ���֫������Ȫ��������ު���
		\param dg IDumpClientDelegate �Ϋݫ���?
		\~
		*/
		PROUD_API static CDumpClient* Create(IDumpClientDelegate* dg);

	};
#endif 

	/**  @} */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
