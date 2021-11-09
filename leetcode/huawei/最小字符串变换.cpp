/*
给定一个字符串，最多只能进行一次变换，返回变换后能得到的最小字符串（按字典序排序）
变换规则：字符串中任意两个位置
输入描述：一串小写字符串
输出描述：最小字符串
例子：
输入：abcdef
输出：abcdef
*/
#include <string>
#include <iostream>

class Solution {
public:
  std::string getMin(std::string str) {
    std::cout << "origin string: " << str << std::endl;
    std::string sorted(str);
    std::sort(sorted.begin(), sorted.end());

    if (str == sorted) {
      std::cout << "target string: " << str << std::endl;
      return str;
    }

    int pos = 0;
    while (str[pos] == sorted[pos]) {
      pos++;
    }

    auto it = str.rfind(sorted[pos]);
    str[it] = str[pos];
    str[pos] = sorted[pos];

    std::cout << "target string: " << str << std::endl;
    return str;
  }
};

////g++ 最小字符串变换.cpp -o xxx -std=c++11 -DDEBUG
int main() {
  Solution s;
  s.getMin("abcedf");
  s.getMin("abcdef");
  s.getMin("dacabef");
  return 0;
}