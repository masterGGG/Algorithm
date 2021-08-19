#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

/*
将单向链表按某值划分成左边小、中间相等、右边大的形式
【题目】 给定一个单向链表的头节点head，节点的值类型是整型，再给定一个 整 数pivot。
实现一个调整链表的函数，将链表调整为左部分都是值小于 pivot 的节点，
中间部分都是值等于pivot的节点，右部分都是值大于 pivot的节点。 
除这个要求外，对调整后的节点顺序没有更多的要求。 
例如:链表9->0->4->5- >1，pivot=3。 
调整后链表可以是1->0->4->9->5，
也可以是0->1->9->5->4。总 之，
满 足左部分都是小于3的节点，中间部分都是等于3的节点(本例中这个部 分为空)，右部分都是大于3的节点即可。
对某部分内部的节点顺序不做 要求。

进阶: 在原问题的要求之上再增加如下两个要求。 在左、中、右三个部分的内部也做顺序要求，
要求每部分里的节点从左 到右的 顺序与原链表中节点的先后次序一致。 
例如:链表9->0->4->5->1，pivot=3。 调整后的链表是0->1->9->4->5。 
在满足原问题要求的同时，左部分节点从左到 右为0、1。在原链表中也 是先出现0，后出现1;
中间部分在本例中为空，不再 讨论;右部分节点 从左到右为9、4、5。
在原链表中也是先出现9，然后出现4， 最后出现5。 
如果链表长度为N，时间复杂度请达到O(N)，额外空间复杂度请达到O(1)。
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

// need n extra space
struct Node * arrPartition(struct Node *head, int num) {
    printList(head);

    std::vector<int> vec;
    struct Node *cur = head;

    while (cur) {
        vec.emplace_back(cur->value);
        cur = cur->next;
    }

    std::sort(vec.begin(), vec.end());

    cur = head;
    int i = 0;
    while (cur) {
        cur->value = vec[i++];
        cur = cur->next;
    }

    printList(head);
    return head;
}

// need 1 extra space
struct Node *listPartition(struct Node *head, int num) {
    printList(head);

    struct Node *preHead = nullptr;
    struct Node *preTail = nullptr;
    struct Node *curHead = nullptr;
    struct Node *curTail = nullptr;
    struct Node *nextHead = nullptr;
    struct Node *nextTail = nullptr;
    struct Node *next = nullptr;

    while (head) {
        next = head->next;
        head->next = nullptr;

        if (head->value < num) {
            if (preHead == nullptr) {
                preHead = preTail = head;
            } else {
                preTail->next = head;
                preTail = head;
            }
        } else if (head->value > num) {
            if (nextHead == nullptr) {
                nextHead = nextTail = head;
            } else {
                nextTail->next = head;
                nextTail = head;
            }
        } else {
            if (curHead == nullptr) {
                curHead = curTail = head;
            } else {
                curTail->next = head;
                curTail = head;
            }
        }

        head = next;
    }

    head = nextHead;

    if (curHead != nullptr) {
        curTail->next = head;
        head = curHead;
    }

    if (preHead != nullptr) {
        preTail->next = head;
        head = preHead;
    }

    printList(head);
    return head;
}

//g++ code_12.cpp  -o xxx -std=c++11
int main() {
    struct Node *head5 = new struct Node(7);
    head5->next = new struct Node(9);
    head5->next->next = new struct Node(1);
    head5->next->next->next = new struct Node(8);
    head5->next->next->next->next = new struct Node(5);
    head5->next->next->next->next->next = new struct Node(2);
    head5->next->next->next->next->next->next = new struct Node(5);
    head5->next->next->next->next->next->next->next = nullptr;
    //arrPartition(head5, 5);
    listPartition(head5, 5);

    return 0;
}