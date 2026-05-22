class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* p = NULL;
        ListNode* t = head;

        while(t) {
            ListNode* n = t->next;
            t->next = p;
            p = t;
            t = n;
        }

        return p;
    }
};