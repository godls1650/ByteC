// API_04_WinMenu.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "API_04_WinMenu.h"

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
    LoadStringW(hInstance, IDC_API04WINMENU, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_API04WINMENU));

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
//  함수: MyRegisterClass()
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_API04WINMENU));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_API04WINMENU);
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
    static int rows , idx;
    static TCHAR text[100][100];
    static SIZE size;
    
    OPENFILENAME OFN;
    OPENFILENAME SFN;

    TCHAR lpstrMsgText[100];
    TCHAR lpstrFile[100] = _T("");
    FILE* file;

    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_FILE_NEW :
                break;
            case IDM_FILE_SAVE:
                memset(lpstrMsgText, 0, sizeof(lpstrMsgText));
                memset(lpstrFile, 0, sizeof(lpstrFile));
                memset(&SFN, 0, sizeof(OPENFILENAME));
                SFN.lStructSize = sizeof(OPENFILENAME);
                SFN.lpstrFile = lpstrFile;
                SFN.hwndOwner = hWnd;
                SFN.lpstrFilter = _T("텍스트 파일\0*.txt;*.dat\0모든 파일\0*.*\0");
                SFN.nMaxFile = 256;
                SFN.lpstrInitialDir = _T(".");
                if (GetSaveFileName(&SFN) != 0) {
                    _stprintf_s(lpstrMsgText, _T("%s파일로 저장하시겠습니까?"), SFN.lpstrFile);
                    if (MessageBox(hWnd, lpstrMsgText, _T("열기선택"), MB_OKCANCEL) == IDOK) {
#ifndef _UNICODE
                        _tfopen_s(&file, SFN.lpstrFile, _T("w"));
#else
                        _tfopen_s(&file, SFN.lpstrFile, _T("w, ccs = UNICODE"));
#endif
                        if (!feof(file)) {
                            if (MessageBox(hWnd, _T("기존 내용이 있습니다. 덮어쓰시겠습니까?"), _T("저장"), MB_OKCANCEL) == IDOK) {
                                for (int i = 0; i <= rows; i++) {
                                    _fputts(text[i], file);
                                    _fputtc(_T('\n'), file);
                                }
                                
                            }
                        }
                        fclose(file);
                    }
                }

                break;
            case IDM_FILE_OPEN:
                memset(lpstrMsgText, 0, sizeof(lpstrMsgText));
                memset(lpstrFile, 0, sizeof(lpstrFile));
                rows = idx = 0;
                for (int i = 0; i < 100; i++)
                    memset(text[i], 0, sizeof(text[i]));

                memset(&OFN, 0, sizeof(OPENFILENAME));
                OFN.lStructSize = sizeof(OPENFILENAME);
                OFN.hwndOwner = hWnd;
                OFN.lpstrFilter = _T("텍스트 파일\0*.txt;*.dat\0모든 파일\0*.*\0");
                OFN.lpstrFile = lpstrFile;
                OFN.nMaxFile = 100;
                OFN.lpstrInitialDir = _T(".");
                if (GetOpenFileName(&OFN) != 0) {
                    _stprintf_s(lpstrMsgText, _T("%s파일을 열겠습니까?"), OFN.lpstrFile);
                    if (MessageBox(hWnd, lpstrMsgText, _T("열기선택"), MB_OKCANCEL) == IDOK) {
#ifndef _UNICODE
                        _tfopen_s(&file, OFN.lpstrFile, _T("r"));
#else _UNICODE
                        _tfopen_s(&file, OFN.lpstrFile, _T("r, ccs = UNICODE"));
#endif
                        if (file != nullptr) {
                            while (_fgetts(text[rows], 100, file) != NULL) {
                                if (text[rows][_tcslen(text[rows] - 2)] == _T('\n'))
                                    text[rows][_tcslen(text[rows] - 2)] = NULL;
                                rows++;
                            }
                            idx = 0;
                            fclose(file);
                            ShowCaret(hWnd);
                            InvalidateRgn(hWnd, NULL, TRUE);
                        }
                    }
                }
                break;


            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_CREATE :
        rows = idx = 0;
        CreateCaret(hWnd, NULL, 2, 16);
        ShowCaret(hWnd);
        break;
    case WM_CHAR: {
        if (wParam == VK_BACK) {
            if (idx != 0) {
                
                idx--;
            }
            else if (idx == 0 && rows != 0) {
                rows--;
                idx = _tcslen(text[rows]);
            }
        }
        else if (wParam == VK_RETURN) {
            text[rows][idx++] = NULL;
            rows++;
            idx = 0;
        }
        else if (wParam == VK_TAB) {
            for (int i = 0; i < 4; i++) {
                text[rows][idx++] = _T(' ');
            }
        }
        else {
            text[rows][idx++] = wParam;
        }

        text[rows][idx] = NULL;
        InvalidateRgn(hWnd, NULL, TRUE);
    }
        break;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            for (int i = 0; i <= rows; i++) {
                TextOut(hdc, 0, i * 16, text[i], _tcslen(text[i]));
            }
            GetTextExtentPoint(hdc, text[rows], _tcslen(text[rows]),&size);
            SetCaretPos(size.cx, rows * 16);
            
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
