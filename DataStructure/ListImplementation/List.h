// LinkList class definition
// Author: Lv_Kaiyuan
// Email: lky.hoooo94@gmail.com
#include <iostream>
#ifndef LIST_H
#define LIST_H

struct ListNode {
	explicit ListNode(int _val = 0):val(_val), next(nullptr){}
	//ListNode *prev;
	ListNode *next;
	int val;
};

class LinkList {
public:
	// constructor
	LinkList() : dummyHead(new ListNode), tail(nullptr), len(0){
		// empty
	}

	// destructor
	~LinkList() {	
		std::cout << "Destroying nodes...\n";
		clear();// delete all elements	
		delete dummyHead;
	}

	// delete all nodes in list
	void clear() {		
		ListNode *curr = dummyHead->next;
		ListNode *temp = NULL;
		while(curr){
			temp = curr;
			curr = curr->next;
			std::cout << temp->val << ' ';
			delete temp;
		}
		std::cout << "\nAll nodes above has been destroyed\n";
	}

	// check whether the list is empty
	bool isEmpty() {
		return len == 0;
	}

	// insert val_ to the right position, pos = 0 means insert as head
	// if pos > 0, pos = i means insert after the ith node
	// if pos < 0, pos = i means insert after the |i|th node from bottom
	void insertNode(int value, int pos = -1) {		
		ListNode *newNode = getNewNode(value);
		pos = pos < 0 ? (len + pos + 1) : pos;
		pos = pos > len || pos < 0 ? len : pos;
		if(pos == len) {
			// insert new node as tail, including the case len = 0
			isEmpty() ? dummyHead->next = newNode : tail->next = newNode;
			tail = newNode;
		} else {
			ListNode *curr = dummyHead;
			while(pos--) curr = curr->next;
			newNode->next = curr->next;
			curr->next = newNode;
		} 
		len++;// length of list + 1
	}

	// delete node at the right position
	// pos = i means delete the ith node, pos = -1 and pos > len both means delete tail
	bool deleteNode(int &value, int pos = -1) {
		pos = pos < 0 ? (len + pos + 1) : pos;
		pos = pos > len || pos <= 0 ? len : pos;
		if(isEmpty()) {
			std::cout << "The list has been empty, no node could be deleted\n";
			return false;
		} else {
			ListNode *curr = dummyHead;
			while(pos-- > 1) curr = curr->next;
			ListNode *temp = curr->next;
			curr->next = temp->next;
			value = temp->val;// return the value of deleted node
			delete temp;
		}
		len--;// length of list - 1
		return true;
	}

	// reverse the list
	void reverseList() {
		// empty
	}

	// print nodes in list
	void printList() {
		ListNode *curr = dummyHead->next;
		while(curr) {
			std::cout << curr->val << ' ';
			curr = curr->next;			
		}
		std::cout << "\n";
	}
private:
	// return a new node with _val
	ListNode * getNewNode(int _val) {
		return new ListNode(_val);
	}
private:
	ListNode *dummyHead;// not the real head, the dummyHead's next node is the first node
	ListNode *tail;// last node
	int len;// number of nodes
};

#endif