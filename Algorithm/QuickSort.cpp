/*
接下来是快排,先照着wiki上的伪码算法自己写了一个,非原地(in place)版本
*/

#include <vector>
#include <algorithm>
using namespace std;

// start of quick sort algorithm, non-in-place version, by myself
template<typename T>
vector<T> joint(vector<T> &v1, vector<T> &v2, vector<T> &v3) {
	vector<int> res;
	for(T item : v1) res.push_back(item);
	for(T item : v2) res.push_back(item);
	for(T item : v3) res.push_back(item);
	return res;
}

template<typename T>
vector<T> quick_sort(vector<T> &arr) {
	if(arr.size() < 2) return arr; // no need to sort
	vector<T> less, pivotList, greater;
	int pivotIndex = arr.size() / 2; // 暂时不知道pivot要怎么选, 这里是取数组的中点
	for(int i = 0; i < arr.size(); ++i) {
		if(i != pivotIndex) {
			arr[i] < arr[pivotIndex] ? less.push_back(arr[i]) : greater.push_back(arr[i]);
		}
	}
	pivotList.push_back(arr[pivotIndex]);
	return joint(quick_sort(less), pivotList, quick_sort(greater));
}
// end of quick sort algorithm, non-in-place version, by myself

// start of quick sort algorithm, in-place version, by myself
template<typename T>
int partition(T arr[], int left, int right, int pivotIndex) {
	T pivotValue = arr[pivotIndex];
	swap(arr[pivotIndex], arr[right]); // move pivot to the tail
	int storeIndex = left; // stored as pivotIndex to return
	for(int i = left; i < right; ++i) {
		// move element less than pivot to the left(not in order)
		if(arr[i] <= pivotValue) swap(arr[storeIndex++], arr[i]);
	}
	swap(arr[right], arr[storeIndex]); // move pivot back to its place
	return storeIndex;
}

template<typename T>
void quick_sort(T arr[], int left, int right) {
	if(right > left) {
		// if right <= left, only 0 or 1 element, no need to sort
		int pivotIndex = (right + left) / 2; // still don't know how to choose pivot
		int pivotNewIndex = partition(arr, left, right, pivotIndex);
		quick_sort(arr, left, pivotNewIndex - 1); // recursively call quick_sort for left part
		quick_sort(arr, pivotNewIndex + 1, right); // similarly, for right part
	}
}
// end of quick sort algorithm, in-place version, by myself

// 原地版本, 但是pivot的选取仍未做考虑, 接下来看看wiki上的标准实现方法

