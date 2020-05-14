#include "framework.h"

int global_var = 100; // 전역변수 --> 인식 범위 file scope : 전역변수 , 파일범위, 외부 연계가능
static int static_global_var = 1000;// 파일범위 , 전역변수 , 내부 연계만 가능

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
	auto int a = 100;// 자동변수 : 시스템의 주기억장치에 저장하는 변수 
	register int b = 200; // 시스템 연산장치(CPU)의 레지스터에 저장 
	printf("auto int a 의 값 : %d\n", a);
	printf("auto int a 의 메모리 위치  : %p\n", &a);

	printf("register b 의 값 : %d\n", b);
	//printf("register b 의 위치 : %p\n", &b);

	for (register int i = 0; i < 100; i++) {

	}




	func();
	func();
	func();
	printf("ev_global : %d\n", ev_global);
	//printf("ev_static_global : %d\n", ev_static_global);

	int local = 0; // main::local  지역 변수  function scope
	printf("global_var : %d\n", global_var);
	
	printf("global_var : %d\n", global_var);


	return 0;
}



