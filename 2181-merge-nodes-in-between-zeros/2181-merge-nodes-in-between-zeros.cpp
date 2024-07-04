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
    ListNode* mergeNodes(ListNode* head) {
        if (head == NULL) return NULL;

        ListNode* dummy = new ListNode(0);  // Create a dummy node to start the new list
        ListNode* current = dummy;  // This will point to the last node in the new list
        int value = 0;

        head = head->next;  // Skip the initial zero node

        while (head != NULL) {
            if (head->val == 0) {
                // If we encounter a zero and value is not zero, create a new node with the sum
                if (value != 0) {
                    current->next = new ListNode(value);
                    current = current->next;
                }
                value = 0;  // Reset the value
            } else {
                value += head->val;  // Add the current node's value to the sum
            }
            head = head->next;
        }

        return dummy->next;  // Return the next of dummy node as dummy is a placeholder
    }
};
