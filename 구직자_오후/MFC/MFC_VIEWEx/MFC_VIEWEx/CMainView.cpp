// CMainView.cpp: 구현 파일
//

#include "pch.h"
#include "MFC_VIEWEx.h"
#include "CMainView.h"


// CMainView

IMPLEMENT_DYNCREATE(CMainView, CView)

CMainView::CMainView()
{

}

CMainView::~CMainView()
{
}

BEGIN_MESSAGE_MAP(CMainView, CView)
END_MESSAGE_MAP()


// CMainView 그리기

void CMainView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: 여기에 그리기 코드를 추가합니다.
}


// CMainView 진단

#ifdef _DEBUG
void CMainView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CMainView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMainView 메시지 처리기
