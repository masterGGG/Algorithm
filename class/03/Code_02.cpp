#include <iostream>
#include <stack>
//#include 
/*
实现一个特殊的栈，在实现栈的基本功能的基础上，再实现返
回栈中最小元素的操作。
【要求】 1.pop、push、getMin操作的时间复杂度都是O(1)。 2.设计的栈类型可以使用现成的栈结构。
*/

class MinStack {
public:
    int pop() {
        if (m_stack.empty() || m_min_stack.empty()) {
            throw "Your stack is empty.";
        }

        m_min_stack.pop();
        return m_stack.pop();
    }

    void push(int num) {
        m_stack.push(num);

        if (m_min_stack.empty() || m_min_stack.top() > num) {
            m_min_stack.push(num);
        } else {
            m_min_stack.push(m_min_stack.top());
        }
    }

    int getMin() {
        if (m_min_stack.empty()) {
            throw "Your stack is empty.";
        }

        return m_min_stack.top();
    }
public:
    std::stack<int> m_stack;
    std::stack<int> m_min_stack;
}