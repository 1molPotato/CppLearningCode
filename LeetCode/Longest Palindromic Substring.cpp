/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
*/

/*
求最长回文子串，这道题总算让我明白了算法的重要性，6次Time Limit Exceeded终于让我意识到暴力枚举和递归是行不通的
下面先给出中心扩展法的解，也是看了半天解题思路才写完最后AC的，时间复杂度是O(n^2)，接下来准备理解一下DP（动态规划）和马拉车算法
*/

// Expand around center method
// 回文串的特点是关于中心对称（偶数个数时中心在最中间两个字符之间），设字符串s长度为n，则共有2n-1个中心
string longestPalindrome(string s) {
	if(s.size() < 2) {
		return s;
	}	
	string ls = "";
	int len = s.size();
	int left, right;

	// for each "index i" center, (len) in total
	for(int i = 1; i < len - 1; ++i) {		
		for(left = i - 1, right = i + 1; left >= 0 && right < len; --left, ++right) {
			if(s[left] != s[right]) {
				break;
			}
		}
		++left;
		--right;
		ls =  s.substr(left, right - left + 1).size() > ls.size() ? s.substr(left, right - left + 1) : ls;
	}

	// for each "mid of index i and i+1" center, (len - 1) in total
	for(int i = 0; i < len - 1; ++i) {
		for(left = i, right = i + 1; left >= 0 && right < len; --left, ++right) {
			if(s[left] != s[right]) {
				break;
			}
		}
		++left;
		--right;
		ls =  s.substr(left, right - left + 1).size() > ls.size() ? s.substr(left, right - left + 1) : ls;
	}
	return ls;
}

// 和"别人的代码"对比之后发现还是写得太丑了，整改如下，最终AC的Runtime为16ms，一高兴提交了三次

string longestPalindrome(string s) {
	int start = 0, len_ls = 0;
	for(int i = 0; i < s.size(); ++i) {
		int len1 = expandAroundCenter(s, i, i);
		int len2 = expandAroundCenter(s, i, i + 1);
		if(len_ls < max(len1, len2)) {
			len_ls = max(len1, len2);
			start = i - (len_ls - 1) / 2;
		}
	}
	return s.substr(start, len_ls);
}

int expandAroundCenter(const string &s, int left, int right) {
	while(left >= 0 && right < s.size() && s[left] == s[right]) {
		--left;
		++right;
	}
	return right - left - 1;
}

/*
Dynamic Programming(动态规划)是指将原问题拆分成更易求解的子问题，并将求解子问题的结果记忆化存储，避免重复求解
例如在对字符串"ababa"求解最长回文子串时，若已经求得"bab"是回文串，则"ababa"是否是回文串只取决于"a"和"a"是否相等
具体实现可以用n * n大小的bool数组dp[][]来存储子问题的解，若s[i],s[i+1],...,s[j]是回文串，则dp[i][j] = true
下面给出实现代码，AC的Runtime为99ms，感觉优化远远不够，有时间再分析一下原因
*/

string longestPalindrome(string s) {
	int len = s.size();
	// s.substr(i, j - i + 1) is a palindrome if dp[i][j] == true 
	bool *dp = new bool[len * len];// dynamic memory allocation
	
	//initialize value in array
	for(int k = 0; k < len * len; ++k) {
		dp[k] = false;
	}
	
	//int start record the begin position of lps
	//int len_ls record the length of lps
	int start = 0, len_ls = 0;
	for(int i = 0; i < len; ++i) {
		for(int j = 0; j < len - i; ++j) {
			if(0 == i) {
				// dp[i][i] = true;
				dp[j * len + j] = true;
			} else if(1 == i) {
				// dp[i][i + 1] = (s[i] == s[i + 1])
				dp[j * len + j + 1] = (s[j] == s[j + 1]); 
			} else {
				// dp[i][j] = (s[i] == s[j]) and dp[i + 1][j - 1]
				dp[j * len + j + i] = (s[j] == s[j + i]) && dp[(j + 1) * len + j + i - 1];
			}
			if(dp[j * len + j + i] && len_ls < i + 1) {
				start = j;
				len_ls = i + 1;
			}
		}
	}
	delete[]dp;// release the memory allocated dynamicly
	return s.substr(start, len_ls);
}
