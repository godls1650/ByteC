#include "TreeNode.h"

template<typename T>
TreeNode<T>::TreeNode<T>() {
	data = (T)0;
	Left = nullptr; right = nullptr;
}
template<typename T>
TreeNode<T>::TreeNode<T>(T d) {
	data = d;
	Left = nullptr; right = nullptr;
}

template<typename T>
TreeNode<T>::~TreeNode<T>() {

}

template<typename T>
ostream& operator<< (ostream& os, const TreeNode<T>& ref) {
	os <<setw(3) << ref.data;
	return os;
}