/*
Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]
*/

/*
************动态规划***********
状态的定义:
设dp[i]是target = i时的解,它表示
从备选数组中挑选出的,所有和为i的数字组合,例如对candidates = {2, 3, 6, 7}
dp[0] = {}, dp[1] = {}, dp[2] = {{2}},..., dp[7] = {{2,2,3}, {7}}
状态转移方程:
状态i能够由此前的状态得到,例如
dp[7] = {(each item in dp[7-3]).append(3), (each item in dp[7-7]).append(7)},而
dp[7-3] = dp[4] = {(each item in dp[4-2]).append(2)}
dp[4-2] = dp[2] = {(each item in dp[2-2]).append(2)}
dp[2-2] = dp[0] = {}

下面是i从0到7的解:
i    	 dp[i]				state transition		
0	 {}				-
1	 {}				-
2	 {{2}}				dp[0] + {2}
3	 {{3}}				dp[0] + {3}
4	 {{2,2}}			dp[2] + {2}
5	 {{2,3}}			dp[2] + {3}
6	 {{2,2,2},{3,3},{6}}		dp[4] + {2} and dp[3] + {3} and dp[0] + {6}
7	 {{2,2,3},{7}}			dp[4] + {3} and dp[0] + {7}
...

需要注意的是,解集中不应包含重复的解,例如{2,2,3}和{2,3,2},它们分别是dp[4] + {3}和dp[5] + {2}
为了避免这种重复解,默认所有解都按升序排列
leetcode上的AC码如下,runtime为23ms
*/

// dynamic programming
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<vector<int>>> dp; // dp[i] is the solution set when target = i
	vector<vector<int>> ini; // empty set
	for(int i = 0; i <= target; ++i) {
		dp.push_back(ini);
		for(int item : candidates) {
			if(item == i) {
				// special case
				vector<int> ans = { item };
				dp[i].push_back(ans);
			}
			if(item < i) {
				// for each solution "solu" in dp[i - item], 
				// if item is bigger than last number in "solu"
				// append item to "solu"
				for(vector<int> solu : dp[i - item]) {
					if(item >= solu.back()) {
						solu.push_back(item);
						dp[i].push_back(solu);
					}
				}
			}
		}
	}
	return dp[target];
}

/*
Time complexity: O(n * target) —— n = candidates.size()
************动态规划***********
*/


/*
**********回溯法***********
回溯法属于暴力搜索法的一种,其本质是对解空间的深度优先搜索算法
仍然将candidates = {2,3,6,7},target = 7作为例子,搜索所有满足和为7的解集
target = 7作为根节点,第一步先搜索解集的第一个元素为2的情况,对2之后的元素,是target = 5时的解集
于是向下搜索第二个元素为2的情况,其后的元素是target = 3时的解集
接着向下搜索第三个元素为2的情况,使得target = 1,1 < 2因此不是要求的解,于是回溯到父节点
搜索第三个元素为3的情况,使得target = 0,表示到达满足要求的叶节点,将此条路径上的节点值{2,2,3}作为解集之一添加到结果中
接着回溯到父节点搜索第二个元素为2的情况...依次进行

原理是,只要满足要求就继续搜索子节点,遇到无解的情况便丢掉这个结果,返回父节点进行下一个子节点的搜索,整个搜索树可以表示如下
			    (7)
			     |
	  |----------------|--------------|-----------| 
	 2(5)	          3(4)           6(1)        7(0)
          |                |             no          yes
    |-----|-----|       |-----|
   2(3)  3(2)  ...     3(1)  ...
   yes   no    no      no     no
括号内的数表示搜索下一层节点时的target
回溯法常用递归实现,leetcode讨论版上的代码如下
*/

//backtracking method
class Solution {
public:
	std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
		std::sort(candidates.begin(), candidates.end()); //升序排列
		std::vector<std::vector<int> > res;
		std::vector<int> combination;
		combinationSum(candidates, target, res, combination, 0);
		return res;
	}
private:
	void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
		if(target == 0) {
			res.push_back(combination); //搜索到达满足条件的叶节点,将解添加到解集中
			return;
		}
		//保持解集中的元素按升序排列,避免重复解并且减少搜索数目
		for(int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
			combination.push_back(candidates[i]); //更新该层节点的临时解
			combinationSum(candidates, target - candidates[i], res, combination, i); //递归搜索子节点
			combination.pop_back(); //回溯到父节点的临时解
		}
	}
};

/*
**********回溯法***********
*/
