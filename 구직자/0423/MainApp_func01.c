#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// �������� �����ؾ��ϴ� �� : ���� �ڷ��� + ������

// �������� ������ ���ʿ��� �� : ���� �ڷ���


// �迭 -> ǥ�� �ڷ����� ���� ������(C 
void DataSwap(int lParam , int rParam) { // ���� ����ȣ��
	int temp = lParam;
	printf("<swap ����>lParam(%d)  , rParam(%d)\n", lParam, rParam);
	lParam = rParam;
	rParam = temp;
	printf("<swap ����>lParam(%d)  , rParam(%d)\n", lParam, rParam);

	printf("�Լ� ���� : delete > lparam, rparam, temp\n");
	return;
}

void pDataSwap(int * plParam, int * prParam) { // �ּҿ� ���� ȣ��
	int temp = *plParam;
	printf("plParam : %p \nprParam : %p\n", plParam, prParam);
	*plParam = *prParam;
	*prParam = temp;
	return;
}


int global_num; //MainApp_func01:: x;

/*
�������� : ���α׷� ���θ� ���� ��� ���� 
�������� : �Լ� ���ο����� ����ϴ� ����  (������)
�������� : �Լ� ���ο� ������ �޸𸮸� �����ϴ� ���� (���Ⱑ��)
�ܺκ��� : �ٸ� ������ �������� 

  ������
  ����
  �Ҽ���
  �޸� ��ġ
  ������
  ....

  ����� ���� Ÿ��
     ����ü
	 ������
	 ����ü 
	 C ���� -> �ڷᱸ�� �˰��� -> C++
	 <Data Base >
	 API / MFC
*/

void func() {
	int func_num = 0; //func::x
	printf("func::num : %d \tglobal::num : %d\n",
		func_num++, global_num++);
}

int  func2() {
	static int stat_number = 0;
	global_num++;
	stat_number++;
	return stat_number;
}

//���� ���� : �Լ����ο��� �Լ� ȣ��� ���� �޸𸮸� �Ҵ��Ѵ�.
//           ���α׷��� ������ �� �޸𸮿��� �Ҹ��Ѵ�.
int main() {
	printf("SIZE : %d\n", SIZE);
	
	int main_num = 0; // main::x
	int y = 0,x = 0;

	int funcCnt = 0;
	int funcCnt2 = 0;
	for (int i = 0; i < 10; i++) {
		 func();
		y = func2();
	}

	printf("func = %d�� ������\n", global_num);
	
	
	printf("main::x = %d   main::y = %d\n", x, y);
	DataSwap(x, y);// == DataSwap(10,20)
	printf("main::x = %d   main::y = %d\n", x, y);
	printf("x�� �޸� : %p\n y�� �޸� : %p\n", &x, &y);
	pDataSwap(&x, &y);
	printf("main::x = %d   main::y = %d\n", x, y);



	return 0;
}