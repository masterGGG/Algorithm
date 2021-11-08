/*
给定一棵树的前序遍历 preorder 与中序遍历  inorder。请构造二叉树并返回其根节点。

示例 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
示例 2:
Input: preorder = [-1], inorder = [-1]
Output: [-1]

提示:
1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder 和 inorder 均无重复元素
inorder 均出现在 preorder
preorder 保证为二叉树的前序遍历序列
inorder 保证为二叉树的中序遍历序列
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