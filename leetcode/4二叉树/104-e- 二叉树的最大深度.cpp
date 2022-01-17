/*
给定一个二叉树，找出其最大深度。
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
*/

/**
思路：递归+回溯
f(n) = max{f(n->left), f(n->right)} + 1;
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
      if (root == nullptr) {
        return 0;
      }

      return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};