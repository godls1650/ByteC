#include "framework.h"
#include "Product.h"
#include <vector>
#include "BinarySearchTree.h"
#include "DataCls.h"
/*
	template 구현 

	Template < typename T >
*/
#define _CRT_SECURE_NO_WARNINGS


template <typename T> // T : template 인자 값
void Swap(T& x, T& y) {
	T temp = x;
	x = y; y = temp;
	return;
}
template <>
void Swap<char *>(char* & str, char* & str2) {
	char temp[100] = { 0 };
	strcpy(temp, str);
	strcpy(str, str2);
	strcpy(str2, temp);
}


template<typename T = int, int Size = 10>
T* allocArea() {
	return new T[Size];
}

enum Figure {Circle, Triangle, Rectangle};

template<typename T, Figure = Rectangle>
T getArea(T len) {
	T result;
	switch (Figure) {
	case Circle: return (double)(result * result) * 3.141592;
	case Triangle: return (result * result)/2;
	case Rectangle: return (result * result);
	}
}

template <typename T1 ,typename T2>
void func(T1 x, T2 y);

using CODETYPE = int[2];

int main() {

	BinarySearchTree<DataCls> test
		= BinarySearchTree<DataCls>();

	test.insert(DataCls());


	vector<int> ivec = vector<int>(10);

	ivec.push_back(10);
	ivec.push_back(20);
	ivec.push_back(30);

	vector<string> svec = vector<string>(10);

	svec.push_back(string("apple"));
	svec.push_back(string("banana"));
	svec.push_back(string("chicken"));

	vector<Product<int>> pvec = vector<Product<int>>();




	Product<int> P1 = Product<int>();
	Product<CODETYPE> P2 = Product<CODETYPE>();
	Product<string> P3 = Product<string>();

	int* arr = allocArea();

	int x = 10 , y = 20; 
	cout << x << " , " << y << endl;
	Swap<int>(x, y); // T에 사용될 데이터 타입을 작성 : 명시적 호출
	cout << x << " , " << y << endl;

	double dx = 2315.3, dy = 142.5434;
	cout << dx << " , " << dy << endl;
	Swap(dx, dy); // 묵시적 호출
	cout << dx << " , " << dy << endl;


}

template<typename T1, typename T2>
void func(T1 x, T2 y){
	cout << x << y << endl;
}