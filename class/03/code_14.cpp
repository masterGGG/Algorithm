#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

/*
两个单链表相交的一系列问题
【题目】 在本题中，单链表可能有环，也可能无环。
给定两个 单链表的头节点 head1和head2，
这两个链表可能相交，也可能 不相交。请实现一个函数， 
如果两个链表相交，请返回相交的 第一个节点;
如果不相交，返回null 即可。 
要求:如果链表1 的长度为N，链表2的长度为M，时间复杂度请达到 O(N+M)，
额外 空间复杂度请达到O(1)。
*/

struct Node {
    Node(int v) : value(v) {
        next = nullptr;
    }
    int value;
    struct Node *next;
};

void printList(struct Node *head) {
    std::cout << "Linked List: ";

    while (head) {
        std::cout << head->value << ", ";
        head = head->next;
    }

    std::cout << std::endl;
}

struct Node *getLoopNode(struct Node *head) {
    if (head == nullptr) {
        return nullptr;
    }

    struct Node *slow = head;
    struct Node *fast = head;

    while (fast) {
        slow = slow->next;

        if (fast->next == nullptr) {
            return nullptr;
        }

        fast = fast->next->next;

        if (fast == slow) {
            break;
        }
    }

    fast = head;

    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

int listLength(struct Node *head) {
    int len = 0;

    while (head) {
        len++;
        head = head->next;
    }

    return len;
}

struct Node *getNoLoopNode(struct Node *head1, struct Node *head2) {
    int len1 = listLength(head1);
    int len2 = listLength(head2);

    while (len1 < len2) {
        head2 = head2->next;
        len2--;
    }

    while (len1 > len2) {
        head1 = head1->next;
        len1--;
    }

    while (head1) {
        if (head1 == head2) {
            return head1;
        }

        head1 = head1->next;
        head2 = head2->next;
    }

    return nullptr;
}

struct Node *getIntersectLoopNode(struct Node *head1, struct Node *node1, struct Node *head2, struct Node *node2) {
    struct Node *cur = node1->next;
    struct Node *res = nullptr;

    //Intersect outside loop
    if (node1 == node2) {
        node1->next = nullptr;
        res = getNoLoopNode(head1, head2);
        node1->next = cur;
        return res;
    } else {
        while (cur != node1) {
            if (cur == node2) {
                return node1;
            }

            cur = cur->next;
        }

        return nullptr;
    }
}

struct Node *getIntersectNode(struct Node *head1, struct Node *head2) {
    struct Node *node1 = getLoopNode(head1);
    struct Node *node2 = getLoopNode(head2);
    struct Node *res = nullptr;

    if (node1 == nullptr && node2 == nullptr) {
        res = getNoLoopNode(head1, head2);
        std::cout << "NoLoop"<< std::endl;
    } else if (node1 != nullptr && node2 != nullptr) {
        res = getIntersectLoopNode(head1, node1, head2, node2);
        std::cout << "Loop " << std::endl;
    } else {
        std::cout << "Not IntersectNode" << std::endl;
    }

    if (res) {
        std::cout << "IntersectNode " << res->value << std::endl;
    }

    return res;
}

//g++ code_14.cpp  -o xxx -std=c++11
int main() {
    // 1->2->3->4->5->6->7->null
    struct Node *head1 = nullptr;
    head1 = new struct Node(1);
    head1->next = new struct Node(2);
    head1->next->next = new struct Node(3);
    head1->next->next->next = new struct Node(4);
    head1->next->next->next->next = new struct Node(5);
    head1->next->next->next->next->next = new struct Node(6);
    head1->next->next->next->next->next->next = new struct Node(7);

    // 0->9->8->6->7->null
    struct Node *head2 = nullptr;
    head2 = new struct Node(0);
    head2->next = new struct Node(9);
    head2->next->next = new struct Node(8);
    head2->next->next->next = head1->next->next->next->next->next; // 8->6

    getIntersectNode(head1, head2);

    // 1->2->3->4->5->6->7->4...
    head1->next->next->next->next->next->next->next = head1->next->next->next; // 7->4
    // 0->9->8->2...
    head2->next->next->next = head1->next; // 8->2
    getIntersectNode(head1, head2);

    // 0->9->8->6->4->5->6..
    head2->next->next->next = head1->next->next->next->next->next;// 8->6
    getIntersectNode(head1, head2);

    return 0;
}