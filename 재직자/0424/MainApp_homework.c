#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	for(int i= 0; i < 5; i++){
		for (int j = 0; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
	printf("\n");

	for (int i = 0; i < 5; i++) {
		for (int sp = 0; sp < 4 - i; sp++) {
			printf(" ");
		}
		for (int j = 0; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < i ; j++) {
			printf(" ");
		}
		printf("*\n");
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == j) printf("*");
			else printf(" ");
			printf("%c", (i == j) ? '*' : ' ');
		}
		printf("\n");
	}
	printf("\n");


	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4 - i; j++) {
			printf(" ");
		}
		printf("*\n");
	}
	printf("\n");

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == 4-j) printf("*");
			else printf(" ");
		}
		printf("\n");
	}

	

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == j || i == 4 - j) printf("*");
			else printf(" ");
		}
		printf("\n");
		
	}
	// i 0    j 1    
		// i 1    j 3
		// i 2    j 5
		// i 3    j 7  
		// i 4    j 9  
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4 - i; j++) {
			printf(" ");
		}
		
		for (int j = 0; j < 2 * i + 1; j++)
			printf("*");
		printf("\n");
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j <= i; j++) {
			printf(" ");
		}
		for (int j = 0; j < 2 * (4-i) - 1; j++)
			printf("*");
		printf("\n");
	}




	printf("\n");


	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4 - i; j++) {
			printf("*");
		}

		for (int j = 0; j < 2 * i + 1; j++)
			printf(" ");
		printf("\n");
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j <= i; j++) {
			printf("*");
		}
		for (int j = 0; j < 2 * (4 - i) - 1; j++)
			printf(" ");
		printf("\n");
	}


	return 0;
}