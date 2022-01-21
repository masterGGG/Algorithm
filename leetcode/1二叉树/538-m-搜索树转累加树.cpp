/*
思路：二叉搜索树 中序遍历是一个递增序列
反向中序遍历就是递减序列
反向中序遍历并实时更新节点值即可
*/

class Solution {
public:
    int sum = 0;

    TreeNode* convertBST(TreeNode* root) {
        if (root != nullptr) {
            convertBST(root->right);
            sum += root->val;
            root->val = sum;
            convertBST(root->left);
        }
        return root;
    }
};