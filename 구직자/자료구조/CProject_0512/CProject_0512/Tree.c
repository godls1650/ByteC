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
	else { // �θ����� �ڽĳ�尡 �̹� �ִٸ�
		cursor = cursor->Child; // ���θ� ����Ű�� �����͸� �ڽ� ���� �̵�
		while (cursor->Sibling != NULL) {// ������带 ����Ű�� ���� ���� ��带
			cursor = cursor->Sibling; // ã�´�.
		}
		cursor->Sibling = newTnode; // ����带 Ŀ���� ������ ����
		newTnode->Parent = cursor->Parent; // ������� �θ���� cursor�� �θ���� ����.
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
�� : ������ �ִ� �ڽ� ���� 

�� : ������ ���� �ڽ� ����  

�� : �θ��� ������ �ִ°�� ���

A { B { E,F,G},C{H},D{I{M,N,O},J,K,L}}

 " A		\n" A : Parent = NULL	Sibling = NULL
 " �� B		\n" B : Parent = A		Sibling = C
 " �� C		\n" C : Parent = A		Sibling = D
 " �� D		\n" D : Parent = A		Sibling = NULL
 " �� �� E	\n" E : Parent = B		Sibling = F
 " �� �� F	\n" F : Parent = B		Sibling = G
 " �� �� G	\n" G : Parent = B		Sibling = NULL
 " �� �� H	\n" H : Parent = C		Sibling = NULL
 "   �� J	\n" J : Parent = C		Sibling = K
 "   �� K	\n" K : Parent = C		Sibling = L
 "   �� L	\n" L : Parent = C		Sibling = NULL
 "   �� I	\n" I : Parent = C		Sibling = J
 "   �� �� M	\n" M : Parent = I		Sibling = N
 "   �� �� N	\n" N : Parent = I		Sibling = O
 "   �� �� O	\n" O : Parent = I		Sibling = NULL
 "   �� �� �� X

*/


void inner_dir(const tnode* _target) {
	tnode* cursor = _target;
	for (int i = 0; i < _target->level - 2; i++) {
		printf(" ");
	}
	if (_target->Parent != NULL) {
		if (_target->Parent->Sibling != NULL) printf("\b��");

		if (_target->Sibling != NULL) printf("�� ");
		else printf("�� ");
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

