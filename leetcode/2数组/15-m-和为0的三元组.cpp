/*
排序 + 双指针
时间复杂度：O(N^2)  其中 N 是数组 nums 的长度。
空间复杂度：O(log N)
*/
class Solution {
public:
    void thresHelper(vector<int>& nums, int pos, int target, vector<vector<int>>& res) {
        int head = pos + 1;
        int tail = nums.size() - 1;

        while (head < tail) {
            int sum = nums[head] + nums[tail];

            if (sum < target) {
                head++;

                while (nums[head] == nums[head-1]) {
                    head++;
                }
            } else if (sum > target) {
                tail--;

                while (nums[tail] == nums[tail+1]) {
                    tail--;
                }
            } else {
                res.emplace_back(vector<int>{nums[pos], nums[head], nums[tail]});
                head++;

                while (nums[head] == nums[head-1]) {
                    head++;
                }
            }
        }
    }

    vector<vector<int>> thres(vector<int> nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            thresHelper(nums, i, 0 - nums[i], res);
        }

        return res;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // 枚举 a
        for (int first = 0; first < n; ++first) {
            // 需要和上一次枚举的数不相同
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            // c 对应的指针初始指向数组的最右端
            int third = n - 1;
            int target = -nums[first];
            // 枚举 b
            for (int second = first + 1; second < n; ++second) {
                // 需要和上一次枚举的数不相同
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                // 需要保证 b 的指针在 c 的指针的左侧
                while (second < third && nums[second] + nums[third] > target) {
                    --third;
                }
                // 如果指针重合，随着 b 后续的增加
                // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
                if (second == third) {
                    break;
                }
                if (nums[second] + nums[third] == target) {
                    ans.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return ans;
    }
};

/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。
返回这三个数的和。假定每组输入只存在唯一答案。

示例：
输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
*/