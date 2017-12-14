/*
注意： 总时间限制: 1000ms 内存限制: 65536kB

描述

写一个二维数组类 Array2,使得下面程序的输出结果是：

0,1,2,3,

4,5,6,7,

8,9,10,11,

next

0,1,2,3,

4,5,6,7,

8,9,10,11,

程序：
*/

#include <iostream>
#include <cstring>
using namespace std;
// 在此处补充你的代码
class Array2 {
private:
	int* praw[1000];//int*类型的指针数组存放行指针
public:
	//函数原型声明
	Array2();//无参构造函数
	Array2(int raw, int col);//构造函数
	~Array2();//析构函数
	int* operator [](int index_raw);//重载[]运算符,返回第index_raw行的整型数组指针
	int operator()(int index_raw, int index_col);//重载()运算符,返回整型数
	
};

Array2::Array2() {

}
Array2::Array2(int raw, int col) {
	for(int i = 0; i < raw; i++) {
		praw[i] = new int[col];
	}
}
Array2::~Array2() {
	delete praw;//释放动态分配的内存空间
}
int* Array2::operator[](int index_raw) {
	return praw[index_raw];
}
int Array2::operator()(int index_raw, int index_col) {
	return praw[index_raw][index_col];
}

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
