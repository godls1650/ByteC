#include "framework.h"
#include <stdio.h>

#define pType(x) x *
#define Allocate(type,size) (type *)malloc(sizeof(type)* size)
/*	���ۿ� �����͸� �Է��� ��� --> printf (������ �Է� ��� :  stdout��¹���)
    ���ڿ��� �����͸� �Է�  ----> sprintf  (������ �Է� ��� : ���ڿ�)
	���Ἲ X 
	���α׷����� ���� ��Ű���� �ϴ� Data�� �ϵ��ũ�� ��� : ����

	����� ��� --> ����  FILE IO  
	���� ����ü ����   : ������ Ÿ�Ը�Ī : FILE �⺻������ Ÿ��X 
	  * char		  : ���ڱ�� �����		--> .txt
	  * unsigned char : ����Ʈ ��� �����   --> .bin
	
	���α׷����� �ٸ� ������ ���� ��� 
	���α׷� ���� ���Ŀ� ������ �ٸ� ������ ��ġ�� ���� // �����Ҵ�
	fopen();


	fclose();										// ������� �� �޸� ����
*/

void AllocationEx1();
void UsingVLAEx1();

int main() {

	FILE* fp = fopen("DataList.txt", "w"); // ������� ������ ����.
	UsingVLAEx1();
	fclose(fp);
	return 0;
}
/* ���� �Ҵ� :Dynamic Allocation 
	- ���α׷��� Runtime ���� ������� ȣ��( ���α׷� �ڵ���� �Ҵ� �Լ��� ȣ��)�ϴ� ������
	  ���α׷��� ���� Runtime memory ���� (heap area)�� ��û�� �´� ũ���� �޸𸮸� �Ҵ��Ѵ�.

	  - void * malloc(size_t _Size) : memory Allocation
	  - void * calloc() : clear Allocation
	  - void * realloc() : re- Allocation (Variable Length Array : VLA)
	  - free()
*/
void AllocationEx1() {
	int count = 4;
	int * m_ptr = (int *)malloc(sizeof(int)*count); // 16 byte �Ҵ��ϰ� �� ���� ��ġ�� ��ȯ
	//int* c_ptr = (int*)calloc(count, sizeof(int)); //int ũ��� 4�� �����ؼ� �Ҵ��� ������ ���� ��ġ�� ��ȯ
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
	// �����迭
	// ������ ������
	// ���� ������ �������� ��ġ
	// ��ü ��������� ���� 


	printf("\n");

}

void UsingVLAEx1() {
	pType(int) Storage = NULL;
	int index = 0;
	int Capacity = 0;

	

	///// �ʱ� �迭�� ���̰� 10 �� ���� �迭�� �ʱ�ȭ -start/////////
	Capacity = 10;
	Storage = Allocate(int, Capacity); // (int *)malloc(sizeof(int)*Capacity)
	memset(Storage, 0, sizeof(int) * Capacity);
	///// �ʱ� �迭�� ���̰� 10 �� ���� �迭�� �ʱ�ȭ - end/////////

	/////���� �Է� ����/////
	 do{
		 Storage[index] = (index + 1) * 10;
		 index++;
	 } while (index < Capacity);
	 index--;
	/////���� �Է� ��/////
	 int bFull = (index + 1 == Capacity);
	 if (bFull) {
		 Capacity *= 2;
	 }
}