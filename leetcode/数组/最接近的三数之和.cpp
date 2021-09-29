/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

示例：
输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。

提示：
3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool closer(int cur, int prev, int target) {
        return abs(target - cur) < abs(target - prev);
    }

    int twoSumClosest(vector<int>& nums, int head, int tail, int target) {
        if (nums[head] + nums[head + 1] >= target) {
            return nums[head] + nums[head + 1];
        }

        if (nums[tail] + nums[tail - 1] <= target) {
            return nums[tail] + nums[tail - 1];
        }

        int nearest = nums[head] + nums[tail];

        while (head < tail) {
            int sum = nums[head] + nums[tail];

            if (closer(sum, nearest, target)) {
                nearest = sum;
            }

            if (sum > target) {
                tail--;
            } else if (sum < target) {
                head++;
            } else {
                return target;
            }
        }

        return nearest;
    }

    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int nearest = nums[0] + nums[1] + nums[2];

        if (nearest > target) {
            return nearest;
        }

        for (int i = 0; i < nums.size() - 2; ++i) {
            int sum = nums[i] + twoSumClosest(nums, i + 1, nums.size() - 1, target - nums[i]);

            if (closer(sum, nearest, target)) {
                nearest = sum;
            }
        }

        return nearest;
    }
};

int main() {
    Solution s;
    vector<int> vec{-1,2,1,-4};

    cout << s.threeSumClosest(vec, 1) <<endl;

    return 0;
}