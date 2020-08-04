#pragma once
#include "framework.h"
#define TOCHAR(x) (LPSTR)(LPCTSTR)x

struct MYSQL_INF {
	CString DB_LOCATE;
	CString DB_UID;
	CString DB_UPW;
	CString DB_UNAME;
	int DB_PORT;
};

//template<typename ResultType>
class DBConnect{
private :
	MYSQL m_DBcon;
	MYSQL* m_pConnect;
	MYSQL_ROW row;
	MYSQL_RES * Result;
	CString Table;
public :
	DBConnect(MYSQL_INF & targetDB ,CString TableName):m_pConnect(NULL) {
		mysql_init(&m_DBcon);
		m_pConnect = mysql_real_connect(&m_DBcon,
			(LPSTR)(LPCTSTR)targetDB.DB_LOCATE , 
			(LPSTR)(LPCTSTR)targetDB.DB_UID, 
			(LPSTR)(LPCTSTR)targetDB.DB_UPW,
			(LPSTR)(LPCTSTR)targetDB.DB_UNAME,
			targetDB.DB_PORT, NULL, 0);

		Table.Format(_T("%s.%s"), targetDB.DB_UNAME, TableName);
		// "DataBase.TableName" 
		if (isDBSafeLinked(*this)) {
			AfxMessageBox(_T("DB Connect Success"), MB_OK | MB_ICONINFORMATION);
		}
	}
	~DBConnect() {
		mysql_close(m_pConnect);
	}

	void TestInsertToDB(CString id, CString pw, CString name, CString addr, CString mail, CString gender) {
		CString Query;
		Query.Format(
			_T("INSERT INTO %s VALUES('%s','%s','%s','%s','%s','%s');"),
			Table, id, pw, name, addr, mail, gender);

		mysql_query(m_pConnect, TOCHAR(Query));
		mysql_commit(m_pConnect);
	}
	

private :
	static BOOL isDBSafeLinked(DBConnect& target){
		CString form;
		form.Format(_T("DB Connection error\nError > %s"), mysql_error(&target.m_DBcon));

		if (target.m_pConnect == NULL) {
			AfxMessageBox( form
			,MB_OK|MB_ICONWARNING);
			return false;
		}
		return true;
	}
} const;

