#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define _SIZE	10
int main() { 
	int menu = 0;
	int arr1[_SIZE] = { 0 }; // 0은 데이터가 없다.
	int arr2[_SIZE] = { 0};
	int index = 0;
	int select = 0;
	//int number = 0;
	// [104, 434,  22,  55, 10 , 0 , 0 , 0, 0, 0];
	// [104, 434,  0,  55, 10 , 0 , 0 , 0, 0, 0];
	// [104, 434,  55,  55, 10 , 0 , 0 , 0, 0, 0];
	// [104, 434,  55,  10, 0 , 0 , 0 , 0, 0, 0];
	//  0   1     2   3    4
	//[104, 434,  55, 0   , 132 , 0 , 0, 0, 0, 0];
	while (menu != 5) {
		printf("1. 숫자 입력  2. 데이터 출력 3. 데이터 삭제 4. 데이터 반전  5.Exit\nSelect > ");
		scanf("%d", &menu);
		switch (menu) {
		case 1 : // arr1 의 인덱스에 데이터를 입력하고 인덱스 번호를 증가시킨다.
			printf("arr1[%d] > ", index);
			scanf("%d", &arr1[index]);
			index++;
			break;
		case 2:
			for (int i = 0; i < index; i++) {
				printf("%d ", arr1[i]);
			}
			printf("\n");
			break;
		case 3:
			printf("0 ~ %d 사이에 삭제할 인덱스 > ", index - 1);
			scanf("%d", &select);
			for (int i = select; i < index-1; i++) {
				arr1[i] = arr1[i + 1];
			}
			arr1[index - 1] = 0;
			index--;
			break;
		case 4 : 
			for (int i = 0; i < index; i++) {
				arr2[i] = arr1[index - (i+1)];
			}
			for (int i = 0; i < index; i++) {
				arr1[i] = arr2[i];
			}
			break;
		case 5:
			break;
		default :
			printf("menu not found\n");
			break;
		}
	}


	char plan[9][10] = { "무", "패", "승","승", "무",  "패","패", "승", "무" };
	int user = 2;
	int com = 3;
	user--; // user = 1
	com--; // com = 2  

	int result = user*3 +com;
	printf("%s\n", plan[result]);


	return 0;
}