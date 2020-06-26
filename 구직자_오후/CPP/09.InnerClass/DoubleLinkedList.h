#pragma once
#include "framework.h"
template<typename T> struct Node {
	T m_Data;
	Node* m_pNext;
	Node* m_pPrev;
};

template <typename T> class DoubleLinkedList{
private :
	Node<T>* Head;
	Node<T>* Tail;
	int len;
	void DelFunc(Node<T>* cursor);


public:
	DoubleLinkedList();
	~DoubleLinkedList();
	void Append(T data);
	void Show()const;
	T Pop();

	Node<T>* begin();
	Node<T>* end();
	T operator[](int i);
	int length();


public : 
	class Iterator {
	private :
		Node<T>* C;
	public :
		Iterator operator= (const Node<T>* ref);
		bool operator!= (const Node<T>* ref);
		Iterator operator++(int n);
		T operator*();
	};
};

