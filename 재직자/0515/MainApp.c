#include "framework.h"

/*
	기본 데이터 타입
	 - 정수, 문자, 실수, 없음
	 - 포인터

	사용자 정의 데이터 타입
	 - 구조체 (struct) : 필요한 각각의 정보를 나열해서 새로운 타입을 지정
			--> 정수 x2 float x1  --> 12byte

	 - 공용체 (union)  : 하나의 공간을 공유하는 변수를 여러개 지정
			--> 정수 x2 float x1  --> 4byte
	 - 열거형 (enum)
	  <회원 정보>
	문자열    이름
	숫자	      나이
	숫자 배열 연락처

	 사용자 정의 타입의 형태를 정의 --> 전역공간

	 사용자가 데이터 타입을 만들 수 있다.
	 사용자가 메모리 할당을 자유롭게 할 수 있다.
	 사용자가 동작을 구현할 수 있다.

*/

struct Person {
	char* m_sName;
	char* m_sAddress;
	int		m_nAge;
	float	m_fWeight;
	double	m_dHeight;
};
char* strInput() {
	char* str = NULL, temp[128] = { 0 };
	gets(temp);
	str = (char*)malloc(strlen(temp) + 1);
	strcpy(str, temp); 
	return str;
}
char* strAlloc(const char * const temp) {
	char* str = NULL;
	str = (char*)malloc(strlen(temp) + 1);
	strcpy(str, temp);
	return str;
}
struct Test {
	int nData;
	char cText;
};

// number = number2;

void dataCopy(struct Person * ptr1, const struct Person * ptr2) {
	if (ptr1 == NULL)
		return;
		//*ptr1 = (struct Person*)malloc(sizeof(struct Person));

	ptr1->m_sName = strAlloc(ptr2->m_sName);
	ptr1->m_sAddress = strAlloc(ptr2->m_sAddress);
	ptr1->m_dHeight = ptr2->m_dHeight;
	ptr1->m_fWeight = ptr2->m_fWeight;
	ptr1->m_nAge = ptr2->m_nAge;

	return;
}
void InputData(struct Person* ptr1) {
	if (ptr1 == NULL)
		return;
	//*ptr1 = (struct Person*)malloc(sizeof(struct Person));
	printf("이름 > "); ptr1->m_sName = strInput();
	printf("주소 > "); ptr1->m_sAddress = strInput();
	
	printf("나이 > "); scanf("%d", &ptr1->m_nAge);
	
	printf("신장 > "); scanf("%lf", &ptr1->m_dHeight);
	printf("체중 > "); scanf("%f", &ptr1->m_fWeight);
	while (getchar() != '\n');
		
	return;
}

void printPerson(const struct Person* ptr1) {
	/*
	printf("이름 > %s\n"   ,ptr1->m_sName	);
	printf("주소 > %s\n"   ,ptr1->m_sAddress	);
	printf("나이 > %d\n"   ,ptr1->m_nAge		);
	printf("신장 > %.1lf\n",ptr1->m_dHeight	);
	printf("체중 > %.1f\n" ,ptr1->m_fWeight	);
	*/
	printf("%-10s \t %-20s \t %3d \t %.1lf \t %.1f\n", ptr1->m_sName
		, ptr1->m_sAddress
		, ptr1->m_nAge
		, ptr1->m_dHeight
		, ptr1->m_fWeight
	);
}


int main() {
	struct Person** test = (struct Person*)malloc(sizeof(struct Person) * 3);
	InputData(test[0]);
	InputData(test[1]);
	InputData(test[2]);

	printPerson(test[0]);
	printPerson(test[1]);
	printPerson(test[2]);


	return 0;
}
