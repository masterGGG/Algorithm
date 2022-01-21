/*
思路：辅助栈
1. 根节点入栈
2. 取栈顶节点，节点值写入辅助栈,
3. 右子节点入栈
4. 左子节点入栈，跳转到2
5. 依此取出栈中值
*/

class Solution {
public:
  std::vector<int> posorder(TreeNode* root) {
    std::vector<int> res;
    std::stack<TreeNode *> stk;
    std::stack<int> reverse;
    
    if (root) {
      stk.push(root);
    }

    while (!stk.empty()) {
      root = stk.top();
      stk.pop();

      if (root->left) {
        stk.push(root->left);
      }

      if (root->right) {
        stk.push(root->right);
      }

      reverse.push(root->val);
    }

    while (!reverse.empty()) {
      res.emplace_back(reverse.top());
      reverse.pop();
    }

    return res;
  }
};