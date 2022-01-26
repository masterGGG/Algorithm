/*
思路：头尾双指针，
移动规则：移动头尾指针中，比较小的一个
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int prev = 0;
        int head = height[prev];
        int last = height.size() - 1;
        int tail = height[last];
        int max = 0;
        int area = 0;

        while (prev < last) {
            if (head > tail) {
                area = tail * (last - prev);
                last--;
            } else {
                area = head * (last - prev);
                prev++;
            }
    
            if (max < area) {
                max = area;
            }

            if (head > tail) {
                while (height[last] < tail) {
                    last--;
                }

                tail = height[last];
            } else {
                while (height[prev] < head) {
                    prev++;
                }

                head = height[prev];
            }
        }

        return max;
    }
};

/*
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
[盛最多水的容器](https://leetcode-cn.com/problems/container-with-most-water/)
*/