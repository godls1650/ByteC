#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FALSE   0
#define TRUE    1
/* 
	��� �����
	 - ���� ������ 1 Line �� ��� ��� ��ȣ�� �����ص� �ȴ�.
*/
int main() {
	const double Girin = 140.0;
	double Child_H = 0.0; // ��  Ű
	short bTall = FALSE;

	printf("�˹ٰ� �ָ� ��ҽ��ϴ�. > ");
	scanf("%lf", &Child_H); // �˹ٰ� Ű�� ��ϴ�.
	// ()�� ������ ���� ��� 

	bTall = Child_H >= Girin;// T / F
	if (bTall) printf("��... ���..\n");
	else	   printf("�����԰�Ͷ� �ּ���.\n");// ()�� ������ ������ ��� 
	
	// ����, ��� �� ���ÿ��� ���� ī��� ������ �� 10�ۼ�Ʈ ������ �մϴ�. ��������..
	int FoodPrice = 0;
	int Point = 533;
	short bCompanyCard = FALSE;
	char Text = 0;

	printf("�ֹ��� ���İ� > ");
	scanf("%d", &FoodPrice);// []
	printf("���� ī�尡 ���ī�� �Դϱ� ? (Y/N)> ");
	scanf("%*c%c", &Text);
	if (Text == 'Y' || Text == 'y')
		bCompanyCard = TRUE;
	else
		bCompanyCard = FALSE;

	bCompanyCard = (Text == 'Y') ? TRUE : FALSE; // �ݵ�� �� ���� ��ġ�� ���� �־�� �Ѵ�.

	if (bCompanyCard) {
		Point += FoodPrice / 100;
	}
	else {
		printf("ī�� ���弼�� ������\n");
	}
	printf("���� �ݾ� : %d��\n", FoodPrice + 2000);
	printf("��������Ʈ : %d Point\n", FoodPrice / 100);
	printf("��������Ʈ : %d Point\n", Point);

	int bohumgeum = 120000;
	int gender = 2; // m : 10 %   f : 20%

	bohumgeum *= (gender == 2) ? 1.2 : 1.1;// ���׿��� : ���� �����ϴ� ��츸 ��� 
	if (gender == 2) printf("����");
	else printf("����");
	printf(" ����� : %d\n", bohumgeum);



	return 0;
}