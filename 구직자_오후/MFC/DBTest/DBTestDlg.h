
// DBTestDlg.h: 헤더 파일
//

#pragma once


// CDBTestDlg 대화 상자
class CDBTestDlg : public CDialogEx
{
// 생성입니다.
public:
	CDBTestDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DBTEST_DIALOG };
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
public:
	CListCtrl m_listData;
	CEdit m_EditMemNo;
	CString m_szName;
	CString m_szMemNo;
	CString m_szAddress;
	CString m_ph1;
	CString m_szPh2;
	CString m_szPh3;
	afx_msg void OnClickedButtonEdit();
	afx_msg void OnClickedButtonDel();
	afx_msg void OnClickedButtonAppend();
};
