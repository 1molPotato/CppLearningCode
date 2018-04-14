/*
自己实现了一个单向链表
采用了指向链表头的头节点,方便维护数据
下面的测试程序测试了在任意位置插入或删除链表中的节点,用一组随机值初始化一定数量的节点,翻转链表(明天写)
关注到了内存的动态分配和销毁
*/

#include <iostream>
#include <ctime>
#include "List.h" // List class definition
using namespace std;

const int BOUND = 100;// randomly generate numbers in [0,BOUND-1)

// set elements in arr to random numbers in [0, BOUND-1)
void makeArray(int arr[], const int len) {	
	srand((unsigned int)time(NULL));
	for(int i = 0; i < len; ++i) arr[i] = rand() % BOUND;
}

// instructions of test program
void instructions() {
	cout << "\nEnter one of the following:\n"
		<< " 1 to insert a number at a position\n"
		<< " 2 to delete a number at a position\n"
		<< " 3 to reverse the list\n"
		<< " 4 to print elments in the list one by one\n"
		<< " 5 to randomly initialize the list with the size you input\n"
		<< " 6 to end this program\n";
}

void testList(LinkList &list){
	cout << "---------Test Program for Link List-----------\n"
	 << "                             ——designed by lky\n\n";
	instructions();// display instructions

	int choice;// store user's choice
	int value;// store input number
	int pos;// store the position

	do {
		cout << "? ";
		cin >> choice;// user input the choice

		switch(choice) {
		case 1:
			cout << "\nEnter a number you want to be inserted and its postion(i)\n"
				<< " if i = 0, the number will be inserted as the head\n"
				<< " if |i| > length of the list, the number will be inserted as tail\n"
				<< " if i > 0, the number will be inserted after the ith node\n"
				<< " if i < 0, the number will be inserted after the |i|th node from bottom\n"
				<< " The number and position: ";
			cin >> value >> pos;
			list.insertNode(value, pos);
			cout << "\nAfter your operation, the list is:\n";
			list.printList();
			break;
		case 2:
			cout << "\nEnter the postion(i) of node you want to be deleted\n"
				<< "if i = 0 or |i| > length of the list, the last node will be deleted\n"
				<< "if i > 0, the ith node will be deleted\n"
				<< "if i < 0, the |i|th node from the bottom will be deleted\n"
				<< "The position: ";
			cin >> pos;
			if(list.deleteNode(value, pos))
				cout << "\nThe value of the deleted node is: " << value << '\n' 
					<< "After your operation, the list is:\n";
			list.printList();
			break;
		case 3:
			break;
		case 4:
			cout << "For now, the list is:\n";
			list.printList();
			break;
		case 5:
			cout << "Enter the size of the list to initialize: ";
			cin >> value;
			list.clear();		
			int *arr = new int[value];
			makeArray(arr, value);// randomly set values in array
			for(int i = 0; i < value; ++i) {
				list.insertNode(arr[i]);
			}
			cout << "After initialization, the list is:\n";
			list.printList();
			delete[] arr;
		}
	} while(choice >= 0 && choice < 6);
}

// test program
int main() {
	LinkList *list = new LinkList;
	testList(*list);
	delete list;
	return 0;
}
