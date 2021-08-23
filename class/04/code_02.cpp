#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

/*
如何直观的打印一颗二叉树
*/
struct Node {
    Node(int v) : value(v) {
        left = right = nullptr;
    }
    int value;
    struct Node *left;
    struct Node *right;
};

int placehold = 1;
int max = 9;
int min = 0;

void record(int num) {
    while (num < min || num > max) {
        min = (min - 1) * 10 + 1;
        max = (max + 1) * 10 - 1;
        placehold++;
    }

    std::cout << min << "<" << num << ">" << max << " placehold " << placehold << std::endl;
}

//获取树的高度
int getLevel(struct Node *root) {
    if (root == nullptr) {
        return 0;
    }

    record(root->value);
    int left = getLevel(root->left);
    int right = getLevel(root->right);

    return left > right ? left + 1 : right + 1;
}

//先序遍历 递归方式
void printTree(struct Node *root) {
    std::cout << "Binary Tree:" << std::endl;
 
    if (root == nullptr) {
        return ;
    }

    int level = getLevel(root);
    int curlevel = 1;
    int slot = 2 * (1 << (level-1)) - 1;
    std::vector<struct Node *> pre;
    std::vector<struct Node *> cur;

    std::cout << std::endl;
}

//g++ code_01->cpp  -o xxx -std=c++11
int main() {
    struct Node *root = new struct Node(5);
    root->left = new struct Node(3);
    root->right = new struct Node(8);
    root->left->left = new struct Node(2);
    root->left->right = new struct Node(4);
    root->right->left = new struct Node(1);
    root->right->left->left = new struct Node(6);
    root->right->right = new struct Node(10);
    root->right->right->left = new struct Node(9);
    root->right->right->right = new struct Node(11);

    std::cout << "Tree level " << getLevel(root) << std::endl;
    //printTree(root);

    return 0;
}