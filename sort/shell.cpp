#include <iostream>
#include <vector>

/*
# 简介
```
1959年Shell发明，第一个突破O(n2)的排序算法，是简单插入排序的改进版。它与插入排序的不同之处在于，它会优先比较距离较远的元素。希尔排序又叫缩小增量排序。
```
# 算法描述
先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序，具体算法描述：
1. 选择一个增量序列t1，t2，…，tk，其中ti>tj，tk=1；
2. 按增量序列个数k，对序列进行k 趟排序；
3. 每趟排序，根据对应的增量ti，将待排序列分割成若干长度为m 的子序列，分别对各子表进行直接插入排序。仅增量因子为1 时，整个序列作为一个表来处理，表长度即为整个序列的长度。

g++ shell.cpp -o xxx -std=c++11
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

//直接插入排序
void Insert(std::vector<int> &vec, int start, int step) {
    for (int i = start + step; i < vec.size(); i += step) {
        int value = vec[i];
        int j;

        for (j = i - step; j >= 0; j -= step) {
            if (vec[j] > value) {
                vec[j + step] = vec[j];
            } else {
                break;
            }
        }
        
        vec[j + step] = value;
    }
}

/*
1. 选择一个增量序列t1，t2，…，tk，其中ti>tj，tk=1；
2. 按增量序列个数k，对序列进行k 趟排序；
3. 每趟排序，根据对应的增量ti，将待排序列分割成若干长度为m 的子序列，分别对各子表进行直接插入排序。仅增量因子为1 时，整个序列作为一个表来处理，表长度即为整个序列的长度。
*/
void Shell(std::vector<int> &vec) {
    for (int step = vec.size() / 2; step > 0; step/=2) {
        for (int i = 0; i < step; i++) {
            Insert(vec, i, step);
        }
    }
}

void ShellX(std::vector<int> &vec) {
    for (int step = vec.size() / 2; step > 0; step/=2) {
        // 注意：这里是多个分组交替执行
        /*self implement
        for (int i = vec.size() - 1; i >= 0; i--) {
            if (i - step >=0 && vec[i] < vec[i - step]) {
                Swap(vec, i, i - step);
            }
        }
        */
       for (int i = step; i < vec.size(); ++i) {
           int value = vec[i];
           int j;
           for (j = i - step; j >= 0; j -= step) {
               if (vec[j + step] < vec[j]) {
                   vec[j + step] = vec[j];
               } else {
                   break;
               }
           }
           vec[j + step] = value; 
       }
    }
}

int main() {
    std::vector<int> _vec;//= {5,4,7,1,8,6,2,9,3};
    Init(_vec);
    ShellX(_vec);
    Show(_vec);
    return 0;
}