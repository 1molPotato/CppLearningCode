/*
约瑟夫问题
来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述
有n只猴子，按顺时针方向围成一圈选大王（编号从1到n），从第1号开始报数，一直数到m，数到m的猴子退出圈外，剩下的猴子再接着从1开始报数。
就这样，直到圈内只剩下一只猴子时，这个猴子就是猴王，编程求输入n，m后，输出最后猴王的编号。

输入
输入包含两个整数，第一个是n，第二个是m (0 < m,n <=300)。

输出
输出包含一行，即最后猴王的编号。

样例输入
12 4
样例输出
1
*/

#include <iostream>
using namespace std;

struct LinkNode {
	//双向链表的单个节点，用结构体定义
	int id;
	LinkNode *prev;
	LinkNode *next;
};
class LinkCircle {
private:
	LinkNode *head;
	LinkNode *tail;
	LinkNode *temp;
public:
	LinkCircle();//无参构造函数初始化空表	
	~LinkCircle();//析构函数
	void Append(int id_);//将编号为id_的节点置于表尾
	void Initialize(int n);//初始化数量为n的节点
	void RemoveTemp();//删除当前节点——即temp指针指向节点，并将temp指向下一个节点
	int SolveJoesph(int n, int m);//解参数为n和m的约瑟夫问题，返回结果（猴王编号）
};
LinkCircle::LinkCircle() {
	head = tail = temp = NULL;
}
LinkCircle::~LinkCircle() {
	if(head)
		delete head;//若非空表则释放表头内存——表中其他节点占用内存是否释放？
}
void LinkCircle::Append(int id_) {
	if(head) {
		//不为空表时,在表尾添加节点
		temp = new LinkNode;
		temp->id = id_;
		temp->prev = tail;
		head->prev = temp;
		tail->next = temp;
		temp->next = head;
		tail = temp;
	}
	else {
		//为空表时，添加头节点
		head = new LinkNode;
		head->id = id_;
		tail = head;
		temp = head;
	}
}
void LinkCircle::Initialize(int n) {
	if(head) {
		delete head;
		head = tail = temp = NULL;//初始化为空表
	}		
	for(int i = 1; i <= n; i++) {
		Append(i);//依次添加n个节点，编号为i
	}
}
void LinkCircle::RemoveTemp() {
	if(!temp)
		return;//如果temp为空，直接返回
	LinkNode *p = temp;
	if(head == temp) {
		//如果当前节点是头节点
		head = temp->next;
		temp->next->prev = tail;
		tail->next = head;
		temp = temp->next;
	}
	else if(tail == temp) {
		//如果当前节点是尾节点
		tail = temp->prev;
		temp->prev->next = head;
		head->prev = tail;
		temp = head;
	}
	else {
		//当前节点是中间节点
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		temp = temp->next;
	}
	delete p;
}
int LinkCircle::SolveJoesph(int n, int m) {
	Initialize(n);
	temp = head;
	while(temp->next != temp) {
		for(int i = 0; i < m - 1; i++)
			temp = temp->next;//当前位置开始从1报数到m
		RemoveTemp();//报数为m的猴子离队
	}
	return temp->id;
}


int main() {
	int n, m;
	cin >> n >> m;
	LinkCircle *test = new LinkCircle;
	cout << test->SolveJoesph(n, m) << endl;
	delete test;
	
	return 0;
}
