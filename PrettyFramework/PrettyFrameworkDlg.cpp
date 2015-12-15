#include "stdafx.h"
#include "PrettyFramework.h"
#include "PrettyFrameworkDlg.h"

#include "Label.h"
#include "Image.h"

CPrettyFrameworkDlg::CPrettyFrameworkDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PRETTYFRAMEWORK_DIALOG, pParent)
	, LinearLayout(nullptr, FALSE)
{
	BaseControl::SetWindow(GetSafeHwnd());
}

void CPrettyFrameworkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPrettyFrameworkDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_SIZE()
END_MESSAGE_MAP()

BOOL CPrettyFrameworkDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 标题栏布局
	shared_ptr<LinearLayout> title_layout(new LinearLayout(this, TRUE));
	title_layout->SetFixSize(CSize(0, 40));
	LayoutControl::AddChild(title_layout);

	shared_ptr<Image> title_image(new Image(title_layout.get()));
	title_image->SetBitmap(AfxGetApp()->LoadIcon(IDR_MAINFRAME));
	title_image->SetFixSize(CSize(32, 32));
	title_layout->AddChild(title_image);

	shared_ptr<Label> title_text(new Label(title_layout.get()));
	title_text->SetGravity(Gravity::CenterH | Gravity::CenterV);
	title_text->SetText(_T("资料管理"));
	title_layout->AddChild(title_text);
	title_text->SetBorderNull(TRUE);
	title_text->SetAutoWidth(TRUE);


// 	shared_ptr<Label> label(new Label(this));
// 	label->SetRect(CRect(100, 100, 200, 200));
// 	label->SetText(_T("这是一个标签控件"));
// 	label->SetTextColor(RGB(255, 0, 0));
// 	label->SetBkColor(RGB(0, 255, 0));
// 
// 	LayoutControl::AddChild(label);
// 
// 	auto& layout = shared_ptr<LinearLayout>(new LinearLayout(label.get(), TRUE));
// 
// 	shared_ptr<Label> sub_label_1(new Label(layout.get()));
// 	//sub_label_1->SetRect(CRect(0, 50, 50, 100));
// 	sub_label_1->SetText(_T("这是一个标签控件"));
// 	sub_label_1->SetTextColor(RGB(0, 0, 255));
// 	sub_label_1->SetBkColor(RGB(255, 0, 0));
// 	sub_label_1->SetMinSize(CSize(70, 70));
// 
// 	layout->AddChild(sub_label_1);
// 
// 	shared_ptr<Label> sub_label_2(new Label(layout.get()));
// 	//sub_label_2->SetRect(CRect(0, 50, 50, 100));
// 	sub_label_2->SetText(_T("这是一个标签控件"));
// 	sub_label_2->SetTextColor(RGB(255, 0, 255));
// 	sub_label_2->SetBkColor(RGB(255, 255, 255));
// 
// 	layout->AddChild(sub_label_2);
// 
// 	label->SetLayoutControl(layout);

	return TRUE;
}

void CPrettyFrameworkDlg::OnPaint()
{
	CPaintDC dc(this);

	CRect rcClient;
	GetClientRect(rcClient);

	CMemDC memDC(dc, this);
	memDC.GetDC().FillSolidRect(rcClient, RGB(240, 240, 240));

	LayoutControl::Paint(memDC.GetDC());
}

void CPrettyFrameworkDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	CRect rcClient;
	GetClientRect(rcClient);
	LayoutControl::SetRect(rcClient);
}