// API_03_WinMenu.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//
#define _CRT_SECURE_NO_WARNINGS
#include "framework.h"
#include "API_03_WinMenu.h"
#include <commdlg.h>
#include <stdio.h>


#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_API03WINMENU, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDR_ACCELERATOR_MY));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  함수: `gisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_API03WINMENU));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDR_MENU_MYMENU);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    OPENFILENAME OFN;
    TCHAR filter[] = _T("텍스트파일\0*.txt;*.doc\0모든 형식(*.*)\0*.*\0");
    TCHAR str[100] = _T(""), lpstrFile[100] = _T("");
    static TCHAR text[1024] = _T("");
    static FILE* fout;
    switch (message)
    {
    case WM_CREATE :
        fout =NULL;
        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            int mbId = 0;
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_FILELOAD :
                memset(&OFN, 0, sizeof(OPENFILENAME));  // OFN의 메모리를 초기화
                OFN.lStructSize = sizeof(OPENFILENAME); // OFN의 크기 변수에 크기값을 저장
                OFN.hwndOwner = hWnd;                   // 대화상자를 사용하는 윈도우의 핸들
                OFN.lpstrFilter = filter;               // 대화상자에 출력할 필터를 저장
                OFN.lpstrFile = lpstrFile;              // 선택된 파일의 이름이 저장될 변수를 지정
                OFN.nMaxFile = 100;                     // 경로 길이의 최대값 지정 
                OFN.lpstrInitialDir = _T(".."); // 대화상자가 열렸을때 가장 먼저 띄워질 폴더를 현재폴더 (./) 로 설정
                if (GetOpenFileName(&OFN) != 0) {
                    _stprintf_s(str, _T("%s 파일을 열겠습니까?"), OFN.lpstrFile);
                    if (MessageBox(hWnd, str, _T("열기"), MB_OKCANCEL) == IDOK) {
#ifdef _UNICODE
                        _tfopen_s(&fout, OFN.lpstrFile, _T("r, ccs = UNICODE"));
#else
                        _tfopen_s(&fout, str, _T("r"));
#endif
                        _fgetts(text, 1024, fout);
                       
                        fclose(fout);

                        InvalidateRgn(hWnd, NULL, TRUE);
                    }
                    
                }

                break;
            case IDM_FILENEW :
                mbId = MessageBox(hWnd, _T("저장은 하시고 끄는겁니까? "), _T("알림창"), MB_ICONQUESTION|MB_YESNO );
                if (mbId == IDYES) {
                    
                }
                else if (mbId == IDNO) {
                    while (
                        MessageBox(hWnd, _T("왜죠 ? "), _T("장난"), MB_ICONERROR | MB_OKCANCEL) != IDCANCEL);
                }
                break;
            
            case IDM_FILEEXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            if (fout != NULL) {
                TextOut(hdc, 0, 0, text, _tcslen(text));
            }

            EndPaint(hWnd, &ps);

        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
