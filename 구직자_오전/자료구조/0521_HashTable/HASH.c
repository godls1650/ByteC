#include "HASH.h"
/*
Hash 는 요소의 모든 값을 사용하는 것이 좋다고 한다.
*/
int basicHash(const char* const _source) {
	int hash = 0;
	int len = strlen(_source);

	for (int i = 0; i < len; i++) {
		hash += _source[i];
	}
	hash = hash < 0 ? -hash : hash;
	return hash % hsSize;// 0 ~ 99
}

int exHash(const char* const _source) {
	int hash = 0;
	int len = strlen(_source);

	for (int i = 0; i < len; i++) {
		hash += (_source[i]*len * 64) << i; 
	}
	hash >>= 10;
	return hash % hsSize;// 0 ~ 99

}
char* SHA_256ex(const char* const _src) {
	char* str = NULL;
	int len = strlen(_src);
	int len2 = 0;
	len2 = len / 64 + 1;
	len2 *= 64;
	//1. 원본 메시지의 바로 뒤에 '1'비트를 추가
	//2. 메시지의 길이가 512Bit의 배수가 되도록 0을 추가
	//3. 마지막 64bit에는 원본 메시지 길이의 비트 수를 추가
	str = (char*)malloc(len2);
	strcpy(str, _src);
	str[len+1] = 1;
	str[len2-4] = len;

	return str;
}
/*
	자릿수 선택(Digit Selection)
	자릿수 폴딩(Digit Folding)
*/

int hashFolding(const char* src) {
	int len = strlen(SHA_256ex(src));
	int fold = len/8;
	int value = 0;
	char* copy = NULL;
	for (register int i = 0; i < fold; i++) {
		copy = strSlicing(src, i*fold , (i + 1) * fold);
		value += basicHash(copy);
		free(copy);
	}
	return value;
}
char* strSlicing(const char* str, int start, int size) {
	char* temp = (char*)malloc(size+1);
	memset(temp, 0, size);
	
	for (register int i = start, idx = 0; i < size; i++, idx++) {
		temp[idx] = str[i];
	}
	return temp;
}