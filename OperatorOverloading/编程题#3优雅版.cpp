//来源：程序设计与算法（三）C++面向对象程序设计 第四周测验答案

#include <iostream>
using namespace std;
/*
用一维数组来存放二维数组
a[i][j]的计算过程从左到右，
a[i] 的返回值是个指针，
指向第 i 行的首地址。
a[i][j] 就会是第 i 行第 j 个元素了。
*/
class Array2
{
	//your code starts here
private:
	int * p;
	int r, c;
public:
	Array2() { p = NULL; }
	Array2(int r_, int c_) :r(r_), c(c_)
	{
		p = new int[r * c];
	}
	Array2(Array2 & a) :r(a.r), c(a.c)
	{
		p = new int[r * c];
		memcpy(p, a.p, sizeof(int)*r*c);
	}
	Array2 & operator=(const Array2 & a) {
		if(p)
			delete[] p;
		r = a.r; c = a.c; p = new int[r * c];
		memcpy(p, a.p, sizeof(int) * r * c);
		return *this;
	}
	~Array2()
	{
		if(p)
			delete[] p;
	}
	int * operator [] (int i) {
		return p + i * c;
	}
	int & operator() (int i, int j) {
		return p[i * c + j];
	}
	//your code ends here
};
int main() {
	Array2 a(3, 4);
	int i, j;
	for(i = 0; i < 3; ++i)
		for(j = 0; j < 4; j++)
			a[i][j] = i * 4 + j;
	for(i = 0; i < 3; ++i) {
		for(j = 0; j < 4; j++) {
			cout << a(i, j) << ",";
		}
		cout << endl;
	}
	cout << "next" << endl;
	Array2 b; b = a;
	for(i = 0; i < 3; ++i) {
		for(j = 0; j < 4; j++) {
			cout << b[i][j] << ",";
		}
		cout << endl;
	}
	return 0;
}
