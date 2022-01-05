/*
存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除链表中所有存在数字重复情况的节点，只保留原始链表中 没有重复出现 的数字。
返回同样按升序排列的结果链表。

示例 1：
输入：head = [1,2,3,3,4,4,5]
输出：[1,2,5]
 */

/*
思路：双指针法+假头节点
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return head;
        }
        
        ListNode* fade = new ListNode(0, head);
        ListNode* cur = fade;

        //如果当前节点后存在至少2个节点，比较对应的值
        while (cur->next && cur->next->next) {
            //如果后续两个节点的值相等，将所有重复节点移除
            if (cur->next->val == cur->next->next->val) {
                int x = cur->next->val;
                while (cur->next && cur->next->val == x) {
                    cur->next = cur->next->next;
                }
            } else {
                cur = cur->next;
            }
        }

        return fade->next;
    }
};