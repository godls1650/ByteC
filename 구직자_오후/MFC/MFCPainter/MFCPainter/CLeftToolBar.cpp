// CLeftToolBar.cpp: 구현 파일
//

#include "pch.h"
#include "MFCPainter.h"
#include "CLeftToolBar.h"

#include "CTestDlg.h"

// CLeftToolBar

IMPLEMENT_DYNCREATE(CLeftToolBar, CFormView)

CLeftToolBar::CLeftToolBar()
	: CFormView(IDD_CLeftToolBar)
{

}

CLeftToolBar::~CLeftToolBar()
{
}

void CLeftToolBar::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLeftToolBar, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CLeftToolBar::OnClickedButton1)
END_MESSAGE_MAP()


// CLeftToolBar 진단

#ifdef _DEBUG
void CLeftToolBar::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CLeftToolBar::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CLeftToolBar 메시지 처리기


void CLeftToolBar::OnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CTestDlg test;
	//test.Create(IDD_DIALOG1, this);
	//test.ShowWindow(SW_SHOW);
	if (test.DoModal() == IDOK) {
	
	}
}
