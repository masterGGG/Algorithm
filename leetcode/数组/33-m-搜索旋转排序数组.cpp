/*
整数数组 nums 按升序排列，数组中的值 互不相同 。
在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。

给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。

示例 1：
输入：nums = [4,5,6,7,0,1,2], target = 0
输出：4
示例 2：
输入：nums = [4,5,6,7,0,1,2], target = 3
输出：-1
示例 3：
输入：nums = [1], target = 0
输出：-1
 
提示：
1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
nums 中的每个值都 独一无二
题目数据保证 nums 在预先未知的某个下标上进行了旋转
-10^4 <= target <= 10^4
*/
#include <vector>
#include <iostream>

class Solution {
public:
int search(std::vector<int>& nums, int target) {
    int begin = 0, end = nums.size() - 1;

    while (begin < end) {
        if (nums[begin] == target) {
            return begin;
        } else if (nums[end] == target) {
            return end;
        } else if (end == begin + 1) {
            return -1;
        }

        int mid = (begin + end) >> 1;

        if (nums[mid] > nums[begin]) {
            if (nums[mid] <= target || target <= nums[begin]) {
                begin = mid;
            } else {
                end = mid;
            }
        } else {
            if (target >= nums[begin] || target <= nums[mid]) {
                end = mid;
            } else {
                begin = mid;
            }
        }
    }

    return nums[begin] == target ? begin : -1;
}
};