#pragma once

#include <memory>
using namespace std;

namespace PrettyFramework {

	// 
	// 只接受 PNG 格式的图像
	// 

	/**
	 * 释放所有图像资源
	 */
	void ClearImages();

	/**
	 * 根据图像ID获取图像
	 */
	weak_ptr<Gdiplus::Image>& GetImage(CString id);

	/**
	 * 根据图像ID获取列表式图像
	 */
	weak_ptr<Gdiplus::Image>& GetImageList(CString id);

}