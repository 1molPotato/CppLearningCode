/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

/*
对n对括号而言(即长度为2n的字符串),第一时间的想法是枚举所有括号数组,共2^(2n)种,然后依次判断
每个括号数组是否是括号匹配的,若匹配则加入到结果中
判断是否括号匹配很简单(实际上也是因为之前做过),但是如何生成2^(2n)个括号数组,这个问题击碎了
我薄弱的智商,直到看了solution才反应过来需要递归来实现(而且还理解了半天...我摔)
*/

//recursive function to generate all strings
void generate(vector<string> &ans, string &current, int pos){
	// ans,储存所有结果的可变长字符串数组
	// current,长度为2n的字符串
	// pos,从0开始的下标
	if(pos == current.size()){
		ans.push_back(current);
	}else{
		current[pos] = '(';
		generate(ans, current, pos + 1);
		current[pos] = ')';
		generate(ans, current, pos + 1);
	}
}
/*
以n = 2为例解释上述递归函数的原理
递归循环终止条件是pos = current.size(),在这里也就是pos = 4
初始条件ans = {}, current = "    ", pos = 0;
调用函数generate(ans, current, 0)
current[0] = '(';// current = "(   ";
generate(ans, current, 1)进入第一层递归
	current[1] = '(';// current = "((  ";
	generate(ans, current, 2)进入第二层递归
		current[2] = '(';// current = "((( ";
		generate(ans, current, 3)进入第三层递归
			current[3] = '(';// current = "((((";
			generate(ans, current, 3)进入第四层递归
				pos = 4, ans.push_back(current);// ans = {"(((("}
				结束第四层递归,退回第三层递归
			current[3] = ')';// current = "((()";
			generate(ans, current, 3)进入第四层递归
				pos = 4, ans.push_back(current);// ans = {"((((", "((()"}
				结束第四层递归,退回第三层递归
			结束第三层递归,退回第二层递归
		current[2] = ')';// current = "(() ";
		generate(ans, current, 3)进入第三层递归
			current[3] = '(';// current = "(()(";
			generate(ans, current, 3)进入第四层递归
				pos = 4, ans.push_back(current);// ans = {"((((", "((()", "(()("}
				结束第四层递归,退回第三层递归
			current[3] = ')';// current = "(())";
			generate(ans, current, 3)进入第四层递归
				pos = 4, ans.push_back(current);// ans = {"((((", "((()", "(()(", "(())"}
				结束第四层递归,退回第三层递归
...
最终得到
ans = {"((((", "((()", "(()(", "(())", "()((", "()()", "())(", 
	"()))", ")(((", ")(()", ")()(", ")())", "))((", "))()", ")))(", "))))"}
*/

/*
对于本道题,上述做法的开销是不必要的
首先,显然n对括号组成的字符串并不是2^(2n)种情况,而只有组合数C(2n,n)种情况,
在枚举的过程中判定是否满足括号匹配的原则,则情况将更少一些
因此可采用回溯法(backtracking)解这道题
*/

//backtracking method
void backtracking(vector<string>&, int, int, string&);//declare prototype
vector<string> generateParenthesis(int n){
	vector<string> ans;
	if(n < 1)
		return ans;
	string current(2 * n, ' ');
	backtracking(ans, 0, 0, current);
	return ans;
}

void backtracking(vector<string> &ans, int left, int right, string &current){
	//left,字符串中已有'('的数目
	//right,字符串中已有')'的数目
	int n = current.size() / 2;
	if(left == n && right == n){
		ans.push_back(current);
		return;
	}
	if(left > right){
		//current中'('数量大于')'的数量,则加上')'并进入下一层递归
	backtracking(ans, left, right + 1, current + ')', n);
	}
	if(left < n){
		//current中'('数量小于n,则加上'('并进入下一层递归
	backtracking(ans, left + 1, right, current + '(', n);
	}
}

/*
回溯仍然是暴力搜索法的一种,接下来学习DP——动态规划解法(怎么哪儿都有你)
*/

/*
DP(Dynamic Programming),也即动态规划,其核心在于状态的定义和状态转移方程的定义
1.状态的定义
dp[n]为n对括号的所有满足要求的组合
显然有dp[0] = {""}, dp[1] = {"()"}
2.状态转移方程的定义
对dp[i], 1 <= i <= n, 有:
dp[i] = '(' + dp[j] + ')' + dp[i - j - 1], 0 <= j < i
故只要已经求解了dp[k], k < i, 那么dp[i]即可通过上面的方程得到
已知dp[0] = {""}, 于是便可以迭代求解得到dp[n]
*/

//dynamic programming method
vector<string> generateParenthesis(int n) {
	vector<string> empty;
	vector<vector<string>> dp(n + 1, empty);
	dp[0].push_back("");
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < i; ++j) {
			for(string s1 : dp[j]) {
				for(string s2 : dp[i - j - 1]) {
					dp[i].push_back("(" + s1 + ")" + s2);
				}
			}
		}
	}
	return dp[n];
}

//两种方法的时间复杂度都是O(4^n/sqrt(n)), 调试n > 10时运行时间已经明显较长, 指数时间复杂度相当恐怖!



