/**
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例 1：
输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.
示例 2：
输入：l1 = [0], l2 = [0]
输出：[0]
示例 3：
输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
输出：[8,9,9,9,0,0,0,1]

提示：
每个链表中的节点数在范围 [1, 100] 内
0 <= Node.val <= 9
题目数据保证列表表示的数字不含前导零
 */

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