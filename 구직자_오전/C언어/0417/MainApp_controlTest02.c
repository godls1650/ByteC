#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int user = 0;
	int com = 0;
	int bSearch = 0;
	srand((unsigned int)time(NULL));
	com = rand() % 100 + 1;

	while (bSearch != 1) {
		
		
		
		
		
		
		printf("Up And Down > ");
		scanf("%d", &user);
		
		if (user == com) {
			printf("정답입니다 !\n");
			bSearch = 1;
		}
		else if (user > com) {
			printf("Down\n");
		}
		else {
			printf("Up\n");
		}
	
	
	
	
	
	
	
	
	}
	return 0;
}