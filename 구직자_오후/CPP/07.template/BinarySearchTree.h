#pragma once
#include "TreeNode.h"
template <typename T>
class BinarySearchTree{
	friend ostream& operator<<(ostream&, const BinarySearchTree&);
private :
	TreeNode* Root;
public :
	BinarySearchTree();
	BinarySearchTree(T d);
	~BinarySearchTree();

	void insert(T d);

};

