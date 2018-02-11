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
此题的问题在于不是标准的升序排列，所以不能直接用二分搜索
由于已经知道数列可以被分为两段各自升序排列的数列，因此想到先找出两段数列的分界
然后判断target属于哪一段，紧接着便可以采用二分搜索
那么接下来的问题是如何快速找到两段数列的分界(逐个查找显然不行，因为光是找到分界就已经是O(N)的时间复杂度了)

*/
