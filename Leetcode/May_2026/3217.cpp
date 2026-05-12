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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, int> dp;
        for (int n: nums) dp[n]++;

        ListNode* tmp = head;
        ListNode* pre = NULL;

        while(tmp) {
            if(dp.find(tmp->val) != dp.end()) {
                if(pre == NULL) {
                    head = head->next;
                } else {
                    pre->next = tmp->next;
                }
            } else {
                pre = tmp;
            }
            tmp = tmp->next;
        }

        return head;
    }
};