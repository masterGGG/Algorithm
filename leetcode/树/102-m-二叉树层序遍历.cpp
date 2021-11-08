/*
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

示例：
二叉树：[3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
返回其层序遍历结果：
[
  [3],
  [9,20],
  [15,7]
]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
      if (root == nullptr) {
        return vector<vector<int>>();
      }

      vector<vector<int> > vec_;
      queue<TreeNode*> queue_;
      queue_.push(root);

      while (!queue_.empty()) {
        vector<int> cur_;
        int len = queue_.size();

        while (len--) {
          TreeNode *node_ = queue_.front();
          queue_.pop();
          cur_.emplace_back(node_->val);

          if (node_->left != nullptr) {
            queue_.push(node_->left);
          }

          if (node_->right != nullptr) {
            queue_.push(node_->right);
          }
        }

        vec_.emplace_back(cur_);
      }

      return vec_;
    }
};