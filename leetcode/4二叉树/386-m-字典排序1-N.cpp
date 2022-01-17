/*
给你一个整数 n ，按字典序返回范围 [1, n] 内所有整数。
你必须设计一个时间复杂度为 O(n) 且使用 O(1) 额外空间的算法。
*/

class Solution {
public:
    void lexicalOrder(vector<int>& vec, int num, int n) {
        if (num > n) {
            return;
        }

        vec.emplace_back(num);
        num *= 10;

        for (int i = 0; i < 10; ++i) {
            lexicalOrder(vec, num + i, n);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> vec;

        for (int i = 1; i < 10; ++i) {
            lexicalOrder(vec, i, n);
        }

        return vec;
    }
};