#include "Complex.h"

int main(){
	//test class Complex
	Complex c1(1, 2);
	c1.Print();
	Complex c2(2, 3);
	c2.Print();
	Complex c3 = c1 + c2;
	c3.Print();
	Complex c4;
	c4 = c3 + c2;
	c4.Print();

	return 0;
}