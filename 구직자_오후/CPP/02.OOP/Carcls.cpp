#include "Carcls.h"

size_t nameLength = 30;
/*�ʱ�ȭ ����Ʈ : ������ ��� ���� ������ ���� �ʱ�ȭ �Ѵ�.
	             �޸𸮿� ��ü�� ��������� ���� �� �� 
�������� �ٷ� ��  ��  ����� �ٷξ�    : �ݷ� ���� �����ϰ� , �� �����Ѵ�.*/

int Carcls::CarCnt = 0; // static member�� �ʱ�ȭ�� �ܺο��� 

Carcls::Carcls() 
:Speed(0), fuelGauge(0) 
{	m_cpName = new char[nameLength];
	std::cout << "Carcls::Carcls() constructor called.." << std::endl;
	this->CarCnt++;
}


Carcls::Carcls(const char cName[], int sp, int feul) : 
	Speed(sp), fuelGauge(feul) // �������� �ƴ� ������ �ʱ�ȭ ����Ʈ�� �ʱ�ȭ ����
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