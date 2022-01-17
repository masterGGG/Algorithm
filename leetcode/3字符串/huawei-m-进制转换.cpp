#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  string s;
  unordered_map<char, int> table{
    {'0',0},{'1',1},{'2',2},{'3',3},{'4',4},
    {'5',5},{'6',6},{'7',7},{'8',8},{'9',9},
    {'A',10},{'B',11},{'C',12},{'D',13},{'E',14},{'F', 15}
  };

  while (cin >> s) {
    int sum = 0;
    int help = 1;
    for (int i = s.length()-1; i > 1; --i) {
      sum += help * table[s[i]];
      help *= 16;
    }

    cout << sum << endl;
  }

  return 0;
}