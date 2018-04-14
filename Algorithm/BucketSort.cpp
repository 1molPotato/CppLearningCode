/*
桶排序,今天最后一个坑
*/

/*
结果还是拖到了第二天, 原因是昨天看了桶排序的原理有点让我失望, 感觉很蠢
...
然后发现链表都写不顺所以就睡了...
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

const int BOUND = 1000;// 排序的数限制在[0,999)
const int BUCKET_NUM = 10;// 10个桶

struct ListNode {
	explicit ListNode(int _val = 0):val(_val), next(NULL){}
	ListNode *next;
	int val;
};

ListNode *insertNode(ListNode *head, int _val) {
	ListNode *newNode = new ListNode(_val);
	ListNode dummy;// 前置节点, 方便处理头节点为空的情况
	dummy.next = head;
	ListNode *pNode = &dummy;
	while(pNode->next && pNode->next->val <= _val) 
		pNode = pNode->next;
	newNode->next = pNode->next;
	pNode->next = newNode;
	return dummy.next;
}

// 这里我写了两个insert函数, 原因在于我第一次写了一个没有用二级指针, 也没有返回头节点指针的函数
// 毫无疑问就是插入之后没有任何变化, 因为它只传了"指针的值", 所以对指针自身的操作都是无效的
// 所以现在把两个函数都保留, 它们实现的功能是一样的

void insertNode(ListNode **head, int _val) {
	ListNode *newNode = new ListNode(_val);
	ListNode dummy;
	dummy.next = *head;
	ListNode *pNode = &dummy;
	while(pNode->next && pNode->next->val <= _val)
		pNode = pNode->next;
	newNode->next = pNode->next;
	pNode->next = newNode;
	*head = dummy.next;// 利用二级指针才能效地给一级指针赋值
}

void printNode(ListNode *head) {
	ListNode *pNode = head;
	while(pNode) {
		cout << pNode->val << ' ';
		pNode = pNode->next;
	}
	cout << endl;
}

// 在[0,BOUND)内随机生成一堆数赋值给数组
void makeArray(int arr[], const int len) {	
	srand((unsigned int)time(NULL));
	for(int i = 0; i < len; ++i) 
		arr[i] = rand() % BOUND;
}

// 这个函数没作用, 是自己测试插入节点的时候写的
ListNode *makeList() {
	int arr[20] = { 0 };
	int len = (int) sizeof(arr) / sizeof(*arr);
	makeArray(arr, len);
	ListNode *head = new ListNode(arr[0]);
	for(int i = 1; i < len; i++) {
		//head = insertNode(head, arr[i]);
		insertNode(&head, arr[i]);
	}
	printNode(head);
	while(head) {
		ListNode *p = head;
		head = head->next;
		delete p;
	}
	return head;
}

void bucket_sort(int arr[], const int len) {	
	vector<ListNode*> buckets(BUCKET_NUM, NULL);// 每个桶是一个链表
	
	// 将数组中的数按区间装入桶内，并在桶内排序
	for(int i = 0; i < len; ++i) {
		int index = arr[i] / (BOUND / BUCKET_NUM);
		insertNode(&buckets[index], arr[i]);
	}

	// 将每个桶中链表里的值传回数组，并删除节点
	int k = 0;
	for(ListNode *bucket : buckets) {
		ListNode **curr = &bucket;// 这里用了李纳斯大婶用二级指针销毁链表节点的方法, 但是我没看懂原理其实, 改天再说吧...
		while(*curr) {
			ListNode *p = *curr;
			*curr = p->next;
			arr[k++] = p->val;
			delete p;
		}
	}
}

// test program
int main() {
	int arr[50] = { 0 };
	int len = (int) sizeof(arr) / sizeof(*arr);
	makeArray(arr, len);
	bucket_sort(arr, len);

	return 0;
}
