#pragma once

// CServerSocket 명령 대상
#define WM_ACCEPT_SOCKET	WM_USER + 1
#include "CClientSocket.h"

class CServerSocket : public CAsyncSocket
{
public:
	HWND m_hWnd;//메시지 처리용 핸들 
	CServerSocket();
	virtual ~CServerSocket();
	void SetWnd(HWND hWnd);

	virtual void OnAccept(int nErrorCode);
};


