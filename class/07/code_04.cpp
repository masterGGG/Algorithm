#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
一个数据流中，随时可以取得中位数
*/

struct Min {
    bool operator() (int a, int b) {
        return a < b;
    }
};

struct Max {
    bool operator() (int a, int b) {
        return a > b;
    }
};

class intStream {
public:
    priority_queue<int, vector<int>, Max> min_heap;  
    priority_queue<int, vector<int>, Min> max_heap;

    intStream() {}

    void addNumber(int num) {
        if (!min_heap.empty() && num >= min_heap.top()) {
            cout << "Insert min_heap " << num << endl;
            min_heap.emplace(num);
        } else {
            cout << "Insert max_heap " << num << endl;
            max_heap.emplace(num);
        }
        
        while (max_heap.size() > min_heap.size() + 1) {
            cout << "move " << max_heap.top() << " from max_heap to min_heap"<< endl;
            min_heap.emplace(max_heap.top());
            max_heap.pop();
        }

        while (min_heap.size() > max_heap.size() + 1) {
            cout << "move " << min_heap.top() << "from min_heap to max_heap"<< endl;
            max_heap.emplace(min_heap.top());
            min_heap.pop();
        }
    }

    int getMedian() {
        if (max_heap.empty() && min_heap.empty()) {
            return -1;
        }
        if (min_heap.size() > max_heap.size()) {
            return min_heap.top();
        } else if (min_heap.size() < max_heap.size()) {
            return max_heap.top();
        } else {
            return (min_heap.top() + max_heap.top()) / 2;
        }
    } 
};

#include <stdlib.h>
#include <time.h>

//rm code* && rz && g++ code_04.cpp  -o xxx -std=c++11 -g && ./xxx
int main() {
    intStream medianHold;
    srand((unsigned)time(nullptr));

    for (int i = 0; i < 20; i++) {
        int num = rand() % 99 + 1;
        medianHold.addNumber(num);

        if (num % 3 == 0) {
            cout << "getMedian " << medianHold.getMedian() << endl;
        }
    }

    return 0;
}