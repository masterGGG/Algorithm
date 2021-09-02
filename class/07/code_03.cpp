#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
输入: 
参数1，正数数组costs     costs[i]表示i号项目的花费
参数2，正数数组profits   profits[i]表示i号项目在扣除花费之后还能挣到的钱(利润)
参数3， 正数k           k表示你不能并行、只能串行的最多 做k个项目
参数4，正数m            m表示你初始的资金
说明:你每做完一个项目，马上获得的收益，可以支持你去做下 一个 项目。
输出: 你最后获得的最大钱数。
*/

typedef struct project {
public:
    int cost;
    int profit;

    project(int c, int p) : cost(c), profit(p) {}
} Project;

struct greaterCost {
    bool operator() (Project a, Project b) {
        return a.cost > b.cost;
    }
};

struct lesserProfit {
    bool operator() (Project a, Project b) {
        return a.profit < b.profit;
    }
};

int ipo(vector<int> costs, vector<int> profits, int parallel, int money) {
    priority_queue<Project, vector<Project>, greaterCost> min_heap_cost;
    priority_queue<Project, vector<Project>, lesserProfit> max_heap_profit;

    for (int i = 0; i < costs.size(); ++i) {
        min_heap_cost.emplace(Project(costs[i], profits[i]));
    }

    while (parallel--) {
        //cout << "Times: " << parallel << " Money: " << money << endl;
        while (!min_heap_cost.empty()) {
            Project tmp = min_heap_cost.top();

            if (tmp.cost <= money) {
                //cout << "Project can do cost " << tmp.cost << " profit " << tmp.profit << endl;
                max_heap_profit.emplace(tmp);
                min_heap_cost.pop();
            } else {
                //cout << "No money for Project cost " << tmp.cost << " profit " << tmp.profit << endl;
                break;
            }
        }

        if (!max_heap_profit.empty()) {
            Project tmp = max_heap_profit.top();
            //cout << "Project done cost " << tmp.cost << " profit " << tmp.profit << endl;
            money += tmp.profit;
        }
    }

    return money;
}

//rm code* && rz && g++ code_03.cpp  -o xxx -std=c++11 -g && ./xxx
int main() {
    vector<int> costs = { 70, 50, 100, 90, 80 };
    vector<int> profits = { 25, 20, 35, 40, 30};
    int k = 8;
    int m = 60;

    cout << "Max ipo: " << ipo(costs, profits, k, m) << endl;

    return 0;
}