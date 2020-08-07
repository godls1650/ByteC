#pragma once


// CLogOnDlg 대화 상자

class CLogOnDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLogOnDlg)

public:
	CLogOnDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CLogOnDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_LOGON };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strUID;
	int m_nUPw;
	CComboBox m_cbServerNo;
	afx_msg void OnBnClickedButtonAccept();
};
