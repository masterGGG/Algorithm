#include <iostream>
#include <vector>

using namespace std;

/*
给定两个数组w和v，两个数组长度相等，w[i]表示第i件商品的 重量，v[i]表示第i件商品的价值。 
再给定一个整数bag，
要求 你挑选商品的重量加起来一定不能超 过bag，
返回满足这个条件 下，你能获得的最大价值。
*/
#include <iomanip>
void Show(vector<vector<int> > vec) {
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec[i].size(); ++j) {
            cout << " " << setw(3) << vec[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

int process(vector<int> w, vector<int> v, int pos, int weight, int max, int bag) {
    if (pos == w.size()) {
        return max;
    }

    if (w[pos] + weight > bag) {
        return process(w, v, pos + 1, weight, max, bag);
    }

    int max1 = process(w, v, pos + 1, w[pos] + weight, v[pos] + max, bag);
    int max2 = process(w, v, pos + 1, weight, max, bag);

    return max1 > max2 ? max1 : max2;
}

int maxValue(vector<int> w, vector<int> v, int bag) {
    int max = process(w, v, 0, 0, 0, bag);

    return max;
}

int maxValue_DP(vector<int> w, vector<int> v, int bag) {
    vector<int> tmp(bag + 1, 0);
    vector<vector<int> > dp;

    for (int i = 0; i <= w.size(); ++i) {
        dp.emplace_back(tmp);
    }

    for (int i = 1; i < dp.size(); ++i) {
        for (int j = 0; j <= bag; ++j) {
            dp[i][j] = dp[i - 1][j];

            if (j >= w[i - 1] && dp[i - 1][j - w[i - 1]] + v[i - 1] > dp[i - 1][j]) {
                dp[i][j] = dp[i - 1][j - w[i - 1]] + v[i - 1];
            }
        }
    }

    cout << "Dp arr:" << endl;
    Show(dp);

    return dp[dp.size() - 1][bag];
}

//rm code* && rz && g++ code_09.cpp  -o xxx -std=c++11 && ./xxx
int main() {
    vector<int> w = { 3, 2, 4, 7 };
    vector<int> v = { 5, 6, 3, 19 };
    int bag = 11;

    cout << maxValue(w, v, bag) << endl;

    maxValue_DP(w, v, bag);
    return 0;
}