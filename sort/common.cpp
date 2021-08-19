#include "common.hpp"

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
