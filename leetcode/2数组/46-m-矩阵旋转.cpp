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