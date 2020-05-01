#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	char text[][20]={"introduce", "produce", "chase", "scratch", "crash", "stare", "gaze"
			, "scare", "grab", "guard", "discuss", "shrug", "sniff", "scream", "rid", "surround"};
	int n = rand() % 16;
	char text2[20] = { 0 };
	int i = 0;
	int j = 0;
	while (1) {
		while (text[n][i] != '\0') {
			if(text2[i] == '\0')
				printf(" _ ");
			else
				printf(" %c ",text2[i]);
			i++;
		}
		printf("\ninput Character > ");
		char c = 0;
		scanf("%c*c", &c);

		for (j = 0; j < i; j++) {
			if (text[n][j] == c) {
				text2[j] = c;
				break;
			}
		}
		i = 0;
	}


}