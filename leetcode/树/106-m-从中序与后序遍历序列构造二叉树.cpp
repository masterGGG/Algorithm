/*
根据一棵树的中序遍历与后序遍历构造二叉树。
*/

class Solution {
public:
    TreeNode* buildTree(vector<int> inorder, int inhead, vector<int> postorder, int posthead, int size) {
      if (size == 0) {
        return nullptr;
      }

      TreeNode *root = new TreeNode(postorder[posthead + size - 1]);

      int count = 0;

      while (inorder[inhead + count] != postorder[posthead + size - 1]) {
        count++;
      }
      
      root->left =  buildTree(inorder, inhead, postorder, posthead, count);
      root->right = buildTree(inorder, inhead + count + 1, postorder, posthead + count, size - 1 - count);;

      return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      return buildTree(inorder, 0, postorder, 0, inorder.size());
    }
};