/*
注意： 总时间限制: 1000ms 内存限制: 65536kB
描述
下面程序的输出是：
3+4i
5+6i
请补足Complex类的成员函数。不能加成员变量。
*/

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class Complex {
private:
	double r, i;
public:
	void Print() {
		cout << r << "+" << i << "i" << endl;
	}
	// 在此处补充你的代码
	Complex & operator = (const string & str) {
		int pos = str.find('+', 0);//寻找+号并返回它的位置
		string str_real = str.substr(0, pos);//分离出代表实部的字符串
		r = stod(str_real);//库函数stod将str_real中的内容转换成double类型
		string str_imag = str.substr(pos + 1, str.size() - pos - 2);
		i = stod(str_imag);

		return *this;//返回成员函数所作用的对象
	}
};
int main() {
	Complex a;
	a = "3+4i"; a.Print();
	a = "5+6i"; a.Print();

	return 0;
}
