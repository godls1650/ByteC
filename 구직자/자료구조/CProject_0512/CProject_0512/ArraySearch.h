#pragma once
#include "framework.h"

//순차 탐색 : 배열 , 배열의 길이, 검색 대상 
int LinearSearch(const data* arr, int len, int target);
// 이진탐색 알고리즘 --> 반드시 정렬 후 실행 되어야한다.
/*
	1. 가운데 인덱스를 구한다. 
	2-1. 가운데 인덱스의 값보다 검색 하고자 하는 값이 더 크면
	   mid = ((mid +1) + rear) / 2
    2-2. 가운데 인덱스 값보다 검색 하고자 하는 값이 더 작다면
		mid = (front + (mid -1))  / 2
	분할 

	정복 : mid 인덱스의 값이 검색 대상과 같다면 반복을 종료하고 인덱스를 반환한다.

*/
int BinarySearch(const int* arr, int front, int rear , int target);
