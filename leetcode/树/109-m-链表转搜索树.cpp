/*
给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 */
class Solution {
public:
  TreeNode* sortedArrayToBST(vector<int>& nums, int l, int r) {
    if (l > r) {
      return nullptr;
    }

    int mid = (l + r) >> 1;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = l < mid ? sortedArrayToBST(nums, l, mid -1) : nullptr;
    root->right = r > mid ? sortedArrayToBST(nums, mid + 1, r) : nullptr;
    return root;
  }

  TreeNode* sortedListToBST(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }

    std::vector<int> vec;

    while (head) {
      vec.emplace_back(head->val);
      head = head->next;
    }

    return sortedArrayToBST(vec, 0, vec.size()-1);
  }
};