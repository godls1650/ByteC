#include "Tree.h"

tree* setTree(char Text) {
	tree* temp = (tree*)malloc(sizeof(tree));
	temp->root = initNode();
	setData(temp->root, Text);
	temp->root->level = 1;
	return temp;
}
int CreateChild(tnode* cursor, char Text) {
	tnode* newTnode = initNode();
	if (cursor == NULL)
		return -1;
	setData(newTnode, Text);
	if (cursor->Child == NULL) {
		cursor->Child = newTnode;
		newTnode->Parent = cursor;
		newTnode->level = cursor->level + 1;
		return 1;
	}
	else { // 부모노드의 자식노드가 이미 있다면
		cursor = cursor->Child; // 내부를 가리키는 포인터를 자식 노드로 이동
		while (cursor->Sibling != NULL) {// 형제노드를 가리키고 있지 않은 노드를
			cursor = cursor->Sibling; // 찾는다.
		}
		cursor->Sibling = newTnode; // 새노드를 커서의 형제로 저장
		newTnode->Parent = cursor->Parent; // 새노드의 부모노드는 cursor의 부모노드와 같다.
		newTnode->level = cursor->level;
		return 1;
	}
	return -1;
}

void printTree(const tree* target) {
	tnode* cursor = target->root;
	
	while (cursor != NULL) {
		printf("%c ", cursor->m_cData);
		
		if (cursor->Child != NULL) {
			cursor = cursor->Child;
			printf("{");
			continue;
		}
		if (cursor->Sibling != NULL) {
			cursor = cursor->Sibling;
			printf(",");
			continue;
		}
		printf("}");
		cursor = cursor->Parent->Sibling;
		
	}
	printf("\n");
}

void printTree_recur(const tree* target) {
	printInner(target->root);
}

void printInner(tnode* subRoot) {
	printf("%c ", subRoot->m_cData); 
		
	if (subRoot->Child != NULL) {
		printf("{");
		printInner(subRoot->Child);
		printf("}");
	}
	
	if (subRoot->Sibling != NULL) {
		printf(", ");
		printInner(subRoot->Sibling);
	}
}

void printDir(const tree* _constTarget) {
	inner_dir(_constTarget->root);
}
/*
├ : 형제가 있는 자식 노드로 

└ : 형제가 없는 자식 노드로  

│ : 부모의 형제가 있는경우 출력

A { B { E,F,G},C{H},D{I{M,N,O},J,K,L}}

 " A		\n" A : Parent = NULL	Sibling = NULL
 " ├ B		\n" B : Parent = A		Sibling = C
 " ├ C		\n" C : Parent = A		Sibling = D
 " └ D		\n" D : Parent = A		Sibling = NULL
 " │ ├ E	\n" E : Parent = B		Sibling = F
 " │ ├ F	\n" F : Parent = B		Sibling = G
 " │ └ G	\n" G : Parent = B		Sibling = NULL
 " │ └ H	\n" H : Parent = C		Sibling = NULL
 "   ├ J	\n" J : Parent = C		Sibling = K
 "   ├ K	\n" K : Parent = C		Sibling = L
 "   └ L	\n" L : Parent = C		Sibling = NULL
 "   ├ I	\n" I : Parent = C		Sibling = J
 "   │ ├ M	\n" M : Parent = I		Sibling = N
 "   │ ├ N	\n" N : Parent = I		Sibling = O
 "   │ └ O	\n" O : Parent = I		Sibling = NULL
 "   │ │ └ X

*/


void inner_dir(const tnode* _target) {
	tnode* cursor = _target;
	for (int i = 0; i < _target->level - 2; i++) {
		printf(" ");
	}
	if (_target->Parent != NULL) {
		if (_target->Parent->Sibling != NULL) printf("\b│");

		if (_target->Sibling != NULL) printf("├ ");
		else printf("└ ");
	}
	/*

		
	
	}
	*/
	printf("%c\n", _target->m_cData);

	if (_target->Child != NULL) {
		
		inner_dir(_target->Child);
	}

	if (_target->Sibling != NULL) {
		inner_dir(_target->Sibling);
	}
}

