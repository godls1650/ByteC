#include "framework.h"

/*
	�⺻ ������ Ÿ��
	 - ����, ����, �Ǽ�, ����
	 - ������

	����� ���� ������ Ÿ��
	 - ����ü (struct) : �ʿ��� ������ ������ �����ؼ� ���ο� Ÿ���� ����
			--> ���� x2 float x1  --> 12byte

	 - ����ü (union)  : �ϳ��� ������ �����ϴ� ������ ������ ����
			--> ���� x2 float x1  --> 4byte
	 - ������ (enum)
	  <ȸ�� ����>
	���ڿ�    �̸�
	����	      ����
	���� �迭 ����ó

	 ����� ���� Ÿ���� ���¸� ���� --> ��������

	 ����ڰ� ������ Ÿ���� ���� �� �ִ�.
	 ����ڰ� �޸� �Ҵ��� �����Ӱ� �� �� �ִ�.
	 ����ڰ� ������ ������ �� �ִ�.

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
	printf("�̸� > "); ptr1->m_sName = strInput();
	printf("�ּ� > "); ptr1->m_sAddress = strInput();
	
	printf("���� > "); scanf("%d", &ptr1->m_nAge);
	
	printf("���� > "); scanf("%lf", &ptr1->m_dHeight);
	printf("ü�� > "); scanf("%f", &ptr1->m_fWeight);
	while (getchar() != '\n');
		
	return;
}

void printPerson(const struct Person* ptr1) {
	/*
	printf("�̸� > %s\n"   ,ptr1->m_sName	);
	printf("�ּ� > %s\n"   ,ptr1->m_sAddress	);
	printf("���� > %d\n"   ,ptr1->m_nAge		);
	printf("���� > %.1lf\n",ptr1->m_dHeight	);
	printf("ü�� > %.1f\n" ,ptr1->m_fWeight	);
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
