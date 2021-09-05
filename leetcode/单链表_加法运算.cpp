#include <iostream>

using namespace std;

/**
Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reserveList(ListNode* head) {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        ListNode *next = nullptr;

        while (cur != nullptr) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }

    void show(ListNode *head) {
        cout << "List: ";
        while (head) {
            cout << head->val << " - ";
        }
        cout << endl;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reserveList(l1);
        l2 = reserveList(l2);
        show(l1);
        show(l2);

        ListNode* head = nullptr;
        ListNode* cur = nullptr;
        int needAdd = 0;
        int num;

        while (l1 != nullptr || l2 != nullptr) {
            num = needAdd ? 1 : 0;

            if (l1 != nullptr) {
                num += l1->val;
            }

            if (l2 != nullptr) {
                num += l2->val;
            }

            if (num > 9) {
                num %= 10;
                needAdd = 1;
            } else {
                needAdd = 0;
            }

            if (cur == nullptr) {
                head = new ListNode(num);
                cur = head;
            } else {
                cur->next = new ListNode(num);
                cur = cur->next;
            }
        }

        if (needAdd) {
            cur->next = new ListNode(1);
        }

        return reserveList(head);
    }
};