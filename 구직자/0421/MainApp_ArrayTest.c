#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main() {
	/*변수 선언*/
	int myLotto[5][6] = { 0 };
	int temp[6] = { 0 };
	int Winning[7] = { 0 }; // 6번인덱스는 보너스번호
	int money = 0, count = 0;

	int check[5] = { 0 };
	int checkCnt = 0;
	int bSecond = 0;

	srand((unsigned int)time(NULL)); // 난수 SEED 설정
	
	printf("얼마나 뽑으실껀가요 > "); // 데이터 입력
	scanf("%d", &money);

	count = money / 1000; // 몇회 뽑는건가
	for (int i = 0; i < count; i++) {
		/*임시 배열 temp 에 로또 한줄 저장*/
		for (int j = 0; j < 6; j++) {
			temp[j] = rand() % 45 + 1;
			for (int k = 0; k < j; k++) {
				if (temp[j] == temp[k]) {
					j--; break;
				}
			}
		}
		/*저장된 로또 번호를 myLotto[i] 행에 저장*/
		for (int j = 0; j < 6; j++) {
			myLotto[i][j] = temp[j];
		}
		/*위의 동작을 count 만큼 반복*/
	}

	/*내 로또 용지 출력*/
	for (int i = 0; i < count; i++) {
		printf("자  동 %c\t", 'A' + i);
		for (int j = 0; j < 6; j++) {
			printf("%2d ", myLotto[i][j]);
		}
		printf("\n");
	}

	/*일요일입니다 . 결과 나옵니다.*/
	for (int i = 0; i < 7; i++) { // 보너스 번호까지 한번에
		Winning[i] = rand() % 45 + 1;
		for (int j = 0; j < i; j++) {
			if (Winning[i] == Winning[j]) {
				i--; break;
			}
		}
	}

	printf("\n------------------<<당첨 번호>>---------------------\n");
	for (int i = 0; i < 6; i++) {
		printf("%2d ", Winning[i]);
	}
	printf("  + %2d\n", Winning[6]);
	/*번호 확인*/
	for (int i = 0; i < count; i++) {
		checkCnt = 0;// 라인 마다 count를 초기화
		for (int j = 0; j < 6; j++) { /*myLotto 인덱스와*/
			for (int k = 0; k < 6; k++) {/*Winning의 인덱스를 별도로 반복*/
				if (myLotto[i][j] == Winning[k]) { /*하면서 같은 값인지 조회*/
					checkCnt++; /*같다면 count 를 늘리고*/
					break; /*내 번호와 같은 값을 찾았기 때문에 다음 번호로 넘어가기 위해 중단*/
				}
			}
		}/*여기서 하나의 로또번호 라인을 끝냄*/
		check[i] = checkCnt; //여러 라인을 확인해야하기 때문에 check배열에 count를 저장
	}

	/*결과*/
	for (int i = 0; i < count; i++) {
		printf("자  동 %c(%d개)\t", 'A' + i, check[i]);
		switch (check[i]) {
		case 6 : printf("1등\n"); break;
		case 5 :
			for (int j = 0; j < 6; j++) {
				if (myLotto[i][j] == Winning[6]) {
					bSecond = 1;// 2등이 참값
					break;
				}
			}
			if (bSecond) printf("2등\n");
			else printf("3등\n");
			break;
		case 4: 
			printf("4등\n");
			break;
		case 3:
			printf("5등\n");
			break;
		default : 
			printf("꽝\n");
		}
	}
	



	return 0;
}
