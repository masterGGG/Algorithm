#include <iostream>
#include <vector>

/*
# 简介
```
快速排序的基本思想：通过一趟排序将待排记录分隔成独立的两部分，其中一部分记录的关键字均比另一部分的关键字小，则可分别对这两部分记录继续进行排序，以达到整个序列有序。
```
# 算法描述
快速排序使用分治法来把一个串（list）分为两个子串（sub-lists）。具体算法描述如下：
1. 从数列中挑出一个元素，称为 “基准”（pivot）；
2. 重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作；
3. 递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序。

g++ quick.cpp -o xxx -std=c++11
*/

void Show(std::vector<int> vec) {
    for (auto it : vec) {
        std::cout << it << " - ";
    }

    std::cout << std::endl;
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

void Swap(int &a, int &b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

void Sort(std::vector<int> &vec, int start, int end) {
    if (end <= start) {
        return;
    } else if (start == end - 1) {
        //只有两个元素时，直接比较大小
        if (vec[0] > vec[1]) {
            Swap(vec[0], vec[1]);
        }

        return ;
    }

    int pivot = vec[start];
    int head = start + 1;
    int tail = end;

    while (head <= tail) {
        //正序遍历，找出第一个比pivot大的索引
        while (head <= tail && vec[head] < pivot) {
            head++;
        }

        //反向遍历，找出第一个比pivot小的索引
        while (tail >= head && vec[tail] >= pivot) {
            tail--;
        }

        //如果head在tail之前，则交换head和tail的值
        if (head < tail) {
            Swap(vec[head], vec[tail]);
        }
    }

    if (start != tail) {
        Swap(vec[start], vec[tail]);
    }

    //std::cout << "start: " << start << " end: " << end << std::endl;
    //Show(vec);
    Sort(vec, start, tail - 1);
    Sort(vec, head, end);
 
    return ;
}


void QuickSort(std::vector<int> &vec, int start, int end) {
    if (start < end) {
        int pivot = vec[start];
        int head = start;
        int tail = end;

        while (head < tail) {
            // Step 1. 反向遍历，找出第一个比pivot小的元素x
            while (head < tail && vec[tail] > pivot) {
                tail--;
            }

            // Step 2. 还有元素未处理，将正向遍历的第一个大于等于pivot元素值改为x（初始为pivot所在位置）
            if (head < tail) {
                vec[head] = vec[tail];
                head++;
            }

            // Step 3. 正向遍历，找出第一个大于等于pivot的元素y
            while (head < tail && vec[head] < pivot) {
                head++;
            }

            // Step 4. 还有元素未处理，将反向遍历的第一个小于pivot元素值改为y（该位置的值已经在Step 2中赋值给前面某个位置了）
            if (head < tail) {
                vec[tail] = vec[head];
                tail--;
            }
        }

        // Step 5. 空出的head的位置就是pivot的最终位置
        vec[head] = pivot;

        // Step 6. 分别排序pivot分割的左右分区
        QuickSort(vec, start, head - 1);
        QuickSort(vec, head + 1, end);
    }
}

int main() {
    std::vector<int> _vec;// = {5,4,7,1,8,6,2,9,3};
    Init(_vec);

    //Sort(_vec, 0, _vec.size() - 1);
    QuickSort(_vec, 0, _vec.size() - 1);

    Show(_vec);
    return 0;
}