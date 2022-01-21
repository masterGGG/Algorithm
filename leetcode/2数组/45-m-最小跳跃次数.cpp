/*
思路： 贪心算法
1. 维护当前能够到达的最大下标位置，记为边界。
2. 从左到右遍历数组，到达边界时，更新边界并将跳跃次数增加 1。
时间复杂度：O(n)，其中 n 是数组长度。
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int maxPos = 0, n = nums.size(), end = 0, step = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (maxPos >= i) {
                maxPos = max(maxPos, i + nums[i]);
                if (i == end) {
                    end = maxPos;
                    ++step;
                }
            }
        }
        return step;
    }
};