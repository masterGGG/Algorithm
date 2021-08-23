#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

/*
在二叉树中找到一个节点的后继节点
【题目】 现在有一种新的二叉树节点类型如下:
public class Node { public int value; public Node left; public Node right; public Node parent;
public Node(int data) { this->value = data; }
}
该结构比普通二叉树节点结构多了一个指向父节点的parent指针。
假设有一棵Node类型的节点组成的二叉树，
树中每个节点的parent指针都正确地指向自己的父节点，
头节点的parent指向null。
只给一个在二叉树中的某个节点node，请实现返回node的后继节点的函数。
在二叉树的中序遍历的序列中， node的下一个节点叫作node的后继节点。
*/
struct Node {
    Node(int v) : value(v) {
        left = right = parent = nullptr;
    }
    int value;
    struct Node *parent;
    struct Node *left;
    struct Node *right;
};

struct Node *getSuccessorNode(struct Node *root) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->right != nullptr) {
        root = root->right;

        while (root->left != nullptr) {
            root = root->left;
        }

        return root;
    } else {
        struct Node *parent = root->parent;

        while ((parent != nullptr) && (parent->right == root)) {
            root = parent;
            parent = root->parent;
        }

        return parent;
    }
}

void Show(struct Node *node) {
    if (node != nullptr) {
        std::cout << "Current Node: " << node->value;

        node = getSuccessorNode(node);

        if (node != nullptr) {
            std::cout << " getSuccessorNode: " << node->value;
        } else {
            std::cout << " getSuccessorNode: None";
        }
    } else {
        std::cout << "Current Node: None";
        node = getSuccessorNode(node);
    }

    std::cout << std::endl;
}
 
//g++ code_03.cpp  -o xxx -std=c++11
int main() {
    struct Node *root = new struct Node(5);
    root->parent = nullptr;
    root->left = new struct Node(3);
    root->left->parent = root;
    root->right = new struct Node(8);
    root->right->parent = root;
    root->left->left = new struct Node(2);
    root->left->left->parent = root->left;
    root->left->right = new struct Node(4);
    root->left->right->parent = root->left;
    root->right->left = new struct Node(1);
    root->right->left->parent = root->right;
    root->right->left->left = new struct Node(6);
    root->right->left->left->parent = root->right->left;
    root->right->right = new struct Node(0);
    root->right->right->parent = root->right;
    root->right->right->left = new struct Node(9);
    root->right->right->left->parent = root->right->right;
    root->right->right->right = new struct Node(7);
    root->right->right->right->parent = root->right->right;
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

    Show(nullptr);
    Show(root);
    Show(root->left);
    Show(root->left->left);
    Show(root->left->right);
    Show(root->right->right->right);

    return 0;
}