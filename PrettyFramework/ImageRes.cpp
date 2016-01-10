#include "stdafx.h"
#include "ImageRes.h"

#include <map>
using namespace std;

namespace PrettyFramework {

	/**
	 * 图像资源
	 */
	static map<CString, shared_ptr<Gdiplus::Image>> m_images;

	weak_ptr<Gdiplus::Image>& GetImage(CString id) {

		auto& iter = m_images.find(id);
		if (iter != m_images.end()) {
			return weak_ptr<Gdiplus::Image>((*iter).second);
		}
		
		CString strImageDir = GetResourceDir() + _T("Image\\");
		CString strPath = strImageDir + id + _T(".png");

		shared_ptr<Gdiplus::Image> image(new Gdiplus::Image(strPath));
		auto& res = m_images.insert(make_pair(id, image));

		return weak_ptr<Gdiplus::Image>(res.second ? image : nullptr);
	}

	/**
	 * 列表式图像资源
	 */
	static map<CString, shared_ptr<Gdiplus::Image>> m_list_type_images;

	weak_ptr<Gdiplus::Image>& GetImageList(CString id) {

		auto& iter = m_list_type_images.find(id);
		if (iter != m_list_type_images.end()) {
			return weak_ptr<Gdiplus::Image>((*iter).second);
		}

		CString strImageDir = GetResourceDir() + _T("Image\\");
		CString strPath = strImageDir + id + _T(".png");

		shared_ptr<Gdiplus::Image> image(new Gdiplus::Image(strPath));
		auto& res = m_list_type_images.insert(make_pair(id, image));

		return weak_ptr<Gdiplus::Image>(res.second ? image : nullptr);
	}
	
	void ClearImages() {
		m_images.clear();
		m_list_type_images.clear();
	}

}