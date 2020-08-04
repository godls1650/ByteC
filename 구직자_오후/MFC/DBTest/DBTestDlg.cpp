
// DBTestDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "DBTest.h"
#include "DBTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define DB_LOCATE _T("localhost")// 내지 Server IP
#define DB_USER	_T("root") //DB 접속 계정
#define DB_PASS _T("1234") //DB 계정 비밀 번호
#define DB_BASE	_T("testdb")// DB 이름
#define DB_TABLE _T("memberdb")// DB 테이블 이름
#define DB_DTABLE(tabName) "testdb."##tabName


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


// CDBTestDlg 대화 상자



CDBTestDlg::CDBTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DBTEST_DIALOG, pParent)
	, m_szName(_T(""))
	, m_szMemNo(_T(""))
	, m_szAddress(_T(""))
	, m_ph1(_T(""))
	, m_szPh2(_T(""))
	, m_szPh3(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDBTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_DATA, m_listData);
	DDX_Control(pDX, IDC_EDIT_MemNo, m_EditMemNo);
	DDX_Text(pDX, IDC_EDIT_NAME, m_szName);
	DDX_Text(pDX, IDC_EDIT_MemNo, m_szMemNo);
	DDX_Text(pDX, IDC_EDIT_ADDRESS, m_szAddress);
	DDX_Text(pDX, IDC_EDIT_PH1, m_ph1);
	DDX_Text(pDX, IDC_EDIT_PH2, m_szPh2);
	DDX_Text(pDX, IDC_EDIT_PH3, m_szPh3);
}

BEGIN_MESSAGE_MAP(CDBTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_EDIT, &CDBTestDlg::OnClickedButtonEdit)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &CDBTestDlg::OnClickedButtonDel)
	ON_BN_CLICKED(IDC_BUTTON_APPEND, &CDBTestDlg::OnClickedButtonAppend)
END_MESSAGE_MAP()


// CDBTestDlg 메시지 처리기

BOOL CDBTestDlg::OnInitDialog()
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
	MYSQL Connect;
	MYSQL_ROW Sql_Row;
	MYSQL_RES* Sql_Result;
	CString Query;
	Query.Format(_T("Select * From %s.%s;"), DB_BASE, DB_TABLE);

	mysql_init(&Connect);
	mysql_real_connect(&connect, DB_LOCATE, DB_USER, DB_PASS, DB_DTABLE(DB_TABLE), 8080, NULL, 0);
	mysql_query(&Connect, Query);
	Sql_Result = mysql_store_result(&Connect);


	CRect rect;
	m_listData.GetClientRect(&rect);
	m_listData.DeleteAllItems(); // 기존 리스트출력을 비운다.
	m_listData.SetExtendedStyle(LVS_EX_GRIDLINES); // 리스트 스타일


	m_listData.InsertColumn(0, _T("회원번호"), LVCFMT_LEFT, rect.right / 8, -1);
	m_listData.InsertColumn(1, _T("이    름"), LVCFMT_CENTER, rect.right / 6, -1);
	m_listData.InsertColumn(2, _T("주    소"), LVCFMT_CENTER, rect.right / 2, -1);
	m_listData.InsertColumn(3, _T("전화번호"), LVCFMT_CENTER, rect.right / 4, -1);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CDBTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDBTestDlg::OnPaint()
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
HCURSOR CDBTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDBTestDlg::OnClickedButtonEdit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CDBTestDlg::OnClickedButtonDel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CDBTestDlg::OnClickedButtonAppend()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
