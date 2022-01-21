class Solution {
public:
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* phead = this->head;
        int val = phead->val;
        int count = 1;
        while (phead){
            if (rand() % count++ == 0)
                val = phead->val;
            phead = phead->next;
        }
        return val;
    }
    ListNode* head;
};