/*
思路：二分思想
1. 求左子树的高度（依次遍历左子节点）
2. 求右子树的高度
3. H（左） == H（右），左子树是满二叉树，将右子树作为根节点重复 1
H（左） == H（右），左子树是满二叉树，将左子树作为根节点重复 1
满二叉树的节点数是2的树高加1次幂减1
*/
class Solution {
public:
    int getHeight(struct TreeNode *root) {
        int level = 0;
        while (root) {
            level++;
            root = root->left;
        }
        return level;
    }

    int getNode(struct TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int lHeight = getHeight(root->left);
        int rHeight = getHeight(root->right);
        int count = 1;

        if (lHeight == 0) {
            return count;
        } else if (lHeight == rHeight) {
            count += int(pow(2.0, lHeight)) - 1;
            count += getNode(root->right);
        } else {
            count += int(pow(2.0, rHeight)) - 1;
            count += getNode(root->left);
        }

        return count;
    }

    int countNodes(TreeNode* root) {
        return getNode(root);
    }
};