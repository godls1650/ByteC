#pragma once
class myNode{
// C++�� default ���� ���� --> private 
private :				// default �������� ����
	int data;			// data = 0
	myNode* next;		// left = nullptr
	myNode* prev;		// right = nullptr
public :
	myNode();
	myNode(int data);
	void setData(int value);
	void setNext(myNode * next);
	void setPrev(myNode* prev);

	int getData();
	myNode * getNext();
	myNode* getPrev();


	/* �Լ��� �̸��� ���� ���鼭 �Ű������� �ٲٴ� ������
	   �ٸ� ������ �����ϴ� ��
	    --> function overloading 
	*/

};