#include "stdafx.h"
#include "PrettyFramework.h"
#include "PrettyFrameworkDlg.h"

#include "Label.h"
#include "Image.h"
#include "Button.h"

#include "ImageRes.h"
#include "StringRes.h"

CPrettyFrameworkDlg::CPrettyFrameworkDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PRETTYFRAMEWORK_DIALOG, pParent)
	, LinearLayout(nullptr, FALSE)
	, m_mouse_down(FALSE)
{
}

void CPrettyFrameworkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPrettyFrameworkDlg, CDialogEx)
	ON_WM_LBUTTONDOWN()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_PAINT()
	ON_WM_SIZE()
END_MESSAGE_MAP()

BOOL CPrettyFrameworkDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CRect rcWindow(0, 0, 480, 600);
	MoveWindow(rcWindow);
	CenterWindow();

	BaseControl::SetWindow(GetSafeHwnd());
	BaseControl::SetMargin(CRect(2, 2, 2, 2));

	// 标题栏布局
	shared_ptr<LinearLayout> title_layout(new LinearLayout(this, TRUE));
	title_layout->SetMargin(CRect(2, 2, 2, 2));
	title_layout->SetId(_T("title_layout"));
	title_layout->SetFixSize(CSize(0, 40));
	LayoutControl::AddChild(title_layout);

	shared_ptr<Image> title_image(new Image(title_layout.get()));
	HICON hTImage = theImageRes.GetImage(_T("title_image"));
	title_image->SetMargin(CRect(3, 3, 3, 3));
	title_image->SetFixSize(CSize(36, 0));
	title_image->SetId(_T("title_image"));
	title_layout->AddChild(title_image);
	title_image->SetBitmap(hTImage);

	shared_ptr<Label> title_text(new Label(title_layout.get()));
	title_text->SetGravity(Gravity::CenterH | Gravity::CenterV);
	CString strTText = theStringRes.GetString(_T("title_text"));
	title_text->SetMargin(CRect(2, 2, 2, 2));
	title_text->SetId(_T("title_text"));
	title_layout->AddChild(title_text);
	title_text->SetAutoWidth(TRUE);
	title_text->SetText(strTText);

	shared_ptr<Button> title_close(new Button(title_layout.get()));
	HICON hTClose = theImageRes.GetImage(_T("title_close"));
	title_close->SetMargin(CRect(10, 10, 10, 10));
	title_close->SetFixSize(CSize(36, 0));
	title_close->SetId(_T("title_close"));
	title_layout->AddChild(title_close);
	title_close->SetBitmap(hTClose);

	auto& children = LayoutControl::GetChildren();
	for (size_t i = 0; i < children.size(); i++) {
		children.at(i)->Dump();
	}

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
	memDC.GetDC().FillSolidRect(rcClient, RGB(214, 219, 233));

	LayoutControl::Paint(memDC.GetDC());
}

BOOL CPrettyFrameworkDlg::OnEraseBkgnd(CDC* pDC)
{
	return TRUE;
}

void CPrettyFrameworkDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	CRect rcClient;
	GetClientRect(rcClient);
	LayoutControl::SetRect(rcClient);

	auto& children = LayoutControl::GetChildren();
	for (size_t i = 0; i < children.size(); i++) {
		children.at(i)->Dump();
	}
}

void CPrettyFrameworkDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_mouse_down = TRUE;

	CDialogEx::OnLButtonDown(nFlags, point);

	LayoutControl::OnMouseDown(point);
}

void CPrettyFrameworkDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_mouse_down = FALSE;

	CPoint ptCursor;
	GetCursorPos(&ptCursor);

	CRect rcWindow;
	GetWindowRect(rcWindow);

	if (!rcWindow.PtInRect(ptCursor)) {
		if (GetCapture() == this) {
			ReleaseCapture();
		}
	}

	CDialogEx::OnLButtonUp(nFlags, point);

	LayoutControl::OnMouseUp(point);
}

void CPrettyFrameworkDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	CPoint ptCursor;
	GetCursorPos(&ptCursor);

	CRect rcWindow;
	GetWindowRect(rcWindow);

	if (rcWindow.PtInRect(ptCursor)) {
		if (GetCapture() != this) {
			SetCapture();
		}
	} else {
		if (!m_mouse_down) {
			ReleaseCapture();
		}
	}

	CDialogEx::OnMouseMove(nFlags, point);

	LayoutControl::OnMouseMove(point);
}