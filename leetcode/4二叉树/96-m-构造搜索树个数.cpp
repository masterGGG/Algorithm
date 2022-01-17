/*
给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。
 */

class Solution {
public:
/*常规解法
思想 假定n个节点构成二叉树个数为F(n)
那么N个节点，以i为节点的二叉树个数为： F(i - 1) * F(N - i)
N个节点的BST个数为： F(0)*F(N-1) + F(1)*F(N-2) + ... + F(N-1)*F(0)
*/
  int numTrees(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        dp[i] += dp[j] * dp[i - j - 1];
      }
    }

    return dp[n];
  }

/*卡塔兰数：F(n) = (4n+2)/(n+1) * F(n-1)
               = [4*(n-1) + 6] / [(n-1) + 2] * F(n-1)
        ====>>> F(n + 1) = 2(2n + 3)/(n+2) *F(n)       
*/
  int numTrees(int n) {
      int C = 1;

      for (int i = 0; i < n; ++i) {
          C = (4 * i + 2) / (i + 1) * C;
      }

      return C;
  }
};