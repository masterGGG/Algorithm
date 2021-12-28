/*
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

 
示例 1：

输入：s = "aa" p = "a"
输出：false
解释："a" 无法匹配 "aa" 整个字符串。
示例 2:

输入：s = "aa" p = "a*"
输出：true
解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
示例 3：

输入：s = "ab" p = ".*"
输出：true
解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
示例 4：

输入：s = "aab" p = "c*a*b"
输出：true
解释：因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
示例 5：

输入：s = "mississippi" p = "mis*is*p*."
输出：false
 

提示：

0 <= s.length <= 20
0 <= p.length <= 30
s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
保证每次出现字符 * 时，前面都匹配到有效的字符

[正则表达式匹配](https://leetcode-cn.com/problems/regular-expression-matching/solution/)
*/

class Solution {
public:
    int ignoreAlpha(string p, int ppos) {
        while (ppos + 3 < p.length()) {
            if (p[ppos] == p[ppos + 2] && p[ppos + 1] == '*' && p[ppos + 3] == '*') {
                ppos += 2;
            } else {
                return ppos;
            }
        }

        return ppos;
    }

    bool isMatch(string s, int spos, string p, int ppos) {
        if (spos == s.length() && ppos == p.length()) {
            //边界条件：如果正则表达式和待匹配字符串同时匹配到末尾，则匹配成功
            return true;
        } else if (ppos == p.length()) {
            //边界条件：如果正则表达式匹配到末尾，则匹配失败
            return false;
        } else if (spos == s.length()) {
            //边界条件：如果待匹配字符串匹配到末尾，检查后续正则表达式是否可以忽略
            if (ppos + 1 < p.length() && p[ppos + 1] == '*') {
                return isMatch(s, spos, p, ppos + 2);
            }

            return false;
        }

        ppos = ignoreAlpha(p, ppos);
    
        if (s[spos] == p[ppos]) {
            //如果当前字符相等，需要检查正则表达式的后续一个字符是不是‘*’
            if (ppos + 1 < p.length() && p[ppos + 1] == '*') {
                return isMatch(s, spos + 1, p, ppos) || isMatch(s, spos + 1, p, ppos + 2) || isMatch(s, spos, p, ppos + 2);
            }

            return isMatch(s, spos + 1, p, ppos + 1);
        } else {
            if (p[ppos] == '.') {
                if (ppos + 1 < p.length() && p[ppos + 1] == '*') {
                    return isMatch(s, spos + 1, p, ppos) || isMatch(s, spos + 1, p, ppos + 2) || isMatch(s, spos, p, ppos + 2);
                }

                return isMatch(s, spos + 1, p, ppos + 1);
            } else if (ppos + 1 < p.length() && p[ppos + 1] == '*') {
                return isMatch(s, spos, p, ppos + 2);
            }

            return false;
        }
    }

    //递归实现
    bool isMatch(string s, string p) {
        return isMatch(s, 0, p, 0);
    }

    //动态规划
    bool isMatch(string s, string p) {
        //dp【i][j]表示s前i个元素和p前j个元素匹配情况
        vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, false));
        auto match = [&](int i, int j) {
            if (i == 0) {
                return false;
            }

            return p[j - 1] == '.' || p[j - 1] == s[i - 1];
        };

        dp[0][0] = true; //空串能够匹配

        for (int i = 0; i <= s.length(); ++i) {
            for (int j = 1; j <= p.length(); ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] |= dp[i][j - 2];

                    if (match(i, j - 1)) {
                        dp[i][j] |= dp[i - 1][j];
                    }
                } else {
                    if (match(i, j)) {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }

        return dp[s.length()][p.length()];
    }
};