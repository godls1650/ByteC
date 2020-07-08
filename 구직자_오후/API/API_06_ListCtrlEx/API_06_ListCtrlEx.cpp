// API_06_ListCtrlEx.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "API_06_ListCtrlEx.h"

#define MAX_LOADSTRING 100
#define WM_SENDMEMBER WM_USER +1

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    MemEditProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    MemAccProc(HWND, UINT, WPARAM, LPARAM);

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
    LoadStringW(hInstance, IDC_API06LISTCTRLEX, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_API06LISTCTRLEX));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_API06LISTCTRLEX));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_API06LISTCTRLEX);
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
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_MM_EDITOR :
                DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG_MBEDITOR), hWnd, MemEditProc);
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


void MakeColumn(HWND hDlg) {
    TCHAR     szColumn[3][30] = { _T("이름"), _T("나이"),_T("전화번호") };
    LVCOLUMN    lvCol = { 0, };
    HWND        hTgList; // 대상 리스트컨트롤의 핸들
    int         ColumnSize[3] = { 90, 50, 200 };

    hTgList = GetDlgItem(hDlg, IDC_LIST_MEMBER);
    lvCol.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
    //              fmt 값    칼럼의 폭    칼럼의 텍스트   칼럼의 값
    //               ㄴ 칼럼의 정렬 위치
    lvCol.fmt = LVCFMT_LEFT;

    for (int i = 0; i < 3; i++) {
        lvCol.cx = ColumnSize[i];
        lvCol.iSubItem = i;
        lvCol.pszText = szColumn[i];
        SendMessage(hTgList, LVM_INSERTCOLUMN, (WPARAM)i, (LPARAM)&lvCol);
    }
   
}

void InsertData(HWND hDlg , LPARAM lParam) {
    TCHAR Name[30], Phone[30];
    TCHAR Age[10];
    TCHAR szBuffer[100];

    LVITEM item;
    HWND hList;
    int i = 0;
    // 메시지 처리 후 데이터로 분리 
    _tcscpy_s(szBuffer, 100, (TCHAR*)lParam);
    _stscanf_s(szBuffer, _T("%s\t%s\t%s"), Name, 30, Age, 10, Phone, 30);


    hList = GetDlgItem(hDlg, IDC_LIST_MEMBER);
    i = ListView_GetItemCount(hList);

    item.mask = LVIF_TEXT;
    item.iItem = i;
    item.iSubItem = 0;
    item.pszText = Name;
    ListView_InsertItem(hList, &item);

    ListView_SetItemText(hList, i, 1, Age);
    ListView_SetItemText(hList, i, 2, Phone);

}


INT_PTR CALLBACK    MemEditProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
    //UNREFERENCED_PARAMETER(lParam);
    
    switch (message) {
    case WM_SENDMEMBER :
        InsertData(hDlg, lParam);
       
           
        break;
    case WM_INITDIALOG :
        {
        //TODO : dialog의 초기화 동작을 여기에구현
        MakeColumn(hDlg);
        }
        break;
    case WM_COMMAND:
        {
            //TODO : 명령 신호를 처리하는 동작을 여기에 구현 
            switch (LOWORD(wParam)) {
            case IDC_BUTTON_APPEND :
                DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG_ACC), hDlg, MemAccProc);
                break;
            case IDCANCEL : 
                EndDialog(hDlg, (INT_PTR)TRUE);
                break;
            }
        }
    break;

    }

    
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK    MemAccProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
    TCHAR Name[30], Phone[3][10];
    int Age;
    TCHAR * szBuffer;
    szBuffer = (TCHAR *)malloc(sizeof(TCHAR) * 100);
    int bNotInt;
    switch (message) {
    case WM_COMMAND :
        switch (LOWORD(wParam)) {
        case IDC_BUTTON_SEND:
            GetDlgItemText(hDlg, IDC_EDIT_NAME, Name, 30);
            
            Age = GetDlgItemInt(hDlg, IDC_EDIT_AGE, &bNotInt, TRUE);

            for (int i = 0; i < 3; i++) {
                GetDlgItemText(hDlg, IDC_EDIT_PH1 + i, Phone[i], 10);
            }
            _stprintf_s(szBuffer, 100,_T("%s\t%d\t%s-%s-%s"), Name, Age, Phone[0], Phone[1], Phone[2]);
           
            EndDialog(hDlg, (INT_PTR)TRUE);
            SendMessage(GetParent(hDlg), WM_SENDMEMBER, 0, (LPARAM)szBuffer);
            break;
        case IDCANCEL:
            EndDialog(hDlg, (INT_PTR)TRUE);
            break;
        }
        break;
    }
    return (INT_PTR)FALSE;
}