#include <stdio.h>
/*������ �ſ� 20ml �� ����� �ְ� 
  �Ķ��� �ſ� 30ml �� ����� �ִ�.

  �� ���� ����� ���� �ʰ� ��ȯ�Ѵ�.

*/
int main(void) {
    int RedCup = 0;
    int BlueCup = 0;
    int GreenCup = 0;

    RedCup = 20;
    BlueCup = 30;

    printf("���� ���� ��� : %dml\n �Ķ� ���� ��� : %dml\n", RedCup, BlueCup);
    /*��ȯ ��*/

    RedCup = BlueCup;
    BlueCup = RedCup;

    printf("���� ���� ��� : %dml\n �Ķ� ���� ��� : %dml\n", RedCup, BlueCup);
	return 0;
}