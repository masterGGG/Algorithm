#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

/*

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
 
//rm code* && rz && g++ code_0.cpp  -o xxx -std=c++11 && ./xxx
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
    printTree(root);

    return 0;
}