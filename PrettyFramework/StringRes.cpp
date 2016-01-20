#include "stdafx.h"
#include "Markup.h"
#include "StringRes.h"
#include "SelfModule.h"
#include "TypeSelect.h"

namespace PrettyFramework {

	/**
	 * 语言类型简写
	 */
	CString langDir[] = { _T("zh_CN"), _T("zh_TW") };

	shared_ptr<StringRes> StringRes::_instance;

	shared_ptr<StringRes>& StringRes::GetInstance() {
		if (_instance == nullptr) {
			_instance.reset(new StringRes);
		}
		return _instance;
	}

	/**
	 * 定义当前模块
	 */
	static DefModule _Module("StringResource"
		, ""
		, []$(Constructor)() {
		}, []$(Initializer)() {
			auto& stringRes = StringRes::GetInstance();
			stringRes->SetLanguage(Language::ChineseSimplified);
		}, []$(Uninitializer)() {
		}, []$(Destructor)() {
		});

	BOOL StringRes::RefreshStrings() {

		CString strDir = GetResourceDir() + _T("String\\");
		strDir += langDir[_language] + _T("\\");

		CString strPath = strDir + _T("String.xml");

		CMarkup xml;
		if (!xml.Load(strPath)) {
			return FALSE;
		}

		while (xml.FindChildElem(L"String")) {
			CString id = xml.GetChildAttrib(L"id");
			CString strContent = xml.GetChildData();

			auto& pair = make_pair(id, strContent);
			auto res = m_strings.insert(pair);

			if (!res.second) {
				res.first->second.SetString(strContent);
			}
		}

		return TRUE;
	}

	void StringRes::SetLanguage(Language lang) {
		_language = lang;
		RefreshStrings();
	}

	CString& StringRes::GetString(CString id) {

		auto& iter = m_strings.find(id);
		if (iter != m_strings.end()) {
			return (*iter).second;
		}

		static CString emptyString;
		return emptyString;
	}

}