#include <iostream>
#include <string>

using namespace std;

/*
汉诺塔问题 打印n层汉诺塔从最左边移动到最右边的全部过程
*/

//暴力递归
void hanoi(int n, string src, string dst, string help) {
    if (n > 1) {
        hanoi(n - 1, src, help, dst);
    }

    cout << "Move " << n << " from " << src << " to " << dst << endl;

    if (n > 1) {
        hanoi(n - 1, help, dst, src);
    }

    return;
}


//rm code* && rz && g++ code_02.cpp  -o xxx -std=c++11 && ./xxx
int main() {
    string left("left");
    string mid("mid");
    string right("right");
    hanoi(3, left, right, mid);

    return 0;
}