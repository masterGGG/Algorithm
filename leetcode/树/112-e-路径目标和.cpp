/*给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，
这条路径上所有节点值相加等于目标和targetSum 。如果存在，返回 true ；否则，返回 false 。
*/

/*
思路：先序遍历，递归寻找目标值
*/

class Solution {
public:
  bool hasPathSum(TreeNode *root, int sum) {
    if (root == nullptr) {
      return false;
    }
    if (root->left == nullptr && root->right == nullptr) {
      return sum == root->val;
    }
    return hasPathSum(root->left, sum - root->val) ||
            hasPathSum(root->right, sum - root->val);
  }
};

/*给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。*/
/*
思路：DFS
*/
class Solution {
public:
  vector<vector<int>> ret;
  vector<int> path;

  void dfs(TreeNode* root, int targetSum) {
    if (root == nullptr) {
        return;
    }
    path.emplace_back(root->val);
    targetSum -= root->val;
    if (root->left == nullptr && root->right == nullptr && targetSum == 0) {
        ret.emplace_back(path);
    }
    dfs(root->left, targetSum);
    dfs(root->right, targetSum);
    path.pop_back();
  }

  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    dfs(root, targetSum);
    return ret;
  }
};