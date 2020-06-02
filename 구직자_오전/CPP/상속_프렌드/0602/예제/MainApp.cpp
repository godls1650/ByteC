#include "framework.h"
/*
��ü���� ���α׷��� --> �������� �𵨸�(SIMULA)
 ��ü������ 3��� 
   - ��Ӽ�(Inheritance) : ���� Ŭ������ base�� ������ Ȯ�� ��Ų��.

         Ŭ������ Ŭ�������� �������� ���� 

   [å class] --handler class--> [���� ����Ʈ] : �Ӽ����� å �迭��ü�� ���´�.
      �� �帣�� 
          �� [���� class]
          �� [�������� class]
          ��           �� [IT,���α׷���]        
          �� [�Ҽ�å class]
          �� ...
          �� ...

����Ŭ������ �ۼ�
--> ��������Ʈ Ŭ���� �ۼ�

����Ŭ������ �ۼ�
    --> IT�������� {�������� + "IT,���α׷���"}
        --> �ý��� ���α׷��� {�������� + "IT,���α׷���", "�ý��� ���α׷���"}
        --> �ΰ����� {�������� + "IT,���α׷���", �ΰ�����}
        --> ���ӿ��� {�������� + "IT,���α׷���", "���ӿ��� �̸�"}

*/
#include "Comics.h"
#include "Gossip.h"
int main(void) {
    Comics c = Comics();
    myBook** booklist = new myBook*[5];

    booklist[0] = new Comics(); // myBook * Ÿ���� �ڽ� Ŭ���� Ÿ���� Comics * Ÿ������ 
                                // casting �Ѵ�.  ����Ŭ����-> ����Ŭ���� DownCasting
    booklist[1] = new Gossip();

    booklist[0]->view();
    booklist[1]->view();
	return 0;
}