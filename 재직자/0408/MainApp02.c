#include <stdio.h>
#define PI 3.141592
/*
CProject_200408.exe
  ---> MainApp01.c -->main()
  ---> MainApp02.c -->main()

  ������ ���� , �ʱ�ȭ , ��� , Ư¡
  godls1650@gmail.com

*/
int main(void) {
    // ��� 10 , 'a' , 3.141592 : ���� �״�� �ϳ��� �� : ���ͷ� ��� 
    //pi --> �ɺ��� ��� 
    // �ɺ��� ����� ����� ��� 1. ������ ���ȭ ��Ų��. const Ÿ�Ը� 
    const float pi = 3.141592f;
    int nData = 0; // ������ �����Ѵ� . main()�Լ��� �������� 

    float r = 4.0f;
    float result = 0.0f;
    
    result = r * r * PI;


    printf("%d �� ���� �Դϴ�.\n", nData);
    nData = 100; // ���� ��� �� �ϳ��� ���� �޸𸮿� ���� ��Ų��.
    printf("%d �� ���� �Դϴ�.\n", nData);
    nData = 200; // ���� 100�� �޸𸮿��� ���� �� 200�� ����ȴ�.


	return 0;
}