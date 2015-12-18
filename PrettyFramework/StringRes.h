#pragma once

#include <map>
using namespace std;

namespace PrettyFramework {

	/**
	 * 字符串资源
	 */
	class StringResource
	{
	public:
		StringResource();
		virtual ~StringResource();

		/**
		 * 根据字符串ID获取字符串
		 */
		CString GetString(CString id);

		/**
		 * 初始化函数
		 */
		void MustInitFirst(CString file);

	protected:
		/**
		 * 字符串资源
		 */
		map<CString, CString> m_strings;
	};

	/**
	 * 全局的字符串资源管理器
	 */
	extern StringResource theStringRes;

}