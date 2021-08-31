#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

/*
给你一个二维数组，二维数组中的每个数都是正数，要求从左上
角走到右下角，每一步只能向右或者向下。沿途经过的数字要累
加起来。返回最小的路径和。
*/
void Show(vector<vector<int> > vec) {
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec[i].size(); ++j) {
            cout << " " << setw(3) << vec[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

//暴力递归
int getMinPath(vector<vector<int> > vec, int i, int j) {
    if ((j == vec[0].size() - 1) && (i == vec.size() - 1)) {
        return vec[i][j];
    }

    int sum = vec[i][j];

    if (i == vec.size() - 1) {
        return sum + getMinPath(vec, i, j + 1);
    }

    if (j == vec[0].size() - 1) {
        return sum + getMinPath(vec, i + 1, j);
    }
    
    int right = getMinPath(vec, i, j + 1);
    int down = getMinPath(vec, i + 1, j);
    sum += right > down ? down : right;

    return sum;
}

//动态规划
int getMinPath_V1(vector<vector<int> > vec, int i, int j) {
    vector<vector<int> > dp;
    vector<int> tmp;

    tmp.emplace_back(vec[i][j]);

    for (int m = j + 1; m < vec[i].size(); ++m) {
        tmp.emplace_back(vec[i][m - j] + tmp[m - j - 1]);
    }

    dp.emplace_back(tmp);
    dp.emplace_back(tmp);
    int prev = 0;

    for (int m = i + 1; m < vec.size(); ++m) {
        dp[1 - prev][0] = dp[prev][0] + vec[m][j];

        for (int n = j + 1; j < vec[i].size(); ++n) {
            dp[1 - prev][n - j] = vec[m][n];
            dp[1 - prev][n - j] += dp[1 - prev][n - j - 1] > dp[prev][n - j] ? dp[prev][n - j] : dp[1 - prev][n - j - 1];
        }

        prev = 1 - prev;
    }

    return dp[prev][vec[i].size() - j - 1];    
}

//DP
int getMinPath_V2(vector<vector<int> > vec, int m, int n) {
    vector<int> tmp(vec[0].size(), 0);
    vector<vector<int> > dp;

    for (int i = 0; i < vec.size(); ++i) {
        dp.emplace_back(tmp);
    }

    for (int i = 0; i < vec[0].size(); ++i) {
        dp[vec.size() - 1][i] = vec[vec.size() - 1][i];
    }

    for (int i = vec.size() - 2; i >= 0; --i) {
        dp[i][vec[0].size() - 1] = dp[i + 1][vec[0].size() - 1] + vec[i][vec[0].size() - 1];
    }

    for (int i = dp.size() - 2; i >= 0; --i) {
        for (int j = dp[i].size() - 2; j >= 0; --j) {
            dp[i][j] = dp[i+1][j] > dp[i][j+1] ? dp[i][j+1] : dp[i+1][j];
            dp[i][j] += vec[i][j];
        }
    }

    cout << "DP arr:" << endl;
    Show(dp);
    return dp[m][n];
}

//rm code* && rz && g++ code_07.cpp  -o xxx -std=c++11 && ./xxx
int main() {
    vector<vector<int> > vec = {
        { 1, 3, 5, 9 }, 
        { 8, 1, 3, 4 }, 
        { 5, 0, 6, 1 }, 
        { 8, 8, 4, 0 }};
    cout << "Src arr:" << endl;
    Show(vec);

    std::cout << "Min path sum: " << getMinPath(vec, 0, 0) << endl;

    std::cout << "Min path sum: " << getMinPath_V2(vec, 0, 0) << endl;

    return 0;
}