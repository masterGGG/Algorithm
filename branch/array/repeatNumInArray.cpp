/*
 * 找出数组中重复的数字。
 * 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

示例 1：
输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 
 **/
#include <vector>
#include <iostream>

using namespace std;

/*第一次解法，时间复杂度O(n)，空间复杂度O(n)*/
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        vector<int> res(nums.size());

        for (auto it : nums) {
            if (res[it] > 0) {
                return it;
            }

            res[it]++;
        }

        return 0;
    }
};

/*参考解法，时间复杂度O(n)，空间复杂度O(1)，
 * 鸽巢原理，因为出现的元素值 < nums.size(); 所以我们可以将见到的元素 放到索引的位置，如果交换时，发现索引处已存在该元素，则重复 O(N) 空间O(1)
 * 依次遍历数组中的每个元素，并将其放到对应下⌚标的位置上
 * 如果对应下标的元素与当前元素一致，即找到相同的元素
 * 否则继续移动元素
 */

class Solution1 {
public:
    int findRepeatNumber(vector<int>& nums) {
        int tmp = 0;


        for (int i = 0; i < nums.size(); ++i)
        {
            while (i != nums[i])
            {
                if (nums[i] == nums[nums[i]]) {
                    return nums[i];
                }

                tmp = nums[i];
                nums[i] = nums[tmp];
                nums[tmp] = tmp;
            }
        }

        return 0;
    }
};