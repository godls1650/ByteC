#include "framework.h"
/*	
	���� ����� (FILE ����ü ������)
	1. ���� ������ ����Ű�� ������ ��ġ�� �����Ѵ�. --> ������ ������ ���α׷����� �����´� --> ������ ����.
	2. ���� ������ ���������� �о� ���δ�.
	3. ����� ����Ǿ��� �� ������ �Ҵ� �� ������ �Ҵ��� ���� ��Ų��. --> ������ �ݴ´�.

	������ ����.  ==> fopen()�� ��� 
	                   �� fopen(const char * _Filename, const char * _Mode)
					      _Filename : �ش� C��� ���ϰ� ���� �������ִ� ������ �̸� 
						              �ٸ� ������ �ִ� ������ ��� �ϵ��ũ �̸� ������ ������ �� ������ �̸�
									                        �Ǵ� ���� ������ ��ġ���� ������ ����θ� ������ �̸� 



	������ �ݴ´�. => fclose(FILE * _Stream);  _Stream : �����ִ� ���������� 

	���� ��� -->   C:\Users\godls\Desktop\C���\[����Ʈ]C���_���ᱹ��\DataFile\BookData.txt
	��� ��� -->   
	������Ʈ ��ġ :  C:\Users\godls\Desktop\C���\[����Ʈ]C���_���ᱹ��\CProject_0518\CProject_0518\PROGRAM
	������   ��ġ :  C:\Users\godls\Desktop\C���\[����Ʈ]C���_���ᱹ��\DataFile
	��� ���     :  "../../DataFile/BookData.txt"

	_Mode : ������ ���� ���� 
	1. ���Ͽ� �����͸� ���� ���ؼ�			"w"  "wt"
	2. ������ �����͸� �б� ���ؼ�			"r"	 "rt"
	3. ���Ͽ� �����͸� �߰��ϱ� ���ؼ�		"a"	 "at"

	������ ���� --> ����
	���� -----> ���Ͽ� ��� 

	���� -----> ���Ͽ� ��� 
	fprintf()
	fputs()

	����Ŀ���� ��ġ�� �����ϴ� �Լ� : fseek(File * ,  �̵��Ÿ� , Origin);


	Origin : ����Ŀ���� ��ġ�� ��Ÿ���� ��� 
	SEEK_CUR : ���� ��ġ
	SEEK_END : �� ����
	SEEK_SET : ���� ����
	

*/
#define FILELOCATE "../../DataFile/"

typedef struct Book {
	char title[30];	// ����
	char company[30];	// ���ǻ�
	char author[30];	// ����
	int price;		// ����
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
	//book �����͸� ������ ���� ������
	book** bookList = NULL;
	book* newBook = NULL;
	int count = 0;
	/* ���α׷� �ʱ� ����   */
	//���Ͽ� å ������ ��� �ִ��� Ȯ�� 
	while (!feof(fp)) { // ���������Ͱ� ������ �������� ����Ű�� ������ �ݺ�
		if (fgetc(fp) == '\n') { // ������ �ѱ��ھ� �о��. �о �����Ͱ� \n�� ���ٸ�
			count++; // ������ ���� ��Ÿ���� ������ ����
		}
	}
	// count�� ������ �� --> å�� ���� 
	bookList = (book**)malloc(sizeof(book*) * count); // bookList --> [å����] x count�� 
	
	// ������ Ŀ���� �ٽ� �� ������ �̵� 
	fseek(fp, 0, SEEK_SET); // SEEK_SET(������ ������)���� 0��ŭ ������ ��ġ�� Ŀ���� �ű��.

	for (int i = 0; i < count; i++) {
		bookList[i] = (book*)malloc(sizeof(book)); // å ����ü ��ŭ�� �޸𸮸� �Ҵ�.
		fscanf(fp,"%[^\t]%*c %[^\t]%*c %[^\t]%*c %d", bookList[i]->title, bookList[i]->company, bookList[i]->author,
			&bookList[i]->price);
		fgetc(fp);
	}
	fclose(fp);

	int menu = 0;

	newBook = (book*)malloc(sizeof(book));


	while (1) {
		printf("1. ��� ��� 2. ��� �߰� 3. ���� \nselect > ");
		scanf("%d", &menu);
		switch (menu) {
		case 1:

			printf("�������\n");
			for (int i = 0; i < count; i++) {
				printf("%-30s\t%-10s\t%-10s\t%d��\n", bookList[i]->title, bookList[i]->company,
					bookList[i]->author, bookList[i]->price);
			}


			break;

		case 2:
			strcpy(newBook->title, "����б�");
			strcpy(newBook->company, "�˿���ġ�ڸ���");
			strcpy(newBook->author, "�����");
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

	



	// �� ������ ��Ͽ� �߰�
	
	

	
	return 0;
}

/*
strcpy(title, "���� �ڷᱸ��");
strcpy(company, "������ �̵��");
strcpy(author, "������");
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
//f._Placeholder; ���� ���ϳ����� ��ġ�� ����Ű�� ������
// type : void * _iobuf::_Placeholder

*/