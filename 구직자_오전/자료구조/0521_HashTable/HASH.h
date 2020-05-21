#pragma once
#include "framework.h"
#define hsSize 10
//������ �ؽ��Լ�
int basicHash(const char* const);
int exHash(const char* const);

//������ �ؽ��Լ�

/*
SHA-256 (SHA2���)
 1. ���� �޽����� �ٷ� �ڿ� '1'��Ʈ�� �߰�
 2. �޽����� ���̰� 512Bit�� ����� �ǵ��� 0�� �߰�
 3. ������ 64bit���� ���� �޽��� ������ ��Ʈ ���� �߰�
*/
char* SHA_256ex(const char* const);
int hashFolding(const char* src);
char* strSlicing(const char* str, int start, int size);