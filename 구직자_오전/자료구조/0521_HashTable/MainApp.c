#include "HASH.h"
#include "HashTable.h"
#define MACRO(f,x) printf("%s ->hashing result--> %08d\n",x, f(x))

int main() {
	hashTable* dataset = initTable(hsSize, basicHash);
	char str[128] = { 0 };
	FILE* fp = fopen("person.txt", "r");
	while (!feof(fp)) {
		fscanf(fp, "%s%*c", str);
		setTable(dataset, str);
	}

	for (int i = 0; i < hsSize; i++) {
		if (dataset->bucket[i] != NULL) {
			printf("bucket[%d] => ", i);
			printList(dataset->bucket[i]);
		}
		printf("\n");
	}
	printf("�˻��� ����� �̸� : ");
	gets(str);

	int callHash = basicHash(str);
	int count = 0;
	hNode* cursor = dataset->bucket[callHash]->head->next;

	while (strcmp(cursor->data->key, str) != 0) {
		if (cursor->next == NULL) {
			printf("����\n");
			break;
		}
		cursor = cursor->next;
		count++;
	}
	printf("bucket[%d]��° ����Ʈ�� %d��° �����Ͱ� %s�Դϴ�.\n",
		callHash, count, str );


	return 0;
}

/*
MACRO(basicHash,"Hommer Simpson");
	MACRO(basicHash,"Test String");
	MACRO(basicHash,"C language");
	MACRO(basicHash,"Algorithm Programming");
	MACRO(basicHash,"[GIGABYTE] GeForce RTX 2070 SUPER AORUS D6 8GB");
	MACRO(basicHash,"testSize");
	MACRO(basicHash,"C:\\Users\\godls\\Desktop\\C���\\[����Ʈ]C���_SW����");
	MACRO(basicHash,"]");

	printf("\n\n");

	MACRO(exHash, "Hommer Simpson");
	MACRO(exHash, "Test String");
	MACRO(exHash, "C language");
	MACRO(exHash, "Algorithm Programming");
	MACRO(exHash, "[GIGABYTE] GeForce RTX 2070 SUPER AORUS D6 8GB");
	MACRO(exHash, "testSize");
	MACRO(exHash, "C:\\Users\\godls\\Desktop\\C���\\[����Ʈ]C���_SW����");
	MACRO(exHash, "]");

	printf("\n\n");

	MACRO(hashFolding, "Hommer Simpson");
	MACRO(hashFolding, "Test String");
	MACRO(hashFolding, "C language");
	MACRO(hashFolding, "Algorithm Programming");
	MACRO(hashFolding, "[GIGABYTE] GeForce RTX 2070 SUPER AORUS D6 8GB");
	MACRO(hashFolding, "testSize");
	MACRO(hashFolding, "C:\\Users\\godls\\Desktop\\C���\\[����Ʈ]C���_SW����");
	MACRO(hashFolding, "]");


*/