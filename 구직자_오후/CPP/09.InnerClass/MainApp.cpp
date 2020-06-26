#include "DoubleLinkedList.h"
#include "DoubleLinkedList.cpp"



using INT = DoubleLinkedList<int>::Iterator ;

int main() {
	DoubleLinkedList<int> dlst = DoubleLinkedList<int>();
	dlst.Append(10);
	dlst.Append(20);
	dlst.Append(30);
	dlst.Append(40);

	dlst.Show();
	cout << endl;
	DoubleLinkedList<int>::Iterator it;
	it = dlst.begin();
	
	for (it = dlst.begin(); it != dlst.end(); it++) {
		cout << (*it) << endl;
	}
	
	for (int i = 0; i < dlst.length(); i++) {
		cout << dlst[i] << endl;
	}


	//Standard Template Library
	


	return 0;
}