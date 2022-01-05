/*
给你二叉树的根结点 root ，请你将它展开为一个单链表：
展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
展开后的单链表应该与二叉树 先序遍历 顺序相同。
进阶：你可以使用原地算法（O(1) 额外空间）展开这棵树吗？*/

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

/*
思路：将右子树挂到左子树的最右节点之后
左子树变为右子树
*/
class Solution {
public:
  void flatten(TreeNode* root) {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
      return ;
    }

    TreeNode* cur = root;

    while (cur) {
      if (cur->left != nullptr) {
        TreeNode* lright = cur->left;
        while (lright->right) {
          lright = lright->right;
        }
        lright->right = cur->right;
        cur->right = cur->left;
        cur->left = nullptr;
      }

      cur = cur->right;
    }
  }
};