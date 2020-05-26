#pragma once
/*VLAlib.h*/
#include "framework.h"

// ����ü ���� : struct
/*	
	struct ����ü�̸�{
		������ �̷�� ������ ����
	};
*/


typedef struct VLArray {
	// member variale : ������� 
	int* Storage;
	int index;
	size_t Capacity;
} vlarray;

void printArray(int*, int);
void setVLArray(vlarray* _block, size_t _size);
vlarray initVLA();

vlarray* allocVLA();
size_t getCapacity(const vlarray * _cBlock);
int getSize(const vlarray* _cBlock);

int getCurrentIndex(const vlarray* _cBlock);
int peek(const vlarray* _cBlock, int index);

int append(vlarray* _Block, int value);
void viewVLAarray(const vlarray* _block);
