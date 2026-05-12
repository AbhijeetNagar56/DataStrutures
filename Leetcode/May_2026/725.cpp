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
    int size(ListNode* head) {
        int s = 0;
        ListNode* tmp = head;
        while(tmp) {
            s++;
            tmp = tmp->next;
        }
        return s;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, nullptr);
        int n = size(head);
        int base = n / k;
        int extra = n % k;

        ListNode* curr = head;
        for (int i = 0; i < k && curr; ++i) {
            ans[i] = curr;
            int partSize = base + (extra > 0 ? 1 : 0);
            extra--;

            for (int j = 1; j < partSize; ++j) {
                curr = curr->next;
            }

            ListNode* nextPart = curr->next;
            curr->next = nullptr;
            curr = nextPart;
        }

        return ans;
    }
};