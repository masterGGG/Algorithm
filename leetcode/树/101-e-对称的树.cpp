/*
给定一个二叉树，检查它是否是镜像对称的。

 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
 
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
    1
   / \
  2   2
   \   \
   3    3
 

进阶：

你可以运用递归和迭代两种方法解决这个问题吗？
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
    bool isSymmetric(TreeNode* root) {
      if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
        return true;
      } else if (root->left == nullptr || root->right == nullptr || root->right->val != root->left->val) {
        return false;
      }

      vector<TreeNode*> upper;
      upper.emplace_back(root->left);
      upper.emplace_back(root->right);

      while (!upper.empty()) {
        vector<TreeNode*> layer;
        
        for (int head = 0, tail = upper.size() - 1; head < tail; ++head, --tail) {
          if ((upper[head]->left == nullptr && upper[tail]->right != nullptr) || 
              (upper[head]->left != nullptr && upper[tail]->right == nullptr) || 
              (upper[head]->left != nullptr && upper[tail]->right != nullptr && upper[head]->left->val != upper[tail]->right->val) || 
              (upper[head]->right == nullptr && upper[tail]->left != nullptr) || 
              (upper[head]->right != nullptr && upper[tail]->left == nullptr) || 
              (upper[head]->right != nullptr && upper[tail]->left != nullptr && upper[head]->right->val != upper[tail]->left->val)) {
            return false;
          }
        }

        for (auto it : upper) {
          if (it->left) {
            layer.emplace_back(it->left);
          }
          if (it->right) {
            layer.emplace_back(it->right);
          }
        }
        upper.swap(layer);
      }

      return true;
    }
};