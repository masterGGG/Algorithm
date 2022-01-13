/*
给定一个二叉树，返回其节点值自底向上的层序遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],
*/

class Solution {
public:
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
};