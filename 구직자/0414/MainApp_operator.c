#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define pi 3.141592
/* ����ȯ (casting) ����
   ũ����ȸ ���� ---> sizeof(_����orŸ���̸�_ )

   ���մ��Կ��� : ������� + ����  |  ��Ʈ���� + ���� 
   011011100   ~ --> 100100011
   


   A >= B  A <= B  A == B  A != B

   A >= B  A <= B  A == B  A != B
   (bool)�������� : ������ ����
   ( bit)�������� : �� ��Ʈ �ڸ� 

   AND    : �� �� ���� �� �������� ���� Ű�� 150 �̻��̰� ���̰� 8�� �̻�
   OR	  : �� �� �ϳ��� ���̸� ����
   NOT	  : ��� ����
   (bit) XOR : ���� �ٸ��� 1   (A or B) - (A and B)

   logic  && : and   || : or    ! : not
   bit     & : and    | : or    ~ : not   xor : ^ 

	�� 10�ð� ������  �ýÿ�ݿ� ������ �ٴ´ٸ�.
	
 */
#define AM 0
#define PM 1

int main() {
	int timer = 0;
	timer = PM;
	double inc = 0.0;
	int pay = 3300;

	if (timer == PM) inc = 0.25; 
	else inc = 0.0;
	// ���׿�����    A ? B : C  --> A�� ���̸� B�� ��� �����̸� C�� ���
	inc =  timer == PM ?  0.25 : 0.0;

	
	int result = (int)((double)pay*(1.0 +  inc));
	printf("%d\n", result);
	
	int number = 0;
	float fData = 0.0f;
	double dData = pi;
	char text = 0;
	short sNumber = 0;
	long lNumber = 0l;
	long long llnumber = 0ll;


	printf("byte : %d",sizeof(number));
	printf("byte : %d",sizeof(sNumber));
	printf("byte : %d",sizeof(lNumber));
	printf("byte : %d",sizeof(llnumber));
	printf("byte : %d",sizeof(fData));
	printf("byte : %d",sizeof(dData));
	printf("byte : %d",sizeof(char));
	// �ڵ� ����ȯ
	number = 100;
	sNumber = number; // ����ȯ �ۼ� �ʿ� X
	text = number;
	
	dData = pow(2.0, 10.0);
	number = (int)pow(2.0, 10.0);


	printf("number : %d\n", number);  // 01100100
	printf("~number : %d\n", ~number);// 10011011
	printf("~number + 1 : %d\n", ~number + 1);// 10011100
	//						  ???? ???1
	// Ȧ�� ¦�� //            0000 0001   
	number % 2 == 1; // ������ ���������� + �񱳿���
	number & 1; //  and����

	
	// ���� ����ȯ
	lNumber = (long)number;

	int total = 0;
	int score = 0;

	printf("���� > ");
	scanf("%d", &score);
	total = total + score;
	
	printf("���� > ");
	scanf("%d", &score);
	total += score;
	
	printf("���� > ");
	scanf("%d", &score);
	total = total + score;

	printf("Ž�� > ");
	scanf("%d", &score);
	total = total + score;

	double average = 0.0;
	average = (double)total / 4; // 323.0 / 4

	printf("���� : %d\t ��� : %lf/\n", total, average);

	// casting , sizeof, &(�ּ����� ����)
	// = , + - * / %
	

	return 0;
}