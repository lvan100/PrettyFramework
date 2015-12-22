#include "stdafx.h"
#include "ImageRes.h"

namespace PrettyFramework {

	/**
	 * 全局的图像资源管理器
	 */
	ImageResource theImageRes;

	ImageResource::ImageResource()
	{
	}

	ImageResource::~ImageResource()
	{
	}

	HICON ImageResource::GetImage(CString id)
	{
		auto& iter = m_images.find(id);
		if (iter != m_images.end()) {
			return (*iter).second;
		}
		
		CString strPath = GetModuleDir() + _T("Resource\\Image\\");
		HICON icon = (HICON)LoadImage(nullptr, strPath + id + _T(".ico")
			, IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
		auto& res = m_images.insert(make_pair(id, icon));
		if (res.second) {
			return icon;
		}

		return nullptr;
	}
	
	HICON ImageResource::GetImageList(CString id)
	{
		// 
		// 根据图像高度对图像进行切割
		// 

		return GetImage(id);
	}

}