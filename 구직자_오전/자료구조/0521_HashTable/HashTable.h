#pragma once
#include "framework.h"
#include "HList.h"

typedef struct HashTable {
	List** bucket;
	int Size;
	hashFunc * hash;
}hashTable;

hashTable* initTable(int size, hashFunc * funcName);
void setTable(hashTable* pTable, const char* const data);