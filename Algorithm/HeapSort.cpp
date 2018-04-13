/*
又给自己挖坑, 堆都还没看就想写堆排序
*/

/*
刚实现了heap, 现在回来填坑
因为堆只保证父节点一定小于子节点(以最小堆为例), 而不限制兄弟节点的大小关系, 所以表示堆的数组并非排好序的数组
然后我当即想了一个贼牛逼的算法
设要排序的数组是vector<int> arr
申请一个vector<int> res
建一个空堆heap
先把arr中的元素依次push到heap中
然后把heap依次pop的元素扔进res
哇
这大概是一个以空间时间加起来换智商的例子, 做到了既耗时又占存储, 斯国一
like an idiot
*/

// 正确的做法是堆化数组, 然后进行堆排序, 其实思路是类似的, 但是可以做到in place
// 来源: https://blog.csdn.net/morewindows/article/details/6709644, 稍作了修改

#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
void maxHeapFixdown(T arr[], int i, const int len) {
	// 调整以arr[i]为根节点的子树为最大堆
	int j = 2 * i + 1;// 左节点下标
	T temp = arr[i];// 临时存储根节点, 便于比较
	while(j < len) {
		// 至少有左节点
		if(j + 1 < len && arr[j + 1] > arr[j]) {
			// 有右节点, 取左右节点的大值
			++j;
		}
		if(arr[j] < temp) break;// 无须调整
		arr[i] = arr[j];
		i = j;
		j = 2 * i + 1;
	}
	arr[i] = temp;// 原根节点的最终位置
}

template <typename T>
void makeMaxHeap(T arr[], const int len) {
	// 堆化数组arr, 从最后一个叶节点的父节点开始处理
	for(int i = (len - 1) / 2; i >= 0; --i)
		maxHeapFixdown(arr, i, len);
}

template <typename T>
void maxHeapSortToAscend(T arr[], const int len) {
	// 利用最大堆使数组升序排列
	makeMaxHeap(arr, len); // 堆化数组
	for(int i = len - 1; i >= 0; --i) {
		swap(arr[0], arr[i]);
		maxHeapFixdown(arr, 0, i);
	}
}

// test program
int main() {
	int arr[] = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
	int len = (int) sizeof(arr) / sizeof(*arr);
	maxHeapSortToAscend(arr, len);
	for(int i = 0; i < len; i++)
		cout << arr[i] << ' ';
	cout << endl;
	return 0;
}




