/*
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。

示例 1：
输入：strs = ["flower","flow","flight"]
输出："fl"
示例 2：

输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。
 
提示：
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] 仅由小写英文字母组成
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }

        sort(strs.begin(), strs.end());

        string head = strs[0];
        string tail = strs[strs.size() - 1];
        int len = 0;

        while (len < head.length() && len < tail.length() && head[len] == tail[len]) {
            len++;
        }

        return head.substr(0, len);
    }
};