/*
罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给你一个整数，将其转为罗马数字。

 

示例 1:

输入: num = 3
输出: "III"
示例 2:

输入: num = 4
输出: "IV"
示例 3:

输入: num = 9
输出: "IX"
示例 4:

输入: num = 58
输出: "LVIII"
解释: L = 50, V = 5, III = 3.
示例 5:

输入: num = 1994
输出: "MCMXCIV"
解释: M = 1000, CM = 900, XC = 90, IV = 4.
 
提示：
1 <= num <= 3999
*/

class Solution {
public:
    string intToString(int num, string ten, string five, string one) {
        if (num == 9) {
            return one + ten;
        } else if (num == 4) {
            return one + five;
        }

        string str("");

        if (num > 4) {
            str += five;
            num -= 5;
        }

        if (num > 0) {
            for (int i = 0; i < num; ++i) {
                str += one;
            }
        }

        return str;
    }

    string intToRoman(int num) {
        string str("");

        if (num >= 1000) {
            str += intToString(num / 1000, "-", "-", "M");
            num = num % 1000;
        }

        if (num >= 100) {
            str += intToString(num / 100, "M", "D", "C");
            num = num % 100;
        }

        if (num >= 10) {
            str += intToString(num / 10, "C", "L", "X");
            num = num % 10;
        }

        str += intToString(num, "X", "V", "I");

        return str;
    }

    string intToRoman(int num) {
        pair<int, string> _map[] = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };

        string str("");

        for (int i = 0; i < 13; ++i) {
            while (num >= _map[i].first) {
                str += _map[i].second;
                num -= _map[i].first;
            }
        }

        return str;
    }

    int romanToInt(string s) {
        pair<string, int> _map[] = {
            {"M", 1000},
            {"CM", 900},
            {"D", 500},
            {"CD", 400},
            {"C", 100},
            {"XC", 90},
            {"L", 50},
            {"XL", 40},
            {"X", 10},
            {"IX", 9},
            {"V", 5},
            {"IV", 4},
            {"I", 1}
        };

        int num = 0;
        int pos = 0;

        for (auto i : _map) {
            while (pos < s.length()) {
                if (i.first != s.substr(pos, i.first.length())) {
                    break;
                }

                num += i.second;
                pos += i.first.length();
            }
        }

        return num;
    }
};

/*
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
*/

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <string>
#include <queue>

using namespace std;

struct Item {
    Item(string s, int i) : key(s), value(i) {}

    string key;
    int value;
};

struct lessItem{
    bool operator() (Item a, Item b) {
        return a.value < b.value;
    }
};

priority_queue<Item, vector<Item>, lessItem> heap;

int romanToInt(string s) {
}

int main() {
  heap.emplace(Item("M", 1000));
  heap.emplace(Item("CM", 900));
  heap.emplace(Item("D", 500));
  heap.emplace(Item("CD", 400));
  heap.emplace(Item("C", 100));
  heap.emplace(Item("XC", 90));
  heap.emplace(Item("L", 50));
  heap.emplace(Item("XL", 40));
  heap.emplace(Item("X", 10));
  heap.emplace(Item("IX", 9));
  heap.emplace(Item("V", 5));
  heap.emplace(Item("IV", 4));
  heap.emplace(Item("I", 1));

  while (!heap.empty()) {
    Item tmp = heap.top();
    heap.pop();
    cout << tmp.key << "  " << tmp.value << endl;
  }

  return 0;
}