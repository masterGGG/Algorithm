#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

/*
实现二叉树的先序、中序、后序遍历，包括递归方式和非递归方式
*/
struct Node {
    Node(v) : value(v) {
        left = right = nullptr;
    }
    int value;
    struct Node *left;
    struct Node *right;
}

//g++ code_01.cpp  -o xxx -std=c++11
int main() {
    struct Node *root = new struct Node(5);
    root.left = new struct Node(3);
    root.right = new struct Node(8);
    root.left.left = new struct Node(2);
    root.left.right = new struct Node(4);
    root.right.left = new struct Node(1);
    root.right.left.left = new struct Node(6);
    root.right.right = new struct Node(10);
    root.right.right.left = new struct Node(9);
    root.right.right.right = new struct Node(11);

    return 0;
}