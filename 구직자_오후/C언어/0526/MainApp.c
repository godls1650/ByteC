#include "framework.h"
#include <stdio.h>

#define pType(x) x *
#define Allocate(type,size) (type *)malloc(sizeof(type)* size)
/*	버퍼에 데이터를 입력후 출력 --> printf (데이터 입력 대상 :  stdout출력버퍼)
    문자열에 데이터를 입력  ----> sprintf  (데이터 입력 대상 : 문자열)
	연결성 X 
	프로그램에서 유지 시키고자 하는 Data를 하드디스크에 기록 : 파일

	입출력 대상 --> 파일  FILE IO  
	파일 구조체 변수   : 데이터 타입명칭 : FILE 기본데이터 타입X 
	  * char		  : 문자기반 입출력		--> .txt
	  * unsigned char : 바이트 기반 입출력   --> .bin
	
	프로그램에서 다른 파일을 읽을 경우 
	프로그램 실행 이후에 변수에 다른 파일의 위치를 저장 // 동적할당
	fopen();


	fclose();										// 사용종료 후 메모리 해제
*/

void AllocationEx1();
void UsingVLAEx1();

int main() {

	FILE* fp = fopen("DataList.txt", "w"); // 쓰기모드로 파일을 연다.
	UsingVLAEx1();
	fclose(fp);
	return 0;
}
/* 동적 할당 :Dynamic Allocation 
	- 프로그램의 Runtime 동안 사용자의 호출( 프로그램 코드상의 할당 함수를 호출)하는 것으로
	  프로그램의 여유 Runtime memory 공간 (heap area)에 요청에 맞는 크기의 메모리를 할당한다.

	  - void * malloc(size_t _Size) : memory Allocation
	  - void * calloc() : clear Allocation
	  - void * realloc() : re- Allocation (Variable Length Array : VLA)
	  - free()
*/
void AllocationEx1() {
	int count = 4;
	int * m_ptr = (int *)malloc(sizeof(int)*count); // 16 byte 할당하고 그 시작 위치를 반환
	//int* c_ptr = (int*)calloc(count, sizeof(int)); //int 크기로 4번 나열해서 할당한 공간의 시작 위치를 반환
	memset(m_ptr, 0, sizeof(int) * count);

	for (int i = 0; i < count; i++) {
		m_ptr[i] = (i + 1) * 10;
	}
	for (int i = 0; i < count; i++) {
		printf("%3d ", m_ptr[i]);
	}
	printf("\n");
	/*
	for (int i = 0; i < count; i++) {
		printf("m_ptr[%d] : %d\tc_ptr[%d] : %d\n", i, m_ptr[i], i, c_ptr[i]);
	}
	*/
	//m_ptr = (int*)malloc(sizeof(int) * count * 2);
	m_ptr = (int *)realloc(m_ptr, sizeof(int) * count * 2);
	int index = count;
	count *= 2;
	for (int i = index; i < count; i++) {
		m_ptr[index++] = (i + 1) * 10;
	}
	for (int i = 0; i < count; i++) {
		printf("%3d ", m_ptr[i]);
	}
	// 가변배열
	// 저장할 포인터
	// 현재 마지막 데이터의 위치
	// 전체 저장공간의 갯수 


	printf("\n");

}

void UsingVLAEx1() {
	pType(int) Storage = NULL;
	int index = 0;
	int Capacity = 0;

	

	///// 초기 배열의 길이가 10 인 가변 배열을 초기화 -start/////////
	Capacity = 10;
	Storage = Allocate(int, Capacity); // (int *)malloc(sizeof(int)*Capacity)
	memset(Storage, 0, sizeof(int) * Capacity);
	///// 초기 배열의 길이가 10 인 가변 배열을 초기화 - end/////////

	/////값을 입력 시작/////
	 do{
		 Storage[index] = (index + 1) * 10;
		 index++;
	 } while (index < Capacity);
	 index--;
	/////값을 입력 끝/////
	 int bFull = (index + 1 == Capacity);
	 if (bFull) {
		 Capacity *= 2;
	 }
}