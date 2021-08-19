#ifndef __ALGO_COMMON_H__
#define __ALGO_COMMON_H__

#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <functional>

class Comparator {
public:
    Comparator(int size = 0, int min = 0, int max = 0) : size_(size),min_(min),max_(max) {}

    std::vector<int> Generator();
    static int GenComparator(std::vector<int> &vec);
    static void Show(std::vector<int> vec, int begin, int end);
    static void Swap(std::vector<int> &vec, int lhs, int rhs);
    static bool Equal(std::vector<int> &lhs, std::vector<int> &rhs);
    int Loop(int times, std::function<int(std::vector<int>&)> func);

public:
    int min_;
    int max_;
    int size_;
};
#endif