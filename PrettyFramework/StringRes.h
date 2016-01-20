#pragma once

#include <map>
#include <memory>
using namespace std;

namespace PrettyFramework {

	// 
	// 在程序运行过程中切换语言在我看来不是一个好的主意，
	// 但是经常有人会拿这个特性来去炫耀。那就实现它好了。
	// 

	/**
	 * 语言类型
	 */
	enum Language {
		ChineseSimplified,
		ChineseTraditional,
	};

	/**
	 * 字符串资源
	 */
	class StringRes {

	protected:
		StringRes()
			: _language(Language::ChineseSimplified)
		{}

	public:
		/**
		 * 获取单例对象的句柄
		 */
		static shared_ptr<StringRes>& GetInstance();

	protected:
		/**
		 * 单例对象的句柄
		 */
		static shared_ptr<StringRes> _instance;

	public:
		/**
		 * 设置语言类型
		 */
		void SetLanguage(Language lang);

		/**
		 * 根据字符串ID获取字符串
		 */
		CString& GetString(CString id);

	protected:
		/**
		 * 刷新所有字符串
		 */
		BOOL RefreshStrings();

	protected:
		/**
		 * 语言类型
		 */
		Language _language;

		/**
		 * 字符串资源
		 */
		map<CString, CString> m_strings;
	};

	/**
	 * 语言类型简写
	 */
	extern CString langDir[];

}