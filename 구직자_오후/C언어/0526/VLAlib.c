#include "VLAlib.h"
vlarray initVLA() {
	vlarray temp = { NULL,0,0 };
	return temp;
}
vlarray* allocVLA() {
	vlarray* temp = (vlarray*)malloc(sizeof(vlarray));
	temp->Storage = NULL;
	temp->index = temp->Capacity = 0;
	return temp;
}
void printArray(int* block, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", block[i]);
	}
	printf("\n");
}
void setVLArray(vlarray* _block, size_t _size) {
	//(*_block).Capacity = _size;
	_block->Capacity = _size;
	_block->Storage = (int*)calloc(_size, sizeof(int));
	_block->index = 0;
}

size_t getCapacity(const vlarray* _cBlock) {
	return _cBlock->Capacity;
}
int getCurrentIndex(const vlarray* _cBlock) {
	return _cBlock->index;
}
int getSize(const vlarray* _cBlock) {
	return _cBlock->index;
}

int peek(const vlarray* _cBlock, int index) {
	if (index >= _cBlock->Capacity) {
		printf("Memory Access Error: IndexBoundOfSize\n");
		return -1;
	}
	return _cBlock->Storage[index];
}


int append(vlarray* _Block, int value) {
	if (_Block->index == _Block->Capacity) {
		_Block->Capacity *= 2;
		_Block->Storage = (int*)realloc(_Block->Storage, sizeof(int) * _Block->Capacity);
	}
	_Block->Storage[_Block->index] = value;
	_Block->index++;
	return TRUE;
}

void viewVLAarray(const vlarray* _block) {
	printArray(_block->Storage, _block->index);
}