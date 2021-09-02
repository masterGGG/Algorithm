#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给定一个字符串类型的数组strs，找到一种拼接方式，
使得把所 有字 符串拼起来之后形成的字符串具有最低的字典序。
*/

struct MyComparator {
    bool operator() (string a, string b) {
        string first = a + b;
        string second = b + a;

        return first.compare(second) < 0;
    }
};

void Show(vector<string> arr) {
    for (auto s : arr) {
        cout << s << " ";
    }

    cout << endl;
}

//rm code* && rz && g++ code_05.cpp  -o xxx -std=c++11 -g && ./xxx
int main() {
    vector<string> arr = { "jibw", "ji", "jp", "bw", "jibw" };

    Show(arr);
    sort(arr.begin(), arr.end(), MyComparator());
    Show(arr);

    string res;
    for (auto s : arr) {
        res += s;
    }
    cout << res << endl;


    vector<string> arr1 = { "ba", "a" };
    sort(arr1.begin(), arr1.end(), comp);
    Show(arr1);

    return 0;
}