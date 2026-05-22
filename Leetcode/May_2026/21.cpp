class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* n1 = list1;
        ListNode* n2 = list2;

        ListNode* head = new ListNode(0);
        ListNode* A = head;

        while(n1 && n2) {
            if(n1->val < n2->val) {
                A->next = n1;
                n1 = n1->next;
                A = A->next;
                A->next = NULL;
            } else {
                A->next = n2;
                n2 = n2->next;
                A = A->next;
                A->next = NULL;
            }
        }


        if(n1 != NULL) {
            A->next = n1;
        }

        if(n2 != NULL) {
            A->next = n2;
        }

        return head->next;
    }
};