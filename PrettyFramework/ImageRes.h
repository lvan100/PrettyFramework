#pragma once

#include <memory>
using namespace std;

namespace PrettyFramework {

	// 
	// ֻ���� PNG ��ʽ��ͼ��
	// 

	/**
	 * �ͷ�����ͼ����Դ
	 */
	void ClearImages();

	/**
	 * ����ͼ��ID��ȡͼ��
	 */
	weak_ptr<Gdiplus::Image>& GetImage(CString id);

	/**
	 * ����ͼ��ID��ȡ�б�ʽͼ��
	 */
	weak_ptr<Gdiplus::Image>& GetImageList(CString id);

}