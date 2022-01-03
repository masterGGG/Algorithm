/*
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1：
输入：head = [1,2,3,4]
输出：[2,1,4,3]
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {     
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* sHead = head->next;
        head->next = swapPairs(sHead->next);
        sHead->next = head;
        return sHead;
    }
};