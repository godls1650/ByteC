// CListenSocket.cpp: 구현 파일
//

#include "pch.h"
#include "SokcetServer.h"
#include "CListenSocket.h"
#include "CClientSocket.h"
#include "SokcetServerDlg.h"


// CListenSocket

CListenSocket::CListenSocket()
{
}

CListenSocket::~CListenSocket()
{
}


// CListenSocket 멤버 함수


void CListenSocket::OnAccept(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CClientSocket* pClient = new CClientSocket;
	CString szClientID; // Client 번호

	if (Accept(*pClient)) {// 클라이언트의 접속 요청
		pClient->SetListenSocket(this);
		m_pClientSocketList.AddTail(pClient); // 클라이언트 리스트 포인터에 현재 요청한 클라이언트를 추가

		CSokcetServerDlg* pMain = (CSokcetServerDlg*)AfxGetMainWnd();
		szClientID.Format(_T("Client (%d)"), (int)m_pClientSocketList.Find(pClient));
		pMain->m_plbClient->AddString(szClientID);
	}
	else {
		delete pClient;
		AfxMessageBox(_T("ERROR : Failed Can't Accept New Client"));
	}
	CAsyncSocket::OnAccept(nErrorCode);
}

void CListenSocket::CloseClientSocket(CSocket* pClient){
	POSITION pos;
	pos = m_pClientSocketList.Find(pClient);

	if (pos != NULL) {
		if (pClient != NULL) {
			pClient->ShutDown(); // 종료
			pClient->Close(); // 클라이언트를 닫는다.
		}
		// 서버 다이얼로그의 리스트에서 해당 클라이언트의 문자열을 제거
		CSokcetServerDlg* pMainDlg = (CSokcetServerDlg*)AfxGetMainWnd();
		CString str1, str2;
		UINT index = 0, PosNum;

		pMainDlg->m_plbClient->SetCurSel(0);
		while (index < pMainDlg->m_plbClient->GetCount()) {
			PosNum = (int)m_pClientSocketList.Find(pClient);
			pMainDlg->m_plbClient->GetText(index, str1);
			str2.Format(_T("%d"), PosNum);
			if (str1.Find(str2) != -1) {
				AfxMessageBox(str1 + str2);
				pMainDlg->m_plbClient->DeleteString(index);
				break;
			}
			index++;
		}

		m_pClientSocketList.RemoveAt(pos);
		delete pClient;

	}

}

void CListenSocket::SendAllMessage(TCHAR* pszMessage){
	POSITION pos;
	pos = m_pClientSocketList.GetHeadPosition();
	CClientSocket* pClient = NULL;
	int Size = 0;
#ifdef _UNICODE 
	Size = 2;
#elif 
	Size = 3;
#endif
	while (pos != NULL) {
		pClient = (CClientSocket*)m_pClientSocketList.GetNext(pos);
		if (pClient != NULL) {
			int checkLenOfMsg = pClient->Send(pszMessage, lstrlen(pszMessage) * Size);
			if (checkLenOfMsg != lstrlen(pszMessage) * Size) {
				AfxMessageBox(_T("데이터가 일부 소실, 증가 되었습니다."));
			}
		}
	
	}

}
