#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define WALL	1
#define USER	2
#define TRAP	4
#define GOAL	3
#define ROAD	0
int main() {
	int map[10][10] = {
		1,1,1,0,1,1,1,1,1,1,
		2,0,1,0,0,0,0,0,0,0,
		1,0,1,0,1,4,1,1,0,1,
		0,0,0,0,0,0,0,1,0,1,
		1,1,1,1,1,1,0,1,0,1,
		1,1,1,1,0,0,0,1,0,1,
		0,0,0,0,0,1,0,0,0,0,
		1,1,0,1,1,1,0,1,0,1,
		1,1,0,0,0,1,0,1,0,0,
		1,1,1,1,3,1,0,1,1,4
	};

	while (1) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				switch (map[i][j]) {
				case WALL: printf("¡á"); break;
				case TRAP:case ROAD: printf("  "); break;
				case USER : printf("¡Ý"); break;
				case GOAL : printf("¡Ù"); break;
				}
			}
			printf("\n");
		}
	
		
		system("cls");

	}

	return 0;
}