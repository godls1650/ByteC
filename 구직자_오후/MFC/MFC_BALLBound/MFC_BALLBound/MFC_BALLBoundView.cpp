
// MFC_BALLBoundView.cpp: CMFCBALLBoundView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFC_BALLBound.h"
#endif

#include "MFC_BALLBoundDoc.h"
#include "MFC_BALLBoundView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#define Timer1 1000
#endif


// CMFCBALLBoundView

IMPLEMENT_DYNCREATE(CMFCBALLBoundView, CView)

BEGIN_MESSAGE_MAP(CMFCBALLBoundView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CMFCBALLBoundView 생성/소멸

CMFCBALLBoundView::CMFCBALLBoundView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	
}

CMFCBALLBoundView::~CMFCBALLBoundView()
{

}

BOOL CMFCBALLBoundView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFCBALLBoundView 그리기

void CMFCBALLBoundView::OnDraw(CDC* /*pDC*/)
{
	CMFCBALLBoundDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC dc(this);
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	Ellipse(dc
		, pDoc->m_Pos.x
		, pDoc->m_Pos.y
		, pDoc->m_Pos.x + pDoc->m_nDiameter 
		, pDoc->m_Pos.y + pDoc->m_nDiameter );
}


// CMFCBALLBoundView 인쇄

BOOL CMFCBALLBoundView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFCBALLBoundView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.

}

void CMFCBALLBoundView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
	//
}


// CMFCBALLBoundView 진단

#ifdef _DEBUG
void CMFCBALLBoundView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCBALLBoundView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCBALLBoundDoc* CMFCBALLBoundView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCBALLBoundDoc)));
	return (CMFCBALLBoundDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCBALLBoundView 메시지 처리기


void CMFCBALLBoundView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CMFCBALLBoundDoc* pDoc = GetDocument();
	CRect rect;
	GetClientRect(rect);
	
	if (pDoc->m_Pos.x + pDoc->m_nDiameter == rect.right  || pDoc->m_Pos.x == 0) {
		pDoc->m_Path.x *= -1;
	}
	if (pDoc->m_Pos.y + pDoc->m_nDiameter == rect.bottom || pDoc->m_Pos.y == 0) {
		pDoc->m_Path.y *= -1;
	}
	CString str;
	
	
	pDoc->m_Pos.x += pDoc->m_Path.x;
	pDoc->m_Pos.y += pDoc->m_Path.y;
	
	Invalidate(TRUE);
	CView::OnTimer(nIDEvent);
}


int CMFCBALLBoundView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	SetTimer(Timer1, 1000 / 60, NULL);
	return 0;
}


void CMFCBALLBoundView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	KillTimer(Timer1);
}
