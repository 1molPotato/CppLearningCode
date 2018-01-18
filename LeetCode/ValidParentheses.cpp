/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

/*
看到难度是easy自信地点进来然后又是一脸懵逼，关键是我前段时间还做过括号匹配的题
先马，今晚回去搞定
*/

bool isValid(string s) {
	int len = s.size();
	if(1 == len % 2)
		return false;
	if("{}" == s || "()" == s || "[]" == s)
		return true;
	if(s[0] == s[len - 1]) {
		return s.substr(0, len - 2);
	} else {
		// find a series of sub strings composing s, where each sub string is valid
		bool result = false;
		for(int i = 2; i <= len / 2; ++i) {

		}
	}
}

/*
想破头了
若s是括号匹配的字串，那么有以下两种情况：(len = s.size())
1.s[0] == s[len - 1]
	s的子串s.substr(1, len - 2)必定是括号匹配的字串
2.s[0] != s[len - 1]
	s可以拆分成两个及以上括号匹配的字串，这种情况较复杂，不好推广，思路也在这里中断了
*/
