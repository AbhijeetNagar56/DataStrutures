/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* res = new ListNode(-1);
        ListNode* head = res;
        int carry = 0;
        while(t1 && t2) {
            int sum = (carry + t1->val + t2->val) % 10;
            carry = (carry + t1->val + t2->val) / 10;

            ListNode* newNode = new ListNode(sum);
            res->next = newNode;
            res = newNode;

            t1 = t1->next;
            t2 = t2->next;
        }

        while(t1) {
            int sum = (carry + t1->val) % 10;
            carry = (carry + t1->val) / 10;

            ListNode* newNode = new ListNode(sum);
            res->next = newNode;
            res = newNode;

            t1 = t1->next;
        }

        while(t2) {
            int sum = (carry + t2->val) % 10;
            carry = (carry + t2->val) / 10;

            ListNode* newNode = new ListNode(sum);
            res->next = newNode;
            res = newNode;

            t2 = t2->next;
        }

        if(carry == 1) {
            res->next = new ListNode(1);
        }

        return head->next;
    }
};