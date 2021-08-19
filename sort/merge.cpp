#include "common.hpp"

/*
> 简介
归并排序是建立在归并操作上的一种有效的排序算法。该算法是采用分治法（Divide and Conquer）的一个非常典型的应用。将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。若将两个有序表合并成一个有序表，称为2-路归并。 
> 算法描述
1. 把长度为n的输入序列分成两个长度为n/2的子序列；
2. 对这两个子序列分别采用归并排序；
3. 将两个排序好的子序列合并成一个最终的排序序列。
> 算法分析
稳定排序
时间复杂度：O(nlog n)，每次合并操作需要O（n）的时间复杂度，二分的深度为O（log n）
空间复杂度：O(n)

g++ merge.cpp common.cpp -o xxx -std=c++11
*/

void Merge(std::vector<int> &vec, int start, int end) {
    int left = start;
    int lend = (start + end) / 2;
    int right = lend + 1;
    std::vector<int> array;

    while (left <= lend && right <= end) {
        if (vec[left] <= vec[right]) {
            array.emplace_back(vec[left++]);
        } else {
            array.emplace_back(vec[right++]);
        }
    }

    //将左边剩余元素填充进array中
    while (left <= lend) {
        array.emplace_back(vec[left++]);
    }

    //将右边剩余元素填充进array中
    while (right <= end) {
        array.emplace_back(vec[right++]);
    }

    //将array中的元素全部拷贝到原数组中
    left = start;
    for (auto i : array) {
        vec[left++] = i;
    }

    return;
}

void Sort(std::vector<int> &vec, int start, int end) {
    if (end <= start) {
        return;
    } else if (end - start == 1) {
        if (vec[end] < vec[start]) {
            Swap(vec, start, end);
        }

        return ;
    }

    int mid = (start + end) / 2;
    Sort(vec, start, mid);
    Sort(vec, mid + 1, end);
    Merge(vec, start, end);
    //std::cout << "SortMerge " << start << " - " << end << std::endl;
    //Show(vec);
}


int main() {
    std::vector<int> _vec;// = {9,6,8,5,3,4,7,2,1};
    Init(_vec);
    Sort(_vec, 0, _vec.size() - 1);
    Show(_vec);
    return 0;
}