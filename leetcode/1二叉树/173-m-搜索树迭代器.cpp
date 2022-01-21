/*
思路：非递归中序遍历（辅助栈）
1. 节点入栈
2. 左子节点存在，入栈，重复检查，直至不存在左子节点
3. 取出栈顶节点，记录节点值，针对节点右子节点重复1
*/
class BSTIterator {
public:
    std::stack<TreeNode*> _stack;

    BSTIterator(TreeNode* root) {
      while (root) {
        _stack.push(root);
        root = root->left;
      }
    }
    
    int next() {
      if (!_stack.empty()) {
        TreeNode* root = _stack.top(); 
        _stack.pop();

        int res = root->val;
        root = root->right;

        while (root) {
          _stack.push(root);
          root = root->left;
        }

        return res;
      }

      return -1;
    }
    
    bool hasNext() {
      return !_stack.empty();
    }
};