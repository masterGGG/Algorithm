#include <iostream>
#include <vector>
#include <stack>

/*
判断一个链表是否为回文结构
【题目】 给定一个链表的头节点head，请判断该链表是否为回 文结构。 
例如: 
1->2->1，返回true。 
1->2->2->1，返回true。 
15->6->15，返回true。 1->2->3，返回false。
进阶: 如果链表长度为N，时间复杂度达到O(N)，额外空间复杂 度达到O(1)。
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

// need n/2 extra space
bool isPalindrome1(struct Node *head) {
    printList(head);

    std::stack<int> myStack;
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast) {
        if (fast->next == nullptr) {
            slow = slow->next;
            break;
        }

        myStack.push(slow->value);
        slow = slow->next;
        fast = fast->next->next;
    }

    while (slow) {
        if (slow->value != myStack.top()) {
            std::cout << "Isn't Palindrome" << std::endl;
            return false;
        }

        myStack.pop();
        slow = slow->next;
    }

    std::cout << "Is Palindrome" << std::endl;
    return true;
}

// need 1 extra space
bool isPalindrome2(struct Node *head) {
    printList(head);

    if (nullptr == head || head->next == nullptr) {
        std::cout << "Is Palindrome" << std::endl;
        return true;
    }

    struct Node *slow = head;
    struct Node *fast = head;

    while (fast) {
        if (fast->next == nullptr) {
            //slow = slow->next;
            break;
        }

        slow = slow->next;
        fast = fast->next->next;
    }

    //right part convert
    struct Node *pre = nullptr;
    struct Node *cur = slow;
    struct Node *next = nullptr;
    while (cur) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }

    struct Node *tail = pre;

    //check palindrome
    bool isPalindrome = true;
    next = tail;
    pre = head;
    while (next) {
        if (next->value != pre->value) {
            isPalindrome = false;
            std::cout << "Isn't Palindrome" << std::endl;
            break;
        }
        next = next->next;
        pre = pre->next;
    }

    //recover right part
    pre = nullptr;
    cur = tail;
    while (cur) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }

    std::cout << "Is Palindrome" << std::endl;
    return isPalindrome;
}

//g++ code_11.cpp  -o xxx -std=c++11
int main() {
    struct Node *head = nullptr;
    isPalindrome1(head);
    isPalindrome2(head);

    head = new struct Node(1);
    isPalindrome1(head);
    isPalindrome2(head);

    struct Node *head1 = new struct Node(1);
    head1->next = new struct Node(2);
    head1->next->next = nullptr;
    isPalindrome1(head1);
    isPalindrome2(head1);

    struct Node *head2 = new struct Node(1);
    head2->next = new struct Node(2);
    head2->next->next = new struct Node(1);
    head2->next->next->next = nullptr;
    isPalindrome1(head2);
    isPalindrome2(head2);

    struct Node *head3 = new struct Node(1);
    head3->next = new struct Node(1);
    head3->next->next = nullptr;
    isPalindrome1(head3);
    isPalindrome2(head3);

    struct Node *head4 = new struct Node(1);
    head4->next = new struct Node(2);
    head4->next->next = new struct Node(3);
    head4->next->next->next = nullptr;
    isPalindrome1(head4);
    isPalindrome2(head4);

    struct Node *head5 = new struct Node(1);
    head5->next = new struct Node(2);
    head5->next->next = new struct Node(3);
    head5->next->next->next = new struct Node(2);
    head5->next->next->next->next = new struct Node(1);
    head5->next->next->next->next->next = nullptr;
    isPalindrome1(head5);
    isPalindrome2(head5);

    return 0;
}