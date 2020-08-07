// LogOnDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ClientDemo.h"
#include "LogOnDlg.h"
#include "afxdialogex.h"
#include "ClientSocket.h"
#include "ClientDemoDlg.h"

#define WM_CLIENT_LOGON WM_USER + 4

// CLogOnDlg 대화 상자

IMPLEMENT_DYNAMIC(CLogOnDlg, CDialogEx)

CLogOnDlg::CLogOnDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_LOGON, pParent)
	, m_strUID(_T(""))
	, m_nUPw(NULL)
{

}

CLogOnDlg::~CLogOnDlg()
{
}

void CLogOnDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ID, m_strUID);
	DDX_Text(pDX, IDC_EDIT_PW, m_nUPw);
	DDX_Control(pDX, IDC_COMBO_SELSV, m_cbServerNo);
}


BEGIN_MESSAGE_MAP(CLogOnDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_ACCEPT, &CLogOnDlg::OnBnClickedButtonAccept)
END_MESSAGE_MAP()


// CLogOnDlg 메시지 처리기


void CLogOnDlg::OnBnClickedButtonAccept()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	CString mesForm;
	
	int serverNo = m_cbServerNo.GetCurSel();
	
	CClientDemoDlg* pMainDlg = (CClientDemoDlg*)AfxGetMainWnd();
	pMainDlg->m_ClientSocket.SetWnd(this->m_hWnd);
	pMainDlg->m_ClientSocket.Create();
	if (pMainDlg->m_ClientSocket.Connect(TESTIP, SERVER_PORT_0) == FALSE) {
		AfxMessageBox(_T("ERROR : FAILED TO CONNECT SERVER"));
		PostQuitMessage(0);
		return;
	}
	else {
		mesForm.Format(_T("%d\t%s\t%d\n"), WM_CLIENT_LOGON, m_strUID.GetString(), m_nUPw);
		

#ifdef _UNICODE
		pMainDlg->m_ClientSocket.Send(mesForm, mesForm.GetLength() * 2);
#else
		pMainDlg->m_ClientSocket.Send(mesForm, mesForm.GetLength() * 3);
#endif
	}
}
