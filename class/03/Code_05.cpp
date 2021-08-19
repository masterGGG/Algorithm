#include <iostream>
#include <vector>

/*
旋转正方形矩阵
【题目】 给定一个整型正方形矩阵matrix，请把该矩阵调整成 顺时针旋转90度的样子。
【要求】 额外空间复杂度为O(1)。
*/

void Show(std::vector<std::vector<int> > vec) {
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec[0].size(); ++j) {
            std::cout << vec[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

void rotateEadge(std::vector<std::vector<int> > &vec, int row0, int col0, int row1, int col1) {
    for (int i = 0; i < row1 - row0; ++i) {
        int tmp = vec[row0][col0 + i];
        vec[row0][col0 + i] = vec[row1 - i][col0];
        vec[row1 - i][col0] = vec[row1][col1 - i];
        vec[row1][col1 - i] = vec[row0 + i][col1];
        vec[row0 + i][col1] = tmp;
    }
}

void rotate(std::vector<std::vector<int> > &vec) {
    int row0 = 0;
    int col0 = 0;
    int row1 = vec.size() - 1;
    int col1 = vec[0].size() - 1;

    while (row0 < row1) {
        rotateEadge(vec, row0++, col0++, row1--, col1--);
    }
}

int main() {
    std::vector<std::vector<int> > vec = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    Show(vec);
    rotate(vec);
    Show(vec);
    return 0;
}