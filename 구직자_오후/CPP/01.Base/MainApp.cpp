/*
C --> C++ 변경, 개선점
<Data 정의 값 추가>
#define TRUE  1 --> true
#define FALSE 0 --> false
0 --> NULL
(void *)0 --> NULL(C) --> nullptr(C++)


<Data Type 추가>
bool : 논리 타입  --> true / false 명령어 를 저장하는 타입
<참조 타입 추가>
type * --> 동적 할당 / C style string 에 사용(char [])에 사용
배열형 --> type var[]
변수 참조형 --> reference type ---> ( type & )

<기본타입, 구조체 등의 초기화>
C style : int a = 10; // 대입을 이용한 초기화
CPP style : int a(10);// ()를 이용한 초기화 --> ex) 초기화 리스트 

<연산자 추가>
   new    : malloc(sizeof(type)*1)
   new [] : malloc(sizeof(type)*n)

   delete    : free( variable );
   delete [] : free(dynamic array);



<사용자 정의 데이터 타입>
typedef struct _Node{}node; --> (C)
struct node{}; ---------------> (CPP)

class 명령어의 추가 

객체지향 프로그래밍 지원
 ㄴ 일반화 프로그래밍 지원 

 함수를 구분하는 기준  이름  ===> 이름 + 매개변수 ( 오버로딩 : Overloading)  


 C언어 : printf()의 매개변수에 "hello world"를 입력해서 < [출력동작]의 요소로 "hello world" 를 사용한다.>
 C++  : console 출력을 담당하는 객체에 "hello world"를 전달한다. < [출력 객체]가 출력 동작을 처리한다.>

  단일 책임 원칙 : XX를 담당하는 객체는 XX 만 처리한다.
*/

#include <iostream>
#include "myNode.h"

using namespace std;

/*
객체지향 3원칙 
 1. 정보은닉 : 데이터에 접근할 수있는 권한을 확인한다.
                   접근지정(제어)자 : 캡슐화 
                     - private : 클래스 외부의 접근은 모두 차단
                     - protected :
                     - public : 외부에 공개하는 데이터 
 2. 상속성
 3. 다형성 

*/

int main(void) {
    myNode * n1 = new myNode(10); // default Constructor
    myNode * n2 = new myNode(20);
    myNode* n3 = new myNode(30);
    myNode* n4 = new myNode(40);
    
    myNode n5 = myNode(11);


    n1->setNext(n2);
    n2->setNext(n3);
    n3->setNext(n4);

    myNode* cursor = nullptr;

    cursor = n1;

    cout << cursor->getData() << endl;
    cursor = cursor->getNext();
    cout << cursor->getData() << endl;
    cursor = cursor->getNext();
    cout << cursor->getData() << endl;
    cursor = cursor->getNext();
    cout << cursor->getData() << endl;

    return 0;
}
 