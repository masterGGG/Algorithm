#include <iostream>

using namespace std;

/*
求n!的结果
*/

//暴力递归
long getFactorial(int n) {
    if (n <= 1) {
        return n;
    }

    return (long)n * getFactorial(n - 1);
}

//动态规划
long getFactorial_V1(int n) {
    if (n <= 1) {
        return n;
    }

    long sum = 1;

    for (int i = 1; i <= n; ++i) {
        sum *= i;
    }

    return sum;
}

//rm code* && rz && g++ code_01.cpp  -o xxx -std=c++11 && ./xxx
int main() {
    cout << "暴力递归:" << getFactorial(5) << endl;
    cout << "动态规划:" << getFactorial_V1(5) << endl;

    return 0;
}