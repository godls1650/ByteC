#pragma once

// CClientSocket 명령 대상
#define WM_CLIENT_RECV WM_USER + 1

class CClientSocket : public CSocket
{
public:
	void SetWnd(HWND hWnd);
	HWND m_hWnd;
	CClientSocket();
	virtual ~CClientSocket();
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);
};


