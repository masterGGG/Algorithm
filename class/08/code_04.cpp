#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

/*
打印一个字符串的全部排列
*/

//暴力递归
void printAllPermutations1(string src, string dst) {
    if (src.length() <= 1) {
        cout << dst << src << endl;
        return;
    }

    for (int i = 0; i < src.length(); ++i) {
        printAllPermutations1(src.substr(0, i - 0) + src.substr(i + 1), dst + src[i]);
    }
}

void swap(string &str, int from, int to) {
    char tmp = str[from];
    str[from] = str[to];
    str[to] = tmp;
}

void process(string str, int pos) {
    if (pos == str.length()) {
        cout << str << endl;
        return;
    }

    for (int i = pos; i < str.length(); ++i) {
        swap(str, i, pos);
        process(str, pos + 1);
    }
}

//打印一个字符串的全部排列，要求不要出现重复的排列
void process_v1(string str, int pos) {
    if (pos == str.length()) {
        cout << str << endl;
        return;
    }

    unordered_set<char> set;

    for (int i = pos; i < str.length(); ++i) {
        if (set.find(str[i]) == set.end()) {
            set.emplace(str[i]);
            swap(str, i, pos);
            process_v1(str, pos + 1);
        }
    }
}

//rm code* && rz && g++ code_04.cpp  -o xxx -std=c++11 && ./xxx
int main() {
    string str("abc");
    printAllPermutations1(str, "");
    cout << endl;
    process("acc", 0);
    cout << endl;
    process_v1("acc", 0);

    return 0;
}