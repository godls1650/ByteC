
// TabTesterDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "TabTester.h"
#include "TabTesterDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTabTesterDlg 대화 상자



CTabTesterDlg::CTabTesterDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TABTESTER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTabTesterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_TabControl);
	DDX_Control(pDX, IDC_TREE1, m_TreeCtrl);
}

BEGIN_MESSAGE_MAP(CTabTesterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CTabTesterDlg::OnSelchangeTab1)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &CTabTesterDlg::OnTvnSelchangedTree1)
END_MESSAGE_MAP()


// CTabTesterDlg 메시지 처리기

BOOL CTabTesterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	TC_ITEM tabSrc;
	tabSrc.mask = TCIF_TEXT;
	tabSrc.pszText = _T("첫번째 탭");
	m_TabControl.InsertItem(0, &tabSrc);

	tabSrc.pszText = _T("두번째 탭");
	m_TabControl.InsertItem(1, &tabSrc);

	CRect rect;
	m_TabControl.GetClientRect(&rect);
	

	m_firstTab.Create(IDD_CFirstDlg, &m_TabControl);
	m_firstTab.MoveWindow(5, 25, rect.right, rect.bottom);
	m_firstTab.ShowWindow(SW_SHOW);

	m_secondTab.Create(IDD_CSecondDlg, &m_TabControl);
	m_secondTab.MoveWindow(5, 25, rect.right, rect.bottom);
	m_secondTab.ShowWindow(SW_HIDE);

	CString label;
	HTREEITEM  hSubRoot[3];
	
	label.LoadString(IDS_STRING102);
	hSubRoot[0] = m_TreeCtrl.InsertItem(label, TVI_ROOT, TVI_LAST);
	label.LoadString(IDS_STRING102 + 1);
	hSubRoot[1] = m_TreeCtrl.InsertItem(label, TVI_ROOT, TVI_LAST);
	label.LoadString(IDS_STRING102 + 2);
	hSubRoot[2] = m_TreeCtrl.InsertItem(label, TVI_ROOT, TVI_LAST);


	m_TreeCtrl.InsertItem(_T("딸기바나나"), hSubRoot[0]);
	m_TreeCtrl.InsertItem(_T("수박 주스"), hSubRoot[0]);

	m_TreeCtrl.InsertItem(_T("허니브래드"), hSubRoot[1]);
	m_TreeCtrl.InsertItem(_T("아이스크림 와플"), hSubRoot[1]);

	m_TreeCtrl.InsertItem(_T("라떼"), hSubRoot[2]);
	hSubRoot[2] = m_TreeCtrl.InsertItem(_T("아메리카노"), hSubRoot[2]);
	m_TreeCtrl.InsertItem(_T("아이스 아메리카노"), hSubRoot[2]);
	m_TreeCtrl.InsertItem(_T("핫 아메리카노"), hSubRoot[2]);
	
	


	






	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CTabTesterDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CTabTesterDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CTabTesterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTabTesterDlg::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int tabIndex = m_TabControl.GetCurSel();
	switch (tabIndex) {
	case 0 :
		m_firstTab.ShowWindow(SW_SHOW);
		m_secondTab.ShowWindow(SW_HIDE);
		break;
	case 1 :
		m_secondTab.ShowWindow(SW_SHOW);
		m_firstTab.ShowWindow(SW_HIDE);
		break;
	}
	*pResult = 0;
}


void CTabTesterDlg::OnTvnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString text =  m_TreeCtrl.GetItemText(pNMTreeView->itemNew.hItem);
	
	if (text == "아이스 아메리카노") {
		MessageBox(_T("2800원 입니다."));
	}
	*pResult = 0;
}
