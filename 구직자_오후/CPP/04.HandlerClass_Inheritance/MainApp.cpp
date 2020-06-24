# include "ProductList.h"
#include "FoodProduct.h"
#include "ElecProduct.h"
/*
ios_base 
--> showbase   : ����ǥ���� ���
--> noshowbase : ����ǥ���� ����
--> oct : 8������
    hex : 16������
	dec : 10������
	uppercase : �빮�ڷ�
	showpoint  : ���ڸ��� ���
	fixed : �����Ҽ���
	scientific : �ε��Ҽ��� 

	precision(�ݿø� �ڸ���)
	
*/
enum Sys_menu {APPEND = 1, SHOWLIST , SEARCH,EXIT};
int main() {
	// ��� ���� Ŭ������ ��� ������ ���� Ŭ�������� ���� �̸��� �Լ��� ����� �� �ִ�.
	Product** plist = new Product * [2];
	//dynamic casting
	for (int i = 0; i < 2; i++) {
	if(i == 0)plist[i] = new FoodProduct("�׳�ġŲ", 1353524, 32000, 2020, 6, 27);
	else if(i == 1)plist[i] = new  ElecProduct("������", 119119, 1000000, 220);
	}

	for (int i = 0; i < 2; i++) {
		plist[i]->showProduct();
		cout << endl;
	}


	
	delete[] plist;

	return 0;
}