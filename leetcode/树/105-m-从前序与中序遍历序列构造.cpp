/*
思路：
1. 前序序列获取根节点值，构造根节点
2. 中序序列确认左右子树序列
3. 划分左右子树前序和中序序列，重复1
*/
class Solution {
public:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int prepos, int inpos, int left) {
      if (left == 0) {
        return nullptr;
      }

      TreeNode *root = new TreeNode(preorder[prepos]);
      int offset = 0;

      while (preorder[prepos] != inorder[inpos + offset]) {
        offset++;
      }

      root->left = helper(preorder, inorder, prepos + 1, inpos, offset);
      root->right = helper(preorder, inorder, prepos + 1 + offset, inpos + offset + 1, left - 1 - offset);

      return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      return helper(preorder, inorder, 0, 0, preorder.size());
    }
};