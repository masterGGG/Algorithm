class Solution {
public:
    /*
    思路：manacher算法
    1. 遍历字符串，记录回文最右边界right以及回文中心mid，跳转2
    2. 如果遍历位置超过回文中心，dp[i] = 1; 跳转到4
    3. 未超过回文中心，取dp[2*mid - i]和right - i - 1的最小值，跳转4
    4. 基于当前的dp[i]的回文长度再向两边拓展，如果i + dp[i] - 1大于right，记录更新
    */
    int countSubstrings(string s) {
        int n = s.size();
        string helper = "$#";
        for (const char &c: s) {
            helper += c;
            helper += '#';
        }
        n = helper.size();
        helper += '!';

        auto dp = vector<int>(n);
        int mid = 0, rMax = 0, ans = 0;
        for (int i = 1; i < n; ++i) {
            // 初始化 dp[i]
            dp[i] = (i <= rMax) ? min(rMax - i + 1, dp[2 * mid - i]) : 1;
            // 中心拓展
            while (helper[i + dp[i]] == helper[i - dp[i]]) ++dp[i];
            // 动态维护 mid 和 rMax
            if (i + dp[i] - 1 > rMax) {
                mid = i;
                rMax = i + dp[i] - 1;
            }
            // 统计答案, 当前贡献为 (f[i] - 1) / 2 上取整
            ans += (dp[i] / 2);
        }

        return ans;
    }





    int expand(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return (right - left - 2) / 2;
    }

    string longestPalindrome(string s) {
        int start = 0, end = -1;
        string t = "#";
        for (char c: s) {
            t += c;
            t += '#';
        }
        t += '#';
        s = t;

        vector<int> arm_len;
        int right = -1, j = -1;
        for (int i = 0; i < s.size(); ++i) {
            int cur_arm_len;
            if (right >= i) {
                int i_sym = j * 2 - i;
                int min_arm_len = min(arm_len[i_sym], right - i);
                cur_arm_len = expand(s, i - min_arm_len, i + min_arm_len);
            } else {
                cur_arm_len = expand(s, i, i);
            }
            arm_len.push_back(cur_arm_len);
            if (i + cur_arm_len > right) {
                j = i;
                right = i + cur_arm_len;
            }
            if (cur_arm_len * 2 + 1 > end - start) {
                start = i - cur_arm_len;
                end = i + cur_arm_len;
            }
        }

        string ans;
        for (int i = start; i <= end; ++i) {
            if (s[i] != '#') {
                ans += s[i];
            }
        }
        return ans;
    }
};