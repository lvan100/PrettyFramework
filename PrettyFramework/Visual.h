#pragma once

#include "Coordinate.h"

namespace PrettyFramework {

	// 
	// ���ԭ��Ϊ�˼򵥣�ֻ��ʵ��Ϊ�����̳е�ϵͳ��
	// 

	// 
	// �κξ����Ӿ�Ч���Ķ�����Ҫ�̳� @Visual �ӿ�
	// ����������ؼ�����ͼ��״�ȣ�����̳иýӿڡ�
	// 

	// 
	// ���ǵ���ƽ̨�ԣ���ͼ��ʹ�� Gdiplus����ƽ̨����
	// 

	/**
	 * �Ӿ��ӿ�
	 */
	class Visual
	{
	public:
		/**
		 * ��ɻ�ͼ����
		 */
		void Paint(Gdiplus::Graphics& graph) {
			if (!_paintFrozen) {
				Paint0(graph);
			}
		}

		/**
		 * �����ͼ����
		 */
		void FreezePaint(BOOL freeze) {
			_paintFrozen = freeze;
		}

		/**
		 * ��ͼ�Ƿ񶳽�
		 */
		BOOL PaintFrozen() {
			return _paintFrozen;
		}

	protected:
		/**
		 * ��ͼ�Ƿ񶳽�
		 */
		BOOL _paintFrozen = FALSE;

	protected:
		/**
		 * ����ʵ�ֻ�ͼ�ӿ�
		 */
		virtual void Paint0(Gdiplus::Graphics& graph) = 0;
	};

}