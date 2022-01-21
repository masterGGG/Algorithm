/*
思路：辅助栈
1. 节点入栈
2. 左子节点存在，入栈，重复检查，直至不存在左子节点
3. 取出栈顶节点，记录节点值，针对节点右子节点重复1
*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }

  /*mirris遍历*/
  std::vector<int> inorderMirris(TreeNode* root) {
    std::vector<int> res;
    TreeNode* right = nullptr;

    while (root) {
      right = root->left;

      if (right) {
        while (right->right && right->right != root) {
          right = right->right;
        }

        if (right->right == nullptr) {
          right->right = root;
          root = root->left;
          continue;
        } else {
          right->right = nullptr;
        }
      }
        
      res.emplace_back(root->val);
      root = root->right;
    }

    return res;
  }
};