/*
剑指 Offer 10- I. 斐波那契数列
写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

示例 1：
输入：n = 2
输出：1
示例 2：
输入：n = 5
输出：5
 

提示：0 <= n <= 100
*/

class Solution {
public:
    static int digui(int n) {
        //return fib(n-1) + fib(n-2);超出时间限制
    }

    static int loop(int n) {
        /*执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
        内存消耗：5.9 MB, 在所有 C++ 提交中击败了51.92%的用户*/
        int ppre = 0;
        int pre = 1;
        int cur = 0;

        for (int i = 2; i < n; i++) {
            cur = pre + ppre;

            if (cur > 1000000007) {
                cur -= 1000000007;
            }
            
            ppre = pre;
            pre = cur;
        }

        return (pre + ppre) % 1000000007;
    }

    static int dp(int n) {
        int *m_dp = new int[n + 1];

        m_dp[0] = 0;
        m_dp[1] = 1;

        for (int i = 2; i < n; ++i) {
            m_dp[i] = m_dp[i - 1] + m_dp[i - 2];

            if (m_dp[i] > 1000000007) {
                m_dp[i] -= 1000000007;
            }
        }

        int value = m_dp[n];
        delete[] m_dp;

        return value;
    }

    int fib(int n) {
        if (n < 2) {
            return n;
        }

        return dp(n);
    }
};