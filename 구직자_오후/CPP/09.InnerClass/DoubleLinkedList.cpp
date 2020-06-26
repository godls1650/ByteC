#include "DoubleLinkedList.h"

template<typename T> 
DoubleLinkedList<T>::DoubleLinkedList() {
	Head = new Node<T>;
	Tail = new Node<T>;

	Head->m_pNext = Tail;
	Tail->m_pPrev = Head;
	len = 0;
}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {
	DelFunc(this->Head);
}

template<typename T>
void DoubleLinkedList<T>::DelFunc(Node<T>* cursor) {
	if (cursor->m_pNext != this->Tail) {
		DelFunc(cursor->m_pNext);
	}
	delete cursor;
}

template<typename T>
void DoubleLinkedList<T>::Append(T data) {
	Node<T>* newNode = new Node<T>;
	newNode->m_Data = data;

	Node<T>* cursor = this->Tail->m_pPrev;

	newNode->m_pNext = cursor->m_pNext;
	newNode->m_pPrev = cursor;
	cursor->m_pNext->m_pPrev = newNode;
	cursor->m_pNext = newNode;
	len++;

}
template<typename T>
void DoubleLinkedList<T>::Show()const {
	Node<T>* cursor = this->Head->m_pNext;
	while (cursor != this->Tail) {
		cout << setw(3) <<cursor->m_Data;
		cursor = cursor->m_pNext;
	}
}
template<typename T>
T DoubleLinkedList<T>::Pop() {
	T rt = this->Tail->m_pPrev->m_Data;
	Node<T>* cursor = this->Tail->m_pPrev;

	cursor->m_pPrev->m_pNext = cursor->m_pNext;
	cursor->m_pNext->m_pPrev = cursor->m_pPrev;
	delete cursor;

	return rt;
}


template<typename T>
Node<T>* DoubleLinkedList<T>:: begin() {
	return Head->m_pNext;
}

template<typename T>
Node<T>* DoubleLinkedList<T>::end() {
	return this->Tail;
}


template<typename T>
typename DoubleLinkedList<T>::Iterator DoubleLinkedList<T>::
Iterator::operator= (const Node<T>* ref) {
	this->C = new Node<T>;
	C->m_Data = ref->m_Data;
	C->m_pNext = ref->m_pNext;
	C->m_pPrev = ref->m_pPrev;
	return *this;
}

template<typename T>
bool DoubleLinkedList<T>::Iterator::
operator!=(const Node<T>* ref) {
	if (this->C != ref) return true;
	else return false;
}

template<typename T>			// 템플릿 지정
typename DoubleLinkedList<T>::Iterator  // 반환 데이터타입 --> typename 을 붙임
DoubleLinkedList<T>::Iterator::operator++(int n)
{
	this->C = this->C->m_pNext;
	return *this;
}

template<typename T>
typename T DoubleLinkedList<T>::Iterator::operator*() {
	return this->C->m_Data;
}

template<typename T>
T DoubleLinkedList<T>::operator[](int i)
{
	Node<T>* cursor = this->Head->m_pNext;
	for (int k = 0; k < i; k++) {
		cursor = cursor->m_pNext;
	}
	return cursor->m_Data;
}
template<typename T>
int DoubleLinkedList<T>::length() {
	return len;
}