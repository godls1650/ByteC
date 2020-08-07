
// DBServerDlg.h: 헤더 파일
//
/*
#define WM_ACCEPT_SOCKET	WM_USER+1
#define WM_CLIENT_MSG_RECV	WM_USER+2
#define WM_CLIENT_CLOSE		WM_USER+3
*/

#pragma once
#include "CServerSocket.h"


// CDBServerDlg 대화 상자
class CDBServerDlg : public CDialogEx
{
// 생성입니다.
public:
	CDBServerDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DBSERVER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private :
	CClientSocket* m_pClientSock;
	CServerSocket* m_pServerSock;

public: // 다이얼로그 컨트롤 멤버 변수 
	CListCtrl m_listDbAcc;
	CListBox m_list_Client;
	CListBox m_list_MSG;

	CPtrList m_ptrClientList;

protected:
	afx_msg LRESULT OnAcceptSocket(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnClientMsgRecv(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnClientClose(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnClientLogon(WPARAM wParam, LPARAM lParam);
};
