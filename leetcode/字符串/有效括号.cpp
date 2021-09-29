/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。

1 <= s.length <= 104
s 仅由括号 '()[]{}' 组成
*/

class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 != 0) {
            return false;
        }

        unordered_map<char, char> map = {
            {'(', ')'},
            {')', '('},
            {'{', '}'},
            {'}', '{'},
            {'[', ']'},
            {']', '['}
        };

        stack<char> mystack;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                mystack.push(s[i]);
            } else {
                if (mystack.empty()) {
                    return false;
                }

                if (map[s[i]] != mystack.top()) {
                    return false;
                }

                mystack.pop();
            }
        }

        return mystack.empty();
    }
};