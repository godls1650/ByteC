#include "../../CProject_0511/CProject_0511/MySort.h"
#include "ArraySearch.h"

#define _SIZE	1000
// 순차 탐색의 최악의 경우 : 마지막인덱스에 값이 있을 경우 
int main() {
	data arr[_SIZE] = { 0 };
	srand((unsigned int)time(NULL));
	int n = 5, m = 5;
	int number = 0;
	int** test = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		test[i] = (int*)malloc(sizeof(int) * m);
		memset(test[i], 0, sizeof(int) * m);
	}
	


	for (int i = 0; i < _SIZE; i++) {
		arr[i].number = rand() % 1222;
		for (int j = 0; j < i; j++) {
			if (arr[i].number == arr[j].number) {
				i--;
				break;
			}
		}
	}
	int index = 0;
	int temp = 0;
	int pivo[] = { 1,1,2,3,5,8,13,21,34,55,89 };
	printArray(arr, _SIZE);
	do{
		scanf("%d", &number);
		printf("%d의 위치 : %d\n", number, LinearSearch(arr, _SIZE, number));
		index = LinearSearch(arr, _SIZE, number);
		arr[index].cnt++; // cnt값에 따라서 정렬2
	
	} while (number != 0);




	return 0;
}