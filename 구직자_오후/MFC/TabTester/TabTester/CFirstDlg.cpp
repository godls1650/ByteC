// CFirstDlg.cpp: 구현 파일
//

#include "pch.h"
#include "TabTester.h"
#include "CFirstDlg.h"
#include "afxdialogex.h"


// CFirstDlg 대화 상자

IMPLEMENT_DYNAMIC(CFirstDlg, CDialog)

CFirstDlg::CFirstDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CFirstDlg, pParent)
{

}

CFirstDlg::~CFirstDlg()
{
}

void CFirstDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFirstDlg, CDialog)
END_MESSAGE_MAP()


// CFirstDlg 메시지 처리기
