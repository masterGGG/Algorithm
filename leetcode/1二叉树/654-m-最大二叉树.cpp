/*
思路：单调栈，栈中记录当前元素之前大于当前元素的节点
1. 从左向右依次遍历元素vec[i]，并构造节点node
2. 如果栈为空，将当前节点node入栈，重复1，否则进入3
3. 栈非空，找node的父节点（从栈中弹出比vec[i]小的节点）
   3.1 弹出的比node小的最大节点作为node的左子树
   3.2 node作为栈顶节点的右子树入栈
*/

/*
3 2 1 6 0 5 
      6
    /   \  
  3       5 
   \     /
    2   0 
     \ 
      1
*/

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
      if (nums.size() == 0) {
        return nullptr;
      }

      TreeNode* root = nullptr;
      stack<TreeNode*> stk;

      for (int i = 0; i < nums.size(); ++i) {
        if (stk.empty()) {
          root = new TreeNode(nums[i]);
          stk.push(root);
        } else {
          TreeNode* skip = nullptr;
          while (!stk.empty() && stk.top()->val < nums[i]) {
            skip = stk.top();
            stk.pop();
          }

          if (stk.empty()) {
            stk.push(new TreeNode(nums[i]));
            stk.top()->left = root;
            root = stk.top();
          } else {
            stk.top()->right = new TreeNode(nums[i]);
            stk.push(stk.top()->right);

            if (skip) {
              stk.top()->left = skip;
            }
          }
        }
      }

      return root;
    }
};

/*
给定一个不含重复元素的整数数组 nums 。一个以此数组直接递归构建的 最大二叉树 定义如下：
二叉树的根是数组 nums 中的最大元素。
左子树是通过数组中 最大值左边部分 递归构造出的最大二叉树。
右子树是通过数组中 最大值右边部分 递归构造出的最大二叉树。
返回有给定数组 nums 构建的 最大二叉树 。
*/