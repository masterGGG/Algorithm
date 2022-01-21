/*
817. 链表组件
给定链表头结点 head，该链表上的每个结点都有一个 唯一的整型值 。
同时给定列表 G，该列表是上述链表中整型值的一个子集。
返回列表 G 中组件的个数，这里对组件的定义为：链表中一段最长连续结点的值（该值必须在列表 G 中）构成的集合。
 */

/*
思路：采用一个set记录列表中的元素
遍历链表，如果当前节点在set中，下一个节点不在或者不存在，组件个数+1
*/
class Solution {
public:
int numComponents(ListNode* head, vector<int>& nums) {
  std::set<int> Gset;

  for (auto i : nums) {
    Gset.emplace(i);
  }

  int res = 0;

  while (head) {
    if (Gset.find(head->val) != Gset.end() && (!head->next || (head->next && Gset.find(head->next->val) == Gset.end()))) {
      res++;
    }

    head = head->next;
  }

  return res;
}
};