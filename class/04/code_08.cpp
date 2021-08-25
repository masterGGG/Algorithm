#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

/*
已知一棵完全二叉树，求其节点的个数 要求:时间复杂度低于O(N)，N为这棵树的节点个数
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

int getMostLevel(struct Node *root) {
    if (root == nullptr) {
        return 0;
    }

    int level = 1;

    while (root->left) {
        level++;
        root = root->left;
    }

    return level;
}

int getMostLeftLevel(struct Node *root) {
    int level = 0;

    if (root->left) {
        struct Node *node = root->left;
        level = 1;

        while (node->right) {
            level++;
            node = node->right;
        }
    }

    return level;
}

int getNode(struct Node *root) {
    if (root == nullptr) {
        return 0;
    }

    int level = getMostLevel(root);

    if (level == 1) {
        return 1;
    }

    int leftLevel = getMostLeftLevel(root);
    int count = 1;

    if (level == (leftLevel+1)) {
        count += int(pow(2.0, level - 1)) - 1;
        count += getNode(root->right);
    } else {
        count += int(pow(2.0, level - 2)) - 1;
        count += getNode(root->left);
    }

    return count;
}

//rm code* && rz && g++ code_08.cpp  -o xxx -std=c++11 && ./xxx
int main() {
    struct Node *root = new struct Node(1);
    root->left = new struct Node(2);
    root->right = new struct Node(3);
    root->left->left = new struct Node(4);
    root->left->right = new struct Node(5);
    root->right->left = new struct Node(6);
    root->right->right = new struct Node(7);
    printTree(root);

    std::cout << "Tree node(" << root->value << "): " << getNode(root) << std::endl;
    std::cout << "Tree node(" << root->left->value << "): " << getNode(root->left) << std::endl;
    std::cout << "Tree node(" << root->right->value << "): " << getNode(root->right) << std::endl;
    std::cout << "Tree node(" << root->left->left->value << "): " << getNode(root->left->left) << std::endl;
    struct Node *node = root->right->right;
    root->right->right = nullptr;
    printTree(root);
    std::cout << "Tree node(" << root->value << "): " << getNode(root) << std::endl;
    std::cout << "Tree node(" << root->left->value << "): " << getNode(root->left) << std::endl;
    std::cout << "Tree node(" << root->right->value << "): " << getNode(root->right) << std::endl;
    std::cout << "Tree node(" << root->left->left->value << "): " << getNode(root->left->left) << std::endl;

    return 0;
}