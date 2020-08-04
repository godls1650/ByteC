
// TextEditorView.cpp: CTextEditorView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "TextEditor.h"
#endif

#include "TextEditorDoc.h"
#include "TextEditorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTextEditorView

IMPLEMENT_DYNCREATE(CTextEditorView, CView)

BEGIN_MESSAGE_MAP(CTextEditorView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
//	ON_WM_CHAR()
ON_WM_CHAR()
END_MESSAGE_MAP()

// CTextEditorView 생성/소멸

CTextEditorView::CTextEditorView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
}

CTextEditorView::~CTextEditorView()
{
}

BOOL CTextEditorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CTextEditorView 그리기

void CTextEditorView::OnDraw(CDC* /*pDC*/)
{
	CTextEditorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect rect;
	GetClientRect(rect);
	
	CClientDC dc(this);
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	for(int i = 0 ;  i <= pDoc->m_cols ; i++)
		dc.TextOutW(0, 20*i, pDoc->m_lpszText[i]);

}


// CTextEditorView 인쇄

BOOL CTextEditorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CTextEditorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CTextEditorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CTextEditorView 진단

#ifdef _DEBUG
void CTextEditorView::AssertValid() const
{
	CView::AssertValid();
}

void CTextEditorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTextEditorDoc* CTextEditorView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTextEditorDoc)));
	return (CTextEditorDoc*)m_pDocument;
}
#endif //_DEBUG




void CTextEditorView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CTextEditorDoc* pDC = GetDocument();
	CString temp;
	switch (nChar) {
	case VK_RETURN:
		pDC->m_cols++;
		pDC->m_lows = 0;
		break;
	case VK_BACK :
		if (pDC->m_cols != 0 && pDC->m_lows == 0) {
			pDC->m_lpszText[pDC->m_cols] = _T("");
			pDC->m_cols--;
			pDC->m_lows = pDC->m_lpszText->GetLength();
		}
		else if(pDC->m_lows > 0){
			pDC->m_lpszText[pDC->m_cols].Delete(pDC->m_lows - 1);
			pDC->m_lows--;
		}
		else {
			break;
		}
		break;
	default :
		temp.Format(_T("%c"), nChar);
		pDC->m_lpszText[pDC->m_cols] += temp;
		pDC->m_lows++;
	}
	//WM_CHAR 일때 Document의 문자열에 값을 저장

	Invalidate(TRUE);//갱신
	CView::OnChar(nChar, nRepCnt, nFlags);
}
