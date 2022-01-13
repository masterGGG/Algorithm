/*
给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
*/

//层序遍历
class Solution {
public:
  vector<int> rightSideView(TreeNode* root) {
    //按层次遍历的最后⼀一个节点
    std::vector<int> view; 
    std::queue<std::pair<TreeNode*,int> > q; 
    
    if(root){
      q.push(std::make_pair(root,0));
    }

    while(!q.empty()){
      //搜索节点
      TreeNode *node=q.front().first; //待搜索的层数
      int depth=q.front().second; q.pop(); 
      if(view.size()==depth){
        view.push_back(node->val);
      }else{
        view[depth]=node->val;
      }
      if(node->left){
        q.push(std::make_pair(node->left,depth+1));
      }
      if(node->right){
        q.push(std::make_pair(node->right,depth+1));
      }
    }
    return view;
  }
};