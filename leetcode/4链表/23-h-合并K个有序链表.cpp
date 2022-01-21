/*
给你一个链表数组，每个链表都已经按升序排列。
请你将所有链表合并到一个升序链表中，返回合并后的链表。
示例 1：
输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
 */


/*
思路：K个有序数组的队列，两两合并再压入队列尾部。
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if (head1 == nullptr) {
            return head2;
        }

        if (head2 == nullptr) {
            return head1;
        }

        if (head1->val < head2->val) {
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        }

        head2->next = mergeTwoLists(head1, head2->next);
        return head2;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        } else if (lists.size() == 1) {
            return lists[0];
        }

        queue<ListNode *> queues;
        
        for (auto l : lists) {
            queues.push(l);
        }

        while (queues.size() > 1) {
            ListNode*h1 = queues.front();
            queues.pop();
            ListNode*h2 = queues.front();
            queues.pop();
            queues.push(mergeTwoLists(h1, h2));
        }

        return queues.front();
    }
};

//迭代
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if (head1 == nullptr) {
            return head2;
        } else if (head2 == nullptr) {
            return head1;
        }

        ListNode head = ListNode(-1);
        ListNode* tail = &head;

        while (head1 && head2) {
            if (head1->val < head2->val) {
                tail->next = head1;
                head1 = head1->next;
            } else {
                tail->next = head2;
                head2 = head2->next;
            }

            tail = tail->next;
        }

        tail->next = head1 ? head1 : head2;
        
        return head.next;
    }
