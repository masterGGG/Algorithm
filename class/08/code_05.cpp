#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
母牛每年生一只母牛，新出生的母牛成长三年后也能每年生一只 母牛，假设不会死。求N年后，母牛的数量。
*/

//暴力递归
int getCow(int N) {
    if (N < 1) {
        return 0;
    } else if (N <= 3) {
        return N;
    }

    return getCow(N - 1) + getCow(N - 3);
}

//如果每只母牛只能活10年，求N年后，母牛的数量。
int getCow_V1(int N) {
    if (N < 1) {
        return 0;
    } else if (N <= 3) {
        return N;
    }

    return getCow(N - 1) + getCow(N - 3) - (N >= 10 ? getCow(N - 10 + 1) : 0);
}

//rm code* && rz && g++ code_05.cpp  -o xxx -std=c++11 && ./xxx
int main() {
    std:: cout << "20 Years later : " << getCow(20) << endl;
    std:: cout << "20 Years later : " << getCow_V1(20) << endl;
    return 0;
}