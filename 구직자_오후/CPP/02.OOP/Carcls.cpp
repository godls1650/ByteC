#include "Carcls.h"

size_t nameLength = 30;
/*초기화 리스트 : 생성자 블록 접근 이전에 값을 초기화 한다.
	             메모리에 객체의 멤버변수가 선언 될 때 
생성자의 바로 뒤  ↓  블록의 바로앞    : 콜론 으로 시작하고 , 로 나열한다.*/

int Carcls::CarCnt = 0; // static member의 초기화는 외부에서 

Carcls::Carcls() 
:Speed(0), fuelGauge(0) 
{	m_cpName = new char[nameLength];
	std::cout << "Carcls::Carcls() constructor called.." << std::endl;
	this->CarCnt++;
}


Carcls::Carcls(const char cName[], int sp, int feul) : 
	Speed(sp), fuelGauge(feul) // 참조형이 아닌 변수는 초기화 리스트로 초기화 가능
{
	m_cpName = new char[nameLength];
	strcpy_s(m_cpName,nameLength, cName);
	std::cout << "Carcls::Carcls(const char [], int , int) constructor called.." << std::endl;
	this->CarCnt++;
}

Carcls::Carcls(const Carcls& ref):Speed(ref.Speed), fuelGauge(ref.fuelGauge){
	this->m_cpName = new char[nameLength];
	strcpy_s(this->m_cpName, nameLength,  ref.m_cpName);
	std::cout << "Carcls::Carcls(const Carcls &) constructor called.." << std::endl;
	this->CarCnt++;
}



Carcls::~Carcls() {
	delete[] m_cpName;
	std::cout << "Carcls::~Carcls() Destructor called.." << std::endl;
	this->CarCnt--;
}

/*
void initialize(Carcls * target){
	target->m_cpName = new char[Car_const::nameLength];
	target->Speed = 0;
	target->fuelGauge = 0;
	return ;
}

*/

void Carcls::pushAccel() {
	this->Speed += 10;
	this->fuelGauge -= 1;

	if (isFuelEmpty(this->fuelGauge)) {
		this->Speed = 0;
	}
}
void Carcls::showCarState()  const {
	std::cout << "speed : " << this->Speed << std::endl;
	std::cout << "fuel  : " << this->fuelGauge << std::endl;
}

int Carcls::getCarCount() {
	return this->CarCnt;
}

void Carcls::clsFunction(const Carcls & ref) {
	std::cout << "speed : " << ref.Speed << std::endl;
	std::cout << "fuel  : " << ref.fuelGauge << std::endl;
}

bool Carcls::isFuelEmpty(int fuel) {
	if (fuel < 0) return true;
	else return false;
}