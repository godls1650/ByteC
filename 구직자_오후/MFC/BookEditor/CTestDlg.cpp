
// CTestDlg.cpp: 구현 파일
//

#include "pch.h"
#include "BookEditor.h"
#include "CTestDlg.h"
#include "afxdialogex.h"


// CTestDlg 대화 상자

IMPLEMENT_DYNAMIC(CTestDlg, CDialogEx)

CTestDlg::CTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_TEST, pParent)
{

}

CTestDlg::~CTestDlg()
{
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTestDlg, CDialogEx)
END_MESSAGE_MAP()


// CTestDlg 메시지 처리기


//void CTestDlg::OnBnClickedCancel()
//{
//	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
//	DestroyWindow();
//	//CDialogEx::OnCancel();
//}


//void CTestDlg::OnNcDestroy()
//{
//	//CDialogEx::OnNcDestroy();
//
//	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
//	delete this;
//}
