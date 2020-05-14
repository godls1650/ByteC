#include "framework.h"
#define MAXSIZE	256



int main() {
	char * 인사 = StringAlloc("hello world");

	char* Name = StringInput("이름 > ");
	char* Address = StringInput("주소 > ");
	char* mail = StringInput("메일 > ");

	printf("%s\n%s\n%s\n", Name, Address, mail);
	return 0;
}