// API_07_MDI.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "API_07_MDI.h"
#define IDW_FIRST_CHILD    100;

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM); // Frame Window 의 프로시저 함수 
LRESULT CALLBACK    ChildWndProc(HWND, UINT, WPARAM, LPARAM); // Child Window 프로시저 함수

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
    LoadStringW(hInstance, IDC_API07MDI, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_API07MDI));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_API07MDI));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_API07MDI);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
    RegisterClassExW(&wcex); // Frame window 등록

    // 자식 윈도우 등록 
    wcex.lpfnWndProc = ChildWndProc;
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = _T("Child Class");

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
    CLIENTCREATESTRUCT ClientCreate;
    static HWND hClient;

    MDICREATESTRUCT mdiCreate;
    HWND    hChild;
    switch (message)
    {
    case WM_CREATE :
        ClientCreate.hWindowMenu =GetSubMenu(GetMenu(hWnd), 0);
        ClientCreate.idFirstChild = IDW_FIRST_CHILD;
        hClient = CreateWindow(_T("MDICLIENT"), NULL,
            WS_CHILD | WS_CLIPCHILDREN | WS_VISIBLE,
            0, 0, 0, 0, hWnd, NULL, hInst, (LPSTR)&ClientCreate);
        ShowWindow(hClient, SW_SHOW);
        return 0;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_NEWWINDOW :
                {
                    mdiCreate.szClass = _T("Child Class");
                    mdiCreate.szTitle = _T("Child Window");
                    mdiCreate.hOwner = hInst;
                    mdiCreate.x = CW_USEDEFAULT;
                    mdiCreate.y = CW_USEDEFAULT;
                    mdiCreate.cx = CW_USEDEFAULT;
                    mdiCreate.cy = CW_USEDEFAULT;
                    mdiCreate.style = NULL;
                    mdiCreate.lParam = NULL;

                    hChild = (HWND)SendMessage(hClient, WM_MDICREATE, 0,
                        (LPARAM)(LPMDICREATESTRUCT)&mdiCreate);
                    return 0;
                }
                break;
            case IDM_WINCLOSE :
                hChild = (HWND)SendMessage(hClient, WM_MDIGETACTIVE, 0, 0);
                if (SendMessage(hChild, WM_QUERYENDSESSION, 0, 0)) {
                    SendMessage(hChild, WM_DESTROY, (WPARAM)hChild, 0);
                }
                return 0;
                break;
            case IDM_TILE :SendMessage(hClient, WM_MDITILE, 0, 0);return 0;
            case IDM_CASCADE:SendMessage(hClient, WM_MDICASCADE, 0, 0); return 0;
            case IDM_ARRANGE:SendMessage(hClient, WM_MDIICONARRANGE, 0, 0); return 0;

            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefFrameProc(hWnd,hClient,message,  wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefFrameProc(hWnd, hClient, message, wParam, lParam);
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

//
LRESULT CALLBACK ChildWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    
    switch (message) {
    case WM_CREATE:
        break;
    case WM_DESTROY :
        break;
    }
    
    return DefMDIChildProc(hWnd, message, wParam, lParam);
}