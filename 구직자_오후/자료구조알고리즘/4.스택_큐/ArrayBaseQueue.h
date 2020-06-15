#pragma once
#include "../SingleLinkedList/framework.h"

typedef struct _ArrayBasedQueue {
	int* Storage;
	int Capacity;
	int front;// �� : ������ġ �ε���
	int rear; // �� : �Է���ġ �ε���
}a_queue;

/*
	Qeueu ������ 
	�迭�� �̿��ؼ� �������·� ������ ��� front / rear �� ���� ������ �ϰ� �����ϱ� ������
	1ȸ������ ����ǰų� Capacity�� �÷��� ���Ҵ��� �� ����ϰ� �ȴ�. 
	   * �޸𸮸� �ʰ��� �� �ִ�.
	   * �׿� �޸�(�Ҵ� �Ǿ������� ������� �ʴ� �޸�)�� ���� �ϰ� �ȴ�.
	�迭�� �� �ε����� ù �ε����� �����ϴ� ���·� �迭�� ����Ѵ�.
	<ȯ�� ť ����> 
	������ �ε��� -> ù �ε��� --> (index + 1) % Size;

	ť ������ ������ �Է°����� : enqueue();
	                �������  : dequeue();
	* ť�� ��������� ���� ������� ��� : 
	   (rear + 1)%capacity ������ �ε�����ȣ�� front �ε�����ȣ�� ����.

	* ť�� ��������� �����Ͱ� ���� ��� : 
		front�ε�����ȣ�� rear�� ��ȣ�� ����.
*/

a_queue* initArrayQueue(int );

void enQueue(a_queue * , int );
int deQueue(a_queue *);
bool isQEmpty(const a_queue *);
bool isQFull(const a_queue*);
int seekFront(const a_queue*);
int seekRear(const a_queue*);
