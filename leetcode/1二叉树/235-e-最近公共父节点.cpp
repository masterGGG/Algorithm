/*
递归方法
1. 分解为求左子树的子问题和右子树的子问题，边界为找到某个节点，或者遍历到空节点
2. 以后序遍历的方式处理子问题
3. 左右子树都找到，则当前节点为最近公共父节点
4. 有一个子树没找到，则另一个子树的返回值为最近公共子节点。
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