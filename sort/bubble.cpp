#include "common.hpp"

/*
# 简介
冒泡排序是一种简单的排序算法。它重复地走访过要排序的数列，一次比较两个元素，如果它们的顺序错误就把它们交换过来。走访数列的工作是重复地进行直到没有再需要交换，也就是说该数列已经排序完成。这个算法的名字由来是因为越小的元素会经由交换慢慢“浮”到数列的顶端。 
# 算法描述
1. 比较相邻的元素。如果第一个比第二个大，就交换它们两个；
2. 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对，这样在最后的元素应该会是最大的数；
3. 针对所有的元素重复以上的步骤，除了最后一个；
4. 重复步骤1~3，直到排序完成。

g++ bubble.cpp -o xxx -std=c++11
*/
void SortX(std::vector<int> &vec) {
    for (int i = vec.size() - 1; i >= 0; --i) {
        //2. 每次从剩余未排序的数组里找出最大的并移到数组末尾
        for (int j = 0; j < i - 1; ++j) {
            if (vec[j] > vec[j+1]) {
                int tmp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = tmp;
                //vec[j], vec[j+1] = vec[j+1], vec[j];
            }
        }
    }

    return;
}

void Sort(std::vector<int> &vec) {
    //1. 比较n次
    for (int i = 0; i < vec.size() - 1; ++i) {
        //2. 每次从剩余未排序的数组里找出最大的并移到数组末尾
        for (int j = 0; j < vec.size() - 1 - i; ++j) {
            if (vec[j] > vec[j+1]) {
                int tmp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = tmp;
                //vec[j], vec[j+1] = vec[j+1], vec[j];
            }
        }
    }
    return ;
}

int main() {
    std::vector<int> _vec = {5,4,7,1,8,6,2,9,3};
    //Init(_vec);

    SortX(_vec);

    for (auto it : _vec) {
        std::cout << it << " - ";
    }

    std::cout << std::endl;
    return 0;
}