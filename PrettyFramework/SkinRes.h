#pragma once

#include <map>
#include <memory>
using namespace std;

#include "BaseShape.h"

namespace PrettyFramework {

	// 
	// Skin���������������ִ�����ز����ٵ�һ����Ҫ���ܣ��ܹ��ӿ�
	// �ܼ���� Skin������������֧����һ���ǳ�������顣һ����˵��
	// Skin����������Ҫ��ָ�ؼ��� Style����ʽ���� Image��ͼ�񣩷�
	// ���仯���� Layout�����֣����ᷢ���仯��������Ϊ���۴����
	// ����ʵ���Ͻ�������ĺ���Ԫ�ء������֣�Layout����������Ӧ��
	// �����仯�������п��ܻ������ʹ��������û���ɲ���Ҫ�����š�
	// 

	// 
	// ��������˼·����ȥ����W3C�Ľ���ģ�ͼ���һ����Skin����������
	// �µ��� CSS3 ��Layout�����֣����µ��� HTML ���ű���ʱ����Ҫ��
	// 

	/**
	 * ��ʽ
	 */
	class Style {

	public:
		/**
		 * �����ʽԪ��
		 */
		void AddItem(CString id, CString val) {
			m_items.insert(make_pair(id, val));
		}

		/**
		 * ������ʽ����
		 */
		void SetName(CString name) {
			m_name = name;
		}

	public:
		/**
		 * ��ʽ������
		 */
		CString m_name;

		/**
		 * ��ʽԪ���б�
		 */
		map<CString, CString> m_items;
	};

	/**
	 * �������ʽ��Դ
	 */
	class CachedStyle {

	protected:
		CachedStyle() {}

	public:
		/**
		 * ��ȡ��������ľ��
		 */
		static shared_ptr<CachedStyle>& GetInstance();

	protected:
		/**
		 * ��������ľ��
		 */
		static shared_ptr<CachedStyle> _instance;

	public:
		/**
		 * �ͷ����л������ʽ
		 */
		void Clear();

		/**
		 * �������ƻ�ȡ������ʽ
		 */
		weak_ptr<Style> GetStyle(CString name);

		/**
		 * ��ӻ�����ʽ����������
		 */
		void CacheStyle(CString name, Style* style);

	protected:
		/**
		 * ��ʽ��Դ
		 */
		map<CString, shared_ptr<Style>> m_styles;
	};

	/**
	 * �������ɫ
	 */
	class CachedColor {

	protected:
		CachedColor() {}

	public:
		/**
		 * ��ȡ��������ľ��
		 */
		static shared_ptr<CachedColor>& GetInstance();

	protected:
		/**
		 * ��������ľ��
		 */
		static shared_ptr<CachedColor> _instance;

	public:
		/**
		 * �ͷ����л������ɫ��Դ
		 */
		void Clear();

		/**
		 * �������ƻ�ȡ�������ɫ
		 */
		Gdiplus::Color GetColor(CString name);

		/**
		 * ��ӻ�����ɫ����������
		 */
		void CacheColor(CString id, Gdiplus::Color clr);

	protected:
		/**
		 * ��ɫ��Դ
		 */
		map<CString, Gdiplus::Color > m_colors;
	};

	/**
	 * �����ͼ����Դ
	 */
	class CachedImage {

	protected:
		CachedImage() {}

	public:
		/**
		 * ��ȡ��������ľ��
		 */
		static shared_ptr<CachedImage>& GetInstance();

	protected:
		/**
		 * ��������ľ��
		 */
		static shared_ptr<CachedImage> _instance;

	public:
		/**
		 * �ͷ����л����ͼ����Դ
		 */
		void Clear();

		/**
		 * ����ID��ȡ�����ͼ��
		 */
		weak_ptr<Gdiplus::Image> GetImage(CString id);

		/**
		 * ��ӻ���ͼ�������ID
		 */
		void CacheImage(CString id, Gdiplus::Image* image);

	protected:
		/**
		 * ͼ����Դ
		 */
		map<CString, shared_ptr<Gdiplus::Image>> m_images;
	};

	/**
	 * ���������
	 */
	class CachedFont {

	protected:
		CachedFont() {}

	public:
		/**
		 * ��ȡ��������ľ��
		 */
		static shared_ptr<CachedFont>& GetInstance();

	protected:
		/**
		 * ��������ľ��
		 */
		static shared_ptr<CachedFont> _instance;

	public:
		/**
		 * �ͷ����л����������Դ
		 */
		void Clear();

		/**
		 * ����ID��ȡ���������
		 */
		weak_ptr<Gdiplus::Font> GetFont(CString id);

		/**
		 * ��ӻ������������ID
		 */
		void CacheFont(CString id, Gdiplus::Font* font);

	protected:
		/**
		 * ������Դ
		 */
		map<CString, shared_ptr<Gdiplus::Font> > m_fonts;
	};

	/**
	 * �������״
	 */
	class CachedShape {

	protected:
		CachedShape() {}

	public:
		/**
		 * ��ȡ��������ľ��
		 */
		static shared_ptr<CachedShape>& GetInstance();

	protected:
		/**
		 * ��������ľ��
		 */
		static shared_ptr<CachedShape> _instance;

	public:
		/**
		 * �ͷ����л������״��Դ
		 */
		void Clear();

		/**
		 * ����ID��ȡ�������״
		 */
		weak_ptr<Shape> GetShape(CString id);

		/**
		 * ��ӻ�����״������ID
		 */
		void CacheShape(CString id, Shape* shape);

	protected:
		/**
		 * ��״��Դ
		 */
		map<CString, shared_ptr<Shape> > m_shapes;
	};

	// 
	// TODO ��������һ�����ʣ�����Ŀǰ���뷨����ʽ�ļ���ͼ���ļ�������
	// ���ڸ���Ψһ�ĵ����ļ��У���Ȼ���� Style����ʽ��֮����Լ̳У�
	// ���ǲ����ڶ���ļ��������Ͳ��ҡ�����е�����ģ��͸����ˡ�
	// 

	/**
	 * Ƥ����Դ������
	 */
	class SkinRes {

	protected:
		SkinRes() {}

	public:
		/**
		* ��ȡ��������ľ��
		*/
		static shared_ptr<SkinRes>& GetInstance();

	protected:
		/**
		* ��������ľ��
		*/
		static shared_ptr<SkinRes> _instance;

	public:
		// 
		// ������Դ���밴�������˳����أ�
		// ������ܳ����Ҳ�����Դ�������
		// 

		/**
		 * 0.���¼��� Color����ɫ����Դ
		 */
		BOOL ReloadColorXml(CString strXml);

		/**
		 * 1.���¼��� Image��ͼ����Դ
		 */
		BOOL ReloadImageXml(CString strXml);

		/**
		 * 2.���¼��� Font�����壩��Դ
		 */
		BOOL ReloadFontXml(CString strXml);

		/**
		 * 3.���¼��� Shape����״����Դ
		 */
		BOOL ReloadShapeXml(CString strXml);

		/**
		 * 4.���¼��� Style����ʽ����Դ
		 */
		BOOL ReleadStyleXml(CString strXml);
	};

}