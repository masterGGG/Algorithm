#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>

using namespace std;

/*
设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。
输入： arr = [1,3,5,7,2,4,6,8], k = 4
输出： [1,2,3,4]
*/

class Solution {
public:
    void swap(vector<int>& arr, int pre, int cur) {
        int tmp = arr[pre];
        arr[pre] = arr[cur];
        arr[cur] = tmp;
    }

    void smallestN(vector<int>& arr, int begin, int end, int n) {
        if (begin >= end) {
            return;
        }

        int less = begin - 1;
        int more = end;
        int pos = begin;
        
        //荷兰国旗问题，将数组排序成 较小的 相等的 较大的 三个部分
        while (pos < more) {
            if (arr[pos] < arr[end]) {
                swap(arr, pos++, ++less);
            } else if(arr[pos] > arr[end]) {
                swap(arr, pos, --more);
            } else {
                pos++;
            }
        }

        swap(arr, more, end);
        //此时less表示较小区间中，最后一个元素的下标
        //more表示相等区间中，最后一个元素的下标

        if (n <= less + 1 - begin) {
            //如果较小区间元素个数大于需要查找的个数，在较小区间中查找前n个数
            return smallestN(arr, begin, less, n);
        } else if (n > more + 1 - begin) {
            //如果前两个区间元素个数不够前n个元素，在较大区间中查找较小的`n-(more+1)`个元素
            return smallestN(arr, more + 1, end, n - more - 1 + begin);
        } else {
            //如果在相等的区间，说明已经找到对应的位置了
            return;
        }
    }

    vector<int> smallestK(vector<int>& arr, int k) {
        if (k == 0) {
            return vector<int>();
        } 

        if (k == arr.size()) {
            return arr;
        }
        
        smallestN(arr, 0, arr.size() - 1, k);

        return vector<int>(arr.begin(), arr.begin() + k);
    }
};