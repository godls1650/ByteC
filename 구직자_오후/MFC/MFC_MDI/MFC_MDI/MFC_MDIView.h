
// MFC_MDIView.h: CMFCMDIView 클래스의 인터페이스
//

#pragma once


class CMFCMDIView : public CListView
{
protected: // serialization에서만 만들어집니다.
	CMFCMDIView() noexcept;
	DECLARE_DYNCREATE(CMFCMDIView)

// 특성입니다.
public:
	CMFCMDIDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~CMFCMDIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC_MDIView.cpp의 디버그 버전
inline CMFCMDIDoc* CMFCMDIView::GetDocument() const
   { return reinterpret_cast<CMFCMDIDoc*>(m_pDocument); }
#endif

