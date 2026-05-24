class Solution {
public:
    ListNode* reverse(ListNode* head) {
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

    ListNode* doubleIt(ListNode* head) {

        head = reverse(head);

        int mul = 0, carry = 0;

        ListNode* tmp = head;

        while(tmp) {
            int n = carry + 2*tmp->val;
            mul = n % 10;
            carry = n / 10;
            tmp->val = mul;
            tmp = tmp->next;
        }

        tmp = head;

        while(tmp->next) {
            tmp = tmp->next;
        }

        if(carry) {
            ListNode* newNode = new ListNode(carry);
            tmp->next = newNode;
        }

        head = reverse(head);

        return head;


    }
};