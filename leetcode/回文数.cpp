/*
给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。例如，121 是回文，而 123 不是。

示例 1：
输入：x = 121
输出：true
示例 2：
输入：x = -121
输出：false
解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3：
输入：x = 10
输出：false
解释：从右向左读, 为 01 。因此它不是一个回文数。
示例 4：
输入：x = -101
输出：false
提示：
-231 <= x <= 231 - 1

[回文数](https://leetcode-cn.com/problems/palindrome-number/solution/hui-wen-shu-by-leetcode-solution/)
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        } else if (x < 10) {
            return true;
        } else if (x % 10 == 0) {
            return false;
        }
    
        int y = 0;

        while (y < x) {
            y = 10 * y + x % 10;
            x = x / 10;
        }

        return x == y || x == y / 10;
    }

    bool isPalindrome_X(int x) {
        if (x < 0) {
            return false;
        }

        if (x < 10) {
            return true;
        }

        vector<int> num;

        while (x > 0) {
            num.emplace_back(x % 10);\
            x = x / 10;
        }

        for (int i = 0; i < num.size() - 1 - i; ++i) {
            if (num[i] != num[num.size() - 1 - i]) {
                return false;
            }
        }

        return true;
    }
};