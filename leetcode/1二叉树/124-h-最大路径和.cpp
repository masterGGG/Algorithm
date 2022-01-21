/*
路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。
路径和 是路径中各节点值的总和。
给你一个二叉树的根节点 root ，返回其 最大路径和 。
*/

/*
思路：递归+回溯
返回以当前节点为起点的最大路径
*/

class Solution {
public:
  int maxPathHelper(TreeNode* root, int &sum) {
    if (!root) {
      return 0;
    }

    // 递归计算左右子节点的最大贡献值
    // 只有在最大贡献值大于 0 时，才会选取对应子节点
    int left = std::max(maxPathHelper(root->left, sum), 0);
    int right = std::max(maxPathHelper(root->right, sum), 0);
    // 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
    int all = left + right + root->val;
    sum = std::max(all, sum);

    return root->val + std::max(left, right);
  }

  int maxPathSum(TreeNode* root) {
    int sum = 0;
    maxPathHelper(root, sum);
    return sum;
  }
};