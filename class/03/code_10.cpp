#include <iostream>
#include <vector>

/*
打印两个有序链表的公共部分
【题目】 给定两个有序链表的头指针head1和head2，打印两个 链表的公共部分。
*/
struct Node {
    Node(int v) : value(v) {
        next = nullptr;
    }
    int value;
    struct Node *next;
};

void printCommonPart(struct Node *lhs, struct Node *rhs) {
    std::cout << "printCommonPart: ";
    while (lhs && rhs) {
        if (lhs->value < rhs->value) {
            lhs = lhs->next;
        } else if (lhs->value > rhs->value) {
            rhs = rhs->next;
        } else {
            std::cout << lhs->value << ", ";
            lhs = lhs->next;
        }
    }

    std::cout << std::endl;
}

void printList(struct Node *head) {
    std::cout << "Linked List: ";

    while (head) {
        std::cout << head->value << ", ";
        head = head->next;
    }

    std::cout << std::endl;
}

//g++ code_10.cpp  -o xxx -std=c++11
int main() {
    struct Node *head1 = new struct Node(2);
    head1->next = new struct Node(3);
    head1->next->next = new struct Node(5);
    head1->next->next->next = new struct Node(6);
    head1->next->next->next->next = nullptr;

    struct Node *head2 = new struct Node(1);
    head2->next = new struct Node(2);
    head2->next->next = new struct Node(5);
    head2->next->next->next = new struct Node(7);
    head2->next->next->next->next = new struct Node(8);
    head2->next->next->next->next->next = nullptr;

    printList(head1);
    printList(head2);
    printCommonPart(head1, head2);
    return 0;
}