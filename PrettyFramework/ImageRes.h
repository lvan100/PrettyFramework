#pragma once

#include <map>
using namespace std;

namespace PrettyFramework {

	/**
	 * ͼ����Դ
	 */
	class ImageResource
	{
	public:
		ImageResource();
		~ImageResource();

		/**
		 * ����ͼ��ID��ȡͼ��
		 */
		HICON GetImage(CString id);

	protected:
		/**
		 * ͼ����Դ
		 */
		map<CString, HICON> m_images;
	};

	/**
	 * ȫ�ֵ�ͼ����Դ������
	 */
	extern ImageResource theImageRes;

}