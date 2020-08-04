
// MFC02_DialogExDlg.h: 헤더 파일
//

#pragma once


// CMFC02DialogExDlg 대화 상자
class CMFC02DialogExDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFC02DialogExDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC02_DIALOGEX_DIALOG };
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
	// IDC_EDIT_NAME Control Value
	CString m_sEditName;
	CButton m_EditBtn;
	afx_msg void OnClickedButtonEdit();
	CString m_EditMoney;
	int m_radioContract;
//	afx_msg void OnClickedRadioContract1();
	afx_msg void OnBnClickedRadioContract2();
	afx_msg void OnBnClickedRadioContract3();
	afx_msg void OnBnClickedRadioContract4();
	afx_msg void OnBnClickedRadioContract1();
	BOOL m_CheckHasCar;
	afx_msg void OnClickedCheckHascar();
	CComboBox m_ComboTeam;
	afx_msg void OnSelchangeComboTeam();
	CListCtrl m_List;
	afx_msg void OnBnClickedButtonSave();
	CString m_StrTeam;
};
