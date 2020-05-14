#include "Heap.h"

int main() {
	char str[15] = "hello world";
	heap* h1 = HeapInit();
	int cnt = 0;
	for(int i = 0 ; i < strlen(str); i++)
		HInsert(h1, str[i], str[i] - 'a');
	
	cnt = h1->numOfData;
	for (int i = 0; i < cnt; i++) {
		str[i] = HDelete(h1);
	}
	
	printf("heap sort : %s\n", str);
}