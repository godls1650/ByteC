#include "myNode.h"
myNode::myNode() {
	data = 0;
	next = nullptr;
	prev = nullptr;
}

myNode::myNode(int data) {
	this->data = data;
	this->next = nullptr;
	this->prev = nullptr;
}

void myNode::setData(int value) {
	if (value > 0)
		data = value;
	else
		return;
}

void myNode::setNext(myNode* next) { this->next = next; }
void myNode::setPrev(myNode* prev) { this->prev = prev; }
int  myNode::getData() { return this->data; }
myNode* myNode::getNext(){ return this->next; }
myNode* myNode::getPrev(){ return this->prev; }