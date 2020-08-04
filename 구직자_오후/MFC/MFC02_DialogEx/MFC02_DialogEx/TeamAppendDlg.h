#pragma once


// TeamAppendDlg 대화 상자

class TeamAppendDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TeamAppendDlg)

public:
	TeamAppendDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~TeamAppendDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_APPTEAM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_EditTeam;
	afx_msg void OnBnClickedButtonSend();
};
