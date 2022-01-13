/*
给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。*/

/*
思路：层序遍历
*/

class Solution {
public:
  vector<int> rightSideView(TreeNode* root) {
    if(!root) return {};

    // bfs 层序遍历 将每层最后一个加入结果数组
    vector<int> ans;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty())
    {
      int counts = que.size();
      for(int i = 0; i < counts; ++i)
      {
        auto node = que.front();
        que.pop();

        if(node->left)  que.push(node->left);
        if(node->right) que.push(node->right);
        if(i == counts - 1) ans.push_back(node->val);
      }
    }

    return ans;
  }
};