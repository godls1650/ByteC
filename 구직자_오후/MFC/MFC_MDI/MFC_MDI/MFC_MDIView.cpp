
// MFC_MDIView.cpp: CMFCMDIView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFC_MDI.h"
#endif

#include "MFC_MDIDoc.h"
#include "MFC_MDIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCMDIView

IMPLEMENT_DYNCREATE(CMFCMDIView, CListView)

BEGIN_MESSAGE_MAP(CMFCMDIView, CListView)
	ON_WM_STYLECHANGED()
END_MESSAGE_MAP()

// CMFCMDIView 생성/소멸

CMFCMDIView::CMFCMDIView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFCMDIView::~CMFCMDIView()
{
}

BOOL CMFCMDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CListView::PreCreateWindow(cs);
}

void CMFCMDIView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: GetListCtrl()을 호출하여 해당 list 컨트롤을 직접 액세스함으로써
	//  ListView를 항목으로 채울 수 있습니다.
}


// CMFCMDIView 진단

#ifdef _DEBUG
void CMFCMDIView::AssertValid() const
{
	CListView::AssertValid();
}

void CMFCMDIView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CMFCMDIDoc* CMFCMDIView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCMDIDoc)));
	return (CMFCMDIDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCMDIView 메시지 처리기
void CMFCMDIView::OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct)
{
	//TODO: 사용자가 창의 뷰 스타일을 변경했을 때 반응하는 코드를 추가합니다.
	CListView::OnStyleChanged(nStyleType,lpStyleStruct);
}
