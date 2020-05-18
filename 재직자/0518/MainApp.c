#include "framework.h"
/*	
	파일 입출력 (FILE 구조체 포인터)
	1. 파일 내용을 가리키는 포인터 위치를 설정한다. --> 파일의 내용을 프로그램으로 가져온다 --> 파일을 연다.
	2. 열린 파일을 순차적으로 읽어 들인다.
	3. 사용이 종료되었을 때 파일을 할당 한 변수의 할당을 해제 시킨다. --> 파일을 닫는다.

	파일을 연다.  ==> fopen()을 사용 
	                   ㄴ fopen(const char * _Filename, const char * _Mode)
					      _Filename : 해당 C언어 파일과 같은 폴더에있는 파일의 이름 
						              다른 폴더에 있는 파일의 경우 하드디스크 이름 부터의 절대경로 를 포함한 이름
									                        또는 현재 폴더의 위치에서 부터의 상대경로를 포함한 이름 



	파일을 닫는다. => fclose(FILE * _Stream);  _Stream : 열려있는 파일포인터 

	절대 경로 -->   C:\Users\godls\Desktop\C언어\[바이트]C언어_저녁국비\DataFile\BookData.txt
	상대 경로 -->   
	프로젝트 위치 :  C:\Users\godls\Desktop\C언어\[바이트]C언어_저녁국비\CProject_0518\CProject_0518\PROGRAM
	파일의   위치 :  C:\Users\godls\Desktop\C언어\[바이트]C언어_저녁국비\DataFile
	상대 경로     :  "../../DataFile/BookData.txt"

	_Mode : 파일을 여는 이유 
	1. 파일에 데이터를 쓰기 위해서			"w"  "wt"
	2. 파일의 데이터를 읽기 위해서			"r"	 "rt"
	3. 파일에 데이터를 추가하기 위해서		"a"	 "at"

	파일의 내용 --> 변수
	변수 -----> 파일에 기록 

	변수 -----> 파일에 기록 
	fprintf()
	fputs()

	파일커서의 위치를 변경하는 함수 : fseek(File * ,  이동거리 , Origin);


	Origin : 파일커서의 위치를 나타내는 상수 
	SEEK_CUR : 현재 위치
	SEEK_END : 끝 지점
	SEEK_SET : 시작 지점
	

*/
#define FILELOCATE "../../DataFile/"

typedef struct Book {
	char title[30];	// 제목
	char company[30];	// 출판사
	char author[30];	// 저자
	int price;		// 가격
}book;




int main() {
	/*
	int number;
	printf("hello world\n");
	scanf("%d", &number); // stdin [100 200\n]

	fprintf(stdout, "hello world\n"); // stdin [ 200\n]
	fscanf(stdin, "%d", &number);// stdin [ \n]

	fprintf(stdout, "number %d\n", number);
	*/
	FILE * fp = fopen("../../DataFile/BookData.txt","r");
	//book 포인터를 여러개 갖는 포인터
	book** bookList = NULL;
	book* newBook = NULL;
	int count = 0;
	/* 프로그램 초기 세팅   */
	//파일에 책 정보가 몇가지 있는지 확인 
	while (!feof(fp)) { // 파일포인터가 파일의 마지막을 가리키지 않으면 반복
		if (fgetc(fp) == '\n') { // 파일을 한글자씩 읽어낸다. 읽어낸 데이터가 \n와 같다면
			count++; // 데이터 수를 나타내는 변수를 증가
		}
	}
	// count는 문장의 수 --> 책의 갯수 
	bookList = (book**)malloc(sizeof(book*) * count); // bookList --> [책정보] x count개 
	
	// 파일의 커서를 다시 맨 앞으로 이동 
	fseek(fp, 0, SEEK_SET); // SEEK_SET(파일의 시작점)부터 0만큼 떨어진 위치로 커서를 옮긴다.

	for (int i = 0; i < count; i++) {
		bookList[i] = (book*)malloc(sizeof(book)); // 책 구조체 만큼의 메모리를 할당.
		fscanf(fp,"%[^\t]%*c %[^\t]%*c %[^\t]%*c %d", bookList[i]->title, bookList[i]->company, bookList[i]->author,
			&bookList[i]->price);
		fgetc(fp);
	}
	fclose(fp);

	int menu = 0;

	newBook = (book*)malloc(sizeof(book));


	while (1) {
		printf("1. 목록 출력 2. 목록 추가 3. 종료 \nselect > ");
		scanf("%d", &menu);
		switch (menu) {
		case 1:

			printf("도서목록\n");
			for (int i = 0; i < count; i++) {
				printf("%-30s\t%-10s\t%-10s\t%d원\n", bookList[i]->title, bookList[i]->company,
					bookList[i]->author, bookList[i]->price);
			}


			break;

		case 2:
			strcpy(newBook->title, "퇴사학교");
			strcpy(newBook->company, "알에이치코리아");
			strcpy(newBook->author, "장수한");
			newBook->price = 10000;

			count++;
			bookList = (book**)realloc(bookList, sizeof(book*) * count);
			bookList[count - 1] = newBook;

			fp = fopen("../../DataFile/BookData.txt", "w");

			for (int i = 0; i < count; i++) {
				fprintf(fp, "%s\t%s\t%s\t%d\n", bookList[i]->title, bookList[i]->company,
					bookList[i]->author, bookList[i]->price);
			}
			fclose(fp);
			break;
		case 3:


			return 0;

		}
	}

	



	// 새 도서를 목록에 추가
	
	

	
	return 0;
}

/*
strcpy(title, "열혈 자료구조");
strcpy(company, "오렌지 미디어");
strcpy(author, "윤성우");
price = 27000;

//fprintf(fp,"%s\t%s\t%s\t%d\n", title, company, author, price);
int count = 0;
while (!feof(fp)) {
	if(fgetc(fp) == '\n') count++;
}
printf("count : %d\n",count);

fseek(fp, 0, SEEK_SET);

for (int i = 0; i < count; i++) {
	fscanf(fp, "%[^\t]%*c %[^\t]%*c%[^\t]%*c%d%*c", title[i], company[i], author[i], &price[i]);
	printf("%s\t%s\t%s\t%d\n", title[i], company[i], author[i], price[i]);
}
//printf("%s\t%s\t%s\t%d\n", title[0], company[1], author[0], price[1]);
fclose(fp);
//f._Placeholder; 현재 파일내용의 위치를 가리키는 포인터
// type : void * _iobuf::_Placeholder

*/