/*
给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。
高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。
*/

/**
思路：递归
排序数组一分为二，分别构造左右子树
 */
class Solution {
public:
  TreeNode* sortedArrayToBST(vector<int>& nums, int l, int r) {
    if (l > r) {
      return nullptr;
    }

    int mid = (l + r) >> 1;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = l < mid ? sortedArrayToBST(nums, l, mid -1) : nullptr;
    root->right = r > mid ? sortedArrayToBST(nums, mid + 1, r) : nullptr;
    return root;
  }

  TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.size() == 0) {
      return nullptr;
    }

    return sortedArrayToBST(nums, 0, nums.size() - 1);
  }
};