#pragma once
#include "framework.h"
#include "BinarySearchTree.h"
template <typename T>
class TreeNode{
	friend class BinarySearchTree;
	
	friend ostream& operator<< (ostream&, const TreeNode&);
private :
	T data;
	TreeNode* Left;
	TreeNode* Right;
public :
	TreeNode();
	TreeNode(T d);
	~TreeNode();
};

