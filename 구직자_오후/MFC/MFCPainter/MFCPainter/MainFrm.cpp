
// MainFrm.cpp: CMainFrame 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "MFCPainter.h"
#include "CLeftToolBar.h"
#include "MFCPainterView.h"
#include "MFCPainterDoc.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(IDM_COLOR_EDIT, &CMainFrame::OnColorEdit)
	ON_COMMAND(ID_FILE_OPEN, &CMainFrame::OnFileOpen)
END_MESSAGE_MAP()

// CMainFrame 생성/소멸

CMainFrame::CMainFrame() noexcept
{
	// TODO: 여기에 멤버 초기화 코드를 추가합니다.
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("도구 모음을 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}

	// TODO: 도구 모음을 도킹할 수 없게 하려면 이 세 줄을 삭제하십시오.
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT /*lpcs*/,
	CCreateContext* pContext)
{
	m_wndSplitter.CreateStatic(this,1, 2);
	m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(CLeftToolBar), CSize(100,0), pContext);
	m_wndSplitter.CreateView(0, 1, RUNTIME_CLASS(CMFCPainterView), CSize(0,0), pContext);
	return TRUE;

}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return TRUE;
}

// CMainFrame 진단

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 메시지 처리기



void CMainFrame::OnColorEdit()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorDialog colorDlg(RGB(255,255,255), CC_FULLOPEN);
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();

	if (colorDlg.DoModal() == IDOK) {
		COLORREF color = colorDlg.GetColor();
		CMFCPainterDoc* pDoc = (CMFCPainterDoc *)(pFrame->GetActiveDocument());
		pDoc->color = color;
		Invalidate(FALSE);
	}
}


void CMainFrame::OnFileOpen()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CFileDialog fileDlg(FALSE, _T("이미지(*.jpg, * bmp, *png)"),_T("*.jpg;*.bmp;*.png"), OFN_OVERWRITEPROMPT);
	if (fileDlg.DoModal() == IDOK) {
		CString path = fileDlg.GetPathName();
	}
}
