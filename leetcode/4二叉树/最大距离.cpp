/*
递归分治
1. 获取左右子树的最大距离
2. 左右子树的最大距离和+2是否大于记录的最大距离，实时更新
3. 返回左右子树中最大的距离。
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