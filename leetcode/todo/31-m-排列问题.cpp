/*
实现获取 下一个排列 的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列（即，组合出下一个更大的整数）。
如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
必须 原地 修改，只允许使用额外常数空间。

示例 1：
输入：nums = [1,2,3]
输出：[1,3,2]
示例 2：
输入：nums = [3,2,1]
输出：[1,2,3]
示例 3：
输入：nums = [1,1,5]
输出：[1,5,1]
示例 4：
输入：nums = [1]
输出：[1]

提示：
1 <= nums.length <= 100
0 <= nums[i] <= 100
*/
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1) {
            return ;
        }

        int pos = nums.size() - 2;

        for (; pos >= 0 && nums[pos] >= nums[pos + 1]; --pos) {
        }

        if (pos == -1) {
            sort(nums.begin(), nums.end());
            return;
        }

        for (int bigger = nums.size() - 1; bigger > pos; --bigger) {
            if (nums[pos] < nums[bigger]) {
                swap(nums, pos, bigger);
                sort(nums.begin() + pos + 1, nums.end());
                break;
            }
        }
    }
};

void show(vector<int> nums) {
    for (auto i : nums) {
        cout << i << " ";
    }

    cout << endl;
}
//g++ 31-m-排列问题.cpp -o xxx -std=c++11
int main() {
    Solution s;
    vector<int> nums = {1,3,1};//{2,3,1};

    cout << "Before "; show(nums);
    s.nextPermutation(nums);
    cout << "After  "; show(nums);

    return 0;
}