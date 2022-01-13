/*
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
*/

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {//递归边界
            return nullptr;
        } else if (root == p || root == q) {
            return root;
        }
        //分解为求左子树的子问题和右子树的子问题
        TreeNode* leftroot = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightroot = lowestCommonAncestor(root->right, p, q);
        //注意是后序遍历
        if (leftroot && rightroot) {//左右子树都有则返回root
            return root;
        }
        //如果左右子树中有一个子问题没得到结果，则返回得到结果的子问题.
        return leftroot ? leftroot : rightroot;
    }
};