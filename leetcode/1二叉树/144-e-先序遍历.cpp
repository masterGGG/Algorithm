/*
思路：辅助栈
1. 根节点入栈
2. 取栈顶节点，记录节点值
3. 右子节点入栈
4. 左子节点入栈，跳转到2
*/

class TreeIterator {
public:
  std::vector<int> preorder(TreeNode* root) {
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
mirris遍历
1. 如果cur无左孩子，cur向右移动（cur=cur.right）
2. 如果cur有左孩子，找到cur左子树上最右的节点，记为mostright
    2.1 如果mostright的right指针指向空，让其指向cur，cur向左移动（cur=cur.left）
    2.2 如果mostright的right指针指向cur，让其指向空，cur向右移动（cur=cur.right）
*/
  std::vector<int> preorderMirris(TreeNode* root) {
    std::vector<int> res;
    TreeNode* right = nullptr;

    while (root) {
      right = root->left;

      if (right) {
        while (right->right && right->right != root) {
          right = right->right;
        }

        if (right->right == nullptr) {
          res.emplace_back(root->val);
          right->right = root;
          root = root->left;
          continue;
        } else {
          right->right = nullptr;
        }
      } else {
        res.emplace_back(root->val);
      }

      root = root->right;
    }

    return res;
  }

};