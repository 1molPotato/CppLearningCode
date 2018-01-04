#pragma once

class Complex{
public:
	Complex();//constructor
	Complex(double real_, double imag_);
	Complex &operator+(Complex &c);//override operator "+"
	//Complex &operator-(Complex &c);//override operator "-"
	void Print();
	double getReal();//accessor
	double getImag();//accessor
private:
	double realPart;//实部
	double imaginaryPart;//虚部
};
