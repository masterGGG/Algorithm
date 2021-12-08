/*
给定一个二叉树，返回其节点值自底向上的层序遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层序遍历为：

[
  [15,7],
  [9,20],
  [3]
]*/

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
#include <vector>

class Solution {
public:
#if 1
  void reverseNode(TreeNode* root, std::vector<std::vector<int>> &vec, int level) {
    if (root == nullptr) {
      return ;
    }

    if (vec.size() == level) {
      if (vec.size() == 0) {
        vec.emplace_back(std::vector<int>());
      } else {
        vec.emplace(vec.begin(), std::vector<int>());
      }
    }

    vec[vec.size()-1-level].emplace_back(root->val);
    reverseNode(root->left, vec, level+1);
    reverseNode(root->right, vec, level+1);
  }
  std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
    std::vector<std::vector<int>> vec;
    reverseNode(root, vec, 0);
    return vec;
  }
#else
  std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
    std::vector<std::vector<int>> vec;

    if (root == nullptr) {
      return vec;
    }

    std::vector<TreeNode *> queue;
    queue.emplace_back(root);

    while (queue.size()) {
      std::vector<TreeNode *> child;
      std::vector<int> tmp;

      for (auto node : queue) {
        tmp.emplace_back(node->val);
        if (node->left) {
          child.emplace_back(node->left);
        }
        if (node->right) {
          child.emplace_back(node->right);
        }
      }

      if (vec.size()) {
        vec.emplace(vec.begin(), tmp);
      } else {
        vec.emplace_back(tmp);
      }
      queue.swap(child);
    }

    return vec;
  }
#endif
};