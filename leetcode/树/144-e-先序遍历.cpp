/*
思路：辅助栈
1. 根节点入栈
2. 取栈顶节点，记录节点值
3. 右子节点入栈
4. 左子节点入栈，跳转到2
*/

class TreeIterator {
public:
  std::vector<int> inorder(TreeNode* root) {
    std::vector<int> res;
    std::stack<TreeNode *> stk;
    if (root) {
      stk.push(root);
    }

    while (!stk.empty()) {
      root = stk.top();
      stk.pop();

      if (root->right) {
        stk.push(root->right);
      }

      if (root->left) {
        stk.push(root->left);
      }

      res.emplace_back(root->val);
    }

    return res;
  }
/*
  std::vector<int> inorder1(TreeNode* root) {
    std::vector<int> res;
    std::stack<TreeNode *> stk;

    while (root || !stk.empty()) {      
      while (root) {
        stk.push(root);
        root = root->left;
      }

      root = stk.top();
      stk.pop();
      res.emplace_back(root->val);
      root = root->right;
    }

    return res;    
  }
*/
};