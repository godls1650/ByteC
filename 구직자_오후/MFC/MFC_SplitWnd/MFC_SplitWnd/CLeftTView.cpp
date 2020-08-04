// CLeftTView.cpp: 구현 파일
//

#include "pch.h"
#include "MFC_SplitWnd.h"
#include "CLeftTView.h"


// CLeftTView

IMPLEMENT_DYNCREATE(CLeftTView, CTreeView)

CLeftTView::CLeftTView()
{

}

CLeftTView::~CLeftTView()
{
}

BEGIN_MESSAGE_MAP(CLeftTView, CTreeView)
END_MESSAGE_MAP()


// CLeftTView 진단

#ifdef _DEBUG
void CLeftTView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CLeftTView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CLeftTView 메시지 처리기
