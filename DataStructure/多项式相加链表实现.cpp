/*
2. 多项式加法
来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 5000kB

描述
我们经常遇到两多项式相加的情况，在这里，我们就需要用程序来模拟实现把两个多项式相加到一起。首先，我们会有两个多项式，每个多项式是独立的一行，每个多项式由系数、幂数这样的多个整数对来表示。

如多项式2x20- x17+ 5x9- 7x7+ 16x5+ 10x4 + 22x2- 15

对应的表达式为：2 20 -1 17 5 9 - 7 7 16 5 10 4 22 2 -15 0。

为了标记每行多项式的结束，在表达式后面加上了一个幂数为负数的整数对。

同时输入表达式的幂数大小顺序是随机的。

我们需要做的就是把所给的两个多项式加起来。

输入
输入包括多行。

第一行整数n,表示有多少组的多项式需要求和。(1 < n < 100)

下面为2n行整数，每一行都是一个多项式的表达式。表示n组需要相加的多项式。

每行长度小于300。

输出
输出包括n行，每行为1组多项式相加的结果。

在每一行的输出结果中，多项式的每一项用“[x y]”形式的字符串表示，x是该项的系数、y 是该项的幂数。要求按照每一项的幂从高到低排列，即先输出幂数高的项、再输出幂数低的项。

系数为零的项不要输出。

样例输入

-1 17 2 20 5 9 -7 7 10 4 22 2 -15 0 16 5 0 -1
2 19 7 7 3 17 4 4 15 10 -10 5 13 2 -7 0 8 -8
-1 17 2 23 22 2 6 8 -4 7 -18 0 1 5 21 4 0 -1
12 7 -7 5 3 17 23 4 15 10 -10 5 13 5 2 19 9 -7
样例输出

[ 2 20 ] [ 2 19 ] [ 2 17 ] [ 15 10 ] [ 5 9 ] [ 6 5 ] [ 14 4 ] [ 35 2 ] [ -22 0 ]
[ 2 23 ] [ 2 19 ] [ 2 17 ] [ 15 10 ] [ 6 8 ] [ 8 7 ] [ -3 5 ] [ 44 4 ] [ 22 2 ] [ -18 0 ]
  
提示
第一组样例数据的第二行末尾的8 -8，因为幂次-8为负数，所以这一行数据结束，8 -8不要参与计算。
*/

#include <iostream>
using namespace std;

struct LinkNode {
	//双向链表的单个节点，用结构体定义
	int coefficent;//多项式的系数
	int power;//多项式的幂
	LinkNode *prev;
	LinkNode *next;
};

class LinkPolynomial {
private:
	LinkNode *head;
	LinkNode *tail;
	LinkNode *temp;
public:
	LinkPolynomial();//无参构造函数初始化空表	
	~LinkPolynomial();//析构函数
	LinkNode *AddNewNode(int coefficent_, int power_);//添加系数为coefficent_、幂为power_的项
	void Insert(LinkNode *p_);//将项p_插入temp指针之后的位置
	void TryInsert(LinkNode *p_);//尝试将p_按降幂插入多项式
	void Initialize();//初始化多项式
	friend ostream &operator << (ostream &output, const LinkPolynomial &formula);//重载流输出运算符，需要重载为非类成员函数，并且为类的友元
	LinkPolynomial &operator+(const LinkPolynomial &formula);//重载加法运算符，定义两个多项式相加
};

LinkPolynomial::LinkPolynomial() {
	head = tail = temp = NULL;
}

LinkPolynomial::~LinkPolynomial() {
	if(head)
		delete head;//若非空表则释放表头内存
}

LinkNode *LinkPolynomial::AddNewNode(int coefficent_, int power_) {
	if(0 != coefficent_) {
		LinkNode *p = new LinkNode;
		p->coefficent = coefficent_;
		p->power = power_;
		//要不要delete p ??
		return p;
	}
	else {
		return NULL;
	}
}

