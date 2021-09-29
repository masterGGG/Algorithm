/*
将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

请你实现这个将字符串进行指定行数变换的函数：
string convert(string s, int numRows);
 
示例 1：
输入：s = "PAYPALISHIRING", numRows = 3
输出："PAHNAPLSIIGYIR"

示例 2：
输入：s = "PAYPALISHIRING", numRows = 4
输出："PINALSIGYAHRPI"
解释：
P     I    N
A   L S  I G
Y A   H R
P     I

示例 3：
输入：s = "A", numRows = 1
输出："A"

提示：
1 <= s.length <= 1000
s 由英文字母（小写和大写）、',' 和 '.' 组成
1 <= numRows <= 1000
*/

#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (s.length() <= 1 || numRows == 1) {
            return s;
        }

        string res = "";
        int gap = 2 * numRows - 2;
        int pos = 0;
        while (pos < s.length()) {
            res += s[pos];
            pos += gap;
        }

        for (int row = 1; row < numRows - 1; ++row) {
            pos = row;
            int rowGap = gap - row - row;

            while (pos < s.length()) {
                res += s[pos];

                if (pos + rowGap < s.length()) {
                    res += s[pos + rowGap];
                }

                pos += gap;
            }
        }

        pos = numRows - 1;
        while (pos < s.length()) {
            res += s[pos];
            pos += gap;
        }

        return res;
    }

    string convert_V1(string s, int numRows) {
        if (s.length() <= 1 || numRows == 1) {
            return s;
        }

        queue<char> src;
        vector<string> dst(numRows, "");

        for (auto c : s) {
            src.push(c);
        }

        bool pushCol = true;
        int row = 0;

        while (!src.empty()) {
            dst[row] = dst[row] + src.front();
            src.pop();

            if (pushCol) {
                if (++row == numRows - 1) {
                    pushCol = false;
                }
            } else {
                if (--row == 0) {
                    pushCol = true;
                }
            }
        }

        string result;

        for (auto str : dst) {
            result += str;
        }

        return result;
    }
};

int main() {
    Solution s;
    cout << "PAYPALISHIRING" << endl << endl;
    cout << s.convert("PAYPALISHIRING", 2) << endl;

    cout << s.convert("PAYPALISHIRING", 3) << endl;
    cout << "PAHNAPLSIIGYIR" << endl;
    cout << s.convert("PAYPALISHIRING", 4) << endl;
    cout << "PINALSIGYAHRPI" << endl;

    return 0;
}