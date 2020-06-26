#include "framework.h"
/*
�ܼ��� ��� ��Ʈ�� --> ostream cout  <Console OUTput stream>
�ܼ��� �Է� ��Ʈ�� --> istream cin   <Console INput stream>

ofstream : 
ifstream : 

C++ �� ��� ��� 
ios::in		�б� ����
ios::ate	������ ���� ���������͸� EOF�� �̵�
ios::app	��� �����Ͱ� �׻� EOF�� ���
ios::trunc  ���� ������ �̹� �ִ� ��� , ������ ������ �ٽ� ����
ios::nocreate fopen()�� �õ����� �ʰ� file�� ���� ���θ� �Ǵ� --> ������ �������� ���� ���
              ������ �߻�
ios::noreplace  �� �� �ݴ�� file�� �����ϸ� ���� 
ios::binary   ���̳ʸ� ���� ���� ����

~@#EWG!#F���Ŀ�����Ʈ�̸�.csv
csv
Comma Separated Value

*/


int main(void) {
	// FILE * fp = fopen("text.txt", "wb");
	// FILE * fp = fopen("text.txt", "w");
	ofstream bfout = ofstream("binarytext.dat", ios::binary | ios::trunc );
	ofstream tfout = ofstream("stringtext.txt", ios::trunc);


	// FILE * fp = fopen("text.txt", "rb");
	// FILE * fp = fopen("text.txt", "r");
	ifstream bfin = ifstream("binarytext.dat");
	ifstream tfin = ifstream("stringtext.txt");

	fstream fs = fstream("binarytext.dat", ios::binary | ios::in | ios::_Nocreate);

	bfout << "hello world" <<","<<100<<","<<3.141592 <<endl;
	tfout << "hello world" << "," << 100 << "," << 3.141592 << endl;

	string text = string();


	char str[100] = { 0 };
	getline(bfin, text);
	tfin.getline(str, 99);

	istringstream sin = istringstream(text);
	sin >> text;
	
	
	tfin.seekg(tfin._Seekbeg);

	cout << text<<endl;
	cout << str << endl;

	bfout.close();
	tfout.close();
	bfin.close();
	tfin.close();
	fs.close();
	
	return 0;
}