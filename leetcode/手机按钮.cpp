/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
示例 1：
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]

示例 2：
输入：digits = ""
输出：[]

示例 3：
输入：digits = "2"
输出：["a","b","c"]

提示：
0 <= digits.length <= 4
digits[i] 是范围 ["2", "9"] 的一个数字。
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

    void show(string digits) {
        vector<string> res = letterCombinations(digits);

        cout << digits << " letterCombinations:" << endl;

        for (auto i : res) {
            cout << i << " ";
        }

        cout << endl;
    }
};

int main() {
    Solution s;

    s.show("2");
    s.show("23");
    s.show("");

    return 0;
}