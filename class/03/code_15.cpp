#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

/*
旋转数组的最小值？？？
*/

void printArr(std::vector<int> vec) {
    int i = 0;

    std::cout << "Arr ";

    while (i < vec.size()) {
        std::cout << vec[i++] << ", ";
    }

    std::cout << std::endl;
}

int getLessIndex(std::vector<int> vec) {
    if (vec.size() == 0) {
        return -1; // no exist
    }

    if (vec.size() == 1 || vec[0] < vec[1]) {
        return 0;
    }

    if (vec[vec.size() - 1] < vec[vec.size() - 2]) {
        return vec[vec.size() - 1];
    }

    int left = 1;
    int right = vec.size() - 2;
    int mid = 0;
    while (left < right) {
        mid = (left + right) / 2;
        if (vec[mid] > vec[mid - 1]) {
            right = mid - 1;
        } else if (vec[mid] > vec[mid + 1]) {
            left = mid + 1;
        } else {
            return mid;
        }
    }

    return left;
}

//g++ code_15.cpp  -o xxx -std=c++11
int main() {
    std::vector<int> vec = {6, 5, 3, 4, 6, 7, 8};
    
    printArr(vec);
    int index = getLessIndex(vec);
    std::cout << "Index " << index << "," << vec[index] << std::endl;
    return 0;
}