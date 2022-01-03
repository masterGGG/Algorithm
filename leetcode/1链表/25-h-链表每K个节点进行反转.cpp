/*
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
k 是一个正整数，它的值小于或等于链表的长度。
如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

进阶：
你可以设计一个只使用常数额外空间的算法来解决此问题吗？
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 
示例 1：
输入：head = [1,2,3,4,5], k = 2
输出：[2,1,4,3,5]
 */
class Solution {
public:
    ListNode* reverseK(ListNode* head, int k) {
        ListNode *prev = nullptr, *cur = head, *next = nullptr;

        while (k--) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        head->next = cur;

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) {
            return head;
        }

        int step = k;
        ListNode *tail = head, *prev = nullptr;

        while (step--) {
            if (!tail) {
                return head;
            }

            prev = tail;
            tail = tail->next;
        }

        prev->next = reverseKGroup(tail, k);
        head = reverseK(head, k);

        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) {
            return head;
        }

        int step = k;
        ListNode *tail = head;
        stack<ListNode*> mystack;

        while (step-- && tail) {
            mystack.push(tail);
            tail = tail->next;
        }

        if (mystack.size() < k) {
            return head;
        }

        ListNode *h = mystack.top(), *next;
        mystack.pop();
        next = h;
    
        while (!mystack.empty()) {
            next->next = mystack.top();
            mystack.pop();
            next = next->next;
        }

        next->next = reverseKGroup(tail, k);

        return h;
    }
};