/*
剑指 Offer 09. 用两个栈实现队列

用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

 

示例 1：

输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
示例 2：

输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
提示：

1 <= values <= 10000
最多会对 appendTail、deleteHead 进行 10000 次调用
*/

#include <stack>

using namespace std;

class CQueue {
public:
    CQueue() {

    }
    /*
    执行用时：336 ms, 在所有 C++ 提交中击败了61.35%的用户
    内存消耗：101 MB, 在所有 C++ 提交中击败了81.95%的用户*/
    void appendTail(int value) {
        input.push(value);
    }
    
    int deleteHead() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        if (output.empty()) {
            return -1;
        } else {
            int value = output.top();
            output.pop();

            return value;
        }
    }

    std::stack<int> input;
    std::stack<int> output;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */