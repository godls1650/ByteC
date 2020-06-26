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
	// postOrder ������� node �Ҹ��ڸ� ���ȣ��
}


template<typename T>
void BinarySearchTree<T>::insert(T d) {
	TreeNode<T>* cursor = this->Root; // ��������
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
