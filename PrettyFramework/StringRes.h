#pragma once

#include <map>
using namespace std;

namespace PrettyFramework {

	/**
	 * �ַ�����Դ
	 */
	class StringResource
	{
	public:
		StringResource();
		virtual ~StringResource();

		/**
		 * �����ַ���ID��ȡ�ַ���
		 */
		CString GetString(CString id);

		/**
		 * ��ʼ������
		 */
		void MustInitFirst(CString file);

	protected:
		/**
		 * �ַ�����Դ
		 */
		map<CString, CString> m_strings;
	};

	/**
	 * ȫ�ֵ��ַ�����Դ������
	 */
	extern StringResource theStringRes;

}