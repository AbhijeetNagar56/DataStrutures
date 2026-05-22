class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int, int> cts;
        vector<int> unique;

        ListNode* tmp = head;

        while(tmp) {
            cts[tmp->val]++;
            tmp = tmp->next;
        }

        for(const auto& pair: cts) {
            if(pair.second == 1) {
                unique.push_back(pair.first);
            }
        }

        sort(unique.begin(), unique.end());

        ListNode* pre = new ListNode(0);
        tmp = pre;
        for(int n: unique) {
            ListNode* newNode = new ListNode(n);
            tmp->next = newNode;
            tmp = tmp->next;
        }
        

        return pre->next;
        // if(!head || !head->next) return head;

        // ListNode* pre = NULL;
        // ListNode* tmp = head;

        // while(tmp) {
        //     ListNode* n = tmp->next;
        //     if(tmp->val == n->val) {
        //         while(n && n->val == tmp->val) {
        //             n = n->next;
        //         }
        //         pre->next = n;
        //         tmp = n;
        //     }
        // }
    }
};