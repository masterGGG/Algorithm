#include "trietree.hpp"

/*
arr2中有哪些字符，是arr1中出现的?请打印
*/

//rm code* && rz && g++ code_01.cpp  -o xxx -std=c++11 -g && ./xxx
int main() {
    TrieTree *root = new TrieTree();

    find(root, "zuo");
    root->insert("zuo");
    find(root, "zuo");
    root->free("zuo");
    find(root, "zuo");
    root->insert("zuo");
    root->insert("zuo");
    root->free("zuo");
    find(root, "zuo");
    root->free("zuo");
    find(root, "zuo");
    root->insert("zuoa");
    root->insert("zuoac");
    root->insert("zuoab");
    root->insert("zuoad");
    root->free("zuoa");
    find(root, "zuoa");
    cout << "zuo PrefixNum: " << root->getPrefixNum("zuo") << endl;
    cout << "zuob PrefixNum: " << root->getPrefixNum("zuob") << endl;

    return 0;
}