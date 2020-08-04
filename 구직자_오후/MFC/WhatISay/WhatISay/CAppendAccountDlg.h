#pragma once


// CAppendAccountDlg 대화 상자

class CAppendAccountDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAppendAccountDlg)

public:
	CAppendAccountDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CAppendAccountDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MEMAPP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strID;
	CString m_strPw;
	CString m_strName;
	CString m_strAddress;
	CString m_strMailAcc;
	bool m_bGender;
	CString m_strMailDom;// 메일 도메인


	afx_msg void OnCbnSelchangeComboDomain();
	afx_msg void OnBnClickedRadioMale();
	afx_msg void OnBnClickedRadioFemale();
	CComboBox m_cbDomain;
	afx_msg void OnBnClickedButtonAppeand();
};
