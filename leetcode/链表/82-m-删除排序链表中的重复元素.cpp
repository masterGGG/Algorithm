/*
存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除链表中所有存在数字重复情况的节点，只保留原始链表中 没有重复出现 的数字。
返回同样按升序排列的结果链表。

示例 1：
输入：head = [1,2,3,3,4,4,5]
输出：[1,2,5]
示例 2：
输入：head = [1,1,1,2,3]
输出：[2,3]

提示：
链表中节点数目在范围 [0, 300] 内
-100 <= Node.val <= 100
题目数据保证链表已经按升序排列
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *pprev = nullptr, *pcurr = head, *pnext = nullptr;

    while (pcurr && pcurr->next) {
      pnext = pcurr->next;

      while (pnext && pnext->val == pcurr->val) {
        pnext = pnext->next;  //过滤相等的结点，next指向下一个不等的结点。
      }

      if (pcurr->next != pnext) {
        //存在相等的结点
        if (!pprev) {
          head = pnext;
        } else {
          pprev->next = pnext;
        }
      } else {
        pprev = pcurr;
      }
    
      pcurr = pnext;
    }

    return head;
  }
};