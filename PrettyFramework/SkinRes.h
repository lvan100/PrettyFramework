#pragma once

#include <map>
#include <memory>
using namespace std;

#include "BaseShape.h"

namespace PrettyFramework {

	// 
	// Skin（换肤）几乎是现代软件必不可少的一个重要功能，能够从框
	// 架级别对 Skin（换肤）进行支持是一件非常酷的事情。一般来说，
	// Skin（换肤）主要是指控件的 Style（样式）和 Image（图像）发
	// 生变化，而 Layout（布局）不会发生变化。这是因为无论从设计
	// 还是实现上讲，界面的核心元素——布局（Layout）——都不应该
	// 发生变化，否则有可能会给正在使用软件的用户造成不必要的困扰。
	// 

	// 
	// 按照这种思路做下去，和W3C的界面模型几乎一样。Skin（换肤）大
	// 致等于 CSS3 ，Layout（布局）大致等于 HTML 。脚本暂时不需要。
	// 

	/**
	 * 样式
	 */
	class Style {

	public:
		/**
		 * 添加样式元素
		 */
		void AddItem(CString id, CString val) {
			m_items.insert(make_pair(id, val));
		}

		/**
		 * 设置样式名称
		 */
		void SetName(CString name) {
			m_name = name;
		}

	public:
		/**
		 * 样式的名称
		 */
		CString m_name;

		/**
		 * 样式元素列表
		 */
		map<CString, CString> m_items;
	};

	/**
	 * 缓存的样式资源
	 */
	class CachedStyle {

	protected:
		CachedStyle() {}

	public:
		/**
		 * 获取单例对象的句柄
		 */
		static shared_ptr<CachedStyle>& GetInstance();

	protected:
		/**
		 * 单例对象的句柄
		 */
		static shared_ptr<CachedStyle> _instance;

	public:
		/**
		 * 释放所有缓存的样式
		 */
		void Clear();

		/**
		 * 根据名称获取缓存样式
		 */
		weak_ptr<Style> GetStyle(CString name);

		/**
		 * 添加缓存样式和它的名称
		 */
		void CacheStyle(CString name, Style* style);

	protected:
		/**
		 * 样式资源
		 */
		map<CString, shared_ptr<Style>> m_styles;
	};

	/**
	 * 缓存的颜色
	 */
	class CachedColor {

	protected:
		CachedColor() {}

	public:
		/**
		 * 获取单例对象的句柄
		 */
		static shared_ptr<CachedColor>& GetInstance();

	protected:
		/**
		 * 单例对象的句柄
		 */
		static shared_ptr<CachedColor> _instance;

	public:
		/**
		 * 释放所有缓存的颜色资源
		 */
		void Clear();

		/**
		 * 根据名称获取缓存的颜色
		 */
		Gdiplus::Color GetColor(CString name);

		/**
		 * 添加缓存颜色和它的名称
		 */
		void CacheColor(CString id, Gdiplus::Color clr);

	protected:
		/**
		 * 颜色资源
		 */
		map<CString, Gdiplus::Color > m_colors;
	};

	/**
	 * 缓存的图像资源
	 */
	class CachedImage {

	protected:
		CachedImage() {}

	public:
		/**
		 * 获取单例对象的句柄
		 */
		static shared_ptr<CachedImage>& GetInstance();

	protected:
		/**
		 * 单例对象的句柄
		 */
		static shared_ptr<CachedImage> _instance;

	public:
		/**
		 * 释放所有缓存的图像资源
		 */
		void Clear();

		/**
		 * 根据ID获取缓存的图像
		 */
		weak_ptr<Gdiplus::Image> GetImage(CString id);

		/**
		 * 添加缓存图像和它的ID
		 */
		void CacheImage(CString id, Gdiplus::Image* image);

	protected:
		/**
		 * 图像资源
		 */
		map<CString, shared_ptr<Gdiplus::Image>> m_images;
	};

	/**
	 * 缓存的字体
	 */
	class CachedFont {

	protected:
		CachedFont() {}

	public:
		/**
		 * 获取单例对象的句柄
		 */
		static shared_ptr<CachedFont>& GetInstance();

	protected:
		/**
		 * 单例对象的句柄
		 */
		static shared_ptr<CachedFont> _instance;

	public:
		/**
		 * 释放所有缓存的字体资源
		 */
		void Clear();

		/**
		 * 根据ID获取缓存的字体
		 */
		weak_ptr<Gdiplus::Font> GetFont(CString id);

		/**
		 * 添加缓存字体和它的ID
		 */
		void CacheFont(CString id, Gdiplus::Font* font);

	protected:
		/**
		 * 字体资源
		 */
		map<CString, shared_ptr<Gdiplus::Font> > m_fonts;
	};

	/**
	 * 缓存的形状
	 */
	class CachedShape {

	protected:
		CachedShape() {}

	public:
		/**
		 * 获取单例对象的句柄
		 */
		static shared_ptr<CachedShape>& GetInstance();

	protected:
		/**
		 * 单例对象的句柄
		 */
		static shared_ptr<CachedShape> _instance;

	public:
		/**
		 * 释放所有缓存的形状资源
		 */
		void Clear();

		/**
		 * 根据ID获取缓存的形状
		 */
		weak_ptr<Shape> GetShape(CString id);

		/**
		 * 添加缓存形状和它的ID
		 */
		void CacheShape(CString id, Shape* shape);

	protected:
		/**
		 * 形状资源
		 */
		map<CString, shared_ptr<Shape> > m_shapes;
	};

	// 
	// TODO 这里留下一个疑问，按照目前的想法，样式文件和图像文件都必须
	// 放在各自唯一的单独文件中，虽然允许 Style（样式）之间可以继承，
	// 但是不能在多个文件中索引和查找。如果有第三方模块就更难了。
	// 

	/**
	 * 皮肤资源管理器
	 */
	class SkinRes {

	protected:
		SkinRes() {}

	public:
		/**
		* 获取单例对象的句柄
		*/
		static shared_ptr<SkinRes>& GetInstance();

	protected:
		/**
		* 单例对象的句柄
		*/
		static shared_ptr<SkinRes> _instance;

	public:
		// 
		// 所有资源必须按照下面的顺序加载，
		// 否则可能出现找不到资源的情况。
		// 

		/**
		 * 0.重新加载 Color（颜色）资源
		 */
		BOOL ReloadColorXml(CString strXml);

		/**
		 * 1.重新加载 Image（图像）资源
		 */
		BOOL ReloadImageXml(CString strXml);

		/**
		 * 2.重新加载 Font（字体）资源
		 */
		BOOL ReloadFontXml(CString strXml);

		/**
		 * 3.重新加载 Shape（形状）资源
		 */
		BOOL ReloadShapeXml(CString strXml);

		/**
		 * 4.重新加载 Style（样式）资源
		 */
		BOOL ReleadStyleXml(CString strXml);
	};

}