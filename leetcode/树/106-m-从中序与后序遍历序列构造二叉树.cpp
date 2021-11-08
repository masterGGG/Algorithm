/*
根据一棵树的中序遍历与后序遍历构造二叉树。
注意:
你可以假设树中没有重复的元素。
例如，给出
中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：
    3
   / \
  9  20
    /  \
   15   7
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      int postindex = postorder.size() - 1;
      TreeNode *root = new TreeNode(postorder[postindex]);
      std::stack<TreeNode *> stack_;
      stack_.push(root);
      
      while ()
    }
};