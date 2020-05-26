#pragma once
/*VLAlib.h*/
#include "framework.h"

// 구조체 정의 : struct
/*	
	struct 구조체이름{
		구조를 이루는 변수를 나열
	};
*/


typedef struct VLArray {
	// member variale : 멤버변수 
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
