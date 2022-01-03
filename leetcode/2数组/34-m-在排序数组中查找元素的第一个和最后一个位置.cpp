/*给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：
你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？

示例 1：
输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]*/
#include <vector>
#include <iostream>

class Solution {
public:
  int binarySearch(std::vector<int>& nums, int head, int tail, int target, bool first) {
    while (head < tail) {
      int mid = (head + tail) >> 1;

      if (nums[mid] < target) {
        head = mid + 1;/// 如果中间结点小于target，那么直接将head索引向后移动至mid+1位置
      } else if (nums[mid] > target) {
        tail = mid;/// 如果中间结点大于target，将tail结点前移至mid位置
      } else {
        if (first) {
          tail = mid;/// 查询第一个等于target的索引，将tail索引前移至mid，继续检索前半个区间
        } else {
          if (head == mid) {
            head = nums[tail] == target ? tail : head;
            break;
          }

          head = mid;/// 查询最后一个等于target的索引，将head索引向后移至mid位置
        }
      }
    }
    
    //head索引记录了第一个/最后一个等于target的数
    return nums[head] == target ? head : -1;
  }
  std::vector<int> searchRange(std::vector<int>& nums, int target) {
    std::vector<int> vec(2, -1);

    if (nums.size() == 0 || target < nums[0] || target > nums[nums.size() - 1]) {
      return std::vector<int>(2, -1);
    }
    
    //先找第一个大于等于target的索引
    vec[0] = binarySearch(nums, 0, nums.size() - 1, target, true);
    //获取第一个大于target的索引
    vec[1] = vec[0] == -1 ? -1 : binarySearch(nums,  vec[0], nums.size() - 1, target, false);

    return vec;
  }
};