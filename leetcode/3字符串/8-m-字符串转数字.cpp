/*
请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数（类似 C/C++ 中的 atoi 函数）。

函数 myAtoi(string s) 的算法如下：
1. 读入字符串并丢弃无用的前导空格
2. 检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
3. 读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
如果整数数超过 32 位有符号整数范围 [−2^31,  2^31 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −2^31 的整数应该被固定为 −2^31 ，大于 2^31 − 1 的整数应该被固定为 2^31 − 1 。
返回整数作为最终结果。
注意：
*/


#include <iostream>

using namespace std;

class Solution {
public:
    const int MAX = 214748364;
    const int MAX_MOD = 7;
    const int MIN = -214748364;
    const int MIN_MOD = 8;

    int myAtoi(string s) {
        int result = 0;
        int pos = 0;

        while (pos < s.length() && s[pos] == ' ') {
            pos++;
        }

        bool isOpposite = false;
        if (s[pos] == '-' || s[pos] == '+') {
            isOpposite = s[pos] == '-';
            pos++;
        }

        while (pos < s.length() && s[pos] >= '0' && s[pos] <= '9') {
            int tail = s[pos] - '0';

            if (result == 0) {
                result = isOpposite ? 0 - tail : tail;
                pos++;
                continue;
            }

            if (result > MAX || ((result == MAX) && (tail > MAX_MOD))) {
                return 2147483647;
            }

            if (result < MIN || ((result == MIN) && (tail > MIN_MOD))) {
                return -2147483648;
            }

            result *= 10;
            result += isOpposite ? 0 - tail : tail;
            pos++;
        }

        return result;
    }
};

int main() {
    Solution s;
    
    cout << s.myAtoi("42") << endl;
    cout << s.myAtoi("-42") << endl;

    return 0;
}