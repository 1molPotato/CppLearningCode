/*
要面鹅厂好紧张哦好怕被当面羞辱, 先练下归排吧, 源码来自wiki, 稍作修改并加了注释
*/

#include <algorithm>
using namespace std;

template<typename T>
void merge_sort_recursive(T arr[], T reg[], int start, int end) {
	if(start >= end) return; // 0 or 1 element, no need to sort
	int len = end - start, mid = len / 2 + start;
	int start1 = start, end1 = mid; // left subarr
	int start2 = mid + 1, end2 = end; // right subarr
	merge_sort_recursive(arr, reg, start1, end1); // recursively sort left subarr
	merge_sort_recursive(arr, reg, start2, end2); // recursively sort right subarr
	// merge left subarr and right subarr
	int k = start;
	while(start1 <= end1 && start2 <= end2) // put element of left subarr and right subarr in reg orderly
		reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
	while(start1 <= end1) // if there are elements remained in left subarr, put all of them in reg
		reg[k++] = arr[start1++];
	while(start2 <= end2) // similarly
		reg[k++] = arr[start2++];
	for(k = start; k <= end; ++k)
		arr[k] = reg[k]; // copy reg's content to arr
}

template<typename T>
void merge_sort(T arr[], const int len) {
	T *reg = new T[len];
	merge_sort_recursive(arr, reg, 0, len - 1);
	delete[] reg;
}

template<typename T>
void merge_sort_iteration(T arr[], const int len) {
	T *a = arr;
	T *b = new T[len];
	for(int seg = 1; seg < len; seg += seg) {
		// seg is length of each sequence, iteration will end when seg = len, that is the arr has been sorted
		for(int start = 0; start < len; start += seg + seg) {
			// start will cross two segments each time
			int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len); // in case out of bound
			int k = low;
			int start1 = low, end1 = mid - 1;
			int start2 = mid, end2 = high - 1;
			while(start1 <= end1 && start2 <= end2) 
				b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
			while(start1 <= end1)
				b[k++] = a[start1++];
			while(start2 <= end2)
				b[k++] = a[start2++];
		}
		// swap array a and array b
		// attention, this operation may lead to a and arr don't point to the same array
		T *temp = b;
		b = a;
		a = temp;
	}
	if(a != arr) {
		// in this case, b and arr point to the same array
		for(int i = 0; i < len; ++i) b[i] = a[i];
		b = a; // let b point to a, which can be deleted
	}
	delete[] b;
}

// test program
int main() {
	int arr[] = { 4,3,1,6,5 };
	int len = sizeof(arr) / sizeof(int);
	//merge_sort(arr, 8);
	merge_sort_iteration(arr, len);
	return 0;
}
