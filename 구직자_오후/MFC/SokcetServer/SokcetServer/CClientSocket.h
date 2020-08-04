#pragma once

// CClientSocket 명령 대상

class CClientSocket : public CSocket
{
public:
	CAsyncSocket* m_pListenSocket;

	CClientSocket();
	virtual ~CClientSocket();
	virtual void OnClose(int nErrorCode);
//	virtual int Receive(void* lpBuf, int nBufLen, int nFlags = 0);
	virtual void OnReceive(int nErrorCode);
	void SetListenSocket(CAsyncSocket* pSocket);
};


