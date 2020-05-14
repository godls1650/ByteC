#include "framework.h"

int global_var = 100; // �������� --> �ν� ���� file scope : �������� , ���Ϲ���, �ܺ� ���谡��
static int static_global_var = 1000;// ���Ϲ��� , �������� , ���� ���踸 ����

extern int ev_global;


void func() {
	int local_var = 100;
	static int static_local_var = 100;

	printf("local_var : %d\n", local_var);
	printf("static_local_var : %d\n", static_local_var);
	local_var++;
	static_local_var++;
	return; // local_var == 101   static_local == 101
}

int main() {
	auto int a = 100;// �ڵ����� : �ý����� �ֱ����ġ�� �����ϴ� ���� 
	register int b = 200; // �ý��� ������ġ(CPU)�� �������Ϳ� ���� 
	printf("auto int a �� �� : %d\n", a);
	printf("auto int a �� �޸� ��ġ  : %p\n", &a);

	printf("register b �� �� : %d\n", b);
	//printf("register b �� ��ġ : %p\n", &b);

	for (register int i = 0; i < 100; i++) {

	}




	func();
	func();
	func();
	printf("ev_global : %d\n", ev_global);
	//printf("ev_static_global : %d\n", ev_static_global);

	int local = 0; // main::local  ���� ����  function scope
	printf("global_var : %d\n", global_var);
	
	printf("global_var : %d\n", global_var);


	return 0;
}



