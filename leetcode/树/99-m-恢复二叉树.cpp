/*给你二叉搜索树的根节点 root ，该树中的两个节点被错误地交换。请在不改变其结构的情况下，恢复这棵树。
进阶：使用 O(n) 空间复杂度的解法很容易实现。你能想出一个只使用常数空间的解决方案吗？

示例 1：
输入：root = [1,3,null,null,2]
输出：[3,1,null,null,2]
解释：3 不能是 1 左孩子，因为 3 > 1 。交换 1 和 3 使二叉搜索树有效。
示例 2：
输入：root = [3,1,4,null,null,2]
输出：[2,1,4,null,null,3]
解释：2 不能在 3 的右子树中，因为 2 < 3 。交换 2 和 3 使二叉搜索树有效。
 
提示：
树上节点的数目在范围 [2, 1000] 内
-231 <= Node.val <= 231 - 1
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
    void inorder(TreeNode* root, deque<TreeNode*> &queue_) {
      if (root == nullptr) {
        return;
      }

      inorder(root->left, queue_);
      queue_.push_back(root);
      inorder(root->right, queue_);
    }
  
    void recoverTree(TreeNode* root) {
      deque<TreeNode*> queue_;
      inorder(root, queue_);

      int prev = 0;
      int next = queue_.size() - 1;
      bool one = false;

      for (int i = 1; i < queue_.size(); ++i) {
        if (!one) {
          if (queue_[i]->val < queue_[i - 1]->val) {
            prev = i - 1;
            next = i;
            one = !one;
          }
        } else {
          if (queue_[i]->val < queue_[i - 1]->val) {
            next = i;
            break;
          }
        }
      }

      int tmp = queue_[prev]->val;
      queue_[prev]->val = queue_[next]->val;
      queue_[next]->val = tmp;
    }
};

/*
输入：
[3,1,4,null,null,2]
输出：
[4,1,3,null,null,2]
预期结果：
[2,1,4,null,null,3]
*/