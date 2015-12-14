#include "stdafx.h"
#include "PrettyFramework.h"
#include "PrettyFrameworkDlg.h"

#include "Label.h"

CPrettyFrameworkDlg::CPrettyFrameworkDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PRETTYFRAMEWORK_DIALOG, pParent)
{
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

	shared_ptr<Label> label(new Label(this));
	label->SetRect(CRect(100, 100, 200, 200));
	label->SetText(_T("这是一个标签控件"));
	label->SetTextColor(RGB(255, 0, 0));
	label->SetBkColor(RGB(0, 255, 0));

	LayoutControl::AddChild(label);

	auto& layout = shared_ptr<VerticalLayout>(new VerticalLayout(label.get()));

	shared_ptr<Label> sub_label_1(new Label(layout.get()));
	//sub_label_1->SetRect(CRect(0, 50, 50, 100));
	sub_label_1->SetText(_T("这是一个标签控件"));
	sub_label_1->SetTextColor(RGB(0, 0, 255));
	sub_label_1->SetBkColor(RGB(255, 0, 0));
	sub_label_1->SetMinSize(CSize(0, 70));

	layout->AddChild(sub_label_1);

	shared_ptr<Label> sub_label_2(new Label(layout.get()));
	//sub_label_2->SetRect(CRect(0, 50, 50, 100));
	sub_label_2->SetText(_T("这是一个标签控件"));
	sub_label_2->SetTextColor(RGB(255, 0, 255));
	sub_label_2->SetBkColor(RGB(255, 255, 255));

	layout->AddChild(sub_label_2);

	label->SetLayoutControl(layout);

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