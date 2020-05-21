#include "HashTable.h"
hashTable* initTable(int size, hashFunc * funcName) {
	hashTable* temp = (hashTable*)malloc(sizeof(hashTable));
	temp->Size = size;
	temp->bucket = (List**)malloc(sizeof(List*) * size);
	memset(temp->bucket, 0, sizeof(List*) * size);
	temp->hash = funcName;
	return temp;
}
void setTable(hashTable * pTable, const char* const data) {
	int index = pTable->hash(data);
	if(pTable->bucket[index] == NULL)
		pTable->bucket[index] = initList();
	append(pTable->bucket[index], data, pTable->hash);
}
