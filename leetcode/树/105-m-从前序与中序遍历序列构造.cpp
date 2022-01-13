/*
给定一棵树的前序遍历 preorder 与中序遍历  inorder。请构造二叉树并返回其根节点。
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