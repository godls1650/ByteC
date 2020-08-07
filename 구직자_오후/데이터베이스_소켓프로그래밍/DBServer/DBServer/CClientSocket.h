#pragma once

// CClientSocket 명령 대상
#define WM_CLIENT_MSG_RECV	WM_USER+2
#define WM_CLIENT_CLOSE		WM_USER+3

#define WM_CLIENT_LOGON		WM_USER + 4

class CClientSocket : public CSocket
{
public:
	HWND m_hWnd;
	void SetWnd(HWND hWnd);
	CClientSocket();
	virtual ~CClientSocket();
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);
};