void LinkPolynomial::Insert(LinkNode *p_) {
	if(!p_)
		return;
	if(!head) {
		//空表，直接添加
		temp = tail = head = p_;
		head->prev = NULL;
		tail->next = NULL;
	}
	else if(temp == tail){
		//表非空且temp指针在表尾
		p_->prev = tail;
		tail->next = p_;
		tail = p_;
		tail->next = NULL;
		temp = tail;
	}
	else {
		//表非空且temp指针不在表尾
		temp->next->prev = p_;
		p_->next = temp->next;
		temp->next = p_;
		p_->prev = temp;
	}
}

void LinkPolynomial::TryInsert(LinkNode *p_) {
	//默认从表尾寻找插入位置
	if(!head) {
		//空表，直接添加
		Insert(p_);
	}
	else {
		//表非空，搜寻合适位置插入
		if(p_->power < temp->power) {
			//若要插入的项比当前位置的项幂次低，则插入到当前位置之后，并将temp指针移到表尾
			Insert(p_);
		}
		else if(p_->power == temp->power) {
			temp->coefficent = temp->coefficent + p_->coefficent;
		}
		else if(temp == head) {
			//若要插入的项比当前位置的项幂次高，且当前项是头节点，则插入到当前位置之前
			temp->prev = p_;
			p_->next = temp;
			head = p_;
			head->prev = NULL;
		}
		else {
			//要插入的项比当前位置的项幂次高，则将temp指针移到前一项，然后递归调用TryInsert函数
			temp = temp->prev;
			TryInsert(p_);
		}
		temp = tail;
	}
}

void LinkPolynomial::Initialize() {
	while(true) {
		int coefficent, power;
		cin >> coefficent >> power;
		if(power < 0)
			break;//幂次出现复数则表示该多项式输入完毕
		else {
			LinkNode *p = AddNewNode(coefficent, power);
			if(p)
				TryInsert(p);
		}
	}
}

ostream &operator << (ostream &output, const LinkPolynomial &formula) {
	LinkNode *p = formula.head;
	while(p) {
		output << "[ " << p->coefficent << ' ' << p->power << " ] ";
		p = p->next;
	}
	return output;
}

LinkPolynomial &LinkPolynomial::operator+(const LinkPolynomial &formula) {
	
	LinkPolynomial *sum = new LinkPolynomial;
	LinkNode *p1 = head;
	LinkNode *p2 = formula.head;//私有成员变量可以直接调用吗...
	while(p1 || p2) {
		//p1和p2都为空时循环终止
		if(NULL != p1 && NULL != p2) {
			if(p1->power == p2->power) {
				//幂次相等的项系数相加
				LinkNode *p = AddNewNode(p1->coefficent + p2->coefficent, p1->power);
				sum->Insert(p);
				p1 = p1->next;
				p2 = p2->next;
			}
			else if(p1->power > p2->power) {
				LinkNode *p = AddNewNode(p1->coefficent, p1->power);
				sum->Insert(p);
				p1 = p1->next;
			}
			else {
				LinkNode *p = AddNewNode(p2->coefficent, p2->power);
				sum->Insert(p);
				p2 = p2->next;
			}
		}
		else if(p1 != NULL) {
			LinkNode *p = AddNewNode(p1->coefficent, p1->power);
			sum->Insert(p);
			p1 = p1->next;
		}
		else if(p2 != NULL){
			LinkNode *p = AddNewNode(p2->coefficent, p2->power);
			sum->Insert(p);
			p2 = p2->next;
		}
	}
	return *sum;//返回类型应该是LinkPolynomial的引用
	
	/*
	LinkNode *p = formula.head;
	while(p) {
		TryInsert(p);
		p = p->next;
	}
	return *this;
	*/
}

int main() {
	int num = 0;
	cin >> num;//输入测试组数
	while(num--) {
		LinkPolynomial *formula1 = new LinkPolynomial;
		formula1->Initialize();//初始化多项式1
		LinkPolynomial *formula2 = new LinkPolynomial;
		formula2->Initialize();//初始化多项式2
		//cout << *formula1 << endl;
		//cout << *formula2 << endl;
		cout << *formula1 + *formula2 << endl;
		delete formula1;
		delete formula2;
	}
	return 0;
}
