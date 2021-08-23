#include <iostream>
#include <vector>
#include <string>
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

void printInOrder(struct Node *root, int height, std::string prefix, int length) {
    if (root) {
        if (root->right) {
            printInOrder(root->right, height+1, "v", length);
        }

        std::string hstr(length, ' ');
        std::string value = "";

        int level = height;
        while (level-- > 0) {
            value += hstr;
        }

        std::string key = prefix + std::to_string(root->value) + prefix;
        
        if (key.length() < length) {
            value += std::string((length - key.length())/2, ' ') + key;
        } else {
            value += key;
        }

        std::cout << value << std::endl;

        if (root->left) {
            printInOrder(root->left, height+1, "^", length);
        }
    }
}

//以中序遍历的方式打印二叉树
void printTree(struct Node *root) {
    std::cout << "Binary Tree:" << std::endl;
    printInOrder(root, 0, "H", 8);
    std::cout << std::endl;
}

//g++ code_02.cpp  -o xxx -std=c++11
int main() {
    struct Node *root = new struct Node(5);
    root->left = new struct Node(3);
    root->right = new struct Node(8);
    root->left->left = new struct Node(2);
    root->left->right = new struct Node(4);
    root->right->left = new struct Node(1);
    root->right->left->left = new struct Node(6);
    root->right->right = new struct Node(0);
    root->right->right->left = new struct Node(9);
    root->right->right->right = new struct Node(7);
    std::vector<std::vector<char>> vec = {{' ',' ',' ',' ',' ',' ',' ',' ','5',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ','/',' ',' ',' ',' ',' ',' ',' ','\\',' ',' ',' '}, 
                        {' ',' ',' ',' ','3',' ',' ',' ',' ',' ',' ',' ','8',' ',' ',' '},
                        {' ',' ','/',' ',' ','\\',' ',' ',' ','/',' ',' ',' ','\\',' ',' '},
                        {' ',' ','2',' ',' ','4',' ',' ',' ','1',' ',' ',' ','0',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' ','/',' ',' ',' ','/',' ','\\',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' ','6',' ',' ',' ','9',' ','7',' '}};
    std::cout << "Binary Tree is :" << std::endl;
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec[0].size(); ++j) {
            std::cout << vec[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    printTree(root);

    return 0;
}