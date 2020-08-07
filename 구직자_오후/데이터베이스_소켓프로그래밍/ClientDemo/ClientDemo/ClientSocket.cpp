// ClientSocket.cpp: 구현 파일
//

#include "pch.h"
#include "ClientDemo.h"
#include "ClientSocket.h"


// CClientSocket

void CClientSocket::SetWnd(HWND hWnd)
{
	m_hWnd = hWnd;
}

CClientSocket::CClientSocket()
{
}

CClientSocket::~CClientSocket()
{
}


// CClientSocket 멤버 함수


void CClientSocket::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	TCHAR szBuffer[1024];
	ZeroMemory(szBuffer, sizeof(szBuffer));
	if (Receive(szBuffer, sizeof(szBuffer)) > 0) {
		SendMessage(m_hWnd, WM_CLIENT_RECV, NULL, (LPARAM)szBuffer);
	}
	CSocket::OnReceive(nErrorCode);
}


void CClientSocket::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	ShutDown(); Close();
	CSocket::OnClose(nErrorCode);
}
