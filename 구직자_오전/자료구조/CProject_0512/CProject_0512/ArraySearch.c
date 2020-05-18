#include "framework.h"



int LinearSearch(const data* arr, int len, int target) {
	for (int i = 0; i < len; i++) {
		if (arr[i].number == target)
			return i;
	}
	return -1;
}

int BinarySearch(const int* arr, int front, int rear, int target) {
	int mid = 0;
	if (front > rear) return -1;
	mid = (front + rear) / 2;
	if (arr[mid] == target)  return mid;
	else if (arr[mid] < target)  return BinarySearch(arr, mid + 1, rear, target);
	else 	return BinarySearch(arr, front, mid - 1, target);
}

/* Æò°¡
	N°³ Data  --> N/2
 


*/