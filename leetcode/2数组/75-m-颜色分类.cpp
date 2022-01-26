/*
思路：荷兰国旗问题
双指针法，pmin，pmax
1. 遍历数组元素，元素大于1，与pmax位置交换，重复1
2. 当前元素小于1，与pmin位置交换，遍历下一个元素，重复1
*/
class Solution {
public:
  void sortColors(vector<int>& nums) {
    int n = nums.size();
    int p0 = 0, p2 = n - 1;
    for (int i = 0; i <= p2; ++i) {
      while (i <= p2 && nums[i] == 2) {
          swap(nums[i], nums[p2]);
          --p2;
      }
      if (nums[i] == 0) {
          swap(nums[i], nums[p0]);
          ++p0;
      }
    }
  }
};
/*
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
*/