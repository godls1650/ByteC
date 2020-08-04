// CMainFVIew.cpp: 구현 파일
//

#include "pch.h"
#include "MFC_SplitWnd.h"
#include "CMainFVIew.h"


// CMainFVIew

IMPLEMENT_DYNCREATE(CMainFVIew, CFormView)

CMainFVIew::CMainFVIew()
	: CFormView(IDD_CMainFVIew)
{

}

CMainFVIew::~CMainFVIew()
{
}

void CMainFVIew::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMainFVIew, CFormView)
END_MESSAGE_MAP()


// CMainFVIew 진단

#ifdef _DEBUG
void CMainFVIew::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CMainFVIew::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMainFVIew 메시지 처리기
