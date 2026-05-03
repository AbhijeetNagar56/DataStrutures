class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        ListNode* temp = head;
        ListNode* pre = NULL;

        while(temp != NULL) {
            if(temp->val == val) {
                if(pre == NULL) {
                    head = head->next;
                    temp = head;
                } else {
                    pre->next = temp->next;
                    temp = temp->next;
                }
            } else {
                pre = temp;
                temp = temp->next;
            }
        }

        return head;
    }
};