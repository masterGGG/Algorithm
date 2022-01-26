/*
排序 + 双指针

1. 固定第一个数字的位置，转化为三数之和为target-v1的子问题
2. 在第一个数字之后，固定第二个数字的位置，转化为两数之和为target-v1-v2的子问题
3. 对剩余数字组合采用双指针，找出值为target的位置

时间复杂度：O(n^3)
空间复杂度：O(logn)
*/

class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int start, int target) {
        unordered_set<int> hash;
        vector<vector<int>> res;

        int tail = nums.size() - 1;

        while (start < tail) {
            if (hash.find(nums[start]) != hash.end()) {
                start++;
            } else if (hash.find(nums[tail]) != hash.end()) {
                tail--;
            } else {
                int cur = nums[start] + nums[tail];
                if (cur < target) {
                    hash.emplace(nums[start++]);
                } else if (cur > target) {
                    hash.emplace(nums[tail--]);
                } else {
                    res.emplace_back(vector<int>{nums[start], nums[tail]});
                    hash.emplace(nums[start++]);
                    hash.emplace(nums[tail--]);
                }
            }
        }

        return res;
    }

    vector<vector<int>> threeSum(vector<int>& nums, int start, int target) {
        unordered_set<int> hash;
        vector<vector<int>> res;

        for (; start < nums.size() - 2; ++start) {
            if (hash.find(nums[start]) == hash.end()) {
                auto two = twoSum(nums, start + 1, target - nums[start]);

                for (auto it : two) {
                    it.emplace_back(nums[start]);
                    res.emplace_back(it);
                }

                hash.emplace(nums[start]);
            }
        }

        return res;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) {
            return vector<vector<int>>();
        }

        sort(nums.begin(), nums.end());
        unordered_set<int> hash;
        vector<vector<int>> res;

        for (int i = 0; i < nums.size() - 3; ++i) {
            if (hash.find(nums[i]) == hash.end()) {
                auto three = threeSum(nums, i + 1, target - nums[i]);

                for (auto it : three) {
                    it.emplace_back(nums[i]);
                    res.emplace_back(it);
                }

                hash.emplace(nums[i]);
            }
        }

        return res;
    }
};

/*
给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] ：
0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。

示例 1：
输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
*/