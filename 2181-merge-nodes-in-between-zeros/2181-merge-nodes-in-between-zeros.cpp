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

        ListNode* dummy = new ListNode(0); 
        ListNode* current = dummy; 
        int value = 0;

        head = head->next;

        while (head != NULL) {
            if (head->val == 0) {
                if (value != 0) {
                    current->next = new ListNode(value);
                    current = current->next;
                }
                value = 0;  
            } else {
                value += head->val; 
            }
            head = head->next;
        }

        return dummy->next;
    }
};
