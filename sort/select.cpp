#include <iostream>
#include <vector>

/*
> 简介
选择排序是一种简单直观的排序算法，无论什么数据进去都是 O(n²) 的时间复杂度。所以用到它的时候，数据规模越小越好。唯一的好处可能就是不占用额外的内存空间了吧。
> 算法步骤
1. 首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置。
2. 再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。
3. 重复第二步，直到所有元素均排序完毕。

g++ select.cpp -o xxx -std=c++11
*/

void Show(std::vector<int> vec) {
    for (auto it : vec) {
        std::cout << it << " - ";
    }

    std::cout << std::endl;
}

void Swap(std::vector<int> &vec, int lhr, int rhr) {
    if (lhr != rhr) {
        int tmp = vec[lhr];
        vec[lhr] = vec[rhr];
        vec[rhr] = tmp;
    }
}

void Init(std::vector<int> &vec) {
    std::cout << "please input one num,enter 0 exit: ";
    int num = 0;
    std::cin >> num;

    while (num != 0) {
        vec.emplace_back(num);
        std::cout << "Current num array: ";
        Show(vec);
        std::cout << "please input one num,enter 0 exit: ";
        std::cin >> num;
    }
}

//排序
void Select(std::vector<int> &vec) {
    int min,index;
    for (int i = 0; i < vec.size(); ++i) {
        min = vec[i];
        index = i;

        for (int j = i + 1; j < vec.size(); ++j) {
            if (vec[j] < min) {
                min = vec[j];
                index = j;
            }
        }

        Swap(vec, i, index);
    }
}


int main() {
    std::vector<int> _vec;// = {5,4,7,1,8,6,2,9,3};
    Init(_vec);
    Select(_vec);
    Show(_vec);
    return 0;
}