//辅助栈记录 左括号的位置
class Solution {
public:
    int longestValidParentheses(string s) {
        int max = 0;
        stack<int> stack_;
        stack_.push(-1);

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                stack_.push(i);
            } else {
                stack_.pop();

                if (stack_.empty()) {
                    stack_.push(i);
                } else {
                    if (max < i - stack_.top()) {
                        max = i - stack_.top();
                    }
                }
            }
        }

        return max;
    }
};

//g++ 32-m-最长有效括号.cpp -o xxx -std=c++11

/*
给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。

示例 1：
输入：s = "(()"
输出：2
解释：最长有效括号子串是 "()"
示例 2：
输入：s = ")()())"
输出：4
解释：最长有效括号子串是 "()()"
示例 3：
输入：s = ""
输出：0

提示：
0 <= s.length <= 3 * 104
s[i] 为 '(' 或 ')'
*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int main() {
    Solution s;
    cout << s.longestValidParentheses(")()())") << endl;

    return 0;
}

