class Solution {
public:
    int size(ListNode* h) {
        int count = 0;
        ListNode* t = h;
        while(t) {
            count++;
            t = t->next;
        }
        return count;
    }

    int pairSum(ListNode* head) {
        unordered_map<int, int> map;

        int n = size(head);

        int i = 0;
        int max_sum = INT_MIN;
        ListNode* tmp = head;

        while(tmp) {
            if(i < n /2) {
                map[i] = tmp->val;
            } else {
                max_sum = max(max_sum, tmp->val + map[n - 1 - i]);
            }
            i++;
            tmp = tmp->next;
        }

        return max_sum;
    }
};