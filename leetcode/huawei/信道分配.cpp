/*
将通信的信道尽可能多的分配给用户
信道分配规则如下：
1.所有信道都有属性：阶，r阶信道的容量为2^r
2.所有用户需要传输的数据量是一样的，D比特
3.一个用户可以分配多个信道，但每个信道只能分配给一个用户
4.只有当分配给一个用户的所有信道容量和超过D，才能传输数据
给出一组信道资源，计算能够为多少用户传输数据。
输入参数
R：一个信道的阶 0<=R<=20
R+1个数字：代表每种信道的数量N(i), 0<=i<=R, 0<=N<1000
D:单个用户需要传输的数据量， 0 < D < 1000000
*/
#include <vector>
#include <iostream>

std::vector<int> g_capacity_ = {1,2,4,8,16,
                              32,64,128,256,1024,
                              2048,4096,8192,16384,32768,
                              65536,131072,262144,524288,1048576};

class Solution {
public:
  int getIndex(int capa, int size) {
    for (int i = size - 1; i >= 0; --i) {
      if (g_capacity_[i] < capa) {
        return i + 1;
      }
    }

    return 0;
  }
  int dispatch(std::vector<int> vec, int preD) {
    int max = vec.size() - 1;
    int total = 0;

    for (int i = max; i >= 0;) {
      if (vec[i] > 0) {
        int resetD = preD - g_capacity_[i];
        vec[i] -= 1;
        
        if (resetD <= 0) {
          total += vec[i];
          vec[i] = 0;
          --i;
          continue;
        }

        while (resetD > 0) {
          int pos = getIndex(resetD, i);

          while (vec[pos] <= 0 && pos > 0) {
            pos--;
          }

          if (vec[pos] == 0) {
            return total;
          }

          resetD -= g_capacity_[pos];
          vec[pos] -= 1;
        }

        total++;
      } else {
        --i;
      }
    }

    return total;
  }
};
//g++ 信道分配.cpp -o xxx -std=c++11
int main() {
  std::vector<int> count_ = {3, 10, 10, 1, 20};
  Solution s;
  std::cout << "23 " << s.dispatch(count_, 23) << std::endl;
  return 0;
}