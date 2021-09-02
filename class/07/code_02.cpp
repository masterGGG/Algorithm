#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
一块金条切成两半，是需要花费和长度数值一样的铜板的。
比如 长度为20的 金条，不管切成长度多大的两半，都要花费20个铜 板。
一群人想整分整块金 条，怎么分最省铜板?

例如,给定数组{10,20,30}，代表一共三个人，
整块金条长度为 10+20+30=60. 金条要分成10,20,30三个部分。 
如果， 先把长 度60的金条分成10和50，花费60 再把长度50的金条分成20和30， 花费50 一共花费110铜板。
但是如果， 先把长度60的金条分成30和30，花费60 再把长度30 金条分成10和20，花费30 一共花费90铜板。 

输入一个数组，返回分割的最小代价。
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

int lessMoney(vector<int> arr) {
    priority_queue<int, vector<int>, Min> max_heap;
    priority_queue<int, vector<int>, Max> min_heap;
    int cost = 0;

    for (auto it : arr) {
        max_heap.emplace(it);
        cost += it;
    }

    min_heap.emplace(cost);

    while (max_heap.size() > 2) {
        cout << "Max " << max_heap.top() << endl;
        min_heap.emplace(min_heap.top() - max_heap.top());
        max_heap.pop();
    }

    cost = 0;

    while (!min_heap.empty()) {
        cost += min_heap.top();
        min_heap.pop();
    }

    return cost;
}

//rm code* && rz && g++ code_02.cpp  -o xxx -std=c++11 -g && ./xxx
#include <algorithm>
int main() {
    vector<int> arr = { 6, 7, 8, 9 };
    cout << "lessMoney: " << lessMoney(arr) << endl;

    vector<int> arr1 = { 10, 20, 30 };
    cout << "lessMoney: " << lessMoney(arr1) << endl;


    vector<int> arr2 = { 3, 5, 2, 7, 0, 1, 6, 4 };
    struct Max g;
    sort(arr2.begin(), arr2.end(), g);
    for (auto it : arr2) {
        cout << it << ' '; 
    }

    cout <<endl;

    return 0;
}