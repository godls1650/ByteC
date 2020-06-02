#include "framework.h"
/*
객체지향 프로그래밍 --> 데이터의 모델링(SIMULA)
 객체지향의 3요소 
   - 상속성(Inheritance) : 기존 클래스를 base로 개념을 확장 시킨다.

         클래스와 클래스간의 여러가지 관계 

   [책 class] --handler class--> [도서 리스트] : 속성으로 책 배열객체를 갖는다.
      ㄴ 장르별 
          ㄴ [잡지 class]
          ㄴ [전공서적 class]
          ㅣ           ㄴ [IT,프로그래밍]        
          ㄴ [소설책 class]
          ㄴ ...
          ㄴ ...

도서클래스를 작성
--> 도서리스트 클래스 작성

도서클래스를 작성
    --> IT전공도서 {도서정보 + "IT,프로그래밍"}
        --> 시스템 프로그래밍 {도서정보 + "IT,프로그래밍", "시스템 프로그래밍"}
        --> 인공지능 {도서정보 + "IT,프로그래밍", 인공지능}
        --> 게임엔진 {도서정보 + "IT,프로그래밍", "게임엔진 이름"}

*/
#include "Comics.h"
#include "Gossip.h"
int main(void) {
    Comics c = Comics();
    myBook** booklist = new myBook*[5];

    booklist[0] = new Comics(); // myBook * 타입을 자식 클래스 타입인 Comics * 타입으로 
                                // casting 한다.  상위클래스-> 하위클래스 DownCasting
    booklist[1] = new Gossip();

    booklist[0]->view();
    booklist[1]->view();
	return 0;
}