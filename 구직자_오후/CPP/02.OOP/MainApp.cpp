#include "Carcls.h"
/*
	클래스 -> 정보 + 동작

	int * ptr = (int *)malloc(sizeof(int));
	*ptr = 10;
	free(ptr);


*/

int main() {
	Carcls car1 = Carcls("티볼리", 55, 72);
//  int number = 0;
//  int number2 = 20;
	Carcls car2 = Carcls("삼성QX3" , 40, 95 );
	Carcls car3 = Carcls(car2); // default copy constructor
	/*	기본 복사 생성자 : 얕은 복사 방식의 복사생성
	  ** 멤버에 동적할당 한 메모리가 있는경우 반드시 ValidPtr
	  *** 깊은 복사 방식의 복사생성자로 <<오버로딩>> 해야 한다.

	Object target = Object(source)
			
	   --> Object::Object(const Object & ref){
			this-> member1 --->[0xcdcdcdcd]<----- ref.member;
			this-> member1 = new Allocate;
			copy(member1, ref.,member);

			this-> member2 = ref. member2;
			this-> member3 = ref. member3;
	   }
		
	
	*/
// int number3 = number2;

	car1.pushAccel();
	car1.pushAccel();
	car1.pushAccel();

	car1.showCarState();
	Carcls::clsFunction(car2);


	std::cout << car1.getCarCount() << std::endl;
	std::cout << car2.getCarCount() << std::endl;
	std::cout << car3.getCarCount() << std::endl;
	std::cout << Carcls::CarCnt << std::endl;
	return 0;
}