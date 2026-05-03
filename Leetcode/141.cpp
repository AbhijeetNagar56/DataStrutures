// hashmap solution
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, bool> isMapped;
        ListNode* temp = head;

        while(temp != NULL) {
            if(isMapped[temp->next] == true) return true;
            isMapped[temp->next] = true;
            temp = temp->next;
        }

        return false;

    }
};

