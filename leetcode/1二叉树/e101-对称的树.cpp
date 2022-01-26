/*
给定一个二叉树，检查它是否是镜像对称的。
 */
class Solution {
public:
    bool isSymmetric(TreeNode* left, TreeNode* right) {
      if (!left && !right) {
        return true;
      } else if (!left || !right || left->val != right->val) {
        return false;
      }

      return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
    //递归解法
    bool isSymmetric(TreeNode* root) {
      return isSymmetric(root, root);
    }

    //迭代法
    bool isSymmetric(TreeNode* root) {
      if (root == nullptr) {
        return true;
      }

      queue<TreeNode*> queue_;
      queue_.push(root);
      queue_.push(root);

      while (!queue_.empty()) {
        TreeNode *left = queue_.front();
        queue_.pop();
        TreeNode *right = queue_.front();
        queue_.pop();

        if (left->val != right->val || 
            (left->left == nullptr && right->right != nullptr) ||
            (left->right == nullptr && right->left != nullptr)) {
          return false;
        }

        if (left->left != nullptr) {
          queue_.push(left->left);
          queue_.push(right->right);
        }
        if (left->right != nullptr) {
          queue_.push(left->right);
          queue_.push(right->left);
        }
      }

      return true;
    }
};