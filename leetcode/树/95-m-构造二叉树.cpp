/*
给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n 互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。

示例 1：
输入：n = 3
输出：[[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
示例 2：
输入：n = 1
输出：[[1]]
 
提示：
1 <= n <= 8
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> genBST(int start, int end) {
        vector<TreeNode*> res;

        if (start == end) {
            res.emplace_back(new TreeNode(start));
            return res;
        } else if (start > end) {
            return res;
        }

        for (int pos = start; pos <= end; ++pos) {
            vector<TreeNode*> left = genBST(start, pos - 1);
            vector<TreeNode*> right = genBST(pos + 1, end);

            if (left.empty()) {
                for (int i = 0; i < right.size(); ++i) {
                    res.emplace_back(new TreeNode(pos, nullptr, right[i]));
                }
            } else if (right.empty()) {
                for (int i = 0; i < left.size(); ++i) {
                    res.emplace_back(new TreeNode(pos, left[i], nullptr));
                }
            } else {
                for (int i = 0; i < right.size(); ++i) {
                    for (int j = 0; j < left.size(); ++j) {
                        res.emplace_back(new TreeNode(pos, left[j], right[i]));
                    }
                }
            }
        }

        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        return genBST(1, n);
    }
};