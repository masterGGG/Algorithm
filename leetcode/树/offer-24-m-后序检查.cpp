/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
*/

/*
思路：根据后序中的跟节点，将数组分为左右子数组，递归判断
*/
class Solution {
public:
  bool verifyPostorder(vector<int>& postorder, int l, int r) {
    if(l >= r) {
      return true;
    }

    int i = l;
    //左子树节点全小于根节点，
    while(i < r && postorder[i] < postorder[r]) ++i;
    if(i == r) {
      //没有右子树，对应的数是只有左子树的单支树，递归考虑左子树
      return verifyPostorder(postorder, l, r-1);
    }
    //存储找到的右子树序列的第一个位置
    int tmp = i;
    while(i < r && postorder[i] > postorder[r]) ++i;
    if(i < r) {
      return false;
    }
    //判断左右区间是不是二叉搜索树
    return verifyPostorder(postorder,l,tmp-1) && verifyPostorder(postorder,tmp,r-1);//递归考虑左子树和右子树
  }

  bool verifyPostorder(vector<int>& postorder) {
    return verifyPostorder(postorder, 0, postorder.size() - 1);
  }
};