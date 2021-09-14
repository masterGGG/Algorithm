/*
给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
如果反转后整数超过 32 位的有符号整数的范围 [−2^31,  2^31 − 1] ，就返回 0。
假设环境不允许存储 64 位整数（有符号或无符号）。

示例 1：
输入：x = 123
输出：321
示例 2：
输入：x = -123
输出：-321
示例 3：
输入：x = 120
输出：21
示例 4：
输入：x = 0
输出：0
*/
#include <iostream>

using namespace std;

const int INT_MAX = (1 << 31) - 1; 

class Solution {
public:
    int reverse(int x) {
        int Max = INT_MAX / 10;
        int Max_mod = INT_MAX % 10;
        int Min = (0 - INT_MAX - 1) / 10;
        int Min_mod = (0 - INT_MAX - 1) % 10;
        int y = 0;

        while (x != 0) {
            int mod = x % 10;

            if ((y > Max) || (y == Max && mod > Max_mod)) {
                return 0;
            }

            if ((y < Min) || (y == Min && mod < Min_mod)) {
                return 0;
            }

            y = y * 10 + mod;
            x /= 10;
        }

        return y;
    }
};

int main() {
    Solution s;

    s.reverse(0);
    s.reverse(12345);
    s.reverse(-1230);
    
    return 0;
}