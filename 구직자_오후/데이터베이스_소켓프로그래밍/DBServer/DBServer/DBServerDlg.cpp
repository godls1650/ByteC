
// DBServerDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "DBServer.h"
#include "DBServerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
//	afx_msg LRESULT OnClientMsgRecv(WPARAM wParam, LPARAM lParam);
//	afx_msg LRESULT OnClientClose(WPARAM wParam, LPARAM lParam);
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
//	ON_MESSAGE(WM_CLIENT_MSG_RECV, &CAboutDlg::OnClientMsgRecv)
//	ON_MESSAGE(WM_CLIENT_CLOSE, &CAboutDlg::OnClientClose)
END_MESSAGE_MAP()


// CDBServerDlg 대화 상자



CDBServerDlg::CDBServerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DBSERVER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDBServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_DBLIST, m_listDbAcc);
	DDX_Control(pDX, IDC_LIST_CLILIST, m_list_Client);
	DDX_Control(pDX, IDC_LIST_CLIMSG, m_list_MSG);
}

BEGIN_MESSAGE_MAP(CDBServerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_ACCEPT_SOCKET, &CDBServerDlg::OnAcceptSocket)
	ON_MESSAGE(WM_CLIENT_MSG_RECV, &CDBServerDlg::OnClientMsgRecv)
	ON_MESSAGE(WM_CLIENT_CLOSE, &CDBServerDlg::OnClientClose)
	ON_MESSAGE(WM_CLIENT_LOGON, &CDBServerDlg::OnClientLogon)
END_MESSAGE_MAP()


// CDBServerDlg 메시지 처리기

BOOL CDBServerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	CRect rect;
	m_listDbAcc.GetClientRect(rect);
	m_listDbAcc.InsertColumn(0, _T("사용자ID"), LVCFMT_CENTER, rect.Width() * 0.33);
	m_listDbAcc.InsertColumn(1, _T("사용자PW"), LVCFMT_CENTER, rect.Width() * 0.33);
	m_listDbAcc.InsertColumn(2, _T("닉 네 임"), LVCFMT_CENTER, rect.Width()*0.33 );

	//DB_CONNECT 
	MYSQL conn;
	CString szConnectMsg;
	const CString db_TableName = _T("user_account");
	CString Query;
	MYSQL_RES * sqlResult;
	MYSQL_ROW sqlRow;
	mysql_init(&conn);
	
	if (mysql_real_connect(&conn, DB_HOST, DB_UID, DB_UPW, DB_SCHEMA, DB_PORT, NULL, 0) == NULL) {
		szConnectMsg.Format(_T("ERROR : DB CONNECT IS FAIL"));
		AfxMessageBox(szConnectMsg);
		TRACE(szConnectMsg);
		return FALSE;
	}
	else {
		//mysql_query(&conn, _T("set names euckr"));
	}

	Query.Format(_T("SELECT * FROM %s.%s;"),DB_SCHEMA,db_TableName);
	//int status = 0; 
	if (mysql_query(&conn, Query) != 0) {
		szConnectMsg.Format(_T("ERROR(%d) : Query is Failed\nSEND>\n%s\nQUERY>\n"),
			mysql_errno(&conn),Query,mysql_error(&conn));
		AfxMessageBox(szConnectMsg);
		TRACE(szConnectMsg);
		return FALSE;
	}
	sqlResult = mysql_store_result(&conn);
	
	int row = 0;
	while ((sqlRow = mysql_fetch_row(sqlResult)) != NULL) {
		m_listDbAcc.InsertItem(row,sqlRow[0]);
		m_listDbAcc.SetItemText(row, 1, sqlRow[1]);
		m_listDbAcc.SetItemText(row, 2, sqlRow[2]);
		row++;
	}

	m_pServerSock = new CServerSocket;
	m_pServerSock->SetWnd(this->m_hWnd);
	m_pServerSock->Create(SERVER_PORT_0);
	m_pServerSock->Listen();

	mysql_free_result(sqlResult);
	mysql_close(&conn);
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CDBServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CDBServerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CDBServerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



afx_msg LRESULT CDBServerDlg::OnAcceptSocket(WPARAM wParam, LPARAM lParam)
{
	CString str;
	m_pClientSock = (CClientSocket*)lParam;
	m_ptrClientList.AddTail(m_pClientSock);

	str.Format(_T("Client (%d)"), int(m_pClientSock));
	m_list_Client.InsertString(-1, str);
	
	m_pClientSock = NULL;
	delete m_pClientSock;
	return 0;
}



afx_msg LRESULT CDBServerDlg::OnClientMsgRecv(WPARAM wParam, LPARAM lParam)
{
	CString message = (LPCSTR)lParam;

	POSITION pos = m_ptrClientList.GetHeadPosition();
	while (pos != NULL) {
		CClientSocket* pClient = (CClientSocket*)m_ptrClientList.GetNext(pos);
		if (pClient != NULL) {
#ifdef _UNICODE
			pClient->Send(message, message.GetLength() * 2);
#else
			pClient->Send(message, message.GetLength() * 3);
#endif
		}
	}
	m_list_MSG.InsertString(-1, message);
	m_list_MSG.SetCurSel(m_list_MSG.GetCurSel() - 1);

	return 0;
}


afx_msg LRESULT CDBServerDlg::OnClientClose(WPARAM wParam, LPARAM lParam)
{
	CClientSocket* pClient = (CClientSocket*)lParam;
	CString str;
	UINT idx = 0;
	POSITION pos = m_ptrClientList.Find(pClient);

	if (pos != NULL) {
		str.Format(_T("Client (%d)"), (int)pClient);
		idx = m_list_Client.SelectString(-1, str);
		m_list_Client.DeleteString(idx);

		m_ptrClientList.RemoveAt(pos);

	}
	return 0;
}


afx_msg LRESULT CDBServerDlg::OnClientLogon(WPARAM wParam, LPARAM lParam)
{	
	CString UID;
	int UPW = 0;
	//"ID    PW"
	LPCTSTR Msg = (LPCTSTR)lParam;
	
	_stscanf_s(Msg, _T("%[^\t]%*c%d"), UID ,1024,&UPW);
	CString form;
	CTime currTime = CTime::GetCurrentTime();

	form.Format(_T("[%d-%02d-%02d %02d:%02d:%02d]::ID <%s> PW <%d> 가 로그인을 시도했습니다."),
		currTime.GetYear(), currTime.GetMonth(), currTime.GetDay(),
		currTime.GetHour(), currTime.GetMinute(), currTime.GetSecond(),
		UID, UPW
		);

	m_list_MSG.InsertString(-1,form);
	m_list_MSG.SetCurSel(m_list_MSG.GetCurSel() - 1);


	return 0;
}
