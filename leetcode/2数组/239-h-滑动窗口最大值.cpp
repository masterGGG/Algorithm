/*
思路：维护最大值队列

1. 依次将遍历到的位置加入队列，加入过程中将小于当前值的元素弹出
2. 当遍历了k个元素之后，除了执行1，还需要检查前k个元素是不是最大值，是则弹出
*/
class Solution {
public:
  std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
    int right = 0;
    std::vector<int> res;
    std::deque<int> record;

    while (right < nums.size()) {
      while (!record.empty() && nums[right] > record.back()) {
        record.pop_back();
      }

      record.push_back(nums[right]);
      right++;

      if (right >= k) {
        res.emplace_back(record.front());

        if (nums[right - k] == record.front()) {
          record.pop_front();
        }
      }
    }

    return res;
  }
};
/*239. 滑动窗口最大值
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
返回滑动窗口中的最大值。
*/