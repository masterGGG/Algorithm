/*
61. 旋转链表
给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。

示例 1：
输入：head = [1,2,3,4,5], k = 2
输出：[4,5,1,2,3]
示例 2：
输入：head = [0,1,2], k = 4
输出：[2,0,1]

提示：
链表中节点的数目在范围 [0, 500] 内
-100 <= Node.val <= 100
0 <= k <= 2*109
*/


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

/* int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  showlist(head);

  return 0;
} */