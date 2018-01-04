#include "Rectangle.h"
#include <iostream>
using namespace std;

//test program
int main(){
	double corners[8] = {5.0, 5.0, 11.0, 13.0, 7.0, 16.0, 1.0, 8.0};
	Rectangle r(corners);
	cout << "the length of rectangle is " << r.getLength() << endl;
	cout << "the width of rectangle is " << r.getWidth() << endl;
	cout << "the perimeter of rectangle is " << r.getPerimeter() << endl;
	cout << "the area of rectangle is " << r.getArea() << endl;
	cout << "the rectangle is square: " << (r.isSquare() ? "true" : "false") << endl;
	return 0;
}