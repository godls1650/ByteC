#include "BinarySearchTree.h"

template<typename T>
BinarySearchTree<T>::BinarySearchTree(){
	Root = new TreeNode<T>();
}
template<>
BinarySearchTree<string>::BinarySearchTree() {
	Root = new TreeNode<string>();
}



template<typename T>
BinarySearchTree<T>::BinarySearchTree(T d) {
	Root = new TreeNode<T>(d);
}
template<>
BinarySearchTree<string>::BinarySearchTree(string d) {
	Root = new TreeNode<string>(d);

}



template<typename T>
BinarySearchTree<T>::~BinarySearchTree(){
	// postOrder 방식으로 node 소멸자를 재귀호출
}


template<typename T>
void BinarySearchTree<T>::insert(T d) {
	TreeNode<T>* cursor = this->Root; // 얕은복사
	while (true) {
		if (cursor->data == d) {
			return;
		}
		else if (cursor->data > d) {
			if (cursor->Left == nullptr) {
				cursor->Left = new TreeNode<T>(d);
				break;
			}
			else {
				cursor = cursor->Left;
			}
		}
		else {
			if (cursor->Right == nullptr) {
				cursor->Right = new TreeNode<T>(d);
				break;
			}
			else {
				cursor = cursor->Right;
			}
		}
	}
}
