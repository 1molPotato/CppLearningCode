/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

//O(n)
int search(vector<int>& nums, int target) {
	auto it = find(nums.begin(), nums.end(), target);
	if(it != nums.end()) {
		return it - nums.begin();
	} else {
		return -1;
	}
}

/*
本来以为时间复杂度O(N)铁定是不让通过的，结果AC了...
不过随后还是开始思考有没有O(logN)的解法
此题的问题在于不是标准的升序排列,所以不能直接用二分搜索
由于已经知道数列可以被分为两段各自升序排列的数列，因此想到先找出两段数列的分界
然后判断target属于哪一段,紧接着再采用二分搜索
那么接下来的问题是如何快速找到两段数列的分界(逐个查找显然不行，因为光是找到分界就已经是O(N)的时间复杂度了)
仍然用二分的思想,AC代码如下
*/

int binary_search(vector<int>&, int, int, int);
int search(vector<int>& nums, int target) {
	size_t len = nums.size();
	if(len == 0 || (target > nums[len - 1] && target < nums[0])) { return -1; }
	if(nums[0] < nums[len - 1]) {
		return binary_search(nums, target, 0, len - 1);//已经是完全升序排列,直接搜索
	}
	int left = 0, right = len - 1;
	while(left < right) {
		int mid = (left + right) / 2;
		if(nums[mid] >= nums[0]) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	int boundary = nums[left] >= nums[0] ? left : left - 1;//分界处是数列中最大的数
	return target >= nums[0] ? binary_search(nums, target, 0, boundary) : binary_search(nums, target, boundary + 1, len - 1);
}

//search target in nums from index l to index r
int binary_search(vector<int>& nums, int target, int l, int r) {
	int left = l, right = r;
	while(left <= right) {
		int mid = (left + right) / 2;
		if(nums[mid] == target) {
			return mid;
		} else if(nums[mid] > target) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return -1;
}

/*
结果很气的是,Runtime和上面O(N)的解法一毛一样...只好灰溜溜去看讨论区的代码了
*/

//在寻找边界的同时进行二分搜索,斯国一
int search(vector<int>& nums, int target) {
	int len = nums.size();
	if(len == 0) return -1;
	int left = 0, right = len - 1;
	while(left < right) {
		int mid = (left + right) / 2;
		if(nums[mid] == target) return mid;
		
		if(nums[mid] > nums[right]) {
			//nums[mid] in the left part
			if(target > nums[right] && target < nums[mid]) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		} else if(nums[mid] < nums[left]) {
			//nums[mid] in the right part
			if(target < nums[left] && target > nums[mid]) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		} else {
			//no rotation
			if(target > nums[mid]) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
	}
	return nums[left] == target ? left : -1;
}
