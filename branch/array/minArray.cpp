/*
[旋转数组的最小数字](https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/solution/mian-shi-ti-11-xuan-zhuan-shu-zu-de-zui-xiao-shu-3/)
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  

示例 1：

输入：[3,4,5,1,2]
输出：1
示例 2：

输入：[2,2,2,0,1]
输出：0

//先排序，然后在拿第一个
if (numbers.size() == 0) {
    return 0;
}

sort(numbers.begin(), numbers.end());

return numbers[0];
*/

#include <vector>

using namespace std;

class Solution {
public:
/*
执行用时：8 ms, 在所有 C++ 提交中击败了54.95%的用户
内存消耗：11.7 MB, 在所有 C++ 提交中击败了94.30%的用户
*/
int minArray1(vector<int>& numbers) {
    if (numbers.size() == 0) {
        return 0;
    }

    sort(numbers.begin(), numbers.end());

    return numbers[0];
}

    int minArray(vector<int>& numbers) {
        int start = 0;
        int end = numbers.size() - 1;
        int mid;

        if (!numbers.size()) {
            return 0;
        } else if (!end) {
            return numbers[end];
        }

        do {
            mid = (start + end) / 2;

            /*如果无法确定二分区间，则顺序查找最小值
            执行用时：4 ms, 在所有 C++ 提交中击败了92.31%的用户
            内存消耗：11.8 MB, 在所有 C++ 提交中击败了55.19%的用户
            if (numbers[mid] == numbers[end] && numbers[end] == numbers[start]) {
                int min = numbers[end];

                for (int i = start + 1; i < end; ++i) {
                    if (numbers[i] < min) {
                        min = numbers[i] ;
                    }
                }

                return min;
            }*/

            //如果能确定最小值的区间，使用二分的方式去找最小值
            if (numbers[mid] < numbers[end]) {
                end = mid;
            } else if (numbers[mid] > numbers[end]) {
                start = mid;
            } else {
                /*
                执行用时：8 ms, 在所有 C++ 提交中击败了54.95%的用户
                内存消耗：11.9 MB, 在所有 C++ 提交中击败了16.11%的用户
                */
                end--;
            }

            if (end - start <= 1) {
                return numbers[start] > numbers[end] ? numbers[end] : numbers[start];
            }
        } while (1);

        return 0;
    }
};