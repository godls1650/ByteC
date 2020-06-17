#pragma once
class myNode{
// C++의 default 접근 제어 --> private 
private :				// default 생성자의 동작
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


	/* 함수의 이름을 같게 쓰면서 매개변수를 바꾸는 것으로
	   다른 동작을 구현하는 것
	    --> function overloading 
	*/

};