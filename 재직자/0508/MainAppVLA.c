#include "framework.h"
#define MAXSIZE	256



int main() {
	char * �λ� = StringAlloc("hello world");

	char* Name = StringInput("�̸� > ");
	char* Address = StringInput("�ּ� > ");
	char* mail = StringInput("���� > ");

	printf("%s\n%s\n%s\n", Name, Address, mail);
	return 0;
}