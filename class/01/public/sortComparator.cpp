#include "sortComparator.hpp"
#include <algorithm>

using namespace std;

//对数器中绝对正确但是复杂度较高的算法
int Comparator::GenComparator(std::vector<int> &vec) {
    int res = 0;

    //std 排序函数
    std::sort(vec.begin(), vec.end(), [](int lhs, int rhs) -> bool { return lhs < rhs; });

    return res;
}

std::vector<int> Comparator::Generator() {
    std::vector<int> vec;
    static unsigned seed = (unsigned)time(NULL);
    int size = size_;

    srand(seed);
    seed += seed % 1000;

    while (size--) {
        vec.emplace_back((rand() % (max_ - min_)) + min_);
    }

    return vec;
}

void Comparator::Show(vector<int> vec, int begin, int end) {
    for (int i = begin; i < end; ++i) {
        std::cout << vec[i] << " ";
    }

    std::cout << endl;
}

void Comparator::Swap(vector<int> &vec, int lhs, int rhs) {
#if 0
    vec[lhs] ^= vec[rhs];
    vec[rhs] ^= vec[lhs];
    vec[lhs] ^= vec[rhs];
#else
    int tmp = vec[lhs];
    vec[lhs] = vec[rhs];
    vec[rhs] = tmp;
#endif
}

bool Comparator::Equal(vector<int> &lhs, vector<int> &rhs) {
    for (int i = 0; i < lhs.size(); ++i) {
        if (lhs[i] != rhs[i]) {
            return false;
        }
    }

    return true;
}

int Comparator::Loop(int times, std::function<int(std::vector<int>&)> func) {
    while (times--) {
        std::vector<int> arr = Generator();
        vector<int> arr1(arr.begin(), arr.end());
        vector<int> arr2(arr.begin(), arr.end());

        GenComparator(arr1);
        func(arr2);

        if (!Equal(arr1, arr2)) {
            Comparator::Show(arr, 0, arr.size());
            Comparator::Show(arr1, 0, arr1.size());
            Comparator::Show(arr2, 0, arr2.size());
            std::cout << "Err" << std::endl;
            return 0;
        }
    }

    std::cout << "OK" << std::endl;
    return 0;
}

#ifdef DEBUG
int Sort(std::vector<int> &vec) {
    //1. 比较n次
    for (int i = 0; i < vec.size() - 1; ++i) {
        //2. 每次从剩余未排序的数组里找出最大的并移到数组末尾
        for (int j = 0; j < vec.size() - 1 - i; ++j) {
            if (vec[j] > vec[j+1]) {
                Comparator::Swap(vec, j+1, j);
            }
        }
    }
    return 0;
}

//g++ sortComparator.cpp -o xxx -std=c++11 -DDEBUG
//g++ sortComparator.cpp -c -std=c++11
int main() {
    Comparator cmp(20, 10, 100);
    int times = 500000;

    cmp.Loop(5, Sort);
}
#endif