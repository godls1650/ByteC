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
	1. ���� �����
	   --> ���������ġ(�ϵ��ũ)�� ������ �����ϴ� ����ü�� �̿��ؼ� 
	       ������ ������ �о�ų� ������ �������� ���
	���ϱ���ü : FILE - ��� _placeholder --> ���� �� �� ���� ������ ���� �а� �ִ� ��ġ�� ���� 
	�Ҵ� : fopen()
	��� : fprintf();
		   fscanf();
		   fputs();
		   fgets();
		   fputc(); fputch(); fputchar();
		   fgetc(); fgetch(); fgetchar();

		   -->stdin buffer or stdout buffer

	���� : fclose()
	2. ������ ������ ����ü�� ����
	3. �ǽ�
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
		�Լ��� ��ȯ�� : FILE *
		�Ű����� 1 : const char * _FileName 
		                 �� ������ �̸� : �ҽ��ڵ�� ���� ��ġ�� ���� (���� ������Ʈ ��������)
				    Root Drive����  ���� ������ �̸� ���� ��� ��� ��(���� ���)
		���� ��� => C:\\Users\\godls\\Desktop\\C���\\[����Ʈ]SW_����\\�ܼ�_C���\\Sample.txt

		��� ��� 
		��� ��λ��� "./" : ���� ����
		            "../" : ���� ����


		_Mode
		"w" : ������ ���� ��ο� ���ٸ� �� ������ ����    ���Ͽ� ����ϴ� �Լ��� ��밡��(Write)
		"r" : ������ ���� ��ο� ���ٸ� NULL�� ����      ���ϵ����͸� �о�� �Լ��� ���(Read)
		"a" : ������ ���� ��ο� ���ٸ� �� ������ ����    ���Ͽ� ����ϴ� �Լ��� ��밡��(Append)
				* "w"���� ������ "w"���� ������ ���������� �о��.
				  "a"���� ������ �� ���� ���� �о��.
		-����� [w,r,a] �� ���� ������ ������  
		      �� ����Լ��� ���� ����ϰ� �ϴ� ��� : "wt", "rt" , "at".
		-���� ���� ��� : "wb" "rb" "ab"
		"C:
		ewFolder"
	*/
	FILE* fp = NULL;
	int year, month, date;
	char memo[128] = { 0 };
	fp = fopen("C:\\Users\\godls\\Desktop\\C���\\[����Ʈ]SW_����\\�ܼ�_C���\\Sample.txt", "a");
	if (fp == NULL) { 
		printf("\a������ �������� �ʰų� �� �� �����ϴ�.\n");
		return;
	}
	
	printf("��¥�Է� > ");
	scanf("%d%*c%d%*c%d%*c", &year, &month, &date);
	fprintf(fp,"%4d�� %2d�� %2d��\n", year, month, date);
	printf("�޸𳻿�\n");
	gets(memo);
	fputs(strcat(memo,"\n"), fp);
	
	fclose(fp);
	return;
}
//C:\\Users\\godls\\Desktop\\C���\\[����Ʈ]SW_����\\�ܼ�_C���\\Sample.txt
//C:\Users\godls\Desktop\C���\[����Ʈ]SW_����\�ܼ�_C���\resource
void FILEIN() {
	FILE* fp = fopen("../../resource/BookData.txt", "r");
	char str[128] = { 0 };
	char str2[128] = { 0 };
	if (fp == NULL) {
		printf("\a������ �������� �ʰų� �� �� �����ϴ�.\n");
		return;
	}
	char c = 0;
	int line = 0;
	// ������ ���κ����� Ȯ���Ѵ�.--> feof --> ���ϰ� true -> ������ �� / false -> ������ ��X
	while (!feof(fp)) {
		c = fgetc(fp);
		if (c == '\n') line++;
	}
	printf("BookData ������ å �� �� : %d\n", line);
	/*���� Ŀ���� ��ġ�� �����ϴ� �Լ� fseek
		SEEK_SET : ������ ������
		SEEK_CUR : ����Ŀ�� �� ���� ��ġ 
		SEEK_END : ������ ������ ��ġ
	
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
			gotoXY(15, 5); printf("%-20s", "1. ��� Ȯ��");
			gotoXY(15, 6); printf("%-20s", "2. ���� �߰�");
			gotoXY(15, 7); printf("%-20s", "3. ���� �˻�");
			gotoXY(15, 8); printf("%-20s", "4. ���� ����");
			gotoXY(15, 9); printf("%-20s", "5. ���α׷� ����");
			gotoXY(x, y); printf("��");
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
	printf("%-50s%-20s%-20s%-20s\n", "������", "���ǻ�", "��  ��", "��  ��");
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