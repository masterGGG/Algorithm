#include <iostream>
#include <stack>
#include <queue>
/*
如何仅用队列结构实现栈结构?
如何仅用栈结构实现队列结构?
*/

/*
如何仅用栈结构实现队列结构?
采用push栈+pop栈双栈设计，实现先进先出能力
*/
class Queue {
public:
    void push(int num) {
        push.push(num);
    }

    int top() {
        if (pop.empty()) {
            if (push.empty()) {
                throw "Queue empty";
            }

            while (!push.empty()) {
                pop.push(push.pop());
            }
        }

        return pop.top();
    }

    int pop() {
        if (pop.empty()) {
            if (push.empty()) {
                throw "Queue empty";
            }

            while (!push.empty()) {
                pop.push(push.pop());
            }
        }

        return pop.pop();
    }
public:
    std::stack<int> push;
    std::stack<int> pop;
};

class Stack {
public:
    void push(int num) {
        list.push(num);
    }

    int top() {
        if (push.empty()) {
            throw "Queue empty";
        }

        while (push.size() != 1) {
            tmp.push(push.pop());
        }

        int tail = push.top();
        tmp.push(push.pop());
        push.swap(tmp);

        return tail;
    }

    int pop() {
        if (push.empty()) {
            throw "Queue empty";
        }

        while (push.size() != 1) {
            tmp.push(push.pop());
        }

        int tail = push.pop();
        push.swap(tmp);

        return tail;
    }
public:
    std::queue<int> list;
    std::queue<int> tmp;
};