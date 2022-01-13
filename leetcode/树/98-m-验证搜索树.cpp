/*
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
有效 二叉搜索树定义如下：
节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
*/

/*
思路：中序遍历有序
*/
class Solution {
public:
    void SeriliazeBST(TreeNode* root, deque<int> &queue) {
        if (root == nullptr) {
            return ;
        }

        SeriliazeBST(root->left, queue);
        queue.push_back(root->val);
        SeriliazeBST(root->right, queue);
    }
    bool isValidBST(TreeNode* root) {
        deque<int> queue;
        SeriliazeBST(root, queue);

        int prev = queue.front();
        queue.pop_front();

        while (!queue.empty()) {
            int next = queue.front();
            queue.pop_front();

            if (next <= prev) {
                return false;
            }

            prev = next;
        }

        return true;
    }
};