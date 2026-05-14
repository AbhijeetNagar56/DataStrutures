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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return NULL;
        ListNode* head = new ListNode(0);
        ListNode* tmp = head;

        while(tmp) {
            int m = 0;

            for(int i = 0; i < n; i++) {
                if(lists[i] == NULL) continue;

                if(lists[m] == NULL) m = i;

                if(lists[m]->val > lists[i]->val) {
                    m = i;
                }
            }

            if(lists[m] != NULL) {
                ListNode* node = lists[m];

                lists[m] = lists[m]->next;

                tmp->next = node;
                tmp = tmp->next;
            } else {
                tmp = NULL;
            }

        }

        return head->next;
    }
};