/*
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
有效括号组合需满足：左括号必须以正确的顺序闭合。

示例 1：
输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
示例 2：
输入：n = 1
输出：["()"]
1 <= n <= 8
*/

class Solution {
public:
    void generateParenthesis(vector<string> &res, string str, int left, int right, int n) {
        if (right == n) {
            res.emplace_back(str);
            return;
        } else if (right > left || left > n) {
            return;
        } else if (left == right) {
            generateParenthesis(res, str + "(", left + 1, right, n);
            return;
        }

        generateParenthesis(res, str + "(", left + 1, right, n);
        generateParenthesis(res, str + ")", left, right + 1, n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;

        generateParenthesis(res, "", 0, 0, n);

        return res;
    }
};