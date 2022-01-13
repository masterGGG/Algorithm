/*
二叉树节点间的最⼤距离
*/

int maxDistance=0;
int binTreeMaxDistance(TreeNode *root){
  if(root==NULL){
    return -1;
  }
  
  int left=binTreeMaxDistance(root->left);
  int right=binTreeMaxDistance(root->right);
  int distance=left+right+2;

  maxDistance=std::max(distance, maxDistance);

  return std::max(left, right) + 1;
}