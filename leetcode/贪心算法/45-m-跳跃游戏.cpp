/*
给你一个非负整数数组 nums ，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
你的目标是使用最少的跳跃次数到达数组的最后一个位置。
假设你总是可以到达数组的最后一个位置。

示例 1:
输入: nums = [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
示例 2:
输入: nums = [2,3,0,1,4]
输出: 2

提示:
1 <= nums.length <= 104
0 <= nums[i] <= 1000
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);

        for (int i = nums.size() - 2; i >= 0; --i) {
            if (i + nums[i] >= nums.size() - 1) {
                dp[i] = 1;
            } else if (nums[i] == 0) {
                dp[i] == 0; 
            } else {
                for (int j = 1; j <= nums[i]; ++j) {
                    if (dp[i + j]) {
                        dp[i] = dp[i] == 0 ? dp[i + j] + 1 : min(dp[i], dp[i + j] + 1);
                    }
                }
            }
        }

        return dp[0];
    }

    //贪心算法
    int jump(vector<int>& nums) {
        int pos = 0, end = 0, distance, step = 0, max_pos = 0;

        while (start < end) {
            distance = 0;
            step++;

            if (start + nums[start] >= end) {
                break;
            }

            for (int i = 1; i <= nums[start]; ++i) {
                if (distance < start + nums[start + i] + i) {
                    max_pos = start + i;
                    distance = start + nums[start + i] + i;
                }
            }

            start = max_pos;
        }

        return step;
    }
};