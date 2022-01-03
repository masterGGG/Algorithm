/*
61. 旋转链表
给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。

示例 1：
输入：head = [1,2,3,4,5], k = 2
输出：[4,5,1,2,3]
*/

class Solution {
public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr || (head->next == nullptr)) {
      return head;
    }

    ListNode *pcurr = head;
    ListNode *pprev = nullptr;
    int ilen = 0;

    while (pcurr) {
      ilen++;
      pprev = pcurr;
      pcurr = pcurr->next;
    }

    k = k % ilen;

    if (k) {
      pprev->next = head;
      k = ilen - k;
      pcurr = head;
      
      while (k--) {
        pprev = pcurr;
        pcurr = pcurr->next;
      }

      head = pcurr;
      pprev->next = nullptr;
    }

    return head;
  }
};