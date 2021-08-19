#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

/*
复制含有随机指针节点的链表
【题目】 一种特殊的链表节点类描述如下:
public class Node { public int value; public Node next; public Node rand;
public Node(int data) { this.value = data; }
} 
Node类中的value是节点值，
next指针和正常单链表中next指针的意义 一 样，都指向下一个节点，
rand指针是Node类中新增的指针，这个指 针可 能指向链表中的任意一个节点，也可能指向null。 
给定一个由 Node节点类型组成的无环单链表的头节点head，
请实现一个 函数完成 这个链表中所有结构的复制，并返回复制的新链表的头节点。 
进阶: 不使用额外的数据结构，只用有限几个变量，且在时间复杂度为 O(N) 内完成原问题要实现的函数。
*/

struct Node {
    Node(int v) : value(v) {
        next = nullptr;
        rand = nullptr;
    }
    int value;
    struct Node *next;
    struct Node *rand;
};

void printList(struct Node *head) {
    std::cout << "Linked List: ";

    while (head) {
        std::cout << head->value << "(" << ((head->rand != nullptr) ? head->rand->value : -1)  << "), ";
        head = head->next;
    }

    std::cout << std::endl;
}

// need n extra space
struct Node * BaseCopy(struct Node *head) {
    if (head == nullptr) {
        return nullptr;
    }

    printList(head);

    std::map<struct Node *, struct Node *> _map;
    std::map<struct Node *, struct Node *>::iterator iter;
    struct Node *newHead = nullptr;
    struct Node *cur = head;
    struct Node *newCur = nullptr;

    while (cur) {
        iter = _map.find(cur);

        if (iter == _map.end()) {
            newCur = new struct Node(cur->value);
            //std::cout << "Insert Node " << cur->value << " " << cur << " " << newCur << std::endl;
            _map.insert(std::pair<struct Node *, struct Node *>(cur, newCur));
        } else {
            newCur = iter->second;
            //std::cout << "Find Node " << cur << " " << newCur << std::endl;
        }

        if (cur->rand) {
            iter = _map.find(cur->rand);

            if (iter == _map.end()) {
                newCur->rand = new struct Node(cur->rand->value);
                _map.insert(std::pair<struct Node *, struct Node *>(cur->rand, newCur->rand));
                //std::cout << "Insert rand " << cur->rand->value << " " << cur->rand << " " << newCur->rand << std::endl;
            } else {
                newCur->rand = iter->second;
                //std::cout << "Find rand " << cur->rand << " " << newCur->rand << std::endl;
            }
        }

        if (cur->next) {
            iter = _map.find(cur->next);

            if (iter == _map.end()) {
                newCur->next = new struct Node(cur->next->value);
                _map.insert(std::pair<struct Node *, struct Node *>(cur->next, newCur->next));
                //std::cout << "Insert next "  << cur->next->value << " " << cur->next << " " << newCur->next << std::endl;
            } else {
                newCur->next = iter->second;
                //std::cout << "Find next " << cur->next << " " << newCur->next << std::endl;
            }
        }

        cur = cur->next;
        newCur = newCur->next;
    }

    iter = _map.find(head);
    newHead = iter->second;

    printList(newHead);
    return newHead;
}

// need 1 extra space
struct Node *AdvancedCopy(struct Node *head) {
    if (head == nullptr) {
        return nullptr;
    }

    printList(head);

    struct Node *cur = head;
    struct Node *next = nullptr;

    while (cur) {
        next = cur->next;
        cur->next = new struct Node(cur->value);
        cur->next->next = next;
        cur = next;
    }

    cur = head;
    while (cur) {
        next = cur->next;

        if (cur->rand != nullptr) {
            next->rand = cur->rand->next;
        }

        cur = next->next;
    }

    cur = head;
    next = nullptr;
    struct Node *newHead = cur->next;
    while (cur) {
        if (next) {
            next->next = cur->next;
        }

        next = cur->next;
        cur->next = next->next;
        cur = cur->next;
    }

    printList(newHead);
    return newHead;
}

//g++ code_13.cpp  -o xxx -std=c++11
int main() {
    struct Node *head = nullptr;
    head = new struct Node(1);
    head->next = new struct Node(2);
    head->next->next = new struct Node(3);
    head->next->next->next = new struct Node(4);
    head->next->next->next->next = new struct Node(5);
    head->next->next->next->next->next = new struct Node(6);
    head->next->next->next->next->next->next = nullptr;

    head->rand = head->next->next->next->next->next;
    head->next->rand = head->next->next->next->next->next;
    head->next->next->rand = head->next->next->next->next;
    head->next->next->next->rand = head->next->next;
    head->next->next->next->next->rand = nullptr;
    head->next->next->next->next->next->rand = head->next->next->next;

    //BaseCopy(head);
    AdvancedCopy(head);

    return 0;
}