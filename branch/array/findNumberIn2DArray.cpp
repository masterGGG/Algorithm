/*
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

 

示例:

现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。

给定 target = 20，返回 false。
*/

//解题思路
/*
从右上角开始走，利用这个顺序关系可以在O(m+n)的复杂度下解决这个题：

如果当前位置元素比target小，则row++
如果当前位置元素比target大，则col--
如果相等，返回true
如果越界了还没找到，说明不存在，返回false
*/
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }

        int row = 0;
        int col = matrix[0].size() - 1;

        do {
            if (matrix[row][col] < target) {
                row++;
            } else if (matrix[row][col] == target) {
                return true;
            } else {
                col--;
            }

            if (row == matrix.size() || col < 0) {
                return false;
            }
        } while (true);

        return false;
    }
};

//暴力穷举法
class Solution {
public:
    bool findInRow(vector<int>vec, int target, int start, int end) {
        if (end < start) {
            return false;
        }

        if (end - start <= 1) {
            return vec[end] == target || vec[start] == target;
        }

        int mid = (start + end) / 2;

        if (vec[mid] == target) {
            return true;
        }

        if (vec[mid] < target) {
            return findInRow(vec, target, mid, end);
        }

        return findInRow(vec, target, start, mid);
    }

    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        for (auto vec : matrix) {
            if (vec.size() == 0 || vec[0] > target) {
                break;
            }

            if (vec[vec.size() - 1] < target) {
                continue;
            }

            if (findInRow(vec, target, 0, vec.size() - 1)) {
                return true;
            }
        }

        return false;
    }
};

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool findInRow(vector<vector<int> > matrix, int target, int row, int start, int end) {
        if (end == start) {
            return matrix[row][start] == target;
        } else if (end == start + 1) {
            return matrix[row][start] == target || matrix[row][end] == target;
        }

        int mid = (end + start) / 2;
std::cout << "[findInRow] " << start << " " << mid << " " << end << std::endl;
        if (matrix[row][mid] == target) {
            return true;
        }

        if (matrix[row][mid] < target) {
            return findInRow(matrix, target, row, mid, end);
        }

        return findInRow(matrix, target, row, start, mid);
    }

    bool findInCol(vector<vector<int> > matrix, int target, int col, int start, int end) {
        if (end == start) {
            return matrix[start][col] == target;
        } else if (end == start + 1) {
            return matrix[start][col] == target || matrix[end][col] == target;
        }

        int mid = (end + start) / 2;
std::cout << "[findInCol] " << start << " " << mid << " " << end << std::endl;
        if (matrix[mid][col] == target) {
            return true;
        }

        if (matrix[mid][col] < target) {
            return findInCol(matrix, target, col, mid, end);
        }

        return findInCol(matrix, target, col, start, mid);
    }

    bool findNumberIn2DArray(vector<vector<int> >& matrix, int target) {
        int row = -1;
        int col = -1;

        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }

        if (matrix.size() == 1) {
            return findInRow(matrix, target, 0, 0, matrix[0].size() - 1);
        }

        if (matrix[0].size() == 1) {
            return findInCol(matrix, target, 0, 0, matrix.size() - 1);
        } 

        int row_len = matrix[0].size() - 1;
        int col_len = matrix.size() - 1;
std::cout << "[findNumberIn2DArray] rowcount:" << row_len << " colcount:" << col_len << std::endl;
        if (matrix[0][0] > target || matrix[row_len][col_len] < target) {
            return false;
        }

        do {
            if (col < col_len) {
                col++;
            }
            
            if (row < row_len) {
                row++;
            }
            
            if (matrix[row][col] >= target) {
                break;
            }
        } while (col < col_len || row < row_len);
std::cout << "[findNumberIn2DArray] row:" << row << " col:" << col << std::endl;
        return findInRow(matrix, target, row, 0, col_len) || findInCol(matrix, target, col, 0, row_len);
    }
};

/*[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]*/
int main(int argc, char **argv) {
    Solution a;

    vector<vector<int> > matrix;
    int arr[5][5] = {{1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20}, {21,22,23,24,25}};

    for (int i = 0; i < 5; ++i) {
        vector<int> row;
    
        for (int j = 0; j < 5; ++j) {
            row.push_back(arr[i][j]);
        }
std::cout<< "row[" << i << "] size:" << row.size() << std::endl;
        matrix.push_back(row);
    }
std::cout<< "matrix size:" << matrix.size() << std::endl;
    int target = 15;

    if (a.findNumberIn2DArray(matrix, target)) {
        std::cout << "find target: " << target << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    return 0;
}