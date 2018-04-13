/*
堆(Heap)是完全二叉树,因此可以用数组来实现,关键的操作在上滤(percolate up)和下滤(percolate down)
自己简单实现了一下,用了std::vector,因为太懒了
*/

#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
class Heap {
public:
	Heap();
	void push(const T &x);
	void pop();
	bool empty();
	size_t size();
private:
	void percolate_up();
	void percolate_down();
private:
	vector<T> _a; // _a[i] is the ith node, _a[0] is the number of nodes
};

template <typename T>
Heap<T>::Heap() {
	_a.push_back(0);
}

template <typename T>
void Heap<T>::push(const T &x) {
	_a.push_back(x); 
	++_a[0];
	percolate_up(); // adjust to satisfy heap's rule	
}

template <typename T>
void Heap<T>::pop() {
	if(empty()) return;
	swap(_a[1], _a.back()); // swap root and the last node
	_a.pop_back(); // delete last(which was root)
	--_a[0]; // number of nodes - 1
	percolate_down(); // adjust to satisfy heap's rule	
}

template <typename T>
void Heap<T>::percolate_up() {
	size_t k = _a[0];
	while(k > 1 && _a[k] < _a[k / 2]) {
		swap(_a[k], _a[k / 2]);
		k /= 2;
	}
}

template <typename T>
void Heap<T>::percolate_down() {
	size_t k = 1;
	while(2 * k < _a[0]) {
		// the kth node still has two child
		if(_a[k] <= min(_a[2 * k], _a[2 * k + 1])) {
			break;
		} else {
			if(_a[2 * k] < _a[2 * k + 1]) {
				swap(_a[k], _a[2 * k]);
				k = 2 * k;
			} else {
				swap(_a[k], _a[2 * k + 1]);
				k = 2 * k + 1;
			}
		}
	}
	if(2 * k == _a[0]) {
		// the kth node has only one child(left child)
		if(_a[k] > _a[2 * k]) {
			swap(_a[k], _a[2 * k]);
		}
	}
}

template <typename T>
bool Heap<T>::empty() {
	return !_a[0]; // if a[0] = 0, return true, else return false
}

template <typename T>
size_t Heap<T>::size() {
	return _a[0];
}

// test program
int main() {
	Heap<int> heap;
	for(int i = 10; i > 0; --i) heap.push(i);
	while(!heap.empty()) {
		heap.pop();
	}
	return 0;
}
