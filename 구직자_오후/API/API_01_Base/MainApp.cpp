#include <windows.h>
#include <tchar.h>
#include "resource.h"

/*
hInstance : ������ ���α׷� ID Kernel�� �������α׷��� �ο��� ID�� 
szCmdLine :  ��� ���ο��� ���α׷� ���� �� ������ ���ڿ� 
iCmdShow : �����쿡 ����� ����


*/

#define MAX_STRSIZE	100
WCHAR szTitle[MAX_STRSIZE];
WCHAR szClassName[MAX_STRSIZE];
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine,int iCmdShow) {
	
	LoadString(hInstance, IDS_STRING_TITLE, szTitle, MAX_STRSIZE);
	LoadString(hInstance, IDS_STRING_CLASS, szClassName, MAX_STRSIZE);

	WNDCLASSEX wcex;
	HWND hWnd;
	MSG msg;

	wcex.cbSize = sizeof(wcex);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = NULL;
	wcex.cbWndExtra = NULL;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON_MYICON));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.lpszMenuName = nullptr;
	wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wcex.lpszClassName = szClassName;
	wcex.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON_MYICON));

	RegisterClassEx(&wcex);

	hWnd = CreateWindowW(szClassName,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		0,
		0,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		nullptr,
		nullptr,
		hInstance,
		nullptr);

	ShowWindow(hWnd, iCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&msg, hWnd, NULL,NULL)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_CREATE:
		break;
	case WM_DESTROY :
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}