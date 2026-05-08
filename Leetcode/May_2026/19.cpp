class Solution {
public:
    int size(ListNode* head) {
        int  s = 0;
        ListNode* tmp = head;
        while(tmp) {
            s++;
            tmp = tmp->next;
        }
        return s;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i = size(head) - n + 1;

        if(i == 1) {
            head = head->next;
            return head;
        }
        

        ListNode* tmp = head;
        ListNode* pre = NULL;

        while(i - 1) {
            pre = tmp;
            tmp = tmp->next;
            i--;
        }

        pre->next = tmp->next;

        return head;
    }
};