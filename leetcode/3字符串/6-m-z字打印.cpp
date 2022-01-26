class Solution {
public:
    /*
    思路：使用n个string表示每一行的数字
    */
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows) ret += row;
        return ret;
    }
/*
将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
*/
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