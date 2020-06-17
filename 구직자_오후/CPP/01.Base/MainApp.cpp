/*
C --> C++ ����, ������
<Data ���� �� �߰�>
#define TRUE  1 --> true
#define FALSE 0 --> false
0 --> NULL
(void *)0 --> NULL(C) --> nullptr(C++)


<Data Type �߰�>
bool : �� Ÿ��  --> true / false ��ɾ� �� �����ϴ� Ÿ��
<���� Ÿ�� �߰�>
type * --> ���� �Ҵ� / C style string �� ���(char [])�� ���
�迭�� --> type var[]
���� ������ --> reference type ---> ( type & )

<�⺻Ÿ��, ����ü ���� �ʱ�ȭ>
C style : int a = 10; // ������ �̿��� �ʱ�ȭ
CPP style : int a(10);// ()�� �̿��� �ʱ�ȭ --> ex) �ʱ�ȭ ����Ʈ 

<������ �߰�>
   new    : malloc(sizeof(type)*1)
   new [] : malloc(sizeof(type)*n)

   delete    : free( variable );
   delete [] : free(dynamic array);



<����� ���� ������ Ÿ��>
typedef struct _Node{}node; --> (C)
struct node{}; ---------------> (CPP)

class ��ɾ��� �߰� 

��ü���� ���α׷��� ����
 �� �Ϲ�ȭ ���α׷��� ���� 

 �Լ��� �����ϴ� ����  �̸�  ===> �̸� + �Ű����� ( �����ε� : Overloading)  


 C��� : printf()�� �Ű������� "hello world"�� �Է��ؼ� < [��µ���]�� ��ҷ� "hello world" �� ����Ѵ�.>
 C++  : console ����� ����ϴ� ��ü�� "hello world"�� �����Ѵ�. < [��� ��ü]�� ��� ������ ó���Ѵ�.>

  ���� å�� ��Ģ : XX�� ����ϴ� ��ü�� XX �� ó���Ѵ�.
*/

#include <iostream>
#include "myNode.h"

using namespace std;

/*
��ü���� 3��Ģ 
 1. �������� : �����Ϳ� ������ ���ִ� ������ Ȯ���Ѵ�.
                   ��������(����)�� : ĸ��ȭ 
                     - private : Ŭ���� �ܺ��� ������ ��� ����
                     - protected :
                     - public : �ܺο� �����ϴ� ������ 
 2. ��Ӽ�
 3. ������ 

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
 