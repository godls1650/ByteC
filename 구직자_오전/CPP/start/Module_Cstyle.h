#pragma once
#include "framework.h"

/*
	<< : Left Shift
	>> : Right Shift

	�������� ���α׷��� �����.
	 < C ���>

*/

/*
namespace �̸� ����
�ڵ带 �ϳ��� �̸����� ��� �����ϴ� ��ɾ�
*/

void swap(int& x, int& y) {// �������� : reference type
	int temp = x;
	cout << "swap::�������� x�� �޸� �ּ� : " << &x << endl;
	x = y;
	y = temp;
}

void setArray(int*& ref) {
	ref[0] = 1000;
}

void swap(int* x, int* y) {// �ּҸ� �����ϴ� Ÿ���� ���� 
	cout << "swap::������ x�� �޸� �ּ� : " << &x << endl;
	int temp = *x;
	*x = *y;
	*y = temp;
}

void Ex01() {
	int* arr = (int*)malloc(sizeof(int) * 10);
	int* ptr = new int[10];
	string name = "ȫ�浿";
	name = "�������� ����"; // ������ �����ε�
	name += "����";

	name != "�̰ŵ� �˴ϴ�";

	name.compare("�̰ŵ� �˴ϴ�");
	name.operator=("what");

	cout << name;

	setArray(ptr);
	cout << ptr[0] << endl;


	cout << ptr[0];
	cout << endl;


	int x = 100, y(200);
	cout << "main:: ���� x�� �޸� �ּ� : " << &x << endl;
	cout << "x : " << x << "\ty : " << y << endl;
	cout << "�Ű������� �Ϲ� int �� ��ȯ�Լ� ���� ��" << endl;
	swap(x, y);
	cout << "x : " << x << "\ty : " << y << endl;

	cout << "�Ű������� int * �� ��ȯ�Լ� ���� ��" << endl;
	swap(&x, &y);
	cout << "x : " << x << "\ty : " << y << endl;


}