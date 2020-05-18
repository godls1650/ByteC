#pragma once
#include "framework.h"

//���� Ž�� : �迭 , �迭�� ����, �˻� ��� 
int LinearSearch(const data* arr, int len, int target);
// ����Ž�� �˰��� --> �ݵ�� ���� �� ���� �Ǿ���Ѵ�.
/*
	1. ��� �ε����� ���Ѵ�. 
	2-1. ��� �ε����� ������ �˻� �ϰ��� �ϴ� ���� �� ũ��
	   mid = ((mid +1) + rear) / 2
    2-2. ��� �ε��� ������ �˻� �ϰ��� �ϴ� ���� �� �۴ٸ�
		mid = (front + (mid -1))  / 2
	���� 

	���� : mid �ε����� ���� �˻� ���� ���ٸ� �ݺ��� �����ϰ� �ε����� ��ȯ�Ѵ�.

*/
int BinarySearch(const int* arr, int front, int rear , int target);
