
// ControlExDlg.h: 헤더 파일
//

#pragma once


// CControlExDlg 대화 상자
class CControlExDlg : public CDialogEx
{
// 생성입니다.
public:
	CControlExDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONTROLEX_DIALOG };
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

	CEdit szEdit;
	CSpinButtonCtrl m_SpinCtrl;
	int Value;
//	afx_msg void OnDeltaposSpin2(NMHDR* pNMHDR, LRESULT* pResult);
	CString szEditText;
	CSliderCtrl m_Slider;
//	afx_msg void OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult);
	CEdit m_Edit2;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
