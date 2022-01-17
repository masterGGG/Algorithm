/*
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
你必须在 原地 旋转图像
*/

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

/*
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素
*/
/*
思路：按圈打印
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }

        int rows = matrix.size(), columns = matrix[0].size();
        vector<int> order;
        int left = 0, right = columns - 1, top = 0, bottom = rows - 1;
        while (left <= right && top <= bottom) {
            for (int column = left; column <= right; column++) {
                order.push_back(matrix[top][column]);
            }
            for (int row = top + 1; row <= bottom; row++) {
                order.push_back(matrix[row][right]);
            }
            if (left < right && top < bottom) {
                for (int column = right - 1; column > left; column--) {
                    order.push_back(matrix[bottom][column]);
                }
                for (int row = bottom; row > top; row--) {
                    order.push_back(matrix[row][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return order;
    }
};