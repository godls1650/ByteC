
// MFC_BALLBoundView.h: CMFCBALLBoundView 클래스의 인터페이스
//

#pragma once


class CMFCBALLBoundView : public CView
{
protected: // serialization에서만 만들어집니다.
	CMFCBALLBoundView() noexcept;
	DECLARE_DYNCREATE(CMFCBALLBoundView)

// 특성입니다.
public:
	CMFCBALLBoundDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMFCBALLBoundView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
};

#ifndef _DEBUG  // MFC_BALLBoundView.cpp의 디버그 버전
inline CMFCBALLBoundDoc* CMFCBALLBoundView::GetDocument() const
   { return reinterpret_cast<CMFCBALLBoundDoc*>(m_pDocument); }
#endif

