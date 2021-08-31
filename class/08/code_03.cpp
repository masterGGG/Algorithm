#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
打印一个字符串的全部子序列，包括空字符串
*/

//暴力递归
void process(string src, string dst) {
    if (src.length() == 0) {
        cout << dst << endl;
        return ;
    }

    char cur = src[0];
    src = src.substr(1, src.length() - 1);
    process(src, dst);
    process(src, dst + cur);

    return;
}

void process_V1(string src) {
    vector<string> res;
    int pos = 0;

    res.emplace_back("");

    while (pos < src.length()) {
        int count = res.size();

        for (int i = 0; i < count; ++i) {
            res.emplace_back(res[i] + src[pos]);
        }

        pos++;
    }

    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }

    return ;
}

//rm code* && rz && g++ code_03.cpp  -o xxx -std=c++11 && ./xxx
int main() {
    string str("abc");
    process(str, "");
    process_V1(str);

    return 0;
}