class Solution {
public:
    int gcd(int a, int b) {
        int gcd = 0;
        for(int i = 1;  i <= min(a, b); i++) {
            if(a % i == 0 && b % i == 0) gcd = i;
        }
        return gcd;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head->next) return head;

        ListNode* pre = head;
        ListNode* tmp = head->next;

        while(tmp) {
            int curr = gcd(pre->val, tmp->val);
            ListNode*  newNode = new ListNode(curr);
            pre->next = newNode;
            newNode->next = tmp;
            pre = tmp;
            tmp = tmp->next;
        }

        return head;
    }
};