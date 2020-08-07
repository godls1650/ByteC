
// DBServer.h: PROJECT_NAME 애플리케이션에 대한 주 헤더 파일입니다.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH에 대해 이 파일을 포함하기 전에 'pch.h'를 포함합니다."
#endif

#include "resource.h"		// 주 기호입니다.
#define DB_HOST _T("localhost")
#define DB_UID	_T("root")
#define DB_UPW	_T("1234")
#define DB_SCHEMA _T("dbtest")
#define DB_PORT 3306
#define SERVER_PORT_0	21000
#define SERVER_PORT_1	21010
#define SERVER_PORT_2	21020

// CDBServerApp:
// 이 클래스의 구현에 대해서는 DBServer.cpp을(를) 참조하세요.
//

class CDBServerApp : public CWinApp
{
public:
	CDBServerApp();

// 재정의입니다.
public:
	virtual BOOL InitInstance();

// 구현입니다.

	DECLARE_MESSAGE_MAP()
};

extern CDBServerApp theApp;
