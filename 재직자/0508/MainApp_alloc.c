#include "framework.h"
/* 프로그램의 메모리 관리 (구조)
------ 프로그램의 메모리---------------------
	코드 저장공간 : 실행중인 내용에 대한 어셈블리 저장
	데이터 영역 : 전역변수 , 함수 프로토타입 을 저장

------------동작 중 사용 메모리------------------
            Runtime Memory
    Stack 영역 : 함수가 동작하면서  동작이 종료되면 사용한 메모리를 반납하는 공간
   Last in First out  --> Stack
	
	여분의 공간 (Heap) free store

	메모리를 할당하고 그 heap공간의 위치값을 리턴하는 함수
		- void *  malloc(size_t _Size)   Memory Allocation 
		-void * calloc(size_t _COUNT, size_t _SIZE)	Allocation
		-realloc()	Allocation
	
	사용이 끝난 heap공간의 할당을 해제하는 함수
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
	



	printf("func의 위치 : %p\n", func);
	free(ptr);
	free(arr);

	return 0;
}