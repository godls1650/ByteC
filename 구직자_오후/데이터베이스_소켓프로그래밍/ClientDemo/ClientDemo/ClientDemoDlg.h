
// ClientDemoDlg.h: 헤더 파일
//

#pragma once
#include "CLientSocket.h"
#define WM_CLIENT_RECV 		WM_USER+1
#define WM_CLIENT_MSG_RECV	WM_USER+2
#define WM_CLIENT_CLOSE		WM_USER+3


#define TESTIP _T("127.0.0.1")
#define REALIP _T("10.5.1.3")

// CClientDemoDlg 대화 상자
class CClientDemoDlg : public CDialogEx
{
// 생성입니다.
public:
	CClientDemoDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLIENTDEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
private :
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CClientSocket m_ClientSocket;
	CString m_strMsg;
	CListBox m_lbComm;
	afx_msg void OnBnClickedButtonSend();
protected:
	afx_msg LRESULT OnClientRecv(WPARAM wParam, LPARAM lParam);
};
