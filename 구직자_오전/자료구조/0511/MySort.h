#pragma once
#include "framework.h"
#define SWAP(x, y) temp = x; x = y; y =temp

int BubbleSort(int* ptr, int size);
int SelectSort(int* ptr, int size);
void printArray(const int* ptr, int size);
void MergeSort(int* ptr, int left, int right);// ���� �Լ�
void Merge2Array(int* ptr, int left, int mid, int right);// ���� �Լ�

int getPivot(int* ptr, int left, int right);
void QuickSort(int* ptr, int left, int right);

void printArray2(const int* ptr, int left, int right);
