#pragma once
#include "framework.h"
#define hsSize 10
//간단한 해시함수
int basicHash(const char* const);
int exHash(const char* const);

//쓸만한 해시함수

/*
SHA-256 (SHA2기반)
 1. 원본 메시지의 바로 뒤에 '1'비트를 추가
 2. 메시지의 길이가 512Bit의 배수가 되도록 0을 추가
 3. 마지막 64bit에는 원본 메시지 길이의 비트 수를 추가
*/
char* SHA_256ex(const char* const);
int hashFolding(const char* src);
char* strSlicing(const char* str, int start, int size);