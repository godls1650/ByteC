#include "myFileIO.h"

void OutFromFile(TCHAR filename[], HWND hWnd) {
	FILE* fPtr;
	HDC hdc = GetDC(hWnd);
	int line = 0;;
	TCHAR buffer[500];
#ifdef _UNICODE
	_tfopen_s(&fPtr, filename, _T("r , ccs = UNICODE"));
#else
	_tfopen_s(&fPtr, filename, _T("r"));
#endif
// 파일 읽기의 종료
// 읽은 내용을 출력
	while (_fgetts(buffer, 100, fPtr) != NULL) {
		if (buffer[_tcslen(buffer) - 1] == _T('\n'))
			buffer[_tcslen(buffer) - 1] = NULL;
		TextOut(hdc, 0, line * 20, buffer, _tcslen(buffer));
		line++;
	}
	fclose(fPtr);
	ReleaseDC(hWnd, hdc);
	
}