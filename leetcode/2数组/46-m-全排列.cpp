/*
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

思路：
1. 确定当前位置的值（依次和后续值交换）
2. 当前位置确定，移动索引到下一个，重复1
3. 边界，索引位置到达末尾，获取到一个排列，加入结果

时间复杂度：O(n×n!)
*/

class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len){
        // 所有数都填完了
        if (first == len) {
            res.emplace_back(output);
            return;
        }
        for (int i = first; i < len; ++i) {
            // 动态维护数组
            swap(output[i], output[first]);
            // 继续递归填下一个数
            backtrack(res, output, first + 1, len);
            // 撤销操作
            swap(output[i], output[first]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        backtrack(res, nums, 0, (int)nums.size());
        return res;
    }
};

/*给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

思路：回溯 + 过滤
1. 确定当前位置的值（依次和后续值交换，且不再set中），并加入set
2. 当前位置确定，移动索引到下一个，重复1
3. 边界，索引位置到达末尾，获取到一个排列，加入结果

时间复杂度：O(n×n!)
*/
class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len){
        // 所有数都填完了
        if (first == len) {
            res.emplace_back(output);
            return;
        }

        unordered_set<int> map;

        for (int i = first; i < len; ++i) {
            if (map.find(output[i]) != map.end()) {
                continue;
            }

            map.insert(output[i]);
            // 动态维护数组
            swap(output[i], output[first]);
            // 继续递归填下一个数
            backtrack(res, output, first + 1, len);
            // 撤销操作
            swap(output[i], output[first]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        backtrack(res, nums, 0, (int)nums.size());
        return res;
    }
};