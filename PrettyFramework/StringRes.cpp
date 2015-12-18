#include "stdafx.h"

#include "Markup.h"

#include "StringRes.h"

#include "SelfModule.h"
#include "TypeSelect.h"

namespace PrettyFramework {

	/**
	 * 全局的字符串资源管理器
	 */
	StringResource theStringRes;

	/**
	 * 定义当前模块
	 */
	static DefModule _Module("StringResource"
		, ""
		, []$(Constructor)() {
		}, []$(Initializer)() {
			CString strPath = GetModuleDir() + _T("Resource\\String\\");
			theStringRes.MustInitFirst(strPath + _T("String.xml"));
		}, []$(Uninitializer)() {
		}, []$(Destructor)() {
		});
	
	StringResource::StringResource()
	{
	}
	
	StringResource::~StringResource()
	{
	}

	void StringResource::MustInitFirst(CString file)
	{
		CMarkup xml;
		if (xml.Load(file)) {
			while (xml.FindChildElem(L"String")) {
				CString id = xml.GetChildAttrib(L"id");
				CString strContent = xml.GetChildData();
				m_strings.insert(make_pair(id, strContent));
			}
		}
	}

	CString StringResource::GetString(CString id)
	{
		auto& iter = m_strings.find(id);
		if (iter != m_strings.end()) {
			return (*iter).second;
		}
		return _T("");
	}

}