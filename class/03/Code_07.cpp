#include <iostream>

/*
反转单向和双向链表
【题目】 分别实现反转单向链表和反转双向链表的函数。 
【要求】 如果链表长度为N，时间复杂度要求为O(N)，额外空间 复杂度要求为O(1)
*/
struct List {
public:
    List(int _value) : value(_value) {
        next = nullptr;
    }

    int value;
    struct List *next;
};

struct DoubleList {
public:
    DoubleList(int _value) : value(_value) {
        next = nullptr;
        prev = nullptr;
    }

    int value;
    struct DoubleList *prev;
    struct DoubleList *next;
};

struct List *reverseList(struct List *head) {
#ifdef ZMINGGAO
    if (head == nullptr) {
        return nullptr;
    }

    struct List *cur = head;
    struct List *next = head->next;

    while (next) {
        struct List *tmp = next->next;
        next->next = cur;
        cur = next;
        next = tmp;
    }

    head->next = nullptr;
    head = cur;

    return head;
#else
    struct List *pre = nullptr;
    struct List *next = nullptr;

    while (head != nullptr) {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }

    return pre;
#endif
}

void ShowList(struct List *head) {
    std::cout << "List: ";

    while (head) {
        std::cout << head->value << " ";
        head = head->next;
    }

    std::cout << std::endl;
}

void testList() {
    struct List *head = new struct List(1);
    head->next = new struct List(2);
    head->next->next = new struct List(3);
    head->next->next->next = new struct List(4);
    head->next->next->next->next = new struct List(5);

    ShowList(head);
    head = reverseList(head);
    ShowList(head);
}

struct DoubleList *reverseDoubleList(struct DoubleList *head) {
#ifndef ZUOCHENGYUN
    struct DoubleList *pre = nullptr;
    struct DoubleList *next = nullptr;

    while (head != nullptr) {
        next = head->next;
        head->next = pre;
        head->prev = next;
        pre = head;
        head = next;
    }

    return pre;
#else
    if (head == nullptr) {
        return nullptr;
    }

    struct DoubleList *cur = head;
    struct DoubleList *next = head->next;

    while (next) {
        struct DoubleList *tmp = next->next;
        next->next = cur;
        cur->prev = next;
        cur = next;
        next = tmp;
    }

    head->next = nullptr;
    head = cur;
    head->prev = nullptr;

    return head;
#endif
}

void ShowDoubleList(struct DoubleList *head) {
    std::cout << "DoubleList Next <<< ";
    struct DoubleList *tail = nullptr;

    while (head) {
        std::cout << head->value << " ";
        tail = head;
        head = head->next;
    }

    std::cout << std::endl;
    std::cout << "           prev <<< ";

    while (tail) {
        std::cout << tail->value << " ";
        tail = tail->prev;
    }

    std::cout << std::endl;
}

void testDoubleList() {
    struct DoubleList *head = new struct DoubleList(1);
    head->prev = nullptr;
    head->next = new struct DoubleList(2);
    head->next->prev = head;
    head->next->next = new struct DoubleList(3);
    head->next->next->prev = head->next;
    head->next->next->next = new struct DoubleList(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new struct DoubleList(5);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = nullptr;

    ShowDoubleList(head);
    head = reverseDoubleList(head);
    ShowDoubleList(head);
}


//g++ Code_07.cpp -o xxx -std=c++11

int main() {
    testList();
    testDoubleList();
    return 0;
}