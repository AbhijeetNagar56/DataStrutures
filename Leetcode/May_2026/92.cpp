class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* pre = dummy;
        
        for (int i = 1; i < left; ++i) {
            pre = pre->next;
        }
        
        ListNode* leftNode = pre->next;
        
        ListNode* rightNode = leftNode;
        for (int i = left; i < right; ++i) {
            rightNode = rightNode->next;
        }
        
        ListNode* end = rightNode->next;
        
        rightNode->next = nullptr;
        
        ListNode* newHead = reverse(leftNode);
        
        pre->next = newHead;      // Connect previous part to new head
        leftNode->next = end;     // Connect old left (now tail) to the rest
        
        ListNode* result = dummy->next;
        delete dummy; // Clean up dummy node
        return result;
    }
};