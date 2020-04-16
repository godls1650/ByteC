#include <stdio.h>
/*빨간색 컵에 20ml 의 용액이 있고 
  파란색 컵에 30ml 의 용액이 있다.

  두 컵의 용액을 섞지 않고 교환한다.

*/
int main(void) {
    int RedCup = 0;
    int BlueCup = 0;
    int GreenCup = 0;

    RedCup = 20;
    BlueCup = 30;

    printf("빨간 컵의 용액 : %dml\n 파란 컵의 용액 : %dml\n", RedCup, BlueCup);
    /*교환 후*/

    RedCup = BlueCup;
    BlueCup = RedCup;

    printf("빨간 컵의 용액 : %dml\n 파란 컵의 용액 : %dml\n", RedCup, BlueCup);
	return 0;
}