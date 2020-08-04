// CClientSocket.cpp: 구현 파일
//

#include "pch.h"
#include "SokcetServer.h"
#include "CClientSocket.h"
#include "SokcetServerDlg.h"
#include "CListenSocket.h"


// CClientSocket

CClientSocket::CClientSocket()
{
}

CClientSocket::~CClientSocket()
{
}


// CClientSocket 멤버 함수


void CClientSocket::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CSocket::OnClose(nErrorCode);

	CListenSocket* pServerSocket = (CListenSocket*)m_pListenSocket;
	pServerSocket->CloseClientSocket(this);
}



void CClientSocket::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CString strTemp(_T("")), strIPAddress(_T(""));
	UINT uPortNumber(0);
	TCHAR strBuffer[1024];
	ZeroMemory(strBuffer, sizeof(strBuffer));
	int CODE = 0;
	CSokcetServerDlg* pMain = (CSokcetServerDlg*)AfxGetMainWnd();
	CListenSocket* pServerSocket = (CListenSocket*)m_pListenSocket;
	CString message;
	CString test;

	GetPeerName(strIPAddress, uPortNumber);// 192.168.0.11:7272
	if (Receive(strBuffer, sizeof(strBuffer)) > 0) { // 전달된 값이 있다면
		//AfxMessageBox(strBuffer);
		_stscanf_s(strBuffer, _T("%d%*c%s"), &CODE, message, 1024);
		test.Format(_T("CODE : %d\nMSG  : %s"), CODE, message);
		//AfxMessageBox(test);
		switch (CODE) {
		case 0 :
			strTemp.Format(_T("--------<<%s 님이 입장했습니다.>>--------"), message);
			AfxMessageBox(strTemp);
			break;
		case 1 :
			strTemp.Format(_T("%s(%d) : %s"), strIPAddress, uPortNumber, message);
			pMain->m_lbMsg.AddString(strTemp);
			pMain->m_lbMsg.SetCurSel(pMain->m_lbMsg.GetCount() - 1);
			pServerSocket->SendAllMessage((TCHAR*)(LPCTSTR)strTemp);
			break;
		}
		
		
		

	}

	CSocket::OnReceive(nErrorCode);
}

void CClientSocket::SetListenSocket(CAsyncSocket* pSocket)
{
	m_pListenSocket = pSocket;
}
