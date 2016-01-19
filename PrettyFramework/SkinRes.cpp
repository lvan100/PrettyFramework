#include "stdafx.h"
#include "Markup.h"
#include "SkinRes.h"

namespace PrettyFramework {

	/// CachedStyle

	shared_ptr<CachedStyle> CachedStyle::_instance;

	shared_ptr<CachedStyle>& CachedStyle::GetInstance() {
		if (_instance == nullptr) {
			_instance.reset(new CachedStyle);
		}
		return _instance;
	}

	void CachedStyle::Clear() {
		m_styles.clear();
	}

	weak_ptr<Style> CachedStyle::GetStyle(CString name) {
		auto& iter = m_styles.find(name);
		if (iter == m_styles.end()) {
			return weak_ptr<Style>();
		}
		return weak_ptr<Style>((*iter).second);
	}

	void CachedStyle::CacheStyle(CString name, Style* style) {
		m_styles.insert(make_pair(name, shared_ptr<Style>(style)));
	}

	/// CachedColor

	shared_ptr<CachedColor> CachedColor::_instance;

	shared_ptr<CachedColor>& CachedColor::GetInstance() {
		if (_instance == nullptr) {
			_instance.reset(new CachedColor);
		}
		return _instance;
	}

	void CachedColor::Clear() {
		m_colors.clear();
	}

	Gdiplus::Color CachedColor::GetColor(CString id) {
		auto& iter = m_colors.find(id);
		if (iter == m_colors.end()) {
			return Gdiplus::Color();
		}
		return (*iter).second;
	}

	void CachedColor::CacheColor(CString id, Gdiplus::Color clr) {
		m_colors.insert(make_pair(id, clr));
	}

	/// CachedImage

	shared_ptr<CachedImage> CachedImage::_instance;

	shared_ptr<CachedImage>& CachedImage::GetInstance() {
		if (_instance == nullptr) {
			_instance.reset(new CachedImage);
		}
		return _instance;
	}

	void CachedImage::Clear() {
		m_images.clear();
	}

	weak_ptr<Gdiplus::Image> CachedImage::GetImage(CString id) {
		auto& iter = m_images.find(id);
		if (iter == m_images.end()) {
			return weak_ptr<Gdiplus::Image>();
		}
		return weak_ptr<Gdiplus::Image>((*iter).second);
	}

	void CachedImage::CacheImage(CString id, Gdiplus::Image* image) {
		m_images.insert(make_pair(id, shared_ptr<Gdiplus::Image>(image)));
	}

	/// CachedFont

	shared_ptr<CachedFont> CachedFont::_instance;

	shared_ptr<CachedFont>& CachedFont::GetInstance() {
		if (_instance == nullptr) {
			_instance.reset(new CachedFont);
		}
		return _instance;
	}

	void CachedFont::Clear() {
		m_fonts.clear();
	}

	weak_ptr<Gdiplus::Font> CachedFont::GetFont(CString id) {
		auto& iter = m_fonts.find(id);
		if (iter == m_fonts.end()) {
			return weak_ptr<Gdiplus::Font>();
		}
		return weak_ptr<Gdiplus::Font>((*iter).second);
	}

	void CachedFont::CacheFont(CString id, Gdiplus::Font* font) {
		m_fonts.insert(make_pair(id, shared_ptr<Gdiplus::Font>(font)));
	}

	/// CachedShape

	shared_ptr<CachedShape> CachedShape::_instance;

	shared_ptr<CachedShape>& CachedShape::GetInstance() {
		if (_instance == nullptr) {
			_instance.reset(new CachedShape);
		}
		return _instance;
	}

	void CachedShape::Clear() {
		m_shapes.clear();
	}

	weak_ptr<Shape> CachedShape::GetShape(CString id) {
		auto& iter = m_shapes.find(id);
		if (iter == m_shapes.end()) {
			return weak_ptr<Shape>();
		}
		return weak_ptr<Shape>((*iter).second);
	}

	void CachedShape::CacheShape(CString id, Shape* shape) {
		m_shapes.insert(make_pair(id, shared_ptr<Shape>(shape)));
	}

	/// SkinRes

	shared_ptr<SkinRes> SkinRes::_instance;

	shared_ptr<SkinRes>& SkinRes::GetInstance() {
		if (_instance == nullptr) {
			_instance.reset(new SkinRes);
		}
		return _instance;
	}

	BOOL SkinRes::ReloadColorXml(CString strXml) {

		CMarkup xml;
		if (!xml.Load(strXml)) {
			return FALSE;
		}

		auto& cachedColor = CachedColor::GetInstance();
		cachedColor->Clear();


	}

	BOOL SkinRes::ReloadImageXml(CString strXml) {

		CMarkup xml;
		if (!xml.Load(strXml)) {
			return FALSE;
		}

		auto& cachedImage = CachedImage::GetInstance();
		cachedImage->Clear();

		while (xml.FindChildElem(L"Image")) {
			CString id = xml.GetChildAttrib(L"id");
			CString file = xml.GetChildAttrib(L"file");

			auto* image = Gdiplus::Image::FromFile(file);
			if (image == nullptr) {
				continue;
			}

			cachedImage->CacheImage(id, image);
		}

		return TRUE;
	}

	BOOL SkinRes::ReloadFontXml(CString strXml) {

		CMarkup xml;
		if (!xml.Load(strXml)) {
			return FALSE;
		}

		auto& cachedFont = CachedFont::GetInstance();
		cachedFont->Clear();

	}

	BOOL SkinRes::ReloadShapeXml(CString strXml) {

		CMarkup xml;
		if (!xml.Load(strXml)) {
			return FALSE;
		}

		auto& cachedShape = CachedShape::GetInstance();
		cachedShape->Clear();

	}

	BOOL SkinRes::ReleadStyleXml(CString strXml) {

		CMarkup xml;
		if (!xml.Load(strXml)) {
			return FALSE;
		}

		auto& cachedStyle = CachedStyle::GetInstance();
		cachedStyle->Clear();

	}

}