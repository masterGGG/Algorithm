/*
思路：最小堆 + set去重
1. 1加入最小堆
2. 取出堆顶元素n
3. n分别乘以2，3，5，set去重，不重复的入堆，重复2

时间复杂度：每次取出堆顶O(log N)，重复N次，
          O(N * log N)
空间复杂度 O(N)
*/

class Solution {
public:
  int nthUglyNumber(int n) {
    vector<int> factors = {2, 3, 5};
    unordered_set<long> seen;
    priority_queue<long, vector<long>, greater<long>> heap;
    seen.insert(1L);
    heap.push(1L);
    int ugly = 0;
    for (int i = 0; i < n; i++) {
      long curr = heap.top();
      heap.pop();
      ugly = (int)curr;
      for (int factor : factors) {
        long next = curr * factor;
        if (!seen.count(next)) {
          seen.insert(next);
          heap.push(next);
        }
      }
    }
    return ugly;
  }

  /*
  动态规划：
  dp【i】表示第i个丑数
  定义三个指针 p_2,p_3,p_5表示下一个丑数是当前指针指向的丑数乘以对应的质因数。初始时，三个指针的值都是 1。
  dp[i] = min(p_2 * 2, p_3 * 3, p_5 * 5)

  时间复杂度：O(n)
  空间复杂度：O(n)
  */
  int nthUglyNumber(int n) {
    vector<int> dp(n + 1);
    dp[1] = 1;
    int p2 = 1, p3 = 1, p5 = 1;
    for (int i = 2; i <= n; i++) {
      int num2 = dp[p2] * 2, num3 = dp[p3] * 3, num5 = dp[p5] * 5;
      dp[i] = std::min(std::min(num2, num3), num5);
      if (dp[i] == num2) {
        p2++;
      }
      if (dp[i] == num3) {
        p3++;
      }
      if (dp[i] == num5) {
        p5++;
      }
    }
    return dp[n];
  }
};