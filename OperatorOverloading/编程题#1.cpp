/*
注意： 总时间限制: 1000ms 内存限制: 65536kB

描述

下面程序的输出是：

3+4i

5+6i

请补足Complex类的成员函数。不能加成员变量。
*/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>//
using namespace std;
class Complex {
private:    
    double r,i;
public:    
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
// 在此处补充你的代码
    Complex(){
        //无参构造函数，初始化实部和虚部为0
        r = 0.0;
        i = 0.0;
    }
    Complex & operator = (const string & str){
		//实部和虚部的位数
		int digit_r = 0;
		int digit_i = 0;
		char reals[10];
		char imags[10];
		//从str首元素开始遍历，直到遇到字符'+'，记录遍历过的元素reals[digit1]，表示实部的位数digit1
		//for(int i = 0; i < digit1; i++)
		//	r += (int)reals[i] * 10的(digit1 - i - 1)次方
		int k;
		for(k = 0; str[k] != '+'; k++) {
			reals[k] = str[k];
			digit_r++;
		}
		for(int j = 0; j < digit_r; j++) {
			r += atoi(&reals[j]) * pow(10, digit_r - j - 1);//atoi函数将字符型转化为整型
		}
		//从'+'后面的字符开始遍历，直到遇到字符'i'，记录遍历过的元素imags[digit2]，表示虚部的位数digit2
		//for(int i = 0; i < digit2; i++)
		//	i += (int)imags[i] * 10的(digit2 - i - 1)次方
		for(; str[k + 1] != 'i'; k++) {
			imags[k - digit_r] = str[k + 1];
			digit_i++;
		}
		for(int j = 0; j < digit_r; j++) {
			i += atoi(&imags[j]) * pow(10, digit_r - j - 1);//atoi函数将字符型转化为整型
		}
		return *this;//返回成员函数所作用的对象
	}
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}
