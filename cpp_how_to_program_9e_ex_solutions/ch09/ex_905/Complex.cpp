#include "Complex.h"

#include <iostream>

using namespace std;

Complex::Complex(){
	//默认构造函数
	realPart = 0;
	imaginaryPart = 0;
}

Complex::Complex(double real_, double imag_):realPart(real_),imaginaryPart(imag_){
	//带初始化成员列表的构造函数
}

Complex &Complex::operator+(Complex &c){
	//两个复数求和
	double real = c.getReal();
	double imag = c.getImag();
	Complex sum(realPart + real, imaginaryPart + imag);
	return sum;
}

void Complex::Print(){
	cout << '(' << getReal() << ", " << getImag() << ')' << endl;
}

double Complex::getReal(){
	return realPart;
}

double Complex::getImag(){
	return imaginaryPart;
}

