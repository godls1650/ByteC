// TeamAppendDlg.cpp: 구현 파일
//

#include "pch.h"
#include "MFC02_DialogEx.h"
#include "TeamAppendDlg.h"
#include "afxdialogex.h"


// TeamAppendDlg 대화 상자

IMPLEMENT_DYNAMIC(TeamAppendDlg, CDialogEx)

TeamAppendDlg::TeamAppendDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_APPTEAM, pParent)
	, m_EditTeam(_T(""))
{

}

TeamAppendDlg::~TeamAppendDlg()
{
}

void TeamAppendDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TEAM, m_EditTeam);
}


BEGIN_MESSAGE_MAP(TeamAppendDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SEND, &TeamAppendDlg::OnBnClickedButtonSend)
END_MESSAGE_MAP()


// TeamAppendDlg 메시지 처리기


void TeamAppendDlg::OnBnClickedButtonSend()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AfxMessageBox(_T("???"));
	CDialog* pParent = (CDialog *)GetParent();
	CComboBox* pCombo = (CComboBox *)pParent->GetDlgItem(IDC_COMBO_TEAM);
	
	int index = pCombo->GetCount() - 1;
	UpdateData(TRUE);
	CString temp = m_EditTeam.GetString();
	
	pCombo->InsertString(index, temp);
	pCombo->GetLBText(index,temp);
	
}
