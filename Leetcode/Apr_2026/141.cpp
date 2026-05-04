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

// two pointer solution
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (slow != fast) {
            if (!fast || !fast->next) return false;
            slow = slow->next;
            fast = fast->next->next;
        }

        return true;
    }
};