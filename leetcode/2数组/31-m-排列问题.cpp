/*
思路：找到一个大于当前序列的新序列，且变大的幅度尽可能小。
1. 从后往前找到第一个非递增的元素
2. 从后往前找到一个比1中非递增的元素大的元素
3. 交换1和2中的元素，重新排列1的后续元素
*/

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
        //1. 从后往前找到第一个非递增的元素
        for (; pos >= 0 && nums[pos] >= nums[pos + 1]; --pos) {
        }

        if (pos == -1) {
            sort(nums.begin(), nums.end());
            return;
        }
        //2. 从后往前找到一个比1中非递增大的元素
        for (int bigger = nums.size() - 1; bigger > pos; --bigger) {
            if (nums[pos] < nums[bigger]) {
                //3. 交换1和2中的元素，重新排列1的后续元素
                swap(nums, pos, bigger);
                sort(nums.begin() + pos + 1, nums.end());
                break;
            }
        }
    }
};

/*
实现获取 下一个排列 的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列（即，组合出下一个更大的整数）。
如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
必须 原地 修改，只允许使用额外常数空间。
*/