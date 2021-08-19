#include <iostream>
#include <vector>

using namespace std;

/*
“之”字形打印矩阵
【题目】 给定一个矩阵matrix，按照“之”字形的方式打印这 个矩阵，
例如:
1 2 3 4
5 6 7 8
9 10 11 12 
“之”字形打印的结果为:
1，2，5，9，6，3，4，7，10，11， 8，12
【要求】 额外空间复杂度为O(1)。
*/

void printLine(std::vector<std::vector<int> > vec, int row_x, int row_y, int col_x, int col_y, int reverse) {
    if (reverse) {
        while (col_y <= row_y) {
            std::cout << vec[col_x--][col_y++] << ", ";
        }
    } else {
        while (row_x <= col_x) {
            std::cout << vec[row_x++][row_y--] << ", ";
        }
    }
}

void PrintMartix(std::vector<std::vector<int> > vec) {
    if (vec.size() <= 0) {
        std::cout << "Empty Martix" << std::endl;
        return ;
    }
    
    int col_max = vec[0].size();
    int row_max = vec.size();
    int col_x = 0;
    int col_y = 0;
    int row_x = 0;
    int row_y = 0;
    bool reverse = true;

    while (row_x < row_max) {
        printLine(vec, row_x, row_y, col_x, col_y, reverse);

        if (row_y + 1 < col_max) {
            row_y++;
        } else {
            row_x++;
        }

        if (col_x + 1 < row_max) {
            col_x++;
        } else {
            col_y++;
        }

        reverse = !reverse;
    }

    std::cout << std::endl;
}

int main() {
    std::vector<std::vector<int> > vec = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    PrintMartix(vec);
    return 0;
}