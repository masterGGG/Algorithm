#ifndef ZMINGGAO_TRIETREE_HPP
#define ZMINGGAO_TRIETREE_HPP

#include <iostream>
#include <string>

using namespace std;

class TrieNode {
public:
    TrieNode() : arrive(0), end(0) {
        for (int i = 0; i < 26; i++) {
            edge[i] = nullptr;
        }
    }

    int arrive;
    int end;
    TrieNode *edge[26];
};

class TrieTree{
public:
    TrieTree() {
        root = new TrieNode();
    }

    void insert(string str) {
        if (str.length() == 0) {
            return ;
        }
        
        TrieNode *node = root;
        int index = 0;
        for (int i = 0; i < str.length(); ++i) {
            index = str[i] - 'a';
            if (node->edge[index] == nullptr) {
                node->edge[index] = new TrieNode();
            }

            node->edge[index]->arrive++;
            node = node->edge[index];
        }

        node->end++;
    }

    void free(string str) {
        if (!search(str)) {
            return;
        }

        TrieNode *pre = root;
        TrieNode *cur = nullptr;
        int index = 0;
        for (int i = 0; i < str.length(); ++i) {
            index = str[i] - 'a';
            cur = pre->edge[index];

            cur->arrive--;

            if (cur->arrive == 0) {
                delete cur;
                pre->edge[index] = nullptr;

                return ;
            }

            pre = cur;
        }

        cur->end--;
    }

    bool search(string str) {
        if (str.length() == 0) {
            return false;
        }

        TrieNode *node = root;
        int index = 0;

        for (int i = 0; i < str.length(); ++i) {
            index = str[i] - 'a';
            if (node == nullptr || node->edge[index] == nullptr) {
                return false;
            }

            node = node->edge[index];
        }

        return node->end > 0; 
    }

    int getPrefixNum(string str) {
        if (str.length() == 0) {
            return 0;
        }

        TrieNode *node = root;
        int index = 0;

        for (int i = 0; i < str.length(); ++i) {
            index = str[i] - 'a';
            if (node == nullptr || node->edge[index] == nullptr) {
                return 0;
            }

            node = node->edge[index];
        }

        return node->arrive; 
    }
public:
    TrieNode *root;
};

void find(TrieTree *root, string str) {
    if (!root->search(str)) {
        cout << "Not ";
    }

    cout << "find " << str << endl;
}

#endif