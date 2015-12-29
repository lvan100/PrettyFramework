#pragma once

namespace PrettyFramework {

	//
	// Control、Style 和 Theme 的区别：Control 负责实现控件的
	// 事件逻辑；Style 负责实现控件的界面显示；Theme 负责管理
	// 控件的配色方案。
	//
	
	// 
	// 详细解释 Style 和 Theme 的区别：Style 可以改变控件内容
	// 的显示方式，比如按钮的图上字下、图左字右、是否显示文字
	// 等都可以通过按钮的 Style 去改变；而 Theme 可以改变控件
	// 显示的配色，比如 VS2010 的蓝色风格、VS2013 的浅色和深
	// 色风格都可以通过改变 Theme 实现。
	//

	// 
	// Theme 只能改变控件的默认配色，控件仍然可以通过 Style 改
	// 变按钮或文字的颜色。
	// 

}