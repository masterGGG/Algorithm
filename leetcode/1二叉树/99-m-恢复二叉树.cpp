/*给你二叉搜索树的根节点 root ，该树中的两个节点被错误地交换。请在不改变其结构的情况下，恢复这棵树。
进阶：使用 O(n) 空间复杂度的解法很容易实现。你能想出一个只使用常数空间的解决方案吗？
*/

/**
思路：中序遍历有序
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