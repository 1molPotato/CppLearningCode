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
i    dp[i]					state transition		
0    {}						-
1	 {}						-
2	 {{2}}					dp[0] + {2}
3	 {{3}}					dp[0] + {3}
4	 {{2,2}}				dp[2] + {2}
5	 {{2,3}}				dp[2] + {3}
6	 {{2,2,2},{3,3},{6}}	dp[4] + {2} and dp[3] + {3} and dp[0] + {6}
7	 {{2,2,3},{7}}			dp[4] + {3} and dp[0] + {7}
...

需要注意的是,解集中不应包含重复的解,例如{2,2,3}和{2,3,2},它们分别是dp[4] + {3}和dp[5] + {2}
为了避免这种重复解,默认所有解都按升序排列
leetcode上的AC码如下,runtime为23ms
************动态规划***********
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
// Time complexity: O(n * target) —— n = candidates.size()


/*
**********回溯法***********


**********回溯法***********
*/
