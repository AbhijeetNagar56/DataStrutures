class Solution {
public:
    int size(ListNode* h) {
        int count = 0;
        ListNode* t = h;
        while(t) {
            count++;
            t = t->next;
        }
        return count;
    }
    ListNode* deleteMiddle(ListNode* head) {

        if(!head || !head->next) return NULL;
        int n = size(head);

        int i = 0;

        ListNode* tmp = head;

        while(i + 1 < n / 2) {
            i++;
            tmp = tmp->next;
        }

        ListNode* toDelete = tmp->next;
        tmp->next = tmp->next->next;

        delete toDelete;

        return head;
    }
};