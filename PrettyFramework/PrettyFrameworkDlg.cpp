#include "stdafx.h"
#include "PrettyFramework.h"
#include "PrettyFrameworkDlg.h"

#include "Label.h"
#include "Image.h"
#include "Button.h"

#include "Line.h"
#include "Rectangle.h"

#include "StringRes.h"

#include "HorizontalLayout.h"

CPrettyFrameworkDlg::CPrettyFrameworkDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PRETTYFRAMEWORK_DIALOG, pParent)
	, VerticalLayout(nullptr)
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

	BaseControl::SetId(_T("root_layout"));
	BaseControl::SetWindow(GetSafeHwnd());

	Margin winMaigin(2.0f, 2.0f, 2.0f, 2.0f);
	BaseControl::SetMargin(winMaigin);

	auto& bkgnd = LayoutControl::GetBkgndShape();

	bkgnd->SetFillNull(FALSE);
	bkgnd->SetBorderNull(FALSE);
	bkgnd->SetBorderWidth(1.0f);
	bkgnd->SetBorderColor(Gdiplus::Color(72, 72, 72));
	bkgnd->SetFillColor(Gdiplus::Color(214, 219, 233));

// 	// 标题栏布局
// 	shared_ptr<HorizontalLayout> title_layout(new HorizontalLayout(this));
// 	title_layout->SetMargin(Rect(2, 2, 2, 2));
// 	title_layout->SetId(_T("title_layout"));
// 	title_layout->SetFixSize(Size(0, 40));
// 	LayoutControl::AddChild(title_layout);
// 
// 	auto& title_bkgnd = title_layout->GetBkgndShape();
// 	title_bkgnd->SetBorderNull(TRUE);
// 	title_bkgnd->SetFillNull(TRUE);
// 
// 	// 标题栏图标
// 	shared_ptr<Image> title_image(new Image(title_layout.get()));
// 	HICON hTImage = theImageRes.GetImage(_T("title_image"));
// 	title_image->SetMargin(Rect(3, 3, 3, 3));
// 	title_image->SetFixSize(Size(36, 0));
// 	title_image->SetId(_T("title_image"));
// 	title_layout->AddChild(title_image);
// 	title_image->SetBitmap(hTImage);
// 
// 	// 标题栏文字
// 	shared_ptr<Label> title_text(new Label(title_layout.get()));
// 	title_text->SetGravity(Gravity::CenterH | Gravity::CenterV);
// 	CString strTText = theStringRes.GetString(_T("title_text"));
// 	title_text->SetMargin(Rect(2, 2, 2, 2));
// 	title_text->SetId(_T("title_text"));
// 	title_layout->AddChild(title_text);
// 	title_text->SetAutoWidth(TRUE);
// 	title_text->SetText(strTText);
// 
// 	title_text->SetPreviewMouseDownEvent([&](EventParam& param) {
// 		DWORD lParam = MAKELPARAM(param.point.X, param.point.Y);
// 		SendMessage(WM_NCLBUTTONDOWN, HTCAPTION, lParam);
// 	});
// 
// 	// 标题栏关闭按钮
// 	shared_ptr<Button> title_close(new Button(title_layout.get()));
// 	HICON hTClose = theImageRes.GetImage(_T("title_close"));
// 	title_close->SetMargin(Rect(10, 10, 10, 10));
// 	title_close->SetFixSize(Size(36, 0));
// 	title_close->SetId(_T("title_close"));
// 	title_layout->AddChild(title_close);
// 	title_close->SetBitmap(hTClose);
// 
// 	ClickEvent clickEvent = bind(&CPrettyFrameworkDlg::BtnCloseClicked
// 		, this, std::placeholders::_1);
// 	title_close->SetClickEvent(clickEvent);
// 
// 	auto& children = LayoutControl::GetChildren();
// 	for (size_t i = 0; i < children.size(); i++) {
// 		children.at(i)->Dump();
// 	}

	shared_ptr<Line> line0(new Line());
	m_shapes.push_back(line0);

	line0->SetBorderWidth(3.0f);
	line0->SetBeginPoint(Point(200.0f, 0.0f));
	line0->SetEndPoint(Point(200.0f, 200.0f));
	// line0->SetBorderStyle(Gdiplus::DashStyleDash);
	line0->SetBorderColor(Gdiplus::Color(255, 0, 0));

	shared_ptr<Line> line1(new Line());
	m_shapes.push_back(line1);

	line1->SetBorderWidth(3.0f);
	line1->SetBeginPoint(Point(0.0f, 0.0f));
	line1->SetEndPoint(Point(200.0f, 200.0f));
	// line1->SetBorderStyle(Gdiplus::DashStyleDash);
	line1->SetBorderColor(Gdiplus::Color(255, 0, 0));

	shared_ptr<PrettyFramework::Rectangle>
		rectangle(new PrettyFramework::Rectangle());
	m_shapes.push_back(rectangle);

	rectangle->SetBorderWidth(3.0f);
	rectangle->SetBeginPoint(Point(0.0f, 200.0f));
	rectangle->SetEndPoint(Point(200.0f, 400.0f));
	// rectangle->SetBorderStyle(Gdiplus::DashStyleDash);
	rectangle->SetBorderColor(Gdiplus::Color(255, 0, 0));
	rectangle->SetFillColor(Gdiplus::Color(255, 255, 255));

	return TRUE;
}

void CPrettyFrameworkDlg::OnPaint()
{
	CPaintDC dc(this);
	CMemDC memDC(dc, this);

	Gdiplus::Graphics* graph = nullptr;
	HDC hDC = memDC.GetDC().GetSafeHdc();
	graph = Gdiplus::Graphics::FromHDC(hDC);

	LayoutControl::Paint(*graph);

	// for (size_t i = 0; i < m_shapes.size(); i++) {
	// 	m_shapes[i]->Paint(*graph);
	// }
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

	LayoutControl::SetRect(fromGdiRect(rcClient));

	auto& children = LayoutControl::GetChildren();
	for (size_t i = 0; i < children.size(); i++) {
		children.at(i)->Dump();
	}
}

void CPrettyFrameworkDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	CDialogEx::OnLButtonDown(nFlags, point);

	LayoutControl::OnMouseDown(fromGdiPoint(point));
}

void CPrettyFrameworkDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	CDialogEx::OnMouseMove(nFlags, point);

	LayoutControl::OnMouseMove(fromGdiPoint(point));
}

void CPrettyFrameworkDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	CDialogEx::OnLButtonUp(nFlags, point);

	LayoutControl::OnMouseUp(fromGdiPoint(point));
}

void CPrettyFrameworkDlg::BtnCloseClicked(ClickParam& param)
{
	param.control->SetDisable(TRUE);
}