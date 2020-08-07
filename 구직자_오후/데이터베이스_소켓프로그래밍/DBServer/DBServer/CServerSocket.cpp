// CServerSocket.cpp: 구현 파일
//

#include "pch.h"
#include "DBServer.h"
#include "CServerSocket.h"


// CServerSocket

CServerSocket::CServerSocket()
{
}

CServerSocket::~CServerSocket()
{
}


// CServerSocket 멤버 함수


void CServerSocket::OnAccept(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CClientSocket* pClient = new CClientSocket;// Client 소켓 포인터
	if (Accept(*pClient)) { // 클라이언트의 접속을 확인
		pClient->SetWnd(m_hWnd);
	}
	else {
		delete pClient;
	}
	// Client List 에 Client(13631421)를 추가 
	SendMessage(m_hWnd, WM_ACCEPT_SOCKET, 0, (LPARAM)pClient);
	CAsyncSocket::OnAccept(nErrorCode);
}

void CServerSocket::SetWnd(HWND hWnd) { m_hWnd = hWnd; }