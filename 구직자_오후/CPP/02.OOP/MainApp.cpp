#include "Carcls.h"
/*
	Ŭ���� -> ���� + ����

	int * ptr = (int *)malloc(sizeof(int));
	*ptr = 10;
	free(ptr);


*/

int main() {
	Carcls car1 = Carcls("Ƽ����", 55, 72);
//  int number = 0;
//  int number2 = 20;
	Carcls car2 = Carcls("�ＺQX3" , 40, 95 );
	Carcls car3 = Carcls(car2); // default copy constructor
	/*	�⺻ ���� ������ : ���� ���� ����� �������
	  ** ����� �����Ҵ� �� �޸𸮰� �ִ°�� �ݵ�� ValidPtr
	  *** ���� ���� ����� ��������ڷ� <<�����ε�>> �ؾ� �Ѵ�.

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