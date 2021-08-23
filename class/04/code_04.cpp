#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

/*
介绍二叉树的序列化和反序列化
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

std::string NONE = "#!";
const char SPLIT = '!';

std::string serializeByPre(struct Node *root) {
    std::string str = "";

    if (root == nullptr) {
        return NONE;
    }

    str += std::to_string(root->value);
    str += SPLIT;
    str += serializeByPre(root->left);
    str += serializeByPre(root->right);

    return str;
}

struct Node * genTree(std::queue<std::string> &queue) {
    if (queue.size() == 0) {
        return nullptr;
    }

    std::string value = queue.front();

    if (value == "#") {
        queue.pop();
        return nullptr;
    }

    struct Node *node = new struct Node(atoi(value.c_str()));
    queue.pop();
    node->left = genTree(queue);
    node->right = genTree(queue);

    return node;
}

struct Node * reconByPreString(std::string str) {
    if (str.length() == 0) {
        return nullptr;
    }

    std::queue<std::string> queue;

    while (str.length() > 0) {
        int pos = str.find(SPLIT);

        if (pos == str.npos) {
            std::cout << "Invalid serialize string" << std::endl;
            return nullptr;
        }

        queue.push(str.substr(0, pos));
        str = ((pos + 1) == str.length()) ? "" : str.substr(pos+1, str.length() - pos - 1);
    }

    return genTree(queue);
}

//g++ code_04.cpp  -o xxx -std=c++11 -g
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

    std::string str = serializeByPre(root);
    std::cout << "serializeByPre: " << str << std::endl;

    struct Node *node = reconByPreString(str);
    printTree(node);

    return 0;
}