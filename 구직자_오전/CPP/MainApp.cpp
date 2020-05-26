#include "framework.h"
#include "MyPair.h"
#include "MyString.h"

int main(void) {
	/*
	int number = 0;
	int number = 100;
	int number2 = number;
	*/
	
	MyPair point1 = MyPair(20,30);
	MyPair point2(45,34);
	MyPair point3 = MyPair();
	MyString str = MyString("hello world");
	MyPair point4 = point1;
	MyString str2 = MyString(str);

	printf("%s\n", str.toChrArray());
	printf("%s\n", str2.toChrArray());
	str2.changeword("halo ");

	printf("%s\n", str.toChrArray());
	printf("%s\n", str2.toChrArray());

	point1.viewInfo();
	point4.viewInfo();
	
	point1.setXY(10, 20);
	point1.viewInfo();
	point4.viewInfo();
	
	
	return 0;
}