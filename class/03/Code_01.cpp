#include <iostream>
#include <vector>
/*
用数组结构实现大小固定的队列和栈
*/

class TStack {
public:
    TStack(int s) : size(s),tail(0) {
        vec = std::vector<int>(10, 0);
    }

    int push(int num) {
        if (tail == size) {
            std::cout << "TStack fulled" << std::endl;
            return tail;
        }

        vec[tail++] = num;
        return tail;
    }

    int peak() {
        if (tail == 0) {
            std::cout << "TStack empty" << std::endl;
            return -1;
        }

        return vec[tail-1];
    }

    int pop() {
        if (tail == 0) {
            std::cout << "TStack empty" << std::endl;
            return -1;
        }

        return vec[--tail];
    }

public:
    std::vector<int> vec;
    int tail;
    int size;
};

class TQueue {
public:
    TQueue(int s) : size(s),tail(0),head(0),count(0) {
        vec = std::vector<int>(10, 0);
    }

    int push(int num) {
        if (count == size) {
            std::cout << "TQueue fulled" << std::endl;
            return count;
        }

        count++;
        vec[tail] = num;
        tail = (tail == size - 1) ? 0 : tail + 1;
        return tail;
    }

    int peak() {
        if (count == 0) {
            std::cout << "TQueue empty" << std::endl;
            return -1;
        }

        return vec[head];
    }

    int pop() {
        if (count == 0) {
            std::cout << "TQueue empty" << std::endl;
            return -1;
        }

        count--;
        int tmp = vec[head];
        head = (tail == size - 1) ? 0 : head + 1;
        return tmp;
    }

public:
    std::vector<int> vec;
    int head;
    int tail;
    int count;
    int size;
};



/*
用数组结构实现大小固定的队列和栈
*/
#include <iostream>
#include <vector>

/*
设计思路：采用单个数组，尾插尾取的方式达到栈结构的功能。
*/
class ZStack {
public:
    ZStack(int s) : capacity(s), length(0) {
        vec = std::vector<int>(s, 0);
    }

    bool empty() { return length == 0; }
    bool full()  { return length == capacity; }

    int push(int num) {
        if (full()) {
            std::cout << "Stack is full while push("<< num <<")" << std::endl;
            return -1;
        }
std::cout << "push:  " << num << std::endl;
        vec[length++] = num;
        return length;
    }

    int peak() {
        if (empty()) {
            std::cout << "Stack is empty while peak" << std::endl;
            return -1;
        }

        return vec[length - 1];
    }

    int pop() {
        if (empty()) {
            std::cout << "Stack is empty while pop" << std::endl;
            return -1;
        }

        return vec[--length];
    }

    void show() {
        std::cout << "Stack is:";

        for (int i = 0; i < length; ++i) {
            std::cout << "  " << vec[i];
        }

        std::cout << std::endl;
    }
public:
    std::vector<int> vec;
    int capacity;
    int length;
};

/*
设计思路：采用头尾位置环形队列的方式进行数据存储，达到队列结构的功能。
*/
class ZQueue {
public:
    ZQueue(int size) : capacity(size),length(0),head(0),tail(0) {
        vec = std::vector<int>(size, 0);
    }

    bool empty() { return length == 0; }
    bool full()  { return length == capacity; }

    int push(int num) {
        if (full()) {
            std::cout << "Queue is full while push("<< num <<")" << std::endl;
            return -1;
        }

        length++;
        vec[tail++] = num;
        tail = (tail == capacity) ? 0 : tail;
        std::cout << "push:  " << num << std::endl;

        return length;    
    }

    int peak() {
        if (empty()) {
            std::cout << "Queue is empty while peak" << std::endl;
            return -1;
        }

        return vec[head];
    }

    int pop() {
        if (empty()) {
            std::cout << "Queue is empty while pop" << std::endl;
            return -1;
        }

        length--;
        int num = vec[head++];
        head = (head == capacity) ? 0 : head;

        return num;
    }

    void show() {
        std::cout << "Queue is:";

        for (int i = 0; i < length; ++i) {
            std::cout << "  ";

            if (head + i < capacity) {
                std::cout << vec[head+i];
            } else {
                std::cout << vec[head+i-capacity];
            }
        }

        std::cout << std::endl;
    }
public:
    std::vector<int> vec;
    int capacity;
    int length;
    int head;
    int tail;
};

void TestStack() {
    ZStack stack(3);
    stack.peak();
    stack.pop();
    stack.push(5);
    stack.push(4);
    stack.show();
    std::cout << "peak:  " << stack.peak() << std::endl;
    std::cout << "pop :  " << stack.pop() << std::endl;
    stack.show();
    stack.push(3);
    stack.push(2);
    stack.push(1);
    stack.show();

    while (!stack.empty()) {
        std::cout << "pop :  " << stack.pop() << std::endl;
    }
}

void TestQueue() {
    ZQueue queue(3);
    queue.peak();
    queue.pop();
    queue.push(5);
    queue.push(4);
    queue.show();
    std::cout << "peak:  " << queue.peak() << std::endl;
    std::cout << "pop :  " << queue.pop() << std::endl;
    queue.show();
    queue.push(3);
    queue.push(2);
    queue.push(1);
    queue.show();

    while (!queue.empty()) {
        std::cout << "pop :  " << queue.pop() << std::endl;
    }
}

//g++ arrayToStackOrQueue.cpp -o xxx -std=c++11
int main() {
    TestStack();
    TestQueue();
    return 0;
}