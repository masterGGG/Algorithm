#include "common.hpp"

/*
# 简介
```
插入排序（Insertion-Sort）的算法描述是一种简单直观的排序算法。它的工作原理是通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
```
# 算法描述
一般来说，插入排序都采用in-place在数组上实现。具体算法描述如下：
1. 从第一个元素开始，该元素可以认为已经被排序；
2. 取出下一个元素，在已经排序的元素序列中从后向前扫描；
3. 如果该元素（已排序）大于新元素，将该元素移到下一位置；
4. 重复步骤3，直到找到已排序的元素小于或者等于新元素的位置；
5. 将新元素插入到该位置后；
6. 重复步骤2~5。

g++ insert.cpp -o xxx -std=c++11
*/

/*
1. 从第一个元素开始，该元素可以认为已经被排序；
2. 取出下一个元素，在已经排序的元素序列中从后向前扫描；
3. 如果该元素（已排序）大于新元素，将该元素移到下一位置；
4. 重复步骤3，直到找到已排序的元素小于或者等于新元素的位置；
5. 将新元素插入到该位置后；
6. 重复步骤2~5。
*/
void InsertSort(std::vector<int> &vec) {
    //从第一个元素开始，该元素可以认为已经被排序；
    for (int i = 1; i < vec.size(); ++i) {
        //取出下一个元素，在已经排序的元素序列中从后向前扫描；
        for (int j = i - 1; j >= 0; --j) {
            //如果该元素（已排序）大于新元素，将该元素移到下一位置；
            if (vec[j+1] < vec[j]) {
                Swap(vec, j+1, j);
            } else {
                break;
            }
        }
    }
}

void Insert1(std::vector<int> &vec) {
    for (int i = 1; i < vec.size(); ++i) {
        int value = vec[i];
        int j;

        for (j = i - 1; j >= 0; --j) {
            if (vec[j] > value) {
                vec[j + 1] = vec[j];
            } else {
                break;
            }
        }
        
        vec[j + 1] = value;
    }
}

int main() {
    std::vector<int> _vec;// = {5,4,7,1,8,6,2,9,3};
    Init(_vec);

    //Sort(_vec, 0, _vec.size() - 1);
    Insert1(_vec);
    Show(_vec);
    return 0;
}