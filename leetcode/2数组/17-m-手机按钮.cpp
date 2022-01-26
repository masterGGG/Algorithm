/*
思路：回溯
1. 计算当前元素之后元素的字母组合
2. 将当前元素并入字母组合，返回字母组合
时间复杂度：O(3^m * 4^n)
空间复杂度：O(m+n)
*/

class Solution {
public:
    vector<vector<string>> map {
        {"a", "b", "c"},{"d", "e", "f"},{"g", "h", "i"},
        {"j", "k", "l"},{"m", "n", "o"},{"p", "q", "r", "s"},
        {"t", "u", "v"},{"w", "x", "y", "z"}
    };

    vector<string> trans(string digits, int index) {
        vector<string> res;
        vector<string> cur(map[digits[index] - '2'].begin(), map[digits[index] - '2'].end());

        if (index == digits.length () - 1) {
            return cur;
        }

        vector<string> pre = trans(digits, index + 1);
        
        for (int i = 0; i < cur.size(); ++i) {
            for (int j = 0; j < pre.size(); ++j) {
                res.emplace_back(cur[i] + pre[j]);
            }
        }

        return res;
    }

    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) {
            return vector<string>();
        }

        return trans(digits, 0);
    }
};

/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
*/