
// GraphicProgramView.cpp: CGraphicProgramView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "GraphicProgram.h"
#endif

#include "GraphicProgramDoc.h"
#include "GraphicProgramView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGraphicProgramView

IMPLEMENT_DYNCREATE(CGraphicProgramView, CView)

BEGIN_MESSAGE_MAP(CGraphicProgramView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
	ON_WM_PAINT()
//	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CGraphicProgramView 생성/소멸

CGraphicProgramView::CGraphicProgramView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	
}

CGraphicProgramView::~CGraphicProgramView()
{
}

BOOL CGraphicProgramView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CGraphicProgramView 그리기

void CGraphicProgramView::OnDraw(CDC* pDC)
{
	CGraphicProgramDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	pDC = GetDC();
	if (pDoc->bLbuttonPush) {
		pDC->MoveTo(pDoc->Start);
		pDC->LineTo(pDoc->pos);
	}
	/*
	CPen pen, * oldPen;
	CBrush brush, * oldBrush;
	brush.CreateSolidBrush(RGB(pDoc->R, pDoc->G, pDoc->B));
	pen.CreatePen(PS_SOLID, 10, RGB(pDoc->R, pDoc->G, pDoc->B));
	oldPen = pDC->SelectObject(&pen);
	oldBrush = pDC->SelectObject(&brush);
	int n = pDoc->s;
	if (pDoc->bLbuttonPush) {
		pDC->Ellipse(pDoc->pos.x - n, pDoc->pos.y - n,
			pDoc->pos.x + n, pDoc->pos.y + n);
	}

	CString text;
	text.Format(_T("%3d, %3d"), pDoc->pos.x, pDoc->pos.y);
	pDC->TextOut(100, 100, text);

	pDC->SelectObject(oldPen);
	pDC->SelectObject(oldBrush);
	pen.DeleteObject();
	brush.DeleteObject();
	*/
	ReleaseDC(pDC);
}


// CGraphicProgramView 인쇄

BOOL CGraphicProgramView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	
	return DoPreparePrinting(pInfo);
}

void CGraphicProgramView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
	
}

void CGraphicProgramView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CGraphicProgramView 진단

#ifdef _DEBUG
void CGraphicProgramView::AssertValid() const
{
	CView::AssertValid();
}

void CGraphicProgramView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGraphicProgramDoc* CGraphicProgramView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGraphicProgramDoc)));
	return (CGraphicProgramDoc*)m_pDocument;
}
#endif //_DEBUG


// CGraphicProgramView 메시지 처리기


//void CGraphicProgramView::OnPaint()
//{
//	CPaintDC dc(this); // device context for painting
//					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
//					   // 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.
//
//}


//void CGraphicProgramView::OnPaint()
//{
//	CPaintDC dc(this); // device context for painting
//					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
//					   // 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.
//	CRect rect = CRect(0, 0, 100, 100);
//	dc.Ellipse(&rect);
//	CView::OnPaint();
//}


//void CGraphicProgramView::OnLButtonDblClk(UINT nFlags, CPoint point)
//{
//	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
//	CGraphicProgramDoc* pDoc = GetDocument();
//	pDoc->pos.x = point.x;
//	pDoc->pos.y = point.y;
//	CView::OnLButtonDblClk(nFlags, point);
//}


void CGraphicProgramView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CGraphicProgramDoc* pDoc = GetDocument();
	pDoc->bLbuttonPush = true;
	
	pDoc->Start.x = point.x;
	pDoc->Start.y = point.y;

	CView::OnLButtonDown(nFlags, point);
}


void CGraphicProgramView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CGraphicProgramDoc* pDoc = GetDocument();
	pDoc->bLbuttonPush = false;
	CView::OnLButtonUp(nFlags, point);
}


void CGraphicProgramView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CGraphicProgramDoc* pDoc = GetDocument();
	if (pDoc->bLbuttonPush) {
		pDoc->pos.x = point.x;
		pDoc->pos.y = point.y;
		Invalidate(TRUE);
	}
	/*
	static int count = 500;
	if (pDoc->bLbuttonPush) {
		pDoc->pos.x = point.x;
		pDoc->pos.y = point.y;
		
		Invalidate(FALSE);
		count--;
		if (count % 100 == 0 && count >= 0) pDoc->s--;
		else {
			count = 500;
			pDoc->s = 10;
		}
	}
	*/
	CView::OnMouseMove(nFlags, point);
}
