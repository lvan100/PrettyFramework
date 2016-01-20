#pragma once

#include <map>
#include <memory>
using namespace std;

namespace PrettyFramework {

	// 
	// �ڳ������й������л��������ҿ�������һ���õ����⣬
	// ���Ǿ������˻������������ȥ��ҫ���Ǿ�ʵ�������ˡ�
	// 

	/**
	 * ��������
	 */
	enum Language {
		ChineseSimplified,
		ChineseTraditional,
	};

	/**
	 * �ַ�����Դ
	 */
	class StringRes {

	protected:
		StringRes()
			: _language(Language::ChineseSimplified)
		{}

	public:
		/**
		 * ��ȡ��������ľ��
		 */
		static shared_ptr<StringRes>& GetInstance();

	protected:
		/**
		 * ��������ľ��
		 */
		static shared_ptr<StringRes> _instance;

	public:
		/**
		 * ������������
		 */
		void SetLanguage(Language lang);

		/**
		 * �����ַ���ID��ȡ�ַ���
		 */
		CString& GetString(CString id);

	protected:
		/**
		 * ˢ�������ַ���
		 */
		BOOL RefreshStrings();

	protected:
		/**
		 * ��������
		 */
		Language _language;

		/**
		 * �ַ�����Դ
		 */
		map<CString, CString> m_strings;
	};

	/**
	 * �������ͼ�д
	 */
	extern CString langDir[];

}