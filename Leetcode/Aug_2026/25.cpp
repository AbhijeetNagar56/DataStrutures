class Solution {
private:
    ListNode* reverse(ListNode* head) {
        ListNode* tmp = head;
        ListNode* pre = nullptr;
        while(tmp) {
            ListNode* nxt = tmp->next;
            tmp->next = pre;
            pre = tmp;
            tmp = nxt;
        }
        return pre;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ans = new ListNode(0);
        ListNode* ansptr = ans;

        ListNode* tmp = head;
        bool leaveEnd = false;


        while(tmp) {

            ListNode* current_head = tmp;

            for(int i=1; i<k; i++) {
                if(tmp == NULL) {
                    leaveEnd = true;
                    break;
                }
                tmp = tmp->next;
            }

            if(tmp == NULL || leaveEnd) {
                ansptr->next = current_head;
                break;
            }
            ListNode* next_head = tmp->next;
            tmp->next = NULL;

            current_head = reverse(current_head);

            ansptr->next = current_head;

            while(ansptr->next) {
                ansptr = ansptr->next;
            }

            tmp = next_head;
        }

        return ans->next;
    }
};