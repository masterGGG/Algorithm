/*
给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
返回被除数 dividend 除以除数 divisor 得到的商。
整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2

示例 1:
输入: dividend = 10, divisor = 3
输出: 3
解释: 10/3 = truncate(3.33333..) = truncate(3) = 3
示例 2:
输入: dividend = 7, divisor = -3
输出: -2
解释: 7/-3 = truncate(-2.33333..) = -2

提示：
被除数和除数均为 32 位有符号整数。
除数不为 0。
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    const int MIN = -(1 << 30) - (1 << 30);
    const int MAX = (1 << 30) - 1 + (1 << 30);
    const int LIMIT = -(1 << 30);

    int divide(int dividend, int divisor) {
        if (divisor == 1) {
            return dividend;
        } else if (divisor == -1) {
            return dividend == MIN ? MAX : -dividend;
        }

        bool isC = false;

        if (dividend > 0) {
            isC = !isC;
            dividend = -dividend;
        }
        
        if (divisor > 0) {
            isC = !isC;
            divisor = -divisor;
        }

        if (divisor < dividend) {
            return 0;
        }

        int mod = 0;
        int divisor1 = divisor;
        stack<int> history;

        while (dividend <= divisor1) {
            history.push(divisor1);

            if (divisor1 < LIMIT) {
                break;
            }

            divisor1 += divisor1;
        }

        while (dividend <= divisor && !history.empty()) {
            int sub = history.top();
            if (sub >= dividend) {
                mod += 1 << (history.size() - 1);
                dividend -= sub;
            } else {
                history.pop();
            }
        }

        return isC ? -mod : mod;
    }
};


//g++ 除法问题.cpp -std=c++11 -o xxx
int main() {
    Solution s;

    cout << "1100540749/-1090366779 = " << s.divide(1100540749, -1090366779) << endl;
    cout << "7/-3 = " << s.divide(7, -3) << endl;
    return 0;
}