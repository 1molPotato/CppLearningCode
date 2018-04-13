/*
接下来是快排,先照着wiki上的伪码算法自己写了一个,非原地(in place)版本
*/

// start of quick sort algorithm, non-in-place version, by myself
#include <vector>
using namespace std;

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

