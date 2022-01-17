/*描述
写出一个程序，接受一个由字母、数字和空格组成的字符串，和一个字符，然后输出输入字符串中该字符的出现次数。（不区分大小写字母）
数据范围： 
输入描述：
第一行输入一个由字母和数字以及空格组成的字符串，第二行输入一个字符。
输出描述：
输出输入字符串中含有该字符的个数。（不区分大小写字母）*/

#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  char c;

  while (cin >> s) {
    cin >> c;

    if (c >= 'a' && c <= 'z') {
      cout << count(s.begin(), s.end(), c) + count(s.begin(), s.end(), c - 'a' + 'A') << endl;
    } else if (c >= 'A' && c <= 'Z') {
      cout << count(s.begin(), s.end(), c) + count(s.begin(), s.end(), c - 'A' + 'a') << endl;
    } else {
      cout << count(s.begin(), s.end(), c) << endl;
    }
    cin.ignore();
  }

  return 0;
}