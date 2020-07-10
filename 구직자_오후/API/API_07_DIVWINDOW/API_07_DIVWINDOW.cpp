// API_07_DIVWINDOW.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "API_07_DIVWINDOW.h"
#define IDC_USER    500
#define IDC_BUTTON_SEND     IDC_USER + 1
#define IDC_EDIT_TYPO     IDC_USER + 2
#define IDC_EDIT_OUT      IDC_USER + 3
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
LRESULT CALLBACK    ChildWndProc(HWND, UINT, WPARAM, LPARAM); // Child Window 프로시저 함수


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
    LoadStringW(hInstance, IDC_API07DIVWINDOW, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_API07DIVWINDOW));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_API07DIVWINDOW));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_API07DIVWINDOW);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
    RegisterClassExW(&wcex); // Frame window 등록

   // 자식 윈도우 등록 
    wcex.lpfnWndProc = ChildWndProc;
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = _T("Child Window ClassName");

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
    static HWND hChild[3];
    RECT rectView;
    TCHAR str[100];
    

    switch (message)
    {

    case WM_CREATE :
        
        _stprintf_s(str, _T("ID : %u"), (UINT_PTR)IDC_BUTTON_SEND);
        MessageBox(hWnd, str, 0, 0);
        GetClientRect(hWnd, &rectView);
        hChild[0] = CreateWindowEx(WS_EX_CLIENTEDGE, _T("Child Window ClassName"),
            NULL, WS_CHILD | WS_VISIBLE, 0, 0, rectView.right *0.2, rectView.bottom,
            hWnd, NULL, hInst, NULL);
        
        hChild[1] = CreateWindowEx(WS_EX_CLIENTEDGE, _T("Child Window ClassName"),
            NULL, WS_CHILD | WS_VISIBLE, rectView.right * 0.2, 0, rectView.right, rectView.bottom / 2-1,
            hWnd, NULL, hInst, NULL);

        hChild[2] = CreateWindowEx(WS_EX_CLIENTEDGE, _T("Child Window ClassName"),
            NULL, WS_CHILD | WS_VISIBLE, rectView.right * 0.2, rectView.bottom / 2 + 1, rectView.right, rectView.bottom / 2 - 1,
            hWnd, NULL, hInst, NULL);

        return 0;

    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDC_BUTTON_SEND:
                
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
//
LRESULT CALLBACK ChildWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    static HWND hBtnSend, hEditTypo, hEditOut;
    static TCHAR str[100];
    switch (message) {
    case WM_CREATE:
        hBtnSend = CreateWindow(_T("button"), _T("전송"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON 
            , 10, 10, 210, 60,hWnd,(HMENU)IDC_BUTTON_SEND, hInst, NULL);
        
        hEditTypo = CreateWindow(_T("edit"), _T(""), WS_CHILD | WS_VISIBLE | WS_BORDER,
            220, 10, 400, 60, hWnd, (HMENU)IDC_EDIT_TYPO, hInst, NULL);
        hEditOut = CreateWindow(_T("edit"), _T(""), WS_CHILD | WS_VISIBLE | WS_BORDER,
            220, 70, 400, 130, hWnd, (HMENU)IDC_EDIT_OUT, hInst, NULL);
        
        break;
  
    case WM_COMMAND :
        switch (LOWORD(wParam)) {
        case IDC_BUTTON_SEND :
            GetDlgItemText(hWnd,IDC_EDIT_TYPO, str, 100);
            SetDlgItemText(hWnd, IDC_EDIT_OUT, str);
            MessageBox(hWnd, str, 0, 0);
            SetDlgItemText(hWnd, IDC_EDIT_TYPO, _T(""));
            break;
        }
        break;
    
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }

    return DefWindowProc(hWnd, message, wParam, lParam);
}