#pragma once

#include <map>
using namespace std;

namespace PrettyFramework {

	/**
	 * 图像资源
	 */
	class ImageResource
	{
	public:
		ImageResource();
		~ImageResource();

		/**
		 * 根据图像ID获取图像
		 */
		HICON GetImage(CString id);

	protected:
		/**
		 * 图像资源
		 */
		map<CString, HICON> m_images;
	};

	/**
	 * 全局的图像资源管理器
	 */
	extern ImageResource theImageRes;

}