#include "stdafx.h"
#include "PrettyFramework.h"
#include "PrettyFrameworkDlg.h"

#include "Label.h"
#include "Image.h"
#include "Button.h"

#include "Line.h"
#include "Rectangle.h"

#include "ImageRes.h"
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
	BaseControl::SetMargin(Rect(2, 2, 2, 2));

	auto& bkgnd = LayoutControl::GetBkgndShape();
	bkgnd->SetFillColor(RGB(214, 219, 233));
	bkgnd->SetBorderColor(RGB(72, 72, 72));
	bkgnd->SetBorderWidth(1);

	// 标题栏布局
	shared_ptr<HorizontalLayout> title_layout(new HorizontalLayout(this));
	title_layout->SetMargin(Rect(2, 2, 2, 2));
	title_layout->SetId(_T("title_layout"));
	title_layout->SetFixSize(Size(0, 40));
	LayoutControl::AddChild(title_layout);

	auto& title_bkgnd = title_layout->GetBkgndShape();
	title_bkgnd->SetBorderNull(TRUE);
	title_bkgnd->SetFillNull(TRUE);

	// 标题栏图标
	shared_ptr<Image> title_image(new Image(title_layout.get()));
	HICON hTImage = theImageRes.GetImage(_T("title_image"));
	title_image->SetMargin(Rect(3, 3, 3, 3));
	title_image->SetFixSize(Size(36, 0));
	title_image->SetId(_T("title_image"));
	title_layout->AddChild(title_image);
	title_image->SetBitmap(hTImage);

	// 标题栏文字
	shared_ptr<Label> title_text(new Label(title_layout.get()));
	title_text->SetGravity(Gravity::CenterH | Gravity::CenterV);
	CString strTText = theStringRes.GetString(_T("title_text"));
	title_text->SetMargin(Rect(2, 2, 2, 2));
	title_text->SetId(_T("title_text"));
	title_layout->AddChild(title_text);
	title_text->SetAutoWidth(TRUE);
	title_text->SetText(strTText);

	title_text->SetPreviewMouseDownEvent([&](EventParam& param) {
		DWORD lParam = MAKELPARAM(param.point.X, param.point.Y);
		SendMessage(WM_NCLBUTTONDOWN, HTCAPTION, lParam);
	});

	// 标题栏关闭按钮
	shared_ptr<Button> title_close(new Button(title_layout.get()));
	HICON hTClose = theImageRes.GetImage(_T("title_close"));
	title_close->SetMargin(Rect(10, 10, 10, 10));
	title_close->SetFixSize(Size(36, 0));
	title_close->SetId(_T("title_close"));
	title_layout->AddChild(title_close);
	title_close->SetBitmap(hTClose);

	ClickEvent clickEvent = bind(&CPrettyFrameworkDlg::BtnCloseClicked
		, this, std::placeholders::_1);
	title_close->SetClickEvent(clickEvent);

	auto& children = LayoutControl::GetChildren();
	for (size_t i = 0; i < children.size(); i++) {
		children.at(i)->Dump();
	}

	// shared_ptr<Line> line(new Line());
	// m_shapes.push_back(line);
	// 
	// line->SetBorderWidth(1);
	// line->SetBorderStyle(PS_DASHDOT);
	// line->SetBeginPoint(Point(0, 0));
	// line->SetEndPoint(Point(200, 200));
	// line->SetBorderColor(RGB(255, 0, 0));

	shared_ptr<PrettyFramework::Rectangle>
		rectangle(new PrettyFramework::Rectangle());
	m_shapes.push_back(rectangle);

	rectangle->SetBorderWidth(3);
	rectangle->SetBorderStyle(PS_DASHDOT);
	rectangle->SetBeginPoint(Point(0, 200));
	rectangle->SetEndPoint(Point(200, 400));
	rectangle->SetBorderColor(RGB(255, 0, 0));
	rectangle->SetFillColor(RGB(255, 255, 255));


	return TRUE;
}

void CPrettyFrameworkDlg::OnPaint()
{
	CPaintDC dc(this);
	CMemDC memDC(dc, this);

	Gdiplus::Graphics* graph = nullptr;
	graph = Gdiplus::Graphics::FromHDC(memDC.GetDC().GetSafeHdc());

	for (size_t i = 0; i < m_shapes.size(); i++) {
		m_shapes[i]->Paint(*graph);
	}

	LayoutControl::Paint(*graph);
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

	Rect rcClientF;
	LayoutControl::SetRect(rcClientF);

	auto& children = LayoutControl::GetChildren();
	for (size_t i = 0; i < children.size(); i++) {
		children.at(i)->Dump();
	}
}

void CPrettyFrameworkDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	CDialogEx::OnLButtonDown(nFlags, point);

	Point pointF;
	LayoutControl::OnMouseDown(pointF);
}

void CPrettyFrameworkDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	CDialogEx::OnMouseMove(nFlags, point);

	Point pointF;
	LayoutControl::OnMouseMove(pointF);
}

void CPrettyFrameworkDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	CDialogEx::OnLButtonUp(nFlags, point);

	Point pointF;
	LayoutControl::OnMouseUp(pointF);
}

void CPrettyFrameworkDlg::BtnCloseClicked(ClickParam& param)
{
	param.control->SetDisable(TRUE);
}