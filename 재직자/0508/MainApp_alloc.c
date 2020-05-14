#include "framework.h"
/* ���α׷��� �޸� ���� (����)
------ ���α׷��� �޸�---------------------
	�ڵ� ������� : �������� ���뿡 ���� ����� ����
	������ ���� : �������� , �Լ� ������Ÿ�� �� ����

------------���� �� ��� �޸�------------------
            Runtime Memory
    Stack ���� : �Լ��� �����ϸ鼭  ������ ����Ǹ� ����� �޸𸮸� �ݳ��ϴ� ����
   Last in First out  --> Stack
	
	������ ���� (Heap) free store

	�޸𸮸� �Ҵ��ϰ� �� heap������ ��ġ���� �����ϴ� �Լ�
		- void *  malloc(size_t _Size)   Memory Allocation 
		-void * calloc(size_t _COUNT, size_t _SIZE)	Allocation
		-realloc()	Allocation
	
	����� ���� heap������ �Ҵ��� �����ϴ� �Լ�
		- free()

*/
int func() { return 1; }


typedef unsigned char byte;
typedef byte boolean;
typedef char* string;

int main() {
	int* ptr = NULL;
	ptr = (int *)malloc(sizeof(int));
	int * arr = NULL;
	int Size = 10;
	
	arr = (int*)malloc(sizeof(int) * Size);
	memset(arr, 0, sizeof(int) * Size);
	for (int i = 0; i < Size; i++) {
		arr[i] = (i + 1) * 10;
	}


	for (int i = 0; i < Size; i++) {
		printf("%2d ", arr[i]);
	}
	printf("\n");
	//arr = (int*)malloc(++Size* sizeof(int));
	arr = (int*)realloc(arr, sizeof(int) * (++Size));
	arr[10] = 110;

	

	for (int i = 0; i < Size; i++) {
		printf("%2d ", arr[i]);
	}

	printf("\n");

	
	*ptr = 1000;
	ptr[0] = 2000;
	



	printf("func�� ��ġ : %p\n", func);
	free(ptr);
	free(arr);

	return 0;
}