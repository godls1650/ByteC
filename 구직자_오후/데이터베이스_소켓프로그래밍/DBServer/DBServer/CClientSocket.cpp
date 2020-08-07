// CClientSocket.cpp: 구현 파일
//

#include "pch.h"
#include "DBServer.h"
#include "CClientSocket.h"

#define BUFSIZE	1024

// CClientSocket

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
	CString strTemp(_T("")), strIPAddress(_T(""));
	UINT uPortNumber(0);
	TCHAR strBuffer[BUFSIZE];
	ZeroMemory(strBuffer, sizeof(TCHAR)*BUFSIZE);
	int MSGCode = 0;
	CString MSGItem = _T("");

	GetPeerName(strIPAddress, uPortNumber);
	if (Receive(strBuffer, sizeof(strBuffer)) > 0) { // Receive로 받아온 메시지의 길이가 0보다 큰경우
		// 클라이언트에서 받아온 메시지를 
		// 분해해서 용도와 값으로 나눈다.

		// 용도에 따라서 Server내에서 사용할 메시지(LPARAM으로 전달할 값) 을 각각 가공한다.
		_stscanf_s(strBuffer, _T("%d\t%[^\n]"), &MSGCode, MSGItem,1024);
		/*
		switch (MSGCode) {
		case WM_CLIENT_LOGON :
			SendMessage(m_hWnd, WM_CLIENT_LOGON, NULL, (LPARAM)(LPCTSTR)MSGItem);
			break;
		case WM_CLIENT_MSG_RECV :
			strTemp.Format(_T("[%s : %d] : %s"), strIPAddress, uPortNumber, strBuffer);
			SendMessage(m_hWnd, WM_CLIENT_MSG_RECV, NULL, (LPARAM)(LPCTSTR)MSGItem);
			break;
		}
		*/
		SendMessage(m_hWnd, MSGCode, NULL, (LPARAM)(LPCTSTR)MSGItem);
	}

	CSocket::OnReceive(nErrorCode);
}


void CClientSocket::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	SendMessage(m_hWnd, WM_CLIENT_CLOSE, 0, (LPARAM)this);
	CSocket::OnClose(nErrorCode);
}

void CClientSocket::SetWnd(HWND hWnd) { m_hWnd = hWnd; }