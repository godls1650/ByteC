#pragma once
#include <afxcview.h>

// CLeftTView 보기

class CLeftTView : public CTreeView
{
	DECLARE_DYNCREATE(CLeftTView)

protected:
	CLeftTView();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CLeftTView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
};


