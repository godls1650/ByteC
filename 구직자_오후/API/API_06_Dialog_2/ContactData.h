#pragma once
#include "framework.h"

typedef struct ContactData {
	TCHAR Name[30];
	TCHAR Group[50];
	TCHAR Phone[30];
}ContactData, * lpContactData;

void SetContactData(lpContactData cdData,HWND hDlg, int NameID, int GroupID, 
	int Ph1ID , int Ph2ID, int Ph3ID) {
	TCHAR ph[3][10];

	GetDlgItemText(hDlg, NameID, cdData->Name, 30);
	GetDlgItemText(hDlg, GroupID, cdData->Group, 30);
	GetDlgItemText(hDlg, Ph1ID, ph[0], 10);
	GetDlgItemText(hDlg, Ph2ID, ph[1], 10);
	GetDlgItemText(hDlg, Ph3ID, ph[2], 10);

	_stprintf_s(cdData->Phone, _T("%s-%s-%s"), ph[0], ph[1], ph[2]);

}
