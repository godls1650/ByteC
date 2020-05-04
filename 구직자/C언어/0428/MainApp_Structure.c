#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


/*
	����ü�� ����� ���� ������ Ÿ�� 
	 -> �⺻ ������ Ÿ�԰� ����� ���� ������ Ÿ���� �����ϴ� ���ο� ������ ���¸� ����
	
	struct  TypeName {  
	 ���� ����
	};

	typedef : �ڷ��� ������ ��ɾ� 

	typedef struct TypeName  <����ȭ�� Ÿ���̸�>

*/
/* �Ű� */
struct Person {
	// struct Person �� ��� ���� 
	char	Name[30];
	char	Address[128];
	int		age;
	//double	eyes[2];
	//double	height;
	//double	weight;
};

typedef struct Person _person;

struct Family { // ��ø ����ü
	int count;
	_person* fam;
};

// ������ �����ؾ��Ѵ�.
// �Է��� �����ؾ��Ѵ�.
// ����� �����ؾ��Ѵ�.

void inputPerson(_person* target, const char* pName, const char* pAddress, int age);
void printPerson(_person target);
_person initPerson() { 
	_person temp = { {0},{0},0 };
	return temp; 
}
void scanPerson(_person* target);
void copyPerson(_person* target, _person source);
/*
	1. Input 2. Output  3.Edit  4.Delete  5.Insert  6. Exit (7.Save  8. Load 9.Sorting )  

*/
#define MAX_SIZE	10
int main() {
	/*
		int number = 0;
		number = 100;
		printf("%d", number);
		scanf("%d", &number);
	*/
	//struct Person p1 = initPerson();
	//_person p2 = initPerson();
	/*
	inputPerson(&p1, "���ù�", "���� ���� �빮�� ������", 29);
	inputPerson(&p2, "harry potter", "ȣ�׿�Ʈ", 10);

	printPerson(p2);
	printPerson(p1);
	*/
	_person pArr[MAX_SIZE] = { initPerson() };
	int menu = 0;
	int index = 0;
	int selIndex = 0; // �ε��� ����

	while (menu != 6) {
		printf("index count : %d\n", index);
		printf("1. Input 2. Output  3.Edit  4.Delete  5.Insert  6. Exit \n select >");
		scanf("%d%*c", &menu);
		switch (menu) {
		case 1: // �迭�� index��° �����Ϳ� �Է� �� index ����
			printf("<<input Data>>\n");
			scanPerson(pArr + index);
			index++;
			break;
		case 2:  // �迭�� index��° ���� ���� ���
			printf("<<print Data>>\n");
			for (int i = 0; i < index; i++) {
				printPerson(pArr[i]);
			}
			system("pause");
			break;
		case 3: //  selIndex��° �����͸� ����
			do{
				printf("select Edit Index > ");
				scanf("%d%*c", &selIndex);
				
				if (selIndex >= index) {
					printf("select value is over Index : 0 ~ %d\n", index - 1);
				}
			} while (selIndex >= index);
			printf("<<input Data to be Edited >>\n");
			scanPerson(pArr+ selIndex);

			break;
		case 4:  // ������ selIndex��° �����͸� �迭���� ����
			do {
				printf("select Delete Index > ");
				scanf("%d%*c", &selIndex);
				if (selIndex >= index) {
					printf("select value is over Index : 0 ~ %d\n", index - 1);
				}
			} while (selIndex >= index);

			for (int i = selIndex; i < index -1 ; i++) {
				copyPerson(pArr + i, pArr[i + 1]);
			}
			pArr[index-1] = initPerson();
			index--;
			break; 
		case 5:  // ������ �ε����� �����͸� ����
			do {
				printf("select Insert Index > ");
				scanf("%d%*c", &selIndex);
				if (selIndex >= index) {
					printf("select value is over Index : 0 ~ %d\n", index - 1);
				}
			} while (selIndex >= index);

			for (int i = index; i > selIndex; i--) {
				copyPerson(pArr + i, pArr[i - 1]);
			}
			printf("input Data to be Inserted\n");
			scanPerson(pArr + selIndex);
			index++;
			break;
		case 6: // ���α׷� ���� 
			
			break;
		}
		system("cls");
	}



	


	return 0;
}

void inputPerson(_person* target, const char * pName, const char * pAddress, int age) {
	//strcpy((*target).Name, pName);
	strcpy(target->Name, pName);
	strcpy(target->Address, pAddress);
	target->age = age;
	
}
void printPerson(_person target) {
	printf("%-20s", target.Name);
	printf("%-40s", target.Address);
	printf("%3d\n", target.age);
}

void scanPerson(_person* target) {
	char	Name[30];
	char	Address[128];
	int		age;

	printf("name > "); gets(Name);
	printf("Address > "); gets(Address);
	printf("age  > "); scanf("%d", &age);
	inputPerson(target, Name, Address, age);

}
void copyPerson(_person* target, _person source) {
	inputPerson(target, source.Name, source.Address, source.age);
	return;
}
