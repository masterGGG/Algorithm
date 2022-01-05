/*
给定一棵树的前序遍历 preorder 与中序遍历  inorder。请构造二叉树并返回其根节点。
*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, int prehead, int precount, vector<int>& inorder, int inhead, int incount) {
      if (precount == 0) {
        return nullptr;
      }

      TreeNode *root = new TreeNode(preorder[prehead]);
      
      if (precount == 1) {
        return root;
      }

      int count = 0;

      while (preorder[prehead] != inorder[inhead + count]) {
        count++;
      }

      root->left = buildTree(preorder, prehead + 1, count, inorder, inhead, count);
      root->right = buildTree(preorder, prehead + 1 + count, precount - 1 - count, inorder, inhead + count + 1, precount - 1 - count);

      return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      if (preorder.size() == 0) {
        return nullptr;
      }

      return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};