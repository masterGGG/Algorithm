/*
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 */

/*
思路：两两交换+递归处理
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