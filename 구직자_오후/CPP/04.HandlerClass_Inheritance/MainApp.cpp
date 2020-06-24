# include "ProductList.h"
#include "FoodProduct.h"
#include "ElecProduct.h"
/*
ios_base 
--> showbase   : 진수표현식 출력
--> noshowbase : 진수표현식 제거
--> oct : 8진수로
    hex : 16진수로
	dec : 10진수로
	uppercase : 대문자로
	showpoint  : 빈자리를 출력
	fixed : 고정소수점
	scientific : 부동소수점 

	precision(반올림 자리수)
	
*/
enum Sys_menu {APPEND = 1, SHOWLIST , SEARCH,EXIT};
int main() {
	// 상속 받은 클래스의 경우 각각의 형제 클래스들이 같은 이름의 함수를 사용할 수 있다.
	Product** plist = new Product * [2];
	//dynamic casting
	for (int i = 0; i < 2; i++) {
	if(i == 0)plist[i] = new FoodProduct("네네치킨", 1353524, 32000, 2020, 6, 27);
	else if(i == 1)plist[i] = new  ElecProduct("에어컨", 119119, 1000000, 220);
	}

	for (int i = 0; i < 2; i++) {
		plist[i]->showProduct();
		cout << endl;
	}


	
	delete[] plist;

	return 0;
}