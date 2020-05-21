#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	저수준(Low Level) 프로그래밍  CPU등의 마이크로 프로그래밍 
	비트필드 
	멤버변수 : 비트수; --> 멤버 변수를 unsigned 형태를 주로 사용 

*/
typedef struct INTEGER {
	unsigned int Sign : 1; // 1bit 변수 
	unsigned int Value : 31;

}INT;

typedef struct _COLOR {
	unsigned int BLUE : 8;
	unsigned int GREEN : 8;
	unsigned int RED : 8;
	unsigned int TYPE : 8;

}color;

typedef union Data {
	color Bit;
	unsigned char byte[4];
}Color;

typedef union UnionInt {
	INT BIT;
	char Data[4];
}integer;



int main() {
	Color w;
	w.Bit.TYPE = 0;
	w.Bit.RED = 255;
	w.Bit.GREEN = 100;
	w.Bit.BLUE = 120;

	printf("%08x\n", w);
	switch (w.byte[3]) {
	case 0: printf("RGB"); break;
	case 1: printf("YCB"); break;
	case 2: printf("sRGB"); break;
	}
	char* colorName[3] = { "red", "green", "blue" };
	for (int i = 0; i < 3; i++) {
		printf("%-5s : %u\n", colorName[i], w.byte[2-i]);
	}


	integer x;

	x.BIT.Sign = 1;
	x.BIT.Value = 0x7FFFFFFF;

	printf("%d %d %d %d\n", x.Data[0], x.Data[1], x.Data[2], x.Data[3]);

	
	return 0;
}