class Solution {
public:
    int size(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            n++;
            temp = temp->next;
        }
        return n;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        
        int s = size(head);
        k = k % s;

        if(s == 1 || k == 0 || k == s) return head; // best cases

        ListNode* temp = head;

        for(int i = 0; i < s - k - 1; i++) temp = temp->next;

        ListNode* new_head = temp->next;
        temp->next = NULL;

        temp = new_head;

        while(temp->next != NULL) temp = temp->next;

        temp->next = head;

        return new_head;
    }
};