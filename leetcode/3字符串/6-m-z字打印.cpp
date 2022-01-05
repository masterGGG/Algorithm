/*
将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
*/
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