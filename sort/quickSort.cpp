#include <iostream>
#include <vector>
#include <algorithm>

void swap(std::vector<int> &vec, int a, int b) {
  int tmp = vec[a];
  vec[a] = vec[b];
  vec[b] = tmp;
}

void qsort(std::vector<int> &vec, int begin, int end) {
  if (begin >= end) {
    return;
  }

  int less = begin - 1, more = end + 1, pos = begin, povit = vec[begin];

  while (pos < more) {
    if (vec[pos] < povit) {
      swap(vec, pos++, ++less);
    } else if (vec[pos] > povit) {
      swap(vec, pos, --more);
    } else {
      pos++;
    }
  }

  qsort(vec, begin, less);
  qsort(vec, more, end);
}

void qsort(std::vector<int> &vec) {
  qsort(vec, 0, vec.size() - 1);
}

void test(int times) {
  while (times--) {}
}

//g++ quickSort.cpp -o xxx -std=c++11
int main() {
  //test(int times);
  std::vector<int> vec = {9,2,4,6,7,1,5};
  qsort(vec);
  for (auto i : vec) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}