#pragma once

namespace PrettyFramework {
	
	/**
	 * ˢ�������ַ���
	 */
	void RefreshStrings();

	/**
	 * �ַ�������
	 */
	enum Language {
		ChineseSimplified,
		ChineseTraditional,
	};

	/**
	 * �����ַ�������
	 */
	void SetLanguage(Language lan);

	/**
	 * �����ַ���ID��ȡ�ַ���
	 */
	CString& GetString(CString id);
	
}