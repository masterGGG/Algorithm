#include <iostream>
#include <vector>

using namespace std;

/*
给你一个数组arr，和一个整数aim。如果可以任意选择arr中的 数字，能不能累加得到aim，返回true或者false
*/

//暴力递归
bool process(vector<int> vec, int sum, int aim, int index) {
    if (index == vec.size()) {
        return sum;
    }

    return process(vec, sum, aim, index+1) || process(vec, sum + vec[index], aim, index + 1);
}

//动态规划
bool process_V1(vector<int> vec, int aim) {
    vector<bool> tmp(aim + 1, false);
    vector<vector<bool>> dp;

    for (int i = 0; i <= vec.size(); ++i) {
        dp.emplace_back(tmp);
    }

    dp[vec.size()][aim] = true;

    for (int i = vec.size() - 1; i >=0; --i) {
        for (int j = 0; j < dp[i].size(); ++j) {
            dp[i][j] = dp[i + 1][j];

            if (j + vec[i] <= aim) {
                dp[i][j] = dp[i][j] || dp[i + 1][j + vec[i]];
            }
        }
    }

    for (int i = 0; i < dp.size(); ++i) {
        for (int j = 0; j < dp[i].size(); ++j) {
            if (dp[i][j]) {
                cout << "V ";
            } else {
                cout << "X ";
            }
        }
        cout << endl;
    }
    for (int i = 0; i < dp[0].size(); ++i) {
        cout << i << " ";
    }
    cout << endl;

    return dp[0][0];
}
//rm code* && rz && g++ code_08.cpp  -o xxx -std=c++11 && ./xxx
int main() {
    vector<int> vec = {1, 3, 4, 5, 7, 8, 11 };
    int aim = 15;

    process(vec, 0, aim, 0);

    process_V1(vec, aim);

    return 0;
}