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
从备选数组中挑选出的所有和为i的数字组合


******Dynamic Programming******
*/

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	sort(candidates.begin(), candidates.end());
	vector<vector<vector<int>>> dp; // dp[i] is the solution set when target = i
	vector<vector<int>> ini; // empty set
	for(int i = 0; i <= target; ++i) {
		dp.push_back(ini);
		for(int item : candidates) {
			if(item == i) {
				vector<int> ans = { item };
				dp[i].push_back(ans);
			}
			if(item < i) {
				for(vector<int> solu : dp[i - item]) {
					if(item <= solu.back()) {
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
**********回溯法**********


*******Backtracking*******
*/
