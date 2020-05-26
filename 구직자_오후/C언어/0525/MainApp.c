#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <wchar.h>
#include <windows.h>
/*
//godls1650@gmail.com
	������ ���� : �ٸ� ����, ���� �޸� �ּҸ� �����ϴ� ���� 
	  --> ������ �Ҵ���� ������ "�ٸ� �޸��� �ּҰ�" �̶�� �����͸� �����ϱ� ���� ����Ѵ�.
	���ڿ� ���̺귯�� �Լ� ���� 
*/
#define BUFFER_SIZE 129
void UseProgram();
void absolute(int * nParam);
int absolute2(int nParam);

int stringLength(const char * _str);
char* stringCopy(char* _destination, const char* _source);  // strcpy   -->  strncpy
char* stringConcat(char* _destination, const char* _source); // strcat  -->  strncat
int stringCompare(const char* _Str1, const char* _Str2);    //strcmp    -->  strncmp

// ���ڿ� header --> char : 1byte 
// ��� �迭�̴�  ���ϴ� ������ �Ҵ��� ��翵���� �Է½�Ų��.

void* memorySet(void* Dst, int value, unsigned int SIZE);

/* ���ڿ��� ���ϴ� �Լ� 
	ù��° �Ű������� ���� ������ �տ� �ִٸ� -1
	ù��° �Ű������� ���� ������ �ڿ� �ִٸ� 1
	ù��° �Ű������� �ι�°�� ���� �����̸� 0

	application
	apple
	apple pie
	camera
	apply
	
	
	
	banana

	apple pie

*/

/*
	���α׷��� ���� 
	str1�� ���ڿ��� �Է¹޴´�. // gets(), scanf()
	str2�� �Է¹��� ���ڿ��� �����Ѵ�. --> strcpy()
*/
char* strAlloc(const char* const str);
int stringSearchString(const char* des, const char* src);
char* strsplit(const char* str, int val);

void Ex01();

int factorial(int n) { returnif (n > 1) ? n* factorial(n - 1) : n;}

int main() {
	char* str = "0x7F26";
	int number = 0;
	double dData = 0.0;
	
	char data[100] = { 0 };

	sscanf(str, "%x", &number);
	//number = strtol(str, NULL, 16);
	printf("%#x\n", number);

	sprintf(data,"%#x", number);
	puts(data);

	
	return 0;
}

int stringLength(const char* _str) {
	int j = 0;
	for (; _str[j] != '\0'; j++);
	return j;
	
}
char* stringCopy(char* _destination, const char* _source) {
	int len = stringLength(_source);
	

	for (int i = 0; i <= len; i++) {
		_destination[i] = _source[i];
	}
	return _destination;
}
char* stringConcat(char* _destination, const char* _source) {
	int dlen = stringLength(_destination);
	int slen = stringLength(_source);

	for (int i = 0, j = dlen; i <= slen; i++, j++) {
		_destination[j] = _source[i];
	}
	return _destination;
}
int stringCompare(const char* _Str1, const char* _Str2) {
	int dlen = stringLength(_Str1);
	int slen = stringLength(_Str2);
	int len = dlen <= slen ? dlen : slen;

	for (int i = 0; i <= len; i++) {
		if (_Str1[i] - _Str2[i] == 0) continue;
		else if (_Str1 - _Str2[i] > 0) return 1;
		else return -1;
	}
	return 0;
}

void* memorySet(void* Dst, int value, unsigned int SIZE) { // memset()
	char* ptr = Dst;
	for (int i = 0; i < SIZE; i++) {
		ptr[i] = value;
	}
	return Dst;
}

void UseProgram() {
	int number = 0;
	number = -100;
	absolute(&number);// absolute::nParam = &UseProgram::number

	printf("���밪 : %d\n", number);
	return;
}
void absolute(int * nParam) {
	if (*nParam < 0) (*nParam) * -1;
}
int absolute2(int nParam) {
	return (nParam < 0) ? nParam * -1 : nParam;
}

char* strAlloc(const char* const str) {
	char* temp = (char*)malloc(strlen(str) + 1);
	strcpy(temp, str);
	return temp;
}

int stringSearchString(const char* des, const char* src) {
	int dlen = strlen(des); // ���� ����
	int slen = strlen(src); // �˻� ���ڿ� ����
	char str[BUFFER_SIZE] = { 0 };
	for (int i = 0; i < dlen - slen; i++) {
		for (int j = i, k = 0; j < slen; j++, k++) {
			str[k] = des[j];
		}
		if (strcmp(str, src) == 0) { return i; }
		else continue;
	}
	return  -1;
}
/*
int stringSearchString(const char* des, const char* src) { // strstr()
	int dlen = strlen(des); // ���� ����
	int slen = strlen(src); // �˻� ���ڿ� ����
	char* cursor = NULL;

	do{
		if (cursor == NULL)
			cursor = strchr(des, src[0]);
		else
			cursor = strchr(cursor + 1, src[0]);
		
		if (strncpy(cursor, src, slen) == 0) return 1;
	} while (cursor != NULL);
	
	return -1;
}
*/
char* strsplit(const char* str, int val) {
	int len = strlen(str);
	char* temp = (char*)malloc(len+ 1);
	for (int i = 0, k = 0; i < len; i++) {
		if (str[i] == val) {
			break;
		}
		else {
			temp[k++] = str[i];
		}
	}
	if (strcmp(temp, str) == 0) { 
		free(temp);
		return str; 
	}
	else {
		strcpy(str, strchr(str, val));
		
		return temp;
	}
}

void Ex01(){
	char str1[BUFFER_SIZE] = { 0 };
	char str2[BUFFER_SIZE] = { 0 };
	char temp[BUFFER_SIZE] = { 0 };

	char Email[128] = "godls1650@gmail.com";
	char Account[100] = { 0 };
	char Domain[100] = { 0 };

	strcpy(Domain, strchr(Email, '@') + 1);
	strcpy(Account, strtok(Email, "@."));
	strcpy(Domain, strtok(NULL, "@."));
	printf("%s\n", Account);

	printf("%s : %s\n", Account, Domain);




	char inBuffer[BUFFER_SIZE] = { 0 };

	strcpy(inBuffer, "ipconfig -all\n");
	sscanf(inBuffer, "%s %s", str1, str2);
	printf("%s |||||| %s\n", str1, str2);




	/*
	str2 = str1  strcpy(str2, str1);
	str2 += str1 strcpy(str2, str1);
	str2 < str1  strcmp(str2, str1);

	*/

	printf("���ڿ��� �Է� > ");
	gets(str2);

	char* strr = strAlloc(str2);

	printf("���ڿ��� �Է� > ");
	gets(str1);
	// hello + " " + world
	// hello world
	// helloworld
	printf("%s �� %s�� ���� ��� : %d\n", str1, str2, stringCompare(str1, str2));
	if (stringCompare(str1, str2) == 1) {
		stringCopy(temp, str1);
		stringCopy(str1, str2);
		stringCopy(str2, temp);
		// ���ڿ� Swap;
	}



	stringConcat(stringConcat(str2, "@"), str1);

	printf("���� : %s\n���纻 : %s\n", str1, str2);


}