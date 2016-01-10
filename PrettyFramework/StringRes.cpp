#include "stdafx.h"
#include "Markup.h"

#include <map>
using namespace std;

#include "StringRes.h"

#include "SelfModule.h"
#include "TypeSelect.h"

namespace PrettyFramework {
	
	/**
	 * ¿Õ×Ö·û´®
	 */
	static CString emptyString;

	/**
	 * ×Ö·û´®×ÊÔ´
	 */
	static map<CString, CString> m_strings;

	/**
	 * ¼ÓÔØ×Ö·û´®×ÊÔ´
	 */
	static void LoadStringRes(CString file) {

		CMarkup xml;
		if (xml.Load(file)) {

			while (xml.FindChildElem(L"String")) {
				CString id = xml.GetChildAttrib(L"id");
				CString strContent = xml.GetChildData();

				auto& pair = make_pair(id, strContent);
				auto res = m_strings.insert(pair);
				if (!res.second) {
					res.first->second.SetString(strContent);
				}
			}
		}
	}

	/**
	 * ¶¨Òåµ±Ç°Ä£¿é
	 */
	static DefModule _Module("StringResource"
		, ""
		, []$(Constructor)() {
		}, []$(Initializer)() {
			RefreshStrings();
		}, []$(Uninitializer)() {
		}, []$(Destructor)() {
		});
	
	/**
	 * ×Ö·û´®ÓïÑÔ
	 */
	static Language language = Language::ChineseSimplified;

	/**
	 * ×Ö·û´®ÓïÑÔÄ¿Â¼ÁÐ±í
	 */
	static CString langDir[] = { _T("zh_CN"), _T("zh_TW") };

	void RefreshStrings() {

		CString strDir = GetResourceDir() + _T("String\\");
		strDir += langDir[language] + _T("\\");

		CString strPath = strDir + _T("String.xml");
		LoadStringRes(strPath);
	}

	void SetLanguage(Language lan) {
		language = lan;
		RefreshStrings();
	}

	CString& GetString(CString id) {
		auto& iter = m_strings.find(id);
		if (iter != m_strings.end()) {
			return (*iter).second;
		}
		return emptyString;
	}

}