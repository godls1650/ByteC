#include <iostream>
#include <string>
#include "myString.h"
#include "Point.h"
using namespace std;




int main() {
	Point p1 = Point();		
	Point p2(10, 20);
	Point p3(2, 7);
	p1.showPoint();
	p2.showPoint();
	p3.showPoint();
	

	cin >> p1 >> p2 >> p3;

	cout << p1 << p2 << p3 << endl;
	
	
	

	Point result = Point();
	result = p2 + p3;

	result = -p3;
	
	result < p3;

	/*
	x--;  --> x.operator--(int v);

	--x;  --> x.operator--(void);
	*/
	cout << p2++ << endl;
	if (p2 > p1) {
		p2 = -p2;
	}

	(p2++).showPoint();
	(p2).showPoint();
	(++p2).showPoint();

	(p2--).showPoint();
	(p2).showPoint();
	(--p2).showPoint();
	return 0;
}
