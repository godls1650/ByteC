#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


/*
	구조체와 사용자 정의 데이터 타입 
	 -> 기본 데이터 타입과 사용자 정의 데이터 타입을 포함하는 새로운 데이터 형태를 구현
	
	struct  TypeName {  
	 변수 정의
	};

	typedef : 자료형 재정의 명령어 

	typedef struct TypeName  <간소화할 타입이름>

*/
/* 신검 */
struct Person {
	// struct Person 의 멤버 변수 
	char	Name[30];
	char	Address[128];
	int		age;
	//double	eyes[2];
	//double	height;
	//double	weight;
};

typedef struct Person _person;

struct Family { // 중첩 구조체
	int count;
	_person* fam;
};

// 연산이 가능해야한다.
// 입력이 가능해야한다.
// 출력이 가능해야한다.

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
	inputPerson(&p1, "남궁민", "대전 서구 용문동 언저리", 29);
	inputPerson(&p2, "harry potter", "호그와트", 10);

	printPerson(p2);
	printPerson(p1);
	*/
	_person pArr[MAX_SIZE] = { initPerson() };
	int menu = 0;
	int index = 0;
	int selIndex = 0; // 인덱스 선택

	while (menu != 6) {
		printf("index count : %d\n", index);
		printf("1. Input 2. Output  3.Edit  4.Delete  5.Insert  6. Exit \n select >");
		scanf("%d%*c", &menu);
		switch (menu) {
		case 1: // 배열의 index번째 데이터에 입력 후 index 증가
			printf("<<input Data>>\n");
			scanPerson(pArr + index);
			index++;
			break;
		case 2:  // 배열의 index번째 이전 까지 출력
			printf("<<print Data>>\n");
			for (int i = 0; i < index; i++) {
				printPerson(pArr[i]);
			}
			system("pause");
			break;
		case 3: //  selIndex번째 데이터를 수정
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
		case 4:  // 선택한 selIndex번째 데이터를 배열에서 제거
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
		case 5:  // 선택한 인덱스에 데이터를 삽입
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
		case 6: // 프로그램 종료 
			
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
