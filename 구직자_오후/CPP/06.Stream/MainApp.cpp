#include "framework.h"
/*
콘솔의 출력 스트림 --> ostream cout  <Console OUTput stream>
콘솔의 입력 스트림 --> istream cin   <Console INput stream>

ofstream : 
ifstream : 

C++ 의 모드 상수 
ios::in		읽기 상태
ios::ate	파일을 열고 파일포인터를 EOF로 이동
ios::app	출력 데이터가 항상 EOF에 기록
ios::trunc  기존 파일이 이미 있는 경우 , 파일을 삭제후 다시 생성
ios::nocreate fopen()을 시도하지 않고 file의 존재 여부만 판단 --> 파일이 존재하지 않을 경우
              에러를 발생
ios::noreplace  ↑ 랑 반대로 file이 존재하면 에러 
ios::binary   바이너리 파일 모드로 오픈

~@#EWG!#F그파워포인트이름.csv
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