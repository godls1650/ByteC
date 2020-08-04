// CAppendAccountDlg.cpp: 구현 파일
//

#include "pch.h"
#include "WhatISay.h"
#include "CAppendAccountDlg.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "WhatISayView.h"
#include "WhatISayDoc.h"
#include "DBConnect.h"


// CAppendAccountDlg 대화 상자

IMPLEMENT_DYNAMIC(CAppendAccountDlg, CDialogEx)

CAppendAccountDlg::CAppendAccountDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_MEMAPP, pParent)
	, m_strID(_T(""))
	, m_strPw(_T(""))
	, m_strName(_T(""))
	, m_strAddress(_T(""))
	, m_strMailAcc(_T(""))
	, m_bGender(true)
	, m_strMailDom(_T(""))
{

}

CAppendAccountDlg::~CAppendAccountDlg()
{
}

void CAppendAccountDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ID, m_strID);
	DDX_Text(pDX, IDC_EDIT_PW, m_strPw);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_ADDRESS, m_strAddress);
	DDX_Text(pDX, IDC_EDIT_MAILACC, m_strMailAcc);
	DDX_Control(pDX, IDC_COMBO_DOMAIN, m_cbDomain);
}


BEGIN_MESSAGE_MAP(CAppendAccountDlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO_DOMAIN, &CAppendAccountDlg::OnCbnSelchangeComboDomain)
	ON_BN_CLICKED(IDC_RADIO_MALE, &CAppendAccountDlg::OnBnClickedRadioMale)
	ON_BN_CLICKED(IDC_RADIO_FEMALE, &CAppendAccountDlg::OnBnClickedRadioFemale)
	ON_BN_CLICKED(IDC_BUTTON_APPEAND, &CAppendAccountDlg::OnBnClickedButtonAppeand)
END_MESSAGE_MAP()


// CAppendAccountDlg 메시지 처리기


void CAppendAccountDlg::OnCbnSelchangeComboDomain()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItemText(IDC_COMBO_DOMAIN, m_strMailDom);
}


void CAppendAccountDlg::OnBnClickedRadioMale()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_bGender = true;
}


void CAppendAccountDlg::OnBnClickedRadioFemale()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_bGender = false;
}


void CAppendAccountDlg::OnBnClickedButtonAppeand()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(true);
	CMainFrame * pFrame = (CMainFrame*)AfxGetMainWnd();
	CWhatISayView* pView = (CWhatISayView*)pFrame->GetActiveView();
	CWhatISayDoc* pDoc = pView->GetDocument();
	MYSQL_INF db = { _T("localhost"),_T("root"),_T("1234"),_T("byteproject"),3306 };
	DBConnect* pCon = new DBConnect(db, _T("member"));
	CString email;
	email.Format(_T("%s@%s"), m_strMailAcc, m_strMailDom);



	pCon->TestInsertToDB( m_strID, m_strPw, m_strName, m_strAddress, email, m_bGender ? _T("남성") : _T("여성"));

	delete pCon;
	EndDialog(0);
	/*
	CString DB_LOCATE;
	CString DB_UID;
	CString DB_UPW;
	CString DB_UNAME;
	int DB_PORT;

	//pDoc->회원목록
	// --> CWhatISayDoc:: vector<회원> 회원목록 = new vector<회원>();
	pDoc->회원목록.add(
	new 회원(
	m_strID,
	m_strPw,
	m_strName,
	m_strAddress,
	m_strMailAcc,
	m_strMailDom,
	m_bGender ? _T("남성") : _T("여성")
	));

	pDoc->멤버배열1[pDoc->현재 인덱스] = m_strID ;
	pDoc->멤버배열2[pDoc->현재 인덱스] = m_strPw;
	pDoc->멤버배열3[pDoc->현재 인덱스] = m_strName ;
	pDoc->멤버배열4[pDoc->현재 인덱스] = m_strAddress;
	pDoc->멤버배열5[pDoc->현재 인덱스] = m_strMailAcc ;
	pDoc->멤버배열6[pDoc->현재 인덱스] = m_strMailDom ;
	pDoc->멤버배열7[pDoc->현재 인덱스] = m_bGender ? _T("남성") : _T("여성");
	*/
}
