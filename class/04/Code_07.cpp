/*判断一棵树是否是搜索二叉树、判断一棵树是否是完全二叉树*/

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    Node(int v) : value(v) {
        left = right = nullptr;
    }

    int value;
    struct Node *left;
    struct Node *right;
};

/*判断一棵树是否是搜索二叉树，中序遍历是有序的*/
bool isBst(struct Node *root) {
    return true;
}

/*判断一棵树是否是完全二叉树*/
bool isCompleteTree(struct Node *root) {
    return true;
}

int main() {
    struct Node *root = new struct Node(6);
    root->left
    return 0;
}