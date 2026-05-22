class Solution {
public:
    // Helper to reverse a linked list
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

    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // 1. Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Split the list into two halves
        ListNode* secondHalf = slow->next;
        slow->next = nullptr; // Break the link

        // 3. Reverse the second half
        secondHalf = reverse(secondHalf);

        // 4. Merge the two halves
        ListNode* firstHalf = head;
        while (secondHalf) {
            ListNode* nextFirst = firstHalf->next;
            ListNode* nextSecond = secondHalf->next;

            firstHalf->next = secondHalf;
            secondHalf->next = nextFirst;

            firstHalf = nextFirst;
            secondHalf = nextSecond;
        }
    }
};