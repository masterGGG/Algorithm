/*
思路：栈+哈希表
*/
class Solution {
public:
    unordered_map<char, char> pairs = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 == 1) {
            return false;
        }

        stack<char> stack_;
        for (char ch: s) {
            if (pairs.count(ch)) {
                if (stack_.empty() || stack_.top() != pairs[ch]) {
                    return false;
                }
                stack_.pop();
            } else {
                stack_.push(ch);
            }
        }
        return stack_.empty();
    }
};
/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。

1 <= s.length <= 104
s 仅由括号 '()[]{}' 组成
*/