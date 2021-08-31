#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
给你一个栈，请你逆序这个栈，不能申请额外的数据结构，只能
使用递归函数。如何实现?
*/

void show(stack<int> test) {
    while (!test.empty()) {
        cout << test.top() << " ";
        test.pop();
    }

    cout << endl;
}

void insert(stack<int> &test, int head, int size) {
    if (test.size() == size) {
        test.push(head);
        return;
    }

    int cur = test.top();
    test.pop();

    insert(test, head, size);
    test.push(cur);
}

//暴力递归
stack<int> reverse(stack<int> &test) {
    if (test.size() <= 1) {
        return test;
    }

    int i = 0;
    while (i < test.size()) {
        int head = test.top();
        test.pop();
        insert(test, head, i++);
    }

    return test;
}

stack<int> reverse_V1(stack<int> &test);

int swapBottom(stack<int> &test) {
    int cur = test.top();
    test.pop();

    if (test.empty()) {
        return cur;
    }

    int bottom = swapBottom(test);
    test.push(cur);

    return bottom;
}

stack<int> reverse_V1(stack<int> &test) {
    if (test.size() <= 1) {
        return test;
    }

    int bottom = swapBottom(test);
    reverse_V1(test);
    test.push(bottom);

    return test;
}

//rm code* && rz && g++ code_06.cpp  -o xxx -std=c++11 && ./xxx
int main() {
    stack<int> test;
    test.push(1);
    test.push(2);
    test.push(3);
    test.push(4);
    test.push(5);
    cout << "Before ";
    show(test);
    reverse(test);
    cout << "After  ";
    show(test);

    reverse_V1(test);
    cout << "After  ";
    show(test);

    return 0;
}