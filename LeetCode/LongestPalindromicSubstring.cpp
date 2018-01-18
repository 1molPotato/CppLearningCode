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
