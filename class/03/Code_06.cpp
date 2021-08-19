#include <iostream>
#include <vector>
/*
转圈打印矩阵
【题目】 给定一个整型矩阵matrix，请按照转圈的方式打印它。 
例如:
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16 
打印结果为:1，2，3，4，8，12，16，15，14，13，9， 5，6，7，11， 10
【要求】 额外空间复杂度为O(1)。
*/

void printRow(std::vector<std::vector<int> > vec, int row, int fCol, int lCol) {
    while (fCol <= lCol) {
        std::cout << vec[row][fCol++] << " ";
    }
}

void printCol(std::vector<std::vector<int> > vec, int col, int fRow, int lRow) {
    while (fRow <= lRow) {
        std::cout << vec[fRow++][col] << " ";
    }
}

void printEdge(std::vector<std::vector<int> > vec, int fRow, int fCol, int lRow, int lCol) {
    int pos  = 0;

    //1.打印上边框
    if (fRow < lRow) {
        printRow(vec, fRow, fCol, lCol - 1);
    }

    //2.打印右边框
    if (fCol < lCol) {
        printCol(vec, lCol, fRow, lRow - 1);
    }

    //3.打印下边框
    if (fRow < lRow) {
        pos = lCol;

        while (pos > fRow) {
            std::cout << vec[lRow][pos--] << " ";
        }
    }

    //4.打印左边框
    if (fCol < lCol) {
        pos = lRow;

        while (pos > fRow) {
            std::cout << vec[pos--][fCol] << " ";
        }
    }
}

void rotate(std::vector<std::vector<int> > vec) {
    int fCol = 0;
    int fRow = 0;
    int lCol = vec[0].size() - 1;
    int lRow = vec.size() - 1;
    int pos;

    while (fCol <= lCol) {
        if (fCol < lCol && fRow < lRow) {
            printEdge(vec, fRow, fCol, lRow, lCol);
        } else {
            if (fRow == lRow) {
                printRow(vec, fRow, fCol, lCol);
            } else if (fCol == lCol) {
                printCol(vec, fCol, fRow, lRow);
            }

            break;
        }

        fCol++;
        fRow++;
        lRow--;
        lCol--;
    }

    std::cout << std::endl;
}

//g++ Code_05.cpp -o xxx -g -std=c++11
int main() {
    std::cout << "5,6,7,8" << std::endl << "9,10,11,12" << std::endl <<"13,14,15,16" << std::endl;
    std::vector<std::vector<int> > vec0 = {{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    rotate(vec0);
    std::cout << "1,2,3,4,5" << std::endl << "6,7,8,9,10" << std::endl <<"11,12,13,14,15" << std::endl <<"16,17,18,19,20" << std::endl <<"21,22,23,24,25" << std::endl;
    std::vector<std::vector<int> > vec1 = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    rotate(vec1);
    std::cout << "5" << std::endl << "9" << std::endl << "16" << std::endl;
    std::vector<std::vector<int> > vec2 = {{5},{9},{16}};
    rotate(vec2);
    std::cout << "1,2,3,4" << std::endl << "5,6,7,8" << std::endl <<"9,10,11,12" << std::endl <<"13,14,15,16" << std::endl;
    std::vector<std::vector<int> > vec3 = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    rotate(vec3);

    std::cout << "5,6,7" << std::endl << "9,10,11" << std::endl <<"13,14,15" << std::endl << "17,18,19" << std::endl;
    std::vector<std::vector<int> > vec4 = {{5,6,7},{9,10,11},{13,14,15},{17,18,19}};
    rotate(vec4);
    return 0;
}