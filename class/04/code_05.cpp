#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

/*
折纸问题
【题目】 请把一段纸条竖着放在桌子上，然后从纸条的下边向上方对折1次，压出折痕后展开。
此时 折痕是凹下去的，即折痕 突起的方向指向纸条的背面。
如果从纸条的下边向上方连续对折2次，压出折痕后展开，此时有三条折痕，从上到下依次是下折 痕、下折痕和上折痕。
给定一个输入参数N，代表纸条都从下边向上方连续对折N次， 请从上到下打印所有折痕的方向。 
例如:
N=1时，打印: down 
N=2时，打印: down down up
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
 
void printFolds(int folds, int N, bool isDown) {
    if (folds > N) {
        return;
    }

    printFolds(folds+1, N, true);

    if (isDown) {
        std::cout << "down ";
    } else {
        std::cout << "up ";
    }

    printFolds(folds+1, N, false);
}

void printAllFolds(int N) {
    std::cout << "AllFolds: " << N << " ___ ";
    printFolds(1, N, true);
    std::cout << std::endl;
}

//rm code* && rz && g++ code_05.cpp  -o xxx -std=c++11 && ./xxx
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

    printAllFolds(1);
    printAllFolds(2);
    printAllFolds(3);
    printAllFolds(4);

    return 0;
}