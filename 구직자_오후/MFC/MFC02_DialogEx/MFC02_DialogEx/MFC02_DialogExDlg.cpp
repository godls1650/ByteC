
// MFC02_DialogExDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFC02_DialogEx.h"
#include "MFC02_DialogExDlg.h"
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
public:
//	afx_msg void OnBnClickedRadioContract1();
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


// CMFC02DialogExDlg 대화 상자



CMFC02DialogExDlg::CMFC02DialogExDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC02_DIALOGEX_DIALOG, pParent)
	, m_sEditName(_T(""))
	, m_EditMoney(_T(""))
	, m_CheckHasCar(FALSE)
	, m_StrTeam(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC02DialogExDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_sEditName);
	DDX_Control(pDX, IDC_BUTTON_EDIT, m_EditBtn);
	DDX_Text(pDX, IDC_EDIT_MONEY, m_EditMoney);
	DDX_Check(pDX, IDC_CHECK_HASCAR, m_CheckHasCar);
	DDX_Control(pDX, IDC_COMBO_TEAM, m_ComboTeam);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_CBString(pDX, IDC_COMBO_TEAM, m_StrTeam);
}

BEGIN_MESSAGE_MAP(CMFC02DialogExDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_EDIT, &CMFC02DialogExDlg::OnClickedButtonEdit)
//	ON_BN_CLICKED(IDC_RADIO_CONTRACT1, &CMFC02DialogExDlg::OnClickedRadioContract1)
	ON_BN_CLICKED(IDC_RADIO_CONTRACT2, &CMFC02DialogExDlg::OnBnClickedRadioContract2)
	ON_BN_CLICKED(IDC_RADIO_CONTRACT3, &CMFC02DialogExDlg::OnBnClickedRadioContract3)
	ON_BN_CLICKED(IDC_RADIO_CONTRACT4, &CMFC02DialogExDlg::OnBnClickedRadioContract4)
	ON_BN_CLICKED(IDC_RADIO_CONTRACT1, &CMFC02DialogExDlg::OnBnClickedRadioContract1)
	ON_BN_CLICKED(IDC_CHECK_HASCAR, &CMFC02DialogExDlg::OnClickedCheckHascar)
	ON_CBN_SELCHANGE(IDC_COMBO_TEAM, &CMFC02DialogExDlg::OnSelchangeComboTeam)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CMFC02DialogExDlg::OnBnClickedButtonSave)
END_MESSAGE_MAP()


// CMFC02DialogExDlg 메시지 처리기

BOOL CMFC02DialogExDlg::OnInitDialog()
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
	m_EditBtn.EnableWindow(TRUE);
	m_CheckHasCar = FALSE;

	m_ComboTeam.AddString(_T("보안팀"));
	m_ComboTeam.AddString(_T("개발팀"));
	m_ComboTeam.AddString(_T("디자인팀"));
	m_ComboTeam.AddString(_T("회계팀"));
	m_ComboTeam.AddString(_T("영업팀"));
	m_ComboTeam.AddString(_T("..추가"));

	CRect rect;
	m_List.GetClientRect(rect);

	m_List.InsertColumn(0, _T("이름"),LVCFMT_LEFT,rect.right/5);
	m_List.InsertColumn(1, _T("계약형태"), LVCFMT_LEFT, rect.right / 5);
	m_List.InsertColumn(2, _T("소속"), LVCFMT_LEFT, rect.right / 5);
	m_List.InsertColumn(3, _T("차량 소유 여부"), LVCFMT_LEFT, rect.right / 5);
	m_List.InsertColumn(4, _T("연봉(만)"), LVCFMT_LEFT, rect.right / 5);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFC02DialogExDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC02DialogExDlg::OnPaint()
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
HCURSOR CMFC02DialogExDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC02DialogExDlg::OnClickedButtonEdit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	CString temp;
	temp = m_sEditName.GetString();
	AfxMessageBox(temp);
	m_EditMoney.SetString(temp);
	m_sEditName.SetString(_T(""));
	UpdateData(FALSE);
}


//void CAboutDlg::OnBnClickedRadioContract1()
//{
//	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
//}


void CMFC02DialogExDlg::OnBnClickedRadioContract1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_radioContract = 0;
}

void CMFC02DialogExDlg::OnBnClickedRadioContract2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_radioContract = 1;
}


void CMFC02DialogExDlg::OnBnClickedRadioContract3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_radioContract = 2;
}


void CMFC02DialogExDlg::OnBnClickedRadioContract4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_radioContract = 3;
}





void CMFC02DialogExDlg::OnClickedCheckHascar()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_CheckHasCar = !m_CheckHasCar;
}


void CMFC02DialogExDlg::OnSelchangeComboTeam()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialog dlg(IDD_DIALOG_APPTEAM, this);
	UpdateData(TRUE);
	int i = m_ComboTeam.GetCurSel();
	CString temp;
	/*if (i == m_ComboTeam.GetCount()-1) {
		dlg.ShowWindow(SW_SHOW);
		UpdateData(FALSE);
	}*/

	m_ComboTeam.GetLBText(i, temp);
	m_StrTeam = temp;
	UpdateData(FALSE);
}


void CMFC02DialogExDlg::OnBnClickedButtonSave()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString szTeam[4] = { _T("정규직"),_T("영업직"), _T("계약직"), _T("프리랜서") };
	UpdateData(TRUE);
	int i = m_List.GetItemCount();
	m_List.InsertItem(i, m_sEditName);
	m_List.SetItemText(i, 1, szTeam[m_radioContract]);
	m_List.SetItemText(i, 2, m_StrTeam);
	m_List.SetItemText(i, 3, m_CheckHasCar ? _T("차량 소유") : _T("차량 미소유"));
	m_List.SetItemText(i, 4, m_EditMoney);
	UpdateData(FALSE);
}
