#include "framework.h"
#include "BookInfo.h"
#include <windows.h>
#include <conio.h>
#define UP		72
#define DOWN	80
#define LEFT	75
#define RIGHT	77
#define WS		32
/*
	1. 파일 입출력
	   --> 보조기억장치(하드디스크)의 파일을 저장하는 구조체를 이용해서 
	       파일의 내용을 읽어내거나 파일의 내용으로 출력
	파일구조체 : FILE - 멤버 _placeholder --> 저장 중 인 파일 내용의 현재 읽고 있는 위치를 저장 
	할당 : fopen()
	사용 : fprintf();
		   fscanf();
		   fputs();
		   fgets();
		   fputc(); fputch(); fputchar();
		   fgetc(); fgetch(); fgetchar();

		   -->stdin buffer or stdout buffer

	해제 : fclose()
	2. 파일의 내용을 구조체에 전달
	3. 실습
*/
void FILEOUT();
void FILEIN();
book** setupProgram(const char* filename, int count);
void viewList(const book** Blist, int count);
int Program();

HANDLE mhandle;
COORD pos;

void gotoXY(int x, int y);

int main() {return Program();}




void FILEOUT() {
	/*	fopen
		함수의 반환값 : FILE *
		매개변수 1 : const char * _FileName 
		                 ㄴ 파일의 이름 : 소스코드와 같은 위치의 파일 (현재 프로젝트 폴더내부)
				    Root Drive부터  읽을 파일의 이름 까지 모든 경로 값(절대 경로)
		절대 경로 => C:\\Users\\godls\\Desktop\\C언어\\[바이트]SW_오후\\콘솔_C언어\\Sample.txt

		상대 경로 
		상대 경로상의 "./" : 현재 폴더
		            "../" : 상위 폴더


		_Mode
		"w" : 파일이 현재 경로에 없다면 새 파일을 생성    파일에 출력하는 함수만 사용가능(Write)
		"r" : 파일이 현재 경로에 없다면 NULL을 리턴      파일데이터를 읽어내는 함수만 사용(Read)
		"a" : 파일이 현재 경로에 없다면 새 파일을 생성    파일에 출력하는 함수만 사용가능(Append)
				* "w"모드와 차이점 "w"모드는 파일의 시작점부터 읽어낸다.
				  "a"모드는 파일의 끝 지점 부터 읽어낸다.
		-기반은 [w,r,a] 의 모드로 파일을 열지만  
		      입 출력함수를 전부 사용하게 하는 모드 : "wt", "rt" , "at".
		-이진 파일 모드 : "wb" "rb" "ab"
		"C:
		ewFolder"
	*/
	FILE* fp = NULL;
	int year, month, date;
	char memo[128] = { 0 };
	fp = fopen("C:\\Users\\godls\\Desktop\\C언어\\[바이트]SW_오후\\콘솔_C언어\\Sample.txt", "a");
	if (fp == NULL) { 
		printf("\a파일이 존재하지 않거나 열 수 없습니다.\n");
		return;
	}
	
	printf("날짜입력 > ");
	scanf("%d%*c%d%*c%d%*c", &year, &month, &date);
	fprintf(fp,"%4d년 %2d월 %2d일\n", year, month, date);
	printf("메모내용\n");
	gets(memo);
	fputs(strcat(memo,"\n"), fp);
	
	fclose(fp);
	return;
}
//C:\\Users\\godls\\Desktop\\C언어\\[바이트]SW_오후\\콘솔_C언어\\Sample.txt
//C:\Users\godls\Desktop\C언어\[바이트]SW_오후\콘솔_C언어\resource
void FILEIN() {
	FILE* fp = fopen("../../resource/BookData.txt", "r");
	char str[128] = { 0 };
	char str2[128] = { 0 };
	if (fp == NULL) {
		printf("\a파일이 존재하지 않거나 열 수 없습니다.\n");
		return;
	}
	char c = 0;
	int line = 0;
	// 파일의 끝부분인지 확인한다.--> feof --> 리턴값 true -> 파일의 끝 / false -> 파일의 끝X
	while (!feof(fp)) {
		c = fgetc(fp);
		if (c == '\n') line++;
	}
	printf("BookData 파일의 책 권 수 : %d\n", line);
	/*파일 커서의 위치를 변경하는 함수 fseek
		SEEK_SET : 파일의 시작점
		SEEK_CUR : 파일커서 의 현재 위치 
		SEEK_END : 파일의 마지막 위치
	
	*/
	fseek(fp, 0, SEEK_SET);

	fscanf(fp, "%[^\t]%*c", str); 
	fscanf(fp, "%[^\t]", str2); fseek(fp, 1, SEEK_CUR);
	puts(str);
	puts(str2);
	fclose(fp);
}
int Program() {
	////setup Program//////
	mhandle = GetStdHandle(STD_OUTPUT_HANDLE);
	

	const char* filename = "../../resource/BookData.txt";
	int count = countLines(filename);
	book** Blist = setupProgram(filename, count);
	int menu = 1;
	int bShutDown = 0;
	int c = 0;
	int x =0, y = 0;

	////using this Program/////
	while (!bShutDown) {
		x = 35;  y = 5;
		while (c != WS) {
			gotoXY(15, 5); printf("%-20s", "1. 목록 확인");
			gotoXY(15, 6); printf("%-20s", "2. 도서 추가");
			gotoXY(15, 7); printf("%-20s", "3. 도서 검색");
			gotoXY(15, 8); printf("%-20s", "4. 파일 갱신");
			gotoXY(15, 9); printf("%-20s", "5. 프로그램 종료");
			gotoXY(x, y); printf("◀");
			c = _getch();
			if (c == 224)
				c = _getch();
			if (c == UP) {
				gotoXY(x, y); printf("  ");
				y = (y-1)%5 + 5;
				menu = menu == 0? 5 : menu -1;
				
			}
			else if (c == DOWN) {
				gotoXY(x, y); printf("  ");
				y = (y+1)%5 + 5;
				menu = (y + 1) % 5;

			}
			
		}
	
	
		//gotoXY(15,10);printf("select menu > ");
		//scanf("%d", &menu);
		system("cls");
		switch (menu) {
		case 1: viewList(Blist, count); break;
		case 2: viewList(Blist, count); break;
		case 3: viewList(Blist, count); break;
		case 5: bShutDown = 1;  case 4: viewList(Blist, count); break;
		}
		c = 0;
		system("cls");
	}
	//Memory Distroy

	return 0 ;
}

book** setupProgram(const char * filename, int count) {
	book** Blist = NULL;

	Blist = (book**)calloc(count, sizeof(book*));

	for (int i = 0; i < count; i++) {
		Blist[i] = initBook();
		LoadFile(filename, Blist[i], count);
	}
	return Blist;
}

void viewList(const book ** Blist, int count) {
	printf("%-50s%-20s%-20s%-20s\n", "도서명", "출판사", "저  자", "금  액");
	for (int i = 0; i < count; i++) {
		viewBook(Blist[i]);
	}
	system("pause");
}

void gotoXY(int x, int y) {
	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(mhandle, pos);
}