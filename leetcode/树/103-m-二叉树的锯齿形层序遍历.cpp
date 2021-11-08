/*
给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
例如：
给定二叉树 [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层序遍历如下：
[
  [3],
  [20,9],
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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
      if (root == nullptr) {
        return vector<vector<int>>();
      }

      vector<vector<int> > vec_;
      queue<TreeNode*> queue_;
      bool begin = true;
      queue_.push(root);
      
      while (!queue_.empty()) {
        vec_.emplace_back(vector<int>(queue_.size(), 0));
        int len = queue_.size();
        int count = len;

        while (len) {
          TreeNode *node_ = queue_.front();
          queue_.pop();

          if (node_->left) {
            queue_.push(node_->left);
          }

          if (node_->right) {
            queue_.push(node_->right);
          }

          if (begin) {
            vec_[vec_.size() - 1][count - len] = node_->val;
          } else {
            vec_[vec_.size() - 1][len - 1] = node_->val;
          }

          len--;
        }

        begin = !begin;
      }

      return vec_;
    }
};

/*
[3,9,20,null,null,15,7]
输出：
[[3],[20,9],[7,15]]
预期结果：
[[3],[20,9],[15,7]]
*/