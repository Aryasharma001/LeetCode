class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;

        // Step 1: Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while (slow != nullptr) {
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        // Step 3: Merge the two halves
        ListNode* firstHalf = head;
        ListNode* secondHalf = prev; // prev now points to the head of the reversed second half
        while (secondHalf->next) {
            next = firstHalf->next;
            prev = secondHalf->next;

            firstHalf->next = secondHalf;
            secondHalf->next = next;
            
            firstHalf = next;
            secondHalf = prev;
        }
    }
};