#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

/*
实现二叉树的先序、中序、后序遍历，包括递归方式和非递归方式
*/
struct Node {
    Node(int v) : value(v) {
        left = right = nullptr;
    }
    int value;
    struct Node *left;
    struct Node *right;
};

//先序遍历 递归方式
void printPreOrder_V1(struct Node *root) {
    if (root == nullptr) {
        return ;
    }

    std::cout << root->value << ", ";
    printPreOrder_V1(root->left);
    printPreOrder_V1(root->right);
}
//中序遍历 递归方式
void printInOrder_V1(struct Node *root) {
    if (root == nullptr) {
        return ;
    }

    printInOrder_V1(root->left);
    std::cout << root->value << ", ";
    printInOrder_V1(root->right);
}
//后序遍历 递归方式
void printPosOrder_V1(struct Node *root) {
    if (root == nullptr) {
        return ;
    }

    printPosOrder_V1(root->left);
    printPosOrder_V1(root->right);
    std::cout << root->value << ", ";
}

//先序遍历 非递归方式
void printPreOrder_V2(struct Node *root) {
    if (root == nullptr) {
        return ;
    }

    struct Node *node = nullptr;
    std::stack<struct Node *> myStack;
    myStack.push(root);

    while (!myStack.empty()) {
        node = myStack.top();
        std::cout << node->value << ", ";
        myStack.pop();
        
        if (node->right) {
            myStack.push(node->right);
        }

        if (node->left) {
            myStack.push(node->left);
        }
    }

    std::cout << std::endl;
}
//中序遍历 非递归方式
void printInOrder_V2(struct Node *root) {
    if (root == nullptr) {
        return ;
    }

    struct Node *n = root;
    std::stack<struct Node*> s;

    while (!s.empty() || n) {
        if (n) {
            s.push(n);
            n = n->left;
        } else {
            n = s.top();
            std::cout << n->value << ", ";
            s.pop();
            n = n->right;
        }
    }
    std::cout << std::endl;
}
//后序遍历 非递归方式
void printPosOrder_V2(struct Node *root) {
    if (root == nullptr) {
        return ;
    }

    struct Node *node = nullptr;
    std::stack<struct Node *> s1;   //保存遍历节点
    std::stack<int> s2;   //记录打印顺序
    s1.push(root);

    while (!s1.empty()) {
        node = s1.top();
        s1.pop();
        s2.push(node->value);

        if (node->left) {
            s1.push(node->left);
        }

        if (node->right) {
            s1.push(node->right);
        }
    }

    while (!s2.empty()) {
        std::cout << s2.top() << ", ";
        s2.pop();
    }

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

    printPreOrder_V1(root);
    std::cout << std::endl;
    printPreOrder_V2(root);

    printInOrder_V1(root);
    std::cout << std::endl;
    printInOrder_V2(root);

    printPosOrder_V1(root);
    std::cout << std::endl;
    printPosOrder_V2(root);

    return 0;
}