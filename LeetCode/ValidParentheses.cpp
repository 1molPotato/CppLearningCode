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
			//搞不定啊搞不定啊
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

/*
换了一种思路总算AC
我比较蠢用3个vector<int>来记录3种括号的匹配情况，如遇到左括号则将下标push到相应数组，如遇到右括号则判定是否合法
如果不合法则直接返回false，如果合法则从相应数组pop，下面给出代码，冗长程度不忍直视
*/

bool isValid(string s) {
	if(1 == s.size() % 2)
		return false;
	vector<int> count[3];
	int last = 0;
	bool flag = true;
	for(int i = 0; i < s.size(); ++i) {
		switch(s[i]) {
		case '(':
			count[0].push_back(i);
			break;
		case '{':
			count[1].push_back(i);
			break;
		case '[':
			count[2].push_back(i);
			break;
		case ')':
			if(count[0].empty())
				return false;
			if(!count[1].empty() && count[0].back() < count[1].back()) {
				return false;
			}
			if(!count[2].empty() && count[0].back() < count[2].back()) {
				return false;
			}
			count[0].pop_back();
			break;
		case '}':
			if(count[1].empty())
				return false;
			if(!count[0].empty() && count[1].back() < count[0].back()) {
				return false;
			}
			if(!count[2].empty() && count[1].back() < count[2].back()) {
				return false;
			}
			count[1].pop_back();
			break;
		case ']':
			if(count[2].empty())
				return false;
			if(!count[0].empty() && count[2].back() < count[0].back()) {
				return false;
			}
			if(!count[1].empty() && count[2].back() < count[1].back()) {
				return false;
			}
			count[2].pop_back();
			break;
		default:
			break;
		}
	}
	if(count[0].empty() && count[1].empty() && count[2].empty())
		return true;
	else
		return false;
}

/*
然后！一看"别人的代码"，瞬间醒悟为什么不用stack，学半天数据结构不就是为了这时候用吗
选择堆栈作为括号字符的容器，遇到左括号则入栈，遇到右括号则判断是否与栈顶元素匹配，否则返回false
是则将栈顶元素弹出，继续循环，直至遍历完s中的所有字符，太精妙了！
*/

bool isValid(string s) {
	if(1 == s.size() % 2)
		return false;// 括号匹配的字串长度不可能是奇数
	stack<char> stk;// 栈作为容器
	for(char &c : s) {
		if(c == '(' || c == '{' || c == '[') {
			stk.push(c);// 遇左括号则入栈
		} else {
			if(stk.empty()) {
				return false;// 右括号先出现则返回false
			} else {
				char top = stk.top();
				if((c == ')' && top != '(') || (c == '}' && top != '{')
					|| (c == ']' && top != '[')) {
					return false;// 右括号与栈顶元素不匹配则返回false
				}
				stk.pop();// 栈顶弹出
			}
		}
	}
	return stk.empty();// 栈为空则说明匹配成功
}

