// CSecondDlg.cpp: 구현 파일
//

#include "pch.h"
#include "TabTester.h"
#include "CSecondDlg.h"
#include "afxdialogex.h"


// CSecondDlg 대화 상자

IMPLEMENT_DYNAMIC(CSecondDlg, CDialog)

CSecondDlg::CSecondDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CSecondDlg, pParent)
{

}

CSecondDlg::~CSecondDlg()
{
}

void CSecondDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSecondDlg, CDialog)
END_MESSAGE_MAP()


// CSecondDlg 메시지 처리기
